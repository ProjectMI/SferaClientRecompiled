#pragma once

#include "lifted_abi.h"
#include "semantic_native.h"

#if defined(_MSC_VER)
#define LIFT_FORCEINLINE static __forceinline
#else
#define LIFT_FORCEINLINE static inline __attribute__((always_inline))
#endif

#define LIFT_SOURCE_TEXT_BEGIN UINT32_C(0x00401000)
#define LIFT_SOURCE_TEXT_SIZE UINT32_C(0x000FB200)
#define LIFT_CODE_TOKEN_BASE UINT32_C(0xE0000000)
#define LIFT_CODE_TOKEN_RVA(rva) (LIFT_CODE_TOKEN_BASE + (uint32_t)(rva))
#define LIFT_CODE_TOKEN_VA(source_va) LIFT_CODE_TOKEN_RVA((uint32_t)(source_va) - UINT32_C(0x00400000))
#define LIFT_CALLBACK_RVA(rva) lift_callback_address_rva((uint32_t)(rva))
#define LIFT_SOURCE_RDATA_BEGIN UINT32_C(0x004FD000)
#define LIFT_SOURCE_RDATA_SIZE UINT32_C(0x00022E00)
#define LIFT_SOURCE_DATA_BEGIN UINT32_C(0x00520000)
#define LIFT_SOURCE_DATA_SIZE UINT32_C(0x04A70790)

LIFT_FORCEINLINE uint32_t lift_fast_source_rva(uint32_t address) { uint32_t offset = address - LIFT_CODE_TOKEN_BASE; if (offset >= UINT32_C(0x00001000) && offset < UINT32_C(0x00001000) + LIFT_SOURCE_TEXT_SIZE) { return offset; } { uint32_t rdata_rva = sfera_rdata_source_rva(address); if (rdata_rva != UINT32_MAX) { return rdata_rva; } } { uint32_t data_rva = sfera_data_source_rva(address); if (data_rva != UINT32_MAX) { return data_rva; } } return lift_source_rva(address); }

LIFT_FORCEINLINE uint8_t lift_fast_load8(uint32_t address) { address = sfera_data_deref_address(address); return *(const uint8_t*)(uintptr_t)address; }
LIFT_FORCEINLINE uint16_t lift_fast_load16(uint32_t address) { address = sfera_data_deref_address(address); return *(const uint16_t*)(uintptr_t)address; }
LIFT_FORCEINLINE uint32_t lift_fast_load32(uint32_t address) { address = sfera_data_deref_address(address); return *(const uint32_t*)(uintptr_t)address; }
LIFT_FORCEINLINE uint64_t lift_fast_load64(uint32_t address) { address = sfera_data_deref_range(address, 8u); return *(const uint64_t*)(uintptr_t)address; }
LIFT_FORCEINLINE float lift_fast_load_f32(uint32_t address) { address = sfera_data_deref_address(address); return *(const float*)(uintptr_t)address; }
LIFT_FORCEINLINE double lift_fast_load_f64(uint32_t address) { address = sfera_data_deref_range(address, 8u); return *(const double*)(uintptr_t)address; }
LIFT_FORCEINLINE void lift_fast_store8(uint32_t address, uint8_t value) { address = sfera_data_deref_address(address); *(uint8_t*)(uintptr_t)address = value; }
LIFT_FORCEINLINE void lift_fast_store16(uint32_t address, uint16_t value) { address = sfera_data_deref_address(address); *(uint16_t*)(uintptr_t)address = value; }
LIFT_FORCEINLINE void lift_fast_store32(uint32_t address, uint32_t value) { address = sfera_data_deref_address(address); *(uint32_t*)(uintptr_t)address = value; }
LIFT_FORCEINLINE void lift_fast_store64(uint32_t address, uint64_t value) { address = sfera_data_deref_range(address, 8u); *(uint64_t*)(uintptr_t)address = value; }
LIFT_FORCEINLINE void lift_fast_store_f32(uint32_t address, float value) { address = sfera_data_deref_address(address); *(float*)(uintptr_t)address = value; }
LIFT_FORCEINLINE void lift_fast_store_f64(uint32_t address, double value) { address = sfera_data_deref_range(address, 8u); *(double*)(uintptr_t)address = value; }
LIFT_FORCEINLINE uint8_t lift_fast_fs_load8(const LiftCpu* cpu, uint32_t offset) { return *(const uint8_t*)(cpu->fs_data + offset); }
LIFT_FORCEINLINE uint16_t lift_fast_fs_load16(const LiftCpu* cpu, uint32_t offset) { return *(const uint16_t*)(const void*)(cpu->fs_data + offset); }
LIFT_FORCEINLINE uint32_t lift_fast_fs_load32(const LiftCpu* cpu, uint32_t offset) { return *(const uint32_t*)(const void*)(cpu->fs_data + offset); }
LIFT_FORCEINLINE void lift_fast_fs_store8(LiftCpu* cpu, uint32_t offset, uint8_t value) { *(uint8_t*)(cpu->fs_data + offset) = value; }
LIFT_FORCEINLINE void lift_fast_fs_store16(LiftCpu* cpu, uint32_t offset, uint16_t value) { *(uint16_t*)(void*)(cpu->fs_data + offset) = value; }
LIFT_FORCEINLINE void lift_fast_fs_store32(LiftCpu* cpu, uint32_t offset, uint32_t value) { *(uint32_t*)(void*)(cpu->fs_data + offset) = value; }
LIFT_FORCEINLINE void lift_fast_push32(LiftCpu* cpu, uint32_t value) { cpu->esp -= 4u; *(uint32_t*)(uintptr_t)cpu->esp = value; }
LIFT_FORCEINLINE uint32_t lift_fast_pop32(LiftCpu* cpu) { uint32_t value = *(const uint32_t*)(uintptr_t)cpu->esp; cpu->esp += 4u; return value; }

