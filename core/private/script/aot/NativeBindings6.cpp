#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::npc01_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 110u, 63u);
}

SferaNativeTask SferaFunctions::npc01_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_b95468e9_body(std::move(c), std::move(args), SferaFields::reference_256, 1u, 60u);
}

SferaMbcValue SferaFunctions::npc01_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_b4e2eadb_body(std::move(c), args, SferaFields::buffer_221, 4u, SferaFields::buffer_222,
        SferaFields::buffer_224, SferaFields::integer_264, 1u, SferaFields::reference_256, SferaFields::buffer_225,
        SferaFields::buffer_223);
}

SferaMbcValue SferaFunctions::npc01_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_56750d0a_body(std::move(c), args, 93u, SferaFields::integer_272, SferaFields::reference_277,
        SferaFields::integer_274, 1u, SferaFields::buffer_224, 4u, 4294967295u, SferaFields::buffer_221, SferaFields::integer_278,
        SferaFields::buffer_222, SferaFields::buffer_223, 47u, SferaFields::integer_275, SferaFields::buffer_279, SferaFields::integer_219,
        SferaFields::integer_276, SferaFields::reference_273, SferaFunctions::npc01_FlyWeapon);
}

SferaMbcValue SferaFunctions::npc01_NotEmptyCont(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_NotEmptyCont_body(std::move(c), args, SferaFields::integer_252, SferaFields::buffer_253, 35u,
        SferaFields::buffer_254, 79u);
}

SferaMbcValue SferaFunctions::npc01_SendOffer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SendOffer_body(std::move(c), args, SferaFields::integer_254_at_12, 104u, SferaFields::reference_255,
        SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::npc01_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_ee7fcfe6_body(std::move(c), args, 3u, SferaFields::buffer_215, SferaFields::buffer_216,
        SferaFields::buffer_217, 0u, SferaFields::buffer_218, SferaFunctions::npc01_ShowHlth);
}

SferaMbcValue SferaFunctions::npc01_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 71u);
}

SferaMbcValue SferaFunctions::npc01_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 94u, 95u, SferaFields::buffer_83, 73u);
}

SferaMbcValue SferaFunctions::npc01_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_57e7a4f4_body(std::move(c), args, SferaFields::integer_280, 96u, SferaFields::reference_281,
        SferaFields::buffer_224, 4u, 4294967295u, SferaFields::buffer_221);
}

SferaMbcValue SferaFunctions::npc01_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_694e7ae7_body(std::move(c), args, 106u, SferaFields::integer_303, 107u, 103u, SferaFields::buffer_220, 300u,
        4294967221u, SferaFields::integer_304, 108u, SferaFields::buffer_305, 75u, SferaFunctions::npc01_openSlot);
}

SferaMbcValue SferaFunctions::npc01_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 109u, SferaFields::integer_306, 75u, SferaFields::integer_307,
        SferaFields::buffer_220, 300u, 4294967221u, SferaFields::integer_308);
}

SferaMbcValue SferaFunctions::npc01_SeekTagInsideNoRecursive(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 110u, SferaFields::integer_309, 75u, SferaFields::integer_310,
        SferaFields::buffer_220, 300u, 4294967221u);
}

SferaMbcValue SferaFunctions::npc01_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 111u, SferaFields::integer_302, SferaFields::integer_311, 75u, 112u,
        SferaFields::buffer_220, 300u, 4294967221u);
}

SferaMbcValue SferaFunctions::npc01_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_4816c116_body(std::move(c), args, 113u, SferaFields::integer_302, 114u, 115u, SferaFields::buffer_312,
        116u, 118u, SferaFields::integer_312_at_8, 75u, 117u, SferaFields::buffer_220, 300u, 4294967221u, SferaFields::buffer_313,
        SferaFields::buffer_314, 119u, 120u, 121u, 122u, SferaFields::buffer_315, 123u, SferaFields::buffer_316, SferaFields::buffer_318,
        SferaFields::buffer_316_at_12, SferaFields::buffer_319, SferaFields::buffer_317, SferaFields::buffer_320, SferaFields::buffer_321,
        SferaFields::buffer_322, SferaFields::buffer_323, 124u, SferaFunctions::npc01_TestIt);
}

SferaMbcValue SferaFunctions::npc01_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_324, 75u, SferaFields::buffer_220, 300u,
        4294967221u, SferaFields::buffer_300);
}

