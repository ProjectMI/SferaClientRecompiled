#pragma once

#include <stddef.h>
#include <stdint.h>

#if defined(_MSC_VER)
#define LIFT_CDECL __cdecl
#define LIFT_NORETURN __declspec(noreturn)
#define LIFT_ENTRY __declspec(noinline)
#elif defined(__cplusplus)
#define LIFT_CDECL
#define LIFT_NORETURN [[noreturn]]
#define LIFT_ENTRY __attribute__((noinline))
#else
#define LIFT_CDECL
#define LIFT_NORETURN _Noreturn
#define LIFT_ENTRY __attribute__((noinline))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define LIFT_FLAG_CF UINT32_C(0x00000001)
#define LIFT_FLAG_PF UINT32_C(0x00000004)
#define LIFT_FLAG_AF UINT32_C(0x00000010)
#define LIFT_FLAG_ZF UINT32_C(0x00000040)
#define LIFT_FLAG_SF UINT32_C(0x00000080)
#define LIFT_FLAG_DF UINT32_C(0x00000400)
#define LIFT_FLAG_OF UINT32_C(0x00000800)
#define LIFT_CALLBACK_SENTINEL UINT32_C(0xFFF0FFF0)

typedef struct SferaGuid32 { uint32_t data1; uint16_t data2; uint16_t data3; uint8_t data4[8]; } SferaGuid32;
typedef struct SferaDIDataFormat32 { uint32_t size; uint32_t object_size; uint32_t flags; uint32_t data_size; uint32_t object_count; uint32_t object_formats; } SferaDIDataFormat32;
typedef struct SferaDIObjectDataFormat32 { uint32_t object_guid; uint32_t offset; uint32_t type; uint32_t flags; } SferaDIObjectDataFormat32;
typedef struct SferaMsvcVbtable2 { int32_t self_offset; int32_t virtual_base_offset; } SferaMsvcVbtable2;
typedef union SferaMsvcStringStorage32 { char inline_buffer[16]; uint32_t heap_pointer; } SferaMsvcStringStorage32;
typedef struct SferaMsvcString32 { SferaMsvcStringStorage32 storage; uint32_t size; uint32_t capacity; } SferaMsvcString32;

typedef struct LiftCpu {
    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;
    uint32_t esp;
    uint32_t ebp;
    uint32_t esi;
    uint32_t edi;
    uint32_t eip;
    uint32_t eflags;
    uint32_t stack_base;
    uint32_t stack_limit;
    double fpu[8];
    uint8_t fpu_depth;
    uint8_t fpu_top;
    uint16_t fpu_control;
    uint16_t fpu_status;
    uint16_t reserved;
    uint8_t fs_data[64];
} LiftCpu;

#if defined(__cplusplus)
static_assert(offsetof(SferaMsvcString32, size) == 16, "SferaMsvcString32.size ABI offset changed");
static_assert(offsetof(SferaMsvcString32, capacity) == 20, "SferaMsvcString32.capacity ABI offset changed");
static_assert(sizeof(SferaMsvcString32) == 24, "SferaMsvcString32 ABI size changed");
static_assert(offsetof(LiftCpu, eax) == 0, "LiftCpu.eax ABI offset changed");
static_assert(offsetof(LiftCpu, eflags) == 36, "LiftCpu.eflags ABI offset changed");
static_assert(offsetof(LiftCpu, stack_base) == 40, "LiftCpu.stack_base ABI offset changed");
static_assert(offsetof(LiftCpu, stack_limit) == 44, "LiftCpu.stack_limit ABI offset changed");
static_assert(offsetof(LiftCpu, fpu_control) == 114, "LiftCpu.fpu_control ABI offset changed");
static_assert(offsetof(LiftCpu, fs_data) == 120, "LiftCpu.fs_data ABI offset changed");
static_assert(sizeof(LiftCpu) == 184, "LiftCpu ABI size changed");
#else
_Static_assert(offsetof(SferaMsvcString32, size) == 16, "SferaMsvcString32.size ABI offset changed");
_Static_assert(offsetof(SferaMsvcString32, capacity) == 20, "SferaMsvcString32.capacity ABI offset changed");
_Static_assert(sizeof(SferaMsvcString32) == 24, "SferaMsvcString32 ABI size changed");
_Static_assert(offsetof(LiftCpu, eax) == 0, "LiftCpu.eax ABI offset changed");
_Static_assert(offsetof(LiftCpu, eflags) == 36, "LiftCpu.eflags ABI offset changed");
_Static_assert(offsetof(LiftCpu, stack_base) == 40, "LiftCpu.stack_base ABI offset changed");
_Static_assert(offsetof(LiftCpu, stack_limit) == 44, "LiftCpu.stack_limit ABI offset changed");
_Static_assert(offsetof(LiftCpu, fpu_control) == 114, "LiftCpu.fpu_control ABI offset changed");
_Static_assert(offsetof(LiftCpu, fs_data) == 120, "LiftCpu.fs_data ABI offset changed");
_Static_assert(sizeof(LiftCpu) == 184, "LiftCpu ABI size changed");
#endif

