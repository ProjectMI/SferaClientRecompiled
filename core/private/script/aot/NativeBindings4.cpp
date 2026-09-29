#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::ct_chest1_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_97811cb2_body(std::move(c), args, SferaFunctions::ct_chest1_UseOwner);
}

SferaMbcValue SferaFunctions::ct_chest1_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_202, 64u, SferaFields::buffer_81, SferaFields::integer_196);
}

SferaNativeTask SferaFunctions::ct_chest1_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_3738afb9_body(std::move(c), std::move(args), 5u, SferaFields::integer_194, SferaFields::reference_188,
        SferaFields::integer_195, SferaFields::integer_198, SferaFields::buffer_191, SferaFields::buffer_86, 47u, 16u,
        SferaFields::buffer_202, 64u, 4294967280u, SferaFields::buffer_81, 47u, SferaFunctions::ct_chest1_Use,
        SferaFunctions::ct_chest1_sendslot);
}

SferaMbcValue SferaFunctions::ct_chest1_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 5u, SferaFields::integer_0, SferaFields::integer_63,
        SferaFields::integer_62, 47u, SferaFields::integer_66, SferaFields::reference_83, SferaFields::buffer_84, SferaFields::integer_64,
        SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::ct_chest1_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 41u, 46u, SferaFields::reference_187, SferaFields::integer_3,
        SferaFields::buffer_230, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_231, SferaFields::buffer_232,
        SferaFields::buffer_233, 58u, 57u, SferaFields::buffer_234, SferaFields::buffer_226, SferaFields::buffer_227,
        SferaFields::integer_228, SferaFields::integer_229, SferaFields::reference_221, SferaFields::buffer_235,
        SferaFields::reference_220, SferaFields::buffer_200, SferaFields::reference_222, SferaFields::buffer_236,
        SferaFields::reference_223, SferaFields::buffer_237, SferaFields::reference_224, SferaFields::reference_225,
        SferaFields::buffer_238, SferaFields::buffer_239, SferaFields::buffer_240, SferaFields::buffer_241, SferaFields::real_192,
        SferaFields::integer_61, SferaFields::real_193, 100000u, SferaFields::buffer_242, SferaFields::buffer_243, 59u, 56u,
        SferaFields::buffer_244, SferaFields::buffer_245, SferaFields::buffer_247, SferaFields::buffer_246, SferaFields::buffer_248,
        SferaFields::buffer_249, SferaFields::buffer_250);
}

SferaMbcValue SferaFunctions::ct_chest1_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 48u, SferaFields::buffer_251, SferaFields::buffer_252, SferaFields::buffer_253,
        10u, 5u);
}

SferaMbcValue SferaFunctions::ct_chest1_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_197, 17u, SferaFields::reference_203, 47u,
        SferaFields::buffer_202, 64u, 4294967280u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_chest1_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_d8a2dcca_body(std::move(c), args, 60u, SferaFields::integer_254, 61u, 47u, SferaFields::buffer_202, 64u,
        4294967280u, SferaFields::integer_255, 62u, SferaFields::buffer_256, 16u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::cs_table_CheckWght);
}

SferaMbcValue SferaFunctions::ct_chest1_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 49u, SferaFields::integer_204, 16u, SferaFields::integer_205,
        SferaFields::buffer_202, 64u, 4294967280u, SferaFields::integer_206);
}

SferaMbcValue SferaFunctions::ct_chest1_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 50u, SferaFields::integer_213, 16u, SferaFields::integer_214,
        SferaFields::buffer_202, 64u, 4294967280u);
}

SferaMbcValue SferaFunctions::ct_chest1_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 51u, SferaFields::integer_186, SferaFields::integer_215, 16u, 52u,
        SferaFields::buffer_202, 64u, 4294967280u);
}

SferaMbcValue SferaFunctions::ct_chest1_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_29d8322a_body(std::move(c), args, 63u, SferaFields::integer_186, 64u, 65u, SferaFields::buffer_257, 66u,
        68u, SferaFields::integer_257_at_8, 16u, 67u, SferaFields::buffer_202, 64u, 4294967280u, SferaFields::buffer_258,
        SferaFields::buffer_259, 69u, 70u, 71u, 72u, SferaFields::buffer_260, 73u, SferaFields::buffer_261, SferaFields::buffer_263,
        SferaFields::buffer_261_at_12, SferaFields::buffer_264, SferaFields::buffer_262, SferaFields::buffer_265, SferaFields::buffer_266,
        SferaFields::buffer_267, SferaFields::buffer_268, 74u, SferaFields::buffer_182, SferaFunctions::ct_chest1_TestIt);
}

