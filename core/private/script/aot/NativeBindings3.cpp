#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::ct_chest_pr_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 63u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_97811cb2_body(std::move(c), args, SferaFunctions::ct_chest_pr_UseOwner);
}

SferaMbcValue SferaFunctions::ct_chest_pr_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_54, 128u, SferaFields::buffer_80, SferaFields::integer_85);
}

SferaMbcValue SferaFunctions::ct_chest_pr_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_0d2d5d95_body(std::move(c), args, SferaFields::integer_213_at_18, SferaFields::reference_228);
}

SferaMbcValue SferaFunctions::ct_chest_pr_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 41u, SferaFields::integer_0, SferaFields::integer_63,
        SferaFields::integer_62, 48u, SferaFields::integer_66, SferaFields::reference_83, SferaFields::buffer_84, SferaFields::integer_64,
        SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::ct_chest_pr_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 46u, 47u, SferaFields::reference_229, SferaFields::integer_3,
        SferaFields::buffer_195, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_196, SferaFields::buffer_197,
        SferaFields::buffer_198, 5u, 50u, SferaFields::buffer_202, SferaFields::buffer_238, SferaFields::buffer_182,
        SferaFields::integer_193, SferaFields::integer_194, SferaFields::reference_233, SferaFields::buffer_203,
        SferaFields::reference_232, SferaFields::buffer_204, SferaFields::reference_234, SferaFields::buffer_205,
        SferaFields::reference_235, SferaFields::buffer_206, SferaFields::reference_236, SferaFields::reference_237,
        SferaFields::buffer_214, SferaFields::buffer_215, SferaFields::buffer_216, SferaFields::buffer_217, SferaFields::real_230,
        SferaFields::integer_61, SferaFields::real_231, 600000u, SferaFields::buffer_219, SferaFields::buffer_220, 48u, 49u,
        SferaFields::buffer_221, SferaFields::buffer_222, SferaFields::buffer_224, SferaFields::buffer_223, SferaFields::buffer_225,
        SferaFields::buffer_226, SferaFields::buffer_227);
}

SferaMbcValue SferaFunctions::ct_chest_pr_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 4u, SferaFields::buffer_239, SferaFields::buffer_240, SferaFields::buffer_241, 12u,
        0u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_242, 51u, SferaFields::reference_243, 17u,
        SferaFields::buffer_54, 128u, 4294967264u, SferaFields::buffer_80);
}

SferaMbcValue SferaFunctions::ct_chest_pr_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_d8a2dcca_body(std::move(c), args, 52u, SferaFields::integer_244, 56u, 17u, SferaFields::buffer_54, 128u,
        4294967264u, SferaFields::integer_245, 57u, SferaFields::buffer_246, 32u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::ct_chest_pr_CheckWght);
}

SferaMbcValue SferaFunctions::ct_chest_pr_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 58u, SferaFields::integer_247, 32u, SferaFields::integer_248,
        SferaFields::buffer_54, 128u, 4294967264u, SferaFields::integer_249);
}

SferaMbcValue SferaFunctions::ct_chest_pr_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 59u, SferaFields::integer_250, 32u, SferaFields::integer_251,
        SferaFields::buffer_54, 128u, 4294967264u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 60u, SferaFields::integer_81, SferaFields::integer_252, 32u, 61u,
        SferaFields::buffer_54, 128u, 4294967264u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_29d8322a_body(std::move(c), args, 62u, SferaFields::integer_81, 63u, 64u, SferaFields::buffer_253, 65u,
        67u, SferaFields::integer_253_at_8, 32u, 66u, SferaFields::buffer_54, 128u, 4294967264u, SferaFields::buffer_254,
        SferaFields::buffer_255, 68u, 69u, 70u, 71u, SferaFields::buffer_256, 72u, SferaFields::buffer_257, SferaFields::buffer_259,
        SferaFields::buffer_257_at_12, SferaFields::buffer_260, SferaFields::buffer_258, SferaFields::buffer_261, SferaFields::buffer_262,
        SferaFields::buffer_263, SferaFields::buffer_264, 73u, SferaFields::buffer_265, SferaFunctions::ct_chest_pr_TestIt);
}

SferaMbcValue SferaFunctions::ct_chest_pr_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_17921366_body(std::move(c), args, SferaFields::integer_265_at_8, 600000u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_266, 32u, SferaFields::buffer_54, 128u, 4294967264u,
        SferaFields::buffer_80);
}

