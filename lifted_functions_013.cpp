#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint8_t sfera_buffer_cipher_key(uint32_t index) {
    switch (index % 9u) {
        case 0u: return UINT8_C(0x4B);
        case 1u: return UINT8_C(0x0D);
        case 2u: return UINT8_C(0xEF);
        case 3u: return UINT8_C(0x60);
        case 4u: return UINT8_C(0xC9);
        case 5u: return UINT8_C(0x9A);
        case 6u: return UINT8_C(0x70);
        case 7u: return UINT8_C(0x0E);
        default: return UINT8_C(0x03);
    }
}
static uint32_t sfera_clip_plane_order(uint32_t index) {
    switch (index) {
        case 0u: return 0u;
        case 1u: return 1u;
        case 2u: return 3u;
        case 3u: return 5u;
        case 4u: return 4u;
        default: return 2u;
    }
}
__declspec(noinline) void sfera_sub_00482170(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48217Bu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x48217Bu));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482182u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x482182u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482189u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x482189u));
    if (cpu->edi != 0xFFFFFFFFu) goto label_0008219C;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"openCfg: file %s is not found");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482199u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x482199u));
    cpu->esp += 8u;
    label_0008219C:
    lift_push32(cpu, 0x469u);
    cpu->ecx = cpu->edi + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4821AEu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4821AEu));
    cpu->esi = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi + cpu->edi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4821BDu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x4821BDu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4821C9u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4821C9u));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4821D0u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x4821D0u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == 0xDu) goto label_0008224F;
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_0008224F;
    if ((cpu->eax & 0xFFu) == 0x2Fu) goto label_0008224F;
    if ((cpu->eax & 0xFFu) == 0xC6u) goto label_0008221B;
    if ((cpu->eax & 0xFFu) == 0xEBu) goto label_0008221B;
    if ((cpu->eax & 0xFFu) == 0xE4u) goto label_0008221B;
    lift_push32(cpu, 0x48Bu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4821FBu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4821FBu));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"openCfg: wrong fromat of Cfg %s"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x482206u));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_config_parser_runtime.token[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482219u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x482219u));
    goto label_00082299;
    label_0008221B:
    cpu->eax = 0u;
    if ((int32_t)cpu->edi <= 0) goto label_0008222A;
    label_00082221:
    *(uint8_t*)(cpu->eax + cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->eax + cpu->esi)) ^ (uint64_t)(0xCBu);
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00082221;
    label_0008222A:
    if (g_sfera_config_parser_runtime.open_mode != 0u) goto label_00082299;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48223Au)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x48223Au));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482246u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x482246u));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48224Du)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x48224Du));
    goto label_00082299;
    label_0008224F:
    if (g_sfera_config_parser_runtime.open_mode != 1u) goto label_00082299;
    cpu->eax = 0u;
    if ((int32_t)cpu->edi <= 0) goto label_00082269;
    label_00082260:
    *(uint8_t*)(cpu->eax + cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->eax + cpu->esi)) ^ (uint64_t)(0xCBu);
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00082260;
    label_00082269:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482270u)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x482270u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48227Cu)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x48227Cu));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482283u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x482283u));
    cpu->eax = 0u;
    if ((int32_t)cpu->edi <= 0) goto label_00082299;
    label_00082290:
    *(uint8_t*)(cpu->eax + cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->eax + cpu->esi)) ^ (uint64_t)(0xCBu);
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00082290;
    label_00082299:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4822A0u)); sfera_sub_00480660(cpu, LIFT_CODE_TOKEN_VA(0x4822A0u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, 0x491u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4822B3u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4822B3u));
    cpu->edi = cpu->eax;
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4822BEu)); sfera_sub_004815E0(cpu, LIFT_CODE_TOKEN_VA(0x4822BEu));
    if (cpu->ebx == cpu->eax) goto label_000822CC;
    cpu->ecx = (uintptr_t)"openCfg: internal error";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x822CCu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x822CCu));
    label_000822CC:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4822D3u)); sfera_sub_004813D0(cpu, LIFT_CODE_TOKEN_VA(0x4822D3u));
    lift_push32(cpu, 0x497u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4822E4u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4822E4u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004822F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->edx + 4u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 8u);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->edx + 0xCu);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax);
    x87_v3 = (double)*(float*)(cpu->esp + 4u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v2 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x20u);
    x87_v4 = (double)*(float*)(cpu->esp + 8u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x30u);
    x87_v5 = (double)*(float*)(cpu->esp + 0xCu); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x14u);
    x87_v4 = (x87_v4) * (x87_v1);
    x87_v5 = x87_v0;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 4u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x24u);
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x34u)));
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 4u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 8u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v5 = (double)*(float*)(cpu->eax + 0x18u);
    x87_v5 = (x87_v5) * (x87_v1);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v2;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x28u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x38u);
    x87_v5 = (x87_v5) * (x87_v3);
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 8u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x1Cu);
    x87_v1 = x87_v1 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v0 = x87_v0 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->eax + 0x2Cu)));
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->eax + 0x3Cu)));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->ecx + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx + 0x10u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->edx + 0x14u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 0x18u);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->edx + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax);
    x87_v3 = (double)*(float*)(cpu->esp + 4u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v2 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x20u);
    x87_v4 = (double)*(float*)(cpu->esp + 8u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x30u);
    x87_v5 = (double)*(float*)(cpu->esp + 0xCu); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x10u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x14u);
    x87_v4 = (x87_v4) * (x87_v1);
    x87_v5 = x87_v0;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 4u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x24u);
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x34u)));
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x14u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 8u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v5 = (double)*(float*)(cpu->eax + 0x18u);
    x87_v5 = (x87_v5) * (x87_v1);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v2;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x28u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x38u);
    x87_v5 = (x87_v5) * (x87_v3);
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x18u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x1Cu);
    x87_v1 = x87_v1 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v0 = x87_v0 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->eax + 0x2Cu)));
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->eax + 0x3Cu)));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->ecx + 0x1Cu) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx + 0x20u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->edx + 0x24u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 0x28u);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->edx + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax);
    x87_v3 = (double)*(float*)(cpu->esp + 4u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v2 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x20u);
    x87_v4 = (double)*(float*)(cpu->esp + 8u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x30u);
    x87_v5 = (double)*(float*)(cpu->esp + 0xCu); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x20u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x14u);
    x87_v4 = (x87_v4) * (x87_v1);
    x87_v5 = x87_v0;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 4u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x24u);
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x34u)));
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x24u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 8u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v5 = (double)*(float*)(cpu->eax + 0x18u);
    x87_v5 = (x87_v5) * (x87_v1);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v2;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x28u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x38u);
    x87_v5 = (x87_v5) * (x87_v3);
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x28u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x1Cu);
    x87_v1 = x87_v1 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v0 = x87_v0 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->eax + 0x2Cu)));
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->eax + 0x2Cu)));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->ecx + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx + 0x30u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->edx + 0x34u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 0x38u);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->edx + 0x3Cu);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax);
    x87_v3 = (double)*(float*)(cpu->esp + 4u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v2 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x20u);
    x87_v4 = (double)*(float*)(cpu->esp + 8u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x30u);
    x87_v5 = (double)*(float*)(cpu->esp + 0xCu); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x30u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x14u);
    x87_v4 = (x87_v4) * (x87_v1);
    x87_v5 = x87_v0;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 4u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x24u);
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x34u)));
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x34u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 8u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v5 = (double)*(float*)(cpu->eax + 0x18u);
    x87_v5 = (x87_v5) * (x87_v1);
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = x87_v2;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->eax + 0x28u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->eax + 0x38u);
    x87_v5 = (x87_v5) * (x87_v3);
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->ecx + 0x38u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x1Cu);
    x87_v1 = x87_v1 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v0 = x87_v0 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->eax + 0x2Cu)));
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->eax + 0x2Cu)));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->ecx + 0x3Cu) = x87_v0; 
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004825A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0x20u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi);
    *(double*)(cpu->esp + 0x14u) = x87_v0;
    cpu->esi = cpu->ecx;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0x14u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    *(double*)(cpu->esp + 0xCu) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0xCu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x30u);
    *(double*)(cpu->esp + 0x1Cu) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0x1Cu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 4u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v4 = (double)*(float*)(cpu->esp + 8u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0xCu); x87_v5 = x87_v4;
    x87_v5 = (x87_v5) * (x87_v3);
    *(float*)(cpu->esp + 0x30u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x18u); x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (x87_v2);
    *(float*)(cpu->esi) = x87_v6; 
    x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (x87_v4);
    *(float*)(cpu->esi + 0x10u) = x87_v6; 
    x87_v6 = x87_v0;
    x87_v6 = -x87_v6;
    *(float*)(cpu->esi + 0x20u) = x87_v6; 
    x87_v6 = x87_v2;
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x28u)));
    x87_v6 = (x87_v6) - (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esi + 4u) = x87_v6; 
    x87_v6 = x87_v4;
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x28u)));
    x87_v6 = (x87_v6) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esi + 0x14u) = x87_v6; 
    x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (x87_v1);
    *(float*)(cpu->esi + 0x24u) = x87_v6; 
    x87_v6 = x87_v1;
    x87_v4 = x87_v4 * x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v6 = (x87_v6) * (x87_v0);
    x87_v4 = x87_v4 + x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esi + 8u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v0 = x87_v0 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v1 = x87_v1 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v3 - x87_v1; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esi + 0x18u) = x87_v2; 
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    x87_v0 = 0.0;
    *(float*)(cpu->esi + 0x38u) = x87_v0;
    *(float*)(cpu->esi + 0x34u) = x87_v0;
    *(float*)(cpu->esi + 0x30u) = x87_v0;
    *(float*)(cpu->esi + 0x2Cu) = x87_v0;
    *(float*)(cpu->esi + 0x1Cu) = x87_v0;
    *(float*)(cpu->esi + 0xCu) = x87_v0; 
    *(float*)(cpu->esi + 0x3Cu) = (double)(1.0);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004826C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4826CBu));
    x87_v0 = 1.0;
    *(float*)(cpu->esi + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(double*)(cpu->esp + 0xCu) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0xCu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esi) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esp + 4u); x87_v2 = x87_v1;
    x87_v2 = -x87_v2;
    *(float*)(cpu->esi + 4u) = x87_v2; 
    *(float*)(cpu->esi + 0x10u) = x87_v1; 
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00482720(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48272Bu));
    x87_v0 = 1.0;
    *(float*)(cpu->esi + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(double*)(cpu->esp + 0xCu) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0xCu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esi) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esp + 4u);
    *(float*)(cpu->esi + 8u) = x87_v1;
    x87_v1 = -x87_v1;
    *(float*)(cpu->esi + 0x20u) = x87_v1; 
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00482780(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48278Bu));
    x87_v0 = 1.0;
    *(float*)(cpu->esi + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esi) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(double*)(cpu->esp + 0xCu) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0xCu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esi + 0x14u) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esp + 4u); x87_v2 = x87_v1;
    x87_v2 = -x87_v2;
    *(float*)(cpu->esi + 0x18u) = x87_v2; 
    *(float*)(cpu->esi + 0x24u) = x87_v1; 
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00484A80(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26, value_27, value_28, value_29, value_30, value_31, value_32, value_33, value_34, value_35, value_36, value_37, value_38, value_39, value_40, value_41, value_42, value_43, value_44, value_45, value_46, value_47, value_48, value_49, value_50, value_51, value_52;
 bool sub_pred[2]; double x87_v0; double x87_p0, x87_p1, x87_p2, x87_p3;
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi = cpu->edi + (cpu->edi * 4u);
    cpu->esi = cpu->ecx;
    cpu->edi <<= 4u;
    cpu->edi += *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esi + 0x64u) == 0u) goto label_00084AA7;
    x87_v0 = (double)*(float*)(cpu->esi + 0x6Cu);
    goto label_00084AC5;
label_00084AA7:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) * (3.0518509447574615e-05));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 0x68u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x6Cu)));
label_00084AC5:
    *(float*)(cpu->edi + 0x2Cu) = x87_v0; 
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->ecx = 0xFEu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->edi + 0x34u) = cpu->edx;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint16_t*)(cpu->edi + 0x38u) = cpu->eax & 0xFFFFu;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint16_t*)(cpu->edi + 0x3Au) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x48u);
    if (cpu->eax==0u) goto label_00084B12;
    if ((*(uint32_t*)(cpu->eax + 0x4Cu)&0x1000000u)==0u) goto label_00084B12;
    cpu->ecx = 0u;
    sub_pred[0] = (int32_t)(*(uint32_t*)(cpu->eax + 0x5Cu) - cpu->ecx) < 0;
    if (*(uint32_t*)(cpu->eax + 0x5Cu) <= cpu->ecx) goto label_00084B12;
    x87_p0 = (double)-1.0f;
    cpu->edx = 0u;
     value_46 = x87_p0; 
label_00084B00:
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    *(float*)(cpu->edx + cpu->ebx + 0x28u) = value_46;
    ++cpu->ecx;
    cpu->edx += 0x50u;
    sub_pred[0] = (int32_t)(cpu->ecx - *(uint32_t*)(cpu->eax + 0x5Cu)) < 0;
    if (cpu->ecx < *(uint32_t*)(cpu->eax + 0x5Cu)) goto label_00084B00;
label_00084B12:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x34u);
    x87_p0 = 0.0;
    cpu->eax = *(uint16_t*)(cpu->edi + 0x3Cu);
    cpu->ebx <<= 9u;
    cpu->ebx += g_sfera_effect_manager.particle_random_table;
    cpu->edx = 0xFFFFu;
     value_49 = x87_p0; if ((cpu->eax & 0xFFFFu) == (cpu->edx & 0xFFFFu)) { value_7 = value_49; goto label_00084B53; }
    cpu->ecx = *(uint16_t*)(cpu->edi + 0x3Au);
    cpu->edx = *(uint16_t*)(cpu->edi + 0x38u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x16Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    *(float*)(cpu->esp) = value_49; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484B51u)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_VA(0x484B51u));
    value_50 = 0.0; value_7 = value_50;
label_00084B53:
    cpu->eax = *(uint16_t*)(cpu->edi + 0x3Eu);
    cpu->ecx = 0xFFFFu;
    if ((cpu->eax & 0xFFFFu) == (cpu->ecx & 0xFFFFu)) { value_8 = value_7; goto label_00084B84; }
    cpu->edx = *(uint16_t*)(cpu->edi + 0x3Au);
    cpu->ecx = *(uint16_t*)(cpu->edi + 0x38u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x170u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    *(float*)(cpu->esp) = value_7; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484B82u)); sfera_sub_0042D430(cpu, LIFT_CODE_TOKEN_VA(0x484B82u));
    value_51 = 0.0; value_8 = value_51;
label_00084B84:
    *(float*)(cpu->edi + 0x28u) = (double)*(float*)(cpu->edi + 0x2Cu);
    *(float*)(cpu->esp + 0x18u) = value_8;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x1Cu) = value_8;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = value_8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->ecx;
    if (((*(uint32_t*)(cpu->esi + 0x4Cu)) & (0x80000u)) == 0u) { value_0 = value_8; goto label_00084BD2; }
     cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->esi + 0x180u)); cpu->eax = n / d; cpu->edx = n % d; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
     value_9 = x87_p0; if ((int32_t)cpu->edx >= 0) { value_0 = value_9; goto label_00084BD2; }
    value_10 = (value_9) + (((double)4294967296.0f)); value_0 = value_10;
label_00084BD2:
    *(float*)(cpu->edi + 0x44u) = value_0; 
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
     if ((int32_t)cpu->eax <= 0) goto label_00084BF0;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x28u));
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x484BE7u));
    cpu->esp += 4u;
label_00084BF0:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax > 7u) goto label_0008519E;
    switch (cpu->eax) {
        case 0u: goto label_00084C03;
        case 1u: goto label_00084C50;
        case 2u: goto label_00084D46;
        case 3u: goto label_000850F2;
        case 4u: goto label_00084FAB;
        case 5u: goto label_00085031;
        case 6u: goto label_00084EA8;
        case 7u: goto label_00084DE2;
        default: cpu->eip = 0x484BFCu; throw std::out_of_range("resolved jump-table index out of range"); return;
    }