SferaMbcValue SferaFunctions::ct_chest1_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_269, 16u, SferaFields::buffer_202, 64u, 4294967280u,
        SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_chest1_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 47u, SferaFields::integer_270, 16u, SferaFields::buffer_202, 64u,
        4294967280u, SferaFields::buffer_81, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::ct_chest1_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 75u, 47u, SferaFields::integer_271, 16u, SferaFields::buffer_202, 64u,
        4294967280u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_chest1_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 16u);
}

SferaMbcValue SferaFunctions::ct_chest1_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_216, 16u, SferaFields::buffer_202, 64u, 4294967280u);
}

SferaMbcValue SferaFunctions::ct_chest1_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_85, 16u, SferaFields::buffer_54, 64u, 4294967280u);
}

SferaMbcValue SferaFunctions::ct_chest1_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_217, SferaFields::integer_218, 16u, SferaFields::buffer_202,
        64u, 4294967280u);
}

SferaMbcValue SferaFunctions::ct_chest1_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_219, 16u, SferaFields::buffer_202, 64u, 4294967280u);
}

SferaMbcValue SferaFunctions::ct_chest1_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_12088b0e_body(std::move(c), args, 4u, SferaFields::buffer_80, 38u, SferaFunctions::bank_isGxpItem);
}

SferaMbcValue SferaFunctions::ct_chest1_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_189,
        SferaFields::reference_190, SferaFields::reference_209, SferaFields::buffer_212, 3u, SferaFields::reference_211,
        SferaFields::reference_210);
}

SferaMbcValue SferaFunctions::quest_empty(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_empty_body(std::move(c), args, SferaFields::integer_212_at_3);
}

SferaMbcValue SferaFunctions::quest_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_289, SferaFields::integer_184, 99u,
        SferaFields::integer_288, 10u, SferaFields::buffer_284, 40u, 4294967286u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::quest_sendslot);
}

SferaMbcValue SferaFunctions::quest_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_284, 40u, SferaFields::buffer_285, SferaFields::integer_290);
}

SferaNativeTask SferaFunctions::quest_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_c22d77f4_body(std::move(c), std::move(args), 10u, 40u, 4294967286u, SferaFunctions::quest_sendslot);
}

SferaMbcValue SferaFunctions::quest_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_be50c274_body(std::move(c), args, 89u, 90u, SferaFields::reference_222, SferaFields::integer_200,
        SferaFields::buffer_235, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_236, SferaFields::buffer_237,
        SferaFields::buffer_238, 94u, 93u, SferaFields::buffer_239, SferaFields::buffer_231, SferaFields::buffer_232,
        SferaFields::integer_233, SferaFields::integer_234, SferaFields::reference_226, SferaFields::buffer_240,
        SferaFields::reference_225, SferaFields::buffer_241, SferaFields::reference_227, SferaFields::buffer_242,
        SferaFields::reference_228, SferaFields::buffer_243, SferaFields::reference_229, SferaFields::reference_230,
        SferaFields::buffer_244, SferaFields::buffer_245, SferaFields::buffer_246, SferaFields::buffer_248, SferaFields::buffer_249,
        SferaFields::buffer_249_at_18, SferaFields::integer_213, SferaFields::real_223, SferaFields::integer_250, SferaFields::real_224,
        200000u, SferaFields::buffer_252, SferaFields::buffer_253, 91u, 92u, SferaFields::buffer_254, SferaFields::buffer_255,
        SferaFields::buffer_257, SferaFields::buffer_256, SferaFields::buffer_259, SferaFields::buffer_260, SferaFields::buffer_261);
}

SferaMbcValue SferaFunctions::quest_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::ct_cbook1_UseServer);
}

SferaMbcValue SferaFunctions::quest_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_300, 100u, SferaFields::reference_301, 99u,
        SferaFields::buffer_284, 40u, 4294967286u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_ed86e89b_body(std::move(c), args, 40u, 4294967286u, 10u);
}

