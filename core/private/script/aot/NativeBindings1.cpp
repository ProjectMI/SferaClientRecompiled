#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::player_cleanse_buffs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_cleanse_buffs_body(std::move(c), args, SferaFields::integer_315_at_42, SferaFields::reference_316,
        SferaFields::integer_317, SferaFields::buffer_318, SferaFields::buffer_319, SferaFields::buffer_320, 23u, SferaFields::buffer_321,
        21u, SferaFields::buffer_322, SferaFields::buffer_323);
}

SferaMbcValue SferaFunctions::player_cleanse_viruses(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_cleanse_buffs_body(std::move(c), args, SferaFields::integer_323_at_12, SferaFields::reference_324,
        SferaFields::integer_325, SferaFields::buffer_326, SferaFields::buffer_327, SferaFields::buffer_328, 25u, SferaFields::buffer_329,
        22u, SferaFields::buffer_330, SferaFields::buffer_331);
}

SferaMbcValue SferaFunctions::player_GetActionName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GetCastleName_body(std::move(c), args, SferaFields::integer_354_at_20, 18u, SferaFields::buffer_336, 216u,
        4294967278u, SferaFields::buffer_355, 8u);
}

SferaMbcValue SferaFunctions::player_getMoney(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_209, 232u, 228u);
}

SferaMbcValue SferaFunctions::player_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 28u);
}

SferaMbcValue SferaFunctions::player_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 30u, 255u);
}

SferaMbcValue SferaFunctions::player_Effect(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_Effect_body(std::move(c), args, SferaFields::integer_63);
}

SferaMbcValue SferaFunctions::player_SetHealth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetHealth_body(std::move(c), args, SferaFields::buffer_209, 232u);
}

SferaMbcValue SferaFunctions::player_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_body(std::move(c), args, 39u, SferaFields::reference_298, SferaFields::buffer_60, 1u,
        SferaFields::integer_61);
}

SferaMbcValue SferaFunctions::player_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_60_at_1, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::player_SetParent(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_SetParent_body(std::move(c), args, SferaFields::integer_374, SferaFields::buffer_176, 60u, 4u, 11u);
}

SferaMbcValue SferaFunctions::player_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_0c1a1db3_body(std::move(c), args, 26u, SferaFields::buffer_209, 232u, SferaFields::reference_377,
        SferaFields::buffer_176, 60u, SferaFields::integer_196, 35u, 36u);
}

SferaMbcValue SferaFunctions::player_Recalc(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Recalc_body(std::move(c), args, SferaFields::buffer_209, 232u, SferaFields::integer_378, 5u, 3u, 0u, 6u, 4u, 1u);
}

SferaMbcValue SferaFunctions::player_use_send_cuse_to_server(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_send_cuse_to_server_body(std::move(c), args, SferaFields::integer_93_at_12, 71u, 72u,
        SferaFields::reference_380, SferaFields::buffer_176, 60u, 73u);
}

SferaMbcValue SferaFunctions::player_UseServer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_62_at_5);
}

SferaNativeTask SferaFunctions::player_ShowKill(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ShowKill_ba13cfba_body(std::move(c), std::move(args), 82u, SferaFields::buffer_397, SferaFields::integer_393, 81u,
        SferaFields::buffer_394, SferaFields::buffer_395, 80u, SferaFields::buffer_209, 232u, SferaFields::buffer_396,
        SferaFields::buffer_398, SferaFields::buffer_400, SferaFields::buffer_399, SferaFields::buffer_185, 20u, SferaFields::buffer_401,
        SferaFields::buffer_402, SferaFields::buffer_403, SferaFields::buffer_404, SferaFields::buffer_405, SferaFields::buffer_406, 15u,
        79u, 14u);
}

SferaMbcValue SferaFunctions::player_NotEmptyCont(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_NotEmptyCont_body(std::move(c), args, SferaFields::integer_420_at_18, SferaFields::buffer_421, 84u,
        SferaFields::buffer_422, 85u);
}

SferaMbcValue SferaFunctions::player_SendOffer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SendOffer_body(std::move(c), args, SferaFields::integer_422_at_12, 86u, SferaFields::reference_423,
        SferaFields::buffer_176, 60u);
}

SferaMbcValue SferaFunctions::player_getItemName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_getItemName_body(std::move(c), args, SferaFields::reference_170_at_12);
}

