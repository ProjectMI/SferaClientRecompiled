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
__declspec(noinline) void sfera_sub_004827E0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->esi != 0u) goto label_000827E7;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000827E7:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"PS_ROTATEXYZ"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x827F6u), LIFT_CODE_TOKEN_RVA(0x827F4u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082804;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082804:
    lift_push32(cpu, (uintptr_t)"PS_ROTATEX"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8280Cu), LIFT_CODE_TOKEN_RVA(0x8280Au))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008281A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008281A:
    lift_push32(cpu, (uintptr_t)"PS_ROTATEY"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82822u), LIFT_CODE_TOKEN_RVA(0x82820u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082830;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082830:
    lift_push32(cpu, (uintptr_t)"PS_ROTATEZ"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82838u), LIFT_CODE_TOKEN_RVA(0x82836u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082846;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082846:
    lift_push32(cpu, (uintptr_t)"PS_USEROTSCALE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8284Eu), LIFT_CODE_TOKEN_RVA(0x8284Cu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008285C;
    cpu->eax = 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008285C:
    lift_push32(cpu, (uintptr_t)"PS_TRANSLATEONLY"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82864u), LIFT_CODE_TOKEN_RVA(0x82862u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082872;
    cpu->eax = 0x20u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082872:
    lift_push32(cpu, (uintptr_t)"PS_STATICEMITALL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8287Au), LIFT_CODE_TOKEN_RVA(0x82878u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082888;
    cpu->eax = 0x40u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082888:
    lift_push32(cpu, (uintptr_t)"PS_DYNAMICEMITALL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82890u), LIFT_CODE_TOKEN_RVA(0x8288Eu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008289E;
    cpu->eax = 0x80u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008289E:
    lift_push32(cpu, (uintptr_t)"PS_USEMAGNITE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x828A6u), LIFT_CODE_TOKEN_RVA(0x828A4u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000828B4;
    cpu->eax = 0x100u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000828B4:
    lift_push32(cpu, (uintptr_t)"PS_NOHEAVYATTACH"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x828BCu), LIFT_CODE_TOKEN_RVA(0x828BAu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000828CA;
    cpu->eax = 0x400u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000828CA:
    lift_push32(cpu, (uintptr_t)"PS_NOFACECAMERA"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x828D2u), LIFT_CODE_TOKEN_RVA(0x828D0u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000828E0;
    cpu->eax = 0x800u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000828E0:
    lift_push32(cpu, (uintptr_t)"PS_NOLIFETIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x828E8u), LIFT_CODE_TOKEN_RVA(0x828E6u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000828F6;
    cpu->eax = 0x2000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000828F6:
    lift_push32(cpu, (uintptr_t)"PS_NOLOCALTIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x828FEu), LIFT_CODE_TOKEN_RVA(0x828FCu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008290C;
    cpu->eax = 0x1000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008290C:
    lift_push32(cpu, (uintptr_t)"PS_USEUVTRANSLATE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82914u), LIFT_CODE_TOKEN_RVA(0x82912u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082922;
    cpu->eax = 0x4000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082922:
    lift_push32(cpu, (uintptr_t)"PS_USECOLOR"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8292Au), LIFT_CODE_TOKEN_RVA(0x82928u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082938;
    cpu->eax = 0x8000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082938:
    lift_push32(cpu, (uintptr_t)"PS_USEDISTORTION"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82940u), LIFT_CODE_TOKEN_RVA(0x8293Eu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008294E;
    cpu->eax = 0x10000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008294E:
    lift_push32(cpu, (uintptr_t)"PS_MAGFACTORISLIFE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82956u), LIFT_CODE_TOKEN_RVA(0x82954u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082964;
    cpu->eax = 0x20000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082964:
    lift_push32(cpu, (uintptr_t)"PS_EMITONPOSCHANGE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8296Cu), LIFT_CODE_TOKEN_RVA(0x8296Au))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008297A;
    cpu->eax = 0x40000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008297A:
    lift_push32(cpu, (uintptr_t)"PS_RANDOMTEXFRAME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82982u), LIFT_CODE_TOKEN_RVA(0x82980u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082990;
    cpu->eax = 0x80000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082990:
    lift_push32(cpu, (uintptr_t)"PS_MAGISCHILDPS"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82998u), LIFT_CODE_TOKEN_RVA(0x82996u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000829A6;
    cpu->eax = 0x100000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000829A6:
    lift_push32(cpu, (uintptr_t)"PS_MAGFACTORGTIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x829AEu), LIFT_CODE_TOKEN_RVA(0x829ACu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000829BC;
    cpu->eax = 0x200000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000829BC:
    lift_push32(cpu, (uintptr_t)"PS_EMITCTRLRHW"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x829C4u), LIFT_CODE_TOKEN_RVA(0x829C2u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000829D2;
    cpu->eax = 0x400000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000829D2:
    lift_push32(cpu, (uintptr_t)"PS_PARENTALPHA"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x829DAu), LIFT_CODE_TOKEN_RVA(0x829D8u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000829E8;
    cpu->eax = 0x800000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000829E8:
    lift_push32(cpu, (uintptr_t)"PS_PARENTLIFETIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x829F0u), LIFT_CODE_TOKEN_RVA(0x829EEu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000829FE;
    cpu->eax = 0x1000000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000829FE:
    lift_push32(cpu, (uintptr_t)"PS_DIRECTVELOCITY"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82A06u), LIFT_CODE_TOKEN_RVA(0x82A04u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082A14;
    cpu->eax = 0x2000000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082A14:
    lift_push32(cpu, (uintptr_t)"PS_FOLLOWWITHSPIN"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82A1Cu), LIFT_CODE_TOKEN_RVA(0x82A1Au))) { return; }
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xF8000000u;
    cpu->eax += 0x8000000u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00482A30(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->eax != 0u) goto label_00082A35;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082A35:
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x482A3Bu));
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    ++cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00482A50(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->esi != 0u) goto label_00082A57;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082A57:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_LINE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82A66u), LIFT_CODE_TOKEN_RVA(0x82A64u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082A74;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082A74:
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_DISK"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82A7Cu), LIFT_CODE_TOKEN_RVA(0x82A7Au))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082A8A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082A8A:
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_RING"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82A92u), LIFT_CODE_TOKEN_RVA(0x82A90u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082AA0;
    cpu->eax = 6u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082AA0:
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_BOX"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82AA8u), LIFT_CODE_TOKEN_RVA(0x82AA6u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082AB6;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082AB6:
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_CYLINDER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82ABEu), LIFT_CODE_TOKEN_RVA(0x82ABCu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082ACC;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082ACC:
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_SPHERE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82AD4u), LIFT_CODE_TOKEN_RVA(0x82AD2u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00082AE2;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00082AE2:
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_DISK2"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x82AEAu), LIFT_CODE_TOKEN_RVA(0x82AE8u))) { return; }
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xFFFFFFF9u;
    cpu->eax += 7u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00482B00(LiftCpu* cpu, uint32_t stop_address) { double x87_p0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x60u;
    cpu->ebp = cpu->edx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482B45u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x482B45u));
    if (cpu->eax == 0u) goto label_00082B59;
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482B53u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x482B53u));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx > (int32_t)cpu->edi) goto label_00082B60;
    label_00082B59:
    cpu->eax = 0u;
    goto label_00082CBB;
    label_00082B60:
    cpu->edx = 0xE1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482B6Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x482B6Fu));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482B76u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x482B76u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00082B8E;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482B8Cu)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x482B8Cu));
    cpu->edi = cpu->eax;
    label_00082B8E:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x6Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482B9Eu)); sfera_sub_0042E000(cpu, LIFT_CODE_TOKEN_VA(0x482B9Eu));
    lift_push32(cpu, 0x30u);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x482BAFu));
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482BBFu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x482BBFu));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482BCBu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482BCBu));
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_00082C37;
    cpu->ebp = cpu->esi + 0x10u;
    label_00082BE0:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x82BF7u), LIFT_CODE_TOKEN_RVA(0x82BF5u))) { return; }
    x87_p0 = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x40u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x30u);
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x2Cu;
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482C23u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x482C23u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482C2Fu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482C2Fu));
    if (cpu->eax != 0u) goto label_00082BE0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    label_00082C37:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482C3Fu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x482C3Fu));
    lift_push32(cpu, (uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482C4Bu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482C4Bu));
    if (cpu->eax == 0u) goto label_00082CB2;
    cpu->ebp = cpu->esi + 0x10u;
    label_00082C52:
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x82C6Eu), LIFT_CODE_TOKEN_RVA(0x82C6Cu))) { return; }
    x87_p0 = (double)*(float*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp + 0x44u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    cpu->esp += 0x18u;
    cpu->ecx = cpu->esp + 0x2Cu;
    *(float*)(cpu->esp + 0x34u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    *(float*)(cpu->esp + 0x40u) = x87_p0; 
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482CA2u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x482CA2u));
    lift_push32(cpu, (uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482CAEu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482CAEu));
    if (cpu->eax != 0u) goto label_00082C52;
    label_00082CB2:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482CB9u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x482CB9u));
    cpu->eax = cpu->edi;
    label_00082CBB:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00482CE0(LiftCpu* cpu, uint32_t stop_address) { double x87_p0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x74u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x88u;
    cpu->ebp = cpu->edx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482D28u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x482D28u));
    if (cpu->eax == 0u) goto label_00082D3C;
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482D36u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x482D36u));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx > (int32_t)cpu->edi) goto label_00082D43;
    label_00082D3C:
    cpu->eax = 0u;
    goto label_00083034;
    label_00082D43:
    cpu->edx = 0x119u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482D52u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x482D52u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482D59u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x482D59u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00082D74;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482D72u)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x482D72u));
    cpu->edi = cpu->eax;
    label_00082D74:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x94u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482D87u)); sfera_sub_0042E000(cpu, LIFT_CODE_TOKEN_VA(0x482D87u));
    lift_push32(cpu, 0x30u);
    cpu->eax = cpu->esp + 0x58u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x482D98u));
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482DA8u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x482DA8u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482DB4u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482DB4u));
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_00082E52;
    cpu->ebp = cpu->esi + 0x10u;
    label_00082DC5:
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x82DE6u), LIFT_CODE_TOKEN_RVA(0x82DE4u))) { return; }
    *(float*)(cpu->esp + 0x70u) = (double)*(float*)(cpu->esp + 0x4Cu);
    cpu->esp += 0x1Cu;
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x58u) = 0u;
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x2Cu) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482E3Au)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x482E3Au));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482E46u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482E46u));
    if (cpu->eax != 0u) goto label_00082DC5;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x4Cu);
    label_00082E52:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482E5Au)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x482E5Au));
    lift_push32(cpu, (uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482E66u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482E66u));
    if (cpu->eax == 0u) goto label_00082F40;
    cpu->ebp = cpu->esi + 0x10u;
    label_00082E71:
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x82EA1u), LIFT_CODE_TOKEN_RVA(0x82E9Fu))) { return; }
    *(float*)(cpu->esp + 0x7Cu) = (double)*(float*)(cpu->esp + 0x58u);
    cpu->esp += 0x28u;
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x58u) = 1u;
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ecx;
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->edx;
    *(float*)(cpu->esp + 0x2Cu) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->eax;
    *(float*)(cpu->esp + 0x38u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    *(float*)(cpu->esp + 0x3Cu) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x48u);
    cpu->ecx = cpu->esp + 0x54u;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x40u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482F28u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x482F28u));
    lift_push32(cpu, (uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482F34u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482F34u));
    if (cpu->eax != 0u) goto label_00082E71;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x4Cu);
    label_00082F40:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482F48u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x482F48u));
    lift_push32(cpu, (uintptr_t)"mrkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x482F54u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x482F54u));
    if (cpu->eax == 0u) goto label_0008302B;
    cpu->ebp = cpu->esi + 0x10u;
    (void)cpu;
    label_00082F60:
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x82F90u), LIFT_CODE_TOKEN_RVA(0x82F8Eu))) { return; }
    *(float*)(cpu->esp + 0x7Cu) = (double)*(float*)(cpu->esp + 0x58u);
    cpu->esp += 0x28u;
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x58u) = 2u;
    *(float*)(cpu->esp + 0x38u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x3Cu) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->eax;
    *(float*)(cpu->esp + 0x40u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ecx;
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->edx;
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x48u);
    cpu->edx = cpu->esp + 0x54u;
    *(float*)(cpu->esp + 0x2Cu) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483017u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x483017u));
    lift_push32(cpu, (uintptr_t)"mrkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483023u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x483023u));
    if (cpu->eax != 0u) goto label_00082F60;
    label_0008302B:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483032u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x483032u));
    cpu->eax = cpu->edi;
    label_00083034:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x80u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483060(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    bool lift_cmp[1];
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    x87_v0 = (x87_v0) - (((double)g_sfera_effect_manager.viewer_position.x));
    cpu->edi = cpu->edx;
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi + 4u))) - (((double)g_sfera_effect_manager.viewer_position.y)));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->esi + 8u))) - (((double)g_sfera_effect_manager.viewer_position.z)));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    x87_v1 = (x87_v1) * (x87_v2);
    x87_v3 = (double)*(float*)(cpu->esp + 0x20u); x87_v4 = x87_v3;
    x87_v5 = -1.0;
    x87_v4 = (x87_v4) * (x87_v5);
    x87_v6 = x87_v1;
    x87_v4 = x87_v6 - x87_v4; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0xCu) = x87_v5; 
    x87_v5 = x87_v3;
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v6 = (double)*(float*)(cpu->esp + 0x18u); x87_v7 = x87_v6;
    x87_v2 = x87_v2 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    x87_v2 = x87_v6 - x87_v2; 
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v5; 
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v1 = x87_v4 - x87_v1; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v4 = (double)*(float*)(cpu->esp + 0x14u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x10u); x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (x87_v1);
    x87_v3 = x87_v3 - x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0xCu); x87_v6 = x87_v5;
    x87_v1 = x87_v1 * x87_v6; 
    x87_v6 = x87_v2;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v4; 
    x87_v2 = x87_v2 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 * x87_v2; 
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)9.999999747378752e-06f;
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    lift_cmp[0]=x87_v1<x87_v0;
    x87_v0 = x87_v1; 
    x87_v1 = 0.0;
    if (!lift_cmp[0]) goto label_00083181;
    x87_v0 = x87_v1; 
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    goto label_000831AB;
    label_00083181:
    x87_v1 = x87_v1; 
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    label_000831AB:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = (double)9.999999747378752e-06f;
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_0008321F; }
    x87_v0 = x87_v0; 
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    goto label_00083247;
    label_0008321F:
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0xCu)));
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    label_00083247:
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x30u) = x87_v1;
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v2 = (x87_v2) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x34u) = x87_v2;
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v3 = (x87_v3) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x38u) = x87_v3;
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v4 = (x87_v4) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x24u) = x87_v4;
    x87_v5 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x28u) = x87_v5;
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = x87_v0 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v5;
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->esi))) - (((double)*(float*)(cpu->esp + 0x24u))));
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi + 4u))) - (((double)*(float*)(cpu->esp + 0x28u))));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->esi + 8u))) - (((double)*(float*)(cpu->esp + 0x2Cu))));
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->esp + 0x18u))) - (((double)*(float*)(cpu->esp + 0x30u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    x87_v6 = (x87_v6) - (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x28u) = x87_v6; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    x87_v6 = (x87_v6) - (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v6; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(uint32_t*)(cpu->edi + 8u) = cpu->edx;
    *(float*)(cpu->esp + 0x18u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0x30u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x38u) = x87_v5;
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->esi))) - (((double)*(float*)(cpu->esp + 0x30u))));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esi + 4u))) - (((double)*(float*)(cpu->esp + 0x34u))));
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esi + 8u))) - (((double)*(float*)(cpu->esp + 0x38u))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esp + 0x24u))) + (((double)*(float*)(cpu->esp + 0x18u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    x87_v6 = (x87_v6) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x34u) = x87_v6; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ecx;
    x87_v6 = (x87_v6) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x38u) = x87_v6; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->edx;
    *(float*)(cpu->esp + 0x18u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x30u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x38u) = x87_v5;
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->esi))) + (((double)*(float*)(cpu->esp + 0x30u))));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x34u))) + (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esp + 0x38u))) + (((double)*(float*)(cpu->esi + 8u))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esp + 0x24u))) + (((double)*(float*)(cpu->esp + 0x18u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->eax;
    x87_v6 = (x87_v6) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x34u) = x87_v6; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->ecx;
    x87_v6 = (x87_v6) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x38u) = x87_v6; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->edx;
    *(float*)(cpu->esp + 0x18u) = x87_v5; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x30u) = x87_v2; 
    *(float*)(cpu->esp + 0x34u) = x87_v1; 
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    *(float*)(cpu->esp + 0x24u) = ((((double)*(float*)(cpu->esp + 0x30u))) + (((double)*(float*)(cpu->esi))));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x34u))) + (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esp + 0x38u))) + (((double)*(float*)(cpu->esi + 8u))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esp + 0x24u))) - (((double)*(float*)(cpu->esp + 0x18u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edi + 0x24u) = cpu->eax;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->edi + 0x28u) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->edi + 0x2Cu) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x4Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x50u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004834C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x30u) == 0u) goto label_000834E4;
    cpu->edx = 0x1A2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4834D8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4834D8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4834E1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4834E1u));
    cpu->esp += 4u;
    label_000834E4:
    if (*(uint32_t*)(cpu->esi + 0x34u) == 0u) goto label_00083505;
    cpu->edx = 0x1A3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4834F9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4834F9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483502u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483502u));
    cpu->esp += 4u;
    label_00083505:
    if (*(uint32_t*)(cpu->esi + 0x38u) == 0u) goto label_00083526;
    cpu->edx = 0x1A4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48351Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48351Au));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483523u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483523u));
    cpu->esp += 4u;
    label_00083526:
    if (*(uint32_t*)(cpu->esi + 0x3Cu) == 0u) goto label_00083547;
    cpu->edx = 0x1A5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48353Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48353Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483544u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483544u));
    cpu->esp += 4u;
    label_00083547:
    if (*(uint32_t*)(cpu->esi + 0x40u) == 0u) goto label_00083568;
    cpu->edx = 0x1A6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48355Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48355Cu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483565u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483565u));
    cpu->esp += 4u;
    label_00083568:
    if (*(uint32_t*)(cpu->esi + 0x44u) == 0u) goto label_00083589;
    cpu->edx = 0x1A8u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48357Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48357Du));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483586u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483586u));
    cpu->esp += 4u;
    label_00083589:
    if (*(uint32_t*)(cpu->esi + 0x48u) == 0u) goto label_000835AA;
    cpu->edx = 0x1A9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48359Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48359Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4835A7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4835A7u));
    cpu->esp += 4u;
    label_000835AA:
    if (*(uint32_t*)(cpu->esi + 0x4Cu) == 0u) goto label_000835CB;
    cpu->edx = 0x1AAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4835BFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4835BFu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4835C8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4835C8u));
    cpu->esp += 4u;
    label_000835CB:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004835D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x28u) <= 0u) goto label_00083658;
    cpu->edx = 0x1B9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4835E8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4835E8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx = 0xCu;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483601u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x483601u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483612u));
    cpu->esp += 0x10u;
    cpu->edx = 0x1BCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483629u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483629u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483642u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x483642u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483650u));
    cpu->esp += 0x10u;
    label_00083658:
    if (*(uint32_t*)(cpu->esi + 0x2Cu) <= 0u) goto label_0008369E;
    cpu->edx = 0x1C2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48366Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48366Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = 8u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483686u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x483686u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483696u));
    cpu->esp += 0x10u;
    label_0008369E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004836A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x20u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4836BEu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4836BEu));
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esi + 0x28u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4836CAu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4836CAu));
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4836D7u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4836D7u));
    cpu->edx = cpu->esi + 0x2Cu;
    lift_push32(cpu, 4u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4836E3u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4836E3u));
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esi + 0x24u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4836EFu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4836EFu));
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4836FCu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4836FCu));
    if (*(uint32_t*)(cpu->esi + 0x28u) <= 0u) goto label_0008375E;
    cpu->edx = 0x1DBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483711u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483711u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx = 0xCu;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48372Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48372Au));
    cpu->esp += 4u;
    cpu->edx = 0x1DEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48373Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48373Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483758u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x483758u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    label_0008375E:
    if (*(uint32_t*)(cpu->esi + 0x2Cu) <= 0u) goto label_00083792;
    cpu->edx = 0x1E4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483773u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483773u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = 8u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48378Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48378Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->eax;
    label_00083792:
    if (*(uint32_t*)(cpu->esi + 0x24u) <= 0u) goto label_000837F4;
    cpu->edx = 0x1EAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4837A7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4837A7u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx = 0x10u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4837C0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4837C0u));
    cpu->esp += 4u;
    cpu->edx = 0x1EBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4837D5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4837D5u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx = 0x10u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4837EEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4837EEu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    label_000837F4:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483809u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x483809u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, 1u);
    cpu->edx += cpu->edx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48381Du)); sfera_sub_0042F0E0(cpu, LIFT_CODE_TOKEN_VA(0x48381Du));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x38u);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48382Eu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x48382Eu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483840u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x483840u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->eax == 0u) goto label_00083869;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483858u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x483858u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x3Cu);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x83869u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_RVA(0x83869u));
    label_00083869:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483870u)); sfera_sub_004835D0(cpu, LIFT_CODE_TOKEN_VA(0x483870u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483880(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    x87_v0 = 0.0;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(float*)(cpu->esi + 0x24u) = x87_v0;
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->esi + 0x28u) = x87_v0;
    cpu->ecx = 0xFFu;
    *(float*)(cpu->esp + 8u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->esi + 0x50u;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->edx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x98u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x94u) = 0xFFFFFFFFu;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4838FEu));
    x87_v0 = 1.0;
    *(float*)(cpu->edi + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->edi + 0x28u) = x87_v0;
    cpu->eax = cpu->esi;
    *(float*)(cpu->edi + 0x14u) = x87_v0;
    *(float*)(cpu->edi) = x87_v0; 
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483920(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x34u) != 0u) goto label_00083A7D;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_0008394C;
    cpu->edx = 0x233u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483941u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483941u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483949u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483949u));
    cpu->esp += 4u;
    label_0008394C:
    if (*(uint32_t*)(cpu->esi + 0x90u) == 0u) goto label_00083973;
    cpu->edx = 0x234u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483964u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483964u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483970u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483970u));
    cpu->esp += 4u;
    label_00083973:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_000839A0;
    cpu->edx = 0x235u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483989u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483989u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->edi == 0u) goto label_000839A0;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483997u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x483997u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48399Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48399Du));
    cpu->esp += 4u;
    label_000839A0:
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_000839CC;
    cpu->edx = 0x236u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4839B5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4839B5u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->edi == 0u) goto label_000839CC;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4839C3u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4839C3u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4839C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4839C9u));
    cpu->esp += 4u;
    label_000839CC:
    if (*(uint32_t*)(cpu->esi + 0x14u) == 0u) goto label_000839F8;
    cpu->edx = 0x237u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4839E1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4839E1u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->edi == 0u) goto label_000839F8;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4839EFu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4839EFu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4839F5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4839F5u));
    cpu->esp += 4u;
    label_000839F8:
    if (*(uint32_t*)(cpu->esi + 0x18u) == 0u) goto label_00083A24;
    cpu->edx = 0x238u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A0Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483A0Du));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    if (cpu->edi == 0u) goto label_00083A24;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A1Bu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x483A1Bu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A21u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483A21u));
    cpu->esp += 4u;
    label_00083A24:
    if (*(uint32_t*)(cpu->esi + 0x1Cu) == 0u) goto label_00083A50;
    cpu->edx = 0x239u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A39u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483A39u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (cpu->edi == 0u) goto label_00083A50;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A47u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x483A47u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A4Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483A4Du));
    cpu->esp += 4u;
    label_00083A50:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x20u) == 0u;
    cpu->edi = lift_pop32(cpu);
    if (sub_pred[1]) goto label_00083A7D;
    cpu->edx = 0x23Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A66u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483A66u));
    cpu->esi = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->esi == 0u) goto label_00083A7D;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A74u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x483A74u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483A7Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483A7Au));
    cpu->esp += 4u;
    label_00083A7D:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483A80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    *(float*)(cpu->edi + 0x24u) = x87_v0; 
    *(float*)(cpu->edi + 0x28u) = (double)*(float*)(cpu->esi + 0x28u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x2Cu);
    *(uint8_t*)(cpu->edi + 0x2Cu) = cpu->eax & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x2Du));
    *(uint8_t*)(cpu->edi + 0x2Du) = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x2Eu));
    *(uint8_t*)(cpu->edi + 0x2Eu) = cpu->edx & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x2Fu);
    *(uint8_t*)(cpu->edi + 0x2Fu) = cpu->eax & 0xFFu;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x83AB7u), LIFT_CODE_TOKEN_RVA(0x83AB5u))) { return; }
    cpu->ecx = 0xFFu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->edi + 0x38u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x83AC4u), LIFT_CODE_TOKEN_RVA(0x83AC2u))) { return; }
    *(uint32_t*)(cpu->edi + 0x3Cu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x83AC9u), LIFT_CODE_TOKEN_RVA(0x83AC7u))) { return; }
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x44u);
    *(uint32_t*)(cpu->edi + 0x44u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x48u);
    *(uint32_t*)(cpu->edi + 0x48u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x4Cu);
    *(uint32_t*)(cpu->edi + 0x4Cu) = cpu->ecx;
    cpu->esi += 0x50u;
    cpu->edi += 0x50u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483B00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    cpu->esi = cpu->ecx;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x83B0Cu), LIFT_CODE_TOKEN_RVA(0x83B0Au))) { return; }
    cpu->ecx = 0xFFu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x83B19u), LIFT_CODE_TOKEN_RVA(0x83B17u))) { return; }
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x83B1Eu), LIFT_CODE_TOKEN_RVA(0x83B1Cu))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->ecx == 0u) goto label_00083B55;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483B30u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x483B30u));
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_00083B55;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CEffectMesh::Initialize() -> Texture '%s' not found");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483B4Cu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x483B4Cu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483B52u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x483B52u));
    cpu->esp += 0xCu;
    label_00083B55:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483B60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0u) goto label_00083BBC;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00083B74:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00083B74;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00083BBC;
    cpu->edx = 0x272u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483B8Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483B8Eu));
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00083B93:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00083B93;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483BA3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x483BA3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    label_00083BB0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00083BB0;
    goto label_00083BC2;
    label_00083BBC:
    *(uint32_t*)(cpu->edi) = 0u;
    label_00083BC2:
    if (cpu->ebx == 0u) goto label_00083BDE;
    cpu->edx = 0x277u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483BD5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483BD5u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483BDBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483BDBu));
    cpu->esp += 4u;
    label_00083BDE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483BF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x90u);
    if (cpu->esi == 0u) goto label_00083C50;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00083C08:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00083C08;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00083C50;
    cpu->edx = 0x283u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483C22u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483C22u));
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00083C27:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00083C27;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483C37u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x483C37u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 0x90u) = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    label_00083C44:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00083C44;
    goto label_00083C5A;
    label_00083C50:
    *(uint32_t*)(cpu->edi + 0x90u) = 0u;
    label_00083C5A:
    if (cpu->ebx == 0u) goto label_00083C76;
    cpu->edx = 0x288u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483C6Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483C6Du));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483C73u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483C73u));
    cpu->esp += 4u;
    label_00083C76:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483C80(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 4u) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (sub_pred[0]) goto label_00083F1E;
    lift_test[0]=(*(uint8_t*)(cpu->ebx + 8u)&0x20u)==0u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebx + 0x44u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ebx + 0x48u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebx + 0x4Cu) = cpu->eax;
    if (lift_test[0]) goto label_00083D0F;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x14u);
    if (cpu->ecx == 0u) goto label_00083CF3;
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483CD5u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x483CD5u));
    *(float*)(cpu->ebx + 0x44u) = ((((double)*(float*)(cpu->ebx + 0x44u))) + (((double)*(float*)(cpu->esp + 0xCu))));
    *(float*)(cpu->ebx + 0x48u) = ((((double)*(float*)(cpu->ebx + 0x48u))) + (((double)*(float*)(cpu->esp + 0x10u))));
    *(float*)(cpu->ebx + 0x4Cu) = ((((double)*(float*)(cpu->ebx + 0x4Cu))) + (((double)*(float*)(cpu->esp + 0x14u))));
    label_00083CF3:
    if ((*(uint32_t*)(cpu->ebx + 8u)&0x8000000u)==0u) goto label_00083E9C;
    cpu->edi = cpu->ebx + 0x50u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    goto label_00083E9C;
    label_00083D0F:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x40u);
    cpu->ebp = 0u;
    cpu->edi = cpu->ebx + 0x50u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483D19u));
    x87_v0 = 1.0;
    *(float*)(cpu->edi + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->edi + 0x28u) = x87_v0;
    *(float*)(cpu->edi + 0x14u) = x87_v0;
    *(float*)(cpu->edi) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xCu);
    if (cpu->ecx == 0u) goto label_00083DB3;
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483D47u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x483D47u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00083D71;
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483D6Fu)); sfera_sub_004825A0(cpu, LIFT_CODE_TOKEN_VA(0x483D6Fu));
    goto label_00083DAE;
    label_00083D71:
    if ((((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_00083D86;
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483D84u)); sfera_sub_00482720(cpu, LIFT_CODE_TOKEN_VA(0x483D84u));
    goto label_00083DAE;
    label_00083D86:
    if ((((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_00083D9B;
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483D99u)); sfera_sub_004826C0(cpu, LIFT_CODE_TOKEN_VA(0x483D99u));
    goto label_00083DAE;
    label_00083D9B:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00083DB3;
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x83DAEu)); sfera_sub_00482780(cpu, LIFT_CODE_TOKEN_RVA(0x83DAEu));
    label_00083DAE:
    cpu->ebp = 1u;
    label_00083DB3:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    if (cpu->ecx == 0u) goto label_00083E3F;
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483DD0u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x483DD0u));
    if (cpu->ebp == 0u) goto label_00083E2B;
    x87_v0 = (double)*(float*)(cpu->edi);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->edi) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->ebx + 0x60u)));
    *(float*)(cpu->ebx + 0x60u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ebx + 0x70u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x18u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->ebx + 0x70u) = x87_v3; 
    x87_v3 = x87_v0;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->ebx + 0x54u)));
    *(float*)(cpu->ebx + 0x54u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ebx + 0x64u);
    x87_v3 = (x87_v3) * (x87_v1);
    *(float*)(cpu->ebx + 0x64u) = x87_v3; 
    x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->ebx + 0x74u)));
    *(float*)(cpu->ebx + 0x74u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ebx + 0x58u);
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ebx + 0x58u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->ebx + 0x68u)));
    *(float*)(cpu->ebx + 0x68u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->ebx + 0x78u)));
    goto label_00083E3C;
    label_00083E2B:
    *(float*)(cpu->edi) = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->ebx + 0x64u) = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    label_00083E3C:
    *(float*)(cpu->ebx + 0x78u) = x87_v0; 
    label_00083E3F:
    x87_v0 = (double)*(float*)(cpu->ebx + 0x44u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x14u);
    *(float*)(cpu->ebx + 0x5Cu) = x87_v0; 
    cpu->ebp = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x6Cu) = (double)*(float*)(cpu->ebx + 0x48u);
    *(float*)(cpu->ebx + 0x7Cu) = (double)*(float*)(cpu->ebx + 0x4Cu);
    if (cpu->ecx == 0u) goto label_00083E89;
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483E6Bu)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x483E6Bu));
    *(float*)(cpu->ebx + 0x5Cu) = ((((double)*(float*)(cpu->esp + 0xCu))) + (((double)*(float*)(cpu->ebx + 0x5Cu))));
    *(float*)(cpu->ebx + 0x6Cu) = ((((double)*(float*)(cpu->ebx + 0x6Cu))) + (((double)*(float*)(cpu->esp + 0x10u))));
    *(float*)(cpu->ebx + 0x7Cu) = ((((double)*(float*)(cpu->ebx + 0x7Cu))) + (((double)*(float*)(cpu->esp + 0x14u))));
    label_00083E89:
    if ((*(uint32_t*)(cpu->ebx + 8u)&0x8000000u)==0u) goto label_00083E9C;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x83E9Cu)); sfera_sub_004822F0(cpu, LIFT_CODE_TOKEN_RVA(0x83E9Cu));
    label_00083E9C:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x38u);
    cpu->esi <<= 9u;
    cpu->esi += g_sfera_effect_manager.particle_random_table;
    lift_test[1]=(*(uint32_t*)(cpu->ebx + 8u)&0x4000u)==0u;
    cpu->edi = lift_pop32(cpu);
    if (lift_test[1]) goto label_00083EF4;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x18u);
    if (cpu->ecx == 0u) goto label_00083ED3;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x40u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x83ED3u)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x83ED3u));
    label_00083ED3:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1Cu);
    if (cpu->ecx == 0u) goto label_00083EF4;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x40u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x83EF4u)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x83EF4u));
    label_00083EF4:
    if (((*(uint32_t*)(cpu->ebx + 8u)) & (0x8000u)) == 0u) goto label_00083F1E;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x20u);
    if (cpu->ecx == 0u) goto label_00083F1E;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x40u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ebx += 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x83F1Eu)); sfera_sub_0042D430(cpu, LIFT_CODE_TOKEN_RVA(0x83F1Eu));
    label_00083F1E:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != 0u) goto label_00083F48;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00083F48:
    cpu->eax = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00483F50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x198u) != 0u) goto label_000843F3;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_00083F7F;
    cpu->edx = 0x47Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483F74u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483F74u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483F7Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483F7Cu));
    cpu->esp += 4u;
    label_00083F7F:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x50u) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_00083FAC;
    cpu->edx = 0x47Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483F95u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483F95u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x50u);
    if (cpu->edi == 0u) goto label_00083FAC;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483FA3u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x483FA3u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483FA9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483FA9u));
    cpu->esp += 4u;
    label_00083FAC:
    if (*(uint32_t*)(cpu->esi + 0x54u) == 0u) goto label_00083FD8;
    cpu->edx = 0x47Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483FC1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483FC1u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x54u);
    if (cpu->edi == 0u) goto label_00083FD8;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483FCFu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x483FCFu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483FD5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x483FD5u));
    cpu->esp += 4u;
    label_00083FD8:
    if (*(uint32_t*)(cpu->esi + 0x58u) == 0u) goto label_00084004;
    cpu->edx = 0x47Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483FEDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x483FEDu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x58u);
    if (cpu->edi == 0u) goto label_00084004;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x483FFBu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x483FFBu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484001u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484001u));
    cpu->esp += 4u;
    label_00084004:
    if (*(uint32_t*)(cpu->esi + 0x64u) == 0u) goto label_00084030;
    cpu->edx = 0x481u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484019u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484019u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x64u);
    if (cpu->edi == 0u) goto label_00084030;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484027u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x484027u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48402Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48402Du));
    cpu->esp += 4u;
    label_00084030:
    if (*(uint32_t*)(cpu->esi + 0x80u) == 0u) goto label_00084062;
    cpu->edx = 0x482u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484048u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484048u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x80u);
    if (cpu->edi == 0u) goto label_00084062;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484059u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x484059u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48405Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48405Fu));
    cpu->esp += 4u;
    label_00084062:
    if (*(uint32_t*)(cpu->esi + 0x84u) == 0u) goto label_00084094;
    cpu->edx = 0x483u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48407Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48407Au));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x84u);
    if (cpu->edi == 0u) goto label_00084094;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48408Bu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x48408Bu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484091u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484091u));
    cpu->esp += 4u;
    label_00084094:
    if (*(uint32_t*)(cpu->esi + 0x78u) == 0u) goto label_000840C0;
    cpu->edx = 0x484u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4840A9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4840A9u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x78u);
    if (cpu->edi == 0u) goto label_000840C0;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4840B7u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4840B7u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4840BDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4840BDu));
    cpu->esp += 4u;
    label_000840C0:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x16Cu) == 0u;
    lift_push32(cpu, cpu->ebx);
    if (sub_pred[1]) goto label_00084133;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x15Cu) <= cpu->edi) goto label_00084115;
    label_000840D4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x16Cu);
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) == 0u) goto label_0008410C;
    cpu->edx = 0x489u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4840EFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4840EFu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x16Cu);
    cpu->ebx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    if (cpu->ebx == 0u) goto label_0008410C;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484103u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x484103u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484109u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484109u));
    cpu->esp += 4u;
    label_0008410C:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x15Cu)) goto label_000840D4;
    label_00084115:
    cpu->edx = 0x48Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484124u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484124u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x16Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484130u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484130u));
    cpu->esp += 4u;
    label_00084133:
    if (*(uint32_t*)(cpu->esi + 0x170u) == 0u) goto label_000841AF;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x160u) <= cpu->edi) goto label_00084191;
    label_00084150:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x170u);
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) == 0u) goto label_00084188;
    cpu->edx = 0x491u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48416Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48416Bu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x170u);
    cpu->ebx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    if (cpu->ebx == 0u) goto label_00084188;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48417Fu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x48417Fu));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484185u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484185u));
    cpu->esp += 4u;
    label_00084188:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x160u)) goto label_00084150;
    label_00084191:
    cpu->edx = 0x493u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4841A0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4841A0u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x170u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4841ACu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4841ACu));
    cpu->esp += 4u;
    label_000841AF:
    if (*(uint32_t*)(cpu->esi + 0x174u) == 0u) goto label_00084221;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x164u) <= cpu->edi) goto label_00084203;
    label_000841C2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x174u);
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) == 0u) goto label_000841FA;
    cpu->edx = 0x499u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4841DDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4841DDu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x174u);
    cpu->ebx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    if (cpu->ebx == 0u) goto label_000841FA;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4841F1u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4841F1u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4841F7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4841F7u));
    cpu->esp += 4u;
    label_000841FA:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x164u)) goto label_000841C2;
    label_00084203:
    cpu->edx = 0x49Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484212u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484212u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x174u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48421Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48421Eu));
    cpu->esp += 4u;
    label_00084221:
    if (*(uint32_t*)(cpu->esi + 0x178u) == 0u) goto label_00084293;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x168u) <= cpu->edi) goto label_00084275;
    label_00084234:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x178u);
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) == 0u) goto label_0008426C;
    cpu->edx = 0x4A0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48424Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48424Fu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x178u);
    cpu->ebx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    if (cpu->ebx == 0u) goto label_0008426C;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484263u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x484263u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484269u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484269u));
    cpu->esp += 4u;
    label_0008426C:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x168u)) goto label_00084234;
    label_00084275:
    cpu->edx = 0x4A1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484284u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484284u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x178u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484290u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484290u));
    cpu->esp += 4u;
    label_00084293:
    if (*(uint32_t*)(cpu->esi + 0x40u) == 0u) goto label_000842BF;
    cpu->edx = 0x4A4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4842A8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4842A8u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x40u);
    if (cpu->edi == 0u) goto label_000842BF;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4842B6u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4842B6u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4842BCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4842BCu));
    cpu->esp += 4u;
    label_000842BF:
    if (*(uint32_t*)(cpu->esi + 0x44u) == 0u) goto label_000842EB;
    cpu->edx = 0x4A5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4842D4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4842D4u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x44u);
    if (cpu->edi == 0u) goto label_000842EB;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4842E2u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4842E2u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4842E8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4842E8u));
    cpu->esp += 4u;
    label_000842EB:
    if (*(uint32_t*)(cpu->esi + 0x2Cu) == 0u) goto label_0008430C;
    cpu->edx = 0x4A6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484300u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484300u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484309u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484309u));
    cpu->esp += 4u;
    label_0008430C:
    if (*(uint32_t*)(cpu->esi + 0x17Cu) == 0u) goto label_00084378;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x180u) <= cpu->ebx) goto label_0008435A;
    cpu->edi = 0u;
    label_00084321:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x17Cu);
    if (*(uint32_t*)(cpu->edi + cpu->edx) == 0u) goto label_0008434E;
    cpu->edx = 0x4ACu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48433Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48433Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x17Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48434Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48434Bu));
    cpu->esp += 4u;
    label_0008434E:
    ++cpu->ebx;
    cpu->edi += 0x28u;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x180u)) goto label_00084321;
    label_0008435A:
    cpu->edx = 0x4AEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484369u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484369u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x17Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484375u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484375u));
    cpu->esp += 4u;
    label_00084378:
    if (*(uint32_t*)(cpu->esi + 0x188u) == 0u) goto label_000843F1;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) <= cpu->ebx) goto label_000843C9;
    cpu->edi = 0u;
    label_00084390:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x188u);
    if (*(uint32_t*)(cpu->edi + cpu->eax) == 0u) goto label_000843BD;
    cpu->edx = 0x4B5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4843ABu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4843ABu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x188u);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4843BAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4843BAu));
    cpu->esp += 4u;
    label_000843BD:
    ++cpu->ebx;
    cpu->edi += 0x14u;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x18Cu)) goto label_00084390;
    label_000843C9:
    cpu->edx = 0x4B7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4843D8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4843D8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x188u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4843E4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4843E4u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x188u) = 0u;
    label_000843F1:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000843F3:
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_00084414;
    cpu->edx = 0x4BCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484408u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484408u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484411u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484411u));
    cpu->esp += 4u;
    label_00084414:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00484420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->ecx + 0x70u) = (double)*(float*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + 0x74u) = cpu->eax;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00484440(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    cpu->esi = cpu->ecx;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8444Cu), LIFT_CODE_TOKEN_RVA(0x8444Au))) { return; }
    cpu->ecx = 0xFFu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->esi + 0xD8u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8445Cu), LIFT_CODE_TOKEN_RVA(0x8445Au))) { return; }
    *(uint32_t*)(cpu->esi + 0xDCu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x84464u), LIFT_CODE_TOKEN_RVA(0x84462u))) { return; }
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x17Cu) == 0u;
    *(uint32_t*)(cpu->esi + 0xE0u) = cpu->eax;
    if (sub_pred[0]) goto label_000844CD;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x180u) <= cpu->ebx) goto label_000844CC;
    cpu->edi = 0u;
    label_00084480:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x17Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->edx);
    if (cpu->ecx == 0u) goto label_000844C0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484492u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x484492u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->ecx + cpu->edi + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x17Cu);
    if (*(uint32_t*)(cpu->eax + cpu->edi + 4u) != 0xFFFFFFFFu) goto label_000844C0;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CParticleSystem::Initialize() -> Texture '%s' not found");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4844B7u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4844B7u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4844BDu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4844BDu));
    cpu->esp += 0xCu;
    label_000844C0:
    ++cpu->ebx;
    cpu->edi += 0x28u;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x180u)) goto label_00084480;
    label_000844CC:
    cpu->ebx = lift_pop32(cpu);
    label_000844CD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004844D0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
 bool lift_test[1]; double x87_p0;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x34u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x38u);
    *(uint32_t*)(cpu->ebp + 0x38u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(uint32_t*)(cpu->ebp + 0x3Cu) = cpu->edx;
    *(float*)(cpu->ebp + 0x48u) = (double)*(float*)(cpu->ebx + 0x48u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->ebp + 0x60u) = cpu->edi;
    *(float*)(cpu->ebp + 0x6Cu) = (double)*(float*)(cpu->ebx + 0x6Cu);
    cpu->esi = native_function_address32(&::rand);
    *(float*)(cpu->ebp + 0x70u) = (double)(0.0);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x4Cu);
    *(uint32_t*)(cpu->ebp + 0x4Cu) = cpu->eax;
    *(float*)(cpu->ebp + 0x7Cu) = (double)*(float*)(cpu->ebx + 0x7Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x8Cu);
    *(uint32_t*)(cpu->ebp + 0x8Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x90u);
    *(uint32_t*)(cpu->ebp + 0x90u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x94u);
    *(uint32_t*)(cpu->ebp + 0x94u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x98u);
    *(uint32_t*)(cpu->ebp + 0x98u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x9Cu);
    *(uint32_t*)(cpu->ebp + 0x9Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    *(uint32_t*)(cpu->ebp + 0xA0u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xD4u) = 1u;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x84565u), LIFT_CODE_TOKEN_RVA(0x84563u))) { return; }
    cpu->ecx = 0xFFu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->ebp + 0xD8u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x84575u), LIFT_CODE_TOKEN_RVA(0x84573u))) { return; }
    *(uint32_t*)(cpu->ebp + 0xDCu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x8457Du), LIFT_CODE_TOKEN_RVA(0x8457Bu))) { return; }
    lift_test[0]=(*(uint8_t*)(cpu->ebp + 0x4Cu)&0x40u)==0u;
    cpu->edx = 1u;
    *(uint32_t*)(cpu->ebp + 0x194u) = cpu->edi;
    cpu->esi = cpu->ebx + 0x11Cu;
    cpu->edi = cpu->ebp + 0x11Cu;
    *(uint32_t*)(cpu->ebp + 0xE0u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x74u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0x190u) = cpu->edx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    if (lift_test[0]) goto label_000845F4;
    cpu->edx = 0u;
    if (*(uint32_t*)(cpu->ebx + 0x5Cu) <= cpu->edx) goto label_00084616;
    cpu->eax = 0u;