SferaMbcValue SferaFunctions::quest_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 104u, SferaFields::integer_305, 10u, SferaFields::integer_306,
        SferaFields::buffer_284, 40u, 4294967286u, SferaFields::integer_307);
}

SferaMbcValue SferaFunctions::quest_SeekTagInsideNoRecursive(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 105u, SferaFields::integer_308, 10u, SferaFields::integer_309,
        SferaFields::buffer_284, 40u, 4294967286u);
}

SferaMbcValue SferaFunctions::quest_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 106u, SferaFields::integer_287, SferaFields::integer_310, 10u, 107u,
        SferaFields::buffer_284, 40u, 4294967286u);
}

SferaMbcValue SferaFunctions::quest_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_262, 200000u);
}

SferaMbcValue SferaFunctions::quest_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 108u, 109u, SferaFields::integer_311, 10u, SferaFields::buffer_284, 40u,
        4294967286u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 110u, 99u, SferaFields::integer_312, 10u, SferaFields::buffer_284, 40u,
        4294967286u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_313, 99u, SferaFields::integer_314, 10u,
        SferaFields::buffer_284, 40u, 4294967286u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 10u);
}

SferaMbcValue SferaFunctions::quest_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_315, 10u, SferaFields::buffer_284, 40u, 4294967286u);
}

SferaMbcValue SferaFunctions::quest_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_316, 10u, SferaFields::buffer_286, 40u, 4294967286u);
}

SferaMbcValue SferaFunctions::quest_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_317, SferaFields::integer_318, 10u, SferaFields::buffer_284,
        40u, 4294967286u);
}

SferaMbcValue SferaFunctions::quest_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_319, 10u, SferaFields::buffer_284, 40u, 4294967286u);
}

SferaMbcValue SferaFunctions::quest_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_263, SferaFields::reference_264, SferaFields::reference_265,
        SferaFields::reference_266, SferaFields::buffer_269, 15u, SferaFields::reference_268, SferaFields::reference_267);
}

SferaMbcValue SferaFunctions::quest_settim(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_269_at_15, SferaFields::integer_213);
}

SferaMbcValue SferaFunctions::quest_GetMMChr(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMMChr_body(std::move(c), args, SferaFields::reference_334, SferaFields::buffer_336, SferaFields::buffer_337, 8u,
        40u, 4294967286u, SferaFields::buffer_337_at_25, SferaFields::buffer_338, SferaFields::integer_335);
}

SferaMbcValue SferaFunctions::pcontrol_TSTHK(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_259_at_8, SferaFields::integer_260, 20u,
        SferaFields::buffer_145, 80u, 4294967276u);
}

SferaMbcValue SferaFunctions::pcontrol_ControlOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_ControlOff_body(std::move(c), args, SferaFields::integer_126, 0u);
}

SferaMbcValue SferaFunctions::pcontrol_IsChatFocus(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_cm_isVisible_body(std::move(c), args, SferaFields::integer_125, 106u, SferaFields::integer_363, 1u, 0u);
}

SferaMbcValue SferaFunctions::pcontrol_SetDebug(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_226, SferaFields::integer_203);
}

SferaMbcValue SferaFunctions::pcontrol_pcontrol_WinDiary_helper(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_WinDiary_helper_body(std::move(c), args, 0u, 1u);
}

SferaMbcValue SferaFunctions::pcontrol_pcontrol_WinDiary_helper_1671eb09(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_WinDiary_helper_body(std::move(c), args, 1u, 0u);
}

SferaMbcValue SferaFunctions::pcontrol_stopWinGroupNew(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_stopWinGroupExist_body(std::move(c), args, 73u);
}

SferaMbcValue SferaFunctions::pcontrol_stopWinGroupExist(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_stopWinGroupExist_body(std::move(c), args, 74u);
}

SferaMbcValue SferaFunctions::pcontrol_runRefreshWinGroupList(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_runRefreshWinGroupList_body(std::move(c), args, SferaFields::integer_639_at_8, SferaFields::integer_640, 76u);
}

SferaMbcValue SferaFunctions::pcontrol_RSTT(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_cm_create_body(std::move(c), args, 81u);
}

SferaMbcValue SferaFunctions::pcontrol_DropAsk_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_DropAsk_stop_body(std::move(c), args, 323u);
}

