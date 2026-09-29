#pragma once
#include "script/NativeContext.h"
#include "script/NativeEntries.h"

SferaMbcValue sfera_shared_IsItemType_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t constant3);
SferaMbcValue sfera_shared_convertTime2Str_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2, std::uint32_t buffer0,
    std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t buffer4, std::uint32_t buffer5,
    std::uint32_t buffer6, std::uint32_t buffer7, std::uint32_t buffer8, std::uint32_t buffer9, std::uint32_t buffer10,
    std::uint32_t buffer11, std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t buffer14,
    std::uint32_t buffer15, std::uint32_t buffer16, std::uint32_t buffer17, std::uint32_t buffer18,
    std::uint32_t buffer19, std::uint32_t buffer20, std::uint32_t buffer21, std::uint32_t buffer22,
    std::uint32_t buffer23, std::uint32_t buffer24, std::uint32_t buffer25);
SferaMbcValue sfera_ai_isFlamount_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_ai_empty_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0);
SferaMbcValue sfera_shared_halt_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_ai_thalt_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t constant0);
SferaMbcValue sfera_shared_sercli_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_shared_main_3c19d64f_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_CheckUseDist_stop_c61b2854_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_CheckUseDist_stop_f16e3b4b_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_CheckUseDist_stop_869d600d_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_bank_DnDRes_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0,
    std::uint32_t integer1);
SferaMbcValue sfera_bank_GetAmount_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_bank_GetModel_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_Effect_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_SetHealth_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_GetWeight_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant1,
    std::uint32_t integer0);
SferaMbcValue sfera_bank_CheckRights_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_bank_SetParent_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_bank_Setabg_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t constant0);
SferaMbcValue sfera_shared_EInit_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1,
    std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3, SferaNativeFunction call0);
SferaMbcValue sfera_bank_froom_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0,
    std::uint32_t integer1);
SferaNativeTask sfera_shared_CheckUseDist_4ec3337b_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_CheckUseDist_f1cf35c1_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_CheckUseDist_606b6da7_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_CheckCanUseOnDistance_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t buffer0);
SferaMbcValue sfera_shared_use_send_cuse_to_server_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t constant1, std::uint32_t reference0,
    std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3);
SferaMbcValue sfera_shared_Use_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t constant0,
    std::uint32_t constant1, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t integer0,
    std::uint32_t buffer2, std::uint32_t constant2, std::uint32_t buffer3, std::uint32_t constant3,
    std::uint32_t buffer4, std::uint32_t integer1);
SferaMbcValue sfera_bank_UseWith_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0);
SferaMbcValue sfera_bank_CheckPut_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_GetP_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t buffer0,
    std::uint32_t constant0, std::uint32_t buffer1, std::uint32_t integer0);
SferaMbcValue sfera_shared_TradeMan_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t constant1, std::uint32_t integer3, std::uint32_t reference0, std::uint32_t buffer0,
    std::uint32_t integer4, std::uint32_t integer5, std::uint32_t constant2, std::uint32_t constant3);
SferaMbcValue sfera_shared_getItemName_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0);
SferaMbcValue sfera_shared_getNeutralInfo_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0);
SferaMbcValue sfera_shared_GetInfo_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t reference0, std::uint32_t integer0,
    std::uint32_t buffer0, std::uint32_t integer1, std::uint32_t integer2, std::uint32_t reference1,
    std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t constant2, std::uint32_t constant3,
    std::uint32_t buffer3, std::uint32_t buffer4, std::uint32_t buffer5, std::uint32_t integer3,
    std::uint32_t integer4, std::uint32_t reference2, std::uint32_t buffer6, std::uint32_t reference3,
    std::uint32_t buffer7, std::uint32_t reference4, std::uint32_t buffer8, std::uint32_t reference5,
    std::uint32_t buffer9, std::uint32_t reference6, std::uint32_t reference7, std::uint32_t buffer10,
    std::uint32_t buffer11, std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t real0,
    std::uint32_t integer5, std::uint32_t real1, std::uint32_t constant4, std::uint32_t buffer14,
    std::uint32_t buffer15, std::uint32_t constant5, std::uint32_t constant6, std::uint32_t buffer16,
    std::uint32_t buffer17, std::uint32_t buffer18, std::uint32_t buffer19, std::uint32_t buffer20,
    std::uint32_t buffer21, std::uint32_t buffer22);