SferaMbcValue SferaFunctions::ct_chest_pr_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 17u, SferaFields::integer_267, 32u, SferaFields::buffer_54, 128u,
        4294967264u, SferaFields::buffer_80, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 74u, 17u, SferaFields::integer_268, 32u, SferaFields::buffer_54, 128u,
        4294967264u, SferaFields::buffer_80);
}

SferaMbcValue SferaFunctions::ct_chest_pr_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 32u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_269, 32u, SferaFields::buffer_54, 128u, 4294967264u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_270, 32u, SferaFields::buffer_218, 128u, 4294967264u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_271, SferaFields::integer_272, 32u, SferaFields::buffer_54,
        128u, 4294967264u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_273, 32u, SferaFields::buffer_54, 128u, 4294967264u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_12088b0e_body(std::move(c), args, 75u, SferaFields::buffer_274, 39u, SferaFunctions::bank_isGxpItem);
}

SferaMbcValue SferaFunctions::ct_chest_pr_Main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Main_bc3f8381_body(std::move(c), args, SferaFields::buffer_276, 10u);
}

SferaMbcValue SferaFunctions::ct_chest_pr_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ct_chest_pr_LoadGame_body(std::move(c), args, 14u, SferaFields::buffer_281);
}

SferaMbcValue SferaFunctions::ct_chest_pr_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ct_chest_pr_LoadGame_body(std::move(c), args, 13u, SferaFields::buffer_282);
}

SferaMbcValue SferaFunctions::cs_table_RcvG(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvG_body(std::move(c), args, SferaFields::integer_299, SferaFields::integer_300, SferaFields::integer_301,
        SferaFields::integer_302, SferaFields::integer_305, SferaFields::buffer_307, SferaFields::integer_303, SferaFields::integer_306,
        SferaFields::buffer_308, SferaFields::integer_304);
}

SferaMbcValue SferaFunctions::cs_table_halt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_halt_body(std::move(c), args, 12u, 13u);
}

SferaMbcValue SferaFunctions::cs_table_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 15u);
}

SferaMbcValue SferaFunctions::cs_table_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 17u, 71u);
}

SferaMbcValue SferaFunctions::cs_table_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_60_at_1, SferaFields::integer_91);
}

SferaMbcValue SferaFunctions::cs_table_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_77c2afeb_body(std::move(c), args, 5u, SferaFields::reference_211, SferaFields::integer_200,
        SferaFields::integer_204, SferaFields::integer_205, SferaFields::integer_206);
}

SferaMbcValue SferaFunctions::cs_table_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_207, 20u, SferaFields::buffer_208, SferaFields::integer_213);
}

SferaMbcValue SferaFunctions::cs_table_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 44u, SferaFields::integer_214, SferaFields::integer_204,
        SferaFields::integer_215, 58u, SferaFields::integer_216, SferaFields::reference_217, SferaFields::buffer_218,
        SferaFields::integer_205, SferaFields::integer_206);
}

SferaMbcValue SferaFunctions::cs_table_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_254, 52u, SferaFields::reference_255, 40u,
        SferaFields::buffer_207, 20u, 4294967291u, SferaFields::buffer_208);
}

SferaMbcValue SferaFunctions::cs_table_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 56u, SferaFields::integer_259, 5u, SferaFields::integer_260,
        SferaFields::buffer_207, 20u, 4294967291u, SferaFields::integer_261);
}

SferaMbcValue SferaFunctions::cs_table_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 57u, SferaFields::integer_262, 5u, SferaFields::integer_263,
        SferaFields::buffer_207, 20u, 4294967291u);
}

SferaMbcValue SferaFunctions::cs_table_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 58u, SferaFields::integer_210, SferaFields::integer_264, 5u, 59u,
        SferaFields::buffer_207, 20u, 4294967291u);
}

SferaMbcValue SferaFunctions::cs_table_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_17921366_body(std::move(c), args, SferaFields::integer_182_at_8, 100000u);
}

SferaMbcValue SferaFunctions::cs_table_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_0, 5u, SferaFields::buffer_207, 20u, 4294967291u,
        SferaFields::buffer_208);
}

