#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::cs_chest_halt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_halt_body(std::move(c), args, 4u, 5u);
}

SferaMbcValue SferaFunctions::cs_chest_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 7u);
}

SferaMbcValue SferaFunctions::cs_chest_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 9u, 64u);
}

SferaMbcValue SferaFunctions::cs_chest_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::cs_chest_InitObj);
}

SferaMbcValue SferaFunctions::cs_chest_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 35u, SferaFields::buffer_201, 10u);
}

SferaMbcValue SferaFunctions::cs_chest_dnts(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_201_at_10, SferaFields::integer_199);
}

SferaMbcValue SferaFunctions::cs_chest_Effect(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Effect_body(std::move(c), args, SferaFields::integer_211_at_4);
}

SferaMbcValue SferaFunctions::cs_chest_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_77c2afeb_body(std::move(c), args, 3u, SferaFields::reference_87, SferaFields::integer_4,
        SferaFields::integer_63, SferaFields::integer_64, SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::cs_chest_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_97811cb2_body(std::move(c), args, SferaFunctions::cs_chest_UseOwner);
}

SferaMbcValue SferaFunctions::cs_chest_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_171, 296u, SferaFields::buffer_172, SferaFields::integer_85);
}

SferaMbcValue SferaFunctions::cs_chest_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 48u, SferaFields::integer_233_at_18, SferaFields::integer_63,
        SferaFields::integer_234, 50u, SferaFields::integer_235, SferaFields::reference_236, SferaFields::buffer_237,
        SferaFields::integer_64, SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::cs_chest_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 49u, 50u, SferaFields::reference_238, SferaFields::integer_3,
        SferaFields::buffer_195, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_196, SferaFields::buffer_197,
        SferaFields::buffer_198, 5u, 56u, SferaFields::buffer_202, SferaFields::buffer_247, SferaFields::buffer_182,
        SferaFields::integer_193, SferaFields::integer_194, SferaFields::reference_242, SferaFields::buffer_203,
        SferaFields::reference_241, SferaFields::buffer_204, SferaFields::reference_243, SferaFields::buffer_205,
        SferaFields::reference_244, SferaFields::buffer_206, SferaFields::reference_245, SferaFields::reference_246,
        SferaFields::buffer_214, SferaFields::buffer_215, SferaFields::buffer_216, SferaFields::buffer_217, SferaFields::real_239,
        SferaFields::integer_61, SferaFields::real_240, 3000000u, SferaFields::buffer_219, SferaFields::buffer_220, 51u, 52u,
        SferaFields::buffer_221, SferaFields::buffer_222, SferaFields::buffer_224, SferaFields::buffer_223, SferaFields::buffer_225,
        SferaFields::buffer_226, SferaFields::buffer_227);
}

SferaMbcValue SferaFunctions::cs_chest_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 17u, SferaFields::buffer_54, SferaFields::buffer_80, SferaFields::buffer_81, 9u,
        0u);
}

SferaMbcValue SferaFunctions::cs_chest_CheckIndex(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckIndex_body(std::move(c), args, SferaFields::integer_53_at_7);
}

SferaMbcValue SferaFunctions::cs_chest_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_248, 57u, SferaFields::reference_249, 33u,
        SferaFields::buffer_171, 296u, 4294967222u, SferaFields::buffer_172);
}

SferaMbcValue SferaFunctions::cs_chest_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_c06a4fe6_body(std::move(c), args, 58u, SferaFields::integer_250, 59u, 33u, SferaFields::buffer_171, 296u,
        4294967222u, SferaFields::integer_251, 60u, SferaFields::buffer_252, 74u, SferaFunctions::cs_chest_openSlot,
        SferaFunctions::cs_chest_CheckWght);
}

SferaMbcValue SferaFunctions::cs_chest_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 61u, SferaFields::integer_253, 74u, SferaFields::integer_254,
        SferaFields::buffer_171, 296u, 4294967222u, SferaFields::integer_255);
}

SferaMbcValue SferaFunctions::cs_chest_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 62u, SferaFields::integer_256, 74u, SferaFields::integer_257,
        SferaFields::buffer_171, 296u, 4294967222u);
}

SferaMbcValue SferaFunctions::cs_chest_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 63u, SferaFields::integer_174, SferaFields::integer_258, 74u, 64u,
        SferaFields::buffer_171, 296u, 4294967222u);
}

