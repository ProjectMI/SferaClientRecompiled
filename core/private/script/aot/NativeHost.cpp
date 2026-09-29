#include "script/NativeFunctions.h"
#include "script/MbcRuntime.h"
#include "script/NativeCall.h"

SferaMbcValue sferaHost2(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptExit();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost3(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSin();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost4(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCos();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost5(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptAbsoluteReal();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost6(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptIntegerValue(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost7(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptArcTangent();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost9(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scanText();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost10(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.windowCommand();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost11(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptPackColor();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost12(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSquareRoot();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost13(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSceneContext();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost14(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptKeyboardState();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost15(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptAllocateMemory();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost16(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptLoadProcess();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost17(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptUnloadProcess();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost18(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptLinkProcess();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost19(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptProcessModule();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost20(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.callFunction(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost21(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.callFunction(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost24(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCurrentModule();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost26(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.buildRegion();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost27(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptZeroResult();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost28(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptFindProcess();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost29(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptProfileValue();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost30(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptConnect();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost31(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptDisconnect();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost33(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.receiveRegion();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost34(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCopyString(false, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost35(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCopyString(false, true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost36(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptStringLength();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost37(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCompareStrings(false, false, true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost38(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.writeScriptLog();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost39(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCurrentProcess();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost40(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptOpenFile(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost41(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptOpenFile(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost42(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCloseFile();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost43(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptTransferFile(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost44(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptTransferFile(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost45(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptIntegerValue(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost46(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptRealValue();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost47(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCreateObject();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost48(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptWorldPosition(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost49(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptWorldPosition(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost50(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectTransform(false, false, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost51(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectTransform(false, true, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost52(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectTransform(true, false, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost53(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectTransform(false, false, true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost54(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectComponent(true, 0u);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost55(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectComponent(true, 1u);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost56(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectComponent(true, 2u);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost57(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectComponent(false, 0u);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost58(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectComponent(false, 1u);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost59(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectComponent(false, 2u);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost60(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptDestroyResource(SferaMbcRuntimeResourceKind::worldObject);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost61(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptText();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost62(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptDestroyResource(SferaMbcRuntimeResourceKind::textControl);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost63(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptTextColor();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost65(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSeekFile();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost66(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptFileSize();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost67(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.formatText(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost68(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptRenameFile();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost69(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptRemoveFile();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost70(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptFileTime();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost71(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptResizeFile();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost72(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSetFileTime();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost73(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSprite();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost75(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCompareStrings(true, false, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost76(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCompareStrings(false, true, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost77(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCopyProcess(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost78(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCopyMemory(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost79(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCopyMemory(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost81(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.calculateDistance();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost82(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptStopInterpreter();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost83(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptMovementContact();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost84(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectProcess();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost85(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptNetworkInitialization();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost86(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptDiscardArgument();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost87(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptAnimationValue(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost88(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptAnimationValue(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost89(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptAnimationLength();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost90(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSetInterpolation();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost91(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.writeFormattedLog(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost92(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCommandVelocity();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost93(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectVelocity(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost94(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectVelocity(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost95(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptFindString(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost96(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCopyMemory(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost97(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptAirborne();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost98(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptMouseMotion();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost99(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptSetRenderEnabled();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost100(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectVector(false, true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost101(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectVector(true, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost102(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptObjectVector(false, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost103(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.systemCommand();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost104(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptProcessName(true, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost105(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptDestroyResource(SferaMbcRuntimeResourceKind::spriteControl);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost106(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptRandomReal();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost107(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptProcessName(false, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost108(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptCopyProcess(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost110(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptFindModule();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost111(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptEffect();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost112(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptDynamicArray(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost113(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptDynamicArray(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost114(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptNamedValue(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost115(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptNamedValue(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost117(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptConfiguration();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost118(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptFontSettings();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost119(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptInvalidResult();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost121(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptRebaseSlice();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost122(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptNoop();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost123(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.formatText(true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost124(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptReadLine();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost126(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.writeFormattedLog(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost128(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.parseText();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost129(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.chatUtility();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost132(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptPlayerLists();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost148(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptWriteScalar(1u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost149(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptWriteScalar(2u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost150(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptWriteScalar(3u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost151(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptWriteScalar(4u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost152(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptWriteScalar(4u, true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost154(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptReadScalar(1u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost155(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptReadScalar(2u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost156(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptReadScalar(3u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost157(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptReadScalar(4u, false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost158(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptReadScalar(4u, true);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost159(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptTransferString(false);
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost161(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptContainerCommand();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost162(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptContainerManagement();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}

SferaMbcValue sferaHost163(SferaNativeContext &c, std::span<const SferaMbcValue> args)
{
    auto &runtime = *c.runtime;
    SferaNativeCallScope invocation(runtime, args);
    runtime.scriptMemoryChecksum();
    auto result = invocation.finish();
    if (runtime.execution_failed) throw SferaNativeExecutionFailed{};
    return result;
}
