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
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
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
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
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
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->ecx)->transformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
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