label_000845C0:
    cpu->edi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->eax + 0x48u);
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edi += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->esi += cpu->eax;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),80u); cpu->edi += 80u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx + cpu->eax + 0x48u) = cpu->esi;
    ++cpu->edx;
    cpu->eax += 0x50u;
    if (cpu->edx < *(uint32_t*)(cpu->ebx + 0x5Cu)) goto label_000845C0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
label_000845F4:
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->ebx + 0x5Cu) <= cpu->eax) goto label_00084616;
    x87_p0 = (double)-1.0f;
    cpu->ecx = 0u;
     value_0 = x87_p0; 
label_00084603:
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    *(float*)(cpu->esi + cpu->ecx + 0x28u) = value_0;
    cpu->eax += cpu->edx;
    cpu->ecx += 0x50u;
    if (cpu->eax < *(uint32_t*)(cpu->ebx + 0x5Cu)) goto label_00084603;
label_00084616:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00484620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0u) goto label_0008467C;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00084634:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00084634;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0008467C;
    cpu->edx = 0x7A4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48464Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48464Eu));
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00084653:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00084653;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484663u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x484663u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    label_00084670:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00084670;
    goto label_00084682;
    label_0008467C:
    *(uint32_t*)(cpu->edi) = 0u;
    label_00084682:
    if (cpu->ebx == 0u) goto label_0008469E;
    cpu->edx = 0x7AAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484695u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484695u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48469Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48469Bu));
    cpu->esp += 4u;
    label_0008469E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004846B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->esi + 0x17Cu) == cpu->ebp) goto label_00084732;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x180u) <= cpu->ebp) goto label_00084708;
    cpu->edi = 0u;
    label_000846D0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x17Cu);
    if (*(uint32_t*)(cpu->edi + cpu->eax) == cpu->ebp) goto label_000846FC;
    cpu->edx = 0x7B7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4846EAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4846EAu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4846F9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4846F9u));
    cpu->esp += 4u;
    label_000846FC:
    ++cpu->ebx;
    cpu->edi += 0x28u;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x180u)) goto label_000846D0;
    label_00084708:
    cpu->edx = 0x7B9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484717u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484717u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x17Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484723u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484723u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x17Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x180u) = cpu->ebp;
    label_00084732:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->edi == cpu->ebp) goto label_00084A07;
    cpu->edx = 0x7BFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48474Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48474Du));
    cpu->eax = cpu->edi;
    cpu->edx = 0x28u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484765u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x484765u));
    x87_v0 = 0.0;
    x87_v1 = 1.0;
    cpu->esp += 4u;
    cpu->ebx = 0u;
    cpu->edx |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x17Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x180u) = cpu->edi;
    if ((int32_t)(cpu->edi) < (int32_t)(4u)) goto label_00084977;
    cpu->ecx = cpu->edi + 0xFFFFFFFCu;
    cpu->ecx >>= 2u;
    cpu->eax = 0u;
    ++cpu->ecx;
    cpu->ebx = cpu->ecx * 4u;
    label_00084796:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + cpu->ebp) = 0u;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ebp + 4u) = cpu->edx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 8u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0xCu) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x10u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x14u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x18u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x1Cu) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x20u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x24u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x28u) = 0u;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x2Cu) = cpu->edx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x30u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x34u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x38u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x3Cu) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x40u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x44u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x48u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x4Cu) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x50u) = 0u;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x54u) = cpu->edx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x58u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x5Cu) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x60u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x64u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x68u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x6Cu) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x70u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0x74u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x78u) = 0u;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x7Cu) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x80u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0x84u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax += 0xA0u;
    --cpu->ecx;
    *(float*)(cpu->eax + cpu->ebp + 0xFFFFFFE8u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0xFFFFFFECu) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0xFFFFFFF0u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ebp + 0xFFFFFFF4u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0xFFFFFFF8u) = x87_v1;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ebp + 0xFFFFFFFCu) = x87_v1;
    if (cpu->ecx != 0u) goto label_00084796;
    label_00084977:
    if (cpu->ebx >= cpu->edi) goto label_00084A03;
    cpu->eax = cpu->ebx + (cpu->ebx * 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edi -= cpu->ebx;
    label_0008498A:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + cpu->ecx) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(uint32_t*)(cpu->eax + cpu->ecx + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ecx + 8u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ecx + 0xCu) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax += 0x28u;
    --cpu->edi;
    *(float*)(cpu->eax + cpu->ecx + 0xFFFFFFE8u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ecx + 0xFFFFFFECu) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ecx + 0xFFFFFFF0u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    *(float*)(cpu->eax + cpu->ecx + 0xFFFFFFF4u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ecx + 0xFFFFFFF8u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x17Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + cpu->ecx + 0xFFFFFFFCu) = x87_v1;
    if (cpu->edi != 0u) goto label_0008498A;
    label_00084A03:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00084A07:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00484A10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x2Cu) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_00084A43;
    cpu->edx = 0x7FEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484A29u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484A29u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484A32u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x484A32u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = 0u;
    *(uint32_t*)(cpu->esi + 0x30u) = 0u;
    label_00084A43:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi == 0u) goto label_00084A7B;
    cpu->edx = 0x805u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484A5Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x484A5Au));
    cpu->eax = cpu->edi;
    cpu->edx = 0xCu;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x484A72u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x484A72u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    label_00084A7B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84AA9u), LIFT_CODE_TOKEN_RVA(0x84AA7u))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) * (3.0518509447574615e-05));
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x68u)));
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esi + 0x6Cu)));
label_00084AC5:
    *(float*)(cpu->edi + 0x2Cu) = x87_v0; 
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84ACAu), LIFT_CODE_TOKEN_RVA(0x84AC8u))) { return; }
    cpu->ecx = 0xFEu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->edi + 0x34u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84AD7u), LIFT_CODE_TOKEN_RVA(0x84AD5u))) { return; }
    *(uint16_t*)(cpu->edi + 0x38u) = cpu->eax & 0xFFFFu;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84ADDu), LIFT_CODE_TOKEN_RVA(0x84ADBu))) { return; }
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
     if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84BB8u), LIFT_CODE_TOKEN_RVA(0x84BB6u))) { return; }
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
        default: lift_trap(cpu, 0x484BFCu, "resolved jump-table index out of range"); return;
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84C2Cu), LIFT_CODE_TOKEN_RVA(0x84C2Au))) { return; }
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
     if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84CCEu), LIFT_CODE_TOKEN_RVA(0x84CCCu))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84CD4u), LIFT_CODE_TOKEN_RVA(0x84CD2u))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84D48u), LIFT_CODE_TOKEN_RVA(0x84D46u))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84D6Au), LIFT_CODE_TOKEN_RVA(0x84D68u))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84DE4u), LIFT_CODE_TOKEN_RVA(0x84DE2u))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84E06u), LIFT_CODE_TOKEN_RVA(0x84E04u))) { return; }
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
     if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84F1Du), LIFT_CODE_TOKEN_RVA(0x84F1Bu))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x10u)));
     value_43 = x87_p0; value_6 = value_43; goto label_0008519B;
