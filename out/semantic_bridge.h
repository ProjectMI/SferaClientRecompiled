#pragma once

#include "lifted_abi.h"

#ifdef __cplusplus
extern "C" {
#endif

int LIFT_CDECL semantic_bridge_try_invoke(LiftCpu* cpu, uint32_t source_va, uint32_t stop_address);

#ifdef __cplusplus
}
#endif