SferaMbcValue SferaFunctions::cs_chest_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_ae2aa720_body(std::move(c), args, 65u, SferaFields::integer_174, 66u, 67u, SferaFields::buffer_259, 68u,
        70u, SferaFields::integer_259_at_8, 74u, 69u, SferaFields::buffer_171, 296u, 4294967222u, SferaFields::buffer_260,
        SferaFields::buffer_261, 71u, 74u, 75u, 76u, SferaFields::buffer_262, 77u, SferaFields::buffer_263, SferaFields::buffer_265,
        SferaFields::buffer_263_at_12, SferaFields::buffer_266, SferaFields::buffer_264, SferaFields::buffer_267, SferaFields::buffer_268,
        SferaFields::buffer_269, SferaFields::buffer_270, 78u, SferaFields::buffer_271, SferaFunctions::cs_chest_TestIt);
}

SferaMbcValue SferaFunctions::cs_chest_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_17921366_body(std::move(c), args, SferaFields::integer_271_at_8, 3000000u);
}

SferaMbcValue SferaFunctions::cs_chest_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_0, 74u, SferaFields::buffer_171, 296u, 4294967222u,
        SferaFields::buffer_172);
}

SferaMbcValue SferaFunctions::cs_chest_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 33u, SferaFields::integer_62, 74u, SferaFields::buffer_171, 296u,
        4294967222u, SferaFields::buffer_172, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::cs_chest_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 41u, 33u, SferaFields::integer_66, 74u, SferaFields::buffer_171, 296u,
        4294967222u, SferaFields::buffer_172);
}

SferaMbcValue SferaFunctions::cs_chest_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 74u);
}

SferaMbcValue SferaFunctions::cs_chest_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_83, 74u, SferaFields::buffer_171, 296u, 4294967222u);
}

SferaMbcValue SferaFunctions::cs_chest_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_84, 74u, SferaFields::buffer_173, 296u, 4294967222u);
}

SferaMbcValue SferaFunctions::cs_chest_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_86, SferaFields::integer_186, 74u, SferaFields::buffer_171,
        296u, 4294967222u);
}

SferaMbcValue SferaFunctions::cs_chest_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_187, 74u, SferaFields::buffer_171, 296u, 4294967222u);
}

SferaMbcValue SferaFunctions::cs_chest_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_12088b0e_body(std::move(c), args, 4u, SferaFields::buffer_213, 41u, SferaFunctions::bank_isGxpItem);
}

SferaMbcValue SferaFunctions::cs_chest_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_116adf93_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_272,
        SferaFields::reference_273, 0u, SferaFields::reference_188, SferaFields::buffer_191, 221u, SferaFields::buffer_192, 2u,
        SferaFields::reference_190, SferaFields::reference_189);
}

SferaMbcValue SferaFunctions::ct_chest7_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_196, 160u, SferaFields::buffer_188, SferaFields::integer_85);
}

SferaNativeTask SferaFunctions::ct_chest7_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_3738afb9_body(std::move(c), std::move(args), 5u, SferaFields::integer_191, SferaFields::reference_204,
        SferaFields::integer_192, SferaFields::integer_203, SferaFields::buffer_205, SferaFields::buffer_86, 47u, 40u,
        SferaFields::buffer_196, 160u, 4294967256u, SferaFields::buffer_188, 47u, SferaFunctions::ct_chest1_Use,
        SferaFunctions::ct_chest7_sendslot);
}

SferaMbcValue SferaFunctions::ct_chest7_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 41u, 46u, SferaFields::reference_187, SferaFields::integer_3,
        SferaFields::buffer_219, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_220, SferaFields::buffer_221,
        SferaFields::buffer_222, 51u, 50u, SferaFields::buffer_223, SferaFields::buffer_215, SferaFields::buffer_216,
        SferaFields::integer_217, SferaFields::integer_218, SferaFields::reference_211, SferaFields::buffer_224,
        SferaFields::reference_210, SferaFields::buffer_225, SferaFields::reference_212, SferaFields::buffer_226,
        SferaFields::reference_213, SferaFields::buffer_227, SferaFields::reference_214, SferaFields::reference_193,
        SferaFields::buffer_228, SferaFields::buffer_229, SferaFields::buffer_230, SferaFields::buffer_231, SferaFields::real_206,
        SferaFields::integer_61, SferaFields::real_209, 750000u, SferaFields::buffer_232, SferaFields::buffer_233, 48u, 49u,
        SferaFields::buffer_234, SferaFields::buffer_235, SferaFields::buffer_237, SferaFields::buffer_236, SferaFields::buffer_238,
        SferaFields::buffer_239, SferaFields::buffer_240);
}