SferaMbcValue SferaFunctions::player_GetPlName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetModel_body(std::move(c), args, SferaFields::integer_88, SferaFields::reference_89, SferaFields::buffer_185, 20u);
}

SferaMbcValue SferaFunctions::player_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_451, 0u, 0u, 1u, 1u);
}

SferaMbcValue SferaFunctions::player_VirEffect(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_Effect_body(std::move(c), args, SferaFields::integer_53_at_7);
}

SferaMbcValue SferaFunctions::player_Params(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Params_body(std::move(c), args, SferaFields::reference_452, SferaFields::buffer_209, 232u);
}

SferaMbcValue SferaFunctions::player_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_477_at_4, 91u, 92u, 99u);
}

SferaMbcValue SferaFunctions::player_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 113u, 114u, SferaFields::buffer_478, 101u);
}

SferaNativeTask SferaFunctions::player_CheckSpec(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckSpec_body(std::move(c), std::move(args), SferaFields::reference_480, SferaFields::buffer_209, 232u, 115u,
        117u, 119u, 121u, 116u, SferaFields::buffer_481, 118u, 120u, 122u);
}

SferaMbcValue SferaFunctions::player_getCreatureLevel(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_getCreatureLevel_body(std::move(c), args, SferaFields::buffer_209, 232u);
}

SferaMbcValue SferaFunctions::player_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 127u, SferaFields::integer_486, 60u, SferaFields::integer_487,
        SferaFields::buffer_228, 240u, 4294967236u, SferaFields::integer_488);
}

SferaMbcValue SferaFunctions::player_SeekTagInsideNoRecursive(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 128u, SferaFields::integer_489, 60u, SferaFields::integer_490,
        SferaFields::buffer_228, 240u, 4294967236u);
}

SferaMbcValue SferaFunctions::player_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 129u, SferaFields::integer_241, SferaFields::integer_491, 60u, 130u,
        SferaFields::buffer_228, 240u, 4294967236u);
}

SferaMbcValue SferaFunctions::player_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckRights_body(std::move(c), args, SferaFields::integer_202_at_8);
}

SferaMbcValue SferaFunctions::player_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_504, 60u, SferaFields::buffer_228, 240u,
        4294967236u, SferaFields::buffer_229);
}

SferaMbcValue SferaFunctions::player_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 46u, SferaFields::integer_505, 60u, SferaFields::buffer_228, 240u,
        4294967236u, SferaFields::buffer_229, SferaFields::buffer_176, 60u);
}

SferaMbcValue SferaFunctions::player_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 60u);
}

SferaMbcValue SferaFunctions::player_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_509, 60u, SferaFields::buffer_230, 240u, 4294967236u);
}

SferaMbcValue SferaFunctions::player_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_510, SferaFields::integer_511, 60u, SferaFields::buffer_228,
        240u, 4294967236u);
}

SferaMbcValue SferaFunctions::player_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_512, 60u, SferaFields::buffer_228, 240u, 4294967236u);
}

SferaMbcValue SferaFunctions::player_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_116adf93_body(std::move(c), args, SferaFields::integer_513, SferaFields::reference_514,
        SferaFields::reference_515, 0u, SferaFields::reference_516, SferaFields::buffer_519, 131u, SferaFields::buffer_520, 2u,
        SferaFields::reference_518, SferaFields::reference_517);
}

SferaMbcValue SferaFunctions::player_StartClanEff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_StartClanEff_body(std::move(c), args, 148u, SferaFields::reference_523, 145u, SferaFields::buffer_521, 128u);
}

SferaMbcValue SferaFunctions::player_SendSys2(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_SendSys2_body(std::move(c), args, 151u, 152u, 153u, SferaFields::reference_530, 2u);
}

SferaMbcValue SferaFunctions::player_SendSys3(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_SendSys2_body(std::move(c), args, 154u, 155u, 156u, SferaFields::reference_531, 3u);
}

SferaMbcValue SferaFunctions::player_LostItem(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_SetParent_body(std::move(c), args, SferaFields::integer_678_at_45, SferaFields::buffer_176, 60u, 12u, 19u);
}

SferaMbcValue SferaFunctions::player_PrgMove_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_char_Animating_stop_body(std::move(c), args, SferaFields::integer_692, SferaFields::integer_183);
}