LIFT_FORCEINLINE uint64_t lift_fast_width_mask(uint32_t width) { return width == 8u ? UINT64_C(0xFF) : width == 16u ? UINT64_C(0xFFFF) : width == 32u ? UINT64_C(0xFFFFFFFF) : UINT64_MAX; }
LIFT_FORCEINLINE uint64_t lift_fast_sign_bit(uint32_t width) { return width == 8u ? UINT64_C(0x80) : width == 16u ? UINT64_C(0x8000) : width == 32u ? UINT64_C(0x80000000) : UINT64_C(0x8000000000000000); }
LIFT_FORCEINLINE uint32_t lift_fast_parity_flag(uint64_t value) { uint32_t byte = (uint32_t)value & 0xFFu; byte ^= byte >> 4u; byte &= 0xFu; return (((UINT32_C(0x6996) >> byte) & 1u) == 0u) ? LIFT_FLAG_PF : 0u; }
LIFT_FORCEINLINE uint32_t lift_fast_szp_flags(uint64_t value, uint32_t width) { uint64_t truncated = value & lift_fast_width_mask(width); uint32_t flags = lift_fast_parity_flag(truncated); if (truncated == 0u) { flags |= LIFT_FLAG_ZF; } if ((truncated & lift_fast_sign_bit(width)) != 0u) { flags |= LIFT_FLAG_SF; } return flags; }

LIFT_FORCEINLINE uint64_t lift_fast_shift_left(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width) { uint64_t mask = lift_fast_width_mask(width); uint64_t sign = lift_fast_sign_bit(width); count &= 0x1Fu; value &= mask; if (count == 0u) { return value; } uint64_t result = (value << count) & mask; uint32_t flags = lift_fast_szp_flags(result, width); if (count <= width && ((value >> (width - count)) & 1u) != 0u) { flags |= LIFT_FLAG_CF; } if (count == 1u && (((result & sign) != 0u) != ((flags & LIFT_FLAG_CF) != 0u))) { flags |= LIFT_FLAG_OF; } cpu->eflags = (cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_PF | LIFT_FLAG_ZF | LIFT_FLAG_SF | (count == 1u ? LIFT_FLAG_OF : 0u))) | flags; return result; }
LIFT_FORCEINLINE uint64_t lift_fast_shift_right(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width) { uint64_t mask = lift_fast_width_mask(width); uint64_t sign = lift_fast_sign_bit(width); value &= mask; count &= 0x1Fu; if (count == 0u) { return value; } uint64_t result = value >> count; uint32_t flags = lift_fast_szp_flags(result, width); if (count <= width && ((value >> (count - 1u)) & 1u) != 0u) { flags |= LIFT_FLAG_CF; } if (count == 1u && (value & sign) != 0u) { flags |= LIFT_FLAG_OF; } cpu->eflags = (cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_PF | LIFT_FLAG_ZF | LIFT_FLAG_SF | (count == 1u ? LIFT_FLAG_OF : 0u))) | flags; return result; }
LIFT_FORCEINLINE uint64_t lift_fast_shift_arithmetic(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width) { uint64_t mask = lift_fast_width_mask(width); value &= mask; count &= 0x1Fu; if (count == 0u) { return value; } int64_t signed_value; if (width == 8u) { signed_value = (int8_t)value; } else if (width == 16u) { signed_value = (int16_t)value; } else if (width == 32u) { signed_value = (int32_t)value; } else { signed_value = (int64_t)value; } uint64_t result = (uint64_t)(signed_value >> count) & mask; uint32_t flags = lift_fast_szp_flags(result, width); if (count <= width && ((value >> (count - 1u)) & 1u) != 0u) { flags |= LIFT_FLAG_CF; } cpu->eflags = (cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_PF | LIFT_FLAG_ZF | LIFT_FLAG_SF | (count == 1u ? LIFT_FLAG_OF : 0u))) | flags; return result; }