SferaMbcValue SferaFunctions::cs_table_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 40u, SferaFields::integer_62, 5u, SferaFields::buffer_207, 20u,
        4294967291u, SferaFields::buffer_208, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::cs_table_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 41u, 40u, SferaFields::integer_66, 5u, SferaFields::buffer_207, 20u,
        4294967291u, SferaFields::buffer_208);
}

SferaMbcValue SferaFunctions::cs_table_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 5u);
}

SferaMbcValue SferaFunctions::cs_table_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_83, 5u, SferaFields::buffer_207, 20u, 4294967291u);
}

SferaMbcValue SferaFunctions::cs_table_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_84, 5u, SferaFields::buffer_209, 20u, 4294967291u);
}

SferaMbcValue SferaFunctions::cs_table_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_86, SferaFields::integer_186, 5u, SferaFields::buffer_207, 20u,
        4294967291u);
}

SferaMbcValue SferaFunctions::cs_table_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_187, 5u, SferaFields::buffer_207, 20u, 4294967291u);
}

SferaMbcValue SferaFunctions::cs_table_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_116adf93_body(std::move(c), args, SferaFields::integer_277, SferaFields::reference_278,
        SferaFields::reference_279, 0u, SferaFields::reference_188, SferaFields::buffer_191, 10u, SferaFields::buffer_192, 2u,
        SferaFields::reference_190, SferaFields::reference_189);
}

SferaMbcValue SferaFunctions::cs_table_pUSTATE(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_getLastGVG_body(std::move(c), args, SferaFields::buffer_90, 12u);
}

SferaMbcValue SferaFunctions::cs_table_GetAddrs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetAddrs_body(std::move(c), args, SferaFields::reference_328, SferaFields::reference_329,
        SferaFields::reference_330, SferaFields::reference_331, SferaFields::reference_332, SferaFields::reference_333,
        SferaFields::reference_334, SferaFields::reference_335, SferaFields::reference_336);
}

SferaMbcValue SferaFunctions::cs_table_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_30c23da7_body(std::move(c), args, SferaFields::reference_281_at_7, SferaFields::buffer_282,
        SferaFields::buffer_185, SferaFields::buffer_283, SferaFields::buffer_284, SferaFields::buffer_63);
}

SferaMbcValue SferaFunctions::cs_table_GetCastleNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_cs_table_GetCastleNum_body(std::move(c), args, SferaFields::integer_164, 8000u);
}

SferaMbcValue SferaFunctions::quest2_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_289, SferaFields::integer_184, 99u,
        SferaFields::integer_288, 18u, SferaFields::buffer_284, 72u, 4294967278u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::quest2_sendslot);
}

SferaMbcValue SferaFunctions::quest2_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_284, 72u, SferaFields::buffer_285, SferaFields::integer_290);
}

SferaNativeTask SferaFunctions::quest2_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_c22d77f4_body(std::move(c), std::move(args), 18u, 72u, 4294967278u, SferaFunctions::quest2_sendslot);
}

SferaMbcValue SferaFunctions::quest2_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_300, 100u, SferaFields::reference_301, 99u,
        SferaFields::buffer_284, 72u, 4294967278u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest2_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_ed86e89b_body(std::move(c), args, 72u, 4294967278u, 18u);
}

SferaMbcValue SferaFunctions::quest2_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 104u, SferaFields::integer_305, 18u, SferaFields::integer_306,
        SferaFields::buffer_284, 72u, 4294967278u, SferaFields::integer_307);
}

SferaMbcValue SferaFunctions::quest2_SeekTagInsideNoRecursive(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 105u, SferaFields::integer_308, 18u, SferaFields::integer_309,
        SferaFields::buffer_284, 72u, 4294967278u);
}

SferaMbcValue SferaFunctions::quest2_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 106u, SferaFields::integer_287, SferaFields::integer_310, 18u, 107u,
        SferaFields::buffer_284, 72u, 4294967278u);
}

SferaMbcValue SferaFunctions::quest2_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 108u, 109u, SferaFields::integer_311, 18u, SferaFields::buffer_284, 72u,
        4294967278u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest2_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 110u, 99u, SferaFields::integer_312, 18u, SferaFields::buffer_284, 72u,
        4294967278u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest2_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_313, 99u, SferaFields::integer_314, 18u,
        SferaFields::buffer_284, 72u, 4294967278u, SferaFields::buffer_285);
}