SferaMbcValue SferaFunctions::ct_chest7_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_241, 52u, SferaFields::reference_242, 47u,
        SferaFields::buffer_196, 160u, 4294967256u, SferaFields::buffer_188);
}

SferaMbcValue SferaFunctions::ct_chest7_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_c06a4fe6_body(std::move(c), args, 56u, SferaFields::integer_243, 57u, 47u, SferaFields::buffer_196, 160u,
        4294967256u, SferaFields::integer_244, 58u, SferaFields::buffer_245, 40u, SferaFunctions::ct_chest7_openSlot,
        SferaFunctions::ct_chest7_CheckWght);
}

SferaMbcValue SferaFunctions::ct_chest7_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 59u, SferaFields::integer_246, 40u, SferaFields::integer_247,
        SferaFields::buffer_196, 160u, 4294967256u, SferaFields::integer_248);
}

SferaMbcValue SferaFunctions::ct_chest7_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 60u, SferaFields::integer_249, 40u, SferaFields::integer_250,
        SferaFields::buffer_196, 160u, 4294967256u);
}

SferaMbcValue SferaFunctions::ct_chest7_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 61u, SferaFields::integer_189, SferaFields::integer_251, 40u, 62u,
        SferaFields::buffer_196, 160u, 4294967256u);
}

SferaMbcValue SferaFunctions::ct_chest7_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_ae2aa720_body(std::move(c), args, 63u, SferaFields::integer_189, 64u, 65u, SferaFields::buffer_252, 66u,
        68u, SferaFields::integer_252_at_8, 40u, 67u, SferaFields::buffer_196, 160u, 4294967256u, SferaFields::buffer_253,
        SferaFields::buffer_254, 69u, 70u, 71u, 72u, SferaFields::buffer_255, 73u, SferaFields::buffer_256, SferaFields::buffer_258,
        SferaFields::buffer_256_at_12, SferaFields::buffer_259, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263, 74u, SferaFields::buffer_264, SferaFunctions::ct_chest7_TestIt);
}

SferaMbcValue SferaFunctions::ct_chest7_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_17921366_body(std::move(c), args, SferaFields::integer_264_at_8, 750000u);
}

SferaMbcValue SferaFunctions::ct_chest7_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_265, 40u, SferaFields::buffer_196, 160u,
        4294967256u, SferaFields::buffer_188);
}

SferaMbcValue SferaFunctions::ct_chest7_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 47u, SferaFields::integer_266, 40u, SferaFields::buffer_196, 160u,
        4294967256u, SferaFields::buffer_188, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::ct_chest7_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 75u, 47u, SferaFields::integer_267, 40u, SferaFields::buffer_196, 160u,
        4294967256u, SferaFields::buffer_188);
}

SferaMbcValue SferaFunctions::ct_chest7_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 40u);
}

SferaMbcValue SferaFunctions::ct_chest7_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_268, 40u, SferaFields::buffer_196, 160u, 4294967256u);
}

SferaMbcValue SferaFunctions::ct_chest7_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_269, 40u, SferaFields::buffer_54, 160u, 4294967256u);
}

SferaMbcValue SferaFunctions::ct_chest7_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_270, SferaFields::integer_271, 40u, SferaFields::buffer_196,
        160u, 4294967256u);
}

SferaMbcValue SferaFunctions::ct_chest7_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_272, 40u, SferaFields::buffer_196, 160u, 4294967256u);
}

SferaMbcValue SferaFunctions::ct_chest7_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_116adf93_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_190,
        SferaFields::reference_194, 32u, SferaFields::reference_195, SferaFields::buffer_200, 24u, SferaFields::buffer_202, 3u,
        SferaFields::reference_198, SferaFields::reference_197);
}

SferaMbcValue SferaFunctions::npc14_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 64u);
}

SferaNativeTask SferaFunctions::npc14_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_b95468e9_body(std::move(c), std::move(args), SferaFields::reference_332, 75u, 127u);
}

SferaNativeTask SferaFunctions::npc14_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_f1cf35c1_body(std::move(c), std::move(args), SferaFunctions::npc14_UseOff);
}

SferaMbcValue SferaFunctions::npc14_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_f16e3b4b_body(std::move(c), args, SferaFunctions::npc14_UseOff);
}

SferaMbcValue SferaFunctions::npc14_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_333d080e_body(std::move(c), args, SferaFunctions::npc14_UseOwner);
}

SferaMbcValue SferaFunctions::npc14_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_b4e2eadb_body(std::move(c), args, SferaFields::buffer_269, 300u, SferaFields::buffer_270,
        SferaFields::buffer_272, SferaFields::integer_334, 75u, SferaFields::reference_332, SferaFields::buffer_273,
        SferaFields::buffer_271);
}

