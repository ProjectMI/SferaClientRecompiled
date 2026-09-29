#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::ct_bag_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_90, SferaFields::integer_184, 56u,
        SferaFields::integer_82, 12u, SferaFields::buffer_218, 48u, 4294967284u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::ct_bag_sendslot);
}

SferaMbcValue SferaFunctions::ct_bag_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_218, 48u, SferaFields::buffer_214, SferaFields::integer_219);
}

SferaNativeTask SferaFunctions::ct_bag_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_beb84fb0_body(std::move(c), std::move(args), SferaFields::integer_0, SferaFields::reference_62,
        SferaFields::integer_199, SferaFields::integer_201, SferaFields::buffer_295, SferaFields::buffer_298, 12u, SferaFields::buffer_218,
        48u, 4294967284u, SferaFields::buffer_214, 56u, SferaFunctions::ct_bag_sendslot);
}

SferaMbcValue SferaFunctions::ct_bag_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 49u, SferaFields::integer_204, SferaFields::integer_191,
        SferaFields::integer_205, 55u, SferaFields::integer_206, SferaFields::reference_197, SferaFields::buffer_203,
        SferaFields::integer_198, SferaFields::integer_192, 46u, 47u);
}

SferaMbcValue SferaFunctions::ct_bag_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 72u, 73u, SferaFields::reference_241, SferaFields::integer_200,
        SferaFields::buffer_287, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_288, SferaFields::buffer_289,
        SferaFields::buffer_290, 89u, 88u, SferaFields::buffer_291, SferaFields::buffer_283, SferaFields::buffer_284,
        SferaFields::integer_285, SferaFields::integer_286, SferaFields::reference_267, SferaFields::buffer_292,
        SferaFields::reference_266, SferaFields::buffer_293, SferaFields::reference_268, SferaFields::buffer_294,
        SferaFields::reference_269, SferaFields::buffer_246, SferaFields::reference_281, SferaFields::reference_282,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_264,
        SferaFields::integer_250, SferaFields::real_265, 3000000u, SferaFields::buffer_254, SferaFields::buffer_255, 74u, 78u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_bag_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_220, 17u, SferaFields::reference_221, 56u,
        SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_bag_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_218, 48u, 4294967284u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 12u, SferaFunctions::bank_openSlot, SferaFunctions::ct_bag_CheckWght);
}

SferaMbcValue SferaFunctions::ct_bag_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 57u, SferaFields::integer_222, 12u, SferaFields::integer_223,
        SferaFields::buffer_218, 48u, 4294967284u, SferaFields::integer_224);
}

SferaMbcValue SferaFunctions::ct_bag_SeekTagInsideNoRecursive(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 58u, SferaFields::integer_225, 12u, SferaFields::integer_226,
        SferaFields::buffer_218, 48u, 4294967284u);
}

SferaMbcValue SferaFunctions::ct_bag_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 59u, SferaFields::integer_217, SferaFields::integer_227, 12u, 63u,
        SferaFields::buffer_218, 48u, 4294967284u);
}

SferaMbcValue SferaFunctions::ct_bag_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 60u, SferaFields::integer_217, 61u, 62u, SferaFields::buffer_202, 79u,
        81u, SferaFields::integer_202_at_8, 12u, 80u, SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_270,
        SferaFields::buffer_271, 82u, 83u, 84u, 85u, SferaFields::buffer_272, 86u, SferaFields::buffer_273, SferaFields::buffer_275,
        SferaFields::buffer_273_at_12, SferaFields::buffer_276, SferaFields::buffer_274, SferaFields::buffer_277, SferaFields::buffer_278,
        SferaFields::buffer_279, SferaFields::buffer_280, 87u, SferaFields::buffer_182, SferaFunctions::ct_bag_TestIt);
}

SferaMbcValue SferaFunctions::ct_bag_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 3000000u);
}

SferaMbcValue SferaFunctions::ct_bag_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 67u, 68u, SferaFields::integer_235, 12u, SferaFields::buffer_218, 48u,
        4294967284u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_bag_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 69u, 56u, SferaFields::integer_236, 12u, SferaFields::buffer_218, 48u,
        4294967284u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_bag_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_190, 56u, SferaFields::integer_189, 12u,
        SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_bag_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 12u);
}