label_00084F3B:
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84F3Du), LIFT_CODE_TOKEN_RVA(0x84F3Bu))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84F8Du), LIFT_CODE_TOKEN_RVA(0x84F8Bu))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x10u)));
     value_44 = x87_p0; value_6 = value_44; goto label_0008519B;
label_00084FAB:
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FADu), LIFT_CODE_TOKEN_RVA(0x84FABu))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FB3u), LIFT_CODE_TOKEN_RVA(0x84FB1u))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FDDu), LIFT_CODE_TOKEN_RVA(0x84FDBu))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x84FE3u), LIFT_CODE_TOKEN_RVA(0x84FE1u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    x87_p0 = (x87_p0) * (3.0518509447574615e-05);
    x87_p1 = (double)*(float*)(cpu->esi + 0x10u);
    x87_p1 = (x87_p1) * (0.5);
    x87_p0 = x87_p0 * x87_p1; 
    *(float*)(cpu->edi + 0x14u) = x87_p0; 
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85007u), LIFT_CODE_TOKEN_RVA(0x85005u))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x8500Du), LIFT_CODE_TOKEN_RVA(0x8500Bu))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85033u), LIFT_CODE_TOKEN_RVA(0x85031u))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85055u), LIFT_CODE_TOKEN_RVA(0x85053u))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x850C8u), LIFT_CODE_TOKEN_RVA(0x850C6u))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x850CEu), LIFT_CODE_TOKEN_RVA(0x850CCu))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x850F4u), LIFT_CODE_TOKEN_RVA(0x850F2u))) { return; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (3.0518509447574615e-05));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x28u))) * (6.283185958862305));
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x85116u), LIFT_CODE_TOKEN_RVA(0x85114u))) { return; }
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
__declspec(noinline) void sfera_sub_00485430(LiftCpu* cpu, uint32_t stop_address) { double x87_p0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x78u;
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->edx = 0x93u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485479u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x485479u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485480u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x485480u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    if (cpu->eax == cpu->ebx) goto label_0008549F;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48549Bu)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x48549Bu));
    cpu->edi = cpu->eax;
    goto label_000854A1;
    label_0008549F:
    cpu->edi = 0u;
    label_000854A1:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x88u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4854B9u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4854B9u));
    if (cpu->eax == 0u) goto label_000854C9;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4854C5u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4854C5u));
    if ((int32_t)cpu->eax > (int32_t)cpu->ebx) goto label_000854F3;
    label_000854C9:
    cpu->edx = 0x99u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4854D8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4854D8u));
    if (cpu->edi == cpu->ebx) goto label_000854EC;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4854E3u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4854E3u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4854E9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4854E9u));
    cpu->esp += 4u;
    label_000854EC:
    cpu->eax = 0u;
    goto label_000856A5;
    label_000854F3:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4854FFu)); sfera_sub_0042E000(cpu, LIFT_CODE_TOKEN_VA(0x4854FFu));
    lift_push32(cpu, 0x30u);
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x485507u));
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485517u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x485517u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485523u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x485523u));
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000855B4;
    cpu->ebp = cpu->esi + 0x10u;
    label_00085534:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %d %d %d %d"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8555Au), LIFT_CODE_TOKEN_RVA(0x85558u))) { return; }
    x87_p0 = (double)*(float*)(cpu->esp + 0x44u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x38u);
    *(float*)(cpu->esp + 0x64u) = x87_p0; 
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x3Cu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x40u));
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x48u);
    cpu->esp += 0x20u;
    *(uint8_t*)(cpu->esp + 0x55u) = cpu->edx & 0xFFu;
    cpu->edx = cpu->esp + 0x44u;
    *(uint8_t*)(cpu->esp + 0x56u) = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0x5Bu) = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x50u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4855A0u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x4855A0u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4855ACu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4855ACu));
    if (cpu->eax != 0u) goto label_00085534;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000855B4:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4855BCu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4855BCu));
    lift_push32(cpu, (uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4855C8u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4855C8u));
    if (cpu->eax == 0u) goto label_0008569C;
    cpu->ebp = cpu->esi + 0x10u;
    label_000855D3:
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8560Du), LIFT_CODE_TOKEN_RVA(0x8560Bu))) { return; }
    x87_p0 = (double)*(float*)(cpu->esp + 0x54u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x48u);
    *(float*)(cpu->esp + 0x74u) = x87_p0; 
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x50u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x4Cu);
    *(uint8_t*)(cpu->esp + 0x84u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->esp + 0x58u);
    *(uint8_t*)(cpu->esp + 0x86u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x68u);
    *(uint8_t*)(cpu->esp + 0x85u) = cpu->eax & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->esp + 0x6Cu);
    *(uint8_t*)(cpu->esp + 0x87u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->esp + 0x60u);
    *(uint8_t*)(cpu->esp + 0x89u) = cpu->ecx & 0xFFu;
    cpu->esp += 0x30u;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->eax & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->esp + 0x34u);
    cpu->ecx = cpu->esp + 0x44u;
    *(uint8_t*)(cpu->esp + 0x5Au) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x50u) = 1u;
    *(uint8_t*)(cpu->esp + 0x63u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485688u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x485688u));
    lift_push32(cpu, (uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485694u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x485694u));
    if (cpu->eax != 0u) goto label_000855D3;
    label_0008569C:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4856A3u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x4856A3u));
    cpu->eax = cpu->edi;
    label_000856A5:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004856D0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; double x87_v0;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = 0u;
    if (cpu->eax == cpu->edx) goto label_00085AE3;
    if (*(uint32_t*)(cpu->edi + 0x90u) == cpu->edx) goto label_00085AE3;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if (cpu->ecx >= 0x2710u) goto label_00085AE3;
    lift_test[0]=(*(uint8_t*)(cpu->edi + 8u)&0x20u)==0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0x4Cu);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x48u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x44u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if (lift_test[0]) goto label_00085779;
    if (*(uint32_t*)(cpu->eax + 0x28u) <= cpu->edx) goto label_000857BF;
    cpu->ecx = 0u;
    label_00085730:
    cpu->eax = *(uint32_t*)(cpu->eax + 0x30u);
    x87_v0 = (double)*(float*)(cpu->eax + cpu->ecx);
    ++cpu->edx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edi + 0x44u)));
    cpu->ecx += 0xCu;
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->eax + cpu->ecx + 0xFFFFFFF8u))) + (((double)*(float*)(cpu->edi + 0x48u))));
    x87_v0 = (double)*(float*)(cpu->eax + cpu->ecx + 0xFFFFFFFCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edi + 0x4Cu)));
    *(uint32_t*)(cpu->ecx + cpu->esi + 0xFFFFFFF4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->ecx + cpu->esi + 0xFFFFFFF8u) = cpu->eax;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->ecx + cpu->esi + 0xFFFFFFFCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->edx < *(uint32_t*)(cpu->eax + 0x28u)) goto label_00085730;
    goto label_000857BF;
    label_00085779:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if (*(uint32_t*)(cpu->eax + 0x28u) <= cpu->edx) goto label_000857BF;
    cpu->ebp = 0u;
    label_00085784:
    cpu->eax = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebp);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ebp + 8u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi + 0x50u;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4857A4u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x4857A4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    ++cpu->ecx;
    cpu->ebp += 0xCu;
    cpu->esi += 0xCu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->ecx < *(uint32_t*)(cpu->eax + 0x28u)) goto label_00085784;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    label_000857BF:
    if (((*(uint32_t*)(cpu->edi + 8u)) & (0x4000u)) == 0u) goto label_000857FE;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->ecx + 0x2Cu) <= cpu->eax) goto label_00085804;
    label_000857D2:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x34u);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->eax * 8u));
    ++cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edi + 0x24u)));
    *(float*)(cpu->ebx + (cpu->eax * 8u) + 0xFFFFFFF8u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x34u);
    *(float*)(cpu->ebx + (cpu->eax * 8u) + 0xFFFFFFFCu) = ((((double)*(float*)(cpu->ecx + (cpu->eax * 8u) + 0xFFFFFFFCu))) + (((double)*(float*)(cpu->edi + 0x28u))));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax < *(uint32_t*)(cpu->edx + 0x2Cu)) goto label_000857D2;
    goto label_00085804;
    label_000857FE:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x34u);
    label_00085804:
    cpu->eax = 0u;
    if (((*(uint32_t*)(cpu->edi + 8u)) & (0x8000u)) == 0u) goto label_0008588A;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint8_t*)(cpu->edi + 0x2Fu);
    if (*(uint32_t*)(cpu->ecx + 0x28u) <= cpu->eax) goto label_000858D6;
    (void)cpu;
    label_00085820:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x40u);
    cpu->edx = *(uint8_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x2Cu);
    cpu->edx *= cpu->ecx;
    cpu->edx = (uint32_t)((int32_t)cpu->edx >> 8u);
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u)) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x40u);
    cpu->edx = *(uint8_t*)(cpu->ecx + (cpu->eax * 4u) + 1u);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x2Du);
    cpu->edx *= cpu->ecx;
    cpu->edx = (uint32_t)((int32_t)cpu->edx >> 8u);
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u) + 1u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x40u);
    cpu->edx = *(uint8_t*)(cpu->ecx + (cpu->eax * 4u) + 2u);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x2Eu);
    cpu->edx *= cpu->ecx;
    cpu->edx = (uint32_t)((int32_t)cpu->edx >> 8u);
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u) + 2u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x40u);
    cpu->edx = *(uint8_t*)(cpu->ecx + (cpu->eax * 4u) + 3u);
    cpu->edx *= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u) + 3u) = cpu->edx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    ++cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 0x28u)) goto label_00085820;
    goto label_000858D6;
    label_0008588A:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    if (*(uint32_t*)(cpu->edx + 0x28u) <= cpu->eax) goto label_000858D6;
    label_00085892:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->ecx = *(uint8_t*)(cpu->edx + (cpu->eax * 4u));
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u)) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x40u);
    cpu->edx = *(uint8_t*)(cpu->ecx + (cpu->eax * 4u) + 1u);
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u) + 1u) = cpu->edx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->ecx = *(uint8_t*)(cpu->edx + (cpu->eax * 4u) + 2u);
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u) + 2u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x40u);
    cpu->edx = *(uint8_t*)(cpu->ecx + (cpu->eax * 4u) + 3u);
    *(uint8_t*)(cpu->ebp + (cpu->eax * 4u) + 3u) = cpu->edx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    ++cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 0x28u)) goto label_00085892;
    label_000858D6:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if (*(uint32_t*)(cpu->edx + 0x24u) <= cpu->ecx) goto label_00085AE0;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    goto label_000858F4;
    label_000858F0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    label_000858F4:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax + 0x38u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x3Cu);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->ebp = cpu->eax;
    cpu->edx += cpu->ecx;
    ++cpu->eax;
    cpu->esi += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    if ((int32_t)cpu->ebp >= 0) goto label_00085924;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485920u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x485920u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00085924:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_0008593C;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485938u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x485938u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0008593C:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x94u);
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebp += g_sfera_effect_manager.render_slots.data;
    cpu->eax = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0x90u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x98u);
    *(uint32_t*)(cpu->eax + 0x98u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    *(uint32_t*)(cpu->eax + 0x94u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u);
    cpu->ebp = *(uint8_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 1u);
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 2u);
    *(uint32_t*)(cpu->eax + 0x50u) = cpu->ebp;
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    *(uint32_t*)(cpu->eax + 0x60u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u);
    cpu->ebp = *(uint8_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 1u);
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 2u);
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->ebp;
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    *(uint32_t*)(cpu->eax + 0x64u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u);
    cpu->ebp = *(uint8_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 1u);
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 2u);
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->ebp;
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 0x68u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u);
    cpu->ebp = *(uint8_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 1u);
    *(uint32_t*)(cpu->eax + 0x4Cu) = cpu->ebp;
    cpu->ebp = *(uint8_t*)(cpu->ecx + 2u);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->ebp;
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 0x6Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u);
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u);
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u);
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = cpu->esi + (cpu->esi * 2u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->esi + (cpu->ecx * 4u);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->ecx * 8u));
    *(uint32_t*)(cpu->eax + 0x70u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebx + (cpu->ecx * 8u) + 4u);
    *(uint32_t*)(cpu->eax + 0x74u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->ecx * 8u));
    *(uint32_t*)(cpu->eax + 0x78u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebx + (cpu->ecx * 8u) + 4u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x10u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->ecx * 8u));
    *(uint32_t*)(cpu->eax + 0x80u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebx + (cpu->ecx * 8u) + 4u);
    *(uint32_t*)(cpu->eax + 0x84u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebx + (cpu->edx * 8u));
    *(uint32_t*)(cpu->eax + 0x88u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + (cpu->edx * 8u) + 4u);
    *(uint32_t*)(cpu->eax + 0x8Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 0x24u)) goto label_000858F0;
    label_00085AE0:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00085AE3:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00485AF0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xC0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xE4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xE8u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xECu);
    cpu->ebx = cpu->ecx;
    cpu->ecx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485B56u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x485B56u));
    cpu->edx = 0x379u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485B65u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x485B65u));
    lift_push32(cpu, 0x200u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485B6Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x485B6Fu));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->eax;
    lift_push32(cpu, (uintptr_t)"effectmesh_name");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485B85u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485B85u));
    if (cpu->eax == 0u) goto label_00085B9F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485B93u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x485B93u));
    if (cpu->eax == 0u) goto label_00085B9F;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x85B9Fu)); sfera_sub_00483B60(cpu, LIFT_CODE_TOKEN_RVA(0x85B9Fu));
    label_00085B9F:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"effectmesh_ssm");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485BACu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485BACu));
    if (cpu->eax == 0u) goto label_00085BCA;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485BBAu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x485BBAu));
    if (cpu->eax == 0u) goto label_00085BCA;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485BC5u)); sfera_sub_00425A50(cpu, LIFT_CODE_TOKEN_VA(0x485BC5u));
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    goto label_00085BE5;
    label_00085BCA:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CEffectMesh::LoadScript(%s) -> SSM Mesh not specified in effectMesh '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485BDCu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x485BDCu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485BE2u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x485BE2u));
    cpu->esp += 0x10u;
    label_00085BE5:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"effectmesh_flags");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485BF2u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485BF2u));
    if (cpu->eax == 0u) goto label_00085C3C;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485BFDu)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x485BFDu));
    cpu->esi = cpu->eax;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    if ((int32_t)cpu->esi <= 0) goto label_00085C38;
    label_00085C10:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485C1Du)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x485C1Du));
    if (cpu->eax == 0u) goto label_00085C31;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485C2Au)); sfera_sub_004827E0(cpu, LIFT_CODE_TOKEN_VA(0x485C2Au));
    *(uint32_t*)(cpu->ebx + 8u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 8u)) | (uint64_t)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    label_00085C31:
    cpu->ebp += 2u;
    if ((int32_t)cpu->ebp < (int32_t)cpu->esi) goto label_00085C10;
    label_00085C38:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    label_00085C3C:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"self_illumination");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485C49u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485C49u));
    if (cpu->eax == 0u) goto label_00085C59;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485C56u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x485C56u));
    *(uint32_t*)(cpu->ebx + 0x30u) = cpu->eax;
    label_00085C59:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"color");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485C66u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485C66u));
    if (cpu->eax == 0u) goto label_00085C8C;
    cpu->ecx = cpu->ebx + 0x2Fu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx + 0x2Eu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x2Du;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x485C83u));
    cpu->esp += 0x18u;
    label_00085C8C:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"rotation_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485CA0u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x485CA0u));
    if (cpu->eax == 0u) goto label_00085E5D;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485CB9u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485CB9u));
    if (cpu->eax == 0u) goto label_00085E5D;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485CCAu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x485CCAu));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_00085E5D;
    cpu->edx = 0x3ABu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485CE3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x485CE3u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485CEAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x485CEAu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_00085D07;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485D05u)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x485D05u));
    goto label_00085D09;
    label_00085D07:
    cpu->eax = 0u;
    label_00085D09:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xE0u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485D1Fu)); sfera_sub_0042E000(cpu, LIFT_CODE_TOKEN_VA(0x485D1Fu));
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485D2Bu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x485D2Bu));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485D3Fu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x485D3Fu));
    if (cpu->eax == 0u) goto label_00085E09;
    cpu->ebp = cpu->edi + 0x10u;
    label_00085D50:
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x485D6Fu));
    *(float*)(cpu->esp + 0x8Cu) = (double)*(float*)(cpu->esp + 0x80u);
    cpu->esp += 0x1Cu;
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    x87_v1 = 0.01745329424738884;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x60u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x4Cu)));
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edx;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u);
    cpu->edx = cpu->esp + 0x70u;
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485DF5u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x485DF5u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485E01u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x485E01u));
    if (cpu->eax != 0u) goto label_00085D50;
    label_00085E09:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485E10u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x485E10u));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485E21u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485E21u));
    if (cpu->eax == 0u) goto label_00085E59;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485E33u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x485E33u));
    if (cpu->eax == 0u) goto label_00085E59;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_00085E53;
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x485E45u));
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    ++cpu->eax;
    label_00085E53:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xCu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_00085E59:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    label_00085E5D:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"scale_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485E71u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x485E71u));
    if (cpu->eax == 0u) goto label_00086006;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485E8Au)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485E8Au));
    if (cpu->eax == 0u) goto label_00086006;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485E9Bu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x485E9Bu));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_00086006;
    cpu->edx = 0x3CBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485EB4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x485EB4u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485EBBu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x485EBBu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0xDCu) = 1u;
    if (cpu->eax == cpu->esi) goto label_00085EDC;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485EDAu)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x485EDAu));
    goto label_00085EDE;
    label_00085EDC:
    cpu->eax = 0u;
    label_00085EDE:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xE0u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485EF4u)); sfera_sub_0042E000(cpu, LIFT_CODE_TOKEN_VA(0x485EF4u));
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485F00u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x485F00u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485F14u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x485F14u));
    if (cpu->eax == 0u) goto label_00085FB2;
    cpu->ebp = cpu->edi + 0x10u;
    (void)cpu;
    label_00085F20:
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x485F3Fu));
    *(float*)(cpu->esp + 0x8Cu) = (double)*(float*)(cpu->esp + 0x54u);
    cpu->esp += 0x1Cu;
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edx;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x4Cu);
    cpu->edx = cpu->esp + 0x70u;
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485F9Eu)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x485F9Eu));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485FAAu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x485FAAu));
    if (cpu->eax != 0u) goto label_00085F20;
    label_00085FB2:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485FB9u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x485FB9u));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485FCAu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x485FCAu));
    if (cpu->eax == 0u) goto label_00086002;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x485FDCu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x485FDCu));
    if (cpu->eax == 0u) goto label_00086002;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_00085FFC;
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x485FEEu));
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    ++cpu->eax;
    label_00085FFC:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_00086002:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    label_00086006:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"position_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48601Au)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x48601Au));
    if (cpu->eax == 0u) goto label_000861B9;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486033u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x486033u));
    if (cpu->eax == 0u) goto label_000861B9;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486044u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x486044u));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_000861B9;
    cpu->edx = 0x3EAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48605Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48605Du));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486064u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x486064u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0xDCu) = 2u;
    if (cpu->eax == cpu->esi) goto label_00086085;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486083u)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x486083u));
    goto label_00086087;
    label_00086085:
    cpu->eax = 0u;
    label_00086087:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xE0u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x14u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48609Du)); sfera_sub_0042E000(cpu, LIFT_CODE_TOKEN_VA(0x48609Du));
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4860A9u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4860A9u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xA8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4860C0u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4860C0u));
    if (cpu->eax == 0u) goto label_00086165;
    cpu->ebp = cpu->edi + 0x10u;
    label_000860D0:
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4860EFu));
    *(float*)(cpu->esp + 0xBCu) = (double)*(float*)(cpu->esp + 0x74u);
    cpu->esp += 0x1Cu;
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 0x5Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esp + 0xB8u) = cpu->edx;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x48u);
    cpu->edx = cpu->esp + 0xA0u;
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0xC4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486151u)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x486151u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48615Du)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x48615Du));
    if (cpu->eax != 0u) goto label_000860D0;
    label_00086165:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48616Cu)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x48616Cu));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48617Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48617Du));
    if (cpu->eax == 0u) goto label_000861B5;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48618Fu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x48618Fu));
    if (cpu->eax == 0u) goto label_000861B5;
    if (cpu->esi != 0u) goto label_0008619B;
    cpu->eax = 0u;
    goto label_000861AF;
    label_0008619B:
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4861A1u));
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    ++cpu->eax;
    label_000861AF:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x14u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    label_000861B5:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    label_000861B9:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4861CDu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4861CDu));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x44u);
    if (cpu->eax == 0u) goto label_000861E9;
    lift_push32(cpu, (uintptr_t)"effectmesh->color_track"); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4861E6u)); sfera_sub_00485430(cpu, LIFT_CODE_TOKEN_VA(0x4861E6u));
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    label_000861E9:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ucoord_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4861FDu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4861FDu));
    if (cpu->eax == 0u) goto label_00086215;
    lift_push32(cpu, (uintptr_t)"effectmesh->ucoord_track"); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486212u)); sfera_sub_00482B00(cpu, LIFT_CODE_TOKEN_VA(0x486212u));
    *(uint32_t*)(cpu->ebx + 0x18u) = cpu->eax;
    label_00086215:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"vcoord_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486229u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x486229u));
    if (cpu->eax == 0u) goto label_00086241;
    lift_push32(cpu, (uintptr_t)"effectmesh->vcoord_track"); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48623Eu)); sfera_sub_00482B00(cpu, LIFT_CODE_TOKEN_VA(0x48623Eu));
    *(uint32_t*)(cpu->ebx + 0x1Cu) = cpu->eax;
    label_00086241:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"texture_def");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486255u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x486255u));
    if (cpu->eax == 0u) goto label_000862E2;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"blendmode");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebx + 0x98u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486278u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x486278u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_000862B7;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48628Au)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x48628Au));
    if (cpu->eax == 0u) goto label_000862B7;
    cpu->ebp = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"PS_BLENDADD"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x8629Cu), LIFT_CODE_TOKEN_RVA(0x8629Au))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000862AC;
    *(uint32_t*)(cpu->ebx + 0x98u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 0x98u)) | (uint64_t)(1u);
    goto label_000862B7;
    label_000862AC:
    lift_push32(cpu, (uintptr_t)"PS_BLENDALPHA"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x862B4u), LIFT_CODE_TOKEN_RVA(0x862B2u))) { return; }
    cpu->esp += 8u;
    label_000862B7:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4862C8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4862C8u));
    if (cpu->eax == 0u) goto label_000862E2;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4862D6u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4862D6u));
    if (cpu->eax == 0u) goto label_000862E2;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x862E2u)); sfera_sub_00483BF0(cpu, LIFT_CODE_TOKEN_RVA(0x862E2u));
    label_000862E2:
    cpu->ebp = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x862EAu), LIFT_CODE_TOKEN_RVA(0x862E8u))) { return; }
    cpu->ecx = 0xFFu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->ebx + 0x38u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x862F7u), LIFT_CODE_TOKEN_RVA(0x862F5u))) { return; }
    *(uint32_t*)(cpu->ebx + 0x3Cu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x862FCu), LIFT_CODE_TOKEN_RVA(0x862FAu))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x90u);
    *(uint32_t*)(cpu->ebx + 0x40u) = cpu->eax;
    if (cpu->ecx == 0u) goto label_00086333;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48630Eu)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x48630Eu));
    *(uint32_t*)(cpu->ebx + 0x94u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_00086333;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CEffectMesh::Initialize() -> Texture '%s' not found");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48632Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x48632Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486330u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x486330u));
    cpu->esp += 0xCu;
    label_00086333:
    cpu->edx = 0x424u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486342u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x486342u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48634Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48634Cu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48635Bu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x48635Bu));
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00486390(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x44u);
    cpu->edi = 0u;
    cpu->eax = cpu->esi + 8u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4863A0u));
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    cpu->esp += 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 8u) = x87_v0;
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    *(float*)(cpu->esi + 0x6Cu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esi + 0x68u) = x87_v0;
    *(float*)(cpu->esi + 0x70u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0xBCu) = cpu->ecx;
    x87_v1 = 1.0;
    *(uint32_t*)(cpu->esi + 0xC0u) = cpu->edx;
    *(float*)(cpu->esi + 0x7Cu) = x87_v1;
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 8u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0xC4u) = cpu->eax;
    *(float*)(cpu->esp + 0xCu) = x87_v1;
    cpu->eax = 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0x10u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 8u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x98u) = cpu->ecx;
    *(float*)(cpu->esp + 0xCu) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x9Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 8u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0xA0u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0xCu) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x8Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 8u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 0xA8u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x78u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x80u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->edi;
    *(uint8_t*)(cpu->esi + 0xD4u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xACu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xE4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0xD8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0xE8u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 8u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0xF0u) = cpu->ecx;
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0xF8u) = cpu->ecx;
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0xF4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0xFCu) = cpu->edx;
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 8u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x100u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x104u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x108u) = cpu->ecx;
    *(float*)(cpu->esi + 0x184u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esi + 0x110u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x10Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 0x15Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x160u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x164u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x168u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x16Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x170u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x174u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x178u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x180u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x17Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x188u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x18Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x114u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x74u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x190u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x118u) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004865F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->esi + 4u) == cpu->ebp) goto label_00086620;
    cpu->edx = 0x7DAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48660Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48660Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486614u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x486614u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ebp;
    label_00086620:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->edi == cpu->ebp) goto label_0008669A;
    cpu->edx = 0x7E2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x486637u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x486637u));
    cpu->eax = cpu->edi;
    cpu->edx = 0x50u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48664Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48664Fu));
    cpu->ecx = cpu->edi + (cpu->edi * 4u);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ebp;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x486661u));
    cpu->esp += 0x10u;
    if (cpu->edi <= cpu->ebp) goto label_0008669A;
    cpu->ecx = 0u;
    cpu->edx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebx);
    label_00086673:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax += cpu->ecx;
    cpu->ebx = 0xFFFFu;
    cpu->ecx += 0x50u;
    --cpu->edi;
    *(uint16_t*)(cpu->eax + 0x3Cu) = cpu->ebx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + 0x3Eu) = cpu->ebx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + 0x40u) = cpu->ebx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + 0x42u) = cpu->ebx & 0xFFFFu;
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0x4Cu) = cpu->edx;
    if (cpu->edi != 0u) goto label_00086673;
    cpu->ebx = lift_pop32(cpu);
    label_0008669A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
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
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x87073u), LIFT_CODE_TOKEN_RVA(0x87071u))) { return; }
    cpu->edi = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x87077u), LIFT_CODE_TOKEN_RVA(0x87075u))) { return; }
    cpu->edi -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(float*)(cpu->esi + 0xCu) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (3.0518509447574615e-05)))) * (((double)*(float*)(cpu->ebp + 0xA4u)))))) + (((double)*(float*)(cpu->esi + 0xCu))));
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x87095u), LIFT_CODE_TOKEN_RVA(0x87093u))) { return; }
    cpu->edi = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x87099u), LIFT_CODE_TOKEN_RVA(0x87097u))) { return; }
    cpu->edi -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(float*)(cpu->esi + 0x10u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (3.0518509447574615e-05)))) * (((double)*(float*)(cpu->ebp + 0xA8u)))))) + (((double)*(float*)(cpu->esi + 0x10u))));
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x870B7u), LIFT_CODE_TOKEN_RVA(0x870B5u))) { return; }
    cpu->edi = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x870BBu), LIFT_CODE_TOKEN_RVA(0x870B9u))) { return; }
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
__declspec(noinline) void sfera_sub_00487D50(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26, value_27, value_28, value_29, value_30, value_31, value_32, value_33, value_34, value_35, value_36, value_37, value_38, value_39, value_40, value_41, value_42, value_43, value_44, value_45, value_46, value_47, value_48, value_49, value_50, value_51, value_52, value_53, value_54, value_55, value_56, value_57, value_58;
 bool lift_test[2]; bool sub_pred[1]; double x87_p0, x87_p1, x87_p2, x87_p3;
    bool lift_cmp[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x88u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487DAFu)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x487DAFu));
    cpu->edx = 0x4D7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487DBEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x487DBEu));
    lift_push32(cpu, 0x200u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487DC8u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x487DC8u));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"psystem_name");
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487DDCu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487DDCu));
    if (cpu->eax == 0u) goto label_000897E3;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487DF2u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x487DF2u));
    if (cpu->eax == 0u) goto label_000897E3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E06u)); sfera_sub_00484620(cpu, LIFT_CODE_TOKEN_VA(0x487E06u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"particles_num");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E13u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487E13u));
    if (cpu->eax == 0u) goto label_000897E3;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E24u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x487E24u));
    if (cpu->eax == 0u) goto label_000897E3;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E34u)); sfera_sub_004865F0(cpu, LIFT_CODE_TOKEN_VA(0x487E34u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"psystem_flags");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E41u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487E41u));
    if (cpu->eax == 0u) goto label_00087E92;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E4Cu)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x487E4Cu));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    if ((int32_t)cpu->eax <= 0) goto label_00087E8E;
