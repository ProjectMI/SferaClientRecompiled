#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

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

LIFT_ENTRY void LIFT_CDECL sfera_sub_00482170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482170u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48217Bu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482182u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482189u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_0008219C;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"openCfg: file %s is not found");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482199u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0008219C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48219Cu);
    lift_push32(cpu, 0x469u);
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4821AEu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi + cpu->edi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4821BDu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4821C9u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4821D0u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xDu)) goto label_0008224F;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_0008224F;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Fu)) goto label_0008224F;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xC6u)) goto label_0008221B;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xEBu)) goto label_0008221B;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xE4u)) goto label_0008221B;
    lift_push32(cpu, 0x48Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4821FBu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"openCfg: wrong fromat of Cfg %s"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x482206u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48220Cu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.token[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482219u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00082299;
    label_0008221B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48221Bu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0008222A;
    label_00082221: cpu->eip = LIFT_CODE_TOKEN_VA(0x482221u);
    lift_store8(cpu->eax + cpu->esi, (uint64_t)(lift_load8(cpu->eax + cpu->esi)) ^ (uint64_t)(0xCBu));
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00082221;
    label_0008222A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48222Au);
    if ((uint32_t)(g_sfera_config_parser_runtime.open_mode) != (uint32_t)(0u)) goto label_00082299;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48223Au); lift_push32(cpu, r); sfera_sub_0042EE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482246u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48224Du); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    goto label_00082299;
    label_0008224F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48224Fu);
    if ((uint32_t)(g_sfera_config_parser_runtime.open_mode) != (uint32_t)(1u)) goto label_00082299;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00082269;
    cpu->edi = cpu->edi;
    label_00082260: cpu->eip = LIFT_CODE_TOKEN_VA(0x482260u);
    lift_store8(cpu->eax + cpu->esi, (uint64_t)(lift_load8(cpu->eax + cpu->esi)) ^ (uint64_t)(0xCBu));
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00082260;
    label_00082269: cpu->eip = LIFT_CODE_TOKEN_VA(0x482269u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482270u); lift_push32(cpu, r); sfera_sub_0042EE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48227Cu); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482283u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00082299;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00082290: cpu->eip = LIFT_CODE_TOKEN_VA(0x482290u);
    lift_store8(cpu->eax + cpu->esi, (uint64_t)(lift_load8(cpu->eax + cpu->esi)) ^ (uint64_t)(0xCBu));
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00082290;
    label_00082299: cpu->eip = LIFT_CODE_TOKEN_VA(0x482299u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4822A0u); lift_push32(cpu, r); sfera_sub_00480660(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_push32(cpu, 0x491u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4822B3u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4822BEu); lift_push32(cpu, r); sfera_sub_004815E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_000822CC;
    cpu->ecx = (uint32_t)(uintptr_t)"openCfg: internal error";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x822CCu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000822CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4822CCu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4822D3u); lift_push32(cpu, r); sfera_sub_004813D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x497u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4822E4u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004822F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4822F0u);
    cpu->esp -= 0x10u;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x34u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x3Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x34u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x3Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x2Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x34u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x30u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x34u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x38u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x3Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x34u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004825A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4825A0u);
    cpu->esp -= 0x20u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->esi);
    lift_store_f64(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4825B3u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4825C0u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f64(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4825D1u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4825DEu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f64(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4825EFu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4825FCu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 6u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004826C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4826C0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4826CBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4826D0u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f64(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4826E8u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4826F5u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00482720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482720u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48272Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x482730u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f64(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482748u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482755u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00482780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482780u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48278Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x482790u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f64(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4827A7u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4827B4u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004827E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4827E0u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000827E7;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000827E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4827E7u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"PS_ROTATEXYZ"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x827F6u), LIFT_CODE_TOKEN_RVA(0x827F4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4827F6u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082804;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082804: cpu->eip = LIFT_CODE_TOKEN_VA(0x482804u);
    lift_push32(cpu, (uintptr_t)"PS_ROTATEX"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8280Cu), LIFT_CODE_TOKEN_RVA(0x8280Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48280Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008281A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0008281A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48281Au);
    lift_push32(cpu, (uintptr_t)"PS_ROTATEY"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82822u), LIFT_CODE_TOKEN_RVA(0x82820u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482822u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082830;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082830: cpu->eip = LIFT_CODE_TOKEN_VA(0x482830u);
    lift_push32(cpu, (uintptr_t)"PS_ROTATEZ"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82838u), LIFT_CODE_TOKEN_RVA(0x82836u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482838u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082846;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082846: cpu->eip = LIFT_CODE_TOKEN_VA(0x482846u);
    lift_push32(cpu, (uintptr_t)"PS_USEROTSCALE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8284Eu), LIFT_CODE_TOKEN_RVA(0x8284Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48284Eu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008285C;
    cpu->eax = 0x10u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0008285C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48285Cu);
    lift_push32(cpu, (uintptr_t)"PS_TRANSLATEONLY"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82864u), LIFT_CODE_TOKEN_RVA(0x82862u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482864u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082872;
    cpu->eax = 0x20u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082872: cpu->eip = LIFT_CODE_TOKEN_VA(0x482872u);
    lift_push32(cpu, (uintptr_t)"PS_STATICEMITALL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8287Au), LIFT_CODE_TOKEN_RVA(0x82878u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48287Au);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082888;
    cpu->eax = 0x40u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082888: cpu->eip = LIFT_CODE_TOKEN_VA(0x482888u);
    lift_push32(cpu, (uintptr_t)"PS_DYNAMICEMITALL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82890u), LIFT_CODE_TOKEN_RVA(0x8288Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482890u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008289E;
    cpu->eax = 0x80u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0008289E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48289Eu);
    lift_push32(cpu, (uintptr_t)"PS_USEMAGNITE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x828A6u), LIFT_CODE_TOKEN_RVA(0x828A4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4828A6u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000828B4;
    cpu->eax = 0x100u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000828B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4828B4u);
    lift_push32(cpu, (uintptr_t)"PS_NOHEAVYATTACH"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x828BCu), LIFT_CODE_TOKEN_RVA(0x828BAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4828BCu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000828CA;
    cpu->eax = 0x400u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000828CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4828CAu);
    lift_push32(cpu, (uintptr_t)"PS_NOFACECAMERA"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x828D2u), LIFT_CODE_TOKEN_RVA(0x828D0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4828D2u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000828E0;
    cpu->eax = 0x800u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000828E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4828E0u);
    lift_push32(cpu, (uintptr_t)"PS_NOLIFETIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x828E8u), LIFT_CODE_TOKEN_RVA(0x828E6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4828E8u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000828F6;
    cpu->eax = 0x2000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000828F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4828F6u);
    lift_push32(cpu, (uintptr_t)"PS_NOLOCALTIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x828FEu), LIFT_CODE_TOKEN_RVA(0x828FCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4828FEu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008290C;
    cpu->eax = 0x1000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0008290C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48290Cu);
    lift_push32(cpu, (uintptr_t)"PS_USEUVTRANSLATE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82914u), LIFT_CODE_TOKEN_RVA(0x82912u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482914u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082922;
    cpu->eax = 0x4000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082922: cpu->eip = LIFT_CODE_TOKEN_VA(0x482922u);
    lift_push32(cpu, (uintptr_t)"PS_USECOLOR"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8292Au), LIFT_CODE_TOKEN_RVA(0x82928u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48292Au);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082938;
    cpu->eax = 0x8000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082938: cpu->eip = LIFT_CODE_TOKEN_VA(0x482938u);
    lift_push32(cpu, (uintptr_t)"PS_USEDISTORTION"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82940u), LIFT_CODE_TOKEN_RVA(0x8293Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482940u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008294E;
    cpu->eax = 0x10000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0008294E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48294Eu);
    lift_push32(cpu, (uintptr_t)"PS_MAGFACTORISLIFE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82956u), LIFT_CODE_TOKEN_RVA(0x82954u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482956u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082964;
    cpu->eax = 0x20000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082964: cpu->eip = LIFT_CODE_TOKEN_VA(0x482964u);
    lift_push32(cpu, (uintptr_t)"PS_EMITONPOSCHANGE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8296Cu), LIFT_CODE_TOKEN_RVA(0x8296Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48296Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008297A;
    cpu->eax = 0x40000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0008297A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48297Au);
    lift_push32(cpu, (uintptr_t)"PS_RANDOMTEXFRAME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82982u), LIFT_CODE_TOKEN_RVA(0x82980u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482982u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082990;
    cpu->eax = 0x80000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082990: cpu->eip = LIFT_CODE_TOKEN_VA(0x482990u);
    lift_push32(cpu, (uintptr_t)"PS_MAGISCHILDPS"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82998u), LIFT_CODE_TOKEN_RVA(0x82996u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482998u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000829A6;
    cpu->eax = 0x100000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000829A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4829A6u);
    lift_push32(cpu, (uintptr_t)"PS_MAGFACTORGTIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x829AEu), LIFT_CODE_TOKEN_RVA(0x829ACu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4829AEu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000829BC;
    cpu->eax = 0x200000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000829BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4829BCu);
    lift_push32(cpu, (uintptr_t)"PS_EMITCTRLRHW"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x829C4u), LIFT_CODE_TOKEN_RVA(0x829C2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4829C4u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000829D2;
    cpu->eax = 0x400000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000829D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4829D2u);
    lift_push32(cpu, (uintptr_t)"PS_PARENTALPHA"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x829DAu), LIFT_CODE_TOKEN_RVA(0x829D8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4829DAu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000829E8;
    cpu->eax = 0x800000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000829E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4829E8u);
    lift_push32(cpu, (uintptr_t)"PS_PARENTLIFETIME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x829F0u), LIFT_CODE_TOKEN_RVA(0x829EEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4829F0u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000829FE;
    cpu->eax = 0x1000000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000829FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4829FEu);
    lift_push32(cpu, (uintptr_t)"PS_DIRECTVELOCITY"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82A06u), LIFT_CODE_TOKEN_RVA(0x82A04u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482A06u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082A14;
    cpu->eax = 0x2000000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082A14: cpu->eip = LIFT_CODE_TOKEN_VA(0x482A14u);
    lift_push32(cpu, (uintptr_t)"PS_FOLLOWWITHSPIN"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82A1Cu), LIFT_CODE_TOKEN_RVA(0x82A1Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482A1Cu);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xF8000000u;
    cpu->eax += 0x8000000u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00482A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482A30u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082A35;
    lift_return(cpu, 0u, stop_address); return;
    label_00082A35: cpu->eip = LIFT_CODE_TOKEN_VA(0x482A35u);
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x482A3Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x482A41u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    ++cpu->eax;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00482A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482A50u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00082A57;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_00082A57: cpu->eip = LIFT_CODE_TOKEN_VA(0x482A57u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_LINE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82A66u), LIFT_CODE_TOKEN_RVA(0x82A64u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482A66u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082A74;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082A74: cpu->eip = LIFT_CODE_TOKEN_VA(0x482A74u);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_DISK"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82A7Cu), LIFT_CODE_TOKEN_RVA(0x82A7Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482A7Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082A8A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082A8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x482A8Au);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_RING"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82A92u), LIFT_CODE_TOKEN_RVA(0x82A90u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482A92u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082AA0;
    cpu->eax = 6u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082AA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x482AA0u);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_BOX"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82AA8u), LIFT_CODE_TOKEN_RVA(0x82AA6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482AA8u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082AB6;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082AB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x482AB6u);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_CYLINDER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82ABEu), LIFT_CODE_TOKEN_RVA(0x82ABCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482ABEu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082ACC;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082ACC: cpu->eip = LIFT_CODE_TOKEN_VA(0x482ACCu);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_SPHERE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82AD4u), LIFT_CODE_TOKEN_RVA(0x82AD2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482AD4u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082AE2;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00082AE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x482AE2u);
    lift_push32(cpu, (uintptr_t)"EMITSHAPE_DISK2"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82AEAu), LIFT_CODE_TOKEN_RVA(0x82AE8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482AEAu);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFF9u;
    cpu->eax += 7u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00482B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482B00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->edx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482B45u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00082B59;
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482B53u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(cpu->edi)) goto label_00082B60;
    label_00082B59: cpu->eip = LIFT_CODE_TOKEN_VA(0x482B59u);
    cpu->eax = 0u;
    goto label_00082CBB;
    label_00082B60: cpu->eip = LIFT_CODE_TOKEN_VA(0x482B60u);
    cpu->edx = 0xE1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482B6Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482B76u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x68u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00082B8E;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482B8Cu); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    label_00082B8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x482B8Eu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x6Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482B9Eu); lift_push32(cpu, r); sfera_sub_0042E000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x30u);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x482BAFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x482BB4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482BBFu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482BCBu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00082C37;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    label_00082BE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x482BE0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x82BF7u), LIFT_CODE_TOKEN_RVA(0x82BF5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482BF7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x38u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482C23u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482C2Fu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082BE0;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    label_00082C37: cpu->eip = LIFT_CODE_TOKEN_VA(0x482C37u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482C3Fu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482C4Bu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00082CB2;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    label_00082C52: cpu->eip = LIFT_CODE_TOKEN_VA(0x482C52u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x82C6Eu), LIFT_CODE_TOKEN_RVA(0x82C6Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482C6Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->esp += 0x18u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x38u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482CA2u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482CAEu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082C52;
    label_00082CB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x482CB2u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482CB9u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    label_00082CBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x482CBBu);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00482CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482CE0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x74u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x88u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->edx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x54u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482D28u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00082D3C;
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482D36u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(cpu->edi)) goto label_00082D43;
    label_00082D3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x482D3Cu);
    cpu->eax = 0u;
    goto label_00083034;
    label_00082D43: cpu->eip = LIFT_CODE_TOKEN_VA(0x482D43u);
    cpu->edx = 0x119u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482D52u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482D59u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x90u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00082D74;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482D72u); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    label_00082D74: cpu->eip = LIFT_CODE_TOKEN_VA(0x482D74u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x94u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482D87u); lift_push32(cpu, r); sfera_sub_0042E000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x30u);
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x482D98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x482D9Du);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482DA8u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482DB4u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00082E52;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    label_00082DC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x482DC5u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x82DE6u), LIFT_CODE_TOKEN_RVA(0x82DE4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482DE6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x58u, 0u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x6Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x70u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x7Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482E3Au); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482E46u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082DC5;
    cpu->ebp = lift_load32(cpu->esp + 0x4Cu);
    label_00082E52: cpu->eip = LIFT_CODE_TOKEN_VA(0x482E52u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482E5Au); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482E66u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00082F40;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    label_00082E71: cpu->eip = LIFT_CODE_TOKEN_VA(0x482E71u);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x82EA1u), LIFT_CODE_TOKEN_RVA(0x82E9Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482EA1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x28u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x58u, 1u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x6Cu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x70u, cpu->edx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store32(cpu->esp + 0x78u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_store32(cpu->esp + 0x7Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x88u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482F28u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482F34u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082E71;
    cpu->ebp = lift_load32(cpu->esp + 0x4Cu);
    label_00082F40: cpu->eip = LIFT_CODE_TOKEN_VA(0x482F40u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482F48u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"mrkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482F54u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008302B;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    (void)cpu;
    label_00082F60: cpu->eip = LIFT_CODE_TOKEN_VA(0x482F60u);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x82F90u), LIFT_CODE_TOKEN_RVA(0x82F8Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482F90u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x28u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x58u, 2u);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x6Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x70u, cpu->eax);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store32(cpu->esp + 0x74u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store32(cpu->esp + 0x78u, cpu->edx);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x7Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x84u, cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483017u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"mrkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483023u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00082F60;
    label_0008302B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48302Bu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483032u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    label_00083034: cpu->eip = LIFT_CODE_TOKEN_VA(0x483034u);
    cpu->ecx = lift_load32(cpu->esp + 0x88u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x80u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483060u);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.x)));
    cpu->edi = cpu->edx;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.y)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.z)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, -1.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483136u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00083181;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    goto label_000831AB;
    label_00083181: cpu->eip = LIFT_CODE_TOKEN_VA(0x483181u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000831AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4831ABu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4831D4u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008321F;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    goto label_00083247;
    label_0008321F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48321Fu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00083247: cpu->eip = LIFT_CODE_TOKEN_VA(0x483247u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->edi, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store32(cpu->edi + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store32(cpu->edi + 8u, cpu->edx);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store32(cpu->edi + 0x10u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store32(cpu->edi + 0x14u, cpu->edx);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store32(cpu->edi + 0x18u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store32(cpu->edi + 0x1Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store32(cpu->edi + 0x20u, cpu->edx);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store32(cpu->edi + 0x24u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store32(cpu->edi + 0x28u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->edi + 0x2Cu, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483490u);
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    lift_store32(cpu->eax + 0x28u, cpu->ecx);
    lift_store32(cpu->eax + 0x2Cu, cpu->ecx);
    lift_store32(cpu->eax + 0x30u, cpu->ecx);
    lift_store32(cpu->eax + 0x34u, cpu->ecx);
    lift_store32(cpu->eax + 0x38u, cpu->ecx);
    lift_store32(cpu->eax + 0x3Cu, cpu->ecx);
    lift_store32(cpu->eax + 0x40u, cpu->ecx);
    lift_store32(cpu->eax + 0x44u, cpu->ecx);
    lift_store32(cpu->eax + 0x48u, cpu->ecx);
    lift_store32(cpu->eax + 0x4Cu, cpu->ecx);
    lift_store32(cpu->eax + 0x50u, cpu->ecx);
    lift_store32(cpu->eax + 0x54u, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004834C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4834C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) == (uint32_t)(0u)) goto label_000834E4;
    cpu->edx = 0x1A2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4834D8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4834E1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000834E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4834E4u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x34u)) == (uint32_t)(0u)) goto label_00083505;
    cpu->edx = 0x1A3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4834F9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483502u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083505: cpu->eip = LIFT_CODE_TOKEN_VA(0x483505u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x38u)) == (uint32_t)(0u)) goto label_00083526;
    cpu->edx = 0x1A4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48351Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483523u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083526: cpu->eip = LIFT_CODE_TOKEN_VA(0x483526u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x3Cu)) == (uint32_t)(0u)) goto label_00083547;
    cpu->edx = 0x1A5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48353Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483544u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083547: cpu->eip = LIFT_CODE_TOKEN_VA(0x483547u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x40u)) == (uint32_t)(0u)) goto label_00083568;
    cpu->edx = 0x1A6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48355Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483565u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083568: cpu->eip = LIFT_CODE_TOKEN_VA(0x483568u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x44u)) == (uint32_t)(0u)) goto label_00083589;
    cpu->edx = 0x1A8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48357Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483586u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083589: cpu->eip = LIFT_CODE_TOKEN_VA(0x483589u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x48u)) == (uint32_t)(0u)) goto label_000835AA;
    cpu->edx = 0x1A9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48359Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4835A7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000835AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4835AAu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x4Cu)) == (uint32_t)(0u)) goto label_000835CB;
    cpu->edx = 0x1AAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4835BFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4835C8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000835CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4835CBu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004835D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4835D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) <= (uint32_t)(0u)) goto label_00083658;
    cpu->edx = 0x1B9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4835E8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0xCu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483601u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x44u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483612u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x483617u);
    cpu->esp += 0x10u;
    cpu->edx = 0x1BCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483629u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483642u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x4Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483650u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x483655u);
    cpu->esp += 0x10u;
    label_00083658: cpu->eip = LIFT_CODE_TOKEN_VA(0x483658u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) <= (uint32_t)(0u)) goto label_0008369E;
    cpu->edx = 0x1C2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48366Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 8u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483686u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x48u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483696u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48369Bu);
    cpu->esp += 0x10u;
    label_0008369E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48369Eu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004836A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4836A0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x20u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4836BEu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esi + 0x28u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4836CAu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4836D7u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, 4u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4836E3u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esi + 0x24u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4836EFu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4836FCu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) <= (uint32_t)(0u)) goto label_0008375E;
    cpu->edx = 0x1DBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483711u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0xCu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48372Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x1DEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48373Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483758u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    label_0008375E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48375Eu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) <= (uint32_t)(0u)) goto label_00083792;
    cpu->edx = 0x1E4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483773u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 8u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48378Cu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x34u, cpu->eax);
    label_00083792: cpu->eip = LIFT_CODE_TOKEN_VA(0x483792u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x24u)) <= (uint32_t)(0u)) goto label_000837F4;
    cpu->edx = 0x1EAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4837A7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x10u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4837C0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x1EBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4837D5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x10u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4837EEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    label_000837F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4837F4u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483809u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx += cpu->edx;
    lift_push32(cpu, 1u);
    cpu->edx += cpu->edx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48381Du); lift_push32(cpu, r); sfera_sub_0042F0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    cpu->edx = lift_load32(cpu->esi + 0x38u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48382Eu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483840u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00083869;
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483858u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    cpu->edx = lift_load32(cpu->esi + 0x3Cu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x83869u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    label_00083869: cpu->eip = LIFT_CODE_TOKEN_VA(0x483869u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483870u); lift_push32(cpu, r); sfera_sub_004835D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483880u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, 0.0);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ecx = 0xFFu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x30u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x44u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->eax);
    cpu->edi = (uint32_t)(cpu->esi + 0x50u);
    lift_store32(cpu->esi + 0x48u, cpu->edx);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x34u, cpu->eax);
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    lift_store32(cpu->esi + 0x4Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    lift_store32(cpu->esi + 0x98u, cpu->eax);
    lift_store32(cpu->esi + 0x94u, 0xFFFFFFFFu);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4838FEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x483903u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->edi + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->edi + 0x28u, lift_x87_get(cpu, 0u));
    cpu->eax = cpu->esi;
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483920u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x34u)) != (uint32_t)(0u)) goto label_00083A7D;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_0008394C;
    cpu->edx = 0x233u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483941u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483949u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008394C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48394Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x90u)) == (uint32_t)(0u)) goto label_00083973;
    cpu->edx = 0x234u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483964u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483970u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083973: cpu->eip = LIFT_CODE_TOKEN_VA(0x483973u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000839A0;
    cpu->edx = 0x235u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483989u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000839A0;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483997u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48399Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000839A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4839A0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(0u)) goto label_000839CC;
    cpu->edx = 0x236u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4839B5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000839CC;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4839C3u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4839C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000839CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4839CCu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(0u)) goto label_000839F8;
    cpu->edx = 0x237u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4839E1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000839F8;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4839EFu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4839F5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000839F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4839F8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) == (uint32_t)(0u)) goto label_00083A24;
    cpu->edx = 0x238u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A0Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00083A24;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A1Bu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A21u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083A24: cpu->eip = LIFT_CODE_TOKEN_VA(0x483A24u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) == (uint32_t)(0u)) goto label_00083A50;
    cpu->edx = 0x239u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A39u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00083A50;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A47u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A4Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083A50: cpu->eip = LIFT_CODE_TOKEN_VA(0x483A50u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083A7D;
    cpu->edx = 0x23Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A66u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00083A7D;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A74u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483A7Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083A7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x483A7Du);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483A80u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store_f32(cpu->edi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x28u));
    lift_store_f32(cpu->edi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load8(cpu->esi + 0x2Cu);
    lift_store8(cpu->edi + 0x2Cu, cpu->eax & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x2Du)) & 0xFFu);
    lift_store8(cpu->edi + 0x2Du, cpu->ecx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x2Eu)) & 0xFFu);
    lift_store8(cpu->edi + 0x2Eu, cpu->edx & 0xFFu);
    cpu->eax = lift_load8(cpu->esi + 0x2Fu);
    lift_store8(cpu->edi + 0x2Fu, cpu->eax & 0xFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x83AB7u), LIFT_CODE_TOKEN_RVA(0x83AB5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483AB7u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFFu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->edi + 0x38u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x83AC4u), LIFT_CODE_TOKEN_RVA(0x83AC2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483AC4u);
    lift_store32(cpu->edi + 0x3Cu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x83AC9u), LIFT_CODE_TOKEN_RVA(0x83AC7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483AC9u);
    lift_store32(cpu->edi + 0x40u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x44u);
    lift_store32(cpu->edi + 0x44u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x48u);
    lift_store32(cpu->edi + 0x48u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x4Cu);
    lift_store32(cpu->edi + 0x4Cu, cpu->ecx);
    cpu->esi += 0x50u;
    cpu->edi += 0x50u;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483B00u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    cpu->esi = cpu->ecx;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x83B0Cu), LIFT_CODE_TOKEN_RVA(0x83B0Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483B0Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFFu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->esi + 0x38u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x83B19u), LIFT_CODE_TOKEN_RVA(0x83B17u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483B19u);
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x83B1Eu), LIFT_CODE_TOKEN_RVA(0x83B1Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483B1Eu);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083B55;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483B30u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x94u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00083B55;
    cpu->edx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CEffectMesh::Initialize() -> Texture '%s' not found");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483B4Cu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483B52u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_00083B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x483B55u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483B60u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00083BBC;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00083B74: cpu->eip = LIFT_CODE_TOKEN_VA(0x483B74u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00083B74;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083BBC;
    cpu->edx = 0x272u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483B8Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00083B93: cpu->eip = LIFT_CODE_TOKEN_VA(0x483B93u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00083B93;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483BA3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00083BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x483BB0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00083BB0;
    goto label_00083BC2;
    label_00083BBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x483BBCu);
    lift_store32(cpu->edi, 0u);
    label_00083BC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x483BC2u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00083BDE;
    cpu->edx = 0x277u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483BD5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483BDBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083BDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x483BDEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483BF0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->edi + 0x90u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00083C50;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00083C08: cpu->eip = LIFT_CODE_TOKEN_VA(0x483C08u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00083C08;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083C50;
    cpu->edx = 0x283u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483C22u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00083C27: cpu->eip = LIFT_CODE_TOKEN_VA(0x483C27u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00083C27;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483C37u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 0x90u, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    label_00083C44: cpu->eip = LIFT_CODE_TOKEN_VA(0x483C44u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00083C44;
    goto label_00083C5A;
    label_00083C50: cpu->eip = LIFT_CODE_TOKEN_VA(0x483C50u);
    lift_store32(cpu->edi + 0x90u, 0u);
    label_00083C5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x483C5Au);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00083C76;
    cpu->edx = 0x288u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483C6Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483C73u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083C76: cpu->eip = LIFT_CODE_TOKEN_VA(0x483C76u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483C80u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083F1E;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 8u)), r=(uint64_t)(0x20u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->ebx + 0x44u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ebx + 0x48u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebx + 0x4Cu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083D0F;
    cpu->ecx = lift_load32(cpu->ebx + 0x14u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083CF3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483CD5u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->ebx + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x48u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->ebx + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x4Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->ebx + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00083CF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x483CF3u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 8u)), r=(uint64_t)(0x8000000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083E9C;
    cpu->edi = (uint32_t)(cpu->ebx + 0x50u);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    goto label_00083E9C;
    label_00083D0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x483D0Fu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x40u);
    cpu->ebp = 0u;
    cpu->edi = (uint32_t)(cpu->ebx + 0x50u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x483D19u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x483D1Eu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->edi + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->edi + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebx + 0xCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083DB3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483D47u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00083D71;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->edi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483D6Fu); lift_push32(cpu, r); sfera_sub_004825A0(cpu,r); if (cpu->eip != r) return; }
    goto label_00083DAE;
    label_00083D71: cpu->eip = LIFT_CODE_TOKEN_VA(0x483D71u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_00083D86;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483D84u); lift_push32(cpu, r); sfera_sub_00482720(cpu,r); if (cpu->eip != r) return; }
    goto label_00083DAE;
    label_00083D86: cpu->eip = LIFT_CODE_TOKEN_VA(0x483D86u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_00083D9B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483D99u); lift_push32(cpu, r); sfera_sub_004826C0(cpu,r); if (cpu->eip != r) return; }
    goto label_00083DAE;
    label_00083D9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x483D9Bu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00083DB3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x83DAEu); lift_push32(cpu, r); sfera_sub_00482780(cpu,r); if (cpu->eip != r) return; }
    label_00083DAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x483DAEu);
    cpu->ebp = 1u;
    label_00083DB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x483DB3u);
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083E3F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483DD0u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00083E2B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x60u))));
    lift_store_f32(cpu->ebx + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x70u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x54u))));
    lift_store_f32(cpu->ebx + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ebx + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x74u))));
    lift_store_f32(cpu->ebx + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x58u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->ebx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x68u))));
    lift_store_f32(cpu->ebx + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x78u))));
    goto label_00083E3C;
    label_00083E2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x483E2Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->ebx + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_00083E3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x483E3Cu);
    lift_store_f32(cpu->ebx + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00083E3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x483E3Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x44u));
    cpu->ecx = lift_load32(cpu->ebx + 0x14u);
    lift_store_f32(cpu->ebx + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x48u));
    lift_store_f32(cpu->ebx + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x4Cu));
    lift_store_f32(cpu->ebx + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083E89;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483E6Bu); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x5Cu))));
    lift_store_f32(cpu->ebx + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x6Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->ebx + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x7Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->ebx + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00083E89: cpu->eip = LIFT_CODE_TOKEN_VA(0x483E89u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 8u)), r=(uint64_t)(0x8000000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083E9C;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x83E9Cu); lift_push32(cpu, r); sfera_sub_004822F0(cpu,r); if (cpu->eip != r) return; }
    label_00083E9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x483E9Cu);
    cpu->esi = lift_load32(cpu->ebx + 0x38u);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(9u), 32u);
    cpu->esi += g_sfera_effect_manager.particle_random_table;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 8u)), r=(uint64_t)(0x4000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083EF4;
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083ED3;
    cpu->edx = lift_load32(cpu->ebx + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebx + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x83ED3u); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_00083ED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x483ED3u);
    cpu->ecx = lift_load32(cpu->ebx + 0x1Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083EF4;
    cpu->eax = lift_load32(cpu->ebx + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->edx = lift_load32(cpu->ebx + 0x3Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x83EF4u); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_00083EF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x483EF4u);
    if ((uint32_t)((lift_load32(cpu->ebx + 8u)) & (0x8000u)) == 0u) goto label_00083F1E;
    cpu->ecx = lift_load32(cpu->ebx + 0x20u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00083F1E;
    cpu->edx = lift_load32(cpu->ebx + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ebx += 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x83F1Eu); lift_push32(cpu, r); sfera_sub_0042D430(cpu,r); if (cpu->eip != r) return; }
    label_00083F1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x483F1Eu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483F40u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00083F48;
    lift_return(cpu, 0u, stop_address); return;
    label_00083F48: cpu->eip = LIFT_CODE_TOKEN_VA(0x483F48u);
    cpu->eax = lift_load32(cpu->eax + 0x24u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00483F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x483F50u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) != (uint32_t)(0u)) goto label_000843F3;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_00083F7F;
    cpu->edx = 0x47Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483F74u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483F7Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083F7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x483F7Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x50u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00083FAC;
    cpu->edx = 0x47Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483F95u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x50u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00083FAC;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483FA3u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483FA9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083FAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x483FACu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x54u)) == (uint32_t)(0u)) goto label_00083FD8;
    cpu->edx = 0x47Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483FC1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x54u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00083FD8;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483FCFu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483FD5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00083FD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x483FD8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x58u)) == (uint32_t)(0u)) goto label_00084004;
    cpu->edx = 0x47Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483FEDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x58u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00084004;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x483FFBu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484001u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084004: cpu->eip = LIFT_CODE_TOKEN_VA(0x484004u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) == (uint32_t)(0u)) goto label_00084030;
    cpu->edx = 0x481u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484019u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00084030;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484027u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48402Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084030: cpu->eip = LIFT_CODE_TOKEN_VA(0x484030u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x80u)) == (uint32_t)(0u)) goto label_00084062;
    cpu->edx = 0x482u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484048u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x80u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00084062;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484059u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48405Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084062: cpu->eip = LIFT_CODE_TOKEN_VA(0x484062u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x84u)) == (uint32_t)(0u)) goto label_00084094;
    cpu->edx = 0x483u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48407Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x84u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00084094;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48408Bu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484091u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084094: cpu->eip = LIFT_CODE_TOKEN_VA(0x484094u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x78u)) == (uint32_t)(0u)) goto label_000840C0;
    cpu->edx = 0x484u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4840A9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x78u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000840C0;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4840B7u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4840BDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000840C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4840C0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x16Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00084133;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x15Cu)) <= (uint32_t)(cpu->edi)) goto label_00084115;
    label_000840D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4840D4u);
    cpu->ecx = lift_load32(cpu->esi + 0x16Cu);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_0008410C;
    cpu->edx = 0x489u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4840EFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x16Cu);
    cpu->ebx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008410C;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484103u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484109u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008410C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48410Cu);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x15Cu))) goto label_000840D4;
    label_00084115: cpu->eip = LIFT_CODE_TOKEN_VA(0x484115u);
    cpu->edx = 0x48Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484124u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x16Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484130u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084133: cpu->eip = LIFT_CODE_TOKEN_VA(0x484133u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x170u)) == (uint32_t)(0u)) goto label_000841AF;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x160u)) <= (uint32_t)(cpu->edi)) goto label_00084191;
    label_00084150: cpu->eip = LIFT_CODE_TOKEN_VA(0x484150u);
    cpu->ecx = lift_load32(cpu->esi + 0x170u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_00084188;
    cpu->edx = 0x491u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48416Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x170u);
    cpu->ebx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00084188;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48417Fu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484185u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084188: cpu->eip = LIFT_CODE_TOKEN_VA(0x484188u);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x160u))) goto label_00084150;
    label_00084191: cpu->eip = LIFT_CODE_TOKEN_VA(0x484191u);
    cpu->edx = 0x493u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4841A0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x170u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4841ACu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000841AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4841AFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x174u)) == (uint32_t)(0u)) goto label_00084221;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x164u)) <= (uint32_t)(cpu->edi)) goto label_00084203;
    label_000841C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4841C2u);
    cpu->ecx = lift_load32(cpu->esi + 0x174u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_000841FA;
    cpu->edx = 0x499u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4841DDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x174u);
    cpu->ebx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000841FA;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4841F1u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4841F7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000841FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4841FAu);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x164u))) goto label_000841C2;
    label_00084203: cpu->eip = LIFT_CODE_TOKEN_VA(0x484203u);
    cpu->edx = 0x49Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484212u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x174u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48421Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084221: cpu->eip = LIFT_CODE_TOKEN_VA(0x484221u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x178u)) == (uint32_t)(0u)) goto label_00084293;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x168u)) <= (uint32_t)(cpu->edi)) goto label_00084275;
    label_00084234: cpu->eip = LIFT_CODE_TOKEN_VA(0x484234u);
    cpu->ecx = lift_load32(cpu->esi + 0x178u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_0008426C;
    cpu->edx = 0x4A0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48424Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x178u);
    cpu->ebx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008426C;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484263u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484269u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008426C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48426Cu);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x168u))) goto label_00084234;
    label_00084275: cpu->eip = LIFT_CODE_TOKEN_VA(0x484275u);
    cpu->edx = 0x4A1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484284u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x178u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484290u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084293: cpu->eip = LIFT_CODE_TOKEN_VA(0x484293u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x40u)) == (uint32_t)(0u)) goto label_000842BF;
    cpu->edx = 0x4A4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4842A8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x40u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000842BF;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4842B6u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4842BCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000842BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4842BFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x44u)) == (uint32_t)(0u)) goto label_000842EB;
    cpu->edx = 0x4A5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4842D4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x44u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000842EB;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4842E2u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4842E8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000842EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4842EBu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) == (uint32_t)(0u)) goto label_0008430C;
    cpu->edx = 0x4A6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484300u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484309u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008430C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48430Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x17Cu)) == (uint32_t)(0u)) goto label_00084378;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x180u)) <= (uint32_t)(cpu->ebx)) goto label_0008435A;
    cpu->edi = 0u;
    label_00084321: cpu->eip = LIFT_CODE_TOKEN_VA(0x484321u);
    cpu->edx = lift_load32(cpu->esi + 0x17Cu);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->edx)) == (uint32_t)(0u)) goto label_0008434E;
    cpu->edx = 0x4ACu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48433Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x17Cu);
    cpu->ecx = lift_load32(cpu->edi + cpu->eax);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48434Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008434E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48434Eu);
    ++cpu->ebx;
    cpu->edi += 0x28u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x180u))) goto label_00084321;
    label_0008435A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48435Au);
    cpu->edx = 0x4AEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484369u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x17Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484375u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084378: cpu->eip = LIFT_CODE_TOKEN_VA(0x484378u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x188u)) == (uint32_t)(0u)) goto label_000843F1;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x18Cu)) <= (uint32_t)(cpu->ebx)) goto label_000843C9;
    cpu->edi = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00084390: cpu->eip = LIFT_CODE_TOKEN_VA(0x484390u);
    cpu->eax = lift_load32(cpu->esi + 0x188u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax)) == (uint32_t)(0u)) goto label_000843BD;
    cpu->edx = 0x4B5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4843ABu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x188u);
    cpu->edx = lift_load32(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4843BAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000843BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4843BDu);
    ++cpu->ebx;
    cpu->edi += 0x14u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x18Cu))) goto label_00084390;
    label_000843C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4843C9u);
    cpu->edx = 0x4B7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4843D8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x188u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4843E4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x188u, 0u);
    label_000843F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4843F1u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000843F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4843F3u);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(0u)) goto label_00084414;
    cpu->edx = 0x4BCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484408u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484411u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00084414: cpu->eip = LIFT_CODE_TOKEN_VA(0x484414u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00484420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484420u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->ecx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0x74u, cpu->eax);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00484440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484440u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    cpu->esi = cpu->ecx;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8444Cu), LIFT_CODE_TOKEN_RVA(0x8444Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48444Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFFu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->esi + 0xD8u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8445Cu), LIFT_CODE_TOKEN_RVA(0x8445Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48445Cu);
    lift_store32(cpu->esi + 0xDCu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x84464u), LIFT_CODE_TOKEN_RVA(0x84462u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484464u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x17Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0xE0u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000844CD;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x180u)) <= (uint32_t)(cpu->ebx)) goto label_000844CC;
    cpu->edi = 0u;
    label_00084480: cpu->eip = LIFT_CODE_TOKEN_VA(0x484480u);
    cpu->edx = lift_load32(cpu->esi + 0x17Cu);
    cpu->ecx = lift_load32(cpu->edi + cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000844C0;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484492u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->ecx + cpu->edi + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x17Cu);
    if ((uint32_t)(lift_load32(cpu->eax + cpu->edi + 4u)) != (uint32_t)(0xFFFFFFFFu)) goto label_000844C0;
    cpu->eax = lift_load32(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CParticleSystem::Initialize() -> Texture '%s' not found");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4844B7u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4844BDu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000844C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4844C0u);
    ++cpu->ebx;
    cpu->edi += 0x28u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x180u))) goto label_00084480;
    label_000844CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4844CCu);
    cpu->ebx = lift_pop32(cpu);
    label_000844CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4844CDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004844D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4844D0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->ebx + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->ebp + 0x34u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 0x38u);
    lift_store32(cpu->ebp + 0x38u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 0x3Cu);
    lift_store32(cpu->ebp + 0x3Cu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x48u));
    lift_store_f32(cpu->ebp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_store32(cpu->ebp + 0x60u, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x6Cu));
    lift_store_f32(cpu->ebp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = native_function_address32(&::rand);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ebp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebx + 0x4Cu);
    lift_store32(cpu->ebp + 0x4Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x7Cu));
    lift_store_f32(cpu->ebp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebx + 0x8Cu);
    lift_store32(cpu->ebp + 0x8Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 0x90u);
    lift_store32(cpu->ebp + 0x90u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 0x94u);
    lift_store32(cpu->ebp + 0x94u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 0x98u);
    lift_store32(cpu->ebp + 0x98u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 0x9Cu);
    lift_store32(cpu->ebp + 0x9Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    lift_store32(cpu->ebp + 0xA0u, cpu->eax);
    lift_store8(cpu->ebp + 0xD4u, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x84565u), LIFT_CODE_TOKEN_RVA(0x84563u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484565u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFFu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->ebp + 0xD8u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x84575u), LIFT_CODE_TOKEN_RVA(0x84573u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484575u);
    lift_store32(cpu->ebp + 0xDCu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x8457Du), LIFT_CODE_TOKEN_RVA(0x8457Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48457Du);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x4Cu)), r=(uint64_t)(0x40u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = 1u;
    lift_store32(cpu->ebp + 0x194u, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ebx + 0x11Cu);
    cpu->edi = (uint32_t)(cpu->ebp + 0x11Cu);
    cpu->ecx = 0x10u;
    lift_store32(cpu->ebp + 0xE0u, cpu->eax);
    lift_store32(cpu->ebp + 0x74u, cpu->edx);
    lift_store32(cpu->ebp + 0x190u, cpu->edx);
    lift_movs32(cpu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000845F4;
    cpu->edx = 0u;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x5Cu)) <= (uint32_t)(cpu->edx)) goto label_00084616;
    cpu->eax = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000845C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4845C0u);
    cpu->edi = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->edi + cpu->eax + 0x48u);
    cpu->esi = lift_load32(cpu->ebx + 4u);
    cpu->edi += cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->esi += cpu->eax;
    cpu->ecx = 0x14u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx + cpu->eax + 0x48u, cpu->esi);
    ++cpu->edx;
    cpu->eax += 0x50u;
    if ((uint32_t)(cpu->edx) < (uint32_t)(lift_load32(cpu->ebx + 0x5Cu))) goto label_000845C0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000845F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4845F4u);
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x5Cu)) <= (uint32_t)(cpu->eax)) goto label_00084616;
    lift_x87_push(cpu, (double)-1.0f);
    cpu->ecx = 0u;
    label_00084603: cpu->eip = LIFT_CODE_TOKEN_VA(0x484603u);
    cpu->esi = lift_load32(cpu->ebp + 4u);
    lift_store_f32(cpu->esi + cpu->ecx + 0x28u, lift_x87_get(cpu, 0u));
    cpu->eax += cpu->edx;
    cpu->ecx += 0x50u;
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ebx + 0x5Cu))) goto label_00084603;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00084616: cpu->eip = LIFT_CODE_TOKEN_VA(0x484616u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00484620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484620u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0008467C;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00084634: cpu->eip = LIFT_CODE_TOKEN_VA(0x484634u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00084634;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008467C;
    cpu->edx = 0x7A4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48464Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00084653: cpu->eip = LIFT_CODE_TOKEN_VA(0x484653u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00084653;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484663u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00084670: cpu->eip = LIFT_CODE_TOKEN_VA(0x484670u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00084670;
    goto label_00084682;
    label_0008467C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48467Cu);
    lift_store32(cpu->edi, 0u);
    label_00084682: cpu->eip = LIFT_CODE_TOKEN_VA(0x484682u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008469E;
    cpu->edx = 0x7AAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484695u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48469Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008469E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48469Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004846B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4846B0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x17Cu)) == (uint32_t)(cpu->ebp)) goto label_00084732;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x180u)) <= (uint32_t)(cpu->ebp)) goto label_00084708;
    cpu->edi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000846D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4846D0u);
    cpu->eax = lift_load32(cpu->esi + 0x17Cu);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax)) == (uint32_t)(cpu->ebp)) goto label_000846FC;
    cpu->edx = 0x7B7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4846EAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    cpu->edx = lift_load32(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4846F9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000846FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4846FCu);
    ++cpu->ebx;
    cpu->edi += 0x28u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x180u))) goto label_000846D0;
    label_00084708: cpu->eip = LIFT_CODE_TOKEN_VA(0x484708u);
    cpu->edx = 0x7B9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484717u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x17Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484723u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x17Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x180u, cpu->ebp);
    label_00084732: cpu->eip = LIFT_CODE_TOKEN_VA(0x484732u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_00084A07;
    cpu->edx = 0x7BFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48474Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x28u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484765u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    cpu->esp += 4u;
    cpu->ebx = 0u;
    cpu->edx |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0x17Cu, cpu->eax);
    lift_store32(cpu->esi + 0x180u, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00084977;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFCu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax = 0u;
    ++cpu->ecx;
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->ecx) * 4u));
    label_00084796: cpu->eip = LIFT_CODE_TOKEN_VA(0x484796u);
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + cpu->ebp, 0u);
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ebp + 4u, cpu->edx);
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 8u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x18u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ebp + 0x28u, 0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ebp + 0x2Cu, cpu->edx);
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x30u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x34u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x38u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x40u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x44u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x48u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x4Cu, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ebp + 0x50u, 0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ebp + 0x54u, cpu->edx);
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x58u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x5Cu, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x60u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x64u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x68u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x6Cu, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x70u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0x74u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ebp + 0x78u, 0u);
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ebp + 0x7Cu, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x80u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0x84u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax += 0xA0u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store_f32(cpu->eax + cpu->ebp + 0xFFFFFFE8u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0xFFFFFFECu, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0xFFFFFFF0u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ebp + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ebp + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00084796;
    label_00084977: cpu->eip = LIFT_CODE_TOKEN_VA(0x484977u);
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->edi)) goto label_00084A03;
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edi -= cpu->ebx;
    label_0008498A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48498Au);
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + cpu->ecx, 0u);
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->eax + cpu->ecx + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ecx + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ecx + 0xCu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax += 0x28u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    lift_store_f32(cpu->eax + cpu->ecx + 0xFFFFFFE8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ecx + 0xFFFFFFECu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ecx + 0xFFFFFFF0u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    lift_store_f32(cpu->eax + cpu->ecx + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ecx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x17Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->ecx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008498A;
    label_00084A03: cpu->eip = LIFT_CODE_TOKEN_VA(0x484A03u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00084A07: cpu->eip = LIFT_CODE_TOKEN_VA(0x484A07u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00484A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484A10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00084A43;
    cpu->edx = 0x7FEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484A29u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484A32u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x2Cu, 0u);
    lift_store32(cpu->esi + 0x30u, 0u);
    label_00084A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x484A43u);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00084A7B;
    cpu->edx = 0x805u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484A5Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0xCu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484A72u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    label_00084A7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x484A7Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00484A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484A80u);
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 4u));
    cpu->esi = cpu->ecx;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(4u), 32u);
    cpu->edi += lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) == (uint32_t)(0u)) goto label_00084AA7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x6Cu));
    goto label_00084AC5;
    label_00084AA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x484AA7u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84AA9u), LIFT_CODE_TOKEN_RVA(0x84AA7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484AA9u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x68u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x6Cu))));
    label_00084AC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x484AC5u);
    lift_store_f32(cpu->edi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84ACAu), LIFT_CODE_TOKEN_RVA(0x84AC8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484ACAu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFEu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->edi + 0x34u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84AD7u), LIFT_CODE_TOKEN_RVA(0x84AD5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484AD7u);
    lift_store16(cpu->edi + 0x38u, cpu->eax & 0xFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84ADDu), LIFT_CODE_TOKEN_RVA(0x84ADBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484ADDu);
    lift_store16(cpu->edi + 0x3Au, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->edi + 0x48u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00084B12;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x4Cu)), r=(uint64_t)(0x1000000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00084B12;
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x5Cu)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00084B12;
    lift_x87_push(cpu, (double)-1.0f);
    cpu->edx = 0u;
    label_00084B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x484B00u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    lift_store_f32(cpu->edx + cpu->ebx + 0x28u, lift_x87_get(cpu, 0u));
    ++cpu->ecx;
    cpu->edx += 0x50u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x5Cu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00084B00;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00084B12: cpu->eip = LIFT_CODE_TOKEN_VA(0x484B12u);
    cpu->ebx = lift_load32(cpu->edi + 0x34u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load16(cpu->edi + 0x3Cu);
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(9u), 32u);
    cpu->ebx += g_sfera_effect_manager.particle_random_table;
    cpu->edx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00084B53;
    cpu->ecx = lift_load16(cpu->edi + 0x3Au);
    cpu->edx = lift_load16(cpu->edi + 0x38u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x16Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484B51u); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    label_00084B53: cpu->eip = LIFT_CODE_TOKEN_VA(0x484B53u);
    cpu->eax = lift_load16(cpu->edi + 0x3Eu);
    cpu->ecx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00084B84;
    cpu->edx = lift_load16(cpu->edi + 0x3Au);
    cpu->ecx = lift_load16(cpu->edi + 0x38u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x170u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484B82u); lift_push32(cpu, r); sfera_sub_0042D430(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    label_00084B84: cpu->eip = LIFT_CODE_TOKEN_VA(0x484B84u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x2Cu));
    lift_store_f32(cpu->edi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edi + 0xCu, cpu->edx);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 0x14u, cpu->ecx);
    if ((uint32_t)((lift_load32(cpu->esi + 0x4Cu)) & (0x80000u)) == 0u) goto label_00084BD2;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84BB8u), LIFT_CODE_TOKEN_RVA(0x84BB6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484BB8u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x180u), 32u, 0u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00084BD2;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00084BD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x484BD2u);
    lift_store_f32(cpu->edi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00084BF0;
    cpu->edx = lift_load32(cpu->esi + 0x1Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x28u));
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x484BE7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x484BEDu);
    cpu->esp += 4u;
    label_00084BF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x484BF0u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(7u)) goto label_0008519E;
    switch ((uint32_t)(cpu->eax)) {
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
label_00084C03: ;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008519E;
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(0u)) goto label_00084C2A;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00084C22;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    label_00084C22: cpu->eip = LIFT_CODE_TOKEN_VA(0x484C22u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    goto label_00084C3A;
    label_00084C2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x484C2Au);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84C2Cu), LIFT_CODE_TOKEN_RVA(0x84C2Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484C2Cu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x30u), 32u, 0u);
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    label_00084C3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x484C3Au);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->edi + 0xCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edi + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edi + 0x14u, cpu->eax);
    goto label_0008519E;
    label_00084C50: cpu->eip = LIFT_CODE_TOKEN_VA(0x484C50u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x28u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00084CC8;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484C7Cu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = lift_load32(cpu->esi + 0x5Cu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x5Cu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00084C9E;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00084C9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x484C9Eu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00084CBA;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00084CBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x484CBAu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00084D07;
    label_00084CC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x484CC8u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84CCEu), LIFT_CODE_TOKEN_RVA(0x84CCCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484CCEu);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84CD4u), LIFT_CODE_TOKEN_RVA(0x84CD2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484CD4u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f64(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484CF5u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_load_f64(cpu->esp + 0x18u)));
    label_00084D07: cpu->eip = LIFT_CODE_TOKEN_VA(0x484D07u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x28u))));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_store32(cpu->edi + 0x10u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edi + 0x14u, cpu->edx);
    goto label_0008519E;
    label_00084D46: cpu->eip = LIFT_CODE_TOKEN_VA(0x484D46u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84D48u), LIFT_CODE_TOKEN_RVA(0x84D46u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484D48u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84D6Au), LIFT_CODE_TOKEN_RVA(0x84D68u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484D6Au);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484D99u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484DAEu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484DC9u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    goto label_0008519B;
    label_00084DE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x484DE2u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84DE4u), LIFT_CODE_TOKEN_RVA(0x84DE2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484DE4u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84E06u), LIFT_CODE_TOKEN_RVA(0x84E04u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484E06u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484E35u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484E4Au); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484E5Fu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    goto label_0008519B;
    label_00084EA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x484EA8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(0u)) goto label_00084F3B;
    cpu->eax = lift_load32(cpu->esi + 0x5Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x5Cu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00084EC2;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00084EC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x484EC2u);
    lift_x87_set(cpu, 0u, (6.283185958862305) / (lift_x87_get(cpu, 0u)));
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esp + 0x28u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00084EE7;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00084EE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x484EE7u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484EF6u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484F0Du); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84F1Du), LIFT_CODE_TOKEN_RVA(0x84F1Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484F1Du);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    goto label_0008519B;
    label_00084F3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x484F3Bu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84F3Du), LIFT_CODE_TOKEN_RVA(0x84F3Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484F3Du);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484F66u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x484F7Du); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84F8Du), LIFT_CODE_TOKEN_RVA(0x84F8Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484F8Du);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    goto label_0008519B;
    label_00084FAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x484FABu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84FADu), LIFT_CODE_TOKEN_RVA(0x84FABu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484FADu);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84FB3u), LIFT_CODE_TOKEN_RVA(0x84FB1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484FB3u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ebp = native_function_address32(&::rand);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84FDDu), LIFT_CODE_TOKEN_RVA(0x84FDBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484FDDu);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x84FE3u), LIFT_CODE_TOKEN_RVA(0x84FE1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x484FE3u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x85007u), LIFT_CODE_TOKEN_RVA(0x85005u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x485007u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x8500Du), LIFT_CODE_TOKEN_RVA(0x8500Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48500Du);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008519B;
    label_00085031: cpu->eip = LIFT_CODE_TOKEN_VA(0x485031u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x85033u), LIFT_CODE_TOKEN_RVA(0x85031u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x485033u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x85055u), LIFT_CODE_TOKEN_RVA(0x85053u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x485055u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485084u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485099u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4850B4u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x850C8u), LIFT_CODE_TOKEN_RVA(0x850C6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4850C8u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x850CEu), LIFT_CODE_TOKEN_RVA(0x850CCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4850CEu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008519B;
    label_000850F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4850F2u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x850F4u), LIFT_CODE_TOKEN_RVA(0x850F2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4850F4u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x85116u), LIFT_CODE_TOKEN_RVA(0x85114u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x485116u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485145u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48515Au); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485175u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485190u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    label_0008519B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48519Bu);
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008519E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48519Eu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x18u)) <= (int32_t)(uint32_t)(0u)) goto label_000851B4;
    lift_native_call(cpu, native_function_address32(&::timeGetTime), LIFT_CODE_TOKEN_VA(0x4851A4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4851AAu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x4851ABu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4851B1u);
    cpu->esp += 4u;
    label_000851B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4851B4u);
    cpu->eax = lift_load32(cpu->esi + 0x4Cu);
    if ((uint32_t)((cpu->eax) & (0x400u)) == 0u) goto label_000851F6;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_000851E8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xB0u))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x10u))));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x14u))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000851F6;
    label_000851E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4851E8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x11Cu);
    cpu->edx = (uint32_t)(cpu->edi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x851F6u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    label_000851F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4851F6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x10u))));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x14u))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    lift_store32(cpu->edi, cpu->edx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00485250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x485250u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x48u));
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x70u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store16(cpu->esp + 0x34u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x34u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x34u));
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000852A3;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000852A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4852A3u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x4Cu)), r=(uint64_t)(0x40000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000853D1;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xBCu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xC0u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xC4u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00085415;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008532E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008532E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00085413;
    label_0008532E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48532Eu);
    lift_x87_push(cpu, 1.0);
    cpu->edi = 0u;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    if ((uint32_t)(lift_load32(cpu->esi + 0x5Cu)) <= (uint32_t)(cpu->edi)) goto label_00085415;
    cpu->ebx = 0u;
    label_00085349: cpu->eip = LIFT_CODE_TOKEN_VA(0x485349u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00085415;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ebx + cpu->ecx + 0x28u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000853BC;
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485369u); lift_push32(cpu, r); sfera_sub_00484A80(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    cpu->eax = (uint32_t)(cpu->ebx + cpu->edx + 0xCu);
    --cpu->ebp;
    lift_store32(cpu->esi + 0x60u, (uint64_t)(lift_load32(cpu->esi + 0x60u)) + 1u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    label_000853BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4853BCu);
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x5Cu))) goto label_00085349;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
    label_000853D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4853D1u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00085417;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x5Cu)) <= (uint32_t)(cpu->edi)) goto label_00085417;
    cpu->ebx = 0u;
    label_000853E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4853E0u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00085417;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->eax + cpu->ebx + 0x28u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00085400;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4853FCu); lift_push32(cpu, r); sfera_sub_00484A80(cpu,r); if (cpu->eip != r) return; }
    --cpu->ebp;
    lift_store32(cpu->esi + 0x60u, (uint64_t)(lift_load32(cpu->esi + 0x60u)) + 1u);
    label_00085400: cpu->eip = LIFT_CODE_TOKEN_VA(0x485400u);
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x5Cu))) goto label_000853E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
    label_00085413: cpu->eip = LIFT_CODE_TOKEN_VA(0x485413u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00085415: cpu->eip = LIFT_CODE_TOKEN_VA(0x485415u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00085417: cpu->eip = LIFT_CODE_TOKEN_VA(0x485417u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00485430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x485430u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->edx = 0x93u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485479u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485480u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0008549F;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48549Bu); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    goto label_000854A1;
    label_0008549F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48549Fu);
    cpu->edi = 0u;
    label_000854A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4854A1u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x88u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4854B9u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000854C9;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4854C5u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->ebx)) goto label_000854F3;
    label_000854C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4854C9u);
    cpu->edx = 0x99u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4854D8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000854EC;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4854E3u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4854E9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000854EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4854ECu);
    cpu->eax = 0u;
    goto label_000856A5;
    label_000854F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4854F3u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4854FFu); lift_push32(cpu, r); sfera_sub_0042E000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x30u);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x485507u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48550Cu);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485517u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485523u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000855B4;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    label_00085534: cpu->eip = LIFT_CODE_TOKEN_VA(0x485534u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d %f %d %d %d %d"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8555Au), LIFT_CODE_TOKEN_RVA(0x85558u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48555Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    cpu->ecx = lift_load8(cpu->esp + 0x38u);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x3Cu)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x40u)) & 0xFFu);
    lift_store8(cpu->esp + 0x74u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load8(cpu->esp + 0x48u);
    cpu->esp += 0x20u;
    lift_store8(cpu->esp + 0x55u, cpu->edx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_store8(cpu->esp + 0x56u, cpu->eax & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x5Bu, cpu->ecx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x50u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4855A0u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4855ACu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00085534;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    label_000855B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4855B4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4855BCu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4855C8u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008569C;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    label_000855D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4855D3u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8560Du), LIFT_CODE_TOKEN_RVA(0x8560Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48560Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    cpu->edx = lift_load8(cpu->esp + 0x48u);
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load8(cpu->esp + 0x50u);
    cpu->eax = lift_load8(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x84u, cpu->edx & 0xFFu);
    cpu->edx = lift_load8(cpu->esp + 0x58u);
    lift_store8(cpu->esp + 0x86u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load8(cpu->esp + 0x68u);
    lift_store8(cpu->esp + 0x85u, cpu->eax & 0xFFu);
    cpu->eax = lift_load8(cpu->esp + 0x6Cu);
    lift_store8(cpu->esp + 0x87u, cpu->edx & 0xFFu);
    cpu->edx = lift_load8(cpu->esp + 0x60u);
    lift_store8(cpu->esp + 0x89u, cpu->ecx & 0xFFu);
    cpu->esp += 0x30u;
    lift_store8(cpu->esp + 0x58u, cpu->eax & 0xFFu);
    cpu->eax = lift_load8(cpu->esp + 0x34u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store8(cpu->esp + 0x5Au, cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x50u, 1u);
    lift_store8(cpu->esp + 0x63u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485688u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"rkey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485694u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000855D3;
    label_0008569C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48569Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4856A3u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    label_000856A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4856A5u);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004856D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4856D0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00085AE3;
    if ((uint32_t)(lift_load32(cpu->edi + 0x90u)) == (uint32_t)(cpu->edx)) goto label_00085AE3;
    cpu->ecx = lift_load32(cpu->eax + 0x24u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0x2710u)) goto label_00085AE3;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 8u)), r=(uint64_t)(0x20u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    cpu->ebp = lift_load32(cpu->ecx + 0x4Cu);
    cpu->ebx = lift_load32(cpu->ecx + 0x48u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x44u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00085779;
    if ((uint32_t)(lift_load32(cpu->eax + 0x28u)) <= (uint32_t)(cpu->edx)) goto label_000857BF;
    cpu->ecx = 0u;
    label_00085730: cpu->eip = LIFT_CODE_TOKEN_VA(0x485730u);
    cpu->eax = lift_load32(cpu->eax + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx));
    ++cpu->edx;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x44u))));
    cpu->ecx += 0xCu;
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x48u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx + 0xFFFFFFFCu));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x4Cu))));
    lift_store32(cpu->ecx + cpu->esi + 0xFFFFFFF4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ecx + cpu->esi + 0xFFFFFFF8u, cpu->eax);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->ecx + cpu->esi + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(lift_load32(cpu->eax + 0x28u))) goto label_00085730;
    goto label_000857BF;
    label_00085779: cpu->eip = LIFT_CODE_TOKEN_VA(0x485779u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((uint32_t)(lift_load32(cpu->eax + 0x28u)) <= (uint32_t)(cpu->edx)) goto label_000857BF;
    cpu->ebp = 0u;
    label_00085784: cpu->eip = LIFT_CODE_TOKEN_VA(0x485784u);
    cpu->eax = lift_load32(cpu->eax + 0x30u);
    cpu->ecx = lift_load32(cpu->eax + cpu->ebp);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + cpu->ebp + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + cpu->ebp + 8u);
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(cpu->edi + 0x50u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4857A4u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    ++cpu->ecx;
    cpu->ebp += 0xCu;
    cpu->esi += 0xCu;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->eax + 0x28u))) goto label_00085784;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    label_000857BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4857BFu);
    if ((uint32_t)((lift_load32(cpu->edi + 8u)) & (0x4000u)) == 0u) goto label_000857FE;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x2Cu)) <= (uint32_t)(cpu->eax)) goto label_00085804;
    label_000857D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4857D2u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u)));
    ++cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x24u))));
    lift_store_f32(cpu->ebx + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x28u))));
    lift_store_f32(cpu->ebx + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edx + 0x2Cu))) goto label_000857D2;
    goto label_00085804;
    label_000857FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4857FEu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ebx = lift_load32(cpu->eax + 0x34u);
    label_00085804: cpu->eip = LIFT_CODE_TOKEN_VA(0x485804u);
    cpu->eax = 0u;
    if ((uint32_t)((lift_load32(cpu->edi + 8u)) & (0x8000u)) == 0u) goto label_0008588A;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load8(cpu->edi + 0x2Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x28u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000858D6;
    (void)cpu;
    label_00085820: cpu->eip = LIFT_CODE_TOKEN_VA(0x485820u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x40u);
    cpu->edx = lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load8(cpu->edi + 0x2Cu);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ecx); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u), cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x40u);
    cpu->edx = lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 1u);
    cpu->ecx = lift_load8(cpu->edi + 0x2Du);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ecx); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 1u, cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x40u);
    cpu->edx = lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 2u);
    cpu->ecx = lift_load8(cpu->edi + 0x2Eu);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ecx); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 2u, cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x40u);
    cpu->edx = lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 3u);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 3u, cpu->edx & 0xFFu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ecx + 0x28u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00085820;
    goto label_000858D6;
    label_0008588A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48588Au);
    cpu->edx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x28u)) <= (uint32_t)(cpu->eax)) goto label_000858D6;
    label_00085892: cpu->eip = LIFT_CODE_TOKEN_VA(0x485892u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    cpu->ecx = lift_load8(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u), cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x40u);
    cpu->edx = lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 1u);
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 1u, cpu->edx & 0xFFu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    cpu->ecx = lift_load8(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 2u);
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 2u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edx + 0x40u);
    cpu->edx = lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 3u);
    lift_store8(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 3u, cpu->edx & 0xFFu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 0x28u))) goto label_00085892;
    label_000858D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4858D6u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->edx + 0x24u)) <= (uint32_t)(cpu->ecx)) goto label_00085AE0;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    goto label_000858F4;
    label_000858F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4858F0u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    label_000858F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4858F4u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->eax + 0x38u);
    cpu->edx = lift_load32(cpu->eax + 0x3Cu);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->ebp = cpu->eax;
    cpu->edx += cpu->ecx;
    ++cpu->eax;
    cpu->esi += cpu->ecx;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00085924;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485920u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    label_00085924: cpu->eip = LIFT_CODE_TOKEN_VA(0x485924u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_0008593C;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485938u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    label_0008593C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48593Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x94u);
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebp += g_sfera_effect_manager.render_slots.data;
    cpu->eax = cpu->ebp;
    lift_store32(cpu->eax + 0x90u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x98u);
    lift_store32(cpu->eax + 0x98u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x30u);
    lift_store32(cpu->eax + 0x94u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = lift_load8(cpu->ecx);
    lift_store32(cpu->eax + 0x30u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 1u);
    lift_store32(cpu->eax + 0x40u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 2u);
    lift_store32(cpu->eax + 0x50u, cpu->ebp);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    lift_store32(cpu->eax + 0x60u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = lift_load8(cpu->ecx);
    lift_store32(cpu->eax + 0x34u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 1u);
    lift_store32(cpu->eax + 0x44u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 2u);
    lift_store32(cpu->eax + 0x54u, cpu->ebp);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    lift_store32(cpu->eax + 0x64u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = lift_load8(cpu->ecx);
    lift_store32(cpu->eax + 0x38u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 1u);
    lift_store32(cpu->eax + 0x48u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 2u);
    lift_store32(cpu->eax + 0x58u, cpu->ebp);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + 0x68u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = lift_load8(cpu->ecx);
    lift_store32(cpu->eax + 0x3Cu, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 1u);
    lift_store32(cpu->eax + 0x4Cu, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ecx + 2u);
    lift_store32(cpu->eax + 0x5Cu, cpu->ebp);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 0x6Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x10u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x18u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x1Cu, cpu->ebp);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x20u, cpu->ecx);
    cpu->esi = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x28u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x2Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u));
    lift_store32(cpu->eax + 0x70u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u) + 4u);
    lift_store32(cpu->eax + 0x74u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u));
    lift_store32(cpu->eax + 0x78u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u) + 4u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x10u) + (uint64_t)(0u));
    lift_store32(cpu->eax + 0x7Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->esi = lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u));
    lift_store32(cpu->eax + 0x80u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u) + 4u);
    lift_store32(cpu->eax + 0x84u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edx + 0xCu);
    cpu->ecx = lift_load32(cpu->ebx + ((uint32_t)(cpu->edx) * 8u));
    lift_store32(cpu->eax + 0x88u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + ((uint32_t)(cpu->edx) * 8u) + 4u);
    lift_store32(cpu->eax + 0x8Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 0x24u))) goto label_000858F0;
    label_00085AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x485AE0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00085AE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x485AE3u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00485AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x485AF0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xC0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xD4u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0xE4u);
    cpu->edi = lift_load32(cpu->esp + 0xE8u);
    cpu->esi = lift_load32(cpu->esp + 0xECu);
    cpu->ebx = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485B56u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x379u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485B65u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485B6Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->eax;
    lift_push32(cpu, (uint32_t)(uintptr_t)"effectmesh_name");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485B85u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085B9F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485B93u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085B9F;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x85B9Fu); lift_push32(cpu, r); sfera_sub_00483B60(cpu,r); if (cpu->eip != r) return; }
    label_00085B9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x485B9Fu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"effectmesh_ssm");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485BACu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085BCA;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485BBAu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085BCA;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485BC5u); lift_push32(cpu, r); sfera_sub_00425A50(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 4u, cpu->eax);
    goto label_00085BE5;
    label_00085BCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x485BCAu);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CEffectMesh::LoadScript(%s) -> SSM Mesh not specified in effectMesh '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485BDCu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485BE2u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00085BE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x485BE5u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"effectmesh_flags");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485BF2u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085C3C;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485BFDu); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00085C38;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00085C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x485C10u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485C1Du); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085C31;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485C2Au); lift_push32(cpu, r); sfera_sub_004827E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, (uint64_t)(lift_load32(cpu->ebx + 8u)) | (uint64_t)(cpu->eax));
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    label_00085C31: cpu->eip = LIFT_CODE_TOKEN_VA(0x485C31u);
    cpu->ebp += 2u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->esi)) goto label_00085C10;
    label_00085C38: cpu->eip = LIFT_CODE_TOKEN_VA(0x485C38u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    label_00085C3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x485C3Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"self_illumination");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485C49u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085C59;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485C56u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x30u, cpu->eax);
    label_00085C59: cpu->eip = LIFT_CODE_TOKEN_VA(0x485C59u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"color");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485C66u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085C8C;
    cpu->ecx = (uint32_t)(cpu->ebx + 0x2Fu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x2Eu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x2Du);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x485C83u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x485C89u);
    cpu->esp += 0x18u;
    label_00085C8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x485C8Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"rotation_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485CA0u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085E5D;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485CB9u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085E5D;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485CCAu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00085E5D;
    cpu->edx = 0x3ABu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485CE3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485CEAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0xDCu, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_00085D07;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485D05u); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    goto label_00085D09;
    label_00085D07: cpu->eip = LIFT_CODE_TOKEN_VA(0x485D07u);
    cpu->eax = 0u;
    label_00085D09: cpu->eip = LIFT_CODE_TOKEN_VA(0x485D09u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0xE0u, 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485D1Fu); lift_push32(cpu, r); sfera_sub_0042E000(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485D2Bu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    lift_store32(cpu->esp + 0x78u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485D3Fu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085E09;
    cpu->ebp = (uint32_t)(cpu->edi + 0x10u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00085D50: cpu->eip = LIFT_CODE_TOKEN_VA(0x485D50u);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x485D6Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x485D75u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_push(cpu, 0.01745329424738884);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x4Cu))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x88u, cpu->edx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    cpu->edx = (uint32_t)(cpu->esp + 0x70u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x8Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x94u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485DF5u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485E01u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00085D50;
    label_00085E09: cpu->eip = LIFT_CODE_TOKEN_VA(0x485E09u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485E10u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485E21u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085E59;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485E33u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085E59;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085E53;
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x485E45u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x485E4Bu);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    ++cpu->eax;
    label_00085E53: cpu->eip = LIFT_CODE_TOKEN_VA(0x485E53u);
    cpu->ecx = lift_load32(cpu->ebx + 0xCu);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_00085E59: cpu->eip = LIFT_CODE_TOKEN_VA(0x485E59u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    label_00085E5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x485E5Du);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"scale_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485E71u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00086006;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485E8Au); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00086006;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485E9Bu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00086006;
    cpu->edx = 0x3CBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485EB4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485EBBu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0xDCu, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_00085EDC;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485EDAu); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    goto label_00085EDE;
    label_00085EDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x485EDCu);
    cpu->eax = 0u;
    label_00085EDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x485EDEu);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0xE0u, 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485EF4u); lift_push32(cpu, r); sfera_sub_0042E000(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485F00u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    lift_store32(cpu->esp + 0x78u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485F14u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085FB2;
    cpu->ebp = (uint32_t)(cpu->edi + 0x10u);
    (void)cpu;
    label_00085F20: cpu->eip = LIFT_CODE_TOKEN_VA(0x485F20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x485F3Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x485F45u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x88u, cpu->edx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    cpu->edx = (uint32_t)(cpu->esp + 0x70u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x8Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x94u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485F9Eu); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485FAAu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00085F20;
    label_00085FB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x485FB2u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485FB9u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485FCAu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00086002;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x485FDCu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00086002;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00085FFC;
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x485FEEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x485FF4u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    ++cpu->eax;
    label_00085FFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x485FFCu);
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_00086002: cpu->eip = LIFT_CODE_TOKEN_VA(0x486002u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    label_00086006: cpu->eip = LIFT_CODE_TOKEN_VA(0x486006u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"position_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48601Au); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000861B9;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486033u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000861B9;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486044u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000861B9;
    cpu->edx = 0x3EAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48605Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486064u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0xDCu, 2u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_00086085;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486083u); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    goto label_00086087;
    label_00086085: cpu->eip = LIFT_CODE_TOKEN_VA(0x486085u);
    cpu->eax = 0u;
    label_00086087: cpu->eip = LIFT_CODE_TOKEN_VA(0x486087u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0xE0u, 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x14u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48609Du); lift_push32(cpu, r); sfera_sub_0042E000(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4860A9u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    lift_store32(cpu->esp + 0xA8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4860C0u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00086165;
    cpu->ebp = (uint32_t)(cpu->edi + 0x10u);
    label_000860D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4860D0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4860EFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4860F5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store32(cpu->esp + 0xB8u, cpu->edx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    cpu->edx = (uint32_t)(cpu->esp + 0xA0u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0xBCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0xC4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486151u); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48615Du); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000860D0;
    label_00086165: cpu->eip = LIFT_CODE_TOKEN_VA(0x486165u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48616Cu); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48617Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000861B5;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48618Fu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000861B5;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0008619B;
    cpu->eax = 0u;
    goto label_000861AF;
    label_0008619B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48619Bu);
    lift_push32(cpu, (uintptr_t)"I_COSINE"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4861A1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4861A7u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    ++cpu->eax;
    label_000861AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4861AFu);
    cpu->edx = lift_load32(cpu->ebx + 0x14u);
    lift_store32(cpu->edx + 8u, cpu->eax);
    label_000861B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4861B5u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    label_000861B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4861B9u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4861CDu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x44u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000861E9;
    lift_push32(cpu, (uintptr_t)"effectmesh->color_track"); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4861E6u); lift_push32(cpu, r); sfera_sub_00485430(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    label_000861E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4861E9u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ucoord_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4861FDu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00086215;
    lift_push32(cpu, (uintptr_t)"effectmesh->ucoord_track"); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486212u); lift_push32(cpu, r); sfera_sub_00482B00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x18u, cpu->eax);
    label_00086215: cpu->eip = LIFT_CODE_TOKEN_VA(0x486215u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"vcoord_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486229u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00086241;
    lift_push32(cpu, (uintptr_t)"effectmesh->vcoord_track"); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48623Eu); lift_push32(cpu, r); sfera_sub_00482B00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1Cu, cpu->eax);
    label_00086241: cpu->eip = LIFT_CODE_TOKEN_VA(0x486241u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"texture_def");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486255u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000862E2;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"blendmode");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebx + 0x98u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486278u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000862B7;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48628Au); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000862B7;
    cpu->ebp = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"PS_BLENDADD"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x8629Cu), LIFT_CODE_TOKEN_RVA(0x8629Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48629Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000862AC;
    lift_store32(cpu->ebx + 0x98u, (uint64_t)(lift_load32(cpu->ebx + 0x98u)) | (uint64_t)(1u));
    goto label_000862B7;
    label_000862AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4862ACu);
    lift_push32(cpu, (uintptr_t)"PS_BLENDALPHA"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x862B4u), LIFT_CODE_TOKEN_RVA(0x862B2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4862B4u);
    cpu->esp += 8u;
    label_000862B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4862B7u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4862C8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000862E2;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4862D6u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000862E2;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x862E2u); lift_push32(cpu, r); sfera_sub_00483BF0(cpu,r); if (cpu->eip != r) return; }
    label_000862E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4862E2u);
    cpu->ebp = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x862EAu), LIFT_CODE_TOKEN_RVA(0x862E8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4862EAu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFFu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->ebx + 0x38u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x862F7u), LIFT_CODE_TOKEN_RVA(0x862F5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4862F7u);
    lift_store32(cpu->ebx + 0x3Cu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x862FCu), LIFT_CODE_TOKEN_RVA(0x862FAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4862FCu);
    cpu->ecx = lift_load32(cpu->ebx + 0x90u);
    lift_store32(cpu->ebx + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086333;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48630Eu); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x94u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00086333;
    cpu->edx = lift_load32(cpu->ebx + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CEffectMesh::Initialize() -> Texture '%s' not found");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48632Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486330u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_00086333: cpu->eip = LIFT_CODE_TOKEN_VA(0x486333u);
    cpu->edx = 0x424u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486342u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48634Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48635Bu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0xD4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00486390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x486390u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x44u);
    cpu->edi = 0u;
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4863A0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4863A5u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xB0u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xB4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xBCu, cpu->ecx);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 0xC0u, cpu->edx);
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xB8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xC4u, cpu->eax);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x98u, cpu->ecx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x9Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xA0u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x8Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xA4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x94u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 0xA8u, cpu->edx);
    lift_store32(cpu->esi + 0x4Cu, cpu->edi);
    lift_store32(cpu->esi + 0x5Cu, cpu->edi);
    lift_store32(cpu->esi + 0x60u, cpu->edi);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_store32(cpu->esi, cpu->edi);
    lift_store32(cpu->esi + 0x50u, cpu->edi);
    lift_store32(cpu->esi + 0x58u, cpu->edi);
    lift_store32(cpu->esi + 0x54u, cpu->edi);
    lift_store32(cpu->esi + 0x64u, cpu->edi);
    lift_store32(cpu->esi + 0x78u, cpu->edi);
    lift_store32(cpu->esi + 0x80u, cpu->edi);
    lift_store32(cpu->esi + 0x84u, cpu->edi);
    lift_store8(cpu->esi + 0xD4u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0xACu, cpu->ecx);
    lift_store32(cpu->esi + 0xE4u, cpu->edi);
    lift_store32(cpu->esi + 0xD8u, cpu->edi);
    lift_store32(cpu->esi + 0xE8u, cpu->edi);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xECu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xF0u, cpu->ecx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xF8u, cpu->ecx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0xF4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xFCu, cpu->edx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x100u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x104u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x108u, cpu->ecx);
    lift_store_f32(cpu->esi + 0x184u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->esi + 0x110u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x10Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 0x15Cu, cpu->edi);
    lift_store32(cpu->esi + 0x160u, cpu->edi);
    lift_store32(cpu->esi + 0x164u, cpu->edi);
    lift_store32(cpu->esi + 0x168u, cpu->edi);
    lift_store32(cpu->esi + 0x16Cu, cpu->edi);
    lift_store32(cpu->esi + 0x170u, cpu->edi);
    lift_store32(cpu->esi + 0x174u, cpu->edi);
    lift_store32(cpu->esi + 0x178u, cpu->edi);
    lift_store32(cpu->esi + 0x180u, cpu->edi);
    lift_store32(cpu->esi + 0x17Cu, cpu->edi);
    lift_store32(cpu->esi + 0x198u, cpu->edi);
    lift_store32(cpu->esi + 0x188u, cpu->edi);
    lift_store32(cpu->esi + 0x18Cu, cpu->edi);
    lift_store32(cpu->esi + 0x194u, cpu->edi);
    lift_store32(cpu->esi + 0x114u, cpu->edx);
    lift_store32(cpu->esi + 0x74u, cpu->eax);
    lift_store32(cpu->esi + 0x190u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x118u, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004865F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4865F0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->ebp)) goto label_00086620;
    cpu->edx = 0x7DAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48660Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486614u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 4u, cpu->ebp);
    lift_store32(cpu->esi + 0x5Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x60u, cpu->ebp);
    label_00086620: cpu->eip = LIFT_CODE_TOKEN_VA(0x486620u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_0008669A;
    cpu->edx = 0x7E2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486637u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x50u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48664Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x5Cu, cpu->edi);
    lift_store32(cpu->esi + 0x60u, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x486661u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x486666u);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebp)) goto label_0008669A;
    cpu->ecx = 0u;
    cpu->edx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebx);
    label_00086673: cpu->eip = LIFT_CODE_TOKEN_VA(0x486673u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax += cpu->ecx;
    cpu->ebx = 0xFFFFu;
    cpu->ecx += 0x50u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    lift_store16(cpu->eax + 0x3Cu, cpu->ebx & 0xFFFFu);
    lift_store16(cpu->eax + 0x3Eu, cpu->ebx & 0xFFFFu);
    lift_store16(cpu->eax + 0x40u, cpu->ebx & 0xFFFFu);
    lift_store16(cpu->eax + 0x42u, cpu->ebx & 0xFFFFu);
    lift_store32(cpu->eax + 0x48u, cpu->ebp);
    lift_store32(cpu->eax + 0x4Cu, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00086673;
    cpu->ebx = lift_pop32(cpu);
    label_0008669A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48669Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004866A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4866A0u);
    cpu->esp -= 0x98u;
    cpu->eax = lift_load32(cpu->esp + 0x9Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x190u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00087200;
    if ((uint8_t)(lift_load8(cpu->ebp + 0xD4u)) != (uint8_t)(1u)) goto label_0008672B;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->ebp + 0xBCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ebp + 0xC0u, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xB0u);
    lift_store32(cpu->ebp + 0xC8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xB8u);
    lift_store32(cpu->ebp + 0xC4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xB4u);
    lift_store32(cpu->ebp + 0xCCu, cpu->ecx);
    lift_store32(cpu->ebp + 0xD0u, cpu->edx);
    lift_store8(cpu->ebp + 0xD4u, 0u);
    goto label_0008674F;
    label_0008672B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48672Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xB0u);
    cpu->edx = lift_load32(cpu->ebp + 0xB4u);
    lift_store32(cpu->ebp + 0xBCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xB8u);
    lift_store32(cpu->ebp + 0xC0u, cpu->edx);
    lift_store32(cpu->ebp + 0xC4u, cpu->ecx);
    label_0008674F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48674Fu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x4Cu)), r=(uint64_t)(0x20u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ebp + 0xB0u, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ebp + 0xB4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xB8u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000867F6;
    cpu->ecx = lift_load32(cpu->ebp + 0x58u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000867CD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->eax = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486794u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0xB0u))));
    lift_store_f32(cpu->ebp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x90u))));
    lift_store_f32(cpu->ebp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x94u))));
    lift_store_f32(cpu->ebp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000867CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4867CDu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x4Cu)), r=(uint64_t)(0x8000000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00086A26;
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00086A26;
    cpu->edi = (uint32_t)(cpu->ebp + 0x11Cu);
    cpu->ecx = 0x10u;
    cpu->esi = cpu->ebx;
    lift_movs32(cpu, 1u);
    goto label_00086A26;
    label_000867F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4867F6u);
    lift_push32(cpu, 0x40u);
    cpu->edi = 0u;
    cpu->esi = (uint32_t)(cpu->ebp + 0x11Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x486802u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x486807u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebp + 0x50u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000868B8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->edx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48683Au); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x4Cu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0008686D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x9Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x98u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48686Bu); lift_push32(cpu, r); sfera_sub_004825A0(cpu,r); if (cpu->eip != r) return; }
    goto label_000868B3;
    label_0008686D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48686Du);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_00086885;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486883u); lift_push32(cpu, r); sfera_sub_00482720(cpu,r); if (cpu->eip != r) return; }
    goto label_000868B3;
    label_00086885: cpu->eip = LIFT_CODE_TOKEN_VA(0x486885u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_0008689D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48689Bu); lift_push32(cpu, r); sfera_sub_004826C0(cpu,r); if (cpu->eip != r) return; }
    goto label_000868B3;
    label_0008689D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48689Du);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_000868B8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x868B3u); lift_push32(cpu, r); sfera_sub_00482780(cpu,r); if (cpu->eip != r) return; }
    label_000868B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4868B3u);
    cpu->edi = 1u;
    label_000868B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4868B8u);
    cpu->ecx = lift_load32(cpu->ebp + 0x54u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086993;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->eax = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4868DBu); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_00086970;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x12Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebp + 0x12Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x13Cu))));
    lift_store_f32(cpu->ebp + 0x13Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x120u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->ebp + 0x120u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x130u))));
    lift_store_f32(cpu->ebp + 0x130u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x140u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebp + 0x140u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x124u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->ebp + 0x124u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x134u))));
    lift_store_f32(cpu->ebp + 0x134u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x144u))));
    goto label_0008698D;
    label_00086970: cpu->eip = LIFT_CODE_TOKEN_VA(0x486970u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_store_f32(cpu->ebp + 0x130u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    label_0008698D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48698Du);
    lift_store_f32(cpu->ebp + 0x144u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00086993: cpu->eip = LIFT_CODE_TOKEN_VA(0x486993u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB0u));
    cpu->ecx = lift_load32(cpu->ebp + 0x58u);
    lift_store_f32(cpu->ebp + 0x128u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB4u));
    lift_store_f32(cpu->ebp + 0x138u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB8u));
    lift_store_f32(cpu->ebp + 0x148u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086A0F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->edx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4869D6u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x128u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x8Cu))));
    lift_store_f32(cpu->ebp + 0x128u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x138u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x90u))));
    lift_store_f32(cpu->ebp + 0x138u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x148u))));
    lift_store_f32(cpu->ebp + 0x148u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00086A0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x486A0Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x4Cu)), r=(uint64_t)(0x8000000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00086A26;
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00086A26;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86A26u); lift_push32(cpu, r); sfera_sub_004822F0(cpu,r); if (cpu->eip != r) return; }
    label_00086A26: cpu->eip = LIFT_CODE_TOKEN_VA(0x486A26u);
    cpu->edi = lift_load32(cpu->ebp + 0xD8u);
    cpu->ecx = lift_load32(cpu->ebp + 0x40u);
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(9u), 32u);
    cpu->edi += g_sfera_effect_manager.particle_random_table;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086A5F;
    cpu->eax = lift_load32(cpu->ebp + 0xE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->edx = lift_load32(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x48u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86A5Fu); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_00086A5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x486A5Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0x44u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086AC2;
    cpu->edx = lift_load32(cpu->ebp + 0xE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->eax = lift_load32(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486A8Du); lift_push32(cpu, r); sfera_sub_0042D9F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((lift_load32(cpu->ebp + 0x4Cu)) & (0x400000u)) == 0u) goto label_00086AAD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    lift_store_f32(cpu->ebp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_store_f32(cpu->ebp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_store_f32(cpu->ebp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00086AC2;
    label_00086AAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x486AADu);
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    cpu->edx = lift_load32(cpu->esp + 0x7Cu);
    lift_store32(cpu->ebp + 0x34u, cpu->eax);
    lift_store32(cpu->ebp + 0x38u, cpu->ecx);
    lift_store32(cpu->ebp + 0x3Cu, cpu->edx);
    label_00086AC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x486AC2u);
    cpu->ecx = lift_load32(cpu->ebp + 0x64u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086AEC;
    cpu->eax = lift_load32(cpu->ebp + 0xE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->edx = lift_load32(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x6Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86AECu); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_00086AEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x486AECu);
    cpu->ecx = lift_load32(cpu->ebp + 0x78u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086B16;
    cpu->edx = lift_load32(cpu->ebp + 0xE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->eax = lift_load32(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0x7Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86B16u); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_00086B16: cpu->eip = LIFT_CODE_TOKEN_VA(0x486B16u);
    cpu->eax = lift_load32(cpu->ebp + 0x4Cu);
    if ((uint32_t)((cpu->eax) & (0x100u)) == 0u) goto label_00086CD0;
    if ((uint32_t)((cpu->eax) & (0x100000u)) == 0u) goto label_00086BFF;
    cpu->ecx = lift_load32(cpu->ebp + 0x188u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->eax = lift_load32(cpu->ebp + 0x88u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486B5Bu); lift_push32(cpu, r); sfera_sub_004866A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->ebp + 0x4Cu);
    cpu->eax = lift_load32(cpu->esi + 0xB0u);
    cpu->ecx = lift_load32(cpu->esi + 0xB4u);
    cpu->edx = lift_load32(cpu->esi + 0xB8u);
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    lift_store32(cpu->esp + 0x78u, cpu->ecx);
    lift_store32(cpu->esp + 0x7Cu, cpu->edx);
    if ((uint32_t)((cpu->ebx) & (0x400u)) != 0u) goto label_00086C98;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (0x20u)) == 0u) goto label_00086BD4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xB0u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xB4u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_store32(cpu->esp + 0x78u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xB8u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x7Cu, cpu->edx);
    goto label_00086C98;
    label_00086BD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x486BD4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x128u))));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x138u))));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x148u))));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00086C98;
    label_00086BFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x486BFFu);
    cpu->ecx = lift_load32(cpu->ebp + 0x84u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086C2F;
    cpu->eax = lift_load32(cpu->ebp + 0xE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->edx = lift_load32(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x98u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86C2Fu); lift_push32(cpu, r); sfera_sub_0042D9F0(cpu,r); if (cpu->eip != r) return; }
    label_00086C2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x486C2Fu);
    cpu->ebx = lift_load32(cpu->ebp + 0x4Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0x98u);
    cpu->edx = lift_load32(cpu->ebp + 0x9Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xA0u);
    lift_store32(cpu->esp + 0x74u, cpu->ecx);
    lift_store32(cpu->esp + 0x78u, cpu->edx);
    lift_store32(cpu->esp + 0x7Cu, cpu->eax);
    if ((uint32_t)((cpu->ebx) & (0x400u)) == 0u) goto label_00086C98;
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (0x20u)) == 0u) goto label_00086C89;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0xB0u))));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x7Cu))));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00086C98;
    label_00086C89: cpu->eip = LIFT_CODE_TOKEN_VA(0x486C89u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x11Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x74u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86C98u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    label_00086C98: cpu->eip = LIFT_CODE_TOKEN_VA(0x486C98u);
    if ((uint32_t)((cpu->ebx) & (0x200000u)) == 0u) goto label_00086CD0;
    cpu->ecx = lift_load32(cpu->ebp + 0x80u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086CD0;
    cpu->edx = lift_load32(cpu->ebp + 0xE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    cpu->eax = lift_load32(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0x8Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86CD0u); lift_push32(cpu, r); sfera_sub_0042D9F0(cpu,r); if (cpu->eip != r) return; }
    label_00086CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x486CD0u);
    if ((uint32_t)((lift_load32(cpu->ebp + 0x4Cu)) & (0x2000000u)) == 0u) goto label_00086D2A;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xC8u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB4u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xCCu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xB8u));
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xD0u))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x86D2Au); lift_push32(cpu, r); sfera_sub_0042F3E0(cpu,r); if (cpu->eip != r) return; }
    label_00086D2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x486D2Au);
    cpu->edi = 0u;
    lift_store32(cpu->ebp + 0x60u, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x5Cu)) <= (uint32_t)(cpu->edi)) goto label_00087194;
    lift_x87_push(cpu, 0.0);
    cpu->ebx = native_function_address32(&::rand);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    label_00086D48: cpu->eip = LIFT_CODE_TOKEN_VA(0x486D48u);
    cpu->esi = lift_load32(cpu->ebp + 4u);
    cpu->esi += lift_load32(cpu->esp + 0x30u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x28u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0008717B;
    if ((uint32_t)((lift_load32(cpu->ebp + 0x4Cu)) & (0x2000u)) != 0u) goto label_00086D72;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (2.0));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00086D72: cpu->eip = LIFT_CODE_TOKEN_VA(0x486D72u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x28u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008717B;
    cpu->edi = lift_load32(cpu->esi + 0x34u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x80u, cpu->eax);
    lift_store32(cpu->esp + 0x84u, cpu->ecx);
    lift_store32(cpu->esp + 0x88u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esi + 0x2Cu))));
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(9u), 32u);
    cpu->edi += g_sfera_effect_manager.particle_random_table;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x4Cu)), r=(uint64_t)(0x1000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00086DDB;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00086DDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x486DDBu);
    cpu->eax = lift_load16(cpu->esi + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->ecx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00086E12;
    cpu->edx = lift_load16(cpu->esi + 0x3Au);
    cpu->ecx = lift_load16(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x16Cu);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486E0Eu); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_00086E12: cpu->eip = LIFT_CODE_TOKEN_VA(0x486E12u);
    cpu->eax = lift_load16(cpu->esi + 0x3Eu);
    cpu->edx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00086E47;
    cpu->ecx = lift_load16(cpu->esi + 0x3Au);
    cpu->edx = lift_load16(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0x170u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486E43u); lift_push32(cpu, r); sfera_sub_0042D430(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_00086E47: cpu->eip = LIFT_CODE_TOKEN_VA(0x486E47u);
    cpu->eax = lift_load16(cpu->esi + 0x40u);
    cpu->ecx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00086E7E;
    cpu->edx = lift_load16(cpu->esi + 0x3Au);
    cpu->ecx = lift_load16(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x174u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486E7Au); lift_push32(cpu, r); sfera_sub_0042D9F0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_00086E7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x486E7Eu);
    cpu->eax = lift_load16(cpu->esi + 0x42u);
    cpu->edx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00086EF6;
    cpu->ecx = lift_load16(cpu->esi + 0x3Au);
    cpu->edx = lift_load16(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0x178u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486EB3u); lift_push32(cpu, r); sfera_sub_0042D9F0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x98u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x9Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_00086EF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x486EF6u);
    cpu->eax = lift_load32(cpu->ebp + 0x4Cu);
    if ((uint32_t)((cpu->eax) & (0x100u)) == 0u) goto label_00087068;
    cpu->ecx = lift_load32(cpu->ebp + 0x80u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00086F38;
    if ((uint32_t)((cpu->eax) & (0x200000u)) != 0u) goto label_00086F38;
    cpu->edx = lift_load32(cpu->ebp + 0xE0u);
    cpu->eax = lift_load32(cpu->ebp + 0xDCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0x8Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x486F34u); lift_push32(cpu, r); sfera_sub_0042D9F0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_00086F38: cpu->eip = LIFT_CODE_TOKEN_VA(0x486F38u);
    cpu->eax = lift_load32(cpu->ebp + 0x4Cu);
    if ((uint32_t)((cpu->eax) & (0x20000u)) == 0u) goto label_00086FFB;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008706A;
    label_00086FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x486FFBu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x90u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x94u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008706A;
    label_00087068: cpu->eip = LIFT_CODE_TOKEN_VA(0x487068u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008706A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48706Au);
    if ((uint32_t)((cpu->eax) & (0x10000u)) == 0u) goto label_000870D7;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x87073u), LIFT_CODE_TOKEN_RVA(0x87071u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x487073u);
    cpu->edi = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x87077u), LIFT_CODE_TOKEN_RVA(0x87075u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x487077u);
    cpu->edi -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0xA4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x87095u), LIFT_CODE_TOKEN_RVA(0x87093u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x487095u);
    cpu->edi = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x87099u), LIFT_CODE_TOKEN_RVA(0x87097u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x487099u);
    cpu->edi -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0xA8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x870B7u), LIFT_CODE_TOKEN_RVA(0x870B5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4870B7u);
    cpu->edi = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x870BBu), LIFT_CODE_TOKEN_RVA(0x870B9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4870BBu);
    cpu->edi -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0xACu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000870D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4870D7u);
    if ((uint32_t)((lift_load32(cpu->ebp + 0x4Cu)) & (0x2000000u)) == 0u) goto label_00087116;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00087116: cpu->eip = LIFT_CODE_TOKEN_VA(0x487116u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x184u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x44u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->ebp + 0x180u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00087168;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00087168: cpu->eip = LIFT_CODE_TOKEN_VA(0x487168u);
    LIFT_X87_COMPARE_POP2_AX();
    lift_x87_push(cpu, 0.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00087176;
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    label_00087176: cpu->eip = LIFT_CODE_TOKEN_VA(0x487176u);
    lift_store32(cpu->ebp + 0x60u, (uint64_t)(lift_load32(cpu->ebp + 0x60u)) + 1u);
    cpu->edi = 0u;
    label_0008717B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48717Bu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x30u, (uint64_t)(lift_load32(cpu->esp + 0x30u)) + (uint64_t)(0x50u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ebp + 0x5Cu))) goto label_00086D48;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00087194: cpu->eip = LIFT_CODE_TOKEN_VA(0x487194u);
    if ((uint8_t)((lift_load8(cpu->ebp + 0x4Cu)) & (0x80u)) == 0u) goto label_000871B9;
    lift_push32(cpu, 0x9A7u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4871AEu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4871B4u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    goto label_000871E7;
    label_000871B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4871B9u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x74u)) == (uint32_t)(cpu->edi)) goto label_000871CF;
    lift_x87_push(cpu, (double)2.0f);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x871CFu); lift_push32(cpu, r); sfera_sub_00485250(cpu,r); if (cpu->eip != r) return; }
    label_000871CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4871CFu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x60u)) != (uint32_t)(cpu->edi)) goto label_000871E7;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x74u)) != (uint32_t)(cpu->edi)) goto label_000871E7;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x194u)) == (uint32_t)(cpu->edi)) goto label_000871E7;
    lift_store32(cpu->ebp + 0x190u, cpu->edi);
    label_000871E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4871E7u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4871FEu); lift_push32(cpu, r); sfera_sub_00487220(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00087200: cpu->eip = LIFT_CODE_TOKEN_VA(0x487200u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x98u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00487220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x487220u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)((cpu->eax) & (0x400u)) == 0u) goto label_000872B8;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x5Cu)) <= (uint32_t)(cpu->edi)) goto label_000873FB;
    cpu->ebx = 0u;
    label_00087244: cpu->eip = LIFT_CODE_TOKEN_VA(0x487244u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ecx + cpu->ebx + 0x28u)));
    lift_x87_pop(cpu);
    cpu->ecx += cpu->ebx;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000872A5;
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->eax = (uint32_t)(cpu->ecx + 0x18u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x48u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000872A5;
    if ((uint32_t)((lift_load32(cpu->edx + 0x4Cu)) & (0x800000u)) == 0u) goto label_00087292;
    cpu->ebp = lift_load8(cpu->ecx + 0x27u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x7Cu))));
    lift_store_f32(cpu->edx + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00087292: cpu->eip = LIFT_CODE_TOKEN_VA(0x487292u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ecx + 0x48u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x872A5u); lift_push32(cpu, r); sfera_sub_004866A0(cpu,r); if (cpu->eip != r) return; }
    label_000872A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4872A5u);
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x5Cu))) goto label_00087244;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
    label_000872B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4872B8u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_00087372;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x5Cu)) <= (uint32_t)(cpu->edi)) goto label_000873FB;
    cpu->ebx = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000872D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4872D0u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ecx + cpu->ebx + 0x28u)));
    lift_x87_pop(cpu);
    cpu->ecx += cpu->ebx;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0008735B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB0u));
    cpu->eax = (uint32_t)(cpu->ecx + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x10u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x14u))));
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x48u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008735B;
    if ((uint32_t)((lift_load32(cpu->edx + 0x4Cu)) & (0x800000u)) == 0u) goto label_00087348;
    cpu->ebp = lift_load8(cpu->ecx + 0x27u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x7Cu))));
    lift_store_f32(cpu->edx + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00087348: cpu->eip = LIFT_CODE_TOKEN_VA(0x487348u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ecx + 0x48u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8735Bu); lift_push32(cpu, r); sfera_sub_004866A0(cpu,r); if (cpu->eip != r) return; }
    label_0008735B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48735Bu);
    ++cpu->edi;
    cpu->ebx += 0x50u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x5Cu))) goto label_000872D0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
    label_00087372: cpu->eip = LIFT_CODE_TOKEN_VA(0x487372u);
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x5Cu)) <= (uint32_t)(cpu->ebp)) goto label_000873FB;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    label_00087381: cpu->eip = LIFT_CODE_TOKEN_VA(0x487381u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, 0.0);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edi + 0x28u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000873F0;
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    cpu->edx = lift_load32(cpu->edi + 0x14u);
    cpu->ebx = (uint32_t)(cpu->edi + 0x18u);
    lift_store32(cpu->ebx, cpu->eax);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x11Cu);
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4873B5u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x48u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000873F0;
    if ((uint32_t)((lift_load32(cpu->eax + 0x4Cu)) & (0x800000u)) == 0u) goto label_000873DD;
    cpu->ecx = lift_load8(cpu->edi + 0x27u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x7Cu))));
    lift_store_f32(cpu->eax + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000873DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4873DDu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x48u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x873F0u); lift_push32(cpu, r); sfera_sub_004866A0(cpu,r); if (cpu->eip != r) return; }
    label_000873F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4873F0u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x50u) + (uint64_t)(0u));
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0x5Cu))) goto label_00087381;
    label_000873FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4873FBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00487410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x487410u);
    cpu->esp -= 0xBCu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0x190u)) == (uint32_t)(0u)) goto label_00087D48;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->esi)) goto label_00087457;
    cpu->ebx = 0u;
    label_00087431: cpu->eip = LIFT_CODE_TOKEN_VA(0x487431u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ecx + cpu->ebx + 0x28u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0008744E;
    cpu->ecx = lift_load32(cpu->ecx + cpu->ebx + 0x48u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008744E;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8744Eu); lift_push32(cpu, r); sfera_sub_00487410(cpu,r); if (cpu->eip != r) return; }
    label_0008744E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48744Eu);
    ++cpu->esi;
    cpu->ebx += 0x50u;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_00087431;
    label_00087457: cpu->eip = LIFT_CODE_TOKEN_VA(0x487457u);
    cpu->ecx = lift_load32(cpu->edi + 0x5Cu);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(0x2710u)) goto label_00087D46;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x7Cu));
    lift_push32(cpu, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (256.0));
    lift_store16(cpu->esp + 0x30u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x30u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->eax = 0u;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x38u));
    lift_store64(cpu->esp + 0x6Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->esp + 0x38u, cpu->ebp);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->eax)) goto label_00087D45;
    if ((uint32_t)(lift_load32(cpu->edi + 0x17Cu)) == (uint32_t)(cpu->eax)) goto label_00087D45;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x4Cu)), r=(uint64_t)(0x800u), v=l & r; lift_flags_logic(cpu,v,32u); }
    cpu->edx = lift_load32(cpu->edi + 0x17Cu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esp + 0x88u, cpu->edx);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000877B0;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_00087D45;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000874E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4874E1u);
    cpu->esi = lift_load32(cpu->edi + 4u);
    lift_x87_push(cpu, 0.0);
    cpu->esi += lift_load32(cpu->esp + 0x10u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x28u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0008778E;
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->ebx = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00087513;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x87513u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00087513: cpu->eip = LIFT_CODE_TOKEN_VA(0x487513u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_00087527;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x87527u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00087527: cpu->eip = LIFT_CODE_TOKEN_VA(0x487527u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x44u));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += g_sfera_effect_manager.render_slots.data;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48753Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x4Cu)), r=(uint64_t)(0x200u), v=l & r; lift_flags_logic(cpu,v,32u); }
    cpu->ecx = lift_load32(cpu->edi + 0x17Cu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008759B;
    cpu->edx = lift_load32(cpu->esp + 0x88u);
    lift_store32(cpu->ebx + 0x90u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32(cpu->ebx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32(cpu->ebx + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32(cpu->ebx + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->ebx + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_store_f32(cpu->ebx + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_store_f32(cpu->ebx + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_store_f32(cpu->ebx + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_store_f32(cpu->ebx + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000875A4;
    label_0008759B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48759Bu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ebx + 0x90u, cpu->eax);
    label_000875A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4875A4u);
    cpu->ecx = lift_load32(cpu->edi + 0xE8u);
    lift_store32(cpu->ebx + 0x98u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0xE4u);
    lift_store32(cpu->ebx + 0x94u, cpu->edx);
    cpu->ecx = lift_load8(cpu->esi + 0x27u);
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebp); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->eax = (uint32_t)(cpu->ebx + 0x40u);
    cpu->edx = 4u;
    cpu->edi = cpu->edi;
    label_000875D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4875D0u);
    cpu->ebp = lift_load8(cpu->esi + 0x24u);
    lift_store32(cpu->eax + 0xFFFFFFF0u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->esi + 0x25u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_load8(cpu->esi + 0x26u);
    lift_store32(cpu->eax + 0x10u, cpu->ebp);
    lift_store32(cpu->eax + 0x20u, cpu->ecx);
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000875D0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xECu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0xF4u))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_store32(cpu->ebx, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xF8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x100u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x20u))));
    lift_store32(cpu->ebx + 0xCu, cpu->eax);
    lift_store32(cpu->ebx + 0x10u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    lift_store32(cpu->ebx + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x104u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x108u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x10Cu))));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x78u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x7Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x20u))));
    lift_store32(cpu->ebx + 0x18u, cpu->eax);
    lift_store32(cpu->ebx + 0x1Cu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->ebx + 0x20u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x110u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x114u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x118u))));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x18u))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x60u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x20u))));
    lift_store32(cpu->ebx + 0x24u, cpu->eax);
    lift_store32(cpu->ebx + 0x28u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->ebx + 0x2Cu, cpu->edx);
    label_0008778E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48778Eu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x50u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_000874E1;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xBCu;
    lift_return(cpu, 0u, stop_address); return;
    label_000877B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4877B0u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_00087D45;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000877C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4877C0u);
    cpu->ebx = lift_load32(cpu->edi + 4u);
    lift_x87_push(cpu, 0.0);
    cpu->ebx += lift_load32(cpu->esp + 0x14u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ebx + 0x28u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00087D2E;
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000877F2;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x877F2u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000877F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4877F2u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_00087806;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x87806u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00087806: cpu->eip = LIFT_CODE_TOKEN_VA(0x487806u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x44u));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48781Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x4Cu)), r=(uint64_t)(0x200u), v=l & r; lift_flags_logic(cpu,v,32u); }
    cpu->ecx = lift_load32(cpu->edi + 0x17Cu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008787A;
    cpu->edx = lift_load32(cpu->esp + 0x88u);
    lift_store32(cpu->esi + 0x90u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_store_f32(cpu->esi + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_store_f32(cpu->esi + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_store_f32(cpu->esi + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00087883;
    label_0008787A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48787Au);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    label_00087883: cpu->eip = LIFT_CODE_TOKEN_VA(0x487883u);
    cpu->ecx = lift_load32(cpu->edi + 0xE8u);
    lift_store32(cpu->esi + 0x98u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0xE4u);
    lift_store32(cpu->esi + 0x94u, cpu->edx);
    cpu->ecx = lift_load8(cpu->ebx + 0x27u);
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebp); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->eax = (uint32_t)(cpu->esi + 0x40u);
    cpu->edx = 4u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000878B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4878B0u);
    cpu->ebp = lift_load8(cpu->ebx + 0x24u);
    lift_store32(cpu->eax + 0xFFFFFFF0u, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ebx + 0x25u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_load8(cpu->ebx + 0x26u);
    lift_store32(cpu->eax + 0x10u, cpu->ebp);
    lift_store32(cpu->eax + 0x20u, cpu->ecx);
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000878B0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x30u));
    cpu->eax = lift_load32(cpu->ebx + 0x18u);
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebx + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xECu));
    cpu->edx = lift_load32(cpu->ebx + 0x20u);
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xF0u));
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.x)));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.y)));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.z)));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, -1.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00087A16;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    goto label_00087A77;
    label_00087A16: cpu->eip = LIFT_CODE_TOKEN_VA(0x487A16u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->ecx = 0x5F3759DFu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->ecx -= cpu->eax;
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00087A77: cpu->eip = LIFT_CODE_TOKEN_VA(0x487A77u);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00087AD8;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x78u);
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    goto label_00087B33;
    label_00087AD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x487AD8u);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    cpu->eax = 0x5F3759DFu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax -= cpu->edx;
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00087B33: cpu->eip = LIFT_CODE_TOKEN_VA(0x487B33u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x84u))));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x6Cu))));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x9Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store32(cpu->esi, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xA0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xA4u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xB4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xB8u);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xBCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xA8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    lift_store32(cpu->esi + 0x18u, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xACu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x98u));
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 6u)));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xB0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xC0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store32(cpu->esi + 0x24u, cpu->ecx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xC4u);
    lift_store32(cpu->esi + 0x28u, cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xC8u);
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    label_00087D2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x487D2Eu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x50u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_000877C0;
    label_00087D45: cpu->eip = LIFT_CODE_TOKEN_VA(0x487D45u);
    cpu->ebp = lift_pop32(cpu);
    label_00087D46: cpu->eip = LIFT_CODE_TOKEN_VA(0x487D46u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00087D48: cpu->eip = LIFT_CODE_TOKEN_VA(0x487D48u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xBCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00487D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x487D50u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x88u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x98u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487DAFu); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x4D7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487DBEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487DC8u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"psystem_name");
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487DDCu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000897E3;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487DF2u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000897E3;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E06u); lift_push32(cpu, r); sfera_sub_00484620(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"particles_num");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E13u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000897E3;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E24u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000897E3;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E34u); lift_push32(cpu, r); sfera_sub_004865F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"psystem_flags");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E41u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087E92;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E4Cu); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00087E8E;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00087E60: cpu->eip = LIFT_CODE_TOKEN_VA(0x487E60u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E6Du); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087E81;
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E7Au); lift_push32(cpu, r); sfera_sub_004827E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x4Cu, (uint64_t)(lift_load32(cpu->edi + 0x4Cu)) | (uint64_t)(cpu->eax));
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    label_00087E81: cpu->eip = LIFT_CODE_TOKEN_VA(0x487E81u);
    cpu->esi += 2u;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x34u))) goto label_00087E60;
    label_00087E8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x487E8Eu);
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    label_00087E92: cpu->eip = LIFT_CODE_TOKEN_VA(0x487E92u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec0");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487E9Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087ECA;
    cpu->edx = (uint32_t)(cpu->edi + 0xF4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0xF0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0xECu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487EC1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x487EC7u);
    cpu->esp += 0x14u;
    label_00087ECA: cpu->eip = LIFT_CODE_TOKEN_VA(0x487ECAu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec1");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487ED7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087F02;
    cpu->eax = (uint32_t)(cpu->edi + 0x100u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0xFCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0xF8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487EF9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x487EFFu);
    cpu->esp += 0x14u;
    label_00087F02: cpu->eip = LIFT_CODE_TOKEN_VA(0x487F02u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec2");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487F0Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087F3A;
    cpu->ecx = (uint32_t)(cpu->edi + 0x10Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x108u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x104u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487F31u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x487F37u);
    cpu->esp += 0x14u;
    label_00087F3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x487F3Au);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"transform_vec3");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487F47u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087F72;
    cpu->edx = (uint32_t)(cpu->edi + 0x118u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x114u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x110u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487F69u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x487F6Fu);
    cpu->esp += 0x14u;
    label_00087F72: cpu->eip = LIFT_CODE_TOKEN_VA(0x487F72u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"distortion_vec");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487F7Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087FAA;
    cpu->eax = (uint32_t)(cpu->edi + 0xACu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0xA8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0xA4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x487FA1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x487FA7u);
    cpu->esp += 0x14u;
    label_00087FAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x487FAAu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"self_illumination");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487FB7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087FCA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487FC4u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xE4u, cpu->eax);
    label_00087FCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x487FCAu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"power");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487FD7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00087FE7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487FE4u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00087FE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x487FE7u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"power_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x487FFBu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088017;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->power_trac"); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488014u); lift_push32(cpu, r); sfera_sub_00482B00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x78u, cpu->eax);
    label_00088017: cpu->eip = LIFT_CODE_TOKEN_VA(0x488017u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"position_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48802Bu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088047;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->position_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488044u); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x58u, cpu->eax);
    label_00088047: cpu->eip = LIFT_CODE_TOKEN_VA(0x488047u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"scale_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48805Bu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088077;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->scale_track"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488074u); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x54u, cpu->eax);
    label_00088077: cpu->eip = LIFT_CODE_TOKEN_VA(0x488077u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"rotation_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48808Bu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008822B;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"numkeys");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4880A4u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008822B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4880B5u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0008822B;
    cpu->edx = 0x534u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4880D0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4880D7u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0xA0u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000880F6;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4880F4u); lift_push32(cpu, r); sfera_sub_0042D0F0(cpu,r); if (cpu->eip != r) return; }
    goto label_000880F8;
    label_000880F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4880F6u);
    cpu->eax = 0u;
    label_000880F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4880F8u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0xA4u, 0xFFFFFFFFu);
    lift_store32(cpu->edi + 0x50u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488112u); lift_push32(cpu, r); sfera_sub_0042E000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x30u);
    cpu->edx = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48811Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x488120u);
    cpu->esp += 0xCu;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x68u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488137u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48814Bu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000881EE;
    label_00088153: cpu->eip = LIFT_CODE_TOKEN_VA(0x488153u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %f %f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x488175u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48817Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_push(cpu, 0.01745329424738884);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x78u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x80u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x50u);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x88u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4881DAu); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"key");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4881E6u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00088153;
    label_000881EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4881EEu);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4881F5u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"interpolation");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488206u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008822B;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488218u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008822B;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488225u); lift_push32(cpu, r); sfera_sub_00482A30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x50u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0008822B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48822Bu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"childs_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48823Fu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000883AF;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"childs_num");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488258u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008826B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488265u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x18Cu, cpu->eax);
    label_0008826B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48826Bu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x18Cu)) <= (uint32_t)(0u)) goto label_000883AF;
    cpu->edx = 0x557u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488287u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x18Cu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x14u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4882A3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->edi + 0x188u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->edi + 0x18Cu)) <= (uint32_t)(cpu->ecx)) goto label_000882F1;
    cpu->eax = 0u;
    cpu->edx |= 0xFFFFFFFFu;
    label_000882C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4882C0u);
    cpu->esi = lift_load32(cpu->edi + 0x188u);
    lift_store32(cpu->eax + cpu->esi + 4u, 0u);
    cpu->esi = lift_load32(cpu->edi + 0x188u);
    lift_store32(cpu->eax + cpu->esi, 0u);
    cpu->esi = lift_load32(cpu->edi + 0x188u);
    lift_store32(cpu->eax + cpu->esi + 0x10u, cpu->edx);
    ++cpu->ecx;
    cpu->eax += 0x14u;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x18Cu))) goto label_000882C0;
    label_000882F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4882F1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4882FDu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"child");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488309u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000883A4;
    label_00088311: cpu->eip = LIFT_CODE_TOKEN_VA(0x488311u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48831Au); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48832Au); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088390;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00088335: cpu->eip = LIFT_CODE_TOKEN_VA(0x488335u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00088335;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00088390;
    cpu->edx = 0x565u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48834Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00088356: cpu->eip = LIFT_CODE_TOKEN_VA(0x488356u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00088356;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488366u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x188u);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx += cpu->ecx;
    cpu->esp += 4u;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x188u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ecx + cpu->eax);
    label_00088386: cpu->eip = LIFT_CODE_TOKEN_VA(0x488386u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->edx;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00088386;
    label_00088390: cpu->eip = LIFT_CODE_TOKEN_VA(0x488390u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"child");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48839Cu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00088311;
    label_000883A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4883A4u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4883ABu); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    label_000883AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4883AFu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"magnite_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4883C3u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000886B6;
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"magposition_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4883E3u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088402;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->magposition_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4883FCu); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x84u, cpu->eax);
    label_00088402: cpu->eip = LIFT_CODE_TOKEN_VA(0x488402u);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"magfactor_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48841Au); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008854C;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->magfactor_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488437u); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x80u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008854C;
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) <= (uint32_t)(cpu->esi)) goto label_0008854C;
    label_00088450: cpu->eip = LIFT_CODE_TOKEN_VA(0x488450u);
    cpu->ecx = lift_load32(cpu->edi + 0x80u);
    cpu->edx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488461u); lift_push32(cpu, r); sfera_sub_0042D140(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00088484;
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008848A;
    label_00088484: cpu->eip = LIFT_CODE_TOKEN_VA(0x488484u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0008848A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48848Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000884A3;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000884A5;
    label_000884A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4884A3u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000884A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4884A5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000884C4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000884C6;
    label_000884C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4884C4u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000884C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4884C6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000884E5;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000884E7;
    label_000884E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4884E5u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000884E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4884E7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00088506;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00088508;
    label_00088506: cpu->eip = LIFT_CODE_TOKEN_VA(0x488506u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00088508: cpu->eip = LIFT_CODE_TOKEN_VA(0x488508u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00088527;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008852B;
    label_00088527: cpu->eip = LIFT_CODE_TOKEN_VA(0x488527u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008852B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48852Bu);
    cpu->ecx = lift_load32(cpu->edi + 0x80u);
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48853Cu); lift_push32(cpu, r); sfera_sub_0042D160(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x80u);
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00088450;
    label_0008854C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48854Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"magchildps");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48855Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000885AB;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48856Au); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x88u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0008857C;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x18Cu))) goto label_00088594;
    label_0008857C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48857Cu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CParticleSystem::LoadSc(%s) -> Invalid index in 'magchildps'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48858Bu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488591u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_00088594: cpu->eip = LIFT_CODE_TOKEN_VA(0x488594u);
    cpu->eax = lift_load32(cpu->edi + 0x88u);
    cpu->edx = lift_load32(cpu->edi + 0x188u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 4u, (uint64_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 4u)) + 1u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    label_000885AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4885ABu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"magfactor");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4885BCu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008867A;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4885DCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4885E2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->esp += 0x14u;
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008860C;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    goto label_0008860E;
    label_0008860C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48860Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_0008860E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48860Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00088629;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 3u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    label_00088629: cpu->eip = LIFT_CODE_TOKEN_VA(0x488629u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00088CED;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0008864E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48864Eu);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->edi + 0x8Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->edi + 0x90u, cpu->eax);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    lift_store32(cpu->edi + 0x94u, cpu->ecx);
    label_0008867A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48867Au);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"magpos");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48868Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000886B6;
    cpu->eax = (uint32_t)(cpu->edi + 0xA0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x9Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x98u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4886ADu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4886B3u);
    cpu->esp += 0x14u;
    label_000886B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4886B6u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"emission_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4886CEu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088981;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shape");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4886E7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088709;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4886F9u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088709;
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488706u); lift_push32(cpu, r); sfera_sub_00482A50(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 8u, cpu->eax);
    label_00088709: cpu->eip = LIFT_CODE_TOKEN_VA(0x488709u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"randseed");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48871Au); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008872A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488727u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x18u, cpu->eax);
    label_0008872A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48872Au);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"randfactor");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48873Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008874B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488748u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    label_0008874B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48874Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"height");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48875Cu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008876C;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488769u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008876C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48876Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"width");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48877Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008878D;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48878Au); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008878D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48878Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"radius");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48879Eu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000887AE;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4887ABu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000887AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4887AEu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"emit_num");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4887BFu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000887CF;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4887CCu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000887CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4887CFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"direction");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4887E0u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088802;
    cpu->eax = (uint32_t)(cpu->edi + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4887F9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4887FFu);
    cpu->esp += 0x14u;
    label_00088802: cpu->eip = LIFT_CODE_TOKEN_VA(0x488802u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"emitter_pos");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488813u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088835;
    cpu->edx = (uint32_t)(cpu->edi + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x48882Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x488832u);
    cpu->esp += 0x14u;
    label_00088835: cpu->eip = LIFT_CODE_TOKEN_VA(0x488835u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shape_numpoints");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488846u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088919;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488857u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00088919;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"shape_points");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488879u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088919;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488889u); lift_push32(cpu, r); sfera_sub_00484A10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488895u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->edi + 0x2Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"point");
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x34u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4888ACu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088912;
    label_000888B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4888B0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4888CDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4888D3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_store_f32(cpu->esi + ((uint32_t)(cpu->edx) * 4u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_store_f32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->esp += 0x18u;
    lift_store_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"point");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48890Eu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000888B0;
    label_00088912: cpu->eip = LIFT_CODE_TOKEN_VA(0x488912u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x88919u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    label_00088919: cpu->eip = LIFT_CODE_TOKEN_VA(0x488919u);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"emission_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488931u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008894D;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->emission_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48894Au); lift_push32(cpu, r); sfera_sub_00482B00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x40u, cpu->eax);
    label_0008894D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48894Du);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"emissionpos_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488965u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088981;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->emissionpos_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48897Eu); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x44u, cpu->eax);
    label_00088981: cpu->eip = LIFT_CODE_TOKEN_VA(0x488981u);
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"particleborn_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488999u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088A13;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lifetime");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4889AEu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000889BE;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4889BBu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000889BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4889BEu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"lifetime_rf");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4889CFu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000889DF;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4889DCu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000889DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4889DFu);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lifetime_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4889F7u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088A13;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->lifetime_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488A10u); lift_push32(cpu, r); sfera_sub_00482B00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x64u, cpu->eax);
    label_00088A13: cpu->eip = LIFT_CODE_TOKEN_VA(0x488A13u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"particletracks_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488A27u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088FA8;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"nsize_tracks");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488A40u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088AB7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488A4Du); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x15Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088AB7;
    cpu->edx = 0x600u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488A66u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x15Cu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488A82u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x16Cu, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->eax, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x15Cu)) < (uint32_t)(0x40u)) goto label_00088AB7;
    lift_push32(cpu, 0x602u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488AAEu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488AB4u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088AB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x488AB7u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ncolor_tracks");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488AC8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088B3F;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488AD5u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x160u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088B3F;
    cpu->edx = 0x60Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488AEEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x160u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488B0Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x170u, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->eax, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x160u)) < (uint32_t)(0x40u)) goto label_00088B3F;
    lift_push32(cpu, 0x60Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488B36u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488B3Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088B3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x488B3Fu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"nvelocity_tracks");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488B50u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088BC7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488B5Du); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x164u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088BC7;
    cpu->edx = 0x616u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488B76u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x164u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488B92u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x174u, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->eax, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x164u)) < (uint32_t)(0x40u)) goto label_00088BC7;
    lift_push32(cpu, 0x618u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488BBEu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488BC4u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088BC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x488BC7u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ngravitation_tracks");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488BD8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088C4F;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488BE5u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x168u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088C4F;
    cpu->edx = 0x621u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488BFEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x168u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488C1Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x178u, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->eax, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x168u)) < (uint32_t)(0x40u)) goto label_00088C4F;
    lift_push32(cpu, 0x623u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488C46u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488C4Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088C4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x488C4Fu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x15Cu)) <= (uint32_t)(0u)) goto label_00088D31;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488C6Du); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00088D31;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488C81u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488C92u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088D2A;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00088CA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x488CA0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488CB3u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088CC5;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488CBFu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00088CF4;
    label_00088CC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x488CC5u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x15Cu))) goto label_00088CF4;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->size_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488CE2u); lift_push32(cpu, r); sfera_sub_00482B00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x16Cu);
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    goto label_00088D11;
    label_00088CED: cpu->eip = LIFT_CODE_TOKEN_VA(0x488CEDu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008864E;
    label_00088CF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x488CF4u);
    lift_push32(cpu, 0x639u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D08u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D0Eu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088D11: cpu->eip = LIFT_CODE_TOKEN_VA(0x488D11u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D22u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00088CA0;
    label_00088D2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x488D2Au);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x88D31u); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_00088D31: cpu->eip = LIFT_CODE_TOKEN_VA(0x488D31u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x160u)) <= (uint32_t)(0u)) goto label_00088E06;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D4Fu); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00088E06;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D63u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D74u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088DFF;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00088D80: cpu->eip = LIFT_CODE_TOKEN_VA(0x488D80u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D93u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088DA5;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488D9Fu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00088DCD;
    label_00088DA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x488DA5u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x160u))) goto label_00088DCD;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->color_track"); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488DC2u); lift_push32(cpu, r); sfera_sub_00485430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x170u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    goto label_00088DEA;
    label_00088DCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x488DCDu);
    lift_push32(cpu, 0x64Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488DE1u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488DE7u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088DEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x488DEAu);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488DFBu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00088D80;
    label_00088DFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x488DFFu);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x88E06u); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_00088E06: cpu->eip = LIFT_CODE_TOKEN_VA(0x488E06u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x164u)) <= (uint32_t)(0u)) goto label_00088ED7;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488E24u); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00088ED7;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488E38u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488E49u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088ED0;
    label_00088E51: cpu->eip = LIFT_CODE_TOKEN_VA(0x488E51u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488E64u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088E76;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488E70u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00088E9E;
    label_00088E76: cpu->eip = LIFT_CODE_TOKEN_VA(0x488E76u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x164u))) goto label_00088E9E;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->velocity_track"); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488E93u); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x174u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    goto label_00088EBB;
    label_00088E9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x488E9Eu);
    lift_push32(cpu, 0x665u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488EB2u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488EB8u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088EBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x488EBBu);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488ECCu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00088E51;
    label_00088ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x488ED0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x88ED7u); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_00088ED7: cpu->eip = LIFT_CODE_TOKEN_VA(0x488ED7u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x168u)) <= (uint32_t)(0u)) goto label_00088FA8;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488EF5u); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00088FA8;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F09u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F1Au); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088FA1;
    label_00088F22: cpu->eip = LIFT_CODE_TOKEN_VA(0x488F22u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"track_num");
    cpu->ecx = cpu->ebx;
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F35u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088F47;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F41u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00088F6F;
    label_00088F47: cpu->eip = LIFT_CODE_TOKEN_VA(0x488F47u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x168u))) goto label_00088F6F;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"psystem->gravitation_track"); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F64u); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x178u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    goto label_00088F8C;
    label_00088F6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x488F6Fu);
    lift_push32(cpu, 0x67Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F83u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F89u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00088F8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x488F8Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488F9Du); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00088F22;
    label_00088FA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x488FA1u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x88FA8u); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_00088FA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x488FA8u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"texture_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488FC0u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = native_function_address32(&::_stricmp);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008929A;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"numframes");
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->edi + 0xE8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488FE9u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00088FFE;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x488FF6u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x88FFEu); lift_push32(cpu, r); sfera_sub_004846B0(cpu,r); if (cpu->eip != r) return; }
    label_00088FFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x488FFEu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"type");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48900Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008903F;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489021u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008903F;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"PS_TANIMCOORD"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x89031u), LIFT_CODE_TOKEN_RVA(0x8902Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489031u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008903F;
    lift_store32(cpu->edi + 0x4Cu, (uint64_t)(lift_load32(cpu->edi + 0x4Cu)) | (uint64_t)(0x200u));
    label_0008903F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48903Fu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"blendmode");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489050u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089091;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489062u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089091;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"PS_BLENDADD"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x89072u), LIFT_CODE_TOKEN_RVA(0x89070u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489072u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00089082;
    lift_store32(cpu->edi + 0xE8u, (uint64_t)(lift_load32(cpu->edi + 0xE8u)) | (uint64_t)(1u));
    goto label_00089091;
    label_00089082: cpu->eip = LIFT_CODE_TOKEN_VA(0x489082u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"PS_BLENDALPHA"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x8908Eu), LIFT_CODE_TOKEN_RVA(0x8908Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48908Eu);
    cpu->esp += 8u;
    label_00089091: cpu->eip = LIFT_CODE_TOKEN_VA(0x489091u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"animspeed");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4890A2u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000890B5;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4890AFu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x184u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000890B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4890B5u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x180u)) <= (uint32_t)(0u)) goto label_0008929A;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4890D3u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008913F;
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4890E5u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008913F;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000890F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4890F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000890F0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008913F;
    cpu->edx = 0x698u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48910Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_00089110: cpu->eip = LIFT_CODE_TOKEN_VA(0x489110u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00089110;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489120u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x17Cu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 0x17Cu);
    cpu->edx = lift_load32(cpu->edx);
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    label_00089135: cpu->eip = LIFT_CODE_TOKEN_VA(0x489135u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00089135;
    label_0008913F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48913Fu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48914Bu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"frame");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489157u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089293;
    (void)cpu;
    label_00089160: cpu->eip = LIFT_CODE_TOKEN_VA(0x489160u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x4Cu)), r=(uint64_t)(0x200u), v=l & r; lift_flags_logic(cpu,v,32u); }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000891C5;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489172u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x17Cu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->ecx = (uint32_t)(cpu->eax + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %f %f %f %f %f %f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4891B0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4891B6u);
    cpu->esp += 0x2Cu;
    lift_store32(cpu->edi + 0xE8u, (uint64_t)(lift_load32(cpu->edi + 0xE8u)) | (uint64_t)(2u));
    goto label_0008927F;
    label_000891C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4891C5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4891CAu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4891DAu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008927F;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000891F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4891F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000891F0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008927F;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0008922D;
    cpu->edx = lift_load32(cpu->edi + 0x17Cu);
    if ((uint32_t)(lift_load32(cpu->edx)) == (uint32_t)(cpu->esi)) goto label_0008922D;
    cpu->edx = 0x6B4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48921Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x17Cu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48922Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008922D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48922Du);
    cpu->edx = 0x6B6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48923Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00089243: cpu->eip = LIFT_CODE_TOKEN_VA(0x489243u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00089243;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489253u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x17Cu);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->esp += 4u;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x17Cu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ecx + cpu->eax);
    label_00089275: cpu->eip = LIFT_CODE_TOKEN_VA(0x489275u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->edx;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00089275;
    label_0008927F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48927Fu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"frame");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48928Bu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00089160;
    label_00089293: cpu->eip = LIFT_CODE_TOKEN_VA(0x489293u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8929Au); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    label_0008929A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48929Au);
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(0u)) goto label_000896B6;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"particles_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4892B5u); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000896B6;
    cpu->edx = 0x6C5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4892CCu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4892D5u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0008969E;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4892F2u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"particles_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489303u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089693;
    label_00089310: cpu->eip = LIFT_CODE_TOKEN_VA(0x489310u);
    cpu->edx = lift_load32(cpu->edi + 0x5Cu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48931Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489320u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"select");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489334u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008942B;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48934Au); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008942B;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"range"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x48935Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489362u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000893C0;
    cpu->ecx = lift_load32(cpu->edi + 0x5Cu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x489373u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489378u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489384u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->ebx;
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48938Fu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00089399;
    cpu->ecx = cpu->esi;
    cpu->esi = cpu->eax;
    cpu->eax = cpu->ecx;
    label_00089399: cpu->eip = LIFT_CODE_TOKEN_VA(0x489399u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0008939F;
    cpu->esi = 0u;
    label_0008939F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48939Fu);
    cpu->ecx = lift_load32(cpu->edi + 0x5Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000893A8;
    cpu->eax = cpu->ecx;
    label_000893A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4893A8u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000893C0;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4893B8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4893BDu);
    cpu->esp += 0xCu;
    label_000893C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4893C0u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"number"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4893CAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4893D0u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008942B;
    cpu->eax = lift_load32(cpu->edi + 0x5Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4893E2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4893E7u);
    cpu->esp += 0xCu;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4893F1u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0008942B;
    cpu->edi = cpu->edi;
    label_00089400: cpu->eip = LIFT_CODE_TOKEN_VA(0x489400u);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48940Bu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x5Cu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00089415;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    label_00089415: cpu->eip = LIFT_CODE_TOKEN_VA(0x489415u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0008941B;
    cpu->eax = 0u;
    label_0008941B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48941Bu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store8(cpu->eax + cpu->edx, 1u);
    cpu->eax = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_00089400;
    label_0008942B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48942Bu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"size_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48943Cu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089490;
    if ((uint32_t)(lift_load32(cpu->edi + 0x15Cu)) <= (uint32_t)(0u)) goto label_00089490;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489452u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->ecx)) goto label_00089490;
    cpu->edx = 0u;
    (void)cpu;
    label_00089460: cpu->eip = LIFT_CODE_TOKEN_VA(0x489460u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(1u)) goto label_00089487;
    cpu->esi = lift_load32(cpu->edi + 0x16Cu);
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u))) != (uint32_t)(0u)) goto label_0008947B;
    cpu->eax = 0xFFFFu;
    label_0008947B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48947Bu);
    cpu->esi = lift_load32(cpu->edi + 4u);
    lift_store16(cpu->esi + cpu->edx + 0x3Cu, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_00089487: cpu->eip = LIFT_CODE_TOKEN_VA(0x489487u);
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_00089460;
    label_00089490: cpu->eip = LIFT_CODE_TOKEN_VA(0x489490u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4894A1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000894F4;
    if ((uint32_t)(lift_load32(cpu->edi + 0x160u)) <= (uint32_t)(0u)) goto label_000894F4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4894B7u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->ecx)) goto label_000894F4;
    cpu->edx = 0u;
    label_000894C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4894C4u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(1u)) goto label_000894EB;
    cpu->esi = lift_load32(cpu->edi + 0x170u);
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u))) != (uint32_t)(0u)) goto label_000894DF;
    cpu->eax = 0xFFFFu;
    label_000894DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4894DFu);
    cpu->esi = lift_load32(cpu->edi + 4u);
    lift_store16(cpu->esi + cpu->edx + 0x3Eu, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_000894EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4894EBu);
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_000894C4;
    label_000894F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4894F4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"velocity_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489505u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089560;
    if ((uint32_t)(lift_load32(cpu->edi + 0x164u)) <= (uint32_t)(0u)) goto label_00089560;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48951Bu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->ecx)) goto label_00089560;
    cpu->edx = 0u;
    label_00089530: cpu->eip = LIFT_CODE_TOKEN_VA(0x489530u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(1u)) goto label_00089557;
    cpu->esi = lift_load32(cpu->edi + 0x174u);
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u))) != (uint32_t)(0u)) goto label_0008954B;
    cpu->eax = 0xFFFFu;
    label_0008954B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48954Bu);
    cpu->esi = lift_load32(cpu->edi + 4u);
    lift_store16(cpu->esi + cpu->edx + 0x40u, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_00089557: cpu->eip = LIFT_CODE_TOKEN_VA(0x489557u);
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_00089530;
    label_00089560: cpu->eip = LIFT_CODE_TOKEN_VA(0x489560u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"gravitation_track");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489571u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000895C4;
    if ((uint32_t)(lift_load32(cpu->edi + 0x168u)) <= (uint32_t)(0u)) goto label_000895C4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489587u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->ecx)) goto label_000895C4;
    cpu->edx = 0u;
    label_00089594: cpu->eip = LIFT_CODE_TOKEN_VA(0x489594u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(1u)) goto label_000895BB;
    cpu->esi = lift_load32(cpu->edi + 0x178u);
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u))) != (uint32_t)(0u)) goto label_000895AF;
    cpu->eax = 0xFFFFu;
    label_000895AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4895AFu);
    cpu->esi = lift_load32(cpu->edi + 4u);
    lift_store16(cpu->esi + cpu->edx + 0x42u, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_000895BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4895BBu);
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_00089594;
    label_000895C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4895C4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"magnite_weight");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4895D5u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000895F6;
    lift_push32(cpu, 0x70Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4895EDu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4895F3u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000895F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4895F6u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"texture_frame");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489607u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089637;
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489619u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089637;
    lift_push32(cpu, (uintptr_t)"RANDOM"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x489623u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489629u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00089637;
    lift_store32(cpu->edi + 0x4Cu, (uint64_t)(lift_load32(cpu->edi + 0x4Cu)) | (uint64_t)(0x80000u));
    label_00089637: cpu->eip = LIFT_CODE_TOKEN_VA(0x489637u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"child_ps");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489648u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008967A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489655u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->ecx)) goto label_0008967A;
    cpu->edx = 0u;
    cpu->edi = cpu->edi;
    label_00089660: cpu->eip = LIFT_CODE_TOKEN_VA(0x489660u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(1u)) goto label_00089671;
    cpu->esi = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + cpu->edx + 0x4Cu, cpu->eax);
    label_00089671: cpu->eip = LIFT_CODE_TOKEN_VA(0x489671u);
    ++cpu->ecx;
    cpu->edx += 0x50u;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_00089660;
    label_0008967A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48967Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"particles_def");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48968Bu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00089310;
    label_00089693: cpu->eip = LIFT_CODE_TOKEN_VA(0x489693u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48969Au); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    label_0008969E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48969Eu);
    cpu->edx = 0x721u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4896ADu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4896B3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000896B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4896B6u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x18Cu)) <= (uint32_t)(0u)) goto label_000896FA;
    cpu->edx = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->edx)) goto label_000896FA;
    cpu->ecx = 0u;
    label_000896D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4896D0u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + cpu->eax + 0x4Cu)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0x4Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000896F1;
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edi + 0x188u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 4u, (uint64_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 4u)) + 1u);
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 4u);
    label_000896F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4896F1u);
    ++cpu->edx;
    cpu->ecx += 0x50u;
    if ((uint32_t)(cpu->edx) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_000896D0;
    label_000896FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4896FAu);
    if ((uint32_t)(g_sfera_effect_manager.particle_random_table) != (uint32_t)(0u)) goto label_00089720;
    lift_push32(cpu, 0x72Fu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489717u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48971Du); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00089720: cpu->eip = LIFT_CODE_TOKEN_VA(0x489720u);
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x89728u), LIFT_CODE_TOKEN_RVA(0x89726u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489728u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xFEu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->edi + 0xD8u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x89738u), LIFT_CODE_TOKEN_RVA(0x89736u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489738u);
    lift_store32(cpu->edi + 0xDCu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x89740u), LIFT_CODE_TOKEN_RVA(0x8973Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489740u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x4Cu)), r=(uint64_t)(0x40u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->edi + 0xE0u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000897B4;
    cpu->esi = lift_load32(cpu->edi + 0xD8u);
    cpu->ecx = lift_load32(cpu->edi + 0x64u);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(9u), 32u);
    cpu->esi += g_sfera_effect_manager.particle_random_table;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008977A;
    cpu->edx = lift_load32(cpu->edi + 0xDCu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x6Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8977Au); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_0008977A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48977Au);
    cpu->ecx = lift_load32(cpu->edi + 0x44u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008979F;
    cpu->edx = lift_load32(cpu->edi + 0xE0u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->edi + 0xDCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->edi + 0x34u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8979Fu); lift_push32(cpu, r); sfera_sub_0042D9F0(cpu,r); if (cpu->eip != r) return; }
    label_0008979F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48979Fu);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x5Cu)) <= (uint32_t)(cpu->esi)) goto label_000897B4;
    label_000897A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4897A6u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4897AEu); lift_push32(cpu, r); sfera_sub_00484A80(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->edi + 0x5Cu))) goto label_000897A6;
    label_000897B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4897B4u);
    cpu->edx = 0x743u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ParticleSystem.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4897C3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4897CDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4897DCu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_000897E5;
    label_000897E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4897E3u);
    cpu->eax = 0u;
    label_000897E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4897E5u);
    cpu->ecx = lift_load32(cpu->esp + 0x98u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00489810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489810u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008982B;
    lift_push32(cpu, 0x43u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\pathzones.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489825u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, 0u);
    label_0008982B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48982Bu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00489830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489830u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, 4000.0);
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    cpu->edi = cpu->ecx;
    lift_x87_push(cpu, 10.0);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48984Fu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    cpu->esi = cpu->eax;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48985Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) > (uint32_t)(0x31Fu)) goto label_0008989C;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x31Fu)) goto label_0008989C;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x320u);
    cpu->eax += cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(7u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ebx = 1u;
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx &= 7u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->ecx)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008989C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48989Cu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004898B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4898B0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (uint32_t)(cpu->edi + 0x9C40u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x9C40u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx -= 0x2690u;
    cpu->eax -= 0x2690u;
    lift_store32(cpu->esp + 0xCu, 4u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xFFu)) goto label_00089B95;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xFFu)) goto label_00089B95;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edi;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFFFFFFCu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->esi &= 0xFFFFFFFCu;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.quadtree_cells[0]));
    lift_store32(cpu->esp + 0x18u, 2u);
    goto label_00089938;
    label_00089934: cpu->eip = LIFT_CODE_TOKEN_VA(0x489934u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_00089938: cpu->eip = LIFT_CODE_TOKEN_VA(0x489938u);
    if ((uint32_t)(lift_load32(cpu->ebp)) != (uint32_t)(0u)) goto label_00089968;
    lift_push32(cpu, 0x2Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    cpu->ecx = 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48994Fu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    label_00089968: cpu->eip = LIFT_CODE_TOKEN_VA(0x489968u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax += cpu->ebx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->ebx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 2u));
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_0008999E;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(3u)) goto label_000899CB;
    label_0008999E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48999Eu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"----ERROR_Quadtree, xi=%d, yi=%d, xc=%d, yc=%d, xa=%d, ya=%d\n");
    cpu->ebx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4899C0u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->esp += 0x1Cu;
    label_000899CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4899CBu);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 4u));
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_000899DA;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000899DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4899DAu);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_000899E1;
    cpu->esi = cpu->ecx;
    label_000899E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4899E1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x18u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00089934;
    cpu->esi = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00089A0C;
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489A01u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebp, cpu->eax);
    lift_store32(cpu->esi, 0u);
    label_00089A0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x489A0Cu);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00089A2A;
    lift_push32(cpu, 0x47u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    cpu->ecx = (uint32_t)(cpu->eax + 0x18u);
    lift_store32(cpu->esi + 4u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489A28u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    goto label_00089A53;
    label_00089A2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x489A2Au);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00089A56;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, 0x4Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp");
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esi + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x89A53u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    label_00089A53: cpu->eip = LIFT_CODE_TOKEN_VA(0x489A53u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_00089A56: cpu->eip = LIFT_CODE_TOKEN_VA(0x489A56u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u), cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x1D4C0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xCu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + 1u);
    lift_store32(cpu->esi + 0xCu, 0u);
    cpu->eax += 0xFFFFD8F0u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->eax += 0x1D4C0u;
    cpu->ebx = cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFD8F0u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->ecx = cpu->edx;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 2u));
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x80000001u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00089AE9;
    --cpu->edx;
    cpu->edx |= 0xFFFFFFFEu;
    ++cpu->edx;
    label_00089AE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x489AE9u);
    cpu->ebp = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x80000001u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00089AF8;
    --cpu->ebp;
    cpu->ebp |= 0xFFFFFFFEu;
    ++cpu->ebp;
    label_00089AF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x489AF8u);
    cpu->edx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->edx) * 2u));
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    cpu->ecx -= cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ebx += cpu->ecx;
    cpu->eax = 0x27u;
    cpu->ecx = (uint32_t)(cpu->edx + 0x28u);
    cpu->eax -= cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_00089B27;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x50u)) goto label_00089B29;
    label_00089B27: cpu->eip = LIFT_CODE_TOKEN_VA(0x489B27u);
    cpu->ecx = 0u;
    label_00089B29: cpu->eip = LIFT_CODE_TOKEN_VA(0x489B29u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00089B32;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x50u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00089B34;
    label_00089B32: cpu->eip = LIFT_CODE_TOKEN_VA(0x489B32u);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_00089B34: cpu->eip = LIFT_CODE_TOKEN_VA(0x489B34u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x64u); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx += cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x64u);
    cpu->ebp = lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->ebp);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x20u, cpu->ecx);
    lift_store32(cpu->esi + 0xCu, 1u);
    cpu->ebx = lift_pop32(cpu);
    label_00089B95: cpu->eip = LIFT_CODE_TOKEN_VA(0x489B95u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00489BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489BA0u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    cpu->eax = (uint32_t)(cpu->ebx + 0x9C40u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    cpu->edx &= 3u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0x9C40u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->esi -= 0x2690u;
    cpu->eax -= 0x2690u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->edi = 4u;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFu)) goto label_00089CB3;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00089CB3;
    cpu->ecx = cpu->ebx;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->ecx &= 0xFFFFFFFCu;
    cpu->ebp &= 0xFFFFFFFCu;
    cpu->esi += cpu->eax;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.quadtree_cells[0]));
    lift_store32(cpu->esp + 0x10u, 0u);
    label_00089C17: cpu->eip = LIFT_CODE_TOKEN_VA(0x489C17u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00089C7F;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + ((uint32_t)(cpu->eax) * 4u) + 0x20u, cpu->edx);
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edi = cpu->eax;
    cpu->edx = 0u;
    cpu->ebx = (uint32_t)(cpu->edi + cpu->ebp);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = (uint32_t)(cpu->ecx + cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00089C5A;
    cpu->ecx = cpu->esi;
    label_00089C5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x489C5Au);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00089C60;
    cpu->ebp = cpu->ebx;
    label_00089C60: cpu->eip = LIFT_CODE_TOKEN_VA(0x489C60u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(2u)) goto label_00089C17;
    lift_store32(cpu->esp + ((uint32_t)(cpu->eax) * 4u) + 0x20u, cpu->edx);
    cpu->eax = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00089C86;
    lift_push32(cpu, (uint32_t)(uintptr_t)"internal error 639206792");
    goto label_00089CA6;
    label_00089C7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x489C7Fu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"internal error 849385252");
    goto label_00089CA6;
    label_00089C86: cpu->eip = LIFT_CODE_TOKEN_VA(0x489C86u);
    cpu->esi = lift_load32(cpu->eax);
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00089CA1;
    cpu->edx = lift_load32(cpu->eax + 8u);
    label_00089C91: cpu->eip = LIFT_CODE_TOKEN_VA(0x489C91u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->edx)) == (uint32_t)(cpu->edi)) goto label_00089CBD;
    ++cpu->ecx;
    cpu->edx += 4u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->esi)) goto label_00089C91;
    label_00089CA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x489CA1u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"internal error 075982391");
    label_00089CA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x489CA6u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489CB0u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00089CB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x489CB3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_00089CBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x489CBDu);
    --cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00089CD3;
    label_00089CC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x489CC2u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    ++cpu->ecx;
    lift_store32(cpu->edx, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->esi)) goto label_00089CC2;
    label_00089CD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x489CD3u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->eax, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00089CB3;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0xA5u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489CE9u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, 0xA6u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489CFEu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, 0u);
    cpu->edi = 1u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00089D10: cpu->eip = LIFT_CODE_TOKEN_VA(0x489D10u);
    cpu->esi = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x20u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(0u)) goto label_00089CB3;
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(0u)) goto label_00089CB3;
    if ((uint32_t)(lift_load32(cpu->ecx + 8u)) != (uint32_t)(0u)) goto label_00089CB3;
    if ((uint32_t)(lift_load32(cpu->ecx + 0xCu)) != (uint32_t)(0u)) goto label_00089CB3;
    lift_push32(cpu, 0xADu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\quadtree.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489D3Cu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    lift_store32(cpu->esi, 0u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00089D10;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00489D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489D50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->esi = 0u;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((int16_t)(uint16_t)((cpu->eax & 0xFFFFu)) >= (int16_t)(uint16_t)(lift_load16(cpu->ebx + 0x20C98u))) goto label_00089DB9;
    cpu->edi = (uint32_t)(cpu->ebx + 4u);
    cpu->edi = cpu->edi;
    label_00089D90: cpu->eip = LIFT_CODE_TOKEN_VA(0x489D90u);
    cpu->edx = 0x2Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\QuickFile.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489D9Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489DA7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (int16_t)(lift_load16(cpu->ebx + 0x20C98u));
    ++cpu->esi;
    cpu->esp += 4u;
    cpu->edi += 8u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00089D90;
    label_00089DB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x489DB9u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xC80u);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489DCCu); lift_push32(cpu, r); sfera_sub_00430BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00489DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489DE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebp);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x489DEFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489DF5u);
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00089E07;
    cpu->eax = (uint32_t)(cpu->edi + 2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00089E07: cpu->eip = LIFT_CODE_TOKEN_VA(0x489E07u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00089E31;
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x489E14u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489E1Au);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x489E1Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489E21u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x489E28u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489E2Eu);
    cpu->esp += 0x1Cu;
    label_00089E31: cpu->eip = LIFT_CODE_TOKEN_VA(0x489E31u);
    cpu->eax = lift_load16(cpu->esi + 0x20C98u);
    cpu->ecx = 0x190u;
    if ((int16_t)(uint16_t)((cpu->eax & 0xFFFFu)) < (int16_t)(uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00089E68;
    lift_push32(cpu, (uintptr_t)"Too many files in quickfile"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489E51u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->ecx = (uint32_t)(uintptr_t)"Too many files in quickfile\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489E5Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00089E68: cpu->eip = LIFT_CODE_TOKEN_VA(0x489E68u);
    cpu->edx = (int16_t)((cpu->eax & 0xFFFFu));
    lift_store32(cpu->esi + ((uint32_t)(cpu->edx) * 8u), cpu->ebx);
    cpu->edx = 0x47u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\QuickFile.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489E7Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489E83u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (int16_t)(lift_load16(cpu->esi + 0x20C98u));
    lift_store32(cpu->esi + ((uint32_t)(cpu->ecx) * 8u) + 4u, cpu->eax);
    cpu->edx = (int16_t)(lift_load16(cpu->esi + 0x20C98u));
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->edx) * 8u) + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x489E9Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489EA4u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x489EA5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489EABu);
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x489EAEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x489EB4u);
    cpu->esp += 0x20u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00089EBF;
    cpu->eax = cpu->ebp;
    goto label_00089EC0;
    label_00089EBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x489EBFu);
    ++cpu->eax;
    label_00089EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x489EC0u);
    cpu->ecx = (int16_t)(lift_load16(cpu->esi + 0x20C98u));
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xC80u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489ED6u); lift_push32(cpu, r); sfera_sub_004311D0(cpu,r); if (cpu->eip != r) return; }
    lift_store16(cpu->esi + 0x20C98u, (uint64_t)(lift_load16(cpu->esi + 0x20C98u)) + 1u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00489EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489EF0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xC80u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489F05u); lift_push32(cpu, r); sfera_sub_00430F20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00089F10;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00089F10: cpu->eip = LIFT_CODE_TOKEN_VA(0x489F10u);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    lift_store16(cpu->edx, cpu->ecx & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00489F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x489F30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xD44u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, 0x12Cu);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0x20u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xC80u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x489F85u); lift_push32(cpu, r); sfera_sub_00430F60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store16(cpu->ebx + 0x20C98u, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0xD54u);
    cpu->edx = (uint32_t)(cpu->esp + 0x140u);
    lift_store32(cpu->esp + 0xD4Cu, 0u);
    cpu->edx -= cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00089FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x489FB0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00089FB0;
    cpu->eax = (uint32_t)(cpu->esp + 0x140u);
    --cpu->eax;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00089FC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x489FC5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00089FC5;
    cpu->eax -= cpu->edx;
    if ((uint8_t)(lift_load8(cpu->esp + cpu->eax + 0x140u)) == (uint8_t)(0x5Cu)) goto label_00089FF2;
    cpu->edi = (uint32_t)(cpu->esp + 0x140u);
    --cpu->edi;
    label_00089FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x489FE0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00089FE0;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"\\")) & 0xFFFFu);
    lift_store16(cpu->edi, cpu->ecx & 0xFFFFu);
    label_00089FF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x489FF2u);
    cpu->eax = 0u;
    label_0008A000: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A000u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x140u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x940u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0008A000;
    cpu->eax = (uint32_t)(cpu->esp + 0x940u);
    --cpu->eax;
    label_0008A020: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A020u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0008A020;
    cpu->edx = lift_load32((uintptr_t)"*.mbc");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"*.mbc") + 4u)) & 0xFFFFu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_store16(cpu->eax + 4u, cpu->ecx & 0xFFFFu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x944u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x48A048u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48A04Eu);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_0008A16E;
    cpu->eax = 0u;
    cpu->edi = cpu->edi;
    label_0008A060: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A060u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x140u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x540u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0008A060;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->edx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0008A080: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A080u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0008A080;
    cpu->edi = (uint32_t)(cpu->esp + 0x540u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0008A091: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A091u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008A091;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x544u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A0BDu); lift_push32(cpu, r); sfera_sub_00489DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::_findnext64i32);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8A0CBu), LIFT_CODE_TOKEN_RVA(0x8A0C9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A0CBu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008A15E;
    label_0008A0E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A0E0u);
    cpu->eax = 0u;
    label_0008A0F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A0F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x140u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x540u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0008A0F0;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->edx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0008A110: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A110u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0008A110;
    cpu->edi = (uint32_t)(cpu->esp + 0x540u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0008A121: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A121u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008A121;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x544u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A14Fu); lift_push32(cpu, r); sfera_sub_00489DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8A157u), LIFT_CODE_TOKEN_RVA(0x8A155u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A157u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008A0E0;
    label_0008A15E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A15Eu);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x48A15Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48A165u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    goto label_0008A170;
    label_0008A16E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A16Eu);
    cpu->eax = cpu->ebx;
    label_0008A170: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A170u);
    cpu->ecx = lift_load32(cpu->esp + 0xD44u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD3Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048A1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A1A0u);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048A1C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A1C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0008A203;
    label_0008A1D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A1D6u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (uint32_t)sfera_buffer_cipher_key(cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    lift_store8(cpu->esp + 0x13u, cpu->edx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    lift_multiply_accumulator(cpu, lift_load8(cpu->esp + 0x13u), 8u, 1u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esi, cpu->edx & 0xFFu);
    ++cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0008A1D6;
    label_0008A203: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A203u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048A210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A210u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_push32(cpu, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    cpu->esi = 0u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 4u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 8u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)-1.1754943508222875e-38f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A2E8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0008A2E6;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.0);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A2E6;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->edx + 4u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->edx + 8u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_0008A2E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A2E6u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008A2E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A2E8u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esi;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048A300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A300u);
    { uint64_t l=cpu->esp, r=(uint64_t)(0x10u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    label_0008A326: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A326u);
    cpu->esi = sfera_clip_plane_order(cpu->eax);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(4u), 32u);
    cpu->esi += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = 0u;
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0008A3E2;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->edx + 0xFFFFFFFCu);
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(2u), 32u);
    cpu->edi += 0x14u;
    ++cpu->ebx;
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->ebx) * 4u));
    label_0008A351: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A351u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A373;
    ++cpu->ecx;
    label_0008A373: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A373u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A394;
    ++cpu->ecx;
    label_0008A394: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A394u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A3B6;
    ++cpu->ecx;
    label_0008A3B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A3B6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A3D8;
    ++cpu->ecx;
    label_0008A3D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A3D8u);
    cpu->edi += 0x30u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008A351;
    label_0008A3E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A3E2u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0008A41D;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 2u));
    cpu->ebx = cpu->edx;
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 8u);
    cpu->ebx -= cpu->ebp;
    label_0008A3F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A3F6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A417;
    ++cpu->ecx;
    label_0008A417: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A417u);
    cpu->edi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008A3F6;
    label_0008A41D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A41Du);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008A452;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0008A326;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax += 2u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
    label_0008A452: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A452u);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048A460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A460u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_push32(cpu, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008A541;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008A53F;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A51A;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A518;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0008A518: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A518u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_0008A51A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A51Au);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008A541;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A543;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0008A53F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A53Fu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008A541: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A541u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008A543: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A543u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008A615;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008A615;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A5E8;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x18u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008A5E6;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0008A5E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A5E6u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    label_0008A5E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A5E8u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008A61B;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x18u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A619;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 1u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0008A615: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A615u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008A61B;
    label_0008A619: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A619u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    label_0008A61B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A61Bu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 8u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 6u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 5u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008A653;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0xFFFFFFFEu;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0008A653: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A653u);
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048A6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A6A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->edi)) goto label_0008A6C6;
    cpu->edx = 0x14Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A6B9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A6C1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->edi);
    label_0008A6C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A6C6u);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->edi)) goto label_0008A6E9;
    cpu->edx = 0x151u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A6DAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A6E3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 4u, cpu->edi);
    label_0008A6E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A6E9u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) == (uint32_t)(cpu->edi)) goto label_0008A70C;
    cpu->edx = 0x157u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A6FDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A706u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    label_0008A70C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A70Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->edi)) goto label_0008A72F;
    cpu->edx = 0x15Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A720u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A729u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    label_0008A72F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A72Fu);
    lift_store32(cpu->esi + 8u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048A740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48A740u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x1A8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x6Cu, cpu->ebx);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_0008B1DD;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A76Bu); lift_push32(cpu, r); sfera_sub_00456010(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1000.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0008B1DD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.5707964897155762));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store_f64(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.z));
    lift_store32(cpu->esp + 0x58u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f64(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_store_f64(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A7C9u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x48u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A7D6u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_load_f64(cpu->esp + 0xA0u)));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_store_f64(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A7F6u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x40u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48A803u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, 60.0);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0xACu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esp + 0xB4u, cpu->edx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x94u, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x9Cu, cpu->edx);
    lift_store32(cpu->esp + 0xB0u, cpu->ecx);
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x98u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xB4u))));
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x94u))));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x9Cu))));
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x48A892u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48A898u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000001u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0008A8A4;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    label_0008A8A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A8A4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008B1DD;
    lift_store32(cpu->esp + 0x48u, cpu->ebp);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) <= (uint32_t)(cpu->ebp)) goto label_0008B1DD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    lift_store32(cpu->esp + 0xA0u, cpu->ebp);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    goto label_0008A8D3;
    label_0008A8CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A8CBu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    label_0008A8D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A8D3u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_load32(cpu->edi + 8u);
    cpu->ebx = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x80u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x74u, cpu->edx);
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x7Cu, cpu->esi);
    lift_store32(cpu->esp + 0x84u, cpu->edi);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store32(cpu->esp + 0x78u, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x48A90Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48A912u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000001u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0008A91E;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    label_0008A91E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A91Eu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008B1AC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->eax += lift_load32(cpu->esp + 0xA0u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store_f32(cpu->esp + 0xE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_store32(cpu->esp + 0x13Cu, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x138u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    lift_store32(cpu->esp + 0x140u, cpu->eax);
    lift_store_f32(cpu->esp + 0xECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebp);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xE8u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x124u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x128u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xF0u))));
    lift_store_f32(cpu->esp + 0x12Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x124u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x128u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x104u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x12Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x108u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x100u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32(cpu->esp + 0x118u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x104u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x11Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store_f32(cpu->esp + 0x120u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x13Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x11Cu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x138u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x118u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x140u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x120u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008AA9C;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008B1B0;
    label_0008AA9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AA9Cu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xACu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP2();
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008AAD1;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x7Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48AAC9u); lift_push32(cpu, r); sfera_sub_0048A460(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    goto label_0008AAEE;
    label_0008AAD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AAD1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x7Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48AAE8u); lift_push32(cpu, r); sfera_sub_0048A460(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    label_0008AAEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AAEEu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x7Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48AB0Cu); lift_push32(cpu, r); sfera_sub_0048A460(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48AB1Eu); lift_push32(cpu, r); sfera_sub_0048A300(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_0008AB2E;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008AB2E;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008B1AC;
    label_0008AB2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AB2Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0008AC0D;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x168u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x170u, cpu->edx);
    lift_store32(cpu->esp + 0x16Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0xB8u);
    lift_store32(cpu->esp + 0x15Cu, cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x160u);
    lift_store32(cpu->esp + 0x168u, cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x170u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_store32(cpu->esp + 0x168u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ABA6u); lift_push32(cpu, r); sfera_sub_0048A210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008ABCB;
    cpu->ecx = lift_load32(cpu->esp + 0xB8u);
    cpu->edx = lift_load32(cpu->esp + 0xBCu);
    cpu->eax = lift_load32(cpu->esp + 0xC0u);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    label_0008ABCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ABCBu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xB8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x160u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x170u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[5][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ABECu); lift_push32(cpu, r); sfera_sub_0048A210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008AC0D;
    cpu->eax = lift_load32(cpu->esp + 0xB8u);
    cpu->ecx = lift_load32(cpu->esp + 0xC0u);
    cpu->esi = lift_load32(cpu->esp + 0xBCu);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    label_0008AC0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AC0Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store32(cpu->esp + 0x68u, 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48AC56u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008AC7A;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008B1AC;
    label_0008AC7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AC7Au);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)40.0f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008AC9B;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (40.0) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008AC9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AC9Bu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x90u))));
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x174u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x17Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x194u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x194u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x17Cu));
    lift_store_f64(cpu->esp + 0x130u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x174u));
    lift_store_f64(cpu->esp + 0x1B0u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48AD44u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x1B0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x130u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48AD71u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008ADB2;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    label_0008ADB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ADB2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->ebp = 0u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x180u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x188u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x180u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x198u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x188u))));
    lift_store_f32(cpu->esp + 0x1A0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x198u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1A0u))));
    lift_store_f32(cpu->esp + 0x1ACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008AE24: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AE24u);
    cpu->ebx = lift_load32(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, 0.0);
    cpu->esi = lift_load32(cpu->ebx + 0xCu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + cpu->ebp + 0x34u)));
    lift_x87_pop(cpu);
    cpu->esi += cpu->ebp;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008B19D;
    if ((uint32_t)(lift_load32(cpu->esp + 0x68u)) == (uint32_t)(0u)) goto label_0008B1AC;
    cpu->edi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8AE51u), LIFT_CODE_TOKEN_RVA(0x8AE4Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48AE51u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8AE65u), LIFT_CODE_TOKEN_RVA(0x8AE63u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48AE65u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, 0.10000000149011612);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008AE98;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0008AE98: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AE98u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.8999999761581421);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008AEB3;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    goto label_0008AEB5;
    label_0008AEB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AEB3u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008AEB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AEB5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1A4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1ACu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f64(cpu->esp + 0x130u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8AEF4u), LIFT_CODE_TOKEN_RVA(0x8AEF2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48AEF4u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x130u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (10.0));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (2.0));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8AF21u), LIFT_CODE_TOKEN_RVA(0x8AF1Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48AF21u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000007u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0008AF2D;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFF8u;
    ++cpu->eax;
    label_0008AF2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48AF2Du);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (20.0));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x150u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x154u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x90u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x158u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x150u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x154u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 0xE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x158u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x64u))));
    lift_store_f32(cpu->esp + 0xE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC4u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0xC8u))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0xCCu))));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x144u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x144u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esi, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x148u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x148u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x14Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x14Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xD0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx = lift_load32(cpu->esp + 0xD4u);
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xD8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xDCu));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0xF4u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0xF4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xE0u));
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xF8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xE4u));
    lift_store32(cpu->esi + 0x1Cu, cpu->ecx);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0xFCu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store32(cpu->esi + 0x20u, cpu->edx);
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10Cu);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x110u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x110u);
    lift_store32(cpu->esi + 0x28u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x114u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x114u);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8B158u), LIFT_CODE_TOKEN_RVA(0x8B156u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48B158u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x8000001Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0008B164;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFE0u;
    ++cpu->eax;
    label_0008B164: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B164u);
    cpu->eax += 0x32u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8B17Fu), LIFT_CODE_TOKEN_RVA(0x8B17Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48B17Fu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->ebx + 0x14u), 32u, 0u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0008B196;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0008B196: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B196u);
    lift_store32(cpu->esp + 0x68u, (uint64_t)(lift_load32(cpu->esp + 0x68u)) - 1u);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B19D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B19Du);
    cpu->ebp += 0x3Cu;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0x1770u)) goto label_0008AE24;
    label_0008B1AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B1ACu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    label_0008B1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B1B0u);
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->esp + 0xA0u, (uint64_t)(lift_load32(cpu->esp + 0xA0u)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    cpu->eax = 0x18u;
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_0008A8CB;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B1DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B1DDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048B1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48B1F0u);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0008B5D0;
    cpu->edx = 0x106u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B210u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0xCu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B229u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x107u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    lift_store32(cpu->esi + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B23Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1770u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B248u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)-1.0f);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    cpu->eax = 0u;
    label_0008B256: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B256u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->ecx + 0x34u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->edx + 0x70u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->ecx + 0xACu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->edx + 0xE8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->ecx + 0x124u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->edx + 0x160u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->ecx + 0x19Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->edx + 0x1D8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->ecx + 0x214u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store_f32(cpu->eax + cpu->edx + 0x250u, lift_x87_get(cpu, 0u));
    cpu->eax += 0x258u;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x1770u)) goto label_0008B256;
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) <= (uint32_t)(cpu->edi)) goto label_0008B3DC;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_store_f64(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0008B2E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B2E0u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ebp);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0x14u);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x18u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B35Du); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008B380;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    goto label_0008B384;
    label_0008B380: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B380u);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    label_0008B384: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B384u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    ++cpu->edi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->ebp += 0x18u;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ebx += 0xCu;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->eax + cpu->ebx + 0xFFFFFFF4u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + cpu->ebx + 0xFFFFFFF8u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->eax + cpu->ebx + 0xFFFFFFFCu, cpu->ecx);
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0008B2E0;
    cpu->ebx = lift_pop32(cpu);
    goto label_0008B3DE;
    label_0008B3DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B3DCu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B3DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B3DEu);
    cpu->edx = 0x126u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B3EDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x280u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B3F7u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 0.25);
    cpu->esp += 4u;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 0x14u, 0x10u);
    cpu->eax = 0u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.25f);
    lift_x87_push(cpu, (double)0.5f);
    lift_x87_push(cpu, (double)0.75f);
    label_0008B437: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B437u);
    cpu->edx = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0008B44B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0008B44B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B44Bu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->eax + cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_store_f32(cpu->eax + cpu->edx + 0x14u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->eax + cpu->edx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 6u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x20u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x30u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0x34u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x38u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x40u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 6u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0x44u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x48u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x58u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0x5Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x60u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x64u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x68u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 6u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0x6Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0x70u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    ++cpu->ecx;
    lift_store_f32(cpu->eax + cpu->edx + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    cpu->eax += 0xA0u;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFE0u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFE4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFE8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFECu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(4u)) goto label_0008B437;
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B5D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B5D0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048B5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48B5E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008B809;
    lift_x87_push(cpu, 0.0);
    cpu->edi = 0u;
    label_0008B5FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B5FDu);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edi + cpu->eax + 0x34u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0008B7F8;
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0x2710u)) goto label_0008B807;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + cpu->edx + 0x34u));
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx + 0x34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edi + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edi + 0x30u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B65Bu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (100.0));
    lift_store16(cpu->esp + 0x14u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->ebx = cpu->eax;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x18u));
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    lift_store64(cpu->esp + 0x18u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0008B6B8;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8B6B8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0008B6B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B6B8u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_0008B6CC;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8B6CCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0008B6CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B6CCu);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += g_sfera_effect_manager.render_slots.data;
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ecx + 0x98u, 3u);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->ecx + 0x90u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ecx + 0x30u);
    cpu->edx = 4u;
    label_0008B6F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B6F5u);
    cpu->ebx = 0xFFu;
    lift_store32(cpu->eax + 0x30u, cpu->ebp);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 0x10u, cpu->ebx);
    lift_store32(cpu->eax + 0x20u, cpu->ebx);
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008B6F5;
    lift_store32(cpu->ecx + 0x94u, cpu->ebx);
    lift_store16(cpu->esp + 0x14u, cpu->fpu_control);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->eax + cpu->edi);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + cpu->edi + 4u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + cpu->edi + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx + 0xCu);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx + 0x18u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 0x18u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 0x1Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx + 0x24u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 0x24u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 0x28u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 0x2Cu, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + cpu->edx + 0x38u));
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx + 0x38u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.25));
    cpu->edx = 0u;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + cpu->eax + 0x38u));
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x18u));
    lift_store64(cpu->esp + 0x18u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x14u), 32u, 0u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + 8u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u));
    lift_store_f32(cpu->ecx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32(cpu->ecx + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32(cpu->ecx + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->ecx + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_store_f32(cpu->ecx + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_store_f32(cpu->ecx + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_store_f32(cpu->ecx + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_store_f32(cpu->ecx + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    label_0008B7F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B7F8u);
    cpu->edi += 0x3Cu;
    if ((uint32_t)(cpu->edi) < (uint32_t)(0x1770u)) goto label_0008B5FD;
    label_0008B807: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B807u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B809: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B809u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048B820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48B820u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008B82F;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8B82Fu); lift_push32(cpu, r); sfera_sub_0048A6A0(cpu,r); if (cpu->eip != r) return; }
    label_0008B82F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B82Fu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0008B956;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0xC7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ServerWall.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B84Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = (uint32_t)(cpu->esi + cpu->esi);
    cpu->edx = 0xCu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B864u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    cpu->edi = 0u;
    lift_store32(cpu->ebp, cpu->eax);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0008B90C;
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFCu);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    ++cpu->edx;
    cpu->edi = (uint32_t)(((uint32_t)(cpu->edx) * 4u));
    label_0008B88C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B88Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    cpu->eax += 0x60u;
    lift_store_f32(cpu->eax + 0xFFFFFFA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += 0x40u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFC4u));
    lift_store_f32(cpu->eax + 0xFFFFFFA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFA4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFC8u));
    lift_store_f32(cpu->eax + 0xFFFFFFACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFCCu));
    lift_store_f32(cpu->eax + 0xFFFFFFB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFB0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFD0u));
    lift_store_f32(cpu->eax + 0xFFFFFFB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFD4u));
    lift_store_f32(cpu->eax + 0xFFFFFFC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFBCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFD8u));
    lift_store_f32(cpu->eax + 0xFFFFFFC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFDCu));
    lift_store_f32(cpu->eax + 0xFFFFFFCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFC8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFE0u));
    lift_store_f32(cpu->eax + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFE4u));
    lift_store_f32(cpu->eax + 0xFFFFFFD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFD4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFE8u));
    lift_store_f32(cpu->eax + 0xFFFFFFDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFECu));
    lift_store_f32(cpu->eax + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFE0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF0u));
    lift_store_f32(cpu->eax + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_store_f32(cpu->eax + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFECu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    lift_store_f32(cpu->eax + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_store_f32(cpu->eax + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008B88C;
    label_0008B90C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B90Cu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->esi)) goto label_0008B93F;
    cpu->ecx += 8u;
    cpu->eax += 4u;
    cpu->esi -= cpu->edi;
    label_0008B918: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B918u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    cpu->eax += 0x18u;
    lift_store_f32(cpu->eax + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += 0x10u;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFECu));
    lift_store_f32(cpu->eax + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFE8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF0u));
    lift_store_f32(cpu->eax + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_store_f32(cpu->eax + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008B918;
    label_0008B93F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B93Fu);
    cpu->ecx = cpu->ebp;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B948u); lift_push32(cpu, r); sfera_sub_0048B1F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"fx_swall";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B952u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x18u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    label_0008B956: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B956u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048B960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48B960u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_server_wall;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48B96Cu); lift_push32(cpu, r); sfera_sub_0048B820(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}