SferaMbcValue SferaFunctions::ct_bag_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_216, 12u, SferaFields::buffer_218, 48u, 4294967284u);
}

SferaMbcValue SferaFunctions::ct_bag_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_228, 12u, SferaFields::buffer_215, 48u, 4294967284u);
}

SferaMbcValue SferaFunctions::ct_bag_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_229, SferaFields::integer_230, 12u, SferaFields::buffer_218,
        48u, 4294967284u);
}

SferaMbcValue SferaFunctions::ct_bag_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_233, 12u, SferaFields::buffer_218, 48u, 4294967284u);
}

SferaMbcValue SferaFunctions::ct_bag_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_12088b0e_body(std::move(c), args, 77u, SferaFields::buffer_245, 44u,
        SferaFunctions::bank_GetUniqueGeneration);
}

SferaMbcValue SferaFunctions::main_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 4u);
}

SferaMbcValue SferaFunctions::main_WinAsyncInput(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_WinAsyncInput_body(std::move(c), args, SferaFields::integer_72_at_2, SferaFields::reference_5,
        SferaFields::reference_6, 0u, 6u);
}

SferaMbcValue SferaFunctions::main_WinAsyncInputNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_WinAsyncInput_body(std::move(c), args, SferaFields::integer_7, SferaFields::reference_8, SferaFields::reference_9,
        1u, 6u);
}

SferaMbcValue SferaFunctions::main_ShowConsole(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_HideConsole_body(std::move(c), args, 1u, 0u);
}

SferaMbcValue SferaFunctions::main_HideConsole(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_HideConsole_body(std::move(c), args, 0u, 1u);
}

SferaMbcValue SferaFunctions::main_cleanse_buffs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_cleanse_buffs_body(std::move(c), args, SferaFields::buffer_170, 29u, SferaFields::buffer_171, 14u);
}

SferaMbcValue SferaFunctions::main_cleanse_viruses(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_cleanse_buffs_body(std::move(c), args, SferaFields::buffer_172, 31u, SferaFields::buffer_173, 16u);
}

SferaMbcValue SferaFunctions::main_cm_create(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_cm_create_body(std::move(c), args, 54u);
}

SferaMbcValue SferaFunctions::main_cm_isVisible(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_cm_isVisible_body(std::move(c), args, SferaFields::integer_197, 109u, SferaFields::integer_225, 0u, 1u);
}

SferaMbcValue SferaFunctions::main_GetCastleName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GetCastleName_body(std::move(c), args, SferaFields::integer_470_at_13, 38u, SferaFields::buffer_432, 456u,
        4294967258u, SferaFields::buffer_471, 10u);
}

SferaMbcValue SferaFunctions::main_GTST(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GMOD_body(std::move(c), args, SferaFields::integer_471_at_10, SferaFields::buffer_297, 132u, 4294967263u);
}

SferaMbcValue SferaFunctions::main_GMOD(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GMOD_body(std::move(c), args, SferaFields::integer_472, SferaFields::buffer_299, 400u, 4294967196u);
}

SferaMbcValue SferaFunctions::main_SetOSST(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_586_at_16, SferaFields::integer_269);
}

SferaMbcValue SferaFunctions::main_getLastGVG(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_getLastGVG_body(std::move(c), args, SferaFields::buffer_603, 16u);
}

SferaMbcValue SferaFunctions::main_getTmntData(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_getLastGVG_body(std::move(c), args, SferaFields::buffer_604, 24u);
}

SferaMbcValue SferaFunctions::main_SetTmntState(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_SetTmntState_body(std::move(c), args, 8u);
}

SferaMbcValue SferaFunctions::main_GetTmntState(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_604, 24u, 8u);
}

SferaMbcValue SferaFunctions::main_SetTmntTimeLeft(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_SetTmntState_body(std::move(c), args, 12u);
}

SferaMbcValue SferaFunctions::main_GetTmntTimeLeft(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_604, 24u, 12u);
}

SferaMbcValue SferaFunctions::main_GetXYZ(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GetXYZ_body(std::move(c), args, SferaFields::integer_652, SferaFields::reference_653, SferaFields::buffer_654, 12u,
        12u);
}

