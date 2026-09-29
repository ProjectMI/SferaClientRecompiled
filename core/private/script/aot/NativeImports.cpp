#include "script/NativeFunctions.h"
#include "script/NativeImports.h"
#include <utility>

SferaMbcValue sferaImport_AddPrayer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(7u, providers, SferaFunctions::pcontrol_AddPrayer);
    return SferaFunctions::pcontrol_AddPrayer(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Anim(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(15u, providers, SferaFunctions::char_Anim);
    return SferaFunctions::char_Anim(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_AskAlly(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(17u, providers, SferaFunctions::pcontrol_AskAlly);
    return SferaFunctions::pcontrol_AskAlly(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_AskForFile(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000080ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(19u, providers, SferaFunctions::files_AskForFile);
    return SferaFunctions::files_AskForFile(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_BankOper(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000008ull, 0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(27u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CalcRequirs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(42u, providers, SferaFunctions::player_CalcRequirs);
    return SferaFunctions::player_CalcRequirs(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CallEnd(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0xffffffffff000000ull, 0x0000000000001fffull};
    const auto entry = c.exportEntry(44u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CallLink(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0xffffffffff000000ull, 0x0000000000001fffull};
    const auto entry = c.exportEntry(45u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CallPict(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0xffffffffff000000ull, 0x0000000000001fffull};
    const auto entry = c.exportEntry(46u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CenterObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(50u, providers, SferaFunctions::cobj_CenterObj);
    return SferaFunctions::cobj_CenterObj(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_ControlOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(75u, providers, SferaFunctions::pcontrol_ControlOn);
    return SferaFunctions::pcontrol_ControlOn(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CopyAb(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0030600000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(77u, providers, SferaFunctions::npc01_CopyAb);
    return SferaFunctions::npc01_CopyAb(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CountAnim(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(78u, providers, SferaFunctions::cobj_CountAnim);
    return SferaFunctions::cobj_CountAnim(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CreateObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(81u, providers, SferaFunctions::cobj_CreateObj);
    return SferaFunctions::cobj_CreateObj(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_CreateObjWait(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(82u, providers, SferaFunctions::cobj_CreateObjWait);
    return SferaFunctions::cobj_CreateObjWait(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_DestroyObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(95u, providers, SferaFunctions::cobj_DestroyObj);
    return SferaFunctions::cobj_DestroyObj(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_DirectOfObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(99u, providers, SferaFunctions::cobj_DirectOfObj);
    return SferaFunctions::cobj_DirectOfObj(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x000000000000300eull, 0xffffeff600000000ull, 0x0000004000000003ull, 0x0000000000008000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(117u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GCIID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(122u, providers, SferaFunctions::player_GCIID);
    return SferaFunctions::player_GCIID(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GCIName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(123u, providers, SferaFunctions::player_GCIName);
    return SferaFunctions::player_GCIName(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GCIRange(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(124u, providers, SferaFunctions::player_GCIRange);
    return SferaFunctions::player_GCIRange(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetAddrs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000400000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(138u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetAllyList(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(140u, providers, SferaFunctions::player_GetAllyList);
    return SferaFunctions::player_GetAllyList(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetCaster(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000002000ull};
    const auto entry = c.exportEntry(151u, providers, SferaFunctions::main_getWasUpdate);
    return SferaFunctions::main_getWasUpdate(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetConfVis(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(158u, providers, SferaFunctions::bank_GetAmount);
    return SferaFunctions::bank_GetAmount(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetDirAndSpeed(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(163u, providers, SferaFunctions::pcontrol_GetDirAndSpeed);
    return SferaFunctions::pcontrol_GetDirAndSpeed(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetModifiers(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000002000ull};
    const auto entry = c.exportEntry(191u, providers, SferaFunctions::virus_GetModifiers);
    return SferaFunctions::virus_GetModifiers(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetModifs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000002000ull};
    const auto entry = c.exportEntry(192u, providers, SferaFunctions::virus_GetModifs);
    return SferaFunctions::virus_GetModifs(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetModifsArr(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000002000ull};
    const auto entry = c.exportEntry(193u, providers, SferaFunctions::virus_GetModifsArr);
    return SferaFunctions::virus_GetModifsArr(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetMoney(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(194u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0xffffffffffc08008ull, 0xff9fffffffffffffull, 0xffffffffffffffffull, 0xffffffffffffffffull, 0x0000000000ffffffull, 0x0000ffffffffe000ull};
    const auto entry = c.exportEntry(203u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetParent(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0xffffffffffc08008ull, 0xff9fffffffffffffull, 0xffffffffffffffffull, 0xffffffffffffffffull, 0x0000000000ffffffull, 0x0000ffffffffe000ull};
    const auto entry = c.exportEntry(206u, providers, SferaFunctions::bank_GetParent);
    return SferaFunctions::bank_GetParent(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetPictsPointer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(208u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetRootParent(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0xffffffffffc08008ull, 0xff9fffffffffffffull, 0xffffffffffffffffull, 0xffffffffffffffffull, 0x0000000000ffffffull, 0x0000ffffffffe000ull};
    const auto entry = c.exportEntry(221u, providers, SferaFunctions::bank_GetRootParent);
    return SferaFunctions::bank_GetRootParent(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008008ull, 0x0000ffffff9fb800ull, 0x37b1efb71c000000ull, 0x0000004003000001ull, 0x0000000000408000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(225u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008008ull, 0x0000ffffff9fb800ull, 0x37b1efb71c000000ull, 0x0000004003000001ull, 0x0000000000408000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(226u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_GetTableTime(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000400000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(235u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Getabg(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(253u, providers, SferaFunctions::player_Getabg);
    return SferaFunctions::player_Getabg(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Getxyz(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(258u, providers, SferaFunctions::player_Getxyz);
    return SferaFunctions::player_Getxyz(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_HideWebShopWindow(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000010000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(266u, providers, SferaFunctions::player_webshop_HideWebShopWindow);
    return SferaFunctions::player_webshop_HideWebShopWindow(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_IfInv(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000e00ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(269u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_IfPuppet(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000020000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(270u, providers, SferaFunctions::bank_GetParent);
    return SferaFunctions::bank_GetParent(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_IfTeleported(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(271u, providers, SferaFunctions::bank_IsUnique);
    return SferaFunctions::bank_IsUnique(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InitAI(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(277u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InitChar(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(278u, providers, SferaFunctions::char_InitChar);
    return SferaFunctions::char_InitChar(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InitCharOwn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(279u, providers, SferaFunctions::char_InitCharOwn);
    return SferaFunctions::char_InitCharOwn(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InitCharPC(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(280u, providers, SferaFunctions::char_InitCharPC);
    return SferaFunctions::char_InitCharPC(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InvOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000e00ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(284u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InvOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000e00ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(285u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InvTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000e00ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(286u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_InvertAI(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(287u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_IsOwn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(307u, providers, SferaFunctions::bank_HavePassw);
    return SferaFunctions::bank_HavePassw(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_IsReceived(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000080ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(308u, providers, SferaFunctions::bank_GetObjHan);
    return SferaFunctions::bank_GetObjHan(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_IsWebShopWindowOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000010000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(312u, providers, SferaFunctions::bank_GetObjHan);
    return SferaFunctions::bank_GetObjHan(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_LoadMsgGroup(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000100ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(323u, providers, SferaFunctions::gmsg_LoadMsgGroup);
    return SferaFunctions::gmsg_LoadMsgGroup(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Model(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(346u, providers, SferaFunctions::player_Model);
    return SferaFunctions::player_Model(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_ModifsLoaded(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000002000ull};
    const auto entry = c.exportEntry(347u, providers, SferaFunctions::main_GetShopID);
    return SferaFunctions::main_GetShopID(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_NumToModel(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(356u, providers, SferaFunctions::player_NumToModel);
    return SferaFunctions::player_NumToModel(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PCNThit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(360u, providers, SferaFunctions::pcontrol_PCNThit);
    return SferaFunctions::pcontrol_PCNThit(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Params(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x000000000000300eull, 0xbb8e0ff600000000ull, 0x0000004000000002ull, 0x0000000000008000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(361u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Paused(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(366u, providers, SferaFunctions::player_Paused);
    return SferaFunctions::player_Paused(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PercentReceived(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000080ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(367u, providers, SferaFunctions::bank_GetAmount);
    return SferaFunctions::bank_GetAmount(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Pet(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x000000000000300eull, 0xbb8e0ff600000000ull, 0x0000004000000002ull, 0x0000000000008000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(368u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PlFromBuf(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(369u, providers, SferaFunctions::player_PlFromBuf);
    return SferaFunctions::player_PlFromBuf(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PlaySnd(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(371u, providers, SferaFunctions::char_PlaySnd);
    return SferaFunctions::char_PlaySnd(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PlayerName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(372u, providers, SferaFunctions::player_PlayerName);
    return SferaFunctions::player_PlayerName(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PuppetOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000020000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(379u, providers, SferaFunctions::inventory_InvOff);
    return SferaFunctions::inventory_InvOff(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PuppetOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000020000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(380u, providers, SferaFunctions::puppet_PuppetOn);
    return SferaFunctions::puppet_PuppetOn(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PuppetTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000020000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(381u, providers, SferaFunctions::puppet_PuppetTrig);
    return SferaFunctions::puppet_PuppetTrig(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_PutMoney(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(383u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_QueryShowWebShop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(385u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SPDEFF(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(406u, providers, SferaFunctions::pcontrol_SPDEFF);
    return SferaFunctions::pcontrol_SPDEFF(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SVisChar(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(411u, providers, SferaFunctions::char_SVisChar);
    return SferaFunctions::char_SVisChar(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SeekFor(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(418u, providers, SferaFunctions::player_SeekFor);
    return SferaFunctions::player_SeekFor(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SelectChar(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(422u, providers, SferaFunctions::pcontrol_SelectChar);
    return SferaFunctions::pcontrol_SelectChar(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Selected(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(423u, providers, SferaFunctions::bank_GetAmount);
    return SferaFunctions::bank_GetAmount(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SendAllyAsk(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(425u, providers, SferaFunctions::player_SendAllyAsk);
    return SferaFunctions::player_SendAllyAsk(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetAllyList(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(443u, providers, SferaFunctions::player_SetAllyList);
    return SferaFunctions::player_SetAllyList(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetClan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(445u, providers, SferaFunctions::player_SetClan);
    return SferaFunctions::player_SetClan(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetClanXZ(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000004000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(447u, providers, SferaFunctions::pcontrol_SetClanXZ);
    return SferaFunctions::pcontrol_SetClanXZ(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetHealth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0xffffffffffc08008ull, 0xff9fffffffffffffull, 0xffffffffffffffffull, 0xffffffffffffffffull, 0x0000000000ffffffull, 0x0000ffffffffe000ull};
    const auto entry = c.exportEntry(456u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetItemGroup(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000100ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(458u, providers, SferaFunctions::gmsg_SetItemGroup);
    return SferaFunctions::gmsg_SetItemGroup(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetModel(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(465u, providers, SferaFunctions::pcontrol_SetDebug);
    return SferaFunctions::pcontrol_SetDebug(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetRespRadius(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(474u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetTax(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000400000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(481u, providers, SferaFunctions::cs_table_SetTax);
    return SferaFunctions::cs_table_SetTax(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetTestItFlag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008008ull, 0x0000ffffff9fb800ull, 0x37b1efb71c000000ull, 0x0000004003000001ull, 0x0000000000408000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(482u, providers, SferaFunctions::bank_SetTestItFlag);
    return SferaFunctions::bank_SetTestItFlag(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(487u, providers, SferaFunctions::cobj_SetTrig);
    return SferaFunctions::cobj_SetTrig(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetWear(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(491u, providers, SferaFunctions::player_SetWear);
    return SferaFunctions::player_SetWear(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Setabg(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0xffffffffffc08008ull, 0xff9fffffffffffffull, 0xffffffffffffffffull, 0xffffffffffffffffull, 0x0000000000ffffffull, 0x0000ffffffffe000ull};
    const auto entry = c.exportEntry(494u, providers, SferaFunctions::bank_Setabg);
    return SferaFunctions::bank_Setabg(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SetddHan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000020e00ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(495u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Sethp(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(496u, providers, SferaFunctions::player_Sethp);
    return SferaFunctions::player_Sethp(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Setxyz(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0xffffffffffc08008ull, 0xff9fffffffffffffull, 0xffffffffffffffffull, 0xffffffffffffffffull, 0x0000000000ffffffull, 0x0000ffffffffe000ull};
    const auto entry = c.exportEntry(497u, providers, SferaFunctions::bank_Setxyz);
    return SferaFunctions::bank_Setxyz(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_ShowEff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(512u, providers, SferaFunctions::char_ShowEff);
    return SferaFunctions::char_ShowEff(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_ShowWebShopWindow(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000010000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(517u, providers, SferaFunctions::player_webshop_ShowWebShopWindow);
    return SferaFunctions::player_webshop_ShowWebShopWindow(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_SpeedObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000040ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(520u, providers, SferaFunctions::cobj_SpeedObj);
    return SferaFunctions::cobj_SpeedObj(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TableOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000080000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(533u, providers, SferaFunctions::table_TableOff);
    return SferaFunctions::table_TableOff(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TableOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000080000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(534u, providers, SferaFunctions::table_TableOn);
    return SferaFunctions::table_TableOn(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TableTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000080000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(535u, providers, SferaFunctions::table_TableTrig);
    return SferaFunctions::table_TableTrig(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_Teleport(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(536u, providers, SferaFunctions::player_Teleport);
    return SferaFunctions::player_Teleport(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008008ull, 0x0000ffffff9fb800ull, 0x37b1efb71c000000ull, 0x0000004003000001ull, 0x0000000000408000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(538u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TradeOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000102000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(549u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TradeOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000102000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(550u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TradeTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000102000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(551u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_TurnSkin(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(553u, providers, SferaFunctions::char_TurnSkin);
    return SferaFunctions::char_TurnSkin(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_UnloadMsgGroup(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000100ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(560u, providers, SferaFunctions::gmsg_UnloadMsgGroup);
    return SferaFunctions::gmsg_UnloadMsgGroup(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_WaitForAsk(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(576u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_gMsg(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000100ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(651u, providers, SferaFunctions::gmsg_gMsg);
    return SferaFunctions::gmsg_gMsg(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_getFistPowerups(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(660u, providers, SferaFunctions::main_Shadowing2);
    return SferaFunctions::main_Shadowing2(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_getMarkOnMapXZ(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(667u, providers, SferaFunctions::player_getMarkOnMapXZ);
    return SferaFunctions::player_getMarkOnMapXZ(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_getPictName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0xffffffffffc08008ull, 0xff9fffffffffffffull, 0xffffffffffffffffull, 0xffffffffffffffffull, 0x0000000000ffffffull, 0x0000ffffffffe000ull};
    const auto entry = c.exportEntry(676u, providers, SferaNativeCallable{});
    return entry.function()(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_getSkinNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(682u, providers, SferaFunctions::bank_GetObjHan);
    return SferaFunctions::bank_GetObjHan(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_getUpgradeMoney(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(685u, providers, SferaFunctions::bank_IsUnique);
    return SferaFunctions::bank_IsUnique(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_isInvisible(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000000000ull, 0x0000000001000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(707u, providers, SferaFunctions::ai_isFlamount);
    return SferaFunctions::ai_isFlamount(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_pClanName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000400000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(755u, providers, SferaFunctions::player_PlayerName);
    return SferaFunctions::player_PlayerName(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_pEnemies(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000008000ull, 0x000000000000300eull, 0xbb8e0ff600000000ull, 0x0000004000000002ull, 0x0000000000008000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(756u, providers, SferaFunctions::player_pEnemies);
    return SferaFunctions::player_pEnemies(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_pUSTATE(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000000ull, 0x0000000000008000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000400000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(758u, providers, SferaFunctions::cs_table_pUSTATE);
    return SferaFunctions::cs_table_pUSTATE(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_readstr(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000080ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(770u, providers, SferaFunctions::files_readstr);
    return SferaFunctions::files_readstr(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_refreshSkin(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(778u, providers, SferaFunctions::char_refreshSkin);
    return SferaFunctions::char_refreshSkin(c.exportContext(entry), args);
}

SferaMbcValue sferaImport_turnSkinAndSetVis(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    static constexpr std::uint64_t providers[] = {0x0000000000000010ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull};
    const auto entry = c.exportEntry(831u, providers, SferaFunctions::char_turnSkinAndSetVis);
    return SferaFunctions::char_turnSkinAndSetVis(c.exportContext(entry), args);
}