SferaMbcValue SferaFunctions::player_GetPlayerName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GetMainServerURL_body(std::move(c), args, SferaFields::reference_701, SferaFields::buffer_185, 20u);
}

SferaMbcValue SferaFunctions::player_Model(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_froom_body(std::move(c), args, SferaFields::integer_712_at_7, SferaFields::integer_203);
}

SferaMbcValue SferaFunctions::player_Getxyz(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_Getabg_body(std::move(c), args, SferaFields::reference_713, 0u);
}

SferaMbcValue SferaFunctions::player_Getabg(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_Getabg_body(std::move(c), args, SferaFields::reference_714, 12u);
}

SferaMbcValue SferaFunctions::player_WinLink_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_WinLink_stop_body(std::move(c), args, SferaFields::integer_78, 2u);
}

SferaMbcValue SferaFunctions::player_joinSomeone2Group(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_deleteSomeoneFromGroup_body(std::move(c), args, SferaFields::reference_773_at_18, 2u);
}

SferaMbcValue SferaFunctions::player_deleteSomeoneFromGroup(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_deleteSomeoneFromGroup_body(std::move(c), args, SferaFields::reference_774, 3u);
}

SferaMbcValue SferaFunctions::player_deleteMeFroupGroup(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_deleteMeFroupGroup_body(std::move(c), args, 7u);
}

SferaMbcValue SferaFunctions::player_groupDelete(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_deleteMeFroupGroup_body(std::move(c), args, 4u);
}

SferaMbcValue SferaFunctions::player_IsExtra(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetKomiss_body(std::move(c), args, SferaFields::byte_158);
}

SferaMbcValue SferaFunctions::player_IsClearExtra(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetKomiss_body(std::move(c), args, SferaFields::byte_159);
}

SferaMbcValue SferaFunctions::player_SendSwordEff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_TABLE_body(std::move(c), args, SferaFields::integer_1197, SferaFields::buffer_176, 60u, 14u, 1u);
}

SferaMbcValue SferaFunctions::player_GetClanSymbInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetKomiss_body(std::move(c), args, SferaFields::byte_154);
}

SferaMbcValue SferaFunctions::player_AskLnk(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_runRefreshWinGroupList_body(std::move(c), args, SferaFields::integer_1311, SferaFields::integer_756, 191u);
}

SferaMbcValue SferaFunctions::player_SetProperty(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_UseWith_body(std::move(c), args, SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::player_ActivityCtrlWnd_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_1321, SferaFields::integer_1321);
}

SferaMbcValue SferaFunctions::player_GetSids(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GetXYZ_body(std::move(c), args, SferaFields::integer_1326_at_11, SferaFields::reference_1327,
        SferaFields::buffer_194, 8u, 8u);
}

SferaMbcValue SferaFunctions::player_setFistPowerups(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_1377, SferaFields::integer_82);
}

SferaMbcValue SferaFunctions::player_getPassportShard(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_171);
}

SferaMbcValue SferaFunctions::player_setArtisanID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_setArtisanID_body(std::move(c), args, SferaFields::integer_1385_at_9, SferaFields::integer_186, 0u);
}

SferaMbcValue SferaFunctions::player_setCustomerID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_setArtisanID_body(std::move(c), args, SferaFields::integer_1386, SferaFields::integer_188, 2u);
}

SferaMbcValue SferaFunctions::player_setPriceArtisan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_callCloseCustomerWorkshop_body(std::move(c), args, 320u, 1u);
}

SferaMbcValue SferaFunctions::player_resetCustomerData(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_resetArtisanData_body(std::move(c), args, 7u);
}

SferaMbcValue SferaFunctions::player_resetArtisanData(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_resetArtisanData_body(std::move(c), args, 9u);
}

SferaMbcValue SferaFunctions::player_receivePriceArtisan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_187);
}

SferaMbcValue SferaFunctions::player_receiveCustomerID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_188);
}

SferaMbcValue SferaFunctions::player_receiveMyWorkshop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_189);
}

SferaMbcValue SferaFunctions::player_receiveArtisanID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_186);
}

SferaMbcValue SferaFunctions::player_callCloseCustomerWorkshop(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_player_callCloseCustomerWorkshop_body(std::move(c), args, 321u, 8u);
}

