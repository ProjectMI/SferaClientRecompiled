#include "lifted_functions.h"
#include <cmath>
namespace lifted {







__declspec(noinline) void sfera_sub_0041E1B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x410u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == cpu->edi) goto label_0001E1E0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x41E1C3u));
    if (cpu->eax != 0u) goto label_0001E1DA;
    cpu->edx = cpu->edi + 0x23u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CheckFiles.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1E1DAu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1E1DAu));
    label_0001E1DA:
    *(uint32_t*)(cpu->esi + 0x410u) = cpu->edi;
    label_0001E1E0:
    *(uint32_t*)(cpu->esi + 0x404u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x37A4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x37A8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x37ACu) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x37B0u) = 1u;
    *(uint32_t*)(cpu->esi + 0x37B4u) = 0xFFFFFFFFu;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x37A4u);
    if ((int32_t)cpu->eax < (int32_t)0x64u) goto label_0001E231;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001E231:
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x84u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + cpu->ecx + 0x414u;
    label_0001E243:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    ++cpu->edx;
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0001E243;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x37A4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x84u);
    cpu->esi = cpu->eax + cpu->ecx + 0x454u;
    label_0001E264:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    ++cpu->edx;
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0001E264;
    ++*(uint32_t*)(cpu->ecx + 0x37A4u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx=0u;
    label_0001E282:
    cpu->eax = cpu->edx;
    cpu->eax >>= 1u;
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_0001E290;
    cpu->eax ^= 0xEDB88320u;
    label_0001E290:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E29D;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E29F;
    label_0001E29D:
    cpu->eax >>= 1u;
    label_0001E29F:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2AC;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2AE;
    label_0001E2AC:
    cpu->eax >>= 1u;
    label_0001E2AE:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2BB;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2BD;
    label_0001E2BB:
    cpu->eax >>= 1u;
    label_0001E2BD:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2CA;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2CC;
    label_0001E2CA:
    cpu->eax >>= 1u;
    label_0001E2CC:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2D9;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2DB;
    label_0001E2D9:
    cpu->eax >>= 1u;
    label_0001E2DB:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2E8;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2EA;
    label_0001E2E8:
    cpu->eax >>= 1u;
    label_0001E2EA:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0001E2F7;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0001E2F9;
    label_0001E2F7:
    cpu->eax >>= 1u;
    label_0001E2F9:
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = cpu->eax;
    ++cpu->edx;
    if ((int32_t)(cpu->edx) < (int32_t)(0x100u)) goto label_0001E282;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->edx == 0u) goto label_0001E341;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x400u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    label_0001E324:
    cpu->edi = (int8_t)(*(uint8_t*)(cpu->esi));
    cpu->edi ^= cpu->eax;
    cpu->edi&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    ++cpu->esi;
    --cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x400u) = cpu->eax;
    if (cpu->edx != 0u) goto label_0001E324;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0001E341:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_0001E360:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E360;
    cpu->eax -= cpu->esi;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)cpu->eax > (int32_t)4u) goto label_0001E374;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001E374:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFFu));
    if ((cpu->ecx & 0xFFu) == 0x6Cu) goto label_0001E382;
    if ((cpu->ecx & 0xFFu) != 0x4Cu) goto label_0001E3AD;
    label_0001E382:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFEu));
    if ((cpu->ecx & 0xFFu) == 0x64u) goto label_0001E390;
    if ((cpu->ecx & 0xFFu) != 0x44u) goto label_0001E3AD;
    label_0001E390:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFDu));
    if ((cpu->ecx & 0xFFu) == 0x6Du) goto label_0001E39E;
    if ((cpu->ecx & 0xFFu) != 0x4Du) goto label_0001E3AD;
    label_0001E39E:
    if (*(uint8_t*)(cpu->eax + cpu->edx + 0xFFFFFFFCu) != 0x2Eu) goto label_0001E3AD;
    cpu->eax = 1u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001E3AD:
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x10004u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E3CAu)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x41E3CAu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10008u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 0x400u) = 0u;
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x41E3F5u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi != 0xFFFFFFFFu) goto label_0001E409;
    cpu->eax = 0u;
    goto label_0001E464;
    label_0001E409:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x41E40Bu));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1001Cu);
    cpu->esp += 4u;
    if ((int32_t)cpu->edi <= (int32_t)cpu->eax) goto label_0001E423;
    cpu->edi = cpu->eax;
    label_0001E423:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x41E42Au));
    cpu->esp += 0xCu;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0001E446;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E439u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_0001E463;
    label_0001E446:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E453u)); sfera_sub_0041E310(cpu, LIFT_CODE_TOKEN_VA(0x41E453u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E454u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x400u);
    cpu->esp += 4u;
    label_0001E463:
    cpu->edi = lift_pop32(cpu);
    label_0001E464:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10004u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x10004u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E48Au)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x41E48Au));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10008u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    cpu->ebx = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x41E4ADu));
    cpu->ebp = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->ebp != 0xFFFFFFFFu) goto label_0001E4C1;
    cpu->eax = 0u;
    goto label_0001E532;
    label_0001E4C1:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x41E4C3u));
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    if ((int32_t)cpu->edi <= (int32_t)0x10000u) goto label_0001E4DB;
    cpu->edi = 0x10000u;
    label_0001E4DB:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x41E4E2u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0001E4FE;
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E4F1u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_0001E531;
    label_0001E4FE:
    cpu->eax = cpu->esp + 0x10u;
    if (cpu->edi == 0u) goto label_0001E525;
    label_0001E510:
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->ecx ^= cpu->esi;
    cpu->ecx&=0xFFu;
    cpu->esi = (int32_t)(cpu->esi) >> 8u;
    cpu->esi ^= *(uint32_t*)(cpu->ebx + (cpu->ecx * 4u));
    ++cpu->eax;
    if ((--cpu->edi) != 0u) goto label_0001E510;
    label_0001E525:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x41E526u));
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    label_0001E531:
    cpu->edi = lift_pop32(cpu);
    label_0001E532:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10004u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x330u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x338u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x340u);
    cpu->esi = cpu->esp + 0x138u;
    lift_push32(cpu, cpu->edi);
    cpu->esi -= cpu->ecx;
    label_0001E583:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0001E583;
    cpu->edx = cpu->eax;
    (void)cpu;
    label_0001E590:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E590;
    cpu->edi = cpu->esp + 0x13Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0001E5A1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0001E5A1;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x140u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41E5C6u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    cpu->ebp = 0u;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_0001E673;
    label_0001E5E0:
    if (((*(uint8_t*)(cpu->esp + 0x14u)) & (0x10u)) != 0u) goto label_0001E65C;
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E5F1u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E65C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x344u);
    cpu->edx = cpu->esp + 0x23Cu;
    cpu->edx -= cpu->eax;
    label_0001E610:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E610;
    cpu->eax = cpu->esp + 0x38u;
    cpu->edx = cpu->eax;
    label_0001E620:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001E620;
    cpu->edi = cpu->esp + 0x23Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0001E631:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0001E631;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x23Cu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E65Au)); sfera_sub_0041E480(cpu, LIFT_CODE_TOKEN_VA(0x41E65Au));
    cpu->ebp += cpu->eax;
    label_0001E65C:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41E662u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E5E0;
    label_0001E673:
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41E674u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x340u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x330u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x334u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x33Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x37B4u) > (int32_t)cpu->ebx) goto label_0001E91A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x340u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->esp + 0x23Cu;
    cpu->esi -= cpu->ecx;
    label_0001E6E0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E6E0;
    cpu->esi = cpu->eax;
    label_0001E6F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E6F0;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esp + 0x240u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0001E702:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((uint8_t)(cpu->ecx) != (uint8_t)(cpu->ebx)) goto label_0001E702;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x244u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x41E729u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0x37B8u) = 1u;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0001E90E;
    label_0001E750:
    if (((*(uint8_t*)(cpu->esp + 0x18u)) & (0x10u)) != 0u) goto label_0001E8F7;
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E765u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E8F7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x348u);
    cpu->edx = cpu->esp + 0x140u;
    cpu->edx -= cpu->eax;
    label_0001E786:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E786;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->esi = cpu->eax;
    label_0001E796:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0001E796;
    cpu->edi = cpu->esp + 0x140u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0001E7A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((uint8_t)(cpu->ecx) != (uint8_t)(cpu->ebx)) goto label_0001E7A7;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    lift_push32(cpu, 0x110u);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x41E7C2u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0x408u) = cpu->eax;
    if (cpu->eax == cpu->ebx) goto label_0001E98A;
    cpu->eax = cpu->esp + 0x140u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E7E8u)); sfera_sub_0041E350(cpu, LIFT_CODE_TOKEN_VA(0x41E7E8u));
    cpu->ecx = cpu->eax & 0xFFu;
    cpu->ecx = -cpu->ecx;
    cpu->ecx = (cpu->ecx != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ecx &= 0xFFFF0400u;
    cpu->ecx += 0x10000u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x144u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41E80Bu)); sfera_sub_0041E3C0(cpu, LIFT_CODE_TOKEN_VA(0x41E80Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ecx + 0x108u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->edx + 0x10Cu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    lift_push32(cpu, 0xFFu);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41E83Bu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint8_t*)(cpu->eax + 0x106u) = cpu->ebx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x404u);
    cpu->esp += 0xCu;
    if (cpu->esi != cpu->ebx) goto label_0001E879;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ebp + 0x404u) = cpu->eax;
    goto label_0001E8C8;
    label_0001E879:
    *(uint32_t*)(cpu->ebp + 0x40Cu) = cpu->ebx;
    (void)cpu;
    label_0001E880:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41E88Eu));
    cpu->esp += 8u;
    if ((int32_t)cpu->eax > 0) goto label_0001E933;
    *(uint32_t*)(cpu->ebp + 0x40Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->ebx) goto label_0001E880;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x40Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x40Cu);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_0001E8C8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x37A8u);
    ++*(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_0001E8EB;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) < (int32_t)cpu->eax) goto label_0001E8EB;
    lift_push32(cpu, 0x3E8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x41E8E1u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0001E8EB:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x37B4u) > (int32_t)cpu->ebx) goto label_0001E90E;
    label_0001E8F7:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x41E8FDu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0001E750;
    label_0001E90E:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x41E90Fu));
    cpu->esp += 4u;
    label_0001E918:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0001E91A:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x334u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001E933:
    if (cpu->esi != *(uint32_t*)(cpu->ebp + 0x404u)) goto label_0001E95D;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ebp + 0x404u) = cpu->edx;
    goto label_0001E8C8;
    label_0001E95D:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x408u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0001E8C8;
    label_0001E98A:
    *(uint8_t*)(cpu->ebp + 0x37B8u) = cpu->ebx & 0xFFu;
    goto label_0001E918;
}
__declspec(noinline) void sfera_sub_0041EC70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x410u);
    if (cpu->eax != 0u) goto label_0001EC80;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001EC80:
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x41EC85u));
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp) != 0x103u);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041ECA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37B0u) >= (int32_t)0u) goto label_0001ECB5;
    label_0001ECAD:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001ECB5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x410u);
    if (cpu->eax == 0u) goto label_0001ECAD;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x41ECC5u));
    if (cpu->eax != 0u) goto label_0001ECDE;
    cpu->edx = 0x191u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\CheckFiles.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1ECDEu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1ECDEu));
    label_0001ECDE:
    if (*(uint32_t*)(cpu->esp + 4u) != 0x103u) goto label_0001ECEF;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001ECEF:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x37A4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_0001ED05;
    *(uint32_t*)(cpu->esi + 0x37A4u) = cpu->ecx;
    label_0001ED05:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37A4u) <= (int32_t)cpu->eax) goto label_0001ED35;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = cpu->esi + 0x494u;
    lift_push32(cpu, cpu->edi);
    label_0001ED20:
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = cpu->edi;
    ++cpu->eax;
    cpu->ecx += 0x84u;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x37A4u)) goto label_0001ED20;
    cpu->edi = lift_pop32(cpu);
    label_0001ED35:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041ED40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x120u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x124u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x130u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37B0u) >= (int32_t)cpu->ebp) goto label_0001ED7C;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0001F02A;
    label_0001ED7C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x37A4u);
    *(uint32_t*)(cpu->esi + 0x37A8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->eax <= (int32_t)cpu->edx) goto label_0001ED94;
    *(uint32_t*)(cpu->esi + 0x37A4u) = cpu->edx;
    label_0001ED94:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37A4u) <= (int32_t)cpu->ebp) goto label_0001F028;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x414u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_0001EDC0:
    cpu->ebx = cpu->edi + 0x40u;
    *(uint32_t*)(cpu->esi + 0x404u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x37B4u) > (int32_t)cpu->ebp) goto label_0001EFFA;
    lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"xupdate"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x41EDDDu));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0001EE66;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0001EDF0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EDF0;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0001EE83;
    (void)cpu;
    label_0001EE00:
    lift_push32(cpu, 0x3Bu); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_strchr_address32(), LIFT_CODE_TOKEN_VA(0x41EE03u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp == 0u) goto label_0001EE63;
    cpu->edi = cpu->ebp;
    cpu->edi -= cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x41EE1Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + cpu->edi + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41EE3Cu)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_VA(0x41EE3Cu));
    cpu->eax = cpu->ebp + 1u;
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->eax;
    label_0001EE43:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EE43;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_0001EE52:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EE52;
    cpu->eax -= cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax != 0u) goto label_0001EE00;
    goto label_0001EE83;
    label_0001EE63:
    lift_push32(cpu, cpu->ebx);
    goto label_0001EE7B;
    label_0001EE66:
    lift_push32(cpu, (uintptr_t)"sphere.exe"); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->edi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41EE76u)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_VA(0x41EE76u));
    lift_push32(cpu, (uintptr_t)"sphereclient.exe");
    label_0001EE7B:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1EE83u)); sfera_sub_0041E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x1EE83u));
    label_0001EE83:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x404u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x408u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_0001EFE4;
    label_0001EEB0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x408u);
    cpu->eax += 8u;
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_0001EEC0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EEC0;
    cpu->eax = cpu->esp + 0x2Cu;
    cpu->ebx = 0u;
    cpu->edx = cpu->eax + 1u;
    label_0001EED3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EED3;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_0001EF0D;
    label_0001EEE0:
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->esp + cpu->ebx + 0x2Cu));
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::tolower), LIFT_CODE_TOKEN_VA(0x41EEE6u));
    *(uint8_t*)(cpu->esp + cpu->ebx + 0x30u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x30u;
    cpu->esp += 4u;
    ++cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_0001EF00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EF00;
    cpu->eax -= cpu->edx;
    if (cpu->ebx < cpu->eax) goto label_0001EEE0;
    label_0001EF0D:
    cpu->eax = cpu->esp + 0x2Cu;
    cpu->edx = cpu->eax + 1u;
    label_0001EF14:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0001EF14;
    cpu->eax -= cpu->edx;
    cpu->ecx = cpu->eax + 1u;
    cpu->edx = cpu->esp + 0x2Cu;
    if (cpu->ecx == 0u) goto label_0001EF4B;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    label_0001EF30:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebx ^= cpu->eax;
    cpu->ebx&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebx * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EF30;
    label_0001EF4B:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x408u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->ecx = 4u;
    cpu->edx = cpu->ebx + 0x108u;
    label_0001EF62:
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebp ^= cpu->eax;
    cpu->ebp&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebp * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EF62;
    cpu->ecx = 4u;
    cpu->edx = cpu->ebx + 0x10Cu;
    label_0001EF90:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebx ^= cpu->eax;
    cpu->ebx&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(cpu->esi + (cpu->ebx * 4u));
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x400u) = cpu->eax;
    if (cpu->ecx != 0u) goto label_0001EF90;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40Cu);
    if (cpu->eax == 0u) goto label_0001EFBF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EFB6u));
    cpu->esp += 4u;
    label_0001EFBF:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x37B4u) == 0u; sub_pred[1] = (int32_t)(*(uint32_t*)(cpu->esi + 0x37B4u)) < (int32_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x408u);
    *(uint32_t*)(cpu->esi + 0x40Cu) = cpu->eax;
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_0001EFE4;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x408u) = cpu->edx;
    if (cpu->edx != 0u) goto label_0001EEB0;
    label_0001EFE4:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40Cu);
    cpu->ebp = 0u;
    if (cpu->eax == cpu->ebp) goto label_0001EFFA;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x41EFF1u));
    cpu->esp += 4u;
    label_0001EFFA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x400u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = cpu->ecx;
    ++cpu->eax;
    cpu->edi += 0x84u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x37A4u)) goto label_0001EDC0;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001F028:
    cpu->eax = 0u;
    label_0001F02A:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x120u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x37B0u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x37B4u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x410u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41F06Eu)); sfera_sub_0041E280(cpu, LIFT_CODE_TOKEN_VA(0x41F06Eu));
    cpu->eax = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::Sleep);
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::GetExitCodeThread);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x37B4u) = 1u;
    label_0001F0A0:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x410u);
    if (cpu->eax == 0u) goto label_0001F0C5;
    cpu->ecx = cpu->esp + 0xCu;

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetExitCodeThread)))(cpu->eax, cpu->ecx);
    if (*(uint32_t*)(cpu->esp + 0xCu) != 0x103u) goto label_0001F0C5;

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x3E8u);
    goto label_0001F0A0;
    label_0001F0C5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041F0D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 4u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_check_files_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->esi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->eax)))));
    *(uint32_t*)(cpu->esi + 0x410u) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax != 0u) goto label_0001F0FD;
    cpu->eax = 2u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001F0FD:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetThreadPriority), LIFT_CODE_TOKEN_VA(0x41F100u));
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

























