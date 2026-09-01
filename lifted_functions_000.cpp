#include "lifted_functions.h"
#include <cmath>
#include <cstddef>
namespace lifted {

static void sfera_prepare_msvc_string_storage(uint32_t address) { if (*(uint32_t*)(address + 0x10u) == 0u && *(uint32_t*)(address + 0x14u) == 0u) { *(uint8_t*)(address) = 0u; *(uint32_t*)(address + 0x14u) = 15u; } }
__declspec(noinline) void sfera_sub_00401000(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_00001006:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00001006;
    cpu->eax -= cpu->esi;
    sub_pred[0] = *(uint8_t*)(cpu->ecx + cpu->eax + 0xFFFFFFFFu) == 0x5Cu;
    cpu->eax = cpu->ecx + cpu->eax + 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00001026;
    label_00001020:
    --cpu->eax;
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_00001020;
    label_00001026:
    ++cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401030(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->edi <= (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00001064;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"AutoBoundsArray error: non-uniform growth of an index\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x1055u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)g_sfera_array_error_buffer;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1064u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x1064u));
    label_00001064:
    if (cpu->edi != *(uint32_t*)(cpu->esi + 8u)) goto label_0000108A;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"AutoBoundsArray error: the index has exceeded a maximum\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x107Bu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)g_sfera_array_error_buffer;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x108Au)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x108Au));
    label_0000108A:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ebx += *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if ((int32_t)cpu->ebx <= (int32_t)cpu->eax) goto label_00001099;
    cpu->ebx = cpu->eax;
    label_00001099:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebx);
    lift_push32(cpu, 0x2Bu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Arrays.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4010ABu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4010ABu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4010B9u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edx -= cpu->edi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edi += cpu->ebp;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4010CCu));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x2Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Arrays.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4010E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4010E2u));
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004010F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"BoundCheckArray error: index less than zero\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4010FFu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)g_sfera_array_error_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00401120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"BoundCheckArray error: index out of range %d\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x401130u));
    cpu->esp += 0x14u;
    cpu->ecx = (uintptr_t)g_sfera_array_error_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00401150(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x60u;
    x87_v0 = 1.0;
    cpu->eax = cpu->ecx;
    *(float*)(cpu->esp) = x87_v0;
    *(uint32_t*)(cpu->eax + 0x68u) = 0x10000u;
    cpu->ecx = *(uint32_t*)(cpu->esp);
    *(float*)(cpu->esp + 4u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = x87_v0;
    *(uint32_t*)(cpu->eax + 0x50u) = cpu->ecx;
    *(float*)(cpu->esp) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 4u) = x87_v0;
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->edx;
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp);
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x60u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax + 0x64u) = cpu->edx;
    cpu->ecx = cpu->esp + 0x1Cu;
    cpu->ecx &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    *(float*)(cpu->ecx) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = 0.0;
    *(float*)(cpu->ecx + 4u) = x87_v1;
    lift_push32(cpu, cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->edx + 8u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->ecx + 0xCu) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->edx + 0x10u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ecx + 0x14u) = x87_v1;
    lift_push32(cpu, cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->edx + 0x18u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->ecx + 0x1Cu) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->edx + 0x20u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->ecx + 0x24u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->edx + 0x28u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ecx + 0x2Cu) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->edx + 0x30u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->ecx + 0x34u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->edx + 0x38u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->ecx + 0x3Cu) = x87_v0; 
    std::memmove((void*)(*(uint32_t*)(cpu->eax)),(void*)(*(uint32_t*)(cpu->esp + 0x14u)),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x60u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401250(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->ecx + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->ecx + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 4u);
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 4u);
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->ecx + 4u);
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->ecx);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    cpu->esi = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->edx);
    cpu->esi = lift_pop32(cpu);
    x87_v0 = (double)*(float*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->ecx;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax + 0x4Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x50u) = cpu->ecx;
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004013B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004013D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->eax <= 0) goto label_00001465;
    if (cpu->edi == 0u) goto label_0000142E;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = cpu->ecx + cpu->ebp;
    cpu->ebx = cpu->eax * 8u;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ebx) goto label_00001465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, (uintptr_t)" ERROR(1): putbitstream: bufer will overload: bitT = %d, count = %d, bufsize = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inter.h";
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x25Fu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401429u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x401429u));
    cpu->esp += 0x14u;
    goto label_00001465;
    label_0000142E:
    cpu->ecx = cpu->eax * 8u;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ecx) goto label_00001465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, (uintptr_t)" ERROR(2): putbitstream: bufer will overload: count = %d, bufsize = %d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x24u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inter.h";
    *(uint32_t*)(cpu->esp + 0x28u) = 0x265u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401462u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x401462u));
    cpu->esp += 0x10u;
    label_00001465:
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == 0u) goto label_0000146F;
    cpu->edx = *(uint32_t*)(cpu->edi);
    label_0000146F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->eax==0u) goto label_00001479;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_00001479:
    cpu->eax = cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edi = cpu->eax * 8u;
    cpu->ecx -= cpu->edi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (((uint8_t)((cpu->ebx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = cpu->eax + cpu->ecx;
    cpu->eax = cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->ecx = cpu->eax * 8u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx -= cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->esi += cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_000014D5;
    cpu->eax = cpu->ebp;
    label_000014B6:
    if ((uint8_t)((*(uint8_t*)(cpu->edi)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_000014BE;
    *(uint8_t*)(cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->esi)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000014C4;
    label_000014BE:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->esi)) & (uint64_t)((cpu->ecx & 0xFFu));
    label_000014C4:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000014CB;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_000014CB:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ebx + cpu->ebx) & 0xFFu);
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000014D2;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edi;
    label_000014D2:
    if ((--cpu->eax) != 0u) goto label_000014B6;
    label_000014D5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax == 0u) goto label_000014DF;
    *(uint32_t*)(cpu->eax) = (uint64_t)(*(uint32_t*)(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    label_000014DF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->eax == 0u) goto label_000014E9;
    *(uint32_t*)(cpu->eax) = (uint64_t)(*(uint32_t*)(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    label_000014E9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401500(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->esi = cpu->eax + 1u;
    lift_push32(cpu, cpu->ebx);
    label_00001507:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00001507;
    cpu->eax -= cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi -= cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax != cpu->esi) goto label_00001563;
    cpu->esi = cpu->ecx;
    if (cpu->eax < 4u) goto label_00001536;
    label_00001522:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_00001563;
    cpu->eax -= 4u;
    cpu->edx += 4u;
    cpu->esi += 4u;
    if (cpu->eax >= 4u) goto label_00001522;
    label_00001536:
    if (cpu->eax == 0u) goto label_0000155A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    if ((cpu->ecx & 0xFFu) != *(uint8_t*)(cpu->esi)) goto label_00001563;
    if (cpu->eax <= 1u) goto label_0000155A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 1u));
    if ((cpu->ecx & 0xFFu) != *(uint8_t*)(cpu->esi + 1u)) goto label_00001563;
    if (cpu->eax <= 2u) goto label_0000155A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 2u));
    if ((cpu->edx & 0xFFu) != *(uint8_t*)(cpu->esi + 2u)) goto label_00001563;
    label_0000155A:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001563:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    label_00001578:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001578;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401590(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi < 0x25823Fu) goto label_000015A5;
    cpu->esi = 0x25823Fu;
    label_000015A5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_config_text_runtime.owned_text[0]);
    g_sfera_config_text_runtime.current_text = (uintptr_t)&g_sfera_config_text_runtime.owned_text[0];
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4015BAu));
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    cpu->eax = (uintptr_t)"";
    cpu->edx = cpu->edi;
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->ecx + cpu->esi) = 0u;
    cpu->edx -= cpu->eax;
    label_000015D5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000015D5;
    cpu->edi = lift_pop32(cpu);
    g_sfera_config_text_runtime.text_length = cpu->esi;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004015F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_config_text_runtime.text_length;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
static uint32_t sfera_config_lookup(uint32_t key_address) {
    const uint32_t text_address = g_sfera_config_text_runtime.current_text;
    const uint32_t text_length = g_sfera_config_text_runtime.text_length;
    if (text_address == 0u || key_address == 0u) {
        return 0u;
    }
    std::size_t key_length = 0u;
    while (key_length != 4096u && *(uint8_t*)(key_address + static_cast<uint32_t>(key_length)) != 0u) {
        ++key_length;
    }
    if (key_length == 4096u) {
        return 0u;
    }
    const std::size_t bounded_length = text_length < 0x25823Fu ? text_length : 0x25823Fu;
    const std::size_t scan_limit = bounded_length + 1u;
    if (static_cast<uint64_t>(text_address) + scan_limit > 0x100000000ull) {
        return 0u;
    }
    std::size_t line = 0u;
    while (line < scan_limit) {
        std::size_t token_end = line;
        while (token_end < scan_limit) {
            const uint8_t value = *(uint8_t*)(text_address + static_cast<uint32_t>(token_end));
            if (value == ' ' || value == '\t' || value == '\r' || value == 0u) {
                break;
            }
            ++token_end;
        }
        bool matches = token_end - line == key_length;
        for (std::size_t index = 0u; matches && index != key_length; ++index) {
            matches = *(uint8_t*)(text_address + static_cast<uint32_t>(line + index)) == *(uint8_t*)(key_address + static_cast<uint32_t>(index));
        }
        if (matches) {
            std::size_t value = token_end;
            while (value < scan_limit) {
                const uint8_t current = *(uint8_t*)(text_address + static_cast<uint32_t>(value));
                if (current != ' ' && current != '\t') {
                    break;
                }
                ++value;
            }
            return value < scan_limit ? text_address + static_cast<uint32_t>(value) : 0u;
        }
        std::size_t next_line = token_end;
        while (next_line < scan_limit) {
            const uint8_t current = *(uint8_t*)(text_address + static_cast<uint32_t>(next_line));
            if (current == '\n' || current == 0u) {
                break;
            }
            ++next_line;
        }
        if (next_line == scan_limit || *(uint8_t*)(text_address + static_cast<uint32_t>(next_line)) == 0u) {
            return 0u;
        }
        line = next_line + 1u;
    }
    return 0u;
}
__declspec(noinline) void sfera_sub_00401600(LiftCpu* cpu, uint32_t stop_address) {
    static_cast<void>(stop_address);
    const uint32_t key_address = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = sfera_config_lookup(key_address);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x401689u));
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x40169Au));
    cpu->esi = cpu->eax;
    cpu->esp += 0x14u;
    if (cpu->esi != 0xFFFFFFFFu) goto label_000016B0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000016B0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4016BBu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4016C2u));
    cpu->esp += 0x10u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    g_sfera_config_text_runtime.text_length = 0u;
    g_sfera_config_text_runtime.current_text = (uintptr_t)&g_sfera_config_text_runtime.owned_text[0];
    g_sfera_config_text_runtime.owned_text[0] = 0u;
    cpu->edx -= cpu->eax;
    label_00001723:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001723;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    g_sfera_config_text_runtime.current_text = cpu->eax;
    cpu->edx = cpu->eax + 1u;
    lift_push32(cpu, cpu->ebx);
    label_00001740:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00001740;
    cpu->eax -= cpu->edx;
    g_sfera_config_text_runtime.text_length = cpu->eax;
    cpu->eax = (uintptr_t)"";
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_00001758:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001758;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40177Au)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x40177Au));
    if (cpu->eax != 0u) goto label_00001783;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00001783:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x40178Eu));
    cpu->esp += 0xCu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004017A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4017AAu)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x4017AAu));
    if (cpu->eax != 0u) goto label_000017B3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000017B3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4017BEu));
    cpu->esp += 0xCu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004017D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4017DAu)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x4017DAu));
    if (cpu->eax != 0u) goto label_000017E3;
    label_000017DE:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000017E3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0x22u) goto label_000017DE;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->esi == 0u) goto label_00001823;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    label_000017F8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) == 0x22u) goto label_0000181F;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0000181F;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) == 0xAu) goto label_00001815;
    if ((cpu->ecx & 0xFFu) == 0xDu) goto label_00001812;
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    goto label_00001815;
    label_00001812:
    *(uint8_t*)(cpu->edx) = 0x20u;
    label_00001815:
    ++cpu->edx;
    if ((--cpu->esi) != 0u) goto label_000017F8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000181F:
    if (cpu->esi != 0u) goto label_00001829;
    label_00001823:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00001829:
    *(uint8_t*)(cpu->edx) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40184Bu)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x40184Bu));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00001857;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00001857:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((cpu->edx & 0xFFu) == 0x23u) goto label_0000192F;
    label_00001870:
    if ((cpu->edx & 0xFFu) == 0u) goto label_0000192B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ebp = cpu->ecx + 6u;
    cpu->eax += cpu->eax;
    if (cpu->ebp > cpu->eax) goto label_00001979;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->edx + 0xFFFFFFD0u;
    cpu->esi = (int32_t)(cpu->esi) >> 3u;
    cpu->edx = cpu->esi * 8u;
    cpu->ecx -= cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->edi;
    cpu->ecx += cpu->esi;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000018B1;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018B7;
    label_000018B1:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018B7:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018BE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018BE:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_000018C6;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018CC;
    label_000018C6:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018CC:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018D3;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018D3:
    if ((((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000018DB;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018E1;
    label_000018DB:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018E1:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018E8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018E8:
    if ((((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_000018F0;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018F6;
    label_000018F0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018F6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018FD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018FD:
    if ((((cpu->eax & 0xFFu)) & (0x10u)) == 0u) goto label_00001905;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_0000190B;
    label_00001905:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0000190B:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_00001912;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_00001912:
    if ((((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_0000191A;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_0000191E;
    label_0000191A:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->edx & 0xFFu));
    label_0000191E:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->ecx = cpu->ebp;
    if ((cpu->edx & 0xFFu) != 0x23u) goto label_00001870;
    label_0000192B:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    label_0000192F:
    if (*(uint8_t*)(cpu->edi) != 0x23u) goto label_00001970;
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->edi + 1u));
    cpu->edx -= 0x30u;
    if ((int32_t)cpu->edx <= 0) goto label_00001970;
    cpu->eax = cpu->edx + cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    if (cpu->eax > cpu->ecx) goto label_0000197D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 2u));
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x28u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0x30u) - (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1970u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_RVA(0x1970u));
    label_00001970:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00001979:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    label_0000197D:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    g_sfera_config_text_runtime.text_length = 0u;
    g_sfera_config_text_runtime.current_text = (uintptr_t)&g_sfera_config_text_runtime.owned_text[0];
    g_sfera_config_text_runtime.owned_text[0] = 0u;
    cpu->edx -= cpu->eax;
    label_000019B8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000019B8;
    cpu->edi = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4019D0u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00001AA0;
    lift_push32(cpu, 0x25823Fu); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4019EBu));
    lift_push32(cpu, cpu->esi);
    g_sfera_config_text_runtime.text_length = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4019F7u));
    cpu->edx = g_sfera_config_text_runtime.text_length;
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    cpu->esp += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A11u)); sfera_sub_0047E850(cpu, LIFT_CODE_TOKEN_VA(0x401A11u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00001AA8;
    cpu->edx = 0xC6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    *(uint32_t*)(cpu->esp + 0x10u) = 0x25823Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A30u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x401A30u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A3Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x401A3Bu));
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = g_sfera_config_text_runtime.current_text;
    cpu->esp += 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A59u)); sfera_sub_0047E870(cpu, LIFT_CODE_TOKEN_VA(0x401A59u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00001A78;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    g_sfera_config_text_runtime.text_length = cpu->eax;
    cpu->eax = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x401A70u));
    cpu->esp += 0xCu;
    label_00001A78:
    cpu->edx = 0xCFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A87u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x401A87u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A8Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x401A8Du));
    cpu->esp += 4u;
    if (cpu->edi == 0u) goto label_00001AA8;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1AA0u)); sfera_sub_00401700(cpu, LIFT_CODE_TOKEN_RVA(0x1AA0u));
    label_00001AA0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001AA8:
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = g_sfera_config_text_runtime.current_text;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->edx + cpu->ecx) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401AC0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint8_t*)(cpu->edi) != 0u) goto label_00001AD0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001AD0:
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0xCu) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xCu) = 0x25823Fu;
    if (sub_pred[0]) goto label_00001B02;
    cpu->edx = 0xE3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401AF0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x401AF0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401AFBu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x401AFBu));
    cpu->esp += 4u;
    cpu->esi = cpu->eax;
    goto label_00001B04;
    label_00001B02:
    cpu->esi = 0u;
    label_00001B04:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (*(uint8_t*)(cpu->esp + 0x14u) != (cpu->ebx & 0xFFu)) goto label_00001B1C;
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    goto label_00001B3E;
    label_00001B1C:
    cpu->eax = g_sfera_config_text_runtime.text_length;
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401B34u)); sfera_sub_0047E900(cpu, LIFT_CODE_TOKEN_VA(0x401B34u));
    if (cpu->eax != 0u) goto label_00001B47;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    label_00001B3E:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401B45u)); sfera_sub_00401680(cpu, LIFT_CODE_TOKEN_VA(0x401B45u));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    label_00001B47:
    cpu->edx = 0xEBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401B56u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x401B56u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401B5Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x401B5Cu));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ebx & 0xFFu) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_config_text_runtime.text_length;
    if (cpu->eax >= cpu->esi) goto label_00001B81;
    cpu->esi = cpu->eax;
    label_00001B81:
    cpu->eax = g_sfera_config_text_runtime.current_text;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x401B8Du));
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->esi < 4u) goto label_00001C07;
    label_00001BF3:
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_00001C0B;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if (cpu->esi >= 4u) goto label_00001BF3;
    label_00001C07:
    if (cpu->esi == 0u) goto label_00001C4F;
    label_00001C0B:
    cpu->eax = *(uint8_t*)(cpu->edx);
    cpu->edi = *(uint8_t*)(cpu->ecx);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001C46;
    if (cpu->esi <= 1u) goto label_00001C4F;
    cpu->eax = *(uint8_t*)(cpu->edx + 1u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 1u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001C46;
    if (cpu->esi <= 2u) goto label_00001C4F;
    cpu->eax = *(uint8_t*)(cpu->edx + 2u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 2u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001C46;
    if (cpu->esi <= 3u) goto label_00001C4F;
    cpu->eax = *(uint8_t*)(cpu->edx + 3u);
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->eax -= cpu->ecx;
    label_00001C46:
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001C4F:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx == 0u) goto label_00001C7F;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->eax < cpu->edx) goto label_00001C7A;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->eax + cpu->edx + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->ecx + 8u)) goto label_00001C7F;
    label_00001C7A:
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001C7F:
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00001C9C;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00001CBC;
    label_00001C9C:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx == 0u) goto label_00001CB4;
    if (cpu->eax < cpu->edx) goto label_00001CBC;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->eax + cpu->edx + 0xFFFFFFFFu;
    if (cpu->eax > *(uint32_t*)(cpu->ecx + 8u)) goto label_00001CBC;
    label_00001CB4:
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001CBC:
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401CD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00001CE2;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00001CF5;
    label_00001CE2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_00001D01;
    if (cpu->eax < cpu->ecx) goto label_00001CF5;
    cpu->eax += 0xBu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_00001D01;
    label_00001CF5:
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1D01u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x1D01u));
    label_00001D01:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->eax + cpu->edx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx = cpu->ecx + cpu->esi + 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + cpu->edx + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401D30(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2];
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->esi != 0u) goto label_00001D4E;
    if (*(uint32_t*)(cpu->edi + 4u) != 0u) goto label_00001D4E;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001D4E:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->edx==0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((cpu->esi==0u)) ? 1u : 0u) & 0xFFu);
    if (cpu->ecx == cpu->eax) goto label_00001D6B;
    label_00001D63:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001D6B:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    if (cpu->ecx != *(uint32_t*)(cpu->edi)) goto label_00001D63;
    if (cpu->ecx < 4u) goto label_00001D8B;
    label_00001D77:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_00001D8F;
    cpu->ecx -= 4u;
    cpu->edx += 4u;
    cpu->esi += 4u;
    if (cpu->ecx >= 4u) goto label_00001D77;
    label_00001D8B:
    if (cpu->ecx == 0u) goto label_00001DDD;
    label_00001D8F:
    cpu->edi = *(uint8_t*)(cpu->edx);
    cpu->eax = *(uint8_t*)(cpu->esi);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001DCA;
    if (cpu->ecx <= 1u) goto label_00001DDD;
    cpu->eax = *(uint8_t*)(cpu->esi + 1u);
    cpu->edi = *(uint8_t*)(cpu->edx + 1u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001DCA;
    if (cpu->ecx <= 2u) goto label_00001DDD;
    cpu->eax = *(uint8_t*)(cpu->esi + 2u);
    cpu->edi = *(uint8_t*)(cpu->edx + 2u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001DCA;
    if (cpu->ecx <= 3u) goto label_00001DDD;
    cpu->eax = *(uint8_t*)(cpu->esi + 3u);
    cpu->ecx = *(uint8_t*)(cpu->edx + 3u);
    cpu->eax -= cpu->ecx;
    label_00001DCA:
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->eax |= 1u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = 0u;
    lift_test[0]=cpu->eax==0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((lift_test[0]) ? 1u : 0u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001DDD:
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = 0u;
    lift_test[1]=cpu->eax==0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((lift_test[1]) ? 1u : 0u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 2u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 3u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 5u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0x19285u;
    *(uint8_t*)(cpu->eax + 8u) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401E50(LiftCpu* cpu, uint32_t stop_address) {
    *(uint32_t*)(cpu->ecx) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401F10(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_00001F4A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ecx) == 0x19285u);
    if ((cpu->eax & 0xFFu) == 0u) goto label_00001F4A;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00001F4A;
    switch (cpu->eax) {
        case 0u: goto label_00001F31;
        case 1u: goto label_00001F36;
        case 2u: goto label_00001F3B;
        case 3u: goto label_00001F40;
        case 4u: goto label_00001F45;
        default: lift_trap(cpu, 0x401F2Au, "resolved jump-table index out of range"); return;
    }
label_00001F31: ;
    goto label_00014F70;
    label_00001F36:
    goto label_00018680;
    label_00001F3B:
    goto label_000165C0;
    label_00001F40:
    goto label_00016170;
    label_00001F45:
    goto label_00018080;
    label_00001F4A:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014F70:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00015022;
    switch (cpu->eax) {
        case 0u: goto label_00014F87;
        case 1u: goto label_00014FAA;
        case 2u: goto label_00015022;
        case 3u: goto label_00014FCD;
        case 4u: goto label_00015006;
        default: lift_trap(cpu, 0x414F80u, "resolved jump-table index out of range"); return;
    }
label_00014F87: ;
    cpu->edx = 0x18u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414F96u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x414F96u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414F9Du)); sfera_sub_004149E0(cpu, LIFT_CODE_TOKEN_VA(0x414F9Du));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FA3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414FA3u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014FAA:
    cpu->edx = 0x18u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FB9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x414FB9u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FC0u)); sfera_sub_004149E0(cpu, LIFT_CODE_TOKEN_VA(0x414FC0u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FC6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414FC6u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014FCD:
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x18u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FDDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x414FDDu));
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FE5u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x414FE5u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FEEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414FEEu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FF8u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x414FF8u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414FFEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414FFEu));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015006:
    cpu->edx = 0x18u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415015u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415015u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41501Eu)); sfera_sub_00414CA0(cpu, LIFT_CODE_TOKEN_VA(0x41501Eu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015022:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016170:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_000161A0;
    switch (cpu->eax) {
        case 0u: goto label_00016180;
        case 1u: goto label_00016188;
        case 2u: goto label_000161A0;
        case 3u: goto label_00016190;
        case 4u: goto label_00016198;
        default: lift_trap(cpu, 0x416179u, "resolved jump-table index out of range"); return;
    }
label_00016180: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416185u)); sfera_sub_00416080(cpu, LIFT_CODE_TOKEN_VA(0x416185u));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016188:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41618Du)); sfera_sub_00416080(cpu, LIFT_CODE_TOKEN_VA(0x41618Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016190:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416195u)); sfera_sub_004160D0(cpu, LIFT_CODE_TOKEN_VA(0x416195u));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016198:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41619Du)); sfera_sub_00416120(cpu, LIFT_CODE_TOKEN_VA(0x41619Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000161A0:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000165C0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if ((--cpu->eax) == 0u) goto label_000165EF;
    if ((cpu->eax -= 3u) == 0u) goto label_000165D3;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000165D3:
    cpu->edx = 0x19u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4165E2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4165E2u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4165EBu)); sfera_sub_00416520(cpu, LIFT_CODE_TOKEN_VA(0x4165EBu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000165EF:
    cpu->edx = 0x19u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4165FEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4165FEu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416607u)); sfera_sub_00416290(cpu, LIFT_CODE_TOKEN_VA(0x416607u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018080:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_000180B0;
    switch (cpu->eax) {
        case 0u: goto label_00018090;
        case 1u: goto label_00018098;
        case 2u: goto label_000180B0;
        case 3u: goto label_000180A0;
        case 4u: goto label_000180A8;
        default: lift_trap(cpu, 0x418089u, "resolved jump-table index out of range"); return;
    }
label_00018090: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418095u)); sfera_sub_00417F20(cpu, LIFT_CODE_TOKEN_VA(0x418095u));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018098:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41809Du)); sfera_sub_00417F20(cpu, LIFT_CODE_TOKEN_VA(0x41809Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000180A0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4180A5u)); sfera_sub_00417FA0(cpu, LIFT_CODE_TOKEN_VA(0x4180A5u));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000180A8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4180ADu)); sfera_sub_00418010(cpu, LIFT_CODE_TOKEN_VA(0x4180ADu));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000180B0:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018680:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_0001872A;
    switch (cpu->eax) {
        case 0u: goto label_00018697;
        case 1u: goto label_000186B3;
        case 2u: goto label_000186CF;
        case 3u: goto label_000186EB;
        case 4u: goto label_00018707;
        default: lift_trap(cpu, 0x418690u, "resolved jump-table index out of range"); return;
    }
