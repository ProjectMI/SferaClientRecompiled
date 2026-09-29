#include <windows.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fcntl.h>
#include <format>
#include <io.h>
#include <iterator>
#include <list>
#include <memory>
#include <mmsystem.h>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "application/ClientApplication.h"
#include "binary/Binary.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "effects/EffectManager.h"
#include "input/DirectInputDevices.h"
#include "lifetime/Restore.h"
#include "network/Network.h"
#include "numeric/Numeric.h"
#include "players/PlayerLists.h"
#include "resources/FileResources.h"
#include "script/ConfigText.h"
#include "script/MbcBitStream.h"
#include "script/MbcCommands.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/MbcValue.h"
#include "script/ScriptContainer.h"
#include "ui/GameInterfaceManager.h"
#include "ui/ScriptInterface.h"
#include "ui/Window.h"
#include "world/GameCalendar.h"
#include "world/WorldObjects.h"

bool SferaMbcRuntime::executeInstruction(SferaMbcRuntimeInstruction instruction)
{
    auto &stack = g_sfera_mbc_runtime.values;
    switch (instruction)
    {
    case SferaMbcRuntimeInstruction::InvokeBuiltin:
    {
        const auto function = readOperand<SferaMbcRuntimeBuiltin>();
        argument_end = value_stack_size;
        value_stack_size -= argument_count;
        argument_cursor = value_stack_size;
        if (!executeBuiltin(function))
            throw std::runtime_error("unsupported MBInter bytecode opcode");
        break;
    }
    case SferaMbcRuntimeInstruction::ReturnFunction:
        returnFromFunction();
        break;
    case SferaMbcRuntimeInstruction::BindParameters:
        bindParameters();
        break;
    case SferaMbcRuntimeInstruction::DispatchCommand:
        break; // No queued-command producer in this executable; retain opcode 201 as a no-op.
    case SferaMbcRuntimeInstruction::LoadVariable:
    {
        const auto type = readOperand<SferaMbcValueType>();
        const auto offset = readOperand<std::uint32_t>();
        const std::uint32_t width = type == SferaMbcValueTypeByte                                       ? std::uint32_t{sizeof(std::int8_t)}
                                    : type == SferaMbcValueTypeInteger || type == SferaMbcValueTypeReal ? std::uint32_t{sizeof(std::uint32_t)}
                                                                                                        : std::uint32_t{sizeof(SferaSliceReference32)};
        pushReference(type, {offset, offset, offset + width - 1u}, true);
        if (type == SferaMbcValueTypeAddress)
            stack[value_stack_size - 1].value = readMemory<SferaSliceReference32>(offset);
        break;
    }
    case SferaMbcRuntimeInstruction::JumpIfFalse:
    case SferaMbcRuntimeInstruction::JumpIfFalseShort:
    {
        const auto condition = popInteger();
        const std::ptrdiff_t width = instruction == SferaMbcRuntimeInstruction::JumpIfFalse ? sizeof(int) : sizeof(std::int16_t);
        if (condition)
            instruction_cursor += width;
        else
        {
            const auto offset = instruction == SferaMbcRuntimeInstruction::JumpIfFalse ? readOperand<int>() : readOperand<std::int16_t>();
            instruction_cursor += offset - width;
        }
        break;
    }
    case SferaMbcRuntimeInstruction::ArrayElement:
    case SferaMbcRuntimeInstruction::SliceElement:
    {
        const auto type = readOperand<SferaMbcValueType>();
        const auto stride = readOperand<std::uint16_t>();
        SferaSliceReference32 *source = instruction == SferaMbcRuntimeInstruction::SliceElement ? &popSlice() : nullptr;
        auto index = popInteger();
        const auto offset = source ? 0u : readOperand<std::uint32_t>();
        const auto width = source ? 0u : readOperand<std::uint32_t>();
        const auto signedCount = readOperand<int>();
        const auto count = signedCount < 0 ? 0u - SferaNumeric::word(signedCount) : SferaNumeric::word(signedCount);
        if (index < 0 || std::cmp_greater_equal(index, count))
        {
            WorldDiagnostics::describeScript(true);
            auto message = std::format("{}\n{} boundary error: array size = {}, index = {}", diagnostic_context, source ? "Array2" : "Array", count, index);
            WorldDiagnostics::warning(message);
            const auto last = SferaNumeric::signedWord(count - 1u);
            if (source)
                index = index >= 0 && last < 0 ? 0 : last;
            else
                index = index < 0 ? 0 : last;
        }
        const auto displacement = SferaNumeric::word(stride) * SferaNumeric::word(index);
        if (source)
        {
            source->base += displacement;
            pushReference(type, *source, signedCount < 0);
        }
        else
        {
            const auto element = offset + displacement;
            pushReference(type, {element, element, element + width - 1}, signedCount < 0);
        }
        break;
    }
    case SferaMbcRuntimeInstruction::PointerElement:
    case SferaMbcRuntimeInstruction::FieldValue:
    case SferaMbcRuntimeInstruction::FieldSlice:
    {
        const auto type = readOperand<SferaMbcValueType>();
        const auto stride = instruction == SferaMbcRuntimeInstruction::PointerElement ? readOperand<std::uint16_t>() : 0;
        auto &source = popSlice();
        source.base += instruction == SferaMbcRuntimeInstruction::PointerElement ? SferaNumeric::word(stride) * SferaNumeric::word(popInteger()) : readOperand<std::uint16_t>();
        if (source.begin != 0 && (source.base < source.begin || source.base > source.end))
            source.diagnoseRange(0);
        const auto offset = source.base;
        if (instruction == SferaMbcRuntimeInstruction::PointerElement)
            pushReference(type, source, true);
        else if (instruction == SferaMbcRuntimeInstruction::FieldSlice)
        {
            const auto length = readOperand<std::uint32_t>();
            auto &slot = stack[value_stack_size++];
            slot.type = type;
            slot.width = sizeof(slot.value);
            slot.value = {offset, offset, offset + length - 1};
            slot.detach();
        }
        else
        {
            const std::uint32_t width = type == SferaMbcValueTypeAddress                                    ? readOperand<std::uint32_t>()
                                        : type == SferaMbcValueTypeByte                                     ? std::uint32_t{sizeof(std::int8_t)}
                                        : type == SferaMbcValueTypeInteger || type == SferaMbcValueTypeReal ? std::uint32_t{sizeof(std::uint32_t)}
                                                                                                            : std::uint32_t{sizeof(SferaSliceReference32)};
            pushReference(type, {offset, offset, offset + width - 1u}, true);
        }
        break;
    }
    case SferaMbcRuntimeInstruction::CallLocal:
    {
        auto &program = program_table_base[program_index];
        if (program.callDepth >= std::size(program.return_offsets))
        {
            reportError("Return stack overflow");
            break;
        }
        active_program_record->return_offsets[program.callDepth++] = SferaNumeric::signedWord(SferaNumeric::lowWord(instruction_cursor - bytecode_base + sizeof(int)));
        const auto offset = readOperand<int>();
        instruction_cursor += std::ptrdiff_t{offset} - sizeof(offset);
        argument_end = value_stack_size;
        value_stack_size -= argument_count;
        argument_cursor = value_stack_size;
        break;
    }

    case SferaMbcRuntimeInstruction::Jump:
    {
        const std::ptrdiff_t offset = readOperand<int>();
        instruction_cursor += offset - sizeof(int);
        break;
    }
    case SferaMbcRuntimeInstruction::JumpShort:
    {
        const auto offset = readOperand<std::int16_t>();
        std::ptrdiff_t displacement = offset;
        displacement -= sizeof(offset);
        instruction_cursor += displacement;
        break;
    }
    case SferaMbcRuntimeInstruction::ArgumentCount:
        argument_count = readOperand<std::uint8_t>();
        break;
    case SferaMbcRuntimeInstruction::ResetStack:
        value_stack_size = frame_stack_base[call_frame_depth];
        break;
    case SferaMbcRuntimeInstruction::LiteralWord:
    case SferaMbcRuntimeInstruction::LiteralShort:
    case SferaMbcRuntimeInstruction::LiteralByte:
    {
        const auto type = readOperand<SferaMbcValueType>();
        std::uint32_t value;
        if (instruction == SferaMbcRuntimeInstruction::LiteralWord)
            value = readOperand<std::uint32_t>();
        else if (instruction == SferaMbcRuntimeInstruction::LiteralShort)
            value = readOperand<std::uint16_t>();
        else
            value = readOperand<std::int8_t>();
        if (value_stack_size == std::size(stack))
        {
            reportError("Stack overflow");
            break;
        }
        auto &slot = stack[value_stack_size++];
        slot.type = type;
        slot.width = sizeof(value);
        slot.value.base = value;
        slot.detach();
        break;
    }
    case SferaMbcRuntimeInstruction::StringLiteral:
    case SferaMbcRuntimeInstruction::SliceVariable:
    case SferaMbcRuntimeInstruction::SliceLiteral:
    {
        const auto type = instruction == SferaMbcRuntimeInstruction::StringLiteral ? SferaMbcValueTypeBytePointer : readOperand<SferaMbcValueType>();
        const auto offset = readOperand<std::uint32_t>();
        const auto length = instruction == SferaMbcRuntimeInstruction::StringLiteral ? readOperand<std::uint16_t>() : readOperand<std::uint32_t>();
        if (value_stack_size == std::size(stack))
        {
            reportError("Stack overflow");
            break;
        }
        auto &slot = stack[value_stack_size++];
        slot.type = type;
        slot.width = sizeof(slot.value);
        slot.value = {offset, offset, offset + length - 1};
        if (instruction == SferaMbcRuntimeInstruction::SliceVariable)
            slot.source = slot.value;
        else
            slot.detach();
        break;
    }
    case SferaMbcRuntimeInstruction::StartProgram:
    case SferaMbcRuntimeInstruction::CallProgram:
    case SferaMbcRuntimeInstruction::StopProgram:
    case SferaMbcRuntimeInstruction::PauseProgram:
    case SferaMbcRuntimeInstruction::ResumeProgram:
    {
        const auto index = readOperand<std::int16_t>();
        auto &program = program_table_base[index];
        if (instruction == SferaMbcRuntimeInstruction::StopProgram)
        {
            program.instruction_offset = program.stop_offset;
            break;
        }
        if (instruction == SferaMbcRuntimeInstruction::PauseProgram)
        {
            program.state = 0;
            break;
        }
        if (instruction != SferaMbcRuntimeInstruction::ResumeProgram)
        {
            program.instruction_offset = program.entry_offset;
            program.caller_program = instruction == SferaMbcRuntimeInstruction::CallProgram ? program_index : -1;
        }
        if (program.state < 0)
            active_process->linkProgram(SferaNumeric::word(index));
        program.state = 1;
        break;
    }
    case SferaMbcRuntimeInstruction::ReturnLocal:
    {
        auto &program = *active_program_record;
        instruction_cursor = program.callDepth == 0 ? bytecode_base - 1 : bytecode_base + program.return_offsets[--program.callDepth];
        break;
    }
    case SferaMbcRuntimeInstruction::Assign:
    {
        const auto &right = stack[--value_stack_size];
        auto &left = stack[value_stack_size - 1];
        if (!left.source.contains(SferaNumeric::lowWord(left.width)))
            left.source.diagnoseRange(SferaNumeric::lowWord(left.width));
        if (left.width == 1)
        {
            const std::uint8_t value = SferaNumeric::lowByte(right.value.base);
            left.value.base = value;
            writeMemory(left.source.base, value);
        }
        else if (!left.isPointer())
        {
            left.value.base = right.value.base;
            writeMemory(left.source.base, right.value.base);
        }
        else
        {
            left.value = right.value;
            writeMemory(left.source.base, right.value);
        }
        break;
    }
    case SferaMbcRuntimeInstruction::Dereference:
    {
        auto &slot = stack[value_stack_size - 1];
        slot.source = slot.value;
        if (!slot.value.contains(1, true))
            slot.value.diagnoseRange(0);
        const auto offset = slot.value.base;
        slot.type = SferaNumeric::enumFromBits<SferaMbcValueType>(SferaNumeric::lowByte(SferaNumeric::enumBits(slot.type) - 1u));
        if (slot.type == SferaMbcValueTypeByte)
        {
            slot.value.base = readMemory<std::int8_t>(offset);
            slot.type = SferaMbcValueTypeInteger;
            slot.width = sizeof(std::int8_t);
        }
        else if (!slot.isPointer())
        {
            slot.value.base = readMemory<std::uint32_t>(offset);
            slot.width = sizeof(std::uint32_t);
        }
        else
        {
            slot.value = readMemory<SferaSliceReference32>(offset);
            slot.width = sizeof(slot.value);
        }
        break;
    }
    case SferaMbcRuntimeInstruction::AddressOf:
    {
        auto &slot = stack[value_stack_size - 1];
        slot.value = slot.source;
        slot.detach();
        slot.type = SferaNumeric::enumFromBits<SferaMbcValueType>(SferaNumeric::lowByte(SferaNumeric::enumBits(slot.type) + 1u));
        slot.width = sizeof(slot.value);
        break;
    }
    case SferaMbcRuntimeInstruction::Add:
    case SferaMbcRuntimeInstruction::Subtract:
    case SferaMbcRuntimeInstruction::Multiply:
    case SferaMbcRuntimeInstruction::Divide:
    case SferaMbcRuntimeInstruction::Remainder:
    {
        auto &left = stack[value_stack_size - 2];
        const auto &right = stack[value_stack_size - 1];
        if (left.type == SferaMbcValueTypeInteger || instruction == SferaMbcRuntimeInstruction::Remainder)
        {
            const auto divisor = right.integer();
            if ((instruction == SferaMbcRuntimeInstruction::Divide || instruction == SferaMbcRuntimeInstruction::Remainder) && divisor == 0)
            {
                reportError("Division by zero");
                break;
            }
            switch (instruction)
            {
            case SferaMbcRuntimeInstruction::Add:
                left.value.base += right.value.base;
                break;
            case SferaMbcRuntimeInstruction::Subtract:
                left.value.base -= right.value.base;
                break;
            case SferaMbcRuntimeInstruction::Multiply:
                left.value.base *= right.value.base;
                break;
            case SferaMbcRuntimeInstruction::Divide:
            {
                const std::int64_t dividend = left.integer();
                left.value.base = SferaNumeric::lowWord(dividend / divisor);
                break;
            }
            default:
            {
                const std::int64_t dividend = left.integer();
                left.value.base = dividend % divisor;
                break;
            }
            }
        }
        else
        {
            const double first = left.real(), second = right.real();
            double result;
            switch (instruction)
            {
            case SferaMbcRuntimeInstruction::Add:
                result = first + second;
                break;
            case SferaMbcRuntimeInstruction::Subtract:
                result = first - second;
                break;
            case SferaMbcRuntimeInstruction::Multiply:
                result = first * second;
                break;
            default:
                result = first / second;
                break;
            }
            left.setReal(result);
        }
        --value_stack_size;
        left.detach();
        break;
    }
    case SferaMbcRuntimeInstruction::Equal:
    case SferaMbcRuntimeInstruction::NotEqual:
    case SferaMbcRuntimeInstruction::Greater:
    case SferaMbcRuntimeInstruction::Less:
    case SferaMbcRuntimeInstruction::GreaterEqual:
    case SferaMbcRuntimeInstruction::LessEqual:
    {
        auto &left = stack[value_stack_size - 2];
        const auto &right = stack[value_stack_size - 1];
        double first = left.integer();
        double second = right.integer();
        if (left.type == SferaMbcValueTypeReal)
        {
            first = left.real();
            second = right.real();
        }
        bool result;
        switch (instruction)
        {
        case SferaMbcRuntimeInstruction::Equal:
            result = first == second;
            break;
        case SferaMbcRuntimeInstruction::NotEqual:
            result = first != second;
            break;
        case SferaMbcRuntimeInstruction::Greater:
            result = first > second;
            break;
        case SferaMbcRuntimeInstruction::Less:
            result = first < second;
            break;
        case SferaMbcRuntimeInstruction::GreaterEqual:
            result = first >= second;
            break;
        default:
            result = first <= second;
            break;
        }
        --value_stack_size;
        left.detach();
        left.type = SferaMbcValueTypeInteger;
        left.value.base = result;
        break;
    }
    case SferaMbcRuntimeInstruction::ShortCircuitOr:
    case SferaMbcRuntimeInstruction::ShortCircuitAnd:
    {
        auto &slot = stack[value_stack_size - 1];
        const bool branch = (slot.value.base != 0) == (instruction == SferaMbcRuntimeInstruction::ShortCircuitOr);
        const auto offset = readOperand<std::int16_t>();
        if (branch)
        {
            slot.type = SferaMbcValueTypeInteger;
            slot.detach();
            std::ptrdiff_t displacement = offset;
            displacement -= sizeof(offset);
            instruction_cursor += displacement;
        }
        else
            --value_stack_size;
        break;
    }
    case SferaMbcRuntimeInstruction::IntegerResult:
    case SferaMbcRuntimeInstruction::IntegerResultAlternate:
    {
        auto &slot = stack[value_stack_size - 1];
        slot.type = SferaMbcValueTypeInteger;
        slot.detach();
        break;
    }
    case SferaMbcRuntimeInstruction::PreIncrement:
    case SferaMbcRuntimeInstruction::PreDecrement:
    case SferaMbcRuntimeInstruction::PostIncrement:
    case SferaMbcRuntimeInstruction::PostDecrement:
    {
        auto &slot = stack[value_stack_size - 1];
        const bool increment = instruction == SferaMbcRuntimeInstruction::PreIncrement || instruction == SferaMbcRuntimeInstruction::PostIncrement;
        const bool prefix = instruction == SferaMbcRuntimeInstruction::PreIncrement || instruction == SferaMbcRuntimeInstruction::PreDecrement;
        if (slot.type == SferaMbcValueTypeInteger || slot.type == SferaMbcValueTypeByte)
        {
            const auto value = slot.value.base + (increment ? 1 : UINT32_MAX);
            if (slot.width == 1)
                writeMemory(slot.source.base, SferaNumeric::lowByte(value));
            else
                writeMemory(slot.source.base, value);
            if (prefix)
                slot.value.base = value;
        }
        else
        {
            const double current = slot.real();
            const float value = SferaNumeric::real32(current + (increment ? 1.0 : -1.0));
            if (instruction == SferaMbcRuntimeInstruction::PostDecrement)
            {
                // Preserve the stable interpreter's floating postfix result and second decrement.
                slot.setReal(value);
                writeReal(slot.source.base, value - 1.0);
            }
            else
            {
                writeMemory(slot.source.base, value);
                if (prefix)
                    slot.setReal(value);
            }
        }
        break;
    }
    case SferaMbcRuntimeInstruction::PointerPreIncrement:
    case SferaMbcRuntimeInstruction::PointerPreDecrement:
    case SferaMbcRuntimeInstruction::PointerPostIncrement:
    case SferaMbcRuntimeInstruction::PointerPostDecrement:
    {
        const auto stride = readOperand<std::uint16_t>();
        auto &slot = stack[value_stack_size - 1];
        const bool increment = instruction == SferaMbcRuntimeInstruction::PointerPreIncrement || instruction == SferaMbcRuntimeInstruction::PointerPostIncrement;
        const auto value = increment ? slot.value.base + stride : slot.value.base - stride;
        writeMemory(slot.source.base, value);
        if (instruction == SferaMbcRuntimeInstruction::PointerPreIncrement || instruction == SferaMbcRuntimeInstruction::PointerPreDecrement)
            slot.value.base = value;
        break;
    }
    case SferaMbcRuntimeInstruction::IntegerToReal:
    case SferaMbcRuntimeInstruction::PreviousIntegerToReal:
    case SferaMbcRuntimeInstruction::RealToInteger:
    case SferaMbcRuntimeInstruction::PreviousRealToInteger:
    {
        const bool previous = instruction == SferaMbcRuntimeInstruction::PreviousIntegerToReal || instruction == SferaMbcRuntimeInstruction::PreviousRealToInteger;
        auto &slot = stack[value_stack_size - (previous ? 2 : 1)];
        if (instruction == SferaMbcRuntimeInstruction::IntegerToReal || instruction == SferaMbcRuntimeInstruction::PreviousIntegerToReal)
        {
            slot.setReal(SferaNumeric::real32(slot.integer()));
            slot.type = SferaMbcValueTypeReal;
        }
        else
        {
            slot.value.base = SferaMbcValue::truncate(slot.real());
            slot.type = SferaMbcValueTypeInteger;
        }
        break;
    }
    case SferaMbcRuntimeInstruction::Swap:
        std::swap(stack[value_stack_size - 2], stack[value_stack_size - 1]);
        break;
    case SferaMbcRuntimeInstruction::PointerAdd:
    case SferaMbcRuntimeInstruction::PointerSubtract:
    {
        const auto stride = readOperand<std::uint16_t>();
        const auto index = stack[--value_stack_size].value.base;
        auto &slot = stack[value_stack_size - 1];
        if (instruction == SferaMbcRuntimeInstruction::PointerAdd)
            slot.value.base += index * stride;
        else
            slot.value.base -= index * stride;
        slot.detach();
        break;
    }
    case SferaMbcRuntimeInstruction::IntegerPair:
        stack[value_stack_size - 1].type = stack[value_stack_size - 2].type = SferaMbcValueTypeInteger;
        break;
    case SferaMbcRuntimeInstruction::Negate:
    case SferaMbcRuntimeInstruction::LogicalNot:
    {
        if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth])
        {
            --value_stack_size;
            reportError(instruction == SferaMbcRuntimeInstruction::Negate ? "fo27(): stack underflow" : "fo31(): stack underflow");
            break;
        }
        auto &slot = stack[value_stack_size - 1];
        if (instruction == SferaMbcRuntimeInstruction::LogicalNot)
        {
            slot.value.base = slot.value.base == 0;
            slot.type = SferaMbcValueTypeInteger;
        }
        else if (slot.type == SferaMbcValueTypeInteger)
            slot.value.base = 0u - slot.value.base;
        else
            slot.setReal(-slot.real());
        slot.detach();
        break;
    }
    case SferaMbcRuntimeInstruction::EnterFrame:
        if (++call_frame_depth >= std::ssize(frame_stack_base))
            reportError("Stack of stacks overflow");
        if (call_frame_depth >= 0 && call_frame_depth < std::ssize(frame_stack_base))
            frame_stack_base[call_frame_depth] = value_stack_size;
        break;
    case SferaMbcRuntimeInstruction::LeaveFrame:
        if (--call_frame_depth < 0)
            reportError("Stack of stacks devastation");
        break;
    case SferaMbcRuntimeInstruction::UnlinkedFunction:
        reportError("Unlinked function was called");
        break;
    case SferaMbcRuntimeInstruction::Halt:
        execution_failed = true;
        break;
    default:
        return false;
    }
    return true;
}

