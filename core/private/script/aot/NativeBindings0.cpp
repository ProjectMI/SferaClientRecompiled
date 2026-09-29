#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::bank_empty(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_empty_body(std::move(c), args, SferaFields::integer_1);
}

SferaMbcValue SferaFunctions::bank_halt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_halt_body(std::move(c), args, 2u, 3u);
}

SferaMbcValue SferaFunctions::bank_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 5u);
}

SferaMbcValue SferaFunctions::bank_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 61u);
}

SferaMbcValue SferaFunctions::bank_dnts(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_81, SferaFields::integer_80);
}

SferaMbcValue SferaFunctions::bank_GetObjHan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_2);
}

SferaMbcValue SferaFunctions::bank_GetModel(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetModel_body(std::move(c), args, SferaFields::integer_125_at_45, SferaFields::reference_58, SferaFields::buffer_123,
        20u);
}

SferaMbcValue SferaFunctions::bank_Effect(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Effect_body(std::move(c), args, SferaFields::integer_163);
}

SferaMbcValue SferaFunctions::bank_SetHealth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetHealth_body(std::move(c), args, SferaFields::buffer_160, 12u);
}

SferaMbcValue SferaFunctions::bank_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_body(std::move(c), args, 64u, SferaFields::reference_258, SferaFields::buffer_185, 2u,
        SferaFields::integer_250);
}

SferaMbcValue SferaFunctions::bank_GetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::bank_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_185_at_2, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::bank_CheckRights(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckRights_body(std::move(c), args, SferaFields::integer_59);
}

SferaMbcValue SferaFunctions::bank_GetParent(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_79);
}

SferaMbcValue SferaFunctions::bank_SetParent(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_SetParent_body(std::move(c), args, SferaFields::integer_135, SferaFields::buffer_132, 256u, 4u, 11u);
}

SferaMbcValue SferaFunctions::bank_Setxyz(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_Setabg_body(std::move(c), args, SferaFields::reference_72, 0u);
}

SferaMbcValue SferaFunctions::bank_Setabg(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_Setabg_body(std::move(c), args, SferaFields::reference_73, 12u);
}

SferaMbcValue SferaFunctions::bank_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_body(std::move(c), args, SferaFields::reference_196, 56u, SferaFields::integer_186, 8u,
        SferaFields::buffer_229, 32u, 4294967288u, SferaFunctions::bank_sendslot);
}

SferaMbcValue SferaFunctions::bank_froom(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_froom_body(std::move(c), args, SferaFields::integer_151, SferaFields::integer_57);
}

SferaMbcValue SferaFunctions::bank_CheckCanUseOnDistance(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckCanUseOnDistance_body(std::move(c), args, SferaFields::integer_146_at_12, 12u, SferaFields::buffer_130);
}

SferaMbcValue SferaFunctions::bank_use_send_cuse_to_server(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_send_cuse_to_server_body(std::move(c), args, SferaFields::integer_93_at_12, 36u, 37u,
        SferaFields::reference_82, SferaFields::buffer_132, 256u, 38u);
}

SferaMbcValue SferaFunctions::bank_IgnoreUseFreq(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 1u);
}

SferaMbcValue SferaFunctions::bank_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_body(std::move(c), args, 47u, 49u, SferaFields::buffer_203, SferaFields::buffer_205, SferaFields::integer_206,
        SferaFields::buffer_237, 50u, SferaFields::buffer_238, 51u, SferaFields::buffer_233, SferaFields::integer_91);
}

SferaMbcValue SferaFunctions::bank_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_UseWith_body(std::move(c), args, SferaFields::integer_167_at_8);
}

SferaMbcValue SferaFunctions::bank_UseServer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_152);
}

SferaMbcValue SferaFunctions::bank_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_229, 32u, SferaFields::buffer_214, SferaFields::integer_218);
}

SferaMbcValue SferaFunctions::bank_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 71u, SferaFields::integer_188, SferaFields::integer_187,
        SferaFields::integer_191, 47u, SferaFields::integer_192, SferaFields::reference_242, SferaFields::buffer_243,
        SferaFields::integer_183, SferaFields::integer_244, 40u, 46u);
}