label_00018697: ;
    cpu->edx = 0x17u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4186A6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4186A6u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4186AFu)); sfera_sub_00418220(cpu, LIFT_CODE_TOKEN_VA(0x4186AFu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000186B3:
    cpu->edx = 0x17u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4186C2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4186C2u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4186CBu)); sfera_sub_00418220(cpu, LIFT_CODE_TOKEN_VA(0x4186CBu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000186CF:
    cpu->edx = 0x17u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4186DEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4186DEu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4186E7u)); sfera_sub_00418220(cpu, LIFT_CODE_TOKEN_VA(0x4186E7u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000186EB:
    cpu->edx = 0x17u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4186FAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4186FAu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418703u)); sfera_sub_00418620(cpu, LIFT_CODE_TOKEN_VA(0x418703u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018707:
    cpu->edx = 0x17u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418716u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x418716u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41871Du)); sfera_sub_004182C0(cpu, LIFT_CODE_TOKEN_VA(0x41871Du));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418723u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x418723u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001872A:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402040(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00002040;
    label_00001E60:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401E66u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401E66u));
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00001EE3;
    switch (cpu->eax) {
        case 0u: goto label_00001E73;
        case 1u: goto label_00001E99;
        case 2u: goto label_00001EA7;
        case 3u: goto label_00001EB5;
        case 4u: goto label_00001ECC;
        default: lift_trap(cpu, 0x401E6Cu, "resolved jump-table index out of range"); return;
    }
label_00001E73: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401E78u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401E78u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1E7Fu)); sfera_sub_00414E00(cpu, LIFT_CODE_TOKEN_RVA(0x1E7Fu));
    label_00001E7F:
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00001E91;
    cpu->edx = 9u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1E91u)); sfera_sub_00437B00(cpu, LIFT_CODE_TOKEN_RVA(0x1E91u));
    label_00001E91:
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001E99:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401E9Eu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401E9Eu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401EA5u)); sfera_sub_00418470(cpu, LIFT_CODE_TOKEN_VA(0x401EA5u));
    goto label_00001E7F;
    label_00001EA7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401EACu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401EACu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401EB3u)); sfera_sub_00416460(cpu, LIFT_CODE_TOKEN_VA(0x401EB3u));
    goto label_00001E7F;
    label_00001EB5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401EBAu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401EBAu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401EC1u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401EC1u));
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401ECAu)); sfera_sub_00415DB0(cpu, LIFT_CODE_TOKEN_VA(0x401ECAu));
    goto label_00001E7F;
    label_00001ECC:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401ED1u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401ED1u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401ED8u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401ED8u));
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401EE1u)); sfera_sub_00417C70(cpu, LIFT_CODE_TOKEN_VA(0x401EE1u));
    goto label_00001E7F;
    label_00001EE3:
    cpu->esi = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001F70:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401F75u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401F75u));
    if (cpu->eax == 0u) goto label_00001F8E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->eax) == 0x19285u);
    if ((cpu->ecx & 0xFFu) == 0u) goto label_00001F8E;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001F8E:
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001FA0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401FA5u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x401FA5u));
    if (cpu->eax == 0u) goto label_00001FB6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->eax) == 0x19285u);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001FBE;
    label_00001FB6:
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001FBE:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    --cpu->ecx;
    if (cpu->ecx > 4u) goto label_00001FB6;
    switch (cpu->ecx) {
        case 0u: case 1u: goto label_00001FCE;
        case 2u: goto label_00001FB6;
        case 3u: case 4u: goto label_00001FD6;
        default: lift_trap(cpu, 0x401FC7u, "resolved jump-table index out of range"); return;
    }
label_00001FCE: ;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001FD6:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00002000:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402005u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x402005u));
    if (cpu->eax == 0u) goto label_00002016;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->eax) == 0x19285u);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0000201E;
    label_00002016:
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000201E:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->ecx == 3u) goto label_0000202E;
    cpu->ecx += 0xFFFFFFFCu;
    if (cpu->ecx > 1u) goto label_00002016;
    label_0000202E:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00002040:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402045u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x402045u));
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00002089;
    switch (cpu->eax) {
        case 0u: goto label_00002052;
        case 1u: goto label_00002057;
        case 2u: goto label_0000207A;
        case 3u: goto label_0000207F;
        case 4u: goto label_00002084;
        default: lift_trap(cpu, 0x40204Bu, "resolved jump-table index out of range"); return;
    }