SferaMbcValue SferaFunctions::quest2_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 18u);
}

SferaMbcValue SferaFunctions::quest2_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_315, 18u, SferaFields::buffer_284, 72u, 4294967278u);
}

SferaMbcValue SferaFunctions::quest2_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_316, 18u, SferaFields::buffer_286, 72u, 4294967278u);
}

SferaMbcValue SferaFunctions::quest2_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_317, SferaFields::integer_318, 18u, SferaFields::buffer_284,
        72u, 4294967278u);
}

SferaMbcValue SferaFunctions::quest2_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_319, 18u, SferaFields::buffer_284, 72u, 4294967278u);
}

SferaMbcValue SferaFunctions::quest2_GetMMChr(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMMChr_body(std::move(c), args, SferaFields::reference_333, SferaFields::buffer_335, SferaFields::buffer_336,
        16u, 72u, 4294967278u, SferaFields::buffer_336_at_25, SferaFields::buffer_337, SferaFields::integer_334);
}

SferaNativeTask SferaFunctions::quest2_bank_WinBank_helper_5442bb6c(SferaNativeContext c,
    std::vector<SferaMbcValue> args)
{
    return sfera_bank_WinBank_helper_5442bb6c_body(std::move(c), std::move(args), SferaFields::integer_322, SferaFields::integer_340,
        SferaFields::buffer_373, SferaFields::real_369_at_9, SferaFields::real_370, 127u, SferaFields::buffer_374, 126u,
        SferaFields::integer_372, SferaFields::integer_371, SferaFields::buffer_374_at_13, SferaFields::buffer_345,
        SferaFields::buffer_375, SferaFields::buffer_376);
}

SferaMbcValue SferaFunctions::mg_mantrab_use_check_frquse(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_check_frquse_body(std::move(c), args, SferaFields::integer_93_at_12, 5u, 17u, 18u);
}

SferaMbcValue SferaFunctions::mg_mantrab_use_is_stack_use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_is_stack_use_body(std::move(c), args, SferaFields::integer_60);
}

SferaMbcValue SferaFunctions::mg_mantrab_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_acb71a1f_body(std::move(c), args, SferaFunctions::mg_mantrab_UseWith);
}

SferaNativeTask SferaFunctions::mg_mantrab_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_4e681af7_body(std::move(c), std::move(args), SferaFunctions::mg_mantrab_Use);
}

SferaMbcValue SferaFunctions::mg_mantrab_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_ec1497dc_body(std::move(c), args, 65u, SferaFields::integer_188, SferaFields::integer_39,
        SferaFields::integer_195, 53u, SferaFields::integer_197, SferaFields::reference_202, SferaFields::buffer_203,
        SferaFields::integer_204, SferaFields::integer_91, 19u, 36u, 37u);
}

SferaMbcValue SferaFunctions::mg_mantrab_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_d03707f6_body(std::move(c), args, 48u, SferaFields::buffer_46, SferaFields::buffer_47,
        SferaFields::buffer_80, 10u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::mg_mantrab_convertTime2Str(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_convertTime2Str_body(std::move(c), args, SferaFields::integer_9_at_18, SferaFields::reference_10,
        SferaFields::integer_11, SferaFields::integer_12, 2u, 46u, 47u, SferaFields::buffer_16, SferaFields::buffer_13,
        SferaFields::buffer_17, SferaFields::buffer_18, SferaFields::buffer_19, SferaFields::buffer_19_at_11, SferaFields::buffer_19_at_12,
        SferaFields::buffer_20, SferaFields::buffer_14, SferaFields::buffer_21, SferaFields::buffer_22, SferaFields::buffer_23,
        SferaFields::buffer_24, SferaFields::buffer_25, SferaFields::buffer_25_at_11, SferaFields::buffer_25_at_12, SferaFields::buffer_26,
        SferaFields::buffer_15, SferaFields::buffer_27, SferaFields::buffer_28, SferaFields::buffer_29, SferaFields::buffer_30,
        SferaFields::buffer_42, SferaFields::buffer_50, SferaFields::buffer_50_at_11, SferaFields::buffer_191);
}

SferaMbcValue SferaFunctions::mg_mantrab_LoadMulti(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadMulti_8224bbca_body(std::move(c), args, 77u, 78u, SferaFields::reference_309, SferaFields::buffer_311,
        SferaFields::buffer_43, SferaFields::reference_310, SferaFields::integer_40, SferaFields::integer_48, 49u, SferaFields::buffer_49,
        SferaFields::reference_44, SferaFields::buffer_45);
}

SferaMbcValue SferaFunctions::mg_mantrab_PutHere(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_PutHere_body(std::move(c), args, SferaFunctions::player_UseServer);
}

SferaMbcValue SferaFunctions::mg_mantrab_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_73bcb877_body(std::move(c), args, 34u);
}