SferaMbcValue SferaFunctions::npc14_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_56750d0a_body(std::move(c), args, 93u, SferaFields::integer_264, SferaFields::reference_275,
        SferaFields::integer_266, 75u, SferaFields::buffer_272, 300u, 4294967221u, SferaFields::buffer_269, SferaFields::integer_276,
        SferaFields::buffer_270, SferaFields::buffer_271, 48u, SferaFields::integer_267, SferaFields::buffer_277, SferaFields::integer_257,
        SferaFields::integer_274, SferaFields::reference_265, SferaFunctions::npc14_FlyWeapon);
}

SferaMbcValue SferaFunctions::npc14_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_ee7fcfe6_body(std::move(c), args, 3u, SferaFields::buffer_215, SferaFields::buffer_216,
        SferaFields::buffer_217, 0u, SferaFields::buffer_218, SferaFunctions::npc14_ShowHlth);
}

SferaMbcValue SferaFunctions::npc14_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 72u);
}

SferaMbcValue SferaFunctions::npc14_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 94u, 95u, SferaFields::buffer_83, 74u);
}

SferaMbcValue SferaFunctions::npc14_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_57e7a4f4_body(std::move(c), args, SferaFields::integer_335, 130u, SferaFields::reference_336,
        SferaFields::buffer_272, 300u, 4294967221u, SferaFields::buffer_269);
}

SferaMbcValue SferaFunctions::npc14_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_694e7ae7_body(std::move(c), args, 106u, SferaFields::integer_303, 107u, 103u, SferaFields::buffer_220, 300u,
        4294967221u, SferaFields::integer_304, 108u, SferaFields::buffer_305, 75u, SferaFunctions::npc14_openSlot);
}

SferaMbcValue SferaFunctions::npc14_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_4816c116_body(std::move(c), args, 113u, SferaFields::integer_302, 114u, 115u, SferaFields::buffer_312,
        116u, 118u, SferaFields::integer_312_at_8, 75u, 117u, SferaFields::buffer_220, 300u, 4294967221u, SferaFields::buffer_313,
        SferaFields::buffer_314, 119u, 120u, 121u, 122u, SferaFields::buffer_315, 123u, SferaFields::buffer_316, SferaFields::buffer_318,
        SferaFields::buffer_316_at_12, SferaFields::buffer_319, SferaFields::buffer_317, SferaFields::buffer_320, SferaFields::buffer_321,
        SferaFields::buffer_322, SferaFields::buffer_323, 124u, SferaFunctions::npc14_TestIt);
}

SferaMbcValue SferaFunctions::npc14_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_337, SferaFields::reference_338, SferaFields::reference_339,
        SferaFields::reference_340, SferaFields::buffer_343, 9u, SferaFields::reference_342, SferaFields::reference_341);
}

SferaMbcValue SferaFunctions::npc14_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_da1ada41_body(std::move(c), args, 7u, 97u, 7u);
}

SferaMbcValue SferaFunctions::npc14_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOff_16bdcf23_body(std::move(c), args, 97u, SferaFields::buffer_280, 7u);
}

SferaMbcValue SferaFunctions::ct_sac_s_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_body(std::move(c), args, SferaFields::reference_66, 61u, SferaFields::integer_65, 4u,
        SferaFields::buffer_229, 16u, 4294967292u, SferaFunctions::ct_mbag_sendslot);
}

SferaMbcValue SferaFunctions::ct_sac_s_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 47u, 49u, SferaFields::reference_88, SferaFields::integer_3,
        SferaFields::buffer_233, SferaFields::integer_183, SferaFields::integer_244, SferaFields::reference_261, SferaFields::buffer_262,
        SferaFields::buffer_263, 82u, 52u, SferaFields::buffer_264, SferaFields::buffer_247, SferaFields::buffer_258,
        SferaFields::integer_259, SferaFields::integer_260, SferaFields::reference_196, SferaFields::buffer_265,
        SferaFields::reference_190, SferaFields::buffer_266, SferaFields::reference_203, SferaFields::buffer_267,
        SferaFields::reference_204, SferaFields::buffer_268, SferaFields::reference_205, SferaFields::reference_206,
        SferaFields::buffer_269, SferaFields::buffer_270, SferaFields::buffer_271, SferaFields::buffer_272, SferaFields::real_89,
        SferaFields::integer_250, SferaFields::real_186, 200u, SferaFields::buffer_273, SferaFields::buffer_274, 50u, 51u,
        SferaFields::buffer_275, SferaFields::buffer_276, SferaFields::buffer_278, SferaFields::buffer_277, SferaFields::buffer_279,
        SferaFields::buffer_280, SferaFields::buffer_281);
}