SferaMbcValue SferaFunctions::main_SayConnectEnd_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_658_at_16, SferaFields::integer_658_at_16);
}

SferaMbcValue SferaFunctions::main_GetMainServerURL(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GetMainServerURL_body(std::move(c), args, SferaFields::reference_710_at_9, SferaFields::buffer_668, 100u);
}

SferaMbcValue SferaFunctions::main_GETLG(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetModel_body(std::move(c), args, SferaFields::integer_715, SferaFields::reference_716, SferaFields::buffer_292, 64u);
}

SferaMbcValue SferaFunctions::main_GETPD(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetModel_body(std::move(c), args, SferaFields::integer_717, SferaFields::reference_718, SferaFields::buffer_293, 30u);
}

SferaMbcValue SferaFunctions::main_Camera_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_Camera_stop_body(std::move(c), args, SferaFields::integer_80, 0u);
}

SferaMbcValue SferaFunctions::main_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_202_at_9, SferaFields::integer_198);
}

SferaMbcValue SferaFunctions::main_Shadowon_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_Camera_stop_body(std::move(c), args, SferaFields::integer_164, 0u);
}

SferaMbcValue SferaFunctions::main_Stop_StartWin(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 193u);
}

SferaMbcValue SferaFunctions::main_GetCrcBufferSize(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 15u);
}

SferaMbcValue SferaFunctions::main_getWasUpdate(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_83);
}

SferaMbcValue SferaFunctions::main_setWasUpdate(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_896_at_11, SferaFields::integer_83);
}

SferaMbcValue SferaFunctions::main_GetShopID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_247);
}

SferaMbcValue SferaFunctions::main_SetShopID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_923_at_5, SferaFields::integer_247);
}

SferaMbcValue SferaFunctions::main_Shadowing2(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_82);
}

SferaMbcValue SferaFunctions::main_GetTournamentId(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_166);
}

SferaMbcValue SferaFunctions::cs_gate_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 60u);
}

SferaMbcValue SferaFunctions::cs_gate_SetHealth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetHealth_body(std::move(c), args, SferaFields::buffer_161, 200u);
}

SferaMbcValue SferaFunctions::cs_gate_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_0c1a1db3_body(std::move(c), args, 78u, SferaFields::buffer_161, 200u, SferaFields::reference_239,
        SferaFields::buffer_132, 256u, SferaFields::integer_0, 46u, 47u);
}

SferaMbcValue SferaFunctions::cs_gate_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_9222d34b_body(std::move(c), args, SferaFunctions::cs_gate_UseOwner);
}

SferaMbcValue SferaFunctions::cs_gate_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_253, 12u, SferaFields::buffer_313, SferaFields::integer_300);
}

SferaMbcValue SferaFunctions::cs_gate_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 15u, SferaFields::integer_175, SferaFields::integer_177, 49u,
        SferaFields::integer_178, SferaFields::reference_180, SferaFields::buffer_181, SferaFields::integer_200, SferaFields::integer_179,
        SferaFields::reference_176, SferaFunctions::cs_gate_FlyWeapon);
}

SferaMbcValue SferaFunctions::cs_gate_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_270_at_5, 0u, 0u, 1u, 0u);
}

SferaMbcValue SferaFunctions::cs_gate_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 76u);
}

SferaMbcValue SferaFunctions::cs_gate_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 81u, 82u, SferaFields::buffer_83, 78u);
}

SferaMbcValue SferaFunctions::cs_gate_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_301, 3u, SferaFields::reference_302, 58u,
        SferaFields::buffer_253, 12u, 4294967293u, SferaFields::buffer_313);
}

SferaMbcValue SferaFunctions::cs_gate_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_694e7ae7_body(std::move(c), args, 115u, SferaFields::integer_314, 116u, 58u, SferaFields::buffer_253, 12u,
        4294967293u, SferaFields::integer_315, 117u, SferaFields::buffer_316, 3u, SferaFunctions::bank_openSlot);
}