label_00084C03:
 ;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->edx == 0u) goto label_0008519E;
    if (*(uint32_t*)(cpu->esi + 0x18u) != 0u) goto label_00084C2A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->eax < cpu->ecx) goto label_00084C22;
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
label_00084C22:
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    goto label_00084C3A;
label_00084C2A:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->esi + 0x30u)); cpu->eax = n / d; cpu->edx = n % d; }
    cpu->ecx = cpu->edx + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
label_00084C3A:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->eax;
    goto label_0008519E;
label_00084C50:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x18u) == 0u;
    x87_p0 = (double)*(float*)(cpu->esi + 0x24u);
    x87_p1 = (double)*(float*)(cpu->esi + 0x20u);
    x87_p2 = (double)*(float*)(cpu->esi + 0x28u);
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
     value_11 = x87_p0; if (!sub_pred[1]) goto label_00084CC8;
    *(float*)(cpu->esp + 0x14u) = value_11; 
    value_12 = (double)*(float*)(cpu->esp + 0x14u);
    value_13 = std::sqrt(value_12);
    *(float*)(cpu->esp + 0x14u) = value_13; 
    value_14 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x5Cu);
    *(float*)(cpu->esp + 0x14u) = value_14; 
    value_15 = (double)*(float*)(cpu->esp + 0x14u); x87_p0 = value_15;
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x5Cu))));
     value_16 = x87_p1; value_17 = x87_p0; if ((int32_t)cpu->ecx >= 0) { value_1 = value_16; goto label_00084C9E; }
    value_18 = (value_16) + (((double)4294967296.0f)); value_1 = value_18;
label_00084C9E:
    value_19 = value_17 / value_1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x14u) = value_19; 
    value_20 = (double)*(float*)(cpu->esp + 0x14u);
    value_21 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    if ((int32_t)cpu->edx >= 0) { value_2 = value_21; goto label_00084CBA; }
    value_22 = (value_21) + (((double)4294967296.0f)); value_2 = value_22;
label_00084CBA:
    value_23 = value_20 * value_2; 
    value_24 = (value_15) * (0.5);
    value_25 = value_23 - value_24; 
     value_3 = value_25; goto label_00084D07;
label_00084CC8:
    *(float*)(cpu->esp + 0x14u) = value_11; 
     lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84CCCu));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84CD2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    x87_p0 = (x87_p0) * (3.0518509447574615e-05);
    *(double*)(cpu->esp + 0x18u) = x87_p0;
     x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (0.5);
    x87_p0 = (x87_p0) * (*(double*)(cpu->esp + 0x18u));
     value_26 = x87_p0;  value_3 = value_26;
label_00084D07:
    *(float*)(cpu->esp + 0x28u) = value_3; 
    value_27 = (double)*(float*)(cpu->esi + 0x20u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u); x87_p1 = x87_p0;
    value_28 = value_27 * x87_p1; 
    value_52 = x87_p0; x87_p0 = value_28;
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x24u);
    x87_p0 = (x87_p0) * (value_52);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    value_29 = (value_52) * (((double)*(float*)(cpu->esi + 0x28u)));
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ecx;
    *(float*)(cpu->esp + 0x20u) = value_29; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->edx;
     goto label_0008519E;
label_00084D46:
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84D46u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84D68u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x14u) = (((((((double)*(float*)(cpu->esp + 0x14u))) - (0.5)))) * (3.1415929794311523));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    *(float*)(cpu->edi + 0xCu) = (((((((double)*(float*)(cpu->esp + 0x14u))) * (((double)*(float*)(cpu->esi + 0xCu)))))) * (((double)*(float*)(cpu->esp + 0x10u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->edi + 0x14u) = (((((((double)*(float*)(cpu->esp + 0x28u))) * (((double)*(float*)(cpu->esi + 0xCu)))))) * (((double)*(float*)(cpu->esp + 0x10u))));
    x87_p0 = 0.0;
     value_30 = x87_p0; value_6 = value_30; goto label_0008519B;
label_00084DE2:
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84DE2u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84E04u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x14u) = (((((((double)*(float*)(cpu->esp + 0x14u))) - (0.5)))) * (3.1415929794311523));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (double)*(float*)(cpu->esi + 0xCu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x10u); x87_p3 = x87_p2;
    x87_p0 = x87_p0 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esi + 0x14u);
    x87_p1 = x87_p1 * x87_p3; 
    std::swap(x87_p2, x87_p0);
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->edi + 0xCu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esi + 0xCu);
    x87_p2 = (double)*(float*)(cpu->esp + 0x28u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 * x87_p2; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi + 0x14u)));
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->edi + 0x14u) = x87_p0; 
    x87_p0 = 0.0;
     value_31 = x87_p0; value_6 = value_31; goto label_0008519B;
label_00084EA8:
    if (*(uint32_t*)(cpu->esi + 0x18u) != 0u) goto label_00084F3B;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x5Cu);
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x5Cu))));
     value_32 = x87_p0; if ((int32_t)cpu->eax >= 0) { value_4 = value_32; goto label_00084EC2; }
    value_33 = (value_32) + (((double)4294967296.0f)); value_4 = value_33;
label_00084EC2:
    value_34 = (6.283185958862305) / (value_4);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(float*)(cpu->esp + 0x14u) = value_34; 
    value_35 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
     value_36 = x87_p0; if (!sub_pred[0]) { value_5 = value_36; goto label_00084EE7; }
    value_37 = (value_36) + (((double)4294967296.0f)); value_5 = value_37;
label_00084EE7:
    value_38 = value_35 * value_5; 
    *(float*)(cpu->esp + 0x28u) = value_38; 
    value_39 = (double)*(float*)(cpu->esp + 0x28u);
    value_40 = std::sin(value_39);
    *(float*)(cpu->esp + 0x14u) = value_40; 
    *(float*)(cpu->edi + 0xCu) = ((((double)*(float*)(cpu->esp + 0x14u))) * (((double)*(float*)(cpu->esi + 0xCu))));
    value_41 = (double)*(float*)(cpu->esp + 0x28u);
    value_42 = std::cos(value_41);
    *(float*)(cpu->esp + 0x28u) = value_42; 
    *(float*)(cpu->edi + 0x14u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (((double)*(float*)(cpu->esi + 0xCu))));
     lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84F1Bu));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x10u)));
     value_43 = x87_p0; value_6 = value_43; goto label_0008519B;
label_00084F3B:
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84F3Bu));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    *(float*)(cpu->edi + 0xCu) = ((((double)*(float*)(cpu->esp + 0x14u))) * (((double)*(float*)(cpu->esi + 0xCu))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->edi + 0x14u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (((double)*(float*)(cpu->esi + 0xCu))));
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84F8Bu));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x10u)));
     value_44 = x87_p0; value_6 = value_44; goto label_0008519B;
label_00084FAB:
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FABu));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FB1u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = native_function_address32(&::rand);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    x87_p0 = (x87_p0) * (3.0518509447574615e-05);
    x87_p1 = (double)*(float*)(cpu->esi + 0x14u);
    x87_p1 = (x87_p1) * (0.5);
    x87_p0 = x87_p0 * x87_p1; 
    *(float*)(cpu->edi + 0xCu) = x87_p0; 
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FDBu));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FE1u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    x87_p0 = (x87_p0) * (3.0518509447574615e-05);
    x87_p1 = (double)*(float*)(cpu->esi + 0x10u);
    x87_p1 = (x87_p1) * (0.5);
    x87_p0 = x87_p0 * x87_p1; 
    *(float*)(cpu->edi + 0x14u) = x87_p0; 
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85005u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x8500Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    x87_p0 = (x87_p0) * (3.0518509447574615e-05);
    x87_p1 = (double)*(float*)(cpu->esi + 0xCu);
    x87_p1 = (x87_p1) * (0.5);
    x87_p0 = x87_p0 * x87_p1; 
     value_45 = x87_p0; value_6 = value_45; goto label_0008519B;
