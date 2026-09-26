#include <windows.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <ctime>
#include <format>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "animation/Animation.h"
#include "application/ClientApplication.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "effects/EffectManager.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "script/MbcRuntime.h"
#include "ui/Rendering.h"
#include "world/WorldObjects.h"

void SphereRenderModelPose::missingAnimation(std::string_view modelName, int animation, int frame)
{
    auto message = std::format("CalcCharacterNeck: model has no animation (model='{}', controlled={}, animation={}, frame={})", modelName, g_sfera_world_objects.controlled_object_handle, animation,
                               frame);
    const auto &scriptError = g_sfera_mbc_runtime.first_execution_error;
    if (!scriptError.empty())
    {
        message += "\nFirst script error in this session:\n" + scriptError;
    }
    g_sfera_log_runtime.write(message);
    WorldDiagnostics::fail(message);
}

void SferaLogRuntime::initialize()
{
    path = "Error.log";
    size_limit = 10000000u;
    writeTimestamp("**** Start: ");
}

void SferaEngineDiagnosticsAdapter::bind() noexcept
{
    SferaVec3F::setNormalizationFailureHandler(&SferaEngineDiagnosticsAdapter::fail);
    SferaEngineDiagnostics::install({&SferaEngineDiagnosticsAdapter::fatal, &SferaEngineDiagnosticsAdapter::fail, &SferaEngineDiagnosticsAdapter::write, &SferaEngineDiagnosticsAdapter::lightActivated,
                                     &SferaEngineDiagnosticsAdapter::report, &SferaEngineDiagnosticsAdapter::warning});
}

void SferaEngineDiagnosticsAdapter::fatal(std::string_view message)
{
    SferaClientApplication::terminateWithError(message);
}

void SferaEngineDiagnosticsAdapter::fail(std::string_view message)
{
    WorldDiagnostics::fail(message);
}

void SferaEngineDiagnosticsAdapter::write(std::string_view message)
{
    g_sfera_log_runtime.write(message);
}

void SferaEngineDiagnosticsAdapter::lightActivated() noexcept
{
    if (g_sfera_effect_manager.diagnostics.enabled)
        ++g_sfera_effect_manager.diagnostics.light_activations;
}

void SferaEngineDiagnosticsAdapter::report(std::string_view message)
{
    WorldDiagnostics::report(message);
}

void SferaEngineDiagnosticsAdapter::warning(std::string_view message)
{
    WorldDiagnostics::warning(message);
}

void SferaErrorLogRuntime::initialize(IOutputDevice *error, IOutputDevice *log)
{
    auto nextError = error == nullptr ? std::make_unique<CSphereError>() : nullptr;
    auto nextLog = log == nullptr ? std::make_unique<COutputLogDevice>() : nullptr;
    if (nextLog)
        nextLog->setFilename("sphere.log");
    if (error != nullptr && error == owned_error.get())
        nextError = std::move(owned_error);
    if (log != nullptr && log == owned_log.get())
        nextLog = std::move(owned_log);
    clear();
    owned_error = std::move(nextError);
    owned_log = std::move(nextLog);
    outputs[0] = owned_error ? owned_error.get() : error;
    outputs[1] = owned_log ? owned_log.get() : log;
    enabled = true;
}

void SferaErrorLogRuntime::clear()
{
    outputs[0] = outputs[1] = nullptr;
    enabled = false;
    owned_log.reset();
    owned_error.reset();
}

void SphereUIInterfaceRenderer::reportError(std::string_view message)
{
    for (std::uint32_t index : {1u, 0u})
        if (auto *output = g_sfera_error_log_runtime.outputs[index])
        {
            if (index == 1u)
                output->write("*** ERROR ****************************************************:");
            output->write(message);
        }
}

void WorldDiagnostics::appendScriptContext(std::string_view text)
{
    WorldDiagnostics::message.append(text);
}

void WorldDiagnostics::flushScriptContext()
{
    if (const auto context = scriptContext())
    {
        appendScriptContext("\n");
        appendScriptContext(*context);
    }
    warning(WorldDiagnostics::message);
    appendScriptContext("\n\n");
}

std::uint32_t WorldDiagnostics::inspectInstruction(std::uint16_t &module, std::uint32_t &offset, std::uint8_t *bytes, std::uint32_t &count)
{
    module = std::numeric_limits<std::int16_t>::max();
    offset = 0u;
    const auto &vm = g_sfera_mbc_runtime;
    if (vm.process_index < 0 || std::cmp_greater_equal(vm.process_index, std::size(vm.processes)))
    {
        count = 0u;
        return 1u;
    }
    const auto &process = vm.processes[vm.process_index];
    const auto mismatch = vm.bytecode_base != process.codeData() ? codeBaseMismatch : 0u;
    const std::less<const std::uint8_t *> before;
    if (!process.codeData() || !vm.current_instruction_address || before(vm.current_instruction_address, process.codeData()) ||
        !before(vm.current_instruction_address, process.codeData() + process.codeSize()))
    {
        count = 0u;
        return mismatch | 3u;
    }
    const std::uint32_t relative = SferaNumeric::lowWord(vm.current_instruction_address - process.codeData());
    if (bytes)
    {
        count = std::min(count, process.codeSize() - relative);
        std::copy_n(vm.current_instruction_address, count, bytes);
    }
    const auto ranges = std::min<std::size_t>(process.code_range_count, std::size(process.code_range_ids));
    for (std::size_t index = 0; index < ranges; ++index)
    {
        const auto begin = process.code_range_begin[index];
        if (relative >= begin && relative - begin < process.code_range_size[index])
        {
            module = process.code_range_ids[index];
            offset = relative - begin;
            return mismatch;
        }
    }
    return mismatch | (process.code_range_count == std::size(process.code_range_ids) ? 2u : 3u);
}