SferaMbcValue SferaFunctions::bank_getItemName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_getItemName_body(std::move(c), args, SferaFields::reference_170);
}

SferaMbcValue SferaFunctions::bank_getNeutralInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_getNeutralInfo_body(std::move(c), args, SferaFields::integer_168, SferaFields::reference_169);
}

SferaMbcValue SferaFunctions::bank_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 72u, 73u, SferaFields::reference_241, SferaFields::integer_3,
        SferaFields::buffer_287, SferaFields::integer_183, SferaFields::integer_244, SferaFields::reference_288, SferaFields::buffer_289,
        SferaFields::buffer_290, 89u, 88u, SferaFields::buffer_291, SferaFields::buffer_283, SferaFields::buffer_284,
        SferaFields::integer_285, SferaFields::integer_286, SferaFields::reference_267, SferaFields::buffer_292,
        SferaFields::reference_266, SferaFields::buffer_293, SferaFields::reference_268, SferaFields::buffer_294,
        SferaFields::reference_269, SferaFields::buffer_249, SferaFields::reference_281, SferaFields::reference_282,
        SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::buffer_254, SferaFields::buffer_255, SferaFields::real_264,
        SferaFields::integer_250, SferaFields::real_265, 1000000u, SferaFields::buffer_256, SferaFields::buffer_257, 74u, 78u,
        SferaFields::buffer_259, SferaFields::buffer_260, SferaFields::buffer_262, SferaFields::buffer_261, SferaFields::buffer_263,
        SferaFields::buffer_270, SferaFields::buffer_271);
}

SferaMbcValue SferaFunctions::bank_createInfoSeparatorLine(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_createInfoSeparatorLine_body(std::move(c), args, SferaFields::reference_122);
}

SferaMbcValue SferaFunctions::bank_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_body(std::move(c), args, SferaFields::reference_129_at_5);
}

SferaMbcValue SferaFunctions::bank_GetPlName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetModel_body(std::move(c), args, SferaFields::integer_165, SferaFields::reference_166, SferaFields::buffer_78, 256u);
}

SferaMbcValue SferaFunctions::bank_GetUseDist(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_91);
}

SferaMbcValue SferaFunctions::bank_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 48u, SferaFields::buffer_193, SferaFields::buffer_194, SferaFields::buffer_195, 7u,
        6u);
}

SferaMbcValue SferaFunctions::bank_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_162_at_16, 0u, 0u, 1u, 0u);
}

SferaMbcValue SferaFunctions::bank_isGxpItem(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_4);
}

SferaMbcValue SferaFunctions::bank_setGxpItem(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_5_at_2, SferaFields::integer_4);
}

SferaMbcValue SferaFunctions::bank_getHostPID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::bank_GetPrice(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetPrice_body(std::move(c), args, SferaFields::integer_53_at_7, SferaFields::integer_251);
}

SferaMbcValue SferaFunctions::bank_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::bank_CheckPut);
}

SferaMbcValue SferaFunctions::bank_IsUnique(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_183);
}

SferaMbcValue SferaFunctions::bank_GetUniqueID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_198);
}

SferaMbcValue SferaFunctions::bank_GetUniqueGeneration(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_184);
}

SferaMbcValue SferaFunctions::bank_GetHealth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_160, 12u, 0u);
}

SferaMbcValue SferaFunctions::bank_GetHealth_m2(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_160, 12u, 4u);
}

SferaMbcValue SferaFunctions::bank_CheckIndex(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckIndex_body(std::move(c), args, SferaFields::integer_299);
}

SferaMbcValue SferaFunctions::bank_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_202, 57u, SferaFields::reference_217, 56u,
        SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::bank_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 61u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_229, 32u, 4294967288u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 8u, SferaFunctions::bank_openSlot, SferaFunctions::bank_CheckWght);
}

SferaMbcValue SferaFunctions::bank_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 58u, SferaFields::integer_219, 8u, SferaFields::integer_220,
        SferaFields::buffer_229, 32u, 4294967288u, SferaFields::integer_221);
}

SferaMbcValue SferaFunctions::bank_SeekTagInsideNoRecursive(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 59u, SferaFields::integer_222, 8u, SferaFields::integer_223,
        SferaFields::buffer_229, 32u, 4294967288u);
}