label_00085031:
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85031u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85053u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x14u) = (((((((double)*(float*)(cpu->esp + 0x14u))) - (0.5)))) * (3.1415929794311523));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    *(float*)(cpu->edi + 0xCu) = (((((((double)*(float*)(cpu->esp + 0x14u))) * (((double)*(float*)(cpu->esi + 0xCu)))))) * (((double)*(float*)(cpu->esp + 0x10u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->edi + 0x14u) = (((((((double)*(float*)(cpu->esp + 0x28u))) * (((double)*(float*)(cpu->esi + 0xCu)))))) * (((double)*(float*)(cpu->esp + 0x10u))));
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x850C6u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x850CCu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    x87_p0 = (x87_p0) * (3.0518509447574615e-05);
    x87_p1 = (double)*(float*)(cpu->esi + 0x10u);
    x87_p1 = (x87_p1) * (0.5);
    x87_p0 = x87_p0 * x87_p1; 
     value_47 = x87_p0; value_6 = value_47; goto label_0008519B;
label_000850F2:
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x850F2u));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85114u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x14u) = (((((((double)*(float*)(cpu->esp + 0x14u))) - (0.5)))) * (3.1415929794311523));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    *(float*)(cpu->edi + 0xCu) = (((((((double)*(float*)(cpu->esp + 0x18u))) * (((double)*(float*)(cpu->esi + 0xCu)))))) * (((double)*(float*)(cpu->esp + 0x10u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->edi + 0x14u) = (((((((double)*(float*)(cpu->esp + 0x28u))) * (((double)*(float*)(cpu->esi + 0xCu)))))) * (((double)*(float*)(cpu->esp + 0x10u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0xCu)));
     value_48 = x87_p0;  value_6 = value_48;
label_0008519B:
    *(float*)(cpu->edi + 0x10u) = value_6; 
label_0008519E:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x18u) <= (int32_t)0u) goto label_000851B4;
    lift_native_call(cpu, native_function_address32(&::timeGetTime), LIFT_CODE_TOKEN_VA(0x4851A4u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x4851ABu));
    cpu->esp += 4u;
label_000851B4:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4Cu);
    if (((cpu->eax) & (0x400u)) == 0u) goto label_000851F6;
    if ((((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_000851E8;
    *(float*)(cpu->edi + 0xCu) = ((((double)*(float*)(cpu->edi + 0xCu))) + (((double)*(float*)(cpu->esi + 0xB0u))));
    *(float*)(cpu->edi + 0x10u) = ((((double)*(float*)(cpu->esi + 0xB4u))) + (((double)*(float*)(cpu->edi + 0x10u))));
    *(float*)(cpu->edi + 0x14u) = ((((double)*(float*)(cpu->esi + 0xB8u))) + (((double)*(float*)(cpu->edi + 0x14u))));
    goto label_000851F6;
label_000851E8:
    cpu->ecx = cpu->esi + 0x11Cu;
    cpu->edx = cpu->edi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x851F6u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_RVA(0x851F6u));
label_000851F6:
    *(float*)(cpu->edi + 0xCu) = ((((double)*(float*)(cpu->esi + 0x34u))) + (((double)*(float*)(cpu->edi + 0xCu))));
    *(float*)(cpu->edi + 0x10u) = ((((double)*(float*)(cpu->esi + 0x38u))) + (((double)*(float*)(cpu->edi + 0x10u))));
    *(float*)(cpu->edi + 0x14u) = ((((double)*(float*)(cpu->esi + 0x3Cu))) + (((double)*(float*)(cpu->edi + 0x14u))));
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    *(uint32_t*)(cpu->edi) = cpu->edx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ecx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00485250(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->edi);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x34u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x70u)));
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v1 = x87_v0;
    *(uint64_t*)(cpu->esp + 0x10u) = static_cast<int64_t>(std::trunc(x87_v1));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    if ((int32_t)cpu->eax >= 0) goto label_000852A3;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000852A3:
    lift_test[0]=(*(uint32_t*)(cpu->esi + 0x4Cu)&0x40000u)==0u;
    *(float*)(cpu->esp + 0x34u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi + 0x70u) = x87_v1; 
    if (lift_test[0]) goto label_000853D1;
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->esi + 0xB0u))) - (((double)*(float*)(cpu->esi + 0xBCu))));
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi + 0xB4u))) - (((double)*(float*)(cpu->esi + 0xC0u))));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->esi + 0xB8u))) - (((double)*(float*)(cpu->esi + 0xC4u))));
    if (cpu->ebp == 0u) goto label_00085415;
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v2 = 0.0;
    x87_v3 = x87_v2;
    { const double lift_left=x87_v3; const double lift_right=x87_v1;  x87_v1=x87_v2;  if (lift_left!=lift_right) goto label_0008532E; }
    { const double lift_right=(double)*(float*)(cpu->esp + 0x1Cu); const double lift_left=x87_v1; if (lift_left!=lift_right) goto label_0008532E; }
    { const double lift_right=(double)*(float*)(cpu->esp + 0x20u); const double lift_left=x87_v1; if (lift_left==lift_right) goto label_00085413; }
    label_0008532E:
    x87_v2 = 1.0;
    cpu->edi = 0u;
    x87_v0 = x87_v2 / x87_v0; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    *(float*)(cpu->esp + 0x34u) = x87_v0;
    if (*(uint32_t*)(cpu->esi + 0x5Cu) <= cpu->edi) goto label_00085415;
    cpu->ebx = 0u;
    label_00085349:
    if (cpu->ebp == 0u) goto label_00085415;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->ebx + cpu->ecx + 0x28u)); if (!(lift_left>lift_right)) goto label_000853BC; }
    lift_push32(cpu, cpu->edi);
    x87_v0 = x87_v0; 
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485369u)); sfera_sub_00484A80(cpu, LIFT_CODE_TOKEN_VA(0x485369u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u); x87_v1 = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x18u)));
    cpu->eax = cpu->ebx + cpu->edx + 0xCu;
    --cpu->ebp;
    ++*(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x28u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    *(float*)(cpu->eax) = ((((double)*(float*)(cpu->eax))) - (((double)*(float*)(cpu->esp + 0x24u))));
    *(float*)(cpu->eax + 4u) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->esp + 0x28u))));
    *(float*)(cpu->eax + 8u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->esp + 0x2Cu))));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    x87_v0 = 0.0;
    label_000853BC:
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x5Cu)) goto label_00085349;
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000853D1:
    x87_v0 = x87_v0; 
    if (cpu->ebp == 0u) goto label_00085417;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x5Cu) <= cpu->edi) goto label_00085417;
    cpu->ebx = 0u;
    label_000853E0:
    if (cpu->ebp == 0u) goto label_00085417;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    { const double lift_left=0.0; const double lift_right=((double)*(float*)(cpu->eax + cpu->ebx + 0x28u)); if (!(lift_left>lift_right)) goto label_00085400; }
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4853FCu)); sfera_sub_00484A80(cpu, LIFT_CODE_TOKEN_VA(0x4853FCu));
    --cpu->ebp;
    ++*(uint32_t*)(cpu->esi + 0x60u);
    label_00085400:
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x5Cu)) goto label_000853E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00085413:
    x87_v1 = x87_v1; 
    label_00085415:
    x87_v0 = x87_v0; 
    label_00085417:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004866A0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    bool lift_cmp[1];
    cpu->esp -= 0x98u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x9Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0x190u) == 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    if (sub_pred[0]) goto label_00087200;
    if (*(uint8_t*)(cpu->ebp + 0xD4u) != 1u) goto label_0008672B;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xBCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ebp + 0xC0u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xB0u);
    *(uint32_t*)(cpu->ebp + 0xC8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xB8u);
    *(uint32_t*)(cpu->ebp + 0xC4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xB4u);
    *(uint32_t*)(cpu->ebp + 0xCCu) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xD0u) = cpu->edx;
    *(uint8_t*)(cpu->ebp + 0xD4u) = 0u;
    goto label_0008674F;
    label_0008672B:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xB0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xB4u);
    *(uint32_t*)(cpu->ebp + 0xBCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xB8u);
    *(uint32_t*)(cpu->ebp + 0xC0u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xC4u) = cpu->ecx;
    label_0008674F:
    lift_test[0]=(*(uint8_t*)(cpu->ebp + 0x4Cu)&0x20u)==0u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xB0u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ebp + 0xB4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xB8u) = cpu->edx;
    if (lift_test[0]) goto label_000867F6;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x58u);
    if (cpu->ecx == 0u) goto label_000867CD;
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->eax = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486794u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x486794u));
    *(float*)(cpu->ebp + 0xB0u) = ((((double)*(float*)(cpu->esp + 0x8Cu))) + (((double)*(float*)(cpu->ebp + 0xB0u))));
    *(float*)(cpu->ebp + 0xB4u) = ((((double)*(float*)(cpu->ebp + 0xB4u))) + (((double)*(float*)(cpu->esp + 0x90u))));
    *(float*)(cpu->ebp + 0xB8u) = ((((double)*(float*)(cpu->ebp + 0xB8u))) + (((double)*(float*)(cpu->esp + 0x94u))));
    label_000867CD:
    if ((*(uint32_t*)(cpu->ebp + 0x4Cu)&0x8000000u)==0u) goto label_00086A26;
    if (cpu->ebx==0u) goto label_00086A26;
    cpu->edi = cpu->ebp + 0x11Cu;
    cpu->esi = cpu->ebx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    goto label_00086A26;
    label_000867F6:
    lift_push32(cpu, 0x40u);
    cpu->edi = 0u;
    cpu->esi = cpu->ebp + 0x11Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x486802u));
    x87_v0 = 1.0;
    *(float*)(cpu->esi + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esi + 0x28u) = x87_v0;
    *(float*)(cpu->esi + 0x14u) = x87_v0;
    *(float*)(cpu->esi) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x50u);
    if (cpu->ecx == 0u) goto label_000868B8;
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->edx = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48683Au)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x48683Au));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4Cu);
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0008686D;
    x87_v0 = (double)*(float*)(cpu->esp + 0x94u);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x9Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48686Bu)); sfera_sub_004825A0(cpu, LIFT_CODE_TOKEN_VA(0x48686Bu));
    goto label_000868B3;
    label_0008686D:
    if ((((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_00086885;
    x87_v0 = (double)*(float*)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486883u)); sfera_sub_00482720(cpu, LIFT_CODE_TOKEN_VA(0x486883u));
    goto label_000868B3;
    label_00086885:
    if ((((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_0008689D;
    x87_v0 = (double)*(float*)(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48689Bu)); sfera_sub_004826C0(cpu, LIFT_CODE_TOKEN_VA(0x48689Bu));
    goto label_000868B3;
    label_0008689D:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_000868B8;
    x87_v0 = (double)*(float*)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x868B3u)); sfera_sub_00482780(cpu, LIFT_CODE_TOKEN_RVA(0x868B3u));
    label_000868B3:
    cpu->edi = 1u;
    label_000868B8:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x54u);
    if (cpu->ecx == 0u) goto label_00086993;
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->eax = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4868DBu)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x4868DBu));
    if (cpu->edi == 0u) goto label_00086970;
    x87_v0 = (double)*(float*)(cpu->esi);
    x87_v1 = (double)*(float*)(cpu->esp + 0x8Cu); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ebp + 0x12Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x90u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->ebp + 0x12Cu) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x94u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->ebp + 0x13Cu)));
    *(float*)(cpu->ebp + 0x13Cu) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ebp + 0x120u);
    x87_v3 = (x87_v3) * (x87_v0);
    *(float*)(cpu->ebp + 0x120u) = x87_v3; 
    x87_v3 = x87_v1;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->ebp + 0x130u)));
    *(float*)(cpu->ebp + 0x130u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ebp + 0x140u);
    x87_v3 = (x87_v3) * (x87_v2);
    *(float*)(cpu->ebp + 0x140u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ebp + 0x124u);
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ebp + 0x124u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->ebp + 0x134u)));
    *(float*)(cpu->ebp + 0x134u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->ebp + 0x144u)));
    goto label_0008698D;
    label_00086970:
    *(float*)(cpu->esi) = (double)*(float*)(cpu->esp + 0x8Cu);
    *(float*)(cpu->ebp + 0x130u) = (double)*(float*)(cpu->esp + 0x90u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x94u);
    label_0008698D:
    *(float*)(cpu->ebp + 0x144u) = x87_v0; 
    label_00086993:
    x87_v0 = (double)*(float*)(cpu->ebp + 0xB0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x58u);
    *(float*)(cpu->ebp + 0x128u) = x87_v0; 
    *(float*)(cpu->ebp + 0x138u) = (double)*(float*)(cpu->ebp + 0xB4u);
    *(float*)(cpu->ebp + 0x148u) = (double)*(float*)(cpu->ebp + 0xB8u);
    if (cpu->ecx == 0u) goto label_00086A0F;
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->edx = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4869D6u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x4869D6u));
    *(float*)(cpu->ebp + 0x128u) = ((((double)*(float*)(cpu->ebp + 0x128u))) + (((double)*(float*)(cpu->esp + 0x8Cu))));
    *(float*)(cpu->ebp + 0x138u) = ((((double)*(float*)(cpu->ebp + 0x138u))) + (((double)*(float*)(cpu->esp + 0x90u))));
    *(float*)(cpu->ebp + 0x148u) = ((((double)*(float*)(cpu->esp + 0x94u))) + (((double)*(float*)(cpu->ebp + 0x148u))));
    label_00086A0F:
    if ((*(uint32_t*)(cpu->ebp + 0x4Cu)&0x8000000u)==0u) goto label_00086A26;
    if (cpu->ebx==0u) goto label_00086A26;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86A26u)); sfera_sub_004822F0(cpu, LIFT_CODE_TOKEN_RVA(0x86A26u));
    label_00086A26:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xD8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x40u);
    cpu->edi <<= 9u;
    cpu->edi += g_sfera_effect_manager.particle_random_table;
    if (cpu->ecx == 0u) goto label_00086A5F;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xE0u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0x48u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86A5Fu)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x86A5Fu));
    label_00086A5F:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x44u);
    if (cpu->ecx == 0u) goto label_00086AC2;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xE0u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x80u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486A8Du)); sfera_sub_0042D9F0(cpu, LIFT_CODE_TOKEN_VA(0x486A8Du));
    if (((*(uint32_t*)(cpu->ebp + 0x4Cu)) & (0x400000u)) == 0u) goto label_00086AAD;
    *(float*)(cpu->ebp + 0xCu) = (double)*(float*)(cpu->esp + 0x74u);
    *(float*)(cpu->ebp + 0x10u) = (double)*(float*)(cpu->esp + 0x78u);
    *(float*)(cpu->ebp + 0x14u) = (double)*(float*)(cpu->esp + 0x7Cu);
    goto label_00086AC2;
    label_00086AAD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(uint32_t*)(cpu->ebp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x3Cu) = cpu->edx;
    label_00086AC2:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x64u);
    if (cpu->ecx == 0u) goto label_00086AEC;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xE0u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0x6Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86AECu)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x86AECu));
    label_00086AEC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x78u);
    if (cpu->ecx == 0u) goto label_00086B16;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xE0u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0x7Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86B16u)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x86B16u));
    label_00086B16:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4Cu);
    if (((cpu->eax) & (0x100u)) == 0u) goto label_00086CD0;
    if (((cpu->eax) & (0x100000u)) == 0u) goto label_00086BFF;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x188u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x88u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u) + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486B5Bu)); sfera_sub_004866A0(cpu, LIFT_CODE_TOKEN_VA(0x486B5Bu));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xB0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB8u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edx;
    if (((cpu->ebx) & (0x400u)) != 0u) goto label_00086C98;
    x87_v0 = (double)*(float*)(cpu->esp + 0x74u);
    if ((((cpu->ebx & 0xFFu)) & (0x20u)) == 0u) goto label_00086BD4;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xB0u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->eax;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xB4u)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x7Cu);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xB8u)));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edx;
    goto label_00086C98;
    label_00086BD4:
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0x128u)));
    *(float*)(cpu->esp + 0x74u) = x87_v0; 
    *(float*)(cpu->esp + 0x78u) = ((((double)*(float*)(cpu->esp + 0x78u))) - (((double)*(float*)(cpu->ebp + 0x138u))));
    *(float*)(cpu->esp + 0x7Cu) = ((((double)*(float*)(cpu->esp + 0x7Cu))) - (((double)*(float*)(cpu->ebp + 0x148u))));
    goto label_00086C98;
    label_00086BFF:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x84u);
    if (cpu->ecx == 0u) goto label_00086C2F;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xE0u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0x98u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86C2Fu)); sfera_sub_0042D9F0(cpu, LIFT_CODE_TOKEN_RVA(0x86C2Fu));
    label_00086C2F:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x98u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x9Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xA0u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->eax;
    if (((cpu->ebx) & (0x400u)) == 0u) goto label_00086C98;
    if ((((cpu->ebx & 0xFFu)) & (0x20u)) == 0u) goto label_00086C89;
    *(float*)(cpu->esp + 0x74u) = ((((double)*(float*)(cpu->esp + 0x74u))) + (((double)*(float*)(cpu->ebp + 0xB0u))));
    *(float*)(cpu->esp + 0x78u) = ((((double)*(float*)(cpu->ebp + 0xB4u))) + (((double)*(float*)(cpu->esp + 0x78u))));
    *(float*)(cpu->esp + 0x7Cu) = ((((double)*(float*)(cpu->ebp + 0xB8u))) + (((double)*(float*)(cpu->esp + 0x7Cu))));
    goto label_00086C98;
    label_00086C89:
    cpu->ecx = cpu->ebp + 0x11Cu;
    cpu->edx = cpu->esp + 0x74u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86C98u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_RVA(0x86C98u));
    label_00086C98:
    if (((cpu->ebx) & (0x200000u)) == 0u) goto label_00086CD0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x80u);
    if (cpu->ecx == 0u) goto label_00086CD0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xE0u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0x8Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86CD0u)); sfera_sub_0042D9F0(cpu, LIFT_CODE_TOKEN_RVA(0x86CD0u));
    label_00086CD0:
    if (((*(uint32_t*)(cpu->ebp + 0x4Cu)) & (0x2000000u)) == 0u) goto label_00086D2A;
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->ebp + 0xB0u))) - (((double)*(float*)(cpu->ebp + 0xC8u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (double)*(float*)(cpu->ebp + 0xB4u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xCCu)));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->ebp + 0xB8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xD0u)));
    cpu->ecx = cpu->esp + 0x18u;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x86D2Au)); sfera_sub_0042F3E0(cpu, LIFT_CODE_TOKEN_RVA(0x86D2Au));
    label_00086D2A:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->ebp + 0x60u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (*(uint32_t*)(cpu->ebp + 0x5Cu) <= cpu->edi) goto label_00087194;
    x87_v0 = 0.0;
    cpu->ebx = native_function_address32(&::rand);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    label_00086D48:
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->esi += *(uint32_t*)(cpu->esp + 0x30u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esi + 0x28u)); if (lift_left>lift_right) goto label_0008717B; }
    if (((*(uint32_t*)(cpu->ebp + 0x4Cu)) & (0x2000u)) != 0u) goto label_00086D72;
    *(float*)(cpu->esi + 0x28u) = ((((double)*(float*)(cpu->esi + 0x28u))) - (2.0));
    label_00086D72:
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esi + 0x28u)); if (!(lift_left<lift_right)) goto label_0008717B; }
    cpu->edi = *(uint32_t*)(cpu->esi + 0x34u);
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esi + 0x28u);
    x87_v0 = (x87_v0) / (((double)*(float*)(cpu->esi + 0x2Cu)));
    cpu->edi <<= 9u;
    cpu->edi += g_sfera_effect_manager.particle_random_table;
    lift_test[1]=(*(uint32_t*)(cpu->ebp + 0x4Cu)&0x1000u)==0u;
    x87_v1 = 1.0;
    x87_v0 = x87_v1 - x87_v0; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if (lift_test[1]) goto label_00086DDB;
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0xB4u);
    label_00086DDB:
    cpu->eax = *(uint16_t*)(cpu->esi + 0x3Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->ecx = 0xFFFFu;
    if ((cpu->eax & 0xFFFFu) == (cpu->ecx & 0xFFFFu)) goto label_00086E12;
    cpu->edx = *(uint16_t*)(cpu->esi + 0x3Au);
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x16Cu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486E0Eu)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_VA(0x486E0Eu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    label_00086E12:
    cpu->eax = *(uint16_t*)(cpu->esi + 0x3Eu);
    cpu->edx = 0xFFFFu;
    if ((cpu->eax & 0xFFFFu) == (cpu->edx & 0xFFFFu)) goto label_00086E47;
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x3Au);
    cpu->edx = *(uint16_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x170u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486E43u)); sfera_sub_0042D430(cpu, LIFT_CODE_TOKEN_VA(0x486E43u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    label_00086E47:
    cpu->eax = *(uint16_t*)(cpu->esi + 0x40u);
    cpu->ecx = 0xFFFFu;
    if ((cpu->eax & 0xFFFFu) == (cpu->ecx & 0xFFFFu)) goto label_00086E7E;
    cpu->edx = *(uint16_t*)(cpu->esi + 0x3Au);
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x174u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486E7Au)); sfera_sub_0042D9F0(cpu, LIFT_CODE_TOKEN_VA(0x486E7Au));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    label_00086E7E:
    cpu->eax = *(uint16_t*)(cpu->esi + 0x42u);
    cpu->edx = 0xFFFFu;
    if ((cpu->eax & 0xFFFFu) == (cpu->edx & 0xFFFFu)) goto label_00086EF6;
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x3Au);
    cpu->edx = *(uint16_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0xA4u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x178u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486EB3u)); sfera_sub_0042D9F0(cpu, LIFT_CODE_TOKEN_VA(0x486EB3u));
    *(float*)(cpu->esp + 0x80u) = ((((double)*(float*)(cpu->esp + 0x98u))) + (((double)*(float*)(cpu->esp + 0x80u))));
    *(float*)(cpu->esp + 0x84u) = ((((double)*(float*)(cpu->esp + 0x9Cu))) + (((double)*(float*)(cpu->esp + 0x84u))));
    *(float*)(cpu->esp + 0x88u) = ((((double)*(float*)(cpu->esp + 0xA0u))) + (((double)*(float*)(cpu->esp + 0x88u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    label_00086EF6:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4Cu);
    if (((cpu->eax) & (0x100u)) == 0u) goto label_00087068;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x80u);
    if (cpu->ecx == 0u) goto label_00086F38;
    if (((cpu->eax) & (0x200000u)) != 0u) goto label_00086F38;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xE0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0x8Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486F34u)); sfera_sub_0042D9F0(cpu, LIFT_CODE_TOKEN_VA(0x486F34u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    label_00086F38:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4Cu);
    if (((cpu->eax) & (0x20000u)) == 0u) goto label_00086FFB;
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->esp + 0x74u))) - (((double)*(float*)(cpu->esi))));
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->esp + 0x78u))) - (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x3Cu) = ((((double)*(float*)(cpu->esp + 0x7Cu))) - (((double)*(float*)(cpu->esi + 8u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    *(float*)(cpu->esp + 0x68u) = ((((double)*(float*)(cpu->esp + 0x40u))) + (((double)*(float*)(cpu->esi))));
    *(float*)(cpu->esp + 0x6Cu) = ((((double)*(float*)(cpu->esp + 0x44u))) + (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x70u) = ((((double)*(float*)(cpu->esi + 8u))) + (((double)*(float*)(cpu->esp + 0x48u))));
    *(float*)(cpu->esp + 0x5Cu) = ((((double)*(float*)(cpu->esp + 0x68u))) - (((double)*(float*)(cpu->esi + 0xCu))));
    *(float*)(cpu->esp + 0x60u) = ((((double)*(float*)(cpu->esp + 0x6Cu))) - (((double)*(float*)(cpu->esi + 0x10u))));
    *(float*)(cpu->esp + 0x64u) = ((((double)*(float*)(cpu->esp + 0x70u))) - (((double)*(float*)(cpu->esi + 0x14u))));
    *(float*)(cpu->esp + 0x80u) = ((((double)*(float*)(cpu->esp + 0x5Cu))) + (((double)*(float*)(cpu->esp + 0x80u))));
    *(float*)(cpu->esp + 0x84u) = ((((double)*(float*)(cpu->esp + 0x60u))) + (((double)*(float*)(cpu->esp + 0x84u))));
    *(float*)(cpu->esp + 0x88u) = ((((double)*(float*)(cpu->esp + 0x64u))) + (((double)*(float*)(cpu->esp + 0x88u))));
    goto label_0008706A;
    label_00086FFB:
    x87_v0 = x87_v0; 
    *(float*)(cpu->esp + 0x50u) = ((((double)*(float*)(cpu->esp + 0x74u))) - (((double)*(float*)(cpu->esi + 0xCu))));
    *(float*)(cpu->esp + 0x54u) = ((((double)*(float*)(cpu->esp + 0x78u))) - (((double)*(float*)(cpu->esi + 0x10u))));
    *(float*)(cpu->esp + 0x58u) = ((((double)*(float*)(cpu->esp + 0x7Cu))) - (((double)*(float*)(cpu->esi + 0x14u))));
    *(float*)(cpu->esp + 0x80u) = (((((((double)*(float*)(cpu->ebp + 0x8Cu))) * (((double)*(float*)(cpu->esp + 0x50u)))))) + (((double)*(float*)(cpu->esp + 0x80u))));
    *(float*)(cpu->esp + 0x84u) = (((((((double)*(float*)(cpu->ebp + 0x90u))) * (((double)*(float*)(cpu->esp + 0x54u)))))) + (((double)*(float*)(cpu->esp + 0x84u))));
    *(float*)(cpu->esp + 0x88u) = (((((((double)*(float*)(cpu->ebp + 0x94u))) * (((double)*(float*)(cpu->esp + 0x58u)))))) + (((double)*(float*)(cpu->esp + 0x88u))));
    goto label_0008706A;
    label_00087068:
    x87_v0 = x87_v0; 
    label_0008706A:
    if (((cpu->eax) & (0x10000u)) == 0u) goto label_000870D7;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->edi = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->edi -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(float*)(cpu->esi + 0xCu) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (3.0518509447574615e-05)))) * (((double)*(float*)(cpu->ebp + 0xA4u)))))) + (((double)*(float*)(cpu->esi + 0xCu))));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->edi = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->edi -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(float*)(cpu->esi + 0x10u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (3.0518509447574615e-05)))) * (((double)*(float*)(cpu->ebp + 0xA8u)))))) + (((double)*(float*)(cpu->esi + 0x10u))));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->edi = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->edi -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(float*)(cpu->esi + 0x14u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (3.0518509447574615e-05)))) * (((double)*(float*)(cpu->ebp + 0xACu)))))) + (((double)*(float*)(cpu->esi + 0x14u))));
    label_000870D7:
    if (((*(uint32_t*)(cpu->ebp + 0x4Cu)) & (0x2000000u)) == 0u) goto label_00087116;
    *(float*)(cpu->esp + 0x80u) = ((((double)*(float*)(cpu->esp + 0x18u))) * (((double)*(float*)(cpu->esp + 0x80u))));
    *(float*)(cpu->esp + 0x84u) = ((((double)*(float*)(cpu->esp + 0x1Cu))) * (((double)*(float*)(cpu->esp + 0x84u))));
    *(float*)(cpu->esp + 0x88u) = ((((double)*(float*)(cpu->esp + 0x20u))) * (((double)*(float*)(cpu->esp + 0x88u))));
    label_00087116:
    *(float*)(cpu->esi + 0xCu) = ((((double)*(float*)(cpu->esp + 0x80u))) + (((double)*(float*)(cpu->esi + 0xCu))));
    *(float*)(cpu->esi + 0x10u) = ((((double)*(float*)(cpu->esp + 0x84u))) + (((double)*(float*)(cpu->esi + 0x10u))));
    *(float*)(cpu->esi + 0x14u) = ((((double)*(float*)(cpu->esi + 0x14u))) + (((double)*(float*)(cpu->esp + 0x88u))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->ebp + 0x184u))) + (((double)*(float*)(cpu->esi + 0x44u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esi + 0x44u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x180u);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if ((int32_t)(cpu->eax) >= 0) goto label_00087168;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_00087168:
    lift_cmp[0]=x87_v1<x87_v0;  
    x87_v0 = 0.0;
    if (!lift_cmp[0]) goto label_00087176;
    *(float*)(cpu->esi + 0x44u) = x87_v0;
    label_00087176:
    ++*(uint32_t*)(cpu->ebp + 0x60u);
    cpu->edi = 0u;
    label_0008717B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x30u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x30u)) + (uint64_t)(0x50u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ebp + 0x5Cu)) goto label_00086D48;
    x87_v0 = x87_v0; 
    label_00087194:
    if (((*(uint8_t*)(cpu->ebp + 0x4Cu)) & (0x80u)) == 0u) goto label_000871B9;
    lift_push32(cpu, 0x9A7u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4871AEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4871AEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4871B4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4871B4u));
    cpu->esp += 0x10u;
    goto label_000871E7;
    label_000871B9:
    if (*(uint32_t*)(cpu->ebp + 0x74u) == cpu->edi) goto label_000871CF;
    x87_v0 = (double)2.0f;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x871CFu)); sfera_sub_00485250(cpu, LIFT_CODE_TOKEN_RVA(0x871CFu));
    label_000871CF:
    if (*(uint32_t*)(cpu->ebp + 0x60u) != cpu->edi) goto label_000871E7;
    if (*(uint32_t*)(cpu->ebp + 0x74u) != cpu->edi) goto label_000871E7;
    if (*(uint32_t*)(cpu->ebp + 0x194u) == cpu->edi) goto label_000871E7;
    *(uint32_t*)(cpu->ebp + 0x190u) = cpu->edi;
    label_000871E7:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4871FEu)); sfera_sub_00487220(cpu, LIFT_CODE_TOKEN_VA(0x4871FEu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00087200:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x98u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00487220(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    bool lift_cmp[2];
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->edi);
    if (((cpu->eax) & (0x400u)) == 0u) goto label_000872B8;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x5Cu) <= cpu->edi) goto label_000873FB;
    cpu->ebx = 0u;
    label_00087244:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    x87_v0 = 0.0;
    lift_cmp[0]=x87_v0>(((double)*(float*)(cpu->ecx + cpu->ebx + 0x28u)));
    cpu->ecx += cpu->ebx;
    if (lift_cmp[0]) goto label_000872A5;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = cpu->ecx + 0x18u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x48u);
    if (cpu->edx == 0u) goto label_000872A5;
    if (((*(uint32_t*)(cpu->edx + 0x4Cu)) & (0x800000u)) == 0u) goto label_00087292;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 0x27u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(float*)(cpu->edx + 0x7Cu) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) / (255.0)))) * (((double)*(float*)(cpu->esi + 0x7Cu))));
    label_00087292:
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x48u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x872A5u)); sfera_sub_004866A0(cpu, LIFT_CODE_TOKEN_RVA(0x872A5u));
    label_000872A5:
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x5Cu)) goto label_00087244;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000872B8:
    if ((((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_00087372;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x5Cu) <= cpu->edi) goto label_000873FB;
    cpu->ebx = 0u;
    label_000872D0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    x87_v0 = 0.0;
    lift_cmp[1]=x87_v0>(((double)*(float*)(cpu->ecx + cpu->ebx + 0x28u)));
    cpu->ecx += cpu->ebx;
    if (lift_cmp[1]) goto label_0008735B;
    x87_v0 = (double)*(float*)(cpu->esi + 0xB0u);
    cpu->eax = cpu->ecx + 0x18u;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi + 0xB4u))) + (((double)*(float*)(cpu->ecx + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esi + 0xB8u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ecx + 0x14u)));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x48u);
    if (cpu->edx == 0u) goto label_0008735B;
    if (((*(uint32_t*)(cpu->edx + 0x4Cu)) & (0x800000u)) == 0u) goto label_00087348;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 0x27u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(float*)(cpu->edx + 0x7Cu) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) / (255.0)))) * (((double)*(float*)(cpu->esi + 0x7Cu))));
    label_00087348:
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x48u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8735Bu)); sfera_sub_004866A0(cpu, LIFT_CODE_TOKEN_RVA(0x8735Bu));
    label_0008735B:
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x5Cu)) goto label_000872D0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00087372:
    cpu->ebp = 0u;
    if (*(uint32_t*)(cpu->esi + 0x5Cu) <= cpu->ebp) goto label_000873FB;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    label_00087381:
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    x87_v0 = 0.0;
    cpu->edi += *(uint32_t*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->edi + 0x28u));  if (lift_left>lift_right) goto label_000873F0; }
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->ebx = cpu->edi + 0x18u;
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->ecx = cpu->esi + 0x11Cu;
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4873B5u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x4873B5u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x48u);
    if (cpu->eax == 0u) goto label_000873F0;
    if (((*(uint32_t*)(cpu->eax + 0x4Cu)) & (0x800000u)) == 0u) goto label_000873DD;
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x27u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(float*)(cpu->eax + 0x7Cu) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) / (255.0)))) * (((double)*(float*)(cpu->esi + 0x7Cu))));
    label_000873DD:
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x48u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x873F0u)); sfera_sub_004866A0(cpu, LIFT_CODE_TOKEN_RVA(0x873F0u));
    label_000873F0:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x50u) + (uint64_t)(0u);
    ++cpu->ebp;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0x5Cu)) goto label_00087381;
    label_000873FB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00487410(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[3]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    cpu->esp -= 0xBCu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x190u) == 0u) goto label_00087D48;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->esi) goto label_00087457;
    cpu->ebx = 0u;
    label_00087431:
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->ecx + cpu->ebx + 0x28u));  if (lift_left>lift_right) goto label_0008744E; }
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->ebx + 0x48u);
    if (cpu->ecx == 0u) goto label_0008744E;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8744Eu)); sfera_sub_00487410(cpu, LIFT_CODE_TOKEN_RVA(0x8744Eu));
    label_0008744E:
    ++cpu->esi;
    cpu->ebx += 0x50u;
    if (cpu->esi < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_00087431;
    label_00087457:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x5Cu);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->edx = cpu->ecx + cpu->eax;
    if (cpu->edx >= 0x2710u) goto label_00087D46;
    x87_v0 = (double)*(float*)(cpu->edi + 0x7Cu);
    lift_push32(cpu, cpu->ebp);
    x87_v0 = (x87_v0) * (256.0);
    cpu->eax = 0u;
    *(uint64_t*)(cpu->esp + 0x6Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    if (cpu->ebp == cpu->eax) goto label_00087D45;
    if (*(uint32_t*)(cpu->edi + 0x17Cu) == cpu->eax) goto label_00087D45;
    lift_test[0]=(*(uint32_t*)(cpu->edi + 0x4Cu)&0x800u)==0u;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (lift_test[0]) goto label_000877B0;
    if (cpu->ecx <= cpu->eax) goto label_00087D45;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000874E1:
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    x87_v0 = 0.0;
    cpu->esi += *(uint32_t*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esi + 0x28u));  if (lift_left>lift_right) goto label_0008778E; }
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->ebx = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_00087513;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x87513u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x87513u));
    label_00087513:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_00087527;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x87527u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x87527u));
    label_00087527:
    x87_v0 = (double)*(float*)(cpu->esi + 0x44u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += g_sfera_effect_manager.render_slots.data;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    lift_test[1]=(*(uint32_t*)(cpu->edi + 0x4Cu)&0x200u)==0u;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    if (lift_test[1]) goto label_0008759B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x88u);
    *(uint32_t*)(cpu->ebx + 0x90u) = cpu->edx;
    *(float*)(cpu->ebx + 0x70u) = (double)*(float*)(cpu->eax + 8u);
    *(float*)(cpu->ebx + 0x74u) = (double)*(float*)(cpu->eax + 0xCu);
    *(float*)(cpu->ebx + 0x78u) = (double)*(float*)(cpu->eax + 0x10u);
    *(float*)(cpu->ebx + 0x7Cu) = (double)*(float*)(cpu->eax + 0x14u);
    *(float*)(cpu->ebx + 0x80u) = (double)*(float*)(cpu->eax + 0x18u);
    *(float*)(cpu->ebx + 0x84u) = (double)*(float*)(cpu->eax + 0x1Cu);
    *(float*)(cpu->ebx + 0x88u) = (double)*(float*)(cpu->eax + 0x20u);
    *(float*)(cpu->ebx + 0x8Cu) = (double)*(float*)(cpu->eax + 0x24u);
    goto label_000875A4;
    label_0008759B:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ebx + 0x90u) = cpu->eax;
    label_000875A4:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xE8u);
    *(uint32_t*)(cpu->ebx + 0x98u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xE4u);
    *(uint32_t*)(cpu->ebx + 0x94u) = cpu->edx;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x27u);
    cpu->ecx *= cpu->ebp;
    cpu->ecx >>= 8u;
    cpu->eax = cpu->ebx + 0x40u;
    cpu->edx = 4u;
    label_000875D0:
    cpu->ebp = *(uint8_t*)(cpu->esi + 0x24u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF0u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->esi + 0x25u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->esi + 0x26u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->eax += 4u;
    if ((--cpu->edx) != 0u) goto label_000875D0;
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esi + 0x30u);
    x87_v0 = (double)*(float*)(cpu->edi + 0xECu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0xF0u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 0xF4u)));
    *(float*)(cpu->esp + 0x44u) = x87_v0; 
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->esi + 0x18u))) + (((double)*(float*)(cpu->esp + 0x3Cu))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x40u))) + (((double)*(float*)(cpu->esi + 0x1Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x20u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x44u)));
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esi + 0x30u);
    x87_v0 = (double)*(float*)(cpu->edi + 0xF8u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0xFCu);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 0x100u)));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp + 0x6Cu) = ((((double)*(float*)(cpu->esi + 0x18u))) + (((double)*(float*)(cpu->esp + 0x18u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(float*)(cpu->esp + 0x70u) = ((((double)*(float*)(cpu->esp + 0x1Cu))) + (((double)*(float*)(cpu->esi + 0x1Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x20u)));
    *(uint32_t*)(cpu->ebx + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x10u) = cpu->ecx;
    *(float*)(cpu->esp + 0x74u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    *(uint32_t*)(cpu->ebx + 0x14u) = cpu->edx;
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esi + 0x30u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->edi + 0x104u)));
    *(float*)(cpu->esp + 0x48u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x108u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x4Cu) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 0x10Cu)));
    *(float*)(cpu->esp + 0x50u) = x87_v0; 
    *(float*)(cpu->esp + 0x78u) = ((((double)*(float*)(cpu->esi + 0x18u))) + (((double)*(float*)(cpu->esp + 0x48u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x78u);
    *(float*)(cpu->esp + 0x7Cu) = ((((double)*(float*)(cpu->esp + 0x4Cu))) + (((double)*(float*)(cpu->esi + 0x1Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x7Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x50u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x20u)));
    *(uint32_t*)(cpu->ebx + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x1Cu) = cpu->ecx;
    *(float*)(cpu->esp + 0x80u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->edx;
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esi + 0x30u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x110u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x54u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x114u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x58u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 0x118u)));
    *(float*)(cpu->esp + 0x5Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x60u) = ((((double)*(float*)(cpu->esp + 0x54u))) + (((double)*(float*)(cpu->esi + 0x18u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x60u);
    *(float*)(cpu->esp + 0x64u) = ((((double)*(float*)(cpu->esp + 0x58u))) + (((double)*(float*)(cpu->esi + 0x1Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x64u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x5Cu);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x20u)));
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x28u) = cpu->ecx;
    *(float*)(cpu->esp + 0x68u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->ebx + 0x2Cu) = cpu->edx;
    label_0008778E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x50u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_000874E1;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xBCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000877B0:
    if (cpu->ecx <= cpu->eax) goto label_00087D45;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000877C0:
    cpu->ebx = *(uint32_t*)(cpu->edi + 4u);
    x87_v0 = 0.0;
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x14u);
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->ebx + 0x28u));  if (lift_left>lift_right) goto label_00087D2E; }
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_000877F2;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x877F2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x877F2u));
    label_000877F2:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_00087806;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x87806u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x87806u));
    label_00087806:
    x87_v0 = (double)*(float*)(cpu->ebx + 0x44u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    lift_test[2]=(*(uint32_t*)(cpu->edi + 0x4Cu)&0x200u)==0u;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    if (lift_test[2]) goto label_0008787A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x88u);
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->edx;
    *(float*)(cpu->esi + 0x70u) = (double)*(float*)(cpu->eax + 8u);
    *(float*)(cpu->esi + 0x74u) = (double)*(float*)(cpu->eax + 0xCu);
    *(float*)(cpu->esi + 0x78u) = (double)*(float*)(cpu->eax + 0x10u);
    *(float*)(cpu->esi + 0x7Cu) = (double)*(float*)(cpu->eax + 0x14u);
    *(float*)(cpu->esi + 0x80u) = (double)*(float*)(cpu->eax + 0x18u);
    *(float*)(cpu->esi + 0x84u) = (double)*(float*)(cpu->eax + 0x1Cu);
    *(float*)(cpu->esi + 0x88u) = (double)*(float*)(cpu->eax + 0x20u);
    *(float*)(cpu->esi + 0x8Cu) = (double)*(float*)(cpu->eax + 0x24u);
    goto label_00087883;
    label_0008787A:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    label_00087883:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xE8u);
    *(uint32_t*)(cpu->esi + 0x98u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xE4u);
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->edx;
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0x27u);
    cpu->ecx *= cpu->ebp;
    cpu->ecx >>= 8u;
    cpu->eax = cpu->esi + 0x40u;
    cpu->edx = 4u;
    label_000878B0:
    cpu->ebp = *(uint8_t*)(cpu->ebx + 0x24u);
    *(uint32_t*)(cpu->eax + 0xFFFFFFF0u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ebx + 0x25u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ebx + 0x26u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->eax += 4u;
    if ((--cpu->edx) != 0u) goto label_000878B0;
    x87_v0 = (double)*(float*)(cpu->ebx + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x18u);
    *(float*)(cpu->esp + 0x8Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->edi + 0xECu);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x20u);
    *(float*)(cpu->esp + 0x6Cu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->edi + 0xF0u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    *(float*)(cpu->esp + 0x84u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    *(float*)(cpu->esp + 0x60u) = ((((double)*(float*)(cpu->esp + 0x3Cu))) - (((double)g_sfera_effect_manager.viewer_position.x)));
    *(float*)(cpu->esp + 0x64u) = ((((double)*(float*)(cpu->esp + 0x40u))) - (((double)g_sfera_effect_manager.viewer_position.y)));
    *(float*)(cpu->esp + 0x68u) = ((((double)*(float*)(cpu->esp + 0x44u))) - (((double)g_sfera_effect_manager.viewer_position.z)));
    x87_v0 = (double)*(float*)(cpu->esp + 0x64u); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    x87_v1 = (x87_v1) * (x87_v2);
    x87_v3 = (double)*(float*)(cpu->esp + 0x68u); x87_v4 = x87_v3;
    x87_v5 = -1.0;
    x87_v4 = (x87_v4) * (x87_v5);
    x87_v6 = x87_v1;
    x87_v4 = x87_v6 - x87_v4; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0x24u) = x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v6 = (double)*(float*)(cpu->esp + 0x60u); x87_v7 = x87_v6;
    x87_v2 = x87_v2 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    x87_v2 = x87_v6 - x87_v2; 
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v5; 
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v1 = x87_v4 - x87_v1; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v4 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = x87_v1;
    x87_v6 = (double)*(float*)(cpu->esp + 0x28u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    x87_v5 = x87_v6 - x87_v5; 
    *(float*)(cpu->esp + 0x18u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x24u); x87_v6 = x87_v5;
    x87_v1 = x87_v1 * x87_v6; 
    x87_v6 = x87_v2;
    x87_v6 = (x87_v6) * (x87_v4);
    x87_v1 = x87_v1 - x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v5; 
    x87_v5 = x87_v3;
    x87_v2 = x87_v2 * x87_v5; 
    x87_v5 = x87_v1;
    x87_v0 = x87_v0 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v0 = x87_v4 - x87_v0; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v7 = x87_v4;
    x87_v4 = x87_v4 * x87_v7; 
    x87_v7 = x87_v5;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = x87_v4;
    x87_v4 = x87_v4 * x87_v6; 
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->esp + 0x10u) = x87_v4; 
    x87_v4 = (double)9.999999747378752e-06f;
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v5; const double lift_right=x87_v4; if (!(lift_left<lift_right)) goto label_00087A16; }
    x87_v5 = x87_v5; 
    x87_v3 = x87_v4; 
    *(float*)(cpu->esp + 0x54u) = (double)(1.0);
    x87_v4 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    *(float*)(cpu->esp + 0x58u) = x87_v4;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esp + 0x5Cu) = x87_v4; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    goto label_00087A77;
    label_00087A16:
    *(float*)(cpu->esp + 0x10u) = x87_v5;
    cpu->ecx = 0x5F3759DFu;
    x87_v5 = (x87_v5) * (0.5);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax >>= 1u;
    cpu->ecx -= cpu->eax;
    *(float*)(cpu->esp + 0x34u) = x87_v5; 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    x87_v5 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x10u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    x87_v7 = 1.5;
    x87_v5 = x87_v7 - x87_v5; 
    x87_v5 = x87_v5 * x87_v6; 
    *(float*)(cpu->esp + 0x10u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u); x87_v6 = x87_v5;
    x87_v3 = x87_v3 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v4; 
    label_00087A77:
    x87_v4 = x87_v0;
    x87_v5 = x87_v1;
    x87_v6 = x87_v2;
    x87_v7 = x87_v5;
    x87_v5 = x87_v5 * x87_v7; 
    x87_v7 = x87_v4;
    x87_v4 = x87_v4 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    x87_v4 = x87_v4 + x87_v6; 
    x87_v5 = (x87_v5) * (x87_v5);
    x87_v4 = x87_v4 + x87_v5; 
    *(float*)(cpu->esp + 0x34u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x34u);
    { const double lift_left=x87_v4; const double lift_right=x87_v3; x87_v3=x87_v4;  if (!(lift_left<lift_right)) goto label_00087AD8; }
    x87_v3 = x87_v3; 
    x87_v2 = x87_v2; 
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x78u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x78u);
    *(float*)(cpu->esp + 0x7Cu) = x87_v0; 
    x87_v0 = 1.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(float*)(cpu->esp + 0x80u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    goto label_00087B33;
    label_00087AD8:
    *(float*)(cpu->esp + 0x34u) = x87_v3;
    cpu->eax = 0x5F3759DFu;
    x87_v3 = (x87_v3) * (0.5);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx >>= 1u;
    cpu->eax -= cpu->edx;
    *(float*)(cpu->esp + 0x34u) = x87_v3; 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v3 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = 1.5;
    x87_v3 = x87_v5 - x87_v3; 
    x87_v3 = x87_v3 * x87_v4; 
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u); x87_v4 = x87_v3;
    x87_v1 = x87_v1 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x24u) = x87_v3; 
    x87_v3 = x87_v1;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v2; 
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    label_00087B33:
    x87_v0 = (double)*(float*)(cpu->esp + 0x8Cu); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x84u)));
    *(float*)(cpu->esp + 0x84u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x84u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = x87_v2; 
    x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x6Cu)));
    *(float*)(cpu->esp + 0x6Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x6Cu); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x28u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x48u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x40u); x87_v3 = x87_v2;
    x87_v4 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v5 = x87_v4;
    x87_v3 = x87_v3 - x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x4Cu) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x44u); x87_v5 = x87_v4;
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 - x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->esp + 0x50u) = x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 + x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x90u) = x87_v4; 
    x87_v2 = x87_v2 + x87_v3; 
    *(float*)(cpu->esp + 0x94u) = x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x98u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x48u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x24u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x9Cu) = x87_v2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x9Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    x87_v3 = x87_v2;
    x87_v4 = (double)*(float*)(cpu->esp + 0x28u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 - x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0xA0u) = x87_v4; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xA0u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    x87_v5 = x87_v4;
    x87_v6 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v7 = x87_v6;
    x87_v5 = x87_v5 - x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->esp + 0xA4u) = x87_v6; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xA4u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    x87_v6 = x87_v1;
    x87_v0 = x87_v0 + x87_v6; 
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xB4u) = x87_v5; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xB4u);
    x87_v5 = x87_v3;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    x87_v2 = x87_v2 + x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0xB8u) = x87_v4; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xB8u);
    x87_v4 = x87_v0;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    x87_v2 = x87_v2 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0xBCu) = x87_v3; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xBCu);
    x87_v3 = (double)*(float*)(cpu->esp + 0x90u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    x87_v4 = x87_v3;
    x87_v4 = (x87_v4) + (x87_v1);
    *(float*)(cpu->esp + 0xA8u) = x87_v4; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xA8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x94u);
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ecx;
    x87_v5 = x87_v4;
    x87_v5 = (x87_v5) + (x87_v2);
    *(float*)(cpu->esp + 0xACu) = x87_v5; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xACu);
    x87_v5 = (double)*(float*)(cpu->esp + 0x98u);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    x87_v6 = x87_v5;
    x87_v6 = (x87_v6) + (x87_v0);
    *(float*)(cpu->esp + 0xB0u) = x87_v6; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB0u);
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    x87_v1 = x87_v5 - x87_v1; 
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0xC0u) = x87_v4; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xC0u);
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ecx;
    x87_v2 = x87_v3 - x87_v2; 
    *(float*)(cpu->esp + 0xC4u) = x87_v2; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xC4u);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edx;
    x87_v0 = x87_v1 - x87_v0; 
    *(float*)(cpu->esp + 0xC8u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xC8u);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    label_00087D2E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x50u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_000877C0;
    label_00087D45:
    cpu->ebp = lift_pop32(cpu);
    label_00087D46:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00087D48:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xBCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00489810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_0008982B;
    lift_push32(cpu, 0x43u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\pathzones.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489825u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x489825u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_0008982B:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00489830(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; double x87_v0, x87_v1, x87_v2;
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    x87_v1 = 4000.0;
    lift_push32(cpu, cpu->edi);
    x87_v0 = (x87_v0) + (x87_v1);
    cpu->edi = cpu->ecx;
    x87_v2 = 10.0;
    x87_v0 = (x87_v0) / (x87_v2);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->esi = cpu->eax;
    x87_v0 = x87_v1 / x87_v0; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    if (cpu->esi > 0x31Fu) goto label_0008989C;
    if (cpu->eax > 0x31Fu) goto label_0008989C;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x320u);
    cpu->eax += cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx&=7u;
    cpu->ebx = 1u;
    cpu->ebx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx &= 7u;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    lift_test[0]=(*(uint8_t*)(cpu->eax + cpu->ecx)&(cpu->ebx & 0xFFu))==0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((!lift_test[0]) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008989C:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004898B0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = cpu->edi + 0x9C40u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = cpu->edx + cpu->eax;
    cpu->eax = cpu->esi + 0x9C40u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ecx -= 0x2690u;
    cpu->eax -= 0x2690u;
    *(uint32_t*)(cpu->esp + 0xCu) = 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->ecx > 0xFFu) goto label_00089B95;
    if (cpu->eax > 0xFFu) goto label_00089B95;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edi;
    cpu->ebx&=0xFFFFFFFCu;
    cpu->ecx <<= 8u;
    cpu->esi &= 0xFFFFFFFCu;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ebp = (cpu->ecx * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.quadtree_cells[0]);
    *(uint32_t*)(cpu->esp + 0x18u) = 2u;
    goto label_00089938;
    label_00089934:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00089938:
    if (*(uint32_t*)(cpu->ebp) != 0u) goto label_00089968;
    lift_push32(cpu, 0x2Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    cpu->ecx = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48994Fu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x48994Fu));
    *(uint32_t*)(cpu->ebp) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_00089968:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->edx = 0u;
    cpu->ecx = cpu->esi + cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax += cpu->ebx;
    sub_pred[0] = (int32_t)(*(uint32_t*)(cpu->esp + 0x34u)) < (int32_t)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (!sub_pred[0]);
    cpu->ebx = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((int32_t)(cpu->edi) >= (int32_t)(cpu->eax));
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->ebx = cpu->ebx + (cpu->edx * 2u);
    if ((int32_t)cpu->ebx < 0) goto label_0008999E;
    if ((int32_t)cpu->ebx <= (int32_t)3u) goto label_000899CB;
    label_0008999E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"----ERROR_Quadtree, xi=%d, yi=%d, xc=%d, yc=%d, xa=%d, ya=%d\n");
    cpu->ebx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4899C0u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4899C0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esp += 0x1Cu;
    label_000899CB:
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->ebp = cpu->edx + (cpu->ebx * 4u);
    if ((((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_000899DA;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000899DA:
    if ((((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_000899E1;
    cpu->esi = cpu->ecx;
    label_000899E1:
    if ((--*(uint32_t*)(cpu->esp + 0x18u)) != 0u) goto label_00089934;
    cpu->esi = *(uint32_t*)(cpu->ebp);
    if (cpu->esi != 0u) goto label_00089A0C;
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    cpu->ecx = cpu->esi + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489A01u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x489A01u));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->ebp) = cpu->eax;
    *(uint32_t*)(cpu->esi) = 0u;
    label_00089A0C:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax != 0u) goto label_00089A2A;
    lift_push32(cpu, 0x47u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    cpu->ecx = cpu->eax + 0x18u;
    *(uint32_t*)(cpu->esi + 4u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489A28u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x489A28u));
    goto label_00089A53;
    label_00089A2A:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax != cpu->ecx) goto label_00089A56;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, 0x4Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp");
    cpu->edx = cpu->eax * 4u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x89A53u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_RVA(0x89A53u));
    label_00089A53:
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_00089A56:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) = cpu->edx;
    cpu->eax = cpu->edi + 0x1D4C0u;
    cpu->ecx = 0xCu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    ++*(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    cpu->eax += 0xFFFFD8F0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax += 0x1D4C0u;
    cpu->ebx = cpu->edx;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax += 0xFFFFD8F0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->ecx = cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ebx))) >> 32u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + (cpu->edi * 2u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(cpu->ebx))) >> 32u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->edi;
    cpu->edx&=0x80000001u;
    if (((cpu->edx)&0x80000000u)==0u) goto label_00089AE9;
    --cpu->edx;
    cpu->edx |= 0xFFFFFFFEu;
    ++cpu->edx;
    label_00089AE9:
    cpu->ebp = cpu->eax;
    cpu->ebp&=0x80000001u;
    if (((cpu->ebp)&0x80000000u)==0u) goto label_00089AF8;
    --cpu->ebp;
    cpu->ebp |= 0xFFFFFFFEu;
    ++cpu->ebp;
    label_00089AF8:
    cpu->edx = cpu->ebp + (cpu->edx * 2u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    cpu->edx = cpu->edi + (cpu->edi * 2u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx -= cpu->eax;
    cpu->ebx = cpu->ebx + (cpu->ecx * 2u);
    cpu->ebx += cpu->ecx;
    cpu->eax = 0x27u;
    cpu->ecx = cpu->edx + 0x28u;
    cpu->eax -= cpu->edi;
    if ((int32_t)cpu->ecx < 0) goto label_00089B27;
    if ((int32_t)cpu->ecx < (int32_t)0x50u) goto label_00089B29;
    label_00089B27:
    cpu->ecx = 0u;
    label_00089B29:
    if ((int32_t)cpu->eax < 0) goto label_00089B32;
    if ((int32_t)(cpu->eax) < (int32_t)(0x50u)) goto label_00089B34;
    label_00089B32:
    cpu->eax=0u;
    label_00089B34:
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->edx *= 0x64u;
    cpu->ecx <<= 4u;
    cpu->ecx += cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x64u);
    cpu->ebp = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(float*)(cpu->esi + 0x2Cu) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xCu) = 1u;
    cpu->ebx = lift_pop32(cpu);
    label_00089B95:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00489BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    cpu->eax = cpu->ebx + 0x9C40u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx &= 3u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx + cpu->eax;
    cpu->eax = cpu->ebp + 0x9C40u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    cpu->eax += cpu->edx;
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->esi -= 0x2690u;
    cpu->eax -= 0x2690u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->edi = 4u;
    if (cpu->esi > 0xFFu) goto label_00089CB3;
    if (cpu->eax > 0xFFu) goto label_00089CB3;
    cpu->ecx = cpu->ebx;
    cpu->esi <<= 8u;
    cpu->ecx &= 0xFFFFFFFCu;
    cpu->ebp &= 0xFFFFFFFCu;
    cpu->esi += cpu->eax;
    cpu->edx = (cpu->esi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.quadtree_cells[0]);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_00089C17:
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax == 0u) goto label_00089C7F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + (cpu->eax * 4u) + 0x20u) = cpu->edx;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->edi = cpu->eax;
    cpu->edx = 0u;
    cpu->ebx = cpu->edi + cpu->ebp;
    cpu->esi = cpu->ecx + cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)) >= (int32_t)(cpu->ebx));
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)) >= (int32_t)(cpu->esi));
    cpu->eax = cpu->eax + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->edx + (cpu->eax * 4u);
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00089C5A;
    cpu->ecx = cpu->esi;
    label_00089C5A:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00089C60;
    cpu->ebp = cpu->ebx;
    label_00089C60:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)2u) goto label_00089C17;
    *(uint32_t*)(cpu->esp + (cpu->eax * 4u) + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != 0u) goto label_00089C86;
    lift_push32(cpu, (uintptr_t)"internal error 639206792");
    goto label_00089CA6;
    label_00089C7F:
    lift_push32(cpu, (uintptr_t)"internal error 849385252");
    goto label_00089CA6;
    label_00089C86:
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0u;
    if ((int32_t)cpu->esi <= 0) goto label_00089CA1;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    label_00089C91:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (*(uint32_t*)(cpu->edx) == cpu->edi) goto label_00089CBD;
    ++cpu->ecx;
    cpu->edx += 4u;
    if ((int32_t)cpu->ecx < (int32_t)cpu->esi) goto label_00089C91;
    label_00089CA1:
    lift_push32(cpu, (uintptr_t)"internal error 075982391");
    label_00089CA6:
    lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489CB0u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x489CB0u));
    cpu->esp += 8u;
    label_00089CB3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00089CBD:
    --cpu->esi;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_00089CD3;
    label_00089CC2:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 4u);
    cpu->edx = cpu->edx + (cpu->ecx * 4u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->edx) = cpu->edi;
    if ((int32_t)cpu->ecx < (int32_t)cpu->esi) goto label_00089CC2;
    label_00089CD3:
    if ((--*(uint32_t*)(cpu->eax)) != 0u) goto label_00089CB3;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0xA5u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489CE9u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x489CE9u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, 0xA6u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489CFEu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x489CFEu));
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->edi = 1u;
    label_00089D10:
    cpu->esi = *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->ecx) != 0u) goto label_00089CB3;
    if (*(uint32_t*)(cpu->ecx + 4u) != 0u) goto label_00089CB3;
    if (*(uint32_t*)(cpu->ecx + 8u) != 0u) goto label_00089CB3;
    if (*(uint32_t*)(cpu->ecx + 0xCu) != 0u) goto label_00089CB3;
    lift_push32(cpu, 0xADu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489D3Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x489D3Cu));
    --cpu->edi;
    *(uint32_t*)(cpu->esi) = 0u;
    if ((int32_t)(cpu->edi) >= 0) goto label_00089D10;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00489D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->esi = 0u;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if ((int16_t)(cpu->eax & 0xFFFFu) >= (int16_t)*(uint16_t*)(cpu->ebx + 0x20C98u)) goto label_00089DB9;
    cpu->edi = cpu->ebx + 4u;
    label_00089D90:
    cpu->edx = 0x2Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\QuickFile.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489D9Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x489D9Fu));
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489DA7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x489DA7u));
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->ebx + 0x20C98u));
    ++cpu->esi;
    cpu->esp += 4u;
    cpu->edi += 8u;
    if ((int32_t)cpu->esi < (int32_t)cpu->ecx) goto label_00089D90;
    label_00089DB9:
    cpu->ecx = cpu->ebx + 0xC80u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489DCCu)); sfera_sub_00430BC0(cpu, LIFT_CODE_TOKEN_VA(0x489DCCu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00489DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebp);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x489DEFu));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->edi != 0u) goto label_00089E07;
    cpu->eax = cpu->edi + 2u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00089E07:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ebx != 0u) goto label_00089E31;
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x489E14u));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x489E1Bu));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x489E28u));
    cpu->esp += 0x1Cu;
    label_00089E31:
    cpu->eax = *(uint16_t*)(cpu->esi + 0x20C98u);
    cpu->ecx = 0x190u;
    if ((int16_t)(cpu->eax & 0xFFFFu) < (int16_t)(cpu->ecx & 0xFFFFu)) goto label_00089E68;
    lift_push32(cpu, (uintptr_t)"Too many files in quickfile"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489E51u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x489E51u));
    cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"Too many files in quickfile\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489E5Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x489E5Eu));
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00089E68:
    cpu->edx = (int16_t)((cpu->eax & 0xFFFFu));
    *(uint32_t*)(cpu->esi + (cpu->edx * 8u)) = cpu->ebx;
    cpu->edx = 0x47u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\QuickFile.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489E7Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x489E7Du));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489E83u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x489E83u));
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->esi + 0x20C98u));
    *(uint32_t*)(cpu->esi + (cpu->ecx * 8u) + 4u) = cpu->eax;
    cpu->edx = (int16_t)(*(uint16_t*)(cpu->esi + 0x20C98u));
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->edx * 8u) + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x489E9Eu));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x489EA5u));
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x489EAEu));
    cpu->esp += 0x20u;
    if (cpu->eax != 0u) goto label_00089EBF;
    cpu->eax = cpu->ebp;
    goto label_00089EC0;
    label_00089EBF:
    ++cpu->eax;
    label_00089EC0:
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->esi + 0x20C98u));
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xC80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489ED6u)); sfera_sub_004311D0(cpu, LIFT_CODE_TOKEN_VA(0x489ED6u));
    ++*(uint16_t*)(cpu->esi + 0x20C98u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00489EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xC80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489F05u)); sfera_sub_00430F20(cpu, LIFT_CODE_TOKEN_VA(0x489F05u));
    if (cpu->eax != 0xFFFFFFFFu) goto label_00089F10;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00089F10:
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->eax * 8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax + 1u;
    *(uint16_t*)(cpu->edx) = cpu->ecx & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->eax * 8u) + 4u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00489F30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xD44u;
    lift_push32(cpu, 0x12Cu);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0x20u);
    cpu->ecx = cpu->ebx + 0xC80u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489F85u)); sfera_sub_00430F60(cpu, LIFT_CODE_TOKEN_VA(0x489F85u));
    cpu->eax = 0u;
    *(uint16_t*)(cpu->ebx + 0x20C98u) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xD54u);
    cpu->edx = cpu->esp + 0x140u;
    *(uint32_t*)(cpu->esp + 0xD4Cu) = 0u;
    cpu->edx -= cpu->eax;
    label_00089FB0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00089FB0;
    cpu->eax = cpu->esp + 0x140u;
    --cpu->eax;
    cpu->edx = cpu->eax + 1u;
    label_00089FC5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00089FC5;
    cpu->eax -= cpu->edx;
    if (*(uint8_t*)(cpu->esp + cpu->eax + 0x140u) == 0x5Cu) goto label_00089FF2;
    cpu->edi = cpu->esp + 0x140u;
    --cpu->edi;
    label_00089FE0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00089FE0;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"\\"));
    *(uint16_t*)(cpu->edi) = cpu->ecx & 0xFFFFu;
    label_00089FF2:
    cpu->eax = 0u;
    label_0008A000:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x140u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x940u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0008A000;
    cpu->eax = cpu->esp + 0x940u;
    --cpu->eax;
    label_0008A020:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0008A020;
    cpu->edx = *(uint32_t*)((uintptr_t)"*.mbc");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"*.mbc") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = cpu->esp + 0x18u;
    *(uint16_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFFFu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x944u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x48A048u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp == 0xFFFFFFFFu) goto label_0008A16E;
    cpu->eax = 0u;
    label_0008A060:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x140u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x540u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0008A060;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->edx = cpu->eax;
    label_0008A080:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0008A080;
    cpu->edi = cpu->esp + 0x540u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0008A091:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0008A091;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x544u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A0BDu)); sfera_sub_00489DE0(cpu, LIFT_CODE_TOKEN_VA(0x48A0BDu));
    cpu->ebx = native_function_address32(&::_findnext64i32);
    cpu->eax = cpu->esp + 0x18u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findnext64i32)))(cpu->ebp, cpu->eax);

    if (cpu->eax != 0u) goto label_0008A15E;
    label_0008A0E0:
    cpu->eax = 0u;
    label_0008A0F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x140u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x540u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0008A0F0;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->edx = cpu->eax;
    label_0008A110:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0008A110;
    cpu->edi = cpu->esp + 0x540u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0008A121:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0008A121;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x544u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A14Fu)); sfera_sub_00489DE0(cpu, LIFT_CODE_TOKEN_VA(0x48A14Fu));
    cpu->eax = cpu->esp + 0x18u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findnext64i32)))(cpu->ebp, cpu->eax);

    if (cpu->eax == 0u) goto label_0008A0E0;
    label_0008A15E:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x48A15Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    goto label_0008A170;
    label_0008A16E:
    cpu->eax = cpu->ebx;
    label_0008A170:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD3Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048A1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048A1C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp <= 0) goto label_0008A203;
    label_0008A1D6:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (uint32_t)sfera_buffer_cipher_key(cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    *(uint8_t*)(cpu->esp + 0x13u) = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (uint16_t)((int16_t)(int8_t)cpu->eax * (int16_t)(int8_t)(*(uint8_t*)(cpu->esp + 0x13u)));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    ++cpu->esi;
    if ((int32_t)cpu->ecx < (int32_t)cpu->ebp) goto label_0008A1D6;
    label_0008A203:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048A210(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edx)));
    cpu->esi = 0u;
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->edx + 4u))));
    *(float*)(cpu->esp + 8u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->edx + 8u))));
    x87_v0 = (double)*(float*)(cpu->ecx);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->ecx + 4u)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 8u); x87_v4 = x87_v3;
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->ecx + 8u)));
    x87_v0 = x87_v0 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v3; 
    x87_v3 = (double)-1.1754943508222875e-38f;
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v4; const double lift_right=x87_v3; x87_v3=x87_v4;  if (!(lift_left<lift_right)) goto label_0008A2E8; }
    x87_v4 = (double)*(float*)(cpu->ecx);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->edx)));
    x87_v5 = (double)*(float*)(cpu->ecx + 4u);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->edx + 4u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->edx + 8u);
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->ecx + 8u)));
    x87_v4 = x87_v4 + x87_v5; 
    x87_v4 = (x87_v4) + (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = x87_v4; 
    x87_v4 = 0.0;
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v5; const double lift_right=x87_v4; x87_v4=x87_v5;  if (!(lift_left>=lift_right)) goto label_0008A2E6; }
    x87_v5 = x87_v4;
    x87_v5 = (x87_v5) + (x87_v3);
    { const double lift_left=x87_v5; const double lift_right=0.0;  if (!(lift_left<lift_right)) goto label_0008A2E6; }
    x87_v3 = x87_v4 / x87_v3; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esi + 1u;
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->esp + 0xCu) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edx);
    x87_v4 = (double)*(float*)(cpu->esp + 0xCu); x87_v5 = x87_v4;
    x87_v1 = x87_v1 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    x87_v1 = x87_v4 - x87_v1; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->ecx) = x87_v3; 
    x87_v3 = x87_v1;
    x87_v2 = x87_v2 * x87_v3; 
    x87_v2 = (((double)*(float*)(cpu->edx + 4u))) - (x87_v2);
    *(float*)(cpu->ecx + 4u) = x87_v2; 
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (((double)*(float*)(cpu->edx + 8u))) - (x87_v0);
    *(float*)(cpu->ecx + 8u) = x87_v0; 
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008A2E6:
    x87_v3 = x87_v4; 
    label_0008A2E8:
    x87_v3 = x87_v3; 
    cpu->eax = cpu->esi;
    x87_v1 = x87_v2; 
    cpu->esi = lift_pop32(cpu);
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048A300(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x10u;
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    label_0008A326:
    cpu->esi = sfera_clip_plane_order(cpu->eax);
    cpu->esi <<= 4u;
    cpu->esi += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = 0u;
    cpu->ebp = 0u;
    if ((int32_t)(cpu->edx) < (int32_t)(4u)) goto label_0008A3E2;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->edx + 0xFFFFFFFCu;
    cpu->ebx >>= 2u;
    cpu->edi += 0x14u;
    ++cpu->ebx;
    cpu->ebp = cpu->ebx * 4u;
    label_0008A351:
    x87_v1 = (double)*(float*)(cpu->edi + 0xFFFFFFF0u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 4u)));
    x87_v2 = (double)*(float*)(cpu->edi + 0xFFFFFFECu);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0xFFFFFFF4u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 8u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 0xCu)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<lift_right)) goto label_0008A373; }
    ++cpu->ecx;
    label_0008A373:
    x87_v1 = (double)*(float*)(cpu->edi + 0xFFFFFFFCu);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 4u)));
    x87_v2 = (double)*(float*)(cpu->edi + 0xFFFFFFF8u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + 8u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 0xCu)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<lift_right)) goto label_0008A394; }
    ++cpu->ecx;
    label_0008A394:
    x87_v1 = (double)*(float*)(cpu->edi + 8u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 4u)));
    x87_v2 = (double)*(float*)(cpu->edi + 4u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0xCu);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 8u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 0xCu)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<lift_right)) goto label_0008A3B6; }
    ++cpu->ecx;
    label_0008A3B6:
    x87_v1 = (double)*(float*)(cpu->edi + 0x14u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 4u)));
    x87_v2 = (double)*(float*)(cpu->edi + 0x10u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0x18u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi + 8u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 0xCu)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<lift_right)) goto label_0008A3D8; }
    ++cpu->ecx;
    label_0008A3D8:
    cpu->edi += 0x30u;
    if ((--cpu->ebx) != 0u) goto label_0008A351;
    label_0008A3E2:
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edx) goto label_0008A41D;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->ebp + (cpu->ebp * 2u);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->edi + (cpu->eax * 4u) + 8u;
    cpu->ebx -= cpu->ebp;
    label_0008A3F6:
    x87_v1 = (double)*(float*)(cpu->edi + 0xFFFFFFFCu);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 4u)));
    x87_v2 = (double)*(float*)(cpu->edi + 0xFFFFFFF8u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esi)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + 8u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 0xCu)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<lift_right)) goto label_0008A417; }
    ++cpu->ecx;
    label_0008A417:
    cpu->edi += 0xCu;
    if ((--cpu->ebx) != 0u) goto label_0008A3F6;
    label_0008A41D:
    if (cpu->ecx == cpu->edx) goto label_0008A452;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)(cpu->eax) < (int32_t)(4u)) goto label_0008A326;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = x87_v0; 
    cpu->edi = lift_pop32(cpu);
    cpu->eax = -cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->eax += 2u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008A452:
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048A460(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    cpu->esp -= 0xCu;
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ecx + 8u)));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->ecx))) - (((double)*(float*)(cpu->edx))));
    x87_v0 = (double)*(float*)(cpu->edx);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->ecx + 8u)));
    x87_v1 = (double)*(float*)(cpu->ecx);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->edx + 8u)));
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi + 8u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi);
    x87_v3 = (double)*(float*)(cpu->esp + 8u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v2 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0xCu); x87_v4 = x87_v3;
    x87_v2 = x87_v2 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edi + 8u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->edi);
    x87_v0 = x87_v0 * x87_v4; 
    x87_v0 = x87_v0 + x87_v3; 
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u); x87_v2 = x87_v1;
    x87_v3 = 0.0;
    x87_v4 = x87_v3;
    { const double lift_left=x87_v4; const double lift_right=x87_v2;  x87_v2=x87_v3;  if (lift_left==lift_right) goto label_0008A541; }
    x87_v3 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v4 = x87_v3;
    x87_v5 = x87_v2;
    { const double lift_left=x87_v5; const double lift_right=x87_v4;   if (lift_left==lift_right) goto label_0008A53F; }
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (!(lift_left<lift_right)) goto label_0008A51A; }
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (!(lift_left<lift_right)) goto label_0008A518; }
    x87_v2 = x87_v3; 
    cpu->edi = lift_pop32(cpu);
    x87_v1 = x87_v2; 
    cpu->eax |= 0xFFFFFFFFu;
    x87_v1 = x87_v1; 
    cpu->esi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008A518:
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    label_0008A51A:
    { const double lift_left=x87_v3; const double lift_right=x87_v2;  if (!(lift_left>lift_right)) goto label_0008A541; }
    { const double lift_left=x87_v2; const double lift_right=x87_v1; x87_v1=x87_v2;  if (!(lift_left<lift_right)) goto label_0008A543; }
    x87_v1 = x87_v1; 
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008A53F:
    x87_v1 = x87_v3; 
    label_0008A541:
    x87_v1 = x87_v2; 
    label_0008A543:
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->edi + 8u))) - (((double)*(float*)(cpu->esi + 8u))));
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi))) - (((double)*(float*)(cpu->edi))));
    x87_v2 = (double)*(float*)(cpu->esi + 8u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi)));
    x87_v3 = (double)*(float*)(cpu->esi);
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->edi + 8u)));
    x87_v2 = x87_v2 - x87_v3; 
    *(float*)(cpu->esp + 0x10u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ecx);
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v5 = x87_v4;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->ecx + 8u)));
    x87_v2 = x87_v2 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u); x87_v6 = x87_v5;
    x87_v2 = x87_v2 + x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->edx);
    x87_v5 = (x87_v5) * (x87_v3);
    x87_v6 = x87_v4;
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->edx + 8u)));
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (x87_v2);
    *(float*)(cpu->esp + 0x18u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v6 = x87_v5;
    x87_v7 = x87_v1;
    { const double lift_left=x87_v7; const double lift_right=x87_v6;   if (lift_left==lift_right) goto label_0008A615; }
    { const double lift_right=(double)*(float*)(cpu->esp + 0x18u); const double lift_left=x87_v1; if (lift_left==lift_right) goto label_0008A615; }
    { const double lift_left=x87_v5; const double lift_right=x87_v1; if (!(lift_left<lift_right)) goto label_0008A5E8; }
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v5; const double lift_right=((double)*(float*)(cpu->esp + 0x18u)); if (!(lift_left>lift_right)) goto label_0008A5E6; }
    x87_v5 = x87_v5; 
    cpu->edi = lift_pop32(cpu);
    x87_v3 = x87_v4; 
    cpu->eax |= 0xFFFFFFFFu;
    x87_v3 = x87_v3; 
    cpu->esi = lift_pop32(cpu);
    x87_v2 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008A5E6:
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    label_0008A5E8:
    { const double lift_left=x87_v5; const double lift_right=x87_v1;  if (!(lift_left>lift_right)) goto label_0008A61B; }
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v4; const double lift_right=((double)*(float*)(cpu->esp + 0x18u)); if (!(lift_left<lift_right)) goto label_0008A619; }
    x87_v4 = x87_v4; 
    cpu->edi = lift_pop32(cpu);
    x87_v3 = x87_v3; 
    cpu->eax = 1u;
    x87_v1 = x87_v2; 
    cpu->esi = lift_pop32(cpu);
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008A615:
    x87_v5 = x87_v5; 
    goto label_0008A61B;
    label_0008A619:
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    label_0008A61B:
    x87_v5 = x87_v4;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esp + 8u)));
    x87_v6 = x87_v3;
    x87_v6 = (x87_v6) * (x87_v0);
    x87_v5 = x87_v5 - x87_v6; 
    *(float*)(cpu->esp + 0x18u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x18u); x87_v6 = x87_v5;
    { const double lift_left=x87_v6; const double lift_right=x87_v1;  x87_v1=x87_v5;  if (lift_left!=lift_right) goto label_0008A653; }
    x87_v3 = x87_v4; 
    cpu->edi = lift_pop32(cpu);
    x87_v3 = x87_v3; 
    cpu->eax = 0xFFFFFFFEu;
    x87_v2 = x87_v2; 
    cpu->esi = lift_pop32(cpu);
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008A653:
    x87_v5 = 1.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v1 = x87_v5 / x87_v1; 
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v4; 
    x87_v4 = x87_v2;
    x87_v0 = x87_v0 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 4u); x87_v5 = x87_v4;
    x87_v1 = x87_v1 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v4 - x87_v1; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u); x87_v5 = x87_v4;
    x87_v1 = x87_v1 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->eax) = x87_v4; 
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->ecx + 4u);
    x87_v0 = x87_v0 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp)));
    x87_v0 = x87_v0 - x87_v2; 
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->eax + 8u) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048A6A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi) == cpu->edi) goto label_0008A6C6;
    cpu->edx = 0x14Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A6B9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48A6B9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A6C1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48A6C1u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    label_0008A6C6:
    if (*(uint32_t*)(cpu->esi + 4u) == cpu->edi) goto label_0008A6E9;
    cpu->edx = 0x151u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A6DAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48A6DAu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A6E3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48A6E3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    label_0008A6E9:
    if (*(uint32_t*)(cpu->esi + 0xCu) == cpu->edi) goto label_0008A70C;
    cpu->edx = 0x157u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A6FDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48A6FDu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A706u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48A706u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edi;
    label_0008A70C:
    if (*(uint32_t*)(cpu->esi + 0x10u) == cpu->edi) goto label_0008A72F;
    cpu->edx = 0x15Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A720u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48A720u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A729u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48A729u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    label_0008A72F:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048A740(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13;
 bool lift_test[2]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5, x87_p6, x87_p7;
    bool lift_cmp[2];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x1A8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebx);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ebx;
    if (cpu->edi == cpu->ebp) goto label_0008B1DD;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48A76Bu)); sfera_sub_00456010(cpu, LIFT_CODE_TOKEN_VA(0x48A76Bu));
    cpu->esi = cpu->eax;
    if (((double)*(float*)(cpu->esi + 0xCu))>(1000.0)) goto label_0008B1DD;
    x87_v0 = (double)*(float*)(cpu->esi + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    x87_v0 = (x87_v0) + (1.5707964897155762);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    *(double*)(cpu->esp + 0x40u) = x87_v0;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.z);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edx;
    x87_v1 = (x87_v1) * (0.5);
    *(double*)(cpu->esp + 0xA0u) = x87_v1;
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x48u);
    *(double*)(cpu->esp + 0x48u) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0x48u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x48u) = (((*(double*)(cpu->esp + 0x40u))) - (*(double*)(cpu->esp + 0xA0u)));
    x87_v0 = (double)*(float*)(cpu->esp + 0x48u);
    *(double*)(cpu->esp + 0x40u) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0x40u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x4Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    x87_v1 = 60.0;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v0 = (x87_v0) * (x87_v1);
    *(uint32_t*)(cpu->esp + 0xACu) = cpu->eax;
    x87_v2 = (double)*(float*)(cpu->esp + 0xACu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esp + 0xB4u) = cpu->edx;
    x87_v0 = x87_v0 + x87_v2; 
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->eax;
    std::swap(x87_v1, x87_v0);
    *(uint32_t*)(cpu->esp + 0x9Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xB0u) = cpu->ecx;
    *(float*)(cpu->esp + 0xACu) = x87_v1; 
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->ecx;
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0xB4u)));
    *(float*)(cpu->esp + 0xB4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x4Cu);
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x94u)));
    *(float*)(cpu->esp + 0x94u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x48u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x9Cu)));
    *(float*)(cpu->esp + 0x9Cu) = x87_v0; 
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x48A892u));
    cpu->eax&=0x80000001u; lift_test[0]=cpu->eax==0u;
    if (((cpu->eax)&0x80000000u)==0u) goto label_0008A8A4;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    ++cpu->eax; lift_test[0]=cpu->eax == 0u;