SferaMbcValue SferaFunctions::pcontrol_processRButtonDown(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_ControlOff_body(std::move(c), args, SferaFields::integer_131, 1u);
}

SferaMbcValue SferaFunctions::pcontrol_AutobattleHandler_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_Camera_stop_body(std::move(c), args, SferaFields::integer_926_at_11, 0u);
}

SferaMbcValue SferaFunctions::pcontrol_ShowScroll_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_DropAsk_stop_body(std::move(c), args, 384u);
}

SferaMbcValue SferaFunctions::pcontrol_ShowText_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_142, SferaFields::integer_142);
}

SferaMbcValue SferaFunctions::pcontrol_CloseScroll(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_CloseScroll_body(std::move(c), args, 124u, 125u);
}

SferaMbcValue SferaFunctions::pcontrol_TABLE(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_TABLE_body(std::move(c), args, SferaFields::integer_1033_at_2, SferaFields::buffer_1034, 4u, 12u, 12u);
}

SferaMbcValue SferaFunctions::pcontrol_TTax_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_DropAsk_stop_body(std::move(c), args, 425u);
}

SferaMbcValue SferaFunctions::pcontrol_pcontrol_EvacPlayerWinPrg_helper(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_EvacPlayerWinPrg_helper_body(std::move(c), args, 1u);
}

SferaMbcValue SferaFunctions::pcontrol_pcontrol_EvacPlayerWinPrg_helper_7dd4c7dd(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_EvacPlayerWinPrg_helper_body(std::move(c), args, 2u);
}

SferaMbcValue SferaFunctions::pcontrol_closeEvacPlayerWin(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 149u);
}

SferaMbcValue SferaFunctions::pcontrol_clear_use_tout_working(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_UpdateTmntWin_body(std::move(c), args, 35u, 0u);
}

SferaMbcValue SferaFunctions::pcontrol_block_character_move(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_1082_at_15, SferaFields::integer_365);
}

SferaMbcValue SferaFunctions::pcontrol_IsForceDamager(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsForceDamager_body(std::move(c), args, SferaFields::byte_182);
}

SferaMbcValue SferaFunctions::pcontrol_FillBalanceGVG(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FillBalanceGVG_body(std::move(c), args, SferaFunctions::pcontrol_IsForceDamager);
}

SferaMbcValue SferaFunctions::pcontrol_UpdateTmntWin(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_pcontrol_UpdateTmntWin_body(std::move(c), args, 437u, 1u);
}

SferaMbcValue SferaFunctions::crt02_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 66u);
}

SferaMbcValue SferaFunctions::crt02_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_716186f6_body(std::move(c), args, 39u, SferaFields::buffer_60, 1u, SferaFields::integer_61,
        SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::crt02_Recalc(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Recalc_body(std::move(c), args, SferaFields::buffer_161, 200u, SferaFields::integer_263, 9u, 7u, 5u, 10u, 8u, 6u);
}

SferaMbcValue SferaFunctions::crt02_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_951304c9_body(std::move(c), args, SferaFunctions::crt02_UseOwner);
}

SferaMbcValue SferaFunctions::crt02_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_UseWith_body(std::move(c), args, SferaFields::integer_167_at_9);
}

SferaNativeTask SferaFunctions::crt02_ShowKill(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ShowKill_ba13cfba_body(std::move(c), std::move(args), 26u, SferaFields::buffer_154, SferaFields::integer_140, 25u,
        SferaFields::buffer_141, SferaFields::buffer_142, 24u, SferaFields::buffer_161, 200u, SferaFields::buffer_153,
        SferaFields::buffer_155, SferaFields::buffer_157, SferaFields::buffer_156, SferaFields::buffer_78, 256u, SferaFields::buffer_158,
        SferaFields::buffer_159, SferaFields::buffer_163, SferaFields::buffer_164, SferaFields::buffer_171, SferaFields::buffer_172, 1u,
        23u, 0u);
}

SferaMbcValue SferaFunctions::crt02_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 48u, SferaFields::integer_255, SferaFields::integer_269, 51u,
        SferaFields::integer_270, SferaFields::reference_272, SferaFields::buffer_273, SferaFields::integer_200, SferaFields::integer_271,
        SferaFields::reference_268, SferaFunctions::crt02_FlyWeapon);
}

