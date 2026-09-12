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









} // namespace lifted