SferaMbcValue SferaFunctions::bank_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 63u, SferaFields::integer_230, SferaFields::integer_224, 8u, 70u,
        SferaFields::buffer_229, 32u, 4294967288u);
}

SferaMbcValue SferaFunctions::bank_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_272, 1000000u);
}

SferaMbcValue SferaFunctions::bank_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 67u, 68u, SferaFields::integer_235, 8u, SferaFields::buffer_229, 32u, 4294967288u,
        SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::bank_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 69u, 56u, SferaFields::integer_236, 8u, SferaFields::buffer_229, 32u, 4294967288u,
        SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::bank_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_190, 56u, SferaFields::integer_189, 8u,
        SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_214);
}

SferaMbcValue SferaFunctions::bank_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 8u);
}

SferaMbcValue SferaFunctions::bank_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_225, 8u, SferaFields::buffer_229, 32u, 4294967288u);
}

SferaMbcValue SferaFunctions::bank_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_216, 8u, SferaFields::buffer_215, 32u, 4294967288u);
}

SferaMbcValue SferaFunctions::bank_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_226, SferaFields::integer_227, 8u, SferaFields::buffer_229, 32u,
        4294967288u);
}

SferaMbcValue SferaFunctions::bank_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_228, 8u, SferaFields::buffer_229, 32u, 4294967288u);
}

SferaMbcValue SferaFunctions::bank_GetSpecialPoint(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_164);
}

SferaMbcValue SferaFunctions::bank_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckRights_body(std::move(c), args, SferaFields::integer_182);
}

SferaMbcValue SferaFunctions::bank_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_209,
        SferaFields::reference_210, SferaFields::reference_211, SferaFields::buffer_54, 2u, SferaFields::reference_213,
        SferaFields::reference_212);
}

SferaMbcValue SferaFunctions::bank_WinSelcount_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_90, SferaFields::integer_90);
}

SferaMbcValue SferaFunctions::bank_DigSeparate(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_DigSeparate_body(std::move(c), args, SferaFields::reference_307_at_9, SferaFields::reference_308, 3u,
        SferaFields::buffer_309, SferaFields::integer_310, SferaFields::integer_311, SferaFields::integer_312);
}

SferaMbcValue SferaFunctions::bank_DigSeparateInt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_DigSeparateInt_body(std::move(c), args, SferaFunctions::bank_DigSeparate);
}

SferaNativeTask SferaFunctions::bank_bank_WinBank_helper_5442bb6c(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_bank_WinBank_helper_5442bb6c_body(std::move(c), std::move(args), SferaFields::integer_316, SferaFields::integer_313,
        SferaFields::buffer_361, SferaFields::real_359, SferaFields::real_360, 80u, SferaFields::buffer_362, 79u, SferaFields::integer_314,
        SferaFields::integer_315, SferaFields::buffer_362_at_13, SferaFields::buffer_326, SferaFields::buffer_363, SferaFields::buffer_364);
}

SferaMbcValue SferaFunctions::bank_DnDRes(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_201_at_12, SferaFields::integer_199);
}

SferaMbcValue SferaFunctions::bank_WinPassw_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_197, SferaFields::integer_197);
}

SferaMbcValue SferaFunctions::bank_WinAuth_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_WinAuth_stop_body(std::move(c), args, SferaFields::integer_377_at_21, SferaFields::integer_377_at_21);
}

SferaMbcValue SferaFunctions::bank_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_383_at_11);
}

SferaMbcValue SferaFunctions::bank_HavePassw(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetKomiss_body(std::move(c), args, SferaFields::byte_0);
}

SferaMbcValue SferaFunctions::bank_GetKomiss(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetKomiss_body(std::move(c), args, SferaFields::byte_204);
}

SferaMbcValue SferaFunctions::ct_ibag_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_80, SferaFields::integer_184, 58u,
        SferaFields::integer_0, 3u, SferaFields::buffer_253, 12u, 4294967293u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::cs_gate_sendslot);
}