label_0008A8A4:
    if (lift_test[0]) goto label_0008B1DD;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebp;
    if (*(uint32_t*)(cpu->ebx + 8u) <= cpu->ebp) goto label_0008B1DD;
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    cpu->eax = cpu->edi + 0xCu;
    *(uint32_t*)(cpu->esp + 0xA0u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    goto label_0008A8D3;
label_0008A8CB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
label_0008A8D3:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->edi + 8u);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ecx;
    *(float*)(cpu->esp + 0x80u) = x87_v0;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->edx;
    *(float*)(cpu->esp + 0x74u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ebp;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x48A90Cu));
    cpu->eax&=0x80000001u; lift_test[1]=cpu->eax==0u;
    if (((cpu->eax)&0x80000000u)==0u) goto label_0008A91E;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    ++cpu->eax; lift_test[1]=cpu->eax == 0u;
label_0008A91E:
    if (lift_test[1]) goto label_0008B1AC;
    x87_v0 = (double)*(float*)(cpu->esp + 0x70u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x7Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    x87_v2 = x87_v1;
    cpu->eax += *(uint32_t*)(cpu->esp + 0xA0u);
    x87_v0 = x87_v0 - x87_v2; 
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    std::swap(x87_v1, x87_v0);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(float*)(cpu->esp + 0xE8u) = x87_v1; 
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->esp + 0x13Cu) = cpu->edx;
    x87_v2 = x87_v1;
    *(uint32_t*)(cpu->esp + 0x138u) = cpu->ecx;
    x87_v2 = (x87_v2) - (x87_v1);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    *(uint32_t*)(cpu->esp + 0x140u) = cpu->eax;
    *(float*)(cpu->esp + 0xECu) = x87_v2; 
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    x87_v2 = (double)*(float*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    x87_v3 = (double)*(float*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    x87_v4 = x87_v3;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    x87_v2 = x87_v2 - x87_v4; 
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebp;
    std::swap(x87_v3, x87_v2);
    *(float*)(cpu->esp + 0xF0u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0xE8u);
    x87_v4 = 0.5;
    x87_v3 = (x87_v3) * (x87_v4);
    std::swap(x87_v4, x87_v3);
    *(float*)(cpu->esp + 0x124u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0xECu);
    x87_v4 = (x87_v4) * (x87_v3);
    *(float*)(cpu->esp + 0x128u) = x87_v4; 
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esp + 0xF0u)));
    *(float*)(cpu->esp + 0x12Cu) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x124u);
    x87_v0 = x87_v0 + x87_v3; 
    std::swap(x87_v2, x87_v0);
    *(float*)(cpu->esp + 0x100u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x128u);
    x87_v2 = (x87_v2) + (x87_v1);
    *(float*)(cpu->esp + 0x104u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x12Cu);
    x87_v0 = x87_v0 + x87_v2; 
    std::swap(x87_v1, x87_v0);
    *(float*)(cpu->esp + 0x108u) = x87_v1; 
    *(float*)(cpu->esp + 0x118u) = ((((double)*(float*)(cpu->esp + 0x100u))) - (((double)*(float*)(cpu->esp + 0x50u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x104u);
    x87_v1 = (x87_v1) - (x87_v0);
    *(float*)(cpu->esp + 0x11Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x120u) = ((((double)*(float*)(cpu->esp + 0x108u))) - (((double)*(float*)(cpu->esp + 0x58u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x13Cu);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x11Cu)));
    x87_v2 = (double)*(float*)(cpu->esp + 0x138u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x118u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x140u);
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x120u)));
    x87_v1 = x87_v1 + x87_v2; 
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u); x87_v2 = x87_v1;
    x87_v3 = 0.0;
    x87_v4 = x87_v3;
    { const double lift_left=x87_v4; const double lift_right=x87_v2;  x87_v2=x87_v3;  if (lift_left!=lift_right) goto label_0008AA9C; }
    x87_v1 = x87_v2; 
    goto label_0008B1B0;