SferaMbcValue SferaFunctions::ct_sac_s_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_202, 62u, 61u, SferaFields::buffer_229, 16u, 4294967292u,
        SferaFields::integer_232, 63u, SferaFields::buffer_234, 4u, SferaFunctions::bank_openSlot, SferaFunctions::ct_sac_s_CheckWght);
}

SferaMbcValue SferaFunctions::ct_sac_s_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 17u, SferaFields::integer_230, 68u, 69u, SferaFields::buffer_239, 72u,
        75u, SferaFields::integer_239_at_8, 4u, 74u, SferaFields::buffer_229, 16u, 4294967292u, SferaFields::buffer_240,
        SferaFields::buffer_245, 76u, 77u, 78u, 79u, SferaFields::buffer_246, 80u, SferaFields::buffer_248, SferaFields::buffer_252,
        SferaFields::buffer_248_at_12, SferaFields::buffer_253, SferaFields::buffer_249, SferaFields::buffer_254, SferaFields::buffer_255,
        SferaFields::buffer_256, SferaFields::buffer_257, 81u, SferaFields::buffer_182, SferaFunctions::ct_sac_s_TestIt);
}

SferaMbcValue SferaFunctions::ct_sac_s_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 200u);
}

SferaMbcValue SferaFunctions::ct_sac_s_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 65u, 66u, SferaFields::integer_235, 4u, SferaFields::buffer_229, 16u, 4294967292u,
        SferaFields::buffer_231);
}

SferaMbcValue SferaFunctions::ct_sac_s_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 67u, 61u, SferaFields::integer_236, 4u, SferaFields::buffer_229, 16u, 4294967292u,
        SferaFields::buffer_231);
}

SferaMbcValue SferaFunctions::ct_sac_s_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_237, 61u, SferaFields::integer_238, 4u,
        SferaFields::buffer_229, 16u, 4294967292u, SferaFields::buffer_231);
}

SferaMbcValue SferaFunctions::ct_sac_s_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ar_ring_SndUser_body(std::move(c), args, SferaFields::reference_90_at_5);
}

SferaNativeTask SferaFunctions::npc_guilder_CheckUseDist(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_4ec3337b_body(std::move(c), std::move(args), SferaFunctions::npc_guilder_UseOff);
}

SferaMbcValue SferaFunctions::npc_guilder_CheckUseDist_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckUseDist_stop_c61b2854_body(std::move(c), args, SferaFunctions::npc_guilder_UseOff);
}

SferaNativeTask SferaFunctions::npc_guilder_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_521c60b3_body(std::move(c), std::move(args), 48u, SferaFields::buffer_211, SferaFields::buffer_212, 12u,
        SferaFields::buffer_252, SferaFields::integer_253, SferaFields::buffer_254, SferaFunctions::crt02_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_guilder_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_694e7ae7_body(std::move(c), args, 106u, SferaFields::integer_303, 107u, 103u, SferaFields::buffer_220, 300u,
        4294967221u, SferaFields::integer_304, 108u, SferaFields::buffer_305, 75u, SferaFunctions::npc_guilder_openSlot);
}

SferaMbcValue SferaFunctions::npc_guilder_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_4816c116_body(std::move(c), args, 113u, SferaFields::integer_302, 114u, 115u, SferaFields::buffer_312,
        116u, 118u, SferaFields::integer_312_at_8, 75u, 117u, SferaFields::buffer_220, 300u, 4294967221u, SferaFields::buffer_313,
        SferaFields::buffer_314, 119u, 120u, 121u, 122u, SferaFields::buffer_315, 123u, SferaFields::buffer_316, SferaFields::buffer_318,
        SferaFields::buffer_316_at_12, SferaFields::buffer_319, SferaFields::buffer_317, SferaFields::buffer_320, SferaFields::buffer_321,
        SferaFields::buffer_322, SferaFields::buffer_323, 124u, SferaFunctions::npc_guilder_TestIt);
}

SferaMbcValue SferaFunctions::npc_guilder_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_255, SferaFields::reference_336, SferaFields::reference_337,
        SferaFields::reference_338, SferaFields::buffer_341, 3u, SferaFields::reference_340, SferaFields::reference_339);
}