SferaMbcValue SferaFunctions::crt02_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_f837f5b8_body(std::move(c), args, 3u);
}

SferaMbcValue SferaFunctions::crt02_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_162_at_5, 0u, 0u, 0u, 1u);
}

SferaMbcValue SferaFunctions::crt02_VirEffect(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_Effect_body(std::move(c), args, SferaFields::integer_277);
}

SferaMbcValue SferaFunctions::crt02_Params(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Params_body(std::move(c), args, SferaFields::reference_267, SferaFields::buffer_161, 200u);
}

SferaMbcValue SferaFunctions::crt02_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 82u);
}

SferaMbcValue SferaFunctions::crt02_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 17u, 56u, SferaFields::buffer_83, 84u);
}

SferaNativeTask SferaFunctions::crt02_CheckSpec(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckSpec_body(std::move(c), std::move(args), SferaFields::reference_89, SferaFields::buffer_161, 200u, 32u, 34u,
        41u, 43u, 33u, SferaFields::buffer_160, 40u, 42u, 44u);
}

SferaMbcValue SferaFunctions::crt02_getCreatureLevel(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_getCreatureLevel_body(std::move(c), args, SferaFields::buffer_161, 200u);
}

SferaMbcValue SferaFunctions::crt02_MinDist(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_crt02_MaxDist_body(std::move(c), args, 30u, 50u, 30u, 55u);
}

SferaMbcValue SferaFunctions::crt02_MaxDist(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_crt02_MaxDist_body(std::move(c), args, 80u, 80u, 60u, 70u);
}

SferaMbcValue SferaFunctions::crt02_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_163ef7d4_body(std::move(c), args, SferaFields::integer_252);
}

SferaMbcValue SferaFunctions::cs_guard_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_951304c9_body(std::move(c), args, SferaFunctions::cs_guard_UseOwner);
}

SferaNativeTask SferaFunctions::cs_guard_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_d1eccf3b_body(std::move(c), std::move(args), SferaFunctions::cs_guard_Use);
}

SferaMbcValue SferaFunctions::cs_guard_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 48u, SferaFields::integer_255, SferaFields::integer_269, 51u,
        SferaFields::integer_270, SferaFields::reference_272, SferaFields::buffer_273, SferaFields::integer_200, SferaFields::integer_271,
        SferaFields::reference_268, SferaFunctions::cs_guard_FlyWeapon);
}

SferaMbcValue SferaFunctions::cs_guard_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_237abbb1_body(std::move(c), args, 3u);
}

SferaMbcValue SferaFunctions::cs_guard_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_162_at_5, 0u, 0u, 1u, 1u);
}

SferaMbcValue SferaFunctions::cs_guard_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 85u);
}

SferaMbcValue SferaFunctions::cs_guard_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 138u, 139u, SferaFields::buffer_83, 87u);
}

SferaMbcValue SferaFunctions::cs_guard_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_694e7ae7_body(std::move(c), args, 115u, SferaFields::integer_314, 116u, 58u, SferaFields::buffer_253, 12u,
        4294967293u, SferaFields::integer_315, 117u, SferaFields::buffer_316, 3u, SferaFunctions::cs_guard_openSlot);
}

SferaMbcValue SferaFunctions::cs_guard_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_4816c116_body(std::move(c), args, 118u, SferaFields::integer_189, 119u, 120u, SferaFields::buffer_317,
        121u, 123u, SferaFields::integer_317_at_8, 3u, 122u, SferaFields::buffer_253, 12u, 4294967293u, SferaFields::buffer_318,
        SferaFields::buffer_319, 124u, 125u, 126u, 127u, SferaFields::buffer_320, 128u, SferaFields::buffer_321, SferaFields::buffer_323,
        SferaFields::buffer_321_at_12, SferaFields::buffer_324, SferaFields::buffer_322, SferaFields::buffer_325, SferaFields::buffer_326,
        SferaFields::buffer_327, SferaFields::buffer_328, 129u, SferaFunctions::cs_guard_TestIt);
}

SferaMbcValue SferaFunctions::cs_guard_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_344, SferaFields::reference_345, SferaFields::reference_346,
        SferaFields::reference_347, SferaFields::buffer_350, 2u, SferaFields::reference_349, SferaFields::reference_348);
}