SferaMbcValue SferaFunctions::npc01_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 103u, SferaFields::integer_325, 75u, SferaFields::buffer_220, 300u,
        4294967221u, SferaFields::buffer_300, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::npc01_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 125u, 103u, SferaFields::integer_326, 75u, SferaFields::buffer_220, 300u,
        4294967221u, SferaFields::buffer_300);
}

SferaMbcValue SferaFunctions::npc01_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 75u);
}

SferaMbcValue SferaFunctions::npc01_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_327, 75u, SferaFields::buffer_220, 300u, 4294967221u);
}

SferaMbcValue SferaFunctions::npc01_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_328, 75u, SferaFields::buffer_301, 300u, 4294967221u);
}

SferaMbcValue SferaFunctions::npc01_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_329, SferaFields::integer_330, 75u, SferaFields::buffer_220,
        300u, 4294967221u);
}

SferaMbcValue SferaFunctions::npc01_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_331, 75u, SferaFields::buffer_220, 300u, 4294967221u);
}

SferaMbcValue SferaFunctions::npc01_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_282, SferaFields::reference_283, SferaFields::reference_284,
        SferaFields::reference_285, SferaFields::buffer_288, 8u, SferaFields::reference_287, SferaFields::reference_286);
}

SferaMbcValue SferaFunctions::npc01_AddUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddUser_body(std::move(c), args, SferaFields::reference_335, SferaFields::reference_291, 98u, 97u,
        SferaFields::reference_336, SferaFields::buffer_334, SferaFields::integer_337, 480u);
}

SferaMbcValue SferaFunctions::ct_barn_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 66u);
}

SferaMbcValue SferaFunctions::ct_barn_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::ct_barn_InitObj);
}

SferaMbcValue SferaFunctions::ct_barn_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 5u, SferaFields::buffer_249, 8u);
}

SferaMbcValue SferaFunctions::ct_barn_dnts(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_249_at_8, SferaFields::integer_248);
}

SferaMbcValue SferaFunctions::ct_barn_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_146, SferaFields::integer_198, 3u,
        SferaFields::integer_130, 24u, SferaFields::buffer_233, 96u, 4294967272u, SferaFields::integer_54, SferaFields::integer_184,
        SferaFields::integer_62, 12u, 35u, SferaFunctions::ct_barn_sendslot);
}

SferaMbcValue SferaFunctions::ct_barn_CheckCanUseOnDistance(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckCanUseOnDistance_body(std::move(c), args, SferaFields::integer_151, 46u, SferaFields::buffer_166);
}

SferaMbcValue SferaFunctions::ct_barn_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_233, 96u, SferaFields::buffer_81, SferaFields::integer_215);
}

SferaMbcValue SferaFunctions::ct_barn_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 55u, SferaFields::integer_235, SferaFields::integer_54, SferaFields::integer_236,
        53u, SferaFields::integer_237, SferaFields::reference_238, SferaFields::buffer_239, SferaFields::integer_184,
        SferaFields::integer_62, 12u, 35u);
}

SferaMbcValue SferaFunctions::ct_barn_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_216, 56u, SferaFields::reference_217, 3u,
        SferaFields::buffer_233, 96u, 4294967272u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_barn_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 17u, SferaFields::integer_202, 57u, 3u, SferaFields::buffer_233, 96u, 4294967272u,
        SferaFields::integer_218, 58u, SferaFields::buffer_219, 24u, SferaFunctions::ct_barn_openSlot, SferaFunctions::ct_barn_CheckWght);
}

SferaMbcValue SferaFunctions::ct_barn_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 59u, SferaFields::integer_220, 24u, SferaFields::integer_221,
        SferaFields::buffer_233, 96u, 4294967272u, SferaFields::integer_222);
}

SferaMbcValue SferaFunctions::ct_barn_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 60u, SferaFields::integer_223, 24u, SferaFields::integer_224,
        SferaFields::buffer_233, 96u, 4294967272u);
}

SferaMbcValue SferaFunctions::ct_barn_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 61u, SferaFields::integer_234, SferaFields::integer_225, 24u, 62u,
        SferaFields::buffer_233, 96u, 4294967272u);
}

SferaMbcValue SferaFunctions::ct_barn_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_282, 500000u);
}