SferaMbcValue SferaFunctions::player_callOpenCustomerWorkshop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_callCloseCustomerWorkshop_body(std::move(c), args, 322u, 5u);
}

SferaMbcValue SferaFunctions::player_GetCanUseWebShopAndClaim(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_208);
}

SferaMbcValue SferaFunctions::ct_cbag_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 63u);
}

SferaMbcValue SferaFunctions::ct_cbag_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_97811cb2_body(std::move(c), args, SferaFunctions::ct_cbag_UseOwner);
}

SferaNativeTask SferaFunctions::ct_cbag_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_3738afb9_body(std::move(c), std::move(args), 41u, SferaFields::integer_54, SferaFields::reference_265,
        SferaFields::integer_81, SferaFields::integer_264, SferaFields::buffer_266, SferaFields::buffer_267, 49u, 12u,
        SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_214, 56u, SferaFunctions::ct_cbag_Use,
        SferaFunctions::ct_bag_sendslot);
}

SferaMbcValue SferaFunctions::ct_cbag_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 41u, SferaFields::integer_66, SferaFields::integer_63,
        SferaFields::integer_83, 49u, SferaFields::integer_84, SferaFields::reference_85, SferaFields::buffer_86, SferaFields::integer_64,
        SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::ct_cbag_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_be50c274_body(std::move(c), args, 35u, 67u, SferaFields::reference_197, SferaFields::integer_3,
        SferaFields::buffer_241, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_242, SferaFields::buffer_243,
        SferaFields::buffer_244, 71u, 70u, SferaFields::buffer_245, SferaFields::buffer_237, SferaFields::buffer_238,
        SferaFields::integer_239, SferaFields::integer_240, SferaFields::reference_203, SferaFields::buffer_246,
        SferaFields::reference_202, SferaFields::buffer_247, SferaFields::reference_213, SferaFields::buffer_248,
        SferaFields::reference_234, SferaFields::buffer_249, SferaFields::reference_235, SferaFields::reference_236,
        SferaFields::buffer_250, SferaFields::buffer_251, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::buffer_254,
        SferaFields::buffer_254_at_18, SferaFields::integer_186, SferaFields::real_199, SferaFields::integer_61, SferaFields::real_201,
        100000u, SferaFields::buffer_255, SferaFields::buffer_256, 68u, 69u, SferaFields::buffer_257, SferaFields::buffer_258,
        SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261, SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_cbag_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 48u, SferaFields::buffer_193, SferaFields::buffer_194, SferaFields::buffer_195, 8u,
        6u);
}

SferaMbcValue SferaFunctions::ct_cbag_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_99840dcc_body(std::move(c), args, 46u, SferaFields::integer_217, 47u, 49u, SferaFields::buffer_187, 50u,
        52u, SferaFields::integer_187_at_8, 12u, 51u, SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_188,
        SferaFields::buffer_191, 60u, 61u, 62u, SferaFields::buffer_192, SferaFields::buffer_196, SferaFields::buffer_200,
        SferaFields::buffer_196_at_12, SferaFields::buffer_204, SferaFields::buffer_198, SferaFields::buffer_205, SferaFields::buffer_206,
        SferaFields::buffer_231, SferaFields::buffer_232, SferaFields::buffer_182);
}

SferaMbcValue SferaFunctions::ct_cbag_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_268, 12u, SferaFields::buffer_218, 48u, 4294967284u,
        SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_cbag_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 56u, SferaFields::integer_269, 12u, SferaFields::buffer_218, 48u,
        4294967284u, SferaFields::buffer_214, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::ct_cbag_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 72u, 56u, SferaFields::integer_270, 12u, SferaFields::buffer_218, 48u,
        4294967284u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_cbag_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_12088b0e_body(std::move(c), args, 4u, SferaFields::buffer_80, 40u, SferaFunctions::bank_isGxpItem);
}

SferaMbcValue SferaFunctions::ct_chest3_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 9u, 63u);
}

SferaNativeTask SferaFunctions::ct_chest3_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_3738afb9_body(std::move(c), std::move(args), 41u, SferaFields::integer_0, SferaFields::reference_203,
        SferaFields::integer_62, SferaFields::integer_197, SferaFields::buffer_269, SferaFields::buffer_270, 49u, 8u,
        SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_214, 56u, SferaFunctions::ct_cbag_Use,
        SferaFunctions::bank_sendslot);
}

