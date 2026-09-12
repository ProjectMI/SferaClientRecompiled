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





__declspec(noinline) void sfera_ui_pointer_vector_reserve_additional(LiftCpu* cpu, uint32_t stop_address) { auto* self = reinterpret_cast<SphereUI::UiIndexVector*>(static_cast<std::uintptr_t>(cpu->ecx)); const auto additional = *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)); if (additional > 0x3fffffffu - self->size()) throw std::length_error("UI pointer vector too long"); self->reserve(self->size() + additional); cpu->esp += 8u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_pointer_vector_append(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::UiIndexVector*>(static_cast<std::uintptr_t>(cpu->ecx))->append(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u))))); cpu->esp += 8u; cpu->eip = stop_address; }





} // namespace lifted