SferaMbcValue SferaFunctions::cs_gate_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 4u, SferaFields::integer_303, 3u, SferaFields::integer_304,
        SferaFields::buffer_253, 12u, 4294967293u, SferaFields::integer_305);
}

SferaMbcValue SferaFunctions::cs_gate_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 17u, SferaFields::integer_306, 3u, SferaFields::integer_307,
        SferaFields::buffer_253, 12u, 4294967293u);
}

SferaMbcValue SferaFunctions::cs_gate_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 56u, SferaFields::integer_189, SferaFields::integer_308, 3u, 57u,
        SferaFields::buffer_253, 12u, 4294967293u);
}

SferaMbcValue SferaFunctions::cs_gate_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_4816c116_body(std::move(c), args, 118u, SferaFields::integer_189, 119u, 120u, SferaFields::buffer_317,
        121u, 123u, SferaFields::integer_317_at_8, 3u, 122u, SferaFields::buffer_253, 12u, 4294967293u, SferaFields::buffer_318,
        SferaFields::buffer_319, 124u, 125u, 126u, 127u, SferaFields::buffer_320, 128u, SferaFields::buffer_321, SferaFields::buffer_323,
        SferaFields::buffer_321_at_12, SferaFields::buffer_324, SferaFields::buffer_322, SferaFields::buffer_325, SferaFields::buffer_326,
        SferaFields::buffer_327, SferaFields::buffer_328, 129u, SferaFunctions::cs_gate_TestIt);
}

SferaMbcValue SferaFunctions::cs_gate_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_329, 3u, SferaFields::buffer_253, 12u, 4294967293u,
        SferaFields::buffer_313);
}

SferaMbcValue SferaFunctions::cs_gate_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 58u, SferaFields::integer_330, 3u, SferaFields::buffer_253, 12u,
        4294967293u, SferaFields::buffer_313, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::cs_gate_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 3u);
}

SferaMbcValue SferaFunctions::cs_gate_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_332_at_11, 3u, SferaFields::buffer_253, 12u, 4294967293u);
}

SferaMbcValue SferaFunctions::cs_gate_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_309, 3u, SferaFields::buffer_254, 12u, 4294967293u);
}

SferaMbcValue SferaFunctions::cs_gate_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_310, SferaFields::integer_311, 3u, SferaFields::buffer_253, 12u,
        4294967293u);
}

SferaMbcValue SferaFunctions::cs_gate_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_312, 3u, SferaFields::buffer_253, 12u, 4294967293u);
}

SferaMbcValue SferaFunctions::cs_gate_StartClanEff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_StartClanEff_body(std::move(c), args, 86u, SferaFields::reference_273, 83u, SferaFields::buffer_271, 106u);
}

SferaMbcValue SferaFunctions::cs_gate_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_b2ae2bad_body(std::move(c), args, SferaFields::integer_361_at_5, SferaFields::buffer_362, 11u);
}

SferaMbcValue SferaFunctions::cs_gate_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_30c23da7_body(std::move(c), args, SferaFields::reference_365, SferaFields::buffer_366,
        SferaFields::buffer_274, SferaFields::buffer_367, SferaFields::buffer_368, SferaFields::buffer_340);
}

SferaMbcValue SferaFunctions::ct_mbook_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_265, SferaFields::integer_184, 56u,
        SferaFields::integer_82, 8u, SferaFields::buffer_229, 32u, 4294967288u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::bank_sendslot);
}

SferaNativeTask SferaFunctions::ct_mbook_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_beb84fb0_body(std::move(c), std::move(args), SferaFields::integer_266, SferaFields::reference_285,
        SferaFields::integer_283, SferaFields::integer_284, SferaFields::buffer_286, SferaFields::buffer_287, 8u, SferaFields::buffer_229,
        32u, 4294967288u, SferaFields::buffer_214, 56u, SferaFunctions::bank_sendslot);
}