typedef void (LIFT_CDECL *LiftFunction)(LiftCpu* cpu, uint32_t stop_address);


uint32_t LIFT_CDECL lift_callback_address_rva(uint32_t rva);
uint32_t LIFT_CDECL lift_process_module_handle(void);
int LIFT_CDECL lift_has_function_rva(uint32_t rva);
uint8_t LIFT_CDECL lift_load8(uint32_t address);
uint16_t LIFT_CDECL lift_load16(uint32_t address);
uint32_t LIFT_CDECL lift_load32(uint32_t address);
uint64_t LIFT_CDECL lift_load64(uint32_t address);
float LIFT_CDECL lift_load_f32(uint32_t address);
double LIFT_CDECL lift_load_f64(uint32_t address);
void LIFT_CDECL lift_store8(uint32_t address, uint8_t value);
void LIFT_CDECL lift_store16(uint32_t address, uint16_t value);
void LIFT_CDECL lift_store32(uint32_t address, uint32_t value);
void LIFT_CDECL lift_store64(uint32_t address, uint64_t value);
void LIFT_CDECL lift_store_f32(uint32_t address, float value);
void LIFT_CDECL lift_store_f64(uint32_t address, double value);
uint8_t LIFT_CDECL lift_fs_load8(const LiftCpu* cpu, uint32_t offset);
uint16_t LIFT_CDECL lift_fs_load16(const LiftCpu* cpu, uint32_t offset);
uint32_t LIFT_CDECL lift_fs_load32(const LiftCpu* cpu, uint32_t offset);
void LIFT_CDECL lift_fs_store8(LiftCpu* cpu, uint32_t offset, uint8_t value);
void LIFT_CDECL lift_fs_store16(LiftCpu* cpu, uint32_t offset, uint16_t value);
void LIFT_CDECL lift_fs_store32(LiftCpu* cpu, uint32_t offset, uint32_t value);