SferaMbcValue SferaFunctions::ct_barn_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 63u, 65u, SferaFields::integer_226, 24u, SferaFields::buffer_233, 96u,
        4294967272u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_barn_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 66u, 3u, SferaFields::integer_227, 24u, SferaFields::buffer_233, 96u, 4294967272u,
        SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_barn_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_80, 3u, SferaFields::integer_90, 24u, SferaFields::buffer_233,
        96u, 4294967272u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_barn_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 24u);
}

SferaMbcValue SferaFunctions::ct_barn_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_228, 24u, SferaFields::buffer_233, 96u, 4294967272u);
}

SferaMbcValue SferaFunctions::ct_barn_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_229, 24u, SferaFields::buffer_214, 96u, 4294967272u);
}

SferaMbcValue SferaFunctions::ct_barn_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_230, SferaFields::integer_231, 24u, SferaFields::buffer_233,
        96u, 4294967272u);
}

SferaMbcValue SferaFunctions::ct_barn_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_232, 24u, SferaFields::buffer_233, 96u, 4294967272u);
}

SferaMbcValue SferaFunctions::ct_barn_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_189,
        SferaFields::reference_190, SferaFields::reference_209, SferaFields::buffer_212, 15u, SferaFields::reference_211,
        SferaFields::reference_210);
}

SferaMbcValue SferaFunctions::ct_barn_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_d921e1d9_body(std::move(c), args, SferaFields::buffer_286, 7u, SferaFields::integer_82,
        SferaFields::buffer_287, 5u, SferaFields::integer_251);
}

SferaMbcValue SferaFunctions::ct_barn_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_e9053998_body(std::move(c), args, SferaFields::buffer_288, 7u, SferaFields::integer_82,
        SferaFields::buffer_289, 5u, SferaFields::integer_251);
}

SferaMbcValue SferaFunctions::ct_barn_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_70b136b5_body(std::move(c), args, SferaFields::reference_289_at_5, SferaFields::buffer_290,
        SferaFields::integer_82, SferaFields::buffer_291);
}

SferaMbcValue SferaFunctions::ct_barn_froom(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_froom_body(std::move(c), args, SferaFields::integer_291_at_5, SferaFields::integer_0);
}

SferaMbcValue SferaFunctions::ct_jar_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_90, SferaFields::integer_184, 5u,
        SferaFields::integer_82, 1u, SferaFields::buffer_0, 4u, 4294967295u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::ct_jar_sendslot);
}

SferaMbcValue SferaFunctions::ct_jar_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_0, 4u, SferaFields::buffer_62, SferaFields::integer_189);
}

SferaNativeTask SferaFunctions::ct_jar_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_beb84fb0_body(std::move(c), std::move(args), SferaFields::integer_190, SferaFields::reference_214,
        SferaFields::integer_199, SferaFields::integer_201, SferaFields::buffer_215, SferaFields::buffer_216, 1u, SferaFields::buffer_0,
        4u, 4294967295u, SferaFields::buffer_62, 5u, SferaFunctions::ct_jar_sendslot);
}

SferaMbcValue SferaFunctions::ct_jar_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 4u, 70u, SferaFields::reference_265, SferaFields::integer_200,
        SferaFields::buffer_276, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_277, SferaFields::buffer_278,
        SferaFields::buffer_279, 60u, 17u, SferaFields::buffer_280, SferaFields::buffer_272, SferaFields::buffer_273,
        SferaFields::integer_274, SferaFields::integer_275, SferaFields::reference_267, SferaFields::buffer_281,
        SferaFields::reference_233, SferaFields::buffer_282, SferaFields::reference_268, SferaFields::buffer_264,
        SferaFields::reference_269, SferaFields::buffer_246, SferaFields::reference_270, SferaFields::reference_271,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_266,
        SferaFields::integer_250, SferaFields::real_298, 500u, SferaFields::buffer_254, SferaFields::buffer_255, 86u, 3u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_jar_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_202, 57u, SferaFields::reference_217, 5u,
        SferaFields::buffer_0, 4u, 4294967295u, SferaFields::buffer_62);
}

SferaMbcValue SferaFunctions::ct_jar_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 56u, SferaFields::integer_219, 58u, 5u, SferaFields::buffer_0, 4u, 4294967295u,
        SferaFields::integer_220, 59u, SferaFields::buffer_221, 1u, SferaFunctions::bank_openSlot, SferaFunctions::ct_jar_CheckWght);
}

