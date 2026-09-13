#include "lifted_functions.h"
#include <cmath>
#include <cstddef>
#include <cstring>
#include <filesystem>
#include <vector>
namespace lifted {

static void sfera_u32_to_sso_decimal(LiftCpu* cpu) {
    const uint32_t destination = cpu->ecx;
    uint32_t value = *(uint32_t*)(cpu->edx);
    uint8_t reversed[16]{};
    std::size_t length = 0u;
    do {
        reversed[length++] = static_cast<uint8_t>('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);
    for (std::size_t index = 0u; index != 16u; ++index) {
        const uint8_t output = index < length ? reversed[length - index - 1u] : 0u;
        *(uint8_t*)(destination + static_cast<uint32_t>(index)) = output;
    }
    *(uint32_t*)(destination + 0x10u) = static_cast<uint32_t>(length);
    *(uint32_t*)(destination + 0x14u) = 15u;
    cpu->eax = destination;
}

} // namespace lifted