SferaMbcValue SferaFunctions::ct_chest3_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 48u, 67u, SferaFields::reference_194, SferaFields::integer_3,
        SferaFields::buffer_233, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_244, SferaFields::buffer_245,
        SferaFields::buffer_246, 74u, 71u, SferaFields::buffer_247, SferaFields::buffer_240, SferaFields::buffer_241,
        SferaFields::integer_242, SferaFields::integer_243, SferaFields::reference_236, SferaFields::buffer_248,
        SferaFields::reference_235, SferaFields::buffer_249, SferaFields::reference_237, SferaFields::buffer_250,
        SferaFields::reference_238, SferaFields::buffer_251, SferaFields::reference_239, SferaFields::reference_193,
        SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::buffer_254, SferaFields::buffer_255, SferaFields::real_195,
        SferaFields::integer_61, SferaFields::real_234, 300000u, SferaFields::buffer_256, SferaFields::buffer_257, 68u, 69u,
        SferaFields::buffer_258, SferaFields::buffer_259, SferaFields::buffer_261, SferaFields::buffer_260, SferaFields::buffer_262,
        SferaFields::buffer_263, SferaFields::buffer_264);
}

SferaMbcValue SferaFunctions::ct_chest3_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_99840dcc_body(std::move(c), args, 46u, SferaFields::integer_230, 47u, 49u, SferaFields::buffer_187, 50u,
        52u, SferaFields::integer_187_at_8, 8u, 51u, SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_188,
        SferaFields::buffer_191, 60u, 61u, 62u, SferaFields::buffer_192, SferaFields::buffer_196, SferaFields::buffer_200,
        SferaFields::buffer_196_at_12, SferaFields::buffer_204, SferaFields::buffer_198, SferaFields::buffer_205, SferaFields::buffer_206,
        SferaFields::buffer_231, SferaFields::buffer_232, SferaFields::buffer_265);
}

SferaMbcValue SferaFunctions::ct_chest3_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_17921366_body(std::move(c), args, SferaFields::integer_265_at_8, 300000u);
}

SferaMbcValue SferaFunctions::ct_chest3_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_266, 8u, SferaFields::buffer_229, 32u, 4294967288u,
        SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_chest3_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 56u, SferaFields::integer_267, 8u, SferaFields::buffer_229, 32u,
        4294967288u, SferaFields::buffer_214, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::ct_chest3_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 75u, 56u, SferaFields::integer_268, 8u, SferaFields::buffer_229, 32u,
        4294967288u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::mg_magicstove_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 44u, 46u, SferaFields::reference_193, SferaFields::integer_3,
        SferaFields::buffer_233, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_234, SferaFields::buffer_235,
        SferaFields::buffer_236, 50u, 49u, SferaFields::buffer_237, SferaFields::buffer_205, SferaFields::buffer_206,
        SferaFields::integer_213, SferaFields::integer_232, SferaFields::reference_197, SferaFields::buffer_238,
        SferaFields::reference_196, SferaFields::buffer_239, SferaFields::reference_198, SferaFields::buffer_240,
        SferaFields::reference_200, SferaFields::buffer_241, SferaFields::reference_202, SferaFields::reference_204,
        SferaFields::buffer_242, SferaFields::buffer_243, SferaFields::buffer_244, SferaFields::buffer_245, SferaFields::real_194,
        SferaFields::integer_61, SferaFields::real_195, 1500u, SferaFields::buffer_246, SferaFields::buffer_247, 47u, 48u,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_251, SferaFields::buffer_250, SferaFields::buffer_252,
        SferaFields::buffer_253, SferaFields::buffer_254);
}

SferaMbcValue SferaFunctions::mg_magicstove_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_d8a2dcca_body(std::move(c), args, 51u, SferaFields::integer_255, 52u, 61u, SferaFields::buffer_229, 16u,
        4294967292u, SferaFields::integer_256, 62u, SferaFields::buffer_257, 4u, SferaFunctions::ct_barn_openSlot,
        SferaFunctions::mg_magicstove_CheckWght);
}