SferaMbcValue SferaFunctions::ct_jar_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 61u, SferaFields::integer_222, 1u, SferaFields::integer_223,
        SferaFields::buffer_0, 4u, 4294967295u, SferaFields::integer_224);
}

SferaMbcValue SferaFunctions::ct_jar_SeekTagInsideNoRecursive(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 62u, SferaFields::integer_225, 1u, SferaFields::integer_226,
        SferaFields::buffer_0, 4u, 4294967295u);
}

SferaMbcValue SferaFunctions::ct_jar_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 63u, SferaFields::integer_182, SferaFields::integer_227, 1u, 65u,
        SferaFields::buffer_0, 4u, 4294967295u);
}

SferaMbcValue SferaFunctions::ct_jar_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 66u, SferaFields::integer_182, 67u, 68u, SferaFields::buffer_228, 69u,
        73u, SferaFields::integer_228_at_8, 1u, 72u, SferaFields::buffer_0, 4u, 4294967295u, SferaFields::buffer_229,
        SferaFields::buffer_230, 74u, 78u, 79u, 80u, SferaFields::buffer_231, 81u, SferaFields::buffer_232, SferaFields::buffer_235,
        SferaFields::buffer_232_at_12, SferaFields::buffer_236, SferaFields::buffer_234, SferaFields::buffer_241, SferaFields::buffer_283,
        SferaFields::buffer_284, SferaFields::buffer_285, 82u, SferaFields::buffer_286, SferaFunctions::ct_jar_TestIt);
}

SferaMbcValue SferaFunctions::ct_jar_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_286_at_8, 500u);
}

SferaMbcValue SferaFunctions::ct_jar_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 83u, 84u, SferaFields::integer_287, 1u, SferaFields::buffer_0, 4u, 4294967295u,
        SferaFields::buffer_62);
}

SferaMbcValue SferaFunctions::ct_jar_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 85u, 5u, SferaFields::integer_288, 1u, SferaFields::buffer_0, 4u, 4294967295u,
        SferaFields::buffer_62);
}

SferaMbcValue SferaFunctions::ct_jar_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_289, 5u, SferaFields::integer_290, 1u, SferaFields::buffer_0,
        4u, 4294967295u, SferaFields::buffer_62);
}

SferaMbcValue SferaFunctions::ct_jar_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_291, 1u, SferaFields::buffer_0, 4u, 4294967295u);
}

SferaMbcValue SferaFunctions::ct_jar_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_292, 1u, SferaFields::buffer_218, 4u, 4294967295u);
}

SferaMbcValue SferaFunctions::ct_jar_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_293, SferaFields::integer_294, 1u, SferaFields::buffer_0, 4u,
        4294967295u);
}

SferaMbcValue SferaFunctions::ct_jar_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_295, 1u, SferaFields::buffer_0, 4u, 4294967295u);
}

SferaMbcValue SferaFunctions::ct_mbook1_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_185_at_3, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::ct_mbook1_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_body(std::move(c), args, SferaFields::reference_81, 56u, SferaFields::integer_54, 12u,
        SferaFields::buffer_218, 48u, 4294967284u, SferaFunctions::ct_bag_sendslot);
}

SferaNativeTask SferaFunctions::ct_mbook1_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_70a36942_body(std::move(c), std::move(args), SferaFields::integer_85, SferaFields::reference_197,
        SferaFields::integer_186, SferaFields::integer_196, SferaFields::buffer_203, SferaFields::buffer_204, 12u, SferaFields::buffer_218,
        48u, 4294967284u, SferaFields::buffer_214, 56u, SferaFunctions::ct_bag_sendslot);
}

SferaMbcValue SferaFunctions::ct_mbook1_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 73u, 74u, SferaFields::reference_65, SferaFields::integer_3,
        SferaFields::buffer_246, SferaFields::integer_183, SferaFields::integer_244, SferaFields::reference_247, SferaFields::buffer_248,
        SferaFields::buffer_249, 78u, 77u, SferaFields::buffer_252, SferaFields::buffer_238, SferaFields::buffer_239,
        SferaFields::integer_240, SferaFields::integer_245, SferaFields::reference_86, SferaFields::buffer_253, SferaFields::reference_84,
        SferaFields::buffer_254, SferaFields::reference_87, SferaFields::buffer_255, SferaFields::reference_88, SferaFields::buffer_256,
        SferaFields::reference_89, SferaFields::reference_237, SferaFields::buffer_257, SferaFields::buffer_258, SferaFields::buffer_259,
        SferaFields::buffer_260, SferaFields::real_66, SferaFields::integer_250, SferaFields::real_83, 3000u, SferaFields::buffer_261,
        SferaFields::buffer_262, 75u, 76u, SferaFields::buffer_263, SferaFields::buffer_264, SferaFields::buffer_266,
        SferaFields::buffer_265, SferaFields::buffer_267, SferaFields::buffer_268, SferaFields::buffer_269);
}