void SferaMbcRuntime::reportInvalidInstruction()
{
    reportError("Unknown script code: ", SferaText::fromBytes(std::span(--instruction_cursor, 1u)));
}

auto SferaMbcRuntime::callFunctionFail()
{
    active_tag = UINT32_MAX;
    pushInteger(UINT32_MAX);
}

void SferaMbcRuntime::callFunction(bool mainProcess)
{
    const auto required = mainProcess ? 1u : 2u;
    argument_count -= required;

    if (argument_count < 0)
    {
        callFunctionFail();
        return;
    }
    const auto target_word = mainProcess ? 0u : nextWord();
    auto *target = mainProcess ? &processes[0] : target_word == 0 ? nullptr : findProcess(target_word);
    if (target == nullptr || target->functions.empty())
    {
        callFunctionFail();
        return;
    }
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        callFunctionFail();
        return;
    }
    SferaMbcFunctionRecord *function = nullptr;
    if (g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValueTypeBytePointer)
    {
        const auto name = nextSlice();
        const auto text = textIn(name, 31);
        function = target->findFunction(text);
    }
    else
    {
        const std::uint32_t tag = nextInteger();
        if (tag < SferaMbcModuleImage::functionSlotCount)
        {
            const auto index = target->function_map[tag];
            if (index != UINT16_MAX && index < target->functions.size())
                function = &target->functions[index];
        }
    }
    if (function == nullptr || function->program_index < 0 || function->program_index >= target->programs.size())
    {
        callFunctionFail();
        return;
    }
    if (execution_context_depth >= std::ssize(execution_context_stack))
    {
        reportError("Execution context stack overflow");
        callFunctionFail();
        return;
    }
    execution_context_stack[execution_context_depth++] = {process_index, program_index, SferaNumeric::lowWord(instruction_cursor - bytecode_base), processes[process_index].process_id,
                                                          processes[process_index].lifetime};
    active_program_record = &program_table_base[program_index];
    active_program_record->instruction_offset = SferaNumeric::lowWord(instruction_cursor - bytecode_base);
    auto &targetProgram = target->programs.data()[function->program_index];
    if (targetProgram.executing && !function->allow_reentry)
    {
        std::string message;
        message = std::format("Double \"func\" call, prob. stack corruption: {} (prc {}, tag {}), called from (prc {}, tag {}).\n", function->name, SferaNumeric::signedWord(target_word),
                              SferaNumeric::signedWord(target->module_tag), process_index, SferaNumeric::signedWord(active_process->module_tag));
        WorldDiagnostics::warning(message);
    }
    bytecode_base = target->codeData();
    program_table_base = target->programs.data();
    process_memory_base = target->memory.data();
    instruction_cursor = bytecode_base + function->entry_offset;
    program_index = function->program_index;
    active_program_record = &targetProgram;
    targetProgram.callDepth = 0;
    targetProgram.executing = true;
    active_process = target;
    process_index = SferaNumeric::signedWord(target_word);
    active_tag = 0;
}

