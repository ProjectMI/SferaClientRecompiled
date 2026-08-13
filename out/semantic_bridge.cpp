#include "semantic_bridge.h"

#include "diagnostics.h"
#include "runtime.h"
#include "semantic_native.h"

#include <bit>
#include <cstdint>
#include <mutex>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#if defined(_WIN32)
static_assert(sizeof(void*) == 4, "The semantic bridge requires the Win32 target selected by the project");
#endif

namespace {

using sfera::semantic::NativeArgument;
using sfera::semantic::NativeCallingConvention;
using sfera::semantic::NativeEntry;
using sfera::semantic::NativeParameter;
using sfera::semantic::NativeParameterStorage;
using sfera::semantic::NativeResult;
using sfera::semantic::NativeValueKind;

template <typename Value>
Value* pointer_at(std::uint32_t address) noexcept {
    return reinterpret_cast<Value*>(static_cast<std::uintptr_t>(address));
}

void semantic_diagnostic(std::string_view message) {
    const std::string terminated(message);
    lifted::diagnostic_note(terminated.c_str());
}

std::uint64_t load_abi_word(std::uint32_t address, std::uint8_t width) {
    if (width == 0u || width > sizeof(std::uint64_t)) { throw std::runtime_error("Unsupported semantic ABI argument width"); }
    if (width == 1u) { return lift_load8(address); }
    if (width == 2u) { return lift_load16(address); }
    if (width == 4u) { return lift_load32(address); }
    if (width == 8u) { return lift_load64(address); }
    std::uint64_t value = 0;
    for (std::uint8_t index = 0; index < width; ++index) { value |= static_cast<std::uint64_t>(lift_load8(address + index)) << (index * 8u); }
    return value;
}

NativeArgument decode_argument(const LiftCpu& cpu, const NativeParameter& parameter) {
    std::uint64_t word = 0;
    if (parameter.storage == NativeParameterStorage::ecx) { word = cpu.ecx; }
    else if (parameter.storage == NativeParameterStorage::edx) { word = cpu.edx; }
    else { word = load_abi_word(cpu.esp + 4u + parameter.stack_offset, parameter.width); }

    long double floating = 0.0L;
    if (parameter.kind == NativeValueKind::floating) {
        if (parameter.width == 4u) { floating = std::bit_cast<float>(static_cast<std::uint32_t>(word)); }
        else if (parameter.width == 8u) { floating = std::bit_cast<double>(word); }
        else { throw std::runtime_error("Unsupported semantic floating-point argument width"); }
    }
    return {word, floating, parameter.kind, parameter.width};
}

std::vector<NativeArgument> decode_arguments(const LiftCpu& cpu, const NativeEntry& entry) {
    std::vector<NativeArgument> arguments;
    arguments.reserve(entry.parameter_count);
    for (std::uint16_t index = 0; index < entry.parameter_count; ++index) { arguments.push_back(decode_argument(cpu, entry.parameters[index])); }
    return arguments;
}

void store_result(LiftCpu& cpu, const NativeResult& result) {
    if (result.kind == NativeValueKind::none) { return; }
    if (result.kind == NativeValueKind::floating) {
        lift_x87_push(&cpu, static_cast<double>(result.floating));
        return;
    }
    cpu.eax = static_cast<std::uint32_t>(result.word);
    if (result.width > 4u) { cpu.edx = static_cast<std::uint32_t>(result.word >> 32u); }
}

std::uint32_t callee_stack_cleanup(const NativeEntry& entry) noexcept {
    return entry.convention == NativeCallingConvention::cdecl_call || entry.convention == NativeCallingConvention::automatic ? 0u : entry.stack_bytes;
}

NativeCallingConvention resolved_convention(const sfera::semantic::NativeCall& call) noexcept {
    if (call.convention != NativeCallingConvention::automatic) { return call.convention; }
    return call.source_va == 0u ? NativeCallingConvention::cdecl_call : sfera::semantic::native_abi_hint(call.source_va);
}

void append_stack_argument(std::vector<std::uint32_t>& words, const NativeArgument& argument) {
    if (argument.width == 0u || argument.width > sizeof(std::uint64_t)) { throw std::runtime_error("Unsupported legacy ABI argument width"); }
    words.push_back(static_cast<std::uint32_t>(argument.word));
    if (argument.width > 4u) { words.push_back(static_cast<std::uint32_t>(argument.word >> 32u)); }
}

void marshal_legacy_arguments(LiftCpu& cpu, const sfera::semantic::NativeCall& call) {
    const NativeCallingConvention convention = resolved_convention(call);
    std::vector<std::uint32_t> stack_words;
    stack_words.reserve(call.argument_count * 2u);
    std::uint8_t fastcall_register = 0;

    for (std::size_t index = 0; index < call.argument_count; ++index) {
        const NativeArgument& argument = call.arguments[index];
        if (convention == NativeCallingConvention::thiscall_call && index == 0u) {
            cpu.ecx = static_cast<std::uint32_t>(argument.word);
            continue;
        }
        if (convention == NativeCallingConvention::fastcall_call && fastcall_register < 2u && argument.kind == NativeValueKind::word && argument.width <= 4u) {
            if (fastcall_register++ == 0u) { cpu.ecx = static_cast<std::uint32_t>(argument.word); }
            else { cpu.edx = static_cast<std::uint32_t>(argument.word); }
            continue;
        }
        append_stack_argument(stack_words, argument);
    }
    for (auto word = stack_words.rbegin(); word != stack_words.rend(); ++word) { lift_push32(&cpu, *word); }
}

std::uint32_t runtime_callsite(const sfera::semantic::NativeCall& call) {
    if (call.callsite < UINT32_C(0x00400000)) { return call.callsite; }
    return lift_image_va(call.callsite);
}

NativeResult invoke_legacy(void* bridge_context, const sfera::semantic::NativeCall& call) {
    if (!bridge_context || call.target == 0u) { throw std::runtime_error("Invalid semantic-to-processor call"); }
    auto& cpu = *static_cast<LiftCpu*>(bridge_context);
    const LiftCpu saved = cpu;
    marshal_legacy_arguments(cpu, call);
    const std::uint8_t previous_fpu_depth = cpu.fpu_depth;

    if (!lift_call_indirect(&cpu, call.target, LIFT_CALLBACK_SENTINEL, runtime_callsite(call))) {
        cpu = saved;
        throw std::runtime_error("Processor fallback did not return to the semantic bridge");
    }

    NativeResult result{};
    if ((call.expected_result == NativeValueKind::floating && cpu.fpu_depth != 0u) || cpu.fpu_depth > previous_fpu_depth) {
        result = {0u, static_cast<long double>(lift_x87_get(&cpu, 0u)), NativeValueKind::floating, 8u};
    } else if (call.expected_result != NativeValueKind::none) {
        result = {static_cast<std::uint64_t>(cpu.eax) | (static_cast<std::uint64_t>(cpu.edx) << 32u), 0.0L, NativeValueKind::word, 8u};
    }
    cpu = saved;
    return result;
}

void attach_semantic_runtime() {
    static std::once_flag attached;
    std::call_once(attached, [] {
        const std::uint32_t image_base = lift_image_va(UINT32_C(0x00400000));
        sfera::semantic::ConfigurationStorage configuration{
            pointer_at<char*>(lift_image_va(UINT32_C(0x00916E40))),
            pointer_at<std::uint32_t>(lift_image_va(UINT32_C(0x048F5A98))),
            pointer_at<char>(lift_image_va(UINT32_C(0x006BEC00))),
            static_cast<std::size_t>(UINT32_C(0x00258240))
        };
        sfera::semantic::attach_runtime({configuration, &semantic_diagnostic, image_base, &invoke_legacy, &lifted::checked_memory_copy});
    });
}

} // namespace

