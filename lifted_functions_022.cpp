#include "lifted_functions.h"
#include "semantic_zlib.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004DD810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);
    if (cpu->edx == *(uint32_t*)(cpu->ebp + 0x14u)) goto label_000DD834;
    cpu->eax = 0xFFFFFFFBu;
    goto label_000DD8DC;
    label_000DD834:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    if (cpu->ecx == *(uint32_t*)(cpu->eax)) goto label_000DD856;
    cpu->eax = 0xFFFFFFFBu;
    goto label_000DD8DC;
    label_000DD856:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0u;
    lift_push32(cpu, 0x38u); lift_push32(cpu, (uintptr_t)"1.1.3");
    cpu->edx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD874u)); sfera_sub_004DDC0A(cpu, LIFT_CODE_TOKEN_VA(0x4DD874u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) == 0u) goto label_000DD885;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    goto label_000DD8DC;
    label_000DD885:
    lift_push32(cpu, 4u);
    cpu->eax = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD890u)); sfera_sub_004DDC25(cpu, LIFT_CODE_TOKEN_VA(0x4DD890u));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) == 1u) goto label_000DD8C2;
    cpu->ecx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD8A5u)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DD8A5u));
    cpu->esp += 4u;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0u) goto label_000DD8B7;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = 0xFFFFFFFBu;
    goto label_000DD8BD;
    label_000DD8B7:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->edx;
    label_000DD8BD:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    goto label_000DD8DC;
    label_000DD8C2:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD8D3u)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DD8D3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    label_000DD8DC:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DD8E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    if (cpu->eax == *(uint32_t*)(cpu->edx)) goto label_000DD914;
    cpu->eax = 0xFFFFFFFBu;
    goto label_000DD9A5;
    label_000DD914:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 0u;
    lift_push32(cpu, 0x38u); lift_push32(cpu, (uintptr_t)"1.1.3");
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD93Du)); sfera_sub_004DE540(cpu, LIFT_CODE_TOKEN_VA(0x4DD93Du));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) == 0u) goto label_000DD94E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    goto label_000DD9A5;
    label_000DD94E:
    lift_push32(cpu, 4u);
    cpu->eax = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD959u)); sfera_sub_004DEBDE(cpu, LIFT_CODE_TOKEN_VA(0x4DD959u));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) == 1u) goto label_000DD98B;
    cpu->ecx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD96Eu)); sfera_sub_004DF075(cpu, LIFT_CODE_TOKEN_VA(0x4DD96Eu));
    cpu->esp += 4u;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 0u) goto label_000DD980;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = 0xFFFFFFFBu;
    goto label_000DD986;
    label_000DD980:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->edx;
    label_000DD986:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    goto label_000DD9A5;
    label_000DD98B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD99Cu)); sfera_sub_004DF075(cpu, LIFT_CODE_TOKEN_VA(0x4DD99Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    label_000DD9A5:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DD9D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if (*(uint32_t*)(cpu->ebp + 8u) == 0u) goto label_000DD9E2;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 0x1Cu) != 0u) goto label_000DD9E9;
    label_000DD9E2:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDA39;
    label_000DD9E9:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 8u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 0x18u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 7u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    lift_push32(cpu, 0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDA34u)); sfera_sub_004E0950(cpu, LIFT_CODE_TOKEN_VA(0x4DDA34u));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_000DDA39:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DDA3B(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if (*(uint32_t*)(cpu->ebp + 8u) == 0u) goto label_000DDA56;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 0x1Cu) == 0u) goto label_000DDA56;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 0x24u) != 0u) goto label_000DDA5D;
    label_000DDA56:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDAA2;
    label_000DDA5D:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    if (*(uint32_t*)(cpu->eax + 0x14u) == 0u) goto label_000DDA7F;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDA7Cu)); sfera_sub_004E1E72(cpu, LIFT_CODE_TOKEN_VA(0x4DDA7Cu));
    cpu->esp += 8u;
    label_000DDA7F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->eax))->release(*(uint32_t*)(cpu->eax + 0x1Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = 0u;
    cpu->eax = 0u;
    label_000DDAA2:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DDAA4(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if (*(uint32_t*)(cpu->ebp + 0x10u) == 0u) goto label_000DDAC4;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int32_t)(int8_t)*(uint8_t*)((uintptr_t)"1.1.3");
    if (cpu->ecx != cpu->edx) goto label_000DDAC4;
    if (*(uint32_t*)(cpu->ebp + 0x14u) == 0x38u) goto label_000DDACE;
    label_000DDAC4:
    cpu->eax = 0xFFFFFFFAu;
    goto label_000DDC08;
    label_000DDACE:
    if (*(uint32_t*)(cpu->ebp + 8u) != 0u) goto label_000DDADE;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDC08;
    label_000DDADE:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 0x18u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 0x20u) != 0u) goto label_000DDB05;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->zalloc = &sfera_zlib_alloc_callback;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 0x28u) = 0u;
    label_000DDB05:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 0x24u) != 0u) goto label_000DDB18;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->zfree = &sfera_zlib_free_callback;
    label_000DDB18:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->allocate(1u, 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 0x1Cu) != 0u) goto label_000DDB45;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DDC08;
    label_000DDB45:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 0xCu) = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0xCu) >= (int32_t)0u) goto label_000DDB7A;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 0xCu) = 1u;
    label_000DDB7A:
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0xCu) < (int32_t)8u) goto label_000DDB86;
    if ((*(uint32_t*)(cpu->ebp + 0xCu) == 0xFu) || ((int32_t)(*(uint32_t*)(cpu->ebp + 0xCu)) < (int32_t)(0xFu))) goto label_000DDB99;
    label_000DDB86:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDB8Fu)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DDB8Fu));
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDC08;
    label_000DDB99:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = 1u << (cpu->ecx & 31u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu) == 0u ? 1u : 0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDBCFu)); sfera_sub_004E0A07(cpu, LIFT_CODE_TOKEN_VA(0x4DDBCFu));
    cpu->esp += 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    if (*(uint32_t*)(cpu->ecx + 0x14u) != 0u) goto label_000DDBFA;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDBF0u)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DDBF0u));
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DDC08;
    label_000DDBFA:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDC03u)); sfera_sub_004DD9D0(cpu, LIFT_CODE_TOKEN_VA(0x4DDC03u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    label_000DDC08:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DDC0A(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xFu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDC20u)); sfera_sub_004DDAA4(cpu, LIFT_CODE_TOKEN_VA(0x4DDC20u));
    cpu->esp += 0x10u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DDC25(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    if (*(uint32_t*)(cpu->ebp + 8u) == 0u) goto label_000DDC42;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 0x1Cu) == 0u) goto label_000DDC42;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx) != 0u) goto label_000DDC4C;
    label_000DDC42:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DDC4C:
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ebp + 0xCu) != 4u);
    --cpu->edx;
    cpu->edx &= 0xFFFFFFFBu;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0xFFFFFFFBu;
    label_000DDC63:
    cpu->eax = 1u;
    if (cpu->eax == 0u) goto label_000DE2BA;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) > 0xDu) goto label_000DE2AE;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    switch (cpu->ecx) {
        case 0u: goto label_000DDC8F;
        case 1u: goto label_000DDD6A;
        case 2u: goto label_000DDE23;
        case 3u: goto label_000DDE86;
        case 4u: goto label_000DDEF4;
        case 5u: goto label_000DDF62;
        case 6u: goto label_000DDFE6;
        case 7u: goto label_000DE013;
        case 8u: goto label_000DE0BD;
        case 9u: goto label_000DE120;
        case 10u: goto label_000DE18E;
        case 11u: goto label_000DE1FC;
        case 12u: goto label_000DE2A0;
        case 13u: goto label_000DE2A7;
        default: cpu->eip = 0x4DDC88u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }
label_000DDC8F: ;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 4u) != 0u) goto label_000DDCA0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDCA0:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax &= 0xFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edx += 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    if (cpu->eax == 8u) goto label_000DDD1C;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 0xDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"unknown compression method";
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = 5u;
    goto label_000DE2B5;
    label_000DDD1C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax >>= 4u;
    cpu->eax += 8u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    if (cpu->eax <= *(uint32_t*)(cpu->edx + 0x10u)) goto label_000DDD5E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx) = 0xDu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 0x18u) = (uintptr_t)"invalid window size";
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 4u) = 5u;
    goto label_000DE2B5;
    label_000DDD5E:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 1u;
    label_000DDD6A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 4u) != 0u) goto label_000DDD7B;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDD7B:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx -= 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    ++cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax <<= 8u;
    cpu->eax += *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx = 0x1Fu;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ecx); cpu->eax = n / d; cpu->edx = n % d; }
    if (cpu->edx == 0u) goto label_000DDDFC;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 0xDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"incorrect header check";
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = 5u;
    goto label_000DE2B5;
    label_000DDDFC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx &= 0x20u;
    if (cpu->ecx != 0u) goto label_000DDE17;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 7u;
    goto label_000DE2B5;
    label_000DDE17:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx) = 2u;
    label_000DDE23:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 4u) != 0u) goto label_000DDE34;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDE34:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax -= 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->ecx <<= 24u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx) = 3u;
    label_000DDE86:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 4u) != 0u) goto label_000DDE97;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDE97:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax -= 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->ecx <<= 16u;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx += cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax += 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 4u;
    label_000DDEF4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 4u) != 0u) goto label_000DDF05;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDF05:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx -= 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx=0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx <<= 8u;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax += cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx) = 5u;
    label_000DDF62:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 4u) != 0u) goto label_000DDF73;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDF73:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->ecx += cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 6u;
    cpu->eax = 2u;
    goto label_000DE2BA;
    label_000DDFE6:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx) = 0xDu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 0x18u) = (uintptr_t)"need dictionary";
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx + 4u) = 0u;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DE013:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE02Au)); sfera_sub_004E0AFF(cpu, LIFT_CODE_TOKEN_VA(0x4DE02Au));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) != 0xFFFFFFFDu) goto label_000DE054;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 0xDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx + 4u) = 0u;
    goto label_000DE2B5;
    label_000DE054:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) != 0u) goto label_000DE060;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    label_000DE060:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) == 1u) goto label_000DE06E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE06E:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE091u)); sfera_sub_004E0950(cpu, LIFT_CODE_TOKEN_VA(0x4DE091u));
    cpu->esp += 0xCu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    if (*(uint32_t*)(cpu->eax + 0xCu) == 0u) goto label_000DE0B1;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx) = 0xCu;
    goto label_000DE2B5;
    label_000DE0B1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx) = 8u;
    label_000DE0BD:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 4u) != 0u) goto label_000DE0CE;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE0CE:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->eax <<= 24u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx) = 9u;
    label_000DE120:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 4u) != 0u) goto label_000DE131;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE131:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax=0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    cpu->eax <<= 16u;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->ecx += cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edx += 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx) = 0xAu;
    label_000DE18E:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->eax + 4u) != 0u) goto label_000DE19F;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE19F:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax -= 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx=0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->ecx <<= 8u;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx += cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax += 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 0xBu;
    label_000DE1FC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->ecx + 4u) != 0u) goto label_000DE20D;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE20D:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx -= 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax += cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += 1u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->ecx == *(uint32_t*)(cpu->eax + 8u)) goto label_000DE294;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 0xDu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x18u) = (uintptr_t)"incorrect data check";
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = 5u;
    goto label_000DE2B5;
    label_000DE294:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->edx) = 0xCu;
    label_000DE2A0:
    cpu->eax = 1u;
    goto label_000DE2BA;
    label_000DE2A7:
    cpu->eax = 0xFFFFFFFDu;
    goto label_000DE2BA;
    label_000DE2AE:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DE2B5:
    goto label_000DDC63;
    label_000DE2BA:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DE540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 8u); lift_push32(cpu, 0xFu); lift_push32(cpu, 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE560u)); sfera_sub_004DE565(cpu, LIFT_CODE_TOKEN_VA(0x4DE560u));
    cpu->esp += 0x20u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DE565(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = 0u;
    if (*(uint32_t*)(cpu->ebp + 0x20u) == 0u) goto label_000DE591;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (uintptr_t)"1.1.3";
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx));
    if (cpu->ecx != cpu->eax) goto label_000DE591;
    if (*(uint32_t*)(cpu->ebp + 0x24u) == 0x38u) goto label_000DE59B;
    label_000DE591:
    cpu->eax = 0xFFFFFFFAu;
    goto label_000DE84D;
    label_000DE59B:
    if (*(uint32_t*)(cpu->ebp + 8u) != 0u) goto label_000DE5AB;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE84D;
    label_000DE5AB:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x18u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 0x20u) != 0u) goto label_000DE5D2;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->eax))->zalloc = &sfera_zlib_alloc_callback;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x28u) = 0u;
    label_000DE5D2:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint32_t*)(cpu->edx + 0x24u) != 0u) goto label_000DE5E5;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->eax))->zfree = &sfera_zlib_free_callback;
    label_000DE5E5:
    if (*(uint32_t*)(cpu->ebp + 0xCu) != 0xFFFFFFFFu) goto label_000DE5F2;
    *(uint32_t*)(cpu->ebp + 0xCu) = 6u;
    label_000DE5F2:
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x14u) >= (int32_t)0u) goto label_000DE607;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0x14u) = cpu->ecx;
    label_000DE607:
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x18u) < (int32_t)1u) goto label_000DE63D;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x18u) > (int32_t)9u) goto label_000DE63D;
    if (*(uint32_t*)(cpu->ebp + 0x10u) != 8u) goto label_000DE63D;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x14u) < (int32_t)8u) goto label_000DE63D;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x14u) > (int32_t)0xFu) goto label_000DE63D;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0xCu) < (int32_t)0u) goto label_000DE63D;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0xCu) > (int32_t)9u) goto label_000DE63D;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x1Cu) < (int32_t)0u) goto label_000DE63D;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x1Cu) <= (int32_t)2u) goto label_000DE647;
    label_000DE63D:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE84D;
    label_000DE647:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->ecx))->allocate(1u, 0x16B8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) != 0u) goto label_000DE671;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DE84D;
    label_000DE671:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    *(uint32_t*)(cpu->edx + 0x28u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = 1u;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->edx -= 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx += 7u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x48u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = 1u;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x48u);
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x44u);
    cpu->edx -= 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->eax + 0x4Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x48u);
    cpu->eax += 2u;
    cpu->ecx = 3u;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ecx); cpu->eax = n / d; cpu->edx = n % d; }
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x50u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->allocate(cpu->ecx, 2u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x30u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->allocate(cpu->ecx, 2u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x38u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x44u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->edx))->allocate(cpu->ecx, 2u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x3Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->ecx += 6u;
    cpu->eax = 1u;
    cpu->eax <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x1694u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1694u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(cpu->ecx))->allocate(cpu->eax, 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1694u);
    cpu->ecx <<= 2u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (*(uint32_t*)(cpu->eax + 0x30u) == 0u) goto label_000DE7CD;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (*(uint32_t*)(cpu->ecx + 0x38u) == 0u) goto label_000DE7CD;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (*(uint32_t*)(cpu->edx + 0x3Cu) == 0u) goto label_000DE7CD;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (*(uint32_t*)(cpu->eax + 8u) != 0u) goto label_000DE7EC;
    label_000DE7CD:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = (uintptr_t)"insufficient memory";
    *(uint32_t*)(cpu->ecx + 0x18u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE7E2u)); sfera_sub_004DF075(cpu, LIFT_CODE_TOKEN_VA(0x4DE7E2u));
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DE84D;
    label_000DE7EC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1694u);
    cpu->edx >>= 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx = cpu->eax + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->edx + 0x169Cu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1694u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(3u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->ecx + 0x1690u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->edx + 0x7Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 0x80u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x10u));
    *(uint8_t*)(cpu->eax + 0x1Du) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE84Au)); sfera_sub_004DE9F1(cpu, LIFT_CODE_TOKEN_VA(0x4DE84Au));
    cpu->esp += 4u;
    label_000DE84D:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DE9F1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate_reset(*(uint32_t*)(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DEBDE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate(*(uint32_t*)(cpu->esp + 4u), (int32_t)*(uint32_t*)(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004DF075(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream_address = *(uint32_t*)(cpu->esp + 4u);
    auto* stream = reinterpret_cast<SferaZStream32*>(static_cast<uintptr_t>(stream_address));
    if (!stream || stream->state == 0u) cpu->eax = 0xFFFFFFFEu;
    else {
        const uint32_t state_address = stream->state;
        const uint32_t status = *(uint32_t*)(state_address + 4u);
        if (status != 0x2Au && status != 0x71u && status != 0x29Au) cpu->eax = 0xFFFFFFFEu;
        else { stream->release(*(uint32_t*)(state_address + 8u)); stream->release(*(uint32_t*)(state_address + 0x3Cu)); stream->release(*(uint32_t*)(state_address + 0x38u)); stream->release(*(uint32_t*)(state_address + 0x30u)); stream->release(state_address); stream->state = 0u; cpu->eax = status == 0x71u ? 0xFFFFFFFDu : 0u; }
    }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
} // namespace lifted