SferaMbcValue sfera_shared_createInfoSeparatorLine_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0);
SferaMbcValue sfera_shared_AddInfo_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0);
SferaMbcValue sfera_shared_Client_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t buffer2,
    std::uint32_t constant1, std::uint32_t constant2);
SferaMbcValue sfera_bank_setGxpItem_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1);
SferaMbcValue sfera_shared_GetPrice_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1);
SferaMbcValue sfera_shared_PutHere_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_PutHere_a7cd8f11_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_bank_GetHealth_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_shared_CheckIndex_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_sendslot_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t reference0, std::uint32_t constant1,
    std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3, std::uint32_t buffer1);
SferaMbcValue sfera_shared_TestIt_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t buffer1, std::uint32_t constant6, SferaNativeFunction call0,
    SferaNativeFunction call1);
SferaMbcValue sfera_shared_TestIt_c06a4fe6_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t buffer1, std::uint32_t constant6, SferaNativeFunction call0,
    SferaNativeFunction call1);
SferaMbcValue sfera_shared_TestIt_694e7ae7_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t buffer1, std::uint32_t constant6, SferaNativeFunction call0);
SferaMbcValue sfera_shared_TestIt_d8a2dcca_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t buffer1, std::uint32_t constant6, SferaNativeFunction call0,
    SferaNativeFunction call1);
SferaMbcValue sfera_shared_SeekTag_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t integer1,
    std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3, std::uint32_t integer2);
SferaMbcValue sfera_shared_SeekTagInsideNoRecursive_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t integer1,
    std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3);
SferaMbcValue sfera_shared_SetOverFill_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t integer1, std::uint32_t constant1,
    std::uint32_t constant2, std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4);
SferaMbcValue sfera_shared_CheckWght_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_AddWght_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t integer0, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t buffer1);
SferaMbcValue sfera_shared_FreeIt1_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t integer0, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t buffer1);
SferaMbcValue sfera_shared_FreeIt_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t integer1, std::uint32_t constant1,
    std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3, std::uint32_t buffer1);
SferaMbcValue sfera_bank_GetSlotID_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_bank_TestMe_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0,
    std::uint32_t integer1, std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_shared_GetMySlot_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_shared_openSlot_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t reference1, std::uint32_t reference2,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t reference3, std::uint32_t reference4);
SferaMbcValue sfera_bank_WinAuth_stop_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1);
SferaMbcValue sfera_shared_DigSeparate_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t reference1, std::uint32_t constant0, std::uint32_t buffer0,
    std::uint32_t integer0, std::uint32_t integer1, std::uint32_t integer2);
SferaMbcValue sfera_shared_DigSeparateInt_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_bank_WinBank_helper_5442bb6c_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1, std::uint32_t buffer0, std::uint32_t real0, std::uint32_t real1,
    std::uint32_t constant0, std::uint32_t buffer1, std::uint32_t constant1, std::uint32_t integer2,
    std::uint32_t integer3, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t buffer4, std::uint32_t buffer5);
SferaMbcValue sfera_bank_GetKomiss_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t byte0);
SferaMbcValue sfera_char_Animating_stop_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1);
SferaMbcValue sfera_shared_openSlot_116adf93_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t reference1, std::uint32_t constant0,
    std::uint32_t reference2, std::uint32_t buffer0, std::uint32_t constant1, std::uint32_t buffer1,
    std::uint32_t constant2, std::uint32_t reference3, std::uint32_t reference4);
SferaMbcValue sfera_invalch_InvTrig_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, SferaNativeFunction call0, SferaNativeFunction call1);
SferaMbcValue sfera_mission_TradeTrig_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1, SferaNativeFunction call0, SferaNativeFunction call1);
SferaMbcValue sfera_inv_InvOn_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t constant0,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_invalch_InvOn_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_invalch_InvOff_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_main_WinAsyncInput_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t reference1, std::uint32_t constant0,
    std::uint32_t constant1);
SferaMbcValue sfera_main_HideConsole_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_main_cleanse_buffs_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t buffer1, std::uint32_t constant1);
SferaMbcValue sfera_main_cm_create_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_main_cm_isVisible_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t integer1, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_main_GetCastleName_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1,
    std::uint32_t constant2, std::uint32_t buffer1, std::uint32_t constant3);
