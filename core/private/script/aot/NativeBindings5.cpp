#include "script/NativeFunctions.h"
#include <utility>
#include "script/NativeFields.h"

SferaMbcValue SferaFunctions::ct_bag_herb_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::ct_bag_herb_InitObj);
}

SferaMbcValue SferaFunctions::ct_bag_herb_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 5u, SferaFields::buffer_62, 7u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_dnts(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_62_at_7, SferaFields::integer_0);
}

SferaMbcValue SferaFunctions::ct_bag_herb_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_9d76123b_body(std::move(c), args, SferaFields::reference_82, SferaFields::integer_184, 3u,
        SferaFields::integer_189, 20u, SferaFields::buffer_202, 80u, 4294967276u, SferaFields::integer_191, SferaFields::integer_198,
        SferaFields::integer_192, 46u, 47u, SferaFunctions::ct_bag_herb_sendslot);
}

SferaMbcValue SferaFunctions::ct_bag_herb_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_202, 80u, SferaFields::buffer_81, SferaFields::integer_216);
}

SferaNativeTask SferaFunctions::ct_bag_herb_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_beb84fb0_body(std::move(c), std::move(args), SferaFields::integer_190, SferaFields::reference_306,
        SferaFields::integer_304, SferaFields::integer_305, SferaFields::buffer_307, SferaFields::buffer_308, 20u, SferaFields::buffer_202,
        80u, 4294967276u, SferaFields::buffer_81, 3u, SferaFunctions::ct_bag_herb_sendslot);
}

SferaMbcValue SferaFunctions::ct_bag_herb_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 35u, 4u, SferaFields::reference_80, SferaFields::integer_200,
        SferaFields::buffer_283, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_284, SferaFields::buffer_285,
        SferaFields::buffer_286, 74u, 73u, SferaFields::buffer_287, SferaFields::buffer_269, SferaFields::buffer_280,
        SferaFields::integer_281, SferaFields::integer_282, SferaFields::reference_241, SferaFields::buffer_288,
        SferaFields::reference_201, SferaFields::buffer_289, SferaFields::reference_265, SferaFields::buffer_264,
        SferaFields::reference_266, SferaFields::buffer_246, SferaFields::reference_267, SferaFields::reference_268,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_90,
        SferaFields::integer_250, SferaFields::real_199, 12000u, SferaFields::buffer_254, SferaFields::buffer_255, 70u, 72u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_bag_herb_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_217, 17u, SferaFields::reference_218, 3u,
        SferaFields::buffer_202, 80u, 4294967276u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_bag_herb_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 56u, SferaFields::integer_219, 57u, 3u, SferaFields::buffer_202, 80u, 4294967276u,
        SferaFields::integer_220, 58u, SferaFields::buffer_221, 20u, SferaFunctions::bank_openSlot, SferaFunctions::ct_bag_herb_CheckWght);
}

SferaMbcValue SferaFunctions::ct_bag_herb_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 59u, SferaFields::integer_222, 20u, SferaFields::integer_223,
        SferaFields::buffer_202, 80u, 4294967276u, SferaFields::integer_224);
}

SferaMbcValue SferaFunctions::ct_bag_herb_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 60u, SferaFields::integer_225, 20u, SferaFields::integer_226,
        SferaFields::buffer_202, 80u, 4294967276u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 61u, SferaFields::integer_215, SferaFields::integer_227, 20u, 62u,
        SferaFields::buffer_202, 80u, 4294967276u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 63u, SferaFields::integer_215, 65u, 66u, SferaFields::buffer_228, 67u,
        69u, SferaFields::integer_228_at_8, 20u, 68u, SferaFields::buffer_202, 80u, 4294967276u, SferaFields::buffer_229,
        SferaFields::buffer_230, 79u, 80u, 81u, 82u, SferaFields::buffer_231, 83u, SferaFields::buffer_232, SferaFields::buffer_234,
        SferaFields::buffer_232_at_12, SferaFields::buffer_235, SferaFields::buffer_233, SferaFields::buffer_236, SferaFields::buffer_270,
        SferaFields::buffer_271, SferaFields::buffer_272, 84u, SferaFields::buffer_182, SferaFunctions::ct_bag_herb_TestIt);
}

SferaMbcValue SferaFunctions::ct_bag_herb_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 12000u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 85u, 86u, SferaFields::integer_273, 20u, SferaFields::buffer_202, 80u,
        4294967276u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_bag_herb_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 87u, 3u, SferaFields::integer_274, 20u, SferaFields::buffer_202, 80u, 4294967276u,
        SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_bag_herb_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_309, 3u, SferaFields::integer_310, 20u,
        SferaFields::buffer_202, 80u, 4294967276u, SferaFields::buffer_81);
}