SferaMbcValue SferaFunctions::cs_guard_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_163ef7d4_body(std::move(c), args, SferaFields::integer_239_at_5);
}

SferaMbcValue SferaFunctions::ct_bagd_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 72u, 73u, SferaFields::reference_241, SferaFields::integer_200,
        SferaFields::buffer_287, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_288, SferaFields::buffer_289,
        SferaFields::buffer_290, 89u, 88u, SferaFields::buffer_291, SferaFields::buffer_283, SferaFields::buffer_284,
        SferaFields::integer_285, SferaFields::integer_286, SferaFields::reference_267, SferaFields::buffer_292,
        SferaFields::reference_266, SferaFields::buffer_293, SferaFields::reference_268, SferaFields::buffer_294,
        SferaFields::reference_269, SferaFields::buffer_246, SferaFields::reference_281, SferaFields::reference_282,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_264,
        SferaFields::integer_250, SferaFields::real_265, 30000u, SferaFields::buffer_254, SferaFields::buffer_255, 74u, 78u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_bagd_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_218, 48u, 4294967284u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 12u, SferaFunctions::bank_openSlot, SferaFunctions::ct_bagd_CheckWght);
}

SferaMbcValue SferaFunctions::ct_bagd_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 60u, SferaFields::integer_217, 61u, 62u, SferaFields::buffer_202, 79u,
        81u, SferaFields::integer_202_at_8, 12u, 80u, SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_270,
        SferaFields::buffer_271, 82u, 83u, 84u, 85u, SferaFields::buffer_272, 86u, SferaFields::buffer_273, SferaFields::buffer_275,
        SferaFields::buffer_273_at_12, SferaFields::buffer_276, SferaFields::buffer_274, SferaFields::buffer_277, SferaFields::buffer_278,
        SferaFields::buffer_279, SferaFields::buffer_280, 87u, SferaFields::buffer_182, SferaFunctions::ct_bagd_TestIt);
}

SferaMbcValue SferaFunctions::ct_bagd_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 30000u);
}

SferaMbcValue SferaFunctions::ct_mbook4_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_body(std::move(c), args, SferaFields::reference_196, 3u, SferaFields::integer_186, 24u,
        SferaFields::buffer_233, 96u, 4294967272u, SferaFunctions::ct_barn_sendslot);
}

SferaNativeTask SferaFunctions::ct_mbook4_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_70a36942_body(std::move(c), std::move(args), SferaFields::integer_54, SferaFields::reference_203,
        SferaFields::integer_85, SferaFields::integer_197, SferaFields::buffer_204, SferaFields::buffer_205, 24u, SferaFields::buffer_233,
        96u, 4294967272u, SferaFields::buffer_81, 3u, SferaFunctions::ct_barn_sendslot);
}

SferaMbcValue SferaFunctions::ct_mbook4_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 17u, SferaFields::integer_202, 57u, 3u, SferaFields::buffer_233, 96u, 4294967272u,
        SferaFields::integer_218, 58u, SferaFields::buffer_219, 24u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::ct_mbook_CheckWght);
}

SferaMbcValue SferaFunctions::ct_mbook4_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 67u, SferaFields::integer_234, 68u, 69u, SferaFields::buffer_235, 79u,
        81u, SferaFields::integer_235_at_8, 24u, 80u, SferaFields::buffer_233, 96u, 4294967272u, SferaFields::buffer_236,
        SferaFields::buffer_270, 82u, 83u, 84u, 85u, SferaFields::buffer_271, 86u, SferaFields::buffer_272, SferaFields::buffer_274,
        SferaFields::buffer_272_at_12, SferaFields::buffer_275, SferaFields::buffer_273, SferaFields::buffer_276, SferaFields::buffer_277,
        SferaFields::buffer_278, SferaFields::buffer_279, 87u, SferaFields::buffer_182, SferaFunctions::ct_mbook4_TestIt);
}

SferaMbcValue SferaFunctions::ct_mbook4_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_90_at_10, 3u, SferaFields::integer_206, 24u,
        SferaFields::buffer_233, 96u, 4294967272u, SferaFields::buffer_81);
}

SferaNativeTask SferaFunctions::npc_gold_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_f1cf35c1_body(std::move(c), std::move(args), SferaFunctions::npc_gold_UseOff);
}