label_00087E60:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E6Du)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x487E6Du));
    if (cpu->eax == 0u) goto label_00087E81;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E7Au)); sfera_sub_004827E0(cpu, LIFT_CODE_TOKEN_VA(0x487E7Au));
    *(uint32_t*)(cpu->edi + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x4Cu)) | (uint64_t)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
label_00087E81:
    cpu->esi += 2u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x34u)) goto label_00087E60;
label_00087E8E:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3Cu);
label_00087E92:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec0");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487E9Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487E9Fu));
    if (cpu->eax == 0u) goto label_00087ECA;
    cpu->edx = cpu->edi + 0xF4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0xF0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0xECu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487EC1u));
    cpu->esp += 0x14u;
label_00087ECA:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec1");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487ED7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487ED7u));
    if (cpu->eax == 0u) goto label_00087F02;
    cpu->eax = cpu->edi + 0x100u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0xFCu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0xF8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487EF9u));
    cpu->esp += 0x14u;
label_00087F02:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec2");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487F0Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487F0Fu));
    if (cpu->eax == 0u) goto label_00087F3A;
    cpu->ecx = cpu->edi + 0x10Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x108u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x104u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487F31u));
    cpu->esp += 0x14u;
label_00087F3A:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec3");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487F47u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487F47u));
    if (cpu->eax == 0u) goto label_00087F72;
    cpu->edx = cpu->edi + 0x118u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x114u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x110u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487F69u));
    cpu->esp += 0x14u;