SferaMbcValue SferaFunctions::ct_bag_herb_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 20u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_275, 20u, SferaFields::buffer_202, 80u, 4294967276u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_276, 20u, SferaFields::buffer_214, 80u, 4294967276u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_277, SferaFields::integer_278, 20u, SferaFields::buffer_202,
        80u, 4294967276u);
}

SferaMbcValue SferaFunctions::ct_bag_herb_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_279, 20u, SferaFields::buffer_202, 80u, 4294967276u);
}

SferaMbcValue SferaFunctions::ct_chest2_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_196, 112u, SferaFields::buffer_203, SferaFields::integer_206);
}

SferaNativeTask SferaFunctions::ct_chest2_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_3738afb9_body(std::move(c), std::move(args), 5u, SferaFields::integer_54, SferaFields::reference_188,
        SferaFields::integer_189, SferaFields::integer_209, SferaFields::buffer_191, SferaFields::buffer_86, 47u, 28u,
        SferaFields::buffer_196, 112u, 4294967268u, SferaFields::buffer_203, 47u, SferaFunctions::ct_chest1_Use,
        SferaFunctions::ct_chest2_sendslot);
}

SferaMbcValue SferaFunctions::ct_chest2_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 41u, 46u, SferaFields::reference_187, SferaFields::integer_3,
        SferaFields::buffer_227, SferaFields::integer_64, SferaFields::integer_65, SferaFields::reference_228, SferaFields::buffer_229,
        SferaFields::buffer_230, 58u, 57u, SferaFields::buffer_231, SferaFields::buffer_223, SferaFields::buffer_224,
        SferaFields::integer_225, SferaFields::integer_226, SferaFields::reference_211, SferaFields::buffer_232,
        SferaFields::reference_210, SferaFields::buffer_233, SferaFields::reference_212, SferaFields::buffer_234,
        SferaFields::reference_220, SferaFields::buffer_235, SferaFields::reference_221, SferaFields::reference_222,
        SferaFields::buffer_241, SferaFields::buffer_242, SferaFields::buffer_243, SferaFields::buffer_244, SferaFields::real_192,
        SferaFields::integer_61, SferaFields::real_193, 500000u, SferaFields::buffer_245, SferaFields::buffer_246, 48u, 56u,
        SferaFields::buffer_247, SferaFields::buffer_248, SferaFields::buffer_250, SferaFields::buffer_249, SferaFields::buffer_251,
        SferaFields::buffer_252, SferaFields::buffer_253);
}

SferaMbcValue SferaFunctions::ct_chest2_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 17u, SferaFields::buffer_81, SferaFields::buffer_182, SferaFields::buffer_186, 10u,
        0u);
}

SferaMbcValue SferaFunctions::ct_chest2_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_213, 49u, SferaFields::reference_214, 47u,
        SferaFields::buffer_196, 112u, 4294967268u, SferaFields::buffer_203);
}

SferaMbcValue SferaFunctions::ct_chest2_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_c06a4fe6_body(std::move(c), args, 60u, SferaFields::integer_254, 61u, 47u, SferaFields::buffer_196, 112u,
        4294967268u, SferaFields::integer_255, 62u, SferaFields::buffer_256, 28u, SferaFunctions::ct_chest2_openSlot,
        SferaFunctions::ct_chest2_CheckWght);
}

SferaMbcValue SferaFunctions::ct_chest2_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 50u, SferaFields::integer_215, 28u, SferaFields::integer_216,
        SferaFields::buffer_196, 112u, 4294967268u, SferaFields::integer_217);
}

SferaMbcValue SferaFunctions::ct_chest2_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 51u, SferaFields::integer_218, 28u, SferaFields::integer_219,
        SferaFields::buffer_196, 112u, 4294967268u);
}

SferaMbcValue SferaFunctions::ct_chest2_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 52u, SferaFields::integer_205, SferaFields::integer_236, 28u, 59u,
        SferaFields::buffer_196, 112u, 4294967268u);
}

SferaMbcValue SferaFunctions::ct_chest2_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_ae2aa720_body(std::move(c), args, 63u, SferaFields::integer_205, 64u, 65u, SferaFields::buffer_257, 66u,
        68u, SferaFields::integer_257_at_8, 28u, 67u, SferaFields::buffer_196, 112u, 4294967268u, SferaFields::buffer_258,
        SferaFields::buffer_259, 69u, 70u, 71u, 72u, SferaFields::buffer_260, 73u, SferaFields::buffer_261, SferaFields::buffer_263,
        SferaFields::buffer_261_at_12, SferaFields::buffer_264, SferaFields::buffer_262, SferaFields::buffer_265, SferaFields::buffer_266,
        SferaFields::buffer_267, SferaFields::buffer_268, 74u, SferaFields::buffer_269, SferaFunctions::ct_chest2_TestIt);
}

