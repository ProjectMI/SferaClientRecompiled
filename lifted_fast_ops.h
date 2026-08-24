#pragma once

#include "lifted_abi.h"

#if defined(_MSC_VER)
#define LIFT_FORCEINLINE static __forceinline
#else
#define LIFT_FORCEINLINE static inline __attribute__((always_inline))
#endif

#define LIFT_SOURCE_TEXT_SIZE UINT32_C(0x000FB200)
#define LIFT_CODE_TOKEN_BASE UINT32_C(0xE0000000)
#define LIFT_CODE_TOKEN_RVA(rva) (LIFT_CODE_TOKEN_BASE + (uint32_t)(rva))
#define LIFT_CODE_TOKEN_VA(source_va) LIFT_CODE_TOKEN_RVA((uint32_t)(source_va) - UINT32_C(0x00400000))
#define LIFT_FUNCTION(function) ((uint32_t)(uintptr_t)(LiftFunction)(function))
#define LIFT_CALLBACK(function) lift_callback_address((LiftFunction)(function))