label_00087F72:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"distortion_vec");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487F7Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487F7Fu));
    if (cpu->eax == 0u) goto label_00087FAA;
    cpu->eax = cpu->edi + 0xACu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0xA8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0xA4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487FA1u));
    cpu->esp += 0x14u;
label_00087FAA:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"self_illumination");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487FB7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487FB7u));
    if (cpu->eax == 0u) goto label_00087FCA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487FC4u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x487FC4u));
    *(uint32_t*)(cpu->edi + 0xE4u) = cpu->eax;
label_00087FCA:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"power");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487FD7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x487FD7u));
    if (cpu->eax == 0u) goto label_00087FE7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487FE4u)); value_52 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x487FE4u));
    *(float*)(cpu->edi + 0x7Cu) = value_52; 
label_00087FE7:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"power_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x487FFBu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x487FFBu));
    if (cpu->eax == 0u) goto label_00088017;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->power_trac"); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488014u)); sfera_sub_00482B00(cpu, LIFT_CODE_TOKEN_VA(0x488014u));
    *(uint32_t*)(cpu->edi + 0x78u) = cpu->eax;
label_00088017:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"position_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48802Bu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x48802Bu));
    if (cpu->eax == 0u) goto label_00088047;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->position_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488044u)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x488044u));
    *(uint32_t*)(cpu->edi + 0x58u) = cpu->eax;
