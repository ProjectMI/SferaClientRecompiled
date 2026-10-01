#include <windows.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <ctime>
#include <format>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "animation/Animation.h"
#include "application/ClientApplication.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "effects/EffectManager.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "script/MbcRuntime.h"
#include "ui/Rendering.h"
#include "world/WorldObjects.h"

void SphereRenderModelPose::missingAnimation(std::string_view modelName, int animation, int frame)
{
    auto message = std::format("CalcCharacterNeck: model has no animation (model='{}', controlled={}, animation={}, frame={})", modelName, g_sfera_world_objects.controlled_object_handle, animation,
                               frame);
    const auto &scriptError = g_sfera_mbc_runtime.first_execution_error;
    if (!scriptError.empty())
    {
        message += "\nFirst script error in this session:\n" + scriptError;
    }
    g_sfera_log_runtime.write(message);
    WorldDiagnostics::fail(message);
}

void SferaLogRuntime::initialize()
{
    path = "Error.log";
    size_limit = 10000000u;
    writeTimestamp("**** Start: ");
}

void SferaEngineDiagnosticsAdapter::bind() noexcept
{
    SferaVec3F::setNormalizationFailureHandler(&SferaEngineDiagnosticsAdapter::fail);
    SferaEngineDiagnostics::install({&SferaEngineDiagnosticsAdapter::fatal, &SferaEngineDiagnosticsAdapter::fail, &SferaEngineDiagnosticsAdapter::write, &SferaEngineDiagnosticsAdapter::lightActivated,
                                     &SferaEngineDiagnosticsAdapter::report, &SferaEngineDiagnosticsAdapter::warning});
}

void SferaEngineDiagnosticsAdapter::fatal(std::string_view message)
{
    SferaClientApplication::terminateWithError(message);
}

void SferaEngineDiagnosticsAdapter::fail(std::string_view message)
{
    WorldDiagnostics::fail(message);
}

void SferaEngineDiagnosticsAdapter::write(std::string_view message)
{
    g_sfera_log_runtime.write(message);
}

void SferaEngineDiagnosticsAdapter::lightActivated() noexcept
{
    if (g_sfera_effect_manager.diagnostics.enabled)
        ++g_sfera_effect_manager.diagnostics.light_activations;
}

void SferaEngineDiagnosticsAdapter::report(std::string_view message)
{
    WorldDiagnostics::report(message);
}

void SferaEngineDiagnosticsAdapter::warning(std::string_view message)
{
    WorldDiagnostics::warning(message);
}

void SferaErrorLogRuntime::initialize(IOutputDevice *error, IOutputDevice *log)
{
    auto nextError = error == nullptr ? std::make_unique<CSphereError>() : nullptr;
    auto nextLog = log == nullptr ? std::make_unique<COutputLogDevice>() : nullptr;
    if (nextLog)
        nextLog->setFilename("sphere.log");
    if (error != nullptr && error == owned_error.get())
        nextError = std::move(owned_error);
    if (log != nullptr && log == owned_log.get())
        nextLog = std::move(owned_log);
    clear();
    owned_error = std::move(nextError);
    owned_log = std::move(nextLog);
    outputs[0] = owned_error ? owned_error.get() : error;
    outputs[1] = owned_log ? owned_log.get() : log;
    enabled = true;
}

void SferaErrorLogRuntime::clear()
{
    outputs[0] = outputs[1] = nullptr;
    enabled = false;
    owned_log.reset();
    owned_error.reset();
}

void SphereUIInterfaceRenderer::reportError(std::string_view message)
{
    for (std::uint32_t index : {1u, 0u})
        if (auto *output = g_sfera_error_log_runtime.outputs[index])
        {
            if (index == 1u)
                output->write("*** ERROR ****************************************************:");
            output->write(message);
        }
}

void WorldDiagnostics::appendScriptContext(std::string_view text)
{
    WorldDiagnostics::message.append(text);
}

void WorldDiagnostics::flushScriptContext()
{
    if (const auto context = scriptContext())
    {
        appendScriptContext("\n");
        appendScriptContext(*context);
    }
    warning(WorldDiagnostics::message);
    appendScriptContext("\n\n");
}

void WorldDiagnostics::describeScript(bool includeTime)
{
    auto &runtime = g_sfera_mbc_runtime;
    auto &output = runtime.diagnostic_context;
    output.clear();
    if (includeTime)
    {
        const auto now = std::time(nullptr);
        std::tm local{};
#ifdef _WIN32
        localtime_s(&local, &now);
#else
        localtime_r(&now, &local);
#endif
        output = std::format("{:02}:{:02}:{:02} ", local.tm_hour, local.tm_min, local.tm_sec);
    }
    if (const auto *module = runtime.current.module)
        output += std::format("Native script: {}::{}; process: {}, generation: {}\n", module->moduleName(), runtime.current.function, module->processId, module->lifetime);
    else
        output += "Native script context is not active\n";
}

void WorldDiagnostics::appendCallStack(std::string &output)
{
    const auto *execution = g_sfera_mbc_runtime.execution;
    if (!execution)
        return;
    for (auto call = execution->calls.rbegin(); call != execution->calls.rend(); ++call)
        if (call->caller.module)
            output += std::format("Called from {}::{} in process {}\n", call->caller.module->moduleName(), call->caller.function, call->caller.module->processId);
}

std::optional<std::string_view> WorldDiagnostics::scriptContext()
{
    auto &runtime = g_sfera_mbc_runtime;
    if (!runtime.current.module)
    {
        runtime.diagnostic_context.clear();
        return std::nullopt;
    }
    describeScript(true);
    appendCallStack(runtime.diagnostic_context);
    return runtime.diagnostic_context;
}

bool SferaMbcRuntime::reportError(std::string_view message)
{
    WorldDiagnostics::scriptContext();
    if (first_execution_error.empty())
        first_execution_error = std::format("{}\n{}", message, diagnostic_context);
    auto &log = g_sfera_log_runtime;
    log.write("\n---exit_inter start---\nMBINTER MESSAGE:");
    log.write(message);
    log.write("\n");
    log.write(diagnostic_context);
    log.write("---exit_inter end-----\n");
    execution_failed = true;
    if (process_index == 0)
    {
        CSphereError output;
        output.write(diagnostic_context);
    }
    return processes[0].activateProgram("EError");
}
bool SferaMbcRuntime::reportError(std::string_view prefix, std::string_view suffix)
{
    return reportError(std::format("{}{}", prefix, suffix));
}

void WorldDiagnostics::report(std::string_view text)
{
    SphereUIInterfaceRenderer::reportError(text);
}

[[noreturn]] void WorldDiagnostics::fail(std::string_view text)
{
    report(text);
    throw std::runtime_error(std::string(text.empty() ? std::string_view{"World operation failed"} : text));
}

void WorldDiagnostics::warning(std::string_view text)
{
    ::OutputDebugStringA(std::string(text).c_str());
    ::OutputDebugStringA("\n");
}