LIFT_FORCEINLINE double lift_fast_x87_get(const LiftCpu* cpu, uint32_t index) { return cpu->fpu[index]; }
LIFT_FORCEINLINE void lift_fast_x87_set(LiftCpu* cpu, uint32_t index, double value) { cpu->fpu[index] = value; }
LIFT_FORCEINLINE void lift_fast_x87_push(LiftCpu* cpu, double value) { uint32_t index = cpu->fpu_depth; while (index != 0u) { cpu->fpu[index] = cpu->fpu[index - 1u]; --index; } cpu->fpu[0] = value; cpu->fpu_top = (uint8_t)((cpu->fpu_top + 7u) & 7u); ++cpu->fpu_depth; }
LIFT_FORCEINLINE void lift_fast_x87_pop(LiftCpu* cpu) { uint32_t index = 1u; while (index < cpu->fpu_depth) { cpu->fpu[index - 1u] = cpu->fpu[index]; ++index; } --cpu->fpu_depth; cpu->fpu_top = (uint8_t)((cpu->fpu_top + 1u) & 7u); }

#define lift_source_rva(value) lift_fast_source_rva((uint32_t)(value))
#define lift_load8(address) lift_fast_load8((uint32_t)(address))
#define lift_load16(address) lift_fast_load16((uint32_t)(address))
#define lift_load32(address) lift_fast_load32((uint32_t)(address))
#define lift_load64(address) lift_fast_load64((uint32_t)(address))
#define lift_load_f32(address) lift_fast_load_f32((uint32_t)(address))
#define lift_load_f64(address) lift_fast_load_f64((uint32_t)(address))
#define lift_store8(address, value) lift_fast_store8((uint32_t)(address), (uint8_t)(value))
#define lift_store16(address, value) lift_fast_store16((uint32_t)(address), (uint16_t)(value))
#define lift_store32(address, value) lift_fast_store32((uint32_t)(address), (uint32_t)(value))
#define lift_store64(address, value) lift_fast_store64((uint32_t)(address), (uint64_t)(value))
#define lift_store_f32(address, value) lift_fast_store_f32((uint32_t)(address), (float)(value))
#define lift_store_f64(address, value) lift_fast_store_f64((uint32_t)(address), (double)(value))
#define lift_fs_load8(cpu, offset) lift_fast_fs_load8((cpu), (uint32_t)(offset))
#define lift_fs_load16(cpu, offset) lift_fast_fs_load16((cpu), (uint32_t)(offset))
#define lift_fs_load32(cpu, offset) lift_fast_fs_load32((cpu), (uint32_t)(offset))
#define lift_fs_store8(cpu, offset, value) lift_fast_fs_store8((cpu), (uint32_t)(offset), (uint8_t)(value))
#define lift_fs_store16(cpu, offset, value) lift_fast_fs_store16((cpu), (uint32_t)(offset), (uint16_t)(value))
#define lift_fs_store32(cpu, offset, value) lift_fast_fs_store32((cpu), (uint32_t)(offset), (uint32_t)(value))
#define lift_push32(cpu, value) lift_fast_push32((cpu), (uint32_t)(value))
#define lift_pop32(cpu) lift_fast_pop32((cpu))
#define lift_shift_left(cpu, value, count, width) lift_fast_shift_left((cpu), (uint64_t)(value), (uint32_t)(count), (uint32_t)(width))
#define lift_shift_right(cpu, value, count, width) lift_fast_shift_right((cpu), (uint64_t)(value), (uint32_t)(count), (uint32_t)(width))
#define lift_shift_arithmetic(cpu, value, count, width) lift_fast_shift_arithmetic((cpu), (uint64_t)(value), (uint32_t)(count), (uint32_t)(width))
#define lift_x87_get(cpu, index) lift_fast_x87_get((cpu), (uint32_t)(index))
#define lift_x87_set(cpu, index, value) lift_fast_x87_set((cpu), (uint32_t)(index), (double)(value))
#define lift_x87_push(cpu, value) lift_fast_x87_push((cpu), (double)(value))
#define lift_x87_pop(cpu) lift_fast_x87_pop((cpu))