void SferaMbcRuntime::returnFromFunction()
{
    if (active_program_record->callDepth != 0)
    {
        const auto offset = SferaNumeric::signedWord(active_program_record->return_offsets[--active_program_record->callDepth]);
        if (offset != -1)
        {
            if (offset < 0 || active_process == nullptr || std::cmp_greater_equal(offset, active_process->codeSize()))
            {
                reportError("Invalid function continuation");
                return;
            }
            instruction_cursor = bytecode_base + offset;
            return;
        }
    }
    if (execution_context_depth == 0)
    {
        reportError("fo12(): return stack underflow");
        return;
    }
    active_program_record->executing = false;
    while (execution_context_depth != 0)
    {
        const auto context = execution_context_stack[--execution_context_depth];
        if (context.process_index < 0 || std::cmp_greater_equal(context.process_index, std::size(processes)))
            continue;
        auto &process = processes[context.process_index];
        if (process.chain_prev_index < 0 || process.process_id != context.process_id || process.lifetime != context.process_lifetime)
            continue;
        if (context.program_index < 0 || context.program_index >= process.programs.size() || context.instruction_offset >= process.codeSize())
            continue;
        process_index = context.process_index;
        program_index = context.program_index;
        active_process = &process;
        bytecode_base = process.codeData();
        instruction_cursor = bytecode_base + context.instruction_offset;
        process_memory_base = process.memory.data();
        program_table_base = process.programs.data();
        active_program_record = &process.programs[program_index];
        return;
    }
    reportError("Return to defunct process");
}