label_00088047:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"scale_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48805Bu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x48805Bu));
    if (cpu->eax == 0u) goto label_00088077;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->scale_track"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488074u)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x488074u));
    *(uint32_t*)(cpu->edi + 0x54u) = cpu->eax;
label_00088077:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"rotation_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48808Bu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x48808Bu));
    if (cpu->eax == 0u) goto label_0008822B;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4880A4u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4880A4u));
    if (cpu->eax == 0u) goto label_0008822B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4880B5u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4880B5u));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_0008822B;
    cpu->edx = 0x534u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4880D0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4880D0u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4880D7u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4880D7u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xA0u) = 0u;
    if (cpu->eax == 0u) goto label_000880F6;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4880F4u)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x4880F4u));
    goto label_000880F8;
label_000880F6:
    cpu->eax = 0u;
label_000880F8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xA4u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->edi + 0x50u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488112u)); sfera_sub_0042E000(cpu, LIFT_CODE_TOKEN_VA(0x488112u));
    lift_push32(cpu, 0x30u);
    cpu->edx = cpu->esp + 0x64u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48811Bu));
    cpu->esp += 0xCu;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x68u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488137u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x488137u));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48814Bu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x48814Bu));
    if (cpu->eax == 0u) goto label_000881EE;
label_00088153:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x488175u));
    *(float*)(cpu->esp + 0x7Cu) = (double)*(float*)(cpu->esp + 0x4Cu);
    cpu->esp += 0x1Cu;
    x87_p0 = (double)*(float*)(cpu->esp + 0x54u);
    x87_p1 = 0.01745329424738884;
    x87_p0 = (x87_p0) * (x87_p1);
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x48u) = x87_p1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->eax;
    x87_p1 = (x87_p1) * (x87_p0);
    cpu->eax = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x50u) = x87_p1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ecx;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x28u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x50u);
    *(float*)(cpu->esp + 0x58u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4881DAu)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x4881DAu));
    lift_push32(cpu, (uintptr_t)"key");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4881E6u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4881E6u));
    if (cpu->eax != 0u) goto label_00088153;
label_000881EE:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4881F5u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x4881F5u));
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488206u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488206u));
    if (cpu->eax == 0u) goto label_0008822B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488218u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x488218u));
    if (cpu->eax == 0u) goto label_0008822B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488225u)); sfera_sub_00482A30(cpu, LIFT_CODE_TOKEN_VA(0x488225u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x50u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
label_0008822B:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"childs_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48823Fu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x48823Fu));
    if (cpu->eax == 0u) goto label_000883AF;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"childs_num");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488258u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488258u));
    if (cpu->eax == 0u) goto label_0008826B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488265u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488265u));
    *(uint32_t*)(cpu->edi + 0x18Cu) = cpu->eax;
label_0008826B:
    if (*(uint32_t*)(cpu->edi + 0x18Cu) <= 0u) goto label_000883AF;
    cpu->edx = 0x557u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488287u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x488287u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18Cu);
    cpu->edx = 0x14u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4882A3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4882A3u));
    cpu->ecx = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 0x188u) = cpu->eax;
    if (*(uint32_t*)(cpu->edi + 0x18Cu) <= cpu->ecx) goto label_000882F1;
    cpu->eax = 0u;
    cpu->edx |= 0xFFFFFFFFu;
label_000882C0:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x188u);
    *(uint32_t*)(cpu->eax + cpu->esi + 4u) = 0u;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x188u);
    *(uint32_t*)(cpu->eax + cpu->esi) = 0u;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x188u);
    *(uint32_t*)(cpu->eax + cpu->esi + 0x10u) = cpu->edx;
    ++cpu->ecx;
    cpu->eax += 0x14u;
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x18Cu)) goto label_000882C0;
label_000882F1:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4882FDu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4882FDu));
    lift_push32(cpu, (uintptr_t)"child");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488309u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x488309u));
    if (cpu->eax == 0u) goto label_000883A4;
label_00088311:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48831Au)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x48831Au));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48832Au)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x48832Au));
    if (cpu->eax == 0u) goto label_00088390;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->eax + 1u;
label_00088335:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00088335;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00088390;
    cpu->edx = 0x565u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48834Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48834Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->eax + 1u;
label_00088356:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00088356;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488366u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x488366u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x188u);
    cpu->ecx = cpu->esi + (cpu->esi * 4u);
    cpu->ecx += cpu->ecx;
    cpu->esp += 4u;
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x188u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->eax);
label_00088386:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->edx;
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00088386;
label_00088390:
    lift_push32(cpu, (uintptr_t)"child");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48839Cu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x48839Cu));
    if (cpu->eax != 0u) goto label_00088311;
label_000883A4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4883ABu)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x4883ABu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3Cu);
label_000883AF:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"magnite_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4883C3u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4883C3u));
    if (cpu->eax == 0u) goto label_000886B6;
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"magposition_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4883E3u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4883E3u));
    if (cpu->eax == 0u) goto label_00088402;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->magposition_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4883FCu)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x4883FCu));
    *(uint32_t*)(cpu->edi + 0x84u) = cpu->eax;
label_00088402:
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"magfactor_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48841Au)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x48841Au));
    if (cpu->eax == 0u) goto label_0008854C;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->magfactor_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488437u)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x488437u));
    *(uint32_t*)(cpu->edi + 0x80u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0008854C;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->eax + 4u) <= cpu->esi) goto label_0008854C;
label_00088450:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x80u);
    cpu->edx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488461u)); sfera_sub_0042D140(cpu, LIFT_CODE_TOKEN_VA(0x488461u));
    x87_p0 = (double)*(float*)(cpu->esp + 0x78u); x87_p1 = x87_p0;
    x87_p2 = 0.0;
    x87_p3 = x87_p2;
     value_11 = x87_p3; value_12 = x87_p2; value_13 = x87_p1; value_14 = x87_p0; if ((value_11)==(value_13)) goto label_00088484;
    x87_p0 = 1.0;
    x87_p1 = x87_p0;
    value_15 = x87_p1 / value_14; 
    value_50 = x87_p0; x87_p0 = value_15;
    *(float*)(cpu->esp + 0x78u) = x87_p0; 
    value_0 = value_50; goto label_0008848A;
label_00088484:
    value_16 = 1.0;
     value_0 = value_16;
label_0008848A:
    x87_p0 = (double)*(float*)(cpu->esp + 0x7Cu); x87_p1 = x87_p0;
    x87_p2 = value_12;
     value_17 = x87_p2; value_18 = x87_p1; value_19 = x87_p0; if ((value_17)==(value_18)) goto label_000884A3;
    value_20 = (value_0) / (value_19);
    *(float*)(cpu->esp + 0x7Cu) = value_20; 
     value_1 = value_0; goto label_000884A5;
label_000884A3:
      value_1 = value_0;
label_000884A5:
    x87_p0 = (double)*(float*)(cpu->esp + 0x80u); x87_p1 = x87_p0;
    x87_p2 = value_12;
     value_21 = x87_p2; value_22 = x87_p1; value_23 = x87_p0; if ((value_21)==(value_22)) goto label_000884C4;
    value_24 = (value_1) / (value_23);
    *(float*)(cpu->esp + 0x80u) = value_24; 
     value_2 = value_1; goto label_000884C6;
label_000884C4:
      value_2 = value_1;
label_000884C6:
    x87_p0 = (double)*(float*)(cpu->esp + 0x84u); x87_p1 = x87_p0;
    x87_p2 = value_12;
     value_25 = x87_p2; value_26 = x87_p1; value_27 = x87_p0; if ((value_25)==(value_26)) goto label_000884E5;
    value_28 = (value_2) / (value_27);
    *(float*)(cpu->esp + 0x84u) = value_28; 
     value_3 = value_2; goto label_000884E7;
label_000884E5:
      value_3 = value_2;
label_000884E7:
    x87_p0 = (double)*(float*)(cpu->esp + 0x88u); x87_p1 = x87_p0;
    x87_p2 = value_12;
     value_29 = x87_p2; value_30 = x87_p1; value_31 = x87_p0; if ((value_29)==(value_30)) goto label_00088506;
    value_32 = (value_3) / (value_31);
    *(float*)(cpu->esp + 0x88u) = value_32; 
     value_4 = value_3; goto label_00088508;
label_00088506:
      value_4 = value_3;
label_00088508:
    x87_p0 = (double)*(float*)(cpu->esp + 0x8Cu); x87_p1 = x87_p0;
     value_33 = x87_p1; value_34 = x87_p0; if ((value_33)==(value_12)) goto label_00088527;
    value_35 = value_4 / value_34; 
    *(float*)(cpu->esp + 0x8Cu) = value_35; 
     goto label_0008852B;
label_00088527:
label_0008852B:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x80u);
    cpu->eax = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48853Cu)); sfera_sub_0042D160(cpu, LIFT_CODE_TOKEN_VA(0x48853Cu));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x80u);
    ++cpu->esi;
    if (cpu->esi < *(uint32_t*)(cpu->ecx + 4u)) goto label_00088450;
label_0008854C:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"magchildps");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48855Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48855Du));
    if (cpu->eax == 0u) goto label_000885AB;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48856Au)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x48856Au));
    *(uint32_t*)(cpu->edi + 0x88u) = cpu->eax;
    if ((int32_t)cpu->eax < 0) goto label_0008857C;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 0x18Cu)) goto label_00088594;
label_0008857C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CParticleSystem::LoadSc(%s) -> Invalid index in 'magchildps'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48858Bu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x48858Bu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488591u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488591u));
    cpu->esp += 0xCu;
label_00088594:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x88u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x188u);
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    ++*(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 4u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u) + 4u;
label_000885AB:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"magfactor");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4885BCu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4885BCu));
    if (cpu->eax == 0u) goto label_0008867A;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4885DCu));
    x87_p0 = (double)*(float*)(cpu->esp + 0x44u); x87_p1 = x87_p0;
    cpu->esp += 0x14u;
    x87_p2 = 0.0;
    x87_p3 = x87_p2;
    lift_cmp[0]=x87_p3==x87_p1;
    x87_p1 = x87_p2; 
    x87_p2 = 1.0;
     value_36 = x87_p2; value_37 = x87_p1; value_38 = x87_p0; if (lift_cmp[0]) goto label_0008860C;
    x87_p0 = value_36;
    value_39 = x87_p0 / value_38; 
    *(float*)(cpu->esp + 0x30u) = value_39; 
    value_40 = (double)*(float*)(cpu->esp + 0x30u);
    value_5 = value_40; goto label_0008860E;
label_0008860C:
     value_5 = value_38;
label_0008860E:
    x87_p0 = (double)*(float*)(cpu->esp + 0x34u); x87_p1 = x87_p0;
    x87_p2 = value_37;
     value_41 = x87_p2; value_42 = x87_p1; value_43 = x87_p0; { const double lift_left=value_41; const double lift_right=value_42;   if (lift_left==lift_right) { value_6 = value_43; value_7 = value_5; goto label_00088629; } }
    value_44 = (value_36) / (value_43);
    *(float*)(cpu->esp + 0x34u) = value_44; 
    value_45 = (double)*(float*)(cpu->esp + 0x34u); value_6 = value_45; value_7 = value_5;