SferaMbcValue sfera_main_GMOD_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_main_getLastGVG_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_main_SetTmntState_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_main_GetXYZ_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_main_GetMainServerURL_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_main_Camera_stop_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0);
SferaMbcValue sfera_pcontrol_ControlOff_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0);
SferaMbcValue sfera_pcontrol_WinDiary_helper_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_pcontrol_stopWinGroupExist_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_pcontrol_runRefreshWinGroupList_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1, std::uint32_t constant0);
SferaMbcValue sfera_pcontrol_DropAsk_stop_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_pcontrol_CloseScroll_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_pcontrol_TABLE_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_pcontrol_EvacPlayerWinPrg_helper_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_pcontrol_UpdateTmntWin_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_shared_IsForceDamager_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t byte0);
SferaMbcValue sfera_shared_FillBalanceGVG_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_player_cleanse_buffs_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1, std::uint32_t buffer0,
    std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t constant0, std::uint32_t buffer3,
    std::uint32_t constant1, std::uint32_t buffer4, std::uint32_t buffer5);
SferaMbcValue sfera_player_Effect_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_EInit_0c1a1db3_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1, std::uint32_t reference0,
    std::uint32_t buffer1, std::uint32_t constant2, std::uint32_t integer0, std::uint32_t constant3,
    std::uint32_t constant4);
SferaMbcValue sfera_shared_Recalc_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1,
    std::uint32_t constant2, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t constant5,
    std::uint32_t constant6);
SferaMbcValue sfera_shared_Use_97811cb2_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Use_9222d34b_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Use_8376acdd_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0, SferaNativeFunction call1);
SferaMbcValue sfera_shared_Use_333d080e_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Use_672f849d_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ShowKill_ba13cfba_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t integer0, std::uint32_t constant1,
    std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t constant2, std::uint32_t buffer3,
    std::uint32_t constant3, std::uint32_t buffer4, std::uint32_t buffer5, std::uint32_t buffer6,
    std::uint32_t buffer7, std::uint32_t buffer8, std::uint32_t constant4, std::uint32_t buffer9,
    std::uint32_t buffer10, std::uint32_t buffer11, std::uint32_t buffer12, std::uint32_t buffer13,
    std::uint32_t buffer14, std::uint32_t constant5, std::uint32_t constant6, std::uint32_t constant7);
SferaMbcValue sfera_shared_NotEmptyCont_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t buffer1,
    std::uint32_t constant1);
SferaMbcValue sfera_shared_SendOffer_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t reference0, std::uint32_t buffer0,
    std::uint32_t constant1);
SferaMbcValue sfera_shared_Params_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_ShowHlth_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2);
SferaMbcValue sfera_shared_FlyWeapon_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t buffer0, std::uint32_t constant2);
SferaNativeTask sfera_shared_CheckSpec_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t constant1,
    std::uint32_t constant2, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t constant5,
    std::uint32_t buffer1, std::uint32_t constant6, std::uint32_t constant7, std::uint32_t constant8);
SferaMbcValue sfera_shared_getCreatureLevel_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_TestIt_ed86e89b_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2);
SferaMbcValue sfera_shared_TestPut_ae2aa720_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t constant6, std::uint32_t buffer1, std::uint32_t constant7,
    std::uint32_t constant8, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t constant9,
    std::uint32_t constant10, std::uint32_t constant11, std::uint32_t constant12, std::uint32_t buffer4,
    std::uint32_t constant13, std::uint32_t buffer5, std::uint32_t buffer6, std::uint32_t buffer7,
    std::uint32_t buffer8, std::uint32_t buffer9, std::uint32_t buffer10, std::uint32_t buffer11,
    std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t constant14, std::uint32_t buffer14,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_TestPut_4816c116_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t constant6, std::uint32_t buffer1, std::uint32_t constant7,
    std::uint32_t constant8, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t constant9,
    std::uint32_t constant10, std::uint32_t constant11, std::uint32_t constant12, std::uint32_t buffer4,
    std::uint32_t constant13, std::uint32_t buffer5, std::uint32_t buffer6, std::uint32_t buffer7,
    std::uint32_t buffer8, std::uint32_t buffer9, std::uint32_t buffer10, std::uint32_t buffer11,
    std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t constant14, SferaNativeFunction call0);