SferaMbcValue SferaFunctions::mg_magicstove_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_29d8322a_body(std::move(c), args, 63u, SferaFields::integer_230, 64u, 65u, SferaFields::buffer_258, 66u,
        68u, SferaFields::integer_258_at_8, 4u, 67u, SferaFields::buffer_229, 16u, 4294967292u, SferaFields::buffer_259,
        SferaFields::buffer_260, 69u, 70u, 71u, 72u, SferaFields::buffer_261, 73u, SferaFields::buffer_262, SferaFields::buffer_264,
        SferaFields::buffer_262_at_12, SferaFields::buffer_265, SferaFields::buffer_263, SferaFields::buffer_266, SferaFields::buffer_267,
        SferaFields::buffer_268, SferaFields::buffer_269, 74u, SferaFields::buffer_270, SferaFunctions::mg_magicstove_TestIt);
}

SferaMbcValue SferaFunctions::mg_magicstove_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_17921366_body(std::move(c), args, SferaFields::integer_270_at_8, 1500u);
}

SferaMbcValue SferaFunctions::mg_magicstove_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_d698e4fa_body(std::move(c), args, SferaFields::integer_212_at_15, SferaFields::buffer_271, 12u,
        SferaFields::buffer_272, SferaFields::buffer_90, 39u);
}

SferaMbcValue SferaFunctions::npc_guide_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 91u, 65u);
}

SferaMbcValue SferaFunctions::npc_guide_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 48u, SferaFields::integer_255, SferaFields::integer_269, 51u,
        SferaFields::integer_270, SferaFields::reference_272, SferaFields::buffer_273, SferaFields::integer_200, SferaFields::integer_271,
        SferaFields::reference_268, SferaFunctions::npc_guide_FlyWeapon);
}

SferaMbcValue SferaFunctions::npc_guide_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_ee7fcfe6_body(std::move(c), args, 53u, SferaFields::buffer_48, SferaFields::buffer_49,
        SferaFields::buffer_50, 3u, SferaFields::buffer_51, SferaFunctions::npc_guide_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_guide_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 78u);
}

SferaMbcValue SferaFunctions::npc_guide_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 45u, 103u, SferaFields::buffer_83, 80u);
}

SferaMbcValue SferaFunctions::npc_guide_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SndUser_4e1c6ed9_body(std::move(c), args, SferaFields::reference_52, SferaFields::integer_4);
}

SferaMbcValue SferaFunctions::npc_guide_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_6ce5a504_body(std::move(c), args, SferaFields::integer_53, SferaFields::reference_202,
        SferaFields::integer_4);
}

SferaMbcValue SferaFunctions::npc_guide_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_body(std::move(c), args, SferaFields::buffer_204, 6u, SferaFields::integer_4);
}

SferaMbcValue SferaFunctions::npc_guide_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_d5e4132b_body(std::move(c), args, SferaFields::integer_205_at_4, SferaFields::buffer_206, 3u);
}

SferaMbcValue SferaFunctions::ai_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_0, 0u, 0u, 0u, 0u);
}

SferaMbcValue SferaFunctions::ai_convertTime2Str(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_convertTime2Str_body(std::move(c), args, SferaFields::integer_6, SferaFields::reference_7, SferaFields::integer_8,
        SferaFields::integer_9, 0u, 1u, 2u, SferaFields::buffer_13, SferaFields::buffer_10, SferaFields::buffer_14, SferaFields::buffer_15,
        SferaFields::buffer_16, SferaFields::buffer_16_at_11, SferaFields::buffer_16_at_12, SferaFields::buffer_17, SferaFields::buffer_11,
        SferaFields::buffer_18, SferaFields::buffer_19, SferaFields::buffer_20, SferaFields::buffer_21, SferaFields::buffer_22,
        SferaFields::buffer_22_at_11, SferaFields::buffer_22_at_12, SferaFields::buffer_23, SferaFields::buffer_12, SferaFields::buffer_24,
        SferaFields::buffer_25, SferaFields::buffer_26, SferaFields::buffer_27, SferaFields::buffer_28, SferaFields::buffer_29,
        SferaFields::buffer_29_at_11, SferaFields::buffer_30);
}

SferaMbcValue SferaFunctions::ai_isFlamount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 0u);
}

SferaMbcValue SferaFunctions::ai_empty(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_empty_body(std::move(c), args, SferaFields::integer_5_at_2);
}

SferaMbcValue SferaFunctions::ai_halt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_halt_body(std::move(c), args, 5u, 6u);
}