SferaMbcValue SferaFunctions::ct_chest2_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_17921366_body(std::move(c), args, SferaFields::integer_269_at_8, 500000u);
}

SferaMbcValue SferaFunctions::ct_chest2_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_270, 28u, SferaFields::buffer_196, 112u,
        4294967268u, SferaFields::buffer_203);
}

SferaMbcValue SferaFunctions::ct_chest2_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 47u, SferaFields::integer_271, 28u, SferaFields::buffer_196, 112u,
        4294967268u, SferaFields::buffer_203, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::ct_chest2_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 75u, 47u, SferaFields::integer_272, 28u, SferaFields::buffer_196, 112u,
        4294967268u, SferaFields::buffer_203);
}

SferaMbcValue SferaFunctions::ct_chest2_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 28u);
}

SferaMbcValue SferaFunctions::ct_chest2_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_85, 28u, SferaFields::buffer_196, 112u, 4294967268u);
}

SferaMbcValue SferaFunctions::ct_chest2_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_237, 28u, SferaFields::buffer_204, 112u, 4294967268u);
}

SferaMbcValue SferaFunctions::ct_chest2_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_238, SferaFields::integer_239, 28u, SferaFields::buffer_196,
        112u, 4294967268u);
}

SferaMbcValue SferaFunctions::ct_chest2_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_240, 28u, SferaFields::buffer_196, 112u, 4294967268u);
}

SferaMbcValue SferaFunctions::ct_chest2_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_116adf93_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_190,
        SferaFields::reference_194, 20u, SferaFields::reference_195, SferaFields::buffer_200, 24u, SferaFields::buffer_202, 3u,
        SferaFields::reference_198, SferaFields::reference_197);
}

SferaMbcValue SferaFunctions::ct_mbag_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 10u, 65u);
}

SferaMbcValue SferaFunctions::ct_mbag_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_97811cb2_body(std::move(c), args, SferaFunctions::ct_mbag_UseOwner);
}

SferaMbcValue SferaFunctions::ct_mbag_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_body(std::move(c), args, SferaFields::buffer_229, 16u, SferaFields::buffer_231, SferaFields::integer_215);
}

SferaNativeTask SferaFunctions::ct_mbag_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_3738afb9_body(std::move(c), std::move(args), 41u, SferaFields::integer_54, SferaFields::reference_192,
        SferaFields::integer_189, SferaFields::integer_190, SferaFields::buffer_196, SferaFields::buffer_198, 51u, 4u,
        SferaFields::buffer_229, 16u, 4294967292u, SferaFields::buffer_231, 61u, SferaFunctions::ct_mbag_Use,
        SferaFunctions::ct_mbag_sendslot);
}

SferaMbcValue SferaFunctions::ct_mbag_sendslot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sendslot_body(std::move(c), args, SferaFields::integer_216, 56u, SferaFields::reference_217, 61u,
        SferaFields::buffer_229, 16u, 4294967292u, SferaFields::buffer_231);
}

SferaMbcValue SferaFunctions::ct_mbag_SeekTag(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTag_body(std::move(c), args, 57u, SferaFields::integer_218, 4u, SferaFields::integer_219,
        SferaFields::buffer_229, 16u, 4294967292u, SferaFields::integer_220);
}

SferaMbcValue SferaFunctions::ct_mbag_SeekTagInsideNoRecursive(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_SeekTagInsideNoRecursive_body(std::move(c), args, 58u, SferaFields::integer_221, 4u, SferaFields::integer_222,
        SferaFields::buffer_229, 16u, 4294967292u);
}

SferaMbcValue SferaFunctions::ct_mbag_SetOverFill(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SetOverFill_body(std::move(c), args, 59u, SferaFields::integer_230, SferaFields::integer_223, 4u, 60u,
        SferaFields::buffer_229, 16u, 4294967292u);
}

SferaMbcValue SferaFunctions::ct_mbag_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_99840dcc_body(std::move(c), args, 17u, SferaFields::integer_230, 46u, 47u, SferaFields::buffer_200, 49u,
        51u, SferaFields::integer_200_at_8, 4u, 50u, SferaFields::buffer_229, 16u, 4294967292u, SferaFields::buffer_204,
        SferaFields::buffer_205, 52u, 62u, 63u, SferaFields::buffer_206, SferaFields::buffer_209, SferaFields::buffer_211,
        SferaFields::buffer_209_at_12, SferaFields::buffer_212, SferaFields::buffer_210, SferaFields::buffer_232, SferaFields::buffer_233,
        SferaFields::buffer_264, SferaFields::buffer_265, SferaFields::buffer_182);
}

SferaMbcValue SferaFunctions::ct_mbag_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_1a621d44_body(std::move(c), args, SferaFields::integer_187, 4u, SferaFields::buffer_229, 16u, 4294967292u,
        SferaFields::buffer_231);
}

