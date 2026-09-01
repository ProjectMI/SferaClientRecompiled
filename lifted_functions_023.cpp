#include "lifted_functions.h"
#include "semantic_zlib.h"
#include <cmath>
namespace lifted {

static uint32_t sfera_zlib_low_mask(uint32_t bit_count) { if (bit_count == 0u) { return 0u; } return bit_count >= 32u ? UINT32_MAX : (UINT32_C(1) << bit_count) - 1u; }
__declspec(noinline) void sfera_sub_004E0259(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate_slow(*(uint32_t*)(cpu->esp + 4u), (int32_t)*(uint32_t*)(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E0950(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t blocks_address = *(uint32_t*)(cpu->esp + 4u);
    const uint32_t stream_address = *(uint32_t*)(cpu->esp + 8u);
    const uint32_t check_value_address = *(uint32_t*)(cpu->esp + 0xCu);
    auto* stream = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(stream_address));
    auto* blocks = reinterpret_cast<SferaInflateBlocksCallbacks32*>(static_cast<uintptr_t>(blocks_address));
    if (check_value_address) *(uint32_t*)(check_value_address) = blocks->check_value;
    const uint32_t mode = *(uint32_t*)(blocks_address);
    if (mode == 4u || mode == 5u) stream->release(*(uint32_t*)(blocks_address + 0xCu));
    if (mode == 6u) stream->release(*(uint32_t*)(blocks_address + 4u));
    *(uint32_t*)(blocks_address) = 0u;
    *(uint32_t*)(blocks_address + 0x1Cu) = 0u;
    *(uint32_t*)(blocks_address + 0x20u) = 0u;
    *(uint32_t*)(blocks_address + 0x34u) = *(uint32_t*)(blocks_address + 0x28u);
    *(uint32_t*)(blocks_address + 0x30u) = *(uint32_t*)(blocks_address + 0x34u);
    if (blocks->check) { blocks->check_value = blocks->check(0u, 0u, 0u); stream->adler = blocks->check_value; }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E0A07(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream_address = *(uint32_t*)(cpu->esp + 4u);
    const bool checksum_enabled = *(uint32_t*)(cpu->esp + 8u) != 0u;
    const uint32_t window_size = *(uint32_t*)(cpu->esp + 0xCu);
    auto* stream = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(stream_address));
    const uint32_t blocks_address = stream->allocate(1u, 0x40u);
    if (!blocks_address) cpu->eax = 0u;
    else {
        const uint32_t hufts = stream->allocate(8u, 0x5A0u);
        if (!hufts) { stream->release(blocks_address); cpu->eax = 0u; }
        else {
            const uint32_t window = stream->allocate(1u, window_size);
            if (!window) { stream->release(hufts); stream->release(blocks_address); cpu->eax = 0u; }
            else {
                *(uint32_t*)(blocks_address + 0x24u) = hufts;
                *(uint32_t*)(blocks_address + 0x28u) = window;
                *(uint32_t*)(blocks_address + 0x2Cu) = window + window_size;
                auto* blocks = reinterpret_cast<SferaInflateBlocksCallbacks32*>(static_cast<uintptr_t>(blocks_address));
                blocks->check = checksum_enabled ? &sfera_zlib_adler32_callback : nullptr;
                *(uint32_t*)(blocks_address) = 0u;
                *(uint32_t*)(blocks_address + 0x1Cu) = 0u;
                *(uint32_t*)(blocks_address + 0x20u) = 0u;
                *(uint32_t*)(blocks_address + 0x34u) = window;
                *(uint32_t*)(blocks_address + 0x30u) = window;
                if (blocks->check) { blocks->check_value = blocks->check(0u, 0u, 0u); stream->adler = blocks->check_value; }
                cpu->eax = blocks_address;
            }
        }
    }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E0AFF(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x7Cu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ecx + 0x30u)) goto label_000E0B4D;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFACu) = cpu->ecx;
    goto label_000E0B59;
    label_000E0B4D:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFACu) = cpu->eax;
    label_000E0B59:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFACu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ecx;
    label_000E0B5F:
    cpu->edx = 1u;
    if (cpu->edx == 0u) goto label_000E1E36;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u) = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFA8u) > 9u) goto label_000E1DD2;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u);
    switch (cpu->edx) {
        case 0u: goto label_000E0B88;
        case 1u: goto label_000E0E13;
        case 2u: goto label_000E0F96;
        case 3u: goto label_000E11FB;
        case 4u: goto label_000E140A;
        case 5u: goto label_000E161B;
        case 6u: goto label_000E1B3C;
        case 7u: goto label_000E1C48;
        case 8u: goto label_000E1D11;
        case 9u: goto label_000E1D73;
        case 10u: goto label_000E0C61;
        case 11u: goto label_000E0C9E;
        case 12u: goto label_000E0D67;
        case 13u: goto label_000E0D87;
        default: lift_trap(cpu, 0x4E0B81u, "resolved jump-table index out of range"); return;
    }
    label_000E0B88:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) >= 3u) goto label_000E0C30;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == 0u) goto label_000E0BA1;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E0BFC;
    label_000E0BA1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0BF4u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E0BF4u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E0BFC:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx=0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    goto label_000E0B88;
    label_000E0C30:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax &= 7u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx&=1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA4u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFA4u) > 3u) goto label_000E0E0E;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFA4u);
    switch (cpu->ecx) {
        case 0u: goto label_000E0C61;
        case 1u: goto label_000E0C9E;
        case 2u: goto label_000E0D67;
        case 3u: goto label_000E0D87;
        default: lift_trap(cpu, 0x4E0C5Au, "resolved jump-table index out of range"); return;
    }
    label_000E0C61:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax -= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx&=7u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = 1u;
    goto label_000E0E0E;
    label_000E0C9E:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFD4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0CB7u)); sfera_sub_004E6EDB(cpu, LIFT_CODE_TOKEN_VA(0x4E0CB7u));
    cpu->esp += 0x14u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0CD3u)); sfera_sub_004E5600(cpu, LIFT_CODE_TOKEN_VA(0x4E0CD3u));
    cpu->esp += 0x14u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 4u) != 0u) goto label_000E0D47;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFCu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0D3Fu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E0D3Fu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E0D47:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = 6u;
    goto label_000E0E0E;
    label_000E0D67:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = 3u;
    goto label_000E0E0E;
    label_000E0D87:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = 9u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"invalid block type";
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0E06u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E0E06u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E0E0E:
    goto label_000E1E31;
    label_000E0E13:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) >= 0x20u) goto label_000E0EBB;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == 0u) goto label_000E0E2C;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E0E87;
    label_000E0E2C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0E7Fu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E0E7Fu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E0E87:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    goto label_000E0E13;
    label_000E0EBB:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = ~((uint64_t)(cpu->ecx));
    cpu->ecx >>= 16u;
    cpu->ecx &= 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx &= 0xFFFFu;
    if (cpu->ecx == cpu->edx) goto label_000E0F4B;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = 9u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"invalid stored block lengths";
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0F43u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E0F43u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E0F4B:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx &= 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 4u) == 0u) goto label_000E0F79;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA0u) = 2u;
    goto label_000E0F89;
    label_000E0F79:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    cpu->ecx = -cpu->ecx;
    cpu->ecx = (cpu->ecx != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ecx &= 7u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA0u) = cpu->ecx;
    label_000E0F89:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFA0u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    goto label_000E1E31;
    label_000E0F96:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) != 0u) goto label_000E0FF7;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E0FEFu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E0FEFu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E0FF7:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) != 0u) goto label_000E1163;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 0x2Cu)) goto label_000E1051;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    if (cpu->edx == *(uint32_t*)(cpu->ecx + 0x28u)) goto label_000E1051;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->eax >= *(uint32_t*)(cpu->edx + 0x30u)) goto label_000E103F;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF9Cu) = cpu->edx;
    goto label_000E104B;
    label_000E103F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF9Cu) = cpu->ecx;
    label_000E104B:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFF9Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edx;
    label_000E1051:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) != 0u) goto label_000E1163;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1075u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1075u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ecx + 0x30u)) goto label_000E10A0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF98u) = cpu->ecx;
    goto label_000E10AC;
    label_000E10A0:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF98u) = cpu->eax;
    label_000E10AC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFF98u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 0x2Cu)) goto label_000E1102;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x30u);
    if (cpu->eax == *(uint32_t*)(cpu->edx + 0x28u)) goto label_000E1102;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + 0x30u)) goto label_000E10F0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x30u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF94u) = cpu->eax;
    goto label_000E10FC;
    label_000E10F0:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF94u) = cpu->edx;
    label_000E10FC:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFF94u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    label_000E1102:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) != 0u) goto label_000E1163;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E115Bu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E115Bu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1163:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    if (cpu->eax <= *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u)) goto label_000E1181;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    label_000E1181:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    if (cpu->edx <= *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u)) goto label_000E118F;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    label_000E118F:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4E119Bu));
    cpu->esp += 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 4u) == 0u) goto label_000E11E4;
    goto label_000E1E31;
    label_000E11E4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    cpu->ecx = -cpu->ecx;
    cpu->ecx = (cpu->ecx != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ecx &= 7u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    goto label_000E1E31;
    label_000E11FB:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) >= 0xEu) goto label_000E12A3;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == 0u) goto label_000E1214;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E126F;
    label_000E1214:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1267u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1267u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E126F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx=0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    goto label_000E11FB;
    label_000E12A3:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax &= 0x3FFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax &= 0x1Fu;
    if (cpu->eax > 0x1Du) goto label_000E12D0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx >>= 5u;
    cpu->ecx &= 0x1Fu;
    if (cpu->ecx <= 0x1Du) goto label_000E1345;
    label_000E12D0:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = 9u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"too many length or distance symbols";
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E133Du)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E133Du));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1345:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx&=0x1Fu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx >>= 5u;
    cpu->edx &= 0x1Fu;
    cpu->eax = cpu->ecx + cpu->edx + 0x102u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->allocate(cpu->ecx, 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 0xCu) != 0u) goto label_000E13E5;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFCu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E13DDu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E13DDu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E13E5:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx >>= 14u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx -= 0xEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = 4u;
    label_000E140A:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax >>= 10u;
    cpu->eax += 4u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 8u) >= cpu->eax) goto label_000E150E;
    label_000E1422:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) >= 3u) goto label_000E14CC;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == 0u) goto label_000E143B;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E1496;
    label_000E143B:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E148Eu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E148Eu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1496:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    goto label_000E1422;
    label_000E14CC:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax &= 7u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ecx = cpu->edx < 3u ? 16u + cpu->edx : (cpu->edx == 3u ? 0u : ((cpu->edx & 1u) != 0u ? 10u - ((cpu->edx + 1u) >> 1u) : 6u + (cpu->edx >> 1u)));
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u)) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    ++cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    goto label_000E140A;
    label_000E150E:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 8u) >= 0x13u) goto label_000E1542;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx < 3u ? 16u + cpu->ecx : (cpu->ecx == 3u ? 0u : ((cpu->ecx & 1u) != 0u ? 10u - ((cpu->ecx + 1u) >> 1u) : 6u + (cpu->ecx >> 1u)));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    goto label_000E150E;
    label_000E1542:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 0x10u) = 7u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax += 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx += 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1571u)); sfera_sub_004E63E0(cpu, LIFT_CODE_TOKEN_VA(0x4E1571u));
    cpu->esp += 0x14u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) == 0u) goto label_000E1608;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->eax))->release(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0x10u) != 0xFFFFFFFDu) goto label_000E15AD;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = 9u;
    label_000E15AD:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1600u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1600u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1608:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 8u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = 5u;
    label_000E161B:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax&=0x1Fu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx >>= 5u;
    cpu->ecx &= 0x1Fu;
    cpu->edx = cpu->eax + cpu->ecx + 0x102u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 8u) >= cpu->edx) goto label_000E19AE;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    label_000E164F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (cpu->eax >= *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u)) goto label_000E16F9;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == 0u) goto label_000E166A;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E16C5;
    label_000E166A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E16BDu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E16BDu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E16C5:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    goto label_000E164F;
    label_000E16F9:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx&=(uint64_t)(sfera_zlib_low_mask(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) >= 0x10u) goto label_000E1766;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    goto label_000E19A9;
    label_000E1766:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) != 0x12u) goto label_000E1775;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF90u) = 7u;
    goto label_000E177E;
    label_000E1775:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    cpu->ecx -= 0xEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF90u) = cpu->ecx;
    label_000E177E:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFF90u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    cpu->eax -= 0x12u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(0xF8u))) & 0xFFu);
    cpu->eax += 0xBu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->eax;
    label_000E1796:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) >= cpu->ecx) goto label_000E1845;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == 0u) goto label_000E17B4;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E180F;
    label_000E17B4:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1807u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1807u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E180F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    goto label_000E1796;
    label_000E1845:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax&=(uint64_t)(sfera_zlib_low_mask(cpu->edx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    cpu->edx += *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax&=0x1Fu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx >>= 5u;
    cpu->ecx &= 0x1Fu;
    cpu->eax = cpu->eax + cpu->ecx + 0x102u;
    if (cpu->edx > cpu->eax) goto label_000E18C8;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) != 0x10u) goto label_000E1954;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) >= 1u) goto label_000E1954;
    label_000E18C8:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->eax))->release(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = 9u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"invalid bit length repeat";
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E194Cu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E194Cu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1954:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) != 0x10u) goto label_000E196C;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF8Cu) = cpu->edx;
    goto label_000E1973;
    label_000E196C:
    *(uint32_t*)(cpu->ebp + 0xFFFFFF8Cu) = 0u;
    label_000E1973:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFF8Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->eax;
    label_000E1979:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) != 0u) goto label_000E1979;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    label_000E19A9:
    goto label_000E161B;
    label_000E19AE:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 0x14u) = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB4u) = 9u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = 6u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFB8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax >>= 5u;
    cpu->eax &= 0x1Fu;
    cpu->eax += 1u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx &= 0x1Fu;
    cpu->ecx += 0x101u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1A10u)); sfera_sub_004E6D56(cpu, LIFT_CODE_TOKEN_VA(0x4E1A10u));
    cpu->esp += 0x24u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->ecx))->release(cpu->eax);
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) == 0u) goto label_000E1AA3;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) != 0xFFFFFFFDu) goto label_000E1A42;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = 9u;
    label_000E1A42:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1A9Bu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1A9Bu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1AA3:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1ABCu)); sfera_sub_004E5600(cpu, LIFT_CODE_TOKEN_VA(0x4E1ABCu));
    cpu->esp += 0x14u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFBCu) != 0u) goto label_000E1B2A;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFCu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1B22u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1B22u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1B2A:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = 6u;
    label_000E1B3C:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1B8Fu)); sfera_sub_004E5655(cpu, LIFT_CODE_TOKEN_VA(0x4E1B8Fu));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0x10u) == 1u) goto label_000E1BB4;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1BACu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1BACu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1BB4:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1BCBu)); sfera_sub_004E63BD(cpu, LIFT_CODE_TOKEN_VA(0x4E1BCBu));
    cpu->esp += 8u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + 0x30u)) goto label_000E1C16;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x30u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF88u) = cpu->eax;
    goto label_000E1C22;
    label_000E1C16:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF88u) = cpu->edx;
    label_000E1C22:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFF88u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 0x18u) != 0u) goto label_000E1C3F;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = 0u;
    goto label_000E1E31;
    label_000E1C3F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = 7u;
    label_000E1C48:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1C62u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1C62u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->eax >= *(uint32_t*)(cpu->edx + 0x30u)) goto label_000E1C8D;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF84u) = cpu->edx;
    goto label_000E1C99;
    label_000E1C8D:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF84u) = cpu->ecx;
    label_000E1C99:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFF84u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    if (cpu->edx == *(uint32_t*)(cpu->ecx + 0x34u)) goto label_000E1D08;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1D00u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1D00u));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1D08:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = 8u;
    label_000E1D11:
    *(uint32_t*)(cpu->ebp + 0x10u) = 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1D6Bu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1D6Bu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1D73:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1DCDu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1DCDu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1DD2:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFEu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1E2Cu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E1E2Cu));
    cpu->esp += 0xCu;
    goto label_000E1E36;
    label_000E1E31:
    goto label_000E0B5F;
    label_000E1E36:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E1E72(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E1E84u)); sfera_sub_004E0950(cpu, LIFT_CODE_TOKEN_VA(0x4E1E84u));
    cpu->esp += 0xCu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->ecx))->release(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->eax))->release(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->ecx))->release(cpu->eax);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E2200(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_tree_init(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E2296(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E229B(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_init_block(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E2364(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_write_stored_block(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u), *(uint32_t*)(cpu->esp + 16u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E24A3(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_align_static_block(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E2992(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_flush_block(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u), *(uint32_t*)(cpu->esp + 16u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E2D4E(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_build_tree(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E30EE(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_pq_down_heap(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E328D(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_generate_bit_lengths(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E35C0(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_generate_codes(*(uint32_t*)(cpu->esp + 4u), (int32_t)*(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E3685(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_build_bit_length_tree(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E373C(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_scan_tree(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), (int32_t)*(uint32_t*)(cpu->esp + 12u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E38D9(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_send_all_trees(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u), *(uint32_t*)(cpu->esp + 16u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E3DFC(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_send_tree(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), (int32_t)*(uint32_t*)(cpu->esp + 12u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E4A02(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_compress_block(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E524A(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_set_data_type(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E52FC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_bit_reverse(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E533D(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_bit_flush(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E5426(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_bit_windup(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E54E2(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_copy_stored_block(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u), *(uint32_t*)(cpu->esp + 16u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E5600(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream_address = *(uint32_t*)(cpu->esp + 0x14u);
    auto* stream = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(stream_address));
    const uint32_t state = stream->allocate(1u, 0x1Cu);
    if (state) { *(uint32_t*)(state) = 0u; *(uint8_t*)(state + 0x10u) = static_cast<uint8_t>(*(uint32_t*)(cpu->esp + 4u)); *(uint8_t*)(state + 0x11u) = static_cast<uint8_t>(*(uint32_t*)(cpu->esp + 8u)); *(uint32_t*)(state + 0x14u) = *(uint32_t*)(cpu->esp + 0xCu); *(uint32_t*)(state + 0x18u) = *(uint32_t*)(cpu->esp + 0x10u); }
    cpu->eax = state;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E5655(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x58u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + 0x30u)) goto label_000E56AC;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x30u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->eax;
    goto label_000E56B8;
    label_000E56AC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->edx;
    label_000E56B8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    label_000E56BE:
    cpu->ecx = 1u;
    if (cpu->ecx == 0u) goto label_000E6391;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) > 9u) goto label_000E632D;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    switch (cpu->ecx) {
        case 0u: goto label_000E56E7;
        case 1u: goto label_000E5810;
        case 2u: goto label_000E5A11;
        case 3u: goto label_000E5B16;
        case 4u: goto label_000E5CDD;
        case 5u: goto label_000E5DC8;
        case 6u: goto label_000E5FE4;
        case 7u: goto label_000E6182;
        case 8u: goto label_000E626C;
        case 9u: goto label_000E62CE;
        default: lift_trap(cpu, 0x4E56E0u, "resolved jump-table index out of range"); return;
    }
label_000E56E7: ;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) < 0x102u) goto label_000E57ED;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) < 0xAu) goto label_000E57ED;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 0x11u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 0x10u));
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E576Du)); sfera_sub_004E70F0(cpu, LIFT_CODE_TOKEN_VA(0x4E576Du));
    cpu->esp += 0x18u;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ecx + 0x30u)) goto label_000E57BB;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->ecx;
    goto label_000E57C7;
    label_000E57BB:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->eax;
    label_000E57C7:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0x10u) == 0u) goto label_000E57ED;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx -= 1u;
    cpu->edx = -cpu->edx;
    cpu->edx = (cpu->edx != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 2u;
    cpu->edx += 7u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    goto label_000E638C;
    label_000E57ED:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 0x10u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx) = 1u;
    label_000E5810:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->eax;
    label_000E5819:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    if (cpu->ecx >= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u)) goto label_000E58C5;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) == 0u) goto label_000E5834;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E588F;
    label_000E5834:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5887u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5887u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E588F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->edx;
    goto label_000E5819;
    label_000E58C5:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx&=(uint64_t)(sfera_zlib_low_mask(cpu->eax));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->ecx = cpu->eax + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 1u));
    cpu->ecx = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) != 0u) goto label_000E592A;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 6u;
    goto label_000E638C;
    label_000E592A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax &= 0x10u;
    if (cpu->eax == 0u) goto label_000E595A;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx &= 0xFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax) = 2u;
    goto label_000E638C;
    label_000E595A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx &= 0x40u;
    if (cpu->ecx != 0u) goto label_000E5984;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = cpu->eax + (cpu->edx * 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    goto label_000E638C;
    label_000E5984:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax &= 0x20u;
    if (cpu->eax == 0u) goto label_000E599C;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx) = 7u;
    goto label_000E638C;
    label_000E599C:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 9u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"invalid literal/length code";
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5A09u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5A09u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E5A11:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->edx;
    label_000E5A1A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    if (cpu->eax >= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u)) goto label_000E5AC4;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) == 0u) goto label_000E5A35;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E5A90;
    label_000E5A35:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5A88u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5A88u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E5A90:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->eax <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->eax += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->eax;
    goto label_000E5A1A;
    label_000E5AC4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx&=(uint64_t)(sfera_zlib_low_mask(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->eax >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 0x11u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 3u;
    label_000E5B16:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ecx;
    label_000E5B1F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    if (cpu->edx >= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u)) goto label_000E5BC9;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) == 0u) goto label_000E5B3A;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E5B95;
    label_000E5B3A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5B8Du)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5B8Du));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E5B95:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx=0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->edx;
    goto label_000E5B1F;
    label_000E5BC9:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx&=(uint64_t)(sfera_zlib_low_mask(cpu->eax));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->ecx = cpu->eax + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 1u));
    cpu->ecx = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx &= 0x10u;
    if (cpu->edx == 0u) goto label_000E5C3E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax &= 0xFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 4u;
    goto label_000E638C;
    label_000E5C3E:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax &= 0x40u;
    if (cpu->eax != 0u) goto label_000E5C68;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = cpu->edx + (cpu->ecx * 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    goto label_000E638C;
    label_000E5C68:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 9u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"invalid distance code";
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5CD5u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5CD5u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E5CDD:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->edx;
    label_000E5CE6:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    if (cpu->eax >= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u)) goto label_000E5D90;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) == 0u) goto label_000E5D01;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    goto label_000E5D5C;
    label_000E5D01:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5D54u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5D54u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E5D5C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->eax <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->eax += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->eax;
    goto label_000E5CE6;
    label_000E5D90:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx&=(uint64_t)(sfera_zlib_low_mask(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->eax >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 5u;
    label_000E5DC8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= *(uint32_t*)(cpu->eax + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    if (cpu->ecx >= *(uint32_t*)(cpu->edx + 0xCu)) goto label_000E5DF7;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= *(uint32_t*)(cpu->eax + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->eax -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx -= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->edx;
    goto label_000E5E03;
    label_000E5DF7:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->ecx;
    label_000E5E03:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    label_000E5E09:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    if (*(uint32_t*)(cpu->eax + 4u) == 0u) goto label_000E5FD6;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) != 0u) goto label_000E5F82;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 0x2Cu)) goto label_000E5E70;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    if (cpu->edx == *(uint32_t*)(cpu->ecx + 0x28u)) goto label_000E5E70;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->eax >= *(uint32_t*)(cpu->edx + 0x30u)) goto label_000E5E5E;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->edx;
    goto label_000E5E6A;
    label_000E5E5E:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->ecx;
    label_000E5E6A:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    label_000E5E70:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) != 0u) goto label_000E5F82;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5E94u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5E94u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ecx + 0x30u)) goto label_000E5EBF;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu) = cpu->ecx;
    goto label_000E5ECB;
    label_000E5EBF:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu) = cpu->eax;
    label_000E5ECB:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 0x2Cu)) goto label_000E5F21;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x30u);
    if (cpu->eax == *(uint32_t*)(cpu->edx + 0x28u)) goto label_000E5F21;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + 0x30u)) goto label_000E5F0F;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x30u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u) = cpu->eax;
    goto label_000E5F1B;
    label_000E5F0F:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u) = cpu->edx;
    label_000E5F1B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    label_000E5F21:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) != 0u) goto label_000E5F82;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E5F7Au)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E5F7Au));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E5F82:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 0x2Cu)) goto label_000E5FC2;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    label_000E5FC2:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax -= 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_000E5E09;
    label_000E5FD6:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 0u;
    goto label_000E638C;
    label_000E5FE4:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) != 0u) goto label_000E6150;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 0x2Cu)) goto label_000E603E;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x30u);
    if (cpu->ecx == *(uint32_t*)(cpu->eax + 0x28u)) goto label_000E603E;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ecx + 0x30u)) goto label_000E602C;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB4u) = cpu->ecx;
    goto label_000E6038;
    label_000E602C:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB4u) = cpu->eax;
    label_000E6038:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFB4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    label_000E603E:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) != 0u) goto label_000E6150;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E6062u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E6062u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + 0x30u)) goto label_000E608D;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x30u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB0u) = cpu->eax;
    goto label_000E6099;
    label_000E608D:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB0u) = cpu->edx;
    label_000E6099:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFB0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 0x2Cu)) goto label_000E60EF;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    if (cpu->edx == *(uint32_t*)(cpu->ecx + 0x28u)) goto label_000E60EF;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->eax >= *(uint32_t*)(cpu->edx + 0x30u)) goto label_000E60DD;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFACu) = cpu->edx;
    goto label_000E60E9;
    label_000E60DD:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFACu) = cpu->ecx;
    label_000E60E9:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFACu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    label_000E60EF:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) != 0u) goto label_000E6150;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E6148u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E6148u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E6150:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 8u));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 0u;
    goto label_000E638C;
    label_000E6182:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) <= 7u) goto label_000E61A3;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->eax -= 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    label_000E61A3:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E61BDu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E61BDu));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ecx + 0x30u)) goto label_000E61E8;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u) = cpu->ecx;
    goto label_000E61F4;
    label_000E61E8:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u) = cpu->eax;
    label_000E61F4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x30u);
    if (cpu->ecx == *(uint32_t*)(cpu->eax + 0x34u)) goto label_000E6263;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E625Bu)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E625Bu));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E6263:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = 8u;
    label_000E626C:
    *(uint32_t*)(cpu->ebp + 0x10u) = 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E62C6u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E62C6u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E62CE:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFDu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E6328u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E6328u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E632D:
    *(uint32_t*)(cpu->ebp + 0x10u) = 0xFFFFFFFEu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E6387u)); sfera_sub_004E6F10(cpu, LIFT_CODE_TOKEN_VA(0x4E6387u));
    cpu->esp += 0xCu;
    goto label_000E6391;
    label_000E638C:
    goto label_000E56BE;
    label_000E6391:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E63BD(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t address = *(uint32_t*)(cpu->esp + 4u);
    auto* stream = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(*(uint32_t*)(cpu->esp + 8u)));
    stream->release(address);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E63E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->allocate(0x13u, 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) != 0u) goto label_000E6411;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000E6484;
    label_000E6411:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFF8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x13u); lift_push32(cpu, 0x13u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E6436u)); sfera_sub_004E6488(cpu, LIFT_CODE_TOKEN_VA(0x4E6436u));
    cpu->esp += 0x28u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0xFFFFFFFDu) goto label_000E644E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"oversubscribed dynamic bit lengths tree";
    goto label_000E646D;
    label_000E644E:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) == 0xFFFFFFFBu) goto label_000E645C;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    if (*(uint32_t*)(cpu->ecx) != 0u) goto label_000E646D;
    label_000E645C:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    *(uint32_t*)(cpu->edx + 0x18u) = (uintptr_t)"incomplete dynamic bit lengths tree";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFDu;
    label_000E646D:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->ecx))->release(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    label_000E6484:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E6488(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_huft_build(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u), *(uint32_t*)(cpu->esp + 16u), *(uint32_t*)(cpu->esp + 20u), *(uint32_t*)(cpu->esp + 24u), *(uint32_t*)(cpu->esp + 28u), *(uint32_t*)(cpu->esp + 32u), *(uint32_t*)(cpu->esp + 36u), *(uint32_t*)(cpu->esp + 40u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E6D56(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->allocate(0x120u, 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) != 0u) goto label_000E6D8D;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000E6ED7;
    label_000E6D8D:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFF8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x101u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E6DBDu)); sfera_sub_004E6488(cpu, LIFT_CODE_TOKEN_VA(0x4E6DBDu));
    cpu->esp += 0x28u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0u) goto label_000E6DD1;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (*(uint32_t*)(cpu->ecx) != 0u) goto label_000E6E16;
    label_000E6DD1:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0xFFFFFFFDu) goto label_000E6DE3;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    *(uint32_t*)(cpu->edx + 0x18u) = (uintptr_t)"oversubscribed literal/length tree";
    goto label_000E6DFA;
    label_000E6DE3:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) == 0xFFFFFFFCu) goto label_000E6DFA;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x28u);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"incomplete literal/length tree";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFDu;
    label_000E6DFA:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->release(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    goto label_000E6ED7;
    label_000E6E16:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFF8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4E6E49u)); sfera_sub_004E6488(cpu, LIFT_CODE_TOKEN_VA(0x4E6E49u));
    cpu->esp += 0x28u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0u) goto label_000E6E66;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    if (*(uint32_t*)(cpu->edx) != 0u) goto label_000E6EC1;
    if (*(uint32_t*)(cpu->ebp + 8u) <= 0x101u) goto label_000E6EC1;
    label_000E6E66:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0xFFFFFFFDu) goto label_000E6E78;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x28u);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"oversubscribed distance tree";
    goto label_000E6EA8;
    label_000E6E78:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0xFFFFFFFBu) goto label_000E6E91;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x28u);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"incomplete distance tree";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFDu;
    goto label_000E6EA8;
    label_000E6E91:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) == 0xFFFFFFFCu) goto label_000E6EA8;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    *(uint32_t*)(cpu->edx + 0x18u) = (uintptr_t)"empty distance tree with lengths";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFDu;
    label_000E6EA8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x28u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->ecx))->release(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    goto label_000E6ED7;
    label_000E6EC1:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->release(cpu->ecx);
    cpu->eax = 0u;
    label_000E6ED7:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E6EDB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_inflate_fixed(*(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u), *(uint32_t*)(cpu->esp + 12u), *(uint32_t*)(cpu->esp + 16u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E6F10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x30u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx > *(uint32_t*)(cpu->ecx + 0x34u)) goto label_000E6F3E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    goto label_000E6F47;
    label_000E6F3E:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    label_000E6F47:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    if (cpu->eax <= *(uint32_t*)(cpu->edx + 0x10u)) goto label_000E6F64;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    label_000E6F64:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) == 0u) goto label_000E6F77;
    if (*(uint32_t*)(cpu->ebp + 0x10u) != 0xFFFFFFFBu) goto label_000E6F77;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    label_000E6F77:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ecx += *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 0x14u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 0x38u) == 0u) goto label_000E6FC8;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaInflateBlocksCallbacks32*>(static_cast<uintptr_t>(cpu->eax))->check(*(uint32_t*)(cpu->eax + 0x3Cu), cpu->edx, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x3Cu);
    *(uint32_t*)(cpu->edx + 0x30u) = cpu->ecx;
    label_000E6FC8:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4E6FD4u));
    cpu->esp += 0xCu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx += *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 0x2Cu)) goto label_000E70CA;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x34u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 0x2Cu)) goto label_000E7020;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->ecx;
    label_000E7020:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x34u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    if (cpu->edx <= *(uint32_t*)(cpu->ecx + 0x10u)) goto label_000E7040;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    label_000E7040:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) == 0u) goto label_000E7053;
    if (*(uint32_t*)(cpu->ebp + 0x10u) != 0xFFFFFFFBu) goto label_000E7053;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    label_000E7053:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 0x38u) == 0u) goto label_000E70A4;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaInflateBlocksCallbacks32*>(static_cast<uintptr_t>(cpu->edx))->check(*(uint32_t*)(cpu->edx + 0x3Cu), cpu->ecx, cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 0x3Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x3Cu);
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->edx;
    label_000E70A4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4E70B0u));
    cpu->esp += 0xCu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx += *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    label_000E70CA:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x30u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E70F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x48u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x34u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ecx + 0x30u)) goto label_000E713E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->ecx;
    goto label_000E714A;
    label_000E713E:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->eax;
    label_000E714A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = sfera_zlib_low_mask(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = sfera_zlib_low_mask(cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->edx;
    label_000E716A:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) >= 0x14u) goto label_000E71A1;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx=0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    goto label_000E716A;
    label_000E71A1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax &= *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) != 0u) goto label_000E7204;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 1u));
    cpu->ecx = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 4u));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    goto label_000E772A;
    label_000E7204:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 1u));
    cpu->ecx = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->eax &= 0x10u;
    if (cpu->eax == 0u) goto label_000E754B;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx &= 0xFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax&=(uint64_t)(sfera_zlib_low_mask(cpu->edx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->eax >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    label_000E7269:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) >= 0xFu) goto label_000E72A2;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    goto label_000E7269;
    label_000E72A2:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax &= *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ecx;
    label_000E72BB:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 1u));
    cpu->ecx = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->eax &= 0x10u;
    if (cpu->eax == 0u) goto label_000E7457;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx &= 0xFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ecx;
    label_000E72F4:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    if (cpu->edx >= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u)) goto label_000E732D;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->eax -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx=0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    goto label_000E72F4;
    label_000E732D:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx&=(uint64_t)(sfera_zlib_low_mask(cpu->eax));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax -= *(uint32_t*)(cpu->edx + 0x28u);
    if (cpu->eax < *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u)) goto label_000E73C5;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    goto label_000E7427;
    label_000E73C5:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax -= *(uint32_t*)(cpu->edx + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (cpu->ecx <= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u)) goto label_000E7427;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    label_000E73F3:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->edx;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) != 0u) goto label_000E73F3;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    label_000E7427:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) != 0u) goto label_000E7427;
    goto label_000E7546;
    label_000E7457:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edx &= 0x40u;
    if (cpu->edx != 0u) goto label_000E7495;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = cpu->edx + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx&=(uint64_t)(sfera_zlib_low_mask(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = cpu->eax + (cpu->edx * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->eax;
    goto label_000E7539;
    label_000E7495:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"invalid distance code";
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx >>= 3u;
    if (cpu->ecx >= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000E74C1;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->edx;
    goto label_000E74C7;
    label_000E74C1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->eax;
    label_000E74C7:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->edx += *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx <<= 3u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = 0xFFFFFFFDu;
    goto label_000E77CF;
    label_000E7539:
    cpu->eax = 1u;
    if (cpu->eax != 0u) goto label_000E72BB;
    label_000E7546:
    goto label_000E772A;
    label_000E754B:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx &= 0x40u;
    if (cpu->ecx != 0u) goto label_000E75D1;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx&=(uint64_t)(sfera_zlib_low_mask(cpu->eax));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = cpu->edx + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->edx;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) != 0u) goto label_000E75CC;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx >>= (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 4u));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx -= 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    goto label_000E772A;
    label_000E75CC:
    goto label_000E771D;
    label_000E75D1:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edx &= 0x20u;
    if (cpu->edx == 0u) goto label_000E7679;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx >>= 3u;
    if (cpu->edx >= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000E7601;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->eax;
    goto label_000E7607;
    label_000E7601:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->ecx;
    label_000E7607:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx <<= 3u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x34u) = cpu->eax;
    cpu->eax = 1u;
    goto label_000E77CF;
    label_000E7679:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"invalid literal/length code";
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx >>= 3u;
    if (cpu->ecx >= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000E76A5;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu) = cpu->edx;
    goto label_000E76AB;
    label_000E76A5:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu) = cpu->eax;
    label_000E76AB:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFBCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->edx += *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx <<= 3u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx -= *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->eax = 0xFFFFFFFDu;
    goto label_000E77CF;
    label_000E771D:
    cpu->eax = 1u;
    if (cpu->eax != 0u) goto label_000E7204;
    label_000E772A:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) < 0x102u) goto label_000E773D;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) >= 0xAu) goto label_000E716A;
    label_000E773D:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->eax >>= 3u;
    if (cpu->eax >= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000E775F;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx >>= 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u) = cpu->ecx;
    goto label_000E7765;
    label_000E775F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u) = cpu->edx;
    label_000E7765:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->ecx += *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax <<= 3u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->eax -= *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    cpu->eax = 0u;
    label_000E77CF:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004E787C(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[77];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = 0x88760233u;
    sub_pred[0] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8D8E;
    if (sub_pred[0]) goto label_000E8D84;
    cpu->ecx = 0x80070492u;
    sub_pred[1] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E81B1;
    if (sub_pred[1]) goto label_000E81A7;
    cpu->ecx = 0x80040261u;
    sub_pred[2] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E7CF7;
    if (sub_pred[2]) goto label_000E7CED;
    cpu->ecx += 0xFFFFFFC0u;
    sub_pred[3] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E7B37;
    if (sub_pred[3]) goto label_000E7B2D;
    cpu->ecx = 0x8004020Bu;
    sub_pred[4] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E7A46;
    if (sub_pred[4]) goto label_000E7A3C;
    cpu->ecx += 0xFFFFFFF5u;
    sub_pred[5] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E79C3;
    if (sub_pred[5]) goto label_000E79B9;
    cpu->ecx = 0x80004005u;
    sub_pred[6] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E7960;
    if (sub_pred[6]) goto label_000E7956;
    if (cpu->eax == 0x8000000Au) goto label_000E794C;
    if (cpu->eax == 0x80004001u) goto label_000E7942;
    if (cpu->eax == 0x80004002u) goto label_000E7938;
    if (cpu->eax == 0x80004003u) goto label_000E792E;
    if (cpu->eax != 0x80004004u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Operation aborted";
    goto label_000EA1A9;
    label_000E792E:
    cpu->eax = (uintptr_t)"Invalid pointer";
    goto label_000EA1A9;
    label_000E7938:
    cpu->eax = (uintptr_t)"The requested COM interface is not available";
    goto label_000EA1A9;
    label_000E7942:
    cpu->eax = (uintptr_t)"The function called is not supported at this time";
    goto label_000EA1A9;
    label_000E794C:
    cpu->eax = (uintptr_t)"The data necessary to complete this operation is not yet available.";
    goto label_000EA1A9;
    label_000E7956:
    cpu->eax = (uintptr_t)"An undetermined error occurred";
    goto label_000EA1A9;
    label_000E7960:
    if (cpu->eax == 0x8000FFFFu) goto label_000E79AF;
    if (cpu->eax == 0x80040110u) goto label_000E79A5;
    if (cpu->eax == 0x80040154u) goto label_000E799B;
    if (cpu->eax == 0x800401F0u) goto label_000E7991;
    if (cpu->eax != 0x800401F1u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"CoInitialize has already been called.";
    goto label_000EA1A9;
    label_000E7991:
    cpu->eax = (uintptr_t)"CoInitialize has not been called.";
    goto label_000EA1A9;
    label_000E799B:
    cpu->eax = (uintptr_t)"Class not registered";
    goto label_000EA1A9;
    label_000E79A5:
    cpu->eax = (uintptr_t)"This object does not support aggregation";
    goto label_000EA1A9;
    label_000E79AF:
    cpu->eax = (uintptr_t)"Catastrophic failure";
    goto label_000EA1A9;
    label_000E79B9:
    cpu->eax = (uintptr_t)"Unable to IDirectInputJoyConfig_Acquire because the user does not have sufficient privileges to change the joystick configuration. & An invalid media type was specified";
    goto label_000EA1A9;
    label_000E79C3:
    cpu->eax += 0x7FFBFDFFu;
    if (cpu->eax > 9u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E79D8;
        case 1u: goto label_000E79E2;
        case 2u: goto label_000E79EC;
        case 3u: goto label_000E79F6;
        case 4u: goto label_000E7A00;
        case 5u: goto label_000E7A0A;
        case 6u: goto label_000E7A14;
        case 7u: goto label_000E7A1E;
        case 8u: goto label_000E7A28;
        case 9u: goto label_000E7A32;
        case 10u: goto label_000E7A5B;
        case 11u: goto label_000E7A65;
        case 12u: goto label_000E7A6F;
        case 13u: goto label_000E7A79;
        case 14u: goto label_000E7A83;
        case 15u: goto label_000E7A8D;
        case 16u: goto label_000E7A97;
        case 17u: goto label_000E7AA1;
        case 18u: goto label_000E7AAB;
        case 19u: goto label_000E7AB5;
        case 20u: goto label_000E7ABF;
        case 21u: goto label_000E7AC9;
        case 22u: goto label_000E7AD3;
        case 23u: goto label_000E7ADD;
        case 24u: goto label_000E7AE7;
        case 25u: goto label_000E7AF1;
        case 26u: goto label_000E7AFB;
        case 27u: goto label_000E7B05;
        case 28u: goto label_000E7B0F;
        case 29u: goto label_000E7B19;
        case 30u: goto label_000E7B23;
        case 31u: goto label_000E7B53;
        case 32u: goto label_000E7B5D;
        case 33u: goto label_000E7B67;
        case 34u: goto label_000E7B71;
        case 35u: goto label_000E7B7B;
        case 36u: goto label_000E7B85;
        case 37u: goto label_000E7B8F;
        case 38u: goto label_000E7B99;
        case 39u: goto label_000E7BA3;
        case 40u: goto label_000E7BAD;
        case 41u: goto label_000E7BB7;
        case 42u: goto label_000E7BC1;
        case 43u: goto label_000E7BCB;
        case 44u: goto label_000E7BD5;
        case 45u: goto label_000E7BDF;
        case 46u: goto label_000E7BE9;
        case 47u: goto label_000E7BF3;
        case 48u: goto label_000E7BFD;
        case 49u: goto label_000E7C07;
        case 50u: goto label_000E7C11;
        case 51u: goto label_000E7C1B;
        case 52u: goto label_000E7C25;
        case 53u: goto label_000E7C2F;
        case 54u: goto label_000E7C39;
        case 55u: goto label_000E7C43;
        case 56u: goto label_000E7C4D;
        case 57u: goto label_000E7C57;
        case 58u: goto label_000E7C61;
        case 59u: goto label_000E7C6B;
        case 60u: goto label_000E7C75;
        case 61u: goto label_000E7C7F;
        case 62u: goto label_000E7C89;
        case 63u: goto label_000E7C93;
        case 64u: goto label_000E7C9D;
        case 65u: goto label_000E7CA7;
        case 66u: goto label_000E9FC6;
        case 67u: goto label_000E7CB1;
        case 68u: goto label_000EA03B;
        case 69u: goto label_000E7CBB;
        case 70u: goto label_000E7CC5;
        case 71u: goto label_000E7CCF;
        case 72u: goto label_000E7CD9;
        case 73u: goto label_000E7CE3;
        case 74u: goto label_000EA18F;
        default: lift_trap(cpu, 0x4E79D1u, "resolved jump-table index out of range"); return;
    }
label_000E79D8: ;
    cpu->eax = (uintptr_t)"The device is full. & An invalid media subtype was specified.";
    goto label_000EA1A9;
    label_000E79E2:
    cpu->eax = (uintptr_t)"Not all the requested information fit into the buffer. & This object can only be created as an aggregated object.";
    goto label_000EA1A9;
    label_000E79EC:
    cpu->eax = (uintptr_t)"The effect is not downloaded. & The enumerator has become invalid.";
    goto label_000EA1A9;
    label_000E79F6:
    cpu->eax = (uintptr_t)"The device cannot be reinitialized because there are still effects attached to it. & At least one of the pins involved in the operation is already connected.";
    goto label_000EA1A9;
    label_000E7A00:
    cpu->eax = (uintptr_t)"The operation cannot be performed unless the device is acquired in DISCL_EXCLUSIVE mode. & This operation cannot be performed because the filter is active.";
    goto label_000EA1A9;
    label_000E7A0A:
    cpu->eax = (uintptr_t)"The effect could not be downloaded because essential information is missing.  For example, no axes have been associated with the effect, or no type-specific information has been created. & One of the specified pins supports no media types.";
    goto label_000EA1A9;
    label_000E7A14:
    cpu->eax = (uintptr_t)"Attempted to read buffered device data from a device that is not buffered. & There is no common media type between these pins.";
    goto label_000EA1A9;
    label_000E7A1E:
    cpu->eax = (uintptr_t)"An attempt was made to modify parameters of an effect while it is playing.  Not all hardware devices support altering the parameters of an effect while it is playing. & Two pins of the same direction cannot be connected together.";
    goto label_000EA1A9;
    label_000E7A28:
    cpu->eax = (uintptr_t)"The operation could not be completed because the device is not plugged in. & The operation cannot be performed because the pins are not connected.";
    goto label_000EA1A9;
    label_000E7A32:
    cpu->eax = (uintptr_t)"SendDeviceData failed because more information was requested to be sent than can be sent to the device.  Some devices have restrictions on how much data can be sent to them.  (For example, there might be a limit on the number of buttons that can be pressed at once.) & No sample buffer allocator is available.";
    goto label_000EA1A9;
    label_000E7A3C:
    cpu->eax = (uintptr_t)"A mapper file function failed because reading or writing the user or IHV settings file failed. & A run-time error occurred.";
    goto label_000EA1A9;
    label_000E7A46:
    cpu->eax += 0x7FFBFDF4u;
    if (cpu->eax > 0x14u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E7A5B;
        case 1u: goto label_000E7A65;
        case 2u: goto label_000E7A6F;
        case 3u: goto label_000E7A79;
        case 4u: goto label_000E7A83;
        case 5u: goto label_000E7A8D;
        case 6u: goto label_000E7A97;
        case 7u: goto label_000E7AA1;
        case 8u: goto label_000E7AAB;
        case 9u: goto label_000E7AB5;
        case 10u: goto label_000E7ABF;
        case 11u: goto label_000E7AC9;
        case 12u: goto label_000E7AD3;
        case 13u: goto label_000E7ADD;
        case 14u: goto label_000E7AE7;
        case 15u: goto label_000E7AF1;
        case 16u: goto label_000E7AFB;
        case 17u: goto label_000E7B05;
        case 18u: goto label_000E7B0F;
        case 19u: goto label_000E7B19;
        case 20u: goto label_000E7B23;
        case 21u: goto label_000E7B53;
        case 22u: goto label_000E7B5D;
        case 23u: goto label_000E7B67;
        case 24u: goto label_000E7B71;
        case 25u: goto label_000E7B7B;
        case 26u: goto label_000E7B85;
        case 27u: goto label_000E7B8F;
        case 28u: goto label_000E7B99;
        case 29u: goto label_000E7BA3;
        case 30u: goto label_000E7BAD;
        case 31u: goto label_000E7BB7;
        case 32u: goto label_000E7BC1;
        case 33u: goto label_000E7BCB;
        case 34u: goto label_000E7BD5;
        case 35u: goto label_000E7BDF;
        case 36u: goto label_000E7BE9;
        case 37u: goto label_000E7BF3;
        case 38u: goto label_000E7BFD;
        case 39u: goto label_000E7C07;
        case 40u: goto label_000E7C11;
        case 41u: goto label_000E7C1B;
        case 42u: goto label_000E7C25;
        case 43u: goto label_000E7C2F;
        case 44u: goto label_000E7C39;
        case 45u: goto label_000E7C43;
        case 46u: goto label_000E7C4D;
        case 47u: goto label_000E7C57;
        case 48u: goto label_000E7C61;
        case 49u: goto label_000E7C6B;
        case 50u: goto label_000E7C75;
        case 51u: goto label_000E7C7F;
        case 52u: goto label_000E7C89;
        case 53u: goto label_000E7C93;
        case 54u: goto label_000E7C9D;
        case 55u: goto label_000E7CA7;
        case 56u: goto label_000E9FC6;
        case 57u: goto label_000E7CB1;
        case 58u: goto label_000EA03B;
        case 59u: goto label_000E7CBB;
        case 60u: goto label_000E7CC5;
        case 61u: goto label_000E7CCF;
        case 62u: goto label_000E7CD9;
        case 63u: goto label_000E7CE3;
        case 64u: goto label_000EA18F;
        default: lift_trap(cpu, 0x4E7A54u, "resolved jump-table index out of range"); return;
    }
    label_000E7A5B:
    cpu->eax = (uintptr_t)"No buffer space has been set";
    goto label_000EA1A9;
    label_000E7A65:
    cpu->eax = (uintptr_t)"The buffer is not big enough.";
    goto label_000EA1A9;
    label_000E7A6F:
    cpu->eax = (uintptr_t)"An invalid alignment was specified.";
    goto label_000EA1A9;
    label_000E7A79:
    cpu->eax = (uintptr_t)"Cannot change allocated memory while the filter is active.";
    goto label_000EA1A9;
    label_000E7A83:
    cpu->eax = (uintptr_t)"One or more buffers are still active.";
    goto label_000EA1A9;
    label_000E7A8D:
    cpu->eax = (uintptr_t)"Cannot allocate a sample when the allocator is not active.";
    goto label_000EA1A9;
    label_000E7A97:
    cpu->eax = (uintptr_t)"Cannot allocate memory because no size has been set.";
    goto label_000EA1A9;
    label_000E7AA1:
    cpu->eax = (uintptr_t)"Cannot lock for synchronization because no clock has been defined.";
    goto label_000EA1A9;
    label_000E7AAB:
    cpu->eax = (uintptr_t)"Quality messages could not be sent because no quality sink has been defined.";
    goto label_000EA1A9;
    label_000E7AB5:
    cpu->eax = (uintptr_t)"A required interface has not been implemented.";
    goto label_000EA1A9;
    label_000E7ABF:
    cpu->eax = (uintptr_t)"An object or name was not found.";
    goto label_000EA1A9;
    label_000E7AC9:
    cpu->eax = (uintptr_t)"No combination of intermediate filters could be found to make the connection.";
    goto label_000EA1A9;
    label_000E7AD3:
    cpu->eax = (uintptr_t)"No combination of filters could be found to render the stream.";
    goto label_000EA1A9;
    label_000E7ADD:
    cpu->eax = (uintptr_t)"Could not change formats dynamically.";
    goto label_000EA1A9;
    label_000E7AE7:
    cpu->eax = (uintptr_t)"No color key has been set.";
    goto label_000EA1A9;
    label_000E7AF1:
    cpu->eax = (uintptr_t)"Current pin connection is not using the IOverlay transport.";
    goto label_000EA1A9;
    label_000E7AFB:
    cpu->eax = (uintptr_t)"Current pin connection is not using the IMemInputPin transport.";
    goto label_000EA1A9;
    label_000E7B05:
    cpu->eax = (uintptr_t)"Setting a color key would conflict with the palette already set.";
    goto label_000EA1A9;
    label_000E7B0F:
    cpu->eax = (uintptr_t)"Setting a palette would conflict with the color key already set.";
    goto label_000EA1A9;
    label_000E7B19:
    cpu->eax = (uintptr_t)"No matching color key is available.";
    goto label_000EA1A9;
    label_000E7B23:
    cpu->eax = (uintptr_t)"No palette is available.";
    goto label_000EA1A9;
    label_000E7B2D:
    cpu->eax = (uintptr_t)"Display does not use a palette.";
    goto label_000EA1A9;
    label_000E7B37:
    cpu->eax += 0x7FFBFDDEu;
    if (cpu->eax > 0x3Du) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E7B53;
        case 1u: goto label_000E7B5D;
        case 2u: goto label_000E7B67;
        case 3u: goto label_000E7B71;
        case 4u: goto label_000E7B7B;
        case 5u: goto label_000E7B85;
        case 6u: goto label_000E7B8F;
        case 7u: goto label_000E7B99;
        case 8u: goto label_000E7BA3;
        case 9u: goto label_000E7BAD;
        case 10u: goto label_000E7BB7;
        case 11u: goto label_000E7BC1;
        case 12u: goto label_000E7BCB;
        case 13u: goto label_000E7BD5;
        case 14u: goto label_000E7BDF;
        case 15u: goto label_000E7BE9;
        case 16u: goto label_000E7BF3;
        case 17u: goto label_000E7BFD;
        case 18u: goto label_000E7C07;
        case 19u: goto label_000E7C11;
        case 20u: goto label_000E7C1B;
        case 22u: goto label_000E7C25;
        case 23u: goto label_000E7C2F;
        case 24u: goto label_000E7C39;
        case 25u: goto label_000E7C43;
        case 30u: goto label_000E7C4D;
        case 31u: goto label_000E7C57;
        case 33u: goto label_000E7C61;
        case 34u: goto label_000E7C6B;
        case 37u: goto label_000E7C75;
        case 38u: goto label_000E7C7F;
        case 39u: goto label_000E7C89;
        case 47u: goto label_000E7C93;
        case 48u: goto label_000E7C9D;
        case 49u: goto label_000E7CA7;
        case 51u: goto label_000E9FC6;
        case 52u: goto label_000E7CB1;
        case 55u: goto label_000EA03B;
        case 57u: goto label_000E7CBB;
        case 58u: goto label_000E7CC5;
        case 59u: goto label_000E7CCF;
        case 60u: goto label_000E7CD9;
        case 61u: goto label_000E7CE3;
        default: goto label_000EA18F;
    }
    label_000E7B53:
    cpu->eax = (uintptr_t)"Too many colors for the current display settings.";
    goto label_000EA1A9;
    label_000E7B5D:
    cpu->eax = (uintptr_t)"The state changed while waiting to process the sample.";
    goto label_000EA1A9;
    label_000E7B67:
    cpu->eax = (uintptr_t)"The operation could not be performed because the filter is not stopped.";
    goto label_000EA1A9;
    label_000E7B71:
    cpu->eax = (uintptr_t)"The operation could not be performed because the filter is not paused.";
    goto label_000EA1A9;
    label_000E7B7B:
    cpu->eax = (uintptr_t)"The operation could not be performed because the filter is not running.";
    goto label_000EA1A9;
    label_000E7B85:
    cpu->eax = (uintptr_t)"The operation could not be performed because the filter is in the wrong state.";
    goto label_000EA1A9;
    label_000E7B8F:
    cpu->eax = (uintptr_t)"The sample start time is after the sample end time.";
    goto label_000EA1A9;
    label_000E7B99:
    cpu->eax = (uintptr_t)"The supplied rectangle is invalid.";
    goto label_000EA1A9;
    label_000E7BA3:
    cpu->eax = (uintptr_t)"This pin cannot use the supplied media type.";
    goto label_000EA1A9;
    label_000E7BAD:
    cpu->eax = (uintptr_t)"This sample cannot be rendered.";
    goto label_000EA1A9;
    label_000E7BB7:
    cpu->eax = (uintptr_t)"This sample cannot be rendered because the end of the stream has been reached.";
    goto label_000EA1A9;
    label_000E7BC1:
    cpu->eax = (uintptr_t)"An attempt to add a filter with a duplicate name failed.";
    goto label_000EA1A9;
    label_000E7BCB:
    cpu->eax = (uintptr_t)"A time-out has expired.";
    goto label_000EA1A9;
    label_000E7BD5:
    cpu->eax = (uintptr_t)"The file format is invalid.";
    goto label_000EA1A9;
    label_000E7BDF:
    cpu->eax = (uintptr_t)"The list has already been exhausted.";
    goto label_000EA1A9;
    label_000E7BE9:
    cpu->eax = (uintptr_t)"The filter graph is circular.";
    goto label_000EA1A9;
    label_000E7BF3:
    cpu->eax = (uintptr_t)"Updates are not allowed in this state.";
    goto label_000EA1A9;
    label_000E7BFD:
    cpu->eax = (uintptr_t)"An attempt was made to queue a command for a time in the past.";
    goto label_000EA1A9;
    label_000E7C07:
    cpu->eax = (uintptr_t)"The queued command has already been canceled.";
    goto label_000EA1A9;
    label_000E7C11:
    cpu->eax = (uintptr_t)"Cannot render the file because it is corrupt.";
    goto label_000EA1A9;
    label_000E7C1B:
    cpu->eax = (uintptr_t)"An overlay advise link already exists.";
    goto label_000EA1A9;
    label_000E7C25:
    cpu->eax = (uintptr_t)"No full-screen modes are available.";
    goto label_000EA1A9;
    label_000E7C2F:
    cpu->eax = (uintptr_t)"This Advise cannot be canceled because it was not successfully set.";
    goto label_000EA1A9;
    label_000E7C39:
    cpu->eax = (uintptr_t)"A full-screen mode is not available.";
    goto label_000EA1A9;
    label_000E7C43:
    cpu->eax = (uintptr_t)"Cannot call IVideoWindow methods while in full-screen mode.";
    goto label_000EA1A9;
    label_000E7C4D:
    cpu->eax = (uintptr_t)"The media type of this file is not recognized.";
    goto label_000EA1A9;
    label_000E7C57:
    cpu->eax = (uintptr_t)"The source filter for this file could not be loaded.";
    goto label_000EA1A9;
    label_000E7C61:
    cpu->eax = (uintptr_t)"A file appeared to be incomplete.";
    goto label_000EA1A9;
    label_000E7C6B:
    cpu->eax = (uintptr_t)"The version number of the file is invalid.";
    goto label_000EA1A9;
    label_000E7C75:
    cpu->eax = (uintptr_t)"This file is corrupt: it contains an invalid class identifier.";
    goto label_000EA1A9;
    label_000E7C7F:
    cpu->eax = (uintptr_t)"This file is corrupt: it contains an invalid media type.";
    goto label_000EA1A9;
    label_000E7C89:
    cpu->eax = (uintptr_t)"No time stamp has been set for this sample.";
    goto label_000EA1A9;
    label_000E7C93:
    cpu->eax = (uintptr_t)"No media time stamp has been set for this sample.";
    goto label_000EA1A9;
    label_000E7C9D:
    cpu->eax = (uintptr_t)"No media time format has been selected.";
    goto label_000EA1A9;
    label_000E7CA7:
    cpu->eax = (uintptr_t)"Cannot change balance because audio device is mono only.";
    goto label_000EA1A9;
    label_000E7CB1:
    cpu->eax = (uintptr_t)"Cannot play back the audio stream: no audio hardware is available, or the hardware is not responding.";
    goto label_000EA1A9;
    label_000E7CBB:
    cpu->eax = (uintptr_t)"ActiveMovie cannot play MPEG movies on this processor.";
    goto label_000EA1A9;
    label_000E7CC5:
    cpu->eax = (uintptr_t)"Cannot play back the audio stream: the audio format is not supported.";
    goto label_000EA1A9;
    label_000E7CCF:
    cpu->eax = (uintptr_t)"Cannot play back the video stream: the video format is not supported.";
    goto label_000EA1A9;
    label_000E7CD9:
    cpu->eax = (uintptr_t)"ActiveMovie cannot play this video stream because it falls outside the constrained standard.";
    goto label_000EA1A9;
    label_000E7CE3:
    cpu->eax = (uintptr_t)"Cannot perform the requested function on an object that is not in the filter graph.";
    goto label_000EA1A9;
    label_000E7CED:
    cpu->eax = (uintptr_t)"Cannot get or set time related information on an object that is using a time format of TIME_FORMAT_NONE.";
    goto label_000EA1A9;
    label_000E7CF7:
    cpu->ecx = 0x80040305u;
    sub_pred[7] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E7EE0;
    if (sub_pred[7]) goto label_000E7ED6;
    cpu->eax += 0x7FFBFD9Eu;
    if (cpu->eax > 0xA2u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E7D5A;
        case 2u: goto label_000E7D64;
        case 3u: goto label_000E7D6E;
        case 4u: goto label_000E7D78;
        case 7u: goto label_000E7D82;
        case 15u: goto label_000E7D8C;
        case 16u: goto label_000E7D96;
        case 17u: goto label_000E7DA0;
        case 18u: goto label_000E7DAA;
        case 19u: goto label_000E7DB4;
        case 20u: goto label_000E7DBE;
        case 21u: goto label_000E7DC8;
        case 22u: goto label_000E7DD2;
        case 23u: goto label_000E7DDC;
        case 24u: goto label_000E7DE6;
        case 25u: goto label_000E7DF0;
        case 26u: goto label_000E7DFA;
        case 27u: goto label_000E7E04;
        case 29u: goto label_000E7E0E;
        case 31u: goto label_000E7E18;
        case 32u: goto label_000E7E22;
        case 33u: goto label_000E7E2C;
        case 34u: goto label_000E7E36;
        case 35u: goto label_000E7E40;
        case 36u: goto label_000E7E4A;
        case 37u: goto label_000E7E54;
        case 38u: goto label_000E7E5E;
        case 39u: goto label_000E7E68;
        case 40u: goto label_000E7E72;
        case 41u: goto label_000E7E7C;
        case 44u: goto label_000E7E86;
        case 45u: goto label_000E7E90;
        case 46u: goto label_000E7E9A;
        case 47u: goto label_000E7EA4;
        case 48u: goto label_000E7EAE;
        case 49u: goto label_000E7EB8;
        case 50u: goto label_000E7EC2;
        case 51u: goto label_000E7ECC;
        case 158u: goto label_000E7D28;
        case 159u: goto label_000E7D32;
        case 160u: goto label_000E7D3C;
        case 161u: goto label_000E7D46;
        case 162u: goto label_000E7D50;
        default: goto label_000EA18F;
    }
label_000E7D28: ;
    cpu->eax = (uintptr_t)"Device driver-specific codes. Unless the specific driver has been precisely identified, no meaning should be attributed to these values other than that the driver originated the error.";
    goto label_000EA1A9;
    label_000E7D32:
    cpu->eax = (uintptr_t)"DIERR_DRIVERFIRST+1";
    goto label_000EA1A9;
    label_000E7D3C:
    cpu->eax = (uintptr_t)"DIERR_DRIVERFIRST+2";
    goto label_000EA1A9;
    label_000E7D46:
    cpu->eax = (uintptr_t)"DIERR_DRIVERFIRST+3";
    goto label_000EA1A9;
    label_000E7D50:
    cpu->eax = (uintptr_t)"DIERR_DRIVERFIRST+4";
    goto label_000EA1A9;
    label_000E7D5A:
    cpu->eax = (uintptr_t)"The connection cannot be made because the stream is read only and the filter alters the data.";
    goto label_000EA1A9;
    label_000E7D64:
    cpu->eax = (uintptr_t)"The buffer is not full enough.";
    goto label_000EA1A9;
    label_000E7D6E:
    cpu->eax = (uintptr_t)"Cannot play back the file.  The format is not supported.";
    goto label_000EA1A9;
    label_000E7D78:
    cpu->eax = (uintptr_t)"Pins cannot connect due to not supporting the same transport.";
    goto label_000EA1A9;
    label_000E7D82:
    cpu->eax = (uintptr_t)"The Video CD can't be read correctly by the device or is the data is corrupt.";
    goto label_000EA1A9;
    label_000E7D8C:
    cpu->eax = (uintptr_t)"There is not enough Video Memory at this display resolution and number of colors. Reducing resolution might help.";
    goto label_000EA1A9;
    label_000E7D96:
    cpu->eax = (uintptr_t)"The VideoPort connection negotiation process has failed.";
    goto label_000EA1A9;
    label_000E7DA0:
    cpu->eax = (uintptr_t)"Either DirectDraw has not been installed or the Video Card capabilities are not suitable. Make sure the display is not in 16 color mode.";
    goto label_000EA1A9;
    label_000E7DAA:
    cpu->eax = (uintptr_t)"No VideoPort hardware is available, or the hardware is not responding.";
    goto label_000EA1A9;
    label_000E7DB4:
    cpu->eax = (uintptr_t)"No Capture hardware is available, or the hardware is not responding.";
    goto label_000EA1A9;
    label_000E7DBE:
    cpu->eax = (uintptr_t)"This User Operation is inhibited by DVD Content at this time.";
    goto label_000EA1A9;
    label_000E7DC8:
    cpu->eax = (uintptr_t)"This Operation is not permitted in the current domain.";
    goto label_000EA1A9;
    label_000E7DD2:
    cpu->eax = (uintptr_t)"The specified button is invalid or is not present at the current time, or there is no button present at the specified location.";
    goto label_000EA1A9;
    label_000E7DDC:
    cpu->eax = (uintptr_t)"DVD-Video playback graph has not been built yet.";
    goto label_000EA1A9;
    label_000E7DE6:
    cpu->eax = (uintptr_t)"DVD-Video playback graph building failed.";
    goto label_000EA1A9;
    label_000E7DF0:
    cpu->eax = (uintptr_t)"DVD-Video playback graph could not be built due to insufficient decoders.";
    goto label_000EA1A9;
    label_000E7DFA:
    cpu->eax = (uintptr_t)"Version number of DirectDraw not suitable. Make sure to install dx5 or higher version.";
    goto label_000EA1A9;
    label_000E7E04:
    cpu->eax = (uintptr_t)"Copy protection cannot be enabled. Please make sure any other copy protected content is not being shown now.";
    goto label_000EA1A9;
    label_000E7E0E:
    cpu->eax = (uintptr_t)"This object cannot be used anymore as its time has expired.";
    goto label_000EA1A9;
    label_000E7E18:
    cpu->eax = (uintptr_t)"The operation cannot be performed at the current playback speed.";
    goto label_000EA1A9;
    label_000E7E22:
    cpu->eax = (uintptr_t)"The specified menu doesn't exist.";
    goto label_000EA1A9;
    label_000E7E2C:
    cpu->eax = (uintptr_t)"The specified command was either cancelled or no longer exists.";
    goto label_000EA1A9;
    label_000E7E36:
    cpu->eax = (uintptr_t)"The data did not contain a recognized version.";
    goto label_000EA1A9;
    label_000E7E40:
    cpu->eax = (uintptr_t)"The state data was corrupt.";
    goto label_000EA1A9;
    label_000E7E4A:
    cpu->eax = (uintptr_t)"The state data is from a different disc.";
    goto label_000EA1A9;
    label_000E7E54:
    cpu->eax = (uintptr_t)"The region was not compatible with the current drive.";
    goto label_000EA1A9;
    label_000E7E5E:
    cpu->eax = (uintptr_t)"The requested DVD stream attribute does not exist.";
    goto label_000EA1A9;
    label_000E7E68:
    cpu->eax = (uintptr_t)"Currently there is no GoUp (Annex J user function) program chain (PGC).";
    goto label_000EA1A9;
    label_000E7E72:
    cpu->eax = (uintptr_t)"The current parental level was too low.";
    goto label_000EA1A9;
    label_000E7E7C:
    cpu->eax = (uintptr_t)"The current audio is not karaoke content.";
    goto label_000EA1A9;
    label_000E7E86:
    cpu->eax = (uintptr_t)"Frame step is not supported on this configuration.";
    goto label_000EA1A9;
    label_000E7E90:
    cpu->eax = (uintptr_t)"The specified stream is disabled and cannot be selected.";
    goto label_000EA1A9;
    label_000E7E9A:
    cpu->eax = (uintptr_t)"The operation depends on the current title number, however the navigator has not yet entered the VTSM or the title domains, so the 'current' title index is unknown.";
    goto label_000EA1A9;
    label_000E7EA4:
    cpu->eax = (uintptr_t)"The specified path does not point to a valid DVD disc.";
    goto label_000EA1A9;
    label_000E7EAE:
    cpu->eax = (uintptr_t)"There is currently no resume information.";
    goto label_000EA1A9;
    label_000E7EB8:
    cpu->eax = (uintptr_t)"This thread has already blocked this output pin.  There is no need to call IPinFlowControl::Block() again.";
    goto label_000EA1A9;
    label_000E7EC2:
    cpu->eax = (uintptr_t)"IPinFlowControl::Block() has been called on another thread.  The current thread cannot make any assumptions about this pin's block state.";
    goto label_000EA1A9;
    label_000E7ECC:
    cpu->eax = (uintptr_t)"An operation failed due to a certification failure.";
    goto label_000EA1A9;
    label_000E7ED6:
    cpu->eax = (uintptr_t)"DIERR_DRIVERFIRST+5";
    goto label_000EA1A9;
    label_000E7EE0:
    cpu->ecx = 0x80040909u;
    sub_pred[8] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8050;
    if (sub_pred[8]) goto label_000E8046;
    cpu->ecx = 0x80040408u;
    sub_pred[9] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E7F90;
    if (sub_pred[9]) goto label_000E7F86;
    cpu->eax += 0x7FFBFC0Eu;
    if (cpu->eax > 0x15u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E7F4A;
        case 13u: goto label_000E7F22;
        case 14u: goto label_000E7F2C;
        case 15u: goto label_000E7F36;
        case 16u: goto label_000E7F40;
        case 17u: goto label_000E7F54;
        case 18u: goto label_000E7F5E;
        case 19u: goto label_000E7F68;
        case 20u: goto label_000E7F72;
        case 21u: goto label_000E7F7C;
        default: goto label_000EA18F;
    }
label_000E7F22: ;
    cpu->eax = (uintptr_t)"Device installer errors.";
    goto label_000EA1A9;
    label_000E7F2C:
    cpu->eax = (uintptr_t)"Registry entry or DLL for class installer invalid or class installer not found.";
    goto label_000EA1A9;
    label_000E7F36:
    cpu->eax = (uintptr_t)"The user cancelled the install operation. & The stream already has allocated samples and the surface doesn't match the sample format.";
    goto label_000EA1A9;
    label_000E7F40:
    cpu->eax = (uintptr_t)"The INF file for the selected device could not be found or is invalid or is damaged. & The specified purpose ID can't be used for the call.";
    goto label_000EA1A9;
    label_000E7F4A:
    cpu->eax = (uintptr_t)"A registry entry is corrupt.";
    goto label_000EA1A9;
    label_000E7F54:
    cpu->eax = (uintptr_t)"No stream can be found with the specified attributes.";
    goto label_000EA1A9;
    label_000E7F5E:
    cpu->eax = (uintptr_t)"Seeking not supported for this object.";
    goto label_000EA1A9;
    label_000E7F68:
    cpu->eax = (uintptr_t)"The stream formats are not compatible.";
    goto label_000EA1A9;
    label_000E7F72:
    cpu->eax = (uintptr_t)"The sample is busy.";
    goto label_000EA1A9;
    label_000E7F7C:
    cpu->eax = (uintptr_t)"The object can't accept the call because its initialize function or equivalent has not been called.";
    goto label_000EA1A9;
    label_000E7F86:
    cpu->eax = (uintptr_t)"MS_E_SOURCEALREADYDEFINED";
    goto label_000EA1A9;
    label_000E7F90:
    cpu->ecx = 0x80040904u;
    sub_pred[10] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E7FFE;
    if (sub_pred[10]) goto label_000E7FF4;
    if (cpu->eax == 0x80040409u) goto label_000E7FEA;
    if (cpu->eax == 0x8004040Au) goto label_000E7FE0;
    if (cpu->eax == 0x80040901u) goto label_000E7FD6;
    if (cpu->eax == 0x80040902u) goto label_000E7FCC;
    if (cpu->eax != 0x80040903u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"A media file could not be found.";
    goto label_000EA1A9;
    label_000E7FCC:
    cpu->eax = (uintptr_t)"No device could be found with the specified device settings.";
    goto label_000EA1A9;
    label_000E7FD6:
    cpu->eax = (uintptr_t)"Could not initialize Direct3D.";
    goto label_000EA1A9;
    label_000E7FE0:
    cpu->eax = (uintptr_t)"The object is not in running state.";
    goto label_000EA1A9;
    label_000E7FEA:
    cpu->eax = (uintptr_t)"The stream type is not valid for this operation.";
    goto label_000EA1A9;
    label_000E7FF4:
    cpu->eax = (uintptr_t)"The device interface has a non-zero reference count, meaning that some objects were not released.";
    goto label_000EA1A9;
    label_000E7FFE:
    if (cpu->eax == 0x80040905u) goto label_000E803C;
    if (cpu->eax == 0x80040906u) goto label_000E8032;
    if (cpu->eax == 0x80040907u) goto label_000E8028;
    if (cpu->eax != 0x80040908u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"An error occurred in the device reset callback function.";
    goto label_000EA1A9;
    label_000E8028:
    cpu->eax = (uintptr_t)"An error occurred in the device create callback function.";
    goto label_000EA1A9;
    label_000E8032:
    cpu->eax = (uintptr_t)"An error occurred when attempting to reset a device.";
    goto label_000EA1A9;
    label_000E803C:
    cpu->eax = (uintptr_t)"An error occurred when attempting to create a device.";
    goto label_000EA1A9;
    label_000E8046:
    cpu->eax = (uintptr_t)"Incorrect version of Direct3D or D3DX.";
    goto label_000EA1A9;
    label_000E8050:
    cpu->ecx = 0x8007000Cu;
    sub_pred[11] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E80F7;
    if (sub_pred[11]) goto label_000E80ED;
    cpu->ecx += 0xFFFFFFFAu;
    sub_pred[12] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E80B7;
    if (sub_pred[12]) goto label_000E86A7;
    if (cpu->eax == 0x8004090Au) goto label_000E80AD;
    if (cpu->eax == 0x80070002u) goto label_000E9ECB;
    if (cpu->eax == 0x80070003u) goto label_000E9ED5;
    if (cpu->eax == 0x80070004u) goto label_000E9EDF;
    if (cpu->eax != 0x80070005u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Access is denied";
    goto label_000EA1A9;
    label_000E80AD:
    cpu->eax = (uintptr_t)"The device was removed.";
    goto label_000EA1A9;
    label_000E80B7:
    if (cpu->eax == 0x80070008u) goto label_000E9EFD;
    if (cpu->eax == 0x80070009u) goto label_000E9F07;
    if (cpu->eax == 0x8007000Au) goto label_000E9F11;
    if (cpu->eax != 0x8007000Bu) goto label_000EA18F;
    label_000E80E3:
    cpu->eax = (uintptr_t)"An attempt was made to load a program with an incorrect format.";
    goto label_000EA1A9;
    label_000E80ED:
    cpu->eax = (uintptr_t)"The operation cannot be performed unless the device is acquired.";
    goto label_000EA1A9;
    label_000E80F7:
    cpu->ecx = 0x800700AAu;
    sub_pred[13] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E815F;
    if (sub_pred[13]) goto label_000E8155;
    if (cpu->eax == 0x8007000Eu) goto label_000E814B;
    if (cpu->eax == 0x80070015u) goto label_000E93E3;
    if (cpu->eax == 0x8007001Eu) goto label_000E8141;
    if (cpu->eax == 0x80070057u) goto label_000E8137;
    if (cpu->eax != 0x80070077u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The object could not be created due to an incompatible driver version or mismatched or incomplete driver components.";
    goto label_000EA1A9;
    label_000E8137:
    cpu->eax = (uintptr_t)"An invalid parameter was passed to the returning function";
    goto label_000EA1A9;
    label_000E8141:
    cpu->eax = (uintptr_t)"Access to the device has been lost.  It must be re-acquired.";
    goto label_000EA1A9;
    label_000E814B:
    cpu->eax = (uintptr_t)"Ran out of memory";
    goto label_000EA1A9;
    label_000E8155:
    cpu->eax = (uintptr_t)"The operation cannot be performed while the device is acquired.";
    goto label_000EA1A9;
    label_000E815F:
    if (cpu->eax == 0x80070103u) goto label_000E819D;
    if (cpu->eax == 0x8007047Eu) goto label_000E8193;
    if (cpu->eax == 0x80070481u) goto label_000E8189;
    if (cpu->eax != 0x80070490u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The specified property ID is not supported for the specified property set.";
    goto label_000EA1A9;
    label_000E8189:
    cpu->eax = (uintptr_t)"The application was written for an unsupported prerelease version of DirectInput.";
    goto label_000EA1A9;
    label_000E8193:
    cpu->eax = (uintptr_t)"The application requires a newer version of DirectInput.";
    goto label_000EA1A9;
    label_000E819D:
    cpu->eax = (uintptr_t)"No more items.";
    goto label_000EA1A9;
    label_000E81A7:
    cpu->eax = (uintptr_t)"The specified property set is not supported.";
    goto label_000EA1A9;
    label_000E81B1:
    cpu->ecx = 0x80158440u;
    sub_pred[14] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E871B;
    if (sub_pred[14]) goto label_000E8711;
    cpu->ecx = 0x80150190u;
    sub_pred[15] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E83EE;
    if (sub_pred[15]) goto label_000E83E4;
    cpu->ecx += 0xFFFFFFE6u;
    sub_pred[16] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E831B;
    if (sub_pred[16]) goto label_000E8311;
    cpu->ecx = 0x80150169u;
    sub_pred[17] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E82A2;
    if (sub_pred[17]) goto label_000E8298;
    cpu->ecx = 0x80150087u;
    sub_pred[18] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E824B;
    if (sub_pred[18]) goto label_000E86FD;
    if (cpu->eax == 0x800704DFu) goto label_000E9401;
    if (cpu->eax == 0x8015001Eu) goto label_000E84B6;
    if (cpu->eax == 0x8015004Au) goto label_000E85FB;
    if (cpu->eax == 0x80150078u) goto label_000E86BB;
    if (cpu->eax != 0x80150082u) goto label_000EA18F;
    label_000E8241:
    cpu->eax = (uintptr_t)"Invalid object";
    goto label_000EA1A9;
    label_000E824B:
    if (cpu->eax == 0x80150091u) goto label_000E86B1;
    if (cpu->eax == 0x80150096u) goto label_000E86A7;
    if (cpu->eax == 0x8015012Cu) goto label_000E828E;
    if (cpu->eax == 0x8015012Eu) goto label_000E8284;
    if (cpu->eax != 0x80150168u) goto label_000EA18F;
    label_000E827A:
    cpu->eax = (uintptr_t)"Connection lost";
    goto label_000EA1A9;
    label_000E8284:
    cpu->eax = (uintptr_t)"No voice session";
    goto label_000EA1A9;
    label_000E828E:
    cpu->eax = (uintptr_t)"Session lost";
    goto label_000EA1A9;
    label_000E8298:
    cpu->eax = (uintptr_t)"Not initialized";
    goto label_000EA1A9;
    label_000E82A2:
    cpu->eax += 0x7FEAFE96u;
    if (cpu->eax > 0xBu) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E82B7;
        case 1u: goto label_000E82C1;
        case 2u: case 3u: case 22u: case 23u: case 26u: case 27u: case 71u: goto label_000EA18F;
        case 4u: goto label_000E82CB;
        case 5u: goto label_000E87F4;
        case 6u: goto label_000E82D5;
        case 7u: goto label_000E82DF;
        case 8u: goto label_000E82E9;
        case 9u: goto label_000E82F3;
        case 10u: goto label_000E82FD;
        case 11u: goto label_000E8307;
        case 12u: goto label_000E8330;
        case 13u: goto label_000E833A;
        case 14u: goto label_000E8344;
        case 15u: goto label_000E85E7;
        case 16u: goto label_000E834E;
        case 17u: goto label_000E927C;
        case 18u: goto label_000E8358;
        case 19u: goto label_000E8362;
        case 20u: goto label_000E836C;
        case 21u: goto label_000E88A0;
        case 24u: goto label_000E8376;
        case 25u: goto label_000E8380;
        case 28u: goto label_000E838A;
        case 29u: goto label_000E8394;
        case 30u: goto label_000E839E;
        case 31u: goto label_000E83A8;
        case 32u: goto label_000E83B2;
        case 33u: goto label_000E83BC;
        case 34u: goto label_000E83C6;
        case 35u: goto label_000E83D0;
        case 36u: goto label_000E83DA;
        case 37u: goto label_000E8DBD;
        case 38u: goto label_000E8DC7;
        case 39u: goto label_000E8DD1;
        case 40u: goto label_000E8DDB;
        case 41u: goto label_000E8DE5;
        case 42u: goto label_000E8DEF;
        case 43u: goto label_000E8DF9;
        case 44u: goto label_000E8E03;
        case 45u: goto label_000E8E0D;
        case 46u: goto label_000E8E17;
        case 47u: goto label_000E8E21;
        case 48u: goto label_000E8E2B;
        case 49u: goto label_000E8E35;
        case 50u: goto label_000E8E3F;
        case 51u: goto label_000E8E49;
        case 52u: goto label_000E8E53;
        case 53u: goto label_000E8E5D;
        case 54u: goto label_000E8E67;
        case 55u: goto label_000E8E71;
        case 56u: goto label_000E8E7B;
        case 57u: goto label_000E8E85;
        case 58u: goto label_000E8E8F;
        case 59u: goto label_000E8E99;
        case 60u: goto label_000E8EA3;
        case 61u: goto label_000E8EAD;
        case 62u: goto label_000E8EB7;
        case 63u: goto label_000E8EC1;
        case 64u: goto label_000E8ECB;
        case 65u: goto label_000E8ED5;
        case 66u: goto label_000E8EDF;
        case 67u: goto label_000E8EE9;
        case 68u: goto label_000E8EF3;
        case 69u: goto label_000E8EFD;
        case 70u: goto label_000E8F07;
        default: lift_trap(cpu, 0x4E82B0u, "resolved jump-table index out of range"); return;
    }
label_000E82B7: ;
    cpu->eax = (uintptr_t)"Connected";
    goto label_000EA1A9;
    label_000E82C1:
    cpu->eax = (uintptr_t)"Not connected";
    goto label_000EA1A9;
    label_000E82CB:
    cpu->eax = (uintptr_t)"Connect aborting";
    goto label_000EA1A9;
    label_000E82D5:
    cpu->eax = (uintptr_t)"Invalid target";
    goto label_000EA1A9;
    label_000E82DF:
    cpu->eax = (uintptr_t)"Transport not host";
    goto label_000EA1A9;
    label_000E82E9:
    cpu->eax = (uintptr_t)"Compression not supported";
    goto label_000EA1A9;
    label_000E82F3:
    cpu->eax = (uintptr_t)"Already pending";
    goto label_000EA1A9;
    label_000E82FD:
    cpu->eax = (uintptr_t)"Sound init failure";
    goto label_000EA1A9;
    label_000E8307:
    cpu->eax = (uintptr_t)"Time out";
    goto label_000EA1A9;
    label_000E8311:
    cpu->eax = (uintptr_t)"Connect aborted";
    goto label_000EA1A9;
    label_000E831B:
    cpu->eax += 0x7FEAFE89u;
    if (cpu->eax > 0x18u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E8330;
        case 1u: goto label_000E833A;
        case 2u: goto label_000E8344;
        case 3u: goto label_000E85E7;
        case 4u: goto label_000E834E;
        case 5u: goto label_000E927C;
        case 6u: goto label_000E8358;
        case 7u: goto label_000E8362;
        case 8u: goto label_000E836C;
        case 9u: goto label_000E88A0;
        case 10u: case 11u: case 14u: case 15u: case 59u: goto label_000EA18F;
        case 12u: goto label_000E8376;
        case 13u: goto label_000E8380;
        case 16u: goto label_000E838A;
        case 17u: goto label_000E8394;
        case 18u: goto label_000E839E;
        case 19u: goto label_000E83A8;
        case 20u: goto label_000E83B2;
        case 21u: goto label_000E83BC;
        case 22u: goto label_000E83C6;
        case 23u: goto label_000E83D0;
        case 24u: goto label_000E83DA;
        case 25u: goto label_000E8DBD;
        case 26u: goto label_000E8DC7;
        case 27u: goto label_000E8DD1;
        case 28u: goto label_000E8DDB;
        case 29u: goto label_000E8DE5;
        case 30u: goto label_000E8DEF;
        case 31u: goto label_000E8DF9;
        case 32u: goto label_000E8E03;
        case 33u: goto label_000E8E0D;
        case 34u: goto label_000E8E17;
        case 35u: goto label_000E8E21;
        case 36u: goto label_000E8E2B;
        case 37u: goto label_000E8E35;
        case 38u: goto label_000E8E3F;
        case 39u: goto label_000E8E49;
        case 40u: goto label_000E8E53;
        case 41u: goto label_000E8E5D;
        case 42u: goto label_000E8E67;
        case 43u: goto label_000E8E71;
        case 44u: goto label_000E8E7B;
        case 45u: goto label_000E8E85;
        case 46u: goto label_000E8E8F;
        case 47u: goto label_000E8E99;
        case 48u: goto label_000E8EA3;
        case 49u: goto label_000E8EAD;
        case 50u: goto label_000E8EB7;
        case 51u: goto label_000E8EC1;
        case 52u: goto label_000E8ECB;
        case 53u: goto label_000E8ED5;
        case 54u: goto label_000E8EDF;
        case 55u: goto label_000E8EE9;
        case 56u: goto label_000E8EF3;
        case 57u: goto label_000E8EFD;
        case 58u: goto label_000E8F07;
        default: lift_trap(cpu, 0x4E8329u, "resolved jump-table index out of range"); return;
    }
    label_000E8330:
    cpu->eax = (uintptr_t)"No 3d sound";
    goto label_000EA1A9;
    label_000E833A:
    cpu->eax = (uintptr_t)"Already buffered";
    goto label_000EA1A9;
    label_000E8344:
    cpu->eax = (uintptr_t)"Not buffered";
    goto label_000EA1A9;
    label_000E834E:
    cpu->eax = (uintptr_t)"Not hosting";
    goto label_000EA1A9;
    label_000E8358:
    cpu->eax = (uintptr_t)"Record system error";
    goto label_000EA1A9;
    label_000E8362:
    cpu->eax = (uintptr_t)"Playback system error";
    goto label_000EA1A9;
    label_000E836C:
    cpu->eax = (uintptr_t)"Send error";
    goto label_000EA1A9;
    label_000E8376:
    cpu->eax = (uintptr_t)"Run setup";
    goto label_000EA1A9;
    label_000E8380:
    cpu->eax = (uintptr_t)"Incompatible version";
    goto label_000EA1A9;
    label_000E838A:
    cpu->eax = (uintptr_t)"Initialized";
    goto label_000EA1A9;
    label_000E8394:
    cpu->eax = (uintptr_t)"No transport";
    goto label_000EA1A9;
    label_000E839E:
    cpu->eax = (uintptr_t)"No callback";
    goto label_000EA1A9;
    label_000E83A8:
    cpu->eax = (uintptr_t)"Transport not init";
    goto label_000EA1A9;
    label_000E83B2:
    cpu->eax = (uintptr_t)"Transport no session";
    goto label_000EA1A9;
    label_000E83BC:
    cpu->eax = (uintptr_t)"Transport no player";
    goto label_000EA1A9;
    label_000E83C6:
    cpu->eax = (uintptr_t)"User back";
    goto label_000EA1A9;
    label_000E83D0:
    cpu->eax = (uintptr_t)"No rec vol available";
    goto label_000EA1A9;
    label_000E83DA:
    cpu->eax = (uintptr_t)"Invalid buffer";
    goto label_000EA1A9;
    label_000E83E4:
    cpu->eax = (uintptr_t)"Locked buffer";
    goto label_000EA1A9;
    label_000E83EE:
    cpu->ecx = 0x80158220u;
    sub_pred[19] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E858E;
    if (sub_pred[19]) goto label_000E8584;
    cpu->ecx = 0x80158130u;
    sub_pred[20] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E84D4;
    if (sub_pred[20]) goto label_000E84CA;
    cpu->ecx = 0x80158080u;
    sub_pred[21] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8482;
    if (sub_pred[21]) goto label_000E8478;
    if (cpu->eax == 0x80158030u) goto label_000E846E;
    if (cpu->eax == 0x80158040u) goto label_000E8464;
    if (cpu->eax == 0x80158050u) goto label_000E845A;
    if (cpu->eax == 0x80158060u) goto label_000E8450;
    if (cpu->eax != 0x80158070u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Already disconnecting";
    goto label_000EA1A9;
    label_000E8450:
    cpu->eax = (uintptr_t)"Already connected";
    goto label_000EA1A9;
    label_000E845A:
    cpu->eax = (uintptr_t)"Already closing";
    goto label_000EA1A9;
    label_000E8464:
    cpu->eax = (uintptr_t)"Addressing";
    goto label_000EA1A9;
    label_000E846E:
    cpu->eax = (uintptr_t)"Aborted";
    goto label_000EA1A9;
    label_000E8478:
    cpu->eax = (uintptr_t)"Already initialized";
    goto label_000EA1A9;
    label_000E8482:
    if (cpu->eax == 0x80158090u) goto label_000E84C0;
    if (cpu->eax == 0x80158100u) goto label_000E84B6;
    if (cpu->eax == 0x80158110u) goto label_000E84AC;
    if (cpu->eax != 0x80158120u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Cant create group";
    goto label_000EA1A9;
    label_000E84AC:
    cpu->eax = (uintptr_t)"Can not cancel";
    goto label_000EA1A9;
    label_000E84B6:
    cpu->eax = (uintptr_t)"Buffer too small";
    goto label_000EA1A9;
    label_000E84C0:
    cpu->eax = (uintptr_t)"Already registered";
    goto label_000EA1A9;
    label_000E84CA:
    cpu->eax = (uintptr_t)"Cant create player";
    goto label_000EA1A9;
    label_000E84D4:
    cpu->ecx = 0x80158180u;
    sub_pred[22] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E853C;
    if (sub_pred[22]) goto label_000E8532;
    if (cpu->eax == 0x80158140u) goto label_000E8528;
    if (cpu->eax == 0x80158150u) goto label_000E851E;
    if (cpu->eax == 0x80158160u) goto label_000E827A;
    if (cpu->eax == 0x80158170u) goto label_000E8514;
    if (cpu->eax != 0x80158175u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Data too large";
    goto label_000EA1A9;
    label_000E8514:
    cpu->eax = (uintptr_t)"Conversion";
    goto label_000EA1A9;
    label_000E851E:
    cpu->eax = (uintptr_t)"Connecting";
    goto label_000EA1A9;
    label_000E8528:
    cpu->eax = (uintptr_t)"Cant launch application";
    goto label_000EA1A9;
    label_000E8532:
    cpu->eax = (uintptr_t)"Does not exist";
    goto label_000EA1A9;
    label_000E853C:
    if (cpu->eax == 0x80158185u) goto label_000E857A;
    if (cpu->eax == 0x80158190u) goto label_000E8570;
    if (cpu->eax == 0x80158200u) goto label_000E8566;
    if (cpu->eax != 0x80158210u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Enum query too large";
    goto label_000EA1A9;
    label_000E8566:
    cpu->eax = (uintptr_t)"End point not receiving";
    goto label_000EA1A9;
    label_000E8570:
    cpu->eax = (uintptr_t)"Duplicate command";
    goto label_000EA1A9;
    label_000E857A:
    cpu->eax = (uintptr_t)"dpnsvr not available";
    goto label_000EA1A9;
    label_000E8584:
    cpu->eax = (uintptr_t)"Enum response too large";
    goto label_000EA1A9;
    label_000E858E:
    cpu->ecx = 0x80158330u;
    sub_pred[23] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8661;
    if (sub_pred[23]) goto label_000E8657;
    cpu->ecx = 0x80158280u;
    sub_pred[24] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E860F;
    if (sub_pred[24]) goto label_000E8605;
    if (cpu->eax == 0x80158230u) goto label_000E85FB;
    if (cpu->eax == 0x80158240u) goto label_000E85F1;
    if (cpu->eax == 0x80158250u) goto label_000E85E7;
    if (cpu->eax == 0x80158260u) goto label_000E85DD;
    if (cpu->eax != 0x80158270u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Host terminated session";
    goto label_000EA1A9;
    label_000E85DD:
    cpu->eax = (uintptr_t)"Host rejected connection";
    goto label_000EA1A9;
    label_000E85E7:
    cpu->eax = (uintptr_t)"Hosting";
    goto label_000EA1A9;
    label_000E85F1:
    cpu->eax = (uintptr_t)"Group not empty";
    goto label_000EA1A9;
    label_000E85FB:
    cpu->eax = (uintptr_t)"Exception";
    goto label_000EA1A9;
    label_000E8605:
    cpu->eax = (uintptr_t)"Incomplete address";
    goto label_000EA1A9;
    label_000E860F:
    if (cpu->eax == 0x80158290u) goto label_000E864D;
    if (cpu->eax == 0x80158300u) goto label_000E8643;
    if (cpu->eax == 0x80158310u) goto label_000E8639;
    if (cpu->eax != 0x80158320u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Invalid device address";
    goto label_000EA1A9;
    label_000E8639:
    cpu->eax = (uintptr_t)"Invalid command";
    goto label_000EA1A9;
    label_000E8643:
    cpu->eax = (uintptr_t)"Invalid application";
    goto label_000EA1A9;
    label_000E864D:
    cpu->eax = (uintptr_t)"Invalid address format";
    goto label_000EA1A9;
    label_000E8657:
    cpu->eax = (uintptr_t)"Invalid end point";
    goto label_000EA1A9;
    label_000E8661:
    cpu->ecx = 0x80158390u;
    sub_pred[25] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E86CF;
    if (sub_pred[25]) goto label_000E86C5;
    if (cpu->eax == 0x80158340u) goto label_000E86BB;
    if (cpu->eax == 0x80158350u) goto label_000E86B1;
    if (cpu->eax == 0x80158360u) goto label_000E86A7;
    if (cpu->eax == 0x80158370u) goto label_000E869D;
    if (cpu->eax != 0x80158380u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Invalid instance";
    goto label_000EA1A9;
    label_000E869D:
    cpu->eax = (uintptr_t)"Invalid host address";
    goto label_000EA1A9;
    label_000E86A7:
    cpu->eax = (uintptr_t)"Invalid handle";
    goto label_000EA1A9;
    label_000E86B1:
    cpu->eax = (uintptr_t)"Invalid group";
    goto label_000EA1A9;
    label_000E86BB:
    cpu->eax = (uintptr_t)"Invalid flags";
    goto label_000EA1A9;
    label_000E86C5:
    cpu->eax = (uintptr_t)"Invalid interface";
    goto label_000EA1A9;
    label_000E86CF:
    if (cpu->eax == 0x80158400u) goto label_000E8241;
    if (cpu->eax == 0x80158410u) goto label_000E8707;
    if (cpu->eax == 0x80158420u) goto label_000E86FD;
    if (cpu->eax != 0x80158430u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Invalid priority";
    goto label_000EA1A9;
    label_000E86FD:
    cpu->eax = (uintptr_t)"Invalid player";
    goto label_000EA1A9;
    label_000E8707:
    cpu->eax = (uintptr_t)"Invalid password";
    goto label_000EA1A9;
    label_000E8711:
    cpu->eax = (uintptr_t)"Invalid string";
    goto label_000EA1A9;
    label_000E871B:
    cpu->ecx = 0x887600DCu;
    sub_pred[26] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8A59;
    if (sub_pred[26]) goto label_000E8A4F;
    cpu->ecx = 0x88760005u;
    sub_pred[27] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E88C8;
    if (sub_pred[27]) goto label_000E9401;
    cpu->ecx = 0x80158550u;
    sub_pred[28] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8812;
    if (sub_pred[28]) goto label_000E8808;
    cpu->ecx += 0xFFFFFFB0u;
    sub_pred[29] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E87C0;
    if (sub_pred[29]) goto label_000E87B6;
    if (cpu->eax == 0x80158450u) goto label_000E87AC;
    if (cpu->eax == 0x80158460u) goto label_000E87A2;
    if (cpu->eax == 0x80158470u) goto label_000E8798;
    if (cpu->eax == 0x80158480u) goto label_000E878E;
    if (cpu->eax != 0x80158490u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"No host player";
    goto label_000EA1A9;
    label_000E878E:
    cpu->eax = (uintptr_t)"No connection";
    goto label_000EA1A9;
    label_000E8798:
    cpu->eax = (uintptr_t)"No caps";
    goto label_000EA1A9;
    label_000E87A2:
    cpu->eax = (uintptr_t)"Invalid version";
    goto label_000EA1A9;
    label_000E87AC:
    cpu->eax = (uintptr_t)"Invalid url";
    goto label_000EA1A9;
    label_000E87B6:
    cpu->eax = (uintptr_t)"No more address components";
    goto label_000EA1A9;
    label_000E87C0:
    if (cpu->eax == 0x80158510u) goto label_000E87FE;
    if (cpu->eax == 0x80158520u) goto label_000E87F4;
    if (cpu->eax == 0x80158530u) goto label_000E87EA;
    if (cpu->eax != 0x80158540u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Not ready";
    goto label_000EA1A9;
    label_000E87EA:
    cpu->eax = (uintptr_t)"Not host";
    goto label_000EA1A9;
    label_000E87F4:
    cpu->eax = (uintptr_t)"Not allowed";
    goto label_000EA1A9;
    label_000E87FE:
    cpu->eax = (uintptr_t)"No response";
    goto label_000EA1A9;
    label_000E8808:
    cpu->eax = (uintptr_t)"Not registered";
    goto label_000EA1A9;
    label_000E8812:
    cpu->ecx = 0x80158610u;
    sub_pred[30] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8880;
    if (sub_pred[30]) goto label_000E8876;
    if (cpu->eax == 0x80158560u) goto label_000E886C;
    if (cpu->eax == 0x80158570u) goto label_000E8862;
    if (cpu->eax == 0x80158580u) goto label_000E8858;
    if (cpu->eax == 0x80158590u) goto label_000E884E;
    if (cpu->eax != 0x80158600u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Send too large";
    goto label_000EA1A9;
    label_000E884E:
    cpu->eax = (uintptr_t)"Player not reachable";
    goto label_000EA1A9;
    label_000E8858:
    cpu->eax = (uintptr_t)"Player not in group";
    goto label_000EA1A9;
    label_000E8862:
    cpu->eax = (uintptr_t)"Player lost";
    goto label_000EA1A9;
    label_000E886C:
    cpu->eax = (uintptr_t)"Player already in group";
    goto label_000EA1A9;
    label_000E8876:
    cpu->eax = (uintptr_t)"Session full";
    goto label_000EA1A9;
    label_000E8880:
    if (cpu->eax == 0x80158620u) goto label_000E88BE;
    if (cpu->eax == 0x80158630u) goto label_000E88B4;
    if (cpu->eax == 0x80158640u) goto label_000E88AA;
    if (cpu->eax != 0x80158650u) goto label_000EA18F;
    label_000E88A0:
    cpu->eax = (uintptr_t)"User cancel";
    goto label_000EA1A9;
    label_000E88AA:
    cpu->eax = (uintptr_t)"Uninitialized";
    goto label_000EA1A9;
    label_000E88B4:
    cpu->eax = (uintptr_t)"Timed out";
    goto label_000EA1A9;
    label_000E88BE:
    cpu->eax = (uintptr_t)"Table full";
    goto label_000EA1A9;
    label_000E88C8:
    cpu->ecx = 0x88760091u;
    sub_pred[31] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8999;
    if (sub_pred[31]) goto label_000E898F;
    cpu->ecx += 0xFFFFFFCEu;
    sub_pred[32] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8947;
    if (sub_pred[32]) goto label_000E893D;
    if (cpu->eax == 0x8876000Au) goto label_000E8933;
    if (cpu->eax == 0x88760014u) goto label_000E8929;
    if (cpu->eax == 0x88760028u) goto label_000E891F;
    if (cpu->eax == 0x88760037u) goto label_000E8915;
    if (cpu->eax != 0x8876005Au) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Height of rectangle provided is not a multiple of reqd alignment";
    goto label_000EA1A9;
    label_000E8915:
    cpu->eax = (uintptr_t)"An exception was encountered while performing the requested operation";
    goto label_000EA1A9;
    label_000E891F:
    cpu->eax = (uintptr_t)"Support is currently not available.";
    goto label_000EA1A9;
    label_000E8929:
    cpu->eax = (uintptr_t)"This surface can not be detached from the requested surface.";
    goto label_000EA1A9;
    label_000E8933:
    cpu->eax = (uintptr_t)"This surface can not be attached to the requested surface.";
    goto label_000EA1A9;
    label_000E893D:
    cpu->eax = (uintptr_t)"Unable to match primary surface creation request with existing primary surface.";
    goto label_000EA1A9;
    label_000E8947:
    if (cpu->eax == 0x88760064u) goto label_000E8985;
    if (cpu->eax == 0x8876006Eu) goto label_000E897B;
    if (cpu->eax == 0x88760078u) goto label_000E8971;
    if (cpu->eax != 0x88760082u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"DirectDraw received a pointer that was an invalid DIRECTDRAW object.";
    goto label_000EA1A9;
    label_000E8971:
    cpu->eax = (uintptr_t)"DirectDraw does not support the requested mode";
    goto label_000EA1A9;
    label_000E897B:
    cpu->eax = (uintptr_t)"DirectDraw does not support provided Cliplist.";
    goto label_000EA1A9;
    label_000E8985:
    cpu->eax = (uintptr_t)"One or more of the caps bits passed to the callback are incorrect.";
    goto label_000EA1A9;
    label_000E898F:
    cpu->eax = (uintptr_t)"pixel format was invalid as specified";
    goto label_000EA1A9;
    label_000E8999:
    cpu->ecx = 0x887600B6u;
    sub_pred[33] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8A07;
    if (sub_pred[33]) goto label_000E89FD;
    if (cpu->eax == 0x88760096u) goto label_000E89F3;
    if (cpu->eax == 0x887600A0u) goto label_000E89E9;
    if (cpu->eax == 0x887600AAu) goto label_000E89DF;
    if (cpu->eax == 0x887600B4u) goto label_000E89D5;
    if (cpu->eax != 0x887600B5u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no stereo hardware present or available.";
    goto label_000EA1A9;
    label_000E89D5:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no alpha accleration hardware present or available.";
    goto label_000EA1A9;
    label_000E89DF:
    cpu->eax = (uintptr_t)"There is no 3D present.";
    goto label_000EA1A9;
    label_000E89E9:
    cpu->eax = (uintptr_t)"Operation could not be carried out because one or more surfaces are locked";
    goto label_000EA1A9;
    label_000E89F3:
    cpu->eax = (uintptr_t)"Rectangle provided was invalid.";
    goto label_000EA1A9;
    label_000E89FD:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no hardware present which supports stereo surfaces";
    goto label_000EA1A9;
    label_000E8A07:
    if (cpu->eax == 0x887600CDu) goto label_000E8A45;
    if (cpu->eax == 0x887600D2u) goto label_000E8A3B;
    if (cpu->eax == 0x887600D4u) goto label_000E8A31;
    if (cpu->eax != 0x887600D7u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Surface doesn't currently have a color key";
    goto label_000EA1A9;
    label_000E8A31:
    cpu->eax = (uintptr_t)"Create function called without DirectDraw object method SetCooperativeLevel being called.";
    goto label_000EA1A9;
    label_000E8A3B:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no color conversion hardware present or available.";
    goto label_000EA1A9;
    label_000E8A45:
    cpu->eax = (uintptr_t)"no clip list available";
    goto label_000EA1A9;
    label_000E8A4F:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no hardware support of the dest color key.";
    goto label_000EA1A9;
    label_000E8A59:
    cpu->ecx = 0x88760180u;
    sub_pred[34] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8BFD;
    if (sub_pred[34]) goto label_000E8BF3;
    cpu->ecx += 0xFFFFFFB6u;
    sub_pred[35] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8B3D;
    if (sub_pred[35]) goto label_000E8B33;
    cpu->ecx = 0x887600FFu;
    sub_pred[36] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8AEB;
    if (sub_pred[36]) goto label_000E8AE1;
    if (cpu->eax == 0x887600DEu) goto label_000E8AD7;
    if (cpu->eax == 0x887600E1u) goto label_000E8ACD;
    if (cpu->eax == 0x887600E6u) goto label_000E8AC3;
    if (cpu->eax == 0x887600F0u) goto label_000E8AB9;
    if (cpu->eax != 0x887600FAu) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no hardware present or available.";
    goto label_000EA1A9;
    label_000E8AB9:
    cpu->eax = (uintptr_t)"There is no GDI present.";
    goto label_000EA1A9;
    label_000E8AC3:
    cpu->eax = (uintptr_t)"Flipping visible surfaces is not supported.";
    goto label_000EA1A9;
    label_000E8ACD:
    cpu->eax = (uintptr_t)"Operation requires the application to have exclusive mode but the application does not have exclusive mode.";
    goto label_000EA1A9;
    label_000E8AD7:
    cpu->eax = (uintptr_t)"No DirectDraw support possible with current display driver";
    goto label_000EA1A9;
    label_000E8AE1:
    cpu->eax = (uintptr_t)"Requested item was not found";
    goto label_000EA1A9;
    label_000E8AEB:
    if (cpu->eax == 0x88760104u) goto label_000E8B29;
    if (cpu->eax == 0x8876010Eu) goto label_000E8B1F;
    if (cpu->eax == 0x88760118u) goto label_000E8B15;
    if (cpu->eax != 0x88760122u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no rotation hardware present or available.";
    goto label_000EA1A9;
    label_000E8B15:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no appropriate raster op hardware present or available.";
    goto label_000EA1A9;
    label_000E8B1F:
    cpu->eax = (uintptr_t)"Operation could not be carried out because the source and destination rectangles are on the same surface and overlap each other.";
    goto label_000EA1A9;
    label_000E8B29:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no overlay hardware present or available.";
    goto label_000EA1A9;
    label_000E8B33:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no hardware support for stretching";
    goto label_000EA1A9;
    label_000E8B3D:
    cpu->ecx = 0x88760154u;
    sub_pred[37] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8BAB;
    if (sub_pred[37]) goto label_000E8BA1;
    if (cpu->eax == 0x8876013Cu) goto label_000E8B97;
    if (cpu->eax == 0x8876013Du) goto label_000E8B8D;
    if (cpu->eax == 0x88760140u) goto label_000E8B83;
    if (cpu->eax == 0x8876014Au) goto label_000E8B79;
    if (cpu->eax != 0x8876014Fu) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no hardware support for vertical blank synchronized operations.";
    goto label_000EA1A9;
    label_000E8B79:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no texture mapping hardware present or available.";
    goto label_000EA1A9;
    label_000E8B83:
    cpu->eax = (uintptr_t)"DirectDraw Surface is not in 8 bit color mode and the requested operation requires 8 bit color.";
    goto label_000EA1A9;
    label_000E8B8D:
    cpu->eax = (uintptr_t)"DirectDrawSurface is not in 4 bit color index palette and the requested operation requires 4 bit color index palette.";
    goto label_000EA1A9;
    label_000E8B97:
    cpu->eax = (uintptr_t)"DirectDrawSurface is not in 4 bit color palette and the requested operation requires 4 bit color palette.";
    goto label_000EA1A9;
    label_000E8BA1:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no hardware support for zbuffer blting.";
    goto label_000EA1A9;
    label_000E8BAB:
    if (cpu->eax == 0x8876015Eu) goto label_000E8BE9;
    if (cpu->eax == 0x88760168u) goto label_000E8BDF;
    if (cpu->eax == 0x8876017Cu) goto label_000E8BD5;
    if (cpu->eax != 0x8876017Eu) goto label_000EA18F;
    cpu->eax = (uintptr_t)"hardware does not support clipped overlays";
    goto label_000EA1A9;
    label_000E8BD5:
    cpu->eax = (uintptr_t)"Out of video memory";
    goto label_000EA1A9;
    label_000E8BDF:
    cpu->eax = (uintptr_t)"The hardware needed for the requested operation has already been allocated.";
    goto label_000EA1A9;
    label_000E8BE9:
    cpu->eax = (uintptr_t)"Overlay surfaces could not be z layered based on their BltOrder because the hardware does not support z layering of overlays.";
    goto label_000EA1A9;
    label_000E8BF3:
    cpu->eax = (uintptr_t)"Can only have ony color key active at one time for overlays";
    goto label_000EA1A9;
    label_000E8BFD:
    cpu->ecx = 0x887601E0u;
    sub_pred[38] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8CCE;
    if (sub_pred[38]) goto label_000E8CC4;
    cpu->ecx += 0xFFFFFFD3u;
    sub_pred[39] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8C7C;
    if (sub_pred[39]) goto label_000E8C72;
    if (cpu->eax == 0x88760183u) goto label_000E8C68;
    if (cpu->eax == 0x88760190u) goto label_000E8C5E;
    if (cpu->eax == 0x8876019Au) goto label_000E8C54;
    if (cpu->eax == 0x887601A4u) goto label_000E8C4A;
    if (cpu->eax != 0x887601AEu) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Access to this surface is being refused because the surface is already locked by another thread.";
    goto label_000EA1A9;
    label_000E8C4A:
    cpu->eax = (uintptr_t)"This surface is already a dependency of the surface it is being made a dependency of.";
    goto label_000EA1A9;
    label_000E8C54:
    cpu->eax = (uintptr_t)"This surface is already attached to the surface it is being attached to.";
    goto label_000EA1A9;
    label_000E8C5E:
    cpu->eax = (uintptr_t)"No src color key specified for this operation.";
    goto label_000EA1A9;
    label_000E8C68:
    cpu->eax = (uintptr_t)"Access to this palette is being refused because the palette is already locked by another thread.";
    goto label_000EA1A9;
    label_000E8C72:
    cpu->eax = (uintptr_t)"Access to this surface is being refused because no driver exists which can supply a pointer to the surface. This is most likely to happen when attempting to lock the primary surface when no DCI provider is present. Will also happen on attempts to lock an optimized surface.";
    goto label_000EA1A9;
    label_000E8C7C:
    if (cpu->eax == 0x887601B8u) goto label_000E8CBA;
    if (cpu->eax == 0x887601C2u) goto label_000E8CB0;
    if (cpu->eax == 0x887601CCu) goto label_000E8CA6;
    if (cpu->eax != 0x887601D6u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Height requested by DirectDraw is too large.";
    goto label_000EA1A9;
    label_000E8CA6:
    cpu->eax = (uintptr_t)"The requested surface is not attached.";
    goto label_000EA1A9;
    label_000E8CB0:
    cpu->eax = (uintptr_t)"Access to this surface is being refused because the surface is gone. The DIRECTDRAWSURFACE object representing this surface should have Restore called on it.";
    goto label_000EA1A9;
    label_000E8CBA:
    cpu->eax = (uintptr_t)"Access to Surface refused because Surface is obscured.";
    goto label_000EA1A9;
    label_000E8CC4:
    cpu->eax = (uintptr_t)"Size requested by DirectDraw is too large --  The individual height and width are OK.";
    goto label_000EA1A9;
    label_000E8CCE:
    cpu->ecx = 0x8876021Cu;
    sub_pred[40] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8D3C;
    if (sub_pred[40]) goto label_000E8D32;
    if (cpu->eax == 0x887601EAu) goto label_000E8D28;
    if (cpu->eax == 0x887601FEu) goto label_000E8D1E;
    if (cpu->eax == 0x88760208u) goto label_000E8D14;
    if (cpu->eax == 0x88760209u) goto label_000E8D0A;
    if (cpu->eax != 0x88760219u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"vertical blank is in progress";
    goto label_000EA1A9;
    label_000E8D0A:
    cpu->eax = (uintptr_t)"The specified stream contains invalid data";
    goto label_000EA1A9;
    label_000E8D14:
    cpu->eax = (uintptr_t)"Bitmask in the pixel format requested is unsupported by DirectDraw";
    goto label_000EA1A9;
    label_000E8D1E:
    cpu->eax = (uintptr_t)"Pixel format requested is unsupported by DirectDraw";
    goto label_000EA1A9;
    label_000E8D28:
    cpu->eax = (uintptr_t)"Width requested by DirectDraw is too large.";
    goto label_000EA1A9;
    label_000E8D32:
    cpu->eax = (uintptr_t)"Was still drawing";
    goto label_000EA1A9;
    label_000E8D3C:
    if (cpu->eax == 0x8876021Eu) goto label_000E8D7A;
    if (cpu->eax == 0x88760230u) goto label_000E8D70;
    if (cpu->eax == 0x88760231u) goto label_000E8D66;
    if (cpu->eax != 0x88760232u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"A DirectDraw object representing this driver has already been created for this process.";
    goto label_000EA1A9;
    label_000E8D66:
    cpu->eax = (uintptr_t)"The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.";
    goto label_000EA1A9;
    label_000E8D70:
    cpu->eax = (uintptr_t)"Rectangle provided was not horizontally aligned on reqd. boundary";
    goto label_000EA1A9;
    label_000E8D7A:
    cpu->eax = (uintptr_t)"The specified surface type requires specification of the COMPLEX flag";
    goto label_000EA1A9;
    label_000E8D84:
    cpu->eax = (uintptr_t)"A hardware only DirectDraw object creation was attempted but the driver did not support any hardware.";
    goto label_000EA1A9;
    label_000E8D8E:
    cpu->ecx = 0x88760276u;
    sub_pred[41] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8F1B;
    if (sub_pred[41]) goto label_000E8F11;
    cpu->eax += 0x7789FDCCu;
    if (cpu->eax > 0x38u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E8DBD;
        case 1u: goto label_000E8DC7;
        case 2u: goto label_000E8DD1;
        case 3u: goto label_000E8DDB;
        case 4u: goto label_000E8DE5;
        case 5u: goto label_000E8DEF;
        case 6u: goto label_000E8DF9;
        case 7u: goto label_000E8E03;
        case 8u: goto label_000E8E0D;
        case 9u: goto label_000E8E17;
        case 10u: goto label_000E8E21;
        case 11u: goto label_000E8E2B;
        case 12u: goto label_000E8E35;
        case 13u: goto label_000E8E3F;
        case 14u: goto label_000E8E49;
        case 15u: goto label_000E8E53;
        case 16u: goto label_000E8E5D;
        case 17u: goto label_000E8E67;
        case 18u: goto label_000E8E71;
        case 19u: goto label_000E8E7B;
        case 20u: goto label_000E8E85;
        case 21u: goto label_000E8E8F;
        case 22u: goto label_000E8E99;
        case 23u: goto label_000E8EA3;
        case 24u: goto label_000E8EAD;
        case 25u: goto label_000E8EB7;
        case 26u: goto label_000E8EC1;
        case 27u: goto label_000E8ECB;
        case 28u: goto label_000E8ED5;
        case 36u: goto label_000E8EDF;
        case 37u: goto label_000E8EE9;
        case 38u: goto label_000E8EF3;
        case 39u: goto label_000E8EFD;
        case 56u: goto label_000E8F07;
        default: goto label_000EA18F;
    }
    label_000E8DBD:
    cpu->eax = (uintptr_t)"this process already has created a primary surface";
    goto label_000EA1A9;
    label_000E8DC7:
    cpu->eax = (uintptr_t)"software emulation not available.";
    goto label_000EA1A9;
    label_000E8DD1:
    cpu->eax = (uintptr_t)"region passed to Clipper::GetClipList is too small.";
    goto label_000EA1A9;
    label_000E8DDB:
    cpu->eax = (uintptr_t)"an attempt was made to set a clip list for a clipper objec that is already monitoring an hwnd.";
    goto label_000EA1A9;
    label_000E8DE5:
    cpu->eax = (uintptr_t)"No clipper object attached to surface object";
    goto label_000EA1A9;
    label_000E8DEF:
    cpu->eax = (uintptr_t)"Clipper notification requires an HWND or no HWND has previously been set as the CooperativeLevel HWND.";
    goto label_000EA1A9;
    label_000E8DF9:
    cpu->eax = (uintptr_t)"HWND used by DirectDraw CooperativeLevel has been subclassed, this prevents DirectDraw from restoring state.";
    goto label_000EA1A9;
    label_000E8E03:
    cpu->eax = (uintptr_t)"The CooperativeLevel HWND has already been set. It can not be reset while the process has surfaces or palettes created.";
    goto label_000EA1A9;
    label_000E8E0D:
    cpu->eax = (uintptr_t)"No palette object attached to this surface.";
    goto label_000EA1A9;
    label_000E8E17:
    cpu->eax = (uintptr_t)"No hardware support for 16 or 256 color palettes.";
    goto label_000EA1A9;
    label_000E8E21:
    cpu->eax = (uintptr_t)"If a clipper object is attached to the source surface passed into a BltFast call.";
    goto label_000EA1A9;
    label_000E8E2B:
    cpu->eax = (uintptr_t)"No blter.";
    goto label_000EA1A9;
    label_000E8E35:
    cpu->eax = (uintptr_t)"No DirectDraw ROP hardware.";
    goto label_000EA1A9;
    label_000E8E3F:
    cpu->eax = (uintptr_t)"returned when GetOverlayPosition is called on a hidden overlay";
    goto label_000EA1A9;
    label_000E8E49:
    cpu->eax = (uintptr_t)"returned when GetOverlayPosition is called on a overlay that UpdateOverlay has never been called on to establish a destionation.";
    goto label_000EA1A9;
    label_000E8E53:
    cpu->eax = (uintptr_t)"returned when the position of the overlay on the destionation is no longer legal for that destionation.";
    goto label_000EA1A9;
    label_000E8E5D:
    cpu->eax = (uintptr_t)"returned when an overlay member is called for a non-overlay surface";
    goto label_000EA1A9;
    label_000E8E67:
    cpu->eax = (uintptr_t)"An attempt was made to set the cooperative level when it was already set to exclusive.";
    goto label_000EA1A9;
    label_000E8E71:
    cpu->eax = (uintptr_t)"An attempt has been made to flip a surface that is not flippable.";
    goto label_000EA1A9;
    label_000E8E7B:
    cpu->eax = (uintptr_t)"Can't duplicate primary & 3D surfaces, or surfaces that are implicitly created.";
    goto label_000EA1A9;
    label_000E8E85:
    cpu->eax = (uintptr_t)"Surface was not locked.  An attempt to unlock a surface that was not locked at all, or by this process, has been attempted.";
    goto label_000EA1A9;
    label_000E8E8F:
    cpu->eax = (uintptr_t)"Windows can not create any more DCs, or a DC was requested for a paltte-indexed surface when the surface had no palette AND the display mode was not palette-indexed (in this case DirectDraw cannot select a proper palette into the DC)";
    goto label_000EA1A9;
    label_000E8E99:
    cpu->eax = (uintptr_t)"No DC was ever created for this surface.";
    goto label_000EA1A9;
    label_000E8EA3:
    cpu->eax = (uintptr_t)"This surface can not be restored because it was created in a different mode.";
    goto label_000EA1A9;
    label_000E8EAD:
    cpu->eax = (uintptr_t)"This surface can not be restored because it is an implicitly created surface.";
    goto label_000EA1A9;
    label_000E8EB7:
    cpu->eax = (uintptr_t)"The surface being used is not a palette-based surface";
    goto label_000EA1A9;
    label_000E8EC1:
    cpu->eax = (uintptr_t)"The display is currently in an unsupported mode";
    goto label_000EA1A9;
    label_000E8ECB:
    cpu->eax = (uintptr_t)"Operation could not be carried out because there is no mip-map texture mapping hardware present or available.";
    goto label_000EA1A9;
    label_000E8ED5:
    cpu->eax = (uintptr_t)"The requested action could not be performed because the surface was of the wrong type.";
    goto label_000EA1A9;
    label_000E8EDF:
    cpu->eax = (uintptr_t)"Device does not support optimized surfaces, therefore no video memory optimized surfaces";
    goto label_000EA1A9;
    label_000E8EE9:
    cpu->eax = (uintptr_t)"Surface is an optimized surface, but has not yet been allocated any memory";
    goto label_000EA1A9;
    label_000E8EF3:
    cpu->eax = (uintptr_t)"Attempt was made to create or set a device window without first setting the focus window";
    goto label_000EA1A9;
    label_000E8EFD:
    cpu->eax = (uintptr_t)"Attempt was made to set a palette on a mipmap sublevel";
    goto label_000EA1A9;
    label_000E8F07:
    cpu->eax = (uintptr_t)"A DC has already been returned for this surface. Only one DC can be retrieved per surface.";
    goto label_000EA1A9;
    label_000E8F11:
    cpu->eax = (uintptr_t)"An attempt was made to allocate non-local video memory from a device that does not support non-local video memory.";
    goto label_000EA1A9;
    label_000E8F1B:
    cpu->ecx = 0x88781205u;
    sub_pred[42] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9875;
    if (sub_pred[42]) goto label_000E986B;
    cpu->ecx = 0x887800BEu;
    sub_pred[43] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E941F;
    if (sub_pred[43]) goto label_000E9415;
    cpu->ecx = 0x88760818u;
    sub_pred[44] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9190;
    if (sub_pred[44]) goto label_000E9186;
    cpu->ecx = 0x8876036Bu;
    sub_pred[45] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E90C0;
    if (sub_pred[45]) goto label_000E917C;
    cpu->ecx = 0x887602B8u;
    sub_pred[46] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9027;
    if (sub_pred[46]) goto label_000E901D;
    cpu->ecx += 0xFFFFFFFBu;
    sub_pred[47] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E8FD5;
    if (sub_pred[47]) goto label_000E8FCB;
    if (cpu->eax == 0x88760280u) goto label_000E8FC1;
    if (cpu->eax == 0x88760294u) goto label_000E8FB7;
    if (cpu->eax == 0x887602A8u) goto label_000E8FAD;
    if (cpu->eax != 0x887602B2u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"There is more data available than the specified buffer size could hold";
    goto label_000EA1A9;
    label_000E8FAD:
    cpu->eax = (uintptr_t)"An attempt was made to page unlock a surface with no outstanding page locks.";
    goto label_000EA1A9;
    label_000E8FB7:
    cpu->eax = (uintptr_t)"The attempt to page unlock a surface failed.";
    goto label_000EA1A9;
    label_000E8FC1:
    cpu->eax = (uintptr_t)"The attempt to page lock a surface failed.";
    goto label_000EA1A9;
    label_000E8FCB:
    cpu->eax = (uintptr_t)"The data has expired and is therefore no longer valid.";
    goto label_000EA1A9;
    label_000E8FD5:
    if (cpu->eax == 0x887602B4u) goto label_000E9013;
    if (cpu->eax == 0x887602B5u) goto label_000E9009;
    if (cpu->eax == 0x887602B6u) goto label_000E8FFF;
    if (cpu->eax != 0x887602B7u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The video port is not active";
    goto label_000EA1A9;
    label_000E8FFF:
    cpu->eax = (uintptr_t)"D3D has not yet been initialized.";
    goto label_000EA1A9;
    label_000E9009:
    cpu->eax = (uintptr_t)"The mode test has switched to a new mode.";
    goto label_000EA1A9;
    label_000E9013:
    cpu->eax = (uintptr_t)"The mode test has finished executing.";
    goto label_000EA1A9;
    label_000E901D:
    cpu->eax = (uintptr_t)"The monitor does not have EDID data.";
    goto label_000EA1A9;
    label_000E9027:
    cpu->ecx = 0x88760366u;
    sub_pred[48] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E907E;
    if (sub_pred[48]) goto label_000E9074;
    if (cpu->eax == 0x887602B9u) goto label_000E906A;
    if (cpu->eax == 0x887602BBu) goto label_000E9060;
    if (cpu->eax == 0x88760364u) goto label_000E9168;
    if (cpu->eax != 0x88760365u) goto label_000EA18F;
    label_000E9056:
    cpu->eax = (uintptr_t)"Bad data reference";
    goto label_000EA1A9;
    label_000E9060:
    cpu->eax = (uintptr_t)"Surfaces created by one direct draw device cannot be used directly by another direct draw device.";
    goto label_000EA1A9;
    label_000E906A:
    cpu->eax = (uintptr_t)"The driver does not enumerate display mode refresh rates.";
    goto label_000EA1A9;
    label_000E9074:
    cpu->eax = (uintptr_t)"Internal error";
    goto label_000EA1A9;
    label_000E907E:
    if (cpu->eax == 0x88760367u) goto label_000E9172;
    if (cpu->eax == 0x88760368u) goto label_000E90B6;
    if (cpu->eax == 0x88760369u) goto label_000E90AC;
    if (cpu->eax != 0x8876036Au) goto label_000EA18F;
    label_000E90A2:
    cpu->eax = (uintptr_t)"No more data";
    goto label_000EA1A9;
    label_000E90AC:
    cpu->eax = (uintptr_t)"No more stream handles";
    goto label_000EA1A9;
    label_000E90B6:
    cpu->eax = (uintptr_t)"Bad intrinsics";
    goto label_000EA1A9;
    label_000E90C0:
    cpu->eax += 0x7789FC94u;
    if (cpu->eax > 0x29u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E90DC;
        case 24u: goto label_000E90E6;
        case 25u: goto label_000E90F0;
        case 26u: goto label_000E90FA;
        case 27u: goto label_000E9104;
        case 28u: goto label_000E910E;
        case 29u: goto label_000E9118;
        case 30u: goto label_000E9122;
        case 31u: goto label_000E912C;
        case 32u: goto label_000E9136;
        case 33u: goto label_000E9140;
        case 34u: goto label_000E914A;
        case 35u: goto label_000E9154;
        case 36u: goto label_000E915E;
        case 37u: goto label_000E9168;
        case 38u: goto label_000E9056;
        case 39u: goto label_000E9172;
        case 40u: goto label_000E90A2;
        case 41u: goto label_000E917C;
        default: goto label_000EA18F;
    }
label_000E90DC: ;
    cpu->eax = (uintptr_t)"No internet";
    goto label_000EA1A9;
    label_000E90E6:
    cpu->eax = (uintptr_t)"Bad object";
    goto label_000EA1A9;
    label_000E90F0:
    cpu->eax = (uintptr_t)"Bad value";
    goto label_000EA1A9;
    label_000E90FA:
    cpu->eax = (uintptr_t)"Bad type";
    goto label_000EA1A9;
    label_000E9104:
    cpu->eax = (uintptr_t)"Not found";
    goto label_000EA1A9;
    label_000E910E:
    cpu->eax = (uintptr_t)"Not done yet";
    goto label_000EA1A9;
    label_000E9118:
    cpu->eax = (uintptr_t)"File not found";
    goto label_000EA1A9;
    label_000E9122:
    cpu->eax = (uintptr_t)"Resource not found";
    goto label_000EA1A9;
    label_000E912C:
    cpu->eax = (uintptr_t)"Bad resource";
    goto label_000EA1A9;
    label_000E9136:
    cpu->eax = (uintptr_t)"Bad file type";
    goto label_000EA1A9;
    label_000E9140:
    cpu->eax = (uintptr_t)"Bad file version";
    goto label_000EA1A9;
    label_000E914A:
    cpu->eax = (uintptr_t)"Bad file float size";
    goto label_000EA1A9;
    label_000E9154:
    cpu->eax = (uintptr_t)"Bad file";
    goto label_000EA1A9;
    label_000E915E:
    cpu->eax = (uintptr_t)"Parse error";
    goto label_000EA1A9;
    label_000E9168:
    cpu->eax = (uintptr_t)"Bad array size";
    goto label_000EA1A9;
    label_000E9172:
    cpu->eax = (uintptr_t)"No more objects";
    goto label_000EA1A9;
    label_000E917C:
    cpu->eax = (uintptr_t)"Bad cache file";
    goto label_000EA1A9;
    label_000E9186:
    cpu->eax = (uintptr_t)"Wrong texture format";
    goto label_000EA1A9;
    label_000E9190:
    cpu->ecx = 0x88760866u;
    sub_pred[49] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9226;
    if (sub_pred[49]) goto label_000E9104;
    cpu->eax += 0x7789F7E7u;
    if (cpu->eax > 0xEu) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E91B8;
        case 1u: goto label_000E91C2;
        case 2u: goto label_000E91CC;
        case 3u: goto label_000E91D6;
        case 4u: goto label_000E91E0;
        case 5u: goto label_000E91EA;
        case 6u: goto label_000E91F4;
        case 7u: case 10u: case 11u: case 12u: case 24u: goto label_000EA18F;
        case 8u: goto label_000E91FE;
        case 9u: goto label_000E9208;
        case 13u: goto label_000E9212;
        case 14u: goto label_000E921C;
        case 15u: goto label_000E951F;
        case 16u: goto label_000E9529;
        case 17u: goto label_000E9533;
        case 18u: goto label_000E953D;
        case 19u: goto label_000E9547;
        case 20u: goto label_000E9551;
        case 21u: goto label_000E955B;
        case 22u: goto label_000E9565;
        case 23u: goto label_000E956F;
        default: lift_trap(cpu, 0x4E91B1u, "resolved jump-table index out of range"); return;
    }
label_000E91B8: ;
    cpu->eax = (uintptr_t)"Unsupported color operation";
    goto label_000EA1A9;
    label_000E91C2:
    cpu->eax = (uintptr_t)"Unsupported color arg";
    goto label_000EA1A9;
    label_000E91CC:
    cpu->eax = (uintptr_t)"Unsupported alpha operation";
    goto label_000EA1A9;
    label_000E91D6:
    cpu->eax = (uintptr_t)"Unsupported alpha arg";
    goto label_000EA1A9;
    label_000E91E0:
    cpu->eax = (uintptr_t)"Too many operations";
    goto label_000EA1A9;
    label_000E91EA:
    cpu->eax = (uintptr_t)"Conflicting texture filter";
    goto label_000EA1A9;
    label_000E91F4:
    cpu->eax = (uintptr_t)"Unsupported factor value";
    goto label_000EA1A9;
    label_000E91FE:
    cpu->eax = (uintptr_t)"Conflicting render state";
    goto label_000EA1A9;
    label_000E9208:
    cpu->eax = (uintptr_t)"Unsupported texture filter";
    goto label_000EA1A9;
    label_000E9212:
    cpu->eax = (uintptr_t)"Conflicting texture palette";
    goto label_000EA1A9;
    label_000E921C:
    cpu->eax = (uintptr_t)"Driver internal error";
    goto label_000EA1A9;
    label_000E9226:
    cpu->ecx = 0x88760B5Au;
    sub_pred[50] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E932C;
    if (sub_pred[50]) goto label_000E9322;
    cpu->ecx = 0x8876086Du;
    sub_pred[51] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E92B8;
    if (sub_pred[51]) goto label_000E92AE;
    if (cpu->eax == 0x88760867u) goto label_000E92A4;
    if (cpu->eax == 0x88760868u) goto label_000E929A;
    if (cpu->eax == 0x88760869u) goto label_000E9290;
    if (cpu->eax == 0x8876086Au) goto label_000E9286;
    if (cpu->eax == 0x8876086Bu) goto label_000E927C;
    if (cpu->eax != 0x8876086Cu) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Invalid call";
    goto label_000EA1A9;
    label_000E927C:
    cpu->eax = (uintptr_t)"Invalid device";
    goto label_000EA1A9;
    label_000E9286:
    cpu->eax = (uintptr_t)"Not available";
    goto label_000EA1A9;
    label_000E9290:
    cpu->eax = (uintptr_t)"Device not reset";
    goto label_000EA1A9;
    label_000E929A:
    cpu->eax = (uintptr_t)"Device lost";
    goto label_000EA1A9;
    label_000E92A4:
    cpu->eax = (uintptr_t)"More data";
    goto label_000EA1A9;
    label_000E92AE:
    cpu->eax = (uintptr_t)"Driver invalid call";
    goto label_000EA1A9;
    label_000E92B8:
    if (cpu->eax == 0x88760B54u) goto label_000E9318;
    if (cpu->eax == 0x88760B55u) goto label_000E930E;
    if (cpu->eax == 0x88760B56u) goto label_000E9304;
    if (cpu->eax == 0x88760B57u) goto label_000E92FA;
    if (cpu->eax == 0x88760B58u) goto label_000E92F0;
    if (cpu->eax != 0x88760B59u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Invalid data";
    goto label_000EA1A9;
    label_000E92F0:
    cpu->eax = (uintptr_t)"Too many influences";
    goto label_000EA1A9;
    label_000E92FA:
    cpu->eax = (uintptr_t)"Skinning not supported";
    goto label_000EA1A9;
    label_000E9304:
    cpu->eax = (uintptr_t)"Cannot attr sort";
    goto label_000EA1A9;
    label_000E930E:
    cpu->eax = (uintptr_t)"Invalid mesh";
    goto label_000EA1A9;
    label_000E9318:
    cpu->eax = (uintptr_t)"Can not modify index buffer";
    goto label_000EA1A9;
    label_000E9322:
    cpu->eax = (uintptr_t)"Loaded mesh has no data";
    goto label_000EA1A9;
    label_000E932C:
    cpu->ecx = 0x88780064u;
    sub_pred[52] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E93AB;
    if (sub_pred[52]) goto label_000E93A1;
    if (cpu->eax == 0x88760B5Bu) goto label_000E9397;
    if (cpu->eax == 0x88760B5Cu) goto label_000E938D;
    if (cpu->eax == 0x8878000Au) goto label_000E9383;
    if (cpu->eax == 0x8878001Eu) goto label_000E9379;
    if (cpu->eax == 0x88780032u) goto label_000E936F;
    if (cpu->eax != 0x88780046u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The caller does not have the priority level required for the function to succeed";
    goto label_000EA1A9;
    label_000E936F:
    cpu->eax = (uintptr_t)"This call is not valid for the current state of this object";
    goto label_000EA1A9;
    label_000E9379:
    cpu->eax = (uintptr_t)"The control (vol, pan, etc.) requested by the caller is not available";
    goto label_000EA1A9;
    label_000E9383:
    cpu->eax = (uintptr_t)"The call failed because resources (such as a priority level) were already being used by another caller";
    goto label_000EA1A9;
    label_000E938D:
    cpu->eax = (uintptr_t)"Can Not remove last item";
    goto label_000EA1A9;
    label_000E9397:
    cpu->eax = (uintptr_t)"Duplicate named fragment";
    goto label_000EA1A9;
    label_000E93A1:
    cpu->eax = (uintptr_t)"The specified WAVE format is not supported";
    goto label_000EA1A9;
    label_000E93AB:
    if (cpu->eax == 0x88780078u) goto label_000E940B;
    if (cpu->eax == 0x88780082u) goto label_000E9401;
    if (cpu->eax == 0x88780096u) goto label_000E93F7;
    if (cpu->eax == 0x887800A0u) goto label_000E93ED;
    if (cpu->eax == 0x887800AAu) goto label_000E93E3;
    if (cpu->eax != 0x887800B4u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds";
    goto label_000EA1A9;
    label_000E93E3:
    cpu->eax = (uintptr_t)"This object has not been initialized";
    goto label_000EA1A9;
    label_000E93ED:
    cpu->eax = (uintptr_t)"Another app has a higher priority level, preventing this call from succeeding";
    goto label_000EA1A9;
    label_000E93F7:
    cpu->eax = (uintptr_t)"The buffer memory has been lost, and must be restored";
    goto label_000EA1A9;
    label_000E9401:
    cpu->eax = (uintptr_t)"This object is already initialized";
    goto label_000EA1A9;
    label_000E940B:
    cpu->eax = (uintptr_t)"No sound driver is available for use";
    goto label_000EA1A9;
    label_000E9415:
    cpu->eax = (uintptr_t)"Attempt to use DirectSound 8 functionality on an older DirectSound object";
    goto label_000EA1A9;
    label_000E941F:
    cpu->ecx = 0x88781136u;
    sub_pred[53] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9660;
    if (sub_pred[53]) goto label_000E9656;
    cpu->ecx += 0xFFFFFFECu;
    sub_pred[54] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9583;
    if (sub_pred[54]) goto label_000E9579;
    cpu->ecx = 0x88781109u;
    sub_pred[55] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9503;
    if (sub_pred[55]) goto label_000E94F9;
    cpu->ecx += 0xFFFFFFFAu;
    sub_pred[56] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E94B1;
    if (sub_pred[56]) goto label_000E94A7;
    if (cpu->eax == 0x887800C8u) goto label_000E949D;
    if (cpu->eax == 0x887800D2u) goto label_000E9493;
    if (cpu->eax == 0x88781101u) goto label_000E9489;
    if (cpu->eax != 0x88781102u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The requested operation cannot be performed while there are  instantiated ports in any process in the system.";
    goto label_000EA1A9;
    label_000E9489:
    cpu->eax = (uintptr_t)"An unexpected error was returned from a device driver, indicating possible failure of the driver or hardware.";
    goto label_000EA1A9;
    label_000E9493:
    cpu->eax = (uintptr_t)"The GUID specified in an audiopath file does not match a valid MIXIN buffer";
    goto label_000EA1A9;
    label_000E949D:
    cpu->eax = (uintptr_t)"A circular loop of send effects was detected";
    goto label_000EA1A9;
    label_000E94A7:
    cpu->eax = (uintptr_t)"The requested device is already in use (possibly by a non-DirectMusic client) and cannot be opened again.";
    goto label_000EA1A9;
    label_000E94B1:
    if (cpu->eax == 0x88781104u) goto label_000E94EF;
    if (cpu->eax == 0x88781105u) goto label_000E94E5;
    if (cpu->eax == 0x88781106u) goto label_000E94DB;
    if (cpu->eax != 0x88781108u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Error parsing DLS collection. File is corrupt.";
    goto label_000EA1A9;
    label_000E94DB:
    cpu->eax = (uintptr_t)"Download failed due to inability to access or create download buffer.";
    goto label_000EA1A9;
    label_000E94E5:
    cpu->eax = (uintptr_t)"No buffer was prepared for the download data.";
    goto label_000EA1A9;
    label_000E94EF:
    cpu->eax = (uintptr_t)"Buffer is not large enough for requested operation.";
    goto label_000EA1A9;
    label_000E94F9:
    cpu->eax = (uintptr_t)"Wave chunks in DLS collection file are at incorrect offsets.";
    goto label_000EA1A9;
    label_000E9503:
    cpu->eax += 0x7787EEEFu;
    if (cpu->eax > 0x10u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E951F;
        case 2u: goto label_000E9529;
        case 3u: goto label_000E9533;
        case 4u: goto label_000E953D;
        case 5u: goto label_000E9547;
        case 6u: goto label_000E9551;
        case 8u: goto label_000E955B;
        case 15u: goto label_000E9565;
        case 16u: goto label_000E956F;
        default: goto label_000EA18F;
    }
    label_000E951F:
    cpu->eax = (uintptr_t)"Second attempt to load a DLS collection that is currently open. ";
    goto label_000EA1A9;
    label_000E9529:
    cpu->eax = (uintptr_t)"Error reading wave data from DLS collection. Indicates bad file.";
    goto label_000EA1A9;
    label_000E9533:
    cpu->eax = (uintptr_t)"There is no instrument in the collection that matches patch number.";
    goto label_000EA1A9;
    label_000E953D:
    cpu->eax = (uintptr_t)"The IStream* doesn't support Seek().";
    goto label_000EA1A9;
    label_000E9547:
    cpu->eax = (uintptr_t)"The IStream* doesn't support Write().";
    goto label_000EA1A9;
    label_000E9551:
    cpu->eax = (uintptr_t)"The RIFF parser doesn't contain a required chunk while parsing file.";
    goto label_000EA1A9;
    label_000E955B:
    cpu->eax = (uintptr_t)"Invalid download id was used in the process of creating a download buffer.";
    goto label_000EA1A9;
    label_000E9565:
    cpu->eax = (uintptr_t)"Tried to unload an object that was not downloaded or previously unloaded.";
    goto label_000EA1A9;
    label_000E956F:
    cpu->eax = (uintptr_t)"Buffer was already downloaded to synth.";
    goto label_000EA1A9;
    label_000E9579:
    cpu->eax = (uintptr_t)"The specified property item was not recognized by the target object.";
    goto label_000EA1A9;
    label_000E9583:
    cpu->eax += 0x7787EEDDu;
    if (cpu->eax > 0x12u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E9598;
        case 1u: goto label_000E95A2;
        case 2u: goto label_000E95AC;
        case 3u: goto label_000E95B6;
        case 4u: goto label_000E95C0;
        case 5u: goto label_000E95CA;
        case 6u: goto label_000E95D4;
        case 7u: goto label_000E95DE;
        case 8u: goto label_000E95E8;
        case 9u: goto label_000E95F2;
        case 10u: goto label_000E95FC;
        case 11u: goto label_000E9606;
        case 12u: goto label_000E9610;
        case 13u: goto label_000E961A;
        case 14u: goto label_000E9624;
        case 15u: goto label_000E962E;
        case 16u: goto label_000E9638;
        case 17u: goto label_000E9642;
        case 18u: goto label_000E964C;
        case 19u: goto label_000E9699;
        case 20u: goto label_000E96A3;
        case 21u: goto label_000E96AD;
        case 22u: goto label_000E96B7;
        case 23u: goto label_000E96C1;
        case 24u: goto label_000E96CB;
        case 25u: goto label_000E96D5;
        case 26u: goto label_000E96DF;
        case 27u: goto label_000E96E9;
        case 28u: goto label_000E96F3;
        case 29u: goto label_000E96FD;
        case 30u: goto label_000E9707;
        case 31u: goto label_000E9711;
        case 32u: goto label_000E971B;
        case 33u: goto label_000E9725;
        case 34u: goto label_000E972F;
        case 35u: goto label_000E9739;
        case 36u: goto label_000E9743;
        case 37u: goto label_000E968F;
        case 38u: goto label_000E974D;
        case 39u: goto label_000E9757;
        case 40u: goto label_000E9761;
        case 41u: goto label_000E976B;
        case 42u: goto label_000E9775;
        case 43u: goto label_000E977F;
        case 44u: goto label_000EA18F;
        default: lift_trap(cpu, 0x4E9591u, "resolved jump-table index out of range"); return;
    }
label_000E9598: ;
    cpu->eax = (uintptr_t)"The specified property item may not be set on the target object.";
    goto label_000EA1A9;
    label_000E95A2:
    cpu->eax = (uintptr_t)"* The specified property item may not be retrieved from the target object.";
    goto label_000EA1A9;
    label_000E95AC:
    cpu->eax = (uintptr_t)"Wave chunk has more than one interleaved channel. DLS format requires MONO.";
    goto label_000EA1A9;
    label_000E95B6:
    cpu->eax = (uintptr_t)"Invalid articulation chunk in DLS collection.";
    goto label_000EA1A9;
    label_000E95C0:
    cpu->eax = (uintptr_t)"Invalid instrument chunk in DLS collection.";
    goto label_000EA1A9;
    label_000E95CA:
    cpu->eax = (uintptr_t)"Wavelink chunk in DLS collection points to invalid wave.";
    goto label_000EA1A9;
    label_000E95D4:
    cpu->eax = (uintptr_t)"Articulation missing from instrument in DLS collection.";
    goto label_000EA1A9;
    label_000E95DE:
    cpu->eax = (uintptr_t)"Downoaded DLS wave is not in PCM format. ";
    goto label_000EA1A9;
    label_000E95E8:
    cpu->eax = (uintptr_t)"Bad wave chunk in DLS collection";
    goto label_000EA1A9;
    label_000E95F2:
    cpu->eax = (uintptr_t)"Offset Table for download buffer has errors. ";
    goto label_000EA1A9;
    label_000E95FC:
    cpu->eax = (uintptr_t)"Attempted to download unknown data type.";
    goto label_000EA1A9;
    label_000E9606:
    cpu->eax = (uintptr_t)"The operation could not be completed because no sink was connected to the synthesizer.";
    goto label_000EA1A9;
    label_000E9610:
    cpu->eax = (uintptr_t)"An attempt was made to open the software synthesizer while it was already  open.";
    goto label_000EA1A9;
    label_000E961A:
    cpu->eax = (uintptr_t)"An attempt was made to close the software synthesizer while it was already  open.";
    goto label_000EA1A9;
    label_000E9624:
    cpu->eax = (uintptr_t)"The operation could not be completed because the software synth has not  yet been fully configured.";
    goto label_000EA1A9;
    label_000E962E:
    cpu->eax = (uintptr_t)"The operation cannot be carried out while the synthesizer is active.";
    goto label_000EA1A9;
    label_000E9638:
    cpu->eax = (uintptr_t)"An error occurred while attempting to read from the IStream* object.";
    goto label_000EA1A9;
    label_000E9642:
    cpu->eax = (uintptr_t)"The operation cannot be performed because the final instance of the DirectMusic object was released. Ports cannot be used after final  release of the DirectMusic object.";
    goto label_000EA1A9;
    label_000E964C:
    cpu->eax = (uintptr_t)"There was no data in the referenced buffer.";
    goto label_000EA1A9;
    label_000E9656:
    cpu->eax = (uintptr_t)"There is insufficient space to insert the given event into the buffer.";
    goto label_000EA1A9;
    label_000E9660:
    cpu->ecx = 0x88781170u;
    sub_pred[57] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9793;
    if (sub_pred[57]) goto label_000E9789;
    cpu->eax += 0x7787EEC9u;
    if (cpu->eax > 0x30u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E9699;
        case 1u: goto label_000E96A3;
        case 2u: goto label_000E96AD;
        case 3u: goto label_000E96B7;
        case 4u: goto label_000E96C1;
        case 5u: goto label_000E96CB;
        case 6u: goto label_000E96D5;
        case 7u: goto label_000E96DF;
        case 8u: goto label_000E96E9;
        case 25u: goto label_000E96F3;
        case 26u: goto label_000E96FD;
        case 27u: goto label_000E9707;
        case 30u: goto label_000E9711;
        case 31u: goto label_000E971B;
        case 32u: goto label_000E9725;
        case 33u: goto label_000E972F;
        case 34u: goto label_000E9739;
        case 41u: goto label_000E9743;
        case 42u: goto label_000E968F;
        case 43u: goto label_000E974D;
        case 44u: goto label_000E9757;
        case 45u: goto label_000E9761;
        case 46u: goto label_000E976B;
        case 47u: goto label_000E9775;
        case 48u: goto label_000E977F;
        default: goto label_000EA18F;
    }
    label_000E968F:
    cpu->eax = (uintptr_t)"The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)";
    goto label_000EA1A9;
    label_000E9699:
    cpu->eax = (uintptr_t)"The given operation could not be carried out because the port is a capture port.";
    goto label_000EA1A9;
    label_000E96A3:
    cpu->eax = (uintptr_t)"The given operation could not be carried out because the port is a render port.";
    goto label_000EA1A9;
    label_000E96AD:
    cpu->eax = (uintptr_t)"The port could not be created because no DirectSound has been specified. Specify a DirectSound interface via the IDirectMusic::SetDirectSound method; pass NULL to have DirectMusic manage usage of DirectSound.";
    goto label_000EA1A9;
    label_000E96B7:
    cpu->eax = (uintptr_t)"The operation cannot be carried out while the port is active.";
    goto label_000EA1A9;
    label_000E96C1:
    cpu->eax = (uintptr_t)"Invalid DirectSound buffer was handed to port. ";
    goto label_000EA1A9;
    label_000E96CB:
    cpu->eax = (uintptr_t)"Invalid buffer format was handed to the synth sink.";
    goto label_000EA1A9;
    label_000E96D5:
    cpu->eax = (uintptr_t)"The operation cannot be carried out while the synthesizer is inactive.";
    goto label_000EA1A9;
    label_000E96DF:
    cpu->eax = (uintptr_t)"IDirectMusic::SetDirectSound has already been called. It may not be changed while in use.";
    goto label_000EA1A9;
    label_000E96E9:
    cpu->eax = (uintptr_t)"The given event is invalid (either it is not a valid MIDI message or it makes use of running status). The event cannot be packed into the buffer.";
    goto label_000EA1A9;
    label_000E96F3:
    cpu->eax = (uintptr_t)"The IStream* object does not contain data supported by the loading object.";
    goto label_000EA1A9;
    label_000E96FD:
    cpu->eax = (uintptr_t)"The object has already been initialized.";
    goto label_000EA1A9;
    label_000E9707:
    cpu->eax = (uintptr_t)"The file does not contain a valid band.";
    goto label_000EA1A9;
    label_000E9711:
    cpu->eax = (uintptr_t)"The IStream* object's data does not have a track header as the first chunk, and therefore can not be read by the segment object.";
    goto label_000EA1A9;
    label_000E971B:
    cpu->eax = (uintptr_t)"The IStream* object's data does not have a tool header as the first chunk, and therefore can not be read by the graph object.";
    goto label_000EA1A9;
    label_000E9725:
    cpu->eax = (uintptr_t)"The IStream* object's data contains an invalid track header (ckid is 0 and fccType is NULL,) and therefore can not be read by the segment object.";
    goto label_000EA1A9;
    label_000E972F:
    cpu->eax = (uintptr_t)"The IStream* object's data contains an invalid tool header (ckid is 0 and fccType is NULL,) and therefore can not be read by the graph object.";
    goto label_000EA1A9;
    label_000E9739:
    cpu->eax = (uintptr_t)"The graph object was unable to load all tools from the IStream* object data. This may be due to errors in the stream, or the tools being incorrectly registered on the client.";
    goto label_000EA1A9;
    label_000E9743:
    cpu->eax = (uintptr_t)"The segment object was unable to load all tracks from the IStream* object data. This may be due to errors in the stream, or the tracks being incorrectly registered on the client.";
    goto label_000EA1A9;
    label_000E974D:
    cpu->eax = (uintptr_t)"A required object is not initialized or failed to initialize.";
    goto label_000EA1A9;
    label_000E9757:
    cpu->eax = (uintptr_t)"The requested parameter type is currently disabled. Parameter types may be enabled and disabled by certain calls to SetParam().";
    goto label_000EA1A9;
    label_000E9761:
    cpu->eax = (uintptr_t)"The requested parameter type is not supported on the object.";
    goto label_000EA1A9;
    label_000E976B:
    cpu->eax = (uintptr_t)"The time is in the past, and the operation can not succeed.";
    goto label_000EA1A9;
    label_000E9775:
    cpu->eax = (uintptr_t)"The requested track is not contained by the segment.";
    goto label_000EA1A9;
    label_000E977F:
    cpu->eax = (uintptr_t)"The track does not support clock time playback or getparam.";
    goto label_000EA1A9;
    label_000E9789:
    cpu->eax = (uintptr_t)"There is no master clock in the performance. Be sure to call IDirectMusicPerformance::Init().";
    goto label_000EA1A9;
    label_000E9793:
    cpu->ecx = 0x88781186u;
    sub_pred[58] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9812;
    if (sub_pred[58]) goto label_000E9808;
    if (cpu->eax == 0x88781180u) goto label_000E97FE;
    if (cpu->eax == 0x88781181u) goto label_000E97F4;
    if (cpu->eax == 0x88781182u) goto label_000E97EA;
    if (cpu->eax == 0x88781183u) goto label_000E97E0;
    if (cpu->eax == 0x88781184u) goto label_000E97D6;
    if (cpu->eax != 0x88781185u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Object was not found.";
    goto label_000EA1A9;
    label_000E97D6:
    cpu->eax = (uintptr_t)"Unable to find or create object.";
    goto label_000EA1A9;
    label_000E97E0:
    cpu->eax = (uintptr_t)"Search data type is not supported.";
    goto label_000EA1A9;
    label_000E97EA:
    cpu->eax = (uintptr_t)"File open failed - either file doesn't exist or is locked.";
    goto label_000EA1A9;
    label_000E97F4:
    cpu->eax = (uintptr_t)"The requested file path is invalid.";
    goto label_000EA1A9;
    label_000E97FE:
    cpu->eax = (uintptr_t)"The class id field is required and missing in the DMUS_OBJECTDESC.";
    goto label_000EA1A9;
    label_000E9808:
    cpu->eax = (uintptr_t)"The file name is missing from the DMUS_OBJECTDESC.";
    goto label_000EA1A9;
    label_000E9812:
    if (cpu->eax == 0x88781200u) goto label_000E9861;
    if (cpu->eax == 0x88781201u) goto label_000E9857;
    if (cpu->eax == 0x88781202u) goto label_000E984D;
    if (cpu->eax == 0x88781203u) goto label_000E9843;
    if (cpu->eax != 0x88781204u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The DMUS_PMSG has already been sent to the performance object via IDirectMusicPerformance::SendPMsg().";
    goto label_000EA1A9;
    label_000E9843:
    cpu->eax = (uintptr_t)"Segment initialization failed, most likely due to a critical memory situation.";
    goto label_000EA1A9;
    label_000E984D:
    cpu->eax = (uintptr_t)"Value is out of range, for instance the requested length is longer than the segment.";
    goto label_000EA1A9;
    label_000E9857:
    cpu->eax = (uintptr_t)"The tool is already contained in the graph. Create a new instance.";
    goto label_000EA1A9;
    label_000E9861:
    cpu->eax = (uintptr_t)"The file requested is not a valid file.";
    goto label_000EA1A9;
    label_000E986B:
    cpu->eax = (uintptr_t)"The DMUS_PMSG was either not allocated by the performance via IDirectMusicPerformance::AllocPMsg(), or it was already freed via IDirectMusicPerformance::FreePMsg().";
    goto label_000EA1A9;
    label_000E9875:
    cpu->ecx = 0xC8770BC0u;
    sub_pred[59] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9D66;
    if (sub_pred[59]) goto label_000E9D5C;
    cpu->ecx = 0x887A0007u;
    sub_pred[60] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9AA9;
    if (sub_pred[60]) goto label_000E9A9F;
    cpu->ecx = 0x88781223u;
    sub_pred[61] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E998B;
    if (sub_pred[61]) goto label_000E9981;
    cpu->eax += 0x7787EDFAu;
    if (cpu->eax > 0x1Cu) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E98C3;
        case 1u: goto label_000E98CD;
        case 2u: case 3u: case 4u: case 5u: case 6u: case 7u: case 8u: case 9u: case 12u: case 25u:
        case 83u: case 88u: case 89u: goto label_000EA18F;
        case 10u: goto label_000E98D7;
        case 11u: goto label_000E98E1;
        case 13u: goto label_000E98EB;
        case 14u: goto label_000E98F5;
        case 15u: goto label_000E98FF;
        case 16u: goto label_000E9909;
        case 17u: goto label_000E9913;
        case 18u: goto label_000E991D;
        case 19u: goto label_000E9927;
        case 20u: goto label_000E9931;
        case 21u: goto label_000E993B;
        case 22u: goto label_000E9945;
        case 23u: goto label_000E994F;
        case 24u: goto label_000E9959;
        case 26u: goto label_000E9963;
        case 27u: goto label_000E996D;
        case 28u: goto label_000E9977;
        case 29u: goto label_000E99B3;
        case 30u: goto label_000E99BD;
        case 31u: goto label_000E99C7;
        case 32u: goto label_000E99D1;
        case 33u: goto label_000E99DB;
        case 34u: goto label_000E99E5;
        case 35u: goto label_000E99EF;
        case 36u: goto label_000E99F9;
        case 37u: goto label_000E9A03;
        case 38u: goto label_000E9A0D;
        case 39u: goto label_000E9A17;
        case 40u: goto label_000E9A21;
        case 41u: goto label_000E9B91;
        case 42u: goto label_000E9B9B;
        case 43u: goto label_000E9BA5;
        case 44u: goto label_000E9BAF;
        case 45u: goto label_000E9BB9;
        case 46u: goto label_000E9BC3;
        case 47u: goto label_000E9BCD;
        case 48u: goto label_000E9BD7;
        case 49u: goto label_000E9BE1;
        case 50u: goto label_000E9D89;
        case 51u: goto label_000E9D93;
        case 52u: goto label_000E9D9D;
        case 53u: goto label_000E9DA7;
        case 54u: goto label_000E9DB1;
        case 55u: goto label_000E9DBB;
        case 56u: goto label_000E9DC5;
        case 57u: goto label_000E9DCF;
        case 58u: goto label_000E9DD9;
        case 59u: goto label_000E9DE3;
        case 60u: goto label_000E9DED;
        case 61u: goto label_000E9DF7;
        case 62u: goto label_000E9E01;
        case 63u: goto label_000E9E0B;
        case 64u: goto label_000E9E15;
        case 65u: goto label_000E9E1F;
        case 66u: goto label_000E9E29;
        case 67u: goto label_000E9E33;
        case 68u: goto label_000E9E3D;
        case 69u: goto label_000E9E47;
        case 70u: goto label_000E9E51;
        case 71u: goto label_000E9E5B;
        case 72u: goto label_000E9E65;
        case 73u: goto label_000E9E6F;
        case 74u: goto label_000E9E79;
        case 75u: goto label_000E9E83;
        case 76u: goto label_000E9E8D;
        case 77u: goto label_000E9EC1;
        case 78u: goto label_000E9ECB;
        case 79u: goto label_000E9ED5;
        case 80u: goto label_000E9EDF;
        case 81u: goto label_000E9EE9;
        case 82u: goto label_000E9EF3;
        case 84u: goto label_000E9EFD;
        case 85u: goto label_000E9F07;
        case 86u: goto label_000E9F11;
        case 87u: goto label_000E80E3;
        case 90u: goto label_000E9F1B;
        default: lift_trap(cpu, 0x4E98BCu, "resolved jump-table index out of range"); return;
    }
label_000E98C3: ;
    cpu->eax = (uintptr_t)"The default system port could not be opened.";
    goto label_000EA1A9;
    label_000E98CD:
    cpu->eax = (uintptr_t)"A call to MIDIToMusic() or MusicToMIDI() resulted in an error because the requested conversion could not happen. This usually occurs when the provided DMUS_CHORD_KEY structure has an invalid chord or scale pattern.";
    goto label_000EA1A9;
    label_000E98D7:
    cpu->eax = (uintptr_t)"DMUS_E_DESCEND_CHUNK_FAIL is returned when the end of the file  was reached before the desired chunk was found.";
    goto label_000EA1A9;
    label_000E98E1:
    cpu->eax = (uintptr_t)"An attempt to use this object failed because it first needs to be loaded.";
    goto label_000EA1A9;
    label_000E98EB:
    cpu->eax = (uintptr_t)"The activeX scripting engine for the script's language is not compatible with DirectMusic.";
    goto label_000EA1A9;
    label_000E98F5:
    cpu->eax = (uintptr_t)"A varient was used that had a type that is not supported by DirectMusic.";
    goto label_000EA1A9;
    label_000E98FF:
    cpu->eax = (uintptr_t)"An error was encountered while parsing or executing the script. The pErrorInfo parameter (if supplied) was filled with information about the error.";
    goto label_000EA1A9;
    label_000E9909:
    cpu->eax = (uintptr_t)"Loading of oleaut32.dll failed.  VBScript and other activeX scripting languages require use of oleaut32.dll.  On platforms where oleaut32.dll is not present, only the DirectMusicScript language, which doesn't require oleaut32.dll can be used.";
    goto label_000EA1A9;
    label_000E9913:
    cpu->eax = (uintptr_t)"An error occured while parsing a script loaded using LoadScript.  The script that was loaded contains an error.";
    goto label_000EA1A9;
    label_000E991D:
    cpu->eax = (uintptr_t)"The script file is invalid.";
    goto label_000EA1A9;
    label_000E9927:
    cpu->eax = (uintptr_t)"The file contains an invalid script track.";
    goto label_000EA1A9;
    label_000E9931:
    cpu->eax = (uintptr_t)"The script does not contain a variable with the specified name.";
    goto label_000EA1A9;
    label_000E993B:
    cpu->eax = (uintptr_t)"The script does not contain a routine with the specified name.";
    goto label_000EA1A9;
    label_000E9945:
    cpu->eax = (uintptr_t)"Scripts variables for content referenced or embedded in a script cannot be set.";
    goto label_000EA1A9;
    label_000E994F:
    cpu->eax = (uintptr_t)"Attempt was made to set a script's variable by reference to a value that was not an object type.";
    goto label_000EA1A9;
    label_000E9959:
    cpu->eax = (uintptr_t)"Attempt was made to set a script's variable by value to an object that does not support a default value property.";
    goto label_000EA1A9;
    label_000E9963:
    cpu->eax = (uintptr_t)"The file contains an invalid segment trigger track.";
    goto label_000EA1A9;
    label_000E996D:
    cpu->eax = (uintptr_t)"The file contains an invalid lyrics track.";
    goto label_000EA1A9;
    label_000E9977:
    cpu->eax = (uintptr_t)"The file contains an invalid parameter control track.";
    goto label_000EA1A9;
    label_000E9981:
    cpu->eax = (uintptr_t)"A script written in AudioVBScript could not be read because it contained a statement that is not allowed by the AudioVBScript language.";
    goto label_000EA1A9;
    label_000E998B:
    cpu->ecx = 0x88790001u;
    sub_pred[62] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9A35;
    if (sub_pred[62]) goto label_000E9A2B;
    cpu->eax += 0x7787EDDCu;
    if (cpu->eax > 0xBu) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E99B3;
        case 1u: goto label_000E99BD;
        case 2u: goto label_000E99C7;
        case 3u: goto label_000E99D1;
        case 4u: goto label_000E99DB;
        case 5u: goto label_000E99E5;
        case 6u: goto label_000E99EF;
        case 7u: goto label_000E99F9;
        case 8u: goto label_000E9A03;
        case 9u: goto label_000E9A0D;
        case 10u: goto label_000E9A17;
        case 11u: goto label_000E9A21;
        case 12u: goto label_000E9B91;
        case 13u: goto label_000E9B9B;
        case 14u: goto label_000E9BA5;
        case 15u: goto label_000E9BAF;
        case 16u: goto label_000E9BB9;
        case 17u: goto label_000E9BC3;
        case 18u: goto label_000E9BCD;
        case 19u: goto label_000E9BD7;
        case 20u: goto label_000E9BE1;
        case 21u: goto label_000E9D89;
        case 22u: goto label_000E9D93;
        case 23u: goto label_000E9D9D;
        case 24u: goto label_000E9DA7;
        case 25u: goto label_000E9DB1;
        case 26u: goto label_000E9DBB;
        case 27u: goto label_000E9DC5;
        case 28u: goto label_000E9DCF;
        case 29u: goto label_000E9DD9;
        case 30u: goto label_000E9DE3;
        case 31u: goto label_000E9DED;
        case 32u: goto label_000E9DF7;
        case 33u: goto label_000E9E01;
        case 34u: goto label_000E9E0B;
        case 35u: goto label_000E9E15;
        case 36u: goto label_000E9E1F;
        case 37u: goto label_000E9E29;
        case 38u: goto label_000E9E33;
        case 39u: goto label_000E9E3D;
        case 40u: goto label_000E9E47;
        case 41u: goto label_000E9E51;
        case 42u: goto label_000E9E5B;
        case 43u: goto label_000E9E65;
        case 44u: goto label_000E9E6F;
        case 45u: goto label_000E9E79;
        case 46u: goto label_000E9E83;
        case 47u: goto label_000E9E8D;
        case 48u: goto label_000E9EC1;
        case 49u: goto label_000E9ECB;
        case 50u: goto label_000E9ED5;
        case 51u: goto label_000E9EDF;
        case 52u: goto label_000E9EE9;
        case 53u: goto label_000E9EF3;
        case 54u: case 59u: case 60u: goto label_000EA18F;
        case 55u: goto label_000E9EFD;
        case 56u: goto label_000E9F07;
        case 57u: goto label_000E9F11;
        case 58u: goto label_000E80E3;
        case 61u: goto label_000E9F1B;
        default: lift_trap(cpu, 0x4E99ACu, "resolved jump-table index out of range"); return;
    }
    label_000E99B3:
    cpu->eax = (uintptr_t)"A script routine written in AudioVBScript failed because an invalid operation occurred.  For example, adding the number 3 to a segment object would produce this error.  So would attempting to call a routine that doesn't exist.";
    goto label_000EA1A9;
    label_000E99BD:
    cpu->eax = (uintptr_t)"A script routine written in AudioVBScript failed because a function outside of a script failed to complete. For example, a call to PlaySegment that fails to play because of low memory would return this error.";
    goto label_000EA1A9;
    label_000E99C7:
    cpu->eax = (uintptr_t)"The Performance has set up some PChannels using the AssignPChannel command, which makes it not capable of supporting audio paths.";
    goto label_000EA1A9;
    label_000E99D1:
    cpu->eax = (uintptr_t)"This is the inverse of the previous error. The Performance has set up some audio paths, which makes is incompatible with the calls to allocate pchannels, etc. ";
    goto label_000EA1A9;
    label_000E99DB:
    cpu->eax = (uintptr_t)"A segment or song was asked for its embedded audio path configuration, but there isn't any. ";
    goto label_000EA1A9;
    label_000E99E5:
    cpu->eax = (uintptr_t)"An audiopath is inactive, perhaps because closedown was called.";
    goto label_000EA1A9;
    label_000E99EF:
    cpu->eax = (uintptr_t)"An audiopath failed to create because a requested buffer could not be created.";
    goto label_000EA1A9;
    label_000E99F9:
    cpu->eax = (uintptr_t)"An audiopath could not be used for playback because it lacked port assignments.";
    goto label_000EA1A9;
    label_000E9A03:
    cpu->eax = (uintptr_t)"Attempt was made to play segment in audiopath mode and there was no audiopath.";
    goto label_000EA1A9;
    label_000E9A0D:
    cpu->eax = (uintptr_t)"Invalid data was found in a RIFF file chunk.";
    goto label_000EA1A9;
    label_000E9A17:
    cpu->eax = (uintptr_t)"Attempt was made to create an audiopath that sends to a global effects buffer which did not exist.";
    goto label_000EA1A9;
    label_000E9A21:
    cpu->eax = (uintptr_t)"The file does not contain a valid container object.";
    goto label_000EA1A9;
    label_000E9A2B:
    cpu->eax = (uintptr_t)"There are too many unique state objects.";
    goto label_000EA1A9;
    label_000E9A35:
    if (cpu->eax == 0x887A0001u) goto label_000E9A95;
    if (cpu->eax == 0x887A0002u) goto label_000E9A8B;
    if (cpu->eax == 0x887A0003u) goto label_000E9A81;
    if (cpu->eax == 0x887A0004u) goto label_000E9A77;
    if (cpu->eax == 0x887A0005u) goto label_000E9A6D;
    if (cpu->eax != 0x887A0006u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Device hung.";
    goto label_000EA1A9;
    label_000E9A6D:
    cpu->eax = (uintptr_t)"Device removed.";
    goto label_000EA1A9;
    label_000E9A77:
    cpu->eax = (uintptr_t)"Unsupported.";
    goto label_000EA1A9;
    label_000E9A81:
    cpu->eax = (uintptr_t)"The specified size of the destination buffer is too small to hold the requested data.";
    goto label_000EA1A9;
    label_000E9A8B:
    cpu->eax = (uintptr_t)"The item requested was not found. For GetPrivateData calls, this means that the specified GUID had not been previously associated with the object.";
    goto label_000EA1A9;
    label_000E9A95:
    cpu->eax = (uintptr_t)"The application has made an erroneous API call that it had enough information to avoid. This error is intended to denote that the application should be altered to avoid the error. Use of the debug version of the DXGI.DLL will provide run-time debug output with further information.";
    goto label_000EA1A9;
    label_000E9A9F:
    cpu->eax = (uintptr_t)"Device reset.";
    goto label_000EA1A9;
    label_000E9AA9:
    cpu->ecx = 0x8AC70011u;
    sub_pred[63] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9BF5;
    if (sub_pred[63]) goto label_000E9BEB;
    cpu->ecx += 0xFFFFFFF6u;
    sub_pred[64] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9B7C;
    if (sub_pred[64]) goto label_000E9B72;
    cpu->ecx = 0x8AC70002u;
    sub_pred[65] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9B2A;
    if (sub_pred[65]) goto label_000E9B20;
    if (cpu->eax == 0x887A000Au) goto label_000E9B16;
    if (cpu->eax == 0x887A0020u) goto label_000E9B0C;
    if (cpu->eax == 0x887A0021u) goto label_000E9B02;
    if (cpu->eax != 0x8AC70001u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The engine is already initialized.";
    goto label_000EA1A9;
    label_000E9B02:
    cpu->eax = (uintptr_t)"The application attempted to perform an operation on an DXGI output that is only legal after the output has been claimed for exclusive owenership.";
    goto label_000EA1A9;
    label_000E9B0C:
    cpu->eax = (uintptr_t)"An internal driver error occurred.";
    goto label_000EA1A9;
    label_000E9B16:
    cpu->eax = (uintptr_t)"Was still drawing.";
    goto label_000EA1A9;
    label_000E9B20:
    cpu->eax = (uintptr_t)"The engine has not been initialized.";
    goto label_000EA1A9;
    label_000E9B2A:
    if (cpu->eax == 0x8AC70003u) goto label_000E9B68;
    if (cpu->eax == 0x8AC70004u) goto label_000E9B5E;
    if (cpu->eax == 0x8AC70005u) goto label_000E9B54;
    if (cpu->eax != 0x8AC70006u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Invalid usage.";
    goto label_000EA1A9;
    label_000E9B54:
    cpu->eax = (uintptr_t)"Notification already registered.";
    goto label_000EA1A9;
    label_000E9B5E:
    cpu->eax = (uintptr_t)"No notification callback.";
    goto label_000EA1A9;
    label_000E9B68:
    cpu->eax = (uintptr_t)"The engine has expired (demo or pre-release version).";
    goto label_000EA1A9;
    label_000E9B72:
    cpu->eax = (uintptr_t)"Invalid data.";
    goto label_000EA1A9;
    label_000E9B7C:
    cpu->eax += 0x7538FFF8u;
    if (cpu->eax > 8u) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E9B91;
        case 1u: goto label_000E9B9B;
        case 2u: goto label_000E9BA5;
        case 3u: goto label_000E9BAF;
        case 4u: goto label_000E9BB9;
        case 5u: goto label_000E9BC3;
        case 6u: goto label_000E9BCD;
        case 7u: goto label_000E9BD7;
        case 8u: goto label_000E9BE1;
        case 9u: goto label_000E9D89;
        case 10u: goto label_000E9D93;
        case 11u: goto label_000E9D9D;
        case 12u: goto label_000E9DA7;
        case 13u: goto label_000E9DB1;
        case 14u: goto label_000E9DBB;
        case 15u: goto label_000E9DC5;
        case 16u: goto label_000E9DCF;
        case 17u: goto label_000E9DD9;
        case 18u: goto label_000E9DE3;
        case 19u: goto label_000E9DED;
        case 20u: goto label_000E9DF7;
        case 21u: goto label_000E9E01;
        case 22u: goto label_000E9E0B;
        case 23u: goto label_000E9E15;
        case 24u: goto label_000E9E1F;
        case 25u: goto label_000E9E29;
        case 26u: goto label_000E9E33;
        case 27u: goto label_000E9E3D;
        case 28u: goto label_000E9E47;
        case 29u: goto label_000E9E51;
        case 30u: goto label_000E9E5B;
        case 31u: goto label_000E9E65;
        case 32u: goto label_000E9E6F;
        case 33u: goto label_000E9E79;
        case 34u: goto label_000E9E83;
        case 35u: goto label_000E9E8D;
        case 36u: goto label_000E9EC1;
        case 37u: goto label_000E9ECB;
        case 38u: goto label_000E9ED5;
        case 39u: goto label_000E9EDF;
        case 40u: goto label_000E9EE9;
        case 41u: goto label_000E9EF3;
        case 42u: case 47u: case 48u: goto label_000EA18F;
        case 43u: goto label_000E9EFD;
        case 44u: goto label_000E9F07;
        case 45u: goto label_000E9F11;
        case 46u: goto label_000E80E3;
        case 49u: goto label_000E9F1B;
        default: lift_trap(cpu, 0x4E9B8Au, "resolved jump-table index out of range"); return;
    }
    label_000E9B91:
    cpu->eax = (uintptr_t)"Fail to play due to instance limit.";
    goto label_000EA1A9;
    label_000E9B9B:
    cpu->eax = (uintptr_t)"Global Settings not loaded.";
    goto label_000EA1A9;
    label_000E9BA5:
    cpu->eax = (uintptr_t)"Invalid variable index.";
    goto label_000EA1A9;
    label_000E9BAF:
    cpu->eax = (uintptr_t)"Invalid category.";
    goto label_000EA1A9;
    label_000E9BB9:
    cpu->eax = (uintptr_t)"Invalid cue index.";
    goto label_000EA1A9;
    label_000E9BC3:
    cpu->eax = (uintptr_t)"Invalid wave index.";
    goto label_000EA1A9;
    label_000E9BCD:
    cpu->eax = (uintptr_t)"Invalid track index.";
    goto label_000EA1A9;
    label_000E9BD7:
    cpu->eax = (uintptr_t)"Invalid sound offset or index.";
    goto label_000EA1A9;
    label_000E9BE1:
    cpu->eax = (uintptr_t)"Error reading a file.";
    goto label_000EA1A9;
    label_000E9BEB:
    cpu->eax = (uintptr_t)"Unknown event type.";
    goto label_000EA1A9;
    label_000E9BF5:
    cpu->ecx = 0x8AC70105u;
    sub_pred[66] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9CB7;
    if (sub_pred[66]) goto label_000E9CAD;
    cpu->ecx = 0x8AC70016u;
    sub_pred[67] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9C65;
    if (sub_pred[67]) goto label_000E9C5B;
    if (cpu->eax == 0x8AC70012u) goto label_000E9C51;
    if (cpu->eax == 0x8AC70013u) goto label_000E9C47;
    if (cpu->eax == 0x8AC70014u) goto label_000E9C3D;
    if (cpu->eax != 0x8AC70015u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"There can be only one audition engine.";
    goto label_000EA1A9;
    label_000E9C3D:
    cpu->eax = (uintptr_t)"Unable to select a variation.";
    goto label_000EA1A9;
    label_000E9C47:
    cpu->eax = (uintptr_t)"No wavebank exists for desired operation.";
    goto label_000EA1A9;
    label_000E9C51:
    cpu->eax = (uintptr_t)"Invalid call of method of function from callback.";
    goto label_000EA1A9;
    label_000E9C5B:
    cpu->eax = (uintptr_t)"The wavebank is not prepared.";
    goto label_000EA1A9;
    label_000E9C65:
    if (cpu->eax == 0x8AC70101u) goto label_000E9CA3;
    if (cpu->eax == 0x8AC70102u) goto label_000E9C99;
    if (cpu->eax == 0x8AC70103u) goto label_000E9C8F;
    if (cpu->eax != 0x8AC70104u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Missing data for an audition command.";
    goto label_000EA1A9;
    label_000E9C8F:
    cpu->eax = (uintptr_t)"Missing an RPC curve.";
    goto label_000EA1A9;
    label_000E9C99:
    cpu->eax = (uintptr_t)"Missing a soundbank.";
    goto label_000EA1A9;
    label_000E9CA3:
    cpu->eax = (uintptr_t)"Error writing a file during auditioning.";
    goto label_000EA1A9;
    label_000E9CAD:
    cpu->eax = (uintptr_t)"Unknown command.";
    goto label_000EA1A9;
    label_000E9CB7:
    cpu->ecx = 0xC8770BBBu;
    sub_pred[68] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9D14;
    if (sub_pred[68]) goto label_000E9D0A;
    if (cpu->eax == 0x8AC70106u) goto label_000E9D00;
    if (cpu->eax == 0xC8770BB8u) goto label_000E9CF6;
    if (cpu->eax == 0xC8770BB9u) goto label_000E9CEC;
    if (cpu->eax != 0xC8770BBAu) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The Device Index passed in is invalid";
    goto label_000EA1A9;
    label_000E9CEC:
    cpu->eax = (uintptr_t)"A NULL pointer was passed as a parameter";
    goto label_000EA1A9;
    label_000E9CF6:
    cpu->eax = (uintptr_t)"Out of memory";
    goto label_000EA1A9;
    label_000E9D00:
    cpu->eax = (uintptr_t)"Missing a DSP parameter.";
    goto label_000EA1A9;
    label_000E9D0A:
    cpu->eax = (uintptr_t)"DirectDraw has not been created";
    goto label_000EA1A9;
    label_000E9D14:
    if (cpu->eax == 0xC8770BBCu) goto label_000E9D52;
    if (cpu->eax == 0xC8770BBDu) goto label_000E9D48;
    if (cpu->eax == 0xC8770BBEu) goto label_000E9D3E;
    if (cpu->eax != 0xC8770BBFu) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Z buffer has not been created";
    goto label_000EA1A9;
    label_000E9D3E:
    cpu->eax = (uintptr_t)"Primary surface has not been created";
    goto label_000EA1A9;
    label_000E9D48:
    cpu->eax = (uintptr_t)"Direct3D device has not been created";
    goto label_000EA1A9;
    label_000E9D52:
    cpu->eax = (uintptr_t)"Direct3D has not been created";
    goto label_000EA1A9;
    label_000E9D5C:
    cpu->eax = (uintptr_t)"Backbuffer has not been created";
    goto label_000EA1A9;
    label_000E9D66:
    lift_test[0]=cpu->eax==0u;
    if ((cpu->eax!=0u) && (((cpu->eax)&0x80000000u)==0u)) goto label_000E9EA1;
    if (lift_test[0]) goto label_000E9E97;
    cpu->eax += 0x3788F43Fu;
    if (cpu->eax > 0x1Au) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E9D89;
        case 1u: goto label_000E9D93;
        case 2u: goto label_000E9D9D;
        case 3u: goto label_000E9DA7;
        case 4u: goto label_000E9DB1;
        case 5u: goto label_000E9DBB;
        case 6u: goto label_000E9DC5;
        case 7u: goto label_000E9DCF;
        case 8u: goto label_000E9DD9;
        case 9u: goto label_000E9DE3;
        case 10u: goto label_000E9DED;
        case 11u: goto label_000E9DF7;
        case 12u: goto label_000E9E01;
        case 13u: goto label_000E9E0B;
        case 14u: goto label_000E9E15;
        case 15u: goto label_000E9E1F;
        case 16u: goto label_000E9E29;
        case 17u: goto label_000E9E33;
        case 18u: goto label_000E9E3D;
        case 19u: goto label_000E9E47;
        case 20u: goto label_000E9E51;
        case 21u: goto label_000E9E5B;
        case 22u: goto label_000E9E65;
        case 23u: goto label_000E9E6F;
        case 24u: goto label_000E9E79;
        case 25u: goto label_000E9E83;
        case 26u: goto label_000E9E8D;
        case 27u: goto label_000E9EC1;
        case 28u: goto label_000E9ECB;
        case 29u: goto label_000E9ED5;
        case 30u: goto label_000E9EDF;
        case 31u: goto label_000E9EE9;
        case 32u: goto label_000E9EF3;
        case 33u: case 38u: case 39u: goto label_000EA18F;
        case 34u: goto label_000E9EFD;
        case 35u: goto label_000E9F07;
        case 36u: goto label_000E9F11;
        case 37u: goto label_000E80E3;
        case 40u: goto label_000E9F1B;
        default: lift_trap(cpu, 0x4E9D82u, "resolved jump-table index out of range"); return;
    }
    label_000E9D89:
    cpu->eax = (uintptr_t)"Failed to update caps database after changing display mode";
    goto label_000EA1A9;
    label_000E9D93:
    cpu->eax = (uintptr_t)"Could not create Z buffer";
    goto label_000EA1A9;
    label_000E9D9D:
    cpu->eax = (uintptr_t)"Display mode is not valid";
    goto label_000EA1A9;
    label_000E9DA7:
    cpu->eax = (uintptr_t)"One or more of the parameters passed is invalid";
    goto label_000EA1A9;
    label_000E9DB1:
    cpu->eax = (uintptr_t)"D3DX failed to initialize itself";
    goto label_000EA1A9;
    label_000E9DBB:
    cpu->eax = (uintptr_t)"D3DX failed to start up";
    goto label_000EA1A9;
    label_000E9DC5:
    cpu->eax = (uintptr_t)"D3DXInitialize() must be called first";
    goto label_000EA1A9;
    label_000E9DCF:
    cpu->eax = (uintptr_t)"D3DX is not initialized yet";
    goto label_000EA1A9;
    label_000E9DD9:
    cpu->eax = (uintptr_t)"Failed to render text to the surface";
    goto label_000EA1A9;
    label_000E9DE3:
    cpu->eax = (uintptr_t)"Bad D3DX context";
    goto label_000EA1A9;
    label_000E9DED:
    cpu->eax = (uintptr_t)"The requested device capabilities are not supported";
    goto label_000EA1A9;
    label_000E9DF7:
    cpu->eax = (uintptr_t)"The image file format is unrecognized";
    goto label_000EA1A9;
    label_000E9E01:
    cpu->eax = (uintptr_t)"The image file loading library error";
    goto label_000EA1A9;
    label_000E9E0B:
    cpu->eax = (uintptr_t)"Could not obtain device caps";
    goto label_000EA1A9;
    label_000E9E15:
    cpu->eax = (uintptr_t)"Resize does not work for full-screen";
    goto label_000EA1A9;
    label_000E9E1F:
    cpu->eax = (uintptr_t)"Resize does not work for non-windowed contexts";
    goto label_000EA1A9;
    label_000E9E29:
    cpu->eax = (uintptr_t)"Front buffer already exists";
    goto label_000EA1A9;
    label_000E9E33:
    cpu->eax = (uintptr_t)"The app is using the primary in full-screen mode";
    goto label_000EA1A9;
    label_000E9E3D:
    cpu->eax = (uintptr_t)"Could not get device context";
    goto label_000EA1A9;
    label_000E9E47:
    cpu->eax = (uintptr_t)"Could not bitBlt";
    goto label_000EA1A9;
    label_000E9E51:
    cpu->eax = (uintptr_t)"There is no surface backing up this texture";
    goto label_000EA1A9;
    label_000E9E5B:
    cpu->eax = (uintptr_t)"There is no such miplevel for this surface";
    goto label_000EA1A9;
    label_000E9E65:
    cpu->eax = (uintptr_t)"The surface is not paletted";
    goto label_000EA1A9;
    label_000E9E6F:
    cpu->eax = (uintptr_t)"An error occured while enumerating surface formats";
    goto label_000EA1A9;
    label_000E9E79:
    cpu->eax = (uintptr_t)"D3DX only supports color depths of 16 bit or greater";
    goto label_000EA1A9;
    label_000E9E83:
    cpu->eax = (uintptr_t)"The file format is invalid";
    goto label_000EA1A9;
    label_000E9E8D:
    cpu->eax = (uintptr_t)"No suitable match found";
    goto label_000EA1A9;
    label_000E9E97:
    cpu->eax = (uintptr_t)"The function completed successfully";
    goto label_000EA1A9;
    label_000E9EA1:
    cpu->ecx = 0x40003u;
    sub_pred[69] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9F2F;
    if (sub_pred[69]) goto label_000E9F25;
    --cpu->eax;
    if (cpu->eax > 0xDu) goto label_000EA18F;
    switch (cpu->eax) {
        case 0u: goto label_000E9EC1;
        case 1u: goto label_000E9ECB;
        case 2u: goto label_000E9ED5;
        case 3u: goto label_000E9EDF;
        case 4u: goto label_000E9EE9;
        case 5u: goto label_000E9EF3;
        case 6u: case 11u: case 12u: goto label_000EA18F;
        case 7u: goto label_000E9EFD;
        case 8u: goto label_000E9F07;
        case 9u: goto label_000E9F11;
        case 10u: goto label_000E80E3;
        case 13u: goto label_000E9F1B;
        default: lift_trap(cpu, 0x4E9EBAu, "resolved jump-table index out of range"); return;
    }
    label_000E9EC1:
    cpu->eax = (uintptr_t)"Call successful, but returned FALSE";
    goto label_000EA1A9;
    label_000E9ECB:
    cpu->eax = (uintptr_t)"The system cannot find the file specified.";
    goto label_000EA1A9;
    label_000E9ED5:
    cpu->eax = (uintptr_t)"The system cannot find the path specified.";
    goto label_000EA1A9;
    label_000E9EDF:
    cpu->eax = (uintptr_t)"The system cannot open the file.";
    goto label_000EA1A9;
    label_000E9EE9:
    cpu->eax = (uintptr_t)"Access is denied.";
    goto label_000EA1A9;
    label_000E9EF3:
    cpu->eax = (uintptr_t)"The handle is invalid.";
    goto label_000EA1A9;
    label_000E9EFD:
    cpu->eax = (uintptr_t)"Not enough storage is available to process this command.";
    goto label_000EA1A9;
    label_000E9F07:
    cpu->eax = (uintptr_t)"The storage control block address is invalid.";
    goto label_000EA1A9;
    label_000E9F11:
    cpu->eax = (uintptr_t)"The environment is incorrect.";
    goto label_000EA1A9;
    label_000E9F1B:
    cpu->eax = (uintptr_t)"The system cannot find the drive specified.";
    goto label_000EA1A9;
    label_000E9F25:
    cpu->eax = (uintptr_t)"End of stream. Sample not updated.";
    goto label_000EA1A9;
    label_000E9F2F:
    cpu->ecx = 0x4028Du;
    sub_pred[70] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000EA09A;
    if (sub_pred[70]) goto label_000EA090;
    cpu->ecx += 0xFFFFFFCBu;
    sub_pred[71] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9FF8;
    if (sub_pred[71]) goto label_000E9FEE;
    cpu->ecx = 0x40245u;
    sub_pred[72] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000E9FAC;
    if (sub_pred[72]) goto label_000E9FA2;
    if ((cpu->eax -= 0x40103u) == 0u) goto label_000E9F98;
    if ((cpu->eax -= 0x12Au) == 0u) goto label_000E9F8E;
    if ((cpu->eax -= 0xAu) == 0u) goto label_000E9F84;
    if ((cpu->eax -= 0xBu) != 0u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Some of the streams in this movie are in an unsupported format.";
    goto label_000EA1A9;
    label_000E9F84:
    cpu->eax = (uintptr_t)"The state transition has not completed.";
    goto label_000EA1A9;
    label_000E9F8E:
    cpu->eax = (uintptr_t)"An attempt to add a filter with a duplicate name succeeded with a modified name.";
    goto label_000EA1A9;
    label_000E9F98:
    cpu->eax = (uintptr_t)"The end of the list has been reached.";
    goto label_000EA1A9;
    label_000E9FA2:
    cpu->eax = (uintptr_t)"The file contained some property settings that were not used.";
    goto label_000EA1A9;
    label_000E9FAC:
    if ((cpu->eax -= 0x40246u) == 0u) goto label_000E9FE4;
    if ((cpu->eax -= 0xAu) == 0u) goto label_000E9FDA;
    if ((cpu->eax -= 4u) == 0u) goto label_000E9FD0;
    if ((cpu->eax -= 3u) != 0u) goto label_000EA18F;
    label_000E9FC6:
    cpu->eax = (uintptr_t)"Cannot play back the video stream: no suitable decompressor could be found.";
    goto label_000EA1A9;
    label_000E9FD0:
    cpu->eax = (uintptr_t)"A connection could not be made with the media type in the persistent graph, but has been made with a negotiated media type.";
    goto label_000EA1A9;
    label_000E9FDA:
    cpu->eax = (uintptr_t)"The resource specified is no longer needed.";
    goto label_000EA1A9;
    label_000E9FE4:
    cpu->eax = (uintptr_t)"Some connections have failed and have been deferred.";
    goto label_000EA1A9;
    label_000E9FEE:
    cpu->eax = (uintptr_t)"Cannot play back the audio stream: no audio hardware is available.";
    goto label_000EA1A9;
    label_000E9FF8:
    cpu->ecx = 0x40268u;
    sub_pred[73] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000EA04F;
    if (sub_pred[73]) goto label_000EA045;
    if ((cpu->eax -= 0x4025Au) == 0u) goto label_000EA03B;
    if ((cpu->eax -= 6u) == 0u) goto label_000EA031;
    if ((cpu->eax -= 3u) == 0u) goto label_000EA027;
    if ((cpu->eax -= 4u) != 0u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The stream has been turned off.";
    goto label_000EA1A9;
    label_000EA027:
    cpu->eax = (uintptr_t)"This success code is reserved for internal purposes within ActiveMovie.";
    goto label_000EA1A9;
    label_000EA031:
    cpu->eax = (uintptr_t)"The value returned had to be estimated.  It's accuracy can not be guaranteed.";
    goto label_000EA1A9;
    label_000EA03B:
    cpu->eax = (uintptr_t)"Cannot play back the video stream: format 'RPZA' is not supported.";
    goto label_000EA1A9;
    label_000EA045:
    cpu->eax = (uintptr_t)"The graph can't be cued because of lack of or corrupt data.";
    goto label_000EA1A9;
    label_000EA04F:
    if ((cpu->eax -= 0x40270u) == 0u) goto label_000EA086;
    if ((cpu->eax -= 0xEu) == 0u) goto label_000EA07C;
    --cpu->eax;
    if ((--cpu->eax) == 0u) goto label_000EA072;
    if ((cpu->eax -= 0xCu) != 0u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The audio stream did not contain sufficient information to determine the contents of each channel.";
    goto label_000EA1A9;
    label_000EA072:
    cpu->eax = (uintptr_t)"The current title was not a sequential set of chapters (PGC), and the returned timing information might not be continuous.";
    goto label_000EA1A9;
    label_000EA07C:
    cpu->eax = (uintptr_t)"There was no preview pin available, so the capture pin output is being split to provide both capture and preview.";
    goto label_000EA1A9;
    label_000EA086:
    cpu->eax = (uintptr_t)"The stop time for the sample was not set.";
    goto label_000EA1A9;
    label_000EA090:
    cpu->eax = (uintptr_t)"The seek into the movie was not frame accurate.";
    goto label_000EA1A9;
    label_000EA09A:
    cpu->ecx = 0x8781202u;
    sub_pred[74] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000EA140;
    if (sub_pred[74]) goto label_000EA139;
    cpu->ecx = 0x878000Au;
    sub_pred[75] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000EA106;
    if (sub_pred[75]) goto label_000EA0FC;
    if ((cpu->eax -= 0x150005u) == 0u) goto label_000EA0F2;
    if ((cpu->eax -= 5u) == 0u) goto label_000EA0E8;
    if ((cpu->eax -= 6u) == 0u) goto label_000EA0DE;
    if ((cpu->eax -= 0x861085Fu) != 0u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"The call succeeded but there won't be any mipmaps generated";
    goto label_000EA1A9;
    label_000EA0DE:
    cpu->eax = (uintptr_t)"Pending";
    goto label_000EA1A9;
    label_000EA0E8:
    cpu->eax = (uintptr_t)"Half duplex";
    goto label_000EA1A9;
    label_000EA0F2:
    cpu->eax = (uintptr_t)"Full duplex";
    goto label_000EA1A9;
    label_000EA0FC:
    cpu->eax = (uintptr_t)"The call succeeded, but we had to substitute the 3D algorithm";
    goto label_000EA1A9;
    label_000EA106:
    if ((cpu->eax -= 0x8781091u) == 0u) goto label_000EA132;
    if ((--cpu->eax) == 0u) goto label_000EA12B;
    if ((cpu->eax -= 0x16Eu) == 0u) goto label_000EA124;
    if ((--cpu->eax) != 0u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should free the PMsg automatically.";
    goto label_000EA1A9;
    label_000EA124:
    cpu->eax = (uintptr_t)"Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should cue the PMsg again automatically.";
    goto label_000EA1A9;
    label_000EA12B:
    cpu->eax = (uintptr_t)"Return value from IDirectMusicBand::Download() which indicates that some of the instruments safely downloaded, but others failed. This usually occurs when some instruments are on PChannels not supported by the performance or port.";
    goto label_000EA1A9;
    label_000EA132:
    cpu->eax = (uintptr_t)"The object could only load partially. This can happen if some components are not registered properly, such as embedded tracks and tools. This can also happen if some content is missing. For example, if a segment uses a DLS collection that is not in the loader's current search directory.";
    goto label_000EA1A9;
    label_000EA139:
    cpu->eax = (uintptr_t)"Return value from IDirectMusicTrack::Play() which indicates to the segment that the track has no more data after mtEnd.";
    goto label_000EA1A9;
    label_000EA140:
    cpu->ecx = 0x8781214u;
    sub_pred[76] = cpu->eax == cpu->ecx;
    if ((cpu->eax != cpu->ecx) && ((int32_t)(cpu->eax) >= (int32_t)(cpu->ecx))) goto label_000EA17E;
    if (sub_pred[76]) goto label_000EA177;
    if ((cpu->eax -= 0x8781210u) == 0u) goto label_000EA170;
    if ((--cpu->eax) == 0u) goto label_000EA169;
    if ((--cpu->eax) == 0u) goto label_000EA162;
    if ((--cpu->eax) != 0u) goto label_000EA18F;
    cpu->eax = (uintptr_t)"Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is below 0,  so it has been bumped up one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code.";
    goto label_000EA1A9;
    label_000EA162:
    cpu->eax = (uintptr_t)"Returned from IDirectMusicPerformance::MusicToMIDI(), this indicates  that no note has been calculated because the music value has the note  at a position higher than the top note of the chord. This applies only to DMUS_PLAYMODE_NORMALCHORD play mode. This success code indicates that the caller should not do anything with the note. It is not meant to be played against this chord.";
    goto label_000EA1A9;
    label_000EA169:
    cpu->eax = (uintptr_t)"Returned from IDirectMusicGraph::StampPMsg(), this indicates that the PMsg is already stamped with the last tool in the graph. The returned PMsg's tool pointer is now NULL.";
    goto label_000EA1A9;
    label_000EA170:
    cpu->eax = (uintptr_t)"Returned string has been truncated to fit the buffer size.";
    goto label_000EA1A9;
    label_000EA177:
    cpu->eax = (uintptr_t)"Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is above 127, so it has been bumped down one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code.";
    goto label_000EA1A9;
    label_000EA17E:
    if ((cpu->eax -= 0x8781215u) == 0u) goto label_000EA1A4;
    if ((--cpu->eax) == 0u) goto label_000EA19D;
    if ((cpu->eax -= 0x1EDEBu) == 0u) goto label_000EA196;
    label_000EA18F:
    cpu->eax = (uintptr_t)"n/a";
    goto label_000EA1A9;
    label_000EA196:
    cpu->eax = (uintptr_t)"The target window or output has been occluded. The application should suspend rendering operations if possible.";
    goto label_000EA1A9;
    label_000EA19D:
    cpu->eax = (uintptr_t)"The requested operation was not performed because during CollectGarbage the loader determined that the object had been released.";
    goto label_000EA1A9;
    label_000EA1A4:
    cpu->eax = (uintptr_t)"Although the audio output from the port will be routed to the same device as the given DirectSound buffer, buffer controls such as pan and volume will not affect the output.";
    label_000EA1A9:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EA990(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x84u;
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, 0x80u);
    cpu->eax = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EA9BEu)); sfera_sub_004EDCE0(cpu, LIFT_CODE_TOKEN_VA(0x4EA9BEu));
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF7Cu) == 0u) goto label_000EA9EC;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"alloced: %s %d"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EA9E1u));
    cpu->esp += 0x14u;
    goto label_000EAA04;
    label_000EA9EC:
    lift_push32(cpu, (uintptr_t)"alloced: <Source info is corrupted>"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EA9FBu));
    cpu->esp += 0xCu;
    label_000EAA04:
    cpu->eax = (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0];
    g_sfera_critical_diagnostics_runtime.allocation_context[127] = (uint8_t)(0u);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EAA20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x94u;
    cpu->eax = g_sfera_memory_runtime.tracker_primary;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF70u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF6Cu) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF74u) = 0u;
    if (cpu->eax == 0x3B9ACA00u) goto label_000EACD8;
    (void)cpu;
    label_000EAA60:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFF6Cu);
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0xFFFFFF74u) >= (int32_t)cpu->ecx) goto label_000EACD8;
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->edx + 8u);
    cpu->ebx = cpu->eax + cpu->edx + 4u;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint8_t*)(cpu->ebp + 0xFFFFFF7Bu) = *(uint32_t*)(cpu->eax + cpu->ecx + 4u) != 0x61CCC864u;
    if (*(uint32_t*)(cpu->eax) == 0x61CCC864u) goto label_000EABA5;
    *(uint32_t*)(cpu->eax) = 0x61CCC864u;
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EAAB2:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EAAB2;
    cpu->eax -= cpu->edx;
    cpu->esi = cpu->eax + 0xFFFFFFFFu;
    if ((int32_t)cpu->esi < 0) goto label_000EAACB;
    label_000EAAC2:
    if (*(uint8_t*)(cpu->esi + cpu->edi) == 0x5Cu) goto label_000EAACB;
    if ((int32_t)(--cpu->esi) >= 0) goto label_000EAAC2;
    label_000EAACB:
    cpu->eax = *(uint16_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, 0x80u);
    cpu->edx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAAE6u)); sfera_sub_004EDCE0(cpu, LIFT_CODE_TOKEN_VA(0x4EAAE6u));
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF7Cu) == 0u) goto label_000EAB14;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"alloced: %s %d"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EAB09u));
    cpu->esp += 0x14u;
    goto label_000EAB2C;
    label_000EAB14:
    lift_push32(cpu, (uintptr_t)"alloced: <Source info is corrupted>"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EAB23u));
    cpu->esp += 0xCu;
    label_000EAB2C:
    cpu->eax = g_sfera_diagnostic_log_byte;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"test_ptr0: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = cpu->esi + cpu->edi + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". "); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]); lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    g_sfera_critical_diagnostics_runtime.allocation_context[127] = (uint8_t)(0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB6Du)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAB6Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB74u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAB74u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB7Bu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAB7Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB82u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAB82u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB89u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAB89u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB90u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAB90u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB97u)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EAB97u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAB9Eu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAB9Eu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEABA5u)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEABA5u));
    label_000EABA5:
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF7Bu) == 0u) goto label_000EACC4;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->edi;
    *(uint32_t*)(cpu->ecx + cpu->edx + 4u) = 0x61CCC864u;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EABD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EABD0;
    cpu->eax -= cpu->edx;
    cpu->esi = cpu->eax + 0xFFFFFFFFu;
    if ((int32_t)cpu->esi < 0) goto label_000EABE9;
    label_000EABE0:
    if (*(uint8_t*)(cpu->esi + cpu->edi) == 0x5Cu) goto label_000EABE9;
    if ((int32_t)(--cpu->esi) >= 0) goto label_000EABE0;
    label_000EABE9:
    cpu->ecx = *(uint16_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, 0x80u);
    cpu->eax = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAC04u)); sfera_sub_004EDCE0(cpu, LIFT_CODE_TOKEN_VA(0x4EAC04u));
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF7Cu) == 0u) goto label_000EAC32;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"alloced: %s %d"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EAC27u));
    cpu->esp += 0x14u;
    goto label_000EAC4A;
    label_000EAC32:
    lift_push32(cpu, (uintptr_t)"alloced: <Source info is corrupted>"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EAC41u));
    cpu->esp += 0xCu;
    label_000EAC4A:
    cpu->ecx = g_sfera_diagnostic_log_byte;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)"test_ptr0: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = cpu->esi + cpu->edi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". "); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]); lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    g_sfera_critical_diagnostics_runtime.allocation_context[127] = (uint8_t)(0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAC8Cu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAC8Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAC93u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAC93u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAC9Au)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAC9Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EACA1u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EACA1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EACA8u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EACA8u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EACAFu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EACAFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EACB6u)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EACB6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EACBDu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EACBDu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEACC4u)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEACC4u));
    label_000EACC4:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xCu);
    ++*(uint32_t*)(cpu->ebp + 0xFFFFFF74u);
    if (cpu->eax != 0x3B9ACA00u) goto label_000EAA60;
    label_000EACD8:
    sub_pred[1] = *(uint32_t*)(cpu->ebp + 0xFFFFFF70u) == 0u; sub_pred[3] = (int32_t)(*(uint32_t*)(cpu->ebp + 0xFFFFFF70u)) < (int32_t)(0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF74u) = 0u;
    if ((sub_pred[1]) || (sub_pred[3])) goto label_000EAED5;
    cpu->esi = g_sfera_memory_runtime.tracker_floor;
    label_000EACF5:
    if (cpu->esi == 0x3B9ACA00u) goto label_000EAD09;
    if ((int32_t)g_sfera_memory_runtime.validation_pass_count < (int32_t)0x3E8u) goto label_000EAD2B;
    label_000EAD09:
    cpu->esi = g_sfera_memory_runtime.tracker_primary;
    if (cpu->esi == 0x3B9ACA00u) goto label_000EAEDB;
    g_sfera_memory_runtime.tracker_floor = cpu->esi;
    g_sfera_memory_runtime.validation_pass_count = 0u;
    label_000EAD2B:
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1Au);
    cpu->eax = *(uint32_t*)(cpu->esi + cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->edx + 8u);
    cpu->esi = cpu->esi + cpu->edx + 4u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ecx + cpu->eax + 4u) != 0x61CCC864u);
    if (*(uint32_t*)(cpu->eax) == 0x61CCC864u) goto label_000EADFC;
    *(uint32_t*)(cpu->eax) = 0x61CCC864u;
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EAD70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EAD70;
    cpu->eax -= cpu->edx;
    if ((int32_t)(--cpu->eax) < 0) goto label_000EAD89;
    label_000EAD80:
    if (*(uint8_t*)(cpu->eax + cpu->edi) == 0x5Cu) goto label_000EAD89;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EAD80;
    label_000EAD89:
    cpu->edx = g_sfera_diagnostic_log_byte;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = cpu->eax + cpu->edi + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADAEu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EADAEu));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"test_ptr1: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADC4u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EADC4u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADCBu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EADCBu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADD2u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EADD2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADD9u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EADD9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADE0u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EADE0u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADE7u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EADE7u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADEEu)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EADEEu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EADF5u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EADF5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEADFCu)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEADFCu));
    label_000EADFC:
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000EAEAD;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = cpu->edi;
    *(uint32_t*)(cpu->ecx + cpu->edx + 4u) = 0x61CCC864u;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EAE20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EAE20;
    cpu->eax -= cpu->edx;
    if ((int32_t)(--cpu->eax) < 0) goto label_000EAE39;
    label_000EAE30:
    if (*(uint8_t*)(cpu->eax + cpu->edi) == 0x5Cu) goto label_000EAE39;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EAE30;
    label_000EAE39:
    cpu->ecx = g_sfera_diagnostic_log_byte;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = cpu->eax + cpu->edi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE5Eu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EAE5Eu));
    cpu->ecx = (uintptr_t)"test_ptr1: MEM CORRUPTED! ";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE75u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAE75u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE7Cu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAE7Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE83u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAE83u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE8Au)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAE8Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE91u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAE91u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE98u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAE98u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAE9Fu)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EAE9Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAEA6u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EAEA6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEAEADu)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEAEADu));
    label_000EAEAD:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFF74u);
    cpu->esi = *(uint32_t*)(cpu->esi + 0xCu);
    ++g_sfera_memory_runtime.validation_pass_count;
    ++cpu->eax;
    g_sfera_memory_runtime.tracker_floor = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF74u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebp + 0xFFFFFF70u)) goto label_000EACF5;
    label_000EAED5:
    cpu->esi = g_sfera_memory_runtime.tracker_primary;
    label_000EAEDB:
    if (*(uint32_t*)(cpu->ebp + 8u) != 0xFFFFFFFFu) goto label_000EAEEA;
    cpu->edx = g_sfera_memory_runtime.live_allocation_count;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->edx;
    label_000EAEEA:
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 8u) == 0u; sub_pred[2] = (int32_t)(*(uint32_t*)(cpu->ebp + 8u)) < (int32_t)(0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF74u) = 0u;
    if ((sub_pred[0]) || (sub_pred[2])) goto label_000EB1A2;
    cpu->eax = g_sfera_memory_runtime.tracker_ceiling;
    goto label_000EAF16;
    label_000EAF10:
    cpu->esi = g_sfera_memory_runtime.tracker_primary;
    label_000EAF16:
    if (cpu->eax != 0x3B9ACA00u) goto label_000EAF2C;
    if (cpu->esi == cpu->eax) goto label_000EB1A2;
    cpu->eax = cpu->esi;
    g_sfera_memory_runtime.tracker_ceiling = cpu->eax;
    label_000EAF2C:
    cpu->ecx = g_sfera_allocation_hash_runtime.records;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ecx + 8u);
    cpu->ebx = cpu->eax + cpu->ecx + 4u;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint8_t*)(cpu->ebp + 0xFFFFFF7Bu) = *(uint32_t*)(cpu->eax + cpu->edx + 4u) != 0x61CCC864u;
    if (*(uint32_t*)(cpu->eax) == 0x61CCC864u) goto label_000EB064;
    *(uint32_t*)(cpu->eax) = 0x61CCC864u;
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EAF70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EAF70;
    cpu->eax -= cpu->edx;
    cpu->esi = cpu->eax + 0xFFFFFFFFu;
    if ((int32_t)cpu->esi < 0) goto label_000EAF89;
    label_000EAF80:
    if (*(uint8_t*)(cpu->esi + cpu->edi) == 0x5Cu) goto label_000EAF89;
    if ((int32_t)(--cpu->esi) >= 0) goto label_000EAF80;
    label_000EAF89:
    cpu->ecx = *(uint16_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, 0x80u);
    cpu->eax = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EAFA4u)); sfera_sub_004EDCE0(cpu, LIFT_CODE_TOKEN_VA(0x4EAFA4u));
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF7Cu) == 0u) goto label_000EAFD2;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"alloced: %s %d"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EAFC7u));
    cpu->esp += 0x14u;
    goto label_000EAFEA;
    label_000EAFD2:
    lift_push32(cpu, (uintptr_t)"alloced: <Source info is corrupted>"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EAFE1u));
    cpu->esp += 0xCu;
    label_000EAFEA:
    cpu->ecx = g_sfera_diagnostic_log_byte;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)"test_ptr2: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = cpu->esi + cpu->edi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". "); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]); lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    g_sfera_critical_diagnostics_runtime.allocation_context[127] = (uint8_t)(0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB02Cu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB02Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB033u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB033u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB03Au)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB03Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB041u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB041u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB048u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB048u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB04Fu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB04Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB056u)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EB056u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB05Du)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB05Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEB064u)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEB064u));
    label_000EB064:
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF7Bu) == 0u) goto label_000EB184;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->edx + cpu->eax + 4u) = 0x61CCC864u;
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EB090:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EB090;
    cpu->eax -= cpu->edx;
    cpu->esi = cpu->eax + 0xFFFFFFFFu;
    if ((int32_t)cpu->esi < 0) goto label_000EB0A9;
    label_000EB0A0:
    if (*(uint8_t*)(cpu->esi + cpu->edi) == 0x5Cu) goto label_000EB0A9;
    if ((int32_t)(--cpu->esi) >= 0) goto label_000EB0A0;
    label_000EB0A9:
    cpu->edx = *(uint16_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, 0x80u);
    cpu->ecx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB0C4u)); sfera_sub_004EDCE0(cpu, LIFT_CODE_TOKEN_VA(0x4EB0C4u));
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF7Cu) == 0u) goto label_000EB0F2;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"alloced: %s %d"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EB0E7u));
    cpu->esp += 0x14u;
    goto label_000EB10A;
    label_000EB0F2:
    lift_push32(cpu, (uintptr_t)"alloced: <Source info is corrupted>"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EB101u));
    cpu->esp += 0xCu;
    label_000EB10A:
    cpu->edx = g_sfera_diagnostic_log_byte;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"test_ptr2: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" ");
    cpu->ecx = cpu->esi + cpu->edi + 1u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)". "); lift_push32(cpu, (uintptr_t)&g_sfera_critical_diagnostics_runtime.allocation_context[0]); lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    g_sfera_critical_diagnostics_runtime.allocation_context[127] = (uint8_t)(0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB14Cu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB14Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB153u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB153u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB15Au)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB15Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB161u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB161u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB168u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB168u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB16Fu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB16Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB176u)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EB176u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB17Du)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB17Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEB184u)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEB184u));
    label_000EB184:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFF74u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xCu);
    ++cpu->ecx;
    g_sfera_memory_runtime.tracker_ceiling = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF74u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebp + 8u)) goto label_000EAF10;
    label_000EB1A2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EB1C0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_memory_runtime.allocation_source_file = cpu->ecx;
    g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EB1D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x14u) == (uint8_t)(cpu->eax));
    cpu->edi = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edi;
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    if (cpu->esi == cpu->edi) goto label_000EB251;
    if (g_sfera_memory_runtime.lock_initialized != 0u) goto label_000EB22F;
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB222u));
    g_sfera_memory_runtime.lock_initialized = 1u;
    label_000EB22F:
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    if (cpu->esi != 1u) goto label_000EB248;
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB239u));
    g_sfera_memory_runtime.lock_held = 1u;
    goto label_000EB251;
    label_000EB248:
    lift_native_call(cpu, native_function_address32(&::TryEnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB248u));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    label_000EB251:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB26Bu)); sfera_sub_004EAA20(cpu, LIFT_CODE_TOKEN_VA(0x4EB26Bu));
    if (g_sfera_memory_runtime.diagnostics_dirty != 0u) goto label_000EB28C;
    if (cpu->esi == 0u) goto label_000EB2DF;
    if (cpu->esi != 1u) goto label_000EB286;
    label_000EB27D:
    g_sfera_memory_runtime.lock_held = 0u;
    goto label_000EB2D4;
    label_000EB286:
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) == 1u;
    goto label_000EB2D2;
    label_000EB28C:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    g_sfera_memory_runtime.diagnostics_dirty = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB2A0u)); sfera_sub_004EAA20(cpu, LIFT_CODE_TOKEN_VA(0x4EB2A0u));
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, (uintptr_t)"Memory corruption!");
    cpu->edi = 1u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = 0x1BDu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB2C4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB2C4u));
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000EB2DF;
    if (cpu->esi == cpu->edi) goto label_000EB27D;
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) == cpu->edi;
    label_000EB2D2:
    if (!sub_pred[0]) goto label_000EB2DF;
    label_000EB2D4:
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEB2D9u));
    label_000EB2DF:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EB300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    cpu->ebx = 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if ((uint8_t)(g_sfera_memory_runtime.lock_initialized) != 0u) goto label_000EB351;
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB345u));
    g_sfera_memory_runtime.lock_initialized = cpu->ebx & 0xFFu;
    label_000EB351:
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB356u));
    g_sfera_memory_runtime.lock_held = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->esi;
    if ((uint8_t)(g_sfera_memory_runtime.tracking_initialized) != 0u) goto label_000EB38F;
    lift_push32(cpu, 0x1388u);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB37Du)); sfera_sub_004EDD40(cpu, LIFT_CODE_TOKEN_VA(0x4EB37Du));
    lift_push32(cpu, 0x32u);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB389u)); sfera_sub_004EDA60(cpu, LIFT_CODE_TOKEN_VA(0x4EB389u));
    g_sfera_memory_runtime.tracking_initialized = cpu->ebx & 0xFFu;
    label_000EB38F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = 5u;
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB3A6u)); sfera_sub_004EB1D0(cpu, LIFT_CODE_TOKEN_VA(0x4EB3A6u));
    if ((int32_t)cpu->edi >= (int32_t)cpu->esi) goto label_000EB3D1;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"malloc2: Wrong size value. Size=%d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0x1CCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB3CEu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB3CEu));
    cpu->esp += 0xCu;
    label_000EB3D1:
    cpu->eax = cpu->edi + 8u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4EB3D5u));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    if (cpu->esi != 0u) goto label_000EB40B;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"malloc2: Not enough memory. Request size = %d"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0x1D0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB408u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB408u));
    cpu->esp += 0xCu;
    label_000EB40B:
    cpu->edx = cpu->ebp + 0xFFFFFFF0u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esi) = 0x61CCC864u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    *(uint32_t*)(cpu->esi + cpu->edi + 4u) = 0x61CCC864u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB42Fu)); sfera_sub_004EDEF0(cpu, LIFT_CODE_TOKEN_VA(0x4EB42Fu));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_000EB45B;
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"store_pointer: pointer already in hash"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0xFEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB458u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB458u));
    cpu->esp += 8u;
    label_000EB45B:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB469u)); sfera_sub_004EDC70(cpu, LIFT_CODE_TOKEN_VA(0x4EB469u));
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ecx;
    if (cpu->edx == 0x3B9ACA00u) goto label_000EB498;
    cpu->ecx = g_sfera_allocation_hash_runtime.records;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1Au);
    *(uint32_t*)(cpu->edx + cpu->ecx + 0xCu) = cpu->ebx;
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    goto label_000EB49E;
    label_000EB498:
    g_sfera_memory_runtime.tracker_auxiliary = cpu->ebx;
    label_000EB49E:
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = 0x3B9ACA00u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint16_t*)(cpu->edx + 0x14u) = cpu->eax & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax &= 0x3FFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->eax + cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_bytes)) = (uint64_t)(*(uint32_t*)(cpu->eax + cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_bytes))) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->eax += cpu->eax;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_allocations)) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_allocations))) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    g_sfera_memory_runtime.live_allocation_count = (uint64_t)(g_sfera_memory_runtime.live_allocation_count) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.tracker_primary = cpu->ebx;
    g_sfera_memory_runtime.lock_held = 0u;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB4F6u));
    cpu->eax = cpu->esi + 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

} // namespace lifted