bool SferaMbcRuntime::negativeModuleIndex(std::uint16_t index)
{
    return SferaNumeric::signedHalf(index) < 0;
}

void SferaMbcRuntime::enqueueProcess(int index, SferaMbcProcessRecord &process)
{
    if (process.execution_linked || index < 0)
        return;
    ++execution_chain_count;
    process.execution_linked = true;
    process.execution_prev_index = -1;
    if (execution_chain_tail < 0)
    {
        if (execution_chain_head >= 0)
            g_sfera_log_runtime.write("internal error 34096874309");
        execution_chain_head = execution_chain_tail = index;
        process.execution_next_index = -1;
    }
    else
    {
        if (execution_chain_head < 0)
        {
            reportError("internal error 04975350934760");
            return;
        }
        processes[execution_chain_head].execution_prev_index = index;
        process.execution_next_index = execution_chain_head;
        execution_chain_head = index;
    }
}
void SferaMbcRuntime::dequeueProcess(SferaMbcProcessRecord &process)
{
    if (!process.execution_linked)
        return;
    --execution_chain_count;
    process.execution_linked = false;
    if (process.execution_next_index != -1)
        processes[process.execution_next_index].execution_prev_index = process.execution_prev_index;
    else
        execution_chain_tail = process.execution_prev_index;
    if (process.execution_prev_index != -1)
        processes[process.execution_prev_index].execution_next_index = process.execution_next_index;
    else
        execution_chain_head = process.execution_next_index;
}
void SferaMbcRuntime::reloadQuickFiles()
{
    auto replacement = std::make_unique<QuickFile>();
    replacement->initialize("mbc\\");
    quick_files = std::move(replacement);
}