SferaMbcValue SferaFunctions::npc_guilder_AddUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddUser_body(std::move(c), args, SferaFields::reference_223, SferaFields::reference_221, 59u, 52u,
        SferaFields::reference_224, SferaFields::buffer_222, SferaFields::integer_225, 720u);
}

SferaMbcValue SferaFunctions::npc_guilder_SendPress(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_SetParent_body(std::move(c), args, SferaFields::integer_346_at_16, SferaFields::buffer_132, 256u, 4u, 7u);
}

SferaMbcValue SferaFunctions::npc_guilder_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ar_ring_SndUser_body(std::move(c), args, SferaFields::reference_345_at_6);
}

SferaMbcValue SferaFunctions::npc_guilder_UseOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 121u);
}

SferaMbcValue SferaFunctions::ct_ubag_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 5u, 72u, SferaFields::reference_0, SferaFields::integer_200,
        SferaFields::buffer_276, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_277, SferaFields::buffer_278,
        SferaFields::buffer_279, 60u, 17u, SferaFields::buffer_280, SferaFields::buffer_272, SferaFields::buffer_273,
        SferaFields::integer_274, SferaFields::integer_275, SferaFields::reference_267, SferaFields::buffer_281,
        SferaFields::reference_233, SferaFields::buffer_282, SferaFields::reference_268, SferaFields::buffer_264,
        SferaFields::reference_269, SferaFields::buffer_246, SferaFields::reference_270, SferaFields::reference_271,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_62,
        SferaFields::integer_250, SferaFields::real_90, 1000000u, SferaFields::buffer_254, SferaFields::buffer_255, 73u, 3u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_ubag_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 61u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_229, 32u, 4294967288u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 8u, SferaFunctions::bank_openSlot, SferaFunctions::ct_ubag_CheckWght);
}

SferaMbcValue SferaFunctions::ct_ubag_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 4u, SferaFields::integer_230, 62u, 78u, SferaFields::buffer_288, 79u,
        81u, SferaFields::integer_288_at_8, 8u, 80u, SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_289,
        SferaFields::buffer_290, 82u, 83u, 84u, 85u, SferaFields::buffer_291, 86u, SferaFields::buffer_292, SferaFields::buffer_294,
        SferaFields::buffer_292_at_12, SferaFields::buffer_295, SferaFields::buffer_293, SferaFields::buffer_298, SferaFields::buffer_300,
        SferaFields::buffer_301, SferaFields::buffer_302, 87u, SferaFields::buffer_182, SferaFunctions::ct_ubag_TestIt);
}

SferaMbcValue SferaFunctions::ct_ubag_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 1000000u);
}

SferaMbcValue SferaFunctions::ct_gbag_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_82, SferaFields::integer_184, 3u,
        SferaFields::integer_189, 24u, SferaFields::buffer_233, 96u, 4294967272u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::ct_barn_sendslot);
}

SferaNativeTask SferaFunctions::ct_gbag_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_beb84fb0_body(std::move(c), std::move(args), SferaFields::integer_190, SferaFields::reference_280,
        SferaFields::integer_199, SferaFields::integer_201, SferaFields::buffer_295, SferaFields::buffer_298, 24u, SferaFields::buffer_233,
        96u, 4294967272u, SferaFields::buffer_81, 3u, SferaFunctions::ct_barn_sendslot);
}

SferaMbcValue SferaFunctions::ct_gbag_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 17u, SferaFields::integer_202, 57u, 3u, SferaFields::buffer_233, 96u, 4294967272u,
        SferaFields::integer_218, 58u, SferaFields::buffer_219, 24u, SferaFunctions::bank_openSlot, SferaFunctions::ct_bag_CheckWght);
}

SferaMbcValue SferaFunctions::ct_gbag_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 67u, SferaFields::integer_234, 68u, 69u, SferaFields::buffer_235, 79u,
        81u, SferaFields::integer_235_at_8, 24u, 80u, SferaFields::buffer_233, 96u, 4294967272u, SferaFields::buffer_236,
        SferaFields::buffer_270, 82u, 83u, 84u, 85u, SferaFields::buffer_271, 86u, SferaFields::buffer_272, SferaFields::buffer_274,
        SferaFields::buffer_272_at_12, SferaFields::buffer_275, SferaFields::buffer_273, SferaFields::buffer_276, SferaFields::buffer_277,
        SferaFields::buffer_278, SferaFields::buffer_279, 87u, SferaFields::buffer_182, SferaFunctions::ct_gbag_TestIt);
}

SferaMbcValue SferaFunctions::telep1_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 10u, 66u);
}

SferaMbcValue SferaFunctions::telep1_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_672f849d_body(std::move(c), args, SferaFunctions::telep1_UseOwner);
}