SferaMbcValue SferaFunctions::ct_mbook1_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_218, 48u, 4294967284u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 12u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::ct_mbook_CheckWght);
}

SferaMbcValue SferaFunctions::ct_mbook1_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 60u, SferaFields::integer_217, 61u, 62u, SferaFields::buffer_202, 79u,
        81u, SferaFields::integer_202_at_8, 12u, 80u, SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_270,
        SferaFields::buffer_271, 82u, 83u, 84u, 85u, SferaFields::buffer_272, 86u, SferaFields::buffer_273, SferaFields::buffer_275,
        SferaFields::buffer_273_at_12, SferaFields::buffer_276, SferaFields::buffer_274, SferaFields::buffer_277, SferaFields::buffer_278,
        SferaFields::buffer_279, SferaFields::buffer_280, 87u, SferaFields::buffer_182, SferaFunctions::ct_mbook1_TestIt);
}

SferaMbcValue SferaFunctions::ct_mbook1_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_90_at_10, 56u, SferaFields::integer_205, 12u,
        SferaFields::buffer_218, 48u, 4294967284u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::ct_mbook1_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_12088b0e_body(std::move(c), args, 4u, SferaFields::buffer_80, 38u, SferaFunctions::bank_getHostPID);
}

SferaMbcValue SferaFunctions::npc_collector_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_220, 300u, SferaFields::buffer_300, SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::npc_collector_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 48u, SferaFields::integer_255, SferaFields::integer_269, 51u,
        SferaFields::integer_270, SferaFields::reference_272, SferaFields::buffer_273, SferaFields::integer_200, SferaFields::integer_271,
        SferaFields::reference_268, SferaFunctions::npc_collector_FlyWeapon);
}

SferaNativeTask SferaFunctions::npc_collector_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_74399034_body(std::move(c), std::move(args), SferaFunctions::npc_collector_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_collector_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 81u);
}

SferaMbcValue SferaFunctions::npc_collector_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 51u, 56u, SferaFields::buffer_83, 83u);
}

SferaMbcValue SferaFunctions::npc_collector_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_333, 129u, SferaFields::reference_334, 103u,
        SferaFields::buffer_220, 300u, 4294967221u, SferaFields::buffer_300);
}

SferaMbcValue SferaFunctions::npc_collector_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_694e7ae7_body(std::move(c), args, 106u, SferaFields::integer_303, 107u, 103u, SferaFields::buffer_220, 300u,
        4294967221u, SferaFields::integer_304, 108u, SferaFields::buffer_305, 75u, SferaFunctions::ct_chest1_openSlot);
}

SferaMbcValue SferaFunctions::npc_collector_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_4816c116_body(std::move(c), args, 113u, SferaFields::integer_302, 114u, 115u, SferaFields::buffer_312,
        116u, 118u, SferaFields::integer_312_at_8, 75u, 117u, SferaFields::buffer_220, 300u, 4294967221u, SferaFields::buffer_313,
        SferaFields::buffer_314, 119u, 120u, 121u, 122u, SferaFields::buffer_315, 123u, SferaFields::buffer_316, SferaFields::buffer_318,
        SferaFields::buffer_316_at_12, SferaFields::buffer_319, SferaFields::buffer_317, SferaFields::buffer_320, SferaFields::buffer_321,
        SferaFields::buffer_322, SferaFields::buffer_323, 124u, SferaFunctions::npc_collector_TestIt);
}

SferaMbcValue SferaFunctions::npc_collector_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_971db48c_body(std::move(c), args, 80u, 81u, 709u);
}

SferaMbcValue SferaFunctions::npc_collector_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_f24e678e_body(std::move(c), args, SferaFields::integer_351_at_4, SferaFields::reference_352);
}