SferaMbcValue sfera_shared_TestPut_acf82001_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t constant6, std::uint32_t buffer1, std::uint32_t constant7,
    std::uint32_t constant8, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t constant9,
    std::uint32_t constant10, std::uint32_t constant11, std::uint32_t constant12, std::uint32_t buffer4,
    std::uint32_t constant13, std::uint32_t buffer5, std::uint32_t buffer6, std::uint32_t buffer7,
    std::uint32_t buffer8, std::uint32_t buffer9, std::uint32_t buffer10, std::uint32_t buffer11,
    std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t constant14, std::uint32_t buffer14,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_TestPut_29d8322a_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t constant6, std::uint32_t buffer1, std::uint32_t constant7,
    std::uint32_t constant8, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t constant9,
    std::uint32_t constant10, std::uint32_t constant11, std::uint32_t constant12, std::uint32_t buffer4,
    std::uint32_t constant13, std::uint32_t buffer5, std::uint32_t buffer6, std::uint32_t buffer7,
    std::uint32_t buffer8, std::uint32_t buffer9, std::uint32_t buffer10, std::uint32_t buffer11,
    std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t constant14, std::uint32_t buffer14,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_TestPut_99840dcc_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t integer1,
    std::uint32_t constant5, std::uint32_t constant6, std::uint32_t buffer1, std::uint32_t constant7,
    std::uint32_t constant8, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t constant9,
    std::uint32_t constant10, std::uint32_t constant11, std::uint32_t buffer4, std::uint32_t buffer5,
    std::uint32_t buffer6, std::uint32_t buffer7, std::uint32_t buffer8, std::uint32_t buffer9, std::uint32_t buffer10,
    std::uint32_t buffer11, std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t buffer14);
SferaMbcValue sfera_shared_AddWght_1a621d44_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1,
    std::uint32_t constant2, std::uint32_t buffer1);
SferaMbcValue sfera_shared_FreeIt1_b6fd1824_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t constant1, std::uint32_t buffer0,
    std::uint32_t constant2, std::uint32_t constant3, std::uint32_t buffer1, std::uint32_t buffer2,
    std::uint32_t constant4);
SferaMbcValue sfera_shared_StartClanEff_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t reference0, std::uint32_t constant1, std::uint32_t buffer0,
    std::uint32_t constant2);
SferaMbcValue sfera_player_SendSys2_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2, std::uint32_t reference0,
    std::uint32_t constant3);
SferaMbcValue sfera_player_Getabg_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t constant0);
SferaMbcValue sfera_player_WinLink_stop_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0);
SferaMbcValue sfera_player_deleteSomeoneFromGroup_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t constant0);
SferaMbcValue sfera_player_deleteMeFroupGroup_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_player_setArtisanID_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1, std::uint32_t constant0);
SferaMbcValue sfera_player_callCloseCustomerWorkshop_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_player_resetArtisanData_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_GetWeight_716186f6_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1, std::uint32_t integer0,
    std::uint32_t integer1);
SferaMbcValue sfera_shared_use_is_stack_use_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_UseOwner_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t buffer1,
    std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t buffer4, std::uint32_t buffer5);
SferaMbcValue sfera_shared_UseOwner_fef98b01_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_GetP_28e3779b_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1);
SferaNativeTask sfera_shared_ContMan_5b3982b3_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1,
    std::uint32_t integer2, std::uint32_t integer3, std::uint32_t buffer0, std::uint32_t buffer1,
    std::uint32_t constant1);
SferaNativeTask sfera_shared_Main_body(SferaNativeContext c, std::vector<SferaMbcValue> args, std::uint32_t constant0,
    std::uint32_t constant1);
SferaMbcValue sfera_shared_Use_272403a7_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_9a43a292_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_ec757611_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0);
SferaNativeTask sfera_shared_ContMan_aaa013db_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0, SferaNativeFunction call1);
SferaMbcValue sfera_shared_GetInfo_916cf044_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_8ed35db2_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_ar_ring_SndUser_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0);
SferaMbcValue sfera_shared_RcvUser_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t reference0, std::uint32_t buffer0);
SferaMbcValue sfera_shared_Client_879a99f1_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_InitObj_3632f564_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1);
SferaMbcValue sfera_shared_Use_37be24d5_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Use_06f4a581_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Use_726bc4f3_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Use_06611310_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_ac62c630_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_71b7a3a5_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_a553e68b_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_GetInfo_05e952b4_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_RcvUser_0d2d5d95_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0);
SferaMbcValue sfera_shared_LoadGame_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t integer0);
SferaMbcValue sfera_shared_SaveGame_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t integer0);
SferaMbcValue sfera_shared_Use_951304c9_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_TradeMan_9aa3d0cf_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t integer1, std::uint32_t constant1,
    std::uint32_t integer2, std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t integer3,
    std::uint32_t integer4, std::uint32_t reference1, SferaNativeFunction call0);