SferaMbcValue SferaFunctions::mg_mantrab_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_body(std::move(c), args, SferaFields::buffer_0, 5u, SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::mg_mantrab_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_body(std::move(c), args, SferaFields::buffer_62, 5u, SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::mg_mantrab_SetLearned(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_312, SferaFields::integer_54);
}

SferaMbcValue SferaFunctions::ct_cbook1_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 68u);
}

SferaMbcValue SferaFunctions::ct_cbook1_UseServer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_0_at_9);
}

SferaMbcValue SferaFunctions::ct_cbook1_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 49u, SferaFields::integer_36, SferaFields::integer_191, SferaFields::integer_37,
        54u, SferaFields::integer_38, SferaFields::reference_39, SferaFields::buffer_40, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u);
}

SferaMbcValue SferaFunctions::ct_cbook1_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_162_at_16, 1u, 0u, 0u, 0u);
}

SferaNativeTask SferaFunctions::ct_cbook1_UseAll(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_UseAll_body(std::move(c), std::move(args), SferaFields::integer_298, 3u, 12u, 4294967293u, SferaFields::buffer_301,
        SferaFields::buffer_300, SferaFields::buffer_299, SferaFields::buffer_302, SferaFields::buffer_303);
}

SferaMbcValue SferaFunctions::ct_cbook1_ct_cbook1_WinMacros_helper(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_ct_cbook1_WinMacros_helper_body(std::move(c), args, SferaFields::buffer_349, SferaFields::integer_305, 3u,
        SferaFields::integer_306, SferaFields::buffer_311, SferaFields::reference_304, SferaFields::buffer_350, SferaFields::buffer_316,
        SferaFields::buffer_312, SferaFields::buffer_313, SferaFields::integer_310, SferaFields::buffer_351, SferaFields::buffer_352,
        SferaFields::buffer_353, SferaFunctions::ct_cbook1_CalcMacroID);
}

SferaMbcValue SferaFunctions::ct_cbook1_CalcMacroID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CalcMacroID_body(std::move(c), args, SferaFields::integer_354, 3u, 384u, SferaFields::integer_355,
        SferaFields::buffer_356, 12u, 4294967293u, SferaFields::buffer_357, SferaFields::buffer_358, SferaFields::buffer_359,
        SferaFields::buffer_360, SferaFields::buffer_361, SferaFields::buffer_362, SferaFields::buffer_363, SferaFields::buffer_364);
}

SferaMbcValue SferaFunctions::ct_cbook1_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_0f9f3fa3_body(std::move(c), args, SferaFields::buffer_272, 8u, SferaFields::integer_258,
        SferaFields::buffer_273, 4u, SferaFields::integer_247, SferaFields::buffer_274, 8u, SferaFields::integer_82);
}

SferaMbcValue SferaFunctions::ct_cbook1_WinMacrosTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_mission_TradeTrig_body(std::move(c), args, SferaFields::integer_278_at_10, SferaFields::integer_166,
        SferaFunctions::ct_cbook1_WinMacrosOn, SferaFunctions::ct_cbook1_WinMacrosOff);
}

SferaMbcValue SferaFunctions::ct_cbook1_WinMacrosOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_inv_InvOn_body(std::move(c), args, 72u, SferaFields::integer_166, SferaFields::buffer_279, SferaFields::buffer_280, 96u,
        71u);
}

SferaMbcValue SferaFunctions::ct_cbook1_WinMacrosOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 96u);
}

SferaMbcValue SferaFunctions::mg_gmagicpot_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_62, SferaFields::integer_184, 61u,
        SferaFields::integer_0, 4u, SferaFields::buffer_229, 16u, 4294967292u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::ct_mbag_sendslot);
}