SferaNativeTask SferaFunctions::ct_ibag_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_beb84fb0_body(std::move(c), std::move(args), SferaFields::integer_81, SferaFields::reference_62,
        SferaFields::integer_82, SferaFields::integer_90, SferaFields::buffer_182, SferaFields::buffer_190, 3u, SferaFields::buffer_253,
        12u, 4294967293u, SferaFields::buffer_313, 58u, SferaFunctions::cs_gate_sendslot);
}

SferaMbcValue SferaFunctions::ct_ibag_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 35u, 59u, SferaFields::reference_199, SferaFields::integer_200,
        SferaFields::buffer_224, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_225, SferaFields::buffer_226,
        SferaFields::buffer_227, 63u, 62u, SferaFields::buffer_228, SferaFields::buffer_220, SferaFields::buffer_221,
        SferaFields::integer_222, SferaFields::integer_223, SferaFields::reference_215, SferaFields::buffer_229,
        SferaFields::reference_214, SferaFields::buffer_230, SferaFields::reference_216, SferaFields::buffer_231,
        SferaFields::reference_217, SferaFields::buffer_232, SferaFields::reference_218, SferaFields::reference_219,
        SferaFields::buffer_233, SferaFields::buffer_234, SferaFields::buffer_235, SferaFields::buffer_236, SferaFields::real_201,
        SferaFields::integer_250, SferaFields::real_202, 25000u, SferaFields::buffer_241, SferaFields::buffer_246, 60u, 61u,
        SferaFields::buffer_252, SferaFields::buffer_255, SferaFields::buffer_257, SferaFields::buffer_256, SferaFields::buffer_259,
        SferaFields::buffer_260, SferaFields::buffer_261);
}

SferaMbcValue SferaFunctions::ct_ibag_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 65u, SferaFields::integer_262, 66u, 58u, SferaFields::buffer_253, 12u, 4294967293u,
        SferaFields::integer_263, 67u, SferaFields::buffer_264, 3u, SferaFunctions::bank_openSlot, SferaFunctions::ct_ibag_CheckWght);
}

SferaMbcValue SferaFunctions::ct_ibag_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 68u, SferaFields::integer_189, 69u, 70u, SferaFields::buffer_265, 72u,
        74u, SferaFields::integer_265_at_8, 3u, 73u, SferaFields::buffer_253, 12u, 4294967293u, SferaFields::buffer_266,
        SferaFields::buffer_267, 78u, 79u, 80u, 81u, SferaFields::buffer_268, 82u, SferaFields::buffer_269, SferaFields::buffer_271,
        SferaFields::buffer_269_at_12, SferaFields::buffer_272, SferaFields::buffer_270, SferaFields::buffer_273, SferaFields::buffer_274,
        SferaFields::buffer_275, SferaFields::buffer_276, 83u, SferaFields::buffer_277, SferaFunctions::ct_ibag_TestIt);
}

SferaMbcValue SferaFunctions::ct_ibag_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_277_at_8, 25000u);
}

SferaMbcValue SferaFunctions::ct_ibag_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 84u, 85u, SferaFields::integer_278, 3u, SferaFields::buffer_253, 12u, 4294967293u,
        SferaFields::buffer_313);
}

SferaMbcValue SferaFunctions::ct_ibag_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 86u, 58u, SferaFields::integer_279, 3u, SferaFields::buffer_253, 12u, 4294967293u,
        SferaFields::buffer_313);
}

SferaMbcValue SferaFunctions::ct_ibag_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_280, 58u, SferaFields::integer_281, 3u,
        SferaFields::buffer_253, 12u, 4294967293u, SferaFields::buffer_313);
}

SferaMbcValue SferaFunctions::ct_ibag_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_282, 3u, SferaFields::buffer_253, 12u, 4294967293u);
}

SferaMbcValue SferaFunctions::clanlicence_halt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_halt_body(std::move(c), args, 3u, 4u);
}

SferaMbcValue SferaFunctions::clanlicence_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 6u);
}

SferaMbcValue SferaFunctions::clanlicence_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 69u);
}

SferaMbcValue SferaFunctions::clanlicence_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::clanlicence_InitObj);
}

SferaMbcValue SferaFunctions::clanlicence_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 5u, SferaFields::buffer_62, 9u);
}