SferaMbcValue sfera_shared_Client_f837f5b8_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_crt02_MaxDist_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2, std::uint32_t constant3);
SferaMbcValue sfera_shared_UseOwner_163ef7d4_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_RcvUser_6ce5a504_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1);
SferaMbcValue sfera_shared_UseOwner_0537a213_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t constant1, std::uint32_t buffer0);
SferaMbcValue sfera_shared_Client_d03707f6_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t buffer2,
    std::uint32_t constant1, std::uint32_t buffer3);
SferaMbcValue sfera_shared_EInit_77c2afeb_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t reference0, std::uint32_t integer0, std::uint32_t integer1,
    std::uint32_t integer2, std::uint32_t integer3);
SferaMbcValue sfera_shared_TradeMan_a494cfe9_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t constant1, std::uint32_t integer3, std::uint32_t reference0, std::uint32_t buffer0,
    std::uint32_t integer4, std::uint32_t integer5);
SferaMbcValue sfera_shared_CheckWght_17921366_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_FreeIt_671a8fab_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t integer0, std::uint32_t constant2,
    std::uint32_t buffer0, std::uint32_t constant3, std::uint32_t constant4, std::uint32_t buffer1);
SferaMbcValue sfera_shared_UseOwner_12088b0e_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1, SferaNativeFunction call0);
SferaMbcValue sfera_shared_UseOwner_b2ae2bad_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_AddInfo_30c23da7_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t buffer2,
    std::uint32_t buffer3, std::uint32_t buffer4);
SferaNativeTask sfera_shared_ContMan_d1eccf3b_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Client_237abbb1_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_RcvG_body(SferaNativeContext c, std::span<const SferaMbcValue> args, std::uint32_t integer0,
    std::uint32_t integer1, std::uint32_t integer2, std::uint32_t integer3, std::uint32_t integer4,
    std::uint32_t buffer0, std::uint32_t integer5, std::uint32_t integer6, std::uint32_t buffer1,
    std::uint32_t integer7);
SferaMbcValue sfera_shared_GetAddrs_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t reference1, std::uint32_t reference2, std::uint32_t reference3,
    std::uint32_t reference4, std::uint32_t reference5, std::uint32_t reference6, std::uint32_t reference7,
    std::uint32_t reference8);
SferaMbcValue sfera_cs_table_GetCastleNum_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_EInit_9d76123b_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0, std::uint32_t constant0, std::uint32_t integer1,
    std::uint32_t constant1, std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3,
    std::uint32_t integer2, std::uint32_t integer3, std::uint32_t integer4, std::uint32_t constant4,
    std::uint32_t constant5, SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_beb84fb0_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0, std::uint32_t buffer2,
    std::uint32_t constant1, std::uint32_t constant2, std::uint32_t buffer3, std::uint32_t constant3,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_c22d77f4_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2, SferaNativeFunction call0);
SferaMbcValue sfera_shared_LoadGame_d921e1d9_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t integer0, std::uint32_t buffer1,
    std::uint32_t constant1, std::uint32_t integer1);
SferaMbcValue sfera_shared_SaveGame_e9053998_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t integer0, std::uint32_t buffer1,
    std::uint32_t constant1, std::uint32_t integer1);
SferaMbcValue sfera_shared_AddInfo_70b136b5_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t integer0, std::uint32_t buffer1);
SferaMbcValue sfera_shared_froom_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t integer1);
SferaNativeTask sfera_shared_ContMan_3738afb9_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1,
    std::uint32_t integer2, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant1,
    std::uint32_t constant2, std::uint32_t buffer2, std::uint32_t constant3, std::uint32_t constant4,
    std::uint32_t buffer3, std::uint32_t constant5, SferaNativeFunction call0, SferaNativeFunction call1);