SferaMbcValue SferaFunctions::mg_gmagicpot_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 48u, SferaFields::buffer_54, SferaFields::buffer_80, SferaFields::buffer_81, 12u,
        6u);
}

SferaMbcValue SferaFunctions::mg_gmagicpot_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_162_at_16, 0u, 1u, 1u, 0u);
}

SferaMbcValue SferaFunctions::mg_gmagicpot_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_202, 62u, 61u, SferaFields::buffer_229, 16u, 4294967292u,
        SferaFields::integer_232, 63u, SferaFields::buffer_234, 4u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::ct_mapbook_CheckWght);
}

SferaMbcValue SferaFunctions::mg_gmagicpot_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 17u, SferaFields::integer_230, 68u, 69u, SferaFields::buffer_239, 72u,
        75u, SferaFields::integer_239_at_8, 4u, 74u, SferaFields::buffer_229, 16u, 4294967292u, SferaFields::buffer_240,
        SferaFields::buffer_245, 76u, 77u, 78u, 79u, SferaFields::buffer_246, 80u, SferaFields::buffer_248, SferaFields::buffer_252,
        SferaFields::buffer_248_at_12, SferaFields::buffer_253, SferaFields::buffer_249, SferaFields::buffer_254, SferaFields::buffer_255,
        SferaFields::buffer_256, SferaFields::buffer_257, 81u, SferaFields::buffer_182, SferaFunctions::mg_gmagicpot_TestIt);
}

SferaMbcValue SferaFunctions::mg_gmagicpot_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_d698e4fa_body(std::move(c), args, SferaFields::integer_212_at_3, SferaFields::buffer_277, 13u,
        SferaFields::buffer_278, SferaFields::buffer_279, 45u);
}

SferaMbcValue SferaFunctions::mg_gmagicpot_EnableEmptyChecks(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_279_at_5, SferaFields::integer_82);
}

SferaMbcValue SferaFunctions::ct_sbag_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 4u, 35u, SferaFields::reference_238, SferaFields::integer_200,
        SferaFields::buffer_275, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_276, SferaFields::buffer_277,
        SferaFields::buffer_278, 73u, 72u, SferaFields::buffer_279, SferaFields::buffer_271, SferaFields::buffer_272,
        SferaFields::integer_273, SferaFields::integer_274, SferaFields::reference_266, SferaFields::buffer_280,
        SferaFields::reference_265, SferaFields::buffer_281, SferaFields::reference_267, SferaFields::buffer_282,
        SferaFields::reference_268, SferaFields::buffer_283, SferaFields::reference_269, SferaFields::reference_270,
        SferaFields::buffer_284, SferaFields::buffer_240, SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::real_263,
        SferaFields::integer_250, SferaFields::real_264, 900000u, SferaFields::buffer_252, SferaFields::buffer_253, 70u, 71u,
        SferaFields::buffer_254, SferaFields::buffer_255, SferaFields::buffer_257, SferaFields::buffer_256, SferaFields::buffer_259,
        SferaFields::buffer_260, SferaFields::buffer_261);
}

SferaMbcValue SferaFunctions::ct_sbag_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 3u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_218, 48u, 4294967284u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 12u, SferaFunctions::ct_sbag_openSlot, SferaFunctions::ct_sbag_CheckWght);
}

SferaMbcValue SferaFunctions::ct_sbag_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_262, 900000u);
}

SferaMbcValue SferaFunctions::ct_sbag_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_209,
        SferaFields::reference_210, SferaFields::reference_211, SferaFields::buffer_239, 5u, SferaFields::reference_213,
        SferaFields::reference_212);
}

SferaMbcValue SferaFunctions::goldpurse_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::goldpurse_InitObj);
}

SferaMbcValue SferaFunctions::goldpurse_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 5u, SferaFields::buffer_201, 6u);
}

SferaMbcValue SferaFunctions::goldpurse_dnts(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_201_at_6, SferaFields::integer_80);
}

SferaNativeTask SferaFunctions::goldpurse_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_5b3982b3_body(std::move(c), std::move(args), 49u, SferaFields::integer_53, SferaFields::reference_90,
        SferaFields::integer_62, SferaFields::integer_82, SferaFields::integer_52, SferaFields::buffer_167, SferaFields::buffer_196, 59u);
}