SferaMbcValue SferaFunctions::ct_mbag_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_b6fd1824_body(std::move(c), args, 61u, SferaFields::integer_188, 4u, SferaFields::buffer_229, 16u,
        4294967292u, SferaFields::buffer_231, SferaFields::buffer_132, 256u);
}

SferaMbcValue SferaFunctions::ct_mbag_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_671a8fab_body(std::move(c), args, 4u, 61u, SferaFields::integer_191, 4u, SferaFields::buffer_229, 16u,
        4294967292u, SferaFields::buffer_231);
}

SferaMbcValue SferaFunctions::ct_mbag_GetSlotsNum(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_ai_isFlamount_body(std::move(c), args, 4u);
}

SferaMbcValue SferaFunctions::ct_mbag_GetSlotID(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_224, 4u, SferaFields::buffer_229, 16u, 4294967292u);
}

SferaMbcValue SferaFunctions::ct_mbag_isSlotOccupied(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetSlotID_body(std::move(c), args, SferaFields::integer_225, 4u, SferaFields::buffer_214, 16u, 4294967292u);
}

SferaMbcValue SferaFunctions::ct_mbag_TestMe(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_TestMe_body(std::move(c), args, SferaFields::integer_226, SferaFields::integer_227, 4u, SferaFields::buffer_229, 16u,
        4294967292u);
}

SferaMbcValue SferaFunctions::ct_mbag_GetMySlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetMySlot_body(std::move(c), args, SferaFields::integer_228, 4u, SferaFields::buffer_229, 16u, 4294967292u);
}

SferaMbcValue SferaFunctions::ct_mbag_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_12088b0e_body(std::move(c), args, 74u, SferaFields::buffer_266, 42u, SferaFunctions::bank_isGxpItem);
}

SferaMbcValue SferaFunctions::ct_mbag_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_body(std::move(c), args, SferaFields::integer_207_at_5, SferaFields::reference_267,
        SferaFields::reference_268, SferaFields::reference_269, SferaFields::buffer_272, 14u, SferaFields::reference_271,
        SferaFields::reference_270);
}

SferaMbcValue SferaFunctions::ct_rbook_EInit(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_EInit_body(std::move(c), args, SferaFields::reference_65, 47u, SferaFields::integer_54, 28u,
        SferaFields::buffer_196, 112u, 4294967268u, SferaFunctions::ct_chest2_sendslot);
}

SferaNativeTask SferaFunctions::ct_rbook_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_70a36942_body(std::move(c), std::move(args), SferaFields::integer_66, SferaFields::reference_84,
        SferaFields::integer_81, SferaFields::integer_83, SferaFields::buffer_86, SferaFields::buffer_87, 28u, SferaFields::buffer_196,
        112u, 4294967268u, SferaFields::buffer_203, 47u, SferaFunctions::ct_chest2_sendslot);
}

SferaMbcValue SferaFunctions::ct_rbook_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 3u, 17u, SferaFields::reference_88, SferaFields::integer_3,
        SferaFields::buffer_230, SferaFields::integer_183, SferaFields::integer_244, SferaFields::reference_231, SferaFields::buffer_232,
        SferaFields::buffer_233, 58u, 57u, SferaFields::buffer_234, SferaFields::buffer_226, SferaFields::buffer_227,
        SferaFields::integer_228, SferaFields::integer_229, SferaFields::reference_221, SferaFields::buffer_235,
        SferaFields::reference_220, SferaFields::buffer_182, SferaFields::reference_222, SferaFields::buffer_186,
        SferaFields::reference_223, SferaFields::buffer_197, SferaFields::reference_224, SferaFields::reference_225,
        SferaFields::buffer_202, SferaFields::buffer_245, SferaFields::buffer_246, SferaFields::buffer_247, SferaFields::real_89,
        SferaFields::integer_250, SferaFields::real_90, 1260u, SferaFields::buffer_248, SferaFields::buffer_249, 60u, 56u,
        SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::buffer_255, SferaFields::buffer_254, SferaFields::buffer_256,
        SferaFields::buffer_257, SferaFields::buffer_258);
}

SferaMbcValue SferaFunctions::ct_rbook_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 61u, SferaFields::integer_259, 62u, 47u, SferaFields::buffer_196, 112u,
        4294967268u, SferaFields::integer_260, 63u, SferaFields::buffer_261, 28u, SferaFunctions::ct_chest1_openSlot,
        SferaFunctions::ct_rbook_CheckWght);
}