SferaMbcValue sfera_shared_GetInfo_be50c274_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t reference0, std::uint32_t integer0,
    std::uint32_t buffer0, std::uint32_t integer1, std::uint32_t integer2, std::uint32_t reference1,
    std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t constant2, std::uint32_t constant3,
    std::uint32_t buffer3, std::uint32_t buffer4, std::uint32_t buffer5, std::uint32_t integer3,
    std::uint32_t integer4, std::uint32_t reference2, std::uint32_t buffer6, std::uint32_t reference3,
    std::uint32_t buffer7, std::uint32_t reference4, std::uint32_t buffer8, std::uint32_t reference5,
    std::uint32_t buffer9, std::uint32_t reference6, std::uint32_t reference7, std::uint32_t buffer10,
    std::uint32_t buffer11, std::uint32_t buffer12, std::uint32_t buffer13, std::uint32_t buffer14,
    std::uint32_t buffer15, std::uint32_t integer5, std::uint32_t real0, std::uint32_t integer6, std::uint32_t real1,
    std::uint32_t constant4, std::uint32_t buffer16, std::uint32_t buffer17, std::uint32_t constant5,
    std::uint32_t constant6, std::uint32_t buffer18, std::uint32_t buffer19, std::uint32_t buffer20,
    std::uint32_t buffer21, std::uint32_t buffer22, std::uint32_t buffer23, std::uint32_t buffer24);
SferaNativeTask sfera_shared_UseAll_body(SferaNativeContext c, std::vector<SferaMbcValue> args, std::uint32_t integer0,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2, std::uint32_t buffer0,
    std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t buffer4);
SferaMbcValue sfera_ct_cbook1_WinMacros_helper_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t integer0, std::uint32_t constant0, std::uint32_t integer1,
    std::uint32_t buffer1, std::uint32_t reference0, std::uint32_t buffer2, std::uint32_t buffer3,
    std::uint32_t buffer4, std::uint32_t buffer5, std::uint32_t integer2, std::uint32_t buffer6, std::uint32_t buffer7,
    std::uint32_t buffer8, SferaNativeFunction call0);
SferaMbcValue sfera_shared_CalcMacroID_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t constant1, std::uint32_t integer1,
    std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3, std::uint32_t buffer1,
    std::uint32_t buffer2, std::uint32_t buffer3, std::uint32_t buffer4, std::uint32_t buffer5, std::uint32_t buffer6,
    std::uint32_t buffer7, std::uint32_t buffer8);
SferaMbcValue sfera_shared_SaveGame_0f9f3fa3_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t integer0, std::uint32_t buffer1,
    std::uint32_t constant1, std::uint32_t integer1, std::uint32_t buffer2, std::uint32_t constant2,
    std::uint32_t integer2);
SferaMbcValue sfera_shared_Main_bc3f8381_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_ct_chest_pr_LoadGame_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0);
SferaNativeTask sfera_shared_ContMan_70a36942_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0, std::uint32_t buffer2,
    std::uint32_t constant1, std::uint32_t constant2, std::uint32_t buffer3, std::uint32_t constant3,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_LoadGame_15715a6c_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_47532592_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t buffer1,
    std::uint32_t constant0, SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_bd245d6a_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0, SferaNativeFunction call0);
SferaNativeTask sfera_shared_Server_accf726a_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_use_is_stack_use_f003d3d6_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_UseOwner_d374b741_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t constant1,
    std::uint32_t constant2);
SferaMbcValue sfera_shared_Use_51d953eb_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0, SferaNativeFunction call1);
SferaMbcValue sfera_shared_UseWith_91dd0327_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2, std::uint32_t buffer0,
    std::uint32_t constant3, std::uint32_t buffer1);
SferaMbcValue sfera_shared_GetInfo_0865b773_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_UseOwner_c7bed929_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_shared_GetInfo_10e3b377_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t reference0, std::uint32_t constant2,
    std::uint32_t constant3);
SferaMbcValue sfera_shared_GetInfo_8b2de690_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_EKill_a28ec083_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_UseOwner_d698e4fa_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t buffer1,
    std::uint32_t buffer2, std::uint32_t constant1);
SferaMbcValue sfera_shared_use_check_frquse_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2);
SferaMbcValue sfera_shared_Use_acb71a1f_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_4e681af7_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_TradeMan_ec1497dc_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t constant1, std::uint32_t integer3, std::uint32_t reference0, std::uint32_t buffer0,
    std::uint32_t integer4, std::uint32_t integer5, std::uint32_t constant2, std::uint32_t constant3,
    std::uint32_t constant4);