label_0008AA9C:
    x87_v0 = x87_v2; 
    cpu->ecx = cpu->esp + 0xACu;
    lift_cmp[0]=x87_v1>x87_v0;
    cpu->edx = cpu->esp + 0x50u;
    if (!lift_cmp[0]) goto label_0008AAD1;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x7Cu;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48AAC9u)); sfera_sub_0048A460(cpu, LIFT_CODE_TOKEN_VA(0x48AAC9u));
    cpu->esi = cpu->eax;
    cpu->eax = cpu->esp + 0x28u;
    goto label_0008AAEE;
label_0008AAD1:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x7Cu;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48AAE8u)); sfera_sub_0048A460(cpu, LIFT_CODE_TOKEN_VA(0x48AAE8u));
    cpu->esi = cpu->eax;
    cpu->eax = cpu->esp + 0x34u;
label_0008AAEE:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x98u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x7Cu;
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48AB0Cu)); sfera_sub_0048A460(cpu, LIFT_CODE_TOKEN_VA(0x48AB0Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 2u);
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48AB1Eu)); sfera_sub_0048A300(cpu, LIFT_CODE_TOKEN_VA(0x48AB1Eu));
    if (cpu->esi == 0u) goto label_0008AB2E;
    if (cpu->edi == 0u) goto label_0008AB2E;
    if (cpu->eax == 0u) goto label_0008B1AC;