extern "C" int LIFT_CDECL semantic_bridge_try_invoke(LiftCpu* cpu, std::uint32_t source_va, std::uint32_t stop_address) {
    const NativeEntry* entry = sfera::semantic::find_native_entry(source_va);
    if (!entry) { return 0; }
    lift_enter_block(cpu, source_va);
    attach_semantic_runtime();
    lifted::DiagnosticSemanticScope semantic_scope(source_va, entry->name);
    const std::vector<NativeArgument> arguments = decode_arguments(*cpu, *entry);
    for (std::size_t index = 0; index < arguments.size(); ++index) { lifted::set_diagnostic_semantic_argument(index, arguments[index].word, arguments[index].width, arguments[index].kind == NativeValueKind::floating); }
    const NativeResult result = sfera::semantic::invoke_native_entry(*entry, arguments.data(), arguments.size(), cpu);
    store_result(*cpu, result);
    lift_return(cpu, callee_stack_cleanup(*entry), stop_address);
    return 1;
}

extern "C" void LIFT_CDECL sfera_sub_00401600(LiftCpu* cpu, std::uint32_t stop_address) {
    if (semantic_bridge_try_invoke(cpu, UINT32_C(0x00401600), stop_address)) { return; }
    lift_trap(cpu, UINT32_C(0x00401600), "missing semantic binding");
}

extern "C" void LIFT_CDECL sfera_u32_to_sso_decimal(LiftCpu* cpu) {
    const std::uint32_t destination = cpu->ecx;
    const std::string text = sfera::semantic::decimal_string(lift_load32(cpu->edx));
    lift_store64(destination, 0);
    lift_store64(destination + 8u, 0);
    for (std::size_t index = 0; index < text.size(); ++index) { lift_store8(destination + static_cast<std::uint32_t>(index), static_cast<std::uint8_t>(text[index])); }
    lift_store32(destination + 0x10u, static_cast<std::uint32_t>(text.size()));
    lift_store32(destination + 0x14u, 15u);
    cpu->eax = destination;
}
