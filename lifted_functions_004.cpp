#include "lifted_functions.h"
#include <cmath>
#include <cstdio>
namespace lifted {


static uint8_t sfera_ascii_lower(uint8_t value) { return value >= 'A' && value <= 'Z' ? (uint8_t)(value + ('a' - 'A')) : value; }
static uint32_t sfera_ascii_hash_ci(uint32_t address) { uint32_t hash = UINT32_C(2166136261); for (;;) { const uint8_t value = *(uint8_t*)(address++); if (value == 0u) { return hash; } hash = (hash ^ sfera_ascii_lower(value)) * UINT32_C(16777619); } }
static int sfera_ascii_iequals(uint32_t address, const char* literal) { for (;;) { const uint8_t left = sfera_ascii_lower(*(uint8_t*)(address++)); const uint8_t right = sfera_ascii_lower((uint8_t)*literal++); if (left != right) { return 0; } if (left == 0u) { return 1; } } }
static int sfera_process_name_is_ignored(uint32_t address) { switch (sfera_ascii_hash_ci(address)) { case 0xCB320621u: return sfera_ascii_iequals(address, "[System Process]"); case 0xC301CF93u: return sfera_ascii_iequals(address, "idle"); case 0xF84B2A97u: return sfera_ascii_iequals(address, "csrss.exe"); case 0xDE6F2DFEu: return sfera_ascii_iequals(address, "winlogon.exe"); case 0x86049695u: return sfera_ascii_iequals(address, "smss.exe"); case 0x28FDCADBu: return sfera_ascii_iequals(address, "services.exe"); case 0x523B71BAu: return sfera_ascii_iequals(address, "service.exe"); case 0x6105AD4Fu: return sfera_ascii_iequals(address, "lsass.exe"); case 0x82611D84u: return sfera_ascii_iequals(address, "taskmgr.exe"); case 0x491E0A9Cu: return sfera_ascii_iequals(address, "system"); case 0x2453F3B9u: return sfera_ascii_iequals(address, "svchost.exe"); case 0xC979C6AEu: return sfera_ascii_iequals(address, "cdantsrv.exe"); case 0x6369D323u: return sfera_ascii_iequals(address, "spoolsv.exe"); case 0xA162EC55u: return sfera_ascii_iequals(address, "mdm.exe"); case 0x48545BE6u: return sfera_ascii_iequals(address, "nvsvc32.exe"); case 0x708EA5E0u: return sfera_ascii_iequals(address, "far.exe"); case 0x130CD4F6u: return sfera_ascii_iequals(address, "regsvc32.exe"); case 0xA11E0AEu: return sfera_ascii_iequals(address, "mstask.exe"); case 0xABDAFF7Eu: return sfera_ascii_iequals(address, "winmgmt.exe"); case 0x8AE4CC97u: return sfera_ascii_iequals(address, "stisvc.exe"); case 0xDB3A61B5u: return sfera_ascii_iequals(address, "rundll32.exe"); case 0xE566D06Eu: return sfera_ascii_iequals(address, "wcescoomm.exe"); case 0xA062BD36u: return sfera_ascii_iequals(address, "internat.exe"); case 0x5037C1B7u: return sfera_ascii_iequals(address, "winword.exe"); case 0x399460A4u: return sfera_ascii_iequals(address, "explorer.exe"); case 0xB884A32Cu: return sfera_ascii_iequals(address, "notepad.exe"); case 0x82407190u: return sfera_ascii_iequals(address, "ctfmon.exe"); case 0xFFB78D72u: return sfera_ascii_iequals(address, "icq.exe"); case 0x3BC05E55u: return sfera_ascii_iequals(address, "iexplore.exe"); case 0x8C6DE00Au: return sfera_ascii_iequals(address, "srvany.exe"); case 0x47785D4Cu: return sfera_ascii_iequals(address, "spidernt.exe"); case 0xF7D48DE3u: return sfera_ascii_iequals(address, "winamp.exe"); case 0xD391162Bu: return sfera_ascii_iequals(address, "kav.exe"); case 0x83888858u: return sfera_ascii_iequals(address, "winrar.exe"); case 0x4FB24653u: return sfera_ascii_iequals(address, "kavsvc.exe"); case 0x73D09132u: return sfera_ascii_iequals(address, "ati2evxx.exe"); case 0x796F943u: return sfera_ascii_iequals(address, "regsvc.exe"); case 0x51E34A6Eu: return sfera_ascii_iequals(address, "mspmspsv.exe"); case 0x94FF76ADu: return sfera_ascii_iequals(address, "resetservice.exe"); case 0x17B4BBA5u: return sfera_ascii_iequals(address, "directcd.exe"); case 0x5AB899A3u: return sfera_ascii_iequals(address, "qttask.exe"); case 0x91BFD53Cu: return sfera_ascii_iequals(address, "atiptaxx.exe"); case 0x681423EEu: return sfera_ascii_iequals(address, "SOUNDMAN.EXE"); case 0x4DF48812u: return sfera_ascii_iequals(address, "wuauclt.exe"); case 0x5ECB2F2Cu: return sfera_ascii_iequals(address, "miranda32.exe"); case 0xB7110726u: return sfera_ascii_iequals(address, "sphere.exe"); case 0xBB309AE5u: return sfera_ascii_iequals(address, "cmd.exe"); case 0xEDFBE74Au: return sfera_ascii_iequals(address, "calc.exe"); case 0x5D2A3611u: return sfera_ascii_iequals(address, "thebat.exe"); default: return 0; } }


__declspec(noinline) void sfera_sub_0042A290(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x10u) == cpu->edi) goto label_0002A2B8;
    cpu->edx = cpu->edi + 0x48u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    label_0002A2B8:
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx -= *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    cpu->ebx = (int32_t)(cpu->ebx) >> 2u;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->edi) goto label_0002A2F2;
    label_0002A2D0:
    cpu->edx = 0x4Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    ++cpu->edi;
    cpu->esp += 4u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_0002A2D0;
    label_0002A2F2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->edi == cpu->ecx) goto label_0002A31A;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ebx = cpu->eax * 4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x42A30Cu));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    label_0002A31A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0042B7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0042E080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x174u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x17Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 2u);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::CreateToolhelp32Snapshot), LIFT_CODE_TOKEN_VA(0x42E0A4u));
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if (cpu->edi == 0xFFFFFFFFu) goto label_0002E0D2;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x128u;
    lift_native_call(cpu, native_function_address32(&::Process32First), LIFT_CODE_TOKEN_VA(0x42E0C2u));
    if (cpu->eax != 0u) goto label_0002E0DA;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x2E0CCu));
    label_0002E0D2:
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0002E1A7;
    label_0002E0DA:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_0002E0E0:
    if (sfera_process_name_is_ignored(cpu->esp + 0x38u)) { goto label_0002E180; }
    label_0002E15E:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x42E16Cu));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + cpu->ebp + 0xFFFFFFFFu) = 0u;
    cpu->esi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_0002E180:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::Process32Next), LIFT_CODE_TOKEN_VA(0x42E18Au));
    if (cpu->eax != 0u) goto label_0002E0E0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x42E19Cu));
    cpu->eax = 1u;
    label_0002E1A7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x174u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E210(LiftCpu* cpu, uint32_t stop_address) {
    auto* self = reinterpret_cast<COutputLogDevice*>(cpu->ecx);
    std::construct_at(self);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(self));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E250(LiftCpu* cpu, uint32_t stop_address) {
    auto* self = reinterpret_cast<COutputLogDevice*>(cpu->ecx);
    self->~COutputLogDevice();
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E2F0(LiftCpu* cpu, uint32_t stop_address) {
    auto* self = reinterpret_cast<COutputLogDevice*>(cpu->ecx);
    self->setFilename(reinterpret_cast<const char*>(*(uint32_t*)(cpu->esp + 4u)));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E440(LiftCpu* cpu, uint32_t stop_address) {
    auto* self = reinterpret_cast<CSphereError*>(cpu->ecx);
    std::construct_at(self);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(self));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    if (cpu->eax != 0u) goto label_0002E5B8;
    cpu->edx = 0xE9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 8u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_0002E5AB;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E5A9u)); sfera_sub_0042E440(cpu, LIFT_CODE_TOKEN_VA(0x42E5A9u));
    goto label_0002E5AD;
    label_0002E5AB:
    cpu->eax = 0u;
    label_0002E5AD:
    *(uint32_t*)(cpu->esp + 0x10u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0002E5B8:
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax != 0u) goto label_0002E610;
    cpu->edx = 0xF1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0xCu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->eax == 0u) goto label_0002E5F4;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E5F2u)); sfera_sub_0042E210(cpu, LIFT_CODE_TOKEN_VA(0x42E5F2u));
    goto label_0002E5F6;
    label_0002E5F4:
    cpu->eax = 0u;
    label_0002E5F6:
    lift_push32(cpu, (uintptr_t)"sphere.log");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E60Du)); sfera_sub_0042E2F0(cpu, LIFT_CODE_TOKEN_VA(0x42E60Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    label_0002E610:
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x10u) = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E6B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ebx;
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E6D0u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0002E73C;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6E7u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x42E6E7u));
    cpu->ebx = cpu->esp;
    if (*(uint8_t*)(cpu->ebp + 0xCu) == 0u) goto label_0002E701;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 2u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x42E6F8u));
    cpu->esp += 0xCu;
    label_0002E701:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42E709u));
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E713u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n%s\n->\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E723u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x42E731u));
    cpu->esp += 0x30u;
    goto label_0002E74C;
    label_0002E73C:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"\n%s not found!\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E743u));
    cpu->esp += 0xCu;
    label_0002E74C:
    cpu->esp = cpu->ebp + 0xFFFFFFECu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::fopen);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(cpu->eax, (uintptr_t)"r");

    if (cpu->eax == 0u) goto label_0002E844;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fclose);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = (uintptr_t)"client-Crash.1";
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->edi = native_function_address32(&::remove);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi == 0u) goto label_0002E82E;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x3E8u);
    cpu->edx = (uintptr_t)"ERRORLOG.TXT";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E7CAu)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E7CAu));

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))((uintptr_t)"ERRORLOG.TXT");

    lift_push32(cpu, 1u); lift_push32(cpu, 0x258u);
    cpu->edx = (uintptr_t)"Error.log";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E7E7u)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E7E7u));

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))((uintptr_t)"Error.log");

    lift_push32(cpu, 1u); lift_push32(cpu, 0xC8u);
    cpu->edx = (uintptr_t)"Warnings00.log";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E804u)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E804u));
    lift_push32(cpu, (uintptr_t)"Warnings00.log");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    cpu->edx = (uintptr_t)"error-Cause.1";
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x32u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E81Fu)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E81Fu));
    cpu->edx = (uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 8u;
    label_0002E82E:
    cpu->eax = (uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002E844:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x104u;
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_access), LIFT_CODE_TOKEN_VA(0x42E86Cu));
    cpu->esp += 8u;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0002E904;
    cpu->ecx = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42E885u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0002E904;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x42E894u));
    cpu->edx = (uintptr_t)"error-Cause.1";
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E8A8u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0002E902;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strerror), LIFT_CODE_TOKEN_VA(0x42E8B8u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"File %s not deleted (~), error cause: %s\n"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x42E8CFu));
    cpu->eax = cpu->esp + 0x1Cu;
    cpu->esp += 0x14u;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0002E8E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002E8E0;
    lift_push32(cpu, cpu->esi);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x42E8F2u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E8F9u));
    cpu->esp += 0x14u;
    label_0002E902:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0002E904:
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_file_runtime.crash_report_instance;
    if (cpu->eax != 0u) goto label_0002E981;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x12Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\FastCrashReport.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    if (cpu->esi == 0u) goto label_0002E979;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E94Eu)); sfera_sub_0042E770(cpu, LIFT_CODE_TOKEN_VA(0x42E94Eu));
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E959u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0002E970;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E967u));
    cpu->esp += 4u;
    label_0002E970:
    cpu->eax = cpu->esi;
    g_sfera_file_runtime.crash_report_instance = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002E979:
    cpu->eax = 0u;
    g_sfera_file_runtime.crash_report_instance = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_0002E981:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x810u;
    cpu->eax = (uintptr_t)"client-Crash.1";
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E9B0u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0002EA68;
    lift_push32(cpu, 0x800u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42E9CFu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_0002E9E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_error_log_runtime.index_table[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x11u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002E9E0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x77Bu);
    cpu->edx = cpu->esp + 0x9Du;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0x20u) = 3u;
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42EA04u));
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xA5u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42EA12u));
    cpu->esp += 0x14u;
    { auto* client = g_sfera_directplay_runtime.peer; DWORD async_handle = 0u; const SferaDpnBufferDescRuntime buffer{0x800u, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->esp + 0x10u))}; if (client) cpu->eax = static_cast<uint32_t>(client->Send(&buffer, 1u, 0x2BF20u, nullptr, &async_handle, 0xB8u)); }
    cpu->ecx = (uintptr_t)"client-Crash.1";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42EA5Fu));
    cpu->esp += 4u;
    label_0002EA68:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x810u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EB70(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_file_runtime.crash_report_instance == 0u) goto label_0002EBAE;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x136u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\FastCrashReport.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = g_sfera_file_runtime.crash_report_instance;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0002EBA3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42EB9Au)); sfera_sub_0042E850(cpu, LIFT_CODE_TOKEN_VA(0x42EB9Au));
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0002EBA3:
    g_sfera_file_runtime.crash_report_instance = 0u;
    cpu->esi = lift_pop32(cpu);
    label_0002EBAE:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