SferaMbcValue SferaFunctions::ct_rbook_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 65u, SferaFields::integer_205, 66u, 67u, SferaFields::buffer_262, 68u,
        72u, SferaFields::integer_262_at_8, 28u, 69u, SferaFields::buffer_196, 112u, 4294967268u, SferaFields::buffer_263,
        SferaFields::buffer_264, 73u, 74u, 75u, 76u, SferaFields::buffer_265, 77u, SferaFields::buffer_266, SferaFields::buffer_268,
        SferaFields::buffer_266_at_12, SferaFields::buffer_269, SferaFields::buffer_267, SferaFields::buffer_270, SferaFields::buffer_271,
        SferaFields::buffer_272, SferaFields::buffer_273, 78u, SferaFields::buffer_274, SferaFunctions::ct_rbook_TestIt);
}

SferaMbcValue SferaFunctions::ct_rbook_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_274_at_8, 1260u);
}

SferaMbcValue SferaFunctions::ct_rbook_AddWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddWght_body(std::move(c), args, 79u, 80u, SferaFields::integer_275, 28u, SferaFields::buffer_196, 112u,
        4294967268u, SferaFields::buffer_203);
}

SferaMbcValue SferaFunctions::ct_rbook_FreeIt1(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt1_body(std::move(c), args, 81u, 47u, SferaFields::integer_276, 28u, SferaFields::buffer_196, 112u,
        4294967268u, SferaFields::buffer_203);
}

SferaMbcValue SferaFunctions::ct_rbook_FreeIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FreeIt_body(std::move(c), args, SferaFields::integer_277, 47u, SferaFields::integer_278, 28u,
        SferaFields::buffer_196, 112u, 4294967268u, SferaFields::buffer_203);
}

SferaMbcValue SferaFunctions::al_flower_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 76u);
}

SferaMbcValue SferaFunctions::al_flower_GetAlch(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetModel_body(std::move(c), args, SferaFields::integer_37, SferaFields::reference_38, SferaFields::buffer_36, 6u);
}

SferaMbcValue SferaFunctions::al_flower_GetWeight(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetWeight_716186f6_body(std::move(c), args, 45u, SferaFields::buffer_201, 4u, SferaFields::integer_35,
        SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::al_flower_SetAmount(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_DnDRes_body(std::move(c), args, SferaFields::integer_201_at_4, SferaFields::integer_200);
}

SferaMbcValue SferaFunctions::al_flower_use_is_stack_use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_is_stack_use_body(std::move(c), args, SferaFields::integer_60_at_8);
}

SferaMbcValue SferaFunctions::al_flower_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_body(std::move(c), args, SferaFields::integer_49, 60u, SferaFields::buffer_51, SferaFields::buffer_53,
        SferaFields::buffer_54, SferaFields::buffer_82, SferaFields::buffer_182, SferaFields::buffer_196);
}

SferaMbcValue SferaFunctions::al_flower_UseServer(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckPut_body(std::move(c), args, SferaFields::integer_152_at_8);
}

SferaMbcValue SferaFunctions::al_flower_GetP(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetP_28e3779b_body(std::move(c), args, SferaFields::integer_31, SferaFields::integer_32);
}

SferaMbcValue SferaFunctions::al_flower_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_body(std::move(c), args, 61u, SferaFields::integer_208, SferaFields::integer_191,
        SferaFields::integer_209, 62u, SferaFields::integer_210, SferaFields::reference_211, SferaFields::buffer_212,
        SferaFields::integer_198, SferaFields::integer_192, 46u, 47u);
}

SferaMbcValue SferaFunctions::al_flower_getNeutralInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_getNeutralInfo_body(std::move(c), args, SferaFields::integer_90_at_4, SferaFields::reference_168);
}

SferaMbcValue SferaFunctions::al_flower_createInfoSeparatorLine(SferaNativeContext c,
    std::span<const SferaMbcValue> args)
{
    return sfera_shared_createInfoSeparatorLine_body(std::move(c), args, SferaFields::reference_122_at_24);
}

SferaMbcValue SferaFunctions::al_flower_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_162_at_16, 0u, 0u, 0u, 0u);
}

SferaMbcValue SferaFunctions::al_flower_GetPrice(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetPrice_body(std::move(c), args, SferaFields::integer_190, SferaFields::integer_189);
}

SferaNativeTask SferaFunctions::al_flower_Main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Main_body(std::move(c), std::move(args), 41u, 69u);
}