SferaMbcValue SferaFunctions::npc_gold_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_f16e3b4b_body(std::move(c), args, SferaFunctions::npc_gold_UseOff);
}

SferaMbcValue SferaFunctions::npc_gold_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_333d080e_body(std::move(c), args, SferaFunctions::npc_gold_UseOwner);
}

SferaNativeTask SferaFunctions::npc_gold_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_521c60b3_body(std::move(c), std::move(args), 52u, SferaFields::buffer_224, SferaFields::buffer_225, 9u,
        SferaFields::buffer_256, SferaFields::integer_280, SferaFields::buffer_281, SferaFunctions::npc14_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_gold_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_da1ada41_body(std::move(c), args, 2u, 3u, 11u);
}

SferaMbcValue SferaFunctions::npc_gold_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOff_16bdcf23_body(std::move(c), args, 3u, SferaFields::buffer_216, 11u);
}

SferaMbcValue SferaFunctions::npc_gold_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_4da80933_body(std::move(c), args, SferaFields::integer_282, SferaFields::reference_283);
}

SferaMbcValue SferaFunctions::mission_WinAsyncInput(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_WinAsyncInput_body(std::move(c), args, SferaFields::integer_72_at_2, SferaFields::reference_73,
        SferaFields::reference_74, 0u, 0u);
}

SferaMbcValue SferaFunctions::mission_WinAsyncInputNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_WinAsyncInput_body(std::move(c), args, SferaFields::integer_75, SferaFields::reference_76, SferaFields::reference_77,
        1u, 0u);
}

SferaMbcValue SferaFunctions::mission_Mission_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_88, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::mission_TradeTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_mission_TradeTrig_body(std::move(c), args, SferaFields::integer_99_at_21, SferaFields::integer_3,
        SferaFunctions::mission_TradeOn, SferaFunctions::mission_TradeOff);
}

SferaMbcValue SferaFunctions::mission_TradeOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_inv_InvOn_body(std::move(c), args, 22u, SferaFields::integer_3, SferaFields::buffer_100, SferaFields::buffer_101, 12u,
        17u);
}

SferaMbcValue SferaFunctions::mission_TradeOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 12u);
}

SferaNativeTask SferaFunctions::pw_courage_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_f3052ab3_body(std::move(c), std::move(args), SferaFunctions::pw_courage_RcvUser);
}

SferaMbcValue SferaFunctions::pw_courage_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_290d4145_body(std::move(c), args, SferaFunctions::pw_courage_AddInfo);
}

SferaMbcValue SferaFunctions::pw_courage_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_27247a3d_body(std::move(c), args, SferaFields::buffer_128, SferaFields::buffer_199, 12u);
}

SferaMbcValue SferaFunctions::pw_courage_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_1cb0dfbe_body(std::move(c), args, SferaFields::integer_199_at_12, SferaFields::reference_201,
        SferaFields::buffer_290, 12u, SferaFields::buffer_0);
}

SferaMbcValue SferaFunctions::pw_courage_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_body(std::move(c), args, SferaFields::reference_0_at_6);
}

SferaMbcValue SferaFunctions::cs_knot_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 65u);
}

SferaMbcValue SferaFunctions::cs_knot_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_8376acdd_body(std::move(c), args, SferaFunctions::bank_UseOwner, SferaFunctions::bank_UseWith);
}

SferaMbcValue SferaFunctions::cs_knot_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 41u, SferaFields::integer_66, SferaFields::integer_63,
        SferaFields::integer_83, 51u, SferaFields::integer_84, SferaFields::reference_85, SferaFields::buffer_86, SferaFields::integer_64,
        SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::cs_knot_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 17u, SferaFields::buffer_54, SferaFields::buffer_80, SferaFields::buffer_81, 8u,
        0u);
}

SferaMbcValue SferaFunctions::trade_WinBankAuth_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_WinLink_stop_body(std::move(c), args, SferaFields::integer_83_at_11, 3u);
}

SferaMbcValue SferaFunctions::trade_TradeTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_mission_TradeTrig_body(std::move(c), args, SferaFields::integer_202_at_4, SferaFields::integer_91,
        SferaFunctions::trade_TradeOn, SferaFunctions::trade_TradeOff);
}

SferaMbcValue SferaFunctions::trade_TradeOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_inv_InvOn_body(std::move(c), args, 47u, SferaFields::integer_91, SferaFields::buffer_203, SferaFields::buffer_204, 15u,
        20u);
}