label_0008AB2E:
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0;
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->eax != 1u) goto label_0008AC0D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x170u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x16Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = cpu->esp + 0xB8u;
    *(uint32_t*)(cpu->esp + 0x15Cu) = cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x160u;
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x170u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ABA6u)); sfera_sub_0048A210(cpu, LIFT_CODE_TOKEN_VA(0x48ABA6u));
    if (cpu->eax == 0u) goto label_0008ABCB;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xB8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xBCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xC0u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
label_0008ABCB:
    cpu->ecx = cpu->esp + 0xB8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x160u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x170u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[5][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ABECu)); sfera_sub_0048A210(cpu, LIFT_CODE_TOKEN_VA(0x48ABECu));
    if (cpu->eax == 0u) goto label_0008AC0D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xC0u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xBCu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
label_0008AC0D:
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x68u) = 1u;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x88u) = x87_v0; 
    *(float*)(cpu->esp + 0x90u) = ((((double)*(float*)(cpu->esp + 0x3Cu))) - (((double)*(float*)(cpu->esp + 0x30u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x90u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x88u);
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->esp + 0x40u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    if ((x87_v2)!=(x87_v1)) goto label_0008AC7A;
    goto label_0008B1AC;
label_0008AC7A:
    *(float*)(cpu->esp + 0x40u) = (double)(1.0);
    if (!(((double)40.0f)<(x87_v0))) goto label_0008AC9B;
    x87_v1 = x87_v0;
    x87_v1 = (40.0) / (x87_v1);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
label_0008AC9B:
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x88u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    std::swap(x87_v1, x87_v0);
    *(float*)(cpu->esp + 0x88u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x90u)));
    *(float*)(cpu->esp + 0x90u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x50u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x174u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x58u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x17Cu) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v0 = x87_v0 - x87_v2; 
    std::swap(x87_v1, x87_v0);
    *(float*)(cpu->esp + 0x18Cu) = x87_v1; 
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x194u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x194u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x18Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x17Cu);
    *(double*)(cpu->esp + 0x130u) = x87_v2;
     x87_v2 = (double)*(float*)(cpu->esp + 0x174u);
    *(double*)(cpu->esp + 0x1B0u) = x87_v2;
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = *(double*)(cpu->esp + 0x1B0u);
    x87_v0 = (x87_v0) * (x87_v0);
    x87_v1 = *(double*)(cpu->esp + 0x130u);
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    { const double lift_right=(double)*(float*)(cpu->esp + 0x1Cu); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (!(lift_left<lift_right)) goto label_0008ADB2; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
label_0008ADB2:
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    cpu->ebp = 0u;
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    std::swap(x87_v1, x87_v0);
    *(float*)(cpu->esp + 0x180u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x30u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    std::swap(x87_v2, x87_v1);
    *(float*)(cpu->esp + 0x188u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x180u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x40u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    std::swap(x87_v3, x87_v2);
    *(float*)(cpu->esp + 0x198u) = x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x188u)));
    *(float*)(cpu->esp + 0x1A0u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x198u);
    x87_v0 = x87_v0 + x87_v2; 
    std::swap(x87_v1, x87_v0);
    *(float*)(cpu->esp + 0x1A4u) = x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x1A0u)));
    *(float*)(cpu->esp + 0x1ACu) = x87_v0; 