SferaMbcValue SferaFunctions::ct_sac_p_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 4u, 70u, SferaFields::reference_265, SferaFields::integer_200,
        SferaFields::buffer_276, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_277, SferaFields::buffer_278,
        SferaFields::buffer_279, 60u, 17u, SferaFields::buffer_280, SferaFields::buffer_272, SferaFields::buffer_273,
        SferaFields::integer_274, SferaFields::integer_275, SferaFields::reference_267, SferaFields::buffer_281,
        SferaFields::reference_233, SferaFields::buffer_282, SferaFields::reference_268, SferaFields::buffer_264,
        SferaFields::reference_269, SferaFields::buffer_246, SferaFields::reference_270, SferaFields::reference_271,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_266,
        SferaFields::integer_250, SferaFields::real_298, 100u, SferaFields::buffer_254, SferaFields::buffer_255, 86u, 3u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_sac_p_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 56u, SferaFields::integer_219, 58u, 5u, SferaFields::buffer_0, 4u, 4294967295u,
        SferaFields::integer_220, 59u, SferaFields::buffer_221, 1u, SferaFunctions::bank_openSlot, SferaFunctions::ct_sac_p_CheckWght);
}

SferaMbcValue SferaFunctions::ct_sac_p_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 66u, SferaFields::integer_182, 67u, 68u, SferaFields::buffer_228, 69u,
        73u, SferaFields::integer_228_at_8, 1u, 72u, SferaFields::buffer_0, 4u, 4294967295u, SferaFields::buffer_229,
        SferaFields::buffer_230, 74u, 78u, 79u, 80u, SferaFields::buffer_231, 81u, SferaFields::buffer_232, SferaFields::buffer_235,
        SferaFields::buffer_232_at_12, SferaFields::buffer_236, SferaFields::buffer_234, SferaFields::buffer_241, SferaFields::buffer_283,
        SferaFields::buffer_284, SferaFields::buffer_285, 82u, SferaFields::buffer_286, SferaFunctions::ct_sac_p_TestIt);
}

SferaMbcValue SferaFunctions::ct_sac_p_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_286_at_8, 100u);
}

SferaMbcValue SferaFunctions::npc_banker_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 89u, SferaFields::integer_48, SferaFields::integer_50, 47u,
        SferaFields::integer_51, SferaFields::reference_53, SferaFields::buffer_202, SferaFields::integer_35, SferaFields::integer_52,
        SferaFields::reference_49, SferaFunctions::npc_banker_FlyWeapon);
}

SferaNativeTask SferaFunctions::npc_banker_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_521c60b3_body(std::move(c), std::move(args), 3u, SferaFields::buffer_216, SferaFields::buffer_217, 11u,
        SferaFields::buffer_218, SferaFields::integer_218_at_6, SferaFields::buffer_219, SferaFunctions::npc_banker_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_banker_VirEffect(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_player_Effect_body(std::move(c), args, SferaFields::integer_5_at_2);
}

SferaMbcValue SferaFunctions::npc_banker_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 66u);
}

SferaMbcValue SferaFunctions::npc_banker_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 90u, 91u, SferaFields::buffer_83, 68u);
}

SferaMbcValue SferaFunctions::npc_banker_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_27247a3d_body(std::move(c), args, SferaFields::buffer_123, SferaFields::buffer_215, 7u);
}

SferaMbcValue SferaFunctions::npc_banker_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SndUser_220b86e4_body(std::move(c), args, SferaFields::reference_215_at_7);
}

SferaMbcValue SferaFunctions::ct_chest6_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_d8a2dcca_body(std::move(c), args, 60u, SferaFields::integer_254, 61u, 47u, SferaFields::buffer_202, 64u,
        4294967280u, SferaFields::integer_255, 62u, SferaFields::buffer_256, 16u, SferaFunctions::ct_chest6_openSlot,
        SferaFunctions::cs_table_CheckWght);
}

SferaMbcValue SferaFunctions::ct_chest6_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_29d8322a_body(std::move(c), args, 63u, SferaFields::integer_186, 64u, 65u, SferaFields::buffer_257, 66u,
        68u, SferaFields::integer_257_at_8, 16u, 67u, SferaFields::buffer_202, 64u, 4294967280u, SferaFields::buffer_258,
        SferaFields::buffer_259, 69u, 70u, 71u, 72u, SferaFields::buffer_260, 73u, SferaFields::buffer_261, SferaFields::buffer_263,
        SferaFields::buffer_261_at_12, SferaFields::buffer_264, SferaFields::buffer_262, SferaFields::buffer_265, SferaFields::buffer_266,
        SferaFields::buffer_267, SferaFields::buffer_268, 74u, SferaFields::buffer_182, SferaFunctions::ct_chest6_TestIt);
}