SferaMbcValue SferaFunctions::ct_mbook_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 73u, 74u, SferaFields::reference_0, SferaFields::integer_200,
        SferaFields::buffer_276, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_277, SferaFields::buffer_278,
        SferaFields::buffer_279, 60u, 17u, SferaFields::buffer_280, SferaFields::buffer_272, SferaFields::buffer_273,
        SferaFields::integer_274, SferaFields::integer_275, SferaFields::reference_267, SferaFields::buffer_281,
        SferaFields::reference_233, SferaFields::buffer_282, SferaFields::reference_268, SferaFields::buffer_264,
        SferaFields::reference_269, SferaFields::buffer_246, SferaFields::reference_270, SferaFields::reference_271,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_54,
        SferaFields::integer_250, SferaFields::real_62, 3000u, SferaFields::buffer_254, SferaFields::buffer_255, 88u, 3u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_mbook_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 61u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_229, 32u, 4294967288u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 8u, SferaFunctions::ct_chest1_openSlot, SferaFunctions::ct_mbook_CheckWght);
}

SferaMbcValue SferaFunctions::ct_mbook_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 4u, SferaFields::integer_230, 62u, 78u, SferaFields::buffer_288, 79u,
        81u, SferaFields::integer_288_at_8, 8u, 80u, SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_289,
        SferaFields::buffer_290, 82u, 83u, 84u, 85u, SferaFields::buffer_291, 86u, SferaFields::buffer_292, SferaFields::buffer_294,
        SferaFields::buffer_292_at_12, SferaFields::buffer_295, SferaFields::buffer_293, SferaFields::buffer_298, SferaFields::buffer_300,
        SferaFields::buffer_301, SferaFields::buffer_302, 87u, SferaFields::buffer_182, SferaFunctions::ct_mbook_TestIt);
}

SferaMbcValue SferaFunctions::ct_mbook_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 3000u);
}

SferaMbcValue SferaFunctions::ct_mbook_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_90_at_10, 56u, SferaFields::integer_80, 8u,
        SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_mapbook_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_body(std::move(c), args, 64u, SferaFields::reference_241, SferaFields::buffer_185, 3u,
        SferaFields::integer_250);
}

SferaMbcValue SferaFunctions::ct_mapbook_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 4u, 70u, SferaFields::reference_265, SferaFields::integer_200,
        SferaFields::buffer_269, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_280, SferaFields::buffer_281,
        SferaFields::buffer_282, 90u, 89u, SferaFields::buffer_283, SferaFields::buffer_263, SferaFields::buffer_264,
        SferaFields::integer_267, SferaFields::integer_268, SferaFields::reference_195, SferaFields::buffer_284,
        SferaFields::reference_194, SferaFields::buffer_285, SferaFields::reference_259, SferaFields::buffer_286,
        SferaFields::reference_260, SferaFields::buffer_287, SferaFields::reference_261, SferaFields::reference_262,
        SferaFields::buffer_288, SferaFields::buffer_289, SferaFields::buffer_290, SferaFields::buffer_291, SferaFields::real_266,
        SferaFields::integer_250, SferaFields::real_90, 1000u, SferaFields::buffer_292, SferaFields::buffer_293, 73u, 88u,
        SferaFields::buffer_294, SferaFields::buffer_295, SferaFields::buffer_300, SferaFields::buffer_298, SferaFields::buffer_301,
        SferaFields::buffer_302, SferaFields::buffer_303);
}

SferaMbcValue SferaFunctions::ct_mapbook_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 5u, SferaFields::buffer_0, SferaFields::buffer_62, SferaFields::buffer_80, 10u, 6u);
}

SferaMbcValue SferaFunctions::ct_mapbook_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 56u, SferaFields::integer_219, 57u, 3u, SferaFields::buffer_202, 80u, 4294967276u,
        SferaFields::integer_220, 58u, SferaFields::buffer_221, 20u, SferaFunctions::bank_openSlot, SferaFunctions::ct_mapbook_CheckWght);
}

SferaMbcValue SferaFunctions::ct_mapbook_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 63u, SferaFields::integer_215, 65u, 66u, SferaFields::buffer_228, 67u,
        69u, SferaFields::integer_228_at_8, 20u, 68u, SferaFields::buffer_202, 80u, 4294967276u, SferaFields::buffer_229,
        SferaFields::buffer_230, 79u, 80u, 81u, 82u, SferaFields::buffer_231, 83u, SferaFields::buffer_232, SferaFields::buffer_234,
        SferaFields::buffer_232_at_12, SferaFields::buffer_235, SferaFields::buffer_233, SferaFields::buffer_236, SferaFields::buffer_270,
        SferaFields::buffer_271, SferaFields::buffer_272, 84u, SferaFields::buffer_182, SferaFunctions::ct_mapbook_TestIt);
}