SferaMbcValue SferaFunctions::trade_TradeOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 15u);
}

SferaMbcValue SferaFunctions::purse_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::purse_CheckPut);
}

SferaMbcValue SferaFunctions::purse_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_10e3b377_body(std::move(c), args, 5u, 17u, SferaFields::reference_201, 4u, 65u);
}

SferaMbcValue SferaFunctions::purse_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_202_at_18);
}

SferaMbcValue SferaFunctions::purse_CheckFree(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckFree_cb6772d8_body(std::move(c), args, SferaFunctions::bank_halt);
}

SferaMbcValue SferaFunctions::token_pr_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_06611310_body(std::move(c), args, SferaFunctions::token_pr_UseOwner);
}

SferaMbcValue SferaFunctions::token_pr_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_398d065f_body(std::move(c), args, SferaFields::reference_250_at_12, SferaFields::integer_247,
        SferaFields::buffer_251, SferaFields::buffer_48, 64u, SferaFields::buffer_46, 6u);
}

SferaMbcValue SferaFunctions::token_pr_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_6f891cc9_body(std::move(c), args, SferaFields::integer_46_at_6);
}

SferaMbcValue SferaFunctions::fernbush_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 64u);
}

SferaNativeTask SferaFunctions::fernbush_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_47532592_body(std::move(c), std::move(args), SferaFields::reference_200, SferaFields::integer_199,
        SferaFields::buffer_201, SferaFields::buffer_202, 50u, SferaFunctions::cs_knot_Use);
}

SferaMbcValue SferaFunctions::fernbush_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_879a99f1_body(std::move(c), args, SferaFields::buffer_203, 0u);
}

SferaMbcValue SferaFunctions::st_string_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_726bc4f3_body(std::move(c), args, SferaFunctions::st_string_UseWith);
}

SferaMbcValue SferaFunctions::st_string_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_971db48c_body(std::move(c), args, 67u, 68u, 706u);
}

SferaMbcValue SferaFunctions::st_string_GetAntiHackNitkaCount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_cs_table_GetCastleNum_body(std::move(c), args, SferaFields::integer_53, 13u);
}

SferaMbcValue SferaFunctions::pw_buff0_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 9u, 76u);
}

SferaMbcValue SferaFunctions::pw_buff0_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 57u, SferaFields::integer_197, SferaFields::integer_191,
        SferaFields::integer_199, 61u, SferaFields::integer_201, SferaFields::reference_202, SferaFields::buffer_203,
        SferaFields::integer_198, SferaFields::integer_192, 46u, 47u);
}

SferaMbcValue SferaFunctions::fd_fish_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 70u);
}

SferaMbcValue SferaFunctions::fd_fish_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_d374b741_body(std::move(c), args, SferaFields::integer_240, SferaFields::buffer_241, 10u, 95u, 165u);
}

SferaMbcValue SferaFunctions::door_lk_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 62u);
}

SferaMbcValue SferaFunctions::door_lk_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_15715a6c_body(std::move(c), args, SferaFunctions::bank_halt);
}

SferaMbcValue SferaFunctions::vn_tnmnt_randbox_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_0f9f3fa3_body(std::move(c), args, SferaFields::buffer_256, 4u, SferaFields::integer_82,
        SferaFields::buffer_257, 11u, SferaFields::integer_251, SferaFields::buffer_258, 14u, SferaFields::integer_252);
}

SferaMbcValue SferaFunctions::mortar_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_4e68596a_body(std::move(c), args, SferaFields::integer_206, SferaFields::buffer_207);
}

SferaNativeTask SferaFunctions::monsterdf_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_00d2b32e_body(std::move(c), std::move(args), 4u, SferaFunctions::crt02_ShowHlth);
}

SferaMbcValue SferaFunctions::doorc_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_15715a6c_body(std::move(c), args, SferaFunctions::cs_chest_halt);
}

SferaNativeTask SferaFunctions::vir1031_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 12u);
}

SferaNativeTask SferaFunctions::vir1011_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 2u);
}

SferaMbcValue SferaFunctions::island_token_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 70u);
}

SferaMbcValue SferaFunctions::crt51_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_f837f5b8_body(std::move(c), args, 4u);
}
