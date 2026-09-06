#include "lifted_functions.h"
#include <cmath>
#include <cstddef>
#include <cstring>
#include <filesystem>
#include <vector>
namespace lifted {

static void sfera_u32_to_sso_decimal(LiftCpu* cpu) {
    const uint32_t destination = cpu->ecx;
    uint32_t value = *(uint32_t*)(cpu->edx);
    uint8_t reversed[16]{};
    std::size_t length = 0u;
    do {
        reversed[length++] = static_cast<uint8_t>('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);
    for (std::size_t index = 0u; index != 16u; ++index) {
        const uint8_t output = index < length ? reversed[length - index - 1u] : 0u;
        *(uint8_t*)(destination + static_cast<uint32_t>(index)) = output;
    }
    *(uint32_t*)(destination + 0x10u) = static_cast<uint32_t>(length);
    *(uint32_t*)(destination + 0x14u) = 15u;
    cpu->eax = destination;
}
__declspec(noinline) void sfera_sub_004BA370(LiftCpu* cpu, uint32_t stop_address) {
    const LiftCpu saved_cpu = *cpu;
    std::vector<std::filesystem::path> files;
    std::error_code error;
    for (std::filesystem::directory_iterator entry("Effects", error), end; !error && entry != end; entry.increment(error)) {
        if (entry->is_directory(error)) continue;
        if (SferaSimpleParser::equalsIgnoreCase(entry->path().extension().string().c_str(), ".ui")) files.push_back(entry->path());
    }
    float completed_fraction = 0.0f;
    const float file_fraction = files.empty() ? 0.0f : static_cast<float>(1.0 / static_cast<double>(files.size()));
    for (const auto& file : files) {
        if (SferaSimpleParser::equalsIgnoreCase(file.filename().string().c_str(), "loadscreen.ui")) continue;
        g_sfera_interface.loadWindowTemplates(file.string().c_str());
        completed_fraction += file_fraction;
        cpu->ecx = static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<double>(completed_fraction) * 30.0 + 30.0));
        lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA62Fu)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BA62Fu));
    }
    cpu->ebx = saved_cpu.ebx;
    cpu->ebp = saved_cpu.ebp;
    cpu->esi = saved_cpu.esi;
    cpu->edi = saved_cpu.edi;
    cpu->esp = saved_cpu.esp + 4u;
    cpu->eip = stop_address;
}
__declspec(noinline) void sfera_sub_004BC130(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_000BC181;
    lift_push32(cpu, cpu->ebp);
    label_000BC150:
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_000BC164;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC161u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC161u));
    cpu->esp += 4u;
    label_000BC164:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC177u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC177u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_000BC150;
    cpu->ebp = lift_pop32(cpu);
    label_000BC181:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_ui_tool_tip_ctrl_release(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->ToolTipCtrl::destroy(false); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_sub_004BCD80(LiftCpu* cpu, uint32_t stop_address) {
    const LiftCpu saved_cpu = *cpu;
    if (!g_sfera_interface.prepareResources()) {
        cpu->eax = 0u;
        cpu->esp += 4u;
        cpu->eip = stop_address;
        return;
    }
    cpu->ecx = 15u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEB5u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BCEB5u));
    g_sfera_interface.loadHyperTexts();
    cpu->ecx = 30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC4u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC9u)); sfera_sub_004BA370(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC9u));
    g_sfera_interface.finishInitialization();
    cpu->ebx = saved_cpu.ebx;
    cpu->ebp = saved_cpu.ebp;
    cpu->esi = saved_cpu.esi;
    cpu->edi = saved_cpu.edi;
    cpu->esp = saved_cpu.esp + 4u;
    cpu->eax = 1u;
    cpu->eip = stop_address;
}
__declspec(noinline) void sfera_ui_list_item_ctrl_item_at(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = address32(reinterpret_cast<SphereUI::ListItemCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->itemAt(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)))); cpu->esp += 8u; cpu->eip = stop_address; }


__declspec(noinline) void sfera_ui_pointer_vector_reserve_additional(LiftCpu* cpu, uint32_t stop_address) { auto* self = reinterpret_cast<SphereUI::UiIndexVector*>(static_cast<std::uintptr_t>(cpu->ecx)); const auto additional = *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)); if (additional > 0x3fffffffu - self->size()) throw std::length_error("UI pointer vector too long"); self->reserve(self->size() + additional); cpu->esp += 8u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_pointer_vector_append(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::UiIndexVector*>(static_cast<std::uintptr_t>(cpu->ecx))->append(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u))))); cpu->esp += 8u; cpu->eip = stop_address; }





} // namespace lifted