void SferaMbcRuntime::shutdown()
{
    final_shutdown = true;
    g_sfera_config_text_runtime.clear();
    dispatch_slot = -1;
    g_sfera_network_runtime.shutdown();
    for (std::uint32_t index = 0; index < std::size(processes); ++index)
        if (processes[index].chain_prev_index >= 0)
            unloadProcess(index);
    while (!containers.empty())
        destroyContainer(containers.begin()->first);
    while (!dynamic_blocks.empty())
        releaseDynamic(dynamic_blocks.begin()->first);
    mapped_memory.clear();
    native_resources.clear();
    native_resource_ids.clear();
    bytecode_cache.clear();
    quick_files.reset();
    named_vectors.clear();
    active_process = nullptr;
    active_program_record = nullptr;
    program_table_base = nullptr;
    process_memory_base = nullptr;
    bytecode_base = instruction_cursor = current_instruction_address = nullptr;
    process_chain_first = process_chain_last = execution_chain_head = execution_chain_tail = -1;
    execution_chain_count = value_stack_size = 0;
    execution_context_depth = call_frame_depth = 0;
    g_sfera_mbc_runtime.dispatch_slot = -1;
}

void SferaMbcRuntime::initialize()
{
    std::srand(::timeGetTime());
    g_sfera_player_lists.clear();
    shutdown();
    first_execution_error.clear();
    final_shutdown = false;
    reloadQuickFiles();
    next_native_handle = 1;
    process_search_cursor = 0;
    g_sfera_mbc_runtime.dispatch_slot = -1;
    g_sfera_mbc_runtime.simulation_tick = 0;
    g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::pack(7801, 1, 1, 8, 0);
    halt_state = SferaMbcRuntimeHaltState::Running;
    g_sfera_world_objects.controlled_object_handle = UINT32_MAX;
    g_sfera_config_text_runtime.clear();
    g_sfera_direct_input_runtime.text_filter = 0;
    for (std::size_t index = 0; index < 400; ++index)
        g_sfera_mbc_runtime.world_slots[index].state = 4;
    g_sfera_mbc_runtime.active_world_slot = 400;
    auto &slot = g_sfera_mbc_runtime.world_slots[400];
    slot.primary_state = UINT32_MAX;
    slot.state = 2;
    slot.object_handle = 1;
    slot.reliable_bit_count = 0;
    slot.unreliable_bit_count = 0;
    std::fill(std::begin(slot.reliable_payload), std::end(slot.reliable_payload), std::uint8_t{});
    std::fill(std::begin(slot.unreliable_payload), std::end(slot.unreliable_payload), std::uint8_t{});
    slot.reliable_process = UINT32_MAX;
    slot.unreliable_process = UINT32_MAX;
    for (auto &module : g_sfera_mbc_runtime.modules)
        module.name.clear();
    _finddata64i32_t file{};
    const auto search = ::_findfirst64i32("mbc\\*.mbc", &file);
    if (search != -1)
    {
        do
        {
            if ((file.attrib & _A_SUBDIR) != 0)
                continue;
            const auto descriptor = g_sfera_files.open(file.name, _O_RDONLY);
            if (descriptor < 0)
                continue;
            std::uint32_t tag = UINT32_MAX;
            g_sfera_files.seek(descriptor, 20, SEEK_SET);
            const auto read = g_sfera_files.read(descriptor, std::as_writable_bytes(std::span(&tag, 1)));
            g_sfera_files.close(descriptor);
            if (read != sizeof(tag) || tag >= std::size(g_sfera_mbc_runtime.modules))
                continue;
            if (tag == 0)
                ::OutputDebugStringA((std::string("Null tag ") + file.name).c_str());
            auto &name = g_sfera_mbc_runtime.modules[tag].name;
            name = std::string_view(file.name).substr(0, 31);
            const auto extension = name.find_last_of('.');
            const auto separator = name.find_last_of('\\');
            if (extension != std::string::npos && (separator == std::string::npos || extension > separator))
                name.resize(extension);
        } while (::_findnext64i32(search, &file) == 0);
        ::_findclose(search);
    }
    g_sfera_config_text_runtime.load("connectn.cfg");
    int port = 0;
    if (g_sfera_config_text_runtime.readInteger("PORT", port))
        g_sfera_network_runtime.server_port = SferaNumeric::lowHalf(SferaNumeric::word(port));
    if (loadProcess("_main", 0) == UINT32_MAX)
        SferaClientApplication::terminateWithError("MBInter: Process '_main' not found");
    named_vectors.clear();
    g_sfera_effect_manager.pending_effect = nullptr;
    g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::fromUnixTime(::_time64(nullptr));
}

auto SferaMbcRuntime::tickFlush(std::uint32_t &bits, auto &payload, std::uint32_t &owner, std::uint32_t flags)
{
    if (SferaNumeric::signedWord(bits) <= 0)
        return;
    const auto bytes = (bits + 7) >> 3;
    if (!g_sfera_network_runtime.sendPacket(flags, std::span<const std::uint8_t>(payload, bytes)))
        return;
    bits = 0;
    std::fill(std::begin(payload), std::end(payload), std::uint8_t{});
    owner = UINT32_MAX;
}