label_00002052: ;
    goto label_00001E60;
    label_00002057:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40205Du)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40205Du));
    cpu->esi = cpu->eax;
    cpu->edx = 9u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40206Bu)); sfera_sub_00437B80(cpu, LIFT_CODE_TOKEN_VA(0x40206Bu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402072u)); sfera_sub_00401F10(cpu, LIFT_CODE_TOKEN_VA(0x402072u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000207A:
    goto label_00001F70;
    label_0000207F:
    goto label_00001FA0;
    label_00002084:
    goto label_00002000;
    label_00002089:
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004020B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000020BA;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000020BA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004020E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x29u) != 0u) goto label_000020FA;
    label_000020F0:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x29u) == 0u) goto label_000020F0;
    label_000020FA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_0000211B;
    label_00002110:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_00002110;
    label_0000211B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x29u) != 0u) goto label_0000213B;
    label_00002130:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x29u) == 0u) goto label_00002130;
    label_0000213B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x11u) == 0u) goto label_00002150;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00002150:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_0000216F;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x11u) != 0u) goto label_00002191;
    label_00002161:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x11u) == 0u) goto label_00002161;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000216F:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_00002189;
    label_00002178:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_00002189;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_00002178;
    label_00002189:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x11u) != 0u) goto label_00002193;
    label_00002191:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_00002193:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004021A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x29u) == 0u) goto label_000021B0;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000021B0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x29u) != 0u) goto label_000021CF;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x29u) != 0u) goto label_000021F1;
    label_000021C1:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x29u) == 0u) goto label_000021C1;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000021CF:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x29u) != 0u) goto label_000021E9;
    label_000021D8:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_000021E9;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x29u) == 0u) goto label_000021D8;
    label_000021E9:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x29u) != 0u) goto label_000021F3;
    label_000021F1:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000021F3:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_0000221B;
    label_00002210:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x15u) == 0u) goto label_00002210;
    label_0000221B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_0000226A;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x15u) != 0u) goto label_0000224D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_0000224A;
    label_00002240:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x15u) == 0u) goto label_00002240;
    label_0000224A:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000224D:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_00002268;
    label_00002256:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_00002268;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x15u) == 0u) goto label_00002256;
    label_00002268:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000226A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Du) != 0u) goto label_0000228B;
    label_00002280:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_00002280;
    label_0000228B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Du) != 0u) goto label_000022AA;
    label_000022A0:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_000022A0;
    label_000022AA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004022B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_000022CA;
    label_000022C0:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x15u) == 0u) goto label_000022C0;
    label_000022CA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004022D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Du) != 0u) goto label_0000231A;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x2Du) != 0u) goto label_000022FD;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x2Du) != 0u) goto label_000022FA;
    label_000022F0:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_000022F0;
    label_000022FA:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000022FD:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x2Du) != 0u) goto label_00002318;
    label_00002306:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_00002318;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_00002306;
    label_00002318:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000231A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x45u) != 0u) goto label_0000233B;
    label_00002330:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x45u) == 0u) goto label_00002330;
    label_0000233B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x45u) != 0u) goto label_0000235A;
    label_00002350:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x45u) == 0u) goto label_00002350;
    label_0000235A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x45u) != 0u) goto label_000023AA;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x45u) != 0u) goto label_0000238D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x45u) != 0u) goto label_0000238A;
    label_00002380:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x45u) == 0u) goto label_00002380;
    label_0000238A:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000238D:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x45u) != 0u) goto label_000023A8;
    label_00002396:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_000023A8;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x45u) == 0u) goto label_00002396;
    label_000023A8:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000023AA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004023B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x19u) != 0u) goto label_000023CB;
    label_000023C0:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x19u) == 0u) goto label_000023C0;
    label_000023CB:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004023D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x19u) != 0u) goto label_000023EA;
    label_000023E0:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x19u) == 0u) goto label_000023E0;
    label_000023EA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004023F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x19u) != 0u) goto label_0000243A;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x19u) != 0u) goto label_0000241D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x19u) != 0u) goto label_0000241A;
    label_00002410:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x19u) == 0u) goto label_00002410;
    label_0000241A:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000241D:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x19u) != 0u) goto label_00002438;
    label_00002426:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_00002438;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x19u) == 0u) goto label_00002426;
    label_00002438:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000243A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x31u) != 0u) goto label_0000245B;
    label_00002450:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x31u) == 0u) goto label_00002450;
    label_0000245B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x31u) != 0u) goto label_0000247A;
    label_00002470:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x31u) == 0u) goto label_00002470;
    label_0000247A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x31u) != 0u) goto label_000024CA;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x31u) != 0u) goto label_000024AD;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x31u) != 0u) goto label_000024AA;
    label_000024A0:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x31u) == 0u) goto label_000024A0;
    label_000024AA:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000024AD:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x31u) != 0u) goto label_000024C8;
    label_000024B6:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_000024C8;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x31u) == 0u) goto label_000024B6;
    label_000024C8:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000024CA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004024D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_00002528;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    (void)cpu;
    label_000024E0:
    if (cpu->edi == cpu->esi) goto label_00002516;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4024F3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4024F3u));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4024FCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4024FCu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi) = 0u;
    label_00002516:
    cpu->esi += 8u;
    cpu->edi += 8u;
    if (cpu->esi != cpu->ebx) goto label_000024E0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002528:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x2Du) == 0u) goto label_00002550;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00002550:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x2Du) != 0u) goto label_0000256F;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x2Du) != 0u) goto label_00002591;
    label_00002561:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x2Du) == 0u) goto label_00002561;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000256F:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x2Du) != 0u) goto label_00002589;
    label_00002578:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_00002589;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_00002578;
    label_00002589:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x2Du) != 0u) goto label_00002593;
    label_00002591:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_00002593:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004025A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x15u) == 0u) goto label_000025B0;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000025B0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_000025CF;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x15u) != 0u) goto label_000025F1;
    label_000025C1:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x15u) == 0u) goto label_000025C1;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000025CF:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_000025E9;
    label_000025D8:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_000025E9;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x15u) == 0u) goto label_000025D8;
    label_000025E9:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x15u) != 0u) goto label_000025F3;
    label_000025F1:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000025F3:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x45u) == 0u) goto label_00002610;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00002610:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x45u) != 0u) goto label_0000262F;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x45u) != 0u) goto label_00002651;
    label_00002621:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x45u) == 0u) goto label_00002621;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000262F:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x45u) != 0u) goto label_00002649;
    label_00002638:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_00002649;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x45u) == 0u) goto label_00002638;
    label_00002649:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x45u) != 0u) goto label_00002653;
    label_00002651:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_00002653:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x19u) == 0u) goto label_00002670;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00002670:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x19u) != 0u) goto label_0000268F;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x19u) != 0u) goto label_000026B1;
    label_00002681:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x19u) == 0u) goto label_00002681;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000268F:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x19u) != 0u) goto label_000026A9;
    label_00002698:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_000026A9;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x19u) == 0u) goto label_00002698;
    label_000026A9:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x19u) != 0u) goto label_000026B3;
    label_000026B1:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000026B3:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004026C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x31u) == 0u) goto label_000026D0;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000026D0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x31u) != 0u) goto label_000026EF;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x31u) != 0u) goto label_00002711;
    label_000026E1:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x31u) == 0u) goto label_000026E1;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000026EF:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x31u) != 0u) goto label_00002709;
    label_000026F8:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx)) goto label_00002709;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x31u) == 0u) goto label_000026F8;
    label_00002709:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x31u) != 0u) goto label_00002713;
    label_00002711:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_00002713:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402733u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x402733u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40273Au)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40273Au));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00002748;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0000275C;
    label_00002748:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->ecx == 0u) goto label_00002765;
    if (cpu->eax < cpu->ecx) goto label_0000275C;
    cpu->eax = cpu->eax + cpu->esi + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->edi + 8u)) goto label_00002765;
    label_0000275C:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2765u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x2765u));
    label_00002765:
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = 0x20u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    *(uint32_t*)(cpu->ebx) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40277Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40277Eu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402784u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x402784u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x40278Au));
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004027A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax >= cpu->edi) goto label_000027B7;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4027A0u), "std::out_of_range");
    label_000027B7:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= cpu->edi;
    if (cpu->eax >= cpu->esi) goto label_000027C5;
    cpu->esi = cpu->eax;
    label_000027C5:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_000027D1;
    cpu->edx = cpu->ebx;
    label_000027D1:
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_000027DB;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    goto label_000027DD;
    label_000027DB:
    cpu->eax = cpu->ecx;
    label_000027DD:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4027EBu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4027EBu));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_00002806;
    if (cpu->esi >= cpu->ebx) goto label_000027FF;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000027FF:
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebx);
    label_00002806:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402810(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax >= cpu->ecx) goto label_00002829;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x402810u), "std::out_of_range");
    label_00002829:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax -= cpu->ecx;
    if (cpu->eax >= cpu->edi) goto label_00002836;
    cpu->edi = cpu->eax;
    label_00002836:
    if (cpu->edi == 0u) goto label_0000288A;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ebx);
    if (cpu->edx < 0x10u) goto label_00002847;
    cpu->ebx = *(uint32_t*)(cpu->esi);
    goto label_00002849;
    label_00002847:
    cpu->ebx = cpu->esi;
    label_00002849:
    if (cpu->edx < 0x10u) goto label_00002852;
    cpu->edx = *(uint32_t*)(cpu->esi);
    goto label_00002854;
    label_00002852:
    cpu->edx = cpu->esi;
    label_00002854:
    cpu->eax -= cpu->edi;
    cpu->ebx += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ebx += cpu->edi;
    cpu->edx += cpu->ecx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40285Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esp += 0xCu;
    cpu->eax -= cpu->edi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00002884;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->ecx + cpu->eax) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002884:
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->ecx + cpu->eax) = 0u;
    label_0000288A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004028A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000028ED;
    if (cpu->ecx > 0xFFFFFFFFu) goto label_000028BF;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4028B8u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4028B8u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000028ED;
    label_000028BF:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x28EDu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x28EDu));
    label_000028ED:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_00002926;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax >= cpu->edx) goto label_00002926;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002926:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_0000295F;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax >= cpu->edx) goto label_0000295F;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000295F:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_00002996;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax >= cpu->edx) goto label_00002996;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    *(float*)(cpu->ecx + (cpu->eax * 4u)) = (double)*(float*)(cpu->edx);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002996:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004029A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_000029CE;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax >= cpu->edx) goto label_000029CE;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->eax * 4u));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000029CE:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004029E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_00002A03;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax >= cpu->edx) goto label_00002A03;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->eax + cpu->ecx) = cpu->edx & 0xFFu;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002A03:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_00002A3C;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax >= cpu->edx) goto label_00002A3C;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->ecx));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint8_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFu;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002A3C:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_00002AAE;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    if (cpu->eax >= cpu->edx) goto label_00002AAE;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx + (cpu->eax * 8u);
    if (cpu->esi == cpu->edi) goto label_00002AA7;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402A84u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x402A84u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402A8Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x402A8Du));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_00002AA7:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002AAE:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((int32_t)cpu->eax < 0) goto label_00002AE9;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    if (cpu->eax >= cpu->edx) goto label_00002AE9;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402AE4u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x402AE4u));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002AE9:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x29u) != 0u) goto label_00002B3A;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x29u) != 0u) goto label_00002B1D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x29u) != 0u) goto label_00002B1A;
    label_00002B10:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x29u) == 0u) goto label_00002B10;
    label_00002B1A:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00002B1D:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x29u) != 0u) goto label_00002B38;
    label_00002B26:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_00002B38;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x29u) == 0u) goto label_00002B26;
    label_00002B38:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_00002B3A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_00002B9D;
    if (cpu->ecx > 0x9249249u) goto label_00002B6F;
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402B68u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x402B68u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00002B9D;
    label_00002B6F:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2B9Du)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x2B9Du));
    label_00002B9D:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_00002C07;
    if (cpu->ecx > 0x1FFFFFFFu) goto label_00002BD9;
    cpu->eax = cpu->ecx * 8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402BD2u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x402BD2u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00002C07;
    label_00002BD9:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2C07u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x2C07u));
    label_00002C07:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x29u) != 0u) goto label_00002C28;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002C28:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002C42;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002C42:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_00002C53;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002C53:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x29u) != 0u) goto label_00002C78;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002C78:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002C93;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002C93:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_00002CA7;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002CA7:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_00002D14;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402D08u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x402D08u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402D11u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x402D11u));
    cpu->esp += 4u;
    label_00002D14:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402D20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[0]) goto label_00002D71;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402D65u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x402D65u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402D6Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x402D6Eu));
    cpu->esp += 4u;
    label_00002D71:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_00002D9A;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402D8Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x402D8Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402D97u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x402D97u));
    cpu->esp += 4u;
    label_00002D9A:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x15u) != 0u) goto label_00002DC8;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002DC8:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002DE2;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002DE2:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_00002DF3;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002DF3:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x15u) != 0u) goto label_00002E18;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002E18:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002E33;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002E33:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_00002E47;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002E47:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x2Du) != 0u) goto label_00002E78;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002E78:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002E93;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002E93:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_00002EA7;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002EA7:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x2Du) != 0u) goto label_00002ED8;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002ED8:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002EF2;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002EF2:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_00002F03;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002F03:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x45u) != 0u) goto label_00002F28;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002F28:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002F42;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002F42:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_00002F53;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002F53:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x45u) != 0u) goto label_00002F78;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002F78:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002F93;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002F93:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_00002FA7;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002FA7:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x19u) != 0u) goto label_00002FD8;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00002FD8:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00002FF2;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00002FF2:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_00003003;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003003:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x19u) != 0u) goto label_00003028;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00003028:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_00003043;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003043:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_00003057;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003057:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x31u) != 0u) goto label_00003088;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_00003088:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_000030A2;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000030A2:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_000030B3;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000030B3:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004030C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x31u) != 0u) goto label_000030D8;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_000030D8:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_000030F3;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000030F3:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_00003107;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003107:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_00003140;
    lift_push32(cpu, cpu->esi);
    label_00003130:
    cpu->esi = *(uint32_t*)(cpu->edx + 0xFFFFFFFCu);
    cpu->edx -= 4u;
    cpu->eax -= 4u;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    if (cpu->edx != cpu->ecx) goto label_00003130;
    cpu->esi = lift_pop32(cpu);
    label_00003140:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403150(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == cpu->edx) goto label_0000316C;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    label_00003160:
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->ecx += 4u;
    if (cpu->ecx != cpu->edx) goto label_00003160;
    cpu->esi = lift_pop32(cpu);
    label_0000316C:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403170(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edx = (uint32_t)(((uint64_t)0xCCCCCCCDu * (uint32_t)(cpu->edi)) >> 32u);
    cpu->edx >>= 3u;
    cpu->ecx = 0u;
    ++cpu->edx;
    cpu->esi = 0x811C9DC5u;
    if (cpu->edi == 0u) goto label_000031B2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0x14u);
    label_00003194:
    if (cpu->ebp < 0x10u) goto label_0000319D;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    goto label_0000319F;
    label_0000319D:
    cpu->eax = cpu->ebx;
    label_0000319F:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ecx));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    cpu->ecx += cpu->edx;
    cpu->esi ^= cpu->eax;
    if (cpu->ecx < cpu->edi) goto label_00003194;
    cpu->ebp = lift_pop32(cpu);
    label_000031B2:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004031C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_000031D2;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_000031E5;
    label_000031D2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_000031F1;
    if (cpu->eax < cpu->ecx) goto label_000031E5;
    cpu->eax += 0xBu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_000031F1;
    label_000031E5:
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x31F1u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x31F1u));
    label_000031F1:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_00003216;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->eax + cpu->edx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx += cpu->esi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + cpu->edx + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00003216:
    cpu->ecx = cpu->edi;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->eax + cpu->edx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx += cpu->esi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + cpu->edx + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->eax;
    cpu->esi |= 0xFu;
    if (cpu->esi <= 0xFFFFFFFEu) goto label_00003271;
    cpu->esi = cpu->eax;
    goto label_00003298;
    label_00003271:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->edx = (uint32_t)(((uint64_t)0xAAAAAAABu * (uint32_t)(cpu->esi)) >> 32u);
    cpu->ecx = cpu->ebx;
    cpu->ecx >>= 1u;
    cpu->edx >>= 1u;
    if (cpu->ecx <= cpu->edx) goto label_00003298;
    cpu->eax = 0xFFFFFFFEu;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx + cpu->ebx;
    if (cpu->ebx <= cpu->eax) goto label_00003298;
    cpu->esi = 0xFFFFFFFEu;
    label_00003298:
    cpu->eax = 0u;
    cpu->ecx = cpu->esi + 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (cpu->ecx <= cpu->eax) goto label_000032B6;
    if (cpu->ecx > 0xFFFFFFFFu) goto label_000032BB;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4032AFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4032AFu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000032BB;
    label_000032B6:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    goto label_0000330D;
    label_000032BB:
    cpu->ecx = cpu->ebp + 0xFFFFFFE8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x32E4u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x32E4u));
    sfera_sub_004032E4(cpu, stop_address); return;
    label_0000330D:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->ebx == 0u) goto label_0000332E;
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000331E;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00003320;
    label_0000331E:
    cpu->eax = cpu->edi;
    label_00003320:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403326u));
    cpu->esp += 0xCu;
    label_0000332E:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000333F;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40333Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40333Cu));
    cpu->esp += 4u;
    label_0000333F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint8_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    if (cpu->esi < 0x10u) goto label_00003354;
    cpu->edi = cpu->eax;
    label_00003354:
    *(uint8_t*)(cpu->edi + cpu->ebx) = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004032E4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x18u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4032FEu)); sfera_sub_004028A0(cpu, LIFT_CODE_TOKEN_VA(0x4032FEu));
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    sfera_sub_00403307(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00403307(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->ebx == 0u) goto label_0000332E;
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000331E;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00003320;
    label_0000331E:
    cpu->eax = cpu->edi;
    label_00003320:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403326u));
    cpu->esp += 0xCu;
    label_0000332E:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000333F;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40333Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40333Cu));
    cpu->esp += 4u;
    label_0000333F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint8_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    if (cpu->esi < 0x10u) goto label_00003354;
    cpu->edi = cpu->eax;
    label_00003354:
    *(uint8_t*)(cpu->edi + cpu->ebx) = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040336C(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_00003380;
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40337Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40337Du));
    cpu->esp += 4u;
    label_00003380:
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, 0u);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40339Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40339Au));
    lift_trap(cpu, 0x40339Au, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004033A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 8u);
    if ((int32_t)cpu->edi < 0) goto label_000033E6;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->esi -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->esi))) >> 32u);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->esi = lift_pop32(cpu);
    if (cpu->edi >= cpu->eax) goto label_000033E6;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->edi * 8u;
    cpu->edx -= cpu->edi;
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4033E0u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x4033E0u));
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000033E6:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004033F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x11u) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if (!sub_pred[0]) goto label_00003434;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp);
    label_00003410:
    cpu->esi = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->esi >= (int32_t)cpu->edi) goto label_0000341C;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_0000342C;
    label_0000341C:
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_00003428;
    if ((int32_t)cpu->edi >= (int32_t)cpu->esi) goto label_00003428;
    cpu->edx = cpu->eax;
    label_00003428:
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000342C:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_00003410;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00003434:
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_00003442;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_00003444;
    label_00003442:
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_00003444:
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_00003464;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_00003450:
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_0000345B;
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_0000345E;
    label_0000345B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_0000345E:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_00003450;
    label_00003464:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x14u)) goto label_000034A7;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000034A7:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004034C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x14u)) goto label_000034E7;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint8_t*)(cpu->esi + cpu->edx) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000034E7:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403500(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x15u) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if (!sub_pred[0]) goto label_00003544;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp);
    label_00003520:
    cpu->esi = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->esi >= (int32_t)cpu->edi) goto label_0000352C;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_0000353C;
    label_0000352C:
    if (*(uint8_t*)(cpu->edx + 0x15u) == 0u) goto label_00003538;
    if ((int32_t)cpu->edi >= (int32_t)cpu->esi) goto label_00003538;
    cpu->edx = cpu->eax;
    label_00003538:
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000353C:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00003520;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00003544:
    if (*(uint8_t*)(cpu->edx + 0x15u) == 0u) goto label_00003552;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_00003554;
    label_00003552:
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_00003554:
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_00003574;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_00003560:
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_0000356B;
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_0000356E;
    label_0000356B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_0000356E:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00003560;
    label_00003574:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403590(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x2Du) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if (!sub_pred[0]) goto label_000035D4;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp);
    label_000035B0:
    cpu->esi = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->esi >= (int32_t)cpu->edi) goto label_000035BC;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_000035CC;
    label_000035BC:
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_000035C8;
    if ((int32_t)cpu->edi >= (int32_t)cpu->esi) goto label_000035C8;
    cpu->edx = cpu->eax;
    label_000035C8:
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000035CC:
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_000035B0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000035D4:
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_000035E2;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000035E4;
    label_000035E2:
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_000035E4:
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_00003604;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_000035F0:
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_000035FB;
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_000035FE;
    label_000035FB:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_000035FE:
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_000035F0;
    label_00003604:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403620(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x19u) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if (!sub_pred[0]) goto label_00003664;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp);
    label_00003640:
    cpu->esi = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->esi >= (int32_t)cpu->edi) goto label_0000364C;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_0000365C;
    label_0000364C:
    if (*(uint8_t*)(cpu->edx + 0x19u) == 0u) goto label_00003658;
    if ((int32_t)cpu->edi >= (int32_t)cpu->esi) goto label_00003658;
    cpu->edx = cpu->eax;
    label_00003658:
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000365C:
    if (*(uint8_t*)(cpu->eax + 0x19u) == 0u) goto label_00003640;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00003664:
    if (*(uint8_t*)(cpu->edx + 0x19u) == 0u) goto label_00003672;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_00003674;
    label_00003672:
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_00003674:
    if (*(uint8_t*)(cpu->eax + 0x19u) != 0u) goto label_00003694;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_00003680:
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_0000368B;
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_0000368E;
    label_0000368B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_0000368E:
    if (*(uint8_t*)(cpu->eax + 0x19u) == 0u) goto label_00003680;
    label_00003694:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004036B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4036BAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4036BAu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000036E3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_000036DD;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->ecx) = (double)*(float*)(cpu->edx);
    label_000036DD:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000036E3:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403711u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x403711u));
    lift_trap(cpu, 0x403711u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00403720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40372Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40372Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00003768;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == 0u) goto label_00003762;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    *(uint32_t*)(cpu->ecx) = 0u;
    cpu->edi = lift_pop32(cpu);
    label_00003762:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00003768:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403796u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x403796u));
    lift_trap(cpu, 0x403796u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004037A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->eax < 0x1FFFFFFEu) goto label_000037C2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4037B4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4037B4u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4037A0u), "std::length_error");
    label_000037C2:
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (cpu->eax != cpu->edx) goto label_000037EC;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_0000380D;
    label_000037EC:
    if (*(uint8_t*)(cpu->esp + 0x10u) == (cpu->ebx & 0xFFu)) goto label_000037FF;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000380D;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_0000380D;
    label_000037FF:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000380D;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_0000380D:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x14u) != (cpu->ebx & 0xFFu)) goto label_000039AE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_00003820:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_000038EF;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x14u) != (cpu->ebx & 0xFFu)) goto label_00003852;
    *(uint8_t*)(cpu->edx + 0x14u) = 1u;
    *(uint8_t*)(cpu->esi + 0x14u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000039A0;
    label_00003852:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_00003891;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x15u) != (cpu->ebx & 0xFFu)) goto label_0000386B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000386B:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000387E;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000388C;
    label_0000387E:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_00003889;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_0000388C;
    label_00003889:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_0000388C:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_00003891:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x14u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x15u) != (cpu->ebx & 0xFFu)) goto label_000038B9;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_000038B9:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_000038D2;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000399D;
    label_000038D2:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_000038E5;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000399D;
    label_000038E5:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000399D;
    label_000038EF:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x14u) != (cpu->ebx & 0xFFu)) goto label_00003912;
    *(uint8_t*)(cpu->edx + 0x14u) = 1u;
    *(uint8_t*)(cpu->esi + 0x14u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000039A0;
    label_00003912:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_00003952;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x15u) != (cpu->ebx & 0xFFu)) goto label_0000392A;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000392A:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000393D;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000394C;
    label_0000393D:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0000394A;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000394C;
    label_0000394A:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000394C:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_00003952:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x14u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x15u) != (cpu->ebx & 0xFFu)) goto label_0000397A;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000397A:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000398D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_0000399B;
    label_0000398D:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_00003998;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_0000399B;
    label_00003998:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_0000399B:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000399D:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_000039A0:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x14u) == (cpu->ebx & 0xFFu)) goto label_00003820;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000039AE:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x14u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004039D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003A00;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x1FFFFFFEu;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000039F8;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4039D0u), "std::length_error");
    label_000039F8:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003A00:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403A60(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003A90;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x7FFFFFEu;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00003A88;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x403A60u), "std::length_error");
    label_00003A88:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003A90:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403AF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003B20;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x4924923u;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00003B18;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x403AF0u), "std::length_error");
    label_00003B18:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003B20:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403B80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003BB0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x71C71C6u;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00003BA8;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x403B80u), "std::length_error");
    label_00003BA8:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003BB0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403C10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx + 8u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[0]) goto label_00003C62;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403C56u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x403C56u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403C5Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x403C5Fu));
    cpu->esp += 4u;
    label_00003C62:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_00003C8B;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403C7Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x403C7Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403C88u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x403C88u));
    cpu->esp += 4u;
    label_00003C8B:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403CA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp <= 0xFFFFFFFEu) goto label_00003CB8;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x403CA0u), "std::length_error");
    label_00003CB8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->ebp) goto label_00003CD6;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403CC9u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x403CC9u));
    cpu->ecx = 0u;
    cpu->eax = (cpu->ecx < cpu->ebp) ? 0xFFFFFFFFu : 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00003CD6:
    if (*(uint8_t*)(cpu->esp + 0x10u) == 0u) goto label_00003D29;
    if (cpu->ebp >= 0x10u) goto label_00003D29;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->ebp >= cpu->edi) goto label_00003CEC;
    cpu->edi = cpu->ebp;
    label_00003CEC:
    if (cpu->eax < 0x10u) goto label_00003D0D;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (cpu->edi == 0u) goto label_00003D03;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403CFBu));
    cpu->esp += 0xCu;
    label_00003D03:
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403D09u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x403D09u));
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu);
    label_00003D0D:
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    cpu->ecx = 0u;
    *(uint8_t*)(cpu->edi + cpu->esi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->ecx < cpu->ebp) ? 0xFFFFFFFFu : 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00003D29:
    if (cpu->ebp != 0u) goto label_00003D3A;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebp;
    if (cpu->eax < 0x10u) goto label_00003D37;
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_00003D37:
    *(uint8_t*)(cpu->esi) = 0u;
    label_00003D3A:
    cpu->ecx = 0u;
    cpu->eax = (cpu->ecx < cpu->ebp) ? 0xFFFFFFFFu : 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_00003D79;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003D79:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403D90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00003DA0;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003DA0:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403DA9u)); sfera_sub_004B1370(cpu, LIFT_CODE_TOKEN_VA(0x403DA9u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->edi == *(uint32_t*)(cpu->esi + 0x14u)) goto label_00003DCD;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003DCD:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00003E05;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403DFBu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x403DFBu));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003E05:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403E10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00003E20;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003E20:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403E29u)); sfera_sub_00402AF0(cpu, LIFT_CODE_TOKEN_VA(0x403E29u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->edi == *(uint32_t*)(cpu->esi + 0x14u)) goto label_00003E48;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->edi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403E3Du)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x403E3Du));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00003E48:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00003E6F;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00003E6F:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403E80u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x403E80u));
    cpu->ecx = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eax)&0x80000000u)!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403F00(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[3]; bool sub_pred[1];
    cpu->esp -= 0x18u;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x29u) == 0u;
    cpu->edx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if (!sub_pred[0]) goto label_0000401B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    goto label_00003F4C;
    label_00003F40:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    label_00003F4C:
    cpu->edi += 0xCu;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_00003F58;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_00003F58:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if (cpu->ebp >= cpu->esi) goto label_00003F61;
    label_00003F61:
    if (cpu->esi >= cpu->ecx) goto label_00003F67;
    cpu->ecx = cpu->esi;
    label_00003F67:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ebx < 0x10u) goto label_00003F73;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00003F75;
    label_00003F73:
    cpu->eax = cpu->edi;
    label_00003F75:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403F7Du)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x403F7Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00003F93;
    if (cpu->esi < cpu->ecx) goto label_00003F95;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ecx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00003F93:
    if (!lift_test[0]) goto label_00003FA2;
    label_00003F95:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_00004005;
    label_00003FA2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint8_t*)(cpu->eax + 0x29u) == 0u) goto label_00003FF7;
    if (cpu->ebx < 0x10u) goto label_00003FB3;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00003FB3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    if (cpu->ecx >= cpu->esi) goto label_00003FC0;
    cpu->esi = cpu->ecx;
    label_00003FC0:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebp) goto label_00003FC8;
    cpu->ecx = cpu->ebp;
    label_00003FC8:
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_00003FD1;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00003FD1:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403FD9u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x403FD9u));
    cpu->esp += 0xCu;
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00003FEB;
    if (cpu->esi < cpu->ebp) goto label_00003FED;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebp);
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    label_00003FEB:
    if (!lift_test[1]) goto label_00003FF7;
    label_00003FED:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_00003FFB;
    label_00003FF7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00003FFB:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_00004005:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edx + 0x29u) == 0u) goto label_00003F40;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000401B:
    if (*(uint8_t*)(cpu->edx + 0x29u) == 0u) goto label_00004029;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000402B;
    label_00004029:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    label_0000402B:
    if (*(uint8_t*)(cpu->ebx + 0x29u) != 0u) goto label_0000408E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    label_00004035:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->eax = cpu->ebx + 0xCu;
    if (*(uint32_t*)(cpu->ebx + 0x20u) < 0x10u) goto label_00004043;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004043:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_00004050;
    cpu->edx = cpu->edi;
    label_00004050:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_0000405B;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_0000405D;
    label_0000405B:
    cpu->ecx = cpu->ebp;
    label_0000405D:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404065u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404065u));
    cpu->esp += 0xCu;
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004077;
    if (cpu->esi < cpu->edi) goto label_00004079;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    label_00004077:
    if (!lift_test[2]) goto label_00004081;
    label_00004079:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    goto label_00004084;
    label_00004081:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    label_00004084:
    if (*(uint8_t*)(cpu->ebx + 0x29u) == 0u) goto label_00004035;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000408E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004040B0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x29u) == 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if (!sub_pred[0]) goto label_0000412D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    label_000040D0:
    cpu->eax = cpu->edi + 0xCu;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_000040DE;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_000040E0;
    label_000040DE:
    cpu->edx = cpu->ebp;
    label_000040E0:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_000040E9;
    label_000040E9:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_000040F1;
    cpu->ecx = cpu->ebx;
    label_000040F1:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000040F9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000040F9:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404101u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404101u));
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004113;
    if (cpu->esi < cpu->ebx) goto label_00004115;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00004113:
    if (!lift_test[0]) goto label_0000411A;
    label_00004115:
    cpu->edi = *(uint32_t*)(cpu->edi + 8u);
    goto label_00004120;
    label_0000411A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00004120:
    if (*(uint8_t*)(cpu->edi + 0x29u) == 0u) goto label_000040D0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0000412D:
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_00004169;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00004169:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404180(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_000041B6;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x10u)) goto label_000041B2;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000041B2:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_000041B6:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004041C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_000041E6;
    x87_v0 = (double)*(float*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000041E6:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004041F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_00004223;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x10u)) goto label_0000421F;
    x87_v0 = (double)*(float*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000421F:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_00004223:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00004262;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x10u)) goto label_0000425E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404254u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x404254u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000425E:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00004262:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000042A2;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x10u)) goto label_0000429E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404294u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x404294u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000429E:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000042A2:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004042B0(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_000042E2;
    *(uint32_t*)(cpu->ecx + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x20u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x14u)) goto label_000042DE;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000042DE:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_000042E2:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004042F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_0000431F;
    *(uint32_t*)(cpu->ecx + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x20u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x14u)) goto label_0000431B;
    x87_v0 = (double)*(float*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000431B:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_0000431F:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404330(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_00004367;
    cpu->edx = 1u;
    *(uint32_t*)(cpu->ecx + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x20u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x14u)) goto label_00004363;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    *(uint8_t*)(cpu->edi + cpu->esi) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 8u) = cpu->edx & 0xFFu;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00004363:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_00004367:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_0000439C;
    *(uint32_t*)(cpu->esi + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x20u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->edx == *(uint32_t*)(cpu->esi + 0x14u)) goto label_00004398;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40438Eu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x40438Eu));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00004398:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_0000439C:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004043B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000043DC;
    *(uint32_t*)(cpu->esi + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x20u)) + (uint64_t)(8u) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->edx == *(uint32_t*)(cpu->esi + 0x14u)) goto label_000043D8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4043CEu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x4043CEu));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000043D8:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000043DC:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004043F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x11u) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if (!sub_pred[0]) goto label_0000443D;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xCu);
    label_00004411:
    cpu->esi = cpu->eax;
    if (*(uint8_t*)(cpu->esp + 0x1Cu) == 0u) goto label_00004422;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((int32_t)(*(uint32_t*)(cpu->eax + 0xCu)) >= (int32_t)(cpu->edx));
    goto label_00004428;
    label_00004422:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((int32_t)(cpu->edx) < (int32_t)(*(uint32_t*)(cpu->eax + 0xCu)));
    label_00004428:
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_00004434;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_00004437;
    label_00004434:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_00004437:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_00004411;
    label_0000443D:
    cpu->edi = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0000447A;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = cpu->esp + 0x1Cu;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_00004471;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40445Eu)); sfera_sub_004D2180(cpu, LIFT_CODE_TOKEN_VA(0x40445Eu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00004471:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404476u)); sfera_sub_00402140(cpu, LIFT_CODE_TOKEN_VA(0x404476u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000447A:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ebx + 0xCu)) goto label_000044A8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404495u)); sfera_sub_004D2180(cpu, LIFT_CODE_TOKEN_VA(0x404495u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000044A8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4044ADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4044ADu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004044D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->ecx;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x15u) != 0u) goto label_000044FF;
    label_000044E1:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4044ECu)); sfera_sub_004044D0(cpu, LIFT_CODE_TOKEN_VA(0x4044ECu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4044F4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4044F4u));
    cpu->esp += 4u;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x15u) == 0u) goto label_000044E1;
    label_000044FF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404510(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x15u) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (sub_pred[0]) goto label_00004529;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x404510u), "std::out_of_range");
    label_00004529:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40453Bu)); sfera_sub_00402220(cpu, LIFT_CODE_TOKEN_VA(0x40453Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (*(uint8_t*)(cpu->ecx + 0x15u) == 0u) goto label_00004548;
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    goto label_00004560;
    label_00004548:
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00004555;
    cpu->edi = cpu->ecx;
    goto label_00004560;
    label_00004555:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebx) goto label_000045C7;
    label_00004560:
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint8_t*)(cpu->edi + 0x15u) != 0u) goto label_0000456C;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_0000456C:
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebx) goto label_00004579;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_00004584;
    label_00004579:
    if (*(uint32_t*)(cpu->esi) != cpu->ebx) goto label_00004581;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_00004584;
    label_00004581:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_00004584:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x10u)) goto label_000045A2;
    if (*(uint8_t*)(cpu->edi + 0x15u) == 0u) goto label_00004599;
    cpu->eax = cpu->esi;
    goto label_000045A0;
    label_00004599:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x45A0u)); sfera_sub_004022B0(cpu, LIFT_CODE_TOKEN_RVA(0x45A0u));
    label_000045A0:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_000045A2:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->edx) goto label_0000461E;
    if (*(uint8_t*)(cpu->edi + 0x15u) == 0u) goto label_000045BB;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000461E;
    label_000045BB:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4045C2u)); sfera_sub_00402200(cpu, LIFT_CODE_TOKEN_VA(0x4045C2u));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000461E;
    label_000045C7:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebx + 8u)) goto label_000045D7;
    cpu->esi = cpu->eax;
    goto label_000045F1;
    label_000045D7:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edi + 0x15u) != 0u) goto label_000045E3;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_000045E3:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_000045F1:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebx) goto label_000045FE;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000460C;
    label_000045FE:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebx) goto label_00004609;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_0000460C;
    label_00004609:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000460C:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x14u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x14u));
    *(uint8_t*)(cpu->eax + 0x14u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebx + 0x14u) = cpu->ecx & 0xFFu;
    label_0000461E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->eax + 0x14u) != (cpu->ebx & 0xFFu)) goto label_00004726;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->ecx + 4u)) goto label_00004723;
    label_00004640:
    if (*(uint8_t*)(cpu->edi + 0x14u) != (cpu->ebx & 0xFFu)) goto label_00004723;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_000046B2;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x14u) != 0u) goto label_0000466A;
    *(uint8_t*)(cpu->eax + 0x14u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404667u)); sfera_sub_00402DB0(cpu, LIFT_CODE_TOKEN_VA(0x404667u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    label_0000466A:
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000046E2;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x14u) != (cpu->ebx & 0xFFu)) goto label_0000467F;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x14u) == (cpu->ebx & 0xFFu)) goto label_000046DE;
    label_0000467F:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x14u) != (cpu->ebx & 0xFFu)) goto label_00004699;
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->eax + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404696u)); sfera_sub_00402E00(cpu, LIFT_CODE_TOKEN_VA(0x404696u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    label_00004699:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x14u));
    *(uint8_t*)(cpu->eax + 0x14u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x14u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4046B0u)); sfera_sub_00402DB0(cpu, LIFT_CODE_TOKEN_VA(0x4046B0u));
    goto label_00004723;
    label_000046B2:
    if (*(uint8_t*)(cpu->eax + 0x14u) != 0u) goto label_000046C9;
    *(uint8_t*)(cpu->eax + 0x14u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4046C7u)); sfera_sub_00402E00(cpu, LIFT_CODE_TOKEN_VA(0x4046C7u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    label_000046C9:
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000046E2;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x14u) != (cpu->ebx & 0xFFu)) goto label_000046F5;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x14u) != (cpu->ebx & 0xFFu)) goto label_000046F5;
    label_000046DE:
    *(uint8_t*)(cpu->eax + 0x14u) = 0u;
    label_000046E2:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->edx + 4u)) goto label_00004640;
    goto label_00004723;
    label_000046F5:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x14u) != (cpu->ebx & 0xFFu)) goto label_0000470D;
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->eax + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40470Bu)); sfera_sub_00402DB0(cpu, LIFT_CODE_TOKEN_VA(0x40470Bu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    label_0000470D:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x14u));
    *(uint8_t*)(cpu->eax + 0x14u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x14u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->edx + 0x14u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4723u)); sfera_sub_00402E00(cpu, LIFT_CODE_TOKEN_RVA(0x4723u));
    label_00004723:
    *(uint8_t*)(cpu->edi + 0x14u) = cpu->ebx & 0xFFu;
    label_00004726:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404730u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x404730u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_00004741;
    --cpu->eax;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    label_00004741:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404750(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[3]; bool sub_pred[1];
    cpu->esp -= 0x18u;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x2Du) == 0u;
    cpu->edx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if (!sub_pred[0]) goto label_0000486B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    goto label_0000479C;
    label_00004790:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    label_0000479C:
    cpu->edi += 0xCu;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_000047A8;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_000047A8:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if (cpu->ebp >= cpu->esi) goto label_000047B1;
    label_000047B1:
    if (cpu->esi >= cpu->ecx) goto label_000047B7;
    cpu->ecx = cpu->esi;
    label_000047B7:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ebx < 0x10u) goto label_000047C3;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000047C5;
    label_000047C3:
    cpu->eax = cpu->edi;
    label_000047C5:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4047CDu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4047CDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_000047E3;
    if (cpu->esi < cpu->ecx) goto label_000047E5;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ecx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_000047E3:
    if (!lift_test[0]) goto label_000047F2;
    label_000047E5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_00004855;
    label_000047F2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_00004847;
    if (cpu->ebx < 0x10u) goto label_00004803;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00004803:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    if (cpu->ecx >= cpu->esi) goto label_00004810;
    cpu->esi = cpu->ecx;
    label_00004810:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebp) goto label_00004818;
    cpu->ecx = cpu->ebp;
    label_00004818:
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_00004821;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004821:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404829u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404829u));
    cpu->esp += 0xCu;
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_0000483B;
    if (cpu->esi < cpu->ebp) goto label_0000483D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebp);
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    label_0000483B:
    if (!lift_test[1]) goto label_00004847;
    label_0000483D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_0000484B;
    label_00004847:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000484B:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_00004855:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_00004790;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000486B:
    if (*(uint8_t*)(cpu->edx + 0x2Du) == 0u) goto label_00004879;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000487B;
    label_00004879:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    label_0000487B:
    if (*(uint8_t*)(cpu->ebx + 0x2Du) != 0u) goto label_000048DE;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    label_00004885:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->eax = cpu->ebx + 0xCu;
    if (*(uint32_t*)(cpu->ebx + 0x20u) < 0x10u) goto label_00004893;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004893:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_000048A0;
    cpu->edx = cpu->edi;
    label_000048A0:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_000048AB;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_000048AD;
    label_000048AB:
    cpu->ecx = cpu->ebp;
    label_000048AD:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4048B5u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4048B5u));
    cpu->esp += 0xCu;
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_000048C7;
    if (cpu->esi < cpu->edi) goto label_000048C9;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    label_000048C7:
    if (!lift_test[2]) goto label_000048D1;
    label_000048C9:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    goto label_000048D4;
    label_000048D1:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    label_000048D4:
    if (*(uint8_t*)(cpu->ebx + 0x2Du) == 0u) goto label_00004885;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000048DE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404900(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x2Du) == 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if (!sub_pred[0]) goto label_0000497D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    label_00004920:
    cpu->eax = cpu->edi + 0xCu;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_0000492E;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00004930;
    label_0000492E:
    cpu->edx = cpu->ebp;
    label_00004930:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_00004939;
    label_00004939:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_00004941;
    cpu->ecx = cpu->ebx;
    label_00004941:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00004949;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004949:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404951u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404951u));
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004963;
    if (cpu->esi < cpu->ebx) goto label_00004965;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00004963:
    if (!lift_test[0]) goto label_0000496A;
    label_00004965:
    cpu->edi = *(uint32_t*)(cpu->edi + 8u);
    goto label_00004970;
    label_0000496A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00004970:
    if (*(uint8_t*)(cpu->edi + 0x2Du) == 0u) goto label_00004920;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0000497D:
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404990(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[3]; bool sub_pred[1];
    cpu->esp -= 0x18u;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x45u) == 0u;
    cpu->edx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if (!sub_pred[0]) goto label_00004AAB;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    goto label_000049DC;
    label_000049D0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    label_000049DC:
    cpu->edi += 0xCu;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_000049E8;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_000049E8:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if (cpu->ebp >= cpu->esi) goto label_000049F1;
    label_000049F1:
    if (cpu->esi >= cpu->ecx) goto label_000049F7;
    cpu->ecx = cpu->esi;
    label_000049F7:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ebx < 0x10u) goto label_00004A03;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00004A05;
    label_00004A03:
    cpu->eax = cpu->edi;
    label_00004A05:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404A0Du)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404A0Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004A23;
    if (cpu->esi < cpu->ecx) goto label_00004A25;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ecx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00004A23:
    if (!lift_test[0]) goto label_00004A32;
    label_00004A25:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_00004A95;
    label_00004A32:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint8_t*)(cpu->eax + 0x45u) == 0u) goto label_00004A87;
    if (cpu->ebx < 0x10u) goto label_00004A43;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00004A43:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    if (cpu->ecx >= cpu->esi) goto label_00004A50;
    cpu->esi = cpu->ecx;
    label_00004A50:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebp) goto label_00004A58;
    cpu->ecx = cpu->ebp;
    label_00004A58:
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_00004A61;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004A61:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404A69u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404A69u));
    cpu->esp += 0xCu;
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004A7B;
    if (cpu->esi < cpu->ebp) goto label_00004A7D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebp);
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    label_00004A7B:
    if (!lift_test[1]) goto label_00004A87;
    label_00004A7D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_00004A8B;
    label_00004A87:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00004A8B:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_00004A95:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edx + 0x45u) == 0u) goto label_000049D0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00004AAB:
    if (*(uint8_t*)(cpu->edx + 0x45u) == 0u) goto label_00004AB9;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    goto label_00004ABB;
    label_00004AB9:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    label_00004ABB:
    if (*(uint8_t*)(cpu->ebx + 0x45u) != 0u) goto label_00004B1E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    label_00004AC5:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->eax = cpu->ebx + 0xCu;
    if (*(uint32_t*)(cpu->ebx + 0x20u) < 0x10u) goto label_00004AD3;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004AD3:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_00004AE0;
    cpu->edx = cpu->edi;
    label_00004AE0:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00004AEB;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_00004AED;
    label_00004AEB:
    cpu->ecx = cpu->ebp;
    label_00004AED:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404AF5u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404AF5u));
    cpu->esp += 0xCu;
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004B07;
    if (cpu->esi < cpu->edi) goto label_00004B09;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    label_00004B07:
    if (!lift_test[2]) goto label_00004B11;
    label_00004B09:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    goto label_00004B14;
    label_00004B11:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    label_00004B14:
    if (*(uint8_t*)(cpu->ebx + 0x45u) == 0u) goto label_00004AC5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00004B1E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404B40(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x45u) == 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if (!sub_pred[0]) goto label_00004BBD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    label_00004B60:
    cpu->eax = cpu->edi + 0xCu;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00004B6E;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00004B70;
    label_00004B6E:
    cpu->edx = cpu->ebp;
    label_00004B70:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_00004B79;
    label_00004B79:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_00004B81;
    cpu->ecx = cpu->ebx;
    label_00004B81:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00004B89;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004B89:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404B91u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404B91u));
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004BA3;
    if (cpu->esi < cpu->ebx) goto label_00004BA5;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00004BA3:
    if (!lift_test[0]) goto label_00004BAA;
    label_00004BA5:
    cpu->edi = *(uint32_t*)(cpu->edi + 8u);
    goto label_00004BB0;
    label_00004BAA:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00004BB0:
    if (*(uint8_t*)(cpu->edi + 0x45u) == 0u) goto label_00004B60;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00004BBD:
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404BD0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[3]; bool sub_pred[1];
    cpu->esp -= 0x18u;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x31u) == 0u;
    cpu->edx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if (!sub_pred[0]) goto label_00004CEB;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    goto label_00004C1C;
    label_00004C10:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    label_00004C1C:
    cpu->edi += 0xCu;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_00004C28;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_00004C28:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if (cpu->ebp >= cpu->esi) goto label_00004C31;
    label_00004C31:
    if (cpu->esi >= cpu->ecx) goto label_00004C37;
    cpu->ecx = cpu->esi;
    label_00004C37:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ebx < 0x10u) goto label_00004C43;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00004C45;
    label_00004C43:
    cpu->eax = cpu->edi;
    label_00004C45:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404C4Du)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404C4Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004C63;
    if (cpu->esi < cpu->ecx) goto label_00004C65;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ecx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00004C63:
    if (!lift_test[0]) goto label_00004C72;
    label_00004C65:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_00004CD5;
    label_00004C72:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint8_t*)(cpu->eax + 0x31u) == 0u) goto label_00004CC7;
    if (cpu->ebx < 0x10u) goto label_00004C83;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00004C83:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    if (cpu->ecx >= cpu->esi) goto label_00004C90;
    cpu->esi = cpu->ecx;
    label_00004C90:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebp) goto label_00004C98;
    cpu->ecx = cpu->ebp;
    label_00004C98:
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_00004CA1;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004CA1:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404CA9u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404CA9u));
    cpu->esp += 0xCu;
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004CBB;
    if (cpu->esi < cpu->ebp) goto label_00004CBD;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebp);
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    label_00004CBB:
    if (!lift_test[1]) goto label_00004CC7;
    label_00004CBD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_00004CCB;
    label_00004CC7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00004CCB:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_00004CD5:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->edx + 0x31u) == 0u) goto label_00004C10;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00004CEB:
    if (*(uint8_t*)(cpu->edx + 0x31u) == 0u) goto label_00004CF9;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    goto label_00004CFB;
    label_00004CF9:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    label_00004CFB:
    if (*(uint8_t*)(cpu->ebx + 0x31u) != 0u) goto label_00004D5E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    label_00004D05:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->eax = cpu->ebx + 0xCu;
    if (*(uint32_t*)(cpu->ebx + 0x20u) < 0x10u) goto label_00004D13;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004D13:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_00004D20;
    cpu->edx = cpu->edi;
    label_00004D20:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00004D2B;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_00004D2D;
    label_00004D2B:
    cpu->ecx = cpu->ebp;
    label_00004D2D:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404D35u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404D35u));
    cpu->esp += 0xCu;
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004D47;
    if (cpu->esi < cpu->edi) goto label_00004D49;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    lift_test[2]=((cpu->eax)&0x80000000u)!=0u;
    label_00004D47:
    if (!lift_test[2]) goto label_00004D51;
    label_00004D49:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    goto label_00004D54;
    label_00004D51:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    label_00004D54:
    if (*(uint8_t*)(cpu->ebx + 0x31u) == 0u) goto label_00004D05;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00004D5E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404D80(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x31u) == 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if (!sub_pred[0]) goto label_00004DFD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    label_00004DA0:
    cpu->eax = cpu->edi + 0xCu;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00004DAE;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00004DB0;
    label_00004DAE:
    cpu->edx = cpu->ebp;
    label_00004DB0:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_00004DB9;
    label_00004DB9:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_00004DC1;
    cpu->ecx = cpu->ebx;
    label_00004DC1:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00004DC9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00004DC9:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404DD1u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x404DD1u));
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00004DE3;
    if (cpu->esi < cpu->ebx) goto label_00004DE5;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebx);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00004DE3:
    if (!lift_test[0]) goto label_00004DEA;
    label_00004DE5:
    cpu->edi = *(uint32_t*)(cpu->edi + 8u);
    goto label_00004DF0;
    label_00004DEA:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_00004DF0:
    if (*(uint8_t*)(cpu->edi + 0x31u) == 0u) goto label_00004DA0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00004DFD:
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404E10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x15u) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if (!sub_pred[0]) goto label_00004E5D;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xCu);
    label_00004E31:
    cpu->esi = cpu->eax;
    if (*(uint8_t*)(cpu->esp + 0x1Cu) == 0u) goto label_00004E42;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((int32_t)(*(uint32_t*)(cpu->eax + 0xCu)) >= (int32_t)(cpu->edx));
    goto label_00004E48;
    label_00004E42:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((int32_t)(cpu->edx) < (int32_t)(*(uint32_t*)(cpu->eax + 0xCu)));
    label_00004E48:
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_00004E54;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_00004E57;
    label_00004E54:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_00004E57:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00004E31;
    label_00004E5D:
    cpu->edi = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_00004E9A;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = cpu->esp + 0x1Cu;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_00004E91;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404E7Eu)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x404E7Eu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00004E91:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404E96u)); sfera_sub_004025A0(cpu, LIFT_CODE_TOKEN_VA(0x404E96u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00004E9A:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ebx + 0xCu)) goto label_00004EC8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404EB5u)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x404EB5u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00004EC8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x404ECDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x404ECDu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404EF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00004F20;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x15555554u;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00004F18;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x404EF0u), "std::length_error");
    label_00004F18:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00004F20:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404F80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00004FB0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0xFFFFFFEu;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00004FA8;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x404F80u), "std::length_error");
    label_00004FA8:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00004FB0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_00005046;
    lift_push32(cpu, cpu->edi);
    label_00005020:
    if (cpu->eax == 0u) goto label_0000503B;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    *(uint32_t*)(cpu->ecx) = 0u;
    label_0000503B:
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if (cpu->ecx != cpu->edx) goto label_00005020;
    cpu->edi = lift_pop32(cpu);
    label_00005046:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405050(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->edx == 0u) goto label_0000506F;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    label_00005060:
    if (cpu->ecx == 0u) goto label_00005068;
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    label_00005068:
    cpu->ecx += 4u;
    if ((--cpu->edx) != 0u) goto label_00005060;
    cpu->esi = lift_pop32(cpu);
    label_0000506F:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_000050A3;
    lift_push32(cpu, cpu->esi);
    label_00005090:
    if (cpu->eax == 0u) goto label_00005098;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    label_00005098:
    cpu->ecx += 4u;
    cpu->eax += 4u;
    if (cpu->ecx != cpu->edx) goto label_00005090;
    cpu->esi = lift_pop32(cpu);
    label_000050A3:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004050B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4050BAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4050BAu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000050EB;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_000050E5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    label_000050E5:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000050EB:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405119u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x405119u));
    lift_trap(cpu, 0x405119u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00405120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40512Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40512Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0000515B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_00005155;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(float*)(cpu->ecx + 4u) = (double)*(float*)(cpu->edx + 4u);
    cpu->esi = lift_pop32(cpu);
    label_00005155:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000515B:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405189u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x405189u));
    lift_trap(cpu, 0x405189u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00405190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40519Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40519Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000051DF;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == 0u) goto label_000051D9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 8u) = 0u;
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    cpu->edi = lift_pop32(cpu);
    label_000051D9:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000051DF:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40520Du)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40520Du));
    lift_trap(cpu, 0x40520Du, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00405210(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->esi = cpu->ecx;
    if (cpu->edi >= cpu->ebx) goto label_00005230;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x405210u), "std::out_of_range");
    label_00005230:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi -= cpu->ebx;
    if (cpu->eax >= cpu->edi) goto label_0000523C;
    cpu->edi = cpu->eax;
    label_0000523C:
    if (cpu->esi != cpu->ebp) goto label_0000525D;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->edi += cpu->ebx;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40524Au)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x40524Au));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405254u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x405254u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000525D:
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0000526D;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40525Du), "std::length_error");
    label_0000526D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->edi) goto label_00005291;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40527Eu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x40527Eu));
    if (cpu->edi == 0u) goto label_000052EF;
    label_00005282:
    cpu->eax = 0x10u;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->eax) goto label_000052B7;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_000052B9;
    label_00005291:
    if (cpu->edi != 0u) goto label_00005282;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->eax < 0x10u) goto label_000052AB;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000052AB:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000052B7:
    cpu->ecx = cpu->ebp;
    label_000052B9:
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->eax) goto label_000052C2;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000052C4;
    label_000052C2:
    cpu->eax = cpu->esi;
    label_000052C4:
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4052C9u));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_000052E9;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000052E9:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_000052EF:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == cpu->ecx) goto label_0000532E;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    label_00005310:
    if (cpu->edx == cpu->esi) goto label_0000531B;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_00005310;
    label_0000531B:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_0000532E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000532E:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == cpu->ecx) goto label_00005379;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_00005352:
    if (cpu->edx == cpu->esi) goto label_0000535D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_00005352;
    label_0000535D:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_00005379;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005379:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == cpu->ecx) goto label_000053AE;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    label_00005390:
    if (cpu->edx == cpu->esi) goto label_0000539B;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_00005390;
    label_0000539B:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_000053AE;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->eax + 8u) = (double)*(float*)(cpu->ecx);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000053AE:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004053C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == cpu->ecx) goto label_000053F8;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000053D2:
    if (cpu->edx == cpu->esi) goto label_000053DD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_000053D2;
    label_000053DD:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_000053F8;
    x87_v0 = (double)*(float*)(cpu->eax + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000053F8:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == cpu->ecx) goto label_00005433;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_00005412:
    if (cpu->edx == cpu->esi) goto label_0000541D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_00005412;
    label_0000541D:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_00005433;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40542Eu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x40542Eu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005433:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->esi);
    if (cpu->eax == cpu->ecx) goto label_000054A4;
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    label_00005450:
    if (cpu->edx == cpu->esi) goto label_0000545B;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_00005450;
    label_0000545B:
    if (cpu->eax == cpu->ecx) goto label_000054A4;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax + 8u;
    if (cpu->esi == cpu->edi) goto label_0000549D;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40547Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40547Au));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405483u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x405483u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_0000549D:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000054A4:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004054B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == cpu->ecx) goto label_000054E3;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000054C2:
    if (cpu->edx == cpu->esi) goto label_000054CD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_000054C2;
    label_000054CD:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_000054E3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4054DEu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x4054DEu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000054E3:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004054F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->eax < 0) goto label_00005571;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->eax >= cpu->ecx) goto label_00005571;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 8u) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_0000551A;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    goto label_0000551E;
    label_0000551A:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    label_0000551E:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx = cpu->eax + 4u;
    cpu->edx -= cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x405536u));
    *(uint32_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x14u)) + (uint64_t)(0xFFFFFFFCu) + (uint64_t)(0u);
    cpu->esp += 0xCu;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_0000556A;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->edi >= cpu->eax) goto label_00005566;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = cpu->ecx + (cpu->edi * 4u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00005566:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_0000556A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00005571:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405580(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    if ((int32_t)cpu->ecx < 0) goto label_000055EE;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->ecx >= cpu->eax) goto label_000055EE;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 8u) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_000055A4;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x10u);
    goto label_000055A8;
    label_000055A4:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    label_000055A8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->eax += cpu->ecx;
    cpu->ecx = cpu->eax + 1u;
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4055B8u));
    --*(uint32_t*)(cpu->esi + 0x14u);
    cpu->esp += 0xCu;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000055E7;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->edi >= cpu->eax) goto label_000055E3;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000055E3:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000055E7:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000055EE:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405600(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405615u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x405615u));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = 0u;
    sub_pred[0] = cpu->edx == *(uint32_t*)(cpu->esi + 0x14u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (!sub_pred[0]);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405630(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00005630;
    label_00003E90:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp <= 0xFFFFFFFFu) goto label_00003EA8;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x403E90u), "std::length_error");
    label_00003EA8:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax -= *(uint32_t*)(cpu->esi);
    if (cpu->eax >= cpu->ebp) goto label_00003EF4;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403EBCu)); sfera_sub_004028A0(cpu, LIFT_CODE_TOKEN_VA(0x403EBCu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x403EC8u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esp += 0xCu;
    cpu->ebx -= cpu->eax;
    if (cpu->eax == 0u) goto label_00003EE5;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x403EE2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x403EE2u));
    cpu->esp += 4u;
    label_00003EE5:
    cpu->ebx += cpu->edi;
    cpu->edx = cpu->edi + cpu->ebp;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    label_00003EF4:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00005630:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->eax -= cpu->esi;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_00005651;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x405630u), "std::length_error");
    label_00005651:
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx -= cpu->esi;
    if (cpu->eax <= cpu->edx) goto label_00005680;
    cpu->esi = cpu->edx;
    cpu->esi >>= 1u;
    cpu->edi |= 0xFFFFFFFFu;
    cpu->edi -= cpu->esi;
    if (cpu->edi >= cpu->edx) goto label_0000566D;
    cpu->edx = 0u;
    goto label_0000566F;
    label_0000566D:
    cpu->edx += cpu->esi;
    label_0000566F:
    if (cpu->edx >= cpu->eax) goto label_00005675;
    cpu->edx = cpu->eax;
    label_00005675:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    goto label_00003E90;
    label_00005680:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405770(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->ecx -= 3u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (cpu->ecx == 0u) goto label_000057B3;
    if ((--cpu->ecx) == 0u) goto label_00005795;
    if ((--cpu->ecx) == 0u) goto label_00005787;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005787:
    cpu->ecx = 0u;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (sub_pred[0]);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005795:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40579Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40579Au));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000057F2;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4057ABu)); sfera_sub_00404230(cpu, LIFT_CODE_TOKEN_VA(0x4057ABu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000057B3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4057B8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4057B8u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000057F2;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    sub_pred[1] = cpu->edx == cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    cpu->edi = lift_pop32(cpu);
    if (sub_pred[1]) goto label_000057E5;
    cpu->edx += 8u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4057D9u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x4057D9u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000057E5:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000057F2:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405800(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->ecx -= 3u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (cpu->ecx == 0u) goto label_00005843;
    if ((--cpu->ecx) == 0u) goto label_00005825;
    if ((--cpu->ecx) == 0u) goto label_00005817;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005817:
    cpu->ecx = 0u;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (sub_pred[0]);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005825:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40582Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40582Au));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00005882;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40583Bu)); sfera_sub_00404270(cpu, LIFT_CODE_TOKEN_VA(0x40583Bu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005843:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405848u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x405848u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00005882;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    sub_pred[1] = cpu->edx == cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    cpu->edi = lift_pop32(cpu);
    if (sub_pred[1]) goto label_00005875;
    cpu->edx += 8u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405869u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x405869u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005875:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005882:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405A00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->ecx -= 3u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (cpu->ecx == 0u) goto label_00005A43;
    if ((--cpu->ecx) == 0u) goto label_00005A25;
    if ((--cpu->ecx) == 0u) goto label_00005A17;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A17:
    cpu->ecx = 0u;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (sub_pred[0]);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A25:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405A2Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x405A2Au));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00005A7C;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405A3Bu)); sfera_sub_00404370(cpu, LIFT_CODE_TOKEN_VA(0x405A3Bu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A43:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405A48u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x405A48u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00005A7C;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edx;
    if (cpu->edx == *(uint32_t*)(cpu->esi + 0x14u)) goto label_00005A6F;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405A63u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405A63u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A6F:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A7C:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405A80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->ecx -= 3u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (cpu->ecx == 0u) goto label_00005AC3;
    if ((--cpu->ecx) == 0u) goto label_00005AA5;
    if ((--cpu->ecx) == 0u) goto label_00005A97;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A97:
    cpu->ecx = 0u;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (sub_pred[0]);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AA5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405AAAu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x405AAAu));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00005AFC;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405ABBu)); sfera_sub_004043B0(cpu, LIFT_CODE_TOKEN_VA(0x405ABBu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AC3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405AC8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x405AC8u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00005AFC;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edx;
    if (cpu->edx == *(uint32_t*)(cpu->esi + 0x14u)) goto label_00005AEF;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405AE3u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x405AE3u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AEF:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AFC:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_00005B3E;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x10u);
    *(uint32_t*)(cpu->esi + cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005B3E:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405B50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00005B60;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005B60:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405B69u)); sfera_sub_00402220(cpu, LIFT_CODE_TOKEN_VA(0x405B69u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00005BA2;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x10u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005BA2:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00005BEA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405BCBu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405BCBu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x28u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005BEA:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405C00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00005C10;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005C10:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405C19u)); sfera_sub_004022D0(cpu, LIFT_CODE_TOKEN_VA(0x405C19u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00005C4D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405C2Du)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405C2Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x28u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005C4D:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405C60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_00005C9E;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    x87_v0 = (double)*(float*)(cpu->edx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->eax) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005C9E:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405CB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00005CC0;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005CC0:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405CC9u)); sfera_sub_00402220(cpu, LIFT_CODE_TOKEN_VA(0x405CC9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00005D03;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->edx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005D03:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405D10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00005D49;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405D2Bu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405D2Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005D49:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405D60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00005D70;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005D70:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405D79u)); sfera_sub_004022D0(cpu, LIFT_CODE_TOKEN_VA(0x405D79u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00005DAC;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405D8Du)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405D8Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005DAC:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405DC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00005DFA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405DF0u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405DF0u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005DFA:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405E10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00005E20;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005E20:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405E29u)); sfera_sub_004022D0(cpu, LIFT_CODE_TOKEN_VA(0x405E29u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00005E5D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405E52u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405E52u));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005E5D:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405E70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00005EA4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405E8Bu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405E8Bu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405E9Au)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405E9Au));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005EA4:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405EB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00005EC0;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005EC0:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405EC9u)); sfera_sub_00402360(cpu, LIFT_CODE_TOKEN_VA(0x405EC9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00005EF7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405EDDu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405EDDu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405EECu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405EECu));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005EF7:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405F10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00005F4A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405F40u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x405F40u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005F4A:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405F60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00005F70;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005F70:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405F79u)); sfera_sub_004023F0(cpu, LIFT_CODE_TOKEN_VA(0x405F79u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00005FAD;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405FA2u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x405FA2u));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005FAD:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405FC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00005FF4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405FDBu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x405FDBu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405FEAu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x405FEAu));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00005FF4:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) != 0u) goto label_00006010;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006010:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406019u)); sfera_sub_00402480(cpu, LIFT_CODE_TOKEN_VA(0x406019u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00006047;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40602Du)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x40602Du));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40603Cu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x40603Cu));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006047:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406060(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x15u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (!sub_pred[0]) goto label_0000608A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    label_00006075:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->esi) goto label_0000607F;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_00006083;
    label_0000607F:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00006083:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00006075;
    cpu->esi = lift_pop32(cpu);
    label_0000608A:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->edx == cpu->eax) goto label_000060AD;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->edx + 0xCu)) goto label_000060AD;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000060AD:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004060D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x2Du) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (!sub_pred[0]) goto label_000060FA;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    label_000060E5:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->esi) goto label_000060EF;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_000060F3;
    label_000060EF:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000060F3:
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_000060E5;
    cpu->esi = lift_pop32(cpu);
    label_000060FA:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->edx == cpu->eax) goto label_0000611D;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->edx + 0xCu)) goto label_0000611D;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000611D:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406140(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x19u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (!sub_pred[0]) goto label_0000616A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    label_00006155:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->esi) goto label_0000615F;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_00006163;
    label_0000615F:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00006163:
    if (*(uint8_t*)(cpu->eax + 0x19u) == 0u) goto label_00006155;
    cpu->esi = lift_pop32(cpu);
    label_0000616A:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->edx == cpu->eax) goto label_0000618D;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->edx + 0xCu)) goto label_0000618D;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000618D:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004061B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000061C4;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4061C1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4061C1u));
    cpu->esp += 4u;
    label_000061C4:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406210(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x30u) < 0x10u) goto label_00006225;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406222u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x406222u));
    cpu->esp += 4u;
    label_00006225:
    *(uint32_t*)(cpu->esi + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x2Cu) = 0u;
    *(uint8_t*)(cpu->esi + 0x1Cu) = 0u;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_00006248;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406245u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x406245u));
    cpu->esp += 4u;
    label_00006248:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406340(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000636E;
    if (cpu->edx != cpu->eax) goto label_0000636E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40635Eu)); sfera_sub_00429A30(cpu, LIFT_CODE_TOKEN_VA(0x40635Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000636E:
    if (cpu->ecx == cpu->edx) goto label_000063DF;
    label_00006372:
    cpu->edx = cpu->ecx;
    if (*(uint8_t*)(cpu->ecx + 0x15u) != 0u) goto label_000063C8;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000063A0;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_0000639A;
    label_00006390:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00006390;
    label_0000639A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_000063C8;
    label_000063A0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000063C4;
    label_000063B0:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_000063C4;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_000063B0;
    label_000063C4:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000063C8:
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4063D5u)); sfera_sub_00404510(cpu, LIFT_CODE_TOKEN_VA(0x4063D5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_00006372;
    label_000063DF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004063F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->ecx == cpu->edi) goto label_0000642A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 4u;
    label_00006400:
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_0000641F;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406414u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x406414u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40641Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40641Cu));
    cpu->esp += 4u;
    label_0000641F:
    cpu->esi += 8u;
    cpu->ecx = cpu->esi + 0xFFFFFFFCu;
    if (cpu->ecx != cpu->edi) goto label_00006400;
    cpu->esi = lift_pop32(cpu);
    label_0000642A:
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406430(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 8u) == 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (!sub_pred[0]) goto label_0000645C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406452u)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x406452u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000645C:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if (cpu->ebx != *(uint32_t*)(cpu->eax)) goto label_0000648E;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->ebx + 0xCu)) goto label_0000656D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406482u)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x406482u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000648E:
    if (cpu->ebx != cpu->eax) goto label_000064BB;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->edi + 0xCu)) goto label_0000656D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4064AFu)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x4064AFu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000064BB:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0xCu);
    sub_pred[3] = (int32_t)(*(uint32_t*)(cpu->ebx + 0xCu)) < (int32_t)(cpu->ebp);
    if ((*(uint32_t*)(cpu->ebx + 0xCu) == cpu->ebp) || ((int32_t)(*(uint32_t*)(cpu->ebx + 0xCu)) < (int32_t)(cpu->ebp))) goto label_00006516;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4064D0u)); sfera_sub_004025A0(cpu, LIFT_CODE_TOKEN_VA(0x4064D0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->ebp) goto label_00006513;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    sub_pred[1] = *(uint8_t*)(cpu->ecx + 0x15u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if (sub_pred[1]) goto label_000064FE;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4064F2u)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x4064F2u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000064FE:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406507u)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x406507u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00006513:
    sub_pred[3] = (int32_t)(*(uint32_t*)(cpu->ebx + 0xCu)) < (int32_t)(cpu->ebp);
    label_00006516:
    if (!sub_pred[3]) goto label_0000656D;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406525u)); sfera_sub_00402220(cpu, LIFT_CODE_TOKEN_VA(0x406525u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_00006533;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_0000656D;
    label_00006533:
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    sub_pred[2] = *(uint8_t*)(cpu->edx + 0x15u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if (sub_pred[2]) goto label_00006558;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40654Cu)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x40654Cu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00006558:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406561u)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x406561u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000656D:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40657Cu)); sfera_sub_00404E10(cpu, LIFT_CODE_TOKEN_VA(0x40657Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x18u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40659Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40659Du));
    cpu->edx = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->edx) goto label_000065D7;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->eax + 0xCu;
    *(uint16_t*)(cpu->eax + 0x14u) = cpu->edx & 0xFFFFu;
    if (cpu->ecx == cpu->edx) goto label_000065D0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(float*)(cpu->ecx + 4u) = (double)*(float*)(cpu->edx + 4u);
    label_000065D0:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000065D7:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 8u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406601u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x406601u));
    lift_trap(cpu, 0x406601u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00406610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1Cu);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40661Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40661Eu));
    cpu->ebx = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00006665;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->eax + 0xCu;
    *(uint16_t*)(cpu->eax + 0x18u) = cpu->ebx & 0xFFFFu;
    if (cpu->ecx == cpu->ebx) goto label_0000665D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebx;
    label_0000665D:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00006665:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40668Fu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40668Fu));
    lift_trap(cpu, 0x40668Fu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00406690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40669Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40669Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000066DE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == 0u) goto label_000066D8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    *(uint32_t*)(cpu->ecx) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    label_000066D8:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000066DE:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40670Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40670Cu));
    lift_trap(cpu, 0x40670Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00406710(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40671Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40671Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0000675E;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == 0u) goto label_00006758;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    *(uint32_t*)(cpu->ecx) = 0u;
    *(float*)(cpu->edx + 8u) = x87_v0; 
    cpu->edi = lift_pop32(cpu);
    label_00006758:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000675E:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40678Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40678Cu));
    lift_trap(cpu, 0x40678Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00406790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40679Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40679Bu));
    cpu->esi = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->esi) goto label_000067E6;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == cpu->esi) goto label_000067DF;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->esi;
    cpu->edi = lift_pop32(cpu);
    label_000067DF:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000067E6:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406810u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x406810u));
    lift_trap(cpu, 0x406810u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00406820(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sfera_prepare_msvc_string_storage(cpu->esi);
    if (cpu->ebx == 0u) goto label_00006885;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_00006838;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0000683A;
    label_00006838:
    cpu->eax = cpu->esi;
    label_0000683A:
    if (cpu->ebx < cpu->eax) goto label_00006885;
    if (cpu->ecx < 0x10u) goto label_00006847;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_00006849;
    label_00006847:
    cpu->eax = cpu->esi;
    label_00006849:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx += cpu->eax;
    if (cpu->edx <= cpu->ebx) goto label_00006885;
    if (cpu->ecx < 0x10u) goto label_0000686E;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406869u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x406869u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000686E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ebx -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406880u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x406880u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006885:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0000689A;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x406885u), "std::length_error");
    label_0000689A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->edi) goto label_000068BB;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4068ADu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x4068ADu));
    if (cpu->edi == 0u) goto label_00006909;
    label_000068B1:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000068DF;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000068E1;
    label_000068BB:
    if (cpu->edi != 0u) goto label_000068B1;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->eax < 0x10u) goto label_000068D4;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000068D4:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000068DF:
    cpu->eax = cpu->esi;
    label_000068E1:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4068E4u));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_00006903;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006903:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_00006909:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406939u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x406939u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00006953;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x406920u), "std::length_error");
    label_00006953:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40698Bu)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x40698Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000069A5;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x406970u), "std::length_error");
    label_000069A5:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004069C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = 0u;
    if (cpu->eax == cpu->edx) goto label_00006A24;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    label_000069D3:
    if (cpu->ecx == cpu->edi) goto label_000069DE;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->ecx;
    if (cpu->eax != cpu->edx) goto label_000069D3;
    label_000069DE:
    cpu->edi = lift_pop32(cpu);
    if (cpu->eax == cpu->edx) goto label_00006A24;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000069FE;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) != cpu->eax) goto label_000069FE;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ecx;
    if (cpu->ecx != cpu->edx) goto label_000069FE;
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000069FE:
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x10u)) goto label_00006A1E;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406A18u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x406A18u));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 0x14u);
    label_00006A1E:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00006A24:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406A49u)); sfera_sub_004036B0(cpu, LIFT_CODE_TOKEN_VA(0x406A49u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00006A63;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x406A30u), "std::length_error");
    label_00006A63:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406A9Bu)); sfera_sub_004036B0(cpu, LIFT_CODE_TOKEN_VA(0x406A9Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00006AB5;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x406A80u), "std::length_error");
    label_00006AB5:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406AE9u)); sfera_sub_00403720(cpu, LIFT_CODE_TOKEN_VA(0x406AE9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00006B03;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x406AD0u), "std::length_error");
    label_00006B03:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406B3Bu)); sfera_sub_00403720(cpu, LIFT_CODE_TOKEN_VA(0x406B3Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00006B55;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x406B20u), "std::length_error");
    label_00006B55:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x10u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406B85u)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x406B85u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406B92u)); sfera_sub_004043F0(cpu, LIFT_CODE_TOKEN_VA(0x406B92u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406BA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_00006BFD;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0xCu) == 0u) goto label_00006BE2;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406BD6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x406BD6u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406BDFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x406BDFu));
    cpu->esp += 4u;
    label_00006BE2:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406BE8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x406BE8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006BFD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406C10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi >= cpu->eax) goto label_00006C4F;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx > cpu->edi) goto label_00006C4F;
    cpu->edi -= cpu->ecx;
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_00006C38;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C38u)); sfera_sub_004BDE90(cpu, LIFT_CODE_TOKEN_RVA(0x6C38u));
    label_00006C38:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_00006C68;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->edi * 4u));
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->eax) = x87_v0; 
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00006C4F:
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_00006C5D;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C5Du)); sfera_sub_004BDE90(cpu, LIFT_CODE_TOKEN_RVA(0x6C5Du));
    label_00006C5D:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_00006C68;
    *(float*)(cpu->eax) = (double)*(float*)(cpu->edi);
    label_00006C68:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406C80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi >= cpu->eax) goto label_00006CBB;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx > cpu->edi) goto label_00006CBB;
    cpu->edi -= cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_00006CA5;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CA5u)); sfera_sub_00405630(cpu, LIFT_CODE_TOKEN_RVA(0x6CA5u));
    label_00006CA5:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_00006CD4;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + cpu->ecx));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++*(uint32_t*)(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00006CBB:
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_00006CC9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CC9u)); sfera_sub_00405630(cpu, LIFT_CODE_TOKEN_RVA(0x6CC9u));
    label_00006CC9:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_00006CD4;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    label_00006CD4:
    ++*(uint32_t*)(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406CE0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406CF5u)); sfera_sub_00406060(cpu, LIFT_CODE_TOKEN_VA(0x406CF5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00006D15;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006D15:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406D20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406D35u)); sfera_sub_00406060(cpu, LIFT_CODE_TOKEN_VA(0x406D35u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00006D56;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006D56:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406D60(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406D75u)); sfera_sub_004060D0(cpu, LIFT_CODE_TOKEN_VA(0x406D75u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00006D90;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406D8Bu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x406D8Bu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006D90:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406DA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406DB5u)); sfera_sub_00406140(cpu, LIFT_CODE_TOKEN_VA(0x406DB5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00006DD0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406DCBu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x406DCBu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006DD0:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_00006E1E;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    *(uint32_t*)(cpu->esi + cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006E1E:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406E30(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_00006E7B;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->edx;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x18u)) goto label_00006E77;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    *(uint32_t*)(cpu->esi + cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006E77:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_00006E7B:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406E90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00006ECA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406EABu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x406EABu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006ECA:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406EE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00006F26;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00006F22;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406F04u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x406F04u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006F22:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00006F26:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406F30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00006F6A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406F4Bu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x406F4Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006F6A:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406F80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00006FC6;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00006FC2;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406FA4u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x406FA4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x10u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006FC2:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00006FC6:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406FE0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_0000701E;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    x87_v0 = (double)*(float*)(cpu->edx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->eax) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000701E:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407030(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_0000707B;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->edx;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x18u)) goto label_00007077;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    x87_v0 = (double)*(float*)(cpu->edx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->eax) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007077:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_0000707B:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407090(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000070C9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4070ABu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x4070ABu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000070C9:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004070E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007127;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00007123;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407104u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x407104u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->edx + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007123:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007127:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407130(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00007169;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40714Bu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x40714Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007169:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407180(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000071C7;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_000071C3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4071A4u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x4071A4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->edx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000071C3:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000071C7:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004071D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_0000720A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407200u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x407200u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000720A:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007266;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00007262;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407258u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x407258u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007262:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007266:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000072A4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40728Bu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x40728Bu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40729Au)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x40729Au));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000072A4:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004072B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000072F1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_000072ED;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4072D4u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x4072D4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4072E3u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x4072E3u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000072ED:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000072F1:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00007334;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40731Bu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x40731Bu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40732Au)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x40732Au));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007334:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407340(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007381;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_0000737D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407364u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x407364u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407373u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x407373u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000737D:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007381:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000073CA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4073C0u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x4073C0u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000073CA:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004073E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007426;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00007422;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407418u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x407418u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007422:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007426:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407430(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00007464;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40744Bu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x40744Bu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40745Au)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x40745Au));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007464:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000074B1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_000074AD;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407494u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x407494u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4074A3u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x4074A3u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000074AD:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000074B1:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004074C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000074F4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4074DBu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x4074DBu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4074EAu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x4074EAu));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000074F4:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407500(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007541;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_0000753D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407524u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x407524u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407533u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x407533u));
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000753D:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007541:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407550(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x407562u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_00007581;
    cpu->edx += 0x7FFFFFFFu;
    label_00007581:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_00007596;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007596:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    cpu->eax = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_000075A8:
    if (cpu->edi != cpu->esi) goto label_000075B0;
    cpu->ecx = cpu->esi;
    goto label_000075B5;
    label_000075B0:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000075B5:
    if (cpu->eax == cpu->ecx) goto label_000075F6;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx == *(uint32_t*)(cpu->ebx)) goto label_000075C4;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_000075A8;
    label_000075C4:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebx) == cpu->ecx) goto label_000075E3;
    cpu->eax = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000075E3:
    cpu->eax = cpu->esp + 0x18u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000075F6:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407610(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->esi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_00007640;
    label_00007630:
    cpu->edi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->edi;
    if (cpu->eax != cpu->edx) goto label_00007630;
    label_00007640:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    if (*(uint32_t*)(cpu->ecx + 0x24u) > cpu->eax) goto label_00007655;
    cpu->edx >>= 1u;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_00007655:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->edx + (cpu->eax * 8u));
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = cpu->edx + (cpu->eax * 8u);
    cpu->esi = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_00007667:
    if (cpu->ebp != cpu->edi) goto label_0000766F;
    cpu->eax = cpu->edi;
    goto label_00007674;
    label_0000766F:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007674:
    if (cpu->esi == cpu->eax) goto label_000076CE;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407685u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x407685u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000768D;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_00007667;
    label_0000768D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->esi += 8u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40769Eu)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40769Eu));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000076BA;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0x18u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000076BA:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0xCu;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000076CE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004076E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_00007711;
    label_00007701:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_00007701;
    label_00007711:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->edi + 0x24u) > cpu->eax) goto label_00007726;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007726:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = cpu->ecx + (cpu->eax * 8u);
    cpu->esi = cpu->ebp;
    label_00007734:
    if (cpu->ebp != cpu->edi) goto label_0000773C;
    cpu->eax = cpu->edi;
    goto label_00007741;
    label_0000773C:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_00007741:
    if (cpu->esi == cpu->eax) goto label_000077A1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407752u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x407752u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000775A;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_00007734;
    label_0000775A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_00007760:
    if (cpu->ebp != cpu->edi) goto label_00007768;
    cpu->eax = cpu->edi;
    goto label_0000776D;
    label_00007768:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    label_0000776D:
    if (cpu->esi == cpu->eax) goto label_00007786;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esi + 8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40777Eu)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40777Eu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00007786;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_00007760;
    label_00007786:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx == cpu->esi) goto label_000077A1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000077A1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004077C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x4077D3u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_000077F2;
    cpu->edx += 0x7FFFFFFFu;
    label_000077F2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_00007807;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007807:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = cpu->ebx;
    label_00007815:
    if (cpu->ebx != cpu->edx) goto label_0000781D;
    cpu->eax = cpu->edx;
    goto label_00007822;
    label_0000781D:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007822:
    if (cpu->ecx == cpu->eax) goto label_00007872;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->eax == *(uint32_t*)(cpu->ebp)) goto label_00007832;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    goto label_00007815;
    label_00007832:
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_00007840:
    if (cpu->ebx != cpu->edx) goto label_00007848;
    cpu->eax = cpu->edx;
    goto label_0000784D;
    label_00007848:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000784D:
    if (cpu->ecx == cpu->eax) goto label_0000785A;
    if (cpu->ebp != *(uint32_t*)(cpu->ecx + 8u)) goto label_0000785A;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    goto label_00007840;
    label_0000785A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->edx == cpu->ecx) goto label_00007872;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007872:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4078A6u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x4078A6u));
    cpu->eax &= cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_000078B6;
    cpu->edi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->edi;
    cpu->eax += cpu->ecx;
    label_000078B6:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->eax * 8u));
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->esi = 0x10u;
    label_000078E0:
    if (cpu->ecx != cpu->edi) goto label_000078E8;
    cpu->eax = cpu->edi;
    goto label_000078ED;
    label_000078E8:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000078ED:
    if (cpu->edx == cpu->eax) goto label_000079CD;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->edx + 8u;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->esi) goto label_00007905;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00007907;
    label_00007905:
    cpu->edx = cpu->ebp;
    label_00007907:
    cpu->edi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->edi;
    if (cpu->ecx >= cpu->edi) goto label_00007910;
    label_00007910:
    cpu->ecx = cpu->edi;
    if (cpu->edi < cpu->ebx) goto label_00007918;
    cpu->ecx = cpu->ebx;
    label_00007918:
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_0000791F;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000791F:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407927u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x407927u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000793B;
    if (cpu->edi < cpu->ebx) goto label_0000793B;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != cpu->ebx);
    if (cpu->eax == 0u) goto label_00007953;
    label_0000793B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    goto label_000078E0;
    label_00007953:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x18u);
    cpu->eax += 8u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_00007964;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007964:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->edi;
    if (cpu->edi < cpu->ebx) goto label_00007971;
    cpu->edx = cpu->ebx;
    label_00007971:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->esi) goto label_0000797B;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_0000797D;
    label_0000797B:
    cpu->ecx = cpu->ebp;
    label_0000797D:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407985u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x407985u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_00007999;
    if (cpu->edi < cpu->ebx) goto label_00007999;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != cpu->ebx);
    if (cpu->eax == 0u) goto label_000079B7;
    label_00007999:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0x14u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000079B7:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0x20u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000079CD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004079E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x20u);
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4079FAu)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x4079FAu));
    cpu->eax &= cpu->esi;
    if (*(uint32_t*)(cpu->edi + 0x24u) > cpu->eax) goto label_00007A0A;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->eax += cpu->ecx;
    label_00007A0A:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->eax * 8u));
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    label_00007A28:
    if (cpu->ecx != cpu->edx) goto label_00007A30;
    cpu->eax = cpu->edx;
    goto label_00007A35;
    label_00007A30:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007A35:
    if (cpu->ebx == cpu->eax) goto label_00007BB0;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebx + 8u;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00007A4E;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00007A50;
    label_00007A4E:
    cpu->edx = cpu->ebp;
    label_00007A50:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_00007A59;
    label_00007A59:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_00007A61;
    cpu->ecx = cpu->edi;
    label_00007A61:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00007A69;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007A69:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407A71u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x407A71u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_00007A85;
    if (cpu->esi < cpu->edi) goto label_00007A85;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    if (cpu->eax == 0u) goto label_00007A9F;
    label_00007A85:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_00007A28;
    label_00007A9F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    label_00007AB0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint32_t*)(cpu->esp + 0x18u) == cpu->eax) goto label_00007AC3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_00007AC3:
    if (cpu->ebx == cpu->eax) goto label_00007B91;
    cpu->eax = cpu->ebx + 8u;
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_00007ADD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007ADD:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    if (cpu->ecx >= cpu->edi) goto label_00007AE6;
    cpu->edi = cpu->ecx;
    label_00007AE6:
    cpu->edx = cpu->edi;
    if (cpu->edi < cpu->ebx) goto label_00007AEE;
    cpu->edx = cpu->ebx;
    label_00007AEE:
    if (*(uint32_t*)(cpu->esp + 0x24u) < cpu->esi) goto label_00007AF9;
    cpu->esi = *(uint32_t*)(cpu->ebp);
    goto label_00007AFB;
    label_00007AF9:
    cpu->esi = cpu->ebp;
    label_00007AFB:
    cpu->ecx = cpu->eax;
    if (cpu->edx < 4u) goto label_00007B16;
    label_00007B02:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_00007B1A;
    cpu->edx -= 4u;
    cpu->ecx += 4u;
    cpu->esi += 4u;
    if (cpu->edx >= 4u) goto label_00007B02;
    label_00007B16:
    if (cpu->edx == 0u) goto label_00007B65;
    label_00007B1A:
    cpu->ebp = *(uint8_t*)(cpu->ecx);
    cpu->eax = *(uint8_t*)(cpu->esi);
    if ((cpu->eax -= cpu->ebp) != 0u) goto label_00007B55;
    if (cpu->edx <= 1u) goto label_00007B61;
    cpu->eax = *(uint8_t*)(cpu->esi + 1u);
    cpu->ebp = *(uint8_t*)(cpu->ecx + 1u);
    if ((cpu->eax -= cpu->ebp) != 0u) goto label_00007B55;
    if (cpu->edx <= 2u) goto label_00007B61;
    cpu->eax = *(uint8_t*)(cpu->esi + 2u);
    cpu->ebp = *(uint8_t*)(cpu->ecx + 2u);
    if ((cpu->eax -= cpu->ebp) != 0u) goto label_00007B55;
    if (cpu->edx <= 3u) goto label_00007B61;
    cpu->eax = *(uint8_t*)(cpu->esi + 3u);
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->eax -= cpu->ecx;
    label_00007B55:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->eax |= 1u;
    goto label_00007B67;
    label_00007B61:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    label_00007B65:
    cpu->eax = 0u;
    label_00007B67:
    if (cpu->eax != 0u) goto label_00007B8D;
    if (cpu->edi < cpu->ebx) goto label_00007B8D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != cpu->ebx);
    if (cpu->eax != 0u) goto label_00007B8D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ebx = cpu->eax;
    goto label_00007AB0;
    label_00007B8D:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00007B91:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ecx == cpu->ebx) goto label_00007BAC;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007BAC:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_00007BB0:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x407BE1u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_00007C00;
    cpu->edx += 0x7FFFFFFFu;
    label_00007C00:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->ecx) goto label_00007C15;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ecx += cpu->edx;
    label_00007C15:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = cpu->eax + (cpu->ecx * 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->edx + 4u) != cpu->eax) goto label_00007C41;
    if (*(uint32_t*)(cpu->edx) != cpu->eax) goto label_00007C39;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 8u) + 4u) = cpu->eax;
    goto label_00007C49;
    label_00007C39:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    goto label_00007C49;
    label_00007C41:
    if (*(uint32_t*)(cpu->edx) != cpu->eax) goto label_00007C4D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_00007C49:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00007C4D:
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_00007C6F;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407C69u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x407C69u));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 8u);
    label_00007C6F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->esi);
    if (cpu->eax < 0x15555554u) goto label_00007CC4;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint32_t*)(cpu->esi + 0x14u) == 0u) goto label_00007CB0;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407CA4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x407CA4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407CADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x407CADu));
    cpu->esp += 4u;
    label_00007CB0:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407CB6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x407CB6u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x407CB0u), "std::length_error");
    label_00007CC4:
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (cpu->eax != cpu->edx) goto label_00007CEE;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_00007D0F;
    label_00007CEE:
    if (*(uint8_t*)(cpu->esp + 0x14u) == (cpu->ebx & 0xFFu)) goto label_00007D01;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_00007D0F;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_00007D0F;
    label_00007D01:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_00007D0F;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_00007D0F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00007EAD;
    lift_push32(cpu, cpu->edi);
    label_00007D20:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_00007DEF;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00007D52;
    *(uint8_t*)(cpu->edx + 0x18u) = 1u;
    *(uint8_t*)(cpu->esi + 0x18u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x18u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_00007EA0;
    label_00007D52:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_00007D91;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x19u) != (cpu->ebx & 0xFFu)) goto label_00007D6B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_00007D6B:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_00007D7E;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_00007D8C;
    label_00007D7E:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_00007D89;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_00007D8C;
    label_00007D89:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_00007D8C:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_00007D91:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x18u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x18u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x19u) != (cpu->ebx & 0xFFu)) goto label_00007DB9;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_00007DB9:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_00007DD2;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_00007E9D;
    label_00007DD2:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_00007DE5;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_00007E9D;
    label_00007DE5:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_00007E9D;
    label_00007DEF:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00007E12;
    *(uint8_t*)(cpu->edx + 0x18u) = 1u;
    *(uint8_t*)(cpu->esi + 0x18u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x18u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_00007EA0;
    label_00007E12:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_00007E52;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x19u) != (cpu->ebx & 0xFFu)) goto label_00007E2A;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_00007E2A:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_00007E3D;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_00007E4C;
    label_00007E3D:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_00007E4A;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_00007E4C;
    label_00007E4A:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_00007E4C:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_00007E52:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x18u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x18u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x19u) != (cpu->ebx & 0xFFu)) goto label_00007E7A;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_00007E7A:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_00007E8D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_00007E9B;
    label_00007E8D:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_00007E98;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_00007E9B;
    label_00007E98:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_00007E9B:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_00007E9D:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_00007EA0:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x18u) == (cpu->ebx & 0xFFu)) goto label_00007D20;
    cpu->edi = lift_pop32(cpu);
    label_00007EAD:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x18u) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == cpu->esi) goto label_000081A2;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00008162:
    if (cpu->edx == cpu->ebx) goto label_0000816D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->esi) goto label_00008162;
    label_0000816D:
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == cpu->esi) goto label_000081A2;
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_0000818D;
    if (*(uint32_t*)(cpu->ecx + 0x1Cu) != cpu->eax) goto label_0000818D;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    if (cpu->edx != cpu->esi) goto label_0000818D;
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_0000818D:
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ecx + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40819Bu)); sfera_sub_00406BA0(cpu, LIFT_CODE_TOKEN_VA(0x40819Bu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000081A2:
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004081B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = cpu->ebx + 0x10u;
    if (*(uint8_t*)(cpu->ebx + 8u) == 0u) goto label_000081E0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->esi -= *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4081D1u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4081D1u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->ecx + (cpu->esi * 4u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000081E0:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4081E6u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4081E6u));
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004081F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = cpu->ebx + 0x10u;
    if (*(uint8_t*)(cpu->ebx + 8u) == 0u) goto label_00008220;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->esi -= *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408211u)); sfera_sub_00406C10(cpu, LIFT_CODE_TOKEN_VA(0x408211u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->ecx + (cpu->esi * 4u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00008220:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408226u)); sfera_sub_00406C10(cpu, LIFT_CODE_TOKEN_VA(0x408226u));
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = cpu->ebx + 0x10u;
    if (*(uint8_t*)(cpu->ebx + 8u) == 0u) goto label_0000825C;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->edi -= *(uint32_t*)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40824Eu)); sfera_sub_00406C80(cpu, LIFT_CODE_TOKEN_VA(0x40824Eu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx += cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000825C:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408266u)); sfera_sub_00406C80(cpu, LIFT_CODE_TOKEN_VA(0x408266u));
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000082A4;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 0xCu)) goto label_000082A3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx = cpu->esi + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408299u)); sfera_sub_004B1370(cpu, LIFT_CODE_TOKEN_VA(0x408299u));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x20u) == cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000082A3;
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000082A3:
    cpu->edi = lift_pop32(cpu);
    label_000082A4:
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4082B2u)); sfera_sub_004033F0(cpu, LIFT_CODE_TOKEN_VA(0x4082B2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4082C9u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4082C9u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004082E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4082F3u)); sfera_sub_004040B0(cpu, LIFT_CODE_TOKEN_VA(0x4082F3u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ebx + 0x14u)) goto label_00008334;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0000830A;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000830A:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408319u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x408319u));
    if ((int32_t)cpu->eax < 0) goto label_00008334;
    cpu->eax = cpu->esp + 0x14u;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = 0u;
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->ebx + 0x14u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (!sub_pred[0]);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00008334:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x14u);
    cpu->eax = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (cpu->eax != cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040842B(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408434u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408434u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408440u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x408440u));
    lift_trap(cpu, 0x408440u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00408450(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408463u)); sfera_sub_00404900(cpu, LIFT_CODE_TOKEN_VA(0x408463u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u)) goto label_00008493;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0000847A;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000847A:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408489u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x408489u));
    if ((int32_t)cpu->eax < 0) goto label_00008493;
    cpu->eax = cpu->esp + 0x14u;
    goto label_0000849E;
    label_00008493:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x18u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->eax = cpu->esp + 0xCu;
    label_0000849E:
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000084BF;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x28u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000084BF:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004084D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4084ECu)); sfera_sub_00403500(cpu, LIFT_CODE_TOKEN_VA(0x4084ECu));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408502u)); sfera_sub_00406340(cpu, LIFT_CODE_TOKEN_VA(0x408502u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408510(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408523u)); sfera_sub_00404900(cpu, LIFT_CODE_TOKEN_VA(0x408523u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u)) goto label_00008553;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0000853A;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000853A:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408549u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x408549u));
    if ((int32_t)cpu->eax < 0) goto label_00008553;
    cpu->eax = cpu->esp + 0x14u;
    goto label_0000855E;
    label_00008553:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x18u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->eax = cpu->esp + 0xCu;
    label_0000855E:
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00008580;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->eax + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00008580:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408590(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4085A3u)); sfera_sub_00404B40(cpu, LIFT_CODE_TOKEN_VA(0x4085A3u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u)) goto label_000085D3;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000085BA;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000085BA:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4085C9u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x4085C9u));
    if ((int32_t)cpu->eax < 0) goto label_000085D3;
    cpu->eax = cpu->esp + 0x14u;
    goto label_000085DE;
    label_000085D3:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x18u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->eax = cpu->esp + 0xCu;
    label_000085DE:
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000085FA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->eax + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4085F4u)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x4085F4u));
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000085FA:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408610(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408623u)); sfera_sub_00404D80(cpu, LIFT_CODE_TOKEN_VA(0x408623u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u)) goto label_00008653;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0000863A;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000863A:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408649u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x408649u));
    if ((int32_t)cpu->eax < 0) goto label_00008653;
    cpu->eax = cpu->esp + 0x14u;
    goto label_0000865E;
    label_00008653:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x18u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->eax = cpu->esp + 0xCu;
    label_0000865E:
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->ebx + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_0000867A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->eax + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408674u)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x408674u));
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000867A:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if (cpu->eax < 0x9249248u) goto label_000086D5;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_000086B2;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4086AFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4086AFu));
    cpu->esp += 4u;
    label_000086B2:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4086C7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4086C7u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4086B2u), "std::length_error");
    label_000086D5:
    ++cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if (cpu->eax != cpu->edx) goto label_000086FE;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_0000871F;
    label_000086FE:
    if (*(uint8_t*)(cpu->esp + 0x14u) == (cpu->ebx & 0xFFu)) goto label_00008711;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000871F;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_0000871F;
    label_00008711:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000871F;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_0000871F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x28u) != (cpu->ebx & 0xFFu)) goto label_000088BD;
    lift_push32(cpu, cpu->edi);
    label_00008730:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_000087FF;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x28u) != (cpu->ebx & 0xFFu)) goto label_00008762;
    *(uint8_t*)(cpu->edx + 0x28u) = 1u;
    *(uint8_t*)(cpu->esi + 0x28u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x28u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000088B0;
    label_00008762:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_000087A1;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x29u) != (cpu->ebx & 0xFFu)) goto label_0000877B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000877B:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000878E;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000879C;
    label_0000878E:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_00008799;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_0000879C;
    label_00008799:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_0000879C:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_000087A1:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x28u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x28u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x29u) != (cpu->ebx & 0xFFu)) goto label_000087C9;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_000087C9:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_000087E2;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000088AD;
    label_000087E2:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_000087F5;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000088AD;
    label_000087F5:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000088AD;
    label_000087FF:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x28u) != (cpu->ebx & 0xFFu)) goto label_00008822;
    *(uint8_t*)(cpu->edx + 0x28u) = 1u;
    *(uint8_t*)(cpu->esi + 0x28u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x28u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000088B0;
    label_00008822:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_00008862;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x29u) != (cpu->ebx & 0xFFu)) goto label_0000883A;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000883A:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000884D;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000885C;
    label_0000884D:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0000885A;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000885C;
    label_0000885A:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000885C:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_00008862:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x28u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x28u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x29u) != (cpu->ebx & 0xFFu)) goto label_0000888A;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000888A:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000889D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_000088AB;
    label_0000889D:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_000088A8;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_000088AB;
    label_000088A8:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_000088AB:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_000088AD:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_000088B0:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x28u) == (cpu->ebx & 0xFFu)) goto label_00008730;
    cpu->edi = lift_pop32(cpu);
    label_000088BD:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x28u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004088E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x15u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_00008914;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    label_00008900:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->ecx) goto label_0000890A;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_0000890E;
    label_0000890A:
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000890E:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00008900;
    label_00008914:
    if (cpu->edi == *(uint32_t*)(cpu->esi + 4u)) goto label_00008920;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->edi + 0xCu)) goto label_00008957;
    label_00008920:
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40893Au)); sfera_sub_0042A320(cpu, LIFT_CODE_TOKEN_VA(0x40893Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408948u)); sfera_sub_00406430(cpu, LIFT_CODE_TOKEN_VA(0x408948u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x10u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00008957:
    cpu->eax = cpu->edi + 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408970(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000089A4;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    label_00008990:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->ecx) goto label_0000899A;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_0000899E;
    label_0000899A:
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000899E:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00008990;
    label_000089A4:
    if (cpu->esi == *(uint32_t*)(cpu->edi + 4u)) goto label_000089B0;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0xCu)) goto label_000089E5;
    label_000089B0:
    cpu->ecx = *(uint32_t*)(cpu->edx);
    x87_v0 = 0.0;
    cpu->edx = cpu->esp + 8u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4089C8u)); sfera_sub_00406590(cpu, LIFT_CODE_TOKEN_VA(0x4089C8u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4089D6u)); sfera_sub_00406430(cpu, LIFT_CODE_TOKEN_VA(0x4089D6u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x10u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000089E5:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi + 0x10u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004089F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->ecx;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x19u) != 0u) goto label_00008A40;
    label_00008A01:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408A0Cu)); sfera_sub_004089F0(cpu, LIFT_CODE_TOKEN_VA(0x408A0Cu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->edi + 0x14u) == 0u) goto label_00008A2F;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408A23u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x408A23u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408A2Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408A2Cu));
    cpu->esp += 4u;
    label_00008A2F:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408A35u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408A35u));
    cpu->esp += 4u;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x19u) == 0u) goto label_00008A01;
    label_00008A40:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408A50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_00008AA3;
    lift_push32(cpu, cpu->ebx);
    label_00008A70:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_00008A93;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408A87u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x408A87u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408A90u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408A90u));
    cpu->esp += 4u;
    label_00008A93:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408A99u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408A99u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if (cpu->ebx != *(uint32_t*)(cpu->edi)) goto label_00008A70;
    cpu->ebx = lift_pop32(cpu);
    label_00008AA3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408AB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x19u) == 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ebx;
    if (sub_pred[0]) goto label_00008ACD;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x408AB0u), "std::out_of_range");
    label_00008ACD:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408ADBu)); sfera_sub_004023F0(cpu, LIFT_CODE_TOKEN_VA(0x408ADBu));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    if (*(uint8_t*)(cpu->ecx + 0x19u) == 0u) goto label_00008AE9;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    goto label_00008B01;
    label_00008AE9:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint8_t*)(cpu->eax + 0x19u) == 0u) goto label_00008AF6;
    cpu->edi = cpu->ecx;
    goto label_00008B01;
    label_00008AF6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebp) goto label_00008B64;
    label_00008B01:
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint8_t*)(cpu->edi + 0x19u) != 0u) goto label_00008B0D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_00008B0D:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebp) goto label_00008B1A;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_00008B25;
    label_00008B1A:
    if (*(uint32_t*)(cpu->esi) != cpu->ebp) goto label_00008B22;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_00008B25;
    label_00008B22:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_00008B25:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ebx) != cpu->ebp) goto label_00008B3F;
    if (*(uint8_t*)(cpu->edi + 0x19u) == 0u) goto label_00008B36;
    cpu->eax = cpu->esi;
    goto label_00008B3D;
    label_00008B36:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8B3Du)); sfera_sub_004023D0(cpu, LIFT_CODE_TOKEN_RVA(0x8B3Du));
    label_00008B3D:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_00008B3F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->ebp) goto label_00008BBC;
    if (*(uint8_t*)(cpu->edi + 0x19u) == 0u) goto label_00008B58;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_00008BBC;
    label_00008B58:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408B5Fu)); sfera_sub_004023B0(cpu, LIFT_CODE_TOKEN_VA(0x408B5Fu));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_00008BBC;
    label_00008B64:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebp + 8u)) goto label_00008B75;
    cpu->esi = cpu->eax;
    goto label_00008B8F;
    label_00008B75:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edi + 0x19u) != 0u) goto label_00008B81;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_00008B81:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_00008B8F:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebp) goto label_00008B9C;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_00008BAA;
    label_00008B9C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebp) goto label_00008BA7;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_00008BAA;
    label_00008BA7:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_00008BAA:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x18u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x18u));
    *(uint8_t*)(cpu->eax + 0x18u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0x18u) = cpu->ecx & 0xFFu;
    label_00008BBC:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->ebp + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00008CC6;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->eax + 4u)) goto label_00008CC3;
    label_00008BD7:
    if (*(uint8_t*)(cpu->edi + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00008CC3;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_00008C4D;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x18u) != 0u) goto label_00008C03;
    *(uint8_t*)(cpu->eax + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x18u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408BFCu)); sfera_sub_00402FC0(cpu, LIFT_CODE_TOKEN_VA(0x408BFCu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00008C03:
    if (*(uint8_t*)(cpu->eax + 0x19u) != 0u) goto label_00008C7F;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00008C18;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x18u) == (cpu->ebx & 0xFFu)) goto label_00008C7B;
    label_00008C18:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00008C36;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->edx + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x18u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408C2Fu)); sfera_sub_00403010(cpu, LIFT_CODE_TOKEN_VA(0x408C2Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00008C36:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x18u));
    *(uint8_t*)(cpu->eax + 0x18u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x18u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408C4Bu)); sfera_sub_00402FC0(cpu, LIFT_CODE_TOKEN_VA(0x408C4Bu));
    goto label_00008CC3;
    label_00008C4D:
    if (*(uint8_t*)(cpu->eax + 0x18u) != 0u) goto label_00008C66;
    *(uint8_t*)(cpu->eax + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x18u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408C60u)); sfera_sub_00403010(cpu, LIFT_CODE_TOKEN_VA(0x408C60u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00008C66:
    if (*(uint8_t*)(cpu->eax + 0x19u) != 0u) goto label_00008C7F;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00008C92;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00008C92;
    label_00008C7B:
    *(uint8_t*)(cpu->eax + 0x18u) = 0u;
    label_00008C7F:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax + 4u)) goto label_00008BD7;
    goto label_00008CC3;
    label_00008C92:
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x18u) != (cpu->ebx & 0xFFu)) goto label_00008CAF;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint8_t*)(cpu->edx + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x18u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408CA9u)); sfera_sub_00402FC0(cpu, LIFT_CODE_TOKEN_VA(0x408CA9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00008CAF:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x18u));
    *(uint8_t*)(cpu->eax + 0x18u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x18u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8CC3u)); sfera_sub_00403010(cpu, LIFT_CODE_TOKEN_RVA(0x8CC3u));
    label_00008CC3:
    *(uint8_t*)(cpu->edi + 0x18u) = cpu->ebx & 0xFFu;
    label_00008CC6:
    if (*(uint32_t*)(cpu->ebp + 0x14u) == 0u) goto label_00008CE7;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408CDBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x408CDBu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408CE4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408CE4u));
    cpu->esp += 4u;
    label_00008CE7:
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408CEDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408CEDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_00008D02;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_00008D02:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_00008D7D;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_00008D62;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408D56u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x408D56u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408D5Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408D5Fu));
    cpu->esp += 4u;
    label_00008D62:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408D68u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408D68u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00008D7D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408D90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->edi == 0u) goto label_00008F98;
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->edx = 0x3FFFFFFFu;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->edi) goto label_00008DEA;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x408D90u), "std::length_error");
    label_00008DEA:
    cpu->edx = cpu->eax + cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax >= cpu->edx) goto label_00008EE3;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 1u;
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->ecx;
    if (cpu->ebx >= cpu->eax) goto label_00008E18;
    *(uint32_t*)(cpu->ebp + 0xCu) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    goto label_00008E1D;
    label_00008E18:
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    label_00008E1D:
    if (cpu->eax >= cpu->edx) goto label_00008E26;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->edx;
    cpu->eax = cpu->edx;
    label_00008E26:
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E2Fu)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x408E2Fu));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx -= *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ebx = (int32_t)(cpu->ebx) >> 2u;
    cpu->ecx = cpu->eax + (cpu->ebx * 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E59u)); sfera_sub_00405050(cpu, LIFT_CODE_TOKEN_VA(0x408E59u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E71u)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408E71u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx + cpu->edi;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E90u)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408E90u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx -= cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    cpu->edi += cpu->ecx;
    if (cpu->eax == 0u) goto label_00008EA9;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408EA6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408EA6u));
    cpu->esp += 4u;
    label_00008EA9:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = cpu->ebx + (cpu->edx * 4u);
    cpu->ecx = cpu->ebx + (cpu->edi * 4u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00008EE3:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    sub_pred[0] = cpu->eax < cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    if (!sub_pred[0]) goto label_00008F57;
    cpu->edx = cpu->edi * 4u;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F1Au)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408F1Au));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->ecx;
    cpu->edx -= *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    lift_push32(cpu, 0u);
    cpu->edi -= cpu->edx;
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F43u)); sfera_sub_00405050(cpu, LIFT_CODE_TOKEN_VA(0x408F43u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx -= cpu->eax;
    goto label_00008F93;
    label_00008F57:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->edi * 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esi + 0xCu;
    cpu->edi = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edi -= cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F79u)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408F79u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F87u)); sfera_sub_00403120(cpu, LIFT_CODE_TOKEN_VA(0x408F87u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->ecx;
    label_00008F93:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8F98u)); sfera_sub_00403150(cpu, LIFT_CODE_TOKEN_RVA(0x8F98u));
    label_00008F98:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408ECE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408ED7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408ED7u));
    cpu->esp += 4u;
    sfera_sub_00408EDA(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00408EDA(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408EE3u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x408EE3u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    sub_pred[0] = cpu->eax < cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    if (!sub_pred[0]) goto label_00008F57;
    cpu->edx = cpu->edi * 4u;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F1Au)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408F1Au));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->ecx;
    cpu->edx -= *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    lift_push32(cpu, 0u);
    cpu->edi -= cpu->edx;
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F43u)); sfera_sub_00405050(cpu, LIFT_CODE_TOKEN_VA(0x408F43u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx -= cpu->eax;
    goto label_00008F93;
    label_00008F57:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->edi * 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esi + 0xCu;
    cpu->edi = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edi -= cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F79u)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408F79u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F87u)); sfera_sub_00403120(cpu, LIFT_CODE_TOKEN_VA(0x408F87u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->ecx;
    label_00008F93:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F98u)); sfera_sub_00403150(cpu, LIFT_CODE_TOKEN_VA(0x408F98u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408FB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->edi) goto label_00008FE9;
    label_00008FC0:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_00008FD1;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408FCEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408FCEu));
    cpu->esp += 4u;
    label_00008FD1:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi += 0x1Cu;
    if (cpu->esi != cpu->edi) goto label_00008FC0;
    label_00008FE9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408FF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x19u) == 0u;
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if (!sub_pred[0]) goto label_0000903D;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xCu);
    label_00009011:
    cpu->esi = cpu->eax;
    if (*(uint8_t*)(cpu->esp + 0x1Cu) == 0u) goto label_00009022;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((int32_t)(*(uint32_t*)(cpu->eax + 0xCu)) >= (int32_t)(cpu->edx));
    goto label_00009028;
    label_00009022:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((int32_t)(cpu->edx) < (int32_t)(*(uint32_t*)(cpu->eax + 0xCu)));
    label_00009028:
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_00009034;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_00009037;
    label_00009034:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_00009037:
    if (*(uint8_t*)(cpu->eax + 0x19u) == 0u) goto label_00009011;
    label_0000903D:
    cpu->ebp = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0000907A;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = cpu->esp + 0x1Cu;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_00009071;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40905Eu)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40905Eu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00009071:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409076u)); sfera_sub_00402660(cpu, LIFT_CODE_TOKEN_VA(0x409076u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000907A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ebx + 0xCu)) goto label_000090A8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409095u)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x409095u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000090A8:
    if (*(uint32_t*)(cpu->ebx + 0x14u) == 0u) goto label_000090C9;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4090BDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4090BDu));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4090C6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4090C6u));
    cpu->esp += 4u;
    label_000090C9:
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4090CFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4090CFu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004090F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->edi = cpu->eax + 1u;
    label_00009110:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00009110;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409122u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x409122u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409130(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->edi) goto label_0000919A;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000914D;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40914Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40914Au));
    cpu->esp += 4u;
    label_0000914D:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x14u) >= 0x10u) goto label_00009176;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40916Bu));
    cpu->esp += 0xCu;
    goto label_00009180;
    label_00009176:
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    *(uint32_t*)(cpu->edi) = 0u;
    label_00009180:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x10u) = 0u;
    *(uint32_t*)(cpu->edi + 0x14u) = 0u;
    label_0000919A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409790(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00009790;
    label_00008360:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->eax <= 0x1FFFFFFFu) goto label_000083A2;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x408360u), "std::length_error");
    label_000083A2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->ecx = (int32_t)(cpu->ecx) >> 3u;
    if (cpu->ecx >= cpu->eax) goto label_00008417;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4083B9u)); sfera_sub_00402BB0(cpu, LIFT_CODE_TOKEN_VA(0x4083B9u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4083D7u)); sfera_sub_00405010(cpu, LIFT_CODE_TOKEN_VA(0x4083D7u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->edx;
    cpu->edi -= cpu->ecx;
    cpu->edi = (int32_t)(cpu->edi) >> 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    if (cpu->ecx == 0u) goto label_00008406;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4083FBu)); sfera_sub_004063F0(cpu, LIFT_CODE_TOKEN_VA(0x4083FBu));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408403u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x408403u));
    cpu->esp += 4u;
    label_00008406:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = cpu->ebx + (cpu->edx * 8u);
    cpu->ecx = cpu->ebx + (cpu->edi * 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_00008417:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00009790:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->eax -= cpu->esi;
    cpu->edi = 0x1FFFFFFFu;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000097B6;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x409790u), "std::length_error");
    label_000097B6:
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx -= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    if (cpu->eax <= cpu->edx) goto label_000097EA;
    cpu->esi = cpu->edx;
    cpu->esi >>= 1u;
    cpu->edi = 0x1FFFFFFFu;
    cpu->edi -= cpu->esi;
    if (cpu->edi >= cpu->edx) goto label_000097D7;
    cpu->edx = 0u;
    goto label_000097D9;
    label_000097D7:
    cpu->edx += cpu->esi;
    label_000097D9:
    if (cpu->edx >= cpu->eax) goto label_000097DF;
    cpu->edx = cpu->eax;
    label_000097DF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    goto label_00008360;
    label_000097EA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004097F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x29u) != (cpu->ebx & 0xFFu)) goto label_0000983F;
    label_00009803:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40980Eu)); sfera_sub_004097F0(cpu, LIFT_CODE_TOKEN_VA(0x40980Eu));
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_00009822;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40981Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40981Fu));
    cpu->esp += 4u;
    label_00009822:
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409835u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x409835u));
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x29u) == (cpu->ebx & 0xFFu)) goto label_00009803;
    label_0000983F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409850(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x29u) == 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ebx;
    if (sub_pred[0]) goto label_0000986D;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x409850u), "std::out_of_range");
    label_0000986D:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40987Bu)); sfera_sub_00402AF0(cpu, LIFT_CODE_TOKEN_VA(0x40987Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    if (*(uint8_t*)(cpu->ecx + 0x29u) == 0u) goto label_00009889;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    goto label_000098A1;
    label_00009889:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint8_t*)(cpu->eax + 0x29u) == 0u) goto label_00009896;
    cpu->edi = cpu->ecx;
    goto label_000098A1;
    label_00009896:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebp) goto label_00009904;
    label_000098A1:
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint8_t*)(cpu->edi + 0x29u) != 0u) goto label_000098AD;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_000098AD:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebp) goto label_000098BA;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_000098C5;
    label_000098BA:
    if (*(uint32_t*)(cpu->esi) != cpu->ebp) goto label_000098C2;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_000098C5;
    label_000098C2:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_000098C5:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ebx) != cpu->ebp) goto label_000098DF;
    if (*(uint8_t*)(cpu->edi + 0x29u) == 0u) goto label_000098D6;
    cpu->eax = cpu->esi;
    goto label_000098DD;
    label_000098D6:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x98DDu)); sfera_sub_004020E0(cpu, LIFT_CODE_TOKEN_RVA(0x98DDu));
    label_000098DD:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_000098DF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->ebp) goto label_0000995C;
    if (*(uint8_t*)(cpu->edi + 0x29u) == 0u) goto label_000098F8;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000995C;
    label_000098F8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4098FFu)); sfera_sub_00402120(cpu, LIFT_CODE_TOKEN_VA(0x4098FFu));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000995C;
    label_00009904:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebp + 8u)) goto label_00009915;
    cpu->esi = cpu->eax;
    goto label_0000992F;
    label_00009915:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edi + 0x29u) != 0u) goto label_00009921;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_00009921:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_0000992F:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebp) goto label_0000993C;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000994A;
    label_0000993C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebp) goto label_00009947;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_0000994A;
    label_00009947:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000994A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x28u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x28u));
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0x28u) = cpu->ecx & 0xFFu;
    label_0000995C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->ebp + 0x28u) != (cpu->ebx & 0xFFu)) goto label_00009A66;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->eax + 4u)) goto label_00009A63;
    label_00009977:
    if (*(uint8_t*)(cpu->edi + 0x28u) != (cpu->ebx & 0xFFu)) goto label_00009A63;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_000099ED;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x28u) != 0u) goto label_000099A3;
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40999Cu)); sfera_sub_00402C10(cpu, LIFT_CODE_TOKEN_VA(0x40999Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000099A3:
    if (*(uint8_t*)(cpu->eax + 0x29u) != 0u) goto label_00009A1F;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x28u) != (cpu->ebx & 0xFFu)) goto label_000099B8;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x28u) == (cpu->ebx & 0xFFu)) goto label_00009A1B;
    label_000099B8:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x28u) != (cpu->ebx & 0xFFu)) goto label_000099D6;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->edx + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4099CFu)); sfera_sub_00402C60(cpu, LIFT_CODE_TOKEN_VA(0x4099CFu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000099D6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x28u));
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x28u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4099EBu)); sfera_sub_00402C10(cpu, LIFT_CODE_TOKEN_VA(0x4099EBu));
    goto label_00009A63;
    label_000099ED:
    if (*(uint8_t*)(cpu->eax + 0x28u) != 0u) goto label_00009A06;
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409A00u)); sfera_sub_00402C60(cpu, LIFT_CODE_TOKEN_VA(0x409A00u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00009A06:
    if (*(uint8_t*)(cpu->eax + 0x29u) != 0u) goto label_00009A1F;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x28u) != (cpu->ebx & 0xFFu)) goto label_00009A32;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x28u) != (cpu->ebx & 0xFFu)) goto label_00009A32;
    label_00009A1B:
    *(uint8_t*)(cpu->eax + 0x28u) = 0u;
    label_00009A1F:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax + 4u)) goto label_00009977;
    goto label_00009A63;
    label_00009A32:
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x28u) != (cpu->ebx & 0xFFu)) goto label_00009A4F;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint8_t*)(cpu->edx + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409A49u)); sfera_sub_00402C10(cpu, LIFT_CODE_TOKEN_VA(0x409A49u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00009A4F:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x28u));
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x28u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9A63u)); sfera_sub_00402C60(cpu, LIFT_CODE_TOKEN_RVA(0x9A63u));
    label_00009A63:
    *(uint8_t*)(cpu->edi + 0x28u) = cpu->ebx & 0xFFu;
    label_00009A66:
    if (*(uint32_t*)(cpu->ebp + 0x20u) < 0x10u) goto label_00009A78;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409A75u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x409A75u));
    cpu->esp += 4u;
    label_00009A78:
    *(uint32_t*)(cpu->ebp + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = 0u;
    lift_push32(cpu, cpu->ebp);
    *(uint8_t*)(cpu->ebp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409A90u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x409A90u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_00009AA5;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_00009AA5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409AC0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[2];
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebp += 0xCu;
    sub_pred[0] = *(uint8_t*)(cpu->ebx + 0x29u) == 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if (!sub_pred[0]) goto label_00009BBC;
    label_00009AF0:
    sub_pred[1] = *(uint8_t*)(cpu->esp + 0x28u) == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->eax = cpu->ebx + 0xCu;
    if (sub_pred[1]) goto label_00009B52;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00009B09;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00009B0B;
    label_00009B09:
    cpu->edx = cpu->ebp;
    label_00009B0B:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_00009B14;
    label_00009B14:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_00009B1F;
    cpu->ecx = cpu->edi;
    label_00009B1F:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00009B27;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00009B27:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409B2Fu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x409B2Fu));
    cpu->esp += 0xCu;
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00009B4D;
    if (cpu->esi >= cpu->edi) goto label_00009B44;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eax)&0x80000000u)==0u)) ? 1u : 0u) & 0xFFu);
    goto label_00009B9B;
    label_00009B44:
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    label_00009B4D:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((!lift_test[0]) ? 1u : 0u) & 0xFFu);
    goto label_00009B9B;
    label_00009B52:
    cpu->edi = *(uint32_t*)(cpu->eax + 0x10u);
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00009B5D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00009B5D:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_00009B6A;
    cpu->edx = cpu->edi;
    label_00009B6A:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00009B75;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_00009B77;
    label_00009B75:
    cpu->ecx = cpu->ebp;
    label_00009B77:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409B7Fu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x409B7Fu));
    cpu->esp += 0xCu;
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    if (cpu->eax!=0u) goto label_00009B98;
    if (cpu->esi >= cpu->edi) goto label_00009B8F;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00009B96;
    label_00009B8F:
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    label_00009B96:
    lift_test[1]=((cpu->eax)&0x80000000u)!=0u;
    label_00009B98:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((lift_test[1]) ? 1u : 0u) & 0xFFu);
    label_00009B9B:
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_00009BA7;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    goto label_00009BAA;
    label_00009BA7:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    label_00009BAA:
    if (*(uint8_t*)(cpu->ebx + 0x29u) == 0u) goto label_00009AF0;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00009BBC:
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_00009C02;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_00009BF5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    label_00009BDA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409BDFu)); sfera_sub_00408690(cpu, LIFT_CODE_TOKEN_VA(0x409BDFu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00009BF5:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409BFEu)); sfera_sub_004021A0(cpu, LIFT_CODE_TOKEN_VA(0x409BFEu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    label_00009C02:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ebx = 0x10u;
    cpu->ecx = cpu->esi + 0xCu;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->ebx) goto label_00009C17;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    goto label_00009C19;
    label_00009C17:
    cpu->eax = cpu->ebp;
    label_00009C19:
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409C26u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x409C26u));
    if ((int32_t)cpu->eax >= 0) goto label_00009C40;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    goto label_00009BDA;
    label_00009C40:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->ebx) goto label_00009C51;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409C4Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x409C4Eu));
    cpu->esp += 4u;
    label_00009C51:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->ebp + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409C6Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x409C6Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409C90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409CA5u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409CA5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009CC5;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009CC5:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409CD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409CE5u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409CE5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009D05;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009D05:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409D10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409D25u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409D25u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009D45;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009D45:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409D50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409D65u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409D65u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009D86;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->eax + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009D86:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409D90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409DA5u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409DA5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009DC6;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009DC6:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409DD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409DE5u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409DE5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009E06;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009E06:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409E10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409E25u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409E25u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009E40;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409E3Bu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x409E3Bu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009E40:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409E50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409E65u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409E65u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009E80;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409E7Bu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x409E7Bu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009E80:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409E90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409EA5u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409EA5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009EC0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409EBBu)); sfera_sub_004031C0(cpu, LIFT_CODE_TOKEN_VA(0x409EBBu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009EC0:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409ED0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409EE5u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409EE5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009F00;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409EFBu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x409EFBu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009F00:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409F10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409F25u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409F25u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009F40;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409F3Bu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x409F3Bu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009F40:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409F50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409F65u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409F65u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009F80;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409F7Bu)); sfera_sub_00401CD0(cpu, LIFT_CODE_TOKEN_VA(0x409F7Bu));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009F80:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409F90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_00009FDA;
    if (cpu->edx != cpu->eax) goto label_00009FDA;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409FB2u)); sfera_sub_004089F0(cpu, LIFT_CODE_TOKEN_VA(0x409FB2u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00009FDA:
    if (cpu->ecx == cpu->edx) goto label_0000A04F;
    label_00009FE0:
    cpu->edx = cpu->ecx;
    if (*(uint8_t*)(cpu->ecx + 0x19u) != 0u) goto label_0000A038;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x19u) != 0u) goto label_0000A010;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x19u) != 0u) goto label_0000A00A;
    label_0000A000:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x19u) == 0u) goto label_0000A000;
    label_0000A00A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_0000A038;
    label_0000A010:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x19u) != 0u) goto label_0000A034;
    label_0000A020:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_0000A034;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x19u) == 0u) goto label_0000A020;
    label_0000A034:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0000A038:
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A045u)); sfera_sub_00408AB0(cpu, LIFT_CODE_TOKEN_VA(0x40A045u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_00009FE0;
    label_0000A04F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A060(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000A0B3;
    lift_push32(cpu, cpu->ebx);
    label_0000A080:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0xCu) == 0u) goto label_0000A0A3;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A097u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40A097u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A0A0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A0A0u));
    cpu->esp += 4u;
    label_0000A0A3:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A0A9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A0A9u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if (cpu->ebx != *(uint32_t*)(cpu->edi)) goto label_0000A080;
    cpu->ebx = lift_pop32(cpu);
    label_0000A0B3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A0C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = 0u;
    if (cpu->edi == *(uint32_t*)(cpu->ebx)) goto label_0000A167;
    label_0000A0FD:
    cpu->ebp = *(uint32_t*)(cpu->edi);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (sub_pred[0]) goto label_0000A12F;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A123u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40A123u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A12Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A12Cu));
    cpu->esp += 4u;
    label_0000A12F:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_0000A158;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A14Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40A14Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A155u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A155u));
    cpu->esp += 4u;
    label_0000A158:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A15Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A15Eu));
    cpu->esp += 4u;
    cpu->edi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->ebx)) goto label_0000A0FD;
    label_0000A167:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A180(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40A191u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_0000A1B0;
    cpu->edx += 0x7FFFFFFFu;
    label_0000A1B0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_0000A1C5;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_0000A1C5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) == cpu->edx;
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000A1F2;
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000A1EA;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->edx;
    goto label_0000A1FA;
    label_0000A1EA:
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000A1FA;
    label_0000A1F2:
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000A1FE;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0000A1FA:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000A1FE:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A20Cu)); sfera_sub_00408D20(cpu, LIFT_CODE_TOKEN_VA(0x40A20Cu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000A258;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A248u)); sfera_sub_00403C10(cpu, LIFT_CODE_TOKEN_VA(0x40A248u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A24Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A24Eu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000A258:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

} // namespace lifted