SferaMbcValue SferaFunctions::ai_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 8u);
}

SferaMbcValue SferaFunctions::ai_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 10u, 11u);
}

SferaMbcValue SferaFunctions::st_map_GetScale(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_0, 40u, 0u);
}

SferaMbcValue SferaFunctions::st_map_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 10u, 72u);
}

SferaNativeTask SferaFunctions::st_map_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_4ec3337b_body(std::move(c), std::move(args), SferaFunctions::st_map_UseOff);
}

SferaMbcValue SferaFunctions::st_map_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_c61b2854_body(std::move(c), args, SferaFunctions::st_map_UseOff);
}

SferaMbcValue SferaFunctions::st_map_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_st_map_LoadGame_body(std::move(c), args, 14u, SferaFields::buffer_261, SferaFields::buffer_262, SferaFields::buffer_263,
        SferaFields::buffer_264);
}

SferaMbcValue SferaFunctions::st_map_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_st_map_LoadGame_body(std::move(c), args, 13u, SferaFields::buffer_265, SferaFields::buffer_266, SferaFields::buffer_267,
        SferaFields::buffer_268);
}

SferaMbcValue SferaFunctions::st_map_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 104u);
}

SferaMbcValue SferaFunctions::npc_virt_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 48u, SferaFields::integer_255, SferaFields::integer_269, 51u,
        SferaFields::integer_270, SferaFields::reference_272, SferaFields::buffer_273, SferaFields::integer_200, SferaFields::integer_271,
        SferaFields::reference_268, SferaFunctions::npc_virt_FlyWeapon);
}

SferaNativeTask SferaFunctions::npc_virt_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_00d2b32e_body(std::move(c), std::move(args), 3u, SferaFunctions::npc_virt_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_virt_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 83u);
}

SferaMbcValue SferaFunctions::npc_virt_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 110u, 111u, SferaFields::buffer_83, 85u);
}

SferaMbcValue SferaFunctions::npc_virt_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_d5e4132b_body(std::move(c), args, SferaFields::integer_297_at_7, SferaFields::buffer_298, 9u);
}

SferaMbcValue SferaFunctions::npc_tournament_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 65u);
}

SferaNativeTask SferaFunctions::npc_tournament_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_74399034_body(std::move(c), std::move(args), SferaFunctions::npc_guide_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_tournament_Main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Main_bc3f8381_body(std::move(c), args, SferaFields::buffer_300, 6u);
}

SferaMbcValue SferaFunctions::npc_tournament_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_27247a3d_body(std::move(c), args, SferaFields::buffer_123, SferaFields::buffer_345, 6u);
}

SferaMbcValue SferaFunctions::npc_tournament_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SndUser_220b86e4_body(std::move(c), args, SferaFields::reference_345_at_6);
}

SferaMbcValue SferaFunctions::npc_tournament_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_CloseScroll_body(std::move(c), args, 98u, 104u);
}

SferaMbcValue SferaFunctions::fd_apple_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 72u);
}

SferaMbcValue SferaFunctions::fd_apple_use_is_stack_use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_is_stack_use_f003d3d6_body(std::move(c), args, SferaFields::integer_60_at_8);
}

SferaMbcValue SferaFunctions::fd_apple_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_UseWith_body(std::move(c), args, SferaFields::integer_44_at_10);
}

SferaMbcValue SferaFunctions::fd_apple_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 49u, SferaFields::integer_36, SferaFields::integer_191, SferaFields::integer_37,
        58u, SferaFields::integer_38, SferaFields::reference_39, SferaFields::buffer_40, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u);
}

SferaNativeTask SferaFunctions::vn_karma_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_a553e68b_body(std::move(c), std::move(args), SferaFunctions::vn_karma_UseClient);
}

SferaMbcValue SferaFunctions::vn_karma_UseClient(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseClient_7e1b9bcc_body(std::move(c), args, SferaFields::reference_251, SferaFields::integer_250);
}

SferaMbcValue SferaFunctions::vn_karma_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_body(std::move(c), args, SferaFields::buffer_47, 4u, SferaFields::integer_82);
}

SferaMbcValue SferaFunctions::vn_karma_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_body(std::move(c), args, SferaFields::reference_47_at_4);
}