SferaMbcValue SferaFunctions::ct_sac_m_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_body(std::move(c), args, 35u, 72u, SferaFields::reference_80, SferaFields::integer_200,
        SferaFields::buffer_276, SferaFields::integer_198, SferaFields::integer_192, SferaFields::reference_277, SferaFields::buffer_278,
        SferaFields::buffer_279, 60u, 17u, SferaFields::buffer_280, SferaFields::buffer_272, SferaFields::buffer_273,
        SferaFields::integer_274, SferaFields::integer_275, SferaFields::reference_267, SferaFields::buffer_281,
        SferaFields::reference_233, SferaFields::buffer_282, SferaFields::reference_268, SferaFields::buffer_264,
        SferaFields::reference_269, SferaFields::buffer_246, SferaFields::reference_270, SferaFields::reference_271,
        SferaFields::buffer_248, SferaFields::buffer_249, SferaFields::buffer_252, SferaFields::buffer_253, SferaFields::real_81,
        SferaFields::integer_250, SferaFields::real_90, 400u, SferaFields::buffer_254, SferaFields::buffer_255, 88u, 3u,
        SferaFields::buffer_256, SferaFields::buffer_257, SferaFields::buffer_260, SferaFields::buffer_259, SferaFields::buffer_261,
        SferaFields::buffer_262, SferaFields::buffer_263);
}

SferaMbcValue SferaFunctions::ct_sac_m_TestIt(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestIt_body(std::move(c), args, 61u, SferaFields::integer_231, 65u, 56u, SferaFields::buffer_229, 32u, 4294967288u,
        SferaFields::integer_232, 66u, SferaFields::buffer_234, 8u, SferaFunctions::bank_openSlot, SferaFunctions::ct_sac_m_CheckWght);
}

SferaMbcValue SferaFunctions::ct_sac_m_TestPut(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TestPut_acf82001_body(std::move(c), args, 4u, SferaFields::integer_230, 62u, 78u, SferaFields::buffer_288, 79u,
        81u, SferaFields::integer_288_at_8, 8u, 80u, SferaFields::buffer_229, 32u, 4294967288u, SferaFields::buffer_289,
        SferaFields::buffer_290, 82u, 83u, 84u, 85u, SferaFields::buffer_291, 86u, SferaFields::buffer_292, SferaFields::buffer_294,
        SferaFields::buffer_292_at_12, SferaFields::buffer_295, SferaFields::buffer_293, SferaFields::buffer_298, SferaFields::buffer_300,
        SferaFields::buffer_301, SferaFields::buffer_302, 87u, SferaFields::buffer_182, SferaFunctions::ct_sac_m_TestIt);
}

SferaMbcValue SferaFunctions::ct_sac_m_CheckWght(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CheckWght_body(std::move(c), args, SferaFields::integer_182_at_8, 400u);
}

SferaMbcValue SferaFunctions::npc_questman_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 62u);
}

SferaMbcValue SferaFunctions::npc_questman_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_9222d34b_body(std::move(c), args, SferaFunctions::npc_questman_UseOwner);
}

SferaMbcValue SferaFunctions::npc_questman_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 61u, SferaFields::integer_42, SferaFields::integer_44, 48u,
        SferaFields::integer_45, SferaFields::reference_47, SferaFields::buffer_48, SferaFields::integer_35, SferaFields::integer_46,
        SferaFields::reference_43, SferaFunctions::npc_questman_FlyWeapon);
}

SferaNativeTask SferaFunctions::npc_questman_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_74399034_body(std::move(c), std::move(args), SferaFunctions::npc_questman_ShowHlth);
}

SferaMbcValue SferaFunctions::npc_questman_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 67u);
}

SferaMbcValue SferaFunctions::npc_questman_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 62u, 89u, SferaFields::buffer_83, 69u);
}

SferaMbcValue SferaFunctions::npc_questman_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_b2ae2bad_body(std::move(c), args, SferaFields::integer_49, SferaFields::buffer_50, 5u);
}

SferaMbcValue SferaFunctions::npc_questman_LoadGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_npc_questman_LoadGame_body(std::move(c), args, 14u, SferaFields::buffer_255, 4u, SferaFields::buffer_123);
}

SferaMbcValue SferaFunctions::npc_questman_RcvUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_RcvUser_body(std::move(c), args, 60u, SferaFields::reference_256, SferaFields::buffer_123);
}

SferaMbcValue SferaFunctions::monster_event_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 7u, 67u);
}

SferaMbcValue SferaFunctions::monster_event_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_9aa3d0cf_body(std::move(c), args, 48u, SferaFields::integer_255, SferaFields::integer_269, 51u,
        SferaFields::integer_270, SferaFields::reference_272, SferaFields::buffer_273, SferaFields::integer_200, SferaFields::integer_271,
        SferaFields::reference_268, SferaFunctions::monster_event_FlyWeapon);
}

SferaNativeTask SferaFunctions::monster_event_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_00d2b32e_body(std::move(c), std::move(args), 3u, SferaFunctions::monster_event_ShowHlth);
}

SferaMbcValue SferaFunctions::monster_event_ShowHlth(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_ShowHlth_body(std::move(c), args, SferaFields::integer_62_at_4, 18u, 19u, 86u);
}

SferaMbcValue SferaFunctions::monster_event_FlyWeapon(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_FlyWeapon_body(std::move(c), args, 138u, 139u, SferaFields::buffer_83, 88u);
}