void SferaMbcRuntime::tick()
{
    auto &log = g_sfera_log_runtime;
    if (dispatch_slot >= 0)
        return;
    SferaRestore dispatchScope(dispatch_slot);
    ++g_sfera_mbc_runtime.simulation_tick;
    if (++g_sfera_network_runtime.statistics_poll_ticks >= 192)
    {
        g_sfera_network_runtime.updateTcpStatistics();
        g_sfera_network_runtime.statistics_poll_ticks = 0;
    }
    if (halt_state != SferaMbcRuntimeHaltState::Running)
    {
        for (auto &process : processes)
        {
            if (process.chain_prev_index == -1)
                continue;
            active_process = &process;
            std::fill(std::begin(process.program_map_a), std::end(process.program_map_a), UINT16_MAX);
            std::fill(std::begin(process.program_map_b), std::end(process.program_map_b), UINT16_MAX);
            process.activateProgram("EPHalt");
        }
        halt_state = SferaMbcRuntimeHaltState::Dispatched;
    }
    const int simulationTick = g_sfera_mbc_runtime.simulation_tick;
    const std::size_t priorityLimit = simulationTick % 24 == 0 ? 2 : simulationTick % 8 == 0 ? 1 : 0;
    process_index = execution_chain_tail;
    while (process_index >= 0 && std::cmp_less(process_index, std::size(processes)) && processes[process_index].chain_prev_index >= 0)
    {
        g_sfera_mbc_runtime.dispatch_slot = process_index;
        active_process = &processes[process_index];
        program_table_base = active_process->programs.data();
        bytecode_base = active_process->codeData();
        process_memory_base = active_process->memory.data();
        execution_context_depth = 0;
        execution_failed = false;
        bool unload = false;
        for (std::size_t priority = 0; priority <= priorityLimit && !unload; ++priority)
        {
            program_index = SferaNumeric::signedHalf(active_process->program_map_a[priority]);
            while (program_index >= 0)
            {
                active_program_record = &program_table_base[program_index];
                const auto initialProgram = program_index;
                bool finishPriority = false;
                if (active_program_record->state > 0)
                {
                    value_stack_size = 0;
                    call_frame_depth = 0;
                    instruction_step_count = 0;
                    auto caller = program_index;
                    do
                    {
                        caller = program_table_base[caller].caller_program;
                    } while (caller >= 0 && program_table_base[caller].state > 0);
                    const bool pausedCaller = caller >= 0 && program_table_base[caller].state == 0;
                    if (!pausedCaller)
                    {
                        instruction_cursor = bytecode_base + (caller < 0 ? active_program_record->instruction_offset : active_program_record->stop_offset);
                        while (true)
                        {
                            if (instruction_step_count++ > 3500000)
                            {
                                WorldDiagnostics::scriptContext();
                                log.write("\n---exit_inter start---\nMBINTER MESSAGE:Endless cycle found\n");
                                log.write(diagnostic_context);
                                log.write("---exit_inter end-----\n");
                                execution_failed = true;
                                if (process_index == 0)
                                    SferaClientApplication::terminateWithError(diagnostic_context);
                                processes[0].activateProgram("EError");
                                unload = true;
                                break;
                            }
                            current_instruction_address = instruction_cursor;
                            current_opcode = SferaNumeric::enumFromBits<SferaMbcRuntimeInstruction>(*instruction_cursor);
                            if (current_opcode == SferaMbcRuntimeInstruction::Yield)
                            {
                                ++instruction_cursor;
                                break;
                            }
                            if (current_opcode == SferaMbcRuntimeInstruction::EndProgram)
                            {
                                active_program_record->callDepth = 0;
                                active_program_record->state = -1;
                                auto pending_program_index = SferaNumeric::signedHalf(active_process->program_map_b[priority]);
                                auto &head = active_process->program_map_a[priority];
                                auto &tail = active_process->program_map_b[priority];
                                if (program_index == SferaNumeric::signedHalf(tail))
                                {
                                    if (head == tail)
                                    {
                                        head = UINT16_MAX;
                                        tail = UINT16_MAX;
                                        if (std::all_of(std::begin(active_process->program_map_a), std::begin(active_process->program_map_a) + 3, &SferaMbcRuntime::negativeModuleIndex))
                                        {
                                            dequeueProcess(*active_process);
                                            active_process->programs_queued = false;
                                        }
                                    }
                                    else
                                    {
                                        pending_program_index = SferaNumeric::signedHalf(active_program_record->previous_program);
                                        tail = pending_program_index;
                                        program_table_base[pending_program_index].next_program = tail;
                                    }
                                    finishPriority = true;
                                }
                                else if (program_index == head)
                                {
                                    head = active_program_record->next_program;
                                    program_table_base[head].previous_program = head;
                                }
                                else
                                {
                                    program_table_base[active_program_record->next_program].previous_program = active_program_record->previous_program;
                                    program_table_base[active_program_record->previous_program].next_program = active_program_record->next_program;
                                }
                                break;
                            }
                            ++instruction_cursor;
                            try
                            {
                                if (!executeInstruction(current_opcode))
                                    reportInvalidInstruction();
                            }
                            catch (const std::out_of_range &error)
                            {
                                reportError(error.what());
                            }
                            catch (const std::length_error &error)
                            {
                                reportError(error.what());
                            }
                            catch (const SferaBinaryReadError &error)
                            {
                                reportError(error.what());
                            }
                            if (execution_failed)
                            {
                                unload = true;
                                break;
                            }
                        }
                    }
                    if (!finishPriority && !unload)
                        active_program_record->instruction_offset = SferaNumeric::lowWord(instruction_cursor - bytecode_base);
                }
                if (finishPriority || unload)
                    break;
                program_index = SferaNumeric::signedHalf(active_program_record->next_program);
                if (initialProgram == SferaNumeric::signedHalf(active_process->program_map_b[priority]))
                    break;
            }
        }
        if (unload || (active_process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution) != 0)
        {
            unloadProcess(process_index);
            if (process_index == process_chain_last)
                break;
        }
        const auto previousActive = g_sfera_mbc_runtime.dispatch_slot;
        process_index = active_process->execution_prev_index;
        if (previousActive == execution_chain_head)
            break;
    }
    g_sfera_mbc_runtime.dispatch_slot = -1;
    if (halt_state == SferaMbcRuntimeHaltState::Dispatched)
    {
        if (!final_shutdown)
            initialize();
        return;
    }
    if (SferaNumeric::signedWord(g_sfera_mbc_runtime.simulation_tick) % 3 == 0)
    {
        g_sfera_network_runtime.receiveMessages();
        for (int index = SferaNumeric::signedWord(SferaNumeric::lowWord(g_sfera_mbc_runtime.active_world_slot)); index >= 0;)
        {
            auto &slot = g_sfera_mbc_runtime.world_slots[index];
            index = slot.primary_state;

            tickFlush(slot.reliable_bit_count, slot.reliable_payload, slot.reliable_process, 8);
            tickFlush(slot.unreliable_bit_count, slot.unreliable_payload, slot.unreliable_process, 0);
        }
    }
}

void SferaMbcProcessRecord::appendCommand(std::string_view command)
{
    // The leading CRLF and conservative 127-byte command limit are part of ReadCommands.
    if (command.size() > 123u || physics_commands.size() > 123u - command.size())
        return;
    physics_commands += "\r\n";
    physics_commands.append(command);
}

void SferaMbcProcessRecord::linkProgram(std::size_t index)
{
    auto &program = programs.data()[index];
    const std::int16_t previous = program_map_b[program.priority];
    if (previous < 0)
    {
        program_map_a[program.priority] = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
        program.previous_program = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
    }
    else
    {
        programs.data()[previous].next_program = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
        program.previous_program = SferaNumeric::lowHalf(SferaNumeric::word(previous));
    }
    program_map_b[program.priority] = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
    program.next_program = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
    programs_queued = true;
    g_sfera_mbc_runtime.enqueueProcess(process_id, *this);
}
bool SferaMbcProcessRecord::activateProgram(std::size_t index)
{
    if (index >= programs.size() || programs.data() == nullptr)
        return false;
    auto &program = programs.data()[index];
    if (program.state != 1)
    {
        linkProgram(index);
        program.instruction_offset = program.entry_offset;
    }
    program.state = 1;
    programs_queued = true;
    return true;
}
bool SferaMbcProcessRecord::activateProgram(std::string_view programName)
{
    if (programs.empty())
        return false;
    for (std::size_t index = 0; index < programs.size(); ++index)
    {
        if (programs[index].name != programName)
            continue;
        activateProgram(index);
        g_sfera_mbc_runtime.enqueueProcess(process_id, *this);
        return true;
    }
    return false;
}