SferaNativeTask SferaFunctions::telep1_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_bd245d6a_body(std::move(c), std::move(args), SferaFields::integer_83, SferaFields::reference_86,
        SferaFields::integer_84, SferaFields::integer_85, SferaFields::buffer_197, SferaFields::buffer_198, 52u,
        SferaFunctions::telep1_Use);
}

SferaMbcValue SferaFunctions::telep1_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 41u, SferaFields::integer_199, SferaFields::integer_63,
        SferaFields::integer_200, 52u, SferaFields::integer_201, SferaFields::reference_202, SferaFields::buffer_203,
        SferaFields::integer_64, SferaFields::integer_65);
}

SferaNativeTask SferaFunctions::telep1_Cli(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Cli_body(std::move(c), std::move(args), 80u);
}

SferaMbcValue SferaFunctions::telep1_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_d374b741_body(std::move(c), args, SferaFields::integer_5_at_2, SferaFields::buffer_196, 100u, 170u, 100u);
}

SferaMbcValue SferaFunctions::token_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_28e3779b_body(std::move(c), args, SferaFields::integer_152_at_9, SferaFields::integer_31);
}

SferaNativeTask SferaFunctions::token_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_71b7a3a5_body(std::move(c), std::move(args), SferaFunctions::token_UseClient);
}

SferaMbcValue SferaFunctions::token_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::token_CheckPut);
}

SferaMbcValue SferaFunctions::token_UseClient(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseClient_01e86a2a_body(std::move(c), args, SferaFields::reference_201, SferaFields::integer_199,
        SferaFields::buffer_265);
}

SferaMbcValue SferaFunctions::token_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_0f9f3fa3_body(std::move(c), args, SferaFields::buffer_261, 5u, SferaFields::integer_189,
        SferaFields::buffer_262, 7u, SferaFields::integer_82, SferaFields::buffer_263, 4u, SferaFields::integer_41);
}

SferaMbcValue SferaFunctions::token_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_264_at_16);
}

SferaNativeTask SferaFunctions::puppet_bank_WinBank_helper_5442bb6c(SferaNativeContext c,
    std::vector<SferaMbcValue> args)
{
    return sfera_bank_WinBank_helper_5442bb6c_body(std::move(c), std::move(args), SferaFields::integer_62, SferaFields::integer_3,
        SferaFields::buffer_118, SferaFields::real_116_at_9, SferaFields::real_117, 7u, SferaFields::buffer_119, 5u,
        SferaFields::integer_60, SferaFields::integer_61, SferaFields::buffer_119_at_13, SferaFields::buffer_73, SferaFields::buffer_120,
        SferaFields::buffer_121);
}

SferaMbcValue SferaFunctions::puppet_SetddHan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_132_at_15, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::puppet_PuppetTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvTrig_body(std::move(c), args, SferaFields::integer_79, SferaFunctions::puppet_PuppetOn,
        SferaFunctions::inventory_InvOff);
}

SferaMbcValue SferaFunctions::puppet_PuppetOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOn_body(std::move(c), args, SferaFields::integer_79, 9u, 3u);
}

SferaMbcValue SferaFunctions::specab_mb_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_28e3779b_body(std::move(c), args, SferaFields::integer_152_at_8, SferaFields::integer_31);
}

SferaNativeTask SferaFunctions::specab_mb_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_ec757611_body(std::move(c), std::move(args), SferaFields::integer_214, SferaFields::reference_217,
        SferaFields::integer_215, SferaFields::integer_216, SferaFields::buffer_218, SferaFields::buffer_219, 57u);
}

SferaMbcValue SferaFunctions::specab_mb_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_e0a993c7_body(std::move(c), args, 67u, SferaFields::integer_32, SferaFields::integer_203,
        SferaFields::integer_36, 57u, SferaFields::integer_37, SferaFields::reference_62, SferaFields::buffer_80, SferaFields::integer_81,
        SferaFields::integer_184, 52u, 53u, 54u);
}

SferaMbcValue SferaFunctions::wp_axe_boar_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_1b363b1a_body(std::move(c), args, 80u, SferaFields::reference_318, 1u, SferaFields::reference_319,
        SferaFields::integer_317, SferaFields::buffer_320);
}

SferaMbcValue SferaFunctions::wp_axe_boar_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_e9053998_body(std::move(c), args, SferaFields::buffer_324, 8u, SferaFields::integer_311_at_9,
        SferaFields::buffer_325, 4u, SferaFields::integer_317);
}