__declspec(noinline) void sfera_sub_00421710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_execution_monitor_runtime;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00421720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0xDu) == 0u) goto label_0002174A;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x44u;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x42172Eu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x421743u));
    cpu->edi = lift_pop32(cpu);
    label_0002174A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x418u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebp + 0x4000u) != cpu->esi) goto label_00022253;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x4014u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42202Eu));
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42203Eu));
    *(uint32_t*)(cpu->ebp + 0x4008u) = 0xFFFFFFFFu;
    cpu->eax = 0x5C63626Du;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->esp += 0x18u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    cpu->ebx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    label_00022075:
    if (*(uint8_t*)(cpu->ebx) == 0u) goto label_00022105;
    cpu->eax = 0u;
    label_00022080:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x24u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022080;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->ebx;
    label_00022091:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022091;
    cpu->edi = cpu->esp + 0x24u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_000220A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000220A0;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x24u;
    --cpu->eax;
    label_000220C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000220C0;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((int32_t)cpu->esi <= 0) goto label_00022105;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_00022105:
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->ebx += 0x8D8u;
    if ((int32_t)cpu->ebx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022075;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_00022251;
    lift_push32(cpu, 0x6Fu);
    cpu->ecx = cpu->eax * 8u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42213Du)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x42213Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x70u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    *(uint32_t*)(cpu->ebp + 0x4000u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x422153u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x422153u));
    cpu->edx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    *(uint32_t*)(cpu->ebp + 0x4004u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    label_00022166:
    if (*(uint8_t*)(cpu->edx) == 0u) goto label_0002223B;
    cpu->eax = 0u;
    label_00022171:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x24u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022171;
    cpu->eax = cpu->edx;
    label_00022180:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022180;
    cpu->edi = cpu->esp + 0x24u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00022190:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00022190;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x24u;
    --cpu->eax;
    label_000221B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000221B0;
    cpu->ecx = 0x6264612Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((cpu->esi==0u) || (((cpu->esi)&0x80000000u)!=0u)) goto label_00022237;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esi;
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebx + cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx >>= 2u;
    *(uint32_t*)(cpu->ebx + cpu->eax + 4u) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ebx + cpu->ecx + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4004u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->ebx += 8u;
    label_00022237:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0002223B:
    cpu->edx += 0x8D8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022166;
    label_00022251:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00022253:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (*(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) == cpu->eax) goto label_000223D2;
    if (*(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag)) == 3u) goto label_000223D2;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int16_t)((uint16_t)(cpu->eax)) >= (int16_t)(*(uint16_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)))) goto label_000223D2;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids);
    cpu->edx = cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    (void)cpu;
    label_000222C0:
    cpu->eax = *(uint16_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->eax * 4u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00022380;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4000u);
    cpu->edi = *(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi += *(uint32_t*)(cpu->ebp);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if ((int32_t)cpu->edx <= 0) goto label_00022380;
    cpu->ebp = cpu->eax * 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    label_00022300:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4004u);
    cpu->esi = *(uint32_t*)(cpu->eax + cpu->ebp);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    cpu->ebp += 8u;
    if (*(uint32_t*)(cpu->esi + cpu->edi) == 0xDEEDDEEDu) goto label_00022344;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + cpu->edi) = 0xDEEDDEEDu;
    cpu->eax = *(uint16_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42233Du)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x42233Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022344:
    if (*(uint8_t*)(cpu->ebx + cpu->edi) == 0xDEu) goto label_00022372;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->ebx + cpu->edi) = 0xDEu;
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42236Bu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x42236Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022372:
    --*(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != 0u) goto label_00022300;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00022380:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = (int16_t)(*(uint16_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->ecx += 2u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000222C0;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x18u) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000223D2;
    if (*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error == 0u) goto label_000223D2;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4223C0u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x4223C0u));
    cpu->ecx = (uintptr_t)"Memory Error! See at Warnings.log";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4223CAu)); sfera_sub_0044C0A0(cpu, LIFT_CODE_TOKEN_VA(0x4223CAu));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x223CCu));
    label_000223D2:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004223E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x4008u);
    if (cpu->esi == 0xFFFFFFFFu) goto label_000225DB;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->eax * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->edi + (cpu->ecx * 4u));
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_00022431;
    cpu->edx = 0xF5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x22431u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x22431u));
    label_00022431:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4000u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4010u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = cpu->eax + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->edx * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset));
    cpu->ebx += *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    label_00022460:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x4004u);
    cpu->ebp = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 4u);
    cpu->ecx += 2u;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + cpu->ebp) == 0xDEEDDEEDu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (sub_pred[0]) goto label_000224BB;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + cpu->ebp) = 0xDEEDDEEDu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->eax * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4224B0u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x4224B0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224BB:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) == 0xDEu) goto label_000224F4;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + cpu->ebx) = 0xDEu;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0x2D4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4224EDu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x4224EDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224F4:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    ++*(uint32_t*)(cpu->edi + 0x4010u);
    if (*(uint32_t*)(cpu->edi + 0x4010u) != cpu->edx) goto label_000225A3;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->edi + 0x4010u) = cpu->edx;
    label_00022520:
    ++cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x400Cu) = cpu->ecx;
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    if (cpu->ecx != cpu->eax) goto label_0002256A;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x4008u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->edi + 0x400Cu) = cpu->edx;
    label_00022540:
    sub_pred[1] = cpu->eax == (uint32_t)(g_sfera_mbc_runtime->process_chain_last);
    cpu->eax = g_sfera_mbc_runtime->process_chain_first;
    if (sub_pred[1]) goto label_00022550;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    label_00022550:
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    *(uint32_t*)(cpu->edi + 0x4008u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag)) == 3u) goto label_00022540;
    label_0002256A:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u) + 0x2D4u);
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->eax * 4u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00022520;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 0x324u);
    cpu->ebx += *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ecx = cpu->eax;
    label_000225A3:
    if ((--*(uint32_t*)(cpu->esp + 0x24u)) != 0u) goto label_00022460;
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x14u) == 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[2]) goto label_000225DB;
    if (*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error == 0u) goto label_000225DB;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4225C9u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x4225C9u));
    cpu->ecx = (uintptr_t)"Memory Error! See at Warnings.log";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4225D3u)); sfera_sub_0044C0A0(cpu, LIFT_CODE_TOKEN_VA(0x4225D3u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x225D5u));
    label_000225DB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004225F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) == 0xFFFFFFFFu) goto label_00022611;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_00022611:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422620(LiftCpu* cpu, uint32_t stop_address) {
    *(uint32_t*)(cpu->ecx + 0x4008u) = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->ecx + 0x4008u)) goto label_0002265D;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) == 0xFFFFFFFFu) goto label_0002265D;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_0002265D:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x4008u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000226AF;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += *(uint32_t*)(cpu->ecx + 0x400Cu);
    cpu->eax = *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if (cpu->edx != cpu->eax) goto label_000226AF;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) == 0xFFFFFFFFu) goto label_000226AF;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_000226AF:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004226C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x414u;
    cpu->eax = 0x5C63626Du;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ebx = 0u;
    cpu->edx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    label_00022700:
    if (*(uint8_t*)(cpu->edx) == 0u) goto label_000228CC;
    if (*(uint32_t*)(cpu->ebp + (cpu->ebx * 4u)) == 0xFFFFFFFFu) goto label_000228CC;
    cpu->eax = 0u;
    label_00022716:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x18u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x20u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022716;
    cpu->eax = cpu->edx;
    label_00022725:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022725;
    cpu->edi = cpu->esp + 0x20u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00022733:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00022733;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x20u;
    --cpu->eax;
    label_00022750:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022750;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((cpu->esi!=0u) && (((cpu->esi)&0x80000000u)==0u)) goto label_0002278F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42278Au)); sfera_sub_00422660(cpu, LIFT_CODE_TOKEN_VA(0x42278Au));
    goto label_000228CC;
    label_0002278F:
    cpu->edx = *(uint32_t*)(cpu->ebp + (cpu->ebx * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->ecx = cpu->esi;
    cpu->ecx >>= 3u;
    if (cpu->ecx == *(uint32_t*)(cpu->eax + (cpu->edx * 8u))) goto label_000227B0;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227ABu)); sfera_sub_00422660(cpu, LIFT_CODE_TOKEN_VA(0x4227ABu));
    goto label_000228CC;
    label_000227B0:
    lift_push32(cpu, 0x19Au);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4227C1u));
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x20u;
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->edx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4004u);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    cpu->edx = cpu->ebx;
    if (cpu->esi < 4u) goto label_00022817;
    label_00022803:
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_0002281F;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if (cpu->esi >= 4u) goto label_00022803;
    label_00022817:
    if (cpu->esi == 0u) goto label_000228B7;
    label_0002281F:
    cpu->eax = *(uint8_t*)(cpu->edx);
    cpu->edi = *(uint8_t*)(cpu->ecx);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 1u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 1u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 1u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 2u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 2u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 2u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 3u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 3u);
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->eax -= cpu->ecx;
    label_0002285E:
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->eax|=1u;
    if (cpu->eax==0u) goto label_000228B7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4008u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000228B7;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0x400Cu);
    cpu->eax = *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if (cpu->edx != cpu->eax) goto label_000228B7;
    cpu->ecx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ebp + (cpu->ecx * 4u)) == 0xFFFFFFFFu) goto label_000228B7;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ebp + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x4010u) = cpu->eax;
    label_000228B7:
    lift_push32(cpu, 0x1A1u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4228C8u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4228C8u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000228CC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += 0x8D8u;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022700;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}




























} // namespace lifted