SferaMbcValue SferaFunctions::clanlicence_dnts(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_62_at_9, SferaFields::integer_0);
}

SferaMbcValue SferaFunctions::clanlicence_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_716186f6_body(std::move(c), args, 45u, SferaFields::buffer_185, 2u, SferaFields::integer_35,
        SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::clanlicence_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_185_at_2, SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::clanlicence_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 49u, SferaFields::integer_204, SferaFields::integer_191,
        SferaFields::integer_205, 56u, SferaFields::integer_206, SferaFields::reference_197, SferaFields::buffer_203,
        SferaFields::integer_198, SferaFields::integer_192, 46u, 47u);
}

SferaMbcValue SferaFunctions::clanlicence_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_05e952b4_body(std::move(c), args, SferaFunctions::clanlicence_AddInfo);
}

SferaMbcValue SferaFunctions::clanlicence_GetPlName(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetModel_body(std::move(c), args, SferaFields::integer_129_at_5, SferaFields::reference_165, SferaFields::buffer_78,
        256u);
}

SferaMbcValue SferaFunctions::clanlicence_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 48u, SferaFields::buffer_193, SferaFields::buffer_194, SferaFields::buffer_195, 9u,
        6u);
}

SferaMbcValue SferaFunctions::clanlicence_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_0d2d5d95_body(std::move(c), args, SferaFields::integer_54, SferaFields::reference_201);
}

SferaMbcValue SferaFunctions::clanlicence_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_body(std::move(c), args, SferaFields::buffer_244, 5u, SferaFields::integer_189);
}

SferaMbcValue SferaFunctions::clanlicence_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_body(std::move(c), args, SferaFields::buffer_90, 5u, SferaFields::integer_189);
}

SferaMbcValue SferaFunctions::clanlicence_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_body(std::move(c), args, SferaFields::reference_90_at_5);
}

SferaMbcValue SferaFunctions::ct_mbook2_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_body(std::move(c), args, SferaFields::reference_221, 47u, SferaFields::integer_220, 16u,
        SferaFields::buffer_202, 64u, 4294967280u, SferaFunctions::ct_chest1_sendslot);
}

SferaNativeTask SferaFunctions::ct_mbook2_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_70a36942_body(std::move(c), std::move(args), SferaFields::integer_222, SferaFields::reference_225,
        SferaFields::integer_223, SferaFields::integer_224, SferaFields::buffer_226, SferaFields::buffer_227, 16u, SferaFields::buffer_202,
        64u, 4294967280u, SferaFields::buffer_81, 47u, SferaFunctions::ct_chest1_sendslot);
}

SferaMbcValue SferaFunctions::ct_mbook2_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_228, 56u, 47u, SferaFields::buffer_202, 64u, 4294967280u,
        SferaFields::integer_229, 57u, SferaFields::buffer_230, 16u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::ct_mbook_CheckWght);
}

SferaMbcValue SferaFunctions::ct_mbook2_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 58u, SferaFields::integer_186, 59u, 60u, SferaFields::buffer_231, 61u,
        63u, SferaFields::integer_231_at_8, 16u, 62u, SferaFields::buffer_202, 64u, 4294967280u, SferaFields::buffer_232,
        SferaFields::buffer_233, 65u, 66u, 67u, 68u, SferaFields::buffer_234, 69u, SferaFields::buffer_235, SferaFields::buffer_270,
        SferaFields::buffer_235_at_12, SferaFields::buffer_271, SferaFields::buffer_236, SferaFields::buffer_272, SferaFields::buffer_273,
        SferaFields::buffer_274, SferaFields::buffer_275, 79u, SferaFields::buffer_182, SferaFunctions::ct_mbook2_TestIt);
}

SferaMbcValue SferaFunctions::ct_mbook2_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 80u, 81u, SferaFields::integer_276, 16u, SferaFields::buffer_202, 64u,
        4294967280u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_mbook2_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 82u, 47u, SferaFields::integer_277, 16u, SferaFields::buffer_202, 64u,
        4294967280u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_mbook2_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_90_at_10, 47u, SferaFields::integer_278, 16u,
        SferaFields::buffer_202, 64u, 4294967280u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_mbook3_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_body(std::move(c), args, SferaFields::reference_196, 3u, SferaFields::integer_186, 20u,
        SferaFields::buffer_202, 80u, 4294967276u, SferaFunctions::ct_bag_herb_sendslot);
}