label_0008AE24:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x6Cu);
    x87_v0 = 0.0;
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xCu);
    lift_cmp[1]=x87_v0<(((double)*(float*)(cpu->esi + cpu->ebp + 0x34u)));
    cpu->esi += cpu->ebp;
    if (lift_cmp[1]) goto label_0008B19D;
    if (*(uint32_t*)(cpu->esp + 0x68u) == 0u) goto label_0008B1AC;
    cpu->edi = native_function_address32(&::rand);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x1Cu) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) / (32767.0));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) / (32767.0));
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = 0.10000000149011612;
     value_3 = x87_p1; value_4 = x87_p0; { const double lift_left=value_3; const double lift_right=value_4; if (!(lift_left>lift_right)) { value_0 = value_4; goto label_0008AE98; } }
    value_5 = (value_4) + (value_3);
    *(float*)(cpu->esp + 0x1Cu) = value_5; 
    value_6 = (double)*(float*)(cpu->esp + 0x1Cu);
     value_0 = value_6;
label_0008AE98:
    if (!((value_0)>(0.8999999761581421))) goto label_0008AEB3;
    value_7 = value_0 - value_3; 
    *(float*)(cpu->esp + 0x1Cu) = value_7; 
    value_8 = (double)*(float*)(cpu->esp + 0x1Cu);
     value_1 = value_8; goto label_0008AEB5;