SferaMbcValue SferaFunctions::monster_event_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SndUser_b27242af_body(std::move(c), args, SferaFields::reference_380_at_13, SferaFields::integer_359);
}

SferaNativeTask SferaFunctions::monster_event_checkExit(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_checkExit_body(std::move(c), std::move(args), SferaFields::buffer_361, 1097859072u);
}

SferaMbcValue SferaFunctions::specab_use_send_cuse_to_server(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_use_send_cuse_to_server_body(std::move(c), args, SferaFields::integer_197, 49u, 50u, SferaFields::reference_202,
        SferaFields::buffer_132, 256u, 51u);
}

SferaMbcValue SferaFunctions::specab_TradeMan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_TradeMan_e0a993c7_body(std::move(c), args, 62u, SferaFields::integer_88, SferaFields::integer_0,
        SferaFields::integer_89, 50u, SferaFields::integer_164, SferaFields::reference_182, SferaFields::buffer_186,
        SferaFields::integer_187, SferaFields::integer_183, 19u, 36u, 37u);
}

SferaMbcValue SferaFunctions::specab_LoadMulti(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_LoadMulti_8224bbca_body(std::move(c), args, 76u, 77u, SferaFields::reference_305, SferaFields::buffer_307,
        SferaFields::buffer_36, SferaFields::reference_306, SferaFields::integer_91, SferaFields::integer_40, 52u, SferaFields::buffer_41,
        SferaFields::reference_37, SferaFields::buffer_39);
}

SferaMbcValue SferaFunctions::specab_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_91dd0327_body(std::move(c), args, 78u, 79u, 80u, SferaFields::buffer_38, 28u, SferaFields::buffer_41);
}

SferaMbcValue SferaFunctions::inv_IsItemType(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_IsItemType_body(std::move(c), args, SferaFields::integer_0, 0u, 0u, 1u, 0u);
}

SferaMbcValue SferaFunctions::inv_openSlot(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_openSlot_116adf93_body(std::move(c), args, SferaFields::integer_53_at_7, SferaFields::reference_1,
        SferaFields::reference_55, 0u, SferaFields::reference_56, SferaFields::buffer_59, 131u, SferaFields::buffer_54, 2u,
        SferaFields::reference_58, SferaFields::reference_57);
}

SferaMbcValue SferaFunctions::inv_SetddHan(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_setGxpItem_body(std::move(c), args, SferaFields::integer_198_at_6, SferaFields::integer_3);
}

SferaMbcValue SferaFunctions::inv_InvOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_inv_InvOn_body(std::move(c), args, 37u, SferaFields::integer_89_at_12, SferaFields::buffer_199, SferaFields::buffer_200,
        9u, 5u);
}

SferaMbcValue SferaFunctions::inv_IfInv(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_GetAmount_body(std::move(c), args, SferaFields::integer_89_at_12);
}

SferaMbcValue SferaFunctions::rock_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_8376acdd_body(std::move(c), args, SferaFunctions::rock_UseOwner, SferaFunctions::bank_UseWith);
}

SferaNativeTask SferaFunctions::rock_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_47532592_body(std::move(c), std::move(args), SferaFields::reference_86, SferaFields::integer_85,
        SferaFields::buffer_152, SferaFields::buffer_199, 48u, SferaFunctions::rock_Use);
}

SferaMbcValue SferaFunctions::rock_Client(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Client_body(std::move(c), args, 5u, SferaFields::buffer_182, SferaFields::buffer_200, SferaFields::buffer_201, 7u,
        0u);
}

SferaMbcValue SferaFunctions::rock_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_bank_CheckRights_body(std::move(c), args, SferaFields::integer_5_at_2);
}

SferaMbcValue SferaFunctions::crystalcattr_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_272403a7_body(std::move(c), args, SferaFunctions::crystalcattr_UseOwner);
}

SferaMbcValue SferaFunctions::crystalcattr_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_916cf044_body(std::move(c), args, SferaFunctions::crystalcattr_AddInfo);
}

SferaMbcValue SferaFunctions::crystalcattr_UseOwner(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseOwner_0537a213_body(std::move(c), args, SferaFields::integer_46, 75u, 4u, SferaFields::buffer_179);
}

SferaMbcValue SferaFunctions::crystalcattr_AddInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddInfo_body(std::move(c), args, SferaFields::reference_179_at_18);
}

SferaMbcValue SferaFunctions::specab_mc_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_0943456d_body(std::move(c), args, SferaFunctions::specab_mc_UseWith);
}

SferaNativeTask SferaFunctions::specab_mc_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_9a43a292_body(std::move(c), std::move(args), SferaFunctions::specab_mc_Use);
}

