#include "script/MbcRuntime.h"
#include "script/NativeContext.h"

#include <stdexcept>
#include <string>

bool SferaMbcRuntime::hasNativeEntry(const SferaMbcProcessRecord &process, SferaNativeEntry entry)
{
    if (!entry.valid() || entry.binding_index >= process.native_bindings.size())
        return false;
    // Network/script values never carry C++ function pointers. All non-empty
    // callables originate in generated program/export declarations; the mutable
    // part is the checked binding index. There is no routine-membership scan.
    return true;
}

SferaMbcValue SferaMbcRuntime::invokeNative(SferaMbcProcessRecord &target, int targetProgram, SferaNativeEntry entry,
                                          std::span<const SferaMbcValue> arguments)
{
    if (targetProgram < 0 || static_cast<std::size_t>(targetProgram) >= target.programs.size() ||
        !hasNativeEntry(target, entry) || entry.function() == nullptr)
        throw std::out_of_range("Invalid native function entry");
    if (native_call != nullptr)
        native_call->scratch.flush();
    // These are normal C++ automatic variables restoring host context, not VM
    // return addresses or an interpreter-managed return stack.
    const auto previousProcess = process_index;
    const auto previousProgram = program_index;
    const auto previousCaller = native_caller_process;
    const auto previousModule = source_module;
    const auto previousCheckpoint = native_checkpoint;
    const auto previousFunction = source_function;
    const auto previousExecuting = target.programs[targetProgram].executing;
    auto restore = [&]() noexcept
    {
        --target.native_depth;
        auto &program = target.programs[targetProgram];
        program.executing = previousExecuting;
        if (!previousExecuting && program.pending_start)
            program.select(*program.pending_start);
        process_index = previousProcess;
        program_index = previousProgram;
        native_caller_process = previousCaller;
        active_process = previousProcess >= 0 ? &processes[previousProcess] : nullptr;
        program_table_base = active_process != nullptr ? active_process->programs.data() : nullptr;
        active_program_record = active_process != nullptr && previousProgram >= 0 &&
            static_cast<std::size_t>(previousProgram) < active_process->programs.size() ? &active_process->programs[previousProgram] : nullptr;
        source_module = previousModule;
        native_checkpoint = previousCheckpoint;
        source_function = previousFunction;
    };
    native_caller_process = active_process != nullptr ? active_process->process_id : UINT32_MAX;
    process_index = static_cast<std::int32_t>(target.process_id);
    program_index = targetProgram;
    active_process = &target;
    program_table_base = target.programs.data();
    active_program_record = &target.programs[targetProgram];
    active_program_record->executing = true;
    ++target.native_depth;
    try
    {
        const auto binding = target.native_bindings[entry.binding_index];
        auto result = entry.function()(SferaNativeContext(*this, binding), arguments);
        restore();
        return result;
    }
    catch (...)
    {
        restore();
        throw;
    }
}

SferaAotStepResult SferaMbcRuntime::resumeNativeProgram(bool stopping)
{
    auto *const process = active_process;
    const auto index = program_index;
    if (process == nullptr || index < 0 || static_cast<std::size_t>(index) >= process->programs.size())
        return SferaAotStepResult::Failed;
    auto &initial = process->programs[index];
    if (stopping && initial.selected != initial.stop)
        initial.select(initial.stop);
    const auto entry = initial.selected;
    if (!hasNativeEntry(*process, entry))
    {
        reportError("Invalid native program entry");
        return SferaAotStepResult::Failed;
    }
    const auto binding = process->native_bindings[entry.binding_index];
    SferaAotStepResult result = SferaAotStepResult::EndProgram;
    ++process->native_depth;
    initial.executing = true;
    try
    {
        if (entry.coroutine() != nullptr)
        {
            if (!initial.task)
                initial.task = std::make_shared<SferaNativeTask>(entry.coroutine()(SferaNativeContext(*this, binding), {}));
            // A local owner survives a module link or a self-restart request.
            const auto task = initial.task;
            task->resume();
            if (task->done())
                (void)task->result();
            else
                result = SferaAotStepResult::Yield;
        }
        else
            (void)entry.function()(SferaNativeContext(*this, binding), {});
    }
    catch (const SferaNativeBudgetExceeded &) { result = SferaAotStepResult::BudgetExceeded; }
    catch (const SferaNativeExecutionFailed &) { result = SferaAotStepResult::Failed; }
    catch (const std::exception &error)
    {
        reportError(error.what());
        result = SferaAotStepResult::Failed;
    }
    --process->native_depth;
    program_table_base = process->programs.data();
    active_program_record = &process->programs[index];
    active_program_record->executing = false;
    if (execution_failed)
        result = SferaAotStepResult::Failed;
    if (active_program_record->pending_start)
    {
        const auto next = *active_program_record->pending_start;
        active_program_record->select(next);
        if (result == SferaAotStepResult::Yield || result == SferaAotStepResult::EndProgram)
            result = SferaAotStepResult::Yield;
    }
    else if (result != SferaAotStepResult::Yield)
        active_program_record->task.reset();
    return result;
}

void SferaMbcRuntime::drainDeferredUnloads()
{
    for (auto &process : processes)
        if (process.chain_prev_index >= 0 && process.native_depth == 0 && (process.flags & SferaMbcProcessRecordFlagsmarkedForUnload) != 0)
            unloadProcess(process.process_id);
}