void WorldDiagnostics::describeScript(bool includeTime)
{
    auto &vm = g_sfera_mbc_runtime;
    auto &output = vm.diagnostic_context;
    output.clear();
    if (includeTime)
    {
        const auto now = std::time(nullptr);
        std::tm local{};
#ifdef _WIN32
        localtime_s(&local, &now);
#else
        localtime_r(&now, &local);
#endif
        output = std::format("{:02}:{:02}:{:02} ", local.tm_hour, local.tm_min, local.tm_sec);
    }
    std::uint16_t module;
    std::uint32_t offset, count = 16;
    std::uint8_t bytes[16];
    const auto status = inspectInstruction(module, offset, bytes, count);
    if ((status & ~codeBaseMismatch) == 1)
    {
        output.append("PrcName,CodeOffs: unknown. (wrong pos)");
        return;
    }
    if ((status & ~codeBaseMismatch) == 2)
    {
        output.append("PrcName,CodeOffs: unknown. (modulesNum == MAX_MODULES_IN_PRC)");
        return;
    }
    if ((status & ~codeBaseMismatch) == 3)
    {
        output.append("PrcName,CodeOffs: unknown. (Offset not found)");
        return;
    }
    std::string text;
    if (status & codeBaseMismatch)
        text = std::format("Warn!!! pos = {}, sBaseCodePtr = {:p}, Prc[pos].baseCodePtr = {:p}. ", vm.process_index, static_cast<const void *>(vm.bytecode_base),
                           static_cast<const void *>(vm.processes[vm.process_index].codeData()));
    else
        text = std::format("module:{}, code:{}. ", module, offset);
    output.append(text);
    for (std::uint32_t index = 0; index < count; ++index)
    {
        text = std::format("{:x} ", bytes[index]);
        output.append(text);
    }
    output.append("\n");
}

void WorldDiagnostics::appendCallStack(std::string &output)
{
    const auto &vm = g_sfera_mbc_runtime;
    std::string text;
    for (auto index = vm.execution_context_depth - 1; index >= 0; --index)
    {
        const auto &context = vm.execution_context_stack[index];
        if (context.process_index < 0)
        {
            text += "\nCall from C++\n";
            continue;
        }
        if (context.process_index < 0 || std::cmp_greater_equal(context.process_index, std::size(vm.processes)))
        {
            text += "\nInvalid call context\n";
            break;
        }
        const auto &process = vm.processes[context.process_index];
        if (context.process_id != process.process_id)
        {
            text += "\nError in prc call stack\n";
            break;
        }
        if (context.process_lifetime != process.lifetime || context.program_index < 0 || context.program_index >= process.programs.size())
        {
            text += "\nExpired call context\n";
            break;
        }
        const auto &program = process.programs[context.program_index];
        text += "\nPrevious prc: ";
        text += process.name;
        text += "\nProgram: ";
        text += program.name;
        text += '\n';
    }
    output.append(text);
}

std::optional<std::string_view> WorldDiagnostics::scriptContext()
{
    if (g_sfera_mbc_runtime.dispatch_slot < 0)
        return std::nullopt;
    auto &vm = g_sfera_mbc_runtime;
    describeScript(true);
    const auto &program = vm.program_table_base[vm.program_index];
    auto contextMessage = std::format("MBC-file: {}\nProgram: {}\nCall's depth: {}\nAddress: 0x{:08X}\n", vm.processes[vm.process_index].name, program.name, program.callDepth,
                                      (vm.current_instruction_address - vm.bytecode_base) + 32u);
    vm.diagnostic_context.append(contextMessage);
    appendCallStack(vm.diagnostic_context);
    return vm.diagnostic_context;
}

bool SferaMbcRuntime::reportError(std::string_view message)
{
    WorldDiagnostics::scriptContext();
    if (first_execution_error.empty())
        first_execution_error = std::format("{}\n{}", message, diagnostic_context);
    auto &log = g_sfera_log_runtime;
    log.write("\n---exit_inter start---\nMBINTER MESSAGE:");
    log.write(message);
    log.write("\n");
    log.write(diagnostic_context);
    log.write("---exit_inter end-----\n");
    execution_failed = true;
    if (process_index == 0)
    {
        CSphereError output;
        output.write(diagnostic_context);
    }
    return processes[0].activateProgram("EError");
}
bool SferaMbcRuntime::reportError(std::string_view prefix, std::string_view suffix)
{
    return reportError(std::format("{}{}", prefix, suffix));
}

void WorldDiagnostics::report(std::string_view text)
{
    SphereUIInterfaceRenderer::reportError(text);
}

[[noreturn]] void WorldDiagnostics::fail(std::string_view text)
{
    report(text);
    throw std::runtime_error(std::string(text.empty() ? std::string_view{"World operation failed"} : text));
}

void WorldDiagnostics::warning(std::string_view text)
{
    ::OutputDebugStringA(std::string(text).c_str());
    ::OutputDebugStringA("\n");
}