SferaMbcValue SferaFunctions::specab_ca_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_0943456d_body(std::move(c), args, SferaFunctions::specab_ca_UseWith);
}

SferaNativeTask SferaFunctions::specab_ca_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_9a43a292_body(std::move(c), std::move(args), SferaFunctions::specab_ca_Use);
}

SferaMbcValue SferaFunctions::specab_ca_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_797ed502_body(std::move(c), args, SferaFunctions::specab_ca_AddCheck);
}

SferaMbcValue SferaFunctions::specab_ca_AddCheck(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddCheck_body(std::move(c), args, SferaFields::integer_324_at_9, 87u);
}

SferaMbcValue SferaFunctions::vn_candy_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_1b363b1a_body(std::move(c), args, 80u, SferaFields::reference_315, 2u, SferaFields::reference_316,
        SferaFields::integer_82, SferaFields::buffer_41);
}

SferaMbcValue SferaFunctions::vn_candy_AddCheck(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_41_at_6);
}

SferaMbcValue SferaFunctions::vn_candy_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_dba28d1d_body(std::move(c), args, SferaFields::reference_182, SferaFields::integer_82,
        SferaFields::buffer_204, 10u, 101u);
}

SferaMbcValue SferaFunctions::crystal_attr_a_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_d03707f6_body(std::move(c), args, 48u, SferaFields::buffer_43, SferaFields::buffer_45,
        SferaFields::buffer_46, 6u, SferaFields::buffer_47);
}

SferaMbcValue SferaFunctions::crystal_attr_a_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::crystal_attr_a_CheckPut);
}

SferaMbcValue SferaFunctions::crystal_attr_a_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_41);
}

SferaMbcValue SferaFunctions::mg_mantraw_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_acb71a1f_body(std::move(c), args, SferaFunctions::mg_mantraw_UseWith);
}

SferaNativeTask SferaFunctions::mg_mantraw_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_4e681af7_body(std::move(c), std::move(args), SferaFunctions::mg_mantraw_Use);
}

SferaMbcValue SferaFunctions::mg_mantraw_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_73bcb877_body(std::move(c), args, 28u);
}

SferaMbcValue SferaFunctions::st_light1_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_a7cd8f11_body(std::move(c), args, SferaFunctions::st_light1_CheckPut);
}

SferaNativeTask SferaFunctions::st_light1_Main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Main_87f167e6_body(std::move(c), std::move(args), 91u);
}

SferaMbcValue SferaFunctions::st_light1_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckPut_2915b058_body(std::move(c), args, 94u);
}

SferaMbcValue SferaFunctions::claim_blank_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::claim_blank_InitObj);
}

SferaMbcValue SferaFunctions::claim_blank_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 5u, SferaFields::buffer_201, 12u);
}

SferaMbcValue SferaFunctions::telep3_GetTP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetTP_94aedd18_body(std::move(c), args, 1036831949u, 1045220557u);
}

SferaNativeTask SferaFunctions::telep3_Cli(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Cli_body(std::move(c), std::move(args), 81u);
}

SferaNativeTask SferaFunctions::npc_trader_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_521c60b3_body(std::move(c), std::move(args), 3u, SferaFields::buffer_216, SferaFields::buffer_217, 11u,
        SferaFields::buffer_218, SferaFields::integer_218_at_6, SferaFields::buffer_219, SferaFunctions::npc14_ShowHlth);
}

SferaMbcValue SferaFunctions::mg_rcp_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SndUser_4e1c6ed9_body(std::move(c), args, SferaFields::reference_245, SferaFields::integer_54);
}

SferaNativeTask SferaFunctions::tmnt_hostage_checkExit(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_checkExit_body(std::move(c), std::move(args), SferaFields::buffer_359, 1077936128u);
}

SferaMbcValue SferaFunctions::vir1049_CallPict(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ar_ring_SndUser_body(std::move(c), args, SferaFields::reference_0_at_17);
}

SferaMbcValue SferaFunctions::vir1002_CallEnd(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_empty_body(std::move(c), args, SferaFields::integer_2);
}

SferaNativeTask SferaFunctions::vir1044_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 18u);
}

SferaNativeTask SferaFunctions::vir1019_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 8u);
}

SferaMbcValue SferaFunctions::vir1016_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_ebc3160a_body(std::move(c), args, 206u);
}