SferaNativeTask SferaFunctions::ct_mbook3_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_70a36942_body(std::move(c), std::move(args), SferaFields::integer_54, SferaFields::reference_203,
        SferaFields::integer_85, SferaFields::integer_197, SferaFields::buffer_204, SferaFields::buffer_205, 20u, SferaFields::buffer_202,
        80u, 4294967276u, SferaFields::buffer_81, 3u, SferaFunctions::ct_bag_herb_sendslot);
}

SferaMbcValue SferaFunctions::ct_mbook3_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 56u, SferaFields::integer_219, 57u, 3u, SferaFields::buffer_202, 80u, 4294967276u,
        SferaFields::integer_220, 58u, SferaFields::buffer_221, 20u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::ct_mbook_CheckWght);
}

SferaMbcValue SferaFunctions::ct_mbook3_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 63u, SferaFields::integer_215, 65u, 66u, SferaFields::buffer_228, 67u,
        69u, SferaFields::integer_228_at_8, 20u, 68u, SferaFields::buffer_202, 80u, 4294967276u, SferaFields::buffer_229,
        SferaFields::buffer_230, 79u, 80u, 81u, 82u, SferaFields::buffer_231, 83u, SferaFields::buffer_232, SferaFields::buffer_234,
        SferaFields::buffer_232_at_12, SferaFields::buffer_235, SferaFields::buffer_233, SferaFields::buffer_236, SferaFields::buffer_270,
        SferaFields::buffer_271, SferaFields::buffer_272, 84u, SferaFields::buffer_182, SferaFunctions::ct_mbook3_TestIt);
}

SferaMbcValue SferaFunctions::ct_mbook3_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_90_at_10, 3u, SferaFields::integer_206, 20u,
        SferaFields::buffer_202, 80u, 4294967276u, SferaFields::buffer_81);
}

SferaNativeTask SferaFunctions::wp_axe1_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_606b6da7_body(std::move(c), std::move(args), SferaFunctions::wp_axe1_UseOff);
}

SferaMbcValue SferaFunctions::wp_axe1_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_869d600d_body(std::move(c), args, SferaFunctions::wp_axe1_UseOff);
}

SferaMbcValue SferaFunctions::wp_axe1_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_51d953eb_body(std::move(c), args, SferaFunctions::wp_axe1_UseOwner, SferaFunctions::wp_axe1_UseWith);
}

SferaMbcValue SferaFunctions::wp_axe1_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_fef98b01_body(std::move(c), args, SferaFunctions::wp_axe1_PullOut);
}

SferaNativeTask SferaFunctions::wp_axe1_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_aaa013db_body(std::move(c), std::move(args), SferaFunctions::wp_axe1_Use, SferaFunctions::wp_axe1_UseOff);
}

SferaMbcValue SferaFunctions::wp_axe1_PullOut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PullOut_a9e0a32b_body(std::move(c), args, SferaFields::buffer_306, 17u);
}

SferaMbcValue SferaFunctions::wp_axe1_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_9066b1cf_body(std::move(c), args, 18u, 19u);
}

SferaMbcValue SferaFunctions::wp_axe1_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOff_1f1a0acb_body(std::move(c), args, SferaFields::buffer_309, SferaFields::buffer_310, SferaFields::buffer_311,
        21u);
}

SferaMbcValue SferaFunctions::shop_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 68u);
}

SferaMbcValue SferaFunctions::shop_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_56750d0a_body(std::move(c), args, 58u, SferaFields::integer_218, SferaFields::reference_243,
        SferaFields::integer_240, 75u, SferaFields::buffer_272, 300u, 4294967221u, SferaFields::buffer_269, SferaFields::integer_244,
        SferaFields::buffer_270, SferaFields::buffer_271, 52u, SferaFields::integer_241, SferaFields::buffer_245, SferaFields::integer_200,
        SferaFields::integer_242, SferaFields::reference_219, SferaFunctions::shop_FlyWeapon);
}