SferaMbcValue SferaFunctions::ct_mapbook_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 1000u);
}

SferaMbcValue SferaFunctions::mg_workshop_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 68u, 69u, SferaFields::reference_263, SferaFields::integer_200,
        SferaFields::buffer_276, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_277, SferaFields::buffer_278,
        SferaFields::buffer_279, 73u, 72u, SferaFields::buffer_280, SferaFields::buffer_272, SferaFields::buffer_273,
        SferaFields::integer_274, SferaFields::integer_275, SferaFields::reference_267, SferaFields::buffer_281,
        SferaFields::reference_266, SferaFields::buffer_282, SferaFields::reference_268, SferaFields::buffer_283,
        SferaFields::reference_269, SferaFields::buffer_284, SferaFields::reference_270, SferaFields::reference_271,
        SferaFields::buffer_285, SferaFields::buffer_240, SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::real_264,
        SferaFields::integer_250, SferaFields::real_265, 100000u, SferaFields::buffer_252, SferaFields::buffer_253, 70u, 71u,
        SferaFields::buffer_254, SferaFields::buffer_255, SferaFields::buffer_257, SferaFields::buffer_256, SferaFields::buffer_259,
        SferaFields::buffer_260, SferaFields::buffer_261);
}

SferaMbcValue SferaFunctions::mg_workshop_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_202, 62u, 61u, SferaFields::buffer_229, 16u, 4294967292u,
        SferaFields::integer_232, 63u, SferaFields::buffer_234, 4u, SferaFunctions::ct_sbag_openSlot,
        SferaFunctions::mg_workshop_CheckWght);
}

SferaMbcValue SferaFunctions::mg_workshop_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_262, 100000u);
}

SferaMbcValue SferaFunctions::mg_workshop_setFlagCloseWindowWorkshop(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_stopWinGroupExist_body(std::move(c), args, 118u);
}

SferaMbcValue SferaFunctions::mg_workshop_setFlagFreeSlotsInWorkshop(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_mg_workshop_resetFlagAcceptCraft_body(std::move(c), args, 1u);
}

SferaMbcValue SferaFunctions::mg_workshop_resetFlagAcceptCraft(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_mg_workshop_resetFlagAcceptCraft_body(std::move(c), args, 3u);
}

SferaNativeTask SferaFunctions::wp_sword1_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_606b6da7_body(std::move(c), std::move(args), SferaFunctions::wp_sword1_UseOff);
}

SferaMbcValue SferaFunctions::wp_sword1_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_869d600d_body(std::move(c), args, SferaFunctions::wp_sword1_UseOff);
}

SferaMbcValue SferaFunctions::wp_sword1_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_51d953eb_body(std::move(c), args, SferaFunctions::wp_sword1_UseOwner, SferaFunctions::wp_sword1_UseWith);
}

SferaMbcValue SferaFunctions::wp_sword1_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_fef98b01_body(std::move(c), args, SferaFunctions::wp_sword1_PullOut);
}

SferaNativeTask SferaFunctions::wp_sword1_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_aaa013db_body(std::move(c), std::move(args), SferaFunctions::wp_sword1_Use,
        SferaFunctions::wp_sword1_UseOff);
}

SferaMbcValue SferaFunctions::wp_sword1_PullOut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PullOut_a9e0a32b_body(std::move(c), args, SferaFields::buffer_306, 8u);
}

SferaMbcValue SferaFunctions::wp_sword1_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_9066b1cf_body(std::move(c), args, 9u, 10u);
}

SferaMbcValue SferaFunctions::wp_sword1_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOff_1f1a0acb_body(std::move(c), args, SferaFields::buffer_309, SferaFields::buffer_310, SferaFields::buffer_311,
        12u);
}

SferaMbcValue SferaFunctions::crystal_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 69u);
}