SferaMbcValue SferaFunctions::goldpurse_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 49u, SferaFields::integer_36, SferaFields::integer_191, SferaFields::integer_37,
        59u, SferaFields::integer_38, SferaFields::reference_39, SferaFields::buffer_40, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u);
}

SferaMbcValue SferaFunctions::goldpurse_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_10e3b377_body(std::move(c), args, 17u, 35u, SferaFields::reference_81, 6u, 69u);
}

SferaMbcValue SferaFunctions::labyr_GetEnt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_main_GetXYZ_body(std::move(c), args, SferaFields::integer_86, SferaFields::reference_198, SferaFields::buffer_4, 24u, 16u);
}

SferaMbcValue SferaFunctions::labyr_GMID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetHealth_body(std::move(c), args, SferaFields::buffer_54, 52u, 4u);
}

SferaMbcValue SferaFunctions::labyr_halt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_halt_body(std::move(c), args, 6u, 7u);
}

SferaMbcValue SferaFunctions::labyr_thalt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 9u);
}

SferaMbcValue SferaFunctions::labyr_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 11u, 68u);
}

SferaMbcValue SferaFunctions::labyr_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_a494cfe9_body(std::move(c), args, 41u, SferaFields::integer_210, SferaFields::integer_63,
        SferaFields::integer_211, 54u, SferaFields::integer_212, SferaFields::reference_213, SferaFields::buffer_214,
        SferaFields::integer_64, SferaFields::integer_65);
}

SferaMbcValue SferaFunctions::labyr_EKill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EKill_a28ec083_body(std::move(c), args, SferaFields::integer_57);
}

SferaMbcValue SferaFunctions::ar_amulet_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 71u);
}

SferaMbcValue SferaFunctions::ar_amulet_use_send_cuse_to_server(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_send_cuse_to_server_body(std::move(c), args, SferaFields::integer_60_at_8, 50u, 51u,
        SferaFields::reference_196, SferaFields::buffer_132, 256u, 52u);
}

SferaMbcValue SferaFunctions::ar_amulet_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 49u, SferaFields::integer_36, SferaFields::integer_191, SferaFields::integer_37,
        57u, SferaFields::integer_38, SferaFields::reference_39, SferaFields::buffer_40, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u);
}

SferaMbcValue SferaFunctions::ar_amulet_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_916cf044_body(std::move(c), args, SferaFunctions::bank_AddInfo);
}

SferaMbcValue SferaFunctions::npc_empty_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 130u, SferaFields::integer_268, SferaFields::integer_270, 52u,
        SferaFields::integer_271, SferaFields::reference_273, SferaFields::buffer_335, SferaFields::integer_200, SferaFields::integer_272,
        SferaFields::reference_269, SferaFunctions::crt02_FlyWeapon);
}

SferaNativeTask SferaFunctions::npc_empty_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_74399034_body(std::move(c), std::move(args), SferaFunctions::crt02_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_empty_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ar_ring_SndUser_body(std::move(c), args, SferaFields::reference_255_at_4);
}

SferaMbcValue SferaFunctions::npc_empty_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_f24e678e_body(std::move(c), args, SferaFields::integer_246, SferaFields::reference_247);
}

SferaMbcValue SferaFunctions::town_table_RcvG(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvG_body(std::move(c), args, SferaFields::integer_293_at_8, SferaFields::integer_294, SferaFields::integer_295,
        SferaFields::integer_299, SferaFields::integer_302, SferaFields::buffer_304, SferaFields::integer_300, SferaFields::integer_303,
        SferaFields::buffer_305, SferaFields::integer_301);
}

SferaMbcValue SferaFunctions::town_table_GetAddrs(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetAddrs_body(std::move(c), args, SferaFields::reference_192_at_2, SferaFields::reference_318,
        SferaFields::reference_319, SferaFields::reference_320, SferaFields::reference_321, SferaFields::reference_322,
        SferaFields::reference_323, SferaFields::reference_324, SferaFields::reference_325);
}

SferaMbcValue SferaFunctions::license_hrgt_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_37be24d5_body(std::move(c), args, SferaFunctions::license_hrgt_UseOwner);
}

SferaNativeTask SferaFunctions::license_hrgt_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_ac62c630_body(std::move(c), std::move(args), SferaFunctions::license_hrgt_Use);
}

SferaMbcValue SferaFunctions::license_hrgt_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_05e952b4_body(std::move(c), args, SferaFunctions::g_lvlup_license_AddInfo);
}