SferaMbcValue SferaFunctions::shop_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 84u);
}

SferaMbcValue SferaFunctions::shop_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 80u, 81u, SferaFields::buffer_83, 86u);
}

SferaMbcValue SferaFunctions::shop_Main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_Camera_stop_body(std::move(c), args, SferaFields::integer_182, 265u);
}

SferaMbcValue SferaFunctions::shop_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_4da80933_body(std::move(c), args, SferaFields::integer_215_at_7, SferaFields::reference_345);
}

SferaNativeTask SferaFunctions::wp_arbalest1_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_606b6da7_body(std::move(c), std::move(args), SferaFunctions::wp_arbalest1_UseOff);
}

SferaMbcValue SferaFunctions::wp_arbalest1_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_869d600d_body(std::move(c), args, SferaFunctions::wp_arbalest1_UseOff);
}

SferaMbcValue SferaFunctions::wp_arbalest1_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_fef98b01_body(std::move(c), args, SferaFunctions::wp_arbalest1_PullOut);
}

SferaMbcValue SferaFunctions::wp_arbalest1_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_d03707f6_body(std::move(c), args, 48u, SferaFields::buffer_305, SferaFields::buffer_306,
        SferaFields::buffer_307, 13u, SferaFields::buffer_308);
}

SferaMbcValue SferaFunctions::wp_arbalest1_PullOut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PullOut_a9e0a32b_body(std::move(c), args, SferaFields::buffer_311, 13u);
}

SferaMbcValue SferaFunctions::wp_arbalest1_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOff_1f1a0acb_body(std::move(c), args, SferaFields::buffer_312, SferaFields::buffer_313, SferaFields::buffer_314,
        16u);
}

SferaMbcValue SferaFunctions::virus_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_body(std::move(c), args, 49u, 50u, SferaFields::buffer_50, SferaFields::buffer_51, SferaFields::integer_53,
        SferaFields::buffer_60, 51u, SferaFields::buffer_61, 52u, SferaFields::buffer_54, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::virus_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 53u, SferaFields::integer_86, SferaFields::integer_42, SferaFields::integer_87,
        50u, SferaFields::integer_88, SferaFields::reference_89, SferaFields::buffer_90, SferaFields::integer_91, SferaFields::integer_43,
        47u, 48u);
}

SferaMbcValue SferaFunctions::virus_GetModifiers(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_virus_GetModifiers_body(std::move(c), args, SferaFields::buffer_44, 56u);
}

SferaMbcValue SferaFunctions::virus_GetModifs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_virus_GetModifiers_body(std::move(c), args, SferaFields::buffer_39, 32u);
}

SferaMbcValue SferaFunctions::license_hr_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_37be24d5_body(std::move(c), args, SferaFunctions::license_hr_UseOwner);
}

SferaNativeTask SferaFunctions::license_hr_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_ac62c630_body(std::move(c), std::move(args), SferaFunctions::license_hr_Use);
}

SferaMbcValue SferaFunctions::license_hr_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_05e952b4_body(std::move(c), args, SferaFunctions::license_hr_AddInfo);
}

SferaMbcValue SferaFunctions::license_hr_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_c7bed929_body(std::move(c), args, 61u, 94u);
}

SferaMbcValue SferaFunctions::license_hr_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_body(std::move(c), args, SferaFields::reference_242);
}

SferaMbcValue SferaFunctions::specab_ha_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 75u);
}

SferaMbcValue SferaFunctions::specab_ha_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_body(std::move(c), args, SferaFields::integer_0_at_9, 17u, SferaFields::buffer_36, SferaFields::buffer_37,
        SferaFields::buffer_38, SferaFields::buffer_39, SferaFields::buffer_40, SferaFields::buffer_41);
}

SferaMbcValue SferaFunctions::specab_ha_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_e0a993c7_body(std::move(c), args, 65u, SferaFields::integer_215, SferaFields::integer_203,
        SferaFields::integer_216, 59u, SferaFields::integer_217, SferaFields::reference_218, SferaFields::buffer_219,
        SferaFields::integer_220, SferaFields::integer_184, 52u, 53u, 54u);
}