SferaMbcValue SferaFunctions::wp_axe_boar_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_dba28d1d_body(std::move(c), args, SferaFields::reference_325_at_4, SferaFields::integer_317,
        SferaFields::buffer_326, 14u, 10u);
}

SferaMbcValue SferaFunctions::invalch_SetddHan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_114_at_7, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::invalch_InvTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvTrig_body(std::move(c), args, SferaFields::integer_79, SferaFunctions::invalch_InvOn,
        SferaFunctions::invalch_InvOff);
}

SferaMbcValue SferaFunctions::invalch_InvOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOn_body(std::move(c), args, SferaFields::integer_79, 8u, 3u);
}

SferaMbcValue SferaFunctions::invalch_InvOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 8u);
}

SferaMbcValue SferaFunctions::vn_exp_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_1b363b1a_body(std::move(c), args, 59u, SferaFields::reference_234, 1u, SferaFields::reference_235,
        SferaFields::integer_83, SferaFields::buffer_41);
}

SferaMbcValue SferaFunctions::vn_exp_UseServer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_UseWith_body(std::move(c), args, SferaFields::integer_41_at_6);
}

SferaMbcValue SferaFunctions::vn_exp_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_dba28d1d_body(std::move(c), args, SferaFields::reference_236, SferaFields::integer_83,
        SferaFields::buffer_237, 10u, 10u);
}

SferaMbcValue SferaFunctions::token_s_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::token_s_CheckPut);
}

SferaMbcValue SferaFunctions::token_s_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_e9053998_body(std::move(c), args, SferaFields::buffer_283, 5u, SferaFields::integer_189,
        SferaFields::buffer_284, 7u, SferaFields::integer_82);
}

SferaMbcValue SferaFunctions::token_s_CheckPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_285_at_7);
}

SferaMbcValue SferaFunctions::g_lvlup_license_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_0865b773_body(std::move(c), args, SferaFunctions::g_lvlup_license_AddInfo);
}

SferaMbcValue SferaFunctions::g_lvlup_license_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_c7bed929_body(std::move(c), args, 56u, 95u);
}

SferaMbcValue SferaFunctions::g_lvlup_license_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_body(std::move(c), args, SferaFields::reference_249_at_8);
}

SferaMbcValue SferaFunctions::ct_lab_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 5u, SferaFields::buffer_0, SferaFields::buffer_62, SferaFields::buffer_203, 6u, 0u);
}

SferaMbcValue SferaFunctions::ct_lab_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_d921e1d9_body(std::move(c), args, SferaFields::buffer_197, 6u, SferaFields::integer_54,
        SferaFields::buffer_199, 6u, SferaFields::integer_182);
}

SferaMbcValue SferaFunctions::tournament_IsForceDamager(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsForceDamager_body(std::move(c), args, SferaFields::byte_238_at_22);
}

SferaMbcValue SferaFunctions::tournament_FillBalanceGVG(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FillBalanceGVG_body(std::move(c), args, SferaFunctions::tournament_IsForceDamager);
}

SferaMbcValue SferaFunctions::wp_aroma_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 54u, SferaFields::integer_194, SferaFields::integer_42, SferaFields::integer_195,
        58u, SferaFields::integer_199, SferaFields::reference_197, SferaFields::buffer_203, SferaFields::integer_184,
        SferaFields::integer_43, 46u, 47u);
}

SferaMbcValue SferaFunctions::st_key2_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_e9053998_body(std::move(c), args, SferaFields::buffer_255, 6u, SferaFields::integer_54,
        SferaFields::buffer_256, 6u, SferaFields::integer_182);
}

SferaMbcValue SferaFunctions::monsterq_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SndUser_b27242af_body(std::move(c), args, SferaFields::reference_367_at_5, SferaFields::integer_357);
}

SferaMbcValue SferaFunctions::char_Animating_stop(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_char_Animating_stop_body(std::move(c), args, SferaFields::integer_82, SferaFields::integer_78);
}

SferaMbcValue SferaFunctions::gmsg_SetItemGroup(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_0, SferaFields::integer_4);
}

SferaNativeTask SferaFunctions::fb2_Server(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Server_accf726a_body(std::move(c), std::move(args), 1090728755u);
}

SferaNativeTask SferaFunctions::vir1034_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 13u);
}

SferaNativeTask SferaFunctions::vir1012_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 3u);
}

SferaMbcValue SferaFunctions::monsterh_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_237abbb1_body(std::move(c), args, 0u);
}

SferaMbcValue SferaFunctions::vir1017_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_ebc3160a_body(std::move(c), args, 255u);
}