SferaMbcValue SferaFunctions::crystal_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_716186f6_body(std::move(c), args, 41u, SferaFields::buffer_0, 11u, SferaFields::integer_35,
        SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::crystal_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_0_at_11, SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::crystal_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_272403a7_body(std::move(c), args, SferaFunctions::crystal_UseOwner);
}

SferaNativeTask SferaFunctions::crystal_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_8ed35db2_body(std::move(c), std::move(args), SferaFunctions::crystal_Use);
}

SferaMbcValue SferaFunctions::crystal_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_6ce5a504_body(std::move(c), args, SferaFields::integer_273, SferaFields::reference_274,
        SferaFields::integer_192);
}

SferaMbcValue SferaFunctions::crystal_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_0537a213_body(std::move(c), args, SferaFields::integer_46_at_8, 76u, 5u, SferaFields::buffer_275);
}

SferaMbcValue SferaFunctions::inventory_SetddHan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_138_at_10, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::inventory_InvTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvTrig_body(std::move(c), args, SferaFields::integer_89_at_12, SferaFunctions::inventory_InvOn,
        SferaFunctions::inventory_InvOff);
}

SferaMbcValue SferaFunctions::inventory_InvOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOn_body(std::move(c), args, SferaFields::integer_89_at_12, 9u, 6u);
}

SferaMbcValue SferaFunctions::inventory_InvOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 9u);
}

SferaMbcValue SferaFunctions::inventory_DigSeparate(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_DigSeparate_body(std::move(c), args, SferaFields::reference_139, SferaFields::reference_140, 0u,
        SferaFields::buffer_141, SferaFields::integer_142, SferaFields::integer_143, SferaFields::integer_144);
}

SferaMbcValue SferaFunctions::inventory_DigSeparateInt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_DigSeparateInt_body(std::move(c), args, SferaFunctions::inventory_DigSeparate);
}

SferaMbcValue SferaFunctions::st_shamp_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_ec1497dc_body(std::move(c), args, 61u, SferaFields::integer_38, SferaFields::integer_203,
        SferaFields::integer_39, 58u, SferaFields::integer_40, SferaFields::reference_43, SferaFields::buffer_44, SferaFields::integer_45,
        SferaFields::integer_184, 52u, 53u, 54u);
}

SferaMbcValue SferaFunctions::st_shamp_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_a7cd8f11_body(std::move(c), args, SferaFunctions::st_shamp_CheckPut);
}

SferaMbcValue SferaFunctions::st_shamp_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckPut_2915b058_body(std::move(c), args, 98u);
}

SferaMbcValue SferaFunctions::st_shamp_CheckFree(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 98u);
}

SferaMbcValue SferaFunctions::st_shamp_FillPict(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FillPict_body(std::move(c), args, SferaFields::reference_46, SferaFields::buffer_285, 5u);
}

SferaMbcValue SferaFunctions::pw_ability_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 74u);
}

SferaMbcValue SferaFunctions::pw_ability_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::pw_ability_InitObj);
}

SferaMbcValue SferaFunctions::pw_ability_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 5u, SferaFields::buffer_49, 11u);
}

SferaMbcValue SferaFunctions::pw_ability_dnts(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_49_at_11, SferaFields::integer_48);
}

SferaMbcValue SferaFunctions::pw_ability_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_290d4145_body(std::move(c), args, SferaFunctions::bank_AddInfo);
}

SferaMbcValue SferaFunctions::telep2_GetTP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetTP_94aedd18_body(std::move(c), args, 1060320051u, 1061997773u);
}

SferaMbcValue SferaFunctions::telep2_empty(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_empty_body(std::move(c), args, SferaFields::integer_1_at_5);
}

SferaMbcValue SferaFunctions::telep2_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 9u, 65u);
}

SferaNativeTask SferaFunctions::telep2_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_bd245d6a_body(std::move(c), std::move(args), SferaFields::integer_197, SferaFields::reference_200,
        SferaFields::integer_198, SferaFields::integer_199, SferaFields::buffer_201, SferaFields::buffer_202, 51u,
        SferaFunctions::telep1_Use);
}