label_0008AEB3:
      value_1 = value_0;
label_0008AEB5:
    x87_p0 = (double)*(float*)(cpu->esp + 0x1A4u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x28u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = value_1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x5Cu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x1ACu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x30u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    std::swap(x87_p1, x87_p0);
    value_9 = value_1 * x87_p1; 
    value_10 = value_9 + x87_p0; 
    *(float*)(cpu->esp + 0x64u) = value_10; 
    value_11 = (double)*(float*)(cpu->esp + 0x14u);
    *(double*)(cpu->esp + 0x130u) = value_11;
     cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_p0 = (x87_p0) / (32767.0);
    x87_p0 = (*(double*)(cpu->esp + 0x130u)) - (x87_p0);
    x87_p0 = (x87_p0) * (10.0);
    x87_p1 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p1 = (x87_p1) - (2.0);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x60u) = x87_p0; 
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->eax&=0x80000007u;
    if (((cpu->eax)&0x80000000u)==0u) goto label_0008AF2D;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFF8u;
    ++cpu->eax;
label_0008AF2D:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) + (20.0));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) * (0.5));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u); x87_p1 = x87_p0;
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esp + 0x88u)));
    *(float*)(cpu->esp + 0x14u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x150u) = x87_p1;
    x87_p2 = x87_p0;
    x87_p3 = 0.0;
    x87_p2 = (x87_p2) * (x87_p3);
    std::swap(x87_p3, x87_p2);
    *(float*)(cpu->esp + 0x14u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x154u) = x87_p3;
    x87_p4 = x87_p0;
    x87_p4 = (x87_p4) * (((double)*(float*)(cpu->esp + 0x90u)));
    *(float*)(cpu->esp + 0x14u) = x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x158u) = x87_p4;
    x87_p5 = (double)*(float*)(cpu->esp + 0x150u);
    x87_p6 = (double)*(float*)(cpu->esp + 0x5Cu); x87_p7 = x87_p6;
    x87_p5 = x87_p5 + x87_p7; 
    std::swap(x87_p6, x87_p5);
    *(float*)(cpu->esp + 0xDCu) = x87_p6; 
    *(float*)(cpu->esp + 0xE0u) = ((((double)*(float*)(cpu->esp + 0x154u))) + (((double)*(float*)(cpu->esp + 0x60u))));
    *(float*)(cpu->esp + 0xE4u) = ((((double)*(float*)(cpu->esp + 0x158u))) + (((double)*(float*)(cpu->esp + 0x64u))));
    std::swap(x87_p5, x87_p1);
    *(float*)(cpu->esp + 0xC4u) = x87_p5; 
    std::swap(x87_p4, x87_p3);
    *(float*)(cpu->esp + 0xC8u) = x87_p4; 
    *(float*)(cpu->esp + 0xCCu) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0xC4u);
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x5Cu) = x87_p2; 
    *(float*)(cpu->esp + 0x60u) = ((((double)*(float*)(cpu->esp + 0x60u))) - (((double)*(float*)(cpu->esp + 0xC8u))));
    *(float*)(cpu->esp + 0x64u) = ((((double)*(float*)(cpu->esp + 0x64u))) - (((double)*(float*)(cpu->esp + 0xCCu))));
    x87_p2 = x87_p0;
    x87_p2 = -x87_p2;
    *(float*)(cpu->esp + 0x40u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x5Cu);
    x87_p2 = (x87_p2) + (x87_p1);
    *(float*)(cpu->esp + 0x14u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x144u) = x87_p2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x144u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    x87_p4 = x87_p3;
    x87_p5 = (double)*(float*)(cpu->esp + 0x60u); x87_p6 = x87_p5;
    x87_p4 = x87_p4 + x87_p6; 
    std::swap(x87_p5, x87_p4);
    *(float*)(cpu->esp + 0x148u) = x87_p5; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x148u);
    x87_p5 = (double)*(float*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    x87_p5 = (x87_p5) + (x87_p1);
    *(float*)(cpu->esp + 0x14u) = x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x14Cu) = x87_p5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14Cu);
    std::swap(x87_p5, x87_p2);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    *(float*)(cpu->esp + 0xD0u) = x87_p5; 
    x87_p4 = (x87_p4) + (x87_p0);
    *(float*)(cpu->esp + 0xD4u) = x87_p4; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xD0u);
    std::swap(x87_p3, x87_p2);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xD4u);
    *(float*)(cpu->esp + 0xD8u) = x87_p3; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xD8u);
    x87_p3 = (double)*(float*)(cpu->esp + 0xDCu);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    x87_p3 = (x87_p3) + (x87_p1);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    *(float*)(cpu->esp + 0x14u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0xF4u) = x87_p3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xF4u);
    x87_p4 = (double)*(float*)(cpu->esp + 0xE0u);
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    x87_p5 = x87_p4;
    x87_p0 = x87_p0 + x87_p5; 
    std::swap(x87_p4, x87_p0);
    *(float*)(cpu->esp + 0xF8u) = x87_p4; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xF8u);
    x87_p4 = (double)*(float*)(cpu->esp + 0xE4u);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ecx;
    x87_p1 = x87_p1 + x87_p4; 
    std::swap(x87_p3, x87_p1);
    *(float*)(cpu->esp + 0x14u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0xFCu) = x87_p3;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xFCu);
    std::swap(x87_p3, x87_p1);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edx;
    *(float*)(cpu->esp + 0x10Cu) = x87_p3; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10Cu);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x110u) = x87_p1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x110u);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ecx;
    *(float*)(cpu->esp + 0x114u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x114u);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->eax&=0x8000001Fu;
    if (((cpu->eax)&0x80000000u)==0u) goto label_0008B164;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFE0u;
    ++cpu->eax;
label_0008B164:
    cpu->eax += 0x32u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esi + 0x30u) = x87_p0;
    *(float*)(cpu->esi + 0x34u) = x87_p0; 
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->ebx + 0x14u)); cpu->eax = n / d; cpu->edx = n % d; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
     value_12 = x87_p0; if ((int32_t)cpu->edx >= 0) { value_2 = value_12; goto label_0008B196; }
    value_13 = (value_12) + (((double)4294967296.0f)); value_2 = value_13;
label_0008B196:
    --*(uint32_t*)(cpu->esp + 0x68u);
    *(float*)(cpu->esi + 0x38u) = value_2; 
label_0008B19D:
    cpu->ebp += 0x3Cu;
    if (cpu->ebp < 0x1770u) goto label_0008AE24;
label_0008B1AC:
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
label_0008B1B0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->esp + 0xA0u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0xA0u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    cpu->eax = 0x18u;
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 8u)) goto label_0008A8CB;
    label_0008B1DD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048B1F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (cpu->ebp == 0u) goto label_0008B5D0;
    cpu->edx = 0x106u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B210u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48B210u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = 0xCu;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B229u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48B229u));
    cpu->esp += 4u;
    cpu->edx = 0x107u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B23Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48B23Eu));
    lift_push32(cpu, 0x1770u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B248u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48B248u));
    x87_v0 = (double)-1.0f;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    cpu->eax = 0u;
    label_0008B256:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->ecx + 0x34u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->edx + 0x70u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->ecx + 0xACu) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->edx + 0xE8u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->ecx + 0x124u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->edx + 0x160u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->ecx + 0x19Cu) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->edx + 0x1D8u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->ecx + 0x214u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    *(float*)(cpu->eax + cpu->edx + 0x250u) = x87_v0;
    cpu->eax += 0x258u;
    if (cpu->eax < 0x1770u) goto label_0008B256;
    lift_push32(cpu, cpu->edi);
    x87_v0 = x87_v0; 
    x87_v0 = 0.0;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 8u) <= cpu->edi) goto label_0008B3DC;
    x87_v0 = (x87_v0) * (x87_v0);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    *(double*)(cpu->esp + 0x18u) = x87_v0;
    label_0008B2E0:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v2 = x87_v1;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    x87_v0 = x87_v0 * x87_v2; 
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esp + 0x34u)));
    x87_v0 = x87_v0 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x38u)));
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v1 = (x87_v1) + (*(double*)(cpu->esp + 0x18u));
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (lift_left!=lift_right) goto label_0008B380; }
    x87_v0 = x87_v0; 
    x87_v0 = 1.0;
    goto label_0008B384;
    label_0008B380:
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    label_0008B384:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    ++cpu->edi;
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->ebp += 0x18u;
    x87_v2 = x87_v1;
    cpu->ebx += 0xCu;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v1 = 0.0;
    *(uint32_t*)(cpu->eax + cpu->ebx + 0xFFFFFFF4u) = cpu->ecx;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->ebx + 0xFFFFFFF8u) = cpu->edx;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax + cpu->ebx + 0xFFFFFFFCu) = cpu->ecx;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 8u)) goto label_0008B2E0;
    cpu->ebx = lift_pop32(cpu);
    goto label_0008B3DE;
    label_0008B3DC:
    x87_v0 = x87_v0; 
    label_0008B3DE:
    cpu->edx = 0x126u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B3EDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48B3EDu));
    lift_push32(cpu, 0x280u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B3F7u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48B3F7u));
    x87_v0 = 0.0;
    x87_v1 = 0.25;
    cpu->esp += 4u;
    x87_v0 = (x87_v0) * (x87_v1);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 0x14u) = 0x10u;
    cpu->eax = 0u;
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    cpu->edi = lift_pop32(cpu);
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) + (x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v2; 
    x87_v2 = (double)0.25f;
    x87_v3 = (double)0.5f;
    x87_v4 = (double)0.75f;
    label_0008B437:
    cpu->edx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    x87_v5 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->edx >= 0) goto label_0008B44B;
    x87_v5 = (x87_v5) + (((double)4294967296.0f));
    label_0008B44B:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 8u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 8u) = x87_v5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v6 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0xCu) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(float*)(cpu->eax + cpu->edx + 0x10u) = (double)*(float*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(float*)(cpu->eax + cpu->edx + 0x14u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(float*)(cpu->eax + cpu->edx + 0x18u) = (double)*(float*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v6 = (x87_v6) + (x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0x1Cu) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x20u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x24u) = x87_v6; 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 8u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x30u) = x87_v5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v6 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0x34u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x38u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x3Cu) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x40u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    x87_v6 = (x87_v6) + (x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0x44u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x48u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x4Cu) = x87_v6; 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 8u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x58u) = x87_v5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v6 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0x5Cu) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x60u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x64u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x68u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    x87_v6 = (x87_v6) + (x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0x6Cu) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0x70u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    ++cpu->ecx;
    *(float*)(cpu->eax + cpu->edx + 0x74u) = x87_v6; 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    cpu->eax += 0xA0u;
    *(float*)(cpu->esp + 8u) = x87_v5; 
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFE0u) = x87_v4;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v5 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFE4u) = x87_v5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v6 = 1.0;
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFE8u) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFECu) = x87_v6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFF0u) = x87_v6; 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    x87_v5 = (x87_v5) + (x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFF4u) = x87_v5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFF8u) = x87_v5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFFCu) = x87_v5; 
    if (cpu->ecx < 4u) goto label_0008B437;
    x87_v0 = x87_v4; 
    x87_v3 = x87_v3; 
    x87_v0 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_0008B5D0:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048B820(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->ebp) == 0u;
    lift_push32(cpu, cpu->esi);
    if (sub_pred[0]) goto label_0008B82F;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8B82Fu)); sfera_sub_0048A6A0(cpu, LIFT_CODE_TOKEN_RVA(0x8B82Fu));
    label_0008B82F:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->esi == 0u) goto label_0008B956;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0xC7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B84Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48B84Bu));
    cpu->eax = cpu->esi + cpu->esi;
    cpu->edx = 0xCu;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B864u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48B864u));
    x87_v0 = 1.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->ebp) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    if ((int32_t)(cpu->esi) < (int32_t)(4u)) goto label_0008B90C;
    cpu->edx = cpu->esi + 0xFFFFFFFCu;
    cpu->edx >>= 2u;
    ++cpu->edx;
    cpu->edi = cpu->edx * 4u;
    label_0008B88C:
    x87_v1 = (double)*(float*)(cpu->ecx);
    cpu->eax += 0x60u;
    *(float*)(cpu->eax + 0xFFFFFFA0u) = x87_v1; 
    cpu->ecx += 0x40u;
    --cpu->edx;
    *(float*)(cpu->eax + 0xFFFFFFA8u) = (double)*(float*)(cpu->ecx + 0xFFFFFFC4u);
    *(float*)(cpu->eax + 0xFFFFFFA4u) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFACu) = (double)*(float*)(cpu->ecx + 0xFFFFFFC8u);
    *(float*)(cpu->eax + 0xFFFFFFB4u) = (double)*(float*)(cpu->ecx + 0xFFFFFFCCu);
    *(float*)(cpu->eax + 0xFFFFFFB0u) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFB8u) = (double)*(float*)(cpu->ecx + 0xFFFFFFD0u);
    *(float*)(cpu->eax + 0xFFFFFFC0u) = (double)*(float*)(cpu->ecx + 0xFFFFFFD4u);
    *(float*)(cpu->eax + 0xFFFFFFBCu) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFC4u) = (double)*(float*)(cpu->ecx + 0xFFFFFFD8u);
    *(float*)(cpu->eax + 0xFFFFFFCCu) = (double)*(float*)(cpu->ecx + 0xFFFFFFDCu);
    *(float*)(cpu->eax + 0xFFFFFFC8u) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFD0u) = (double)*(float*)(cpu->ecx + 0xFFFFFFE0u);
    *(float*)(cpu->eax + 0xFFFFFFD8u) = (double)*(float*)(cpu->ecx + 0xFFFFFFE4u);
    *(float*)(cpu->eax + 0xFFFFFFD4u) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFDCu) = (double)*(float*)(cpu->ecx + 0xFFFFFFE8u);
    *(float*)(cpu->eax + 0xFFFFFFE4u) = (double)*(float*)(cpu->ecx + 0xFFFFFFECu);
    *(float*)(cpu->eax + 0xFFFFFFE0u) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFE8u) = (double)*(float*)(cpu->ecx + 0xFFFFFFF0u);
    *(float*)(cpu->eax + 0xFFFFFFF0u) = (double)*(float*)(cpu->ecx + 0xFFFFFFF4u);
    *(float*)(cpu->eax + 0xFFFFFFECu) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFF4u) = (double)*(float*)(cpu->ecx + 0xFFFFFFF8u);
    *(float*)(cpu->eax + 0xFFFFFFFCu) = (double)*(float*)(cpu->ecx + 0xFFFFFFFCu);
    *(float*)(cpu->eax + 0xFFFFFFF8u) = x87_v0;
    if (cpu->edx != 0u) goto label_0008B88C;
    label_0008B90C:
    if (cpu->edi >= cpu->esi) goto label_0008B93F;
    cpu->ecx += 8u;
    cpu->eax += 4u;
    cpu->esi -= cpu->edi;
    label_0008B918:
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFF8u);
    cpu->eax += 0x18u;
    *(float*)(cpu->eax + 0xFFFFFFE4u) = x87_v1; 
    cpu->ecx += 0x10u;
    --cpu->esi;
    *(float*)(cpu->eax + 0xFFFFFFECu) = (double)*(float*)(cpu->ecx + 0xFFFFFFECu);
    *(float*)(cpu->eax + 0xFFFFFFE8u) = x87_v0;
    *(float*)(cpu->eax + 0xFFFFFFF0u) = (double)*(float*)(cpu->ecx + 0xFFFFFFF0u);
    *(float*)(cpu->eax + 0xFFFFFFF8u) = (double)*(float*)(cpu->ecx + 0xFFFFFFF4u);
    *(float*)(cpu->eax + 0xFFFFFFF4u) = x87_v0;
    if (cpu->esi != 0u) goto label_0008B918;
    label_0008B93F:
    cpu->ecx = cpu->ebp;
    x87_v0 = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B948u)); sfera_sub_0048B1F0(cpu, LIFT_CODE_TOKEN_VA(0x48B948u));
    cpu->ecx = (uintptr_t)"fx_swall";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B952u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x48B952u));
    *(uint32_t*)(cpu->ebp + 0x18u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    label_0008B956:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048B960(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_server_wall;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48B96Cu)); sfera_sub_0048B820(cpu, LIFT_CODE_TOKEN_VA(0x48B96Cu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