label_00088629:
    x87_p0 = (double)*(float*)(cpu->esp + 0x38u); x87_p1 = x87_p0;
     value_46 = x87_p1; value_47 = x87_p0; if ((value_46)==(value_37)) goto label_00088CED;
    value_48 = value_36 / value_47; 
    *(float*)(cpu->esp + 0x38u) = value_48; 
    value_49 = (double)*(float*)(cpu->esp + 0x38u);
      value_8 = value_7; value_9 = value_49; value_10 = value_6;
label_0008864E:
    *(float*)(cpu->esp + 0x48u) = value_8; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->edi + 0x8Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x4Cu) = value_10; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->edi + 0x90u) = cpu->eax;
    *(float*)(cpu->esp + 0x50u) = value_9; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->edi + 0x94u) = cpu->ecx;
label_0008867A:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"magpos");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48868Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48868Bu));
    if (cpu->eax == 0u) goto label_000886B6;
    cpu->eax = cpu->edi + 0xA0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x9Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x98u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4886ADu));
    cpu->esp += 0x14u;
label_000886B6:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"emission_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4886CEu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4886CEu));
    if (cpu->eax == 0u) goto label_00088981;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shape");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4886E7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4886E7u));
    if (cpu->eax == 0u) goto label_00088709;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4886F9u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4886F9u));
    if (cpu->eax == 0u) goto label_00088709;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488706u)); sfera_sub_00482A50(cpu, LIFT_CODE_TOKEN_VA(0x488706u));
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
label_00088709:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"randseed");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48871Au)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48871Au));
    if (cpu->eax == 0u) goto label_0008872A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488727u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488727u));
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->eax;
label_0008872A:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"randfactor");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48873Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48873Bu));
    if (cpu->eax == 0u) goto label_0008874B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488748u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488748u));
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
label_0008874B:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"height");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48875Cu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48875Cu));
    if (cpu->eax == 0u) goto label_0008876C;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488769u)); value_53 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x488769u));
    *(float*)(cpu->edi + 0x10u) = value_53; 
label_0008876C:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"width");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48877Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48877Du));
    if (cpu->eax == 0u) goto label_0008878D;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48878Au)); value_54 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x48878Au));
    *(float*)(cpu->edi + 0x14u) = value_54; 
label_0008878D:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"radius");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48879Eu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48879Eu));
    if (cpu->eax == 0u) goto label_000887AE;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4887ABu)); value_55 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4887ABu));
    *(float*)(cpu->edi + 0xCu) = value_55; 
label_000887AE:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"emit_num");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4887BFu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4887BFu));
    if (cpu->eax == 0u) goto label_000887CF;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4887CCu)); value_56 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4887CCu));
    *(float*)(cpu->edi + 0x48u) = value_56; 
label_000887CF:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"direction");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4887E0u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4887E0u));
    if (cpu->eax == 0u) goto label_00088802;
    cpu->eax = cpu->edi + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4887F9u));
    cpu->esp += 0x14u;
label_00088802:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"emitter_pos");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488813u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488813u));
    if (cpu->eax == 0u) goto label_00088835;
    cpu->edx = cpu->edi + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x48882Cu));
    cpu->esp += 0x14u;
label_00088835:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shape_numpoints");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488846u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488846u));
    if (cpu->eax == 0u) goto label_00088919;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488857u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488857u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi <= 0) goto label_00088919;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"shape_points");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488879u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x488879u));
    if (cpu->eax == 0u) goto label_00088919;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488889u)); sfera_sub_00484A10(cpu, LIFT_CODE_TOKEN_VA(0x488889u));
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488895u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x488895u));
    cpu->esi = *(uint32_t*)(cpu->edi + 0x2Cu);
    lift_push32(cpu, (uintptr_t)"point");
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x34u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4888ACu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4888ACu));
    if (cpu->eax == 0u) goto label_00088912;
label_000888B0:
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4888CDu));
    x87_p0 = (double)*(float*)(cpu->esp + 0x3Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    *(float*)(cpu->esi + (cpu->edx * 4u)) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x58u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    *(float*)(cpu->esi + (cpu->eax * 4u) + 4u) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x6Cu);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->esp += 0x18u;
    *(float*)(cpu->esi + (cpu->ecx * 4u) + 8u) = x87_p0; 
    lift_push32(cpu, (uintptr_t)"point");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48890Eu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x48890Eu));
    if (cpu->eax != 0u) goto label_000888B0;
label_00088912:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x88919u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_RVA(0x88919u));
label_00088919:
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"emission_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488931u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x488931u));
    if (cpu->eax == 0u) goto label_0008894D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->emission_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48894Au)); sfera_sub_00482B00(cpu, LIFT_CODE_TOKEN_VA(0x48894Au));
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->eax;
label_0008894D:
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"emissionpos_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488965u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x488965u));
    if (cpu->eax == 0u) goto label_00088981;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->emissionpos_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48897Eu)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x48897Eu));
    *(uint32_t*)(cpu->edi + 0x44u) = cpu->eax;
label_00088981:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"particleborn_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488999u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x488999u));
    if (cpu->eax == 0u) goto label_00088A13;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lifetime");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4889AEu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4889AEu));
    if (cpu->eax == 0u) goto label_000889BE;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4889BBu)); value_57 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4889BBu));
    *(float*)(cpu->edi + 0x6Cu) = value_57; 
label_000889BE:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"lifetime_rf");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4889CFu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4889CFu));
    if (cpu->eax == 0u) goto label_000889DF;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4889DCu)); value_58 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4889DCu));
    *(float*)(cpu->edi + 0x68u) = value_58; 
label_000889DF:
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lifetime_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4889F7u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4889F7u));
    if (cpu->eax == 0u) goto label_00088A13;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->lifetime_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488A10u)); sfera_sub_00482B00(cpu, LIFT_CODE_TOKEN_VA(0x488A10u));
    *(uint32_t*)(cpu->edi + 0x64u) = cpu->eax;
label_00088A13:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"particletracks_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488A27u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x488A27u));
    if (cpu->eax == 0u) goto label_00088FA8;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"nsize_tracks");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488A40u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488A40u));
    if (cpu->eax == 0u) goto label_00088AB7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488A4Du)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488A4Du));
    *(uint32_t*)(cpu->edi + 0x15Cu) = cpu->eax;
    if (cpu->eax == 0u) goto label_00088AB7;
    cpu->edx = 0x600u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488A66u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x488A66u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x15Cu);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488A82u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x488A82u));
    *(uint32_t*)(cpu->edi + 0x16Cu) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x15Cu) < 0x40u) goto label_00088AB7;
    lift_push32(cpu, 0x602u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488AAEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488AAEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488AB4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488AB4u));
    cpu->esp += 0x10u;
label_00088AB7:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ncolor_tracks");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488AC8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488AC8u));
    if (cpu->eax == 0u) goto label_00088B3F;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488AD5u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488AD5u));
    *(uint32_t*)(cpu->edi + 0x160u) = cpu->eax;
    if (cpu->eax == 0u) goto label_00088B3F;
    cpu->edx = 0x60Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488AEEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x488AEEu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x160u);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488B0Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x488B0Au));
    *(uint32_t*)(cpu->edi + 0x170u) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x160u) < 0x40u) goto label_00088B3F;
    lift_push32(cpu, 0x60Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488B36u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488B36u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488B3Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488B3Cu));
    cpu->esp += 0x10u;
label_00088B3F:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"nvelocity_tracks");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488B50u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488B50u));
    if (cpu->eax == 0u) goto label_00088BC7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488B5Du)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488B5Du));
    *(uint32_t*)(cpu->edi + 0x164u) = cpu->eax;
    if (cpu->eax == 0u) goto label_00088BC7;
    cpu->edx = 0x616u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488B76u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x488B76u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x164u);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488B92u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x488B92u));
    *(uint32_t*)(cpu->edi + 0x174u) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x164u) < 0x40u) goto label_00088BC7;
    lift_push32(cpu, 0x618u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488BBEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488BBEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488BC4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488BC4u));
    cpu->esp += 0x10u;
label_00088BC7:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ngravitation_tracks");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488BD8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488BD8u));
    if (cpu->eax == 0u) goto label_00088C4F;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488BE5u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488BE5u));
    *(uint32_t*)(cpu->edi + 0x168u) = cpu->eax;
    if (cpu->eax == 0u) goto label_00088C4F;
    cpu->edx = 0x621u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488BFEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x488BFEu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x168u);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488C1Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x488C1Au));
    *(uint32_t*)(cpu->edi + 0x178u) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x168u) < 0x40u) goto label_00088C4F;
    lift_push32(cpu, 0x623u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488C46u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488C46u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488C4Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488C4Cu));
    cpu->esp += 0x10u;
label_00088C4F:
    if (*(uint32_t*)(cpu->edi + 0x15Cu) <= 0u) goto label_00088D31;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488C6Du)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x488C6Du));
    if ((int32_t)cpu->eax <= 0) goto label_00088D31;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488C81u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x488C81u));
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488C92u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488C92u));
    if (cpu->eax == 0u) goto label_00088D2A;
label_00088CA0:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488CB3u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488CB3u));
    if (cpu->eax == 0u) goto label_00088CC5;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488CBFu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488CBFu));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_00088CF4;
label_00088CC5:
    if ((int32_t)cpu->esi >= (int32_t)*(uint32_t*)(cpu->edi + 0x15Cu)) goto label_00088CF4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->size_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488CE2u)); sfera_sub_00482B00(cpu, LIFT_CODE_TOKEN_VA(0x488CE2u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x16Cu);
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->eax;
    goto label_00088D11;
label_00088CED:
     value_8 = value_7; value_9 = value_47; value_10 = value_6; goto label_0008864E;
label_00088CF4:
    lift_push32(cpu, 0x639u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D08u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488D08u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D0Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488D0Eu));
    cpu->esp += 0x10u;
label_00088D11:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D22u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488D22u));
    if (cpu->eax != 0u) goto label_00088CA0;
label_00088D2A:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x88D31u)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0x88D31u));
label_00088D31:
    if (*(uint32_t*)(cpu->edi + 0x160u) <= 0u) goto label_00088E06;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D4Fu)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x488D4Fu));
    if ((int32_t)cpu->eax <= 0) goto label_00088E06;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D63u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x488D63u));
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D74u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488D74u));
    if (cpu->eax == 0u) goto label_00088DFF;
label_00088D80:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D93u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488D93u));
    if (cpu->eax == 0u) goto label_00088DA5;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488D9Fu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488D9Fu));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_00088DCD;
label_00088DA5:
    if ((int32_t)cpu->esi >= (int32_t)*(uint32_t*)(cpu->edi + 0x160u)) goto label_00088DCD;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->color_track"); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488DC2u)); sfera_sub_00485430(cpu, LIFT_CODE_TOKEN_VA(0x488DC2u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x170u);
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->eax;
    goto label_00088DEA;
label_00088DCD:
    lift_push32(cpu, 0x64Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488DE1u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488DE1u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488DE7u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488DE7u));
    cpu->esp += 0x10u;
label_00088DEA:
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488DFBu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488DFBu));
    if (cpu->eax != 0u) goto label_00088D80;
label_00088DFF:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x88E06u)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0x88E06u));
label_00088E06:
    if (*(uint32_t*)(cpu->edi + 0x164u) <= 0u) goto label_00088ED7;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488E24u)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x488E24u));
    if ((int32_t)cpu->eax <= 0) goto label_00088ED7;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488E38u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x488E38u));
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488E49u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488E49u));
    if (cpu->eax == 0u) goto label_00088ED0;
label_00088E51:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488E64u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488E64u));
    if (cpu->eax == 0u) goto label_00088E76;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488E70u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488E70u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_00088E9E;
label_00088E76:
    if ((int32_t)cpu->esi >= (int32_t)*(uint32_t*)(cpu->edi + 0x164u)) goto label_00088E9E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->velocity_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488E93u)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x488E93u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x174u);
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->eax;
    goto label_00088EBB;
label_00088E9E:
    lift_push32(cpu, 0x665u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488EB2u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488EB2u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488EB8u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488EB8u));
    cpu->esp += 0x10u;
label_00088EBB:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488ECCu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488ECCu));
    if (cpu->eax != 0u) goto label_00088E51;
label_00088ED0:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x88ED7u)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0x88ED7u));
label_00088ED7:
    if (*(uint32_t*)(cpu->edi + 0x168u) <= 0u) goto label_00088FA8;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488EF5u)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x488EF5u));
    if ((int32_t)cpu->eax <= 0) goto label_00088FA8;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F09u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x488F09u));
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F1Au)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488F1Au));
    if (cpu->eax == 0u) goto label_00088FA1;
label_00088F22:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F35u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488F35u));
    if (cpu->eax == 0u) goto label_00088F47;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F41u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488F41u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_00088F6F;
label_00088F47:
    if ((int32_t)cpu->esi >= (int32_t)*(uint32_t*)(cpu->edi + 0x168u)) goto label_00088F6F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->gravitation_track"); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F64u)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x488F64u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x178u);
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->eax;
    goto label_00088F8C;
label_00088F6F:
    lift_push32(cpu, 0x67Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F83u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x488F83u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F89u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x488F89u));
    cpu->esp += 0x10u;
label_00088F8C:
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488F9Du)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x488F9Du));
    if (cpu->eax != 0u) goto label_00088F22;
label_00088FA1:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x88FA8u)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0x88FA8u));
label_00088FA8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"texture_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488FC0u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x488FC0u));
    cpu->esi = native_function_address32(&::_stricmp);
    if (cpu->eax == 0u) goto label_0008929A;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"numframes");
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0xE8u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488FE9u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x488FE9u));
    if (cpu->eax == 0u) goto label_00088FFE;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x488FF6u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x488FF6u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x88FFEu)); sfera_sub_004846B0(cpu, LIFT_CODE_TOKEN_RVA(0x88FFEu));
label_00088FFE:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"type");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48900Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48900Fu));
    if (cpu->eax == 0u) goto label_0008903F;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489021u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x489021u));
    if (cpu->eax == 0u) goto label_0008903F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"PS_TANIMCOORD"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x89031u), LIFT_CODE_TOKEN_RVA(0x8902Fu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008903F;
    *(uint32_t*)(cpu->edi + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x4Cu)) | (uint64_t)(0x200u);
label_0008903F:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"blendmode");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489050u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x489050u));
    if (cpu->eax == 0u) goto label_00089091;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489062u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x489062u));
    if (cpu->eax == 0u) goto label_00089091;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"PS_BLENDADD"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x89072u), LIFT_CODE_TOKEN_RVA(0x89070u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00089082;
    *(uint32_t*)(cpu->edi + 0xE8u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0xE8u)) | (uint64_t)(1u);
    goto label_00089091;
label_00089082:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"PS_BLENDALPHA"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x8908Eu), LIFT_CODE_TOKEN_RVA(0x8908Cu))) { return; }
    cpu->esp += 8u;
label_00089091:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"animspeed");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4890A2u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4890A2u));
    if (cpu->eax == 0u) goto label_000890B5;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4890AFu)); value_51 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4890AFu));
    *(float*)(cpu->edi + 0x184u) = value_51; 
label_000890B5:
    if (*(uint32_t*)(cpu->edi + 0x180u) <= 0u) goto label_0008929A;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4890D3u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4890D3u));
    if (cpu->eax == 0u) goto label_0008913F;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4890E5u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4890E5u));
    if (cpu->eax == 0u) goto label_0008913F;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
label_000890F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000890F0;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0008913F;
    cpu->edx = 0x698u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48910Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48910Au));
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
label_00089110:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00089110;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489120u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x489120u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x17Cu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
label_00089135:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00089135;
label_0008913F:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48914Bu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x48914Bu));
    lift_push32(cpu, (uintptr_t)"frame");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489157u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x489157u));
    if (cpu->eax == 0u) goto label_00089293;
    (void)cpu;