std::uint64_t *SferaMbcProcessRecord::resourceLifetime(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind)
{
    if (kind == SferaMbcProcessRecordResourceKind::gameWindow)
    {
        if (auto *item = GameInterface::window(handle))
            return &item->resource_lifetime;
    }
    else if (kind == SferaMbcProcessRecordResourceKind::worldObject)
    {
        if (auto *item = g_sfera_world_objects.object(handle))
            return &item->resource_lifetime;
    }
    else if (kind == SferaMbcProcessRecordResourceKind::textControl || kind == SferaMbcProcessRecordResourceKind::spriteControl)
    {
        if (auto *item = WorldGuiControls::control(handle))
            return &item->resource_lifetime;
    }
    return nullptr;
}

bool SferaMbcProcessRecord::resourceIsCurrent(const SferaMbcProcessRecordCleanupEntry &entry)
{
    if (entry.resource_lifetime == 0)
        return true;
    const auto *lifetime = resourceLifetime(entry.handle, entry.kind);
    return lifetime && *lifetime == entry.resource_lifetime;
}

void SferaMbcProcessRecord::registerResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind)
{
    auto *resourceLifetimeValue = resourceLifetime(handle, kind);
    static std::uint64_t nextLifetime = 1;
    if (resourceLifetimeValue && *resourceLifetimeValue == 0 && nextLifetime == 0)
        throw std::overflow_error("Resource lifetime IDs exhausted");
    const auto id = resourceLifetimeValue ? (*resourceLifetimeValue != 0 ? *resourceLifetimeValue : nextLifetime) : 0;
    cleanup_entries.push_back({handle, kind, id});
    if (resourceLifetimeValue && *resourceLifetimeValue == 0)
    {
        *resourceLifetimeValue = id;
        ++nextLifetime;
    }
}

void SferaMbcProcessRecord::unregisterResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind)
{
    auto found = cleanup_entries.begin();
    while (found != cleanup_entries.end() && !(found->handle == handle && found->kind == kind))
        ++found;
    if (found != cleanup_entries.end())
        cleanup_entries.erase(found);
}

std::uint32_t SferaMbcProcessRecord::growMemory(std::size_t size)
{
    constexpr std::uint32_t maximumRequest = 4000000;
    constexpr auto limit = SferaMbcRuntime::mappedAddressBegin;
    if (size > maximumRequest || memory.size() > limit - 4u)
        return UINT32_MAX;
    const auto aligned = (memory.size() + 3u) & ~std::size_t{3};
    if (size >= limit - aligned)
        return UINT32_MAX;
    memory.resize(aligned + size, 0);
    // Process mappings resolve the owner at access time, so existing addresses remain valid.
    auto &runtime = g_sfera_mbc_runtime;
    if (runtime.active_process == this)
        runtime.process_memory_base = memory.data();
    return SferaNumeric::lowWord(aligned);
}

SferaMbcFunctionRecord *SferaMbcProcessRecord::findFunction(std::string_view functionName)
{
    if (functions.empty())
        return nullptr;
    for (std::uint32_t index = 0; index < functions.size(); ++index)
    {
        if (functions[index].program_index >= 0 && functionName == functions[index].name)
            return &functions[index];
    }
    return nullptr;
}

void SferaMbcProcessRecord::readRegions(std::span<const std::uint8_t> definitions, std::uint32_t firstProgram)
{
    if (regions.empty())
        return;
    std::size_t cursor = 0;
    while (cursor < definitions.size())
    {
        if (definitions[cursor] != 127)
        {
            ++cursor;
            continue;
        }
        if (definitions.size() - cursor < 5)
            break;
        const auto regionIndex = definitions[cursor + 1];
        const std::int8_t regionFlags = SferaNumeric::signedByte(definitions[cursor + 2]);
        std::uint16_t program;
        std::memcpy(&program, definitions.data() + cursor + 3, sizeof(program));
        cursor += 5;
        const auto firstField = cursor;
        while (cursor < definitions.size() && definitions[cursor] != 127)
            ++cursor;
        if (regionIndex >= 62)
            continue;
        auto &region = regions[regionIndex];
        if (region.flags == -1)
        {
            region.flags = regionFlags;
            region.field_count = SferaNumeric::signedWord(SferaNumeric::lowWord(std::min<std::size_t>(cursor - firstField, std::size(region.formats))));
            std::copy_n(definitions.data() + firstField, region.field_count, region.formats);
        }
        if (program != UINT16_MAX && region.program_index == UINT16_MAX)
            region.program_index = SferaNumeric::lowHalf(firstProgram + program);
    }
}

void SferaMbcProcessRecord::releaseResources()
{
    const auto pending = std::exchange(cleanup_entries, {});
    for (const auto &entry : pending)
    {
        try
        {
            if (!resourceIsCurrent(entry))
                continue;
            if (entry.kind == SferaMbcProcessRecordResourceKind::textControl)
                WorldGuiControls::destroyText(entry.handle);
            else if (entry.kind == SferaMbcProcessRecordResourceKind::spriteControl)
                WorldGuiControls::destroySprite(entry.handle);
        }
        catch (const std::exception &error)
        {
            ::OutputDebugStringA(error.what());
        }
        catch (...)
        {
            ::OutputDebugStringA("Process resource cleanup failed");
        }
    }
    for (const auto &entry : pending)
    {
        try
        {
            if (!resourceIsCurrent(entry))
                continue;
            switch (entry.kind)
            {
            case SferaMbcProcessRecordResourceKind::worldObject:
                g_sfera_world_objects.destroy(entry.handle);
                break;
            case SferaMbcProcessRecordResourceKind::file:
                ::_close(SferaNumeric::signedWord(entry.handle));
                break;
            case SferaMbcProcessRecordResourceKind::fileSearch:
            {
                const auto search = g_sfera_mbc_runtime.nativeResource<std::intptr_t>(entry.handle);
                if (search != -1)
                {
                    ::_findclose(search);
                    g_sfera_mbc_runtime.forgetNativeResource(search);
                }
                break;
            }
            case SferaMbcProcessRecordResourceKind::dynamicArray:
            {
                std::uint32_t offset{};
                const auto *source = g_sfera_mbc_runtime.memoryAt(entry.handle, sizeof(offset), this);
                if (source == nullptr)
                    break;
                std::memcpy(&offset, source, sizeof(offset));
                g_sfera_mbc_runtime.releaseDynamic(offset);
                break;
            }
            case SferaMbcProcessRecordResourceKind::gameWindow:
                GameInterface::destroyWindow(entry.handle);
                break;
            case SferaMbcProcessRecordResourceKind::interfaceWindow:
                g_sfera_interface.closeWindow(g_sfera_mbc_runtime.nativeResource<SphereUIWindow *>(entry.handle), true);
                break;
            case SferaMbcProcessRecordResourceKind::container:
            {
                auto *container = g_sfera_mbc_runtime.nativeResource<SferaScriptContainer *>(entry.handle);
                if (container != nullptr && container->header.kind >= SferaDataContainerHeaderKind::List && container->header.kind <= SferaDataContainerHeaderKind::HashMap)
                    g_sfera_mbc_runtime.destroyContainer(entry.handle);
                break;
            }
            default:
                break;
            }
        }
        catch (const std::exception &error)
        {
            ::OutputDebugStringA(error.what());
        }
        catch (...)
        {
            ::OutputDebugStringA("Process resource cleanup failed");
        }
    }
}