void LIFT_CDECL lift_push32(LiftCpu* cpu, uint32_t value);
uint32_t LIFT_CDECL lift_pop32(LiftCpu* cpu);
void LIFT_CDECL lift_flags_add(LiftCpu* cpu, uint64_t left, uint64_t right, uint64_t carry, uint64_t result, uint32_t width);
void LIFT_CDECL lift_flags_sub(LiftCpu* cpu, uint64_t left, uint64_t right, uint64_t borrow, uint64_t result, uint32_t width);
void LIFT_CDECL lift_flags_logic(LiftCpu* cpu, uint64_t result, uint32_t width);
uint64_t LIFT_CDECL lift_shift_left(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_shift_right(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_shift_arithmetic(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_rotate_left(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_rotate_right(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_rotate_carry_right(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_rotate_carry_left(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_double_shift_left(LiftCpu* cpu, uint64_t left, uint64_t right, uint32_t count, uint32_t width);
uint64_t LIFT_CDECL lift_double_shift_right(LiftCpu* cpu, uint64_t left, uint64_t right, uint32_t count, uint32_t width);
void LIFT_CDECL lift_multiply_accumulator(LiftCpu* cpu, uint64_t source, uint32_t width, uint32_t is_signed);
void LIFT_CDECL lift_divide_accumulator(LiftCpu* cpu, uint64_t divisor, uint32_t width, uint32_t is_signed);

double LIFT_CDECL lift_x87_get(const LiftCpu* cpu, uint32_t index);
void LIFT_CDECL lift_x87_set(LiftCpu* cpu, uint32_t index, double value);
void LIFT_CDECL lift_x87_push(LiftCpu* cpu, double value);
void LIFT_CDECL lift_x87_pop(LiftCpu* cpu);
int64_t LIFT_CDECL lift_x87_round(const LiftCpu* cpu, double value, uint32_t truncate);
void LIFT_CDECL lift_x87_compare(LiftCpu* cpu, double left, double right);
void LIFT_CDECL lift_x87_sincos(LiftCpu* cpu);

void LIFT_CDECL lift_movs8(LiftCpu* cpu, uint32_t repeated);
void LIFT_CDECL lift_movs16(LiftCpu* cpu, uint32_t repeated);
void LIFT_CDECL lift_movs32(LiftCpu* cpu, uint32_t repeated);
void LIFT_CDECL lift_stos8(LiftCpu* cpu, uint32_t repeated);
void LIFT_CDECL lift_stos16(LiftCpu* cpu, uint32_t repeated);
void LIFT_CDECL lift_stos32(LiftCpu* cpu, uint32_t repeated);
void LIFT_CDECL lift_cmps8(LiftCpu* cpu, uint32_t repeated, uint32_t repeat_not_equal);
void LIFT_CDECL lift_cmps16(LiftCpu* cpu, uint32_t repeated, uint32_t repeat_not_equal);
void LIFT_CDECL lift_cmps32(LiftCpu* cpu, uint32_t repeated, uint32_t repeat_not_equal);
void LIFT_CDECL lift_scas8(LiftCpu* cpu, uint32_t repeated, uint32_t repeat_not_equal);
void LIFT_CDECL lift_scas16(LiftCpu* cpu, uint32_t repeated, uint32_t repeat_not_equal);
void LIFT_CDECL lift_scas32(LiftCpu* cpu, uint32_t repeated, uint32_t repeat_not_equal);

void LIFT_CDECL lift_import_call(LiftCpu* cpu, uint32_t import_address, uint32_t callsite);
void LIFT_CDECL lift_native_call(LiftCpu* cpu, uint32_t target, uint32_t callsite);
uint32_t LIFT_CDECL lift_source_rva(uint32_t address);
uint32_t LIFT_CDECL lift_code_rva(uint32_t address);
uint32_t LIFT_CDECL lift_is_native_code_address(uint32_t address);
LIFT_NORETURN void LIFT_CDECL lift_trap(LiftCpu* cpu, uint32_t source_va, const char* reason);
LIFT_NORETURN void LIFT_CDECL lift_trap_transfer(LiftCpu* cpu, uint32_t origin, uint32_t target, uint32_t esp_before, uint32_t stack_cleanup, uint32_t stop_address, const char* kind);

void LIFT_CDECL lift_initialize_dispatch(void);
void LIFT_CDECL lift_dispatch(LiftCpu* cpu, uint32_t target, uint32_t stop_address);
int LIFT_CDECL lift_call_indirect(LiftCpu* cpu, uint32_t target, uint32_t return_address, uint32_t callsite);
void LIFT_CDECL lift_tail_indirect(LiftCpu* cpu, uint32_t target, uint32_t stop_address, uint32_t callsite);
void LIFT_CDECL lift_return(LiftCpu* cpu, uint32_t stack_cleanup, uint32_t stop_address);
void LIFT_CDECL lift_import_call_return(LiftCpu* cpu, uint32_t import_address, uint32_t callsite, uint32_t stop_address);

#ifdef __cplusplus
}
#endif