SferaMbcValue sfera_shared_LoadMulti_8224bbca_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t reference0, std::uint32_t buffer0,
    std::uint32_t buffer1, std::uint32_t reference1, std::uint32_t integer0, std::uint32_t integer1,
    std::uint32_t constant2, std::uint32_t buffer2, std::uint32_t reference2, std::uint32_t buffer3);
SferaMbcValue sfera_shared_UseWith_73bcb877_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_SndUser_4e1c6ed9_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0);
SferaMbcValue sfera_mg_workshop_resetFlagAcceptCraft_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaNativeTask sfera_shared_Client_00d2b32e_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0, SferaNativeFunction call0);
SferaMbcValue sfera_shared_SndUser_b27242af_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0);
SferaNativeTask sfera_shared_checkExit_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_UseOwner_4e68596a_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0);
SferaNativeTask sfera_shared_main_b95468e9_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_shared_GetP_b4e2eadb_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0, std::uint32_t buffer1, std::uint32_t buffer2,
    std::uint32_t integer0, std::uint32_t constant1, std::uint32_t reference0, std::uint32_t buffer3,
    std::uint32_t buffer4);
SferaMbcValue sfera_shared_TradeMan_56750d0a_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1,
    std::uint32_t constant1, std::uint32_t buffer0, std::uint32_t constant2, std::uint32_t constant3,
    std::uint32_t buffer1, std::uint32_t integer2, std::uint32_t buffer2, std::uint32_t buffer3,
    std::uint32_t constant4, std::uint32_t integer3, std::uint32_t buffer4, std::uint32_t integer4,
    std::uint32_t integer5, std::uint32_t reference1, SferaNativeFunction call0);
SferaMbcValue sfera_shared_Client_ee7fcfe6_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t buffer2,
    std::uint32_t constant1, std::uint32_t buffer3, SferaNativeFunction call0);
SferaMbcValue sfera_shared_sendslot_57e7a4f4_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0, std::uint32_t reference0, std::uint32_t buffer0,
    std::uint32_t constant1, std::uint32_t constant2, std::uint32_t buffer1);
SferaMbcValue sfera_shared_AddUser_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t reference1, std::uint32_t constant0, std::uint32_t constant1,
    std::uint32_t reference2, std::uint32_t buffer0, std::uint32_t integer0, std::uint32_t constant2);
SferaMbcValue sfera_shared_UseOwner_da1ada41_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2);
SferaMbcValue sfera_shared_UseOff_16bdcf23_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1);
SferaNativeTask sfera_shared_Client_521c60b3_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant1,
    std::uint32_t buffer2, std::uint32_t integer0, std::uint32_t buffer3, SferaNativeFunction call0);
SferaMbcValue sfera_shared_LoadGame_27247a3d_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0);
SferaMbcValue sfera_shared_SndUser_220b86e4_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0);
SferaNativeTask sfera_shared_Client_74399034_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_UseWith_971db48c_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2);
SferaMbcValue sfera_shared_RcvUser_f24e678e_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0);
SferaMbcValue sfera_shared_RcvUser_4da80933_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0);
SferaMbcValue sfera_shared_UseOwner_d5e4132b_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_npc_questman_LoadGame_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t constant1, std::uint32_t buffer1);
SferaMbcValue sfera_shared_CheckFree_cb6772d8_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_Use_482ac760_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_2879f135_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t integer3, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_GetInfo_290d4145_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaNativeTask sfera_shared_ContMan_f3052ab3_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_RcvUser_1cb0dfbe_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant0,
    std::uint32_t buffer1);
SferaMbcValue sfera_shared_UseWith_eb82aad4_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2, std::uint32_t constant3,
    std::uint32_t buffer0);
SferaMbcValue sfera_shared_UseWith_797ed502_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_GetMMChr_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0,
    std::uint32_t constant1, std::uint32_t constant2, std::uint32_t buffer2, std::uint32_t buffer3,
    std::uint32_t integer0);
SferaMbcValue sfera_shared_RcvUser_042b69ba_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t constant0,
    std::uint32_t constant1, std::uint32_t buffer2, std::uint32_t buffer3);