label_00089160:
    lift_test[0]=(*(uint32_t*)(cpu->edi + 0x4Cu)&0x200u)==0u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    if (lift_test[0]) goto label_000891C5;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489172u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x489172u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = cpu->edx + (cpu->ecx * 8u);
    cpu->ecx = cpu->eax + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %f %f %f %f %f %f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4891B0u));
    cpu->esp += 0x2Cu;
    *(uint32_t*)(cpu->edi + 0xE8u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0xE8u)) | (uint64_t)(2u);
    goto label_0008927F;
label_000891C5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4891CAu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4891CAu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4891DAu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4891DAu));
    if (cpu->eax == 0u) goto label_0008927F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->eax + 1u;
label_000891F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000891F0;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0008927F;
    if (cpu->esi != 0u) goto label_0008922D;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x17Cu);
    if (*(uint32_t*)(cpu->edx) == cpu->esi) goto label_0008922D;
    cpu->edx = 0x6B4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48921Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48921Cu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48922Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48922Au));
    cpu->esp += 4u;
label_0008922D:
    cpu->edx = 0x6B6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48923Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48923Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->eax + 1u;
label_00089243:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00089243;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489253u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x489253u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->ecx = cpu->esi + (cpu->esi * 4u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->esp += 4u;
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x17Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->eax);
label_00089275:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->edx;
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00089275;
label_0008927F:
    lift_push32(cpu, (uintptr_t)"frame");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48928Bu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x48928Bu));
    if (cpu->eax != 0u) goto label_00089160;
label_00089293:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8929Au)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_RVA(0x8929Au));
label_0008929A:
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= 0u) goto label_000896B6;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"particles_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4892B5u)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x4892B5u));
    if ((int32_t)cpu->eax <= 0) goto label_000896B6;
    cpu->edx = 0x6C5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4892CCu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4892CCu));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4892D5u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4892D5u));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    if (cpu->esi == 0u) goto label_0008969E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4892F2u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4892F2u));
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"particles_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489303u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x489303u));
    if (cpu->eax == 0u) goto label_00089693;
label_00089310:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x5Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48931Bu));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"select");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489334u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x489334u));
    if (cpu->eax == 0u) goto label_0008942B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48934Au)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x48934Au));
    if (cpu->eax == 0u) goto label_0008942B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"range"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x48935Cu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000893C0;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x5Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x489373u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489384u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x489384u));
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->ebx;
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48938Fu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x48938Fu));
    if ((int32_t)cpu->esi <= (int32_t)cpu->eax) goto label_00089399;
    cpu->ecx = cpu->esi;
    cpu->esi = cpu->eax;
    cpu->eax = cpu->ecx;
label_00089399:
    if ((int32_t)cpu->esi >= 0) goto label_0008939F;
    cpu->esi = 0u;
label_0008939F:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x5Cu);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000893A8;
    cpu->eax = cpu->ecx;
label_000893A8:
    if ((int32_t)cpu->esi >= (int32_t)cpu->eax) goto label_000893C0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4893B8u));
    cpu->esp += 0xCu;
label_000893C0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"number"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4893CAu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0008942B;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x5Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4893E2u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4893F1u)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4893F1u));
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    if ((int32_t)cpu->ecx <= 0) goto label_0008942B;
label_00089400:
    cpu->esi = cpu->eax + 1u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48940Bu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x48940Bu));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x5Cu);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_00089415;
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
label_00089415:
    if ((int32_t)cpu->eax >= 0) goto label_0008941B;
    cpu->eax = 0u;
label_0008941B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint8_t*)(cpu->eax + cpu->edx) = 1u;
    cpu->eax = cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esp + 0x24u)) goto label_00089400;
label_0008942B:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48943Cu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x48943Cu));
    if (cpu->eax == 0u) goto label_00089490;
    if (*(uint32_t*)(cpu->edi + 0x15Cu) <= 0u) goto label_00089490;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489452u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x489452u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->ecx) goto label_00089490;
    cpu->edx = 0u;
    (void)cpu;
label_00089460:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 1u) goto label_00089487;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x16Cu);
    if (*(uint32_t*)(cpu->esi + (cpu->eax * 4u)) != 0u) goto label_0008947B;
    cpu->eax = 0xFFFFu;
label_0008947B:
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    *(uint16_t*)(cpu->esi + cpu->edx + 0x3Cu) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
label_00089487:
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_00089460;
label_00089490:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4894A1u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4894A1u));
    if (cpu->eax == 0u) goto label_000894F4;
    if (*(uint32_t*)(cpu->edi + 0x160u) <= 0u) goto label_000894F4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4894B7u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4894B7u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->ecx) goto label_000894F4;
    cpu->edx = 0u;
label_000894C4:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 1u) goto label_000894EB;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x170u);
    if (*(uint32_t*)(cpu->esi + (cpu->eax * 4u)) != 0u) goto label_000894DF;
    cpu->eax = 0xFFFFu;
label_000894DF:
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    *(uint16_t*)(cpu->esi + cpu->edx + 0x3Eu) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
label_000894EB:
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_000894C4;
label_000894F4:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489505u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x489505u));
    if (cpu->eax == 0u) goto label_00089560;
    if (*(uint32_t*)(cpu->edi + 0x164u) <= 0u) goto label_00089560;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48951Bu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x48951Bu));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->ecx) goto label_00089560;
    cpu->edx = 0u;
label_00089530:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 1u) goto label_00089557;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x174u);
    if (*(uint32_t*)(cpu->esi + (cpu->eax * 4u)) != 0u) goto label_0008954B;
    cpu->eax = 0xFFFFu;
label_0008954B:
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    *(uint16_t*)(cpu->esi + cpu->edx + 0x40u) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
label_00089557:
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_00089530;
label_00089560:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489571u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x489571u));
    if (cpu->eax == 0u) goto label_000895C4;
    if (*(uint32_t*)(cpu->edi + 0x168u) <= 0u) goto label_000895C4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489587u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x489587u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->ecx) goto label_000895C4;
    cpu->edx = 0u;
label_00089594:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 1u) goto label_000895BB;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x178u);
    if (*(uint32_t*)(cpu->esi + (cpu->eax * 4u)) != 0u) goto label_000895AF;
    cpu->eax = 0xFFFFu;
label_000895AF:
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    *(uint16_t*)(cpu->esi + cpu->edx + 0x42u) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
label_000895BB:
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_00089594;
label_000895C4:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"magnite_weight");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4895D5u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4895D5u));
    if (cpu->eax == 0u) goto label_000895F6;
    lift_push32(cpu, 0x70Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4895EDu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4895EDu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4895F3u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4895F3u));
    cpu->esp += 0x10u;
label_000895F6:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"texture_frame");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489607u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x489607u));
    if (cpu->eax == 0u) goto label_00089637;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489619u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x489619u));
    if (cpu->eax == 0u) goto label_00089637;
    lift_push32(cpu, (uintptr_t)"RANDOM"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x489623u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00089637;
    *(uint32_t*)(cpu->edi + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x4Cu)) | (uint64_t)(0x80000u);
label_00089637:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"child_ps");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489648u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x489648u));
    if (cpu->eax == 0u) goto label_0008967A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489655u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x489655u));
    cpu->ecx = 0u;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->ecx) goto label_0008967A;
    cpu->edx = 0u;
label_00089660:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 1u) goto label_00089671;
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + cpu->edx + 0x4Cu) = cpu->eax;
label_00089671:
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_00089660;
label_0008967A:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"particles_def");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48968Bu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x48968Bu));
    if (cpu->eax != 0u) goto label_00089310;
label_00089693:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48969Au)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_VA(0x48969Au));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
label_0008969E:
    cpu->edx = 0x721u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4896ADu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4896ADu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4896B3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4896B3u));
    cpu->esp += 4u;
label_000896B6:
    if (*(uint32_t*)(cpu->edi + 0x18Cu) <= 0u) goto label_000896FA;
    cpu->edx = 0u;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->edx) goto label_000896FA;
    cpu->ecx = 0u;
label_000896D0:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    sub_pred[0] = *(uint32_t*)(cpu->ecx + cpu->eax + 0x4Cu) == 0xFFFFFFFFu;
    cpu->eax = cpu->ecx + cpu->eax + 0x4Cu;
    if (sub_pred[0]) goto label_000896F1;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x188u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    ++*(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 4u);
    cpu->eax = cpu->esi + (cpu->eax * 4u) + 4u;
label_000896F1:
    ++cpu->edx;
    cpu->ecx += 0x50u;
    if (cpu->edx < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_000896D0;
label_000896FA:
    if (g_sfera_effect_manager.particle_random_table != 0u) goto label_00089720;
    lift_push32(cpu, 0x72Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x489717u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x489717u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48971Du)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x48971Du));
    cpu->esp += 0x10u;
label_00089720:
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x89728u), LIFT_CODE_TOKEN_RVA(0x89726u))) { return; }
    cpu->ecx = 0xFEu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->edi + 0xD8u) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x89738u), LIFT_CODE_TOKEN_RVA(0x89736u))) { return; }
    *(uint32_t*)(cpu->edi + 0xDCu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x89740u), LIFT_CODE_TOKEN_RVA(0x8973Eu))) { return; }
    lift_test[1]=(*(uint8_t*)(cpu->edi + 0x4Cu)&0x40u)==0u;
    *(uint32_t*)(cpu->edi + 0xE0u) = cpu->eax;
    if (lift_test[1]) goto label_000897B4;
    cpu->esi = *(uint32_t*)(cpu->edi + 0xD8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x64u);
    cpu->esi <<= 9u;
    cpu->esi += g_sfera_effect_manager.particle_random_table;
    if (cpu->ecx == 0u) goto label_0008977A;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xDCu);
    x87_p0 = 0.0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x6Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8977Au)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x8977Au));
label_0008977A:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x44u);
    if (cpu->ecx == 0u) goto label_0008979F;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xE0u);
    x87_p0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xDCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi + 0x34u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8979Fu)); sfera_sub_0042D9F0(cpu, LIFT_CODE_TOKEN_RVA(0x8979Fu));
label_0008979F:
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->edi + 0x5Cu) <= cpu->esi) goto label_000897B4;
label_000897A6:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4897AEu)); sfera_sub_00484A80(cpu, LIFT_CODE_TOKEN_VA(0x4897AEu));
    ++cpu->esi;
    if (cpu->esi < *(uint32_t*)(cpu->edi + 0x5Cu)) goto label_000897A6;
label_000897B4:
    cpu->edx = 0x743u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4897C3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4897C3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4897CDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4897CDu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4897DCu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4897DCu));
    cpu->eax = 1u;
    goto label_000897E5;
label_000897E3:
    cpu->eax = 0u;
label_000897E5:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8A0CBu), LIFT_CODE_TOKEN_RVA(0x8A0C9u))) { return; }
    cpu->esp += 8u;
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
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8A157u), LIFT_CODE_TOKEN_RVA(0x8A155u))) { return; }
    cpu->esp += 8u;
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
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8AE51u), LIFT_CODE_TOKEN_RVA(0x8AE4Fu))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x1Cu) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))))) / (32767.0));
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8AE65u), LIFT_CODE_TOKEN_RVA(0x8AE63u))) { return; }
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
     if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8AEF4u), LIFT_CODE_TOKEN_RVA(0x8AEF2u))) { return; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_p0 = (x87_p0) / (32767.0);
    x87_p0 = (*(double*)(cpu->esp + 0x130u)) - (x87_p0);
    x87_p0 = (x87_p0) * (10.0);
    x87_p1 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p1 = (x87_p1) - (2.0);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x60u) = x87_p0; 
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8AF21u), LIFT_CODE_TOKEN_RVA(0x8AF1Fu))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8B158u), LIFT_CODE_TOKEN_RVA(0x8B156u))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8B17Fu), LIFT_CODE_TOKEN_RVA(0x8B17Du))) { return; }
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
__declspec(noinline) void sfera_sub_0048B5E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_0008B809;
    x87_v0 = 0.0;
    cpu->edi = 0u;
    label_0008B5FD:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    { const double lift_left=0.0; const double lift_right=((double)*(float*)(cpu->edi + cpu->eax + 0x34u)); if (lift_left>=lift_right) goto label_0008B7F8; }
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    ++cpu->ecx;
    if (cpu->ecx >= 0x2710u) goto label_0008B807;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    x87_v1 = (double)*(float*)(cpu->edi + cpu->edx + 0x34u);
    cpu->eax = cpu->edi + cpu->edx + 0x34u;
    x87_v1 = (x87_v1) - (1.0);
    *(float*)(cpu->eax) = x87_v1; 
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    x87_v1 = (double)*(float*)(cpu->eax + cpu->edi + 0x34u);
    x87_v1 = (x87_v1) - (x87_v0);
    x87_v2 = (double)*(float*)(cpu->eax + cpu->edi + 0x30u);
    x87_v0 = x87_v2 - x87_v0; 
    x87_v0 = x87_v1 / x87_v0; 
    x87_v0 = (x87_v0) * (6.283185958862305);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = 0.5;
    x87_v0 = (x87_v0) * (x87_v1);
    x87_v0 = x87_v1 - x87_v0; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = (x87_v0) * (100.0);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->ebx = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    *(uint64_t*)(cpu->esp + 0x18u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ebx >= 0) goto label_0008B6B8;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8B6B8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x8B6B8u));
    label_0008B6B8:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_0008B6CC;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8B6CCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x8B6CCu));
    label_0008B6CC:
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += g_sfera_effect_manager.render_slots.data;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ecx + 0x98u) = 3u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->ecx + 0x90u) = cpu->edx;
    cpu->eax = cpu->ecx + 0x30u;
    cpu->edx = 4u;
    label_0008B6F5:
    cpu->ebx = 0xFFu;
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->ebp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ebx;
    cpu->eax += 4u;
    if ((--cpu->edx) != 0u) goto label_0008B6F5;
    *(uint32_t*)(cpu->ecx + 0x94u) = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->edi);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->edi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->edi + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = cpu->edi + cpu->edx + 0xCu;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = cpu->edi + cpu->edx + 0x18u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 0x18u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = cpu->edi + cpu->edx + 0x24u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 0x24u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 0x28u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 0x2Cu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    x87_v0 = (double)*(float*)(cpu->edi + cpu->edx + 0x38u);
    cpu->eax = cpu->edi + cpu->edx + 0x38u;
    x87_v0 = (x87_v0) + (0.25);
    *(float*)(cpu->eax) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    x87_v0 = (double)*(float*)(cpu->edi + cpu->eax + 0x38u);
    *(uint64_t*)(cpu->esp + 0x18u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->esi + 0x14u)); cpu->eax = n / d; cpu->edx = n % d; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    x87_v0 = (double)*(float*)(cpu->eax + (cpu->edx * 8u) + 8u);
    cpu->eax = cpu->eax + (cpu->edx * 8u);
    *(float*)(cpu->ecx + 0x70u) = x87_v0; 
    *(float*)(cpu->ecx + 0x74u) = (double)*(float*)(cpu->eax + 0xCu);
    *(float*)(cpu->ecx + 0x78u) = (double)*(float*)(cpu->eax + 0x10u);
    *(float*)(cpu->ecx + 0x7Cu) = (double)*(float*)(cpu->eax + 0x14u);
    *(float*)(cpu->ecx + 0x80u) = (double)*(float*)(cpu->eax + 0x18u);
    *(float*)(cpu->ecx + 0x84u) = (double)*(float*)(cpu->eax + 0x1Cu);
    *(float*)(cpu->ecx + 0x88u) = (double)*(float*)(cpu->eax + 0x20u);
    *(float*)(cpu->ecx + 0x8Cu) = (double)*(float*)(cpu->eax + 0x24u);
    x87_v0 = 0.0;
    label_0008B7F8:
    cpu->edi += 0x3Cu;
    if (cpu->edi < 0x1770u) goto label_0008B5FD;
    label_0008B807:
    x87_v0 = x87_v0; 
    label_0008B809:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
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