SferaMbcValue SferaFunctions::license_hrgt_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_c7bed929_body(std::move(c), args, 61u, 93u);
}

SferaNativeTask SferaFunctions::pw_couragef1_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_f3052ab3_body(std::move(c), std::move(args), SferaFunctions::pw_couragef1_RcvUser);
}

SferaMbcValue SferaFunctions::pw_couragef1_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadGame_27247a3d_body(std::move(c), args, SferaFields::buffer_128, SferaFields::buffer_286, 13u);
}

SferaMbcValue SferaFunctions::pw_couragef1_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_1cb0dfbe_body(std::move(c), args, SferaFields::integer_286_at_13, SferaFields::reference_287,
        SferaFields::buffer_288, 13u, SferaFields::buffer_289);
}

SferaMbcValue SferaFunctions::crystalc_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_272403a7_body(std::move(c), args, SferaFunctions::crystalc_UseOwner);
}

SferaNativeTask SferaFunctions::crystalc_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_8ed35db2_body(std::move(c), std::move(args), SferaFunctions::crystalc_Use);
}

SferaMbcValue SferaFunctions::crystalc_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_0537a213_body(std::move(c), args, SferaFields::integer_46_at_8, 76u, 4u, SferaFields::buffer_275);
}

SferaMbcValue SferaFunctions::specab_ba_use_check_frquse(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_check_frquse_body(std::move(c), args, SferaFields::integer_60_at_8, 58u, 59u, 60u);
}

SferaMbcValue SferaFunctions::specab_ba_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_e0a993c7_body(std::move(c), args, 67u, SferaFields::integer_36, SferaFields::integer_203,
        SferaFields::integer_37, 58u, SferaFields::integer_62, SferaFields::reference_80, SferaFields::buffer_81, SferaFields::integer_214,
        SferaFields::integer_184, 52u, 53u, 54u);
}

SferaMbcValue SferaFunctions::st_ear_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 10u, 73u);
}

SferaMbcValue SferaFunctions::st_ear_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_06f4a581_body(std::move(c), args, SferaFunctions::st_ear_UseWith);
}

SferaMbcValue SferaFunctions::st_ear_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_91afe4f1_body(std::move(c), args, 73u, 74u, 706u);
}

SferaMbcValue SferaFunctions::ar_ring_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ar_ring_SndUser_body(std::move(c), args, SferaFields::reference_204_at_16);
}

SferaMbcValue SferaFunctions::ar_ring_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_body(std::move(c), args, 73u, SferaFields::reference_197, SferaFields::buffer_128);
}

SferaMbcValue SferaFunctions::vn_stoneb_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_726bc4f3_body(std::move(c), args, SferaFunctions::vn_stoneb_UseWith);
}

SferaMbcValue SferaFunctions::vn_stoneb_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_971db48c_body(std::move(c), args, 5u, 62u, 900u);
}

SferaMbcValue SferaFunctions::licence_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_e9053998_body(std::move(c), args, SferaFields::buffer_249, 5u, SferaFields::integer_189,
        SferaFields::buffer_250, 6u, SferaFields::integer_208);
}

SferaMbcValue SferaFunctions::vn_ret1_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SaveGame_e9053998_body(std::move(c), args, SferaFields::buffer_62, 4u, SferaFields::integer_82,
        SferaFields::buffer_47, 4u, SferaFields::integer_0);
}

SferaMbcValue SferaFunctions::pw_fb03_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_eb82aad4_body(std::move(c), args, 83u, 84u, 85u, 4u, SferaFields::buffer_47);
}

SferaMbcValue SferaFunctions::guild_Effect(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Effect_body(std::move(c), args, SferaFields::integer_163_at_8);
}

SferaNativeTask SferaFunctions::st_light3_Main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Main_87f167e6_body(std::move(c), std::move(args), 90u);
}

SferaNativeTask SferaFunctions::vir1037_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 16u);
}

SferaNativeTask SferaFunctions::vir1015_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 6u);
}

SferaMbcValue SferaFunctions::vir1023_CallLink(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CallLink_body(std::move(c), args, 1u, 1u);
}

SferaMbcValue SferaFunctions::st_coin_CheckFree(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_thalt_body(std::move(c), args, 96u);
}
