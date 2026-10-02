#pragma once

#include "script/MbcNative.h"

namespace SphereScripts
{
class ScriptHelpers;

enum class MultiObjectMode : std::int32_t
{
    None = 0,
    E = 69,
    N = 78,
    R = 82,
    S = 83,
    U = 85
};

struct MultiObjectParameters
{
    std::int32_t mergeMode{};
    std::int32_t primaryScale{};
    std::array<std::int32_t, 4> fixedValues{};
    std::array<std::int32_t, 8> conditionalScaledValues{};
    std::array<std::int32_t, 4> coreValues{};
    std::array<std::int32_t, 14> scaledModifiers{};
    std::array<std::int32_t, 2> percentageModifiers{};
    std::int32_t additiveModifier{};
    std::array<std::int32_t, 2> percentageAdjustments{};
    std::array<std::int32_t, 2> overrides{};
    std::int32_t durationUnits{};
    std::int32_t runtimeValue{};
    std::int32_t interactionArgument{};
    std::int32_t auxiliaryArgument{};
    std::int32_t effectId{};
};

struct MultiObject
{
    std::string script;
    std::string primaryResource;
    std::string secondaryResource;
    std::string primaryQualifier;
    std::string secondaryQualifier;
    MultiObjectParameters parameters;
    std::optional<std::int32_t> numericSelector;
    std::string textSelector;
    MultiObjectMode variantMode{MultiObjectMode::None};
    MultiObjectMode resolvedMode{MultiObjectMode::None};
    std::int32_t scale{-1};
    std::string attributes;
    std::optional<std::int32_t> modifierCode;
    std::optional<std::int32_t> modifierLevel;
    std::array<bool, 26> flags{};
    std::int32_t group{-1};
};

struct MultiObjectActionParameters
{
    std::int32_t interactionArgument{};
    std::int32_t auxiliaryArgument{};
    std::int32_t effectId{};
};

struct EffectDefinition
{
    std::int32_t projectileEffectId{};
    std::int32_t sourceEffectId{};
    std::int32_t impactEffectId{};
    std::int32_t targetEffectId{};
    std::int32_t travelDurationPercent{};
    std::string projectileResource;
};

struct ShopItemSelection
{
    std::int32_t objectId{};
    std::int32_t variant{};
};

struct UniqueDefinition
{
    std::int32_t id{};
    std::int32_t group{};
    std::int32_t initialRemaining{};
    bool active{};
    std::string text;
    std::int32_t remaining{};
    std::int32_t revision{};
    std::int32_t reserved0{};
    std::int32_t reserved1{};
};

enum class Entry : std::uint16_t
{
    None,
    AAsk,
    ADDCO,
    ActivatePopup,
    ActivityCtrlWnd,
    AddCheck,
    AddEnemy,
    AddInfo,
    AddPlayerGVG,
    AddPrayer,
    AddToDiary,
    AddToIgnoreList,
    AddUser,
    AddUserInit,
    AddWght,
    AngleBound,
    AngleOffset,
    Anim,
    Animating,
    AppKey,
    Ask,
    AskAlly,
    AskClanSymbol,
    AskForFile,
    AskLnk,
    AskMemb,
    AtoR,
    AttachText,
    AttachType,
    AutoMode,
    AutobattleController,
    AutobattleHandler,
    BalanceGVG,
    BankOper,
    BeFree,
    BearerShine,
    Bezier,
    BezierVA,
    BnkTrd,
    BoundValue,
    BuyIt,
    BuyItBnk,
    CPar,
    CRR,
    CSUII,
    CUSEM,
    CalcByLevel,
    CalcByLevelOnlyDamages,
    CalcByLevelPrg,
    CalcByLevel_ComputeCoeffs,
    CalcMacroID,
    CalcParam,
    CalcParamCli,
    CalcRash,
    CalcRequirs,
    CalcType,
    CallEnd,
    CallLink,
    CallPict,
    CamOff,
    CamOn,
    Camera,
    CanBeTraded,
    Capture_Progress_on_client,
    CastProgressBar,
    CenterObj,
    ChangeAmount,
    Chat,
    ChatHdl,
    CheckActionHelp,
    CheckAnim,
    CheckCanUseOnDistance,
    CheckCastle,
    CheckExit,
    CheckForTrade,
    CheckFree,
    CheckGround,
    CheckIndex,
    CheckLink,
    CheckLinking,
    CheckMob,
    CheckMoving,
    CheckOpenRights,
    CheckOwnImage,
    CheckPets,
    CheckPing,
    CheckPlayer,
    CheckPut,
    CheckRights,
    CheckRoar,
    CheckRoom,
    CheckServer,
    CheckSpec,
    CheckTest,
    CheckTrade,
    CheckUse,
    CheckUseDist,
    CheckWeapon,
    CheckWght,
    ClanEffect,
    ClearRooms,
    ClearScale,
    Cli,
    Client,
    ClientSky,
    CloseCont,
    CloseDiary,
    CloseScroll,
    ComputeParamsCrc,
    ConnResult,
    Console,
    ConsoleWindow,
    ContMan,
    ContTOut,
    ContourManager,
    Control,
    ControlMove,
    ControlOff,
    ControlOn,
    Conts,
    ConvertGXPInRealType,
    CopyAb,
    CountAnim,
    CountKnot,
    CraftString,
    CreateObj,
    CreateObjWait,
    CreateProgressBar,
    CreateUmap,
    CrystalsCantPutOnPuppet,
    Cursor,
    CursorShapeWatcher,
    CycleReceive,
    CycleSend,
    DDBG,
    DHunger,
    DecStonesCntr,
    DecodeClannameForEmblem,
    DelMis,
    DelTime,
    DeletePlayerGVG,
    DeltaAngleBound,
    DestroyObj,
    DestroyProgressBar,
    DigSeparate,
    DigSeparateInt,
    DirectOfObj,
    DnD,
    DnDRes,
    DnDResP,
    DoBoom,
    DragAndDropObjectMover,
    DragDrop,
    DrawScale,
    DropAsk,
    EDyn,
    EError,
    EHalt,
    EInit,
    EKill,
    ELoot,
    ELostcont,
    EPHalt,
    EStat,
    Effect,
    EffectWrapper,
    EnableEmptyChecks,
    EnableShopButton,
    Ensc,
    EvacPlayerWinPrg,
    ExtraGlobalData,
    FCls,
    FFLBP,
    FW,
    FWAsk,
    FW_client_server,
    FillBalanceGVG,
    FillPict,
    FillPlayersGVG,
    FillSeed,
    FillSkinParams,
    Fire,
    FloatArrayAdd,
    Flush,
    FlyFire,
    FlyWeapon,
    FormatText,
    FreeAn,
    FreeIt,
    FreeIt1,
    GCHID,
    GCIID,
    GCIName,
    GCIRange,
    GCN,
    GEFF,
    GENM,
    GETLG,
    GETPD,
    GIRP,
    GMID,
    GMOD,
    GPNT,
    GSCHF,
    GTST,
    GateOn,
    GateOpen,
    GetABG,
    GetActionName,
    GetAddrs,
    GetAlch,
    GetAllyList,
    GetAmount,
    GetAntiHackNitkaCount,
    GetBank,
    GetBankMoney,
    GetBonusInfo,
    GetBoss,
    GetBossLvl,
    GetCS,
    GetCamNorm,
    GetCanUseWebShopAndClaim,
    GetCaster,
    GetCastleName,
    GetCastleNum,
    GetCharge,
    GetChatPrefix,
    GetClanName,
    GetClanSymbInit,
    GetConfVis,
    GetCrcBufferSize,
    GetCrystalType,
    GetCsID,
    GetCsLevel,
    GetDirAndSpeed,
    GetDir_ParamsCrc,
    GetEar,
    GetEnt,
    GetFloatArgument,
    GetGate,
    GetGlobalCont,
    GetGuardLevel,
    GetHand,
    GetHealth,
    GetHealth_m2,
    GetHrLicPrice,
    GetIDArgument,
    GetInfo,
    GetIntegerArgument,
    GetIslLvl,
    GetItemID,
    GetKomiss,
    GetLetter,
    GetLevel,
    GetLicTrade,
    GetLvlClass,
    GetMBLnam,
    GetMMChr,
    GetMName,
    GetMainServerURL,
    GetMaxCharge,
    GetMisXZ,
    GetModel,
    GetModifiers,
    GetModifs,
    GetModifsArr,
    GetMoney,
    GetMulti,
    GetMusic,
    GetMyPa,
    GetMySlot,
    GetNitkaCountFromServer,
    GetNitkaCountReceived,
    GetNitkaInfo,
    GetObjCstlGuard,
    GetObjHan,
    GetP,
    GetPUID,
    GetParam,
    GetParent,
    GetPersMsg,
    GetPictsPointer,
    GetPlName,
    GetPlayerID,
    GetPlayerLevel,
    GetPlayerName,
    GetPrice,
    GetProperty,
    GetQuestTargetPoint,
    GetRandLvl,
    GetRealPuppSlotIndex,
    GetRndName,
    GetRoom,
    GetRoomCoord,
    GetRootParent,
    GetScale,
    GetShopID,
    GetSids,
    GetSlotID,
    GetSlotsNum,
    GetSpecial,
    GetSpecialPoint,
    GetSpecialPointTelep,
    GetStCsGuard,
    GetState,
    GetStringArgument,
    GetSysText,
    GetTP,
    GetTableTime,
    GetTagParent,
    GetTarifForRandBox,
    GetTmntState,
    GetTmntTimeLeft,
    GetTmntType,
    GetTokenLvl,
    GetTotDTipsNumber,
    GetTournamentId,
    GetUBonus,
    GetUniqueGeneration,
    GetUniqueID,
    GetUseDist,
    GetUseTout,
    GetUsedElixirTime,
    GetWear,
    GetWeight,
    GetXYZ,
    Getabg,
    GetddHan,
    GetddWin,
    Getowner,
    GetpID,
    Getxyz,
    GotTrap,
    HaltOnClient,
    HaltOnServer,
    Hand,
    HandFist,
    HavePassw,
    HavePrefZSH,
    HideBank,
    HideConsole,
    HideMinimapWindow,
    HideTotDWindow,
    HideWebShopWindow,
    INCB,
    ITSOFF,
    IfInv,
    IfPuppet,
    IfTeleported,
    IfWinMacros,
    IgnoreSender,
    IgnoreUseFreq,
    Image,
    InHand,
    InIntDiapasons,
    IncTimeClient,
    InitAI,
    InitChar,
    InitCharOwn,
    InitCharPC,
    InitClanSymb,
    InitObj,
    InputDone,
    IntrplOff,
    IntrplOn,
    Inv,
    InvOff,
    InvOn,
    InvTrig,
    InvertAI,
    IsBookInTrade,
    IsChatFocus,
    IsChern,
    IsClanHaveEff,
    IsClanHaveSymbol,
    IsClearExtra,
    IsCommandEmpty,
    IsControllVirus,
    IsDigit,
    IsExit,
    IsExtra,
    IsForceDamager,
    IsItemHaveTiming,
    IsItemType,
    IsLetter,
    IsLetterUnderscore,
    IsLocalFileExist,
    IsNpc_Virt,
    IsOpened,
    IsOwn,
    IsReceived,
    IsUnderSphere,
    IsUnderground,
    IsUnique,
    IsWebShopWindowOn,
    IsWhitespace,
    KeyAlarm,
    Killed,
    KnotEff,
    LID,
    LLTOI,
    LastACC,
    Linking,
    LoadGame,
    LoadIgnoreList,
    LoadKeys,
    LoadLab,
    LoadModel,
    LoadMsgGroup,
    LoadMulti,
    LoadNewMsgGroup,
    LoadPreset,
    LoadSST,
    LoadSSTW,
    LoadStatic,
    LoadStuff,
    LoadTotDParams,
    LoadTotDText,
    LoadUnique,
    LoadiDiapFromFile,
    LostItem,
    LostItem2,
    LotteryResult,
    Lsst,
    Ltim,
    MEM,
    MKM,
    MPRT,
    MUseWith,
    Main,
    MainCBook,
    MainTotD,
    Main_1stHelp,
    MallocBuf,
    Manager,
    MantraDat,
    MaxDist,
    MdlName,
    MinDist,
    MinimapWindow,
    Mission,
    ModTpl,
    Model,
    ModifsLoaded,
    Mouse,
    MoveCamera,
    MoveObj,
    MultiobjCRC,
    MusicManager,
    NAManager,
    NCity,
    NManager,
    NPL,
    NSquare,
    NormalXYZ,
    NormalXZ,
    NotEmptyCont,
    NumOfPlayers,
    NumToModel,
    OBZVR,
    OpenB,
    OriginCsBonus,
    Owner,
    PCNThit,
    Params,
    ParseCommand,
    ParseDateTime,
    ParseItemString,
    ParseiDiapason,
    Paused,
    PeekCancel,
    PercentReceived,
    Pet,
    PlFromBuf,
    PlToBuf,
    PlaySnd,
    PlayerName,
    PopMe,
    PopMenu,
    PopupResult,
    PrgMove,
    PrintPastTime,
    ProcessCommand,
    ProcessConsole,
    ProgressUpdater,
    PullOut,
    Puppet,
    PuppetOff,
    PuppetOn,
    PuppetTrig,
    PutHere,
    PutMoney,
    Qquit,
    QueryInit,
    QueryShowWebShop,
    Qupd,
    RG,
    RGTGS,
    RSTT,
    RVCT,
    RcvG,
    RcvInfo,
    RcvUser,
    ReLoadiDiapFromFile,
    Recalc,
    ReceiveTmntData,
    Reconnect,
    RecvRegG,
    Refresh,
    RefreshClanSymb,
    RegMReceiver,
    RegRegionReceiver,
    RegTmntReceiver,
    RegionManager,
    RegionType,
    RemoveFromIgnoreList,
    ResetParams,
    ResetSkinData,
    ResetUIOnServerJump,
    Resstop,
    RestWait,
    RestoreParams,
    RunClanEffect,
    Run_StartWin,
    SCHN,
    SETMON,
    SKeyAlarm,
    SMSG,
    SOffer,
    SPDEFF,
    SRVC,
    SSCL,
    STW,
    SVis,
    SVisChar,
    SaveGame,
    SaveReturn,
    SaveSetup,
    SaveTotDParams,
    SayChat,
    SayConnectEnd,
    SayTryRestart,
    SearchFreeSlotAndPut,
    SeekFor,
    SeekMap,
    SeekTag,
    SeekTagInsideNoRecursive,
    SelChar,
    SelSky,
    SelectChar,
    Selected,
    SelfHeal,
    SendAllyAsk,
    SendAnim,
    SendCBookItem,
    SendConsole,
    SendConsoleRequest,
    SendDnDRes,
    SendHand,
    SendNPass,
    SendOffer,
    SendPassword,
    SendPress,
    SendSwordEff,
    SendSys,
    SendSys2,
    SendSys3,
    SendSys4,
    SendToRegM,
    Server,
    SetABG,
    SetAllyList,
    SetAmount,
    SetAnim,
    SetClan,
    SetClanName,
    SetClanXZ,
    SetCursType,
    SetDebug,
    SetDelCharRes,
    SetEnable,
    SetFlagLoadscrOnTop,
    SetGateStatus,
    SetGuardLevel,
    SetHand,
    SetHealth,
    SetIsland,
    SetItemGroup,
    SetLearned,
    SetLicClan,
    SetLoadingScreen,
    SetLvl,
    SetMaxLvl,
    SetMis,
    SetModel,
    SetModifiers,
    SetOSST,
    SetOverFill,
    SetPacket,
    SetParent,
    SetPlayerID,
    SetPopup,
    SetProperty,
    SetRespRadius,
    SetReturn,
    SetRunKey,
    SetShopID,
    SetShowText,
    SetSkin,
    SetSpecab,
    SetTax,
    SetTestItFlag,
    SetTmntState,
    SetTmntTimeLeft,
    SetTmntType,
    SetTradeState,
    SetTrig,
    SetUsedElixirTime,
    SetUsing,
    SetWall,
    SetWear,
    SetXYZ,
    SetXYZRAD,
    Setabg,
    SetddHan,
    Sethp,
    Setxyz,
    Sh,
    ShadowIm,
    ShadowIm2,
    ShadowOff,
    ShadowOff2,
    ShadowOn,
    ShadowOn2,
    ShadowState,
    Shadowing,
    Shadowing2,
    Shadowon,
    Shadowon2,
    Sheat,
    ShowActionHelp,
    ShowBank,
    ShowChat,
    ShowConsole,
    ShowConsoleFailure,
    ShowEff,
    ShowHiddens,
    ShowHlth,
    ShowInfo,
    ShowKill,
    ShowLook,
    ShowMap,
    ShowMessage,
    ShowMinimap,
    ShowMinimapWindow,
    ShowMission,
    ShowName,
    ShowReg,
    ShowScroll,
    ShowText,
    ShowTmntStateGVG,
    ShowToolTip,
    ShowTotDWindow,
    ShowWebShopWindow,
    ShowWho,
    ShowWinClan,
    Showtip,
    SlowSteps,
    SndUser,
    SoundManager,
    SpeedObj,
    StartClanEff,
    StartUp,
    StartWinUnhide,
    Start_Win,
    StopEffect,
    StopSwordEff,
    Stop_StartWin,
    StoreItem,
    StrCnt,
    StringSorting,
    TABLE,
    TD,
    THaltOnServer,
    TI_Flag,
    TSTHK,
    TSTIT,
    TTAX,
    TTax,
    Table,
    TableOff,
    TableOn,
    TableTrig,
    Teleport,
    TestCastleNames,
    TestDup,
    TestIt,
    TestMap,
    TestMe,
    TestMerge,
    TestOwnerPID,
    TestPut,
    TestUnique,
    TimeFromSec,
    Timer,
    TimerEff,
    Title,
    Tmnt,
    TmntIcon,
    TmntPlayerGroup,
    ToggleConsole,
    ToggleMinimapWindow,
    Trade,
    TradeMan,
    TradeOff,
    TradeOn,
    TradeTrig,
    TraderDown,
    Trigger,
    TurnMod,
    TurnSkin,
    TutoHelp,
    TutoMsg,
    TypeConsole,
    TypeMission,
    TypeScroll,
    TypeScrollMem,
    TypeTh,
    UniqueLine,
    UnloadMsgGroup,
    UnpackTmntData,
    UpdateCfg,
    UpdateClanSymb,
    UpdateHealth,
    UpdateProgressBar,
    UpdateSST,
    UpdateTmntWin,
    Upload,
    Use,
    UseAll,
    UseClient,
    UseOff,
    UseOwner,
    UseOwnerr,
    UseReturn,
    UseServer,
    UseTout,
    UseWith,
    User,
    VirEffect,
    WaitForAsk,
    WaitForCrcThreadEnd,
    WaitReinc,
    WebShopWindow,
    WhatContinent,
    WhatServer,
    WinAlly,
    WinAsyncInput,
    WinAsyncInputNum,
    WinAuth,
    WinBank,
    WinBankAuth,
    WinBnkPayQuest,
    WinClan,
    WinDiary,
    WinGuild,
    WinLink,
    WinLitMacros,
    WinMacros,
    WinMacrosOff,
    WinMacrosOn,
    WinMacrosTrig,
    WinMain,
    WinMainData,
    WinManager,
    WinPassw,
    WinSelcount,
    WinStat,
    WinTmntRegGVG,
    WinTmntStateGVG,
    WinTrade,
    WinUpd,
    WorkCheck,
    __cleanse_buffs,
    __cleanse_viruses,
    __create_process,
    __destroy_process,
    __enumerate_processes,
    __get_couragef,
    __kill_monsters,
    __set_karma,
    __set_name,
    __test_console,
    addStringToTableList,
    addToSkrijalTxt,
    allocmem,
    assembleChatMsg,
    attachtext,
    block_character_move,
    callCloseCustomerWorkshop,
    callOpenCustomerWorkshop,
    chalt,
    chat,
    checkContinentsDir,
    checkDragAndDropStart,
    checkExit,
    checkMouseStayingStill,
    checkOpenWorkshop,
    check_is_item_link_to_me,
    cleanup_AAsk,
    cleanup_ActivityCtrlWnd,
    cleanup_Animating,
    cleanup_AutobattleHandler,
    cleanup_Camera,
    cleanup_CastProgressBar,
    cleanup_Chat,
    cleanup_CheckPing,
    cleanup_CheckUseDist,
    cleanup_Client,
    cleanup_ConsoleWindow,
    cleanup_CycleReceive,
    cleanup_DragAndDropObjectMover,
    cleanup_DragDrop,
    cleanup_DropAsk,
    cleanup_EvacPlayerWinPrg,
    cleanup_FWAsk,
    cleanup_FlyFire,
    cleanup_Hand,
    cleanup_HandFist,
    cleanup_Inv,
    cleanup_KeyAlarm,
    cleanup_MinimapWindow,
    cleanup_Mission,
    cleanup_Mouse,
    cleanup_PopMenu,
    cleanup_PrgMove,
    cleanup_Puppet,
    cleanup_Qquit,
    cleanup_Qupd,
    cleanup_SayConnectEnd,
    cleanup_SayTryRestart,
    cleanup_SelChar,
    cleanup_Shadowon,
    cleanup_Shadowon2,
    cleanup_ShowInfo,
    cleanup_ShowKill,
    cleanup_ShowLook,
    cleanup_ShowMap,
    cleanup_ShowMessage,
    cleanup_ShowMission,
    cleanup_ShowName,
    cleanup_ShowReg,
    cleanup_ShowScroll,
    cleanup_ShowText,
    cleanup_ShowToolTip,
    cleanup_Start_Win,
    cleanup_TTax,
    cleanup_Table,
    cleanup_Title,
    cleanup_Trade,
    cleanup_TurnMod,
    cleanup_TutoHelp,
    cleanup_TypeMission,
    cleanup_UseTout,
    cleanup_WebShopWindow,
    cleanup_WinAlly,
    cleanup_WinAuth,
    cleanup_WinBank,
    cleanup_WinBankAuth,
    cleanup_WinBnkPayQuest,
    cleanup_WinClan,
    cleanup_WinDiary,
    cleanup_WinGuild,
    cleanup_WinLink,
    cleanup_WinLitMacros,
    cleanup_WinMacros,
    cleanup_WinManager,
    cleanup_WinPassw,
    cleanup_WinSelcount,
    cleanup_WinStat,
    cleanup_WinTmntRegGVG,
    cleanup_WinTmntStateGVG,
    cleanup_WinTrade,
    cleanup_attachtext,
    cleanup_closeWindowWorkshop,
    cleanup_cm_mainProgram,
    cleanup_hotkeys,
    cleanup_prg_OkCancelDialog,
    cleanup_prg_invite2Group,
    cleanup_smsWindowGetPrize,
    cleanup_smsWindowMessage,
    cleanup_smsWindowMessage1,
    cleanup_turnc,
    cleanup_wait4txt,
    cleanup_waitForRes,
    cleanup_winGroupExist,
    cleanup_winGroupNew,
    cleanup_winTournament,
    cleanup_wininput,
    clearChatBuffers,
    clear_use_tout_working,
    closeCustomerWorkshop,
    closeEvacPlayerWin,
    closeWindowWorkshop,
    cm_addItem,
    cm_addItemNoParams,
    cm_clear,
    cm_click,
    cm_create,
    cm_createMenu,
    cm_destroy,
    cm_enable,
    cm_executeFunction,
    cm_getExecuteResult,
    cm_hide,
    cm_isCreated,
    cm_isMainFunction,
    cm_isMenuItem,
    cm_isVisible,
    cm_mainProgram,
    cm_setText,
    cm_setTitle,
    cm_show,
    composeWildcard,
    computeLinesNumber,
    computeMatchingFunctionsNumber,
    computeUseDistance,
    convertTime2Str,
    createInfoPicture,
    createInfoSeparatorLine,
    damg,
    delayRefreshWinGroupList,
    deleteMeFroupGroup,
    deleteSomeoneFromGroup,
    distToProcess,
    dns,
    dntmove,
    dnts,
    dumpShopItems,
    dungeonCheck,
    empty,
    enableFistPwr,
    errhalt,
    executeCommandByAbbreviation,
    executeCommandByAcronym,
    executeCommandByExactName,
    fGetName,
    fastinvis,
    fastvis,
    fillparam,
    froom,
    gMsg,
    getAntiCastleCaptureTimer,
    getBLkID,
    getBLkType,
    getChatState,
    getContinentLoad,
    getCrcValues,
    getCreatureLevel,
    getDungeonNumber,
    getFistPowerups,
    getFormulaInfo,
    getHostPID,
    getItemName,
    getLastGVG,
    getLeader,
    getLinkingInfo,
    getMarkOnMapXZ,
    getMaxHealthAndPrana,
    getMissionFactorSet,
    getMoney,
    getMultiobjGroup,
    getMultiobjRecord,
    getMultiobjectScrpt,
    getNeutralInfo,
    getPassportShard,
    getPictName,
    getPlayerGroupState,
    getPlayerIDByName,
    getPlayerInfo,
    getRoom,
    getShard,
    getSkinNum,
    getTempArrowMode,
    getTmntData,
    getUpgradeMoney,
    getVirusClass,
    getVirusID,
    getWasUpdate,
    getWeaponUseDistance,
    get_base_dfrquse,
    get_crc,
    get_mNumber,
    get_pathlist,
    groupDelete,
    group_new,
    halt,
    hideIfInvisible,
    hotkeys,
    ie,
    ifUsing,
    inCastleZone,
    inSameGroup,
    insrtHText2ChatEdit,
    insrtItemInfo2Edit,
    invitePlrToGroup,
    isEvacPlayerAllowed,
    isFlamount,
    isGxpItem,
    isInvisible,
    isSlotOccupied,
    isValidAcronym,
    joinMeAsCandidate,
    joinSomeone2Group,
    lid,
    listMatchingCommands,
    loadChatFonts,
    loadItemIDsAndPrefixes,
    loadMiniChatFonts,
    lockid,
    main,
    mapXY2SphereXZ,
    mcl,
    mgrAlly,
    mgrAnticheat,
    mgrBuyIt,
    mgrChat,
    mgrCheat,
    mgrCheckCrc,
    mgrCheckKey,
    mgrEffect,
    mgrEffectPrg,
    mgrElem,
    mgrFist,
    mgrGetBonus,
    mgrGrab,
    mgrKey,
    mgrLost,
    mgrSBought,
    mgrSSetOffer,
    mgrSSysMsg,
    mgrSetClan,
    mgrSetCoord,
    mgrSetGroup,
    mgrSetTrade,
    mgrSrClan,
    mgrSrvJump,
    mgrTable,
    mgrTmntAction,
    mgrTmntData,
    mgrTmntDone,
    mgrTmntDrop,
    mgrTmntInfo,
    mgrTmntShowState,
    mgrTmntState,
    mgrTradeWith,
    mouseOverChat,
    move,
    moveObjectAlongLandscape,
    openCustomerWorkshop,
    openEvacPlayerWin,
    openSlot,
    pClanName,
    pEnemies,
    pModelName,
    pUSTATE,
    prgChatData,
    prg_OkCancelDialog,
    prg_invite2Group,
    processAutoDoors,
    processDragAndDropEnd,
    processLButtonClick,
    processLButtonDown,
    processLButtonUp,
    processLookOn,
    processObjectClick,
    processObjectDrop,
    processRButtonDown,
    processRButtonUp,
    progShowEff,
    pturn,
    pvison,
    readnext,
    readstr,
    receiveArtisanID,
    receiveArtisanMonitor,
    receiveCustomerID,
    receiveInvite2Group,
    receiveMarkOnMapXZ,
    receiveMyWorkshop,
    receiveOwnerArtisanMonitor,
    receivePriceArtisan,
    receiveRegExpTime,
    receiveRegG,
    receiveWindowHandler,
    refreshSkin,
    refreshWinGroupList,
    resetArtisanData,
    resetCustomerData,
    resetDungeonNumber,
    resetFlagAcceptCraft,
    resetPassword,
    restartUpdater,
    runCrcCalculation,
    runMgrAnticheat,
    runRefreshWinGroupList,
    runSayTryRestart,
    runWinGroup,
    sayPetition2Plr,
    sayPrivate2Plr,
    seekslot,
    selfHealPrg,
    sendChatMsgByParts,
    sendMarkOnMapXZ,
    sendSysTextToChat,
    sendSysTxt2ChatByNum,
    sendone,
    sendpop,
    sendslot,
    sendsloti,
    sendsloti1,
    sercli,
    setArtisanID,
    setChatState,
    setContinentLoad,
    setCostInWorkshop,
    setCustomerID,
    setEvilClan,
    setFill,
    setFistPowerups,
    setFlagAcceptCraft,
    setFlagCloseWindowWorkshop,
    setFlagFreeSlotsInWorkshop,
    setGxpItem,
    setMarkOnCompassByXZ,
    setMarkOnMapXZ,
    setPriceArtisan,
    setWasUpdate,
    sett,
    settim,
    show,
    showred,
    skincoord,
    slhalt,
    slowinvis,
    smsInfoIcon,
    smsInfoIconFlush,
    smsInfoIconTooltip,
    smsShowPrizeWindow,
    smsShowWindow,
    smsWindowGetPrize,
    smsWindowMessage,
    smsWindowMessage1,
    specialChecksForMerge,
    sphereXZ2MapXY,
    stopWinGroupExist,
    stopWinGroupNew,
    sysMsgAndText,
    testfile,
    thalt,
    tinv,
    toutopen,
    trig,
    tryToRevertClanKills,
    turnSkinAndSetVis,
    turnc,
    use,
    useItemOnOneself,
    useItemOnSuperstatic,
    useItemOnTarget,
    use_check_frquse,
    use_check_linking,
    use_is_stack_use,
    use_on,
    use_send_cuse_to_server,
    valid_filesys_chrs,
    wait4txt,
    waitForRes,
    winGroupExist,
    winGroupNew,
    winTournament,
    wininput,
};

struct ScriptState1
{
    ScriptState1();
    std::int32_t member7_{};
    std::int32_t member8_{};
    String member9_{};
    std::int32_t member10_{};
    std::int32_t member11_{};
    std::int32_t member12_{};
    std::int32_t member13_{};
    std::int32_t member14_{};
    std::array<std::uint8_t, 64> member16_{};
    std::array<std::uint8_t, 64> member18_{};
    std::array<std::uint8_t, 64> member20_{};
    std::array<std::uint8_t, 11> member22_{};
    std::array<std::uint8_t, 11> member23_{};
    std::array<std::uint8_t, 11> member24_{};
    std::array<std::uint8_t, 11> member25_{};
    std::array<std::uint8_t, 1> member26_{};
    std::array<std::uint8_t, 1> member27_{};
    std::array<std::uint8_t, 11> member28_{};
    std::array<std::uint8_t, 11> member29_{};
    std::array<std::uint8_t, 11> member30_{};
    std::array<std::uint8_t, 11> member31_{};
    std::array<std::uint8_t, 11> member32_{};
    std::array<std::uint8_t, 11> member33_{};
    std::array<std::uint8_t, 1> member34_{};
    std::array<std::uint8_t, 1> member35_{};
    std::array<std::uint8_t, 11> member36_{};
    std::array<std::uint8_t, 11> member37_{};
    std::array<std::uint8_t, 11> member38_{};
    std::array<std::uint8_t, 11> member39_{};
    std::array<std::uint8_t, 11> member40_{};
    std::array<std::uint8_t, 11> member41_{};
    std::array<std::uint8_t, 11> member42_{};
    std::array<std::uint8_t, 1> member43_{};
    std::array<std::uint8_t, 2> member44_{};
    std::array<std::uint8_t, 2> member45_{};
    std::int32_t member373_{};
    String member374_{};
    String member375_{};
    String member376_{};
    std::array<std::uint8_t, 13> member377_{};
    std::array<std::uint8_t, 11> member378_{};
    String member379_{};
    std::array<std::uint8_t, 7> member380_{};
    String member381_{};
    std::array<std::uint8_t, 6> member382_{};
    String member383_{};
    std::array<std::uint8_t, 11> member384_{};
    std::array<std::uint8_t, 11> member385_{};
    std::array<std::uint8_t, 10> member386_{};
    std::array<std::uint8_t, 9> member387_{};
    std::array<std::uint8_t, 7> member388_{};
    std::array<std::uint8_t, 13> member389_{};
    std::array<std::uint8_t, 11> member390_{};
    String member391_{};
    std::array<std::uint8_t, 11> member392_{};
    std::array<std::uint8_t, 8> member393_{};
    std::array<std::uint8_t, 8> member394_{};
    std::array<std::uint8_t, 9> member395_{};
    std::array<std::uint8_t, 7> member396_{};
    String member457_{};
    std::int8_t member461_{};
    std::int32_t member463_{};
    std::int32_t member464_{};
    std::int32_t member466_{};
    std::array<std::uint8_t, 28> member467_{};
    std::array<std::uint8_t, 28> member468_{};
    std::array<std::uint8_t, 15> member469_{};
    std::array<std::uint8_t, 15> member470_{};
    std::int32_t member472_{};
    std::int32_t member473_{};
    String member474_{};
    String member475_{};
    std::int32_t member480_{};
    std::array<std::uint8_t, 13> member499_{};
    std::int32_t member501_{};
    std::int32_t member502_{};
    std::int32_t member503_{};
    std::int32_t member504_{};
    std::int32_t member505_{};
    std::int32_t member506_{};
    std::array<std::uint8_t, 8> member508_{};
    std::array<std::uint8_t, 8> member510_{};
    std::array<std::uint8_t, 13> member512_{};
    std::array<std::uint8_t, 3> member513_{};
    String member514_{};
    std::array<std::uint8_t, 9> member515_{};
    String member516_{};
    String member517_{};
    std::int8_t member518_{};
    std::array<std::uint8_t, 60> member520_{};
    std::int32_t member522_{};
    std::int32_t member523_{};
    std::int32_t member524_{};
    std::int32_t member525_{};
    String member526_{};
    std::int8_t member527_{};
    std::array<std::uint8_t, 8> member529_{};
    std::int32_t member532_{};
    std::int32_t member537_{};
    std::int32_t member538_{};
    std::int32_t member539_{};
    std::int32_t member540_{};
    std::int32_t member544_{};
    std::int32_t member563_{};
    std::array<std::uint8_t, 1024> member567_{};
    std::array<std::uint8_t, 256> member607_{};
    std::int32_t member609_{};
    std::int32_t member610_{};
    std::int32_t member611_{};
    std::array<std::uint8_t, 8> member612_{};
    std::array<std::uint8_t, 11> member613_{};
    float member615_{};
    float member616_{};
    std::array<std::uint8_t, 8> member617_{};
    std::array<std::uint8_t, 13> member618_{};
    std::array<std::uint8_t, 1> member619_{};
    std::array<std::uint8_t, 3> member620_{};
    std::array<std::uint8_t, 10> member621_{};
    std::int32_t member629_{};
    std::int32_t member1156_{};
    String member1157_{};
    String member1158_{};
    String member1159_{};
    String member1160_{};
    std::int32_t member1161_{};
    std::array<std::uint8_t, 131> member1162_{};
    std::array<std::uint8_t, 2> member1163_{};
    std::array<std::uint8_t, 256> member3216_{};
    std::array<std::uint8_t, 4096> member3218_{};
    std::array<std::uint8_t, 4096> member3220_{};
    std::array<std::uint8_t, 4096> member3222_{};
    std::int32_t member3224_{};
    std::int32_t member3225_{};
    std::int32_t member3226_{};
    std::int32_t member3227_{};
    String member3228_{};
    std::int8_t member3229_{};
    String member3230_{};
    std::int32_t member3232_{};
    std::int32_t member3233_{};
    String member3234_{};
    std::array<std::uint8_t, 5> member3326_{};
    std::array<std::uint8_t, 5> member3421_{};
    std::int32_t member4441_{};
    std::int32_t member4443_{};
    std::int32_t member4445_{};
    std::int32_t member4446_{};
    std::int32_t member4492_{};
    std::int32_t member4493_{};
    std::int32_t member4494_{};
    std::int32_t member4495_{};
    std::int32_t member4497_{};
    std::int32_t member4498_{};
    std::int8_t member4973_{};
    String member4974_{};
    std::int32_t member4975_{};
    std::int32_t member4977_{};
    std::int32_t member4978_{};
    std::int32_t member4979_{};
    std::array<std::uint8_t, 14> member4980_{};
    std::array<std::uint8_t, 14> member4981_{};
    AddressRef member4982_{};
    std::int32_t member4984_{};
    std::int32_t member4985_{};
    std::int32_t member4986_{};
    std::int32_t member4987_{};
    std::int32_t member4988_{};
    std::array<std::uint8_t, 152> member4989_{};
    String member4990_{};
    std::array<std::uint8_t, 14> member4991_{};
    std::int32_t member4993_{};
    std::int32_t member4994_{};
    AddressRef member4995_{};
    std::int32_t member4996_{};
    std::int32_t member4997_{};
    std::int32_t member4998_{};
    std::int32_t member4999_{};
    std::array<std::uint8_t, 8> member5001_{};
    std::array<std::uint8_t, 8> member5003_{};
    std::int32_t member5005_{};
    std::int32_t member5006_{};
    std::int32_t member5007_{};
    std::int32_t member5008_{};
    String member5009_{};
    std::int32_t member5010_{};
    std::int32_t member5011_{};
    String member5012_{};
    std::int32_t member5013_{};
    std::int32_t member5014_{};
    std::int32_t member5015_{};
};

struct ScriptState2
{
    ScriptState2();
    std::array<std::uint8_t, 24> member62_{};
    std::array<std::uint8_t, 16> member64_{};
    std::array<std::uint8_t, 20> member68_{};
    std::int32_t member71_{};
    std::int32_t member72_{};
    std::int32_t member73_{};
    std::int32_t member74_{};
    std::int32_t member76_{};
    std::int32_t member77_{};
    std::int32_t member81_{};
    std::int32_t member82_{};
    std::array<std::uint8_t, 256> member89_{};
    std::array<std::uint8_t, 20> member91_{};
    std::int32_t member104_{};
    std::int32_t member106_{};
    std::int32_t member116_{};
    std::int32_t member123_{};
    std::int32_t member124_{};
    std::int32_t member125_{};
    String member126_{};
    std::array<std::uint8_t, 45> member127_{};
    std::array<std::uint8_t, 45> member128_{};
    std::int32_t member129_{};
    String member130_{};
    std::int32_t member131_{};
    std::int32_t member133_{};
    IntRef member134_{};
    std::int32_t member143_{};
    std::int32_t member144_{};
    std::int32_t member145_{};
    std::int32_t member146_{};
    std::int32_t member147_{};
    String member148_{};
    std::int32_t member151_{};
    std::int32_t member152_{};
    std::int32_t member153_{};
    std::int32_t member154_{};
    std::int32_t member155_{};
    std::int32_t member156_{};
    std::int32_t member157_{};
    std::int32_t member158_{};
    AddressRef member159_{};
    Address member160_{};
    AddressRef member163_{};
    AddressRef member164_{};
    String member167_{};
    String member168_{};
    AddressRef member169_{};
    String member170_{};
    String member171_{};
    std::int32_t member172_{};
    std::int32_t member173_{};
    AddressRef member174_{};
    std::int32_t member175_{};
    AddressRef member176_{};
    std::int32_t member177_{};
    AddressRef member178_{};
    std::int32_t member180_{};
    std::int32_t member181_{};
    Address member182_{};
    String member183_{};
    std::int32_t member184_{};
    std::int32_t member185_{};
    Address member186_{};
    String member187_{};
    std::int32_t member188_{};
    std::int32_t member189_{};
    std::int32_t member190_{};
    String member191_{};
    std::int32_t member192_{};
    std::int32_t member194_{};
    std::array<std::uint8_t, 13> member196_{};
    std::array<std::uint8_t, 13> member197_{};
    Address member201_{};
    std::int32_t member205_{};
    std::int32_t member206_{};
    std::int32_t member207_{};
    std::int32_t member208_{};
    std::int32_t member209_{};
    std::int32_t member211_{};
    std::array<std::uint8_t, 40> member213_{};
    std::array<std::uint8_t, 40> member215_{};
    std::int32_t member217_{};
    std::int32_t member218_{};
    std::int32_t member220_{};
    std::int32_t member221_{};
    std::int32_t member222_{};
    std::int32_t member223_{};
    std::array<String, 4> member227_{};
    String member229_{};
    std::array<std::uint8_t, 4> member230_{};
    std::int32_t member236_{};
    std::int32_t member237_{};
    std::int32_t member238_{};
    std::int32_t member239_{};
    std::int32_t member241_{};
    std::int32_t member242_{};
    std::int32_t member244_{};
    std::int32_t member245_{};
    String member247_{};
    std::array<std::uint8_t, 20> member249_{};
    std::int32_t member253_{};
    String member263_{};
    std::int32_t member264_{};
    std::int32_t member265_{};
    String member266_{};
    std::int32_t member267_{};
    std::int32_t member268_{};
    String member269_{};
    std::int32_t member277_{};
    String member279_{};
    String member280_{};
    String member281_{};
    String member282_{};
    String member284_{};
    String member285_{};
    String member286_{};
    String member287_{};
    String member288_{};
    String member290_{};
    IntRef member292_{};
    std::array<std::uint8_t, 32> member294_{};
    std::int32_t member296_{};
    std::int32_t member297_{};
    std::int32_t member298_{};
    std::array<std::uint8_t, 6> member299_{};
    String member304_{};
    String member305_{};
    String member306_{};
    String member307_{};
    String member308_{};
    std::array<String, 2> member317_{};
    String member326_{};
    std::array<std::uint8_t, 28> member327_{};
    std::int32_t member328_{};
    String member329_{};
    String member330_{};
    String member331_{};
    std::int32_t member332_{};
    std::int8_t member333_{};
    std::int32_t member334_{};
    std::int32_t member335_{};
    std::int32_t member336_{};
    std::int32_t member337_{};
    std::int32_t member338_{};
    String member339_{};
    std::array<std::uint8_t, 256> member341_{};
    std::array<std::uint8_t, 52> member343_{};
    std::array<std::uint8_t, 50> member344_{};
    std::array<std::uint8_t, 58> member345_{};
    std::array<std::uint8_t, 56> member346_{};
    std::array<std::uint8_t, 4> member347_{};
    std::array<std::uint8_t, 8> member348_{};
    String member349_{};
    std::array<std::uint8_t, 8> member350_{};
    String member351_{};
    String member352_{};
    std::array<std::uint8_t, 4> member353_{};
    String member354_{};
    String member355_{};
    std::array<std::uint8_t, 6> member356_{};
    String member357_{};
    std::array<std::uint8_t, 5> member358_{};
    String member359_{};
    std::int32_t member360_{};
    String member361_{};
    std::int32_t member401_{};
    std::int32_t member403_{};
    std::int32_t member405_{};
    std::int32_t member406_{};
    std::int32_t member407_{};
    std::int32_t member408_{};
    String member409_{};
    std::int8_t member410_{};
    std::int32_t member411_{};
    std::int32_t member412_{};
    std::int32_t member413_{};
    std::int32_t member414_{};
    std::int32_t member416_{};
    std::int32_t member417_{};
    String member419_{};
    std::int32_t member421_{};
    std::int32_t member423_{};
    std::int32_t member424_{};
    std::int32_t member425_{};
    std::int32_t member426_{};
    std::int32_t member427_{};
    std::int32_t member428_{};
    std::int32_t member430_{};
    std::int32_t member431_{};
    std::int32_t member432_{};
    String member433_{};
    std::int32_t member434_{};
    std::int32_t member435_{};
    std::int32_t member438_{};
    std::int32_t member439_{};
    std::int32_t member441_{};
    std::int32_t member442_{};
    std::int32_t member443_{};
    std::int32_t member444_{};
    std::int32_t member446_{};
    std::int32_t member447_{};
    std::int32_t member448_{};
    std::int32_t member449_{};
    std::int32_t member450_{};
    std::int32_t member488_{};
    std::int32_t member489_{};
    std::int32_t member5191_{};
    std::int8_t member5238_{};
    std::array<std::uint8_t, 40> member5244_{};
    std::array<std::uint8_t, 40> member5246_{};
    std::array<std::uint8_t, 40> member5248_{};
    std::array<std::uint8_t, 40> member5250_{};
    std::int32_t member5252_{};
    std::int32_t member5309_{};
    std::int32_t member5310_{};
    std::int32_t member5338_{};
    std::int32_t member5470_{};
    std::int32_t member5472_{};
    IntRef member5473_{};
    std::int32_t member5483_{};
    std::array<std::uint8_t, 1> member5484_{};
    std::int32_t member5490_{};
    std::int32_t member5491_{};
    std::int32_t member5492_{};
    float member5493_{};
    float member5494_{};
    float member5495_{};
    float member5496_{};
    float member5498_{};
    float member5499_{};
    float member5501_{};
    std::int32_t member5502_{};
    std::int32_t member5503_{};
    std::int32_t member5505_{};
    std::int32_t member5506_{};
    std::int32_t member5507_{};
    std::int32_t member5508_{};
    std::int32_t member5509_{};
    std::int32_t member5510_{};
    std::int32_t member5511_{};
    std::int32_t member5512_{};
    std::int32_t member5513_{};
    std::int32_t member5524_{};
    std::int32_t member5525_{};
    std::int32_t member5527_{};
    Address member5528_{};
    std::int32_t member5529_{};
    String member5530_{};
    std::array<std::uint8_t, 8> member5531_{};
    std::int32_t member5532_{};
    String member5533_{};
    std::array<std::uint8_t, 7> member5534_{};
    String member5536_{};
    std::int32_t member5539_{};
    std::int32_t member5543_{};
    float member5544_{};
    float member5545_{};
    std::array<std::uint8_t, 40> member5549_{};
    std::array<std::uint8_t, 11> member5551_{};
    std::array<std::uint8_t, 11> member5552_{};
    std::array<std::uint8_t, 18> member5553_{};
    std::array<std::uint8_t, 13> member5554_{};
    std::array<std::uint8_t, 18> member5555_{};
    std::array<std::uint8_t, 18> member5556_{};
    std::array<std::uint8_t, 9> member5557_{};
    std::array<std::uint8_t, 4> member5558_{};
    std::array<std::uint8_t, 20> member5564_{};
    std::int32_t member5567_{};
    std::int32_t member5568_{};
    String member5572_{};
    std::int32_t member5573_{};
    std::array<std::uint8_t, 18> member5574_{};
    std::int32_t member5575_{};
    std::array<std::uint8_t, 11> member5576_{};
    std::int32_t member5578_{};
    std::int32_t member5579_{};
    String member5580_{};
    std::int32_t member5581_{};
    std::int32_t member5582_{};
    String member5583_{};
    String member5584_{};
    std::int32_t member5613_{};
    IntRef member5614_{};
    std::int32_t member5615_{};
    std::int32_t member5616_{};
    std::int32_t member5617_{};
    String member5646_{};
    std::array<std::uint8_t, 5> member5647_{};
    std::array<std::uint8_t, 5> member5648_{};
    std::array<std::uint8_t, 5> member5649_{};
    std::array<std::uint8_t, 5> member5650_{};
    std::int32_t member5671_{};
    std::int32_t member5673_{};
    std::int32_t member5674_{};
    std::int32_t member5676_{};
    std::int32_t member5677_{};
    EffectDefinition member5678_{};
    Address member5682_{};
    Address member5683_{};
    Address member5684_{};
    float member5685_{};
    std::int32_t member5686_{};
    std::array<std::uint8_t, 6> member5687_{};
    std::array<std::uint8_t, 6> member5688_{};
    std::int32_t member5689_{};
    std::int32_t member5690_{};
    std::int32_t member5691_{};
    std::int32_t member5693_{};
    std::int32_t member5694_{};
    String member5696_{};
    std::int32_t member5697_{};
    String member5698_{};
    std::array<std::uint8_t, 8> member5700_{};
    std::int32_t member5702_{};
    std::int32_t member5703_{};
    std::int32_t member5704_{};
    std::int32_t member5705_{};
    std::int32_t member5706_{};
    std::int32_t member5707_{};
    std::int32_t member5708_{};
    std::int32_t member5709_{};
    std::int32_t member5718_{};
    std::int32_t member5719_{};
    std::int32_t member5720_{};
    std::int32_t member5721_{};
    std::array<std::uint8_t, 8> member5722_{};
    std::int32_t member5723_{};
    std::int32_t member5724_{};
    std::int32_t member5725_{};
    std::int32_t member5727_{};
    std::int32_t member5728_{};
    std::int32_t member5729_{};
    std::array<std::uint8_t, 10> member5730_{};
    std::array<std::uint8_t, 16> member5731_{};
    std::int32_t member5733_{};
    std::int32_t member5734_{};
    String member5735_{};
    String member5736_{};
    std::array<std::uint8_t, 28> member5737_{};
    std::array<std::uint8_t, 28> member5738_{};
    std::array<std::uint8_t, 15> member5739_{};
    std::array<std::uint8_t, 15> member5740_{};
    std::array<std::uint8_t, 10> member5741_{};
    std::array<std::uint8_t, 10> member5742_{};
    std::array<std::uint8_t, 10> member5743_{};
    std::array<std::uint8_t, 10> member5744_{};
    std::int32_t member5746_{};
    std::array<std::uint8_t, 8> member5747_{};
    std::int32_t member5748_{};
    std::int32_t member5749_{};
    std::int32_t member5752_{};
    std::array<std::uint8_t, 11> member5753_{};
    std::int32_t member5758_{};
    std::array<std::uint8_t, 256> member5760_{};
    std::array<std::uint8_t, 256> member5762_{};
    std::int8_t member5764_{};
    std::int32_t member5766_{};
    std::int32_t member5767_{};
    std::int32_t member5768_{};
    String member5769_{};
    String member5770_{};
    String member5771_{};
    std::array<std::uint8_t, 8> member5772_{};
    std::array<std::uint8_t, 6> member5773_{};
    std::array<std::uint8_t, 9> member5774_{};
    String member5775_{};
    std::int32_t member5777_{};
    std::array<std::uint8_t, 20> member5779_{};
    std::array<std::uint8_t, 20> member5781_{};
    std::int32_t member6044_{};
    std::int32_t member6991_{};
};

struct ScriptState3
{
    ScriptState3();
    std::array<std::uint8_t, 256> member66_{};
    std::int32_t member79_{};
    std::int32_t member84_{};
    std::int32_t member85_{};
    std::array<std::uint8_t, 256> member87_{};
    std::int32_t member93_{};
    std::int32_t member94_{};
    std::int32_t member105_{};
    std::int32_t member107_{};
    std::int32_t member108_{};
    std::int32_t member117_{};
    std::int32_t member119_{};
    IntRef member136_{};
    IntRef member140_{};
    IntRef member141_{};
    std::int32_t member161_{};
    AddressRef member162_{};
    Address member179_{};
    std::int32_t member210_{};
    std::int32_t member219_{};
    float member224_{};
    float member225_{};
    std::array<std::uint8_t, 13> member231_{};
    std::array<std::uint8_t, 18> member232_{};
    std::array<std::uint8_t, 18> member233_{};
    std::array<std::uint8_t, 9> member234_{};
    std::array<std::uint8_t, 4> member235_{};
    std::int32_t member255_{};
    std::int32_t member256_{};
    String member258_{};
    std::array<std::uint8_t, 18> member259_{};
    std::int32_t member261_{};
    String member262_{};
    std::array<std::uint8_t, 30> member312_{};
    std::array<std::uint8_t, 6> member364_{};
    std::int32_t member445_{};
    std::array<std::uint8_t, 5> member452_{};
    std::int32_t member453_{};
    String member454_{};
    String member455_{};
    String member458_{};
    String member459_{};
    std::array<std::uint8_t, 2> member462_{};
    std::int32_t member668_{};
    String member7716_{};
    std::array<std::uint8_t, 11> member7717_{};
    std::array<std::uint8_t, 6> member7718_{};
    std::int32_t member8146_{};
    std::int32_t member8151_{};
    std::int32_t member8155_{};
    std::int32_t member8157_{};
    std::array<std::uint8_t, 200> member8159_{};
    std::int32_t member8169_{};
    std::int32_t member8175_{};
    std::int32_t member8177_{};
    std::int32_t member8178_{};
    IntRef member8199_{};
    IntRef member8200_{};
    IntRef member8202_{};
    IntRef member8228_{};
    std::array<std::uint8_t, 6> member8251_{};
    std::int32_t member8264_{};
    std::int32_t member8265_{};
    std::int32_t member8266_{};
    std::int32_t member8270_{};
    FloatRef member8271_{};
    FloatRef member8272_{};
    FloatRef member8273_{};
    float member8274_{};
    std::int32_t member8275_{};
    float member8276_{};
    float member8277_{};
    float member8278_{};
    std::array<std::uint8_t, 17> member8279_{};
    std::int32_t member8281_{};
    float member8282_{};
    float member8283_{};
    float member8284_{};
    std::array<std::uint8_t, 17> member8285_{};
    std::int32_t member8287_{};
    std::int32_t member8288_{};
    std::int32_t member8289_{};
    std::int32_t member8290_{};
    std::int32_t member8291_{};
    std::int32_t member8292_{};
    std::int32_t member8293_{};
    std::int32_t member8294_{};
    std::int32_t member8295_{};
    std::int32_t member8296_{};
    std::int32_t member8297_{};
    std::int32_t member8298_{};
    std::int32_t member8299_{};
    std::int32_t member8300_{};
    std::int32_t member8301_{};
    float member8303_{};
    Address member8304_{};
    float member8305_{};
    String member8306_{};
    std::int32_t member8308_{};
    std::array<std::uint8_t, 5> member8310_{};
    std::array<std::uint8_t, 5> member8311_{};
    std::array<std::uint8_t, 5> member8312_{};
    std::array<std::uint8_t, 5> member8313_{};
    std::int32_t member8314_{};
    std::int32_t member8315_{};
    std::int32_t member8316_{};
    std::int32_t member8317_{};
    std::int32_t member8318_{};
    std::array<std::uint8_t, 5> member8319_{};
    std::array<std::uint8_t, 10> member8320_{};
    std::array<std::uint8_t, 6> member8321_{};
    std::array<std::uint8_t, 8> member8322_{};
    std::array<std::uint8_t, 4> member8323_{};
    String member8434_{};
    std::array<std::uint8_t, 10> member8535_{};
    std::array<std::uint8_t, 20> member8604_{};
    std::int32_t member8610_{};
    std::int32_t member8613_{};
    std::array<std::uint8_t, 12> member8615_{};
    std::array<std::uint8_t, 12> member8617_{};
    std::array<std::int32_t, 3> member8620_{};
    std::array<std::int32_t, 3> member8623_{};
    IntRef member8625_{};
    IntRef member8626_{};
    std::array<std::uint8_t, 20> member8642_{};
    std::int32_t member8650_{};
    std::array<std::uint8_t, 7> member8658_{};
    std::array<String, 2> member8659_{};
    std::array<std::uint8_t, 18> member8660_{};
    std::array<std::uint8_t, 1> member8661_{};
    std::array<std::uint8_t, 5> member8663_{};
    std::array<std::uint8_t, 20> member8665_{};
    std::array<std::uint8_t, 67> member8667_{};
    std::array<std::uint8_t, 29> member8668_{};
    std::array<std::uint8_t, 40> member8669_{};
    std::array<std::uint8_t, 18> member8670_{};
    std::array<std::uint8_t, 16> member8675_{};
    std::int32_t member8684_{};
    std::array<std::uint8_t, 100> member8724_{};
    std::int32_t member8731_{};
    String member8743_{};
    std::array<std::uint8_t, 6> member8744_{};
    std::int32_t member8747_{};
    std::array<std::uint8_t, 4> member8748_{};
    std::array<std::uint8_t, 5> member8749_{};
    std::array<std::uint8_t, 5> member8750_{};
    std::array<std::uint8_t, 5> member8751_{};
    std::array<std::uint8_t, 5> member8752_{};
    std::array<std::uint8_t, 6> member8753_{};
    std::array<std::uint8_t, 4> member8754_{};
    std::array<std::uint8_t, 5> member8755_{};
    std::array<std::uint8_t, 5> member8756_{};
    std::array<std::uint8_t, 16> member8757_{};
    std::int32_t member8758_{};
    std::int32_t member8764_{};
    std::int32_t member8765_{};
    String member8766_{};
    String member8767_{};
    std::array<std::uint8_t, 5> member8768_{};
    std::array<std::uint8_t, 11> member8769_{};
    std::array<std::uint8_t, 11> member8770_{};
};

struct ScriptState4
{
    ScriptState4();
    std::int32_t member70_{};
    std::int32_t member75_{};
    std::int32_t member78_{};
    std::int32_t member83_{};
    std::int32_t member95_{};
    std::int32_t member96_{};
    std::int32_t member97_{};
    std::int32_t member98_{};
    Address member99_{};
    std::int32_t member100_{};
    std::int32_t member101_{};
    std::int32_t member102_{};
    std::int32_t member103_{};
    std::int32_t member109_{};
    std::int32_t member110_{};
    std::int32_t member132_{};
    IntRef member135_{};
    IntRef member137_{};
    IntRef member138_{};
    IntRef member139_{};
    std::int32_t member142_{};
    std::array<std::uint8_t, 2> member149_{};
    std::array<std::uint8_t, 6> member363_{};
    std::array<std::uint8_t, 16> member366_{};
    std::int32_t member371_{};
    std::int32_t member397_{};
    std::int32_t member398_{};
    std::int32_t member399_{};
    std::int32_t member400_{};
    std::int32_t member402_{};
    std::int32_t member404_{};
    std::int32_t member451_{};
    std::int32_t member656_{};
    std::int32_t member657_{};
    std::int32_t member7608_{};
    std::int32_t member7614_{};
    std::int32_t member7615_{};
    std::int32_t member7616_{};
    std::int32_t member7620_{};
    std::int32_t member7621_{};
    std::int32_t member7622_{};
    std::array<std::uint8_t, 8> member7623_{};
    String member7624_{};
    std::array<String, 2> member7625_{};
    std::array<std::uint8_t, 16> member7626_{};
    std::array<std::uint8_t, 11> member7627_{};
    std::array<String, 2> member7628_{};
    std::int32_t member7630_{};
    String member7631_{};
    std::array<std::uint8_t, 8> member7632_{};
    std::array<std::uint8_t, 16> member7633_{};
    std::array<std::uint8_t, 11> member7634_{};
    std::array<std::uint8_t, 16> member7635_{};
    std::array<std::uint8_t, 11> member7636_{};
    std::int32_t member7647_{};
    std::int32_t member7649_{};
    std::int32_t member7650_{};
    std::array<std::uint8_t, 8> member7651_{};
    std::array<std::uint8_t, 7> member7652_{};
    std::array<std::uint8_t, 21> member7653_{};
    std::int32_t member7654_{};
    std::int32_t member7655_{};
    std::array<std::uint8_t, 8> member7656_{};
    std::int32_t member7657_{};
    std::int32_t member7658_{};
    std::int32_t member7659_{};
    std::int32_t member7661_{};
    String member7663_{};
    std::array<std::uint8_t, 8> member7664_{};
    std::array<std::uint8_t, 10> member7665_{};
    std::int32_t member7675_{};
    std::int32_t member7677_{};
    std::array<std::uint8_t, 20> member7685_{};
    std::array<std::uint8_t, 20> member7687_{};
    std::int32_t member7787_{};
    std::int32_t member7788_{};
    Address member7802_{};
    std::int32_t member7819_{};
    String member7944_{};
    std::array<std::uint8_t, 9> member8138_{};
    std::array<std::uint8_t, 6> member11451_{};
};

struct ScriptState5
{
    ScriptState5();
    Address member200_{};
    float member271_{};
    float member272_{};
    std::int32_t member274_{};
    std::int32_t member276_{};
    String member301_{};
    std::array<std::uint8_t, 11> member302_{};
    std::array<std::uint8_t, 6> member303_{};
    std::array<std::uint8_t, 11> member309_{};
    std::array<std::uint8_t, 30> member310_{};
    std::array<std::uint8_t, 25> member311_{};
    std::array<std::uint8_t, 16> member313_{};
    std::array<std::uint8_t, 18> member314_{};
    std::array<std::uint8_t, 5> member316_{};
    std::array<std::uint8_t, 20> member319_{};
    std::array<std::uint8_t, 67> member321_{};
    std::array<std::uint8_t, 29> member322_{};
    std::array<std::uint8_t, 40> member323_{};
    std::array<std::uint8_t, 18> member324_{};
    std::array<std::uint8_t, 7> member365_{};
    std::int32_t member436_{};
    std::int32_t member437_{};
    String member669_{};
    String member671_{};
    std::int32_t member7699_{};
    std::array<std::uint8_t, 16> member7727_{};
    std::array<std::uint8_t, 11> member7733_{};
    std::array<std::uint8_t, 20> member7812_{};
    std::array<std::uint8_t, 11> member7853_{};
    std::array<std::uint8_t, 11> member7865_{};
    std::array<std::uint8_t, 20> member7924_{};
    float member8100_{};
    std::int32_t member8102_{};
    std::int32_t member8104_{};
    String member8112_{};
    std::array<std::uint8_t, 11> member8113_{};
    std::array<std::uint8_t, 6> member8114_{};
    std::array<std::uint8_t, 11> member8115_{};
    std::array<std::uint8_t, 30> member8116_{};
    std::array<std::uint8_t, 25> member8117_{};
    std::array<std::uint8_t, 5> member8118_{};
    std::array<std::uint8_t, 5> member8119_{};
    std::array<std::uint8_t, 11> member8120_{};
    std::array<std::uint8_t, 6> member8121_{};
    std::array<std::uint8_t, 18> member8122_{};
    std::array<std::uint8_t, 15> member8123_{};
    std::array<std::uint8_t, 16> member8124_{};
    std::array<std::uint8_t, 11> member8125_{};
    std::array<std::uint8_t, 128> member8128_{};
    std::array<std::uint8_t, 4> member8130_{};
    std::array<std::uint8_t, 5> member8131_{};
    std::array<std::uint8_t, 5> member8150_{};
    std::array<std::uint8_t, 6> member8252_{};
    std::array<std::uint8_t, 5> member8381_{};
    std::int32_t member8525_{};
    String member8808_{};
    std::array<std::uint8_t, 20> member8917_{};
    std::int32_t member8923_{};
    std::int32_t member8925_{};
    String member8932_{};
    std::array<std::uint8_t, 11> member8933_{};
    std::array<std::uint8_t, 6> member8934_{};
    std::array<std::uint8_t, 11> member8935_{};
    std::array<std::uint8_t, 30> member8936_{};
    std::array<std::uint8_t, 25> member8937_{};
    std::int32_t member9180_{};
    std::int32_t member9279_{};
    std::array<std::uint8_t, 96> member9291_{};
    std::array<std::uint8_t, 96> member9293_{};
    std::array<std::int32_t, 24> member9297_{};
    std::array<std::uint8_t, 8> member9301_{};
    std::array<std::uint8_t, 15> member9343_{};
    std::int32_t member9349_{};
    std::int32_t member9350_{};
    std::array<std::uint8_t, 7> member9351_{};
    std::array<std::uint8_t, 7> member9352_{};
    std::array<std::uint8_t, 5> member9353_{};
    String member10775_{};
    String member10777_{};
    std::array<std::uint8_t, 6> member11603_{};
    std::string member11648_{};
    std::array<std::uint8_t, 6> member11685_{};
    std::int32_t member11888_{};
    std::array<std::uint8_t, 6> member13649_{};
};

struct ScriptState6
{
    ScriptState6();
    std::array<std::uint8_t, 5> member8149_{};
    std::int32_t member8176_{};
    std::array<std::uint8_t, 8> member8957_{};
    std::array<std::uint8_t, 8> member9641_{};
    std::array<std::uint8_t, 8> member9644_{};
    std::int32_t member9645_{};
    std::array<std::uint8_t, 6> member10280_{};
    std::array<std::uint8_t, 6> member10851_{};
    std::array<std::uint8_t, 9> member10899_{};
    String member11226_{};
    std::array<std::uint8_t, 9> member11227_{};
    std::array<std::uint8_t, 32> member12696_{};
    std::array<std::uint8_t, 64> member12698_{};
    std::int32_t member12700_{};
    IntRef member12701_{};
    std::int32_t member12708_{};
    IntRef member12711_{};
    std::array<std::uint8_t, 300> member12713_{};
    std::array<std::uint8_t, 300> member12715_{};
    std::array<std::int32_t, 75> member12717_{};
    IntRef member12728_{};
    std::int32_t member12730_{};
    std::array<std::uint8_t, 5> member12745_{};
    std::int32_t member12751_{};
    std::int32_t member12752_{};
    std::int32_t member12753_{};
    std::int32_t member12754_{};
    std::int32_t member12755_{};
    std::int32_t member12756_{};
    std::int32_t member12757_{};
    std::int32_t member12758_{};
    std::int32_t member12759_{};
    std::int32_t member12760_{};
    std::int32_t member12761_{};
    std::int32_t member12762_{};
    std::int32_t member12763_{};
    std::int32_t member12764_{};
    std::int32_t member12765_{};
    float member12767_{};
    Address member12768_{};
    float member12769_{};
    String member12770_{};
    std::int32_t member12771_{};
    std::int32_t member12772_{};
    std::int32_t member12774_{};
    std::array<std::uint8_t, 13> member12776_{};
    std::array<std::uint8_t, 4> member12777_{};
    std::array<std::uint8_t, 5> member12778_{};
    std::array<std::uint8_t, 5> member12779_{};
    std::array<std::uint8_t, 5> member12780_{};
    std::array<std::uint8_t, 5> member12781_{};
    std::int32_t member12783_{};
    std::int32_t member12784_{};
    std::int32_t member12785_{};
    std::int32_t member12786_{};
    std::int32_t member12787_{};
    std::int32_t member12788_{};
    std::array<std::uint8_t, 5> member12789_{};
    std::array<std::uint8_t, 10> member12790_{};
    std::array<std::uint8_t, 6> member12791_{};
    std::array<std::uint8_t, 8> member12792_{};
    std::array<std::uint8_t, 4> member12793_{};
    std::int32_t member12799_{};
    std::array<std::uint8_t, 256> member12812_{};
    std::int32_t member12814_{};
    std::int32_t member12815_{};
    String member12821_{};
    std::array<std::uint8_t, 128> member12830_{};
    String member12832_{};
    std::int32_t member12834_{};
    std::int32_t member12835_{};
    IntRef member12836_{};
    std::int32_t member12837_{};
    std::int32_t member12856_{};
    std::int32_t member12857_{};
    std::int32_t member12923_{};
};

struct ScriptState7
{
    ScriptState7();
    std::int32_t member7609_{};
    std::int32_t member7610_{};
    std::array<std::uint8_t, 4> member7612_{};
    std::int32_t member7640_{};
    std::int32_t member7641_{};
    std::int32_t member7642_{};
    String member7646_{};
    std::int32_t member7668_{};
    std::array<std::uint8_t, 8> member7669_{};
    std::array<std::uint8_t, 7> member7670_{};
    std::array<std::uint8_t, 8> member7671_{};
    String member7672_{};
    std::array<std::uint8_t, 21> member7673_{};
    std::array<std::uint8_t, 8> member7674_{};
    std::array<std::uint8_t, 4> member7692_{};
    std::int32_t member7697_{};
    String member7706_{};
    std::array<std::uint8_t, 11> member7731_{};
    std::array<std::uint8_t, 16> member7732_{};
    std::int32_t member7734_{};
    std::array<std::uint8_t, 11> member7738_{};
    std::array<String, 2> member7764_{};
    std::array<std::uint8_t, 6> member7768_{};
    std::array<std::uint8_t, 2> member7769_{};
    std::array<std::uint8_t, 16> member7770_{};
    std::int32_t member7776_{};
    std::int32_t member7777_{};
    MultiObject member7779_{};
    std::int8_t member7781_{};
    IntRef member7783_{};
    std::int32_t member7784_{};
    std::int32_t member7785_{};
    std::int32_t member7786_{};
    std::array<std::uint8_t, 92> member7792_{};
    std::array<std::uint8_t, 20> member7814_{};
    std::int32_t member7820_{};
    String member7821_{};
    std::int32_t member7824_{};
    std::int32_t member7828_{};
    String member7836_{};
    String member7838_{};
    std::int32_t member7844_{};
    std::int32_t member7845_{};
    std::int32_t member7846_{};
    std::array<std::uint8_t, 6> member7849_{};
    std::array<std::uint8_t, 4> member7850_{};
    String member7852_{};
    std::array<std::uint8_t, 6> member7854_{};
    String member7855_{};
    std::array<std::uint8_t, 11> member7856_{};
    std::array<std::uint8_t, 30> member7859_{};
    std::array<std::uint8_t, 18> member7868_{};
    std::array<std::uint8_t, 11> member7871_{};
    std::array<std::uint8_t, 11> member7878_{};
    std::array<std::uint8_t, 18> member7891_{};
    std::array<std::uint8_t, 18> member7894_{};
    std::array<std::uint8_t, 1> member7895_{};
    std::array<String, 2> member7906_{};
    std::array<std::uint8_t, 20> member7908_{};
    std::array<std::uint8_t, 67> member7910_{};
    std::array<std::uint8_t, 29> member7911_{};
    std::array<std::uint8_t, 40> member7912_{};
    std::array<std::uint8_t, 18> member7913_{};
    String member7929_{};
    std::int32_t member7961_{};
    std::int32_t member7963_{};
    std::int32_t member7968_{};
    std::array<std::uint8_t, 16> member7996_{};
    std::array<std::uint8_t, 11> member7997_{};
    std::array<std::uint8_t, 18> member8017_{};
    String member8036_{};
    std::array<std::uint8_t, 9> member8082_{};
    std::int32_t member8158_{};
    std::int32_t member8195_{};
    std::array<std::uint8_t, 20> member8227_{};
    float member8363_{};
    std::int32_t member8365_{};
    std::int32_t member8366_{};
    std::int32_t member8368_{};
    String member8370_{};
    std::array<std::uint8_t, 32> member8374_{};
    std::array<std::uint8_t, 92> member8377_{};
    std::array<std::uint8_t, 25> member8380_{};
    std::array<std::uint8_t, 18> member8382_{};
    std::array<std::uint8_t, 5> member8383_{};
    std::array<std::uint8_t, 11> member8384_{};
    std::array<std::uint8_t, 5> member8385_{};
    std::array<std::uint8_t, 11> member8386_{};
    std::array<std::uint8_t, 6> member8387_{};
    std::array<std::uint8_t, 18> member8388_{};
    std::array<std::uint8_t, 15> member8389_{};
    std::array<std::uint8_t, 16> member8390_{};
    std::array<std::uint8_t, 11> member8391_{};
    std::array<std::uint8_t, 11> member8393_{};
    std::int32_t member8395_{};
    std::array<std::uint8_t, 11> member8398_{};
    std::array<std::uint8_t, 18> member8400_{};
    std::array<std::uint8_t, 18> member8401_{};
    std::array<std::uint8_t, 11> member8402_{};
    std::array<std::uint8_t, 11> member8403_{};
    std::array<std::uint8_t, 2> member8404_{};
    String member8405_{};
    std::array<std::uint8_t, 18> member8406_{};
    std::array<std::int8_t, 8> member8410_{};
    std::array<std::uint8_t, 18> member8412_{};
    std::array<std::uint8_t, 1> member8413_{};
    std::array<std::uint8_t, 18> member8420_{};
    std::array<std::uint8_t, 1> member8421_{};
    std::array<std::uint8_t, 18> member8441_{};
    String member8442_{};
    std::array<std::uint8_t, 5> member8443_{};
    std::array<std::uint8_t, 12> member8446_{};
    std::array<std::uint8_t, 16> member8447_{};
    std::array<std::uint8_t, 11> member8448_{};
    std::array<std::uint8_t, 128> member8451_{};
    std::array<std::uint8_t, 11> member8453_{};
    std::array<std::uint8_t, 4> member8454_{};
    std::int32_t member8585_{};
    std::array<std::uint8_t, 8> member8944_{};
    std::int32_t member9025_{};
    std::array<std::uint8_t, 6> member9154_{};
    std::int32_t member9159_{};
    std::array<std::uint8_t, 7> member9234_{};
    std::array<std::uint8_t, 1> member9382_{};
    std::int32_t member9410_{};
    IntRef member9420_{};
    IntRef member9421_{};
    IntRef member9422_{};
    IntRef member9423_{};
    IntRef member9424_{};
    std::array<std::uint8_t, 8> member9429_{};
    std::int32_t member9448_{};
    std::int32_t member9449_{};
    std::int32_t member9451_{};
    std::array<std::uint8_t, 16> member9460_{};
    std::array<std::uint8_t, 11> member9461_{};
    std::int32_t member9463_{};
    std::array<std::uint8_t, 128> member9465_{};
    std::array<std::uint8_t, 4> member9467_{};
    std::int32_t member9489_{};
    std::int32_t member9490_{};
    std::int32_t member9518_{};
    std::int32_t member9540_{};
    std::array<std::uint8_t, 4> member9643_{};
    std::array<std::uint8_t, 10> member9646_{};
    String member10020_{};
    std::int32_t member10781_{};
    std::int32_t member10792_{};
    std::array<std::uint8_t, 18> member10900_{};
    std::array<std::uint8_t, 18> member10931_{};
    float member11006_{};
    std::array<std::uint8_t, 30> member11015_{};
    std::array<std::uint8_t, 11> member11016_{};
    std::array<std::uint8_t, 15> member11018_{};
    std::array<std::uint8_t, 16> member11019_{};
    std::array<std::uint8_t, 11> member11020_{};
    std::array<std::uint8_t, 6> member11040_{};
    std::array<std::uint8_t, 18> member11041_{};
    std::array<std::uint8_t, 128> member11043_{};
    std::array<std::uint8_t, 4> member11045_{};
    std::array<std::uint8_t, 5> member11046_{};
    std::array<std::uint8_t, 16> member11129_{};
    std::string member11133_;
    MultiObjectActionParameters member11139_{};
    String member11145_{};
    std::array<std::uint8_t, 9> member11146_{};
    std::array<std::uint8_t, 1> member11175_{};
    std::array<std::uint8_t, 8> member11179_{};
    std::array<std::uint8_t, 2> member11185_{};
    std::array<std::uint8_t, 18> member11188_{};
    std::array<std::int8_t, 14> member11190_{};
    std::array<std::int8_t, 14> member11192_{};
    std::array<std::uint8_t, 11> member11196_{};
    std::array<std::uint8_t, 11> member11202_{};
    std::array<std::uint8_t, 18> member11203_{};
    std::array<std::uint8_t, 11> member11204_{};
    std::array<std::uint8_t, 11> member11206_{};
    std::int32_t member11218_{};
    std::int32_t member11219_{};
    std::int32_t member11220_{};
    std::array<std::uint8_t, 9> member11222_{};
    std::array<std::uint8_t, 6> member11291_{};
    float member11423_{};
    std::array<std::uint8_t, 16> member11428_{};
    std::array<std::uint8_t, 18> member11429_{};
    std::array<std::uint8_t, 16> member11430_{};
    std::array<std::uint8_t, 11> member11431_{};
    std::int32_t member11446_{};
    std::int32_t member11448_{};
    std::int32_t member11449_{};
    std::array<std::uint8_t, 8> member11450_{};
    std::array<std::uint8_t, 8> member11475_{};
    std::array<std::uint8_t, 128> member11735_{};
    std::array<std::uint8_t, 4> member11736_{};
    std::array<std::uint8_t, 5> member11776_{};
    String member11994_{};
    std::array<std::uint8_t, 9> member11995_{};
    String member12040_{};
    std::int8_t member12071_{};
    std::array<std::uint8_t, 18> member12079_{};
    std::array<std::uint8_t, 18> member12080_{};
    std::int32_t member12227_{};
    std::int32_t member12228_{};
    std::int32_t member12229_{};
    std::int32_t member12230_{};
    std::int32_t member12231_{};
    std::int32_t member12239_{};
    std::array<std::uint8_t, 8> member12242_{};
    std::int32_t member12245_{};
    std::int32_t member12246_{};
    std::int32_t member12247_{};
    std::int32_t member12248_{};
    std::int32_t member12261_{};
    std::int32_t member12263_{};
    std::array<std::uint8_t, 11> member12302_{};
    std::array<std::uint8_t, 11> member12315_{};
    std::array<std::uint8_t, 18> member12317_{};
    std::array<std::uint8_t, 11> member12318_{};
    std::int32_t member12335_{};
    std::int32_t member12336_{};
    std::array<std::uint8_t, 128> member12338_{};
    std::array<std::uint8_t, 11> member12340_{};
    std::array<std::uint8_t, 4> member12341_{};
    std::array<std::uint8_t, 18> member12342_{};
    std::array<std::uint8_t, 6> member12380_{};
    std::int32_t member12406_{};
    std::int32_t member13029_{};
    std::array<std::uint8_t, 7> member13591_{};
    std::array<std::uint8_t, 6> member13592_{};
    std::array<std::uint8_t, 7> member13595_{};
    std::array<std::uint8_t, 18> member13706_{};
    std::array<std::uint8_t, 128> member13725_{};
    std::array<std::uint8_t, 4> member13726_{};
    String member13794_{};
    std::array<std::uint8_t, 18> member13939_{};
    std::array<std::uint8_t, 11> member13940_{};
    std::array<std::uint8_t, 18> member13945_{};
    std::array<std::uint8_t, 1> member14119_{};
    std::int32_t member14629_{};
    std::array<std::uint8_t, 18> member14650_{};
    std::array<std::uint8_t, 56> member14664_{};
    String member14665_{};
    std::int32_t member14666_{};
    std::int32_t member14667_{};
    std::int32_t member14668_{};
    std::int32_t member14679_{};
    std::int8_t member14680_{};
    std::array<std::uint8_t, 11> member14686_{};
    std::array<std::uint8_t, 3> member14687_{};
    std::array<std::uint8_t, 8> member14689_{};
    std::array<std::uint8_t, 8> member14690_{};
    std::array<std::uint8_t, 8> member14691_{};
    std::array<std::uint8_t, 3> member14692_{};
    std::array<std::uint8_t, 2> member14693_{};
    std::array<std::uint8_t, 11> member14694_{};
    std::array<std::uint8_t, 18> member14697_{};
    std::array<std::uint8_t, 1> member14698_{};
    float member14699_{};
    std::array<std::uint8_t, 11> member14700_{};
    std::array<std::uint8_t, 20> member14701_{};
    std::array<std::uint8_t, 5> member14702_{};
    String member14814_{};
    std::array<std::uint8_t, 18> member14816_{};
    std::array<std::uint8_t, 18> member14819_{};
    std::int32_t member14941_{};
    float member15079_{};
    std::array<std::uint8_t, 5> member15285_{};
    std::array<std::uint8_t, 18> member15459_{};
    std::array<std::uint8_t, 5> member16130_{};
};

struct ScriptState8
{
    ScriptState8();
    std::array<std::uint8_t, 3> member7790_{};
    std::array<std::uint8_t, 18> member8005_{};
    String member8145_{};
    std::array<std::uint8_t, 18> member8147_{};
    String member8148_{};
    std::int32_t member8440_{};
    std::array<std::int32_t, 4> member9416_{};
    String member9430_{};
    std::array<std::uint8_t, 9> member9431_{};
    std::int32_t member9450_{};
    std::int32_t member9454_{};
    std::array<std::uint8_t, 18> member9468_{};
    std::array<std::uint8_t, 11> member9479_{};
    std::array<std::uint8_t, 18> member9480_{};
    std::array<std::uint8_t, 11> member9481_{};
    std::array<std::uint8_t, 21> member9519_{};
    std::int32_t member9539_{};
    std::int32_t member9542_{};
    std::array<std::uint8_t, 9> member9544_{};
    std::array<std::uint8_t, 8> member9639_{};
    std::array<std::uint8_t, 4> member9640_{};
    std::array<std::uint8_t, 8> member9642_{};
    std::array<std::uint8_t, 6> member10281_{};
    std::array<std::uint8_t, 5> member11433_{};
    std::int32_t member11447_{};
    std::int32_t member11933_{};
};

struct ScriptState9
{
    ScriptState9();
    std::int32_t member193_{};
    std::int32_t member195_{};
    std::int32_t member199_{};
    std::int32_t member202_{};
    String member203_{};
    std::array<std::uint8_t, 8> member204_{};
    std::array<std::uint8_t, 20> member251_{};
    std::int32_t member682_{};
    std::int32_t member683_{};
    String member685_{};
    std::array<std::uint8_t, 8> member7666_{};
    float member7694_{};
    float member7695_{};
    std::int32_t member7696_{};
    std::int32_t member7700_{};
    IntRef member7708_{};
    std::array<std::uint8_t, 32> member7710_{};
    std::int32_t member7712_{};
    std::array<std::uint8_t, 6> member7713_{};
    std::array<std::uint8_t, 4> member7714_{};
    String member7719_{};
    std::array<std::uint8_t, 11> member7720_{};
    std::array<std::uint8_t, 30> member7721_{};
    std::array<std::uint8_t, 25> member7722_{};
    std::array<std::uint8_t, 30> member7723_{};
    std::array<std::uint8_t, 5> member7724_{};
    std::array<std::uint8_t, 5> member7725_{};
    std::array<std::uint8_t, 11> member7726_{};
    std::array<std::uint8_t, 18> member7728_{};
    std::array<std::uint8_t, 15> member7729_{};
    std::array<std::uint8_t, 16> member7730_{};
    std::array<std::uint8_t, 128> member7736_{};
    std::array<std::uint8_t, 4> member7739_{};
    std::array<std::uint8_t, 11> member7745_{};
    std::array<std::uint8_t, 11> member7747_{};
    std::array<std::uint8_t, 20> member7758_{};
    std::array<std::uint8_t, 67> member7760_{};
    std::array<std::uint8_t, 29> member7761_{};
    std::array<std::uint8_t, 40> member7762_{};
    std::array<std::uint8_t, 18> member7763_{};
    std::array<std::uint8_t, 56> member7793_{};
    std::int32_t member7795_{};
    float member7822_{};
    std::int32_t member7825_{};
    std::int32_t member7826_{};
    std::int32_t member7827_{};
    std::int32_t member7829_{};
    std::int32_t member7830_{};
    std::int32_t member7832_{};
    std::int32_t member7833_{};
    String member7835_{};
    std::array<std::uint8_t, 12> member7840_{};
    std::array<std::uint8_t, 32> member7842_{};
    std::array<std::uint8_t, 92> member7847_{};
    std::array<std::uint8_t, 30> member7857_{};
    std::array<std::uint8_t, 25> member7858_{};
    std::array<std::uint8_t, 5> member7860_{};
    std::array<std::uint8_t, 18> member7861_{};
    std::array<std::uint8_t, 18> member7862_{};
    std::array<std::uint8_t, 1> member7863_{};
    std::array<std::uint8_t, 5> member7864_{};
    std::array<std::uint8_t, 5> member7866_{};
    std::array<std::uint8_t, 6> member7867_{};
    std::array<std::uint8_t, 15> member7869_{};
    std::array<std::uint8_t, 16> member7870_{};
    std::array<std::uint8_t, 11> member7873_{};
    std::int32_t member7874_{};
    std::array<std::uint8_t, 11> member7880_{};
    std::array<std::uint8_t, 18> member7881_{};
    std::array<std::uint8_t, 11> member7882_{};
    std::array<std::uint8_t, 18> member7883_{};
    std::array<std::uint8_t, 11> member7884_{};
    std::array<std::uint8_t, 11> member7885_{};
    std::array<std::uint8_t, 2> member7886_{};
    String member7887_{};
    std::array<std::uint8_t, 18> member7888_{};
    std::array<std::uint8_t, 11> member7889_{};
    std::array<std::int8_t, 8> member7893_{};
    std::array<std::uint8_t, 18> member7903_{};
    std::array<std::uint8_t, 1> member7904_{};
    float member7959_{};
    std::int32_t member7962_{};
    std::int32_t member7964_{};
    std::int32_t member7966_{};
    std::array<std::uint8_t, 12> member7975_{};
    std::array<std::uint8_t, 6> member7982_{};
    String member7984_{};
    std::array<std::uint8_t, 5> member7991_{};
    std::array<std::uint8_t, 11> member7992_{};
    std::array<std::uint8_t, 18> member7994_{};
    std::array<std::uint8_t, 15> member7995_{};
    std::int32_t member7999_{};
    std::array<std::uint8_t, 11> member8004_{};
    std::array<std::uint8_t, 18> member8006_{};
    std::array<std::uint8_t, 18> member8011_{};
    std::array<std::uint8_t, 18> member8015_{};
    std::array<std::uint8_t, 1> member8016_{};
    std::array<std::int8_t, 14> member8020_{};
    String member8209_{};
    std::array<std::uint8_t, 11> member8348_{};
    std::array<std::uint8_t, 16> member8392_{};
    std::array<std::uint8_t, 128> member8396_{};
    std::array<std::uint8_t, 4> member8399_{};
    std::array<std::uint8_t, 11> member8407_{};
    std::array<std::uint8_t, 3> member8408_{};
    std::array<std::uint8_t, 18> member8414_{};
    std::array<std::uint8_t, 1> member8415_{};
    std::array<std::int8_t, 14> member8417_{};
    std::array<std::uint8_t, 5> member8422_{};
    std::int32_t member8435_{};
    std::int32_t member8436_{};
    std::int32_t member8437_{};
    std::int32_t member8439_{};
    std::array<std::uint8_t, 18> member8834_{};
    std::int32_t member9093_{};
    std::int32_t member9095_{};
    std::array<std::uint8_t, 30> member9102_{};
    std::array<std::uint8_t, 7> member9166_{};
    std::array<std::uint8_t, 10> member9715_{};
    std::int32_t member10675_{};
    std::array<std::uint8_t, 3> member10935_{};
    std::array<std::uint8_t, 3> member10941_{};
    std::array<std::uint8_t, 56> member11130_{};
    String member11132_{};
    std::int32_t member11135_{};
    std::int32_t member11136_{};
    std::int32_t member11137_{};
    std::int32_t member11138_{};
    std::int32_t member11161_{};
    std::int8_t member11164_{};
    std::array<std::uint8_t, 11> member11170_{};
    std::array<std::uint8_t, 3> member11171_{};
    std::array<std::uint8_t, 18> member11172_{};
    std::array<std::uint8_t, 18> member11176_{};
    std::array<std::uint8_t, 1> member11177_{};
    std::array<std::uint8_t, 8> member11178_{};
    std::array<std::uint8_t, 8> member11180_{};
    std::array<std::uint8_t, 8> member11181_{};
    std::array<std::uint8_t, 11> member11182_{};
    std::array<std::uint8_t, 3> member11183_{};
    std::array<std::uint8_t, 11> member11184_{};
    std::array<std::uint8_t, 11> member11186_{};
    std::array<std::uint8_t, 2> member11187_{};
    std::array<std::uint8_t, 18> member11194_{};
    std::array<std::uint8_t, 1> member11195_{};
    std::array<std::uint8_t, 18> member11197_{};
    std::array<std::uint8_t, 11> member11198_{};
    float member11200_{};
    std::array<std::uint8_t, 11> member11201_{};
    std::array<std::uint8_t, 18> member11205_{};
    std::array<std::uint8_t, 18> member11207_{};
    std::array<std::uint8_t, 5> member11208_{};
    std::int32_t member11224_{};
    float member11244_{};
    String member11333_{};
    std::array<std::uint8_t, 4> member11607_{};
    float member11762_{};
    std::array<std::uint8_t, 5> member11768_{};
    std::array<std::uint8_t, 11> member11769_{};
    std::array<std::uint8_t, 11> member11771_{};
    std::array<std::uint8_t, 128> member11774_{};
    std::array<std::uint8_t, 4> member11775_{};
    std::array<std::uint8_t, 5> member12019_{};
    std::array<std::uint8_t, 18> member12043_{};
    std::int32_t member12045_{};
    float member12264_{};
    std::int32_t member12266_{};
    std::array<std::uint8_t, 18> member12291_{};
    std::array<std::uint8_t, 11> member12298_{};
    std::array<std::uint8_t, 2> member12301_{};
    std::array<std::int8_t, 14> member12305_{};
    std::array<std::uint8_t, 18> member12311_{};
    std::array<std::uint8_t, 11> member12312_{};
    std::array<std::uint8_t, 18> member12319_{};
    std::array<std::uint8_t, 11> member12320_{};
    std::array<std::uint8_t, 18> member12321_{};
    std::array<std::uint8_t, 11> member12322_{};
    std::int32_t member12486_{};
    String member13039_{};
    std::array<std::uint8_t, 14> member13342_{};
    std::array<std::uint8_t, 16> member13636_{};
    std::array<std::int32_t, 14> member13663_{};
    float member13676_{};
    std::int32_t member13677_{};
    std::int32_t member13678_{};
    std::int32_t member13679_{};
    String member13680_{};
    std::int8_t member13681_{};
    std::array<std::uint8_t, 12> member13683_{};
    std::array<std::uint8_t, 32> member13684_{};
    std::array<std::uint8_t, 92> member13685_{};
    std::array<std::uint8_t, 18> member13687_{};
    std::array<std::uint8_t, 18> member13688_{};
    std::array<std::uint8_t, 2> member13689_{};
    String member13690_{};
    std::array<std::uint8_t, 18> member13691_{};
    std::array<std::uint8_t, 11> member13692_{};
    std::array<std::uint8_t, 3> member13693_{};
    std::array<std::int8_t, 8> member13695_{};
    std::array<std::uint8_t, 18> member13697_{};
    std::array<std::uint8_t, 1> member13698_{};
    std::array<std::int8_t, 14> member13700_{};
    std::array<std::int8_t, 14> member13702_{};
    std::array<std::uint8_t, 18> member13704_{};
    std::array<std::uint8_t, 1> member13705_{};
    std::array<std::uint8_t, 11> member13707_{};
    std::array<std::uint8_t, 5> member13708_{};
    std::array<std::uint8_t, 5> member13730_{};
    std::array<std::uint8_t, 6> member13795_{};
    std::array<std::uint8_t, 11> member13855_{};
    std::array<std::uint8_t, 18> member13858_{};
    std::array<std::uint8_t, 18> member13863_{};
    std::array<std::uint8_t, 18> member13926_{};
    std::array<std::uint8_t, 1> member13927_{};
    std::array<std::uint8_t, 8> member13933_{};
    std::array<std::uint8_t, 18> member13934_{};
    std::array<std::int8_t, 14> member13936_{};
    std::array<std::uint8_t, 11> member13943_{};
    std::array<std::uint8_t, 18> member13944_{};
    std::array<std::uint8_t, 8> member14011_{};
    std::array<std::uint8_t, 8> member14012_{};
    std::array<std::uint8_t, 3> member14014_{};
    std::array<std::uint8_t, 11> member14015_{};
    std::array<std::uint8_t, 11> member14016_{};
    std::array<std::uint8_t, 18> member14021_{};
    std::array<std::uint8_t, 1> member14022_{};
    std::array<std::uint8_t, 18> member14023_{};
    std::array<std::uint8_t, 11> member14027_{};
    std::array<std::uint8_t, 18> member14029_{};
    std::int32_t member14082_{};
    std::array<std::uint8_t, 18> member14120_{};
    String member14251_{};
    std::array<std::uint8_t, 1> member14644_{};
    std::int32_t member14943_{};
    std::array<std::uint8_t, 11> member15229_{};
    std::int32_t member15323_{};
    std::int32_t member15324_{};
    std::int32_t member15325_{};
    std::array<std::uint8_t, 8> member15326_{};
    std::array<std::uint8_t, 11> member15327_{};
    std::array<std::uint8_t, 17> member15333_{};
    std::array<std::uint8_t, 11> member15850_{};
    std::array<std::uint8_t, 56> member15928_{};
    std::int32_t member15931_{};
    std::int32_t member15932_{};
    String member15942_{};
    std::int8_t member15943_{};
    std::array<std::uint8_t, 32> member15944_{};
    std::array<std::uint8_t, 92> member15945_{};
    std::array<std::uint8_t, 6> member15946_{};
    std::array<std::uint8_t, 18> member15947_{};
    std::array<std::uint8_t, 2> member15953_{};
    String member15954_{};
    std::array<std::uint8_t, 3> member15955_{};
    std::array<std::int8_t, 8> member15956_{};
    std::array<std::uint8_t, 1> member15957_{};
    std::array<std::uint8_t, 8> member15958_{};
    std::array<std::uint8_t, 3> member15959_{};
    std::array<std::uint8_t, 11> member15960_{};
    std::array<std::uint8_t, 2> member15961_{};
    std::array<std::uint8_t, 2> member15962_{};
    std::array<std::int8_t, 14> member15964_{};
    std::array<std::int8_t, 14> member15966_{};
    std::array<std::uint8_t, 1> member15968_{};
    std::array<std::uint8_t, 11> member15969_{};
    std::array<std::uint8_t, 9> member16200_{};
    std::array<std::uint8_t, 8> member16201_{};
    std::array<std::uint8_t, 9> member16202_{};
    std::array<std::uint8_t, 9> member16234_{};
    std::int32_t member16246_{};
    std::int32_t member16247_{};
};

struct ScriptState10
{
    ScriptState10();
    std::array<std::uint8_t, 18> member7987_{};
    std::int32_t member8152_{};
    std::int32_t member8153_{};
    std::int32_t member8154_{};
    std::array<std::uint8_t, 20> member8161_{};
    std::int32_t member8164_{};
    std::int32_t member8170_{};
    std::int32_t member8171_{};
    std::int32_t member8172_{};
    std::int32_t member8173_{};
    std::int32_t member8174_{};
    std::array<std::uint8_t, 16> member8180_{};
    std::array<std::uint8_t, 56> member8182_{};
    String member8184_{};
    std::string member8186_;
    std::int32_t member8188_{};
    std::int32_t member8190_{};
    std::int32_t member8191_{};
    MultiObjectActionParameters member8193_{};
    IntRef member8196_{};
    IntRef member8197_{};
    IntRef member8198_{};
    std::int32_t member8203_{};
    IntRef member8204_{};
    std::int32_t member8205_{};
    std::int32_t member8208_{};
    String member8214_{};
    std::array<std::uint8_t, 9> member8215_{};
    std::array<std::uint8_t, 7> member8239_{};
    std::array<std::uint8_t, 20> member8242_{};
    std::array<std::uint8_t, 67> member8244_{};
    std::array<std::uint8_t, 29> member8245_{};
    std::array<std::uint8_t, 40> member8246_{};
    std::array<std::uint8_t, 22> member8262_{};
    std::int32_t member8267_{};
    std::int32_t member8268_{};
    std::int32_t member8269_{};
    std::int32_t member8331_{};
    std::int32_t member8332_{};
    std::int32_t member8333_{};
    std::int32_t member8334_{};
    std::int32_t member8335_{};
    std::array<std::uint8_t, 256> member8337_{};
    String member8339_{};
    std::array<std::uint8_t, 5> member8340_{};
    std::int32_t member8342_{};
    float member8343_{};
    std::int32_t member8826_{};
    std::array<String, 2> member8833_{};
    std::array<std::uint8_t, 1> member8835_{};
    std::array<std::uint8_t, 5> member8844_{};
    std::array<std::uint8_t, 5> member8950_{};
    std::array<std::uint8_t, 5> member8951_{};
    std::array<std::uint8_t, 3> member9732_{};
    std::int32_t member10924_{};
    std::int32_t member11545_{};
    std::int32_t member11550_{};
    std::array<std::uint8_t, 5> member11604_{};
    std::array<std::uint8_t, 5> member12565_{};
    String member12968_{};
    std::array<std::uint8_t, 6> member13427_{};
    std::array<std::uint8_t, 6> member13596_{};
};

struct ScriptState11
{
    ScriptState11();
    std::array<std::uint8_t, 32> member112_{};
    std::array<std::uint8_t, 32> member114_{};
    std::array<std::int32_t, 8> member121_{};
    std::int32_t member7743_{};
    std::array<std::uint8_t, 11> member7749_{};
    std::array<std::uint8_t, 11> member7751_{};
    std::array<std::uint8_t, 11> member7753_{};
    std::array<std::uint8_t, 18> member7896_{};
    std::array<std::uint8_t, 1> member7897_{};
    std::int32_t member7965_{};
    std::int32_t member7969_{};
    String member7971_{};
    std::array<std::uint8_t, 92> member7980_{};
    std::array<std::uint8_t, 5> member7989_{};
    std::array<std::uint8_t, 11> member7990_{};
    std::array<std::uint8_t, 6> member7993_{};
    std::array<std::uint8_t, 128> member8001_{};
    std::array<std::uint8_t, 4> member8003_{};
    std::array<std::uint8_t, 2> member8007_{};
    String member8008_{};
    std::array<std::uint8_t, 3> member8010_{};
    std::array<std::int8_t, 8> member8013_{};
    std::array<std::uint8_t, 1> member8018_{};
    std::int32_t member8508_{};
    std::int32_t member8509_{};
    std::int32_t member8511_{};
    std::int32_t member8512_{};
    std::array<std::uint8_t, 5> member8586_{};
    std::array<std::uint8_t, 5> member8955_{};
    std::array<std::uint8_t, 48> member9170_{};
    std::array<std::uint8_t, 48> member9172_{};
    std::array<std::int32_t, 12> member9176_{};
    std::array<std::uint8_t, 80> member9224_{};
    std::array<std::uint8_t, 80> member9226_{};
    std::array<std::int32_t, 20> member9230_{};
    std::int32_t member9398_{};
    std::int32_t member9399_{};
    std::int32_t member9400_{};
    std::int32_t member10199_{};
    std::int32_t member10200_{};
    std::int32_t member10201_{};
    std::array<std::uint8_t, 16> member10344_{};
    std::array<std::uint8_t, 16> member10345_{};
    std::array<std::int32_t, 4> member10349_{};
    std::int32_t member10418_{};
    std::array<std::uint8_t, 10> member10419_{};
    std::array<std::uint8_t, 20> member10430_{};
    std::int32_t member10790_{};
    std::array<std::uint8_t, 9> member10796_{};
    std::int32_t member10797_{};
    std::int32_t member10798_{};
    std::array<std::uint8_t, 9> member10846_{};
    std::array<std::uint8_t, 5> member10937_{};
    float member11007_{};
    std::array<std::uint8_t, 18> member11017_{};
    std::int32_t member11228_{};
    String member11328_{};
    float member11484_{};
    float member11486_{};
    std::array<std::uint8_t, 6> member11557_{};
    std::array<std::uint8_t, 5> member11564_{};
    std::array<std::uint8_t, 16> member11770_{};
    std::array<std::uint8_t, 128> member12076_{};
    std::array<std::uint8_t, 4> member12078_{};
    std::array<std::uint8_t, 1> member12293_{};
    std::array<std::uint8_t, 8> member12294_{};
    std::array<std::uint8_t, 8> member12296_{};
    std::array<std::uint8_t, 8> member12297_{};
    std::array<std::uint8_t, 3> member12299_{};
    std::array<std::uint8_t, 11> member12300_{};
    std::array<std::uint8_t, 2> member12303_{};
    std::array<std::uint8_t, 1> member12309_{};
    std::array<std::uint8_t, 11> member12310_{};
    float member12314_{};
    float member13841_{};
    std::int32_t member13842_{};
    std::int32_t member13843_{};
    String member13844_{};
    std::array<std::uint8_t, 12> member13846_{};
    std::array<std::uint8_t, 32> member13847_{};
    std::array<std::uint8_t, 92> member13848_{};
    std::array<std::uint8_t, 18> member13851_{};
    std::array<std::uint8_t, 2> member13856_{};
    String member13857_{};
    std::array<std::uint8_t, 11> member13859_{};
    std::array<std::int8_t, 8> member13861_{};
    std::array<std::uint8_t, 1> member13864_{};
    std::array<std::uint8_t, 18> member13865_{};
    std::array<std::uint8_t, 1> member13866_{};
    std::array<std::uint8_t, 56> member13898_{};
    String member13899_{};
    std::string member13900_;
    std::int32_t member13901_{};
    std::int32_t member13902_{};
    std::int32_t member13903_{};
    float member13917_{};
    std::int8_t member13918_{};
    std::array<std::uint8_t, 3> member13924_{};
    std::array<std::uint8_t, 18> member13928_{};
    std::array<std::uint8_t, 1> member13929_{};
    std::array<std::uint8_t, 18> member13930_{};
    std::array<std::uint8_t, 1> member13931_{};
    std::array<std::uint8_t, 8> member13932_{};
    float member13942_{};
    std::array<std::uint8_t, 5> member13946_{};
    std::array<std::uint8_t, 8> member14010_{};
    std::array<std::uint8_t, 18> member14017_{};
    std::array<std::uint8_t, 11> member14028_{};
};

struct ScriptState12
{
    ScriptState12();
    std::array<std::uint8_t, 16> member7872_{};
    std::array<std::uint8_t, 128> member7876_{};
    std::array<std::uint8_t, 4> member7879_{};
    std::array<std::uint8_t, 25> member7986_{};
    std::int32_t member13616_{};
    float member13624_{};
    std::array<std::uint8_t, 30> member13627_{};
    std::array<std::uint8_t, 18> member13628_{};
    std::array<std::uint8_t, 1> member13629_{};
    std::array<std::uint8_t, 5> member13630_{};
    std::array<std::uint8_t, 11> member13631_{};
    std::array<std::uint8_t, 5> member13632_{};
    std::array<std::uint8_t, 6> member13633_{};
    std::array<std::uint8_t, 18> member13634_{};
    std::array<std::uint8_t, 15> member13635_{};
    std::array<std::uint8_t, 5> member13637_{};
};

struct ScriptState13
{
    ScriptState13();
    std::array<std::uint8_t, 5> member7746_{};
    std::array<std::uint8_t, 5> member11024_{};
    std::array<std::uint8_t, 6> member11783_{};
};

struct ScriptState14
{
    ScriptState14();
    std::array<std::uint8_t, 18> member10897_{};
    std::array<std::uint8_t, 18> member11053_{};
    String member15981_{};
};

struct ScriptState15
{
    ScriptState15();
    std::array<std::uint8_t, 3> member7890_{};
    std::array<std::int8_t, 14> member7899_{};
    std::array<std::int8_t, 14> member7901_{};
    std::array<std::uint8_t, 5> member7905_{};
    std::array<std::uint8_t, 11> member14122_{};
    std::array<std::uint8_t, 11> member14929_{};
};

struct ScriptState16
{
    ScriptState16();
    std::int32_t member13978_{};
    std::int32_t member14041_{};
    std::int32_t member14042_{};
    std::int32_t member14044_{};
    std::int32_t member14045_{};
    float member14046_{};
    Address member14048_{};
    Address member14049_{};
    String member14818_{};
};

struct ScriptState17
{
    ScriptState17();
    std::array<std::uint8_t, 4> member7643_{};
    std::array<std::uint8_t, 11> member8009_{};
    std::array<std::uint8_t, 11> member13667_{};
};

struct ScriptState18
{
    ScriptState18();
    std::string member7618_;
    std::int32_t member7638_{};
    String member7639_{};
    String member7702_{};
    std::int8_t member7703_{};
    std::array<std::int32_t, 4> member7741_{};
    std::array<std::uint8_t, 5> member7744_{};
    std::array<std::uint8_t, 5> member7748_{};
    std::array<std::uint8_t, 5> member7750_{};
    std::array<std::uint8_t, 5> member7752_{};
    std::array<std::uint8_t, 5> member7754_{};
    std::array<std::uint8_t, 11> member7755_{};
    std::array<std::uint8_t, 5> member7756_{};
    std::int32_t member7789_{};
};

struct ScriptState19
{
    std::int32_t member15780_{};
    String member15782_{};
    std::int32_t member15797_{};
};

struct ScriptState20
{
    ScriptState20();
    std::array<std::uint8_t, 32> member15789_{};
    IntRef member15790_{};
    std::array<std::uint8_t, 7> member15796_{};
    std::array<std::uint8_t, 7> member15798_{};
};

struct ScriptState21
{
    ScriptState21();
    std::array<std::uint8_t, 16> member8254_{};
    std::array<std::uint8_t, 11> member12947_{};
    std::int32_t member12948_{};
    std::array<std::uint8_t, 7> member12962_{};
    std::int32_t member13109_{};
    std::int32_t member13340_{};
    std::array<std::uint8_t, 11> member13343_{};
};

struct ScriptState22
{
    ScriptState22();
    std::array<std::uint8_t, 300> member12859_{};
    std::array<IntRef, 25> member12861_{};
    std::array<std::uint8_t, 300> member12862_{};
    std::array<std::uint8_t, 300> member12864_{};
    std::array<IntRef, 25> member12865_{};
    std::array<std::uint8_t, 9> member12921_{};
    std::array<std::uint8_t, 11> member13172_{};
    std::array<std::uint8_t, 11> member13173_{};
};

struct ScriptState23
{
    ScriptState23();
    float member9370_{};
    float member9371_{};
    String member9379_{};
    std::array<std::uint8_t, 6> member9380_{};
    std::array<std::uint8_t, 25> member9381_{};
    std::array<std::uint8_t, 16> member9383_{};
    std::array<std::uint8_t, 18> member9384_{};
};

struct ScriptState24
{
    ScriptState24();
    std::array<std::uint8_t, 8> member11121_{};
    std::int32_t member14840_{};
    std::int32_t member14844_{};
};

struct ScriptState25
{
    ScriptState25();
    std::array<std::uint8_t, 2> member12451_{};
    std::array<std::uint8_t, 16> member12452_{};
    std::array<std::uint8_t, 5> member12453_{};
};

struct ScriptState26
{
    ScriptState26();
    std::int32_t member14555_{};
    std::int32_t member15510_{};
    std::array<Address, 2> member15512_{};
    std::int32_t member15537_{};
    std::int32_t member15538_{};
    std::int32_t member15539_{};
    std::array<std::uint8_t, 20> member15542_{};
    std::int32_t member15544_{};
    std::array<std::uint8_t, 14> member15545_{};
    std::array<std::uint8_t, 8> member15546_{};
    std::array<std::uint8_t, 6> member15547_{};
    std::array<std::uint8_t, 14> member15548_{};
    std::array<std::uint8_t, 6> member15549_{};
    std::array<std::uint8_t, 14> member15550_{};
    std::int32_t member15555_{};
    String member15556_{};
    std::array<std::uint8_t, 7> member15560_{};
};

struct ScriptState27
{
    std::array<std::uint8_t, 64> member9681_{};
    std::array<std::uint8_t, 64> member9683_{};
    std::array<std::int32_t, 16> member9687_{};
};

struct ScriptState28
{
    ScriptState28();
    std::int32_t member14490_{};
    std::array<String, 4> member14492_{};
    std::int32_t member14494_{};
    std::int32_t member14495_{};
    std::array<std::uint8_t, 25> member14496_{};
    String member14497_{};
    std::array<std::uint8_t, 7> member14498_{};
    String member14499_{};
    std::array<std::uint8_t, 11> member14500_{};
    std::array<std::uint8_t, 21> member14501_{};
    std::array<std::uint8_t, 23> member14502_{};
    std::array<std::uint8_t, 23> member14504_{};
    std::array<std::uint8_t, 22> member14505_{};
    std::array<std::uint8_t, 11> member14506_{};
    std::array<std::uint8_t, 26> member14507_{};
    std::array<std::uint8_t, 23> member14508_{};
    String member14509_{};
    std::array<std::uint8_t, 11> member14510_{};
};

struct ScriptState29
{
    ScriptState29();
    std::int32_t member15056_{};
    std::int32_t member15071_{};
    float member15073_{};
    std::array<std::uint8_t, 6> member15075_{};
};

struct ScriptState30
{
    ScriptState30();
    std::int32_t member3174_{};
    std::int32_t member3211_{};
    std::int32_t member3212_{};
    String member3213_{};
    std::array<std::uint8_t, 7> member3214_{};
};

struct ScriptState31
{
    std::array<std::uint8_t, 112> member9733_{};
    std::array<std::uint8_t, 112> member9735_{};
    std::array<std::int32_t, 28> member9739_{};
};

struct ScriptState32
{
    std::array<std::uint8_t, 4> member10147_{};
    std::array<std::uint8_t, 4> member10149_{};
    std::int32_t member10153_{};
};

struct ScriptState33
{
    ScriptState33();
    std::array<std::uint8_t, 18> member13867_{};
    std::array<std::uint8_t, 1> member13868_{};
    std::array<std::uint8_t, 5> member13869_{};
};

struct ScriptState34
{
    ScriptState34();
    String member1514_{};
    String member1515_{};
    std::int8_t member1516_{};
    std::int32_t member1518_{};
    std::int32_t member1519_{};
    std::int32_t member1520_{};
    std::int32_t member1521_{};
    std::int32_t member1522_{};
    std::int32_t member1523_{};
    std::int32_t member1524_{};
    std::int32_t member1525_{};
    std::int32_t member1526_{};
    std::int32_t member1527_{};
    std::int32_t member1528_{};
    std::int32_t member1529_{};
    std::int32_t member1530_{};
    std::int32_t member1531_{};
    std::array<std::uint8_t, 256> member1532_{};
    std::array<std::uint8_t, 200> member1534_{};
    std::int32_t member1536_{};
    std::int32_t member1537_{};
    std::int32_t member1538_{};
    std::int32_t member1539_{};
    std::int32_t member1541_{};
    std::int32_t member1542_{};
    std::array<std::uint8_t, 2> member1543_{};
    std::array<std::uint8_t, 2> member1544_{};
    std::array<std::uint8_t, 2> member1545_{};
    std::int32_t member1546_{};
    String member1547_{};
    std::int32_t member1548_{};
    String member1549_{};
    std::int32_t member1550_{};
    std::int32_t member1551_{};
    std::int32_t member1552_{};
    String member1553_{};
    std::int32_t member1554_{};
    String member1555_{};
    std::int32_t member1556_{};
    std::int32_t member1557_{};
};

struct ScriptState35
{
    ScriptState35();
    std::int32_t member15338_{};
    std::int32_t member15368_{};
    std::int32_t member15370_{};
    float member15371_{};
    std::array<std::uint8_t, 5> member15372_{};
    std::array<std::uint8_t, 5> member15373_{};
    std::array<std::uint8_t, 5> member15374_{};
    std::array<std::uint8_t, 5> member15375_{};
};

struct ScriptState36
{
    ScriptState36();
    std::array<std::uint8_t, 56> member12232_{};
    String member12233_{};
    std::int32_t member12236_{};
    std::int32_t member12238_{};
    std::int8_t member12268_{};
    std::array<std::uint8_t, 18> member12323_{};
    std::int32_t member12350_{};
    std::int32_t member12351_{};
};

struct ScriptState37
{
    ScriptState37();
    std::array<std::uint8_t, 4> member12702_{};
    std::array<std::uint8_t, 4> member12704_{};
    std::array<std::uint8_t, 4> member12705_{};
    std::array<std::uint8_t, 4> member12706_{};
    std::array<std::uint8_t, 4> member12710_{};
    std::array<std::uint8_t, 8> member12810_{};
    std::array<std::uint8_t, 5> member12817_{};
    std::array<std::uint8_t, 10> member12819_{};
    std::int32_t member12823_{};
    std::int32_t member12824_{};
    std::int32_t member12825_{};
    std::int32_t member12826_{};
    std::int32_t member12827_{};
    std::int32_t member12828_{};
    String member12838_{};
    String member12839_{};
    IntRef member12840_{};
    IntRef member12841_{};
    IntRef member12842_{};
    IntRef member12843_{};
    IntRef member12844_{};
    IntRef member12845_{};
    std::array<std::uint8_t, 8> member12846_{};
    std::array<std::uint8_t, 8> member12847_{};
    std::array<std::uint8_t, 8> member12848_{};
    std::array<std::uint8_t, 8> member12849_{};
    std::array<std::uint8_t, 8> member12850_{};
    std::array<std::uint8_t, 8> member12851_{};
    std::array<std::uint8_t, 8> member12852_{};
    std::array<std::uint8_t, 8> member12853_{};
    std::array<std::uint8_t, 8> member12854_{};
};

struct ScriptState38
{
    ScriptState38();
    std::int32_t member13737_{};
    Address member13743_{};
    std::array<std::uint8_t, 11> member13759_{};
    std::array<std::uint8_t, 30> member13760_{};
    std::array<std::uint8_t, 25> member13761_{};
    std::array<std::int8_t, 14> member13766_{};
    std::array<std::int8_t, 14> member13768_{};
    std::array<std::uint8_t, 5> member13770_{};
    std::array<std::uint8_t, 20> member13771_{};
    std::array<std::uint8_t, 67> member13773_{};
    std::array<std::uint8_t, 29> member13774_{};
    std::array<std::uint8_t, 40> member13775_{};
    std::array<std::uint8_t, 18> member13776_{};
};

struct ScriptState39
{
    ScriptState39();
    std::int32_t member15058_{};
    String member15059_{};
    std::array<std::uint8_t, 10> member15061_{};
    std::int32_t member15063_{};
    std::int32_t member15064_{};
    std::int32_t member15065_{};
    std::int32_t member15066_{};
    float member15067_{};
    std::array<std::uint8_t, 6> member15069_{};
};

struct ScriptState40
{
    ScriptState40();
    std::int32_t member1166_{};
    IntRef member1172_{};
    IntRef member1173_{};
    std::int32_t member1178_{};
    std::array<std::uint8_t, 13> member1223_{};
    String member1224_{};
    String member1228_{};
    std::int32_t member1342_{};
};

struct ScriptState41
{
    ScriptState41();
    std::int32_t member9281_{};
    std::int8_t member11683_{};
    std::int32_t member11688_{};
    std::int32_t member11690_{};
    String member11692_{};
    String member11693_{};
    String member11705_{};
};

struct ScriptState42
{
    ScriptState42();
    std::int32_t member15509_{};
    std::array<Address, 2> member15511_{};
    std::array<std::uint8_t, 8> member15535_{};
    std::array<std::uint8_t, 18> member15557_{};
    std::array<std::uint8_t, 4> member15561_{};
    std::array<std::uint8_t, 4> member15562_{};
    std::array<std::uint8_t, 16> member15563_{};
    std::array<Address, 2> member15681_{};
    std::int32_t member15682_{};
    std::array<std::uint8_t, 20> member15684_{};
    std::array<std::uint8_t, 6> member15685_{};
    std::array<std::uint8_t, 14> member15686_{};
    std::array<std::uint8_t, 6> member15687_{};
    std::array<std::uint8_t, 14> member15688_{};
};

struct ScriptState43
{
    ScriptState43();
    std::int32_t member1355_{};
    std::int32_t member1372_{};
    String member1399_{};
    String member1407_{};
    String member1417_{};
    std::int32_t member1425_{};
};

struct ScriptState44
{
    ScriptState44();
    std::int32_t member3182_{};
    std::int32_t member3183_{};
    std::int32_t member3184_{};
};

struct ScriptState45
{
    ScriptState45();
    std::int32_t member7409_{};
    std::int8_t member7410_{};
    std::int8_t member7411_{};
    std::array<std::uint8_t, 256> member7413_{};
    std::array<std::uint8_t, 256> member7415_{};
    std::int32_t member7417_{};
    std::int32_t member7418_{};
    std::int32_t member7419_{};
    std::array<std::uint8_t, 13> member7420_{};
    std::array<std::uint8_t, 11> member7421_{};
    std::int32_t member7422_{};
    std::int8_t member7423_{};
    std::int32_t member7425_{};
    std::int32_t member7426_{};
    std::int32_t member7427_{};
    std::array<std::uint8_t, 9> member7429_{};
    std::array<std::uint8_t, 9> member7431_{};
    std::array<std::uint8_t, 128> member7433_{};
    std::int32_t member7435_{};
    std::int32_t member7436_{};
    float member7437_{};
    float member7438_{};
};

struct ScriptState46
{
    ScriptState46();
    std::array<std::int32_t, 14> member7936_{};
    std::int32_t member7938_{};
    std::array<std::uint8_t, 32> member7977_{};
    std::array<std::uint8_t, 30> member7985_{};
    std::array<std::uint8_t, 1> member7988_{};
    std::array<std::int8_t, 14> member8022_{};
    std::array<std::uint8_t, 5> member8024_{};
};

struct ScriptState47
{
    ScriptState47();
    std::array<std::uint8_t, 8> member8438_{};
    std::array<std::uint8_t, 2> member8444_{};
    std::array<std::uint8_t, 11> member8445_{};
};

struct ScriptState48
{
    ScriptState48();
    std::int8_t member9000_{};
    std::int8_t member9001_{};
    std::int32_t member9003_{};
    std::int32_t member9004_{};
    std::int32_t member9006_{};
    std::int32_t member9007_{};
    std::int32_t member9008_{};
    Address member9010_{};
    std::int32_t member9011_{};
    std::int32_t member9012_{};
    std::int32_t member9013_{};
    IntRef member9016_{};
    String member9018_{};
    String member9019_{};
    String member9020_{};
    String member9021_{};
    String member9022_{};
    String member9023_{};
    std::int32_t member9028_{};
    std::int32_t member9029_{};
    std::int32_t member9030_{};
    String member9031_{};
    std::int32_t member9032_{};
    std::int32_t member9033_{};
    std::int32_t member9034_{};
    std::int32_t member9035_{};
    std::int32_t member9036_{};
    std::int32_t member9037_{};
    std::int32_t member9038_{};
    String member9039_{};
    std::int32_t member9040_{};
    String member9041_{};
    std::int32_t member9044_{};
    std::int32_t member9045_{};
    std::int32_t member9046_{};
    std::int32_t member9047_{};
    std::int32_t member9048_{};
    std::int32_t member9049_{};
    std::int32_t member9050_{};
    std::int32_t member9051_{};
    std::int32_t member9052_{};
    std::int32_t member9053_{};
    std::int32_t member9054_{};
    std::int32_t member9055_{};
    std::array<std::uint8_t, 20> member9056_{};
    std::array<std::uint8_t, 20> member9058_{};
    std::array<std::uint8_t, 20> member9069_{};
    std::array<std::uint8_t, 20> member9071_{};
    std::array<std::int32_t, 5> member9074_{};
    std::array<std::uint8_t, 10> member9122_{};
    IntRefRef member9141_{};
    IntRefRef member9142_{};
    IntRefRef member9143_{};
    IntRefRef member9144_{};
    IntRefRef member9145_{};
    IntRefRef member9146_{};
    IntRefRef member9147_{};
    IntRefRef member9148_{};
    IntRefRef member9149_{};
    std::int32_t member9150_{};
    std::int32_t member9152_{};
    std::array<std::uint8_t, 9> member9155_{};
    String member9156_{};
    std::array<std::uint8_t, 6> member9157_{};
    std::array<std::uint8_t, 6> member9169_{};
};

struct ScriptState49
{
    ScriptState49();
    std::array<std::uint8_t, 16> member9412_{};
    std::array<std::int32_t, 14> member9414_{};
    std::int32_t member9452_{};
    std::int8_t member9457_{};
    std::array<std::uint8_t, 1> member9469_{};
    std::array<std::uint8_t, 18> member9470_{};
    std::array<std::uint8_t, 1> member9471_{};
    std::array<std::uint8_t, 1> member9472_{};
    std::array<std::int8_t, 14> member9474_{};
    std::array<std::int8_t, 14> member9476_{};
    std::array<std::uint8_t, 1> member9478_{};
    std::array<std::uint8_t, 5> member9482_{};
    std::int32_t member9488_{};
    std::int32_t member9491_{};
    std::array<std::uint8_t, 20> member9497_{};
    std::array<std::uint8_t, 64> member9499_{};
    std::int32_t member9500_{};
    std::int32_t member9501_{};
    std::array<std::uint8_t, 32> member9503_{};
    String member9505_{};
    String member9506_{};
    std::array<std::uint8_t, 9> member9507_{};
    std::array<std::uint8_t, 5> member9508_{};
    std::array<std::uint8_t, 10> member9509_{};
    std::array<std::uint8_t, 11> member9510_{};
    std::array<std::uint8_t, 10> member9515_{};
    std::int32_t member9516_{};
    std::array<std::uint8_t, 8> member9520_{};
    std::array<std::uint8_t, 7> member9521_{};
    std::array<std::uint8_t, 7> member9522_{};
    std::array<std::uint8_t, 8> member9523_{};
    std::int32_t member9525_{};
    std::int32_t member9526_{};
    std::int32_t member9527_{};
    std::int32_t member9528_{};
    std::int32_t member9529_{};
    std::int32_t member9530_{};
    std::int32_t member9531_{};
    Address member9532_{};
    Address member9533_{};
    float member9534_{};
    std::array<std::uint8_t, 11> member9535_{};
    std::array<std::uint8_t, 11> member9536_{};
    std::array<std::uint8_t, 8> member9537_{};
    std::array<std::uint8_t, 9> member9538_{};
    std::int32_t member9546_{};
    std::int32_t member9547_{};
    IntRef member9549_{};
    std::int32_t member9551_{};
    std::int32_t member9552_{};
    std::int32_t member9553_{};
    std::int32_t member9554_{};
    std::int32_t member9555_{};
    std::int32_t member9556_{};
    std::int32_t member9557_{};
    std::int32_t member9558_{};
    std::int32_t member9559_{};
    std::int32_t member9561_{};
    std::array<std::int32_t, 32> member9563_{};
    std::int32_t member9565_{};
    std::int32_t member9566_{};
    std::int32_t member9568_{};
    std::int32_t member9569_{};
    std::array<std::uint8_t, 20> member9571_{};
    std::array<std::uint8_t, 1024> member9573_{};
    std::array<std::uint8_t, 64> member9575_{};
    std::int32_t member9577_{};
    std::array<std::int32_t, 8> member9579_{};
    std::int32_t member9581_{};
    std::int32_t member9582_{};
    std::array<std::int32_t, 40> member9584_{};
    std::int32_t member9586_{};
    std::int32_t member9587_{};
    std::int32_t member9588_{};
    std::int32_t member9589_{};
    std::array<std::uint8_t, 20> member9591_{};
    std::array<std::uint8_t, 20> member9592_{};
    String member9593_{};
    std::array<std::uint8_t, 10> member9594_{};
    String member9595_{};
    std::array<std::uint8_t, 10> member9596_{};
    String member9597_{};
    std::array<std::uint8_t, 10> member9598_{};
    std::array<std::uint8_t, 2> member9599_{};
    std::array<std::uint8_t, 5> member9600_{};
    std::array<std::uint8_t, 5> member9601_{};
    String member9602_{};
    std::array<std::uint8_t, 6> member9603_{};
    std::array<std::uint8_t, 9> member9604_{};
    std::array<std::uint8_t, 7> member9605_{};
    std::array<std::uint8_t, 9> member9606_{};
    String member9607_{};
    String member9608_{};
    std::array<std::uint8_t, 9> member9609_{};
    String member9610_{};
    std::array<std::uint8_t, 7> member9611_{};
    std::array<std::uint8_t, 9> member9612_{};
    std::array<std::uint8_t, 11> member9613_{};
    String member9614_{};
    std::array<std::uint8_t, 21> member9615_{};
    std::array<std::uint8_t, 10> member9616_{};
    String member9617_{};
    std::array<std::uint8_t, 10> member9618_{};
    std::array<std::uint8_t, 8> member9619_{};
    String member9620_{};
    std::array<std::uint8_t, 5> member9621_{};
    std::array<std::uint8_t, 6> member9622_{};
    std::array<std::uint8_t, 6> member9623_{};
    std::int32_t member9625_{};
    std::array<std::uint8_t, 10> member9627_{};
    String member9628_{};
    std::array<std::uint8_t, 14> member9629_{};
    String member9630_{};
    std::array<std::uint8_t, 14> member9631_{};
    String member9632_{};
    std::array<std::uint8_t, 14> member9633_{};
    String member9634_{};
    std::array<std::uint8_t, 14> member9635_{};
    std::array<std::uint8_t, 9> member9636_{};
    std::array<std::uint8_t, 11> member9638_{};
    std::int32_t member9647_{};
    std::int32_t member9648_{};
    String member9649_{};
    std::array<std::uint8_t, 7> member9650_{};
};

struct ScriptState50
{
    ScriptState50();
    std::array<std::uint8_t, 12> member10942_{};
    float member10944_{};
    float member10945_{};
    float member10946_{};
    std::int32_t member10948_{};
    std::int32_t member10949_{};
    std::int32_t member10950_{};
    std::array<std::int32_t, 4> member10952_{};
    float member10954_{};
    float member10955_{};
    float member10956_{};
    float member10957_{};
    float member10958_{};
    float member10959_{};
    std::int32_t member10960_{};
    std::int32_t member10962_{};
    std::int32_t member10964_{};
    std::int32_t member10965_{};
    std::int32_t member10966_{};
    float member10967_{};
    std::array<std::uint8_t, 9> member10968_{};
    std::int32_t member10970_{};
    std::int32_t member10971_{};
    std::int32_t member10976_{};
};

struct ScriptState51
{
    ScriptState51();
    std::int32_t member11394_{};
    std::int32_t member11396_{};
    std::int32_t member11397_{};
    std::int32_t member11398_{};
    std::array<std::uint8_t, 6> member11399_{};
    std::int32_t member11401_{};
    std::int32_t member11402_{};
    std::int32_t member11403_{};
    std::int32_t member11404_{};
    std::int32_t member11405_{};
    std::array<std::uint8_t, 16> member11407_{};
    std::array<std::uint8_t, 16> member11408_{};
    std::array<std::uint8_t, 8> member11409_{};
    std::array<std::uint8_t, 18> member11410_{};
    String member11411_{};
};

struct ScriptState52
{
    ScriptState52();
    String member11461_{};
    std::int32_t member11463_{};
    std::array<std::uint8_t, 28> member11464_{};
    std::array<std::uint8_t, 9> member11465_{};
    std::array<std::uint8_t, 32> member11467_{};
    std::array<std::uint8_t, 20> member11469_{};
    std::array<std::uint8_t, 29> member11472_{};
    std::array<std::uint8_t, 40> member11473_{};
    std::array<std::uint8_t, 18> member11474_{};
};

struct ScriptState53
{
    ScriptState53();
    std::int32_t member11979_{};
    std::int32_t member11980_{};
    std::int32_t member11981_{};
    std::int32_t member11982_{};
    std::array<std::uint8_t, 14> member11983_{};
    std::array<std::uint8_t, 9> member11984_{};
    std::array<std::uint8_t, 21> member11985_{};
    std::array<std::uint8_t, 8> member11986_{};
    std::array<std::uint8_t, 21> member11987_{};
};

struct ScriptState54
{
    ScriptState54();
    std::int32_t member12089_{};
    std::int32_t member12133_{};
    std::int32_t member12134_{};
    std::int32_t member12136_{};
    std::int32_t member12137_{};
    std::array<std::uint8_t, 13> member12138_{};
    std::int32_t member12140_{};
    std::array<std::uint8_t, 8> member12141_{};
};

struct ScriptState55
{
    ScriptState55();
    std::int32_t member12224_{};
    std::int32_t member12237_{};
    std::array<std::uint8_t, 4> member12262_{};
    std::int32_t member12265_{};
    String member12267_{};
    std::array<std::uint8_t, 12> member12270_{};
    std::array<std::uint8_t, 32> member12271_{};
    std::array<std::uint8_t, 92> member12273_{};
    std::array<std::uint8_t, 4> member12275_{};
    std::array<std::uint8_t, 4> member12276_{};
    String member12278_{};
    std::array<std::uint8_t, 6> member12279_{};
    std::array<std::uint8_t, 28> member12280_{};
    std::array<std::uint8_t, 5> member12281_{};
    std::array<std::uint8_t, 18> member12284_{};
    std::array<std::uint8_t, 2> member12285_{};
    String member12286_{};
    std::array<std::uint8_t, 18> member12287_{};
    std::array<std::int8_t, 8> member12288_{};
    std::array<std::uint8_t, 1> member12290_{};
    std::array<std::uint8_t, 1> member12292_{};
    std::array<std::uint8_t, 8> member12295_{};
    std::array<std::int8_t, 14> member12307_{};
    std::array<std::uint8_t, 11> member12316_{};
    std::array<std::uint8_t, 5> member12324_{};
    std::array<std::uint8_t, 20> member12326_{};
    std::array<std::uint8_t, 67> member12328_{};
    std::array<std::uint8_t, 29> member12329_{};
    std::array<std::uint8_t, 40> member12330_{};
    float member12332_{};
    float member12333_{};
    std::int32_t member12353_{};
    std::array<std::uint8_t, 21> member12354_{};
    std::array<std::uint8_t, 21> member12355_{};
    std::array<std::uint8_t, 21> member12356_{};
};

struct ScriptState56
{
    ScriptState56();
    float member14115_{};
    std::int8_t member14116_{};
    std::array<std::uint8_t, 1> member14121_{};
    std::array<std::uint8_t, 5> member14123_{};
};

struct ScriptState57
{
    ScriptState57();
    std::int32_t member14159_{};
    std::int32_t member14160_{};
    std::int32_t member14161_{};
    std::int32_t member14162_{};
    std::int32_t member14163_{};
    std::int32_t member14164_{};
    std::array<std::int32_t, 13> member14165_{};
    std::int32_t member14166_{};
    String member14168_{};
    std::array<std::uint8_t, 30> member14170_{};
    std::int8_t member14172_{};
    std::int32_t member14173_{};
    std::array<std::int32_t, 3> member14174_{};
    std::int32_t member14176_{};
    std::int32_t member14178_{};
    std::int32_t member14180_{};
    std::array<String, 10> member14182_{};
    std::int32_t member14183_{};
    std::array<std::uint8_t, 100> member14189_{};
    std::int32_t member14191_{};
    std::int32_t member14192_{};
    std::int32_t member14193_{};
    std::int32_t member14194_{};
    std::int32_t member14195_{};
    std::int32_t member14196_{};
    std::int32_t member14197_{};
    std::int32_t member14198_{};
    std::int32_t member14199_{};
    std::int32_t member14200_{};
    std::int32_t member14201_{};
    std::int32_t member14202_{};
    std::int32_t member14203_{};
    std::int32_t member14204_{};
    std::int32_t member14205_{};
    std::int32_t member14206_{};
    std::int32_t member14207_{};
    std::int32_t member14208_{};
    String member14209_{};
    std::int32_t member14210_{};
    std::int32_t member14211_{};
    std::array<std::uint8_t, 2> member14213_{};
    std::array<std::uint8_t, 3> member14215_{};
    std::int32_t member14246_{};
    std::int8_t member14247_{};
    std::int32_t member14249_{};
    std::int32_t member14250_{};
    std::array<std::uint8_t, 10> member14252_{};
    std::array<std::uint8_t, 6> member14253_{};
    std::array<std::uint8_t, 9> member14254_{};
    std::int32_t member14256_{};
    std::int32_t member14257_{};
    String member14258_{};
    std::int32_t member14260_{};
    std::array<Address, 2> member14261_{};
    std::int32_t member14262_{};
    std::array<std::uint8_t, 4> member14266_{};
    std::array<std::uint8_t, 7> member14268_{};
    std::array<std::uint8_t, 3> member14269_{};
    String member14272_{};
    String member14273_{};
    std::int32_t member14274_{};
    AddressRef member14275_{};
    String member14276_{};
    std::int32_t member14278_{};
    std::int32_t member14279_{};
    std::array<std::uint8_t, 100> member14281_{};
    std::int8_t member14283_{};
    std::array<std::uint8_t, 25> member14284_{};
    std::array<std::uint8_t, 1> member14285_{};
    std::array<std::uint8_t, 26> member14286_{};
    std::int32_t member14288_{};
    std::int32_t member14289_{};
    std::int32_t member14290_{};
    std::int32_t member14300_{};
    std::int32_t member14301_{};
    std::int32_t member14306_{};
    String member14314_{};
    std::int32_t member14317_{};
    String member14318_{};
    std::array<std::uint8_t, 9> member14319_{};
    String member14320_{};
    std::array<std::uint8_t, 9> member14321_{};
    std::array<std::uint8_t, 9> member14325_{};
};

struct ScriptState58
{
    ScriptState58();
    std::array<std::uint8_t, 56> member14718_{};
    String member14719_{};
    std::string member14721_;
    std::int32_t member14722_{};
    std::int32_t member14723_{};
    std::int8_t member14740_{};
    std::array<std::uint8_t, 8> member14747_{};
    std::array<std::uint8_t, 8> member14748_{};
    std::array<std::uint8_t, 8> member14749_{};
    std::array<std::uint8_t, 3> member14750_{};
    std::array<std::uint8_t, 2> member14751_{};
    std::array<std::uint8_t, 11> member14752_{};
    std::array<std::int8_t, 14> member14753_{};
    std::array<std::uint8_t, 18> member14756_{};
    std::array<std::uint8_t, 1> member14757_{};
    std::array<std::uint8_t, 11> member14758_{};
    std::array<std::uint8_t, 20> member14759_{};
    std::array<std::uint8_t, 5> member14760_{};
};

struct ScriptState59
{
    ScriptState59();
    String member15929_{};
    std::array<std::uint8_t, 128> member15950_{};
    std::array<std::uint8_t, 4> member15952_{};
};

struct ScriptState60
{
    ScriptState60();
    std::int32_t member15990_{};
    std::array<std::uint8_t, 25> member15994_{};
    std::array<std::uint8_t, 5> member15995_{};
};

struct ScriptState61
{
    ScriptState61();
    std::int32_t member16067_{};
    std::int32_t member16069_{};
    std::array<std::uint8_t, 19> member16070_{};
    std::array<std::uint8_t, 7> member16071_{};
    String member16072_{};
    std::int32_t member16074_{};
    std::array<std::uint8_t, 14> member16075_{};
    std::array<std::uint8_t, 14> member16076_{};
    std::array<std::uint8_t, 11> member16077_{};
    std::array<std::uint8_t, 11> member16078_{};
};

struct ScriptState62
{
    ScriptState62();
    std::array<std::uint8_t, 13> member16197_{};
    std::int32_t member16203_{};
    std::int32_t member16204_{};
    std::int32_t member16206_{};
    std::int32_t member16207_{};
    String member16208_{};
    std::array<std::uint8_t, 9> member16209_{};
    std::array<std::uint8_t, 8> member16210_{};
    std::array<std::uint8_t, 10> member16211_{};
    std::array<std::uint8_t, 18> member16212_{};
};

class MbcAfix final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcAfix(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    std::int32_t member2_{};
    std::array<std::uint8_t, 20> member3_{};
    std::array<std::uint8_t, 3> member4_{};
    std::array<std::uint8_t, 2> member5_{};
};

class MbcAi final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcAi(Host &host);
    void initializeMembers() override;

  private:
    Task<void> Ltim();
    float NormalXZ(FloatRef parameter1, FloatRef parameter2);
    float NormalXYZ(FloatRef parameter1, FloatRef parameter2, FloatRef parameter3);
    Task<void> tinv();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member48_{};
    std::int32_t member49_{};
    FloatRef member51_{};
    FloatRef member52_{};
    float member53_{};
    float member54_{};
    FloatRef member55_{};
    FloatRef member56_{};
    FloatRef member57_{};
    float member58_{};
    std::int32_t member59_{};
    std::int32_t member60_{};
};

class MbcAmbc final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcAmbc(Host &host);
    void initializeMembers() override;

  private:
};

class MbcBank final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcBank(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    Task<void> Manager();
    Task<void> StartUp();
    Task<void> QueryInit();
    Task<void> WinSelcount();
    Task<void> WinBank();
    Task<void> WinPassw();
    Task<void> WinAuth();
    Task<Value> ShowBank();
    Task<std::int32_t> HideBank();
    void SendPassword(std::int8_t parameter1, String parameter2);
    void SendNPass(String parameter1, String parameter2);
    Task<Value> RcvUser3(std::int32_t parameter1, String parameter2);
    void GetBankMoney(std::int32_t parameter1, String parameter2);
    void BankOper(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t BuyItBnk(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4, std::int32_t parameter5, String parameter6);
    std::int32_t IsOpened();
    std::int32_t HavePassw();
    std::int32_t GetKomiss();
    Task<void> resetPassword();
    Task<void> helper105_1();
    Task<void> cleanup_WinBank();
    Task<void> cleanup_WinPassw();
    Task<void> cleanup_WinAuth();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member165_{};
    std::int32_t member534_{};
    std::int8_t member476_{};
    std::int8_t member478_{};
    std::int8_t member482_{};
    std::array<std::uint8_t, 1000> member484_{};
    std::array<std::uint8_t, 8> member486_{};
    std::array<std::uint8_t, 256> member491_{};
    String member493_{};
    String member495_{};
    std::array<std::uint8_t, 5> member496_{};
    std::int8_t member497_{};
    std::int32_t member531_{};
    std::int32_t member533_{};
    std::int32_t member536_{};
    IntRef member541_{};
    IntRef member542_{};
    std::int32_t member545_{};
    std::int32_t member546_{};
    std::array<std::int32_t, 12> member548_{};
    std::int32_t member550_{};
    std::int32_t member551_{};
    std::int32_t member553_{};
    std::int32_t member554_{};
    std::int32_t member555_{};
    std::int32_t member556_{};
    std::int32_t member558_{};
    std::int32_t member559_{};
    std::int32_t member560_{};
    std::int32_t member561_{};
    std::int32_t member562_{};
    std::array<std::uint8_t, 64> member565_{};
    std::array<std::uint8_t, 64> member569_{};
    String member571_{};
    std::array<std::uint8_t, 50> member573_{};
    std::int32_t member575_{};
    String member576_{};
    std::array<std::uint8_t, 5> member577_{};
    std::array<std::uint8_t, 9> member578_{};
    std::array<std::uint8_t, 4> member579_{};
    String member580_{};
    std::array<std::uint8_t, 9> member581_{};
    std::array<std::uint8_t, 7> member582_{};
    std::array<std::uint8_t, 9> member584_{};
    std::array<std::uint8_t, 14> member585_{};
    String member586_{};
    std::array<std::uint8_t, 21> member587_{};
    std::array<std::uint8_t, 8> member588_{};
    std::array<std::uint8_t, 7> member589_{};
    std::array<std::uint8_t, 9> member590_{};
    std::array<std::uint8_t, 8> member591_{};
    std::array<std::uint8_t, 7> member592_{};
    std::array<std::uint8_t, 10> member593_{};
    std::array<std::uint8_t, 10> member594_{};
    std::array<std::uint8_t, 10> member595_{};
    std::array<std::uint8_t, 10> member596_{};
    std::array<std::uint8_t, 11> member597_{};
    String member598_{};
    std::array<std::uint8_t, 11> member599_{};
    String member600_{};
    String member601_{};
    std::array<std::uint8_t, 19> member602_{};
    std::array<std::uint8_t, 11> member603_{};
    String member604_{};
    String member605_{};
    std::array<std::uint8_t, 8> member622_{};
    String member623_{};
    std::array<std::uint8_t, 5> member624_{};
    std::array<std::uint8_t, 5> member625_{};
    std::array<std::uint8_t, 11> member626_{};
    std::array<std::uint8_t, 11> member627_{};
    String member628_{};
    std::int32_t member631_{};
    std::int32_t member632_{};
    std::int32_t member633_{};
    std::int32_t member634_{};
    std::int32_t member635_{};
    std::int32_t member636_{};
    std::array<std::uint8_t, 10> member638_{};
    std::array<std::uint8_t, 10> member640_{};
    std::array<std::uint8_t, 10> member642_{};
    std::array<std::uint8_t, 16> member644_{};
    std::array<std::uint8_t, 21> member645_{};
    std::int32_t member646_{};
    std::int32_t member647_{};
    std::int32_t member648_{};
    std::int32_t member649_{};
    std::array<std::uint8_t, 9> member651_{};
    std::array<std::uint8_t, 9> member653_{};
    std::array<std::uint8_t, 21> member654_{};
    std::array<std::uint8_t, 11> member655_{};
    std::int8_t member658_{};
    String member659_{};
    String member660_{};
    String member661_{};
    String member662_{};
    String member663_{};
    std::array<std::uint8_t, 20> member665_{};
    std::array<std::uint8_t, 6> member667_{};
    std::int8_t member670_{};
    std::array<std::uint8_t, 50> member673_{};
    std::int8_t member675_{};
    std::array<std::uint8_t, 21> member677_{};
    std::array<std::uint8_t, 21> member678_{};
    std::array<std::uint8_t, 21> member679_{};
    std::int32_t member680_{};
    String member681_{};
    std::int32_t member686_{};
    std::int32_t member687_{};
    std::int32_t member688_{};
    std::int32_t member689_{};
    std::int32_t member690_{};
    String member691_{};
    String member692_{};
    std::array<std::uint8_t, 21> member693_{};
};

class MbcChar final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcChar(Host &host);
    void initializeMembers() override;

  private:
    std::int32_t fillparam();
    Task<void> EKill();
    Task<void> slowinvis();
    Task<void> fastinvis();
    Task<void> fastvis();
    std::int32_t getSkinNum();
    std::int32_t ResetSkinData();
    std::int32_t refreshSkin();
    std::int32_t turnSkinAndSetVis(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t TurnSkin(std::int32_t parameter1);
    std::int32_t IsOwn();
    void SVisChar(std::int32_t parameter1);
    std::int32_t GetConfVis();
    Task<void> skincoord();
    Task<void> CheckMoving();
    Task<void> CheckGround();
    Task<void> CheckRoar();
    Task<void> FreeAn();
    Task<void> CheckAnim();
    Task<void> Animating();
    Task<void> SetAnim();
    Task<void> IntrplOn();
    Task<void> IntrplOff();
    std::int32_t InitCharOwn(IntRef parameter1, String parameter2);
    Task<std::int32_t> InitCharPC(IntRef parameter1, String parameter2, float parameter3, float parameter4, float parameter5, float parameter6);
    Task<std::int32_t> InitChar(IntRef parameter1, String parameter2, std::int32_t parameter3);
    Task<void> chalt();
    Task<Value> Anim(std::int32_t parameter1);
    Value PlaySnd(std::int32_t parameter1);
    Value ShowEff(std::int32_t parameter1);
    void helper9_1();
    void helper96_1();
    void helper91_1();
    Task<void> helper66_1();
    Task<void> cleanup_Animating();
    std::array<std::uint8_t, 20> member695_{};
    std::array<std::uint8_t, 20> member697_{};
    std::array<std::uint8_t, 64> member698_{};
    std::int32_t member700_{};
    std::int32_t member701_{};
    std::int32_t member702_{};
    std::int32_t member703_{};
    std::int32_t member704_{};
    std::int32_t member705_{};
    std::int32_t member706_{};
    std::int32_t member707_{};
    std::int32_t member708_{};
    std::int32_t member709_{};
    std::int32_t member710_{};
    std::int32_t member711_{};
    std::int32_t member712_{};
    std::int32_t member713_{};
    std::int32_t member714_{};
    std::int32_t member715_{};
    std::int32_t member716_{};
    std::int32_t member717_{};
    std::int32_t member718_{};
    std::int32_t member719_{};
    std::int32_t member720_{};
    std::int32_t member721_{};
    std::int32_t member722_{};
    std::int32_t member723_{};
    float member724_{};
    float member725_{};
    std::array<std::int8_t, 4> member726_{};
    std::array<std::uint8_t, 144> member728_{};
    std::array<std::uint8_t, 144> member730_{};
    std::array<std::uint8_t, 144> member732_{};
    std::array<std::uint8_t, 144> member734_{};
    std::array<std::uint8_t, 80> member736_{};
    std::int32_t member738_{};
    std::int32_t member739_{};
    std::array<std::uint8_t, 8> member741_{};
    std::array<std::uint8_t, 5> member742_{};
    std::array<std::uint8_t, 8> member743_{};
    std::array<std::uint8_t, 7> member744_{};
    std::array<std::uint8_t, 5> member745_{};
    std::array<std::uint8_t, 6> member746_{};
    std::array<std::uint8_t, 6> member747_{};
    std::array<std::uint8_t, 6> member748_{};
    std::array<std::uint8_t, 5> member749_{};
    std::array<std::uint8_t, 4> member750_{};
    std::array<std::uint8_t, 7> member751_{};
    std::array<std::uint8_t, 6> member752_{};
    std::array<std::uint8_t, 7> member753_{};
    std::array<std::uint8_t, 6> member754_{};
    std::array<std::uint8_t, 6> member755_{};
    std::array<std::uint8_t, 7> member756_{};
    std::array<std::uint8_t, 7> member757_{};
    std::array<std::uint8_t, 4> member758_{};
    std::array<std::uint8_t, 5> member759_{};
    std::array<std::uint8_t, 5> member760_{};
    std::array<std::uint8_t, 6> member761_{};
    std::array<std::uint8_t, 4> member762_{};
    std::array<std::uint8_t, 4> member763_{};
    std::array<std::uint8_t, 4> member764_{};
    std::array<std::uint8_t, 5> member765_{};
    std::array<std::uint8_t, 8> member766_{};
    std::array<std::uint8_t, 7> member767_{};
    std::array<std::uint8_t, 7> member768_{};
    std::array<std::uint8_t, 7> member769_{};
    std::array<std::uint8_t, 9> member770_{};
    std::array<std::uint8_t, 6> member771_{};
    std::array<std::uint8_t, 5> member772_{};
    std::array<std::uint8_t, 5> member773_{};
    std::array<std::uint8_t, 7> member774_{};
    std::array<std::uint8_t, 7> member775_{};
    std::array<std::uint8_t, 6> member776_{};
    std::array<std::uint8_t, 4> member777_{};
    std::array<std::uint8_t, 7> member778_{};
    std::array<std::uint8_t, 7> member779_{};
    std::array<std::uint8_t, 5> member780_{};
    std::array<std::uint8_t, 4> member781_{};
    std::array<std::uint8_t, 4> member782_{};
    std::array<std::uint8_t, 7> member783_{};
    std::array<std::uint8_t, 6> member784_{};
    std::array<std::uint8_t, 6> member785_{};
    std::array<std::uint8_t, 7> member786_{};
    std::array<std::uint8_t, 8> member787_{};
    std::int32_t member789_{};
    float member790_{};
    std::int32_t member791_{};
    float member792_{};
    float member793_{};
    float member794_{};
    std::array<std::uint8_t, 20> member795_{};
    std::array<std::uint8_t, 29> member796_{};
    std::array<std::uint8_t, 20> member797_{};
    std::array<std::uint8_t, 7> member798_{};
    std::array<std::uint8_t, 7> member799_{};
    std::array<std::uint8_t, 3> member800_{};
    std::int32_t member801_{};
    std::int32_t member802_{};
    std::array<std::uint8_t, 20> member803_{};
    std::array<std::uint8_t, 29> member804_{};
    std::array<std::uint8_t, 20> member805_{};
    std::array<std::uint8_t, 7> member806_{};
    std::array<std::uint8_t, 3> member807_{};
    std::int32_t member808_{};
    std::array<std::uint8_t, 20> member809_{};
    std::array<std::uint8_t, 29> member810_{};
    std::array<std::uint8_t, 20> member811_{};
    std::array<std::uint8_t, 7> member812_{};
    std::array<std::uint8_t, 7> member813_{};
    std::array<std::uint8_t, 3> member814_{};
    std::int32_t member815_{};
    Address member817_{};
    Address member818_{};
    float member820_{};
    float member821_{};
    float member822_{};
    float member823_{};
    float member824_{};
    std::int32_t member825_{};
    std::int32_t member826_{};
    std::int32_t member827_{};
    std::int32_t member828_{};
    std::int32_t member829_{};
    std::int32_t member830_{};
    std::int32_t member831_{};
    std::int32_t member832_{};
    std::int32_t member833_{};
    std::int32_t member834_{};
    std::int32_t member836_{};
    std::int32_t member837_{};
    std::int32_t member838_{};
    std::array<std::int32_t, 8> member840_{};
    std::int32_t member842_{};
    std::int32_t member843_{};
    String member844_{};
    float member845_{};
    std::int32_t member846_{};
    std::int32_t member847_{};
    std::int32_t member848_{};
    std::int32_t member849_{};
    std::int32_t member850_{};
    std::int32_t member851_{};
    std::int32_t member852_{};
    std::int32_t member853_{};
    std::int32_t member854_{};
    std::int32_t member855_{};
    std::int32_t member856_{};
    float member857_{};
    float member858_{};
    float member859_{};
    float member860_{};
    IntRef member861_{};
    String member862_{};
    std::array<std::uint8_t, 28> member863_{};
    std::array<std::uint8_t, 28> member864_{};
    IntRef member865_{};
    String member866_{};
    float member867_{};
    float member868_{};
    float member869_{};
    float member870_{};
    std::array<std::uint8_t, 6> member871_{};
    IntRef member872_{};
    String member873_{};
    std::int32_t member874_{};
    std::int32_t member876_{};
    std::int32_t member877_{};
    std::int32_t member878_{};
    std::int32_t member879_{};
    float member880_{};
    float member881_{};
    float member882_{};
    float member883_{};
    std::array<std::uint8_t, 6> member884_{};
    std::int32_t member885_{};
    std::int32_t member887_{};
    std::int32_t member888_{};
    std::int32_t member889_{};
    std::array<std::uint8_t, 8> member890_{};
    std::int32_t member891_{};
    std::int32_t member892_{};
    std::int32_t member893_{};
};

class MbcChat final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcChat(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<Value> SMSG(std::int32_t parameter1, std::int8_t parameter2, String parameter3, String parameter4);
    Task<void> EInit();
    Task<void> Client();
    std::int32_t member46_{};
    std::int32_t member911_{};
    std::int32_t member934_{};
    std::array<std::uint8_t, 12> member894_{};
    float member895_{};
    float member896_{};
    std::array<std::uint8_t, 4096> member898_{};
    std::array<std::uint8_t, 4096> member900_{};
    std::array<std::uint8_t, 256> member902_{};
    std::array<std::uint8_t, 4096> member904_{};
    std::int32_t member906_{};
    std::int32_t member907_{};
    std::int32_t member908_{};
    std::int32_t member909_{};
    std::int32_t member910_{};
    std::int32_t member912_{};
    std::int32_t member913_{};
    std::int32_t member914_{};
    std::int32_t member915_{};
    std::int8_t member916_{};
    String member917_{};
    String member918_{};
    std::array<std::int32_t, 6> member920_{};
    std::int32_t member922_{};
    std::array<std::uint8_t, 5> member923_{};
    std::int32_t member925_{};
    std::array<std::uint8_t, 256> member927_{};
    String member929_{};
    String member930_{};
    std::array<std::uint8_t, 11> member931_{};
    std::array<std::uint8_t, 3> member932_{};
    std::array<std::uint8_t, 13> member935_{};
    String member936_{};
    std::array<std::uint8_t, 14> member937_{};
    std::array<std::uint8_t, 16> member938_{};
    std::array<std::uint8_t, 2> member939_{};
    std::array<std::uint8_t, 5> member940_{};
    std::array<std::uint8_t, 5> member941_{};
};

class MbcCobj final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCobj(Host &host);
    void initializeMembers() override;

  private:
    Task<std::int32_t> CreateObjWait(String parameter1, std::int32_t parameter2);
    Task<std::int32_t> CreateObj(String parameter1, std::int32_t parameter2);
    std::int32_t GetState();
    Task<Value> SetTrig(std::int32_t parameter1);
    std::int32_t DestroyObj();
    void CenterObj(float parameter1, float parameter2, float parameter3, float parameter4, float parameter5, float parameter6);
    float MoveObj(float parameter1, float parameter2, float parameter3, float parameter4, float parameter5, float parameter6, float parameter7);
    Task<void> move();
    Task<void> Trigger();
    Task<float> trig();
    Task<void> CRR();
    Task<void> CycleReceive();
    float Bezier(float parameter1, float parameter2, float parameter3, float parameter4);
    float BezierVA(AddressRef parameter1, AddressRef parameter2, AddressRef parameter3, float parameter4, AddressRef parameter5);
    void FloatArrayAdd(FloatRef parameter1, FloatRef parameter2, float parameter3, float parameter4, std::int32_t parameter5, FloatRef parameter6);
    float AngleBound(float parameter1);
    float DeltaAngleBound(float parameter1);
    float AngleOffset(float parameter1, float parameter2);
    std::int32_t CountAnim();
    float SpeedObj();
    float DirectOfObj();
    void helper100_1();
    Task<void> cleanup_CycleReceive();
    std::int32_t member942_{};
    std::int32_t member944_{};
    std::array<Address, 2> member945_{};
    float member946_{};
    float member947_{};
    float member948_{};
    float member949_{};
    float member950_{};
    float member951_{};
    float member953_{};
    float member954_{};
    float member955_{};
    float member956_{};
    std::array<std::uint8_t, 20> member958_{};
    String member960_{};
    std::int32_t member961_{};
    std::int32_t member963_{};
    std::int32_t member964_{};
    std::int32_t member965_{};
    std::int32_t member966_{};
    std::int32_t member967_{};
    std::array<std::uint8_t, 28> member968_{};
    String member969_{};
    std::int32_t member970_{};
    std::int32_t member971_{};
    std::int32_t member972_{};
    std::int32_t member973_{};
    std::int32_t member974_{};
    std::int32_t member975_{};
    float member976_{};
    float member977_{};
    float member978_{};
    float member979_{};
    float member980_{};
    float member981_{};
    float member982_{};
    float member983_{};
    float member984_{};
    float member985_{};
    float member986_{};
    float member987_{};
    float member988_{};
    String member989_{};
    String member990_{};
    std::array<std::uint8_t, 60> member992_{};
    std::array<std::uint8_t, 60> member994_{};
    std::array<std::uint8_t, 60> member996_{};
    std::array<std::uint8_t, 60> member998_{};
    std::array<std::uint8_t, 60> member1000_{};
    std::array<std::uint8_t, 60> member1002_{};
    std::array<float, 20> member1004_{};
    float member1006_{};
    float member1007_{};
    float member1008_{};
    float member1009_{};
    float member1010_{};
    float member1011_{};
    float member1012_{};
    float member1013_{};
    float member1014_{};
    float member1015_{};
    float member1016_{};
    float member1017_{};
    std::int32_t member1018_{};
    std::int32_t member1019_{};
    std::int32_t member1021_{};
    std::int32_t member1022_{};
    std::array<std::int32_t, 5> member1024_{};
    std::int32_t member1026_{};
    std::int32_t member1027_{};
    std::int32_t member1028_{};
    std::int32_t member1029_{};
    std::int32_t member1030_{};
    std::int32_t member1031_{};
    std::int32_t member1032_{};
    float member1033_{};
    float member1034_{};
    float member1036_{};
    float member1037_{};
    float member1038_{};
    float member1039_{};
    float member1040_{};
    float member1041_{};
    AddressRef member1042_{};
    AddressRef member1043_{};
    AddressRef member1044_{};
    float member1045_{};
    AddressRef member1046_{};
    FloatRef member1047_{};
    FloatRef member1048_{};
    float member1049_{};
    float member1050_{};
    std::int32_t member1051_{};
    FloatRef member1052_{};
    std::int32_t member1053_{};
    float member1054_{};
    float member1055_{};
    float member1056_{};
    float member1057_{};
    std::int32_t member1058_{};
};

class MbcFiles final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFiles(Host &host);
    void initializeMembers() override;

  private:
    String readstr(std::int32_t parameter1);
    std::int32_t testfile(String parameter1);
    Task<void> main();
    Task<void> Ask();
    std::int32_t AskForFile(String parameter1, std::int32_t parameter2);
    std::int32_t IsReceived();
    std::int32_t PercentReceived();
    void helper36_1();
    String member1076_{};
    std::int32_t member1059_{};
    String member1060_{};
    std::array<std::uint8_t, 256> member1062_{};
    std::int32_t member1064_{};
    String member1066_{};
    std::int32_t member1067_{};
    std::int32_t member1068_{};
    std::int32_t member1069_{};
    std::int32_t member1070_{};
    std::int32_t member1071_{};
    std::int32_t member1072_{};
    std::array<std::uint8_t, 128> member1074_{};
    std::array<std::uint8_t, 29> member1077_{};
    String member1078_{};
    std::array<std::uint8_t, 9> member1079_{};
    std::array<std::uint8_t, 9> member1080_{};
    std::array<std::uint8_t, 9> member1081_{};
    std::array<std::uint8_t, 256> member1083_{};
    String member1085_{};
    std::int32_t member1086_{};
    std::int32_t member1087_{};
    std::int32_t member1088_{};
    std::array<std::uint8_t, 256> member1090_{};
    String member1092_{};
    std::int32_t member1093_{};
    std::int32_t member1094_{};
    std::int32_t member1095_{};
    std::int32_t member1096_{};
    std::int32_t member1097_{};
    std::int32_t member1098_{};
    IntRef member1099_{};
    std::int32_t member1100_{};
    std::int32_t member1102_{};
    std::int32_t member1103_{};
    std::int32_t member1104_{};
    std::int32_t member1105_{};
    std::int32_t member1106_{};
    std::int32_t member1107_{};
    std::int32_t member1108_{};
    std::int32_t member1109_{};
    std::array<std::uint8_t, 7> member1110_{};
    String member1111_{};
    std::int32_t member1112_{};
};

class MbcGmsg final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcGmsg(Host &host);
    void initializeMembers() override;

  private:
    std::int32_t SetItemGroup(std::int32_t parameter1);
    std::int32_t UnloadMsgGroup();
    Task<Value> LoadMsgGroup(String parameter1);
    Value LoadNewMsgGroup(std::int32_t parameter1, String parameter2);
    String gMsg(std::int32_t parameter1);
    std::int32_t member1113_{};
    std::array<std::uint8_t, 40> member1114_{};
    std::int32_t member1116_{};
    std::array<std::uint8_t, 64> member1118_{};
    std::array<std::uint8_t, 4> member1120_{};
    std::int32_t member1122_{};
    std::array<std::uint8_t, 1> member1123_{};
    String member1124_{};
    std::array<std::uint8_t, 4> member1125_{};
    std::array<std::uint8_t, 10> member1126_{};
    std::array<std::uint8_t, 5> member1127_{};
    std::int32_t member1129_{};
    std::array<std::uint8_t, 14> member1130_{};
    std::array<std::uint8_t, 11> member1131_{};
    std::int32_t member1132_{};
    String member1133_{};
    std::int32_t member1135_{};
    std::int32_t member1136_{};
    std::int32_t member1137_{};
    std::int32_t member1138_{};
    String member1139_{};
    String member1140_{};
    String member1141_{};
    std::int32_t member1142_{};
    String member1143_{};
    std::array<std::uint8_t, 29> member1144_{};
    std::array<std::uint8_t, 4> member1145_{};
    std::array<std::uint8_t, 4> member1146_{};
    std::array<std::uint8_t, 4> member1147_{};
    std::int32_t member1149_{};
    std::array<std::uint8_t, 8> member1150_{};
    std::int32_t member1151_{};
    std::int32_t member1152_{};
    String member1153_{};
    std::array<std::uint8_t, 8> member1154_{};
};

class MbcInv final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcInv(Host &host);
    void initializeMembers() override;

  private:
    Task<void> Inv();
    Task<std::int32_t> InvTrig2(std::int32_t parameter1);
    Task<std::int32_t> InvOn2(std::int32_t parameter1);
    Task<std::int32_t> InvOff2();
    Task<std::int32_t> setCostInWorkshop();
    std::int32_t receiveWindowHandler();
    Task<void> helper51_1();
    Task<void> helper83_1();
    Task<void> cleanup_Inv();
    ScriptState1 state1_{};
    std::int32_t member534_{};
    std::int32_t member1341_{};
    ScriptState40 state40_{};
    std::int32_t member1167_{};
    std::int32_t member1168_{};
    std::int32_t member1170_{};
    IntRef member1171_{};
    std::int32_t member1174_{};
    std::int32_t member1175_{};
    std::int32_t member1176_{};
    std::int32_t member1177_{};
    std::int32_t member1179_{};
    std::int32_t member1180_{};
    std::int32_t member1181_{};
    std::int32_t member1182_{};
    std::array<std::int32_t, 75> member1184_{};
    std::array<std::int32_t, 40> member1186_{};
    std::int32_t member1188_{};
    std::int32_t member1189_{};
    std::int32_t member1190_{};
    std::int32_t member1191_{};
    std::int32_t member1192_{};
    std::int32_t member1193_{};
    std::int32_t member1194_{};
    std::int32_t member1195_{};
    std::int32_t member1196_{};
    std::int32_t member1197_{};
    std::int32_t member1198_{};
    std::int32_t member1199_{};
    std::int32_t member1200_{};
    std::int32_t member1201_{};
    std::int32_t member1202_{};
    std::int32_t member1203_{};
    std::int32_t member1204_{};
    std::int32_t member1205_{};
    std::int32_t member1206_{};
    std::int32_t member1207_{};
    std::int32_t member1208_{};
    std::array<std::uint8_t, 64> member1209_{};
    std::array<std::uint8_t, 1024> member1211_{};
    std::array<std::uint8_t, 64> member1213_{};
    String member1215_{};
    String member1217_{};
    std::array<std::uint8_t, 5> member1218_{};
    std::array<std::uint8_t, 13> member1219_{};
    String member1220_{};
    std::array<std::uint8_t, 13> member1221_{};
    String member1222_{};
    std::array<std::uint8_t, 13> member1225_{};
    String member1226_{};
    std::array<std::uint8_t, 13> member1227_{};
    std::array<std::uint8_t, 14> member1229_{};
    std::array<std::uint8_t, 8> member1230_{};
    std::array<std::uint8_t, 20> member1231_{};
    std::array<std::uint8_t, 20> member1232_{};
    std::array<std::uint8_t, 10> member1233_{};
    std::array<std::uint8_t, 10> member1234_{};
    std::array<std::uint8_t, 10> member1235_{};
    std::array<std::uint8_t, 2> member1236_{};
    std::array<std::uint8_t, 5> member1237_{};
    std::array<std::uint8_t, 5> member1238_{};
    std::array<std::uint8_t, 17> member1239_{};
    std::array<std::uint8_t, 15> member1240_{};
    std::array<std::uint8_t, 25> member1241_{};
    std::array<std::uint8_t, 17> member1242_{};
    std::array<std::uint8_t, 9> member1243_{};
    std::array<std::uint8_t, 17> member1244_{};
    std::array<std::uint8_t, 9> member1245_{};
    std::array<std::uint8_t, 6> member1246_{};
    std::array<std::uint8_t, 8> member1247_{};
    std::array<std::uint8_t, 17> member1248_{};
    std::array<std::uint8_t, 20> member1250_{};
    std::int32_t member1252_{};
    std::int32_t member1253_{};
    std::array<std::uint8_t, 17> member1254_{};
    std::array<std::uint8_t, 14> member1255_{};
    std::array<std::uint8_t, 17> member1256_{};
    std::array<std::uint8_t, 17> member1257_{};
    std::int32_t member1259_{};
    String member1260_{};
    std::array<std::uint8_t, 9> member1261_{};
    String member1262_{};
    std::array<std::uint8_t, 21> member1263_{};
    std::array<std::uint8_t, 19> member1264_{};
    std::array<std::uint8_t, 9> member1266_{};
    std::int32_t member1268_{};
    std::int32_t member1269_{};
    std::array<std::uint8_t, 3> member1270_{};
    std::array<std::uint8_t, 3> member1271_{};
    std::array<std::uint8_t, 16> member1272_{};
    std::array<std::uint8_t, 17> member1273_{};
    std::array<std::uint8_t, 9> member1274_{};
    std::array<std::uint8_t, 4> member1275_{};
    String member1276_{};
    std::array<std::uint8_t, 7> member1277_{};
    std::array<std::uint8_t, 9> member1278_{};
    std::array<std::uint8_t, 19> member1279_{};
    String member1280_{};
    std::array<std::uint8_t, 17> member1281_{};
    String member1282_{};
    std::array<std::uint8_t, 21> member1283_{};
    String member1284_{};
    String member1285_{};
    std::array<std::uint8_t, 9> member1286_{};
    std::array<std::uint8_t, 7> member1287_{};
    std::array<std::uint8_t, 9> member1288_{};
    std::int32_t member1290_{};
    std::int32_t member1291_{};
    std::int32_t member1292_{};
    std::int32_t member1293_{};
    std::array<std::uint8_t, 21> member1294_{};
    std::int32_t member1296_{};
    std::array<std::uint8_t, 25> member1297_{};
    std::array<std::uint8_t, 21> member1298_{};
    std::array<std::uint8_t, 7> member1299_{};
    std::array<std::uint8_t, 10> member1300_{};
    std::array<std::uint8_t, 10> member1301_{};
    std::array<std::uint8_t, 10> member1302_{};
    std::array<std::uint8_t, 10> member1303_{};
    std::array<std::uint8_t, 11> member1304_{};
    String member1305_{};
    std::array<std::uint8_t, 11> member1306_{};
    String member1307_{};
    String member1308_{};
    float member1312_{};
    float member1313_{};
    std::int32_t member1314_{};
    std::array<std::uint8_t, 8> member1315_{};
    std::array<std::uint8_t, 13> member1316_{};
    std::array<std::uint8_t, 1> member1317_{};
    std::array<std::uint8_t, 3> member1318_{};
    std::array<std::uint8_t, 10> member1319_{};
    std::array<std::uint8_t, 8> member1320_{};
    String member1321_{};
    std::array<std::uint8_t, 5> member1322_{};
    std::array<std::uint8_t, 6> member1323_{};
    std::array<std::uint8_t, 5> member1324_{};
    std::array<std::uint8_t, 1> member1325_{};
    std::array<std::uint8_t, 8> member1326_{};
    std::array<std::uint8_t, 6> member1327_{};
    std::array<std::uint8_t, 6> member1328_{};
    std::array<std::uint8_t, 9> member1329_{};
    std::array<std::uint8_t, 6> member1330_{};
    std::array<std::uint8_t, 17> member1331_{};
    std::array<std::uint8_t, 9> member1332_{};
    std::array<std::uint8_t, 27> member1333_{};
    std::array<std::uint8_t, 21> member1334_{};
    std::array<std::uint8_t, 17> member1335_{};
    std::array<std::uint8_t, 26> member1336_{};
    std::array<std::uint8_t, 17> member1337_{};
    std::array<std::uint8_t, 17> member1338_{};
    std::array<std::uint8_t, 18> member1339_{};
    std::array<std::uint8_t, 6> member1340_{};
    std::int32_t member1343_{};
    String member1344_{};
    std::array<std::uint8_t, 7> member1345_{};
    std::array<std::uint8_t, 11> member1346_{};
    std::array<std::uint8_t, 17> member1347_{};
    std::array<std::uint8_t, 20> member1348_{};
    std::array<std::uint8_t, 10> member1350_{};
    std::array<std::uint8_t, 4> member1352_{};
    std::array<std::uint8_t, 20> member1353_{};
};

class MbcInvalch final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcInvalch(Host &host);
    void initializeMembers() override;

  private:
    Task<void> Inv();
    Task<void> helper42_1();
    Task<void> cleanup_Inv();
    ScriptState1 state1_{};
    std::int32_t member534_{};
    std::int32_t member1341_{};
    ScriptState40 state40_{};
    ScriptState43 state43_{};
    std::int32_t member1357_{};
    IntRef member1358_{};
    std::int32_t member1359_{};
    std::int32_t member1360_{};
    std::int32_t member1361_{};
    std::int32_t member1362_{};
    std::int32_t member1363_{};
    std::int32_t member1364_{};
    std::array<std::int32_t, 75> member1366_{};
    std::array<std::int32_t, 40> member1368_{};
    std::int32_t member1370_{};
    std::int32_t member1371_{};
    std::int32_t member1373_{};
    std::int32_t member1374_{};
    std::int32_t member1375_{};
    std::int32_t member1376_{};
    std::int32_t member1377_{};
    std::int32_t member1378_{};
    std::int32_t member1379_{};
    std::int32_t member1380_{};
    std::int32_t member1381_{};
    std::array<std::uint8_t, 64> member1383_{};
    std::array<std::uint8_t, 1024> member1385_{};
    std::array<std::uint8_t, 64> member1387_{};
    String member1389_{};
    std::array<std::uint8_t, 5> member1390_{};
    String member1391_{};
    std::array<std::uint8_t, 13> member1392_{};
    String member1393_{};
    std::array<std::uint8_t, 13> member1394_{};
    String member1395_{};
    std::array<std::uint8_t, 13> member1396_{};
    String member1397_{};
    std::array<std::uint8_t, 13> member1398_{};
    std::array<std::uint8_t, 14> member1400_{};
    std::array<std::uint8_t, 8> member1401_{};
    std::array<std::uint8_t, 17> member1402_{};
    std::array<std::uint8_t, 17> member1403_{};
    std::array<std::uint8_t, 8> member1404_{};
    std::array<std::uint8_t, 9> member1405_{};
    std::array<std::uint8_t, 4> member1406_{};
    std::array<std::uint8_t, 7> member1408_{};
    std::array<std::uint8_t, 9> member1409_{};
    std::array<std::uint8_t, 19> member1410_{};
    String member1411_{};
    String member1412_{};
    std::array<std::uint8_t, 7> member1413_{};
    std::array<std::uint8_t, 9> member1414_{};
    std::array<std::uint8_t, 9> member1415_{};
    std::array<std::uint8_t, 11> member1416_{};
    String member1418_{};
    std::array<std::uint8_t, 8> member1419_{};
    String member1420_{};
    String member1421_{};
    std::array<std::uint8_t, 5> member1422_{};
    std::array<std::uint8_t, 6> member1423_{};
    std::array<std::uint8_t, 1> member1424_{};
};

class MbcInventory final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcInventory(Host &host);
    void initializeMembers() override;

  private:
    Task<void> Inv();
    Task<void> helper50_1();
    Task<void> helper86_1();
    Task<void> cleanup_Inv();
    ScriptState1 state1_{};
    std::int32_t member534_{};
    std::int32_t member1341_{};
    ScriptState40 state40_{};
    ScriptState43 state43_{};
    std::int32_t member1427_{};
    IntRef member1428_{};
    std::int32_t member1429_{};
    std::int32_t member1430_{};
    std::int32_t member1431_{};
    std::int32_t member1432_{};
    std::int32_t member1433_{};
    std::int32_t member1434_{};
    std::array<std::int32_t, 40> member1436_{};
    std::int32_t member1438_{};
    std::int32_t member1439_{};
    std::int32_t member1440_{};
    std::int32_t member1441_{};
    std::int32_t member1442_{};
    std::int32_t member1443_{};
    std::int32_t member1444_{};
    std::int32_t member1445_{};
    std::int32_t member1446_{};
    std::int32_t member1447_{};
    std::int32_t member1448_{};
    std::int32_t member1449_{};
    IntRef member1450_{};
    IntRef member1451_{};
    std::int32_t member1452_{};
    std::array<std::uint8_t, 64> member1454_{};
    std::array<std::uint8_t, 1024> member1456_{};
    std::array<std::uint8_t, 64> member1458_{};
    String member1460_{};
    String member1461_{};
    std::array<std::uint8_t, 10> member1462_{};
    std::array<std::uint8_t, 10> member1463_{};
    std::array<std::uint8_t, 9> member1464_{};
    std::array<std::uint8_t, 4> member1465_{};
    std::array<std::uint8_t, 9> member1466_{};
    std::array<std::uint8_t, 19> member1467_{};
    String member1468_{};
    std::array<std::uint8_t, 17> member1469_{};
    String member1470_{};
    String member1471_{};
    std::array<std::uint8_t, 7> member1472_{};
    std::array<std::uint8_t, 9> member1473_{};
    std::array<std::uint8_t, 9> member1474_{};
    std::array<std::uint8_t, 7> member1475_{};
    std::array<std::uint8_t, 10> member1476_{};
    std::array<std::uint8_t, 10> member1477_{};
    std::array<std::uint8_t, 10> member1478_{};
    std::array<std::uint8_t, 10> member1479_{};
    std::array<std::uint8_t, 11> member1480_{};
    String member1481_{};
    std::array<std::uint8_t, 11> member1482_{};
    std::array<std::uint8_t, 7> member1483_{};
    float member1487_{};
    float member1488_{};
    std::array<std::uint8_t, 8> member1489_{};
    std::array<std::uint8_t, 13> member1490_{};
    std::array<std::uint8_t, 1> member1491_{};
    std::array<std::uint8_t, 3> member1492_{};
    std::array<std::uint8_t, 10> member1493_{};
    std::array<std::uint8_t, 256> member1495_{};
    std::array<std::uint8_t, 9> member1497_{};
    std::array<std::uint8_t, 3> member1498_{};
    std::array<std::uint8_t, 8> member1499_{};
    String member1500_{};
    String member1501_{};
    std::array<std::uint8_t, 5> member1502_{};
    std::array<std::uint8_t, 5> member1503_{};
    std::array<std::uint8_t, 8> member1504_{};
    std::array<std::uint8_t, 6> member1505_{};
    std::array<std::uint8_t, 6> member1506_{};
    std::array<std::uint8_t, 9> member1507_{};
    String member1508_{};
    std::array<std::uint8_t, 10> member1509_{};
};

class MbcMain final : public Module
{
    friend class ScriptHelpers;
    friend class MbcNpcTournament;
  public:
    explicit MbcMain(Host &host);
    void initializeMembers() override;

  private:
    Task<void> Console();
    std::int32_t GetIntegerArgument(std::int32_t parameter1, IntRef parameter2);
    std::int32_t GetFloatArgument(std::int32_t parameter1, FloatRef parameter2);
    std::int32_t GetStringArgument(std::int32_t parameter1, StringRef parameter2, std::int32_t parameter3);
    std::int32_t GetIDArgument(std::int32_t parameter1, StringRef parameter2);
    Value BoundValue(IntRef parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> TestOwnerPID();
    Task<std::int32_t> SendConsoleRequest(String parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t IsLetter(std::int8_t parameter1);
    std::int32_t IsLetterUnderscore(std::int8_t parameter1);
    std::int32_t IsDigit(std::int8_t parameter1);
    std::int32_t IsWhitespace(std::int8_t parameter1);
    std::int32_t ParseCommand(String parameter1);
    Task<Value> executeCommandByExactName();
    std::int32_t isValidAcronym(String parameter1);
    std::int32_t computeMatchingFunctionsNumber(String parameter1);
    std::int32_t composeWildcard(String parameter1, String parameter2, String parameter3);
    void listMatchingCommands(String parameter1);
    Task<Value> executeCommandByAcronym();
    Task<Value> executeCommandByAbbreviation();
    Task<std::int32_t> ProcessCommand(String parameter1);
    std::int32_t IsCommandEmpty(String parameter1);
    Task<void> ConsoleWindow();
    Value ToggleConsole();
    Value ShowConsole();
    Value HideConsole();
    std::int32_t TypeConsole(String parameter1, std::int32_t parameter2);
    std::int32_t __test_console();
    Task<std::int32_t> __enumerate_processes();
    Task<std::int32_t> __create_process();
    Task<std::int32_t> __destroy_process();
    Task<std::int32_t> __set_karma();
    Task<std::int32_t> __set_name();
    Task<std::int32_t> __cleanse_buffs();
    Task<std::int32_t> __cleanse_viruses();
    Task<std::int32_t> __get_couragef();
    Task<std::int32_t> __kill_monsters();
    Task<void> MinimapWindow();
    void ShowMinimapWindow();
    void HideMinimapWindow();
    void ToggleMinimapWindow();
    Task<void> cm_mainProgram();
    std::int32_t cm_isMenuItem(std::int32_t parameter1);
    Value cm_setTitle(String parameter1);
    Task<void> cm_createMenu();
    void cm_create();
    void cm_destroy();
    Value cm_clear();
    Value cm_addItem(String parameter1, std::int32_t parameter2, String parameter3, std::int32_t parameter4, String parameter5, std::int32_t parameter6);
    Value cm_addItemNoParams(String parameter1, std::int32_t parameter2, String parameter3, std::int32_t parameter4);
    Value cm_show();
    Value cm_hide();
    std::int32_t cm_isMainFunction(std::int32_t parameter1);
    std::int32_t cm_getExecuteResult();
    Task<Value> cm_executeFunction(std::int32_t parameter1);
    Value cm_click(std::int32_t parameter1);
    Value cm_enable(std::int32_t parameter1, std::int32_t parameter2);
    Value cm_setText(std::int32_t parameter1, String parameter2);
    std::int32_t cm_isVisible();
    std::int32_t cm_isCreated();
    Task<void> main();
    Task<void> MainTotD();
    Task<Value> ShowTotDWindow();
    Value HideTotDWindow();
    Task<Value> LoadTotDText(String parameter1);
    std::int32_t GetTotDTipsNumber();
    Value LoadTotDParams(IntRef parameter1, IntRef parameter2);
    std::int32_t SaveTotDParams(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> TestCastleNames();
    String GetCastleName(std::int32_t parameter1);
    std::int32_t GTST(std::int32_t parameter1);
    std::int32_t GMOD(std::int32_t parameter1);
    std::int32_t CheckTest();
    std::int32_t halt();
    Task<void> sercli();
    std::int32_t MKM(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t MEM(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    std::int32_t getMaxHealthAndPrana(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, IntRef parameter4, IntRef parameter5);
    std::int32_t MPRT(std::int32_t parameter1);
    std::int32_t INCB(std::int32_t parameter1);
    std::int32_t GENM(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int8_t parameter4, String parameter5);
    std::int32_t GetSysText(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t GetMBLnam(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    std::int32_t AtoR(std::int32_t parameter1, String parameter2);
    std::int32_t CalcRash(std::int32_t parameter1, String parameter2, IntRef parameter3);
    std::int32_t GEFF(std::int32_t effectIndex, EffectDefinition &output);
    std::int32_t getMissionFactorSet(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t GetMulti(std::int32_t objectId, std::int32_t variant, MultiObject &output);
    void get_crc(std::int32_t parameter1, IntRef parameter2, IntRef parameter3);
    std::int32_t get_pathlist(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t LastACC();
    std::int32_t UpdateSST(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, String parameter4);
    std::int32_t LoadStuff();
    Task<void> Lsst();
    std::int32_t LoadSSTW(std::int32_t parameter1);
    std::int32_t LoadSST(std::int32_t parameter1);
    std::int32_t SetOSST(std::int32_t parameter1);
    std::int32_t SetWall();
    Task<void> MultiobjCRC();
    std::int32_t getCrcValues(IntRef parameter1, IntRef parameter2);
    std::int32_t runCrcCalculation();
    std::int32_t WhatServer(float parameter1, float parameter2, float parameter3);
    std::int32_t WhatContinent(float parameter1, float parameter2);
    Task<void> LoadStatic();
    std::int32_t NCity(float parameter1, float parameter2, float parameter3, std::int32_t parameter4);
    std::int32_t GPNT(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4);
    Task<void> Tmnt();
    AddressRef getLastGVG();
    AddressRef getTmntData();
    std::int32_t SetTmntState(std::int32_t parameter1);
    std::int32_t GetTmntState();
    std::int32_t SetTmntTimeLeft(std::int32_t parameter1);
    std::int32_t GetTmntTimeLeft();
    std::int32_t SetTmntType(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t GetTmntType(std::int32_t parameter1);
    Task<Value> ReceiveTmntData(String parameter1);
    std::int32_t TmntPlayerGroup(String parameter1);
    std::int32_t TimeFromSec(String parameter1, std::int32_t parameter2);
    void LoadUnique(std::int32_t parameter1);
    String GetUBonus();
    std::int32_t UniqueLine(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4, std::int32_t parameter5, std::int32_t parameter6, String parameter7, std::int32_t parameter8, std::int32_t parameter9, String parameter10);
    std::int32_t TestUnique(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> EError();
    Task<std::int32_t> LoadPreset(std::int32_t parameter1, String parameter2);
    Task<void> EHalt();
    Task<void> Refresh();
    std::int32_t GetXYZ2(std::int32_t parameter1, AddressRef parameter2);
    std::int32_t runSayTryRestart(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> SayTryRestart();
    Task<void> SayConnectEnd();
    Task<void> Client();
    String GetMainServerURL(String parameter1);
    Task<Value> ConnResult(std::int32_t parameter1);
    std::int32_t SetPlayerID(std::int32_t parameter1);
    std::int32_t GetPlayerID();
    std::int32_t GETLG(std::int32_t parameter1, String parameter2);
    std::int32_t GETPD(std::int32_t parameter1, String parameter2);
    Task<void> PeekCancel();
    Value SetEnable(std::int32_t parameter1);
    Task<void> RestWait();
    Task<void> Title();
    Task<void> Camera();
    Task<Value> CamOff();
    Task<Value> CamOn();
    Task<void> IncTimeClient();
    Task<void> ClientSky();
    Task<void> ShowChat();
    std::int32_t mouseOverChat();
    Value EnableShopButton(std::int32_t parameter1);
    std::int32_t ChatHdl(std::int32_t parameter1, IntRef parameter2, IntRef parameter3);
    std::int32_t getChatState();
    Task<std::int32_t> setChatState(std::int32_t parameter1);
    std::int32_t sayPrivate2Plr(std::int32_t parameter1, String parameter2);
    std::int32_t sayPetition2Plr(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> getPlayerIDByName(String parameter1);
    std::int32_t chat(String parameter1, std::int32_t parameter2);
    std::int32_t sendSysTxt2ChatByNum(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t sendSysTextToChat(String parameter1, std::int32_t parameter2);
    Task<void> DragDrop();
    std::int32_t GetpID();
    std::int32_t GetddWin();
    Task<std::int32_t> SendDnDRes();
    Task<std::int32_t> SSCL(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> DnD(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    std::int32_t SetCursType(std::int32_t parameter1);
    std::int32_t GetHand();
    Task<Value> SetHand(std::int32_t parameter1);
    std::int32_t SetAmount(std::int32_t parameter1);
    std::int32_t GetAmount();
    Task<void> Shadowon();
    std::int32_t ShadowOn();
    std::int32_t ShadowOff();
    std::int32_t ShadowState();
    std::int32_t ShadowIm();
    std::int32_t Shadowing();
    std::int32_t GetRoomCoord(std::int32_t parameter1, std::int32_t parameter2, AddressRef parameter3);
    std::int32_t GetRoom(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t ClearRooms();
    std::int32_t GetSpecial(std::int32_t parameter1, std::int32_t parameter2, AddressRef parameter3);
    std::int32_t GetRndName(std::int32_t parameter1);
    std::int32_t GetMName(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t WinUpd();
    Task<void> Start_Win();
    std::int32_t Run_StartWin();
    std::int32_t Stop_StartWin();
    std::int32_t StartWinUnhide();
    std::int32_t LoadIgnoreList();
    std::int32_t IgnoreSender(String parameter1);
    std::int32_t AddToIgnoreList(String parameter1);
    std::int32_t RemoveFromIgnoreList(String parameter1);
    std::int32_t GetCrcBufferSize();
    std::int32_t getWasUpdate();
    std::int32_t setWasUpdate(std::int32_t parameter1);
    std::int32_t getContinentLoad(std::int32_t parameter1);
    std::int32_t setContinentLoad(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t checkContinentsDir();
    std::int32_t GetStCsGuard(std::int32_t parameter1);
    std::int32_t HavePrefZSH(std::int32_t parameter1);
    std::int32_t OriginCsBonus(std::int32_t parameter1);
    std::int32_t GetShopID();
    std::int32_t SetShopID(std::int32_t parameter1);
    Task<void> SlowSteps();
    Task<void> ProgressUpdater();
    std::int32_t SetFlagLoadscrOnTop(std::int32_t parameter1);
    Task<void> Shadowon2();
    std::int32_t CreateProgressBar();
    std::int32_t DestroyProgressBar();
    std::int32_t UpdateProgressBar();
    std::int32_t SetLoadingScreen(String parameter1);
    std::int32_t ShadowOn2();
    std::int32_t ShadowOff2();
    std::int32_t ShadowIm2();
    std::int32_t Shadowing2();
    std::int32_t ComputeParamsCrc();
    std::int32_t GetDir_ParamsCrc();
    std::int32_t GetTournamentId();
    std::int32_t insrtHText2ChatEdit(String parameter1);
    Task<std::int32_t> insrtItemInfo2Edit(std::int32_t parameter1);
    Value loadChatFonts();
    std::int32_t computeLinesNumber(std::string_view filename);
    std::int32_t loadItemIDsAndPrefixes(std::string_view filename, std::vector<ShopItemSelection> &items, std::int32_t maximumCount);
    Task<Value> dumpShopItems();
    Task<void> Conts();
    std::int32_t CreateUmap(String parameter1, std::int32_t parameter2, std::int32_t parameter3);
    std::int32_t GetGlobalCont(String parameter1);
    void helper97_1();
    void helper110_1();
    void helper71_1();
    void helper93_1();
    void helper1_1();
    Task<Value> helper56_1();
    Task<void> helper67_1();
    Task<Value> helper37_1();
    void helper99_1();
    void helper108_1();
    void helper69_1();
    Task<void> helper29_1();
    void helper45_1();
    Task<void> helper49_1();
    Task<void> helper102_1();
    void helper104_1();
    std::int32_t helper62_1();
    void helper68_1();
    void helper64_1();
    void helper31_1();
    Value helper12_1();
    Task<void> cleanup_ConsoleWindow();
    Task<void> cleanup_MinimapWindow();
    Task<void> cleanup_cm_mainProgram();
    Task<void> cleanup_SayTryRestart();
    Task<void> cleanup_SayConnectEnd();
    Task<void> cleanup_Client();
    Task<void> cleanup_Title();
    Task<void> cleanup_Camera();
    Task<void> cleanup_DragDrop();
    Task<void> cleanup_Shadowon();
    Task<void> cleanup_Start_Win();
    Task<void> cleanup_Shadowon2();
    std::int32_t member46_{};
    std::int32_t member150_{};
    std::int32_t member534_{};
    ScriptState34 state34_{};
    std::int32_t member1743_{};
    std::array<std::uint8_t, 22> member1763_{};
    std::array<std::uint8_t, 5> member2030_{};
    std::array<std::uint8_t, 9> member2602_{};
    std::int32_t member2855_{};
    std::array<std::uint8_t, 256> member1559_{};
    std::array<std::uint8_t, 256> member1561_{};
    std::array<std::uint8_t, 32> member1563_{};
    std::int32_t member1565_{};
    std::array<std::int32_t, 16> member1567_{};
    std::array<std::int32_t, 16> member1569_{};
    std::array<String, 4> member1571_{};
    std::array<std::uint8_t, 8> member1573_{};
    std::array<std::uint8_t, 6> member1574_{};
    std::array<std::uint8_t, 7> member1575_{};
    std::array<std::uint8_t, 11> member1576_{};
    std::int32_t member1577_{};
    IntRef member1578_{};
    std::array<std::uint8_t, 29> member1579_{};
    std::array<std::uint8_t, 56> member1580_{};
    std::int32_t member1581_{};
    FloatRef member1582_{};
    std::array<std::uint8_t, 29> member1583_{};
    std::array<std::uint8_t, 56> member1584_{};
    float member1586_{};
    std::int32_t member1587_{};
    StringRef member1588_{};
    std::int32_t member1589_{};
    std::array<std::uint8_t, 29> member1590_{};
    std::array<std::uint8_t, 56> member1591_{};
    String member1593_{};
    std::array<std::uint8_t, 81> member1594_{};
    std::int32_t member1595_{};
    StringRef member1596_{};
    std::array<std::uint8_t, 29> member1597_{};
    std::array<std::uint8_t, 56> member1598_{};
    String member1600_{};
    IntRef member1601_{};
    std::int32_t member1602_{};
    std::int32_t member1603_{};
    std::array<std::uint8_t, 38> member1604_{};
    std::array<std::uint8_t, 38> member1605_{};
    std::int32_t member1606_{};
    String member1607_{};
    std::array<std::uint8_t, 30> member1608_{};
    String member1609_{};
    std::int32_t member1610_{};
    String member1611_{};
    String member1612_{};
    String member1613_{};
    std::array<std::uint8_t, 17> member1614_{};
    std::int8_t member1615_{};
    std::int8_t member1616_{};
    std::int8_t member1617_{};
    std::int8_t member1618_{};
    String member1619_{};
    String member1621_{};
    String member1622_{};
    std::int32_t member1623_{};
    std::int32_t member1624_{};
    std::array<std::uint8_t, 78> member1625_{};
    std::array<std::uint8_t, 75> member1626_{};
    std::array<std::uint8_t, 66> member1627_{};
    std::array<std::uint8_t, 82> member1628_{};
    std::array<std::uint8_t, 68> member1629_{};
    std::int32_t member1631_{};
    std::int32_t member1632_{};
    float member1633_{};
    float member1634_{};
    std::array<std::uint8_t, 5> member1635_{};
    String member1636_{};
    String member1637_{};
    std::int32_t member1639_{};
    std::int32_t member1640_{};
    String member1641_{};
    String member1642_{};
    String member1643_{};
    String member1644_{};
    String member1645_{};
    std::int32_t member1646_{};
    String member1647_{};
    std::int32_t member1648_{};
    std::array<std::uint8_t, 32> member1650_{};
    std::array<std::uint8_t, 7> member1652_{};
    std::array<std::uint8_t, 95> member1654_{};
    std::array<std::uint8_t, 32> member1656_{};
    std::array<std::uint8_t, 2> member1658_{};
    std::array<std::uint8_t, 2> member1659_{};
    std::array<std::uint8_t, 50> member1660_{};
    std::array<std::uint8_t, 65> member1662_{};
    std::array<std::uint8_t, 32> member1664_{};
    std::array<std::uint8_t, 3> member1666_{};
    std::array<std::uint8_t, 1> member1667_{};
    std::array<std::uint8_t, 55> member1668_{};
    String member1669_{};
    std::array<String, 2> member1670_{};
    std::array<std::uint8_t, 1> member1671_{};
    String member1672_{};
    std::int32_t member1674_{};
    std::int32_t member1675_{};
    std::int32_t member1677_{};
    std::array<std::uint8_t, 256> member1679_{};
    std::int32_t member1681_{};
    std::int32_t member1682_{};
    std::int32_t member1684_{};
    std::int32_t member1685_{};
    std::int32_t member1686_{};
    std::int32_t member1687_{};
    std::array<std::uint8_t, 7> member1688_{};
    std::array<std::uint8_t, 1> member1689_{};
    String member1690_{};
    std::int32_t member1691_{};
    std::int32_t member1692_{};
    std::int32_t member1693_{};
    std::array<std::uint8_t, 26> member1694_{};
    std::array<String, 2> member1695_{};
    std::array<std::uint8_t, 15> member1696_{};
    std::int32_t member1698_{};
    std::array<std::uint8_t, 21> member1699_{};
    float member1701_{};
    std::array<std::uint8_t, 21> member1702_{};
    String member1704_{};
    std::array<std::uint8_t, 23> member1705_{};
    std::array<std::uint8_t, 23> member1706_{};
    std::array<std::uint8_t, 19> member1707_{};
    float member1709_{};
    String member1710_{};
    std::int32_t member1711_{};
    std::int32_t member1712_{};
    Address member1713_{};
    Address member1714_{};
    std::int32_t member1715_{};
    std::array<std::uint8_t, 128> member1717_{};
    std::array<std::uint8_t, 47> member1719_{};
    std::array<std::uint8_t, 28> member1720_{};
    std::array<std::uint8_t, 57> member1721_{};
    std::array<std::uint8_t, 50> member1722_{};
    String member1723_{};
    std::int32_t member1725_{};
    std::array<std::uint8_t, 64> member1726_{};
    std::array<std::uint8_t, 16> member1727_{};
    std::array<std::uint8_t, 41> member1728_{};
    std::array<std::uint8_t, 39> member1729_{};
    std::array<std::uint8_t, 7> member1730_{};
    std::array<std::uint8_t, 53> member1731_{};
    std::array<std::uint8_t, 6> member1732_{};
    std::array<std::uint8_t, 70> member1733_{};
    std::array<std::uint8_t, 91> member1734_{};
    String member1736_{};
    std::array<std::uint8_t, 30> member1737_{};
    std::array<std::uint8_t, 15> member1738_{};
    std::array<std::uint8_t, 7> member1739_{};
    std::array<std::uint8_t, 37> member1740_{};
    std::array<std::uint8_t, 6> member1741_{};
    std::array<std::uint8_t, 85> member1742_{};
    std::array<std::uint8_t, 33> member1744_{};
    std::array<std::uint8_t, 16> member1745_{};
    std::array<std::uint8_t, 7> member1746_{};
    std::array<std::uint8_t, 34> member1747_{};
    std::array<std::uint8_t, 6> member1748_{};
    std::array<std::uint8_t, 55> member1749_{};
    std::int32_t member1751_{};
    std::array<std::uint8_t, 34> member1752_{};
    std::array<std::uint8_t, 10> member1753_{};
    std::array<std::uint8_t, 7> member1754_{};
    std::array<std::uint8_t, 23> member1755_{};
    std::array<std::uint8_t, 6> member1756_{};
    std::array<std::uint8_t, 67> member1757_{};
    String member1759_{};
    std::array<std::uint8_t, 33> member1760_{};
    std::array<std::uint8_t, 9> member1761_{};
    std::array<std::uint8_t, 7> member1762_{};
    std::array<std::uint8_t, 6> member1764_{};
    std::array<std::uint8_t, 80> member1765_{};
    std::array<std::uint8_t, 52> member1766_{};
    std::array<std::uint8_t, 29> member1767_{};
    std::array<std::uint8_t, 14> member1768_{};
    std::array<std::uint8_t, 31> member1770_{};
    std::array<std::uint8_t, 16> member1771_{};
    std::array<std::uint8_t, 13> member1773_{};
    std::int32_t member1775_{};
    String member1776_{};
    std::array<std::uint8_t, 16> member1777_{};
    std::array<std::uint8_t, 17> member1778_{};
    String member1779_{};
    std::array<std::uint8_t, 7> member1780_{};
    std::array<std::uint8_t, 17> member1781_{};
    float member1783_{};
    std::array<std::uint8_t, 28> member1784_{};
    std::array<std::uint8_t, 14> member1785_{};
    std::array<std::uint8_t, 7> member1786_{};
    std::array<std::uint8_t, 21> member1787_{};
    std::int32_t member1789_{};
    std::int32_t member1790_{};
    std::int32_t member1791_{};
    std::int32_t member1792_{};
    std::int32_t member1793_{};
    std::int32_t member1794_{};
    String member1795_{};
    String member1796_{};
    std::array<std::uint8_t, 14> member1797_{};
    std::int32_t member1799_{};
    std::int32_t member1800_{};
    std::int8_t member1801_{};
    std::int32_t member1803_{};
    std::int32_t member1804_{};
    std::int32_t member1806_{};
    std::int32_t member1807_{};
    std::int32_t member1808_{};
    std::int32_t member1809_{};
    std::array<std::uint8_t, 128> member1811_{};
    String member1813_{};
    std::array<std::int32_t, 32> member1815_{};
    String member1817_{};
    std::int32_t member1818_{};
    std::int32_t member1819_{};
    String member1820_{};
    std::int32_t member1821_{};
    std::array<std::uint8_t, 8> member1822_{};
    std::array<std::uint8_t, 31> member1823_{};
    String member1824_{};
    std::int32_t member1825_{};
    String member1826_{};
    std::int32_t member1827_{};
    String member1828_{};
    std::int32_t member1829_{};
    std::array<std::uint8_t, 1> member1830_{};
    String member1831_{};
    std::int32_t member1832_{};
    String member1833_{};
    std::int32_t member1834_{};
    std::array<std::uint8_t, 1> member1835_{};
    float member1837_{};
    float member1838_{};
    std::int32_t member1839_{};
    std::int32_t member1840_{};
    std::array<std::uint8_t, 21> member1842_{};
    std::array<std::uint8_t, 256> member1844_{};
    std::int32_t member1846_{};
    std::int32_t member1847_{};
    std::int32_t member1848_{};
    std::int32_t member1849_{};
    String member1850_{};
    std::array<std::uint8_t, 1> member1851_{};
    std::int32_t member1853_{};
    std::int32_t member1854_{};
    std::int32_t member1855_{};
    std::int32_t member1856_{};
    std::int32_t member1857_{};
    std::int32_t member1858_{};
    std::int32_t member1859_{};
    std::int32_t member1860_{};
    std::int32_t member1861_{};
    std::int32_t member1862_{};
    std::int32_t member1863_{};
    IntRef member1864_{};
    String member1865_{};
    std::string member1866_{};
    String member1867_{};
    String member1868_{};
    String member1869_{};
    std::array<std::uint8_t, 4096> member1871_{};
    std::array<std::uint8_t, 4096> member1873_{};
    std::array<std::uint8_t, 256> member1875_{};
    std::array<String, 40> member1877_{};
    std::array<std::int8_t, 30> member1879_{};
    std::array<std::uint8_t, 256> member1881_{};
    std::array<IntRef, 10> member1883_{};
    std::int32_t member1885_{};
    std::int32_t member1886_{};
    std::int32_t member1887_{};
    std::int32_t member1888_{};
    std::int32_t member1889_{};
    std::int32_t member1890_{};
    std::int32_t member1891_{};
    std::int32_t member1892_{};
    std::int32_t member1893_{};
    std::int32_t member1894_{};
    std::array<std::uint8_t, 420000> member1896_{};
    std::array<std::int32_t, 22> member1898_{};
    std::int32_t member1899_{};
    std::int32_t member1900_{};
    std::int32_t member1901_{};
    std::int32_t member1902_{};
    std::array<std::int32_t, 27000> member1903_{};
    std::int32_t member1904_{};
    std::int32_t member1905_{};
    std::array<std::uint8_t, 100> member1907_{};
    std::array<std::uint8_t, 100> member1909_{};
    std::vector<std::int32_t> member1911_{};
    std::vector<std::int32_t> availableUniqueDefinitions_{};
    IntRef member1916_{};
    std::int32_t member1918_{};
    std::array<IntRef, 500> member1920_{};
    std::int32_t member1922_{};
    std::array<IntRef, 20> member1924_{};
    std::array<IntRef, 20> member1926_{};
    std::array<IntRef, 130> member1928_{};
    std::array<std::int32_t, 4> member1930_{};
    std::array<std::int32_t, 4> member1932_{};
    std::array<std::int32_t, 500> member1934_{};
    std::int32_t member1936_{};
    std::array<std::vector<std::int32_t>, 200> uniqueDefinitionsByGroup_{};
    std::int32_t member1942_{};
    std::int32_t member1943_{};
    std::array<String, 500> member1945_{};
    std::array<std::int8_t, 5000> member1947_{};
    std::array<std::uint8_t, 256> member1949_{};
    String member1951_{};
    std::string member1952_{};
    std::string member1953_{};
    std::vector<String> member1954_{};
    std::vector<String> member1955_{};
    std::vector<MultiObject> multiObjects_{};
    std::vector<MultiObject> multiObjectVariants_{};
    std::array<std::int32_t, 26> multiObjectVariantCounts_{};
    std::string member1963_{};
    std::array<std::uint8_t, 560> member1965_{};
    std::array<EffectDefinition, 500> effectDefinitions_{};
    std::vector<std::string> indexedConfigurations_{};
    std::vector<UniqueDefinition> uniqueDefinitions_{};
    std::vector<std::string> member1972_{};
    std::array<std::uint8_t, 64> member1974_{};
    std::array<std::uint8_t, 30> member1976_{};
    std::array<std::uint8_t, 64> member1978_{};
    std::intptr_t parameterFileSearch_ = -1;
    std::int8_t member1981_{};
    std::array<float, 10> multiObjectModeChances_{};
    std::array<float, 26> multiObjectGroupChances_{};
    std::array<std::int32_t, 33> member1987_{};
    std::int32_t member1989_{};
    std::array<std::int32_t, 100> member1991_{};
    std::int32_t member1993_{};
    std::int32_t member1994_{};
    std::int32_t member1995_{};
    std::int32_t member1997_{};
    std::int32_t member1998_{};
    std::array<std::uint8_t, 64> member2000_{};
    std::array<std::uint8_t, 30> member2002_{};
    std::int8_t member2004_{};
    std::int32_t member2005_{};
    std::int32_t member2006_{};
    std::int32_t member2007_{};
    std::int32_t member2009_{};
    std::array<std::int32_t, 60> member2011_{};
    std::array<std::int32_t, 60> member2013_{};
    std::array<std::int32_t, 60> member2015_{};
    std::array<std::int32_t, 60> member2017_{};
    std::array<std::int32_t, 60> member2019_{};
    std::array<std::int32_t, 120> member2021_{};
    std::array<std::int32_t, 120> member2023_{};
    std::array<std::int8_t, 60> member2025_{};
    std::array<std::int8_t, 60> member2027_{};
    std::array<std::uint8_t, 6> member2029_{};
    std::array<std::uint8_t, 6> member2031_{};
    String member2032_{};
    std::array<std::uint8_t, 29> member2033_{};
    String member2034_{};
    std::array<std::uint8_t, 8> member2035_{};
    std::array<std::uint8_t, 19> member2036_{};
    std::array<std::uint8_t, 29> member2037_{};
    std::array<std::uint8_t, 19> member2038_{};
    std::array<std::uint8_t, 29> member2039_{};
    std::array<std::uint8_t, 9> member2040_{};
    std::array<std::uint8_t, 4> member2041_{};
    std::array<std::uint8_t, 9> member2042_{};
    std::array<std::uint8_t, 8> member2043_{};
    std::array<std::uint8_t, 6> member2044_{};
    std::array<std::uint8_t, 6> member2045_{};
    String member2046_{};
    std::array<std::uint8_t, 29> member2047_{};
    String member2048_{};
    std::array<std::uint8_t, 8> member2049_{};
    std::array<std::uint8_t, 8> member2050_{};
    std::array<std::uint8_t, 15> member2051_{};
    std::array<std::uint8_t, 1> member2052_{};
    std::array<std::uint8_t, 21> member2053_{};
    std::array<std::uint8_t, 29> member2054_{};
    std::array<std::uint8_t, 5> member2055_{};
    std::array<std::uint8_t, 5> member2056_{};
    std::array<std::uint8_t, 5> member2057_{};
    std::array<std::uint8_t, 3> member2058_{};
    std::array<std::uint8_t, 6> member2059_{};
    std::array<std::uint8_t, 7> member2060_{};
    std::array<std::uint8_t, 6> member2061_{};
    std::array<std::uint8_t, 8> member2062_{};
    std::array<std::uint8_t, 6> member2063_{};
    std::array<std::uint8_t, 5> member2064_{};
    std::array<std::uint8_t, 6> member2065_{};
    std::array<std::uint8_t, 5> member2066_{};
    std::array<std::uint8_t, 7> member2067_{};
    std::array<std::uint8_t, 5> member2068_{};
    std::array<std::uint8_t, 7> member2069_{};
    std::array<std::uint8_t, 7> member2070_{};
    std::array<std::uint8_t, 20> member2071_{};
    std::array<std::uint8_t, 6> member2072_{};
    std::array<std::uint8_t, 3> member2073_{};
    std::array<std::uint8_t, 5> member2074_{};
    std::array<std::uint8_t, 7> member2075_{};
    std::array<std::uint8_t, 3> member2076_{};
    std::array<std::uint8_t, 5> member2077_{};
    std::array<std::uint8_t, 7> member2078_{};
    std::array<std::uint8_t, 29> member2079_{};
    std::array<std::uint8_t, 20> member2080_{};
    std::array<std::uint8_t, 27> member2081_{};
    std::array<std::uint8_t, 6> member2082_{};
    std::array<std::uint8_t, 3> member2083_{};
    std::array<std::uint8_t, 5> member2084_{};
    std::array<std::uint8_t, 7> member2085_{};
    std::array<std::uint8_t, 3> member2086_{};
    std::array<std::uint8_t, 5> member2087_{};
    std::array<std::uint8_t, 7> member2088_{};
    std::array<std::uint8_t, 29> member2089_{};
    std::array<std::uint8_t, 27> member2090_{};
    std::array<std::uint8_t, 18> member2091_{};
    std::array<std::uint8_t, 8> member2092_{};
    std::array<std::uint8_t, 3> member2093_{};
    std::array<std::uint8_t, 22> member2094_{};
    std::array<std::uint8_t, 16> member2095_{};
    std::array<std::uint8_t, 23> member2096_{};
    std::array<std::uint8_t, 2> member2097_{};
    std::array<std::uint8_t, 3> member2098_{};
    std::array<std::uint8_t, 3> member2099_{};
    std::array<std::uint8_t, 3> member2100_{};
    std::array<std::uint8_t, 3> member2101_{};
    std::array<std::uint8_t, 3> member2102_{};
    std::array<std::uint8_t, 3> member2103_{};
    std::array<std::uint8_t, 3> member2104_{};
    std::array<std::uint8_t, 3> member2105_{};
    std::array<std::uint8_t, 3> member2106_{};
    std::array<std::uint8_t, 20> member2107_{};
    std::array<std::uint8_t, 28> member2108_{};
    std::array<std::uint8_t, 3> member2109_{};
    std::array<std::uint8_t, 64> member2110_{};
    std::array<std::uint8_t, 64> member2111_{};
    std::array<std::uint8_t, 18> member2112_{};
    std::array<std::uint8_t, 3> member2113_{};
    std::array<std::uint8_t, 3> member2114_{};
    std::array<std::uint8_t, 3> member2115_{};
    std::array<std::uint8_t, 29> member2116_{};
    std::array<std::uint8_t, 18> member2117_{};
    std::array<std::uint8_t, 23> member2118_{};
    std::array<std::uint8_t, 3> member2119_{};
    std::array<std::uint8_t, 29> member2120_{};
    std::array<std::uint8_t, 23> member2121_{};
    std::array<std::uint8_t, 14> member2122_{};
    std::array<std::uint8_t, 14> member2123_{};
    std::array<std::uint8_t, 8> member2124_{};
    std::int32_t member2126_{};
    std::int32_t member2127_{};
    std::int32_t member2128_{};
    std::int32_t member2129_{};
    std::int32_t member2130_{};
    String member2131_{};
    std::int32_t member2132_{};
    std::int32_t member2133_{};
    std::int32_t member2134_{};
    std::int32_t member2135_{};
    std::int32_t member2136_{};
    std::int32_t member2137_{};
    std::int32_t member2138_{};
    std::int32_t member2139_{};
    std::array<std::uint8_t, 1024> member2141_{};
    String member2143_{};
    String member2144_{};
    String member2146_{};
    std::array<std::uint8_t, 5> member2147_{};
    std::array<std::uint8_t, 1> member2148_{};
    std::array<std::uint8_t, 5> member2149_{};
    std::array<std::uint8_t, 6> member2150_{};
    std::int32_t member2152_{};
    std::array<std::uint8_t, 4> member2153_{};
    IntRef member2154_{};
    IntRef member2155_{};
    std::array<std::uint8_t, 23> member2156_{};
    std::array<std::uint8_t, 29> member2157_{};
    std::array<std::uint8_t, 23> member2158_{};
    std::array<std::uint8_t, 5> member2159_{};
    std::array<std::uint8_t, 7> member2160_{};
    std::int32_t member2161_{};
    std::int32_t member2162_{};
    std::array<std::uint8_t, 23> member2163_{};
    std::array<std::uint8_t, 5> member2164_{};
    std::array<std::uint8_t, 7> member2165_{};
    std::array<String, 38> member2167_{};
    std::array<std::uint8_t, 6> member2169_{};
    std::array<std::uint8_t, 6> member2170_{};
    std::array<std::uint8_t, 5> member2171_{};
    std::array<std::uint8_t, 7> member2172_{};
    std::array<std::uint8_t, 10> member2173_{};
    std::array<std::uint8_t, 7> member2174_{};
    std::array<std::uint8_t, 9> member2175_{};
    std::array<std::uint8_t, 7> member2176_{};
    std::array<std::uint8_t, 8> member2177_{};
    std::array<std::uint8_t, 11> member2178_{};
    String member2179_{};
    std::array<std::uint8_t, 9> member2180_{};
    std::array<std::uint8_t, 11> member2181_{};
    std::array<std::uint8_t, 7> member2182_{};
    std::array<std::uint8_t, 11> member2183_{};
    std::array<std::uint8_t, 8> member2184_{};
    std::array<std::uint8_t, 10> member2185_{};
    std::array<std::uint8_t, 6> member2186_{};
    String member2187_{};
    std::array<std::uint8_t, 9> member2188_{};
    std::array<std::uint8_t, 7> member2189_{};
    std::array<std::uint8_t, 4> member2190_{};
    std::array<std::uint8_t, 7> member2191_{};
    std::array<std::uint8_t, 6> member2192_{};
    std::array<std::uint8_t, 11> member2193_{};
    std::array<std::uint8_t, 9> member2194_{};
    std::array<std::uint8_t, 7> member2195_{};
    std::array<std::uint8_t, 9> member2196_{};
    std::array<std::uint8_t, 5> member2197_{};
    std::array<std::uint8_t, 5> member2198_{};
    std::array<std::uint8_t, 6> member2199_{};
    std::array<std::uint8_t, 7> member2200_{};
    std::array<std::uint8_t, 9> member2201_{};
    std::array<std::uint8_t, 10> member2202_{};
    std::array<std::uint8_t, 7> member2203_{};
    std::array<std::uint8_t, 7> member2204_{};
    std::array<std::uint8_t, 10> member2205_{};
    std::array<std::uint8_t, 13> member2206_{};
    std::int32_t member2207_{};
    std::array<std::uint8_t, 10> member2208_{};
    std::int32_t member2209_{};
    std::int32_t member2210_{};
    std::int32_t member2212_{};
    std::int32_t member2213_{};
    std::array<std::uint8_t, 11> member2214_{};
    std::array<std::uint8_t, 29> member2215_{};
    std::array<std::uint8_t, 11> member2216_{};
    std::array<std::uint8_t, 5> member2217_{};
    std::array<std::uint8_t, 5> member2218_{};
    std::array<std::uint8_t, 9> member2219_{};
    std::array<std::uint8_t, 5> member2220_{};
    std::array<std::uint8_t, 5> member2221_{};
    std::array<std::uint8_t, 9> member2222_{};
    std::array<std::uint8_t, 5> member2223_{};
    std::array<std::uint8_t, 8> member2224_{};
    std::array<std::uint8_t, 11> member2225_{};
    String member2226_{};
    std::int32_t member2227_{};
    std::int32_t member2228_{};
    std::int32_t member2230_{};
    std::int32_t member2231_{};
    std::int32_t member2232_{};
    float member2233_{};
    std::int32_t member2234_{};
    std::int32_t member2235_{};
    std::int32_t member2236_{};
    std::int32_t member2237_{};
    std::int32_t member2238_{};
    std::int32_t member2239_{};
    std::int32_t member2240_{};
    IntRef member2241_{};
    IntRef member2242_{};
    std::int32_t member2243_{};
    std::int32_t member2244_{};
    std::int32_t member2245_{};
    std::int32_t member2246_{};
    std::int32_t member2247_{};
    std::int8_t member2248_{};
    String member2249_{};
    std::int32_t member2251_{};
    std::int32_t member2252_{};
    std::int32_t member2253_{};
    std::int32_t member2254_{};
    std::array<std::uint8_t, 19> member2256_{};
    std::array<std::uint8_t, 1> member2257_{};
    String member2258_{};
    std::int32_t member2259_{};
    std::int32_t member2260_{};
    String member2261_{};
    std::int32_t member2262_{};
    String member2263_{};
    std::int32_t member2264_{};
    std::int32_t member2268_{};
    std::int32_t member2270_{};
    String member2271_{};
    std::int32_t member2272_{};
    std::int32_t member2273_{};
    std::int32_t member2274_{};
    std::int32_t member2275_{};
    std::array<String, 16> member2277_{};
    std::array<std::uint8_t, 70> member2279_{};
    std::array<std::uint8_t, 2> member2281_{};
    std::array<std::uint8_t, 3> member2282_{};
    std::array<std::uint8_t, 4> member2283_{};
    std::array<std::uint8_t, 3> member2284_{};
    std::array<std::uint8_t, 2> member2285_{};
    std::array<std::uint8_t, 3> member2286_{};
    std::array<std::uint8_t, 4> member2287_{};
    std::array<std::uint8_t, 5> member2288_{};
    std::array<std::uint8_t, 3> member2289_{};
    std::array<std::uint8_t, 2> member2290_{};
    std::array<std::uint8_t, 3> member2291_{};
    std::array<std::uint8_t, 4> member2292_{};
    std::array<std::uint8_t, 5> member2293_{};
    std::array<std::uint8_t, 4> member2294_{};
    std::array<std::uint8_t, 3> member2295_{};
    std::array<std::int8_t, 8> member2297_{};
    std::array<std::int32_t, 8> member2299_{};
    std::int32_t member2301_{};
    String member2302_{};
    IntRef member2303_{};
    std::array<std::uint8_t, 8> member2305_{};
    std::int8_t member2307_{};
    std::array<std::uint8_t, 52> member2309_{};
    std::int32_t member2310_{};
    std::int32_t member2311_{};
    std::int32_t member2312_{};
    std::array<std::int32_t, 4> member2314_{};
    std::array<std::int32_t, 10> member2316_{};
    std::int32_t member2325_{};
    std::int32_t member2326_{};
    std::array<std::uint8_t, 45> member2327_{};
    std::int32_t member2329_{};
    std::array<std::int32_t, 15> multiObjectScales_{};
    std::int32_t member2357_{};
    IntRef member2358_{};
    IntRef member2359_{};
    std::int32_t member2360_{};
    std::int32_t member2361_{};
    String member2362_{};
    std::int32_t member2363_{};
    std::int32_t member2364_{};
    std::int32_t member2365_{};
    String member2366_{};
    std::int32_t member2368_{};
    std::int32_t member2369_{};
    IntRef member2370_{};
    IntRef member2371_{};
    std::array<std::uint8_t, 20> member2372_{};
    std::array<std::uint8_t, 19> member2373_{};
    std::int32_t member2375_{};
    std::int32_t member2376_{};
    std::int32_t member2377_{};
    std::int32_t member2378_{};
    std::int32_t member2379_{};
    std::int32_t member2380_{};
    IntRef member2381_{};
    std::int32_t member2382_{};
    std::int32_t member2383_{};
    std::int32_t member2384_{};
    std::int32_t member2385_{};
    std::int32_t member2386_{};
    std::int32_t member2387_{};
    std::int32_t member2388_{};
    std::int32_t member2389_{};
    std::int32_t member2390_{};
    std::int32_t member2392_{};
    std::int32_t member2393_{};
    String member2394_{};
    String member2395_{};
    String member2396_{};
    std::array<Address, 2> member2397_{};
    float member2398_{};
    std::int32_t member2400_{};
    std::int32_t member2402_{};
    std::array<std::uint8_t, 32> member2403_{};
    std::array<std::uint8_t, 16> member2404_{};
    std::int32_t member2405_{};
    std::int32_t member2407_{};
    std::int32_t member2408_{};
    std::int32_t member2409_{};
    std::int32_t member2411_{};
    std::int32_t member2413_{};
    std::int32_t member2414_{};
    String member2416_{};
    IntRef member2417_{};
    IntRef member2418_{};
    float member2419_{};
    float member2420_{};
    float member2421_{};
    Address member2422_{};
    std::int32_t member2423_{};
    float member2424_{};
    float member2425_{};
    std::int32_t member2426_{};
    std::int32_t member2428_{};
    std::int32_t member2429_{};
    std::array<std::uint8_t, 64> member2431_{};
    std::array<std::uint8_t, 20> member2433_{};
    std::array<std::uint8_t, 19> member2434_{};
    float member2435_{};
    float member2436_{};
    float member2437_{};
    std::int32_t member2438_{};
    std::int32_t member2439_{};
    std::int32_t member2440_{};
    std::int32_t member2441_{};
    float member2442_{};
    float member2443_{};
    Address member2444_{};
    std::int32_t member2445_{};
    std::int32_t member2446_{};
    std::int32_t member2447_{};
    std::int32_t member2448_{};
    std::int32_t member2449_{};
    std::int32_t member2450_{};
    std::int32_t member2451_{};
    std::int32_t member2452_{};
    std::array<std::uint8_t, 20> member2453_{};
    std::array<std::uint8_t, 16> member2454_{};
    std::array<Address, 2> member2455_{};
    std::int32_t member2456_{};
    std::int32_t member2457_{};
    std::int32_t member2458_{};
    std::int32_t member2459_{};
    std::int32_t member2460_{};
    String member2461_{};
    std::int32_t member2462_{};
    AddressRef member2463_{};
    String member2464_{};
    std::int32_t member2465_{};
    std::int32_t member2466_{};
    std::int32_t member2467_{};
    String member2468_{};
    std::int32_t member2469_{};
    std::int32_t member2470_{};
    std::int32_t member2471_{};
    std::array<std::uint8_t, 14> member2472_{};
    String member2473_{};
    std::int32_t member2474_{};
    std::int32_t member2476_{};
    std::int32_t member2477_{};
    std::int32_t member2478_{};
    std::array<std::uint8_t, 6> member2479_{};
    std::array<std::uint8_t, 10> member2480_{};
    std::array<std::uint8_t, 21> member2486_{};
    std::array<std::uint8_t, 21> member2515_{};
    std::array<std::uint8_t, 21> member2516_{};
    std::int32_t member2521_{};
    std::int32_t member2522_{};
    std::int32_t member2523_{};
    String member2524_{};
    std::int32_t member2525_{};
    std::int32_t member2527_{};
    String member2528_{};
    String member2529_{};
    std::array<std::uint8_t, 64> member2531_{};
    std::array<Address, 2> member2533_{};
    std::array<std::uint8_t, 29> member2534_{};
    std::array<std::uint8_t, 5> member2535_{};
    std::array<std::uint8_t, 9> member2536_{};
    std::array<std::uint8_t, 5> member2537_{};
    std::array<std::uint8_t, 2> member2538_{};
    std::array<std::uint8_t, 2> member2539_{};
    std::array<std::uint8_t, 2> member2540_{};
    std::array<std::uint8_t, 9> member2541_{};
    std::int32_t member2543_{};
    std::int32_t member2544_{};
    std::int32_t member2545_{};
    std::int32_t member2547_{};
    AddressRef member2548_{};
    Address member2549_{};
    std::int32_t member2550_{};
    std::int32_t member2551_{};
    std::array<std::int32_t, 2> member2553_{};
    std::int32_t member2555_{};
    std::int32_t member2556_{};
    std::int32_t member2557_{};
    std::int32_t member2558_{};
    std::array<std::uint8_t, 16> member2559_{};
    std::int32_t member2560_{};
    std::int32_t member2561_{};
    std::int32_t member2562_{};
    std::int32_t member2563_{};
    std::array<std::uint8_t, 10> member2564_{};
    std::array<std::uint8_t, 1> member2565_{};
    std::array<std::uint8_t, 16> member2566_{};
    std::array<std::uint8_t, 1> member2567_{};
    std::array<std::uint8_t, 11> member2568_{};
    std::int32_t member2570_{};
    std::int32_t member2571_{};
    std::int32_t member2573_{};
    std::int32_t member2575_{};
    std::int32_t member2576_{};
    std::int32_t member2577_{};
    std::array<std::uint8_t, 100> member2579_{};
    std::array<String, 5> member2581_{};
    std::array<std::uint8_t, 100> member2583_{};
    std::int32_t member2585_{};
    std::array<std::uint8_t, 17> member2586_{};
    std::array<std::uint8_t, 8> member2587_{};
    std::array<std::uint8_t, 9> member2588_{};
    std::array<std::uint8_t, 13> member2589_{};
    std::array<std::uint8_t, 29> member2590_{};
    std::array<std::uint8_t, 13> member2591_{};
    std::array<std::uint8_t, 5> member2592_{};
    std::array<std::uint8_t, 9> member2593_{};
    String member2594_{};
    std::array<std::uint8_t, 29> member2595_{};
    String member2596_{};
    std::array<std::uint8_t, 100> member2598_{};
    std::array<std::uint8_t, 9> member2600_{};
    std::array<std::uint8_t, 9> member2601_{};
    std::int32_t member2603_{};
    String member2604_{};
    std::array<std::uint8_t, 29> member2605_{};
    String member2606_{};
    std::array<std::uint8_t, 9> member2607_{};
    std::int32_t member2609_{};
    String member2610_{};
    std::array<std::uint8_t, 29> member2611_{};
    String member2612_{};
    std::array<std::uint8_t, 7> member2613_{};
    std::array<std::uint8_t, 8> member2614_{};
    std::array<std::uint8_t, 7> member2615_{};
    std::array<std::uint8_t, 2> member2616_{};
    String member2617_{};
    std::array<std::uint8_t, 29> member2618_{};
    String member2619_{};
    std::array<std::uint8_t, 7> member2620_{};
    std::array<std::uint8_t, 7> member2621_{};
    std::array<std::uint8_t, 2> member2622_{};
    std::array<std::uint8_t, 8> member2623_{};
    std::array<std::uint8_t, 5> member2624_{};
    std::array<std::uint8_t, 2> member2625_{};
    std::array<std::uint8_t, 2> member2626_{};
    std::array<std::uint8_t, 2> member2627_{};
    std::array<std::uint8_t, 5> member2628_{};
    String member2630_{};
    std::array<std::uint8_t, 29> member2631_{};
    String member2632_{};
    std::array<std::uint8_t, 9> member2633_{};
    String member2634_{};
    std::int32_t member2635_{};
    std::int32_t member2637_{};
    std::array<std::uint8_t, 9> member2638_{};
    std::array<std::uint8_t, 6> member2639_{};
    std::array<std::uint8_t, 9> member2640_{};
    std::int32_t member2641_{};
    std::int32_t member2642_{};
    std::int32_t member2643_{};
    String member2644_{};
    std::int32_t member2645_{};
    String member2646_{};
    std::int32_t member2647_{};
    std::int32_t member2648_{};
    std::int32_t member2649_{};
    std::int32_t member2650_{};
    std::int32_t member2651_{};
    String member2652_{};
    std::array<std::uint8_t, 29> member2653_{};
    String member2654_{};
    std::array<std::uint8_t, 8> member2655_{};
    String member2656_{};
    std::array<std::uint8_t, 29> member2657_{};
    String member2658_{};
    std::array<std::uint8_t, 8> member2659_{};
    String member2660_{};
    std::array<std::uint8_t, 13> member2661_{};
    std::array<std::uint8_t, 7> member2662_{};
    std::int32_t member2664_{};
    std::int32_t member2665_{};
    std::int32_t member2666_{};
    std::int32_t member2667_{};
    std::int32_t member2668_{};
    std::int32_t member2669_{};
    std::int32_t member2670_{};
    std::int32_t member2671_{};
    std::int32_t member2672_{};
    std::int32_t member2673_{};
    std::array<std::uint8_t, 3> member2674_{};
    std::array<std::uint8_t, 7> member2675_{};
    std::array<std::uint8_t, 7> member2676_{};
    std::int32_t member2678_{};
    std::int32_t member2679_{};
    std::int32_t member2680_{};
    std::int32_t member2681_{};
    std::int32_t member2682_{};
    std::int32_t member2683_{};
    std::int32_t member2684_{};
    std::int32_t member2685_{};
    std::int32_t member2686_{};
    std::int32_t member2687_{};
    float member2688_{};
    float member2689_{};
    std::array<std::uint8_t, 10> member2690_{};
    std::array<std::uint8_t, 5> member2691_{};
    std::array<std::uint8_t, 29> member2692_{};
    std::array<std::uint8_t, 10> member2693_{};
    std::array<std::uint8_t, 6> member2694_{};
    std::array<std::uint8_t, 6> member2695_{};
    std::array<std::uint8_t, 8> member2696_{};
    std::array<std::uint8_t, 8> member2697_{};
    std::array<std::uint8_t, 8> member2698_{};
    std::array<std::uint8_t, 8> member2699_{};
    std::array<std::uint8_t, 8> member2700_{};
    std::array<std::uint8_t, 8> member2701_{};
    String member2702_{};
    std::array<std::uint8_t, 7> member2703_{};
    String member2704_{};
    std::array<std::uint8_t, 7> member2705_{};
    std::int32_t member2706_{};
    std::int32_t member2707_{};
    std::int32_t member2708_{};
    std::array<std::uint8_t, 20> member2710_{};
    std::int32_t member2712_{};
    std::int32_t member2713_{};
    std::int32_t member2714_{};
    std::int32_t member2715_{};
    std::int32_t member2717_{};
    std::int32_t member2718_{};
    std::int32_t member2719_{};
    std::int32_t member2720_{};
    std::int32_t member2721_{};
    std::int32_t member2722_{};
    std::int32_t member2723_{};
    std::int32_t member2724_{};
    std::int32_t member2725_{};
    std::int32_t member2726_{};
    std::int32_t member2727_{};
    std::int32_t member2728_{};
    std::array<std::uint8_t, 32> member2730_{};
    std::array<std::int32_t, 7> member2732_{};
    std::int32_t member2734_{};
    std::int32_t member2735_{};
    std::int32_t member2736_{};
    std::int32_t member2737_{};
    std::int32_t member2738_{};
    std::array<std::uint8_t, 20> member2740_{};
    String member2742_{};
    std::int32_t member2743_{};
    std::array<std::uint8_t, 5> member2744_{};
    std::array<std::uint8_t, 9> member2745_{};
    std::array<std::uint8_t, 9> member2746_{};
    std::array<std::uint8_t, 20> member2747_{};
    std::array<std::uint8_t, 5> member2748_{};
    std::array<std::uint8_t, 15> member2749_{};
    std::array<std::uint8_t, 16> member2750_{};
    std::int32_t member2752_{};
    std::int32_t member2753_{};
    std::int32_t member2754_{};
    std::array<std::uint8_t, 8> member2755_{};
    std::array<String, 3> member2756_{};
    std::array<std::uint8_t, 41> member2757_{};
    std::array<std::uint8_t, 17> member2758_{};
    std::array<std::uint8_t, 20> member2759_{};
    std::array<std::uint8_t, 20> member2760_{};
    String member2761_{};
    std::array<std::uint8_t, 18> member2762_{};
    std::array<std::uint8_t, 1> member2763_{};
    std::array<std::uint8_t, 1> member2764_{};
    String member2765_{};
    std::array<std::uint8_t, 7> member2766_{};
    String member2767_{};
    std::array<std::uint8_t, 7> member2768_{};
    std::array<std::uint8_t, 3> member2769_{};
    std::array<std::uint8_t, 8> member2770_{};
    std::array<std::uint8_t, 1> member2771_{};
    std::array<std::uint8_t, 6> member2772_{};
    std::array<std::uint8_t, 6> member2773_{};
    std::array<std::uint8_t, 64> member2775_{};
    std::int32_t member2777_{};
    std::int32_t member2778_{};
    std::int32_t member2779_{};
    std::int32_t member2780_{};
    std::int32_t member2781_{};
    std::int32_t member2782_{};
    float member2783_{};
    float member2784_{};
    std::int32_t member2785_{};
    std::int32_t member2786_{};
    std::int32_t member2787_{};
    IntRef member2788_{};
    IntRef member2789_{};
    std::int32_t member2790_{};
    std::array<std::uint8_t, 10> member2791_{};
    std::int32_t member2792_{};
    String member2793_{};
    std::array<std::uint8_t, 20> member2795_{};
    String member2797_{};
    std::int32_t member2798_{};
    std::array<std::uint8_t, 10> member2799_{};
    std::int32_t member2800_{};
    String member2801_{};
    std::array<std::uint8_t, 256> member2803_{};
    std::array<std::uint8_t, 4096> member2805_{};
    std::array<std::uint8_t, 20> member2807_{};
    std::array<String, 2> member2809_{};
    std::array<std::uint8_t, 32> member2810_{};
    String member2811_{};
    std::int32_t member2813_{};
    std::array<std::uint8_t, 20> member2815_{};
    String member2817_{};
    std::int32_t member2818_{};
    std::int32_t member2820_{};
    std::int32_t member2821_{};
    std::int32_t member2822_{};
    std::int32_t member2823_{};
    std::int32_t member2824_{};
    std::int32_t member2825_{};
    std::int32_t member2826_{};
    std::array<std::uint8_t, 8> member2828_{};
    std::int32_t member2830_{};
    std::int32_t member2831_{};
    std::array<std::uint8_t, 5> member2832_{};
    String member2833_{};
    std::int32_t member2834_{};
    std::array<std::uint8_t, 5> member2835_{};
    std::int32_t member2837_{};
    std::int32_t member2838_{};
    std::int32_t member2839_{};
    std::int32_t member2840_{};
    std::int32_t member2841_{};
    std::int32_t member2842_{};
    std::array<std::uint8_t, 7> member2843_{};
    std::array<std::uint8_t, 7> member2844_{};
    std::array<std::uint8_t, 8> member2845_{};
    std::int32_t member2846_{};
    std::int32_t member2847_{};
    std::int32_t member2849_{};
    std::int32_t member2850_{};
    std::int32_t member2851_{};
    std::int32_t member2852_{};
    std::array<std::uint8_t, 8> member2853_{};
    std::int32_t member2854_{};
    std::array<std::uint8_t, 8> member2856_{};
    std::array<std::uint8_t, 9> member2857_{};
    std::int32_t member2859_{};
    std::int32_t member2860_{};
    std::int32_t member2861_{};
    std::array<std::uint8_t, 64> member2863_{};
    std::int32_t member2865_{};
    std::int32_t member2866_{};
    std::int32_t member2867_{};
    std::int32_t member2868_{};
    std::int32_t member2869_{};
    std::int32_t member2870_{};
    std::int32_t member2871_{};
    std::int32_t member2872_{};
    std::array<std::uint8_t, 1> member2873_{};
    std::array<std::uint8_t, 15> member2874_{};
    std::array<std::uint8_t, 15> member2875_{};
    std::array<std::uint8_t, 1> member2876_{};
    std::array<std::uint8_t, 15> member2877_{};
    std::array<std::uint8_t, 15> member2878_{};
    std::int32_t member2880_{};
    std::int32_t member2881_{};
    std::int32_t member2882_{};
    std::int32_t member2883_{};
    std::array<std::uint8_t, 6> member2884_{};
    std::array<std::uint8_t, 6> member2885_{};
    std::array<std::uint8_t, 6> member2886_{};
    std::array<std::uint8_t, 6> member2887_{};
    std::array<std::uint8_t, 10> member2888_{};
    std::int32_t member2889_{};
    std::int32_t member2890_{};
    AddressRef member2891_{};
    Address member2893_{};
    std::int32_t member2894_{};
    std::int32_t member2895_{};
    std::int32_t member2896_{};
    std::int32_t member2897_{};
    std::int32_t member2898_{};
    std::int32_t member2899_{};
    std::int32_t member2900_{};
    std::int32_t member2901_{};
    std::int32_t member2902_{};
    AddressRef member2903_{};
    IntRef member2904_{};
    std::int32_t member2905_{};
    std::array<std::uint8_t, 6> member2906_{};
    std::array<std::uint8_t, 6> member2907_{};
    std::array<std::uint8_t, 6> member2908_{};
    std::array<std::uint8_t, 6> member2909_{};
    std::array<std::uint8_t, 7> member2910_{};
    std::array<std::uint8_t, 7> member2911_{};
    std::array<std::uint8_t, 7> member2912_{};
    std::int32_t member2913_{};
    std::int32_t member2914_{};
    String member2915_{};
    std::int32_t member2917_{};
    std::int32_t member2918_{};
    std::int32_t member2919_{};
    std::array<std::uint8_t, 6> member2920_{};
    std::array<std::uint8_t, 4> member2921_{};
    std::array<std::uint8_t, 6> member2922_{};
    std::array<std::uint8_t, 6> member2923_{};
    std::array<std::uint8_t, 6> member2924_{};
    std::array<std::uint8_t, 6> member2925_{};
    std::array<std::uint8_t, 6> member2926_{};
    std::array<std::uint8_t, 7> member2927_{};
    std::array<std::uint8_t, 7> member2928_{};
    std::array<std::uint8_t, 7> member2929_{};
    std::array<std::uint8_t, 7> member2930_{};
    std::array<std::uint8_t, 1> member2931_{};
    std::int32_t member2933_{};
    std::int32_t member2935_{};
    std::int32_t member2937_{};
    std::array<std::uint8_t, 64> member2939_{};
    std::array<std::uint8_t, 30> member2941_{};
    std::int32_t member2943_{};
    std::int32_t member2944_{};
    std::int32_t member2946_{};
    std::int32_t member2947_{};
    std::int32_t member2948_{};
    std::int32_t member2949_{};
    std::int32_t member2950_{};
    std::int32_t member2951_{};
    std::int32_t member2952_{};
    std::int32_t member2953_{};
    std::array<std::uint8_t, 11> member2954_{};
    std::array<std::uint8_t, 1> member2955_{};
    std::int32_t member2956_{};
    std::array<std::uint8_t, 255> member2958_{};
    std::array<std::uint8_t, 8> member2960_{};
    std::array<std::uint8_t, 8> member2961_{};
    std::int32_t member2962_{};
    String member2963_{};
    std::array<std::uint8_t, 256> member2965_{};
    std::int32_t member2967_{};
    std::int32_t member2968_{};
    std::int32_t member2969_{};
    std::int32_t member2970_{};
    std::array<std::uint8_t, 11> member2971_{};
    std::array<std::uint8_t, 2> member2972_{};
    String member2973_{};
    std::int32_t member2975_{};
    std::int32_t member2977_{};
    String member2978_{};
    std::int32_t member2979_{};
    std::array<std::uint8_t, 11> member2980_{};
    std::array<std::uint8_t, 11> member2981_{};
    String member2982_{};
    std::int32_t member2984_{};
    std::int32_t member2985_{};
    std::int32_t member2986_{};
    String member2987_{};
    std::array<std::uint8_t, 256> member2989_{};
    std::array<std::uint8_t, 4> member2991_{};
    std::array<std::uint8_t, 11> member2992_{};
    std::array<std::uint8_t, 16> member2993_{};
    std::array<std::uint8_t, 2> member2994_{};
    std::array<std::uint8_t, 11> member2995_{};
    std::array<std::uint8_t, 16> member2996_{};
    std::array<std::uint8_t, 11> member2997_{};
    std::array<std::uint8_t, 11> member2998_{};
    std::int32_t member2999_{};
    std::int32_t member3000_{};
    std::int32_t member3001_{};
    std::int32_t member3002_{};
    std::int32_t member3004_{};
    std::array<std::uint8_t, 13> member3005_{};
    std::array<std::uint8_t, 13> member3006_{};
    std::array<std::uint8_t, 13> member3007_{};
    std::int32_t member3008_{};
    std::int32_t member3010_{};
    std::array<std::uint8_t, 50> member3012_{};
    std::array<std::uint8_t, 5> member3014_{};
    std::array<std::uint8_t, 20> member3015_{};
    std::array<std::uint8_t, 29> member3016_{};
    std::array<std::uint8_t, 20> member3017_{};
    std::int32_t member3018_{};
    std::int32_t member3020_{};
    std::int32_t member3021_{};
    std::int32_t member3022_{};
    std::int32_t member3023_{};
    std::array<std::uint8_t, 50> member3025_{};
    std::array<std::int32_t, 4> member3027_{};
    std::array<std::uint8_t, 5> member3029_{};
    std::array<std::uint8_t, 22> member3030_{};
    std::array<std::uint8_t, 29> member3031_{};
    std::array<std::uint8_t, 22> member3032_{};
    std::int32_t member3034_{};
    std::array<std::uint8_t, 5> member3035_{};
    std::int32_t member3036_{};
    std::int32_t member3038_{};
    std::int32_t member3039_{};
    std::int32_t member3040_{};
    std::array<std::uint8_t, 50> member3042_{};
    std::array<std::int32_t, 4> member3044_{};
    std::array<std::uint8_t, 22> member3046_{};
    std::array<std::uint8_t, 29> member3047_{};
    std::array<std::uint8_t, 22> member3048_{};
    std::int32_t member3050_{};
    std::array<std::uint8_t, 5> member3051_{};
    std::int32_t member3052_{};
    std::int32_t member3054_{};
    std::int32_t member3055_{};
    std::array<std::uint8_t, 5> member3056_{};
    std::int32_t member3057_{};
    StringRef member3058_{};
    String member3059_{};
    std::int32_t member3061_{};
    String member3062_{};
    String member3063_{};
    std::int32_t member3064_{};
    std::int32_t member3065_{};
    std::int32_t member3066_{};
    std::int32_t member3067_{};
    std::int32_t member3068_{};
    std::int32_t member3069_{};
    std::int32_t member3070_{};
    std::array<std::int32_t, 8> member3072_{};
    std::array<std::int32_t, 8> member3074_{};
    std::array<String, 4> member3076_{};
    std::array<std::uint8_t, 32> member3078_{};
    std::int32_t member3080_{};
    std::int32_t member3082_{};
    std::array<std::uint8_t, 11> member3084_{};
    std::array<std::uint8_t, 11> member3085_{};
    std::array<std::uint8_t, 11> member3086_{};
    std::array<std::uint8_t, 11> member3087_{};
    std::array<std::uint8_t, 8> member3088_{};
    std::array<std::uint8_t, 8> member3089_{};
    std::int32_t member3090_{};
    std::int32_t member3091_{};
    std::int32_t member3092_{};
    std::int32_t member3093_{};
    std::int32_t member3094_{};
    std::int32_t member3095_{};
    std::int32_t member3096_{};
    std::array<std::uint8_t, 16> member3097_{};
    std::int32_t member3098_{};
    String member3099_{};
    std::array<std::uint8_t, 3> member3100_{};
    std::array<std::uint8_t, 3> member3101_{};
    std::array<std::uint8_t, 4> member3102_{};
    std::array<std::uint8_t, 4> member3103_{};
    String member3104_{};
    std::int32_t member3105_{};
    std::array<std::uint8_t, 256> member3107_{};
    String member3109_{};
    std::array<std::uint8_t, 5> member3110_{};
    std::array<std::uint8_t, 5> member3111_{};
    std::array<std::uint8_t, 5> member3112_{};
    std::array<std::uint8_t, 11> member3113_{};
    std::array<std::uint8_t, 29> member3114_{};
    std::array<std::uint8_t, 11> member3115_{};
    std::array<std::uint8_t, 15> member3116_{};
    std::array<std::uint8_t, 15> member3117_{};
    std::array<std::uint8_t, 59> member3131_{};
    std::array<String, 5> member3136_{};
    std::array<std::uint8_t, 44> member3140_{};
    std::array<std::uint8_t, 4> member3145_{};
    std::array<std::uint8_t, 4> member3146_{};
    std::array<std::uint8_t, 4> member3147_{};
    std::array<std::uint8_t, 4> member3148_{};
    std::int32_t member3150_{};
    std::array<std::uint8_t, 4> member3151_{};
    std::array<std::uint8_t, 2> member3152_{};
    std::array<std::uint8_t, 52> member3153_{};
    std::int32_t member3155_{};
    String member3156_{};
    std::int32_t member3157_{};
    std::int32_t member3158_{};
    std::int32_t member3159_{};
    String member3160_{};
    std::int32_t member3161_{};
};

class MbcMission final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMission(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    Task<void> Mission();
    Task<void> cleanup_Mission();
    ScriptState1 state1_{};
    ScriptState30 state30_{};
    ScriptState34 state34_{};
    std::int32_t member3180_{};
    ScriptState44 state44_{};
    std::array<std::uint8_t, 5> member3176_{};
    std::array<std::uint8_t, 10> member3178_{};
    std::int32_t member3181_{};
    std::int32_t member3185_{};
    std::int32_t member3186_{};
    std::int32_t member3187_{};
    std::int32_t member3188_{};
    std::int32_t member3189_{};
    std::int32_t member3190_{};
    std::int32_t member3191_{};
    std::int32_t member3192_{};
    std::int32_t member3193_{};
    std::int32_t member3194_{};
    std::array<std::int32_t, 4> member3196_{};
    std::array<std::int32_t, 7> member3198_{};
    std::int32_t member3200_{};
    std::int32_t member3201_{};
    std::int32_t member3202_{};
    std::int32_t member3203_{};
    std::int32_t member3204_{};
    std::array<std::uint8_t, 64> member3206_{};
    String member3208_{};
    std::array<std::uint8_t, 9> member3209_{};
    std::array<std::uint8_t, 21> member3210_{};
};

class MbcPcontrol final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPcontrol(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    Task<std::int32_t> LoadKeys();
    std::int32_t TSTHK(std::int32_t parameter1);
    std::int32_t TSTIT(std::int32_t parameter1);
    std::int32_t GSCHF(std::int32_t parameter1, std::int32_t parameter2, IntRef parameter3);
    std::int32_t SetRunKey(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<void> ResetUIOnServerJump();
    Task<void> EPHalt();
    Task<Value> SaveSetup2(std::int32_t parameter1);
    Task<std::int32_t> UpdateCfg();
    void ControlOn();
    std::int32_t ControlOff();
    Task<void> Control();
    Task<void> Chat();
    Task<void> Mouse();
    std::int32_t IsChatFocus();
    Task<void> ControlMove();
    float GetDirAndSpeed(IntRef parameter1, FloatRef parameter2);
    std::int32_t SPDEFF(std::int32_t parameter1);
    std::int32_t RGTGS(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4, std::int32_t parameter5);
    Task<void> ShowInfo();
    Task<void> SelSky();
    Task<void> SelChar();
    std::int32_t Selected();
    Task<std::int32_t> SelectChar(std::int32_t parameter1);
    std::int32_t SetDelCharRes(std::int32_t parameter1);
    Task<void> MoveCamera();
    Task<void> TurnMod();
    Task<std::int32_t> Cursor(std::int32_t parameter1);
    Task<std::int32_t> SeekMap();
    std::int32_t getTempArrowMode();
    Task<void> WinManager();
    Task<std::int32_t> GetMisXZ(std::int32_t parameter1, FloatRef parameter2, FloatRef parameter3);
    std::int32_t IsChern();
    std::int32_t SetDebug(std::int32_t parameter1);
    Task<void> WinDiary();
    std::int32_t CloseDiary();
    std::int32_t AddToDiary(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    Task<void> PopMenu();
    void SetPopup(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t ActivatePopup(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4);
    std::int32_t PopupResult();
    Task<void> attachtext();
    Value AttachText(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    std::int32_t AttachType();
    float SetClanXZ(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> AAsk();
    String AskAlly(std::int32_t parameter1, String parameter2);
    Task<void> WinAlly();
    Task<Value> RefreshClanSymb(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> SetLicClan(std::int32_t parameter1, String parameter2, std::int32_t parameter3, std::int32_t parameter4);
    Task<void> WinClan();
    Value ShowWinClan(std::int32_t parameter1);
    Task<Value> AddPrayer(std::int32_t parameter1);
    std::int32_t runWinGroup();
    void stopWinGroupNew();
    void stopWinGroupExist();
    Task<void> winGroupNew();
    Task<void> winGroupExist();
    std::int32_t runRefreshWinGroupList(std::int32_t parameter1);
    Task<void> delayRefreshWinGroupList();
    Task<Value> refreshWinGroupList();
    Task<void> WinStat();
    std::int32_t DrawScale(std::int32_t parameter1, std::int32_t parameter2, String parameter3, std::int32_t parameter4, std::int32_t parameter5, std::int32_t parameter6, std::int32_t parameter7, std::int32_t parameter8, std::int32_t parameter9);
    std::int32_t ClearScale(std::int32_t parameter1);
    Task<void> ShowToolTip();
    void RSTT();
    Task<void> ShowLook();
    std::int32_t SetShowText(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    Task<void> CheckTrade();
    Task<void> WinTrade();
    std::int32_t SetTradeState(std::int32_t parameter1);
    Task<void> WinLitMacros();
    Task<void> WinMacros();
    Task<void> CalcMacroID();
    Task<void> DropAsk();
    Task<float> getWeaponUseDistance(std::int32_t parameter1);
    Task<float> computeUseDistance(std::int32_t parameter1);
    Task<void> WinMainData();
    Task<Value> checkDragAndDropStart();
    Task<float> checkMouseStayingStill();
    Task<Value> processDragAndDropEnd();
    Task<Value> processObjectDrop();
    Task<std::int32_t> moveObjectAlongLandscape(std::int32_t parameter1);
    Task<void> DragAndDropObjectMover();
    void processLButtonDown();
    Task<std::int32_t> processLButtonUp();
    Task<void> processLookOn(std::int32_t parameter1);
    Task<std::int32_t> processLButtonClick(std::int32_t parameter1, std::int32_t parameter2);
    Task<Value> useItemOnOneself(std::int32_t parameter1);
    Task<Value> useItemOnTarget(std::int32_t parameter1, std::int32_t parameter2);
    Task<Value> useItemOnSuperstatic(std::int32_t parameter1);
    Task<Value> processObjectClick(std::int32_t parameter1);
    std::int32_t processRButtonDown();
    Task<std::int32_t> processRButtonUp();
    Task<void> WinMain();
    Task<std::int32_t> use_on(std::int32_t parameter1, std::int32_t parameter2);
    Task<Value> processAutoDoors(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> CursorShapeWatcher();
    Task<void> AutobattleHandler();
    Task<void> AutobattleController();
    Task<void> Hand();
    Task<void> HandFist();
    std::int32_t SetHand2(std::int32_t parameter1);
    void SendHand(std::int32_t parameter1);
    Task<void> UseTout();
    std::int32_t SetUsing(std::int32_t parameter1);
    std::int32_t ifUsing();
    Task<void> ShowScroll();
    Task<void> ShowMission();
    Task<void> ShowText();
    std::int32_t TypeScroll(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    std::int32_t TypeScrollMem(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    std::int32_t CloseScroll();
    std::int32_t TypeMission2(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    std::int32_t FormatText(String parameter1, String parameter2, std::int32_t parameter3);
    Task<void> MusicManager();
    Task<String> GetMusic();
    Value PCNThit();
    Task<void> SoundManager();
    std::int32_t RegionType(float parameter1, float parameter2);
    Task<void> ShowReg();
    Task<void> ContourManager();
    std::int32_t TABLE(std::int32_t parameter1);
    Task<void> TTax();
    std::int32_t TTAX(std::int32_t parameter1, String parameter2);
    Task<void> TutoHelp();
    std::int32_t TutoMsg(std::int32_t parameter1);
    std::int32_t GotTrap(std::int32_t parameter1);
    Task<Value> GetChatPrefix(std::int32_t parameter1, String parameter2);
    Task<void> hotkeys();
    std::int32_t setMarkOnCompassByXZ(std::int32_t parameter1, float parameter2, float parameter3);
    Task<std::int32_t> isEvacPlayerAllowed(float parameter1, float parameter2, float parameter3);
    Task<void> EvacPlayerWinPrg();
    std::int32_t openEvacPlayerWin();
    std::int32_t closeEvacPlayerWin();
    Task<float> distToProcess(std::int32_t parameter1);
    Value loadMiniChatFonts();
    std::int32_t getAntiCastleCaptureTimer();
    std::int32_t clear_use_tout_working();
    std::int32_t block_character_move(std::int32_t parameter1);
    std::int32_t UpdateTmntWin();
    Task<void> WinTmntStateGVG();
    Task<void> ShowTmntStateGVG();
    Task<void> TmntIcon();
    void helper76_1();
    Task<void> helper58_1();
    Task<void> helper82_1();
    void helper65_1();
    void helper27_1();
    Task<void> helper21_1();
    Task<void> helper28_1();
    void helper7_1();
    void helper87_1();
    void helper7_2();
    Task<void> helper55_1();
    Value helper4_1();
    Task<void> helper70_1();
    Task<Value> helper89_1();
    void helper79_1();
    Task<void> helper75_1();
    Value helper63_1();
    void helper17_1();
    void helper22_1();
    void helper19_1();
    Task<void> helper77_1();
    Task<void> helper46_1();
    void helper106_1();
    void helper57_1();
    Task<void> helper72_1();
    Task<void> helper23_1();
    Task<void> helper5_1();
    void helper109_1();
    Task<void> helper16_1();
    void helper103_1();
    void helper2_1();
    void helper2_2();
    Task<void> helper54_1();
    Task<void> helper92_1();
    Task<std::int32_t> helper14_1();
    Task<std::int32_t> helper11_1();
    void helper18_1();
    void helper39_1();
    Task<void> helper111_1();
    Task<void> cleanup_Chat();
    Task<void> cleanup_Mouse();
    Task<void> cleanup_ShowInfo();
    Task<void> cleanup_SelChar();
    Task<void> cleanup_TurnMod();
    Task<void> cleanup_WinManager();
    Task<void> cleanup_WinDiary();
    Task<void> cleanup_PopMenu();
    Task<void> cleanup_attachtext();
    Task<void> cleanup_AAsk();
    Task<void> cleanup_WinAlly();
    Task<void> cleanup_WinClan();
    Task<void> cleanup_winGroupNew();
    Task<void> cleanup_winGroupExist();
    Task<void> cleanup_WinStat();
    Task<void> cleanup_ShowToolTip();
    Task<void> cleanup_ShowLook();
    Task<void> cleanup_WinTrade();
    Task<void> cleanup_WinLitMacros();
    Task<void> cleanup_WinMacros();
    Task<void> cleanup_DropAsk();
    Task<void> cleanup_DragAndDropObjectMover();
    Task<void> cleanup_AutobattleHandler();
    Task<void> cleanup_Hand();
    Task<void> cleanup_HandFist();
    Task<void> cleanup_UseTout();
    Task<void> cleanup_ShowScroll();
    Task<void> cleanup_ShowMission();
    Task<void> cleanup_ShowText();
    Task<void> cleanup_ShowReg();
    Task<void> cleanup_TTax();
    Task<void> cleanup_TutoHelp();
    Task<void> cleanup_hotkeys();
    Task<void> cleanup_EvacPlayerWinPrg();
    Task<void> cleanup_WinTmntStateGVG();
    ScriptState1 state1_{};
    ScriptState34 state34_{};
    std::int32_t member2855_{};
    String member3324_{};
    Address member3242_{};
    float member3243_{};
    float member3245_{};
    Address member3246_{};
    std::array<std::uint8_t, 6096> member3248_{};
    std::array<std::uint8_t, 128> member3250_{};
    std::string member3252_{};
    String member3253_{};
    std::array<std::uint8_t, 128> member3255_{};
    std::int32_t member3257_{};
    std::int32_t member3258_{};
    std::int32_t member3259_{};
    std::int32_t member3260_{};
    std::int32_t member3261_{};
    std::int32_t member3262_{};
    std::int32_t member3263_{};
    std::int32_t member3264_{};
    std::int32_t member3265_{};
    std::int32_t member3266_{};
    std::int32_t member3267_{};
    std::int32_t member3268_{};
    std::int32_t member3269_{};
    std::int32_t member3270_{};
    std::int32_t member3271_{};
    std::int32_t member3272_{};
    std::int32_t member3273_{};
    std::int32_t member3274_{};
    std::int32_t member3275_{};
    std::int32_t member3276_{};
    std::int32_t member3277_{};
    std::int32_t member3278_{};
    std::int32_t member3279_{};
    std::int32_t member3280_{};
    std::int32_t member3281_{};
    std::int32_t member3282_{};
    std::int32_t member3283_{};
    std::int32_t member3284_{};
    std::int32_t member3285_{};
    std::int32_t member3286_{};
    std::int32_t member3287_{};
    std::int32_t member3288_{};
    std::int32_t member3289_{};
    std::int32_t member3290_{};
    std::int32_t member3291_{};
    std::int32_t member3292_{};
    std::array<std::uint8_t, 68> member3293_{};
    std::int32_t member3294_{};
    std::int32_t member3295_{};
    std::int32_t member3296_{};
    IntRef member3297_{};
    IntRef member3298_{};
    std::array<std::uint8_t, 2560> member3300_{};
    std::array<std::uint8_t, 80> member3302_{};
    std::array<std::int32_t, 30> member3304_{};
    std::int32_t member3305_{};
    std::array<std::int32_t, 14> member3307_{};
    std::array<std::uint8_t, 32> member3309_{};
    std::int32_t member3311_{};
    std::array<std::int32_t, 20> member3313_{};
    std::array<std::uint8_t, 560> member3315_{};
    std::array<Address, 7> member3317_{};
    std::int32_t member3318_{};
    std::int32_t member3319_{};
    std::int32_t member3320_{};
    std::int32_t member3322_{};
    std::int32_t member3323_{};
    std::array<std::uint8_t, 9> member3325_{};
    std::array<std::uint8_t, 9> member3327_{};
    std::array<std::uint8_t, 8> member3328_{};
    std::array<std::uint8_t, 9> member3329_{};
    std::array<std::uint8_t, 7> member3330_{};
    std::array<std::uint8_t, 6> member3331_{};
    std::array<std::uint8_t, 5> member3332_{};
    std::array<std::uint8_t, 5> member3333_{};
    std::array<std::uint8_t, 9> member3334_{};
    std::array<std::uint8_t, 6> member3335_{};
    std::array<std::uint8_t, 18> member3336_{};
    std::array<std::uint8_t, 1> member3337_{};
    std::array<std::uint8_t, 9> member3338_{};
    std::array<std::uint8_t, 6> member3339_{};
    std::int32_t member3340_{};
    String member3342_{};
    std::array<std::uint8_t, 8> member3343_{};
    std::array<std::uint8_t, 9> member3344_{};
    std::array<std::uint8_t, 10> member3345_{};
    std::array<std::uint8_t, 11> member3346_{};
    std::array<std::uint8_t, 9> member3347_{};
    std::array<std::uint8_t, 8> member3348_{};
    std::array<std::uint8_t, 7> member3349_{};
    std::array<std::uint8_t, 8> member3350_{};
    std::array<std::uint8_t, 8> member3351_{};
    std::array<std::uint8_t, 8> member3352_{};
    std::array<std::uint8_t, 7> member3353_{};
    std::array<std::uint8_t, 7> member3354_{};
    std::array<std::uint8_t, 9> member3355_{};
    std::array<std::uint8_t, 8> member3356_{};
    std::array<std::uint8_t, 8> member3357_{};
    std::array<std::uint8_t, 10> member3358_{};
    std::array<std::uint8_t, 7> member3359_{};
    std::array<std::uint8_t, 9> member3360_{};
    std::array<std::uint8_t, 10> member3361_{};
    std::array<std::uint8_t, 8> member3362_{};
    std::array<std::uint8_t, 7> member3363_{};
    std::array<std::uint8_t, 7> member3364_{};
    std::array<std::uint8_t, 7> member3365_{};
    std::array<std::uint8_t, 7> member3366_{};
    std::array<std::uint8_t, 10> member3367_{};
    std::array<std::uint8_t, 11> member3368_{};
    std::array<std::uint8_t, 11> member3369_{};
    std::array<std::uint8_t, 13> member3370_{};
    std::array<std::uint8_t, 9> member3371_{};
    std::array<std::uint8_t, 9> member3372_{};
    std::array<std::uint8_t, 5> member3373_{};
    std::array<std::uint8_t, 5> member3374_{};
    std::array<std::uint8_t, 5> member3375_{};
    std::array<std::uint8_t, 5> member3376_{};
    std::array<std::uint8_t, 5> member3377_{};
    std::array<std::uint8_t, 5> member3378_{};
    std::array<std::uint8_t, 5> member3379_{};
    std::array<std::uint8_t, 5> member3380_{};
    std::array<std::uint8_t, 5> member3381_{};
    std::array<std::uint8_t, 5> member3382_{};
    std::array<std::uint8_t, 5> member3383_{};
    std::array<std::uint8_t, 5> member3384_{};
    std::array<std::uint8_t, 5> member3385_{};
    std::array<std::uint8_t, 5> member3386_{};
    std::array<std::uint8_t, 5> member3387_{};
    std::array<std::uint8_t, 5> member3388_{};
    std::array<std::uint8_t, 5> member3389_{};
    std::array<std::uint8_t, 5> member3390_{};
    std::array<std::uint8_t, 5> member3391_{};
    std::array<std::uint8_t, 5> member3392_{};
    std::array<std::uint8_t, 5> member3393_{};
    String member3394_{};
    std::array<std::uint8_t, 5> member3395_{};
    std::array<std::uint8_t, 5> member3396_{};
    std::array<std::uint8_t, 5> member3397_{};
    std::array<std::uint8_t, 5> member3398_{};
    std::array<std::uint8_t, 5> member3399_{};
    std::array<std::uint8_t, 5> member3400_{};
    std::array<std::uint8_t, 29> member3401_{};
    String member3402_{};
    std::int32_t member3403_{};
    std::int32_t member3404_{};
    std::array<std::uint8_t, 8> member3405_{};
    std::int32_t member3406_{};
    std::int32_t member3407_{};
    std::int32_t member3408_{};
    std::int32_t member3409_{};
    IntRef member3410_{};
    std::int32_t member3411_{};
    std::int32_t member3412_{};
    IntRef member3413_{};
    std::int32_t member3414_{};
    std::int32_t member3415_{};
    std::int32_t member3416_{};
    IntRef member3417_{};
    std::int32_t member3418_{};
    std::int32_t member3419_{};
    std::array<std::uint8_t, 9> member3420_{};
    std::array<std::uint8_t, 29> member3422_{};
    std::array<std::uint8_t, 9> member3423_{};
    std::array<std::uint8_t, 8> member3424_{};
    std::array<std::uint8_t, 13> member3425_{};
    std::array<std::uint8_t, 9> member3426_{};
    std::array<std::uint8_t, 9> member3427_{};
    std::array<std::uint8_t, 5> member3428_{};
    std::array<std::uint8_t, 6> member3429_{};
    std::array<std::uint8_t, 7> member3430_{};
    std::array<std::uint8_t, 6> member3431_{};
    std::array<std::uint8_t, 5> member3432_{};
    String member3433_{};
    std::array<std::uint8_t, 8> member3434_{};
    std::array<std::uint8_t, 9> member3435_{};
    std::array<std::uint8_t, 10> member3436_{};
    std::array<std::uint8_t, 11> member3437_{};
    std::array<std::uint8_t, 9> member3438_{};
    std::array<std::uint8_t, 8> member3439_{};
    std::array<std::uint8_t, 7> member3440_{};
    std::array<std::uint8_t, 8> member3441_{};
    std::array<std::uint8_t, 8> member3442_{};
    std::array<std::uint8_t, 8> member3443_{};
    std::array<std::uint8_t, 7> member3444_{};
    std::array<std::uint8_t, 7> member3445_{};
    std::array<std::uint8_t, 9> member3446_{};
    std::array<std::uint8_t, 8> member3447_{};
    std::array<std::uint8_t, 8> member3448_{};
    std::array<std::uint8_t, 10> member3449_{};
    std::array<std::uint8_t, 7> member3450_{};
    std::array<std::uint8_t, 9> member3451_{};
    std::array<std::uint8_t, 10> member3452_{};
    std::array<std::uint8_t, 8> member3453_{};
    std::array<std::uint8_t, 7> member3454_{};
    std::array<std::uint8_t, 7> member3455_{};
    std::array<std::uint8_t, 7> member3456_{};
    std::array<std::uint8_t, 10> member3457_{};
    std::array<std::uint8_t, 11> member3458_{};
    std::array<std::uint8_t, 11> member3459_{};
    std::array<std::uint8_t, 13> member3460_{};
    std::array<std::uint8_t, 9> member3461_{};
    std::array<std::uint8_t, 9> member3462_{};
    std::array<std::uint8_t, 29> member3463_{};
    String member3464_{};
    std::int32_t member3466_{};
    std::array<std::uint8_t, 5> member3467_{};
    std::array<std::uint8_t, 5> member3468_{};
    std::array<std::uint8_t, 5> member3469_{};
    std::array<std::uint8_t, 5> member3470_{};
    std::array<std::uint8_t, 5> member3471_{};
    std::array<std::uint8_t, 5> member3472_{};
    std::array<std::uint8_t, 5> member3473_{};
    std::array<std::uint8_t, 5> member3474_{};
    std::array<std::uint8_t, 5> member3475_{};
    std::array<std::uint8_t, 5> member3476_{};
    std::array<std::uint8_t, 5> member3477_{};
    std::array<std::uint8_t, 5> member3478_{};
    std::array<std::uint8_t, 5> member3479_{};
    std::array<std::uint8_t, 5> member3480_{};
    std::array<std::uint8_t, 5> member3481_{};
    std::array<std::uint8_t, 5> member3482_{};
    std::array<std::uint8_t, 5> member3483_{};
    std::array<std::uint8_t, 5> member3484_{};
    std::array<std::uint8_t, 5> member3485_{};
    std::array<std::uint8_t, 5> member3486_{};
    std::array<std::uint8_t, 5> member3487_{};
    std::array<std::uint8_t, 5> member3488_{};
    std::array<std::uint8_t, 5> member3489_{};
    std::array<std::uint8_t, 5> member3490_{};
    std::array<std::uint8_t, 5> member3491_{};
    std::array<std::uint8_t, 5> member3492_{};
    std::array<std::uint8_t, 5> member3493_{};
    std::array<std::uint8_t, 14> member3494_{};
    std::int32_t member3496_{};
    std::array<std::uint8_t, 7> member3498_{};
    std::int32_t member3499_{};
    std::int32_t member3500_{};
    std::int32_t member3501_{};
    std::int32_t member3502_{};
    std::int32_t member3503_{};
    std::int32_t member3504_{};
    std::int32_t member3505_{};
    std::int32_t member3506_{};
    std::int32_t member3507_{};
    std::int32_t member3508_{};
    std::int32_t member3510_{};
    String member3511_{};
    std::array<std::uint8_t, 20> member3513_{};
    std::array<std::uint8_t, 4096> member3515_{};
    std::array<std::uint8_t, 4096> member3517_{};
    std::int32_t member3519_{};
    std::array<std::uint8_t, 20> member3521_{};
    std::array<std::uint8_t, 13> member3523_{};
    std::array<std::uint8_t, 8> member3524_{};
    std::array<std::uint8_t, 10> member3525_{};
    std::array<std::uint8_t, 20> member3526_{};
    std::array<std::uint8_t, 1> member3527_{};
    std::array<std::uint8_t, 1> member3528_{};
    std::array<std::uint8_t, 7> member3529_{};
    std::array<std::uint8_t, 7> member3530_{};
    std::array<std::uint8_t, 3> member3531_{};
    std::array<std::uint8_t, 8> member3532_{};
    std::array<std::uint8_t, 1> member3533_{};
    std::array<std::uint8_t, 20> member3534_{};
    std::array<std::uint8_t, 13> member3535_{};
    std::array<std::uint8_t, 8> member3536_{};
    std::int32_t member3538_{};
    std::int32_t member3539_{};
    std::int32_t member3540_{};
    std::int32_t member3541_{};
    std::int32_t member3542_{};
    std::int32_t member3543_{};
    std::int32_t member3544_{};
    float member3545_{};
    float member3546_{};
    std::int8_t member3547_{};
    std::int32_t member3549_{};
    std::int32_t member3550_{};
    std::int32_t member3551_{};
    std::int32_t member3552_{};
    std::int32_t member3553_{};
    std::int32_t member3554_{};
    std::int32_t member3555_{};
    std::int32_t member3556_{};
    std::int32_t member3557_{};
    std::int32_t member3558_{};
    std::int32_t member3559_{};
    std::int32_t member3560_{};
    std::int32_t member3561_{};
    IntRef member3562_{};
    IntRef member3563_{};
    IntRef member3564_{};
    IntRef member3565_{};
    std::int32_t member3566_{};
    std::int32_t member3567_{};
    float member3569_{};
    float member3571_{};
    float member3572_{};
    float member3573_{};
    float member3574_{};
    float member3576_{};
    String member3577_{};
    std::array<std::uint8_t, 9> member3578_{};
    std::array<std::uint8_t, 20> member3579_{};
    std::array<std::uint8_t, 20> member3580_{};
    std::int32_t member3582_{};
    std::int32_t member3583_{};
    std::array<std::uint8_t, 7> member3584_{};
    std::array<std::uint8_t, 13> member3585_{};
    std::array<std::uint8_t, 6> member3586_{};
    std::array<std::uint8_t, 5> member3587_{};
    String member3588_{};
    std::array<std::uint8_t, 18> member3589_{};
    std::int32_t member3591_{};
    std::int32_t member3592_{};
    std::array<std::uint8_t, 14> member3593_{};
    float member3595_{};
    IntRef member3597_{};
    FloatRef member3598_{};
    std::int32_t member3599_{};
    IntRef member3600_{};
    std::int32_t member3601_{};
    std::int32_t member3602_{};
    std::int32_t member3603_{};
    std::int32_t member3604_{};
    std::int32_t member3605_{};
    std::int32_t member3606_{};
    std::int32_t member3607_{};
    std::int32_t member3608_{};
    std::int32_t member3609_{};
    std::int32_t member3610_{};
    std::int32_t member3611_{};
    std::array<std::uint8_t, 100> member3613_{};
    std::int32_t member3615_{};
    String member3616_{};
    std::array<std::uint8_t, 13> member3617_{};
    std::array<std::uint8_t, 6> member3618_{};
    std::array<std::uint8_t, 13> member3619_{};
    std::array<std::uint8_t, 8> member3620_{};
    std::array<std::uint8_t, 7> member3621_{};
    std::array<std::uint8_t, 7> member3622_{};
    std::array<std::uint8_t, 7> member3623_{};
    std::array<std::uint8_t, 11> member3624_{};
    std::int32_t member3625_{};
    std::int32_t member3626_{};
    std::int32_t member3627_{};
    std::int32_t member3628_{};
    std::int32_t member3629_{};
    std::int32_t member3630_{};
    std::int32_t member3631_{};
    std::int32_t member3632_{};
    std::array<std::int32_t, 4> member3634_{};
    std::int32_t member3636_{};
    std::int32_t member3637_{};
    std::int32_t member3638_{};
    std::int32_t member3639_{};
    String member3640_{};
    std::int32_t member3641_{};
    std::int32_t member3642_{};
    std::int32_t member3643_{};
    std::int32_t member3644_{};
    std::int32_t member3645_{};
    std::int32_t member3646_{};
    std::int32_t member3648_{};
    std::int32_t member3649_{};
    IntRef member3650_{};
    std::array<std::uint8_t, 40> member3652_{};
    std::array<std::int8_t, 11> member3654_{};
    std::array<std::int8_t, 11> member3656_{};
    std::array<std::uint8_t, 4> member3658_{};
    std::array<std::uint8_t, 20> member3660_{};
    std::array<std::uint8_t, 20> member3662_{};
    std::int32_t member3664_{};
    std::int32_t member3665_{};
    std::int32_t member3666_{};
    std::int32_t member3667_{};
    std::int32_t member3668_{};
    std::int32_t member3669_{};
    std::int32_t member3670_{};
    std::int32_t member3671_{};
    std::int32_t member3672_{};
    std::int32_t member3673_{};
    std::int32_t member3674_{};
    std::int32_t member3675_{};
    std::int32_t member3676_{};
    std::int32_t member3677_{};
    std::int32_t member3678_{};
    std::array<std::int32_t, 8> member3680_{};
    IntRef member3682_{};
    std::int32_t member3683_{};
    std::int32_t member3684_{};
    std::array<std::uint8_t, 20> member3686_{};
    std::int32_t member3688_{};
    std::array<std::uint8_t, 10> member3689_{};
    std::array<std::uint8_t, 6> member3690_{};
    String member3691_{};
    std::array<std::uint8_t, 2> member3692_{};
    std::array<std::uint8_t, 9> member3693_{};
    std::array<std::uint8_t, 21> member3694_{};
    std::array<std::uint8_t, 1> member3695_{};
    std::array<std::uint8_t, 8> member3696_{};
    std::array<std::uint8_t, 16> member3697_{};
    std::array<std::uint8_t, 5> member3698_{};
    std::array<std::uint8_t, 18> member3699_{};
    std::array<std::uint8_t, 8> member3700_{};
    std::array<std::uint8_t, 2> member3701_{};
    std::array<std::uint8_t, 2> member3702_{};
    std::array<std::uint8_t, 3> member3703_{};
    std::array<std::uint8_t, 3> member3704_{};
    std::array<std::uint8_t, 3> member3705_{};
    std::array<std::uint8_t, 3> member3706_{};
    std::array<std::uint8_t, 4> member3707_{};
    std::array<std::uint8_t, 1> member3708_{};
    std::array<std::uint8_t, 3> member3709_{};
    std::array<std::uint8_t, 3> member3710_{};
    std::array<std::uint8_t, 3> member3711_{};
    std::array<std::uint8_t, 8> member3712_{};
    std::array<std::uint8_t, 20> member3713_{};
    std::array<std::uint8_t, 9> member3714_{};
    std::array<std::uint8_t, 5> member3715_{};
    std::array<std::uint8_t, 6> member3716_{};
    std::array<std::uint8_t, 29> member3717_{};
    std::array<std::uint8_t, 9> member3718_{};
    std::int32_t member3719_{};
    std::int32_t member3720_{};
    std::int32_t member3721_{};
    std::int32_t member3722_{};
    std::int32_t member3723_{};
    float member3724_{};
    float member3725_{};
    float member3726_{};
    float member3727_{};
    std::int32_t member3728_{};
    std::int32_t member3729_{};
    std::int32_t member3730_{};
    std::int32_t member3731_{};
    std::int32_t member3732_{};
    float member3733_{};
    float member3734_{};
    float member3735_{};
    float member3736_{};
    float member3737_{};
    std::array<std::uint8_t, 9> member3738_{};
    std::array<std::uint8_t, 8> member3739_{};
    std::array<std::uint8_t, 8> member3740_{};
    std::array<std::uint8_t, 10> member3741_{};
    std::int32_t member3742_{};
    std::int32_t member3744_{};
    String member3745_{};
    std::array<std::uint8_t, 7> member3746_{};
    std::array<std::uint8_t, 29> member3747_{};
    String member3748_{};
    std::array<std::uint8_t, 6> member3749_{};
    std::array<std::int32_t, 20> member3751_{};
    std::int32_t member3753_{};
    std::int32_t member3754_{};
    std::int32_t member3755_{};
    std::int32_t member3756_{};
    std::int32_t member3757_{};
    std::int32_t member3758_{};
    std::array<std::uint8_t, 10> member3759_{};
    std::array<std::uint8_t, 8> member3760_{};
    std::array<std::uint8_t, 9> member3761_{};
    std::array<std::uint8_t, 9> member3762_{};
    std::int32_t member3763_{};
    std::int32_t member3764_{};
    std::int32_t member3765_{};
    std::int32_t member3766_{};
    std::int32_t member3767_{};
    std::int32_t member3769_{};
    std::int32_t member3770_{};
    std::int32_t member3772_{};
    std::int32_t member3774_{};
    std::int32_t member3775_{};
    std::int32_t member3776_{};
    std::int32_t member3777_{};
    std::int32_t member3778_{};
    std::int32_t member3779_{};
    std::int32_t member3780_{};
    std::int32_t member3781_{};
    std::int32_t member3782_{};
    std::int32_t member3783_{};
    std::int32_t member3784_{};
    std::int32_t member3785_{};
    std::int32_t member3786_{};
    std::int32_t member3787_{};
    std::int32_t member3788_{};
    std::array<std::int32_t, 10> member3790_{};
    std::int32_t member3792_{};
    std::int32_t member3793_{};
    std::int32_t member3794_{};
    std::int32_t member3795_{};
    std::int32_t member3796_{};
    std::int32_t member3797_{};
    std::int32_t member3798_{};
    std::int32_t member3799_{};
    std::int32_t member3800_{};
    std::int32_t member3801_{};
    std::int32_t member3802_{};
    std::int32_t member3803_{};
    std::int32_t member3804_{};
    std::int32_t member3805_{};
    std::int32_t member3806_{};
    std::int32_t member3807_{};
    std::int32_t member3808_{};
    IntRef member3809_{};
    IntRef member3810_{};
    float member3811_{};
    float member3812_{};
    float member3813_{};
    float member3814_{};
    float member3815_{};
    Address member3816_{};
    float member3817_{};
    float member3818_{};
    std::int32_t member3819_{};
    std::array<std::uint8_t, 13> member3821_{};
    std::array<std::uint8_t, 13> member3822_{};
    std::array<std::uint8_t, 8> member3823_{};
    std::array<std::uint8_t, 8> member3824_{};
    std::array<std::uint8_t, 9> member3825_{};
    std::int8_t member3826_{};
    std::array<std::uint8_t, 8> member3827_{};
    std::array<std::uint8_t, 8> member3828_{};
    String member3829_{};
    std::array<std::uint8_t, 7> member3830_{};
    std::array<std::uint8_t, 29> member3831_{};
    String member3832_{};
    std::array<std::uint8_t, 9> member3833_{};
    std::array<std::uint8_t, 8> member3834_{};
    std::array<std::uint8_t, 10> member3835_{};
    std::array<std::uint8_t, 5> member3836_{};
    std::array<std::uint8_t, 4> member3837_{};
    std::array<std::uint8_t, 1> member3838_{};
    std::array<std::uint8_t, 20> member3839_{};
    std::array<std::uint8_t, 13> member3840_{};
    std::array<std::uint8_t, 13> member3841_{};
    std::array<std::uint8_t, 13> member3842_{};
    std::array<std::uint8_t, 10> member3843_{};
    std::int32_t member3845_{};
    std::int32_t member3846_{};
    std::int32_t member3847_{};
    std::array<std::uint8_t, 2> member3848_{};
    std::array<std::uint8_t, 1> member3849_{};
    std::array<std::uint8_t, 1> member3850_{};
    String member3851_{};
    std::array<std::uint8_t, 15> member3852_{};
    std::array<std::uint8_t, 13> member3853_{};
    std::array<std::uint8_t, 16> member3854_{};
    std::array<std::uint8_t, 17> member3855_{};
    std::int32_t member3856_{};
    FloatRef member3857_{};
    FloatRef member3858_{};
    std::int32_t member3860_{};
    std::int32_t member3861_{};
    std::array<Address, 2> member3862_{};
    std::array<std::uint8_t, 20> member3863_{};
    std::int32_t member3864_{};
    std::int32_t member3865_{};
    std::int32_t member3866_{};
    std::int32_t member3867_{};
    std::int32_t member3868_{};
    std::int32_t member3869_{};
    std::int32_t member3870_{};
    std::int32_t member3872_{};
    std::int32_t member3873_{};
    std::int32_t member3874_{};
    std::int32_t member3875_{};
    std::int32_t member3876_{};
    std::int32_t member3877_{};
    std::int32_t member3878_{};
    std::int32_t member3880_{};
    String member3881_{};
    String member3882_{};
    std::array<std::uint8_t, 9> member3883_{};
    std::array<std::uint8_t, 5> member3884_{};
    std::array<std::uint8_t, 29> member3885_{};
    std::array<std::uint8_t, 13> member3886_{};
    std::array<std::uint8_t, 9> member3887_{};
    std::array<std::uint8_t, 1> member3888_{};
    std::int32_t member3890_{};
    std::int32_t member3891_{};
    std::int32_t member3892_{};
    std::int32_t member3893_{};
    String member3894_{};
    std::array<std::uint8_t, 9> member3895_{};
    std::array<std::uint8_t, 5> member3896_{};
    std::int32_t member3897_{};
    String member3898_{};
    std::int32_t member3899_{};
    String member3901_{};
    std::int32_t member3902_{};
    String member3903_{};
    std::array<std::uint8_t, 9> member3904_{};
    std::array<std::uint8_t, 5> member3905_{};
    std::array<std::uint8_t, 6> member3906_{};
    std::array<std::uint8_t, 6> member3907_{};
    std::int32_t member3909_{};
    std::int32_t member3910_{};
    std::int32_t member3911_{};
    std::int32_t member3912_{};
    std::int32_t member3913_{};
    std::int32_t member3914_{};
    std::int32_t member3915_{};
    std::int32_t member3916_{};
    std::int32_t member3917_{};
    std::int32_t member3918_{};
    std::int32_t member3919_{};
    String member3920_{};
    std::int32_t member3921_{};
    std::int32_t member3922_{};
    std::int32_t member3923_{};
    std::int32_t member3924_{};
    std::int32_t member3925_{};
    std::array<std::int32_t, 20> member3927_{};
    std::int32_t member3929_{};
    std::int32_t member3930_{};
    String member3931_{};
    std::int32_t member3932_{};
    std::int32_t member3933_{};
    std::int32_t member3934_{};
    std::int32_t member3935_{};
    float member3937_{};
    float member3938_{};
    std::int32_t member3939_{};
    std::array<std::uint8_t, 128> member3941_{};
    std::int32_t member3943_{};
    std::int32_t member3944_{};
    std::array<std::uint8_t, 9> member3945_{};
    std::array<std::uint8_t, 1> member3946_{};
    std::int32_t member3947_{};
    String member3948_{};
    std::int32_t member3949_{};
    std::int32_t member3950_{};
    std::int32_t member3951_{};
    std::int32_t member3953_{};
    std::int32_t member3954_{};
    std::int32_t member3955_{};
    std::int32_t member3956_{};
    std::int32_t member3957_{};
    std::array<std::uint8_t, 20> member3959_{};
    std::array<std::uint8_t, 8> member3961_{};
    std::array<std::uint8_t, 11> member3962_{};
    std::int32_t member3963_{};
    String member3964_{};
    std::int32_t member3966_{};
    std::int32_t member3967_{};
    std::int32_t member3968_{};
    std::int32_t member3969_{};
    std::int32_t member3971_{};
    std::array<std::uint8_t, 20> member3973_{};
    std::array<std::uint8_t, 20> member3975_{};
    std::array<String, 3> member3977_{};
    String member3979_{};
    String member3980_{};
    std::int32_t member3982_{};
    std::int32_t member3983_{};
    std::int32_t member3985_{};
    std::int32_t member3987_{};
    std::int32_t member3988_{};
    std::int32_t member3989_{};
    std::int32_t member3990_{};
    std::int32_t member3992_{};
    std::array<std::int32_t, 5> member3994_{};
    std::int32_t member3996_{};
    IntRef member3997_{};
    std::array<std::uint8_t, 9> member3998_{};
    std::array<std::uint8_t, 9> member3999_{};
    std::array<std::uint8_t, 9> member4000_{};
    std::array<std::uint8_t, 5> member4001_{};
    std::int32_t member4002_{};
    std::int32_t member4003_{};
    std::int32_t member4004_{};
    std::int32_t member4005_{};
    String member4006_{};
    std::array<std::uint8_t, 20> member4008_{};
    std::array<std::uint8_t, 17> member4010_{};
    std::array<std::uint8_t, 8> member4011_{};
    std::array<std::uint8_t, 6> member4012_{};
    std::array<std::uint8_t, 9> member4013_{};
    std::int32_t member4014_{};
    String member4015_{};
    std::int32_t member4016_{};
    std::int32_t member4017_{};
    std::array<std::uint8_t, 20> member4019_{};
    std::int8_t member4021_{};
    std::int32_t member4023_{};
    std::array<std::uint8_t, 21> member4024_{};
    std::int32_t member4026_{};
    std::int32_t member4028_{};
    std::int32_t member4029_{};
    std::int32_t member4030_{};
    std::int32_t member4031_{};
    std::int32_t member4033_{};
    std::array<std::uint8_t, 20> member4035_{};
    std::array<String, 5> member4037_{};
    String member4039_{};
    IntRef member4040_{};
    IntRef member4041_{};
    std::int32_t member4042_{};
    std::int32_t member4043_{};
    std::int32_t member4045_{};
    std::int32_t member4046_{};
    std::int32_t member4048_{};
    std::int32_t member4049_{};
    Address member4050_{};
    Address member4051_{};
    std::int32_t member4052_{};
    std::int32_t member4053_{};
    std::int32_t member4054_{};
    std::int32_t member4055_{};
    std::int32_t member4056_{};
    std::int32_t member4057_{};
    std::array<std::int32_t, 5> member4059_{};
    std::int32_t member4061_{};
    IntRef member4062_{};
    std::int32_t member4063_{};
    std::array<std::uint8_t, 9> member4064_{};
    std::array<std::uint8_t, 9> member4065_{};
    std::array<std::uint8_t, 9> member4066_{};
    std::array<std::uint8_t, 9> member4067_{};
    std::array<std::uint8_t, 9> member4068_{};
    std::array<std::uint8_t, 8> member4069_{};
    std::array<std::uint8_t, 5> member4070_{};
    std::array<std::uint8_t, 8> member4071_{};
    std::array<std::uint8_t, 8> member4072_{};
    std::array<std::uint8_t, 8> member4073_{};
    std::int32_t member4075_{};
    std::int32_t member4076_{};
    std::int32_t member4077_{};
    std::int32_t member4078_{};
    std::array<std::uint8_t, 18> member4079_{};
    std::int32_t member4081_{};
    std::int32_t member4082_{};
    std::int32_t member4083_{};
    std::array<std::uint8_t, 8> member4084_{};
    std::int32_t member4085_{};
    std::int32_t member4086_{};
    std::int32_t member4087_{};
    std::array<std::uint8_t, 9> member4088_{};
    std::array<std::uint8_t, 10> member4089_{};
    std::int32_t member4091_{};
    std::int32_t member4092_{};
    std::array<std::int32_t, 10> member4094_{};
    std::int32_t member4096_{};
    std::int32_t member4097_{};
    std::int32_t member4098_{};
    std::int32_t member4099_{};
    std::array<std::int32_t, 5> member4101_{};
    std::int32_t member4103_{};
    std::int32_t member4105_{};
    std::int32_t member4106_{};
    std::int32_t member4107_{};
    std::array<std::uint8_t, 6> member4108_{};
    std::array<std::uint8_t, 8> member4109_{};
    std::array<std::uint8_t, 8> member4110_{};
    std::int32_t member4112_{};
    std::int32_t member4113_{};
    std::array<std::uint8_t, 8> member4114_{};
    std::array<std::uint8_t, 8> member4115_{};
    std::array<std::uint8_t, 18> member4116_{};
    std::array<std::uint8_t, 8> member4117_{};
    String member4118_{};
    std::array<std::uint8_t, 23> member4119_{};
    std::array<std::uint8_t, 19> member4120_{};
    String member4121_{};
    std::array<std::uint8_t, 8> member4122_{};
    std::array<std::uint8_t, 8> member4123_{};
    std::int32_t member4124_{};
    std::int32_t member4125_{};
    std::int32_t member4126_{};
    std::int32_t member4127_{};
    std::array<String, 3> member4129_{};
    std::array<std::uint8_t, 9> member4131_{};
    std::array<std::uint8_t, 9> member4132_{};
    std::array<std::uint8_t, 9> member4133_{};
    std::int32_t member4134_{};
    std::int32_t member4135_{};
    std::int32_t member4136_{};
    std::int32_t member4137_{};
    std::int32_t member4138_{};
    std::int32_t member4139_{};
    std::int32_t member4140_{};
    std::int32_t member4141_{};
    std::array<std::uint8_t, 20> member4143_{};
    std::array<std::uint8_t, 8> member4145_{};
    std::array<std::uint8_t, 18> member4146_{};
    std::array<std::uint8_t, 18> member4147_{};
    std::int32_t member4149_{};
    std::int32_t member4150_{};
    std::array<std::uint8_t, 8> member4151_{};
    std::array<std::uint8_t, 8> member4152_{};
    std::int32_t member4153_{};
    IntRef member4154_{};
    std::int32_t member4155_{};
    std::int32_t member4156_{};
    std::int32_t member4157_{};
    std::int32_t member4158_{};
    std::int32_t member4159_{};
    std::int32_t member4160_{};
    std::int32_t member4161_{};
    std::int32_t member4162_{};
    std::int32_t member4163_{};
    std::int32_t member4164_{};
    std::int32_t member4165_{};
    std::int32_t member4166_{};
    std::int32_t member4167_{};
    std::int32_t member4168_{};
    std::int32_t member4169_{};
    std::int32_t member4170_{};
    std::int32_t member4171_{};
    std::int32_t member4172_{};
    std::int32_t member4173_{};
    std::int32_t member4174_{};
    std::int32_t member4175_{};
    std::int32_t member4176_{};
    std::int32_t member4177_{};
    std::int32_t member4178_{};
    std::int32_t member4179_{};
    std::int32_t member4180_{};
    std::int32_t member4181_{};
    std::array<std::int32_t, 8> member4183_{};
    std::int32_t member4185_{};
    std::array<std::uint8_t, 16> member4187_{};
    std::array<std::int32_t, 8> member4189_{};
    std::int32_t member4191_{};
    std::int32_t member4192_{};
    std::int32_t member4193_{};
    std::array<std::uint8_t, 32> member4195_{};
    IntRef member4197_{};
    std::int32_t member4198_{};
    String member4199_{};
    std::array<std::uint8_t, 32> member4201_{};
    std::array<std::uint8_t, 11> member4203_{};
    std::array<std::uint8_t, 9> member4204_{};
    std::array<std::uint8_t, 8> member4205_{};
    std::array<std::uint8_t, 2> member4206_{};
    std::array<std::uint8_t, 2> member4207_{};
    std::array<std::uint8_t, 2> member4208_{};
    std::array<std::uint8_t, 2> member4209_{};
    String member4210_{};
    std::array<std::uint8_t, 3> member4211_{};
    std::array<std::uint8_t, 3> member4212_{};
    std::array<std::uint8_t, 8> member4213_{};
    std::array<std::uint8_t, 3> member4214_{};
    std::array<std::uint8_t, 3> member4215_{};
    std::array<std::uint8_t, 4> member4216_{};
    std::array<std::uint8_t, 1> member4217_{};
    std::array<std::uint8_t, 6> member4218_{};
    std::int32_t member4219_{};
    std::array<std::uint8_t, 3> member4220_{};
    std::array<std::uint8_t, 3> member4221_{};
    std::int32_t member4222_{};
    std::int32_t member4223_{};
    String member4224_{};
    std::int32_t member4225_{};
    std::int32_t member4226_{};
    std::int32_t member4227_{};
    std::int32_t member4228_{};
    std::int32_t member4229_{};
    std::int32_t member4230_{};
    std::int32_t member4232_{};
    std::int32_t member4233_{};
    std::int32_t member4234_{};
    std::int32_t member4235_{};
    std::int32_t member4236_{};
    std::int32_t member4237_{};
    std::array<std::uint8_t, 14> member4239_{};
    std::array<std::uint8_t, 4> member4241_{};
    std::array<std::uint8_t, 6> member4242_{};
    std::array<std::uint8_t, 5> member4243_{};
    std::array<std::uint8_t, 10> member4244_{};
    std::array<std::uint8_t, 7> member4245_{};
    std::array<std::uint8_t, 8> member4246_{};
    std::array<std::uint8_t, 5> member4247_{};
    std::array<std::uint8_t, 6> member4248_{};
    std::array<std::uint8_t, 3> member4249_{};
    std::array<std::uint8_t, 8> member4250_{};
    std::array<std::uint8_t, 5> member4251_{};
    std::array<std::uint8_t, 5> member4252_{};
    std::array<std::uint8_t, 5> member4253_{};
    std::array<std::uint8_t, 5> member4254_{};
    std::int32_t member4255_{};
    float member4257_{};
    float member4258_{};
    float member4259_{};
    float member4260_{};
    std::array<std::uint8_t, 512> member4262_{};
    String member4264_{};
    std::int8_t member4265_{};
    std::int8_t member4266_{};
    std::int32_t member4268_{};
    std::int32_t member4269_{};
    std::int32_t member4270_{};
    std::int32_t member4271_{};
    std::int32_t member4272_{};
    std::int32_t member4273_{};
    std::int32_t member4274_{};
    std::int32_t member4275_{};
    std::int32_t member4277_{};
    float member4278_{};
    float member4279_{};
    float member4280_{};
    float member4281_{};
    String member4282_{};
    std::int32_t member4283_{};
    String member4284_{};
    std::int32_t member4285_{};
    IntRef member4286_{};
    IntRef member4287_{};
    IntRef member4288_{};
    std::int32_t member4289_{};
    std::int32_t member4290_{};
    IntRef member4292_{};
    IntRef member4293_{};
    IntRef member4294_{};
    IntRef member4295_{};
    std::int32_t member4296_{};
    IntRef member4297_{};
    std::int32_t member4299_{};
    std::array<std::int32_t, 20> member4301_{};
    std::int32_t member4303_{};
    std::int32_t member4304_{};
    std::int32_t member4305_{};
    std::int32_t member4306_{};
    std::int32_t member4307_{};
    std::int32_t member4308_{};
    std::int32_t member4309_{};
    std::int32_t member4310_{};
    std::int32_t member4312_{};
    std::int32_t member4313_{};
    std::int32_t member4314_{};
    std::array<std::uint8_t, 64> member4316_{};
    std::int32_t member4318_{};
    std::int32_t member4319_{};
    std::int32_t member4320_{};
    std::int32_t member4321_{};
    std::int32_t member4322_{};
    std::int32_t member4324_{};
    std::int32_t member4326_{};
    std::int32_t member4327_{};
    std::int32_t member4329_{};
    std::int32_t member4330_{};
    std::array<std::uint8_t, 1024> member4332_{};
    std::array<std::uint8_t, 64> member4334_{};
    String member4336_{};
    std::array<std::uint8_t, 128> member4338_{};
    String member4340_{};
    std::array<std::uint8_t, 11> member4341_{};
    std::array<std::uint8_t, 9> member4342_{};
    String member4343_{};
    std::array<std::uint8_t, 9> member4344_{};
    String member4345_{};
    std::int32_t member4347_{};
    String member4348_{};
    std::array<std::uint8_t, 8> member4349_{};
    std::array<std::uint8_t, 21> member4350_{};
    std::array<std::uint8_t, 11> member4351_{};
    std::array<std::uint8_t, 13> member4352_{};
    std::array<std::uint8_t, 21> member4353_{};
    std::array<std::uint8_t, 11> member4354_{};
    String member4355_{};
    std::array<std::uint8_t, 21> member4356_{};
    String member4357_{};
    std::array<std::uint8_t, 5> member4358_{};
    std::array<std::uint8_t, 3> member4359_{};
    float member4361_{};
    float member4362_{};
    std::int32_t member4363_{};
    std::int32_t member4364_{};
    std::int32_t member4365_{};
    std::int32_t member4366_{};
    std::array<std::uint8_t, 8> member4367_{};
    std::array<std::uint8_t, 13> member4368_{};
    std::array<std::uint8_t, 1> member4369_{};
    std::array<std::uint8_t, 3> member4370_{};
    String member4371_{};
    std::array<std::uint8_t, 5> member4372_{};
    std::array<std::uint8_t, 3> member4373_{};
    std::array<std::uint8_t, 4> member4374_{};
    std::array<std::uint8_t, 1> member4375_{};
    std::array<std::uint8_t, 1> member4376_{};
    std::array<std::uint8_t, 1> member4377_{};
    std::int32_t member4378_{};
    std::int32_t member4379_{};
    std::int32_t member4381_{};
    std::array<std::int32_t, 10> member4383_{};
    std::array<std::int32_t, 10> member4385_{};
    std::int32_t member4387_{};
    std::int32_t member4388_{};
    std::int32_t member4389_{};
    std::int32_t member4390_{};
    std::int32_t member4391_{};
    std::int32_t member4392_{};
    std::int32_t member4393_{};
    std::array<std::int32_t, 20> member4395_{};
    std::int32_t member4397_{};
    std::int32_t member4398_{};
    std::int32_t member4399_{};
    std::int32_t member4400_{};
    std::int32_t member4401_{};
    std::int32_t member4402_{};
    std::int32_t member4403_{};
    std::int32_t member4404_{};
    std::int32_t member4405_{};
    std::array<std::int32_t, 32> member4407_{};
    std::int32_t member4409_{};
    std::int32_t member4410_{};
    std::array<std::uint8_t, 20> member4412_{};
    std::int32_t member4414_{};
    std::int32_t member4415_{};
    String member4416_{};
    std::array<std::uint8_t, 9> member4417_{};
    std::array<std::uint8_t, 9> member4418_{};
    String member4419_{};
    std::array<std::uint8_t, 8> member4420_{};
    std::array<std::uint8_t, 8> member4421_{};
    std::array<std::uint8_t, 9> member4422_{};
    std::array<std::uint8_t, 7> member4423_{};
    std::array<std::uint8_t, 9> member4424_{};
    std::array<std::uint8_t, 11> member4425_{};
    String member4426_{};
    std::array<std::uint8_t, 21> member4427_{};
    std::array<std::uint8_t, 10> member4428_{};
    String member4429_{};
    std::array<std::uint8_t, 10> member4430_{};
    std::array<std::uint8_t, 10> member4431_{};
    String member4432_{};
    std::int32_t member4434_{};
    IntRef member4436_{};
    std::int32_t member4438_{};
    std::int32_t member4439_{};
    std::int32_t member4440_{};
    std::int32_t member4442_{};
    std::int32_t member4444_{};
    std::int32_t member4448_{};
    std::array<std::int32_t, 32> member4450_{};
    std::int32_t member4452_{};
    std::int32_t member4454_{};
    std::int32_t member4456_{};
    std::int32_t member4457_{};
    std::array<std::uint8_t, 20> member4459_{};
    std::array<std::uint8_t, 1024> member4461_{};
    std::array<std::uint8_t, 64> member4463_{};
    std::int32_t member4465_{};
    std::int32_t member4466_{};
    std::array<std::int32_t, 20> member4468_{};
    std::int32_t member4470_{};
    std::array<std::uint8_t, 8> member4471_{};
    std::array<std::uint8_t, 9> member4472_{};
    std::array<std::uint8_t, 7> member4473_{};
    std::array<std::uint8_t, 9> member4474_{};
    String member4475_{};
    String member4476_{};
    std::array<std::uint8_t, 9> member4477_{};
    String member4478_{};
    std::array<std::uint8_t, 7> member4479_{};
    std::array<std::uint8_t, 9> member4480_{};
    std::array<std::uint8_t, 11> member4481_{};
    String member4482_{};
    std::array<std::uint8_t, 21> member4483_{};
    std::array<std::uint8_t, 10> member4484_{};
    String member4485_{};
    std::array<std::uint8_t, 10> member4486_{};
    std::array<std::uint8_t, 8> member4487_{};
    String member4488_{};
    std::array<std::uint8_t, 5> member4489_{};
    std::array<std::uint8_t, 6> member4490_{};
    std::int32_t member4496_{};
    std::array<std::uint8_t, 10> member4499_{};
    std::int32_t member4501_{};
    std::int32_t member4502_{};
    std::int32_t member4503_{};
    std::int32_t member4504_{};
    std::int32_t member4505_{};
    std::int32_t member4506_{};
    std::int32_t member4507_{};
    String member4508_{};
    std::int32_t member4509_{};
    std::array<std::uint8_t, 8> member4510_{};
    std::array<std::uint8_t, 8> member4511_{};
    std::array<std::uint8_t, 8> member4512_{};
    std::int32_t member4513_{};
    float member4514_{};
    std::array<std::uint8_t, 11> member4515_{};
    std::int32_t member4516_{};
    float member4518_{};
    std::int32_t member4519_{};
    std::int32_t member4520_{};
    std::int32_t member4521_{};
    std::int32_t member4522_{};
    float member4523_{};
    float member4524_{};
    float member4525_{};
    float member4526_{};
    std::int32_t member4527_{};
    float member4528_{};
    std::int32_t member4529_{};
    std::int32_t member4530_{};
    std::array<std::uint8_t, 4> member4531_{};
    String member4532_{};
    std::array<std::uint8_t, 5> member4533_{};
    std::int32_t member4535_{};
    float member4536_{};
    float member4537_{};
    float member4538_{};
    float member4539_{};
    std::int32_t member4540_{};
    std::int32_t member4541_{};
    std::array<std::uint8_t, 9> member4542_{};
    std::int32_t member4544_{};
    std::int32_t member4545_{};
    std::array<std::uint8_t, 1> member4546_{};
    std::array<std::uint8_t, 7> member4547_{};
    float member4548_{};
    std::int32_t member4549_{};
    std::int32_t member4550_{};
    std::array<std::uint8_t, 9> member4551_{};
    std::array<std::uint8_t, 9> member4552_{};
    std::array<std::uint8_t, 11> member4553_{};
    std::array<std::uint8_t, 9> member4554_{};
    std::int32_t member4556_{};
    std::array<std::uint8_t, 9> member4557_{};
    std::array<std::uint8_t, 13> member4558_{};
    std::array<std::uint8_t, 21> member4559_{};
    std::array<std::uint8_t, 10> member4560_{};
    std::array<std::uint8_t, 1> member4561_{};
    std::array<std::uint8_t, 4> member4562_{};
    std::int32_t member4563_{};
    std::int32_t member4565_{};
    std::array<std::uint8_t, 10> member4566_{};
    Address member4568_{};
    float member4569_{};
    float member4570_{};
    float member4571_{};
    std::int32_t member4572_{};
    std::int32_t member4573_{};
    String member4574_{};
    std::int32_t member4575_{};
    std::array<std::uint8_t, 9> member4576_{};
    std::int32_t member4578_{};
    std::int32_t member4579_{};
    std::int32_t member4580_{};
    std::array<std::uint8_t, 4> member4581_{};
    std::int32_t member4582_{};
    std::int32_t member4583_{};
    std::int32_t member4584_{};
    std::int32_t member4585_{};
    std::int32_t member4586_{};
    std::int32_t member4587_{};
    std::array<std::uint8_t, 9> member4588_{};
    String member4589_{};
    std::int32_t member4590_{};
    std::int32_t member4591_{};
    std::int32_t member4593_{};
    std::array<std::uint8_t, 8> member4594_{};
    std::array<std::uint8_t, 11> member4595_{};
    std::int32_t member4596_{};
    std::int32_t member4597_{};
    std::int32_t member4598_{};
    float member4600_{};
    std::array<std::uint8_t, 9> member4601_{};
    std::array<std::uint8_t, 9> member4602_{};
    std::array<std::uint8_t, 9> member4603_{};
    Address member4605_{};
    Address member4606_{};
    Address member4607_{};
    float member4608_{};
    std::array<std::uint8_t, 14> member4609_{};
    std::int32_t member4611_{};
    std::int32_t member4612_{};
    std::int32_t member4613_{};
    std::int32_t member4614_{};
    std::array<std::uint8_t, 16> member4615_{};
    std::int32_t member4616_{};
    std::int32_t member4617_{};
    float member4618_{};
    std::array<std::uint8_t, 9> member4619_{};
    std::int32_t member4621_{};
    std::int32_t member4622_{};
    std::array<std::uint8_t, 18> member4623_{};
    std::array<std::uint8_t, 8> member4624_{};
    std::int32_t member4626_{};
    std::int32_t member4627_{};
    std::int32_t member4628_{};
    std::array<std::uint8_t, 8> member4629_{};
    std::array<std::uint8_t, 21> member4630_{};
    std::array<std::uint8_t, 18> member4631_{};
    std::array<std::uint8_t, 35> member4632_{};
    std::array<std::uint8_t, 14> member4633_{};
    std::int32_t member4634_{};
    std::int32_t member4635_{};
    std::int32_t member4636_{};
    std::int32_t member4637_{};
    std::int32_t member4638_{};
    std::int32_t member4639_{};
    std::int32_t member4640_{};
    std::int32_t member4641_{};
    std::array<std::uint8_t, 6> member4642_{};
    std::int32_t member4643_{};
    std::int32_t member4644_{};
    std::int32_t member4646_{};
    std::int32_t member4647_{};
    std::int32_t member4648_{};
    std::int32_t member4649_{};
    std::int32_t member4650_{};
    std::int32_t member4651_{};
    std::int32_t member4652_{};
    std::int32_t member4653_{};
    std::int32_t member4654_{};
    std::int32_t member4655_{};
    float member4656_{};
    std::int32_t member4657_{};
    std::int32_t member4658_{};
    std::array<std::uint8_t, 8> member4659_{};
    float member4660_{};
    std::array<std::uint8_t, 14> member4661_{};
    String member4662_{};
    std::int32_t member4664_{};
    std::array<std::uint8_t, 8> member4665_{};
    std::array<std::uint8_t, 9> member4666_{};
    std::array<std::uint8_t, 9> member4667_{};
    std::array<std::uint8_t, 1> member4668_{};
    std::array<std::uint8_t, 1> member4669_{};
    std::int32_t member4670_{};
    std::int32_t member4671_{};
    std::int32_t member4672_{};
    std::int32_t member4674_{};
    std::int32_t member4675_{};
    std::int32_t member4676_{};
    std::int32_t member4677_{};
    std::int32_t member4679_{};
    std::array<std::uint8_t, 5> member4680_{};
    std::array<std::uint8_t, 8> member4681_{};
    std::array<std::uint8_t, 14> member4682_{};
    std::array<std::uint8_t, 7> member4683_{};
    std::array<std::uint8_t, 8> member4684_{};
    std::int32_t member4686_{};
    std::int32_t member4687_{};
    std::int32_t member4688_{};
    std::int32_t member4689_{};
    std::int32_t member4690_{};
    std::int32_t member4691_{};
    std::int32_t member4692_{};
    std::int32_t member4693_{};
    std::int32_t member4694_{};
    std::int32_t member4695_{};
    std::int32_t member4696_{};
    std::array<std::uint8_t, 30> member4698_{};
    std::int32_t member4700_{};
    std::array<std::uint8_t, 7> member4701_{};
    std::array<std::uint8_t, 9> member4702_{};
    std::array<std::uint8_t, 8> member4703_{};
    std::array<std::uint8_t, 6> member4704_{};
    String member4705_{};
    std::array<std::uint8_t, 5> member4706_{};
    std::array<std::uint8_t, 8> member4707_{};
    std::array<std::uint8_t, 14> member4708_{};
    std::array<std::uint8_t, 6> member4709_{};
    String member4710_{};
    std::array<std::uint8_t, 1> member4711_{};
    String member4712_{};
    std::array<std::uint8_t, 5> member4713_{};
    std::array<std::uint8_t, 29> member4714_{};
    std::array<std::uint8_t, 8> member4715_{};
    std::int32_t member4716_{};
    std::int32_t member4718_{};
    std::int32_t member4719_{};
    std::int32_t member4720_{};
    std::int32_t member4721_{};
    std::array<std::uint8_t, 50> member4723_{};
    std::int32_t member4725_{};
    std::int32_t member4726_{};
    std::int32_t member4727_{};
    String member4729_{};
    String member4731_{};
    String member4732_{};
    std::int32_t member4733_{};
    std::int32_t member4734_{};
    std::int32_t member4735_{};
    std::int32_t member4736_{};
    std::array<std::uint8_t, 9> member4737_{};
    std::array<std::uint8_t, 2> member4738_{};
    std::array<std::uint8_t, 29> member4739_{};
    std::array<std::uint8_t, 5> member4740_{};
    std::int32_t member4742_{};
    std::int32_t member4743_{};
    std::int32_t member4744_{};
    std::int32_t member4745_{};
    std::int32_t member4746_{};
    std::array<String, 125> member4748_{};
    std::array<std::uint8_t, 9> member4750_{};
    std::int32_t member4752_{};
    std::int32_t member4753_{};
    std::int32_t member4754_{};
    std::int32_t member4755_{};
    std::int32_t member4756_{};
    String member4757_{};
    std::array<std::uint8_t, 9> member4758_{};
    std::int32_t member4759_{};
    String member4760_{};
    std::int32_t member4761_{};
    std::int32_t member4762_{};
    String member4763_{};
    std::int32_t member4764_{};
    std::int32_t member4765_{};
    String member4766_{};
    std::int32_t member4767_{};
    String member4768_{};
    String member4769_{};
    std::int32_t member4770_{};
    std::int8_t member4771_{};
    String member4773_{};
    std::int32_t member4774_{};
    std::int32_t member4775_{};
    std::int32_t member4776_{};
    String member4777_{};
    String member4778_{};
    std::int32_t member4779_{};
    std::int32_t member4780_{};
    std::int32_t member4781_{};
    std::int32_t member4782_{};
    std::int32_t member4783_{};
    std::int32_t member4784_{};
    std::array<std::uint8_t, 9> member4785_{};
    std::array<std::uint8_t, 9> member4786_{};
    std::array<std::uint8_t, 9> member4787_{};
    std::array<std::uint8_t, 9> member4788_{};
    std::array<std::uint8_t, 7> member4789_{};
    std::array<std::uint8_t, 7> member4790_{};
    std::array<std::uint8_t, 8> member4791_{};
    std::array<std::uint8_t, 8> member4792_{};
    std::array<std::uint8_t, 8> member4793_{};
    std::array<std::uint8_t, 8> member4794_{};
    std::array<std::uint8_t, 10> member4795_{};
    std::array<std::uint8_t, 10> member4796_{};
    std::array<std::uint8_t, 10> member4797_{};
    std::array<std::uint8_t, 10> member4798_{};
    std::array<std::uint8_t, 10> member4799_{};
    std::array<std::uint8_t, 10> member4800_{};
    std::array<std::uint8_t, 10> member4801_{};
    std::array<std::uint8_t, 9> member4802_{};
    std::array<std::uint8_t, 9> member4803_{};
    std::array<std::uint8_t, 10> member4804_{};
    std::array<std::uint8_t, 10> member4805_{};
    std::array<std::uint8_t, 9> member4806_{};
    std::array<std::uint8_t, 9> member4807_{};
    std::array<std::uint8_t, 8> member4808_{};
    std::array<std::uint8_t, 10> member4809_{};
    std::array<std::uint8_t, 1> member4810_{};
    std::array<std::int32_t, 16> member4812_{};
    std::int32_t member4814_{};
    std::int32_t member4815_{};
    std::int32_t member4816_{};
    std::int32_t member4817_{};
    std::int32_t member4818_{};
    std::int32_t member4819_{};
    std::int32_t member4820_{};
    std::int32_t member4821_{};
    std::int32_t member4822_{};
    String member4823_{};
    String member4825_{};
    float member4826_{};
    float member4827_{};
    float member4828_{};
    std::array<std::int32_t, 15> member4830_{};
    std::int32_t member4832_{};
    std::array<std::uint8_t, 7> member4833_{};
    std::array<std::uint8_t, 6> member4834_{};
    float member4835_{};
    float member4836_{};
    String member4838_{};
    String member4839_{};
    String member4840_{};
    String member4841_{};
    std::int8_t member4842_{};
    std::int8_t member4843_{};
    std::array<std::uint8_t, 20> member4845_{};
    std::int32_t member4847_{};
    std::int32_t member4848_{};
    std::int32_t member4849_{};
    std::int32_t member4850_{};
    std::array<std::uint8_t, 10> member4851_{};
    std::array<std::uint8_t, 8> member4852_{};
    std::array<std::uint8_t, 7> member4853_{};
    std::array<std::uint8_t, 7> member4854_{};
    std::array<std::uint8_t, 7> member4855_{};
    std::array<std::uint8_t, 6> member4856_{};
    std::array<std::uint8_t, 6> member4857_{};
    std::array<std::uint8_t, 6> member4858_{};
    std::array<std::uint8_t, 5> member4859_{};
    std::array<std::uint8_t, 5> member4860_{};
    std::array<std::uint8_t, 4> member4861_{};
    std::array<String, 6> member4863_{};
    std::int32_t member4865_{};
    std::int32_t member4866_{};
    std::int32_t member4867_{};
    std::int32_t member4868_{};
    std::int32_t member4869_{};
    std::int32_t member4870_{};
    std::int32_t member4871_{};
    std::array<std::uint8_t, 2> member4873_{};
    std::int32_t member4874_{};
    std::array<std::uint8_t, 4> member4876_{};
    std::int32_t member4878_{};
    std::array<std::uint8_t, 80> member4880_{};
    std::int32_t member4882_{};
    std::int32_t member4883_{};
    std::int32_t member4884_{};
    std::int32_t member4886_{};
    std::array<std::uint8_t, 5> member4888_{};
    std::array<std::uint8_t, 8> member4889_{};
    std::array<std::uint8_t, 9> member4890_{};
    std::array<std::uint8_t, 21> member4891_{};
    std::array<std::uint8_t, 18> member4892_{};
    std::int32_t member4893_{};
    String member4894_{};
    std::int8_t member4895_{};
    std::int32_t member4897_{};
    std::int32_t member4898_{};
    std::int32_t member4899_{};
    std::int32_t member4900_{};
    std::int32_t member4901_{};
    std::int32_t member4902_{};
    std::array<std::uint8_t, 9> member4904_{};
    std::int32_t member4906_{};
    std::int32_t member4907_{};
    std::int8_t member4908_{};
    float member4910_{};
    float member4911_{};
    float member4912_{};
    float member4913_{};
    std::array<std::uint8_t, 22> member4914_{};
    std::int32_t member4915_{};
    std::int32_t member4916_{};
    std::int32_t member4917_{};
    String member4918_{};
    std::array<std::uint8_t, 10> member4919_{};
    std::array<std::uint8_t, 9> member4920_{};
    std::array<std::uint8_t, 10> member4921_{};
    std::array<std::uint8_t, 6> member4922_{};
    std::array<std::uint8_t, 20> member4924_{};
    std::array<std::uint8_t, 11> member4926_{};
    std::array<std::uint8_t, 10> member4927_{};
    std::array<std::uint8_t, 6> member4928_{};
    std::int32_t member4929_{};
    std::int32_t member4930_{};
    std::int8_t member4931_{};
    String member4933_{};
    std::int32_t member4934_{};
    float member4935_{};
    float member4936_{};
    float member4937_{};
    IntRef member4938_{};
    float member4939_{};
    float member4940_{};
    float member4941_{};
    std::int32_t member4942_{};
    Address member4943_{};
    float member4944_{};
    std::array<std::uint8_t, 8> member4945_{};
    String member4946_{};
    std::int8_t member4947_{};
    std::int32_t member4949_{};
    std::int32_t member4950_{};
    std::int32_t member4951_{};
    std::int32_t member4952_{};
    std::int32_t member4953_{};
    std::int32_t member4954_{};
    std::int32_t member4955_{};
    std::int8_t member4956_{};
    Address member4958_{};
    std::array<std::uint8_t, 256> member4960_{};
    String member4962_{};
    std::array<std::uint8_t, 21> member4963_{};
    std::array<std::uint8_t, 17> member4964_{};
    std::array<std::uint8_t, 21> member4965_{};
    std::int32_t member4966_{};
    Address member4967_{};
    std::array<std::uint8_t, 11> member4968_{};
    std::array<std::uint8_t, 29> member4969_{};
    std::array<std::uint8_t, 11> member4970_{};
    std::array<std::uint8_t, 15> member4971_{};
    std::int32_t member4972_{};
    std::int32_t member5016_{};
    std::int32_t member5017_{};
    std::int32_t member5018_{};
    std::int32_t member5019_{};
    String member5020_{};
    std::int32_t member5021_{};
    std::int32_t member5022_{};
    std::int32_t member5023_{};
    std::int32_t member5024_{};
    std::array<std::uint8_t, 152> member5025_{};
    AddressRef member5026_{};
    std::array<std::uint8_t, 11> member5027_{};
    AddressRef member5029_{};
    String member5030_{};
    std::int32_t member5031_{};
    std::int32_t member5032_{};
    std::array<std::uint8_t, 50> member5034_{};
    std::array<std::int32_t, 2> member5036_{};
    std::array<std::int32_t, 2> member5038_{};
    std::array<std::int32_t, 2> member5040_{};
    std::int32_t member5042_{};
    std::int32_t member5043_{};
    std::int32_t member5044_{};
    std::int32_t member5045_{};
    std::int32_t member5046_{};
    std::int32_t member5047_{};
    std::int32_t member5048_{};
    std::int32_t member5049_{};
    std::int32_t member5050_{};
    std::int32_t member5051_{};
    std::array<std::uint8_t, 9> member5052_{};
    String member5053_{};
    String member5054_{};
    String member5055_{};
    String member5056_{};
    std::array<std::uint8_t, 14> member5057_{};
    std::array<std::uint8_t, 14> member5058_{};
    std::int32_t member5060_{};
    std::int32_t member5061_{};
    std::array<std::uint8_t, 13> member5062_{};
    std::array<std::uint8_t, 16> member5063_{};
    std::array<std::uint8_t, 1> member5064_{};
    std::int32_t member5066_{};
    std::array<std::uint8_t, 16> member5067_{};
    String member5068_{};
    std::array<std::uint8_t, 1> member5069_{};
    std::array<std::uint8_t, 11> member5070_{};
    std::array<std::uint8_t, 11> member5071_{};
    std::array<std::uint8_t, 11> member5072_{};
    std::array<std::uint8_t, 11> member5073_{};
    std::array<std::uint8_t, 6> member5074_{};
    std::array<std::uint8_t, 6> member5075_{};
    std::int32_t member5077_{};
    std::array<std::uint8_t, 8> member5078_{};
    String member5079_{};
    std::int32_t member5080_{};
    std::array<std::uint8_t, 3> member5081_{};
    std::array<std::uint8_t, 3> member5082_{};
    std::array<std::uint8_t, 3> member5083_{};
    std::array<std::uint8_t, 1> member5084_{};
    std::array<std::uint8_t, 5> member5086_{};
    std::array<std::uint8_t, 5> member5088_{};
    std::array<std::uint8_t, 11> member5090_{};
    std::array<std::uint8_t, 11> member5091_{};
    std::array<std::uint8_t, 10> member5092_{};
    std::array<std::uint8_t, 16> member5094_{};
    std::int32_t member5095_{};
    String member5096_{};
    String member5097_{};
    std::int32_t member5098_{};
    std::array<std::uint8_t, 10> member5099_{};
    std::int32_t member5101_{};
    std::int32_t member5102_{};
    std::int32_t member5103_{};
    std::int32_t member5104_{};
    std::int32_t member5105_{};
    std::array<std::uint8_t, 16> member5106_{};
    std::int32_t member5107_{};
    String member5108_{};
    String member5109_{};
};

class MbcPlayer final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPlayer(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> main();
    Task<std::int32_t> ProcessConsole(std::int32_t parameter1, String parameter2);
    void SendConsole(String parameter1, std::int32_t parameter2, String parameter3);
    Task<Value> ShowConsoleFailure();
    Task<std::int32_t> __create_process2(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> __destroy_process2(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> __set_karma2(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> __set_name2(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> __cleanse_buffs2(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> __cleanse_viruses2(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> __kill_monsters2(std::int32_t parameter1, String parameter2);
    Task<void> Main_1stHelp();
    String GetActionName(std::int32_t parameter1);
    void CheckActionHelp(std::int32_t parameter1);
    std::int32_t ShowActionHelp(std::int32_t parameter1);
    std::int32_t GetBank();
    std::int32_t getMoney();
    Task<void> KeyAlarm();
    Task<void> CalcParamCli();
    Value InitObj();
    std::int32_t getPictName(String parameter1);
    std::int32_t GetParam(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, IntRef parameter4, IntRef parameter5, IntRef parameter6, IntRef parameter7, IntRef parameter8, IntRef parameter9, IntRef parameter10, IntRef parameter11);
    std::int32_t SetHealth(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4);
    std::int32_t SetParent(std::int32_t parameter1);
    std::int32_t GetABG(std::int32_t parameter1, AddressRef parameter2);
    Task<void> EInit();
    Value Recalc();
    Task<void> CycleSend();
    IntRef GetP(std::int32_t parameter1);
    Task<void> ShowKill();
    Task<void> ContMan();
    Task<void> TradeMan();
    Task<std::int32_t> SendOffer(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t GetPlName(std::int32_t parameter1, String parameter2);
    IntRef Params();
    std::int32_t GetObjCstlGuard();
    Task<void> ShowName();
    std::int32_t SetSpecab(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> CheckSpec();
    std::int32_t getCreatureLevel();
    std::int32_t SearchFreeSlotAndPut(std::int32_t parameter1);
    Task<std::int32_t> TestIt(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> SeekTag(std::int32_t parameter1);
    std::int32_t SeekTagInsideNoRecursive(std::int32_t parameter1);
    Task<std::int32_t> SetOverFill(std::int32_t parameter1);
    Task<std::int32_t> TestPut(std::int32_t parameter1);
    std::int32_t AddWght(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t FreeIt1(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    std::int32_t GetSlotID(std::int32_t parameter1);
    std::int32_t isSlotOccupied(std::int32_t parameter1);
    std::int32_t TestMe(std::int32_t parameter1);
    std::int32_t GetMySlot(std::int32_t parameter1);
    Task<void> RunClanEffect();
    Task<void> ClanEffect();
    Task<void> ContTOut();
    std::int32_t SendSys(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t SendSys2(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    std::int32_t SendSys3(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    std::int32_t SendSys4(std::int32_t parameter1, std::int32_t parameter2, String parameter3, std::int32_t parameter4);
    Task<std::int32_t> SayChat(String parameter1, std::int32_t parameter2);
    Task<std::int32_t> SRVC(std::int32_t parameter1, std::int32_t parameter2, String parameter3, String parameter4, std::int32_t parameter5);
    std::int32_t SOffer(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    std::int32_t SKeyAlarm();
    std::int32_t AskMemb(std::int32_t parameter1);
    Task<std::int32_t> SetClan(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    std::int32_t LostItem(std::int32_t parameter1);
    std::int32_t STW(std::int32_t parameter1);
    std::int32_t Paused();
    std::int32_t DHunger(std::int32_t parameter1);
    Task<std::int32_t> CalcRequirs(std::int32_t parameter1, IntRef parameter2, std::int32_t parameter3);
    std::int32_t GCIRange(std::int32_t parameter1);
    std::int32_t GCIID(std::int32_t parameter1);
    String GCIName(std::int32_t parameter1);
    Task<void> PrgMove();
    Task<std::int32_t> Teleport(float parameter1, float parameter2, float parameter3, float parameter4, std::int8_t parameter5);
    std::int32_t SaveReturn(AddressRef parameter1);
    std::int32_t SetReturn(float parameter1, float parameter2, float parameter3, float parameter4);
    Task<std::int32_t> UseReturn();
    std::int32_t IfTeleported();
    std::int32_t SetXYZ2(std::int32_t parameter1, AddressRef parameter2);
    std::int32_t SetABG(std::int32_t parameter1, AddressRef parameter2);
    void GetCamNorm(std::int32_t parameter1, FloatRef parameter2);
    String PlayerName();
    String GetPlayerName(String parameter1);
    std::int32_t SeekFor(std::int32_t parameter1, String parameter2);
    Task<void> CheckPets();
    Task<std::int32_t> Pet2(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t IsUnderSphere();
    String NumToModel(std::int32_t parameter1);
    std::int32_t Model(std::int32_t parameter1);
    std::int32_t SetModel(std::int32_t parameter1);
    float Getxyz(AddressRef parameter1);
    float Getabg(AddressRef parameter1);
    std::int32_t Getowner();
    String PlToBuf(std::int32_t parameter1);
    std::int32_t FillSkinParams(std::int32_t parameter1);
    Value PlFromBuf(std::int32_t parameter1);
    std::int32_t ResetParams();
    std::int32_t DelTime(std::int32_t parameter1);
    void sendslot(std::int32_t parameter1, std::int32_t parameter2);
    void sendsloti(std::int32_t parameter1, std::int32_t parameter2);
    void sendsloti1(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> CheckWeapon();
    Task<void> Resstop();
    std::int32_t NSquare(float parameter1, float parameter2, float parameter3);
    void LostItem2(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t errhalt();
    std::int32_t halt();
    std::int32_t GetPersMsg(String parameter1);
    Task<void> UpdateClanSymb();
    Task<void> smsWindowMessage1();
    Task<void> WinLink();
    Task<void> Reconnect();
    Task<void> prg_OkCancelDialog();
    Task<std::int32_t> group_new();
    Task<std::int32_t> joinMeAsCandidate(String parameter1);
    std::int32_t joinSomeone2Group(String parameter1);
    std::int32_t deleteSomeoneFromGroup(String parameter1);
    std::int32_t deleteMeFroupGroup();
    std::int32_t groupDelete();
    std::int32_t invitePlrToGroup(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> receiveInvite2Group(std::int32_t parameter1, String parameter2);
    Task<void> prg_invite2Group();
    std::int32_t getPlayerGroupState();
    Task<std::int32_t> inSameGroup();
    String getLeader();
    Task<Value> mgrChat(String parameter1);
    Task<void> mgrSetTrade(String parameter1, std::int32_t parameter2);
    Task<Value> mgrSSetOffer(String parameter1);
    Task<Value> mgrBuyIt(String parameter1, std::int32_t parameter2);
    Task<Value> mgrSSysMsg(String parameter1);
    Task<Value> mgrFist(String parameter1, std::int32_t parameter2);
    Task<Value> mgrTable(String parameter1, std::int32_t parameter2);
    Task<void> mgrSBought(String parameter1);
    Value mgrKey(String parameter1, std::int32_t parameter2);
    Task<void> mgrCheckKey();
    Value mgrSetCoord(String parameter1, std::int32_t parameter2);
    Value mgrSrvJump(String parameter1, std::int32_t parameter2);
    String mgrElem(String parameter1);
    std::int32_t mgrEffect(String parameter1, std::int32_t parameter2);
    Task<void> mgrEffectPrg();
    Task<Value> mgrTradeWith(std::int32_t parameter1);
    Task<Value> mgrSetClan(String parameter1, std::int32_t parameter2);
    Value mgrSrClan(String parameter1, std::int32_t parameter2);
    void mcl();
    Task<Value> mgrSetGroup(String parameter1, std::int32_t parameter2);
    Task<void> mgrCheckCrc(String parameter1, std::int32_t parameter2);
    Task<void> restartUpdater();
    Task<Value> mgrGrab(String parameter1, std::int32_t parameter2);
    Task<Value> mgrGetBonus(String parameter1, std::int32_t parameter2);
    Value mgrCheat(String parameter1);
    Task<void> mgrAnticheat();
    std::int32_t runMgrAnticheat(String parameter1, std::int32_t parameter2);
    Task<Value> mgrAlly(String parameter1);
    Task<std::int32_t> mgrTmntInfo(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> mgrTmntAction(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> mgrTmntDrop(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> mgrTmntState(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> mgrTmntDone(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> mgrTmntData(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> mgrTmntShowState(std::int32_t parameter1, String parameter2);
    Task<Value> mgrLost(std::int32_t parameter1, String parameter2);
    Task<void> Manager();
    std::int32_t SendToRegM(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t SendAllyAsk(std::int32_t parameter1, String parameter2);
    std::int32_t SetAllyList(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t GetAllyList(std::int32_t parameter1, String parameter2);
    std::int32_t DDBG();
    std::int32_t Ensc(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> Sheat(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, String parameter4);
    std::int32_t IsExtra();
    std::int32_t IsClearExtra();
    Task<void> EDyn();
    Task<void> EStat();
    Task<void> Client();
    std::int32_t AutoMode();
    Task<void> Owner();
    Task<void> CheckServer();
    Task<void> CheckOwnImage();
    Task<std::int32_t> SendAnim(std::int32_t parameter1);
    std::int32_t SendSwordEff(std::int32_t parameter1);
    std::int32_t StopSwordEff();
    std::int32_t SendCBookItem(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    std::int32_t BuyIt(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4);
    std::int32_t readnext(std::int32_t parameter1, String parameter2, IntRef parameter3, IntRef parameter4);
    Task<void> CheckPing();
    Task<void> WaitReinc();
    Task<void> RcvInfo();
    Task<void> showred();
    Task<void> ELoot();
    void SetSkin(std::int32_t parameter1);
    Task<void> User();
    Task<void> EKill();
    Task<void> Image();
    std::int32_t SetWear(std::int32_t parameter1);
    void Sethp(std::int32_t parameter1);
    std::int32_t Upload(std::int32_t parameter1, String parameter2);
    std::int32_t RestoreParams(String parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4, std::int32_t parameter5, std::int32_t parameter6, std::int32_t parameter7, std::int32_t parameter8);
    Task<void> StoreItem();
    std::int32_t LotteryResult(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> WaitForCrcThreadEnd();
    Task<std::int32_t> ShowBank2();
    Task<void> smsWindowMessage();
    Task<void> smsWindowGetPrize();
    Task<std::int32_t> GetBonusInfo(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t smsShowWindow(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> smsShowPrizeWindow(IntRef parameter1, IntRef parameter2, std::int32_t parameter3, std::int32_t parameter4);
    void AskClanSymbol(std::int8_t parameter1);
    std::int32_t InitClanSymb(std::int32_t parameter1);
    std::int32_t GetClanSymbInit();
    std::int32_t GetCsID();
    Task<std::int32_t> BnkTrd(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4, String parameter5);
    std::int32_t LLTOI(String parameter1);
    std::int32_t GetHrLicPrice();
    std::int32_t GetLicTrade();
    Task<void> smsInfoIcon();
    Task<void> smsInfoIconTooltip();
    Task<void> smsInfoIconFlush();
    std::int32_t GetPUID();
    std::int32_t AskLnk(std::int32_t parameter1);
    Task<void> NManager();
    Task<void> NAManager();
    std::int32_t GetProperty(std::int32_t parameter1);
    std::int32_t SetProperty(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> ActivityCtrlWnd();
    std::int32_t GetSids(std::int32_t parameter1, AddressRef parameter2);
    std::int32_t resetDungeonNumber();
    std::int32_t getDungeonNumber();
    Task<std::int32_t> tryToRevertClanKills(std::int32_t parameter1);
    std::int32_t getMarkOnMapXZ(FloatRef parameter1, FloatRef parameter2);
    std::int32_t setMarkOnMapXZ(float parameter1, float parameter2);
    std::int32_t sendMarkOnMapXZ();
    std::int32_t receiveMarkOnMapXZ(String parameter1);
    std::int32_t inCastleZone();
    std::int32_t IsUnderground();
    std::int32_t valid_filesys_chrs(String parameter1);
    Task<std::int32_t> sysMsgAndText(std::int32_t parameter1, String parameter2, std::int32_t parameter3);
    std::int32_t ConvertGXPInRealType(String parameter1);
    std::int32_t GetPlayerLevel();
    Task<std::int32_t> getPlayerInfo(String parameter1);
    void FFLBP(float parameter1, float parameter2);
    std::int32_t enableFistPwr(std::int32_t parameter1);
    std::int32_t setFistPowerups(std::int32_t parameter1);
    std::int32_t getFistPowerups();
    std::int32_t getPassportShard();
    std::int32_t addToSkrijalTxt(String parameter1);
    Task<void> receiveArtisanMonitor();
    void setArtisanID(std::int32_t parameter1);
    void setCustomerID(std::int32_t parameter1);
    void setPriceArtisan(std::int32_t parameter1);
    void resetCustomerData();
    void resetArtisanData();
    std::int32_t receivePriceArtisan();
    std::int32_t receiveCustomerID();
    std::int32_t receiveMyWorkshop();
    std::int32_t receiveArtisanID();
    void callCloseCustomerWorkshop(std::int32_t parameter1);
    void callOpenCustomerWorkshop(std::int32_t parameter1);
    Task<Value> openCustomerWorkshop(std::int32_t parameter1);
    Task<Value> closeCustomerWorkshop(std::int32_t parameter1);
    Task<void> receiveOwnerArtisanMonitor();
    std::int32_t GetCanUseWebShopAndClaim();
    void helper25_1();
    Task<void> helper38_1();
    Task<void> helper32_1();
    Task<void> helper30_1();
    void helper81_1();
    void helper8_1();
    Task<void> helper98_1();
    Task<void> cleanup_KeyAlarm();
    Task<void> cleanup_ShowName();
    Task<void> cleanup_PrgMove();
    Task<void> cleanup_smsWindowMessage1();
    Task<void> cleanup_WinLink();
    Task<void> cleanup_prg_OkCancelDialog();
    Task<void> cleanup_prg_invite2Group();
    Task<void> cleanup_CheckPing();
    Task<void> cleanup_smsWindowMessage();
    Task<void> cleanup_smsWindowGetPrize();
    Task<void> cleanup_ActivityCtrlWnd();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    std::int32_t member3180_{};
    std::int32_t member1743_{};
    std::array<std::uint8_t, 22> member1763_{};
    std::int32_t member5327_{};
    std::array<Address, 2> member5110_{};
    std::array<Address, 2> member5112_{};
    std::int32_t member5113_{};
    std::int32_t member5115_{};
    std::int32_t member5116_{};
    std::array<std::uint8_t, 20> member5117_{};
    std::array<std::uint8_t, 128> member5120_{};
    std::array<std::uint8_t, 128> member5122_{};
    std::int8_t member5124_{};
    std::int8_t member5125_{};
    std::int32_t member5127_{};
    std::array<std::uint8_t, 256> member5128_{};
    String member5131_{};
    std::int8_t member5132_{};
    std::int8_t member5133_{};
    std::int32_t member5135_{};
    std::int32_t member5136_{};
    std::array<std::uint8_t, 64> member5138_{};
    std::int8_t member5140_{};
    std::int8_t member5141_{};
    std::int32_t member5143_{};
    std::int32_t member5144_{};
    std::int32_t member5145_{};
    std::int32_t member5146_{};
    std::int32_t member5147_{};
    std::int32_t member5148_{};
    std::int32_t member5149_{};
    std::int32_t member5150_{};
    std::int32_t member5151_{};
    std::array<std::uint8_t, 60> member5153_{};
    String member5155_{};
    std::array<std::uint8_t, 16> member5156_{};
    std::array<std::uint8_t, 16> member5158_{};
    std::array<std::uint8_t, 16> member5160_{};
    Address member5162_{};
    std::int8_t member5163_{};
    std::int8_t member5164_{};
    std::int8_t member5165_{};
    std::int8_t member5166_{};
    std::int8_t member5167_{};
    std::int8_t member5168_{};
    std::int8_t member5169_{};
    std::int32_t member5171_{};
    std::int32_t member5172_{};
    std::int32_t member5173_{};
    std::int32_t member5174_{};
    std::int32_t member5176_{};
    std::int32_t member5177_{};
    std::int32_t member5178_{};
    std::int32_t member5180_{};
    std::array<std::uint8_t, 160> member5182_{};
    std::int32_t member5184_{};
    std::array<std::uint8_t, 160> member5186_{};
    std::array<std::uint8_t, 8> member5188_{};
    std::int32_t member5190_{};
    std::int32_t member5194_{};
    std::int32_t member5195_{};
    std::int32_t member5197_{};
    std::int32_t member5198_{};
    std::int32_t member5199_{};
    std::int32_t member5200_{};
    std::int32_t member5201_{};
    std::int32_t member5202_{};
    std::int32_t member5203_{};
    std::int32_t member5204_{};
    std::int32_t member5206_{};
    std::int32_t member5208_{};
    std::int32_t member5210_{};
    String member5212_{};
    std::array<std::uint8_t, 20> member5214_{};
    std::int8_t member5216_{};
    std::int32_t member5218_{};
    std::int32_t member5219_{};
    std::array<std::uint8_t, 232> member5220_{};
    std::int32_t member5221_{};
    std::array<std::uint8_t, 32> member5223_{};
    std::int32_t member5224_{};
    std::int32_t member5226_{};
    std::int32_t member5227_{};
    std::array<std::uint8_t, 40> member5229_{};
    std::int32_t member5231_{};
    std::int32_t member5232_{};
    std::int32_t member5233_{};
    std::int32_t member5234_{};
    std::array<std::uint8_t, 20> member5236_{};
    std::int32_t member5240_{};
    std::int32_t member5242_{};
    std::int32_t member5253_{};
    std::int32_t member5254_{};
    std::int32_t member5255_{};
    String member5257_{};
    std::array<std::uint8_t, 16> member5259_{};
    std::int32_t member5261_{};
    std::array<std::uint8_t, 80> member5263_{};
    std::array<std::uint8_t, 80> member5265_{};
    std::array<std::uint8_t, 80> member5267_{};
    std::array<std::uint8_t, 80> member5269_{};
    std::array<std::uint8_t, 80> member5271_{};
    std::int32_t member5273_{};
    std::int32_t member5275_{};
    std::array<std::uint8_t, 80> member5277_{};
    IntRef member5279_{};
    std::array<std::uint8_t, 240> member5281_{};
    std::array<std::uint8_t, 240> member5283_{};
    std::int32_t member5285_{};
    std::int32_t member5287_{};
    std::int32_t member5288_{};
    std::array<std::uint8_t, 240> member5290_{};
    std::int32_t member5292_{};
    std::int32_t member5293_{};
    std::array<std::int32_t, 10> member5295_{};
    std::array<std::uint8_t, 8> member5297_{};
    std::int32_t member5299_{};
    IntRef member5300_{};
    IntRef member5301_{};
    std::int32_t member5303_{};
    std::int32_t member5304_{};
    std::int32_t member5305_{};
    String member5306_{};
    String member5307_{};
    std::array<std::int32_t, 15> member5314_{};
    std::int32_t member5316_{};
    float member5317_{};
    float member5318_{};
    std::int32_t member5320_{};
    std::int32_t member5321_{};
    std::int32_t member5322_{};
    std::int32_t member5323_{};
    std::array<std::uint8_t, 20> member5325_{};
    std::array<std::uint8_t, 11> member5328_{};
    std::array<std::uint8_t, 29> member5329_{};
    std::array<std::uint8_t, 11> member5330_{};
    std::array<std::uint8_t, 5> member5331_{};
    std::array<std::uint8_t, 5> member5332_{};
    std::array<std::uint8_t, 5> member5333_{};
    std::array<std::uint8_t, 30> member5334_{};
    std::array<std::uint8_t, 16> member5335_{};
    std::array<std::uint8_t, 30> member5336_{};
    std::int32_t member5339_{};
    std::int32_t member5346_{};
    String member5347_{};
    String member5348_{};
    std::int32_t member5349_{};
    std::int32_t member5350_{};
    std::array<std::uint8_t, 5> member5351_{};
    String member5352_{};
    std::array<std::uint8_t, 1> member5353_{};
    String member5354_{};
    std::int32_t member5355_{};
    String member5356_{};
    std::int32_t member5358_{};
    std::array<std::uint8_t, 256> member5360_{};
    String member5362_{};
    std::array<std::uint8_t, 16> member5363_{};
    String member5364_{};
    std::array<std::uint8_t, 28> member5365_{};
    String member5366_{};
    std::array<std::uint8_t, 1> member5367_{};
    std::int32_t member5368_{};
    String member5369_{};
    std::int32_t member5371_{};
    std::int32_t member5372_{};
    String member5373_{};
    std::array<std::uint8_t, 19> member5374_{};
    std::array<std::uint8_t, 47> member5375_{};
    String member5376_{};
    String member5377_{};
    std::array<std::uint8_t, 42> member5378_{};
    String member5379_{};
    std::array<std::uint8_t, 26> member5380_{};
    std::int32_t member5381_{};
    String member5382_{};
    std::int32_t member5384_{};
    String member5385_{};
    std::array<std::uint8_t, 19> member5386_{};
    std::array<std::uint8_t, 40> member5387_{};
    String member5388_{};
    std::array<std::uint8_t, 27> member5389_{};
    String member5390_{};
    std::int32_t member5391_{};
    String member5392_{};
    std::int32_t member5394_{};
    String member5395_{};
    std::array<std::uint8_t, 19> member5396_{};
    std::array<std::uint8_t, 21> member5397_{};
    String member5398_{};
    std::int32_t member5399_{};
    String member5400_{};
    String member5401_{};
    String member5402_{};
    std::array<std::uint8_t, 19> member5403_{};
    String member5404_{};
    String member5405_{};
    std::array<std::uint8_t, 42> member5406_{};
    std::int32_t member5407_{};
    String member5408_{};
    std::int32_t member5410_{};
    String member5411_{};
    std::array<std::uint8_t, 19> member5412_{};
    std::array<std::uint8_t, 23> member5413_{};
    std::array<std::uint8_t, 21> member5414_{};
    std::array<std::uint8_t, 23> member5415_{};
    String member5416_{};
    std::int32_t member5417_{};
    String member5418_{};
    std::int32_t member5420_{};
    String member5421_{};
    std::array<std::uint8_t, 19> member5422_{};
    std::array<std::uint8_t, 25> member5423_{};
    std::array<std::uint8_t, 22> member5424_{};
    std::array<std::uint8_t, 25> member5425_{};
    String member5426_{};
    std::int32_t member5427_{};
    String member5428_{};
    float member5430_{};
    String member5432_{};
    std::array<std::uint8_t, 15> member5433_{};
    std::array<String, 18> member5435_{};
    std::array<std::uint8_t, 17> member5437_{};
    std::array<std::uint8_t, 20> member5438_{};
    std::array<std::uint8_t, 19> member5439_{};
    std::array<std::uint8_t, 16> member5440_{};
    std::array<std::uint8_t, 18> member5441_{};
    std::array<std::uint8_t, 21> member5442_{};
    std::array<std::uint8_t, 19> member5443_{};
    std::array<std::uint8_t, 17> member5444_{};
    std::array<std::uint8_t, 19> member5445_{};
    std::array<std::uint8_t, 18> member5446_{};
    std::array<std::uint8_t, 11> member5447_{};
    std::array<std::uint8_t, 21> member5448_{};
    std::array<std::uint8_t, 21> member5449_{};
    std::array<std::uint8_t, 18> member5450_{};
    std::array<std::uint8_t, 18> member5451_{};
    std::array<std::uint8_t, 18> member5452_{};
    std::array<std::uint8_t, 21> member5453_{};
    std::array<std::uint8_t, 20> member5454_{};
    std::int32_t member5455_{};
    std::array<std::uint8_t, 8> member5456_{};
    std::int32_t member5457_{};
    std::int32_t member5458_{};
    std::array<std::uint8_t, 30> member5459_{};
    std::int32_t member5461_{};
    std::int32_t member5462_{};
    std::int32_t member5463_{};
    std::int32_t member5464_{};
    std::int32_t member5466_{};
    std::array<std::uint8_t, 10> member5467_{};
    std::array<std::uint8_t, 5> member5468_{};
    std::int32_t member5471_{};
    IntRef member5474_{};
    IntRef member5475_{};
    IntRef member5476_{};
    IntRef member5477_{};
    IntRef member5478_{};
    IntRef member5479_{};
    IntRef member5481_{};
    IntRef member5482_{};
    std::int32_t member5486_{};
    AddressRef member5487_{};
    IntRef member5488_{};
    float member5514_{};
    float member5515_{};
    float member5516_{};
    float member5517_{};
    float member5518_{};
    float member5519_{};
    float member5520_{};
    std::int32_t member5521_{};
    std::int32_t member5522_{};
    std::int32_t member5523_{};
    std::array<std::uint8_t, 5> member5535_{};
    std::array<std::uint8_t, 7> member5537_{};
    std::array<std::uint8_t, 5> member5538_{};
    IntRef member5566_{};
    std::int32_t member5570_{};
    String member5593_{};
    std::array<std::uint8_t, 11> member5594_{};
    std::array<std::uint8_t, 6> member5595_{};
    std::array<std::uint8_t, 14> member5596_{};
    std::array<std::uint8_t, 20> member5599_{};
    std::array<std::uint8_t, 67> member5601_{};
    std::array<std::uint8_t, 29> member5602_{};
    std::array<std::uint8_t, 40> member5603_{};
    std::array<std::uint8_t, 18> member5604_{};
    std::int32_t member5618_{};
    std::int32_t member5619_{};
    std::int32_t member5620_{};
    std::int32_t member5621_{};
    std::int32_t member5622_{};
    std::int32_t member5623_{};
    std::int32_t member5624_{};
    std::int32_t member5625_{};
    std::int32_t member5626_{};
    std::int32_t member5627_{};
    std::int32_t member5628_{};
    std::int32_t member5629_{};
    std::int32_t member5630_{};
    std::int32_t member5631_{};
    std::int32_t member5632_{};
    float member5634_{};
    Address member5635_{};
    float member5636_{};
    String member5637_{};
    std::int32_t member5638_{};
    std::array<std::uint8_t, 32> member5640_{};
    std::array<std::uint8_t, 32> member5642_{};
    std::int32_t member5644_{};
    std::int32_t member5645_{};
    std::int32_t member5651_{};
    std::array<std::uint8_t, 16> member5652_{};
    std::array<std::uint8_t, 6> member5653_{};
    std::array<std::uint8_t, 6> member5654_{};
    std::array<std::uint8_t, 5> member5655_{};
    std::array<std::uint8_t, 5> member5656_{};
    std::array<std::uint8_t, 5> member5657_{};
    std::array<std::uint8_t, 5> member5658_{};
    std::array<std::uint8_t, 5> member5659_{};
    std::int32_t member5661_{};
    std::int32_t member5662_{};
    std::int32_t member5663_{};
    std::int32_t member5664_{};
    std::int32_t member5665_{};
    std::array<std::uint8_t, 5> member5666_{};
    std::array<std::uint8_t, 10> member5667_{};
    std::array<std::uint8_t, 6> member5668_{};
    std::array<std::uint8_t, 8> member5669_{};
    std::array<std::uint8_t, 4> member5670_{};
    std::int32_t member5710_{};
    std::int32_t member5712_{};
    std::array<std::uint8_t, 22> member5754_{};
    std::int32_t member5755_{};
    std::int32_t member5783_{};
    std::array<std::uint8_t, 4> member5784_{};
    String member5785_{};
    std::array<std::uint8_t, 9> member5786_{};
    std::int32_t member5787_{};
    std::int32_t member5788_{};
    String member5790_{};
    std::int32_t member5791_{};
    std::int32_t member5792_{};
    std::int32_t member5793_{};
    String member5794_{};
    std::int32_t member5795_{};
    std::int32_t member5796_{};
    std::int32_t member5797_{};
    String member5798_{};
    std::int32_t member5799_{};
    std::int32_t member5800_{};
    String member5801_{};
    std::int32_t member5802_{};
    String member5803_{};
    std::array<std::uint8_t, 256> member5805_{};
    String member5807_{};
    std::int32_t member5808_{};
    std::int32_t member5810_{};
    std::int32_t member5811_{};
    std::array<std::int32_t, 4> member5813_{};
    std::int32_t member5815_{};
    String member5816_{};
    std::array<std::uint8_t, 7> member5817_{};
    std::array<std::uint8_t, 5> member5818_{};
    std::array<std::uint8_t, 7> member5819_{};
    std::array<std::uint8_t, 6> member5820_{};
    std::int32_t member5822_{};
    std::array<std::uint8_t, 3> member5823_{};
    std::array<std::uint8_t, 6> member5824_{};
    std::int32_t member5826_{};
    std::array<std::uint8_t, 3> member5827_{};
    std::array<std::uint8_t, 5> member5828_{};
    std::array<std::uint8_t, 6> member5829_{};
    std::int32_t member5831_{};
    std::array<std::uint8_t, 3> member5832_{};
    std::array<std::uint8_t, 5> member5833_{};
    std::array<std::uint8_t, 8> member5834_{};
    std::array<std::uint8_t, 2> member5835_{};
    std::array<std::uint8_t, 2> member5836_{};
    std::array<std::uint8_t, 21> member5837_{};
    std::array<std::uint8_t, 21> member5838_{};
    std::array<std::uint8_t, 8> member5839_{};
    std::array<std::uint8_t, 2> member5840_{};
    std::array<std::uint8_t, 2> member5841_{};
    std::array<std::uint8_t, 8> member5842_{};
    std::array<std::uint8_t, 2> member5843_{};
    std::array<std::uint8_t, 2> member5844_{};
    std::array<std::uint8_t, 7> member5845_{};
    std::array<std::uint8_t, 2> member5846_{};
    std::array<std::uint8_t, 2> member5847_{};
    std::array<std::uint8_t, 5> member5848_{};
    std::array<std::uint8_t, 5> member5849_{};
    std::int32_t member5851_{};
    std::array<std::uint8_t, 15> member5852_{};
    std::array<std::uint8_t, 5> member5853_{};
    std::array<std::uint8_t, 15> member5854_{};
    std::array<std::uint8_t, 8> member5855_{};
    String member5857_{};
    std::array<std::uint8_t, 20> member5859_{};
    std::int32_t member5861_{};
    std::array<std::uint8_t, 15> member5862_{};
    std::array<std::uint8_t, 6> member5863_{};
    std::array<std::uint8_t, 5> member5864_{};
    std::array<std::uint8_t, 3> member5865_{};
    std::array<std::uint8_t, 6> member5866_{};
    std::array<std::uint8_t, 3> member5867_{};
    std::array<std::uint8_t, 9> member5868_{};
    std::array<std::uint8_t, 5> member5869_{};
    std::array<std::uint8_t, 6> member5870_{};
    std::array<std::uint8_t, 4> member5871_{};
    std::array<std::uint8_t, 5> member5872_{};
    std::int32_t member5874_{};
    std::array<std::uint8_t, 3> member5875_{};
    std::array<std::uint8_t, 10> member5876_{};
    std::array<std::uint8_t, 9> member5877_{};
    std::array<std::uint8_t, 11> member5878_{};
    std::array<std::uint8_t, 4> member5879_{};
    std::array<std::uint8_t, 3> member5880_{};
    std::array<std::uint8_t, 3> member5881_{};
    std::array<std::uint8_t, 10> member5882_{};
    std::array<std::uint8_t, 3> member5883_{};
    std::array<std::uint8_t, 6> member5884_{};
    std::array<std::uint8_t, 3> member5885_{};
    std::array<std::uint8_t, 3> member5886_{};
    std::array<std::uint8_t, 6> member5887_{};
    std::array<std::uint8_t, 3> member5888_{};
    std::array<std::uint8_t, 6> member5889_{};
    std::array<std::uint8_t, 3> member5890_{};
    String member5891_{};
    std::array<std::uint8_t, 10> member5892_{};
    std::array<std::uint8_t, 11> member5893_{};
    std::array<std::uint8_t, 8> member5894_{};
    std::array<std::uint8_t, 11> member5895_{};
    std::array<std::uint8_t, 11> member5896_{};
    std::array<std::uint8_t, 5> member5897_{};
    std::array<std::uint8_t, 6> member5898_{};
    std::array<std::uint8_t, 3> member5899_{};
    std::array<std::uint8_t, 5> member5900_{};
    std::array<std::uint8_t, 9> member5901_{};
    String member5902_{};
    std::array<std::uint8_t, 7> member5903_{};
    std::array<std::uint8_t, 9> member5904_{};
    std::array<std::uint8_t, 5> member5905_{};
    std::array<std::uint8_t, 4> member5906_{};
    std::array<std::uint8_t, 21> member5907_{};
    std::array<std::uint8_t, 21> member5908_{};
    std::array<std::uint8_t, 21> member5909_{};
    std::array<std::uint8_t, 21> member5910_{};
    std::array<std::uint8_t, 9> member5911_{};
    std::array<std::uint8_t, 4> member5912_{};
    std::array<std::uint8_t, 2> member5913_{};
    std::array<std::uint8_t, 2> member5914_{};
    std::array<std::uint8_t, 21> member5915_{};
    std::array<std::uint8_t, 8> member5916_{};
    std::array<std::uint8_t, 2> member5917_{};
    std::array<std::uint8_t, 2> member5918_{};
    std::array<std::uint8_t, 21> member5919_{};
    std::array<std::uint8_t, 21> member5920_{};
    std::array<std::uint8_t, 7> member5921_{};
    std::array<std::uint8_t, 2> member5922_{};
    std::array<std::uint8_t, 2> member5923_{};
    std::array<std::uint8_t, 21> member5924_{};
    std::array<std::uint8_t, 21> member5925_{};
    std::array<std::uint8_t, 6> member5926_{};
    std::array<std::uint8_t, 6> member5927_{};
    std::array<std::uint8_t, 6> member5928_{};
    std::array<std::uint8_t, 10> member5929_{};
    std::array<std::uint8_t, 8> member5930_{};
    std::array<std::uint8_t, 9> member5931_{};
    std::array<std::uint8_t, 15> member5932_{};
    std::array<std::uint8_t, 14> member5933_{};
    std::array<std::uint8_t, 6> member5934_{};
    std::int32_t member5936_{};
    std::int32_t member5937_{};
    std::int32_t member5938_{};
    std::int32_t member5939_{};
    std::array<std::uint8_t, 8> member5940_{};
    std::array<std::uint8_t, 57> member5941_{};
    std::array<std::uint8_t, 71> member5942_{};
    std::array<std::uint8_t, 8> member5943_{};
    std::array<std::uint8_t, 63> member5944_{};
    std::array<std::uint8_t, 62> member5945_{};
    std::array<std::uint8_t, 3> member5946_{};
    String member5947_{};
    std::array<std::uint8_t, 13> member5948_{};
    std::array<std::uint8_t, 3> member5949_{};
    std::array<std::uint8_t, 11> member5950_{};
    std::int32_t member5951_{};
    std::int32_t member5952_{};
    String member5953_{};
    String member5954_{};
    std::int32_t member5955_{};
    std::int32_t member5957_{};
    String member5958_{};
    std::array<std::uint8_t, 6> member5959_{};
    std::array<std::uint8_t, 5> member5960_{};
    std::array<std::uint8_t, 2> member5961_{};
    std::int32_t member5962_{};
    std::int32_t member5963_{};
    std::int32_t member5964_{};
    String member5966_{};
    std::int32_t member5967_{};
    String member5968_{};
    std::int32_t member5969_{};
    String member5970_{};
    std::int32_t member5971_{};
    std::array<std::uint8_t, 20> member5973_{};
    std::int8_t member5975_{};
    std::int32_t member5977_{};
    std::array<std::uint8_t, 45> member5978_{};
    std::array<std::uint8_t, 45> member5979_{};
    std::array<std::uint8_t, 21> member5980_{};
    std::array<std::uint8_t, 45> member5981_{};
    std::int32_t member5982_{};
    std::int32_t member5983_{};
    std::int32_t member5984_{};
    std::int32_t member5985_{};
    IntRef member5986_{};
    std::int32_t member5987_{};
    std::array<std::uint8_t, 92> member5988_{};
    String member5989_{};
    String member5990_{};
    std::int32_t member5991_{};
    std::int32_t member5992_{};
    String member5993_{};
    String member5994_{};
    std::int32_t member5995_{};
    std::int32_t member5996_{};
    std::int32_t member5997_{};
    std::array<std::uint8_t, 18> member5998_{};
    std::array<std::uint8_t, 3> member5999_{};
    std::int32_t member6000_{};
    std::int32_t member6001_{};
    std::int32_t member6003_{};
    std::int32_t member6004_{};
    std::array<Address, 2> member6005_{};
    Address member6006_{};
    std::array<float, 3> member6007_{};
    std::int32_t member6008_{};
    std::int8_t member6009_{};
    std::int32_t member6011_{};
    std::int32_t member6012_{};
    std::int32_t member6013_{};
    std::array<std::uint8_t, 9> member6015_{};
    std::array<std::uint8_t, 10> member6016_{};
    std::array<std::uint8_t, 10> member6017_{};
    float member6018_{};
    float member6019_{};
    float member6020_{};
    float member6021_{};
    std::int8_t member6022_{};
    std::array<std::uint8_t, 9> member6023_{};
    AddressRef member6024_{};
    float member6025_{};
    float member6026_{};
    float member6027_{};
    float member6028_{};
    std::int32_t member6029_{};
    FloatRef member6030_{};
    std::array<float, 3> member6032_{};
    String member6033_{};
    std::int32_t member6034_{};
    String member6035_{};
    std::int32_t member6036_{};
    std::int32_t member6037_{};
    std::int32_t member6038_{};
    std::array<std::uint8_t, 20> member6040_{};
    std::int32_t member6042_{};
    std::int32_t member6043_{};
    std::int32_t member6045_{};
    std::int32_t member6046_{};
    std::int32_t member6047_{};
    std::array<std::uint8_t, 9> member6048_{};
    std::array<std::uint8_t, 7> member6049_{};
    std::array<std::uint8_t, 7> member6050_{};
    std::int32_t member6051_{};
    std::int32_t member6052_{};
    AddressRef member6053_{};
    AddressRef member6054_{};
    std::int32_t member6055_{};
    String member6057_{};
    std::int32_t member6059_{};
    String member6061_{};
    std::int32_t member6062_{};
    String member6063_{};
    std::int32_t member6065_{};
    std::int32_t member6067_{};
    std::int32_t member6068_{};
    String member6069_{};
    std::int32_t member6070_{};
    std::int32_t member6071_{};
    String member6072_{};
    std::int32_t member6073_{};
    std::int32_t member6074_{};
    std::int32_t member6075_{};
    IntRef member6076_{};
    std::array<std::int8_t, 4> member6078_{};
    std::array<std::uint8_t, 8> member6080_{};
    std::array<std::uint8_t, 9> member6081_{};
    std::array<std::uint8_t, 7> member6082_{};
    std::array<std::uint8_t, 7> member6083_{};
    float member6084_{};
    float member6085_{};
    float member6086_{};
    std::int32_t member6087_{};
    std::int32_t member6088_{};
    std::int32_t member6089_{};
    String member6090_{};
    std::int32_t member6091_{};
    String member6092_{};
    std::array<std::uint8_t, 256> member6094_{};
    std::array<std::uint8_t, 256> member6096_{};
    std::int32_t member6098_{};
    std::array<std::uint8_t, 256> member6100_{};
    std::array<std::uint8_t, 256> member6102_{};
    std::array<std::uint8_t, 256> member6104_{};
    std::array<std::uint8_t, 256> member6106_{};
    std::array<std::uint8_t, 256> member6108_{};
    std::array<std::uint8_t, 2048> member6110_{};
    std::int32_t member6112_{};
    std::int32_t member6113_{};
    std::int32_t member6114_{};
    float member6115_{};
    float member6116_{};
    std::array<std::uint8_t, 9> member6117_{};
    String member6118_{};
    std::array<std::uint8_t, 11> member6119_{};
    String member6120_{};
    std::array<std::uint8_t, 28> member6121_{};
    std::array<std::uint8_t, 5> member6122_{};
    std::array<std::uint8_t, 5> member6123_{};
    std::array<std::uint8_t, 5> member6124_{};
    std::array<std::uint8_t, 5> member6125_{};
    std::array<std::uint8_t, 5> member6126_{};
    std::int32_t member6128_{};
    std::int8_t member6129_{};
    std::int8_t member6130_{};
    std::array<std::uint8_t, 256> member6132_{};
    std::int32_t member6134_{};
    std::int32_t member6135_{};
    std::int32_t member6136_{};
    std::array<std::uint8_t, 8> member6137_{};
    std::array<std::uint8_t, 11> member6138_{};
    std::string member6140_;
    std::int32_t member6142_{};
    std::int32_t member6143_{};
    std::int32_t member6144_{};
    std::array<std::uint8_t, 9> member6145_{};
    std::array<std::uint8_t, 10> member6146_{};
    std::array<std::uint8_t, 256> member6148_{};
    std::int32_t member6150_{};
    std::int32_t member6151_{};
    std::int8_t member6152_{};
    std::int32_t member6154_{};
    std::int32_t member6156_{};
    std::int32_t member6157_{};
    std::array<std::uint8_t, 8> member6158_{};
    std::array<std::uint8_t, 64> member6160_{};
    String member6162_{};
    std::array<std::uint8_t, 18> member6164_{};
    String member6165_{};
    std::array<std::uint8_t, 18> member6166_{};
    String member6167_{};
    String member6168_{};
    std::int32_t member6169_{};
    String member6170_{};
    std::int32_t member6171_{};
    String member6172_{};
    String member6174_{};
    std::int32_t member6175_{};
    std::array<std::uint8_t, 20> member6177_{};
    std::int32_t member6179_{};
    std::array<std::uint8_t, 256> member6181_{};
    std::array<std::uint8_t, 20> member6183_{};
    std::int8_t member6185_{};
    String member6187_{};
    std::int32_t member6188_{};
    std::int32_t member6189_{};
    std::int32_t member6190_{};
    std::array<std::uint8_t, 8> member6191_{};
    std::array<std::uint8_t, 22> member6192_{};
    String member6193_{};
    String member6194_{};
    std::array<std::uint8_t, 10> member6195_{};
    std::array<std::uint8_t, 1> member6196_{};
    String member6197_{};
    String member6198_{};
    std::array<std::uint8_t, 10> member6199_{};
    std::array<std::uint8_t, 17> member6200_{};
    std::int32_t member6201_{};
    std::int32_t member6202_{};
    std::array<std::uint8_t, 20> member6204_{};
    std::array<std::uint8_t, 8> member6206_{};
    std::array<std::uint8_t, 1> member6207_{};
    String member6208_{};
    std::int32_t member6210_{};
    std::int32_t member6212_{};
    std::int32_t member6213_{};
    String member6214_{};
    String member6215_{};
    std::array<std::uint8_t, 3> member6216_{};
    String member6218_{};
    String member6219_{};
    String member6220_{};
    std::array<std::uint8_t, 3> member6221_{};
    std::array<std::uint8_t, 11> member6222_{};
    std::array<std::uint8_t, 5> member6223_{};
    std::array<std::uint8_t, 5> member6224_{};
    std::array<std::uint8_t, 5> member6225_{};
    std::array<std::uint8_t, 5> member6226_{};
    std::array<std::uint8_t, 5> member6227_{};
    std::array<std::uint8_t, 13> member6228_{};
    std::array<std::uint8_t, 5> member6229_{};
    String member6230_{};
    std::int32_t member6231_{};
    String member6233_{};
    std::int32_t member6234_{};
    std::array<std::uint8_t, 21> member6235_{};
    std::array<std::uint8_t, 2> member6236_{};
    std::int32_t member6238_{};
    std::array<std::uint8_t, 13> member6239_{};
    String member6240_{};
    String member6242_{};
    std::int32_t member6243_{};
    std::array<std::uint8_t, 26> member6244_{};
    std::array<std::uint8_t, 2> member6245_{};
    std::array<std::uint8_t, 20> member6246_{};
    std::array<std::uint8_t, 2> member6247_{};
    std::array<std::uint8_t, 18> member6248_{};
    String member6249_{};
    std::int32_t member6250_{};
    String member6251_{};
    std::int32_t member6252_{};
    std::int32_t member6253_{};
    std::int32_t member6255_{};
    std::array<std::uint8_t, 11> member6256_{};
    std::array<std::uint8_t, 11> member6257_{};
    std::array<std::uint8_t, 11> member6258_{};
    std::array<std::uint8_t, 11> member6259_{};
    std::array<std::uint8_t, 18> member6260_{};
    String member6261_{};
    std::int32_t member6263_{};
    std::int32_t member6264_{};
    std::int32_t member6265_{};
    String member6266_{};
    std::int8_t member6267_{};
    std::array<std::uint8_t, 10> member6269_{};
    std::array<std::uint8_t, 21> member6271_{};
    std::array<std::uint8_t, 18> member6272_{};
    std::array<std::uint8_t, 18> member6273_{};
    std::array<std::uint8_t, 21> member6274_{};
    std::array<std::uint8_t, 18> member6275_{};
    std::array<std::uint8_t, 3> member6276_{};
    std::array<std::uint8_t, 18> member6277_{};
    std::int8_t member6278_{};
    std::int32_t member6280_{};
    std::int32_t member6281_{};
    std::int32_t member6282_{};
    std::int32_t member6283_{};
    std::int32_t member6284_{};
    std::int32_t member6285_{};
    std::array<std::uint8_t, 11> member6286_{};
    std::array<std::uint8_t, 11> member6287_{};
    std::array<std::uint8_t, 11> member6288_{};
    std::array<std::uint8_t, 11> member6289_{};
    std::array<std::uint8_t, 11> member6290_{};
    std::array<std::uint8_t, 5> member6291_{};
    std::array<std::uint8_t, 5> member6292_{};
    std::array<std::uint8_t, 11> member6293_{};
    String member6294_{};
    std::int32_t member6295_{};
    std::int8_t member6296_{};
    float member6298_{};
    float member6299_{};
    std::int32_t member6300_{};
    std::array<std::uint8_t, 6> member6301_{};
    String member6302_{};
    std::array<std::uint8_t, 19> member6303_{};
    String member6304_{};
    std::int32_t member6305_{};
    std::int32_t member6307_{};
    std::array<std::uint8_t, 5> member6309_{};
    String member6310_{};
    std::int32_t member6312_{};
    std::int32_t member6313_{};
    std::int32_t member6314_{};
    std::int32_t member6315_{};
    String member6316_{};
    std::int32_t member6317_{};
    std::int32_t member6318_{};
    std::int32_t member6319_{};
    std::array<std::uint8_t, 4> member6320_{};
    std::array<std::uint8_t, 18> member6321_{};
    String member6322_{};
    std::int32_t member6323_{};
    String member6325_{};
    std::int32_t member6326_{};
    String member6327_{};
    std::int32_t member6328_{};
    std::array<Address, 2> member6329_{};
    String member6330_{};
    String member6331_{};
    std::int32_t member6332_{};
    String member6334_{};
    String member6335_{};
    std::int32_t member6336_{};
    std::array<std::uint8_t, 32> member6338_{};
    IntRef member6340_{};
    IntRef member6341_{};
    IntRef member6342_{};
    std::array<std::uint8_t, 140> member6343_{};
    std::array<std::uint8_t, 140> member6344_{};
    std::array<std::uint8_t, 140> member6345_{};
    String member6346_{};
    std::int32_t member6347_{};
    std::int32_t member6348_{};
    std::int8_t member6349_{};
    String member6351_{};
    std::int8_t member6352_{};
    std::int8_t member6353_{};
    std::int32_t member6354_{};
    std::array<std::uint8_t, 4> member6355_{};
    String member6356_{};
    std::int32_t member6357_{};
    std::int32_t member6359_{};
    std::int32_t member6360_{};
    std::array<std::uint8_t, 18> member6361_{};
    std::array<std::uint8_t, 18> member6362_{};
    std::array<std::uint8_t, 18> member6363_{};
    std::array<std::uint8_t, 18> member6364_{};
    std::array<std::uint8_t, 18> member6365_{};
    std::array<std::uint8_t, 18> member6366_{};
    std::array<std::uint8_t, 18> member6367_{};
    String member6368_{};
    std::int32_t member6369_{};
    std::int32_t member6371_{};
    std::int32_t member6372_{};
    std::int32_t member6373_{};
    String member6374_{};
    String member6375_{};
    String member6376_{};
    std::int32_t member6377_{};
    String member6378_{};
    std::int32_t member6379_{};
    std::int32_t member6380_{};
    std::array<std::uint8_t, 20> member6382_{};
    std::array<std::uint8_t, 8> member6384_{};
    std::array<std::uint8_t, 62> member6385_{};
    std::array<std::uint8_t, 8> member6386_{};
    std::array<std::uint8_t, 20> member6387_{};
    std::array<std::uint8_t, 35> member6388_{};
    std::array<std::uint8_t, 8> member6389_{};
    std::array<std::uint8_t, 18> member6390_{};
    std::array<String, 2> member6391_{};
    std::array<std::uint8_t, 8> member6392_{};
    std::array<std::uint8_t, 20> member6393_{};
    std::array<std::uint8_t, 23> member6394_{};
    std::array<std::uint8_t, 8> member6395_{};
    std::array<std::uint8_t, 18> member6396_{};
    std::array<String, 2> member6397_{};
    std::array<std::uint8_t, 23> member6398_{};
    std::array<std::uint8_t, 8> member6399_{};
    std::array<std::uint8_t, 8> member6400_{};
    std::array<std::uint8_t, 20> member6401_{};
    std::array<std::uint8_t, 8> member6402_{};
    std::array<std::uint8_t, 20> member6403_{};
    std::array<std::uint8_t, 34> member6404_{};
    std::array<std::uint8_t, 16> member6405_{};
    std::array<std::uint8_t, 8> member6406_{};
    String member6407_{};
    String member6408_{};
    std::int32_t member6409_{};
    std::array<std::uint8_t, 17> member6411_{};
    std::array<std::uint8_t, 8> member6412_{};
    std::array<std::uint8_t, 1> member6413_{};
    std::int32_t member6415_{};
    std::array<std::uint8_t, 21> member6416_{};
    std::array<std::uint8_t, 11> member6417_{};
    std::array<std::uint8_t, 1> member6418_{};
    String member6419_{};
    std::int32_t member6420_{};
    std::int32_t member6422_{};
    std::int32_t member6423_{};
    std::int32_t member6424_{};
    std::array<std::uint8_t, 18> member6425_{};
    String member6426_{};
    std::int32_t member6427_{};
    std::int32_t member6429_{};
    std::int32_t member6431_{};
    std::int32_t member6432_{};
    std::int32_t member6433_{};
    std::array<std::uint8_t, 1024> member6435_{};
    std::array<std::uint8_t, 1024> member6437_{};
    std::int32_t member6439_{};
    String member6440_{};
    std::int32_t member6441_{};
    std::int32_t member6442_{};
    String member6443_{};
    String member6444_{};
    String member6445_{};
    std::array<std::uint8_t, 29> member6446_{};
    String member6447_{};
    std::array<std::uint8_t, 7> member6448_{};
    std::array<std::uint8_t, 2> member6449_{};
    std::array<std::uint8_t, 7> member6450_{};
    std::array<std::uint8_t, 9> member6451_{};
    std::array<std::uint8_t, 1> member6452_{};
    std::int32_t member6454_{};
    std::array<std::uint8_t, 256> member6456_{};
    std::int32_t member6458_{};
    String member6459_{};
    std::array<std::uint8_t, 21> member6460_{};
    std::int32_t member6462_{};
    std::array<std::uint8_t, 10> member6463_{};
    std::array<std::uint8_t, 8> member6464_{};
    std::array<std::uint8_t, 21> member6465_{};
    std::array<std::uint8_t, 21> member6466_{};
    std::array<std::uint8_t, 11> member6467_{};
    std::array<std::uint8_t, 29> member6468_{};
    std::array<std::uint8_t, 11> member6469_{};
    std::array<std::uint8_t, 7> member6470_{};
    String member6471_{};
    std::array<std::uint8_t, 1> member6472_{};
    std::array<std::uint8_t, 1> member6473_{};
    String member6474_{};
    String member6475_{};
    std::int32_t member6476_{};
    String member6477_{};
    std::int32_t member6478_{};
    String member6480_{};
    std::array<std::uint8_t, 11> member6481_{};
    std::array<std::uint8_t, 5> member6482_{};
    std::array<std::uint8_t, 11> member6483_{};
    std::array<std::uint8_t, 5> member6484_{};
    std::int32_t member6485_{};
    std::array<std::uint8_t, 50> member6487_{};
    std::array<std::uint8_t, 10> member6489_{};
    std::array<std::uint8_t, 17> member6490_{};
    std::array<std::uint8_t, 5> member6491_{};
    std::array<std::uint8_t, 13> member6492_{};
    std::array<std::uint8_t, 7> member6493_{};
    std::array<std::uint8_t, 7> member6494_{};
    std::array<std::uint8_t, 5> member6495_{};
    std::array<std::uint8_t, 13> member6496_{};
    std::array<std::uint8_t, 7> member6497_{};
    std::array<std::uint8_t, 3> member6498_{};
    std::array<std::uint8_t, 7> member6499_{};
    std::array<std::uint8_t, 10> member6500_{};
    std::array<std::uint8_t, 17> member6501_{};
    std::array<std::uint8_t, 5> member6502_{};
    std::array<std::uint8_t, 22> member6503_{};
    std::array<std::uint8_t, 38> member6504_{};
    std::array<std::uint8_t, 5> member6505_{};
    std::int32_t member6506_{};
    String member6507_{};
    String member6509_{};
    std::int32_t member6510_{};
    std::int32_t member6511_{};
    std::int32_t member6512_{};
    std::int32_t member6513_{};
    std::int32_t member6514_{};
    std::int32_t member6515_{};
    std::array<std::uint8_t, 20> member6517_{};
    std::array<std::uint8_t, 14> member6519_{};
    std::array<std::uint8_t, 14> member6520_{};
    std::array<std::uint8_t, 14> member6521_{};
    std::array<std::uint8_t, 14> member6522_{};
    std::int32_t member6523_{};
    String member6524_{};
    String member6526_{};
    std::int32_t member6527_{};
    std::int32_t member6528_{};
    std::int32_t member6529_{};
    std::int32_t member6530_{};
    std::array<std::uint8_t, 152> member6531_{};
    std::array<std::uint8_t, 20> member6533_{};
    std::int32_t member6535_{};
    std::array<std::uint8_t, 14> member6536_{};
    std::array<std::uint8_t, 14> member6537_{};
    std::array<std::uint8_t, 14> member6538_{};
    std::int32_t member6539_{};
    String member6540_{};
    String member6542_{};
    std::int32_t member6543_{};
    std::int32_t member6544_{};
    std::int32_t member6545_{};
    std::int32_t member6546_{};
    std::array<std::uint8_t, 20> member6548_{};
    AddressRef member6550_{};
    std::array<std::uint8_t, 11> member6551_{};
    std::array<std::uint8_t, 14> member6552_{};
    std::array<std::uint8_t, 13> member6553_{};
    std::array<std::uint8_t, 14> member6554_{};
    String member6555_{};
    std::array<std::uint8_t, 14> member6556_{};
    std::int32_t member6557_{};
    String member6558_{};
    std::int32_t member6560_{};
    std::int32_t member6561_{};
    std::array<std::uint8_t, 20> member6563_{};
    std::int32_t member6565_{};
    String member6567_{};
    std::array<std::uint8_t, 13> member6568_{};
    String member6569_{};
    String member6570_{};
    std::array<std::uint8_t, 16> member6571_{};
    String member6572_{};
    std::array<std::uint8_t, 13> member6573_{};
    std::array<std::uint8_t, 14> member6574_{};
    std::array<std::uint8_t, 14> member6575_{};
    std::array<std::uint8_t, 14> member6576_{};
    std::int32_t member6577_{};
    String member6578_{};
    String member6579_{};
    std::int32_t member6581_{};
    AddressRef member6582_{};
    String member6583_{};
    AddressRef member6584_{};
    std::array<std::uint8_t, 11> member6585_{};
    std::int32_t member6587_{};
    std::int32_t member6588_{};
    std::int32_t member6589_{};
    std::int32_t member6590_{};
    std::array<std::uint8_t, 20> member6592_{};
    std::array<std::uint8_t, 14> member6594_{};
    std::array<std::uint8_t, 14> member6595_{};
    std::array<std::uint8_t, 14> member6596_{};
    std::array<std::uint8_t, 14> member6597_{};
    std::array<std::uint8_t, 14> member6598_{};
    std::array<std::uint8_t, 14> member6599_{};
    std::int32_t member6600_{};
    String member6601_{};
    std::array<std::uint8_t, 16> member6603_{};
    std::int32_t member6604_{};
    String member6605_{};
    std::array<std::uint8_t, 17> member6606_{};
    std::int32_t member6607_{};
    String member6608_{};
    std::int32_t member6610_{};
    std::int32_t member6611_{};
    std::array<std::uint8_t, 4> member6612_{};
    std::array<std::uint8_t, 6> member6613_{};
    std::array<std::uint8_t, 18> member6614_{};
    std::int32_t member6615_{};
    std::int32_t member6616_{};
    std::int32_t member6617_{};
    std::int32_t member6618_{};
    std::array<std::uint8_t, 256> member6620_{};
    String member6621_{};
    std::array<std::uint8_t, 18> member6623_{};
    std::array<std::uint8_t, 11> member6624_{};
    std::array<std::uint8_t, 10> member6625_{};
    std::array<std::uint8_t, 18> member6626_{};
    String member6628_{};
    std::int32_t member6629_{};
    std::int32_t member6630_{};
    std::int32_t member6631_{};
    std::array<std::uint8_t, 14> member6632_{};
    std::array<std::uint8_t, 23> member6633_{};
    std::array<std::uint8_t, 21> member6634_{};
    std::int32_t member6635_{};
    std::int32_t member6636_{};
    String member6637_{};
    std::int32_t member6638_{};
    String member6639_{};
    std::int32_t member6640_{};
    std::int32_t member6641_{};
    String member6642_{};
    String member6644_{};
    std::int32_t member6645_{};
    String member6646_{};
    String member6647_{};
    std::int32_t member6648_{};
    String member6649_{};
    std::array<std::uint8_t, 5> member6650_{};
    std::int32_t member6651_{};
    String member6652_{};
    std::int32_t member6653_{};
    std::int32_t member6654_{};
    std::int32_t member6655_{};
    String member6656_{};
    std::array<std::uint8_t, 16> member6657_{};
    std::array<std::uint8_t, 21> member6658_{};
    std::array<std::uint8_t, 9> member6659_{};
    std::int32_t member6661_{};
    std::int32_t member6663_{};
    std::int32_t member6665_{};
    std::int32_t member6666_{};
    std::int32_t member6667_{};
    IntRef member6669_{};
    std::int32_t member6671_{};
    String member6673_{};
    std::int32_t member6675_{};
    std::int32_t member6676_{};
    std::array<std::uint8_t, 6> member6677_{};
    std::array<std::uint8_t, 7> member6678_{};
    std::array<std::uint8_t, 10> member6679_{};
    std::array<std::uint8_t, 11> member6680_{};
    std::array<std::uint8_t, 8> member6681_{};
    std::array<std::uint8_t, 5> member6682_{};
    std::array<std::uint8_t, 6> member6683_{};
    std::array<std::uint8_t, 13> member6684_{};
    std::array<std::uint8_t, 2> member6685_{};
    std::array<std::uint8_t, 17> member6686_{};
    std::array<std::uint8_t, 17> member6687_{};
    std::array<std::uint8_t, 17> member6688_{};
    String member6689_{};
    std::array<std::uint8_t, 29> member6690_{};
    String member6691_{};
    std::array<std::uint8_t, 6> member6692_{};
    std::array<std::uint8_t, 6> member6693_{};
    std::array<std::uint8_t, 18> member6694_{};
    std::array<std::uint8_t, 11> member6695_{};
    std::array<std::uint8_t, 11> member6696_{};
    std::array<std::uint8_t, 11> member6697_{};
    std::array<std::uint8_t, 11> member6698_{};
    std::array<std::uint8_t, 11> member6699_{};
    std::array<std::uint8_t, 11> member6700_{};
    std::array<std::uint8_t, 11> member6701_{};
    std::array<std::uint8_t, 11> member6702_{};
    std::array<std::uint8_t, 11> member6703_{};
    std::array<std::uint8_t, 11> member6704_{};
    std::array<std::uint8_t, 11> member6705_{};
    std::array<std::uint8_t, 11> member6706_{};
    std::array<std::uint8_t, 10> member6707_{};
    std::array<std::uint8_t, 11> member6708_{};
    std::array<std::uint8_t, 15> member6709_{};
    std::array<std::uint8_t, 21> member6710_{};
    std::array<std::uint8_t, 21> member6711_{};
    std::array<std::uint8_t, 21> member6712_{};
    std::array<std::uint8_t, 11> member6713_{};
    String member6714_{};
    std::array<std::uint8_t, 11> member6715_{};
    std::array<std::uint8_t, 10> member6716_{};
    std::array<std::uint8_t, 9> member6717_{};
    std::array<std::uint8_t, 8> member6718_{};
    std::array<std::uint8_t, 9> member6719_{};
    std::array<std::uint8_t, 8> member6720_{};
    std::array<std::uint8_t, 8> member6721_{};
    String member6722_{};
    std::int32_t member6724_{};
    std::int32_t member6725_{};
    std::int32_t member6726_{};
    std::int32_t member6727_{};
    std::int32_t member6728_{};
    std::int32_t member6729_{};
    String member6730_{};
    std::array<std::uint8_t, 8> member6731_{};
    std::array<std::uint8_t, 21> member6732_{};
    String member6733_{};
    std::array<std::uint8_t, 29> member6734_{};
    String member6735_{};
    std::array<std::uint8_t, 8> member6736_{};
    std::array<std::uint8_t, 19> member6737_{};
    std::array<std::uint8_t, 29> member6738_{};
    std::array<std::uint8_t, 19> member6739_{};
    std::array<std::uint8_t, 29> member6740_{};
    std::array<std::uint8_t, 8> member6741_{};
    String member6742_{};
    std::array<std::uint8_t, 29> member6743_{};
    String member6744_{};
    std::array<std::uint8_t, 9> member6745_{};
    std::array<std::uint8_t, 9> member6746_{};
    std::array<std::uint8_t, 10> member6747_{};
    std::array<std::uint8_t, 11> member6748_{};
    std::array<std::uint8_t, 20> member6750_{};
    std::array<std::uint8_t, 18> member6751_{};
    std::array<std::uint8_t, 13> member6752_{};
    std::int32_t member6754_{};
    std::array<std::uint8_t, 16> member6756_{};
    std::array<std::uint8_t, 16> member6758_{};
    std::array<std::uint8_t, 16> member6760_{};
    Address member6762_{};
    std::int32_t member6763_{};
    std::int32_t member6764_{};
    std::int32_t member6765_{};
    std::int32_t member6766_{};
    std::int32_t member6767_{};
    String member6768_{};
    std::int32_t member6769_{};
    std::int32_t member6770_{};
    std::int32_t member6771_{};
    std::int32_t member6772_{};
    String member6773_{};
    std::int32_t member6774_{};
    String member6775_{};
    IntRef member6776_{};
    IntRef member6777_{};
    std::int32_t member6778_{};
    std::int32_t member6779_{};
    std::int32_t member6780_{};
    std::int32_t member6781_{};
    std::int32_t member6782_{};
    std::int32_t member6784_{};
    std::int32_t member6785_{};
    std::int32_t member6786_{};
    std::int32_t member6787_{};
    std::int32_t member6788_{};
    std::array<std::uint8_t, 17> member6790_{};
    std::array<std::uint8_t, 18> member6791_{};
    std::array<std::uint8_t, 11> member6792_{};
    std::array<std::uint8_t, 18> member6793_{};
    std::array<std::uint8_t, 11> member6794_{};
    std::array<std::uint8_t, 18> member6795_{};
    std::array<std::uint8_t, 18> member6796_{};
    IntRef member6798_{};
    std::array<std::uint8_t, 9> member6799_{};
    std::array<std::uint8_t, 10> member6800_{};
    std::int32_t member6802_{};
    String member6803_{};
    std::array<std::uint8_t, 10> member6804_{};
    std::int32_t member6806_{};
    std::int32_t member6807_{};
    std::int32_t member6808_{};
    std::int32_t member6809_{};
    std::int32_t member6810_{};
    std::int32_t member6811_{};
    std::array<std::uint8_t, 4> member6812_{};
    std::array<std::uint8_t, 4> member6813_{};
    std::array<std::uint8_t, 18> member6814_{};
    std::array<std::uint8_t, 11> member6815_{};
    std::array<std::uint8_t, 18> member6816_{};
    std::array<std::uint8_t, 18> member6817_{};
    std::array<std::uint8_t, 3> member6818_{};
    std::array<std::uint8_t, 2> member6819_{};
    std::int32_t member6821_{};
    std::int32_t member6822_{};
    std::array<std::uint8_t, 4> member6823_{};
    std::array<std::uint8_t, 4> member6824_{};
    std::int32_t member6825_{};
    std::int32_t member6827_{};
    std::int32_t member6828_{};
    std::int32_t member6829_{};
    std::int32_t member6830_{};
    std::int32_t member6831_{};
    std::array<std::uint8_t, 6> member6832_{};
    String member6833_{};
    String member6834_{};
    std::array<std::uint8_t, 20> member6835_{};
    String member6836_{};
    String member6837_{};
    std::array<std::uint8_t, 23> member6838_{};
    std::int32_t member6840_{};
    std::int32_t member6841_{};
    std::int32_t member6842_{};
    std::int32_t member6843_{};
    std::int32_t member6844_{};
    std::int32_t member6845_{};
    String member6846_{};
    std::array<std::uint8_t, 64> member6848_{};
    String member6850_{};
    std::int32_t member6851_{};
    std::int32_t member6852_{};
    std::int32_t member6853_{};
    std::int32_t member6854_{};
    std::int32_t member6855_{};
    std::int32_t member6856_{};
    std::int32_t member6857_{};
    std::int32_t member6859_{};
    std::int32_t member6860_{};
    std::int32_t member6861_{};
    std::array<std::uint8_t, 64> member6863_{};
    std::array<std::uint8_t, 128> member6865_{};
    std::array<std::uint8_t, 18> member6867_{};
    std::int32_t member6868_{};
    std::int32_t member6869_{};
    String member6870_{};
    std::array<std::uint8_t, 20> member6872_{};
    std::array<std::uint8_t, 17> member6874_{};
    String member6876_{};
    String member6877_{};
    std::array<std::uint8_t, 17> member6878_{};
    std::array<std::uint8_t, 9> member6879_{};
    std::int32_t member6881_{};
    std::int32_t member6882_{};
    std::int32_t member6883_{};
    std::int32_t member6884_{};
    String member6885_{};
    std::int32_t member6886_{};
    std::int32_t member6887_{};
    std::int32_t member6888_{};
    std::int32_t member6890_{};
    std::array<std::uint8_t, 11> member6891_{};
    std::array<std::uint8_t, 13> member6892_{};
    std::int32_t member6893_{};
    std::int32_t member6894_{};
    std::int32_t member6895_{};
    IntRef member6896_{};
    IntRef member6897_{};
    std::array<std::uint8_t, 256> member6899_{};
    std::array<std::uint8_t, 256> member6901_{};
    std::int32_t member6903_{};
    std::int32_t member6904_{};
    std::int32_t member6905_{};
    std::int32_t member6906_{};
    std::int32_t member6908_{};
    IntRef member6909_{};
    std::int32_t member6910_{};
    std::int32_t member6911_{};
    std::int32_t member6912_{};
    std::int32_t member6913_{};
    std::int32_t member6914_{};
    std::int32_t member6915_{};
    std::int32_t member6916_{};
    std::int32_t member6917_{};
    std::int32_t member6918_{};
    std::int32_t member6919_{};
    std::int32_t member6920_{};
    std::int32_t member6921_{};
    std::int32_t member6922_{};
    std::int32_t member6924_{};
    std::int32_t member6925_{};
    std::int32_t member6926_{};
    std::int32_t member6927_{};
    std::array<std::uint8_t, 256> member6929_{};
    std::array<std::int8_t, 20> member6931_{};
    std::int8_t member6933_{};
    std::array<std::uint8_t, 64> member6935_{};
    std::array<std::uint8_t, 9> member6937_{};
    std::array<std::uint8_t, 11> member6938_{};
    std::int32_t member6939_{};
    std::int32_t member6940_{};
    std::array<std::uint8_t, 9> member6941_{};
    String member6942_{};
    std::array<std::uint8_t, 5> member6943_{};
    std::int32_t member6944_{};
    String member6945_{};
    IntRef member6946_{};
    IntRef member6947_{};
    std::int32_t member6948_{};
    std::int32_t member6949_{};
    std::array<std::uint8_t, 21> member6950_{};
    std::int8_t member6951_{};
    std::int32_t member6952_{};
    std::int32_t member6953_{};
    std::int32_t member6954_{};
    std::int32_t member6955_{};
    std::int32_t member6956_{};
    String member6957_{};
    std::int32_t member6959_{};
    std::int32_t member6960_{};
    std::int32_t member6961_{};
    std::array<std::uint8_t, 8> member6963_{};
    String member6965_{};
    float member6966_{};
    std::array<std::uint8_t, 10> member6967_{};
    String member6968_{};
    std::int32_t member6970_{};
    std::int32_t member6971_{};
    std::int32_t member6972_{};
    std::int32_t member6973_{};
    std::array<std::uint8_t, 5> member6974_{};
    std::int32_t member6976_{};
    std::int32_t member6977_{};
    std::array<std::uint8_t, 6> member6978_{};
    std::int32_t member6980_{};
    std::int32_t member6981_{};
    String member6983_{};
    std::array<std::uint8_t, 30> member6984_{};
    std::array<std::uint8_t, 11> member6985_{};
    std::array<std::uint8_t, 28> member6986_{};
    std::array<std::uint8_t, 1> member6987_{};
    String member6988_{};
    std::array<std::uint8_t, 5> member6989_{};
    std::int32_t member6992_{};
    std::int32_t member6993_{};
    std::int32_t member6994_{};
    std::int32_t member6995_{};
    std::array<std::uint8_t, 256> member6997_{};
    String member6999_{};
    std::int8_t member7001_{};
    std::int32_t member7003_{};
    std::int32_t member7004_{};
    std::array<std::uint8_t, 256> member7006_{};
    String member7008_{};
    std::int32_t member7010_{};
    std::int32_t member7012_{};
    std::int32_t member7013_{};
    std::int32_t member7014_{};
    std::int32_t member7015_{};
    std::array<std::uint8_t, 64> member7017_{};
    std::array<std::uint8_t, 8> member7019_{};
    std::array<std::uint8_t, 11> member7020_{};
    std::int32_t member7021_{};
    AddressRef member7022_{};
    std::int32_t member7023_{};
    Address member7024_{};
    std::int32_t member7025_{};
    std::array<std::uint8_t, 20> member7027_{};
    std::array<std::uint8_t, 13> member7029_{};
    std::array<std::uint8_t, 1> member7030_{};
    std::array<std::uint8_t, 19> member7031_{};
    FloatRef member7032_{};
    FloatRef member7033_{};
    float member7034_{};
    float member7035_{};
    String member7037_{};
    String member7038_{};
    String member7039_{};
    std::int32_t member7040_{};
    String member7041_{};
    std::int32_t member7042_{};
    std::int32_t member7043_{};
    String member7044_{};
    std::int32_t member7045_{};
    std::array<std::uint8_t, 256> member7047_{};
    std::array<std::uint8_t, 512> member7049_{};
    std::array<std::uint8_t, 3> member7051_{};
    std::array<std::uint8_t, 11> member7052_{};
    std::array<std::uint8_t, 5> member7053_{};
    String member7054_{};
    std::array<std::uint8_t, 256> member7056_{};
    std::int32_t member7058_{};
    std::array<std::uint8_t, 2> member7059_{};
    std::array<std::uint8_t, 3> member7060_{};
    std::array<std::uint8_t, 4> member7061_{};
    std::int32_t member7063_{};
    std::int32_t member7064_{};
    std::int32_t member7065_{};
    String member7066_{};
    String member7067_{};
    String member7068_{};
    String member7069_{};
    String member7070_{};
    String member7071_{};
    String member7072_{};
    String member7073_{};
    std::array<std::uint8_t, 3> member7074_{};
    std::array<String, 2> member7075_{};
    std::array<std::uint8_t, 11> member7076_{};
    std::array<std::uint8_t, 2> member7077_{};
    std::array<std::uint8_t, 11> member7078_{};
    std::array<std::uint8_t, 18> member7079_{};
    std::array<std::uint8_t, 11> member7080_{};
    std::array<std::uint8_t, 2> member7081_{};
    std::array<std::uint8_t, 11> member7082_{};
    std::array<std::uint8_t, 18> member7083_{};
    std::array<std::uint8_t, 11> member7084_{};
    String member7085_{};
    std::array<std::uint8_t, 18> member7086_{};
    std::array<std::uint8_t, 5> member7087_{};
    std::array<std::uint8_t, 11> member7088_{};
    std::array<std::uint8_t, 11> member7089_{};
    float member7090_{};
    float member7091_{};
    float member7093_{};
    std::array<String, 5> member7094_{};
    std::array<std::uint8_t, 26> member7095_{};
    std::int32_t member7096_{};
    std::int32_t member7097_{};
    String member7098_{};
    std::array<std::uint8_t, 512> member7100_{};
    std::int32_t member7102_{};
    std::array<std::uint8_t, 20> member7103_{};
    std::array<std::uint8_t, 20> member7104_{};
    std::array<std::uint8_t, 18> member7105_{};
    std::int32_t member7107_{};
    std::int32_t member7108_{};
    std::array<std::uint8_t, 9> member7109_{};
    std::int32_t member7110_{};
    std::int32_t member7111_{};
    std::int32_t member7112_{};
    std::int32_t member7113_{};
    std::int32_t member7114_{};
    std::int32_t member7115_{};
    std::array<std::uint8_t, 4> member7116_{};
    std::array<std::uint8_t, 9> member7117_{};
    std::int32_t member7118_{};
    std::array<std::uint8_t, 7> member7119_{};
    std::int32_t member7121_{};
    std::int32_t member7122_{};
    std::array<std::uint8_t, 18> member7123_{};
};

class MbcPlayerWebshop final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPlayerWebshop(Host &host);
    void initializeMembers() override;

  private:
    Task<void> WebShopWindow();
    Value ShowWebShopWindow();
    Task<Value> HideWebShopWindow();
    std::int32_t IsWebShopWindowOn();
    Task<void> helper33_1();
    std::int32_t helper114_1();
    Task<String> helper43_1();
    Task<void> cleanup_WebShopWindow();
    std::int32_t member46_{};
    std::int32_t member7124_{};
    std::int32_t member7125_{};
    std::array<std::uint8_t, 20> member7127_{};
    std::array<std::uint8_t, 256> member7129_{};
    std::int32_t member7131_{};
    std::int32_t member7132_{};
    std::int32_t member7133_{};
    std::int32_t member7134_{};
    std::int32_t member7135_{};
    std::array<std::uint8_t, 14> member7136_{};
    String member7138_{};
    std::int32_t member7139_{};
    std::array<std::uint8_t, 41> member7140_{};
    String member7141_{};
    std::array<std::uint8_t, 10> member7142_{};
    std::array<std::uint8_t, 3> member7143_{};
    String member7144_{};
    std::array<std::uint8_t, 17> member7145_{};
    std::array<std::uint8_t, 9> member7146_{};
    std::array<std::uint8_t, 3> member7147_{};
    std::array<std::uint8_t, 11> member7148_{};
    String member7149_{};
    std::array<std::uint8_t, 14> member7150_{};
    std::array<std::uint8_t, 17> member7151_{};
    std::array<std::uint8_t, 17> member7152_{};
    std::array<std::uint8_t, 4> member7154_{};
    std::array<std::uint8_t, 17> member7156_{};
};

class MbcPuppet final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPuppet(Host &host);
    void initializeMembers() override;

  private:
    std::int32_t GetRealPuppSlotIndex(std::int32_t parameter1);
    Task<void> Puppet();
    std::int32_t DnDResP(std::int32_t parameter1);
    std::int32_t PuppetTrig(std::int32_t parameter1);
    std::int32_t PuppetOn(std::int32_t parameter1);
    std::int32_t IfPuppet();
    std::int32_t PuppetOff();
    Task<void> helper15_1();
    Task<void> cleanup_Puppet();
    ScriptState1 state1_{};
    std::int32_t member534_{};
    std::int32_t member1341_{};
    std::int32_t member7157_{};
    std::int32_t member7158_{};
    std::int32_t member7159_{};
    std::int32_t member7160_{};
    std::int32_t member7162_{};
    IntRef member7163_{};
    IntRef member7164_{};
    IntRef member7165_{};
    std::int32_t member7166_{};
    std::int32_t member7167_{};
    std::int32_t member7168_{};
    std::array<std::int32_t, 40> member7170_{};
    std::int32_t member7172_{};
    std::int32_t member7173_{};
    std::int32_t member7174_{};
    std::int32_t member7175_{};
    std::int32_t member7176_{};
    std::int32_t member7177_{};
    std::int32_t member7178_{};
    std::int32_t member7179_{};
    std::int32_t member7180_{};
    std::int32_t member7181_{};
    std::int32_t member7182_{};
    std::int32_t member7183_{};
    std::int32_t member7184_{};
    std::int32_t member7185_{};
    std::array<std::uint8_t, 64> member7186_{};
    std::array<std::uint8_t, 64> member7189_{};
    String member7191_{};
    std::int8_t member7192_{};
    std::array<std::uint8_t, 256> member7194_{};
    std::int32_t member7196_{};
    String member7197_{};
    std::array<std::uint8_t, 7> member7198_{};
    std::array<std::uint8_t, 8> member7199_{};
    std::array<std::uint8_t, 9> member7200_{};
    std::array<std::uint8_t, 4> member7201_{};
    String member7202_{};
    std::array<std::uint8_t, 7> member7203_{};
    std::array<std::uint8_t, 9> member7204_{};
    std::array<std::uint8_t, 19> member7205_{};
    String member7206_{};
    String member7207_{};
    std::array<std::uint8_t, 9> member7208_{};
    std::array<std::uint8_t, 7> member7209_{};
    std::int32_t member7211_{};
    std::int32_t member7212_{};
    std::int32_t member7213_{};
    std::int32_t member7215_{};
    std::int32_t member7216_{};
    std::array<std::uint8_t, 9> member7217_{};
    std::array<std::uint8_t, 11> member7218_{};
    String member7219_{};
    std::array<std::uint8_t, 15> member7220_{};
    String member7221_{};
    String member7222_{};
    std::array<std::uint8_t, 18> member7223_{};
    String member7224_{};
    String member7225_{};
    String member7226_{};
    std::int32_t member7228_{};
    std::int32_t member7229_{};
    std::int32_t member7230_{};
    std::int32_t member7231_{};
    std::int32_t member7232_{};
    std::int32_t member7233_{};
    std::array<std::uint8_t, 14> member7234_{};
    std::array<std::uint8_t, 9> member7235_{};
    std::array<std::uint8_t, 10> member7236_{};
    std::array<std::uint8_t, 14> member7237_{};
    std::array<std::uint8_t, 7> member7238_{};
    std::array<std::uint8_t, 14> member7239_{};
    String member7240_{};
    std::array<std::uint8_t, 11> member7241_{};
    std::array<std::uint8_t, 9> member7242_{};
    std::array<std::uint8_t, 8> member7243_{};
    String member7244_{};
    std::array<std::uint8_t, 5> member7245_{};
    std::array<std::uint8_t, 5> member7246_{};
    std::array<std::uint8_t, 8> member7247_{};
    std::array<std::uint8_t, 6> member7248_{};
    std::array<std::uint8_t, 6> member7249_{};
    std::array<std::uint8_t, 9> member7250_{};
    std::array<std::uint8_t, 6> member7251_{};
    std::int32_t member7252_{};
    std::int32_t member7253_{};
    std::array<std::uint8_t, 15> member7254_{};
    std::int32_t member7255_{};
    std::int32_t member7256_{};
    std::int32_t member7257_{};
};

class MbcStat final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStat(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Server();
    Task<void> EInit();
    Task<void> Client();
    std::int32_t NumOfPlayers();
    std::int32_t member46_{};
    std::array<std::uint8_t, 12> member7258_{};
    std::int32_t member7260_{};
};

class MbcTable final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTable(Host &host);
    void initializeMembers() override;

  private:
    Task<Value> RefreshClanSymb2(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> Table();
    Task<void> WinSelcount();
    Task<std::int32_t> TableTrig(std::int32_t parameter1);
    Task<std::int32_t> TableOn(std::int32_t parameter1);
    std::int32_t TableOff();
    std::int32_t addStringToTableList(std::int32_t parameter1, String parameter2, String parameter3, std::int32_t parameter4, IntRef parameter5);
    Task<void> helper13_1();
    Task<void> helper74_1();
    Task<void> helper113_1();
    Task<void> cleanup_Table();
    ScriptState1 state1_{};
    ScriptState34 state34_{};
    std::int32_t member7261_{};
    std::array<std::uint8_t, 128> member7262_{};
    std::array<std::uint8_t, 128> member7264_{};
    std::int32_t member7266_{};
    std::int32_t member7267_{};
    String member7268_{};
    std::array<std::uint8_t, 64> member7270_{};
    std::array<std::uint8_t, 20> member7272_{};
    std::array<std::uint8_t, 17> member7274_{};
    std::array<std::uint8_t, 8> member7275_{};
    std::array<std::uint8_t, 6> member7276_{};
    std::array<std::uint8_t, 9> member7277_{};
    std::int32_t member7279_{};
    std::int32_t member7280_{};
    std::int32_t member7281_{};
    std::int32_t member7282_{};
    std::int32_t member7283_{};
    std::int32_t member7284_{};
    std::int32_t member7285_{};
    std::int32_t member7286_{};
    std::int32_t member7287_{};
    std::int32_t member7288_{};
    std::int32_t member7289_{};
    std::int32_t member7290_{};
    std::int32_t member7291_{};
    std::int32_t member7292_{};
    std::int32_t member7294_{};
    std::int32_t member7295_{};
    std::array<std::uint8_t, 20> member7297_{};
    std::array<String, 6> member7299_{};
    IntRef member7301_{};
    IntRef member7302_{};
    IntRef member7303_{};
    AddressRef member7304_{};
    String member7305_{};
    String member7306_{};
    String member7307_{};
    String member7308_{};
    String member7309_{};
    String member7310_{};
    std::array<std::int32_t, 75> member7312_{};
    std::int32_t member7314_{};
    std::int32_t member7315_{};
    std::int32_t member7316_{};
    std::int32_t member7317_{};
    std::int32_t member7318_{};
    std::int32_t member7319_{};
    std::int32_t member7320_{};
    std::int32_t member7321_{};
    std::int32_t member7323_{};
    std::int32_t member7324_{};
    std::int32_t member7325_{};
    std::int32_t member7326_{};
    std::int32_t member7327_{};
    IntRef member7328_{};
    IntRef member7329_{};
    IntRef member7330_{};
    std::array<std::uint8_t, 64> member7332_{};
    std::array<std::uint8_t, 1024> member7334_{};
    std::array<std::uint8_t, 64> member7336_{};
    String member7338_{};
    std::array<std::uint8_t, 9> member7339_{};
    std::array<std::uint8_t, 9> member7340_{};
    std::array<std::uint8_t, 9> member7341_{};
    std::array<std::uint8_t, 9> member7342_{};
    std::array<std::uint8_t, 9> member7343_{};
    std::array<std::uint8_t, 10> member7344_{};
    std::array<std::uint8_t, 15> member7346_{};
    std::array<std::uint8_t, 3> member7348_{};
    std::array<std::uint8_t, 16> member7349_{};
    std::array<std::uint8_t, 11> member7350_{};
    String member7351_{};
    std::int32_t member7353_{};
    std::array<std::uint8_t, 16> member7354_{};
    std::array<std::uint8_t, 7> member7355_{};
    std::array<std::uint8_t, 9> member7356_{};
    String member7357_{};
    std::array<std::uint8_t, 9> member7358_{};
    std::array<std::uint8_t, 4> member7359_{};
    String member7360_{};
    std::array<std::uint8_t, 7> member7361_{};
    std::array<std::uint8_t, 9> member7362_{};
    std::array<std::uint8_t, 9> member7363_{};
    String member7364_{};
    std::array<std::uint8_t, 11> member7365_{};
    String member7366_{};
    String member7367_{};
    std::array<std::uint8_t, 3> member7368_{};
    float member7369_{};
    float member7370_{};
    std::array<std::uint8_t, 8> member7371_{};
    std::array<std::uint8_t, 13> member7372_{};
    std::array<std::uint8_t, 1> member7373_{};
    std::array<std::uint8_t, 3> member7374_{};
    std::array<std::uint8_t, 10> member7375_{};
    std::array<std::uint8_t, 3> member7376_{};
    std::array<std::uint8_t, 16> member7377_{};
    String member7378_{};
    std::array<std::uint8_t, 5> member7379_{};
    std::array<std::uint8_t, 5> member7380_{};
    std::int32_t member7381_{};
    std::array<std::uint8_t, 15> member7382_{};
    std::int8_t member7383_{};
    std::array<std::uint8_t, 9> member7389_{};
    String member7390_{};
    std::array<std::uint8_t, 16> member7392_{};
    std::int32_t member7393_{};
    std::int32_t member7394_{};
    String member7395_{};
    std::array<std::uint8_t, 7> member7396_{};
    std::int32_t member7397_{};
    String member7398_{};
    String member7399_{};
    std::int32_t member7400_{};
    IntRef member7401_{};
    std::int32_t member7402_{};
    std::int32_t member7403_{};
};

class MbcTrade final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTrade(Host &host);
    void initializeMembers() override;

  private:
    Task<void> Trade();
    Task<void> checkOpenWorkshop();
    Task<void> helper53_1();
    Task<void> helper34_1();
    Task<void> cleanup_Trade();
    ScriptState1 state1_{};
    ScriptState30 state30_{};
    ScriptState34 state34_{};
    ScriptState45 state45_{};
    std::array<std::uint8_t, 128> member7405_{};
    std::array<std::uint8_t, 512> member7407_{};
    std::int32_t member7439_{};
    std::array<String, 75> member7441_{};
    IntRef member7443_{};
    IntRef member7444_{};
    IntRef member7445_{};
    IntRef member7446_{};
    std::array<std::int32_t, 75> member7448_{};
    std::array<IntRef, 75> member7450_{};
    std::array<IntRef, 75> member7452_{};
    std::array<IntRef, 75> member7454_{};
    IntRef member7456_{};
    IntRef member7457_{};
    IntRef member7458_{};
    std::int32_t member7459_{};
    std::int32_t member7460_{};
    std::array<std::int32_t, 75> member7462_{};
    std::array<std::int32_t, 75> member7464_{};
    std::int32_t member7466_{};
    std::int32_t member7467_{};
    std::int32_t member7468_{};
    std::int32_t member7469_{};
    std::int32_t member7470_{};
    std::int32_t member7471_{};
    std::int32_t member7472_{};
    std::int32_t member7473_{};
    std::int32_t member7474_{};
    std::int32_t member7475_{};
    std::int32_t member7476_{};
    std::array<std::uint8_t, 64> member7478_{};
    std::int32_t member7480_{};
    std::int32_t member7481_{};
    std::int32_t member7482_{};
    std::int32_t member7483_{};
    std::int32_t member7484_{};
    std::int32_t member7485_{};
    std::int32_t member7486_{};
    std::int32_t member7487_{};
    std::int32_t member7488_{};
    std::int32_t member7489_{};
    std::int32_t member7490_{};
    std::int32_t member7491_{};
    std::int32_t member7493_{};
    std::int32_t member7495_{};
    std::int32_t member7496_{};
    std::int32_t member7497_{};
    std::int32_t member7498_{};
    std::array<std::uint8_t, 2524> member7500_{};
    std::array<std::uint8_t, 4096> member7502_{};
    std::array<std::uint8_t, 4096> member7504_{};
    std::array<std::uint8_t, 8> member7506_{};
    std::array<std::uint8_t, 8> member7508_{};
    std::int32_t member7510_{};
    std::int32_t member7511_{};
    std::int32_t member7512_{};
    String member7513_{};
    std::int32_t member7514_{};
    String member7515_{};
    std::int32_t member7516_{};
    std::int32_t member7517_{};
    std::array<std::uint8_t, 18> member7518_{};
    std::array<std::uint8_t, 10> member7519_{};
    std::array<std::uint8_t, 4> member7520_{};
    std::array<std::uint8_t, 4> member7521_{};
    std::array<std::uint8_t, 11> member7522_{};
    std::array<std::uint8_t, 18> member7523_{};
    std::array<std::uint8_t, 14> member7524_{};
    std::array<std::uint8_t, 14> member7525_{};
    std::array<std::uint8_t, 4> member7526_{};
    std::array<std::uint8_t, 7> member7527_{};
    std::array<std::uint8_t, 8> member7528_{};
    std::array<std::uint8_t, 9> member7529_{};
    std::array<std::uint8_t, 11> member7530_{};
    std::array<std::uint8_t, 14> member7531_{};
    String member7532_{};
    std::array<std::uint8_t, 21> member7533_{};
    std::array<std::uint8_t, 9> member7534_{};
    std::array<std::uint8_t, 9> member7535_{};
    std::array<std::uint8_t, 6> member7536_{};
    String member7537_{};
    std::array<std::uint8_t, 8> member7538_{};
    std::array<std::uint8_t, 13> member7539_{};
    std::array<std::uint8_t, 21> member7540_{};
    String member7541_{};
    std::array<std::uint8_t, 7> member7542_{};
    std::array<std::uint8_t, 21> member7543_{};
    std::array<std::uint8_t, 1> member7544_{};
    std::array<std::uint8_t, 10> member7545_{};
    std::array<std::uint8_t, 9> member7546_{};
    String member7547_{};
    std::array<std::uint8_t, 21> member7548_{};
    std::array<std::uint8_t, 21> member7549_{};
    std::array<std::uint8_t, 9> member7550_{};
    String member7551_{};
    std::int32_t member7552_{};
    String member7553_{};
    std::array<std::uint8_t, 9> member7554_{};
    std::array<std::uint8_t, 13> member7555_{};
    std::array<std::uint8_t, 14> member7556_{};
    String member7557_{};
    std::array<std::uint8_t, 25> member7558_{};
    std::array<std::uint8_t, 3> member7559_{};
    std::array<std::uint8_t, 10> member7560_{};
    float member7562_{};
    float member7563_{};
    std::int32_t member7564_{};
    std::int32_t member7565_{};
    std::int32_t member7566_{};
    std::array<std::uint8_t, 10> member7567_{};
    std::array<std::uint8_t, 8> member7568_{};
    std::array<std::uint8_t, 9> member7569_{};
    std::array<std::uint8_t, 13> member7570_{};
    std::array<std::uint8_t, 3> member7571_{};
    std::array<std::uint8_t, 2> member7572_{};
    String member7573_{};
    std::array<std::uint8_t, 7> member7574_{};
    std::array<std::uint8_t, 4> member7575_{};
    std::array<std::uint8_t, 3> member7576_{};
    std::array<std::uint8_t, 5> member7577_{};
    std::array<std::uint8_t, 3> member7578_{};
    std::array<std::uint8_t, 8> member7579_{};
    std::array<std::uint8_t, 13> member7580_{};
    std::array<std::uint8_t, 9> member7581_{};
    std::array<std::uint8_t, 5> member7582_{};
    std::array<std::uint8_t, 5> member7583_{};
    String member7584_{};
    std::int32_t member7586_{};
    String member7587_{};
    std::array<std::uint8_t, 8> member7588_{};
    std::array<std::uint8_t, 4> member7589_{};
    std::array<std::uint8_t, 1> member7590_{};
    String member7591_{};
    std::array<std::uint8_t, 7> member7592_{};
    std::array<std::uint8_t, 3> member7593_{};
    std::array<std::uint8_t, 1> member7594_{};
    std::array<std::uint8_t, 22> member7595_{};
    std::array<std::uint8_t, 18> member7596_{};
    std::array<std::uint8_t, 18> member7597_{};
    std::array<std::uint8_t, 27> member7598_{};
    String member7599_{};
    std::array<std::uint8_t, 14> member7600_{};
    std::array<std::uint8_t, 4> member7601_{};
    std::array<std::uint8_t, 18> member7602_{};
    std::array<std::uint8_t, 21> member7603_{};
    std::array<std::uint8_t, 17> member7604_{};
    std::array<std::uint8_t, 21> member7605_{};
    std::array<std::uint8_t, 18> member7606_{};
};

class MbcTradegold final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTradegold(Host &host);
    void initializeMembers() override;

  private:
    ScriptState1 state1_{};
    ScriptState34 state34_{};
    ScriptState45 state45_{};
};

class MbcAlFlower final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcAlFlower(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState17 state17_{};
    ScriptState18 state18_{};
};

class MbcAlMetal final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcAlMetal(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState18 state18_{};
};

class MbcAlMineral final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcAlMineral(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState18 state18_{};
};

class MbcArAmulet final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArAmulet(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArAmuletRefr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArAmuletRefr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArAmuletf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArAmuletf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArAmuletu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArAmuletu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArArmor final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArArmor(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArArmor2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArArmor2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArArmor2f final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArArmor2f(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArArmor2u final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArArmor2u(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArArmorf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArArmorf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArArmoru final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArArmoru(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArBelt final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArBelt(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArBeltf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArBeltf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArBeltu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArBeltu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArBracelet final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArBracelet(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArBraceletf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArBraceletf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArBraceletu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArBraceletu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArGloves final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArGloves(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArGlovesf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArGlovesf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArGlovesu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArGlovesu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArHelm final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArHelm(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArHelmPr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArHelmPr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArHelmf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArHelmf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArHelmu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArHelmu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArPants final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArPants(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArPantsf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArPantsf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArPantsu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArPantsu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArRing final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArRing(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Value LoadGame5();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
    std::array<std::uint8_t, 16> member7926_{};
    std::array<std::uint8_t, 16> member7928_{};
};

class MbcArRingS final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArRingS(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
    std::int8_t member7931_{};
    std::int8_t member7932_{};
};

class MbcArRingf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArRingf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArRingu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArRingu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArShield final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShield(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArShieldf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShieldf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArShieldu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShieldu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArShoes final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShoes(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArShoes2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShoes2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState17 state17_{};
    ScriptState46 state46_{};
};

class MbcArShoes2u final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShoes2u(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState17 state17_{};
    ScriptState46 state46_{};
};

class MbcArShoesf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShoesf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcArShoesu final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcArShoesu(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcClaimBlank final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcClaimBlank(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState18 state18_{};
};

class MbcClanlicence final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcClanlicence(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcCrt02 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrt02(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::array<std::uint8_t, 2> member8253_{};
};

class MbcCrt03 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrt03(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::array<std::uint8_t, 2> member8253_{};
};

class MbcCrt51 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrt51(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::array<std::uint8_t, 2> member8253_{};
};

class MbcCrystal final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrystal(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState47 state47_{};
};

class MbcCrystalAttrA final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrystalAttrA(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
};

class MbcCrystalAttrB final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrystalAttrB(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
};

class MbcCrystalAttrC final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrystalAttrC(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
};

class MbcCrystalAttrD final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrystalAttrD(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
};

class MbcCrystalc final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrystalc(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState47 state47_{};
};

class MbcCrystalcattr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCrystalcattr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    std::int32_t ADDCO();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcCsChest final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCsChest(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetParam2(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, IntRef parameter4, IntRef parameter5, IntRef parameter6, IntRef parameter7, IntRef parameter8, IntRef parameter9, IntRef parameter10, IntRef parameter11);
    IntRef GetP(std::int32_t parameter1);
    Task<void> ContMan();
    void sendslot(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> TestIt(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> SeekTag(std::int32_t parameter1);
    std::int32_t SeekTagInsideNoRecursive(std::int32_t parameter1);
    Task<std::int32_t> SetOverFill(std::int32_t parameter1);
    Task<std::int32_t> TestPut(std::int32_t parameter1);
    std::int32_t AddWght(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t FreeIt1(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    std::int32_t GetSlotID(std::int32_t parameter1);
    std::int32_t isSlotOccupied(std::int32_t parameter1);
    std::int32_t TestMe(std::int32_t parameter1);
    std::int32_t GetMySlot(std::int32_t parameter1);
    std::int32_t openSlot(std::int32_t parameter1, String parameter2, String parameter3);
    Task<std::int32_t> CheckOpenRights(std::int32_t parameter1);
    Task<Value> GetClanName(String parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    String member8551_{};
    std::array<std::uint8_t, 18> member8552_{};
    std::array<std::uint8_t, 296> member8527_{};
    std::array<std::uint8_t, 296> member8529_{};
    std::array<std::int32_t, 74> member8533_{};
    std::array<std::uint8_t, 4> member8536_{};
    std::array<std::uint8_t, 4> member8537_{};
    std::array<std::uint8_t, 221> member8588_{};
    std::int32_t member8589_{};
    std::array<std::uint8_t, 20> member8591_{};
    std::array<std::uint8_t, 4> member8593_{};
    std::array<std::uint8_t, 4> member8594_{};
    std::int32_t member8596_{};
    String member8597_{};
    std::array<std::uint8_t, 4> member8598_{};
    std::array<std::uint8_t, 4> member8599_{};
};

class MbcCsGate final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCsGate(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> Client();
    Task<void> RunClanEffect();
    Task<void> ClanEffect();
    Task<void> Main();
    String pModelName();
    Task<void> selfHealPrg();
    Task<String> RcvUser5(std::int32_t parameter1, String parameter2);
    Value LoadGame5();
    std::int32_t SaveGame();
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> GateOn();
    std::int32_t UseClient();
    Task<void> GateOpen();
    std::int32_t lid2(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> toutopen();
    void SelfHeal(std::int32_t parameter1);
    std::int32_t EffectWrapper(std::int32_t parameter1, std::int32_t parameter2);
    void StopEffect(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    std::int32_t member8612_{};
    std::array<std::uint8_t, 3> member8644_{};
    std::array<std::uint8_t, 5> member8676_{};
    std::int32_t member8716_{};
    std::array<std::uint8_t, 3> member8717_{};
    std::array<std::uint8_t, 4> member8718_{};
    String member8719_{};
    std::array<std::uint8_t, 9> member8720_{};
    std::array<std::uint8_t, 20> member8722_{};
    std::array<Address, 2> member8726_{};
    std::int32_t member8727_{};
    std::int32_t member8728_{};
    std::int32_t member8729_{};
    std::int32_t member8730_{};
    std::int32_t member8732_{};
    std::int32_t member8734_{};
    std::int32_t member8735_{};
    std::int32_t member8736_{};
    std::int32_t member8737_{};
    std::int32_t member8738_{};
    std::array<std::uint8_t, 6> member8739_{};
    std::array<std::uint8_t, 6> member8740_{};
    std::array<std::uint8_t, 6> member8741_{};
    std::array<std::uint8_t, 9> member8745_{};
    std::array<std::uint8_t, 6> member8759_{};
    std::int32_t member8761_{};
    std::int32_t member8762_{};
    float member8763_{};
    std::int32_t member8771_{};
    std::int32_t member8772_{};
    std::int32_t member8773_{};
    std::array<float, 3> member8775_{};
    float member8776_{};
    float member8777_{};
    std::array<std::uint8_t, 6> member8779_{};
    std::array<std::uint8_t, 6> member8780_{};
    std::int32_t member8781_{};
};

class MbcCsGuard final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCsGuard(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    void GetClanName2(std::int32_t parameter1, String parameter2);
    void SetClanName(std::int32_t parameter1, String parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::array<std::uint8_t, 2> member8843_{};
    std::int32_t member8880_{};
    String member8881_{};
    std::int32_t member8882_{};
    String member8883_{};
};

class MbcCsKnot final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCsKnot(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    Task<std::int32_t> SndUser2(String parameter1);
    Task<void> KnotEff();
    Task<std::int32_t> setFill(std::int32_t parameter1, String parameter2);
    Task<Value> CountKnot();
    Task<void> GetGate();
    std::int32_t SetLvl(std::int32_t parameter1);
    std::int32_t SetUsedElixirTime(std::int32_t parameter1);
    std::int32_t GetUsedElixirTime();
    void helper107_1();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::int32_t member8884_{};
    std::int32_t member8885_{};
    std::int32_t member8886_{};
    std::int32_t member8887_{};
    std::int32_t member8888_{};
    std::int32_t member8889_{};
    std::int32_t member8890_{};
    std::int32_t member8891_{};
    std::int32_t member8892_{};
    std::int32_t member8893_{};
    std::int32_t member8894_{};
    std::int32_t member8895_{};
    std::array<std::uint8_t, 5> member8952_{};
    std::array<std::uint8_t, 4> member8953_{};
    std::array<std::uint8_t, 8> member8954_{};
    std::array<std::uint8_t, 4> member8956_{};
    std::int32_t member8959_{};
    std::int32_t member8960_{};
    std::int32_t member8961_{};
    std::int32_t member8962_{};
    std::int32_t member8963_{};
    std::int32_t member8964_{};
    std::array<std::uint8_t, 6> member8965_{};
    std::array<std::uint8_t, 6> member8966_{};
    std::int32_t member8967_{};
    String member8968_{};
    std::array<std::uint8_t, 16> member8969_{};
    std::array<std::uint8_t, 17> member8970_{};
    std::array<std::uint8_t, 16> member8971_{};
    std::array<std::uint8_t, 23> member8972_{};
    std::array<std::uint8_t, 16> member8973_{};
    std::array<String, 6> member8974_{};
    std::array<std::uint8_t, 16> member8975_{};
    std::array<String, 6> member8976_{};
    std::int32_t member8977_{};
    std::int32_t member8978_{};
    std::int32_t member8979_{};
    std::array<std::uint8_t, 5> member8980_{};
    std::array<std::uint8_t, 5> member8981_{};
    std::array<std::uint8_t, 9> member8982_{};
    std::array<std::uint8_t, 14> member8983_{};
    std::array<std::uint8_t, 14> member8984_{};
    std::array<std::uint8_t, 9> member8985_{};
    std::array<std::uint8_t, 14> member8986_{};
    std::array<std::uint8_t, 14> member8987_{};
    std::array<std::uint8_t, 9> member8988_{};
    std::array<std::uint8_t, 14> member8989_{};
    std::array<std::uint8_t, 14> member8990_{};
    std::array<std::uint8_t, 14> member8991_{};
    std::array<std::uint8_t, 14> member8992_{};
    std::array<std::uint8_t, 5> member8993_{};
    std::array<std::uint8_t, 9> member8994_{};
    std::int32_t member8995_{};
    std::int32_t member8996_{};
};

class MbcCsTable final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCsTable(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    std::int32_t NPL(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4, String parameter5, std::int32_t parameter6, String parameter7, String parameter8);
    std::int32_t getUpgradeMoney();
    void BankOper2(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<void> CastProgressBar();
    Task<void> Capture_Progress_on_client();
    Task<void> cleanup_CastProgressBar();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    std::int32_t member911_{};
    std::int32_t member9168_{};
    ScriptState48 state48_{};
    std::array<std::uint8_t, 20> member8998_{};
    std::int32_t member9015_{};
    std::array<std::uint8_t, 5> member9026_{};
    String member9042_{};
    std::int32_t member9123_{};
    std::int32_t member9125_{};
    std::int32_t member9126_{};
    std::int32_t member9127_{};
    std::array<std::uint8_t, 18> member9128_{};
    std::int32_t member9130_{};
    std::int32_t member9131_{};
    std::int32_t member9132_{};
    std::int32_t member9133_{};
    std::int32_t member9134_{};
    std::int32_t member9135_{};
    std::array<std::uint8_t, 32> member9137_{};
    std::int32_t member9139_{};
    std::int32_t member9140_{};
    std::array<std::uint8_t, 26> member9160_{};
    std::array<std::uint8_t, 21> member9161_{};
    Address member9163_{};
    std::array<std::uint8_t, 21> member9164_{};
    std::array<std::uint8_t, 7> member9165_{};
};

class MbcCtBag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtBag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
};

class MbcCtBagHerb final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtBagHerb(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
};

class MbcCtBagd final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtBagd(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
};

class MbcCtBarn final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtBarn(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<std::int32_t> OpenB(std::int32_t parameter1);
    Task<void> CheckUseDist();
    String RcvUser4(std::int32_t parameter1, String parameter2);
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState41 state41_{};
    std::int32_t member9280_{};
    std::int32_t member9344_{};
    std::array<std::uint8_t, 5> member9345_{};
    std::int32_t member9347_{};
    Address member9348_{};
};

class MbcCtCbag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtCbag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<std::int32_t> TestPut(std::int32_t parameter1);
    std::int32_t AddWght(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t FreeIt1(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    ScriptState23 state23_{};
};

class MbcCtCbook1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtCbook1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> MainCBook();
    Task<void> UseAll();
    Task<void> WinMacros();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState49 state49_{};
    std::array<std::uint8_t, 384> member9493_{};
    std::array<std::uint8_t, 12> member9495_{};
    std::array<std::uint8_t, 7> member9511_{};
    std::array<std::uint8_t, 4> member9512_{};
    std::array<std::uint8_t, 10> member9513_{};
    std::array<std::uint8_t, 11> member9514_{};
    std::array<std::uint8_t, 29> member9637_{};
};

class MbcCtCbook2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtCbook2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> MainCBook();
    Task<void> UseAll();
    Task<void> WinMacros();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState49 state49_{};
    std::array<std::uint8_t, 640> member9651_{};
    std::array<std::uint8_t, 20> member9653_{};
    std::array<std::uint8_t, 10> member9658_{};
    std::array<std::uint8_t, 10> member9659_{};
    std::array<std::uint8_t, 11> member9660_{};
};

class MbcCtChest1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChest1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    ScriptState27 state27_{};
};

class MbcCtChest2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChest2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    std::int32_t AddWght(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t FreeIt1(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    ScriptState31 state31_{};
    std::array<String, 2> member9783_{};
    std::array<std::uint8_t, 3> member9784_{};
};

class MbcCtChest3 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChest3(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
};

class MbcCtChest4 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChest4(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t SETMON(std::int32_t parameter1, String parameter2);
    std::int32_t RVCT();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::int32_t member9843_{};
    std::array<std::uint8_t, 64> member9840_{};
    std::int32_t member9842_{};
    String member9844_{};
};

class MbcCtChest5 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChest5(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
};

class MbcCtChest6 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChest6(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    ScriptState27 state27_{};
    std::array<std::uint8_t, 4> member9944_{};
};

class MbcCtChest7 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChest7(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    IntRef GetP(std::int32_t parameter1);
    Task<void> ContMan();
    void sendslot(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> TestIt(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> SeekTag(std::int32_t parameter1);
    std::int32_t SeekTagInsideNoRecursive(std::int32_t parameter1);
    Task<std::int32_t> SetOverFill(std::int32_t parameter1);
    Task<std::int32_t> TestPut(std::int32_t parameter1);
    std::int32_t AddWght(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t FreeIt1(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    std::int32_t GetSlotID(std::int32_t parameter1);
    std::int32_t isSlotOccupied(std::int32_t parameter1);
    std::int32_t TestMe(std::int32_t parameter1);
    std::int32_t GetMySlot(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::array<String, 2> member9783_{};
    std::array<std::uint8_t, 3> member9784_{};
    std::array<std::uint8_t, 160> member9946_{};
    std::array<std::uint8_t, 160> member9948_{};
    std::array<std::int32_t, 40> member9952_{};
};

class MbcCtChestPr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtChestPr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    IntRef GetP(std::int32_t parameter1);
    Task<void> ContMan();
    void sendslot(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> TestIt(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> SeekTag(std::int32_t parameter1);
    std::int32_t SeekTagInsideNoRecursive(std::int32_t parameter1);
    Task<std::int32_t> SetOverFill(std::int32_t parameter1);
    Task<std::int32_t> TestPut(std::int32_t parameter1);
    std::int32_t AddWght(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t FreeIt1(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    std::int32_t GetSlotID(std::int32_t parameter1);
    std::int32_t isSlotOccupied(std::int32_t parameter1);
    std::int32_t TestMe(std::int32_t parameter1);
    std::int32_t GetMySlot(std::int32_t parameter1);
    Task<void> Main();
    Task<void> RG();
    std::int32_t SndUser(String parameter1);
    std::int32_t GetLetter(std::int32_t parameter1, String parameter2);
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    String member8551_{};
    std::array<std::uint8_t, 18> member8552_{};
    std::array<std::uint8_t, 128> member9996_{};
    std::array<std::uint8_t, 128> member9998_{};
    std::array<std::int32_t, 32> member10002_{};
    std::array<std::uint8_t, 3> member10038_{};
    std::int32_t member10040_{};
    std::array<std::uint8_t, 10> member10042_{};
    std::int32_t member10044_{};
    std::array<std::uint8_t, 8> member10045_{};
    std::array<std::uint8_t, 6> member10046_{};
    std::array<std::uint8_t, 13> member10047_{};
    std::int32_t member10048_{};
    String member10049_{};
};

class MbcCtGbag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtGbag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
};

class MbcCtIbag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtIbag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    Task<std::int32_t> AddWght2(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> FreeIt12(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
};

class MbcCtJar final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtJar(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    ScriptState32 state32_{};
};

class MbcCtLab final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtLab(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t SETMON(std::int32_t parameter1, String parameter2);
    Task<void> ContMan();
    std::int32_t RVCT();
    std::int32_t OBZVR(std::int32_t parameter1);
    Task<Value> RcvUser3(std::int32_t parameter1, String parameter2);
    void LoadModel(float parameter1, float parameter2, float parameter3, float parameter4, float parameter5, float parameter6);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::array<std::uint8_t, 10> member10294_{};
    std::int32_t member9843_{};
    std::int32_t member10202_{};
    std::int32_t member10203_{};
    std::int32_t member10204_{};
    std::array<std::uint8_t, 32> member10206_{};
    std::array<std::uint8_t, 20> member10207_{};
    std::array<std::uint8_t, 160> member10209_{};
    std::array<std::uint8_t, 160> member10211_{};
    std::array<std::uint8_t, 160> member10213_{};
    std::array<std::uint8_t, 160> member10215_{};
    std::array<std::uint8_t, 160> member10216_{};
    std::array<std::uint8_t, 160> member10217_{};
    String member10219_{};
    std::int32_t member10277_{};
    std::int32_t member10278_{};
    std::int8_t member10279_{};
    std::int8_t member10284_{};
    std::array<std::uint8_t, 6> member10285_{};
    std::array<std::uint8_t, 7> member10286_{};
    std::array<std::uint8_t, 5> member10287_{};
    std::array<std::uint8_t, 8> member10288_{};
    std::array<std::uint8_t, 8> member10289_{};
    std::array<std::uint8_t, 8> member10290_{};
    std::array<std::uint8_t, 8> member10291_{};
    std::array<std::uint8_t, 8> member10292_{};
    std::array<std::uint8_t, 8> member10293_{};
    std::array<std::uint8_t, 18> member10295_{};
    std::array<std::uint8_t, 18> member10296_{};
    float member10297_{};
    float member10298_{};
    float member10299_{};
    float member10300_{};
    float member10301_{};
    float member10302_{};
    std::int32_t member10303_{};
};

class MbcCtMapbook final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtMapbook(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
};

class MbcCtMbag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtMbag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LID(std::int32_t parameter1);
    Task<void> ContMan();
    Task<std::int32_t> TestPut(std::int32_t parameter1);
    std::int32_t openSlot(std::int32_t parameter1, String parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    ScriptState23 state23_{};
    std::int32_t member10341_{};
    std::int32_t member10342_{};
    std::array<std::uint8_t, 14> member10386_{};
};

class MbcCtMbook final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtMbook(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
};

class MbcCtMbook1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtMbook1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member165_{};
};

class MbcCtMbook2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtMbook2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    Task<std::int32_t> AddWght2(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> FreeIt12(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member165_{};
    ScriptState27 state27_{};
};

class MbcCtMbook3 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtMbook3(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member165_{};
};

class MbcCtMbook4 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtMbook4(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member165_{};
};

class MbcCtRbook final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtRbook(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    Task<std::int32_t> AddWght2(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> FreeIt12(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member165_{};
    ScriptState31 state31_{};
};

class MbcCtSacM final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtSacM(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState11 state11_{};
};

class MbcCtSacP final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtSacP(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    ScriptState32 state32_{};
};

class MbcCtSacS final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtSacS(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    String LoadGame3();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member165_{};
    std::array<std::uint8_t, 11> member10676_{};
};

class MbcCtSbag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtSbag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 5> member10707_{};
};

class MbcCtUbag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcCtUbag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
};

class MbcDoor1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcDoor1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t SndUser(String parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::int32_t member10791_{};
    std::int32_t member10772_{};
    std::array<Address, 2> member10773_{};
    std::int32_t member10778_{};
    std::int32_t member10779_{};
    Address member10780_{};
    std::int32_t member10782_{};
    std::array<std::uint8_t, 21> member10783_{};
    std::array<std::uint8_t, 6> member10784_{};
    std::array<std::uint8_t, 9> member10785_{};
    String member10786_{};
    std::array<std::uint8_t, 7> member10787_{};
    Address member10789_{};
    std::array<std::uint8_t, 21> member10793_{};
    std::array<std::uint8_t, 18> member10794_{};
    std::array<std::uint8_t, 6> member10795_{};
};

class MbcDoor2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcDoor2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t SndUser(String parameter1);
    Task<Value> LoadGame4();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::array<Address, 2> member10841_{};
    String member10843_{};
    String member10845_{};
    std::array<std::uint8_t, 4> member10847_{};
    std::array<std::uint8_t, 4> member10848_{};
    std::array<std::uint8_t, 4> member10849_{};
    std::array<std::uint8_t, 4> member10850_{};
    std::int32_t member10852_{};
    std::int32_t member10854_{};
    std::int32_t member10855_{};
    Address member10856_{};
    std::array<std::uint8_t, 17> member10857_{};
    std::array<std::uint8_t, 13> member10858_{};
    std::array<std::uint8_t, 19> member10859_{};
    std::array<std::uint8_t, 16> member10860_{};
};

class MbcDoorLk final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcDoorLk(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t SndUser(String parameter1);
    Task<std::int32_t> AppKey(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    std::array<Address, 2> member10896_{};
    std::int32_t member10873_{};
    String member10880_{};
    std::array<std::uint8_t, 11> member10881_{};
    std::array<std::uint8_t, 6> member10882_{};
    std::int32_t member10894_{};
    std::array<std::uint8_t, 18> member10898_{};
    std::int32_t member10901_{};
    std::int32_t member10902_{};
    std::int32_t member10903_{};
    std::int32_t member10904_{};
    std::array<std::uint8_t, 9> member10905_{};
};

class MbcDoorc final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcDoorc(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    std::int32_t SndUser(String parameter1);
    Task<Value> RcvUser7(std::int32_t parameter1, String parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::array<Address, 2> member10896_{};
    std::int32_t member10920_{};
};

class MbcEntry final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcEntry(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    std::int32_t DelMis(std::int32_t parameter1);
    Task<std::int32_t> LoadGame7();
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::array<std::int32_t, 400> member10921_{};
    std::array<std::int32_t, 400> member10922_{};
    std::array<std::int32_t, 400> member10923_{};
    std::array<Address, 2> member10925_{};
    std::array<std::uint8_t, 8> member10927_{};
    std::int32_t member10928_{};
    std::int32_t member10930_{};
    std::array<std::uint8_t, 3> member10933_{};
    std::array<std::uint8_t, 3> member10934_{};
    std::array<std::uint8_t, 3> member10936_{};
    std::array<std::uint8_t, 3> member10938_{};
    std::array<std::uint8_t, 3> member10939_{};
    std::array<std::uint8_t, 3> member10940_{};
};

class MbcFb1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFb1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Client();
    std::int32_t member46_{};
    std::array<std::uint8_t, 9> member2602_{};
    ScriptState50 state50_{};
    std::int32_t member10972_{};
    std::int32_t member10973_{};
    std::int32_t member10974_{};
    std::int32_t member10975_{};
    std::int32_t member10977_{};
    std::int32_t member10978_{};
    float member10979_{};
    float member10980_{};
    std::array<std::uint8_t, 9> member10981_{};
    std::array<std::uint8_t, 9> member10982_{};
    std::array<std::uint8_t, 9> member10983_{};
    std::array<std::uint8_t, 9> member10984_{};
    std::array<std::uint8_t, 9> member10985_{};
};

class MbcFb2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFb2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Client();
    std::int32_t member46_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::int32_t member934_{};
    ScriptState50 state50_{};
    std::int32_t member10987_{};
    std::int32_t member10988_{};
    float member10989_{};
};

class MbcFdApple final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFdApple(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
};

class MbcFdFish final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFdFish(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState14 state14_{};
};

class MbcFdJerky final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFdJerky(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState14 state14_{};
};

class MbcFdPear final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFdPear(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState14 state14_{};
};

class MbcFdScon final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFdScon(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState14 state14_{};
};

class MbcFdStockfish final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFdStockfish(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState14 state14_{};
};

class MbcFernbush final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFernbush(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    std::int32_t member911_{};
};

class MbcFir final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFir(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member911_{};
    ScriptState24 state24_{};
    std::int32_t member11114_{};
    std::array<std::uint8_t, 4> member11083_{};
    std::array<Address, 3> member11112_{};
    std::int32_t member11113_{};
    std::array<std::uint8_t, 28> member11115_{};
    std::array<std::uint8_t, 35> member11116_{};
    String member11117_{};
    std::array<std::uint8_t, 19> member11118_{};
    std::array<std::uint8_t, 28> member11119_{};
    std::array<std::uint8_t, 8> member11120_{};
    std::array<std::uint8_t, 256> member11123_{};
    std::array<std::uint8_t, 256> member11125_{};
    std::array<std::uint8_t, 11> member11127_{};
    std::array<std::uint8_t, 9> member11128_{};
};

class MbcFlag final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFlag(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    void RcvUser2(std::int32_t parameter1, String parameter2);
    Task<void> BearerShine();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState12 state12_{};
};

class MbcFormula final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFormula(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<std::int32_t> Use(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> Main();
    Task<Value> RcvUser3(std::int32_t parameter1, String parameter2);
    std::int32_t fGetName(String parameter1, std::int32_t parameter2);
    Task<std::int32_t> UseOwner(std::int32_t parameter1);
    Task<std::int32_t> WorkCheck(std::int32_t parameter1, std::int32_t parameter2, IntRef parameter3, IntRef parameter4, std::int32_t parameter5);
    Task<std::int32_t> CraftString(std::int32_t parameter1, String parameter2, std::int32_t parameter3, std::int32_t parameter4);
    std::int32_t FCls();
    void getFormulaInfo(std::int32_t parameter1, AddressRef parameter2);
    void helper47_1();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 10> member10294_{};
    std::int32_t member10791_{};
    std::int32_t member11231_{};
    std::array<std::uint8_t, 10> member11233_{};
    std::array<std::uint8_t, 16> member11249_{};
    std::int32_t member11263_{};
    std::int32_t member11264_{};
    std::array<std::uint8_t, 12> member11266_{};
    std::array<std::int32_t, 3> member11267_{};
    std::array<std::uint8_t, 28> member11269_{};
    std::array<std::uint8_t, 100> member11270_{};
    std::array<String, 125> member11272_{};
    std::int8_t member11275_{};
    std::array<std::uint8_t, 50> member11277_{};
    std::array<std::uint8_t, 50> member11279_{};
    std::array<std::uint8_t, 10> member11281_{};
    std::int32_t member11283_{};
    std::int32_t member11284_{};
    std::int32_t member11285_{};
    std::int32_t member11286_{};
    std::array<std::uint8_t, 10> member11287_{};
    std::array<std::uint8_t, 3> member11288_{};
    std::array<std::uint8_t, 5> member11289_{};
    std::array<std::uint8_t, 2> member11290_{};
    std::array<std::uint8_t, 7> member11292_{};
    std::array<std::uint8_t, 7> member11293_{};
    std::array<std::uint8_t, 7> member11294_{};
    std::array<std::uint8_t, 7> member11295_{};
    std::array<std::uint8_t, 7> member11296_{};
    std::array<std::uint8_t, 10> member11297_{};
    std::array<std::uint8_t, 3> member11298_{};
    std::array<std::uint8_t, 5> member11299_{};
    std::array<std::uint8_t, 2> member11300_{};
    std::array<std::uint8_t, 10> member11301_{};
    std::array<std::uint8_t, 10> member11302_{};
    std::array<std::uint8_t, 10> member11303_{};
    std::array<std::uint8_t, 10> member11304_{};
    std::array<std::uint8_t, 11> member11305_{};
    std::array<std::uint8_t, 11> member11306_{};
    String member11307_{};
    std::int32_t member11308_{};
    std::array<std::uint8_t, 100> member11310_{};
    std::array<std::uint8_t, 2> member11312_{};
    std::array<std::uint8_t, 3> member11313_{};
    std::int32_t member11315_{};
    std::int32_t member11316_{};
    String member11317_{};
    std::array<std::uint8_t, 50> member11319_{};
    std::array<std::int8_t, 2> member11321_{};
    std::array<std::uint8_t, 50> member11323_{};
    std::array<std::uint8_t, 6> member11325_{};
    std::array<std::uint8_t, 1> member11326_{};
    std::array<std::uint8_t, 2> member11327_{};
    std::array<std::uint8_t, 14> member11329_{};
    std::array<std::uint8_t, 2> member11330_{};
    std::array<std::uint8_t, 3> member11331_{};
    std::array<std::uint8_t, 2> member11332_{};
    std::int32_t member11334_{};
    std::int32_t member11335_{};
    IntRef member11336_{};
    IntRef member11337_{};
    std::int32_t member11338_{};
    std::int32_t member11340_{};
    std::int32_t member11341_{};
    std::int32_t member11342_{};
    std::int32_t member11343_{};
    std::array<std::uint8_t, 5> member11344_{};
    std::int32_t member11345_{};
    String member11346_{};
    std::int32_t member11347_{};
    std::int32_t member11348_{};
    std::array<std::uint8_t, 20> member11350_{};
    std::array<std::uint8_t, 46> member11352_{};
    std::int32_t member11354_{};
    std::int32_t member11356_{};
    std::array<std::uint8_t, 10> member11357_{};
    std::array<std::uint8_t, 20> member11358_{};
    std::array<std::uint8_t, 10> member11359_{};
    std::array<std::uint8_t, 26> member11360_{};
    std::int32_t member11361_{};
    AddressRef member11362_{};
};

class MbcFwks final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFwks(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState51 state51_{};
};

class MbcFwks2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcFwks2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState51 state51_{};
};

class MbcGLvlupLicense final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcGLvlupLicense(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcGoldpurse final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcGoldpurse(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t GetInfo2(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState52 state52_{};
    std::array<std::uint8_t, 6> member11466_{};
    std::array<std::uint8_t, 69> member11471_{};
};

class MbcGuild final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcGuild(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t GetParam(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, IntRef parameter4, IntRef parameter5, IntRef parameter6, IntRef parameter7, IntRef parameter8, IntRef parameter9, IntRef parameter10, IntRef parameter11);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
};

class MbcIncubator final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcIncubator(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Client();
    Task<String> MdlName();
    Task<void> Main();
    Task<Value> LoadGame4();
    void SaveGame2();
    Task<void> CheckCastle();
    Task<std::int32_t> GetBoss(std::int32_t parameter1);
    Task<std::int32_t> lid3(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t SetGateStatus(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    float member11485_{};
    std::array<std::uint8_t, 7> member11493_{};
    std::array<std::uint8_t, 6> member11494_{};
    std::array<std::uint8_t, 7> member11495_{};
    std::array<std::string, 20> member11497_{};
    std::array<std::uint8_t, 80> member11499_{};
    std::array<std::int32_t, 20> member11501_{};
    std::array<std::uint8_t, 80> member11503_{};
    std::array<std::uint8_t, 80> member11504_{};
    std::array<std::uint8_t, 80> member11506_{};
    std::array<std::uint8_t, 80> member11508_{};
    std::int32_t member11510_{};
    std::array<std::uint8_t, 1600> member11511_{};
    std::int32_t member11512_{};
    std::int32_t member11513_{};
    std::int32_t member11514_{};
    std::int32_t member11515_{};
    std::int32_t member11516_{};
    std::int32_t member11517_{};
    std::int32_t member11518_{};
    std::int32_t member11519_{};
    std::int32_t member11520_{};
    std::int32_t member11521_{};
    std::int32_t member11522_{};
    std::int32_t member11523_{};
    std::int32_t member11524_{};
    std::int32_t member11525_{};
    std::int32_t member11526_{};
    std::int32_t member11527_{};
    std::array<std::int32_t, 2> member11529_{};
    std::int32_t member11531_{};
    std::int32_t member11532_{};
    std::int32_t member11533_{};
    std::int32_t member11534_{};
    std::int32_t member11535_{};
    std::int32_t member11536_{};
    std::int32_t member11537_{};
    std::array<std::uint8_t, 20> member11539_{};
    std::array<std::uint8_t, 80> member11541_{};
    std::int32_t member11543_{};
    std::int32_t member11546_{};
    std::int32_t member11547_{};
    std::int32_t member11548_{};
    std::array<std::uint8_t, 6> member11552_{};
    std::array<std::uint8_t, 6> member11554_{};
    std::int8_t member11556_{};
    std::array<std::uint8_t, 5> member11558_{};
    std::array<std::uint8_t, 5> member11559_{};
    std::array<std::uint8_t, 5> member11560_{};
    std::array<std::uint8_t, 5> member11561_{};
    std::array<std::uint8_t, 4> member11562_{};
    std::array<std::uint8_t, 5> member11563_{};
    std::array<std::uint8_t, 5> member11565_{};
    std::array<std::uint8_t, 6> member11566_{};
    std::array<std::uint8_t, 5> member11567_{};
    std::array<std::uint8_t, 6> member11568_{};
    std::array<std::uint8_t, 6> member11569_{};
    std::array<std::uint8_t, 5> member11570_{};
    std::array<std::uint8_t, 5> member11571_{};
    std::array<std::uint8_t, 3> member11572_{};
    std::array<std::uint8_t, 3> member11573_{};
    std::array<std::uint8_t, 8> member11574_{};
    std::array<std::uint8_t, 4> member11575_{};
    std::array<std::uint8_t, 4> member11576_{};
    std::array<std::uint8_t, 4> member11577_{};
    std::array<std::uint8_t, 4> member11578_{};
    std::array<std::uint8_t, 4> member11579_{};
    std::array<std::uint8_t, 4> member11580_{};
    std::int32_t member11582_{};
    std::array<std::uint8_t, 21> member11583_{};
    std::array<std::uint8_t, 21> member11584_{};
    std::array<std::uint8_t, 21> member11585_{};
    std::array<std::uint8_t, 21> member11586_{};
    std::array<std::uint8_t, 7> member11587_{};
    std::array<std::uint8_t, 4> member11588_{};
    std::array<std::uint8_t, 5> member11589_{};
    std::array<std::uint8_t, 5> member11590_{};
    std::array<std::uint8_t, 5> member11591_{};
    std::array<std::uint8_t, 5> member11592_{};
    std::array<std::uint8_t, 6> member11593_{};
    std::array<std::uint8_t, 5> member11594_{};
    std::array<std::uint8_t, 4> member11595_{};
    std::array<std::uint8_t, 5> member11596_{};
    std::array<std::uint8_t, 8> member11597_{};
    std::array<std::uint8_t, 5> member11598_{};
    std::int32_t member11600_{};
    std::array<std::uint8_t, 6> member11601_{};
    std::array<std::uint8_t, 5> member11605_{};
    std::array<std::uint8_t, 5> member11606_{};
    std::array<std::uint8_t, 5> member11608_{};
    std::array<std::uint8_t, 5> member11609_{};
    std::array<std::uint8_t, 5> member11610_{};
    std::array<std::uint8_t, 5> member11611_{};
    std::array<std::uint8_t, 6> member11612_{};
    std::array<std::uint8_t, 4> member11613_{};
    std::array<std::uint8_t, 5> member11614_{};
    std::array<std::uint8_t, 8> member11615_{};
    std::array<std::uint8_t, 4> member11616_{};
    std::array<std::uint8_t, 4> member11617_{};
    std::array<std::uint8_t, 4> member11618_{};
    std::array<std::uint8_t, 4> member11619_{};
    std::array<std::uint8_t, 4> member11620_{};
    std::array<std::uint8_t, 4> member11621_{};
    std::int32_t member11622_{};
    std::array<std::uint8_t, 4> member11623_{};
    std::array<std::uint8_t, 4> member11624_{};
    std::int32_t member11625_{};
    std::int32_t member11626_{};
    std::int32_t member11627_{};
    std::int32_t member11628_{};
    std::int32_t member11629_{};
    std::int32_t member11630_{};
    std::int32_t member11631_{};
    std::int32_t member11632_{};
    std::int32_t member11633_{};
    std::int32_t member11634_{};
    std::int32_t member11635_{};
    std::int32_t member11636_{};
    std::int32_t member11637_{};
    std::int32_t member11638_{};
    std::int32_t member11639_{};
    IntRef member11640_{};
    std::int32_t member11641_{};
};

class MbcIslandPr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcIslandPr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<void> Cli();
    std::int32_t SndUser(String parameter1);
    Task<std::int32_t> RcvUser6(std::int32_t parameter1, String parameter2);
    std::int32_t SaveGame();
    Task<std::int32_t> CloseCont(std::int32_t parameter1);
    Task<std::int32_t> LoadLab(std::int32_t parameter1);
    Task<void> EKill();
    std::int32_t GetIslLvl();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    std::int32_t member911_{};
    ScriptState41 state41_{};
    std::int32_t member11642_{};
    std::int32_t member11643_{};
    std::int32_t member11644_{};
    std::array<std::uint8_t, 64> member11646_{};
    String member11647_{};
    std::array<std::int32_t, 10> member11650_{};
    std::array<std::int32_t, 10> member11652_{};
    std::array<Address, 2> member11653_{};
    std::int32_t member11654_{};
    std::int32_t member11655_{};
    float member11678_{};
    float member11679_{};
    float member11680_{};
    std::int32_t member11681_{};
    String member11682_{};
    std::array<std::uint8_t, 3> member11684_{};
    std::int32_t member11686_{};
    std::int32_t member11689_{};
    std::int32_t member11691_{};
    std::int32_t member11694_{};
    std::array<std::uint8_t, 22> member11695_{};
    std::array<std::uint8_t, 29> member11696_{};
    std::int32_t member11698_{};
    std::int32_t member11699_{};
    std::int32_t member11700_{};
    std::int32_t member11701_{};
    std::int32_t member11703_{};
    String member11704_{};
    std::int8_t member11706_{};
    String member11707_{};
    Address member11708_{};
    std::array<Address, 2> member11709_{};
    Address member11710_{};
    float member11711_{};
    std::array<Address, 2> member11712_{};
    std::array<std::uint8_t, 22> member11713_{};
    std::array<std::uint8_t, 9> member11714_{};
    std::array<std::uint8_t, 6> member11715_{};
    std::array<std::uint8_t, 11> member11716_{};
    String member11717_{};
    std::array<std::uint8_t, 22> member11718_{};
    std::array<std::uint8_t, 56> member11719_{};
    std::array<std::uint8_t, 7> member11720_{};
    std::array<std::uint8_t, 28> member11721_{};
};

class MbcIslandToken final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcIslandToken(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member11722_{};
    std::array<std::uint8_t, 6> member11746_{};
};

class MbcItemBead final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcItemBead(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
};

class MbcItemLetter final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcItemLetter(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
};

class MbcJwDiamond final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcJwDiamond(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcJwDiamring final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcJwDiamring(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcJwGold final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcJwGold(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcJwRing final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcJwRing(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcJwRuby final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcJwRuby(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcJwRubyring final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcJwRubyring(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcLabyr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcLabyr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t GetEnt(std::int32_t parameter1, AddressRef parameter2);
    std::int32_t GMID();
    std::int32_t GCHID(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, AddressRef parameter4);
    Task<void> Cli();
    std::int32_t GetRandLvl(std::int32_t parameter1);
    std::int32_t GetBossLvl(std::int32_t parameter1);
    Task<std::int32_t> LoadLab2();
    Task<void> ShowMinimap();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    std::int32_t member911_{};
    std::array<Address, 2> member11813_{};
    std::array<std::uint8_t, 52> member11814_{};
    std::int32_t member11815_{};
    std::array<StringRef, 800> member11817_{};
    std::array<std::int8_t, 20> member11819_{};
    std::int32_t member11821_{};
    AddressRef member11822_{};
    std::int32_t member11823_{};
    std::int32_t member11824_{};
    std::int32_t member11825_{};
    AddressRef member11826_{};
    String member11828_{};
    std::int32_t member11879_{};
    std::int32_t member11880_{};
    std::int32_t member11881_{};
    String member11883_{};
    std::int8_t member11885_{};
    std::int32_t member11887_{};
    std::int32_t member11890_{};
    std::int32_t member11892_{};
    std::int32_t member11894_{};
    std::int32_t member11895_{};
    std::int32_t member11897_{};
    String member11898_{};
    String member11899_{};
    std::int8_t member11900_{};
    String member11902_{};
    std::array<std::int8_t, 10> member11904_{};
    std::array<Address, 2> member11906_{};
    Address member11907_{};
    float member11909_{};
    float member11911_{};
    std::array<String, 2> member11912_{};
    std::array<std::uint8_t, 29> member11913_{};
    std::array<std::uint8_t, 7> member11914_{};
    std::array<std::uint8_t, 6> member11915_{};
    std::array<std::uint8_t, 6> member11916_{};
    std::array<std::uint8_t, 6> member11917_{};
    std::array<std::uint8_t, 6> member11918_{};
    std::array<std::uint8_t, 5> member11919_{};
    std::array<std::uint8_t, 8> member11920_{};
    std::array<std::uint8_t, 8> member11921_{};
    std::array<std::uint8_t, 8> member11922_{};
    std::array<std::uint8_t, 8> member11923_{};
    std::array<std::uint8_t, 8> member11924_{};
    std::array<std::uint8_t, 8> member11925_{};
    std::array<std::uint8_t, 10> member11926_{};
    std::array<std::uint8_t, 26> member11927_{};
    std::array<std::uint8_t, 3> member11928_{};
    std::array<std::uint8_t, 25> member11929_{};
    std::array<std::uint8_t, 29> member11930_{};
    std::array<std::uint8_t, 7> member11931_{};
    std::array<std::uint8_t, 18> member11932_{};
};

class MbcLicence final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcLicence(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<std::int32_t> UseClient2();
    Value LoadGame5();
    std::int32_t SaveGame();
    Task<void> slhalt();
    Task<void> Qquit();
    Task<void> dntmove();
    Task<void> cleanup_Qquit();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    std::int32_t member11955_{};
    std::int32_t member11956_{};
    std::int32_t member11957_{};
    std::int32_t member11958_{};
    Address member11959_{};
    std::array<std::uint8_t, 18> member11960_{};
    float member11962_{};
    std::array<std::uint8_t, 18> member11963_{};
    std::int32_t member11965_{};
    String member11966_{};
    std::int32_t member11968_{};
    std::int32_t member11969_{};
    std::int32_t member11970_{};
    std::int32_t member11971_{};
    std::int32_t member11972_{};
    std::array<std::uint8_t, 8> member11973_{};
    std::array<std::uint8_t, 11> member11974_{};
    std::int32_t member11976_{};
    std::array<std::uint8_t, 7> member11977_{};
    std::array<std::uint8_t, 11> member11978_{};
};

class MbcLicenseHr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcLicenseHr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState53 state53_{};
};

class MbcLicenseHrgt final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcLicenseHrgt(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcLicensePh final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcLicensePh(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState53 state53_{};
};

class MbcLicensePhgt final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcLicensePhgt(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcLottery final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcLottery(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> Use(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> waitForRes();
    Task<Value> RcvUser3(std::int32_t parameter1, String parameter2);
    void LoadGame2();
    void AddInfo(String parameter1);
    Task<void> cleanup_waitForRes();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    float member12005_{};
    std::array<std::uint8_t, 56> member11988_{};
    std::array<std::int8_t, 14> member12014_{};
    std::array<std::int8_t, 14> member12016_{};
    std::array<std::uint8_t, 1> member12018_{};
    float member12030_{};
    float member12031_{};
    float member12032_{};
    float member12033_{};
    float member12034_{};
    float member12035_{};
    std::int32_t member12036_{};
    std::array<std::uint8_t, 14> member12037_{};
    std::array<std::uint8_t, 1> member12038_{};
    std::int32_t member12039_{};
    std::array<std::uint8_t, 14> member12044_{};
    std::int32_t member12047_{};
};

class MbcMgCorn final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgCorn(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t isInvisible();
    std::int32_t hideIfInvisible();
    std::int32_t show();
    Task<void> pvison();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member12055_{};
};

class MbcMgEye final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgEye(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> ShowHiddens();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    std::int32_t member12086_{};
    String member12087_{};
    std::array<std::uint8_t, 5> member12088_{};
};

class MbcMgGmagicpot final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgGmagicpot(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 5> member12132_{};
    ScriptState54 state54_{};
};

class MbcMgMagicpot final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgMagicpot(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 5> member12132_{};
    ScriptState54 state54_{};
};

class MbcMgMagicstove final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgMagicstove(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    void RcvUser2(std::int32_t parameter1, String parameter2);
    Task<void> Fire();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::array<std::uint8_t, 5> member12132_{};
    std::int32_t member12217_{};
    std::array<std::int32_t, 2> member12218_{};
    std::array<std::int32_t, 3> member12220_{};
    std::int32_t member12222_{};
    std::array<std::uint8_t, 6> member12223_{};
};

class MbcMgMantrab final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgMantrab(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState36 state36_{};
    ScriptState55 state55_{};
};

class MbcMgMantraw final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgMantraw(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState36 state36_{};
    ScriptState55 state55_{};
};

class MbcMgRcp final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgRcp(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::array<std::uint8_t, 11> member12381_{};
    std::array<std::uint8_t, 26> member12382_{};
    String member12383_{};
    std::array<std::uint8_t, 11> member12384_{};
};

class MbcMgWorkshop final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMgWorkshop(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<Value> RcvUser3(std::int32_t parameter1, String parameter2);
    Task<void> Fire();
    Task<void> closeWindowWorkshop();
    void setFlagCloseWindowWorkshop();
    void setFlagFreeSlotsInWorkshop();
    void resetFlagAcceptCraft();
    Task<Value> setFlagAcceptCraft();
    Task<void> cleanup_closeWindowWorkshop();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member12407_{};
    std::array<std::uint8_t, 5> member10707_{};
    std::array<std::uint8_t, 18> member12408_{};
    std::array<std::uint8_t, 18> member12409_{};
    std::int32_t member12411_{};
    std::int32_t member12412_{};
    std::int32_t member12413_{};
    Address member12414_{};
    std::array<std::uint8_t, 17> member12415_{};
    std::array<std::uint8_t, 18> member12416_{};
    std::array<std::uint8_t, 9> member12417_{};
    std::array<std::uint8_t, 20> member12418_{};
    std::array<std::uint8_t, 18> member12419_{};
};

class MbcMonster final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonster(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
};

class MbcMonsterEvent final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterEvent(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<float> LoadGame6();
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
    Address member12560_{};
    std::int32_t member12564_{};
    std::int32_t member12557_{};
    std::int32_t member12558_{};
    std::int32_t member12561_{};
    std::int32_t member12563_{};
    std::array<std::uint8_t, 14> member12566_{};
    Address member12568_{};
    std::array<std::uint8_t, 18> member12569_{};
    std::array<Address, 2> member12571_{};
    std::array<std::uint8_t, 13> member12572_{};
    std::array<Address, 2> member12574_{};
    std::array<std::uint8_t, 14> member12575_{};
    std::array<std::uint8_t, 18> member12576_{};
    std::array<std::uint8_t, 13> member12577_{};
};

class MbcMonsterTrap final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterTrap(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    std::int32_t member911_{};
};

class MbcMonsterc final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterc(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::array<std::uint8_t, 2> member8843_{};
};

class MbcMonsterd final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterd(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
};

class MbcMonsterdf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterdf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
};

class MbcMonsterf final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterf(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
};

class MbcMonsterh final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterh(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::array<std::uint8_t, 2> member8843_{};
};

class MbcMonstern final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonstern(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
    std::int32_t member12557_{};
};

class MbcMonsterq final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsterq(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
    std::int32_t member12557_{};
};

class MbcMonsters final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMonsters(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState25 state25_{};
};

class MbcMortar final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcMortar(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    std::int32_t SndUser(String parameter1);
    void RcvUser2(std::int32_t parameter1, String parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    std::int32_t member911_{};
    float member12695_{};
};

class MbcNpc01 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc01(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    std::int32_t member12718_{};
    ScriptState37 state37_{};
};

class MbcNpc06 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc06(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    std::int32_t member12718_{};
    ScriptState37 state37_{};
};

class MbcNpc14 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc14(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState22 state22_{};
    std::int32_t member12718_{};
};

class MbcNpc29 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc29(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState22 state22_{};
    std::int32_t member12718_{};
};

class MbcNpc40 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc40(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::array<std::uint8_t, 2> member8253_{};
};

class MbcNpc47 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc47(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::array<std::uint8_t, 2> member8253_{};
};

class MbcNpc55 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc55(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::array<std::uint8_t, 2> member8253_{};
};

class MbcNpc58 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc58(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    std::int32_t member12718_{};
    ScriptState37 state37_{};
};

class MbcNpc59 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpc59(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    std::int32_t member12718_{};
    ScriptState37 state37_{};
};

class MbcNpcBanker final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcBanker(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    void RcvUser2(std::int32_t parameter1, String parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::array<std::uint8_t, 8> member12964_{};
    std::array<std::uint8_t, 16> member12965_{};
    std::array<std::uint8_t, 9> member12966_{};
    std::array<std::uint8_t, 9> member12967_{};
    std::array<std::uint8_t, 8> member12969_{};
    std::array<std::uint8_t, 9> member12970_{};
};

class MbcNpcCollector final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcCollector(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    String LoadGame3();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    std::array<std::uint8_t, 80> member13026_{};
    std::int32_t member13027_{};
    std::int32_t member13030_{};
    std::int32_t member13031_{};
    std::array<std::uint8_t, 2560> member13033_{};
    std::int32_t member13035_{};
    std::array<std::uint8_t, 9> member13037_{};
    String member13038_{};
    std::array<std::uint8_t, 13> member13040_{};
    std::array<std::uint8_t, 11> member13041_{};
    std::array<std::uint8_t, 13> member13042_{};
    String member13043_{};
    String member13044_{};
    String member13045_{};
    std::int32_t member13046_{};
    std::array<std::uint8_t, 9> member13047_{};
    std::array<std::uint8_t, 4> member13048_{};
};

class MbcNpcEmpty final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcEmpty(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    String LoadGame3();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    std::array<std::uint8_t, 80> member13104_{};
};

class MbcNpcFatherFrost final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcFatherFrost(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    void LoadGame2();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 2560> member13106_{};
    std::array<std::uint8_t, 11> member13110_{};
};

class MbcNpcGold final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcGold(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Client();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState21 state21_{};
    ScriptState22 state22_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::int32_t member12718_{};
    std::array<std::uint8_t, 9> member13144_{};
};

class MbcNpcGuide final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcGuide(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    std::int32_t LoadGame();
    Task<void> Server();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    std::int32_t member2_{};
    std::array<std::uint8_t, 4> member13215_{};
};

class MbcNpcGuilder final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcGuilder(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Client();
    std::int32_t SendPress(std::int32_t parameter1);
    String LoadGame3();
    Task<void> WinGuild();
    Task<void> helper90_1();
    Task<void> cleanup_WinGuild();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 5> member8255_{};
    String member13244_{};
    std::array<std::uint8_t, 4> member13271_{};
    std::int8_t member13273_{};
    std::int32_t member13276_{};
    std::int32_t member13280_{};
    std::array<std::uint8_t, 6> member13281_{};
    std::int32_t member13283_{};
    std::int32_t member13284_{};
    std::int32_t member13285_{};
    std::int32_t member13286_{};
    std::int32_t member13287_{};
    std::int32_t member13288_{};
    std::int32_t member13289_{};
    std::int32_t member13290_{};
    std::int32_t member13291_{};
    std::int32_t member13292_{};
    std::int32_t member13293_{};
    std::int32_t member13294_{};
    std::int32_t member13295_{};
    std::int32_t member13296_{};
    std::array<std::int32_t, 4> member13298_{};
    std::int32_t member13300_{};
    std::int32_t member13301_{};
    std::int32_t member13302_{};
    std::int32_t member13303_{};
    std::int32_t member13304_{};
    std::int32_t member13305_{};
    IntRef member13307_{};
    IntRef member13308_{};
    IntRef member13309_{};
    std::array<std::uint8_t, 92> member13310_{};
    std::array<std::uint8_t, 64> member13312_{};
    std::array<String, 127> member13314_{};
    std::array<std::uint8_t, 64> member13316_{};
    String member13318_{};
    std::array<std::uint8_t, 9> member13319_{};
    std::array<std::uint8_t, 11> member13320_{};
    std::array<std::uint8_t, 11> member13321_{};
    std::array<std::uint8_t, 11> member13322_{};
    std::array<std::uint8_t, 11> member13323_{};
    std::array<std::uint8_t, 11> member13324_{};
    std::array<std::uint8_t, 21> member13325_{};
    String member13326_{};
    std::array<std::uint8_t, 5> member13327_{};
    std::array<std::uint8_t, 5> member13328_{};
    std::array<std::uint8_t, 11> member13329_{};
    std::array<std::uint8_t, 11> member13330_{};
    std::array<std::uint8_t, 11> member13331_{};
    std::array<std::uint8_t, 11> member13332_{};
    std::array<std::uint8_t, 11> member13333_{};
    std::array<std::uint8_t, 11> member13334_{};
    std::array<std::uint8_t, 11> member13335_{};
    std::array<std::uint8_t, 11> member13336_{};
    std::array<std::uint8_t, 11> member13337_{};
    std::array<std::uint8_t, 11> member13338_{};
};

class MbcNpcNewyear final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcNewyear(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState21 state21_{};
    std::array<std::uint8_t, 80> member13104_{};
    std::array<std::uint8_t, 13> member13341_{};
};

class MbcNpcQuestman final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcQuestman(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
};

class MbcNpcTournament final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcTournament(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<void> Main();
    Value RcvUser(std::int32_t parameter1, String parameter2);
    Task<void> winTournament();
    Task<void> RegTmntReceiver();
    Task<std::int32_t> ParseItemString(String parameter1, String parameter2);
    String UnpackTmntData(String parameter1);
    std::int32_t AddPlayerGVG(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t DeletePlayerGVG(std::int32_t parameter1);
    Task<void> WinTmntRegGVG();
    Task<void> helper48_1();
    Task<void> helper112_1();
    Task<void> helper73_1();
    Task<void> helper115_1();
    Task<void> helper94_1();
    Task<void> cleanup_winTournament();
    Task<void> cleanup_WinTmntRegGVG();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    std::int32_t member13399_{};
    std::array<std::uint8_t, 1000> member13400_{};
    std::array<std::uint8_t, 20> member13402_{};
    std::int32_t member13404_{};
    std::int32_t member13405_{};
    std::int32_t member13406_{};
    std::int32_t member13407_{};
    std::int32_t member13408_{};
    std::int32_t member13409_{};
    std::int32_t member13410_{};
    std::int32_t member13411_{};
    std::int32_t member13412_{};
    std::int32_t member13413_{};
    std::array<std::uint8_t, 256> member13415_{};
    std::array<std::uint8_t, 128> member13417_{};
    std::array<std::uint8_t, 128> member13419_{};
    std::int32_t member13421_{};
    std::int32_t member13422_{};
    std::array<std::uint8_t, 6> member13423_{};
    std::array<std::uint8_t, 16> member13424_{};
    std::array<std::uint8_t, 21> member13425_{};
    std::array<std::uint8_t, 26> member13426_{};
    std::int32_t member13430_{};
    std::int32_t member13431_{};
    std::int32_t member13432_{};
    std::int32_t member13433_{};
    std::int32_t member13434_{};
    std::array<std::uint8_t, 11> member13436_{};
    std::array<std::int32_t, 6> member13438_{};
    std::int32_t member13440_{};
    std::int32_t member13441_{};
    std::array<std::uint8_t, 1> member13442_{};
    std::array<std::uint8_t, 11> member13443_{};
    std::array<std::uint8_t, 11> member13444_{};
    std::array<std::uint8_t, 11> member13445_{};
    std::array<std::uint8_t, 3> member13446_{};
    std::array<std::uint8_t, 3> member13447_{};
    std::array<std::uint8_t, 10> member13448_{};
    std::int32_t member13450_{};
    std::array<std::uint8_t, 1> member13451_{};
    std::array<std::uint8_t, 11> member13452_{};
    std::array<std::uint8_t, 11> member13453_{};
    std::array<std::uint8_t, 256> member13455_{};
    std::int32_t member13457_{};
    std::int32_t member13458_{};
    String member13459_{};
    std::array<std::uint8_t, 20> member13460_{};
    String member13478_{};
    std::int32_t member13479_{};
    std::int32_t member13480_{};
    String member13482_{};
    std::int32_t member13483_{};
    String member13484_{};
    std::int32_t member13485_{};
    std::int32_t member13486_{};
    std::int32_t member13487_{};
    AddressRef member13488_{};
    std::int32_t member13489_{};
    std::int32_t member13490_{};
    std::int32_t member13491_{};
    std::int32_t member13492_{};
    std::array<std::uint8_t, 152> member13493_{};
    std::array<std::int32_t, 2> member13495_{};
    std::int32_t member13497_{};
    std::int32_t member13498_{};
    std::int32_t member13499_{};
    std::int32_t member13500_{};
    std::int32_t member13501_{};
    std::int32_t member13502_{};
    std::int32_t member13503_{};
    std::int32_t member13504_{};
    std::int32_t member13505_{};
    std::array<std::uint8_t, 13> member13506_{};
    std::array<std::int32_t, 6> member13508_{};
    std::int32_t member13510_{};
    std::int32_t member13511_{};
    String member13512_{};
    String member13513_{};
    String member13514_{};
    std::array<std::uint8_t, 11> member13515_{};
    std::array<std::uint8_t, 11> member13516_{};
    std::array<std::uint8_t, 3> member13517_{};
    std::array<std::uint8_t, 3> member13518_{};
    std::array<std::uint8_t, 10> member13519_{};
    std::int32_t member13521_{};
    std::int32_t member13522_{};
    std::array<std::uint8_t, 14> member13523_{};
    std::int32_t member13525_{};
    std::array<std::uint8_t, 11> member13526_{};
    std::array<std::uint8_t, 6> member13527_{};
    String member13528_{};
    std::array<std::uint8_t, 5> member13530_{};
    std::array<std::uint8_t, 5> member13532_{};
    std::array<std::uint8_t, 11> member13534_{};
    std::array<std::uint8_t, 11> member13535_{};
    std::array<std::uint8_t, 14> member13536_{};
};

class MbcNpcTrader final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcTrader(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState21 state21_{};
    ScriptState22 state22_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::int32_t member12718_{};
};

class MbcNpcVirt final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcNpcVirt(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> Use(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> ContMan();
    Task<String> RcvUser5(std::int32_t parameter1, String parameter2);
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    Task<void> CheckExit();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState21 state21_{};
    ScriptState25 state25_{};
    std::array<std::uint8_t, 20> member13587_{};
    std::int32_t member13589_{};
    std::int32_t member13590_{};
    std::array<std::uint8_t, 15> member13593_{};
    std::array<std::uint8_t, 11> member13594_{};
    std::int32_t member13598_{};
    std::int32_t member13599_{};
    std::int32_t member13600_{};
    Address member13601_{};
    std::array<std::uint8_t, 7> member13602_{};
};

class MbcPacket final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPacket(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    Task<std::int32_t> SetPacket(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> Use(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> ContMan();
    std::int32_t SndUser(String parameter1);
    String RcvUser4(std::int32_t parameter1, String parameter2);
    std::int32_t SaveGame();
    std::int32_t LoadGame();
    Task<std::int32_t> UseOwner(std::int32_t parameter1);
    Task<Value> UseWith3(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 7> member13651_{};
    ScriptState12 state12_{};
    std::int32_t member13603_{};
    std::int32_t member13604_{};
    std::int32_t member13605_{};
    std::int32_t member13606_{};
    std::string member13607_{};
    std::array<std::uint8_t, 64> member13609_{};
    std::int32_t member13611_{};
    std::int32_t member13612_{};
    std::int32_t member13613_{};
    String member13650_{};
};

class MbcPurse final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPurse(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t GetInfo2(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState52 state52_{};
    std::array<std::uint8_t, 4> member13659_{};
    std::array<std::uint8_t, 65> member13661_{};
};

class MbcPwAbility final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwAbility(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState17 state17_{};
};

class MbcPwAmilus final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwAmilus(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState17 state17_{};
    std::array<std::uint8_t, 5> member13731_{};
    ScriptState18 state18_{};
    std::int32_t member13720_{};
    String member13721_{};
    std::int8_t member13722_{};
    std::array<std::int32_t, 4> member13728_{};
};

class MbcPwBuff0 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwBuff0(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    String member13744_{};
    std::array<std::uint8_t, 9> member13745_{};
    ScriptState38 state38_{};
};

class MbcPwBuff1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwBuff1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    String member13744_{};
    std::array<std::uint8_t, 9> member13745_{};
    ScriptState38 state38_{};
};

class MbcPwBuff2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwBuff2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    String member13744_{};
    std::array<std::uint8_t, 9> member13745_{};
    ScriptState38 state38_{};
};

class MbcPwBuff3 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwBuff3(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    String member13744_{};
    std::array<std::uint8_t, 9> member13745_{};
    ScriptState38 state38_{};
};

class MbcPwCourage final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwCourage(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    String LoadGame3();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member13796_{};
    String member13793_{};
};

class MbcPwCouragef final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwCouragef(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::array<std::uint8_t, 6> member13823_{};
};

class MbcPwCouragef1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwCouragef1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    String LoadGame3();
    String AddInfo3(String parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::array<std::uint8_t, 13> member13824_{};
    std::array<std::uint8_t, 13> member13825_{};
};

class MbcPwElixir final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwElixir(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState15 state15_{};
    ScriptState33 state33_{};
};

class MbcPwElixir1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwElixir1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState15 state15_{};
    ScriptState33 state33_{};
};

class MbcPwFb01 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFb01(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
};

class MbcPwFb02 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFb02(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
};

class MbcPwFb03 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFb03(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState16 state16_{};
    std::array<std::uint8_t, 56> member13979_{};
    String member13981_{};
    std::int32_t member13983_{};
    std::int32_t member13984_{};
    String member13991_{};
    std::array<std::uint8_t, 9> member13992_{};
    std::int8_t member14001_{};
    std::array<std::uint8_t, 8> member14009_{};
    std::array<std::uint8_t, 11> member14013_{};
    std::array<std::uint8_t, 11> member14024_{};
    float member14026_{};
    std::array<std::uint8_t, 18> member14030_{};
    std::array<std::uint8_t, 5> member14031_{};
};

class MbcPwFb04 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFb04(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member14083_{};
    std::array<std::uint8_t, 21> member14084_{};
};

class MbcPwFb05 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFb05(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
};

class MbcPwFinish final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFinish(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState17 state17_{};
};

class MbcPwFistpwr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFistpwr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState15 state15_{};
    ScriptState17 state17_{};
    ScriptState56 state56_{};
};

class MbcPwFixhunger final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwFixhunger(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState15 state15_{};
    ScriptState17 state17_{};
    ScriptState56 state56_{};
};

class MbcPwHeal1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcPwHeal1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState15 state15_{};
    ScriptState33 state33_{};
};

class MbcQuest final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcQuest(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    IntRef GetP(std::int32_t parameter1);
    Task<void> ContMan();
    void sendslot(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> TestIt(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> SeekTag(std::int32_t parameter1);
    std::int32_t SeekTagInsideNoRecursive(std::int32_t parameter1);
    Task<std::int32_t> SetOverFill(std::int32_t parameter1);
    Task<std::int32_t> AddWght2(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> FreeIt12(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    std::int32_t GetSlotID(std::int32_t parameter1);
    std::int32_t isSlotOccupied(std::int32_t parameter1);
    std::int32_t TestMe(std::int32_t parameter1);
    std::int32_t GetMySlot(std::int32_t parameter1);
    Task<void> UseOwnerr();
    Task<std::int32_t> GetMMChr(String parameter1);
    Task<void> TypeMission();
    Task<void> helper84_1();
    Task<void> helper52_1();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 7> member13651_{};
    ScriptState23 state23_{};
    ScriptState57 state57_{};
    std::int32_t member14185_{};
    std::int32_t member14187_{};
    std::array<std::uint8_t, 40> member14224_{};
    std::array<std::uint8_t, 40> member14225_{};
    std::array<std::int32_t, 10> member14226_{};
    std::int32_t member14259_{};
    std::array<std::uint8_t, 11> member14263_{};
    std::array<std::uint8_t, 2> member14264_{};
    std::array<String, 2> member14270_{};
    std::array<std::uint8_t, 7> member14271_{};
    std::int32_t member14292_{};
    std::int32_t member14293_{};
    std::int32_t member14294_{};
    std::int32_t member14295_{};
    std::int32_t member14296_{};
    std::int32_t member14297_{};
    std::int32_t member14298_{};
    std::int32_t member14299_{};
    std::array<std::int32_t, 10> member14303_{};
    std::int32_t member14304_{};
    std::int32_t member14305_{};
    std::array<std::uint8_t, 64> member14308_{};
    std::array<std::uint8_t, 1024> member14310_{};
    std::array<std::uint8_t, 64> member14312_{};
    std::int32_t member14315_{};
    std::int32_t member14316_{};
    String member14322_{};
    std::array<std::uint8_t, 9> member14323_{};
    String member14324_{};
    String member14326_{};
    std::array<std::uint8_t, 21> member14327_{};
    std::array<std::uint8_t, 7> member14328_{};
    std::array<std::uint8_t, 9> member14329_{};
    std::array<std::uint8_t, 9> member14330_{};
    Address member14332_{};
    Address member14333_{};
    std::array<std::uint8_t, 30> member14335_{};
    std::array<std::uint8_t, 30> member14337_{};
    std::array<String, 2> member14339_{};
    std::array<std::uint8_t, 22> member14340_{};
    std::array<std::uint8_t, 13> member14341_{};
    std::array<String, 2> member14342_{};
    std::array<std::uint8_t, 22> member14343_{};
    std::array<std::uint8_t, 13> member14344_{};
    std::array<std::uint8_t, 22> member14345_{};
    std::array<std::uint8_t, 8> member14346_{};
    std::array<std::uint8_t, 11> member14347_{};
    String member14348_{};
    String member14349_{};
    String member14350_{};
    std::array<std::uint8_t, 5> member14351_{};
    std::array<std::uint8_t, 5> member14352_{};
    std::array<std::uint8_t, 6> member14353_{};
    std::array<std::uint8_t, 6> member14354_{};
    std::array<std::uint8_t, 9> member14355_{};
    float member14357_{};
    float member14358_{};
    std::int32_t member14359_{};
    std::int32_t member14360_{};
    std::int32_t member14361_{};
    std::int32_t member14362_{};
    std::array<std::uint8_t, 13> member14363_{};
    std::array<std::uint8_t, 1> member14364_{};
    std::array<std::uint8_t, 3> member14365_{};
    std::array<std::uint8_t, 10> member14366_{};
};

class MbcQuest2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcQuest2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    IntRef GetP(std::int32_t parameter1);
    Task<void> ContMan();
    void sendslot(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> TestIt(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3);
    Task<std::int32_t> SeekTag(std::int32_t parameter1);
    std::int32_t SeekTagInsideNoRecursive(std::int32_t parameter1);
    Task<std::int32_t> SetOverFill(std::int32_t parameter1);
    Task<std::int32_t> AddWght2(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> FreeIt12(std::int32_t parameter1);
    Task<std::int32_t> FreeIt(std::int32_t parameter1);
    std::int32_t GetSlotID(std::int32_t parameter1);
    std::int32_t isSlotOccupied(std::int32_t parameter1);
    std::int32_t TestMe(std::int32_t parameter1);
    std::int32_t GetMySlot(std::int32_t parameter1);
    Task<void> UseOwnerr();
    Task<std::int32_t> GetMMChr(String parameter1);
    Task<void> TypeMission();
    Task<void> helper88_1();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 7> member13651_{};
    ScriptState23 state23_{};
    std::int32_t member534_{};
    ScriptState57 state57_{};
    std::array<std::uint8_t, 72> member14367_{};
    std::array<std::uint8_t, 72> member14368_{};
    std::array<std::int32_t, 18> member14370_{};
    std::int32_t member14406_{};
    std::array<std::uint8_t, 11> member14407_{};
    std::array<std::uint8_t, 2> member14408_{};
    std::array<std::uint8_t, 7> member14411_{};
    std::int32_t member14416_{};
    std::int32_t member14417_{};
    std::int32_t member14418_{};
    std::int32_t member14419_{};
    std::int32_t member14420_{};
    std::int32_t member14421_{};
    std::int32_t member14422_{};
    std::array<std::int32_t, 20> member14424_{};
    std::int32_t member14426_{};
    std::int32_t member14427_{};
    std::array<std::uint8_t, 64> member14429_{};
    std::array<std::uint8_t, 64> member14432_{};
    Address member14434_{};
    Address member14435_{};
    std::array<std::uint8_t, 30> member14436_{};
    std::array<std::uint8_t, 30> member14437_{};
    std::array<std::uint8_t, 13> member14438_{};
    std::array<std::uint8_t, 13> member14439_{};
    std::array<std::uint8_t, 7> member14440_{};
    std::array<std::uint8_t, 9> member14441_{};
    std::array<std::uint8_t, 11> member14442_{};
    String member14443_{};
    String member14444_{};
    String member14445_{};
    std::array<std::uint8_t, 5> member14446_{};
    std::array<std::uint8_t, 5> member14447_{};
    std::array<std::uint8_t, 6> member14448_{};
    std::array<std::uint8_t, 6> member14449_{};
    std::array<std::uint8_t, 9> member14450_{};
};

class MbcRdlicense final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRdlicense(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcRglicense final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRglicense(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcRgllicense final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRgllicense(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcRhomb final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRhomb(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    std::int32_t GetWear();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    ScriptState17 state17_{};
    std::array<std::uint8_t, 20> member14451_{};
    std::array<std::uint8_t, 4> member14460_{};
    std::span<const std::int32_t> member14483_{};
    std::array<std::uint8_t, 11> member14484_{};
};

class MbcRilicense final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRilicense(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcRock final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRock(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    std::int32_t member911_{};
};

class MbcRoom1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRoom1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    std::int32_t member911_{};
};

class MbcRslicense final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRslicense(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcRtlicense final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcRtlicense(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcScroll final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcScroll(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    std::int32_t get_mNumber();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState28 state28_{};
};

class MbcScrollOctober final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcScrollOctober(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t lid(std::int32_t parameter1, AddressRef parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState28 state28_{};
    std::int32_t member14518_{};
    AddressRef member14519_{};
};

class MbcSeed final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSeed(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> Client();
    String LoadGame3();
    String AddInfo3(String parameter1);
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> EKill();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState26 state26_{};
    std::int32_t member11114_{};
    std::int32_t member14557_{};
    std::int32_t member14520_{};
    std::int32_t member14521_{};
    std::array<std::uint8_t, 20> member14522_{};
    std::array<std::uint8_t, 128> member14523_{};
    std::array<std::uint8_t, 22> member14541_{};
    std::array<std::uint8_t, 4> member14542_{};
    std::array<std::uint8_t, 5> member14543_{};
    std::array<std::uint8_t, 5> member14544_{};
    std::array<std::uint8_t, 7> member14545_{};
    std::array<std::uint8_t, 8> member14546_{};
    std::array<std::uint8_t, 7> member14547_{};
    std::array<std::uint8_t, 8> member14548_{};
    std::array<std::uint8_t, 7> member14549_{};
    std::array<std::uint8_t, 8> member14550_{};
    std::array<std::uint8_t, 7> member14551_{};
    std::int32_t member14552_{};
    Address member14554_{};
    std::int32_t member14556_{};
};

class MbcShop final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcShop(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Client();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState21 state21_{};
    ScriptState22 state22_{};
    std::array<std::uint8_t, 5> member8255_{};
    std::int32_t member12718_{};
    std::array<std::uint8_t, 5> member14601_{};
    std::array<std::uint8_t, 7> member14602_{};
};

class MbcSpecab final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecab(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<std::int32_t> Use(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState36 state36_{};
    std::int32_t member14630_{};
    std::array<std::uint8_t, 12> member14637_{};
    std::array<std::uint8_t, 32> member14638_{};
    std::array<std::uint8_t, 11> member14642_{};
    std::array<std::uint8_t, 20> member14649_{};
    std::array<std::uint8_t, 11> member14651_{};
    std::array<std::uint8_t, 5> member14652_{};
};

class MbcSpecabBa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabBa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member14715_{};
    std::array<std::uint8_t, 11> member14716_{};
};

class MbcSpecabCa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabCa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member14715_{};
};

class MbcSpecabEa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabEa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member14715_{};
};

class MbcSpecabFa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabFa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member14715_{};
};

class MbcSpecabGa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabGa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    String member13744_{};
    std::array<std::uint8_t, 9> member13745_{};
    ScriptState16 state16_{};
    ScriptState58 state58_{};
};

class MbcSpecabGb final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabGb(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member14715_{};
    std::int32_t member14773_{};
    std::int32_t member14774_{};
};

class MbcSpecabHa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabHa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> TypeTh();
    Task<Value> RcvUser3(std::int32_t parameter1, String parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    std::int32_t member12407_{};
    ScriptState14 state14_{};
    ScriptState16 state16_{};
    std::array<std::uint8_t, 56> member14775_{};
    String member14776_{};
    std::string member14777_;
    MultiObjectActionParameters member14779_{};
    std::int8_t member14785_{};
    std::array<std::int8_t, 14> member14790_{};
    std::array<std::int8_t, 14> member14792_{};
    std::array<std::uint8_t, 1> member14794_{};
    std::array<std::uint8_t, 20> member14795_{};
    std::array<std::uint8_t, 11> member14796_{};
    std::array<std::uint8_t, 18> member14797_{};
    std::array<std::uint8_t, 5> member14798_{};
    std::int32_t member14807_{};
    std::array<std::uint8_t, 128> member14809_{};
    std::int32_t member14811_{};
    std::int32_t member14812_{};
    std::array<std::uint8_t, 18> member14813_{};
    std::int32_t member14817_{};
};

class MbcSpecabIc final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabIc(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    String member13744_{};
    std::array<std::uint8_t, 9> member13745_{};
    ScriptState16 state16_{};
    ScriptState58 state58_{};
};

class MbcSpecabMa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabMa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member14715_{};
    std::int32_t member14773_{};
    std::int32_t member14774_{};
};

class MbcSpecabMb final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabMb(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> helper26_1();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState24 state24_{};
    std::int32_t member14841_{};
    std::int32_t member14842_{};
    std::int32_t member14843_{};
    std::array<std::uint8_t, 16> member14845_{};
    String member14846_{};
    std::array<std::uint8_t, 7> member14847_{};
    std::array<std::uint8_t, 9> member14848_{};
    std::int32_t member14849_{};
};

class MbcSpecabMc final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabMc(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> CheckMob();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member14715_{};
    std::int32_t member14773_{};
};

class MbcSpecabNa final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabNa(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
};

class MbcSpecabNb final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabNb(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
};

class MbcSpecabNc final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcSpecabNc(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
};

class MbcStBrushwood final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStBrushwood(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcStChern final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStChern(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcStCoin final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStCoin(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<void> turnc();
    float RcvUser8(std::int32_t parameter1, String parameter2);
    std::int32_t CheckFree();
    Task<void> pturn();
    Task<void> cleanup_turnc();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member14868_{};
    float member14869_{};
    std::int32_t member14870_{};
    std::array<std::uint8_t, 9> member14871_{};
};

class MbcStEar final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStEar(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> GetMyPa();
    std::int32_t SCHN(std::int32_t parameter1, String parameter2, String parameter3, String parameter4, std::int32_t parameter5, std::int32_t parameter6, std::int32_t parameter7, std::int32_t parameter8, std::int32_t parameter9, std::int32_t parameter10, std::int32_t parameter11, std::int32_t parameter12, std::int32_t parameter13, std::int32_t parameter14);
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> RG();
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    std::int32_t GetEar(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState15 state15_{};
    std::array<std::uint8_t, 20> member14873_{};
    std::array<std::uint8_t, 20> member14874_{};
    std::array<std::uint8_t, 20> member14875_{};
    std::int32_t member14877_{};
    std::int32_t member14878_{};
    std::int32_t member14879_{};
    std::int32_t member14880_{};
    std::int32_t member14881_{};
    std::int32_t member14882_{};
    std::int32_t member14883_{};
    std::int32_t member14884_{};
    std::int32_t member14885_{};
    std::int32_t member14886_{};
    std::int32_t member14887_{};
    std::int32_t member14888_{};
    String member14889_{};
    String member14890_{};
    String member14891_{};
    std::int32_t member14892_{};
    std::int32_t member14893_{};
    std::int32_t member14894_{};
    std::int32_t member14895_{};
    std::int32_t member14896_{};
    std::int32_t member14897_{};
    std::int32_t member14898_{};
    std::int32_t member14899_{};
    std::int32_t member14900_{};
    std::int32_t member14901_{};
    std::array<String, 2> member14924_{};
    std::array<std::uint8_t, 3> member14925_{};
    std::array<std::uint8_t, 2> member14926_{};
    std::array<std::uint8_t, 2> member14927_{};
    std::array<std::uint8_t, 5> member14928_{};
    std::array<std::uint8_t, 11> member14930_{};
    std::array<String, 2> member14931_{};
    std::array<std::uint8_t, 5> member14932_{};
    std::int32_t member14942_{};
    std::array<std::uint8_t, 6> member14944_{};
    std::array<std::uint8_t, 6> member14945_{};
    std::array<std::uint8_t, 7> member14946_{};
    std::array<std::uint8_t, 7> member14947_{};
    std::array<std::uint8_t, 6> member14948_{};
    std::array<std::uint8_t, 7> member14949_{};
    std::array<std::uint8_t, 5> member14950_{};
    std::array<std::uint8_t, 6> member14951_{};
    std::array<std::uint8_t, 6> member14952_{};
    std::array<std::uint8_t, 6> member14953_{};
    std::array<std::uint8_t, 7> member14954_{};
    std::array<std::uint8_t, 7> member14955_{};
    std::array<std::uint8_t, 6> member14956_{};
    std::array<std::uint8_t, 7> member14957_{};
    std::array<std::uint8_t, 5> member14958_{};
    std::array<std::uint8_t, 5> member14959_{};
    std::array<std::uint8_t, 6> member14960_{};
    std::int32_t member14961_{};
    std::int32_t member14962_{};
    String member14963_{};
};

class MbcStExpball final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStExpball(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
};

class MbcStKey final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStKey(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<void> Cli();
    Task<std::int32_t> RcvUser6(std::int32_t parameter1, String parameter2);
    Value SaveGame3();
    Task<std::int32_t> CloseCont(std::int32_t parameter1);
    Task<std::int32_t> LoadLab(std::int32_t parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState41 state41_{};
    std::int32_t member14969_{};
    std::int32_t member14970_{};
    std::int32_t member14971_{};
    String member14973_{};
    String member14974_{};
    std::int32_t member14975_{};
    std::int32_t member14976_{};
    std::array<std::uint8_t, 64> member14978_{};
    float member14980_{};
    float member14981_{};
    std::array<std::uint8_t, 7> member15011_{};
    std::array<std::uint8_t, 6> member15012_{};
    std::array<std::uint8_t, 3> member15013_{};
    std::int32_t member15014_{};
    std::int32_t member15015_{};
    std::int32_t member15016_{};
    std::int32_t member15017_{};
    std::array<std::uint8_t, 30> member15018_{};
    String member15020_{};
    std::array<std::uint8_t, 75> member15021_{};
    std::array<std::uint8_t, 19> member15022_{};
    std::array<std::uint8_t, 3> member15023_{};
    std::array<std::uint8_t, 6> member15024_{};
    std::int32_t member15025_{};
    std::array<std::uint8_t, 22> member15026_{};
    std::array<std::uint8_t, 29> member15027_{};
    std::int32_t member15029_{};
    std::int32_t member15030_{};
    std::int32_t member15031_{};
    std::int32_t member15032_{};
    String member15033_{};
    std::int8_t member15034_{};
    String member15035_{};
    Address member15036_{};
    std::array<Address, 2> member15037_{};
    Address member15038_{};
    float member15039_{};
    std::array<std::uint8_t, 16> member15040_{};
    std::array<std::uint8_t, 10> member15041_{};
    String member15042_{};
};

class MbcStKey2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStKey2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::array<std::uint8_t, 7> member13651_{};
    ScriptState12 state12_{};
    std::array<std::uint8_t, 18> member15054_{};
};

class MbcStLight1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStLight1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState29 state29_{};
    ScriptState39 state39_{};
};

class MbcStLight2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStLight2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState29 state29_{};
};

class MbcStLight3 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStLight3(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState29 state29_{};
    ScriptState39 state39_{};
};

class MbcStLight4 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStLight4(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState29 state29_{};
};

class MbcStLoot final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStLoot(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    std::array<std::uint8_t, 18> member15080_{};
    std::array<std::uint8_t, 16> member15081_{};
};

class MbcStMap final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStMap(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    std::int32_t GetScale();
    Task<std::int32_t> TestMap(float parameter1, float parameter2, float parameter3);
    std::int32_t SndUser(String parameter1);
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    std::int32_t sphereXZ2MapXY(float parameter1, float parameter2, IntRef parameter3, IntRef parameter4, std::int8_t parameter5);
    std::int32_t mapXY2SphereXZ(std::int32_t parameter1, std::int32_t parameter2, FloatRef parameter3, FloatRef parameter4);
    Task<void> ShowMap();
    void helper20_1();
    void helper61_1();
    Task<void> cleanup_ShowMap();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    std::array<std::uint8_t, 40> member15085_{};
    std::int32_t member15086_{};
    std::string member15088_;
    String member15090_{};
    std::array<std::uint8_t, 96> member15091_{};
    std::array<std::uint8_t, 96> member15093_{};
    std::array<std::uint8_t, 96> member15095_{};
    std::int32_t member15097_{};
    float member15098_{};
    float member15099_{};
    float member15100_{};
    std::int32_t member15128_{};
    std::int32_t member15129_{};
    std::int32_t member15130_{};
    String member15131_{};
    String member15132_{};
    std::int32_t member15133_{};
    std::int32_t member15134_{};
    std::array<std::uint8_t, 7> member15135_{};
    std::array<std::uint8_t, 7> member15136_{};
    std::array<std::uint8_t, 7> member15137_{};
    std::array<std::uint8_t, 7> member15138_{};
    float member15139_{};
    float member15140_{};
    IntRef member15141_{};
    IntRef member15142_{};
    std::int8_t member15143_{};
    std::int32_t member15144_{};
    std::int32_t member15145_{};
    FloatRef member15146_{};
    FloatRef member15147_{};
    std::int32_t member15149_{};
    std::int32_t member15150_{};
    std::int32_t member15151_{};
    std::int32_t member15152_{};
    std::int32_t member15153_{};
    std::int32_t member15154_{};
    std::int32_t member15155_{};
    std::int32_t member15156_{};
    std::int32_t member15157_{};
    std::int32_t member15158_{};
    std::int32_t member15159_{};
    std::int32_t member15160_{};
    std::array<std::int32_t, 24> member15161_{};
    std::array<std::int32_t, 24> member15163_{};
    std::int32_t member15164_{};
    std::int32_t member15165_{};
    std::int32_t member15166_{};
    std::int32_t member15167_{};
    std::int32_t member15168_{};
    std::int32_t member15169_{};
    std::int32_t member15170_{};
    std::int32_t member15171_{};
    std::int32_t member15172_{};
    Address member15173_{};
    float member15174_{};
    float member15175_{};
    std::int32_t member15176_{};
    float member15177_{};
    float member15178_{};
    float member15179_{};
    float member15180_{};
    String member15181_{};
    std::array<std::uint8_t, 10> member15182_{};
    std::array<std::uint8_t, 9> member15183_{};
    std::array<std::uint8_t, 8> member15184_{};
    std::array<std::uint8_t, 15> member15185_{};
    std::array<std::uint8_t, 6> member15186_{};
    std::array<std::uint8_t, 9> member15187_{};
    String member15188_{};
    std::array<std::uint8_t, 8> member15189_{};
    std::array<std::uint8_t, 8> member15190_{};
    std::array<std::uint8_t, 9> member15191_{};
    std::array<std::uint8_t, 7> member15192_{};
    std::array<std::uint8_t, 15> member15193_{};
    std::array<std::uint8_t, 6> member15194_{};
    std::array<std::uint8_t, 9> member15195_{};
    String member15196_{};
    std::array<std::uint8_t, 15> member15197_{};
    std::array<std::uint8_t, 9> member15198_{};
    std::array<std::uint8_t, 10> member15199_{};
    std::array<std::uint8_t, 15> member15200_{};
    std::array<std::uint8_t, 9> member15201_{};
    std::array<std::uint8_t, 9> member15202_{};
    std::int32_t member15204_{};
    std::array<std::uint8_t, 8> member15205_{};
    std::array<std::uint8_t, 1> member15206_{};
    std::array<std::uint8_t, 1> member15207_{};
    String member15208_{};
    std::array<std::uint8_t, 10> member15209_{};
    std::array<std::uint8_t, 9> member15210_{};
};

class MbcStShamp final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStShamp(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> FillPict();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState15 state15_{};
    ScriptState29 state29_{};
    std::array<std::uint8_t, 56> member15212_{};
    String member15213_{};
    std::int8_t member15221_{};
    std::array<std::uint8_t, 8> member15224_{};
    std::array<std::uint8_t, 8> member15225_{};
    std::array<std::uint8_t, 8> member15226_{};
    std::array<std::uint8_t, 8> member15227_{};
    std::array<std::uint8_t, 2> member15228_{};
    std::array<std::uint8_t, 2> member15230_{};
    std::array<std::int8_t, 14> member15232_{};
    std::array<std::int8_t, 14> member15234_{};
    float member15237_{};
    std::array<std::uint8_t, 11> member15238_{};
    std::array<std::uint8_t, 18> member15239_{};
    std::array<std::uint8_t, 11> member15240_{};
    std::array<std::uint8_t, 5> member15250_{};
};

class MbcStString final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcStString(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    std::int32_t StrCnt();
    Task<Value> setEvilClan(std::int32_t parameter1);
    std::int32_t GetNitkaInfo(IntRef parameter1, String parameter2);
    std::int32_t GetNitkaCountFromServer();
    std::int32_t GetNitkaCountReceived();
    std::int32_t GetAntiHackNitkaCount();
    Task<void> RegRegionReceiver();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    ScriptState13 state13_{};
    std::array<std::uint8_t, 5> member13731_{};
    std::int32_t member15251_{};
    std::int32_t member15252_{};
    std::int32_t member15253_{};
    std::array<std::uint8_t, 20> member15254_{};
    std::int32_t member15257_{};
    std::int32_t member15258_{};
    std::array<String, 2> member15284_{};
    std::array<std::uint8_t, 2> member15286_{};
    std::int32_t member15297_{};
    std::array<std::uint8_t, 19> member15298_{};
    IntRef member15299_{};
    String member15300_{};
    std::array<std::uint8_t, 1> member15301_{};
    std::array<std::uint8_t, 256> member15303_{};
    std::int32_t member15305_{};
    std::int32_t member15306_{};
};

class MbcTelep final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<String> RcvUser5(std::int32_t parameter1, String parameter2);
    Task<void> Qupd();
    Task<Value> LoadGame4();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::int32_t member15307_{};
    std::array<Address, 2> member15308_{};
    std::array<std::uint8_t, 11> member15310_{};
    std::array<std::uint8_t, 17> member15314_{};
    std::array<std::uint8_t, 17> member15315_{};
    std::array<std::uint8_t, 18> member15316_{};
    std::array<std::uint8_t, 17> member15317_{};
    std::int32_t member15319_{};
    std::int32_t member15320_{};
    std::array<std::uint8_t, 18> member15321_{};
    std::array<std::uint8_t, 21> member15322_{};
    std::array<std::uint8_t, 17> member15328_{};
    std::array<std::uint8_t, 17> member15329_{};
    std::array<std::uint8_t, 17> member15330_{};
    std::array<std::uint8_t, 11> member15331_{};
    std::array<std::uint8_t, 1> member15332_{};
    std::array<std::uint8_t, 17> member15334_{};
    std::array<std::uint8_t, 17> member15335_{};
    std::array<std::uint8_t, 5> member15336_{};
};

class MbcTelep1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t GetSpecialPointTelep();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    ScriptState35 state35_{};
    std::int32_t member15339_{};
    std::int32_t member15341_{};
};

class MbcTelep2 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep2(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    ScriptState35 state35_{};
};

class MbcTelep3 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep3(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    ScriptState35 state35_{};
};

class MbcTelep4 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep4(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetCS();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    ScriptState35 state35_{};
    std::int32_t member15339_{};
    std::int32_t member15341_{};
    std::int32_t member15403_{};
    std::int32_t member15439_{};
    std::int32_t member15440_{};
    std::int32_t member15442_{};
    std::int32_t member15443_{};
    Address member15444_{};
    float member15445_{};
    float member15446_{};
    std::array<std::uint8_t, 4> member15447_{};
    std::array<std::uint8_t, 4> member15448_{};
    std::array<std::uint8_t, 13> member15449_{};
};

class MbcTelep5 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep5(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> Cli();
    std::int32_t SetMaxLvl(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> Qupd();
    Task<Value> LoadGame4();
    String AddInfo3(String parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member911_{};
    std::int32_t member15452_{};
    std::int32_t member15453_{};
    std::array<Address, 2> member15454_{};
    std::int32_t member15456_{};
    std::int32_t member15457_{};
    std::int32_t member15458_{};
    std::array<std::uint8_t, 17> member15461_{};
    std::array<std::uint8_t, 11> member15462_{};
    std::array<std::uint8_t, 1> member15463_{};
};

class MbcTelep6 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep6(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState11 state11_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    ScriptState35 state35_{};
    std::int32_t member15339_{};
    std::int32_t member15341_{};
};

class MbcTelep7 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep7(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member911_{};
    std::int32_t member15464_{};
    std::int32_t member15465_{};
    std::array<Address, 2> member15466_{};
    std::array<std::int32_t, 20> member15467_{};
};

class MbcTelep8 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep8(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member911_{};
};

class MbcTelep9 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTelep9(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member911_{};
};

class MbcTmntHostage final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTmntHostage(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<float> LoadGame6();
    std::int32_t SndUser(String parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    std::int32_t member2_{};
    std::int32_t member12450_{};
    ScriptState21 state21_{};
    ScriptState25 state25_{};
    Address member12560_{};
    std::int32_t member12564_{};
    std::int32_t member15495_{};
    std::int32_t member15497_{};
    std::array<std::uint8_t, 5> member15500_{};
    Address member15502_{};
    std::array<std::uint8_t, 18> member15503_{};
    std::array<Address, 2> member15505_{};
    std::array<std::uint8_t, 13> member15506_{};
    std::array<Address, 2> member15508_{};
};

class MbcToken final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcToken(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState26 state26_{};
    ScriptState42 state42_{};
    std::int32_t member15552_{};
    String member15540_{};
    std::array<std::uint8_t, 11> member15551_{};
    std::int32_t member15553_{};
    std::int32_t member15554_{};
};

class MbcTokenPr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTokenPr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<Value> LoadGame4();
    Task<void> ShowMessage();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member11722_{};
    std::array<std::uint8_t, 64> member15564_{};
    std::array<std::uint8_t, 64> member15565_{};
    std::int32_t member15566_{};
    std::array<std::uint8_t, 13> member15580_{};
    String member15581_{};
    std::array<std::uint8_t, 6> member15582_{};
    std::array<std::uint8_t, 11> member15583_{};
    std::array<std::uint8_t, 6> member15584_{};
    std::array<std::uint8_t, 29> member15585_{};
    std::int32_t member15587_{};
};

class MbcTokenPrCpy final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTokenPrCpy(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> RG();
    Value AddInfo2(String parameter1);
    std::int32_t SndUser(String parameter1);
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    std::int32_t SetIsland(std::int32_t parameter1, String parameter2, String parameter3, std::int32_t parameter4, std::int32_t parameter5);
    Task<void> ShowMessage();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState26 state26_{};
    std::array<std::uint8_t, 8> member15625_{};
    std::int32_t member15627_{};
    std::int32_t member14557_{};
    std::array<std::uint8_t, 64> member15588_{};
    std::array<std::uint8_t, 20> member15589_{};
    std::int32_t member15591_{};
    std::int32_t member15592_{};
    std::array<std::uint8_t, 14> member15619_{};
    std::array<std::uint8_t, 5> member15620_{};
    std::int32_t member15621_{};
    std::array<std::uint8_t, 18> member15622_{};
    std::int32_t member15624_{};
    std::int32_t member15628_{};
    std::int32_t member15629_{};
    std::array<std::uint8_t, 11> member15631_{};
    std::array<std::uint8_t, 5> member15632_{};
    std::array<std::uint8_t, 29> member15633_{};
    std::int32_t member15635_{};
    String member15636_{};
    std::int32_t member15637_{};
    String member15638_{};
    String member15639_{};
    std::int32_t member15640_{};
    std::int32_t member15641_{};
};

class MbcTokenS final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTokenS(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> Use(std::int32_t parameter1, std::int32_t parameter2);
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<Value> RcvUser3(std::int32_t parameter1, String parameter2);
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    Task<std::int32_t> UseClient2();
    Task<Value> LoadGame4();
    std::int32_t SaveGame();
    String AddInfo3(String parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState26 state26_{};
    std::array<Address, 2> member15642_{};
    std::array<std::uint8_t, 18> member15656_{};
    std::array<std::uint8_t, 8> member15660_{};
    String member15662_{};
    std::int32_t member15665_{};
    std::array<String, 2> member15666_{};
    std::array<std::uint8_t, 256> member15668_{};
    std::array<std::uint8_t, 11> member15670_{};
    std::array<std::uint8_t, 9> member15671_{};
    std::array<std::uint8_t, 16> member15672_{};
    std::array<std::uint8_t, 11> member15673_{};
    std::int32_t member15674_{};
    std::int32_t member15675_{};
    std::int32_t member15676_{};
    std::array<std::uint8_t, 18> member15677_{};
    std::array<std::uint8_t, 7> member15680_{};
};

class MbcTokenst final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTokenst(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState24 state24_{};
    ScriptState26 state26_{};
    std::int32_t member11114_{};
    std::int32_t member15627_{};
    ScriptState42 state42_{};
    std::int32_t member15552_{};
    String member15683_{};
    std::array<std::uint8_t, 11> member15689_{};
    std::int32_t member15691_{};
    std::int32_t member15692_{};
};

class MbcTournament final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTournament(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    std::int32_t LoadiDiapFromFile(String parameter1, AddressRef parameter2);
    std::int32_t ParseiDiapason(String parameter1, IntRef parameter2, IntRef parameter3);
    std::int32_t ReLoadiDiapFromFile(String parameter1, AddressRef parameter2);
    std::int32_t InIntDiapasons(std::int32_t parameter1, AddressRef parameter2);
    Task<void> CheckUse();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState11 state11_{};
    std::int32_t member911_{};
    std::array<std::uint8_t, 16> member15696_{};
    String member15697_{};
    AddressRef member15698_{};
    std::int32_t member15699_{};
    String member15700_{};
    std::int32_t member15701_{};
    String member15702_{};
    IntRef member15703_{};
    IntRef member15704_{};
    String member15705_{};
    String member15706_{};
    AddressRef member15707_{};
    std::int32_t member15708_{};
    std::int32_t member15709_{};
    AddressRef member15710_{};
    std::int32_t member15711_{};
    std::array<std::uint8_t, 28> member15712_{};
    std::array<std::uint8_t, 22> member15713_{};
};

class MbcTownTable final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTownTable(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t NPL(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, std::int32_t parameter4, String parameter5, std::int32_t parameter6, String parameter7, String parameter8);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    std::int32_t member911_{};
    std::int32_t member9168_{};
    ScriptState48 state48_{};
    String member15724_{};
    std::array<std::uint8_t, 8> member15725_{};
    std::array<std::uint8_t, 21> member15764_{};
};

class MbcTutomsg final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcTutomsg(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> Main();
    std::int32_t LoadGame();
    Task<void> EKill();
    Task<void> CheckPlayer();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState9 state9_{};
    std::int32_t member911_{};
    std::int32_t member15767_{};
    String member15768_{};
    std::array<std::uint8_t, 8> member15769_{};
    Address member15771_{};
    String member15772_{};
    std::array<std::uint8_t, 8> member15773_{};
};

class MbcVir1000 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1000(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    ScriptState19 state19_{};
    std::array<std::uint8_t, 6> member15778_{};
    std::int32_t member15781_{};
    std::int32_t member2_{};
    ScriptState44 state44_{};
    String member3324_{};
    std::int32_t member5327_{};
    std::array<std::uint8_t, 10> member15774_{};
    float member15776_{};
    Address member15777_{};
    String member15779_{};
};

class MbcVir1001 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1001(Host &host);
    void initializeMembers() override;

  private:
    Task<Value> CallEnd2(std::int32_t parameter1);
    ScriptState19 state19_{};
    std::int32_t member15783_{};
    std::array<std::uint8_t, 56> member15784_{};
};

class MbcVir1002 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1002(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member12718_{};
    String member1076_{};
    std::array<std::uint8_t, 5> member15786_{};
};

class MbcVir1003 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1003(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member2_{};
    std::int32_t member12718_{};
    std::int32_t member3180_{};
};

class MbcVir1004 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1004(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1005 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1005(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    std::array<std::uint8_t, 32> member15791_{};
    IntRef member15792_{};
};

class MbcVir1006 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1006(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    std::array<std::uint8_t, 32> member15791_{};
    IntRef member15792_{};
};

class MbcVir1007 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1007(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    std::array<std::uint8_t, 32> member15791_{};
    IntRef member15792_{};
};

class MbcVir1008 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1008(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    std::array<std::uint8_t, 32> member15791_{};
    IntRef member15792_{};
};

class MbcVir1009 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1009(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1010 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1010(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1011 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1011(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1012 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1012(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1013 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1013(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1014 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1014(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1015 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1015(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1016 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1016(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::array<std::uint8_t, 6> member15778_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
    std::int32_t member2_{};
};

class MbcVir1017 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1017(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::array<std::uint8_t, 6> member15778_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
    std::int32_t member2_{};
};

class MbcVir1018 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1018(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1019 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1019(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1020 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1020(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1021 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1021(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1022 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1022(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member2_{};
    std::array<std::uint8_t, 5> member2030_{};
};

class MbcVir1023 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1023(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1024 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1024(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1025 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1025(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1026 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1026(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1027 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1027(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1028 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1028(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1030 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1030(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1031 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1031(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1032 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1032(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
};

class MbcVir1034 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1034(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1035 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1035(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1036 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1036(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1037 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1037(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1038 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1038(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1039 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1039(Host &host);
    void initializeMembers() override;

  private:
    Task<void> main();
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
    std::array<std::uint8_t, 7> member15799_{};
};

class MbcVir1040 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1040(Host &host);
    void initializeMembers() override;

  private:
    Task<void> Sh();
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
    std::int32_t member15801_{};
    std::array<std::uint8_t, 6> member15802_{};
};

class MbcVir1041 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1041(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1042 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1042(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1043 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1043(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1044 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1044(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1045 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1045(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1046 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1046(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1047 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1047(Host &host);
    void initializeMembers() override;

  private:
    Task<Value> CallLink2(std::int32_t parameter1);
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    std::array<std::uint8_t, 32> member15791_{};
    IntRef member15792_{};
    std::int32_t member15803_{};
    std::int32_t member15805_{};
};

class MbcVir1048 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1048(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1049 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1049(Host &host);
    void initializeMembers() override;

  private:
    Task<Value> CallLink2(std::int32_t parameter1);
    Task<Value> CallEnd2(std::int32_t parameter1);
    ScriptState19 state19_{};
    std::int32_t member15783_{};
    std::array<std::uint8_t, 17> member15807_{};
    std::array<std::uint8_t, 17> member15808_{};
};

class MbcVir1050 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1050(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1051 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1051(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir1111 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir1111(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    ScriptState20 state20_{};
};

class MbcVir2020 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir2020(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    std::array<std::uint8_t, 32> member15791_{};
    IntRef member15792_{};
};

class MbcVir2021 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVir2021(Host &host);
    void initializeMembers() override;

  private:
    ScriptState19 state19_{};
    std::int32_t member15781_{};
    std::int32_t member15787_{};
    std::int32_t member15788_{};
    std::array<std::uint8_t, 32> member15791_{};
    IntRef member15792_{};
};

class MbcVirus final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVirus(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Value CalcType();
    std::int32_t getVirusID();
    std::int32_t IsControllVirus();
    std::int32_t getVirusClass(IntRef parameter1, IntRef parameter2, IntRef parameter3);
    Task<std::int32_t> SetModifiers(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, IntRef parameter4, std::int32_t parameter5, std::int32_t parameter6, String parameter7, std::int32_t parameter8, std::int32_t parameter9);
    Value CheckLink();
    Value LoadGame5();
    Value SaveGame3();
    Task<void> Timer();
    Task<void> RG();
    Task<void> Flush();
    Value RcvUser(std::int32_t parameter1, String parameter2);
    Task<void> ShowWho();
    Task<void> EKill();
    Task<void> Showtip();
    Value AddInfo2(String parameter1);
    Task<void> progShowEff();
    IntRef GetModifiers();
    std::int32_t GetCaster();
    IntRef GetModifs();
    void GetModifsArr(IntRef parameter1);
    std::int32_t ModifsLoaded();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member9168_{};
    float member12005_{};
    std::int32_t member15809_{};
    std::int32_t member15810_{};
    std::int32_t member15811_{};
    std::int32_t member15812_{};
    std::int32_t member15813_{};
    std::array<std::uint8_t, 32> member15814_{};
    std::int32_t member15816_{};
    std::array<std::uint8_t, 20> member15818_{};
    std::int32_t member15819_{};
    std::array<std::uint8_t, 56> member15820_{};
    String member15822_{};
    std::int32_t member15824_{};
    std::int32_t member15825_{};
    std::int32_t member15826_{};
    std::array<std::uint8_t, 20> member15827_{};
    std::array<std::uint8_t, 6> member15836_{};
    std::array<std::uint8_t, 18> member15837_{};
    std::array<std::uint8_t, 16> member15838_{};
    std::array<std::uint8_t, 128> member15840_{};
    std::array<std::uint8_t, 4> member15842_{};
    std::array<std::uint8_t, 8> member15843_{};
    std::array<std::uint8_t, 8> member15844_{};
    std::array<std::uint8_t, 8> member15845_{};
    std::array<std::uint8_t, 8> member15846_{};
    std::array<std::uint8_t, 3> member15847_{};
    std::array<std::uint8_t, 11> member15848_{};
    std::array<std::uint8_t, 2> member15849_{};
    std::array<std::uint8_t, 2> member15851_{};
    std::array<std::uint8_t, 18> member15852_{};
    std::array<std::int8_t, 14> member15854_{};
    std::array<std::int8_t, 14> member15856_{};
    std::array<std::uint8_t, 1> member15858_{};
    std::array<std::uint8_t, 11> member15860_{};
    std::int32_t member15866_{};
    IntRef member15867_{};
    std::int32_t member15868_{};
    std::array<std::uint8_t, 8> member15869_{};
    std::array<std::uint8_t, 8> member15870_{};
    std::array<std::uint8_t, 8> member15871_{};
    std::array<std::uint8_t, 8> member15872_{};
    IntRef member15873_{};
    IntRef member15874_{};
    IntRef member15875_{};
    std::int32_t member15876_{};
    std::int32_t member15877_{};
    std::int32_t member15878_{};
    IntRef member15879_{};
    std::int32_t member15880_{};
    std::int32_t member15881_{};
    String member15882_{};
    std::int32_t member15883_{};
    std::int32_t member15884_{};
    std::array<std::int32_t, 3> member15885_{};
    std::int32_t member15886_{};
    std::int32_t member15887_{};
    std::int32_t member15888_{};
    std::int32_t member15889_{};
    std::array<std::uint8_t, 8> member15890_{};
    String member15892_{};
    std::array<std::uint8_t, 3> member15893_{};
    std::array<std::uint8_t, 4> member15894_{};
    std::array<std::uint8_t, 4> member15895_{};
    std::array<std::uint8_t, 4> member15896_{};
    std::array<std::uint8_t, 4> member15897_{};
    std::array<std::uint8_t, 4> member15898_{};
    String member15899_{};
    std::array<std::uint8_t, 3> member15900_{};
    std::array<std::uint8_t, 4> member15901_{};
    std::array<std::uint8_t, 4> member15902_{};
    std::array<std::uint8_t, 4> member15903_{};
    std::array<std::uint8_t, 4> member15904_{};
    String member15906_{};
    std::array<std::uint8_t, 10> member15907_{};
    std::int32_t member15909_{};
    std::int32_t member15910_{};
    std::int32_t member15911_{};
    std::int32_t member15912_{};
    std::array<std::uint8_t, 64> member15914_{};
    std::array<std::uint8_t, 64> member15915_{};
    std::array<std::uint8_t, 11> member15917_{};
    std::array<std::uint8_t, 18> member15918_{};
    std::int32_t member15920_{};
    std::int32_t member15921_{};
    String member15922_{};
    std::array<std::uint8_t, 1> member15923_{};
    String member15924_{};
    std::array<std::uint8_t, 5> member15925_{};
    IntRef member15927_{};
};

class MbcVnCandy final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnCandy(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member15978_{};
    ScriptState59 state59_{};
};

class MbcVnCryst final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnCryst(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    ScriptState60 state60_{};
};

class MbcVnCrystq final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnCrystq(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> TimerEff();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState10 state10_{};
    ScriptState14 state14_{};
    std::int32_t member911_{};
    ScriptState60 state60_{};
};

class MbcVnExp final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnExp(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t GetParam(std::int32_t parameter1, std::int32_t parameter2, std::int32_t parameter3, IntRef parameter4, IntRef parameter5, IntRef parameter6, IntRef parameter7, IntRef parameter8, IntRef parameter9, IntRef parameter10, IntRef parameter11);
    std::int32_t GetMaxCharge();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
};

class MbcVnKarma final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnKarma(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState26 state26_{};
    std::array<std::uint8_t, 8> member15625_{};
    String member16020_{};
    std::array<std::uint8_t, 7> member16021_{};
    std::array<std::uint8_t, 8> member16022_{};
};

class MbcVnKarma1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnKarma1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState26 state26_{};
    String member16023_{};
    std::int32_t member16024_{};
    std::int32_t member16025_{};
    String member16026_{};
    std::array<std::uint8_t, 8> member16027_{};
    std::array<std::uint8_t, 8> member16028_{};
    std::array<std::uint8_t, 8> member16029_{};
};

class MbcVnMirror final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnMirror(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member15978_{};
    ScriptState59 state59_{};
};

class MbcVnPurge final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnPurge(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState17 state17_{};
    std::int32_t member13796_{};
    std::array<std::uint8_t, 6> member13823_{};
    std::array<std::uint8_t, 56> member16031_{};
    String member16032_{};
    std::int32_t member16034_{};
    std::int32_t member16035_{};
    float member16039_{};
    std::int8_t member16041_{};
    std::array<std::uint8_t, 3> member16046_{};
    std::array<std::uint8_t, 11> member16047_{};
    std::array<std::uint8_t, 2> member16048_{};
    std::array<std::uint8_t, 1> member16052_{};
    std::array<std::uint8_t, 11> member16054_{};
    std::array<std::uint8_t, 5> member16055_{};
};

class MbcVnRandbox final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnRandbox(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState61 state61_{};
    std::int32_t member16066_{};
    std::array<std::uint8_t, 14> member16079_{};
};

class MbcVnRet final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnRet(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::array<std::uint8_t, 4> member16089_{};
};

class MbcVnRet1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnRet1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::int32_t member16090_{};
};

class MbcVnRet2010 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnRet2010(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    std::array<std::uint8_t, 4> member16089_{};
};

class MbcVnSnowman final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnSnowman(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<void> FillPict();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    String member16091_{};
    std::int32_t member16106_{};
    std::array<std::uint8_t, 12> member16109_{};
    std::array<std::uint8_t, 8> member16127_{};
};

class MbcVnStonea final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnStonea(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState26 state26_{};
    String member16020_{};
    std::array<std::uint8_t, 9> member16134_{};
};

class MbcVnStoneb final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnStoneb(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
};

class MbcVnStonew final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnStonew(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
};

class MbcVnSummon final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnSummon(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::int32_t member15978_{};
    std::array<std::uint8_t, 5> member16152_{};
};

class MbcVnTnmntRandbox final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnTnmntRandbox(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    std::int32_t LoadGame();
    std::int32_t SaveGame();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState61 state61_{};
    std::array<std::uint8_t, 14> member16165_{};
    std::array<std::uint8_t, 14> member16166_{};
};

class MbcVnTokensin final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnTokensin(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<std::int32_t> UseServer2(std::int32_t parameter1, std::int32_t parameter2);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState6 state6_{};
    ScriptState7 state7_{};
    ScriptState24 state24_{};
    ScriptState26 state26_{};
    std::int32_t member11114_{};
    std::int32_t member15627_{};
    ScriptState42 state42_{};
    String member16183_{};
};

class MbcVnWell final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcVnWell(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<void> RcvUser9(std::int32_t parameter1, String parameter2);
    Task<void> sendpop();
    void helper95_1();
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    std::int32_t member16185_{};
    Address member16186_{};
};

class MbcWpArbalest1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpArbalest1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::array<std::uint8_t, 7> member13651_{};
    ScriptState12 state12_{};
    ScriptState62 state62_{};
};

class MbcWpArbalest1f final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpArbalest1f(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::array<std::uint8_t, 7> member13651_{};
    ScriptState12 state12_{};
    ScriptState62 state62_{};
};

class MbcWpAroma final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpAroma(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> EInit();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState14 state14_{};
    ScriptState16 state16_{};
    std::int8_t member16225_{};
};

class MbcWpArrow1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpArrow1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
};

class MbcWpAxe1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpAxe1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState12 state12_{};
};

class MbcWpAxe1f final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpAxe1f(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState12 state12_{};
};

class MbcWpAxeBoar final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpAxeBoar(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    Task<void> ContMan();
    Task<std::int32_t> GetInfo(std::int32_t parameter1, std::int32_t parameter2, String parameter3);
    Task<Value> LoadGame4();
    std::int32_t SaveGame();
    Value AddInfo2(String parameter1);
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    std::array<std::uint8_t, 12> member16248_{};
    std::array<std::uint8_t, 128> member16249_{};
    std::array<std::uint8_t, 4> member16250_{};
    std::array<std::uint8_t, 14> member16253_{};
};

class MbcWpSword1 final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpSword1(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState12 state12_{};
};

class MbcWpSword1f final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpSword1f(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState12 state12_{};
};

class MbcWpSword1st final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpSword1st(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState12 state12_{};
};

class MbcWpSword1u final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcWpSword1u(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState8 state8_{};
    ScriptState9 state9_{};
    ScriptState12 state12_{};
};

class MbcX2Degree final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcX2Degree(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcX2TitDegr final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcX2TitDegr(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

class MbcX2Titul final : public Module
{
    friend class ScriptHelpers;
  public:
    explicit MbcX2Titul(Host &host);
    void initializeMembers() override;
    Address position() override;

  private:
    ScriptState1 state1_{};
    std::int32_t member46_{};
    std::int32_t member150_{};
    ScriptState2 state2_{};
    ScriptState3 state3_{};
    ScriptState4 state4_{};
    ScriptState5 state5_{};
    ScriptState7 state7_{};
    ScriptState9 state9_{};
    ScriptState11 state11_{};
    ScriptState12 state12_{};
    ScriptState15 state15_{};
};

std::shared_ptr<Module> createModule(Host &host, std::string_view name);
std::span<const std::string_view> moduleNames() noexcept;
std::string_view moduleName(std::uint32_t tag) noexcept;
std::uint32_t moduleTag(std::string_view name) noexcept;
}