SferaMbcValue sfera_shared_UseOwner_6a9e1c1e_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t buffer3,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_TradeMan_e0a993c7_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t integer0, std::uint32_t integer1, std::uint32_t integer2,
    std::uint32_t constant1, std::uint32_t integer3, std::uint32_t reference0, std::uint32_t buffer0,
    std::uint32_t integer4, std::uint32_t integer5, std::uint32_t constant2, std::uint32_t constant3,
    std::uint32_t constant4);
SferaMbcValue sfera_shared_Use_0943456d_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    SferaNativeFunction call0);
SferaMbcValue sfera_shared_AddCheck_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_UseWith_91afe4f1_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1, std::uint32_t constant2);
SferaNativeTask sfera_shared_Main_87f167e6_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_CheckPut_2915b058_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_st_map_LoadGame_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t buffer3);
SferaMbcValue sfera_shared_FillPict_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t buffer0, std::uint32_t constant0);
SferaNativeTask sfera_shared_Cli_body(SferaNativeContext c, std::vector<SferaMbcValue> args, std::uint32_t constant0);
SferaMbcValue sfera_shared_GetTP_94aedd18_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_shared_UseClient_01e86a2a_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0, std::uint32_t buffer0);
SferaMbcValue sfera_shared_AddInfo_398d065f_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t buffer1,
    std::uint32_t constant0, std::uint32_t buffer2, std::uint32_t constant1);
SferaMbcValue sfera_shared_UseOwner_6f891cc9_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t integer0);
SferaNativeTask sfera_shared_main_e8f28017_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_main_ebc3160a_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0);
SferaMbcValue sfera_shared_CallLink_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaNativeTask sfera_shared_main_54470819_body(SferaNativeContext c, std::vector<SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sfera_virus_GetModifiers_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_RcvUser_1b363b1a_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t reference0, std::uint32_t constant1, std::uint32_t reference1,
    std::uint32_t integer0, std::uint32_t buffer0);
SferaMbcValue sfera_shared_AddInfo_dba28d1d_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0, std::uint32_t buffer0, std::uint32_t constant0,
    std::uint32_t constant1);
SferaMbcValue sfera_shared_UseClient_7e1b9bcc_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t reference0, std::uint32_t integer0);
SferaMbcValue sfera_shared_PullOut_a9e0a32b_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t constant0);
SferaMbcValue sfera_shared_UseOff_1f1a0acb_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t buffer0, std::uint32_t buffer1, std::uint32_t buffer2, std::uint32_t constant0);
SferaMbcValue sfera_shared_UseWith_9066b1cf_body(SferaNativeContext c, std::span<const SferaMbcValue> args,
    std::uint32_t constant0, std::uint32_t constant1);
SferaMbcValue sferaHost2(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost3(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost4(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost5(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost6(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost7(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost9(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost10(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost11(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost12(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost13(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost14(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost15(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost16(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost17(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost18(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost19(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost20(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost21(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost24(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost26(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost27(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost28(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost29(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost30(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost31(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost33(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost34(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost35(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost36(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost37(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost38(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost39(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost40(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost41(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost42(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost43(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost44(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost45(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost46(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost47(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost48(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost49(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost50(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost51(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost52(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost53(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost54(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost55(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost56(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost57(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost58(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost59(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost60(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost61(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost62(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost63(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost65(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost66(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost67(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost68(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost69(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost70(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost71(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost72(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost73(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost75(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost76(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost77(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost78(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost79(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost81(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost82(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost83(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost84(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost85(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost86(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost87(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost88(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost89(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost90(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost91(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost92(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost93(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost94(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost95(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost96(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost97(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost98(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost99(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost100(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost101(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost102(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost103(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost104(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost105(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost106(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost107(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost108(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost110(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost111(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost112(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost113(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost114(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost115(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost117(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost118(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost119(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost121(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost122(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost123(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost124(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost126(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost128(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost129(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost132(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost148(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost149(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost150(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost151(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost152(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost154(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost155(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost156(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost157(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost158(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost159(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost161(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost162(SferaNativeContext &c, std::span<const SferaMbcValue> args);
SferaMbcValue sferaHost163(SferaNativeContext &c, std::span<const SferaMbcValue> args);