SferaMbcValue SferaFunctions::ct_chest6_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_189,
        SferaFields::reference_190, SferaFields::reference_209, SferaFields::buffer_212, 4u, SferaFields::reference_211,
        SferaFields::reference_210);
}

SferaNativeTask SferaFunctions::ct_cbook2_UseAll(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_UseAll_body(std::move(c), std::move(args), SferaFields::integer_297, 5u, 20u, 4294967291u, SferaFields::buffer_300,
        SferaFields::buffer_299, SferaFields::buffer_298, SferaFields::buffer_301, SferaFields::buffer_302);
}

SferaMbcValue SferaFunctions::ct_cbook2_ct_cbook1_WinMacros_helper(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_ct_cbook1_WinMacros_helper_body(std::move(c), args, SferaFields::buffer_348, SferaFields::integer_304, 5u,
        SferaFields::integer_305, SferaFields::buffer_310, SferaFields::reference_303, SferaFields::buffer_349, SferaFields::buffer_315,
        SferaFields::buffer_311, SferaFields::buffer_312, SferaFields::integer_309, SferaFields::buffer_350, SferaFields::buffer_351,
        SferaFields::buffer_352, SferaFunctions::ct_cbook2_CalcMacroID);
}

SferaMbcValue SferaFunctions::ct_cbook2_CalcMacroID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CalcMacroID_body(std::move(c), args, SferaFields::integer_353, 5u, 640u, SferaFields::integer_354,
        SferaFields::buffer_355, 20u, 4294967291u, SferaFields::buffer_356, SferaFields::buffer_357, SferaFields::buffer_358,
        SferaFields::buffer_359, SferaFields::buffer_360, SferaFields::buffer_361, SferaFields::buffer_362, SferaFields::buffer_363);
}

SferaMbcValue SferaFunctions::pw_elixir_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_482ac760_body(std::move(c), args, SferaFunctions::pw_elixir_UseWith);
}

SferaNativeTask SferaFunctions::pw_elixir_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_2879f135_body(std::move(c), std::move(args), SferaFields::integer_205, SferaFields::reference_214,
        SferaFields::integer_206, SferaFields::integer_213, SferaFields::integer_204, SferaFields::buffer_215, SferaFields::buffer_216,
        59u, SferaFunctions::pw_elixir_Use);
}

SferaMbcValue SferaFunctions::pw_elixir_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_d03707f6_body(std::move(c), args, 17u, SferaFields::buffer_43, SferaFields::buffer_44,
        SferaFields::buffer_45, 7u, SferaFields::buffer_46);
}

SferaMbcValue SferaFunctions::pw_elixir_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_91dd0327_body(std::move(c), args, 61u, 62u, 63u, SferaFields::buffer_212, 4u, SferaFields::buffer_211);
}

SferaMbcValue SferaFunctions::ct_chest4_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 10u, 64u);
}

SferaNativeTask SferaFunctions::ct_chest4_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_3738afb9_body(std::move(c), std::move(args), 41u, SferaFields::integer_62, SferaFields::reference_203,
        SferaFields::integer_80, SferaFields::integer_197, SferaFields::buffer_269, SferaFields::buffer_270, 50u, 8u,
        SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_214, 56u, SferaFunctions::cs_chest_Use,
        SferaFunctions::bank_sendslot);
}

SferaMbcValue SferaFunctions::ct_chest4_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 41u, SferaFields::integer_66, SferaFields::integer_63,
        SferaFields::integer_83, 50u, SferaFields::integer_84, SferaFields::reference_85, SferaFields::buffer_86, SferaFields::integer_64,
        SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::st_key_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_06f4a581_body(std::move(c), args, SferaFunctions::st_key_UseWith);
}

SferaMbcValue SferaFunctions::st_key_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_91afe4f1_body(std::move(c), args, 66u, 67u, 701u);
}

SferaMbcValue SferaFunctions::st_key_EKill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EKill_a28ec083_body(std::move(c), args, SferaFields::integer_151);
}

SferaMbcValue SferaFunctions::st_key_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_70b136b5_body(std::move(c), args, SferaFields::reference_275_at_12, SferaFields::buffer_276,
        SferaFields::integer_247, SferaFields::buffer_277);
}