void SferaMbcProcessRecord::queueRegion(std::size_t region, std::uint32_t timestamp, std::span<const int, 3> origin, std::span<const std::uint8_t> payload, std::size_t firstBit, std::size_t bitCount,
                                        bool ordered)
{
    if (region >= received_regions.size() || payload.size() > SIZE_MAX / 8 || firstBit > payload.size() * 8 || bitCount > payload.size() * 8 - firstBit)
        return;
    SferaMbcRegionPacket packet;
    packet.timestamp = timestamp;
    std::copy(origin.begin(), origin.end(), packet.origin.begin());
    // Ordered packets have a legacy trailing byte even when the payload ends on a byte boundary.
    const auto byteCount = bitCount / 8 + (ordered || bitCount % 8 != 0 ? 1 : 0);
    packet.data.resize(byteCount);
    SferaMbcBitStream source(payload, firstBit);
    SferaMbcBitStream destination{std::span<std::uint8_t>(packet.data)};
    for (auto remaining = bitCount; remaining != 0;)
    {
        const unsigned width = SferaNumeric::lowWord(std::min<std::size_t>(remaining, 32));
        destination.write(source.read(width), width);
        remaining -= width;
    }
    if (!source.valid() || !destination.valid())
        return;
    auto &queue = received_regions[region];
    if (queue == nullptr)
    {
        auto created = std::make_unique<std::list<SferaMbcRegionPacket>>();
        created->push_back(std::move(packet));
        queue = std::move(created);
        return;
    }
    auto position = queue->end();
    if (ordered)
    {
        position = queue->begin();
        while (position != queue->end() && SferaNetworkRuntime::tickDifference(timestamp, position->timestamp) >= 0)
            ++position;
    }
    queue->insert(position, std::move(packet));
}

std::int32_t SferaMbcRuntime::popInteger()
{
    if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth])
    {
        reportError("popint(): stack underflow");
        return 0;
    }
    return g_sfera_mbc_runtime.values[--value_stack_size].asInteger();
}
std::uint32_t SferaMbcRuntime::popWord()
{
    if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth])
    {
        reportError("popint(): stack underflow");
        return 0u;
    }
    return g_sfera_mbc_runtime.values[--value_stack_size].asWord();
}
SferaSliceReference32 &SferaMbcRuntime::popSlice()
{
    if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth])
    {
        reportError("popsliceref(): stack underflow");
        g_sfera_mbc_runtime.slice_fallback = {};
        return g_sfera_mbc_runtime.slice_fallback;
    }
    return g_sfera_mbc_runtime.values[--value_stack_size].asSlice();
}
std::int32_t SferaMbcRuntime::nextInteger()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return 0;
    }
    return g_sfera_mbc_runtime.values[argument_cursor++].asInteger();
}
std::uint32_t SferaMbcRuntime::nextWord()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return 0u;
    }
    return g_sfera_mbc_runtime.values[argument_cursor++].asWord();
}
float SferaMbcRuntime::nextReal()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return 0;
    }
    return g_sfera_mbc_runtime.values[argument_cursor++].asReal();
}
SferaSliceReference32 &SferaMbcRuntime::nextSliceReference(std::string_view diagnostic)
{
    if (argument_cursor >= argument_end)
    {
        reportError(diagnostic);
        g_sfera_mbc_runtime.sliceup_fallback = {};
        return g_sfera_mbc_runtime.sliceup_fallback;
    }
    return g_sfera_mbc_runtime.values[argument_cursor++].asSlice();
}
SferaSliceReference32 SferaMbcRuntime::nextSlice()
{
    return nextSliceReference("popsliceup(): stack underflow");
}
SferaSliceReference32 SferaMbcRuntime::nextAddress()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return {};
    }
    const auto &argument = values[argument_cursor++];
    if (argument.isPointer())
        return argument.value;
    return {argument.asWord(), 0, 0};
}
void SferaMbcRuntime::pushInteger(std::uint32_t number)
{
    if (value_stack_size >= std::size(g_sfera_mbc_runtime.values))
    {
        reportError("Stack overflow");
        return;
    }
    auto &slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.type = SferaMbcValueTypeInteger;
    slot.value.base = number;
    slot.detach();
}
void SferaMbcRuntime::pushReal(float number)
{
    if (value_stack_size >= std::size(g_sfera_mbc_runtime.values))
    {
        reportError("Stack overflow");
        return;
    }
    auto &slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.type = SferaMbcValueTypeReal;
    slot.setReal(number);
    slot.detach();
}
void SferaMbcRuntime::pushReal(double number)
{
    pushReal(SferaNumeric::real32(number));
}
void SferaMbcRuntime::pushSlice(const SferaSliceReference32 &value, SferaMbcValueType type)
{
    if (value_stack_size >= std::size(g_sfera_mbc_runtime.values))
    {
        reportError("Stack overflow");
        return;
    }
    auto &slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.type = type;
    slot.value = value;
    slot.detach();
}

void SferaMbcRuntime::pushReference(SferaMbcValueType type, const SferaSliceReference32 &reference, bool load)
{
    const auto source = reference;
    auto &slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.source = source;
    slot.type = type;
    if (!load || type == SferaMbcValueTypeAddress)
    {
        slot.value = source;
        slot.width = sizeof(source);
    }
    else if (type == SferaMbcValueTypeByte)
    {
        slot.value.base = readMemory<std::int8_t>(source.base);
        slot.type = SferaMbcValueTypeInteger;
        slot.width = sizeof(std::int8_t);
    }
    else if (type == SferaMbcValueTypeInteger || type == SferaMbcValueTypeReal)
    {
        slot.value.base = readMemory<std::uint32_t>(source.base);
        slot.width = sizeof(std::uint32_t);
    }
    else
    {
        slot.value = readMemory<SferaSliceReference32>(source.base);
        slot.width = sizeof(source);
    }
}

void SferaMbcRuntime::bindParameters()
{
    const auto declaration = readOperand<std::int8_t>();
    const int capacity = declaration < 0 ? -declaration : declaration;
    if (argument_count < 0 || (declaration >= 0 && argument_count != capacity) || argument_count > capacity)
    {
        text_buffer = std::format("Wrong number of parameters (must be {}, present {})", +declaration, argument_count);
        reportError(text_buffer);
        return;
    }
    const auto supplied = std::min(capacity, argument_count);
    const auto &stack = g_sfera_mbc_runtime.values;
    if (argument_cursor > std::size(stack) || supplied > std::size(stack) - argument_cursor)
    {
        reportError("Parameter stack overflow");
        return;
    }
    for (int index = 0; index < capacity; ++index)
    {
        const auto type = readOperand<SferaMbcValueType>();
        const auto offset = readOperand<std::uint32_t>();
        if (index < supplied)
            stack[argument_cursor + index].storeAs(type, memoryRange(offset));
        else
        {
            const SferaMbcValue zero{};
            zero.storeAs(type, memoryRange(offset));
        }
    }
}