SferaNativeTask SferaFunctions::pw_amilus_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_5b3982b3_body(std::move(c), std::move(args), 35u, SferaFields::integer_40, SferaFields::reference_81,
        SferaFields::integer_53, SferaFields::integer_62, SferaFields::integer_39, SferaFields::buffer_82, SferaFields::buffer_90, 60u);
}

SferaMbcValue SferaFunctions::pw_amilus_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 35u, SferaFields::integer_167, SferaFields::integer_191,
        SferaFields::integer_185, 60u, SferaFields::integer_194, SferaFields::reference_195, SferaFields::buffer_196,
        SferaFields::integer_198, SferaFields::integer_192, 46u, 47u);
}

SferaNativeTask SferaFunctions::mg_eye_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_4ec3337b_body(std::move(c), std::move(args), SferaFunctions::mg_eye_UseOff);
}

SferaMbcValue SferaFunctions::mg_eye_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_c61b2854_body(std::move(c), args, SferaFunctions::mg_eye_UseOff);
}

SferaMbcValue SferaFunctions::mg_eye_PullOut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 94u);
}

SferaMbcValue SferaFunctions::mg_eye_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 94u);
}

SferaMbcValue SferaFunctions::scroll_october_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_042b69ba_body(std::move(c), args, SferaFields::reference_246, SferaFields::buffer_253,
        SferaFields::buffer_254, 62u, 90u, SferaFields::buffer_255, SferaFields::buffer_256);
}

SferaMbcValue SferaFunctions::scroll_october_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_6a9e1c1e_body(std::move(c), args, SferaFields::integer_256_at_11, SferaFields::buffer_257,
        SferaFields::buffer_258, SferaFields::buffer_259, SferaFields::buffer_260, 44u);
}

SferaMbcValue SferaFunctions::fwks_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_05e952b4_body(std::move(c), args, SferaFunctions::bank_AddInfo);
}

SferaMbcValue SferaFunctions::fwks_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 17u, SferaFields::buffer_54, SferaFields::buffer_80, SferaFields::buffer_193, 6u,
        6u);
}

SferaMbcValue SferaFunctions::fwks_Main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_Camera_stop_body(std::move(c), args, SferaFields::integer_241, 20u);
}

SferaNativeTask SferaFunctions::vn_tokensin_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_71b7a3a5_body(std::move(c), std::move(args), SferaFunctions::vn_tokensin_UseClient);
}

SferaMbcValue SferaFunctions::vn_tokensin_UseClient(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseClient_01e86a2a_body(std::move(c), args, SferaFields::reference_270, SferaFields::integer_269_at_14,
        SferaFields::buffer_271);
}

SferaMbcValue SferaFunctions::tutomsg_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_6ce5a504_body(std::move(c), args, SferaFields::integer_205_at_12, SferaFields::reference_206,
        SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::tutomsg_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_body(std::move(c), args, SferaFields::buffer_207, 7u, SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::vir1000_CallLink(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_empty_body(std::move(c), args, SferaFields::integer_7_at_12);
}

SferaMbcValue SferaFunctions::vir1000_CallPict(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ar_ring_SndUser_body(std::move(c), args, SferaFields::reference_0);
}

SferaNativeTask SferaFunctions::specab_na_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_ec757611_body(std::move(c), std::move(args), SferaFields::integer_215, SferaFields::reference_218,
        SferaFields::integer_216, SferaFields::integer_217, SferaFields::buffer_219, SferaFields::buffer_324, 58u);
}

SferaMbcValue SferaFunctions::seed_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_4e68596a_body(std::move(c), args, SferaFields::integer_256_at_5, SferaFields::buffer_257);
}

SferaMbcValue SferaFunctions::door2_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_body(std::move(c), args, SferaFields::buffer_182, 6u, SferaFields::integer_4);
}

SferaMbcValue SferaFunctions::ar_shoes2_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_879a99f1_body(std::move(c), args, SferaFields::buffer_193, 6u);
}

SferaNativeTask SferaFunctions::vir1028_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 10u);
}

SferaNativeTask SferaFunctions::vir1010_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 1u);
}

SferaMbcValue SferaFunctions::player_webshop_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 8u);
}

SferaMbcValue SferaFunctions::vir1046_CallLink(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CallLink_body(std::move(c), args, 4u, 1u);
}