SferaMbcValue SferaFunctions::telep4_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_672f849d_body(std::move(c), args, SferaFunctions::telep4_UseOwner);
}

SferaNativeTask SferaFunctions::telep4_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_bd245d6a_body(std::move(c), std::move(args), SferaFields::integer_83, SferaFields::reference_86,
        SferaFields::integer_84, SferaFields::integer_85, SferaFields::buffer_197, SferaFields::buffer_198, 52u,
        SferaFunctions::telep4_Use);
}

SferaMbcValue SferaFunctions::telep4_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_d374b741_body(std::move(c), args, SferaFields::integer_207_at_13, SferaFields::buffer_208, 100u, 170u,
        100u);
}

SferaMbcValue SferaFunctions::packet_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 9u, 70u);
}

SferaMbcValue SferaFunctions::packet_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::packet_CheckPut);
}

SferaMbcValue SferaFunctions::packet_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_201_at_12);
}

SferaMbcValue SferaFunctions::packet_CheckFree(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckFree_cb6772d8_body(std::move(c), args, SferaFunctions::cs_chest_halt);
}

SferaMbcValue SferaFunctions::island_pr_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_8376acdd_body(std::move(c), args, SferaFunctions::island_pr_UseOwner, SferaFunctions::player_SetProperty);
}

SferaMbcValue SferaFunctions::island_pr_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckRights_body(std::move(c), args, SferaFields::integer_167_at_8);
}

SferaMbcValue SferaFunctions::island_pr_froom(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_froom_body(std::move(c), args, SferaFields::integer_182, SferaFields::integer_151);
}

SferaMbcValue SferaFunctions::vn_snowman_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_ec1497dc_body(std::move(c), args, 67u, SferaFields::integer_47, SferaFields::integer_203,
        SferaFields::integer_48, 57u, SferaFields::integer_49, SferaFields::reference_90, SferaFields::buffer_193,
        SferaFields::integer_194, SferaFields::integer_184, 52u, 53u, 54u);
}

SferaMbcValue SferaFunctions::vn_snowman_FillPict(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FillPict_body(std::move(c), args, SferaFields::reference_45, SferaFields::buffer_311, 8u);
}

SferaMbcValue SferaFunctions::flag_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_d03707f6_body(std::move(c), args, 48u, SferaFields::buffer_43, SferaFields::buffer_45,
        SferaFields::buffer_46, 9u, SferaFields::buffer_47);
}

SferaMbcValue SferaFunctions::flag_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_91dd0327_body(std::move(c), args, 61u, 62u, 63u, SferaFields::buffer_212, 27u, SferaFields::buffer_211);
}

SferaNativeTask SferaFunctions::vn_karma1_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_a553e68b_body(std::move(c), std::move(args), SferaFunctions::vn_karma1_UseClient);
}

SferaMbcValue SferaFunctions::vn_karma1_UseClient(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseClient_7e1b9bcc_body(std::move(c), args, SferaFields::reference_259, SferaFields::integer_258_at_8);
}

SferaMbcValue SferaFunctions::st_loot_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckRights_body(std::move(c), args, SferaFields::integer_182_at_10);
}

SferaMbcValue SferaFunctions::st_loot_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_91afe4f1_body(std::move(c), args, 70u, 71u, 709u);
}

SferaNativeTask SferaFunctions::telep8_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_47532592_body(std::move(c), std::move(args), SferaFields::reference_200, SferaFields::integer_199,
        SferaFields::buffer_201, SferaFields::buffer_202, 49u, SferaFunctions::rock_Use);
}

SferaMbcValue SferaFunctions::telep_Qupd_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_218_at_9, SferaFields::integer_218_at_9);
}

SferaMbcValue SferaFunctions::lottery_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_body(std::move(c), args, SferaFields::buffer_199, 7u, SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::npc_father_frost_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ar_ring_SndUser_body(std::move(c), args, SferaFields::reference_248_at_11);
}

SferaNativeTask SferaFunctions::vir1045_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_54470819_body(std::move(c), std::move(args), 19u, 14u);
}

SferaNativeTask SferaFunctions::vir1035_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 14u);
}

SferaNativeTask SferaFunctions::vir1013_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 4u);
}

SferaMbcValue SferaFunctions::vir1039_CallLink(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CallLink_body(std::move(c), args, 3u, 12u);
}

SferaMbcValue SferaFunctions::chat_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 11u);
}