SferaMbcValue SferaFunctions::specab_mc_UseWith(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_UseWith_797ed502_body(std::move(c), args, SferaFunctions::specab_mc_AddCheck);
}

SferaMbcValue SferaFunctions::specab_mc_AddCheck(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_AddCheck_body(std::move(c), args, SferaFields::integer_325, 88u);
}

SferaMbcValue SferaFunctions::table_TableTrig(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_mission_TradeTrig_body(std::move(c), args, SferaFields::integer_165_at_16, SferaFields::integer_3,
        SferaFunctions::table_TableOn, SferaFunctions::table_TableOff);
}

SferaMbcValue SferaFunctions::table_TableOn(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_inv_InvOn_body(std::move(c), args, 43u, SferaFields::integer_3, SferaFields::buffer_166, SferaFields::buffer_167, 13u,
        19u);
}

SferaMbcValue SferaFunctions::table_TableOff(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_invalch_InvOff_body(std::move(c), args, 13u);
}

SferaMbcValue SferaFunctions::fir_main(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_main_3c19d64f_body(std::move(c), args, SferaFunctions::fir_InitObj);
}

SferaMbcValue SferaFunctions::fir_InitObj(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_InitObj_3632f564_body(std::move(c), args, 5u, SferaFields::buffer_201, 4u);
}

SferaNativeTask SferaFunctions::fir_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_47532592_body(std::move(c), std::move(args), SferaFields::reference_86, SferaFields::integer_85,
        SferaFields::buffer_152, SferaFields::buffer_199, 48u, SferaFunctions::cs_knot_Use);
}

SferaMbcValue SferaFunctions::pw_fb05_Use(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_Use_482ac760_body(std::move(c), args, SferaFunctions::flag_UseWith);
}

SferaNativeTask SferaFunctions::pw_fb05_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_2879f135_body(std::move(c), std::move(args), SferaFields::integer_205, SferaFields::reference_214,
        SferaFields::integer_206, SferaFields::integer_213, SferaFields::integer_204, SferaFields::buffer_215, SferaFields::buffer_216,
        59u, SferaFunctions::pw_fb05_Use);
}

SferaMbcValue SferaFunctions::rhomb_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 71u);
}

SferaMbcValue SferaFunctions::rhomb_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_8b2de690_body(std::move(c), args, SferaFunctions::pw_courage_AddInfo);
}

SferaMbcValue SferaFunctions::rhomb_SaveGame(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_npc_questman_LoadGame_body(std::move(c), args, 13u, SferaFields::buffer_0, 6u, SferaFields::buffer_62);
}

SferaNativeTask SferaFunctions::pw_fb02_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_2879f135_body(std::move(c), std::move(args), SferaFields::integer_82, SferaFields::reference_206,
        SferaFields::integer_204, SferaFields::integer_205, SferaFields::integer_44, SferaFields::buffer_213, SferaFields::buffer_214, 58u,
        SferaFunctions::pw_elixir_Use);
}

SferaMbcValue SferaFunctions::vir1041_CallLink(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CallLink_body(std::move(c), args, 3u, 11u);
}

SferaNativeTask SferaFunctions::vir1041_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_54470819_body(std::move(c), std::move(args), 15u, 10u);
}

SferaNativeTask SferaFunctions::incubator_ContMan(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_ContMan_47532592_body(std::move(c), std::move(args), SferaFields::reference_200, SferaFields::integer_199,
        SferaFields::buffer_201, SferaFields::buffer_202, 49u, SferaFunctions::cs_knot_Use);
}

SferaMbcValue SferaFunctions::monstern_SndUser(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_SndUser_b27242af_body(std::move(c), args, SferaFields::reference_358, SferaFields::integer_357);
}

SferaNativeTask SferaFunctions::monsterf_Client(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_Client_00d2b32e_body(std::move(c), std::move(args), 4u, SferaFunctions::cs_guard_ShowHlth);
}

SferaMbcValue SferaFunctions::item_letter_GetInfo(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_GetInfo_8b2de690_body(std::move(c), args, SferaFunctions::bank_AddInfo);
}

SferaNativeTask SferaFunctions::vir1038_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_54470819_body(std::move(c), std::move(args), 2u, 15u);
}

SferaNativeTask SferaFunctions::vir1036_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 15u);
}

SferaNativeTask SferaFunctions::vir1014_main(SferaNativeContext c, std::vector<SferaMbcValue> args)
{
    return sfera_shared_main_e8f28017_body(std::move(c), std::move(args), 5u);
}

SferaMbcValue SferaFunctions::vir1048_CallLink(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_CallLink_body(std::move(c), args, 3u, 26u);
}

SferaMbcValue SferaFunctions::stat_sercli(SferaNativeContext c, std::span<const SferaMbcValue> args)
{
    return sfera_shared_sercli_body(std::move(c), args, 8u, 10u);
}