SferaMbcValue SferaFunctions::formula_use_is_stack_use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_is_stack_use_f003d3d6_body(std::move(c), args, SferaFields::integer_93_at_12);
}

SferaMbcValue SferaFunctions::formula_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 38u, SferaFields::integer_61, SferaFields::integer_36, SferaFields::integer_63,
        49u, SferaFields::integer_64, SferaFields::reference_65, SferaFields::buffer_66, SferaFields::integer_91, SferaFields::integer_38,
        17u, 18u);
}

SferaMbcValue SferaFunctions::formula_FCls(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_231, 28u, 0u);
}

SferaMbcValue SferaFunctions::token_pr_cpy_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_06611310_body(std::move(c), args, SferaFunctions::token_pr_cpy_UseOwner);
}

SferaMbcValue SferaFunctions::token_pr_cpy_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_398d065f_body(std::move(c), args, SferaFields::reference_246_at_14, SferaFields::integer_48,
        SferaFields::buffer_247, SferaFields::buffer_32, 20u, SferaFields::buffer_248, 5u);
}

SferaMbcValue SferaFunctions::token_pr_cpy_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_6f891cc9_body(std::move(c), args, SferaFields::integer_46_at_18);
}

SferaMbcValue SferaFunctions::al_metal_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_716186f6_body(std::move(c), args, 45u, SferaFields::buffer_185, 3u, SferaFields::integer_35,
        SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::al_metal_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_185_at_3, SferaFields::integer_200);
}

SferaNativeTask SferaFunctions::al_metal_Main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Main_body(std::move(c), std::move(args), 40u, 5u);
}

SferaMbcValue SferaFunctions::scroll_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_042b69ba_body(std::move(c), args, SferaFields::reference_256, SferaFields::buffer_257,
        SferaFields::buffer_258, 57u, 92u, SferaFields::buffer_259, SferaFields::buffer_260);
}

SferaMbcValue SferaFunctions::scroll_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_6a9e1c1e_body(std::move(c), args, SferaFields::integer_260_at_11, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263, SferaFields::buffer_264, 45u);
}

SferaMbcValue SferaFunctions::fb1_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 11u, 13u);
}

SferaNativeTask SferaFunctions::fb1_Server(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Server_accf726a_body(std::move(c), std::move(args), 1086324736u);
}

SferaMbcValue SferaFunctions::fb1_EKill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_Camera_stop_body(std::move(c), args, SferaFields::integer_6, 1u);
}

SferaNativeTask SferaFunctions::monster_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_d1eccf3b_body(std::move(c), std::move(args), SferaFunctions::crt02_Use);
}

SferaNativeTask SferaFunctions::monster_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_00d2b32e_body(std::move(c), std::move(args), 3u, SferaFunctions::cs_guard_ShowHlth);
}

SferaMbcValue SferaFunctions::door1_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 50u, SferaFields::integer_194, SferaFields::integer_63,
        SferaFields::integer_195, 46u, SferaFields::integer_196, SferaFields::reference_197, SferaFields::buffer_198,
        SferaFields::integer_64, SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::vn_cryst_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_d03707f6_body(std::move(c), args, 40u, SferaFields::buffer_198, SferaFields::buffer_200,
        SferaFields::buffer_203, 12u, SferaFields::buffer_204);
}

SferaMbcValue SferaFunctions::vn_ret_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_dba28d1d_body(std::move(c), args, SferaFields::reference_47_at_4, SferaFields::integer_82,
        SferaFields::buffer_50, 10u, 10u);
}

SferaMbcValue SferaFunctions::specab_ga_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_eb82aad4_body(std::move(c), args, 87u, 88u, 89u, 27u, SferaFields::buffer_205);
}

SferaMbcValue SferaFunctions::jw_diamond_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_0865b773_body(std::move(c), args, SferaFunctions::bank_AddInfo);
}

SferaNativeTask SferaFunctions::vir1027_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 11u);
}

SferaNativeTask SferaFunctions::vir1043_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 17u);
}

SferaNativeTask SferaFunctions::vir1018_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 7u);
}

SferaMbcValue SferaFunctions::item_bead_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 73u);
}
