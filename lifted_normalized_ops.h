#pragma once

#include "lifted_fast_ops.h"
#include "semantic_static.h"
#include "import_bridge.h"
#ifdef __cplusplus
#include <memory>
#endif

#include <oleidl.h>
#include <exdisp.h>
#include <mshtmhst.h>
#include <mshtml.h>

namespace {
	const GUID kDirectPlay8ClientIid = { 0x5102DACD, 0x241B, 0x11D3, {0xAE, 0xA7, 0x00, 0x60, 0x97, 0xB0, 0x14, 0x11} };
	const GUID kDirectPlay8ClientClsid = { 0x743F1DC6, 0x5ABA, 0x429F, {0x8B, 0xDF, 0xC5, 0x4D, 0x03, 0x25, 0x3D, 0xC2} };
	const GUID kDirectPlay8AddressClsid = { 0x934A9523, 0xA3CA, 0x4BC5, {0xAD, 0xA0, 0xD6, 0xD9, 0x5D, 0x97, 0x94, 0x21} };
	const GUID kDirectPlay8AddressIid = { 0x83783300, 0x4063, 0x4C8A, {0x9D, 0xB3, 0x82, 0x83, 0x0A, 0x7F, 0xEB, 0x31} };
	const GUID kDirectPlay8TcpIpProvider = { 0xEBFE7BA0, 0x628D, 0x11D2, {0xAE, 0x0F, 0x00, 0x60, 0x97, 0xB0, 0x14, 0x11} };
}

#define LIFT_ENTER(address) do { cpu->eip = LIFT_CODE_TOKEN_VA((address)); } while (0)
#define LIFT_CALL(function, return_address) do { lift_push32(cpu, (return_address)); function(cpu, (return_address)); if (cpu->eip != (return_address)) return; } while (0)
#define LIFT_RET(pop_bytes) do { lift_return(cpu, (uint32_t)(pop_bytes), stop_address); return; } while (0)
#define LIFT_LOGIC(left_expression, right_expression, operation, width, writeback) do { uint64_t left = (uint64_t)(left_expression); uint64_t right = (uint64_t)(right_expression); uint64_t result = left operation right; lift_flags_logic(cpu, result, (width)); writeback; } while (0)
#define LIFT_STORE32(address, value) lift_store32((uint32_t)(address), (uint32_t)(value))
#define LIFT_STORE8(address, value) lift_store8((uint32_t)(address), (uint8_t)(value))
#define LIFT_X87_STATUS_AX() do { cpu->eax = (cpu->eax & UINT32_C(0xFFFF0000)) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & UINT32_C(0xFFFF)); } while (0)
#define LIFT_X87_COMPARE_POP2_AX() do { lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u)); lift_x87_pop(cpu); lift_x87_pop(cpu); LIFT_X87_STATUS_AX(); } while (0)
#define LIFT_X87_POP_STATUS_AX() do { lift_x87_pop(cpu); LIFT_X87_STATUS_AX(); } while (0)

#define LIFT_X87_POP2() do { lift_x87_pop(cpu); lift_x87_pop(cpu); } while (0)
