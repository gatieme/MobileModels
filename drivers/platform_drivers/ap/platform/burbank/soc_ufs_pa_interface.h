#ifndef __SOC_UFS_PA_INTERFACE_H__
#define __SOC_UFS_PA_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_PA_PA_PHY_Type_ADDR(base) ((base) + (0x1500UL))
#define SOC_UFS_PA_PA_AvailTxDataLanes_ADDR(base) ((base) + (0x1520UL))
#define SOC_UFS_PA_PA_AvailRxDataLanes_ADDR(base) ((base) + (0x1540UL))
#define SOC_UFS_PA_PA_MinRxTrailingClocks_ADDR(base) ((base) + (0x1543UL))
#define SOC_UFS_PA_PA_TxHsG1SyncLength_ADDR(base) ((base) + (0x1552UL))
#define SOC_UFS_PA_PA_TxHsG1PrepareLength_ADDR(base) ((base) + (0x1553UL))
#define SOC_UFS_PA_PA_TxHsG2SyncLength_ADDR(base) ((base) + (0x1554UL))
#define SOC_UFS_PA_PA_TxHsG2PrepareLength_ADDR(base) ((base) + (0x1555UL))
#define SOC_UFS_PA_PA_TxHsG3SyncLength_ADDR(base) ((base) + (0x1556UL))
#define SOC_UFS_PA_PA_TxHsG3PrepareLength_ADDR(base) ((base) + (0x1557UL))
#define SOC_UFS_PA_PA_TxMk2Extension_ADDR(base) ((base) + (0x155AUL))
#define SOC_UFS_PA_PA_PeerScrambling_ADDR(base) ((base) + (0x155BUL))
#define SOC_UFS_PA_PA_TxSkip_ADDR(base) ((base) + (0x155CUL))
#define SOC_UFS_PA_PA_TxSkipPeriod_ADDR(base) ((base) + (0x155DUL))
#define SOC_UFS_PA_PA_Local_TX_LCC_Enable_ADDR(base) ((base) + (0x155EUL))
#define SOC_UFS_PA_PA_Peer_TX_LCC_Enable_ADDR(base) ((base) + (0x155FUL))
#define SOC_UFS_PA_PA_ActiveTxDataLanes_ADDR(base) ((base) + (0x1560UL))
#define SOC_UFS_PA_PA_ConnectedTxDataLanes_ADDR(base) ((base) + (0x1561UL))
#define SOC_UFS_PA_PA_TxTrailingClocks_ADDR(base) ((base) + (0x1564UL))
#define SOC_UFS_PA_PA_TxPWRStatus_ADDR(base) ((base) + (0x1567UL))
#define SOC_UFS_PA_PA_TxGear_ADDR(base) ((base) + (0x1568UL))
#define SOC_UFS_PA_PA_TxTermination_ADDR(base) ((base) + (0x1569UL))
#define SOC_UFS_PA_PA_HSSeries_ADDR(base) ((base) + (0x156AUL))
#define SOC_UFS_PA_PA_PWRMode_ADDR(base) ((base) + (0x1571UL))
#define SOC_UFS_PA_PA_ActiveRxDataLanes_ADDR(base) ((base) + (0x1580UL))
#define SOC_UFS_PA_PA_ConnectedRxDataLanes_ADDR(base) ((base) + (0x1581UL))
#define SOC_UFS_PA_PA_RxPWRStatus_ADDR(base) ((base) + (0x1582UL))
#define SOC_UFS_PA_PA_RxGear_ADDR(base) ((base) + (0x1583UL))
#define SOC_UFS_PA_PA_RxTermination_ADDR(base) ((base) + (0x1584UL))
#define SOC_UFS_PA_PA_Scrambling_ADDR(base) ((base) + (0x1585UL))
#define SOC_UFS_PA_PA_MaxRxPWMGear_ADDR(base) ((base) + (0x1586UL))
#define SOC_UFS_PA_PA_MaxRxHSGear_ADDR(base) ((base) + (0x1587UL))
#define SOC_UFS_PA_PA_PACPReqTimeout_ADDR(base) ((base) + (0x1590UL))
#define SOC_UFS_PA_PA_PACPReqEoBTimeout_ADDR(base) ((base) + (0x1591UL))
#define SOC_UFS_PA_PA_RemoteVerInfo_ADDR(base) ((base) + (0x15A0UL))
#define SOC_UFS_PA_PA_LogicalLaneMap_ADDR(base) ((base) + (0x15A1UL))
#define SOC_UFS_PA_PA_SleepNoConfigTime_ADDR(base) ((base) + (0x15A2UL))
#define SOC_UFS_PA_PA_StallNoConfigTime_ADDR(base) ((base) + (0x15A3UL))
#define SOC_UFS_PA_PA_SaveConfigTime_ADDR(base) ((base) + (0x15A4UL))
#define SOC_UFS_PA_PA_RxHSUnterminationCapability_ADDR(base) ((base) + (0x15A5UL))
#define SOC_UFS_PA_PA_RxLSTerminationCapability_ADDR(base) ((base) + (0x15A6UL))
#define SOC_UFS_PA_PA_Hibern8Time_ADDR(base) ((base) + (0x15A7UL))
#define SOC_UFS_PA_PA_TActivate_ADDR(base) ((base) + (0x15A8UL))
#define SOC_UFS_PA_PA_LocalVerInfo_ADDR(base) ((base) + (0x15A9UL))
#define SOC_UFS_PA_PA_Granularity_ADDR(base) ((base) + (0x15AAUL))
#define SOC_UFS_PA_PA_MK2ExtensionGuardBand_ADDR(base) ((base) + (0x15ABUL))
#define SOC_UFS_PA_PA_PWRModeUserData0_ADDR(base) ((base) + (0x15B0UL))
#define SOC_UFS_PA_PA_PWRModeUserData1_ADDR(base) ((base) + (0x15B1UL))
#define SOC_UFS_PA_PA_PWRModeUserData2_ADDR(base) ((base) + (0x15B2UL))
#define SOC_UFS_PA_PA_PWRModeUserData3_ADDR(base) ((base) + (0x15B3UL))
#define SOC_UFS_PA_PA_PWRModeUserData4_ADDR(base) ((base) + (0x15B4UL))
#define SOC_UFS_PA_PA_PWRModeUserData5_ADDR(base) ((base) + (0x15B5UL))
#define SOC_UFS_PA_PA_PWRModeUserData6_ADDR(base) ((base) + (0x15B6UL))
#define SOC_UFS_PA_PA_PWRModeUserData7_ADDR(base) ((base) + (0x15B7UL))
#define SOC_UFS_PA_PA_PWRModeUserData8_ADDR(base) ((base) + (0x15B8UL))
#define SOC_UFS_PA_PA_PWRModeUserData9_ADDR(base) ((base) + (0x15B9UL))
#define SOC_UFS_PA_PA_PWRModeUserData10_ADDR(base) ((base) + (0x15BAUL))
#define SOC_UFS_PA_PA_PWRModeUserData11_ADDR(base) ((base) + (0x15BBUL))
#define SOC_UFS_PA_PA_PACPFrameCount_ADDR(base) ((base) + (0x15C0UL))
#define SOC_UFS_PA_PA_PACPErrorCount_ADDR(base) ((base) + (0x15C1UL))
#define SOC_UFS_PA_PA_PHYTestControl_ADDR(base) ((base) + (0x15C2UL))
#define SOC_UFS_PA_PA_TxHsG4SyncLength_ADDR(base) ((base) + (0x15D0UL))
#define SOC_UFS_PA_PA_TxHsG4PrepareLength_ADDR(base) ((base) + (0x15D1UL))
#define SOC_UFS_PA_PA_PeerRxHsAdaptRefresh_ADDR(base) ((base) + (0x15D2UL))
#define SOC_UFS_PA_PA_PeerRxHsAdaptInitial_ADDR(base) ((base) + (0x15D3UL))
#define SOC_UFS_PA_PA_TxHsAdaptType_ADDR(base) ((base) + (0x15D4UL))
#define SOC_UFS_PA_PA_AdaptAfterLRSTInPA_INIT_ADDR(base) ((base) + (0x15D5UL))
#define SOC_UFS_PA_VS_OverrideAttrEnable_ADDR(base) ((base) + (0x9500UL))
#define SOC_UFS_PA_VS_OverrideAdvTactivate_ADDR(base) ((base) + (0x9501UL))
#define SOC_UFS_PA_VS_OverrideAdvHiber8_ADDR(base) ((base) + (0x9502UL))
#define SOC_UFS_PA_VS_OverrideAdvGran_ADDR(base) ((base) + (0x9503UL))
#define SOC_UFS_PA_VS_CFG_AFIFO_CTRL_ADDR(base) ((base) + (0x9504UL))
#define SOC_UFS_PA_VS_OverridePwmBurstClosureLength_ADDR(base) ((base) + (0x9505UL))
#define SOC_UFS_PA_VS_OverridePwmSyncLength_ADDR(base) ((base) + (0x9506UL))
#define SOC_UFS_PA_VS_OverridePwmPrepareLength_ADDR(base) ((base) + (0x9507UL))
#define SOC_UFS_PA_VS_SaveConfigTimeIncrement_ADDR(base) ((base) + (0x9508UL))
#define SOC_UFS_PA_VS_OverrideHSG1SyncLength_ADDR(base) ((base) + (0x9509UL))
#define SOC_UFS_PA_VS_OverrideHSG1PrepareLength_ADDR(base) ((base) + (0x950AUL))
#define SOC_UFS_PA_VS_OverrideHSG2SyncLength_ADDR(base) ((base) + (0x950BUL))
#define SOC_UFS_PA_VS_OverrideHSG2PrepareLength_ADDR(base) ((base) + (0x950CUL))
#define SOC_UFS_PA_VS_OverrideHSG3SyncLength_ADDR(base) ((base) + (0x950DUL))
#define SOC_UFS_PA_VS_OverrideHSG3PrepareLength_ADDR(base) ((base) + (0x950EUL))
#define SOC_UFS_PA_PMC_INITIAL_LINERESET_FLAG_ADDR(base) ((base) + (0x950FUL))
#define SOC_UFS_PA_VS_OverrideTxHsUnterminatedLineDriveCapability_ADDR(base) ((base) + (0x9510UL))
#define SOC_UFS_PA_VS_OverrideTxLsTerminatedLineDriveCapability_ADDR(base) ((base) + (0x9511UL))
#define SOC_UFS_PA_VS_OverrideRxMinSleepNoConfigTimeCapability_ADDR(base) ((base) + (0x9512UL))
#define SOC_UFS_PA_VS_OverrideRxMinStallNoConfigTimeCapability_ADDR(base) ((base) + (0x9513UL))
#define SOC_UFS_PA_VS_OverrideRxMinSaveConfigTimeCapability_ADDR(base) ((base) + (0x9514UL))
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_ADDR(base) ((base) + (0x9515UL))
#define SOC_UFS_PA_VS_OverrideTxMinSleepNoConfigTimeDowngraded_ADDR(base) ((base) + (0x9516UL))
#define SOC_UFS_PA_VS_OverrideTxMinStallNoConfigTimeDowngraded_ADDR(base) ((base) + (0x9517UL))
#define SOC_UFS_PA_VS_OverrideTxPwmG6G7SyncLengthDowngraded_ADDR(base) ((base) + (0x9518UL))
#define SOC_UFS_PA_VS_OverrideTxLsPrepareLengthDowngraded_ADDR(base) ((base) + (0x9519UL))
#define SOC_UFS_PA_VS_OverrideTxPwmBurstClosureExtensionDowngraded_ADDR(base) ((base) + (0x951AUL))
#define SOC_UFS_PA_VS_AdjustTrailingClocks_ADDR(base) ((base) + (0x951BUL))
#define SOC_UFS_PA_VS_TxBurstClosureDelay_ADDR(base) ((base) + (0x951CUL))
#define SOC_UFS_PA_VS_Mk2ExtnSupport_ADDR(base) ((base) + (0x951DUL))
#define SOC_UFS_PA_CFG_RX_HIBERNATE_EXIT_DIS_ADDR(base) ((base) + (0x951EUL))
#define SOC_UFS_PA_VS_DebugLoopback_ADDR(base) ((base) + (0x951FUL))
#define SOC_UFS_PA_LOCAL_RX_SKIP_REQUEST_ADDR(base) ((base) + (0x9520UL))
#define SOC_UFS_PA_CFG_RX_CTRL_ADDR(base) ((base) + (0x9521UL))
#define SOC_UFS_PA_BURST_END_TIMER_CFG_ADDR(base) ((base) + (0x9522UL))
#define SOC_UFS_PA_TX_BURST_CONTROL_ADDR(base) ((base) + (0x9523UL))
#define SOC_UFS_PA_CFG_RX_CLK_SEL_MODE_ADDR(base) ((base) + (0x9524UL))
#define SOC_UFS_PA_CFG_RX_SW_CLK_SEL_ADDR(base) ((base) + (0x9525UL))
#define SOC_UFS_PA_HSH8ENT_LR_MODE_ADDR(base) ((base) + (0x9526UL))
#define SOC_UFS_PA_DESKEW_CONTROL_ADDR(base) ((base) + (0x9527UL))
#define SOC_UFS_PA_CFG_ERROR_INJECT_ADDR(base) ((base) + (0x9528UL))
#define SOC_UFS_PA_TX_SAVECFG_UNIT_ADDR(base) ((base) + (0x9529UL))
#define SOC_UFS_PA_PMC_CAP_ATTR_ADDR(base) ((base) + (0x952AUL))
#define SOC_UFS_PA_tx_auto_burst_sel_ADDR(base) ((base) + (0x952BUL))
#define SOC_UFS_PA_PMC_ALIGN_EN_ADDR(base) ((base) + (0x952CUL))
#define SOC_UFS_PA_HSH8ENT_LR_ADDR(base) ((base) + (0x952DUL))
#define SOC_UFS_PA_TX_CTRL_ACT_TIMER_ADDR(base) ((base) + (0x952EUL))
#define SOC_UFS_PA_CFG_UPR_SEND_MODE_ADDR(base) ((base) + (0x952FUL))
#define SOC_UFS_PA_VS_OverrideHSG4SyncLength_ADDR(base) ((base) + (0x9530UL))
#define SOC_UFS_PA_VS_OverrideHSG4PrepareLength_ADDR(base) ((base) + (0x9531UL))
#define SOC_UFS_PA_VS_OverrideHsEqualizerSetting_ADDR(base) ((base) + (0x9532UL))
#define SOC_UFS_PA_VS_OverrideHsAdaptRefresh_ADDR(base) ((base) + (0x9533UL))
#define SOC_UFS_PA_VS_OverrideHsAdaptInitial_ADDR(base) ((base) + (0x9534UL))
#define SOC_UFS_PA_CFG_RX_BURST_SEL_ADDR(base) ((base) + (0x9535UL))
#define SOC_UFS_PA_FSM_Status_ADDR(base) ((base) + (0x9540UL))
#define SOC_UFS_PA_PA_Status_ADDR(base) ((base) + (0x9541UL))
#define SOC_UFS_PA_DBG_CFG_RX_ADDR(base) ((base) + (0x9580UL))
#define SOC_UFS_PA_TX_CFG_DBG0_ADDR(base) ((base) + (0x9581UL))
#define SOC_UFS_PA_TX_CFG_DBG1_ADDR(base) ((base) + (0x9582UL))
#define SOC_UFS_PA_DebugPwrChg_ADDR(base) ((base) + (0x9583UL))
#define SOC_UFS_PA_dbg_trace_01_ADDR(base) ((base) + (0x9584UL))
#define SOC_UFS_PA_dbg_trace_02_ADDR(base) ((base) + (0x9585UL))
#define SOC_UFS_PA_dbg_trace_03_ADDR(base) ((base) + (0x9586UL))
#define SOC_UFS_PA_dbg_trace_04_ADDR(base) ((base) + (0x9587UL))
#define SOC_UFS_PA_dbg_trace_05_ADDR(base) ((base) + (0x9588UL))
#define SOC_UFS_PA_dbg_trace_06_ADDR(base) ((base) + (0x9589UL))
#define SOC_UFS_PA_dbg_trace_07_ADDR(base) ((base) + (0x958aUL))
#define SOC_UFS_PA_dbg_trace_08_ADDR(base) ((base) + (0x958bUL))
#define SOC_UFS_PA_dbg_trace_09_ADDR(base) ((base) + (0x958cUL))
#define SOC_UFS_PA_dbg_trace_10_ADDR(base) ((base) + (0x958dUL))
#define SOC_UFS_PA_dbg_trace_11_ADDR(base) ((base) + (0x958eUL))
#define SOC_UFS_PA_dbg_trace_12_ADDR(base) ((base) + (0x958fUL))
#define SOC_UFS_PA_dbg_trace_13_ADDR(base) ((base) + (0x9590UL))
#define SOC_UFS_PA_dbg_trace_14_ADDR(base) ((base) + (0x9591UL))
#define SOC_UFS_PA_dbg_cfg_rx_01_ADDR(base) ((base) + (0x9592UL))
#define SOC_UFS_PA_dbg_cfg_rx_02_ADDR(base) ((base) + (0x9593UL))
#define SOC_UFS_PA_dbg_cfg_rx_03_ADDR(base) ((base) + (0x9594UL))
#define SOC_UFS_PA_dbg_cfg_rx_04_ADDR(base) ((base) + (0x9595UL))
#define SOC_UFS_PA_dbg_pa_tx_timer_ADDR(base) ((base) + (0x9596UL))
#else
#define SOC_UFS_PA_PA_PHY_Type_ADDR(base) ((base) + (0x1500))
#define SOC_UFS_PA_PA_AvailTxDataLanes_ADDR(base) ((base) + (0x1520))
#define SOC_UFS_PA_PA_AvailRxDataLanes_ADDR(base) ((base) + (0x1540))
#define SOC_UFS_PA_PA_MinRxTrailingClocks_ADDR(base) ((base) + (0x1543))
#define SOC_UFS_PA_PA_TxHsG1SyncLength_ADDR(base) ((base) + (0x1552))
#define SOC_UFS_PA_PA_TxHsG1PrepareLength_ADDR(base) ((base) + (0x1553))
#define SOC_UFS_PA_PA_TxHsG2SyncLength_ADDR(base) ((base) + (0x1554))
#define SOC_UFS_PA_PA_TxHsG2PrepareLength_ADDR(base) ((base) + (0x1555))
#define SOC_UFS_PA_PA_TxHsG3SyncLength_ADDR(base) ((base) + (0x1556))
#define SOC_UFS_PA_PA_TxHsG3PrepareLength_ADDR(base) ((base) + (0x1557))
#define SOC_UFS_PA_PA_TxMk2Extension_ADDR(base) ((base) + (0x155A))
#define SOC_UFS_PA_PA_PeerScrambling_ADDR(base) ((base) + (0x155B))
#define SOC_UFS_PA_PA_TxSkip_ADDR(base) ((base) + (0x155C))
#define SOC_UFS_PA_PA_TxSkipPeriod_ADDR(base) ((base) + (0x155D))
#define SOC_UFS_PA_PA_Local_TX_LCC_Enable_ADDR(base) ((base) + (0x155E))
#define SOC_UFS_PA_PA_Peer_TX_LCC_Enable_ADDR(base) ((base) + (0x155F))
#define SOC_UFS_PA_PA_ActiveTxDataLanes_ADDR(base) ((base) + (0x1560))
#define SOC_UFS_PA_PA_ConnectedTxDataLanes_ADDR(base) ((base) + (0x1561))
#define SOC_UFS_PA_PA_TxTrailingClocks_ADDR(base) ((base) + (0x1564))
#define SOC_UFS_PA_PA_TxPWRStatus_ADDR(base) ((base) + (0x1567))
#define SOC_UFS_PA_PA_TxGear_ADDR(base) ((base) + (0x1568))
#define SOC_UFS_PA_PA_TxTermination_ADDR(base) ((base) + (0x1569))
#define SOC_UFS_PA_PA_HSSeries_ADDR(base) ((base) + (0x156A))
#define SOC_UFS_PA_PA_PWRMode_ADDR(base) ((base) + (0x1571))
#define SOC_UFS_PA_PA_ActiveRxDataLanes_ADDR(base) ((base) + (0x1580))
#define SOC_UFS_PA_PA_ConnectedRxDataLanes_ADDR(base) ((base) + (0x1581))
#define SOC_UFS_PA_PA_RxPWRStatus_ADDR(base) ((base) + (0x1582))
#define SOC_UFS_PA_PA_RxGear_ADDR(base) ((base) + (0x1583))
#define SOC_UFS_PA_PA_RxTermination_ADDR(base) ((base) + (0x1584))
#define SOC_UFS_PA_PA_Scrambling_ADDR(base) ((base) + (0x1585))
#define SOC_UFS_PA_PA_MaxRxPWMGear_ADDR(base) ((base) + (0x1586))
#define SOC_UFS_PA_PA_MaxRxHSGear_ADDR(base) ((base) + (0x1587))
#define SOC_UFS_PA_PA_PACPReqTimeout_ADDR(base) ((base) + (0x1590))
#define SOC_UFS_PA_PA_PACPReqEoBTimeout_ADDR(base) ((base) + (0x1591))
#define SOC_UFS_PA_PA_RemoteVerInfo_ADDR(base) ((base) + (0x15A0))
#define SOC_UFS_PA_PA_LogicalLaneMap_ADDR(base) ((base) + (0x15A1))
#define SOC_UFS_PA_PA_SleepNoConfigTime_ADDR(base) ((base) + (0x15A2))
#define SOC_UFS_PA_PA_StallNoConfigTime_ADDR(base) ((base) + (0x15A3))
#define SOC_UFS_PA_PA_SaveConfigTime_ADDR(base) ((base) + (0x15A4))
#define SOC_UFS_PA_PA_RxHSUnterminationCapability_ADDR(base) ((base) + (0x15A5))
#define SOC_UFS_PA_PA_RxLSTerminationCapability_ADDR(base) ((base) + (0x15A6))
#define SOC_UFS_PA_PA_Hibern8Time_ADDR(base) ((base) + (0x15A7))
#define SOC_UFS_PA_PA_TActivate_ADDR(base) ((base) + (0x15A8))
#define SOC_UFS_PA_PA_LocalVerInfo_ADDR(base) ((base) + (0x15A9))
#define SOC_UFS_PA_PA_Granularity_ADDR(base) ((base) + (0x15AA))
#define SOC_UFS_PA_PA_MK2ExtensionGuardBand_ADDR(base) ((base) + (0x15AB))
#define SOC_UFS_PA_PA_PWRModeUserData0_ADDR(base) ((base) + (0x15B0))
#define SOC_UFS_PA_PA_PWRModeUserData1_ADDR(base) ((base) + (0x15B1))
#define SOC_UFS_PA_PA_PWRModeUserData2_ADDR(base) ((base) + (0x15B2))
#define SOC_UFS_PA_PA_PWRModeUserData3_ADDR(base) ((base) + (0x15B3))
#define SOC_UFS_PA_PA_PWRModeUserData4_ADDR(base) ((base) + (0x15B4))
#define SOC_UFS_PA_PA_PWRModeUserData5_ADDR(base) ((base) + (0x15B5))
#define SOC_UFS_PA_PA_PWRModeUserData6_ADDR(base) ((base) + (0x15B6))
#define SOC_UFS_PA_PA_PWRModeUserData7_ADDR(base) ((base) + (0x15B7))
#define SOC_UFS_PA_PA_PWRModeUserData8_ADDR(base) ((base) + (0x15B8))
#define SOC_UFS_PA_PA_PWRModeUserData9_ADDR(base) ((base) + (0x15B9))
#define SOC_UFS_PA_PA_PWRModeUserData10_ADDR(base) ((base) + (0x15BA))
#define SOC_UFS_PA_PA_PWRModeUserData11_ADDR(base) ((base) + (0x15BB))
#define SOC_UFS_PA_PA_PACPFrameCount_ADDR(base) ((base) + (0x15C0))
#define SOC_UFS_PA_PA_PACPErrorCount_ADDR(base) ((base) + (0x15C1))
#define SOC_UFS_PA_PA_PHYTestControl_ADDR(base) ((base) + (0x15C2))
#define SOC_UFS_PA_PA_TxHsG4SyncLength_ADDR(base) ((base) + (0x15D0))
#define SOC_UFS_PA_PA_TxHsG4PrepareLength_ADDR(base) ((base) + (0x15D1))
#define SOC_UFS_PA_PA_PeerRxHsAdaptRefresh_ADDR(base) ((base) + (0x15D2))
#define SOC_UFS_PA_PA_PeerRxHsAdaptInitial_ADDR(base) ((base) + (0x15D3))
#define SOC_UFS_PA_PA_TxHsAdaptType_ADDR(base) ((base) + (0x15D4))
#define SOC_UFS_PA_PA_AdaptAfterLRSTInPA_INIT_ADDR(base) ((base) + (0x15D5))
#define SOC_UFS_PA_VS_OverrideAttrEnable_ADDR(base) ((base) + (0x9500))
#define SOC_UFS_PA_VS_OverrideAdvTactivate_ADDR(base) ((base) + (0x9501))
#define SOC_UFS_PA_VS_OverrideAdvHiber8_ADDR(base) ((base) + (0x9502))
#define SOC_UFS_PA_VS_OverrideAdvGran_ADDR(base) ((base) + (0x9503))
#define SOC_UFS_PA_VS_CFG_AFIFO_CTRL_ADDR(base) ((base) + (0x9504))
#define SOC_UFS_PA_VS_OverridePwmBurstClosureLength_ADDR(base) ((base) + (0x9505))
#define SOC_UFS_PA_VS_OverridePwmSyncLength_ADDR(base) ((base) + (0x9506))
#define SOC_UFS_PA_VS_OverridePwmPrepareLength_ADDR(base) ((base) + (0x9507))
#define SOC_UFS_PA_VS_SaveConfigTimeIncrement_ADDR(base) ((base) + (0x9508))
#define SOC_UFS_PA_VS_OverrideHSG1SyncLength_ADDR(base) ((base) + (0x9509))
#define SOC_UFS_PA_VS_OverrideHSG1PrepareLength_ADDR(base) ((base) + (0x950A))
#define SOC_UFS_PA_VS_OverrideHSG2SyncLength_ADDR(base) ((base) + (0x950B))
#define SOC_UFS_PA_VS_OverrideHSG2PrepareLength_ADDR(base) ((base) + (0x950C))
#define SOC_UFS_PA_VS_OverrideHSG3SyncLength_ADDR(base) ((base) + (0x950D))
#define SOC_UFS_PA_VS_OverrideHSG3PrepareLength_ADDR(base) ((base) + (0x950E))
#define SOC_UFS_PA_PMC_INITIAL_LINERESET_FLAG_ADDR(base) ((base) + (0x950F))
#define SOC_UFS_PA_VS_OverrideTxHsUnterminatedLineDriveCapability_ADDR(base) ((base) + (0x9510))
#define SOC_UFS_PA_VS_OverrideTxLsTerminatedLineDriveCapability_ADDR(base) ((base) + (0x9511))
#define SOC_UFS_PA_VS_OverrideRxMinSleepNoConfigTimeCapability_ADDR(base) ((base) + (0x9512))
#define SOC_UFS_PA_VS_OverrideRxMinStallNoConfigTimeCapability_ADDR(base) ((base) + (0x9513))
#define SOC_UFS_PA_VS_OverrideRxMinSaveConfigTimeCapability_ADDR(base) ((base) + (0x9514))
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_ADDR(base) ((base) + (0x9515))
#define SOC_UFS_PA_VS_OverrideTxMinSleepNoConfigTimeDowngraded_ADDR(base) ((base) + (0x9516))
#define SOC_UFS_PA_VS_OverrideTxMinStallNoConfigTimeDowngraded_ADDR(base) ((base) + (0x9517))
#define SOC_UFS_PA_VS_OverrideTxPwmG6G7SyncLengthDowngraded_ADDR(base) ((base) + (0x9518))
#define SOC_UFS_PA_VS_OverrideTxLsPrepareLengthDowngraded_ADDR(base) ((base) + (0x9519))
#define SOC_UFS_PA_VS_OverrideTxPwmBurstClosureExtensionDowngraded_ADDR(base) ((base) + (0x951A))
#define SOC_UFS_PA_VS_AdjustTrailingClocks_ADDR(base) ((base) + (0x951B))
#define SOC_UFS_PA_VS_TxBurstClosureDelay_ADDR(base) ((base) + (0x951C))
#define SOC_UFS_PA_VS_Mk2ExtnSupport_ADDR(base) ((base) + (0x951D))
#define SOC_UFS_PA_CFG_RX_HIBERNATE_EXIT_DIS_ADDR(base) ((base) + (0x951E))
#define SOC_UFS_PA_VS_DebugLoopback_ADDR(base) ((base) + (0x951F))
#define SOC_UFS_PA_LOCAL_RX_SKIP_REQUEST_ADDR(base) ((base) + (0x9520))
#define SOC_UFS_PA_CFG_RX_CTRL_ADDR(base) ((base) + (0x9521))
#define SOC_UFS_PA_BURST_END_TIMER_CFG_ADDR(base) ((base) + (0x9522))
#define SOC_UFS_PA_TX_BURST_CONTROL_ADDR(base) ((base) + (0x9523))
#define SOC_UFS_PA_CFG_RX_CLK_SEL_MODE_ADDR(base) ((base) + (0x9524))
#define SOC_UFS_PA_CFG_RX_SW_CLK_SEL_ADDR(base) ((base) + (0x9525))
#define SOC_UFS_PA_HSH8ENT_LR_MODE_ADDR(base) ((base) + (0x9526))
#define SOC_UFS_PA_DESKEW_CONTROL_ADDR(base) ((base) + (0x9527))
#define SOC_UFS_PA_CFG_ERROR_INJECT_ADDR(base) ((base) + (0x9528))
#define SOC_UFS_PA_TX_SAVECFG_UNIT_ADDR(base) ((base) + (0x9529))
#define SOC_UFS_PA_PMC_CAP_ATTR_ADDR(base) ((base) + (0x952A))
#define SOC_UFS_PA_tx_auto_burst_sel_ADDR(base) ((base) + (0x952B))
#define SOC_UFS_PA_PMC_ALIGN_EN_ADDR(base) ((base) + (0x952C))
#define SOC_UFS_PA_HSH8ENT_LR_ADDR(base) ((base) + (0x952D))
#define SOC_UFS_PA_TX_CTRL_ACT_TIMER_ADDR(base) ((base) + (0x952E))
#define SOC_UFS_PA_CFG_UPR_SEND_MODE_ADDR(base) ((base) + (0x952F))
#define SOC_UFS_PA_VS_OverrideHSG4SyncLength_ADDR(base) ((base) + (0x9530))
#define SOC_UFS_PA_VS_OverrideHSG4PrepareLength_ADDR(base) ((base) + (0x9531))
#define SOC_UFS_PA_VS_OverrideHsEqualizerSetting_ADDR(base) ((base) + (0x9532))
#define SOC_UFS_PA_VS_OverrideHsAdaptRefresh_ADDR(base) ((base) + (0x9533))
#define SOC_UFS_PA_VS_OverrideHsAdaptInitial_ADDR(base) ((base) + (0x9534))
#define SOC_UFS_PA_CFG_RX_BURST_SEL_ADDR(base) ((base) + (0x9535))
#define SOC_UFS_PA_FSM_Status_ADDR(base) ((base) + (0x9540))
#define SOC_UFS_PA_PA_Status_ADDR(base) ((base) + (0x9541))
#define SOC_UFS_PA_DBG_CFG_RX_ADDR(base) ((base) + (0x9580))
#define SOC_UFS_PA_TX_CFG_DBG0_ADDR(base) ((base) + (0x9581))
#define SOC_UFS_PA_TX_CFG_DBG1_ADDR(base) ((base) + (0x9582))
#define SOC_UFS_PA_DebugPwrChg_ADDR(base) ((base) + (0x9583))
#define SOC_UFS_PA_dbg_trace_01_ADDR(base) ((base) + (0x9584))
#define SOC_UFS_PA_dbg_trace_02_ADDR(base) ((base) + (0x9585))
#define SOC_UFS_PA_dbg_trace_03_ADDR(base) ((base) + (0x9586))
#define SOC_UFS_PA_dbg_trace_04_ADDR(base) ((base) + (0x9587))
#define SOC_UFS_PA_dbg_trace_05_ADDR(base) ((base) + (0x9588))
#define SOC_UFS_PA_dbg_trace_06_ADDR(base) ((base) + (0x9589))
#define SOC_UFS_PA_dbg_trace_07_ADDR(base) ((base) + (0x958a))
#define SOC_UFS_PA_dbg_trace_08_ADDR(base) ((base) + (0x958b))
#define SOC_UFS_PA_dbg_trace_09_ADDR(base) ((base) + (0x958c))
#define SOC_UFS_PA_dbg_trace_10_ADDR(base) ((base) + (0x958d))
#define SOC_UFS_PA_dbg_trace_11_ADDR(base) ((base) + (0x958e))
#define SOC_UFS_PA_dbg_trace_12_ADDR(base) ((base) + (0x958f))
#define SOC_UFS_PA_dbg_trace_13_ADDR(base) ((base) + (0x9590))
#define SOC_UFS_PA_dbg_trace_14_ADDR(base) ((base) + (0x9591))
#define SOC_UFS_PA_dbg_cfg_rx_01_ADDR(base) ((base) + (0x9592))
#define SOC_UFS_PA_dbg_cfg_rx_02_ADDR(base) ((base) + (0x9593))
#define SOC_UFS_PA_dbg_cfg_rx_03_ADDR(base) ((base) + (0x9594))
#define SOC_UFS_PA_dbg_cfg_rx_04_ADDR(base) ((base) + (0x9595))
#define SOC_UFS_PA_dbg_pa_tx_timer_ADDR(base) ((base) + (0x9596))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PHY_Type : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_PHY_Type_UNION;
#endif
#define SOC_UFS_PA_PA_PHY_Type_PA_PHY_Type_START (0)
#define SOC_UFS_PA_PA_PHY_Type_PA_PHY_Type_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_AvailableTxDataLanes : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_AvailTxDataLanes_UNION;
#endif
#define SOC_UFS_PA_PA_AvailTxDataLanes_PA_AvailableTxDataLanes_START (0)
#define SOC_UFS_PA_PA_AvailTxDataLanes_PA_AvailableTxDataLanes_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_AvailableRxDataLanes : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_AvailRxDataLanes_UNION;
#endif
#define SOC_UFS_PA_PA_AvailRxDataLanes_PA_AvailableRxDataLanes_START (0)
#define SOC_UFS_PA_PA_AvailRxDataLanes_PA_AvailableRxDataLanes_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_MinRxTrailingClocks : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_MinRxTrailingClocks_UNION;
#endif
#define SOC_UFS_PA_PA_MinRxTrailingClocks_PA_MinRxTrailingClocks_START (0)
#define SOC_UFS_PA_PA_MinRxTrailingClocks_PA_MinRxTrailingClocks_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG1SyncLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_TxHsG1SyncLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG1SyncLength_TxHsG1SyncLength_START (0)
#define SOC_UFS_PA_PA_TxHsG1SyncLength_TxHsG1SyncLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG1PrepareLength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_PA_TxHsG1PrepareLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG1PrepareLength_TxHsG1PrepareLength_START (0)
#define SOC_UFS_PA_PA_TxHsG1PrepareLength_TxHsG1PrepareLength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG2SyncLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_TxHsG2SyncLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG2SyncLength_TxHsG2SyncLength_START (0)
#define SOC_UFS_PA_PA_TxHsG2SyncLength_TxHsG2SyncLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG2PrepareLength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_PA_TxHsG2PrepareLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG2PrepareLength_TxHsG2PrepareLength_START (0)
#define SOC_UFS_PA_PA_TxHsG2PrepareLength_TxHsG2PrepareLength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG3SyncLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_TxHsG3SyncLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG3SyncLength_TxHsG3SyncLength_START (0)
#define SOC_UFS_PA_PA_TxHsG3SyncLength_TxHsG3SyncLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG3PrepareLength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_PA_TxHsG3PrepareLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG3PrepareLength_TxHsG3PrepareLength_START (0)
#define SOC_UFS_PA_PA_TxHsG3PrepareLength_TxHsG3PrepareLength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxMk2Extension : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_TxMk2Extension_UNION;
#endif
#define SOC_UFS_PA_PA_TxMk2Extension_TxMk2Extension_START (0)
#define SOC_UFS_PA_PA_TxMk2Extension_TxMk2Extension_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerScrambling : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_PeerScrambling_UNION;
#endif
#define SOC_UFS_PA_PA_PeerScrambling_PeerScrambling_START (0)
#define SOC_UFS_PA_PA_PeerScrambling_PeerScrambling_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxSkip : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_TxSkip_UNION;
#endif
#define SOC_UFS_PA_PA_TxSkip_TxSkip_START (0)
#define SOC_UFS_PA_PA_TxSkip_TxSkip_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_TxSkipPeriod : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_UFS_PA_PA_TxSkipPeriod_UNION;
#endif
#define SOC_UFS_PA_PA_TxSkipPeriod_PA_TxSkipPeriod_START (0)
#define SOC_UFS_PA_PA_TxSkipPeriod_PA_TxSkipPeriod_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_LocalTxLccEn : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_Local_TX_LCC_Enable_UNION;
#endif
#define SOC_UFS_PA_PA_Local_TX_LCC_Enable_PA_LocalTxLccEn_START (0)
#define SOC_UFS_PA_PA_Local_TX_LCC_Enable_PA_LocalTxLccEn_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Peer_TX_LCC_Enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_Peer_TX_LCC_Enable_UNION;
#endif
#define SOC_UFS_PA_PA_Peer_TX_LCC_Enable_Peer_TX_LCC_Enable_START (0)
#define SOC_UFS_PA_PA_Peer_TX_LCC_Enable_Peer_TX_LCC_Enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ActiveTxDataLanes : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_ActiveTxDataLanes_UNION;
#endif
#define SOC_UFS_PA_PA_ActiveTxDataLanes_ActiveTxDataLanes_START (0)
#define SOC_UFS_PA_PA_ActiveTxDataLanes_ActiveTxDataLanes_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ConnectedTxDataLanes : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_ConnectedTxDataLanes_UNION;
#endif
#define SOC_UFS_PA_PA_ConnectedTxDataLanes_ConnectedTxDataLanes_START (0)
#define SOC_UFS_PA_PA_ConnectedTxDataLanes_ConnectedTxDataLanes_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxTrailingClocks : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_TxTrailingClocks_UNION;
#endif
#define SOC_UFS_PA_PA_TxTrailingClocks_TxTrailingClocks_START (0)
#define SOC_UFS_PA_PA_TxTrailingClocks_TxTrailingClocks_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_TxPWRStatus : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_TxPWRStatus_UNION;
#endif
#define SOC_UFS_PA_PA_TxPWRStatus_PA_TxPWRStatus_START (0)
#define SOC_UFS_PA_PA_TxPWRStatus_PA_TxPWRStatus_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxGear : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_TxGear_UNION;
#endif
#define SOC_UFS_PA_PA_TxGear_TxGear_START (0)
#define SOC_UFS_PA_PA_TxGear_TxGear_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxTermination : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_TxTermination_UNION;
#endif
#define SOC_UFS_PA_PA_TxTermination_TxTermination_START (0)
#define SOC_UFS_PA_PA_TxTermination_TxTermination_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HSSeries : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_PA_PA_HSSeries_UNION;
#endif
#define SOC_UFS_PA_PA_HSSeries_HSSeries_START (0)
#define SOC_UFS_PA_PA_HSSeries_HSSeries_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxMode : 4;
        unsigned int RxMode : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_PWRMode_UNION;
#endif
#define SOC_UFS_PA_PA_PWRMode_TxMode_START (0)
#define SOC_UFS_PA_PA_PWRMode_TxMode_END (3)
#define SOC_UFS_PA_PA_PWRMode_RxMode_START (4)
#define SOC_UFS_PA_PA_PWRMode_RxMode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ActiveRxDataLanes : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_ActiveRxDataLanes_UNION;
#endif
#define SOC_UFS_PA_PA_ActiveRxDataLanes_ActiveRxDataLanes_START (0)
#define SOC_UFS_PA_PA_ActiveRxDataLanes_ActiveRxDataLanes_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ConnectedRxDataLanes : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_ConnectedRxDataLanes_UNION;
#endif
#define SOC_UFS_PA_PA_ConnectedRxDataLanes_ConnectedRxDataLanes_START (0)
#define SOC_UFS_PA_PA_ConnectedRxDataLanes_ConnectedRxDataLanes_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_RxPWRStatus : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_RxPWRStatus_UNION;
#endif
#define SOC_UFS_PA_PA_RxPWRStatus_PA_RxPWRStatus_START (0)
#define SOC_UFS_PA_PA_RxPWRStatus_PA_RxPWRStatus_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RxGear : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_RxGear_UNION;
#endif
#define SOC_UFS_PA_PA_RxGear_RxGear_START (0)
#define SOC_UFS_PA_PA_RxGear_RxGear_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RxTermination : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_RxTermination_UNION;
#endif
#define SOC_UFS_PA_PA_RxTermination_RxTermination_START (0)
#define SOC_UFS_PA_PA_RxTermination_RxTermination_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Scrambling : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_Scrambling_UNION;
#endif
#define SOC_UFS_PA_PA_Scrambling_Scrambling_START (0)
#define SOC_UFS_PA_PA_Scrambling_Scrambling_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MaxRxPWMGear : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_MaxRxPWMGear_UNION;
#endif
#define SOC_UFS_PA_PA_MaxRxPWMGear_MaxRxPWMGear_START (0)
#define SOC_UFS_PA_PA_MaxRxPWMGear_MaxRxPWMGear_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MaxRxHsGear : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_MaxRxHSGear_UNION;
#endif
#define SOC_UFS_PA_PA_MaxRxHSGear_MaxRxHsGear_START (0)
#define SOC_UFS_PA_PA_MaxRxHSGear_MaxRxHsGear_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PACPReqTimeout : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_UFS_PA_PA_PACPReqTimeout_UNION;
#endif
#define SOC_UFS_PA_PA_PACPReqTimeout_PA_PACPReqTimeout_START (0)
#define SOC_UFS_PA_PA_PACPReqTimeout_PA_PACPReqTimeout_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PACPReqEoBTimeout : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_PA_PACPReqEoBTimeout_UNION;
#endif
#define SOC_UFS_PA_PA_PACPReqEoBTimeout_PA_PACPReqEoBTimeout_START (0)
#define SOC_UFS_PA_PA_PACPReqEoBTimeout_PA_PACPReqEoBTimeout_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_RemoteVerInfo : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_RemoteVerInfo_UNION;
#endif
#define SOC_UFS_PA_PA_RemoteVerInfo_PA_RemoteVerInfo_START (0)
#define SOC_UFS_PA_PA_RemoteVerInfo_PA_RemoteVerInfo_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LogicalLaneMapTx : 8;
        unsigned int LogicalLaneMapRx : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_LogicalLaneMap_UNION;
#endif
#define SOC_UFS_PA_PA_LogicalLaneMap_LogicalLaneMapTx_START (0)
#define SOC_UFS_PA_PA_LogicalLaneMap_LogicalLaneMapTx_END (7)
#define SOC_UFS_PA_PA_LogicalLaneMap_LogicalLaneMapRx_START (8)
#define SOC_UFS_PA_PA_LogicalLaneMap_LogicalLaneMapRx_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SleepNoConfigTime : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_PA_SleepNoConfigTime_UNION;
#endif
#define SOC_UFS_PA_PA_SleepNoConfigTime_SleepNoConfigTime_START (0)
#define SOC_UFS_PA_PA_SleepNoConfigTime_SleepNoConfigTime_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int StallNoConfigTime : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_StallNoConfigTime_UNION;
#endif
#define SOC_UFS_PA_PA_StallNoConfigTime_StallNoConfigTime_START (0)
#define SOC_UFS_PA_PA_StallNoConfigTime_StallNoConfigTime_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SaveConfigTime : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_SaveConfigTime_UNION;
#endif
#define SOC_UFS_PA_PA_SaveConfigTime_SaveConfigTime_START (0)
#define SOC_UFS_PA_PA_SaveConfigTime_SaveConfigTime_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RxHSUnterminationCapability : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_RxHSUnterminationCapability_UNION;
#endif
#define SOC_UFS_PA_PA_RxHSUnterminationCapability_RxHSUnterminationCapability_START (0)
#define SOC_UFS_PA_PA_RxHSUnterminationCapability_RxHSUnterminationCapability_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RxLSTerminationCapability : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PA_RxLSTerminationCapability_UNION;
#endif
#define SOC_UFS_PA_PA_RxLSTerminationCapability_RxLSTerminationCapability_START (0)
#define SOC_UFS_PA_PA_RxLSTerminationCapability_RxLSTerminationCapability_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Hibern8Time : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_UFS_PA_PA_Hibern8Time_UNION;
#endif
#define SOC_UFS_PA_PA_Hibern8Time_Hibern8Time_START (0)
#define SOC_UFS_PA_PA_Hibern8Time_Hibern8Time_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TActivate : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_UFS_PA_PA_TActivate_UNION;
#endif
#define SOC_UFS_PA_PA_TActivate_TActivate_START (0)
#define SOC_UFS_PA_PA_TActivate_TActivate_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_LocalVerInfo : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_LocalVerInfo_UNION;
#endif
#define SOC_UFS_PA_PA_LocalVerInfo_PA_LocalVerInfo_START (0)
#define SOC_UFS_PA_PA_LocalVerInfo_PA_LocalVerInfo_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Granularity : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_PA_Granularity_UNION;
#endif
#define SOC_UFS_PA_PA_Granularity_Granularity_START (0)
#define SOC_UFS_PA_PA_Granularity_Granularity_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_MK2ExtensionGuardBand : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_UFS_PA_PA_MK2ExtensionGuardBand_UNION;
#endif
#define SOC_UFS_PA_PA_MK2ExtensionGuardBand_PA_MK2ExtensionGuardBand_START (0)
#define SOC_UFS_PA_PA_MK2ExtensionGuardBand_PA_MK2ExtensionGuardBand_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData0_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData0_PA_PWRModeUserData0_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData0_PA_PWRModeUserData0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData1_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData1_PA_PWRModeUserData1_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData1_PA_PWRModeUserData1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData2_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData2_PA_PWRModeUserData2_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData2_PA_PWRModeUserData2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData3 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData3_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData3_PA_PWRModeUserData3_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData3_PA_PWRModeUserData3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData4 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData4_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData4_PA_PWRModeUserData4_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData4_PA_PWRModeUserData4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData5 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData5_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData5_PA_PWRModeUserData5_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData5_PA_PWRModeUserData5_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData6 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData6_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData6_PA_PWRModeUserData6_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData6_PA_PWRModeUserData6_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData7 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData7_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData7_PA_PWRModeUserData7_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData7_PA_PWRModeUserData7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData8 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData8_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData8_PA_PWRModeUserData8_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData8_PA_PWRModeUserData8_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData9 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData9_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData9_PA_PWRModeUserData9_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData9_PA_PWRModeUserData9_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData10 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData10_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData10_PA_PWRModeUserData10_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData10_PA_PWRModeUserData10_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PWRModeUserData11 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_PWRModeUserData11_UNION;
#endif
#define SOC_UFS_PA_PA_PWRModeUserData11_PA_PWRModeUserData11_START (0)
#define SOC_UFS_PA_PA_PWRModeUserData11_PA_PWRModeUserData11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PACPFrameCount : 32;
    } reg;
} SOC_UFS_PA_PA_PACPFrameCount_UNION;
#endif
#define SOC_UFS_PA_PA_PACPFrameCount_PA_PACPFrameCount_START (0)
#define SOC_UFS_PA_PA_PACPFrameCount_PA_PACPFrameCount_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_PACPErrorCount : 32;
    } reg;
} SOC_UFS_PA_PA_PACPErrorCount_UNION;
#endif
#define SOC_UFS_PA_PA_PACPErrorCount_PA_PACPErrorCount_START (0)
#define SOC_UFS_PA_PA_PACPErrorCount_PA_PACPErrorCount_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TestContBurst : 1;
        unsigned int TestCfgReady : 1;
        unsigned int TestLineReset : 1;
        unsigned int TestPatternTransmit : 1;
        unsigned int TestPatternSelect : 1;
        unsigned int TestAdapt : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_UFS_PA_PA_PHYTestControl_UNION;
#endif
#define SOC_UFS_PA_PA_PHYTestControl_TestContBurst_START (0)
#define SOC_UFS_PA_PA_PHYTestControl_TestContBurst_END (0)
#define SOC_UFS_PA_PA_PHYTestControl_TestCfgReady_START (1)
#define SOC_UFS_PA_PA_PHYTestControl_TestCfgReady_END (1)
#define SOC_UFS_PA_PA_PHYTestControl_TestLineReset_START (2)
#define SOC_UFS_PA_PA_PHYTestControl_TestLineReset_END (2)
#define SOC_UFS_PA_PA_PHYTestControl_TestPatternTransmit_START (3)
#define SOC_UFS_PA_PA_PHYTestControl_TestPatternTransmit_END (3)
#define SOC_UFS_PA_PA_PHYTestControl_TestPatternSelect_START (4)
#define SOC_UFS_PA_PA_PHYTestControl_TestPatternSelect_END (4)
#define SOC_UFS_PA_PA_PHYTestControl_TestAdapt_START (5)
#define SOC_UFS_PA_PA_PHYTestControl_TestAdapt_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG4SyncLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_TxHsG4SyncLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG4SyncLength_TxHsG4SyncLength_START (0)
#define SOC_UFS_PA_PA_TxHsG4SyncLength_TxHsG4SyncLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsG4PrepareLength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_PA_TxHsG4PrepareLength_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsG4PrepareLength_TxHsG4PrepareLength_START (0)
#define SOC_UFS_PA_PA_TxHsG4PrepareLength_TxHsG4PrepareLength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerRxHsAdaptRefresh : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_PeerRxHsAdaptRefresh_UNION;
#endif
#define SOC_UFS_PA_PA_PeerRxHsAdaptRefresh_PeerRxHsAdaptRefresh_START (0)
#define SOC_UFS_PA_PA_PeerRxHsAdaptRefresh_PeerRxHsAdaptRefresh_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerRxHsAdaptInitial : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_PA_PeerRxHsAdaptInitial_UNION;
#endif
#define SOC_UFS_PA_PA_PeerRxHsAdaptInitial_PeerRxHsAdaptInitial_START (0)
#define SOC_UFS_PA_PA_PeerRxHsAdaptInitial_PeerRxHsAdaptInitial_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxHsAdaptType : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_PA_PA_TxHsAdaptType_UNION;
#endif
#define SOC_UFS_PA_PA_TxHsAdaptType_TxHsAdaptType_START (0)
#define SOC_UFS_PA_PA_TxHsAdaptType_TxHsAdaptType_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PA_AdaptAfterLRSTInPA_INIT : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_PA_PA_AdaptAfterLRSTInPA_INIT_UNION;
#endif
#define SOC_UFS_PA_PA_AdaptAfterLRSTInPA_INIT_PA_AdaptAfterLRSTInPA_INIT_START (0)
#define SOC_UFS_PA_PA_AdaptAfterLRSTInPA_INIT_PA_AdaptAfterLRSTInPA_INIT_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideEnable0 : 1;
        unsigned int OverrideEnable1 : 1;
        unsigned int OverrideEnable2 : 1;
        unsigned int OverrideEnable3 : 1;
        unsigned int OverrideEnable4 : 1;
        unsigned int OverrideEnable5 : 1;
        unsigned int OverrideEnable6 : 1;
        unsigned int OverrideEnable7 : 1;
        unsigned int OverrideEnable8 : 1;
        unsigned int OverrideEnable9 : 1;
        unsigned int OverrideEnable10 : 1;
        unsigned int OverrideEnable11 : 1;
        unsigned int OverrideEnable12 : 1;
        unsigned int OverrideEnable13 : 1;
        unsigned int OverrideEnable14 : 1;
        unsigned int OverrideEnable15 : 1;
        unsigned int OverrideEnable16 : 1;
        unsigned int OverrideEnable17 : 1;
        unsigned int OverrideEnable18 : 1;
        unsigned int OverrideEnable19 : 1;
        unsigned int OverrideEnable20 : 1;
        unsigned int OverrideEnable21 : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_UFS_PA_VS_OverrideAttrEnable_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable0_START (0)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable0_END (0)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable1_START (1)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable1_END (1)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable2_START (2)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable2_END (2)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable3_START (3)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable3_END (3)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable4_START (4)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable4_END (4)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable5_START (5)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable5_END (5)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable6_START (6)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable6_END (6)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable7_START (7)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable7_END (7)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable8_START (8)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable8_END (8)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable9_START (9)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable9_END (9)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable10_START (10)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable10_END (10)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable11_START (11)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable11_END (11)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable12_START (12)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable12_END (12)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable13_START (13)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable13_END (13)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable14_START (14)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable14_END (14)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable15_START (15)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable15_END (15)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable16_START (16)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable16_END (16)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable17_START (17)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable17_END (17)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable18_START (18)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable18_END (18)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable19_START (19)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable19_END (19)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable20_START (20)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable20_END (20)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable21_START (21)
#define SOC_UFS_PA_VS_OverrideAttrEnable_OverrideEnable21_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideAdvTact : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_VS_OverrideAdvTactivate_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideAdvTactivate_OverrideAdvTact_START (0)
#define SOC_UFS_PA_VS_OverrideAdvTactivate_OverrideAdvTact_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideAdvHiber8 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideAdvHiber8_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideAdvHiber8_OverrideAdvHiber8_START (0)
#define SOC_UFS_PA_VS_OverrideAdvHiber8_OverrideAdvHiber8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideAdvGran : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_VS_OverrideAdvGran_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideAdvGran_OverrideAdvGran_START (0)
#define SOC_UFS_PA_VS_OverrideAdvGran_OverrideAdvGran_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_afifo_close_dis : 1;
        unsigned int cfg_afifo_rst_dis : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_PA_VS_CFG_AFIFO_CTRL_UNION;
#endif
#define SOC_UFS_PA_VS_CFG_AFIFO_CTRL_cfg_afifo_close_dis_START (0)
#define SOC_UFS_PA_VS_CFG_AFIFO_CTRL_cfg_afifo_close_dis_END (0)
#define SOC_UFS_PA_VS_CFG_AFIFO_CTRL_cfg_afifo_rst_dis_START (1)
#define SOC_UFS_PA_VS_CFG_AFIFO_CTRL_cfg_afifo_rst_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverridePwmBurstClosure : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverridePwmBurstClosureLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverridePwmBurstClosureLength_OverridePwmBurstClosure_START (0)
#define SOC_UFS_PA_VS_OverridePwmBurstClosureLength_OverridePwmBurstClosure_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverridePwmSyncLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverridePwmSyncLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverridePwmSyncLength_OverridePwmSyncLength_START (0)
#define SOC_UFS_PA_VS_OverridePwmSyncLength_OverridePwmSyncLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverridePwmPrepareLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverridePwmPrepareLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverridePwmPrepareLength_OverridePwmPrepareLength_START (0)
#define SOC_UFS_PA_VS_OverridePwmPrepareLength_OverridePwmPrepareLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SaveConfigTimeIncrement : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_SaveConfigTimeIncrement_UNION;
#endif
#define SOC_UFS_PA_VS_SaveConfigTimeIncrement_SaveConfigTimeIncrement_START (0)
#define SOC_UFS_PA_VS_SaveConfigTimeIncrement_SaveConfigTimeIncrement_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG1SyncLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG1SyncLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG1SyncLength_OverrideRxHsG1SyncLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG1SyncLength_OverrideRxHsG1SyncLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG1PrepareLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG1PrepareLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG1PrepareLength_OverrideRxHsG1PrepareLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG1PrepareLength_OverrideRxHsG1PrepareLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG2SyncLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG2SyncLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG2SyncLength_OverrideRxHsG2SyncLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG2SyncLength_OverrideRxHsG2SyncLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG2PrepareLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG2PrepareLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG2PrepareLength_OverrideRxHsG2PrepareLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG2PrepareLength_OverrideRxHsG2PrepareLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG3SyncLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG3SyncLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG3SyncLength_OverrideRxHsG3SyncLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG3SyncLength_OverrideRxHsG3SyncLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG3PrepareLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG3PrepareLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG3PrepareLength_OverrideRxHsG3PrepareLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG3PrepareLength_OverrideRxHsG3PrepareLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_pmc_initial_linereset_flag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_PMC_INITIAL_LINERESET_FLAG_UNION;
#endif
#define SOC_UFS_PA_PMC_INITIAL_LINERESET_FLAG_cfg_pmc_initial_linereset_flag_START (0)
#define SOC_UFS_PA_PMC_INITIAL_LINERESET_FLAG_cfg_pmc_initial_linereset_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideTxHsUnterminatedLineDriveCap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_VS_OverrideTxHsUnterminatedLineDriveCapability_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideTxHsUnterminatedLineDriveCapability_OverrideTxHsUnterminatedLineDriveCap_START (0)
#define SOC_UFS_PA_VS_OverrideTxHsUnterminatedLineDriveCapability_OverrideTxHsUnterminatedLineDriveCap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideTxLsTerminatedLineDriveCap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_VS_OverrideTxLsTerminatedLineDriveCapability_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideTxLsTerminatedLineDriveCapability_OverrideTxLsTerminatedLineDriveCap_START (0)
#define SOC_UFS_PA_VS_OverrideTxLsTerminatedLineDriveCapability_OverrideTxLsTerminatedLineDriveCap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxMinSleepNoConfigTimeCap : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_VS_OverrideRxMinSleepNoConfigTimeCapability_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideRxMinSleepNoConfigTimeCapability_OverrideRxMinSleepNoConfigTimeCap_START (0)
#define SOC_UFS_PA_VS_OverrideRxMinSleepNoConfigTimeCapability_OverrideRxMinSleepNoConfigTimeCap_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxMinStallNoConfigTimeCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideRxMinStallNoConfigTimeCapability_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideRxMinStallNoConfigTimeCapability_OverrideRxMinStallNoConfigTimeCap_START (0)
#define SOC_UFS_PA_VS_OverrideRxMinStallNoConfigTimeCapability_OverrideRxMinStallNoConfigTimeCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxMinSaveConfigTimeCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideRxMinSaveConfigTimeCapability_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideRxMinSaveConfigTimeCapability_OverrideRxMinSaveConfigTimeCap_START (0)
#define SOC_UFS_PA_VS_OverrideRxMinSaveConfigTimeCapability_OverrideRxMinSaveConfigTimeCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DownValueOverrideEnable0 : 1;
        unsigned int DownValueOverrideEnable1 : 1;
        unsigned int DownValueOverrideEnable2 : 1;
        unsigned int DownValueOverrideEnable3 : 1;
        unsigned int DownValueOverrideEnable4 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_UFS_PA_VS_DowngradedValueOverrideEnable_UNION;
#endif
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable0_START (0)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable0_END (0)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable1_START (1)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable1_END (1)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable2_START (2)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable2_END (2)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable3_START (3)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable3_END (3)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable4_START (4)
#define SOC_UFS_PA_VS_DowngradedValueOverrideEnable_DownValueOverrideEnable4_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxSleepNoConfigTime : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_VS_OverrideTxMinSleepNoConfigTimeDowngraded_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideTxMinSleepNoConfigTimeDowngraded_TxSleepNoConfigTime_START (0)
#define SOC_UFS_PA_VS_OverrideTxMinSleepNoConfigTimeDowngraded_TxSleepNoConfigTime_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxStallNoConfigTime : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideTxMinStallNoConfigTimeDowngraded_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideTxMinStallNoConfigTimeDowngraded_TxStallNoConfigTime_START (0)
#define SOC_UFS_PA_VS_OverrideTxMinStallNoConfigTimeDowngraded_TxStallNoConfigTime_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxPwmG6G7SyncLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideTxPwmG6G7SyncLengthDowngraded_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideTxPwmG6G7SyncLengthDowngraded_TxPwmG6G7SyncLength_START (0)
#define SOC_UFS_PA_VS_OverrideTxPwmG6G7SyncLengthDowngraded_TxPwmG6G7SyncLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxLsPrepareLength : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideTxLsPrepareLengthDowngraded_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideTxLsPrepareLengthDowngraded_TxLsPrepareLength_START (0)
#define SOC_UFS_PA_VS_OverrideTxLsPrepareLengthDowngraded_TxLsPrepareLength_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxPwmBurstClosureExtn : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideTxPwmBurstClosureExtensionDowngraded_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideTxPwmBurstClosureExtensionDowngraded_TxPwmBurstClosureExtn_START (0)
#define SOC_UFS_PA_VS_OverrideTxPwmBurstClosureExtensionDowngraded_TxPwmBurstClosureExtn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MinRxTrailingClocks : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_AdjustTrailingClocks_UNION;
#endif
#define SOC_UFS_PA_VS_AdjustTrailingClocks_MinRxTrailingClocks_START (0)
#define SOC_UFS_PA_VS_AdjustTrailingClocks_MinRxTrailingClocks_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxBurstClosureDelay : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_TxBurstClosureDelay_UNION;
#endif
#define SOC_UFS_PA_VS_TxBurstClosureDelay_TxBurstClosureDelay_START (0)
#define SOC_UFS_PA_VS_TxBurstClosureDelay_TxBurstClosureDelay_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Mk2Extn_Support : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_VS_Mk2ExtnSupport_UNION;
#endif
#define SOC_UFS_PA_VS_Mk2ExtnSupport_Mk2Extn_Support_START (0)
#define SOC_UFS_PA_VS_Mk2ExtnSupport_Mk2Extn_Support_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_rx_hibernate_exit_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_CFG_RX_HIBERNATE_EXIT_DIS_UNION;
#endif
#define SOC_UFS_PA_CFG_RX_HIBERNATE_EXIT_DIS_cfg_rx_hibernate_exit_dis_START (0)
#define SOC_UFS_PA_CFG_RX_HIBERNATE_EXIT_DIS_cfg_rx_hibernate_exit_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DebugLoopBack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_VS_DebugLoopback_UNION;
#endif
#define SOC_UFS_PA_VS_DebugLoopback_DebugLoopBack_START (0)
#define SOC_UFS_PA_VS_DebugLoopback_DebugLoopBack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int local_rx_skip_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_LOCAL_RX_SKIP_REQUEST_UNION;
#endif
#define SOC_UFS_PA_LOCAL_RX_SKIP_REQUEST_local_rx_skip_req_START (0)
#define SOC_UFS_PA_LOCAL_RX_SKIP_REQUEST_local_rx_skip_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_rx_dbg_sel : 3;
        unsigned int cfg_rx_map_gate_dis : 1;
        unsigned int cfg_rx_lsu_wait_burstend_dis : 1;
        unsigned int cfg_rx_upr1_err_dis : 1;
        unsigned int cfg_rx_upr2_err_dis : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_UFS_PA_CFG_RX_CTRL_UNION;
#endif
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_dbg_sel_START (0)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_dbg_sel_END (2)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_map_gate_dis_START (3)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_map_gate_dis_END (3)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_lsu_wait_burstend_dis_START (4)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_lsu_wait_burstend_dis_END (4)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_upr1_err_dis_START (5)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_upr1_err_dis_END (5)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_upr2_err_dis_START (6)
#define SOC_UFS_PA_CFG_RX_CTRL_cfg_rx_upr2_err_dis_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BURST_END_TIMER_CFG : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_BURST_END_TIMER_CFG_UNION;
#endif
#define SOC_UFS_PA_BURST_END_TIMER_CFG_BURST_END_TIMER_CFG_START (0)
#define SOC_UFS_PA_BURST_END_TIMER_CFG_BURST_END_TIMER_CFG_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_FORCE_BURST_CLOSE : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_TX_BURST_CONTROL_UNION;
#endif
#define SOC_UFS_PA_TX_BURST_CONTROL_TX_FORCE_BURST_CLOSE_START (0)
#define SOC_UFS_PA_TX_BURST_CONTROL_TX_FORCE_BURST_CLOSE_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CFG_RX_CLK_SEL_MODE : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_PA_CFG_RX_CLK_SEL_MODE_UNION;
#endif
#define SOC_UFS_PA_CFG_RX_CLK_SEL_MODE_CFG_RX_CLK_SEL_MODE_START (0)
#define SOC_UFS_PA_CFG_RX_CLK_SEL_MODE_CFG_RX_CLK_SEL_MODE_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CFG_RX_SW_CLK_SEL : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_PA_CFG_RX_SW_CLK_SEL_UNION;
#endif
#define SOC_UFS_PA_CFG_RX_SW_CLK_SEL_CFG_RX_SW_CLK_SEL_START (0)
#define SOC_UFS_PA_CFG_RX_SW_CLK_SEL_CFG_RX_SW_CLK_SEL_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HSH8ENT_LR_MODE : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_HSH8ENT_LR_MODE_UNION;
#endif
#define SOC_UFS_PA_HSH8ENT_LR_MODE_HSH8ENT_LR_MODE_START (0)
#define SOC_UFS_PA_HSH8ENT_LR_MODE_HSH8ENT_LR_MODE_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CFG_DESKEW_CONTROL : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_PA_DESKEW_CONTROL_UNION;
#endif
#define SOC_UFS_PA_DESKEW_CONTROL_CFG_DESKEW_CONTROL_START (0)
#define SOC_UFS_PA_DESKEW_CONTROL_CFG_DESKEW_CONTROL_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_rx_err_inject_en : 1;
        unsigned int cfg_rx_err_inject_interval : 8;
        unsigned int cfg_rx_err_inject_cont : 3;
        unsigned int reserved_0 : 4;
        unsigned int cfg_tx_err_inject_en : 1;
        unsigned int cfg_tx_err_inject_interval : 8;
        unsigned int cfg_tx_err_inject_cont : 3;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_UFS_PA_CFG_ERROR_INJECT_UNION;
#endif
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_rx_err_inject_en_START (0)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_rx_err_inject_en_END (0)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_rx_err_inject_interval_START (1)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_rx_err_inject_interval_END (8)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_rx_err_inject_cont_START (9)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_rx_err_inject_cont_END (11)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_tx_err_inject_en_START (16)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_tx_err_inject_en_END (16)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_tx_err_inject_interval_START (17)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_tx_err_inject_interval_END (24)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_tx_err_inject_cont_START (25)
#define SOC_UFS_PA_CFG_ERROR_INJECT_cfg_tx_err_inject_cont_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_SAVECFG_UNIT : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_PA_TX_SAVECFG_UNIT_UNION;
#endif
#define SOC_UFS_PA_TX_SAVECFG_UNIT_TX_SAVECFG_UNIT_START (0)
#define SOC_UFS_PA_TX_SAVECFG_UNIT_TX_SAVECFG_UNIT_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CapabilityTxMaxPWM : 3;
        unsigned int CapabilityTxMaxHS : 3;
        unsigned int CapabilityTxTermPWMCap : 1;
        unsigned int CapabilityTxUntermHSCap : 1;
        unsigned int CapabilityRxHsEqualizerSetting : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_UFS_PA_PMC_CAP_ATTR_UNION;
#endif
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxMaxPWM_START (0)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxMaxPWM_END (2)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxMaxHS_START (3)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxMaxHS_END (5)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxTermPWMCap_START (6)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxTermPWMCap_END (6)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxUntermHSCap_START (7)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityTxUntermHSCap_END (7)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityRxHsEqualizerSetting_START (8)
#define SOC_UFS_PA_PMC_CAP_ATTR_CapabilityRxHsEqualizerSetting_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_auto_burst_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_tx_auto_burst_sel_UNION;
#endif
#define SOC_UFS_PA_tx_auto_burst_sel_tx_auto_burst_sel_START (0)
#define SOC_UFS_PA_tx_auto_burst_sel_tx_auto_burst_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LPMC_ALIGN_EN : 1;
        unsigned int RPMC_ALIGN_EN : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_PA_PMC_ALIGN_EN_UNION;
#endif
#define SOC_UFS_PA_PMC_ALIGN_EN_LPMC_ALIGN_EN_START (0)
#define SOC_UFS_PA_PMC_ALIGN_EN_LPMC_ALIGN_EN_END (0)
#define SOC_UFS_PA_PMC_ALIGN_EN_RPMC_ALIGN_EN_START (1)
#define SOC_UFS_PA_PMC_ALIGN_EN_RPMC_ALIGN_EN_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HSH8ENT_LR_FLAG : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_HSH8ENT_LR_UNION;
#endif
#define SOC_UFS_PA_HSH8ENT_LR_HSH8ENT_LR_FLAG_START (0)
#define SOC_UFS_PA_HSH8ENT_LR_HSH8ENT_LR_FLAG_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_tx_controlled_act_timer : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_TX_CTRL_ACT_TIMER_UNION;
#endif
#define SOC_UFS_PA_TX_CTRL_ACT_TIMER_cfg_tx_controlled_act_timer_START (0)
#define SOC_UFS_PA_TX_CTRL_ACT_TIMER_cfg_tx_controlled_act_timer_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_upr_send_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_CFG_UPR_SEND_MODE_UNION;
#endif
#define SOC_UFS_PA_CFG_UPR_SEND_MODE_cfg_upr_send_mode_START (0)
#define SOC_UFS_PA_CFG_UPR_SEND_MODE_cfg_upr_send_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG4SyncLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG4SyncLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG4SyncLength_OverrideRxHsG4SyncLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG4SyncLength_OverrideRxHsG4SyncLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsG4PrepareLengthCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHSG4PrepareLength_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHSG4PrepareLength_OverrideRxHsG4PrepareLengthCap_START (0)
#define SOC_UFS_PA_VS_OverrideHSG4PrepareLength_OverrideRxHsG4PrepareLengthCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsEqualizerSettingCap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_VS_OverrideHsEqualizerSetting_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHsEqualizerSetting_OverrideRxHsEqualizerSettingCap_START (0)
#define SOC_UFS_PA_VS_OverrideHsEqualizerSetting_OverrideRxHsEqualizerSettingCap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsAdaptRefreshCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHsAdaptRefresh_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHsAdaptRefresh_OverrideRxHsAdaptRefreshCap_START (0)
#define SOC_UFS_PA_VS_OverrideHsAdaptRefresh_OverrideRxHsAdaptRefreshCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OverrideRxHsAdaptInitialCap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_PA_VS_OverrideHsAdaptInitial_UNION;
#endif
#define SOC_UFS_PA_VS_OverrideHsAdaptInitial_OverrideRxHsAdaptInitialCap_START (0)
#define SOC_UFS_PA_VS_OverrideHsAdaptInitial_OverrideRxHsAdaptInitialCap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_rx_burst_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_PA_CFG_RX_BURST_SEL_UNION;
#endif
#define SOC_UFS_PA_CFG_RX_BURST_SEL_cfg_rx_burst_sel_START (0)
#define SOC_UFS_PA_CFG_RX_BURST_SEL_cfg_rx_burst_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_lpmc_sm_state : 8;
        unsigned int cfg_rpmc_sm_state : 5;
        unsigned int cfg_h8exit_state : 3;
        unsigned int cfg_lsu_sm_state : 5;
        unsigned int cfg_ctrl_state : 4;
        unsigned int reserved : 7;
    } reg;
} SOC_UFS_PA_FSM_Status_UNION;
#endif
#define SOC_UFS_PA_FSM_Status_cfg_lpmc_sm_state_START (0)
#define SOC_UFS_PA_FSM_Status_cfg_lpmc_sm_state_END (7)
#define SOC_UFS_PA_FSM_Status_cfg_rpmc_sm_state_START (8)
#define SOC_UFS_PA_FSM_Status_cfg_rpmc_sm_state_END (12)
#define SOC_UFS_PA_FSM_Status_cfg_h8exit_state_START (13)
#define SOC_UFS_PA_FSM_Status_cfg_h8exit_state_END (15)
#define SOC_UFS_PA_FSM_Status_cfg_lsu_sm_state_START (16)
#define SOC_UFS_PA_FSM_Status_cfg_lsu_sm_state_END (20)
#define SOC_UFS_PA_FSM_Status_cfg_ctrl_state_START (21)
#define SOC_UFS_PA_FSM_Status_cfg_ctrl_state_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_lpmc_status_rc : 8;
        unsigned int cfg_rpmc_status_rc : 3;
        unsigned int cfg_lsu_status_rc : 4;
        unsigned int pmc_unchange_flag_rc : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_PA_PA_Status_UNION;
#endif
#define SOC_UFS_PA_PA_Status_cfg_lpmc_status_rc_START (0)
#define SOC_UFS_PA_PA_Status_cfg_lpmc_status_rc_END (7)
#define SOC_UFS_PA_PA_Status_cfg_rpmc_status_rc_START (8)
#define SOC_UFS_PA_PA_Status_cfg_rpmc_status_rc_END (10)
#define SOC_UFS_PA_PA_Status_cfg_lsu_status_rc_START (11)
#define SOC_UFS_PA_PA_Status_cfg_lsu_status_rc_END (14)
#define SOC_UFS_PA_PA_Status_pmc_unchange_flag_rc_START (15)
#define SOC_UFS_PA_PA_Status_pmc_unchange_flag_rc_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_rx : 32;
    } reg;
} SOC_UFS_PA_DBG_CFG_RX_UNION;
#endif
#define SOC_UFS_PA_DBG_CFG_RX_dbg_cfg_rx_START (0)
#define SOC_UFS_PA_DBG_CFG_RX_dbg_cfg_rx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_tx_phy_cfg : 10;
        unsigned int dbg_cfg_tx_lr : 3;
        unsigned int dbg_cfg_tx_h8exit : 3;
        unsigned int dbg_cfg_tx_pacp : 9;
        unsigned int dbg_cfg_tx_dl_send : 2;
        unsigned int reserved : 5;
    } reg;
} SOC_UFS_PA_TX_CFG_DBG0_UNION;
#endif
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_phy_cfg_START (0)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_phy_cfg_END (9)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_lr_START (10)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_lr_END (12)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_h8exit_START (13)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_h8exit_END (15)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_pacp_START (16)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_pacp_END (24)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_dl_send_START (25)
#define SOC_UFS_PA_TX_CFG_DBG0_dbg_cfg_tx_dl_send_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_burst_state : 12;
        unsigned int dbg_cfg_txfifo_err : 2;
        unsigned int reserved : 18;
    } reg;
} SOC_UFS_PA_TX_CFG_DBG1_UNION;
#endif
#define SOC_UFS_PA_TX_CFG_DBG1_dbg_cfg_burst_state_START (0)
#define SOC_UFS_PA_TX_CFG_DBG1_dbg_cfg_burst_state_END (11)
#define SOC_UFS_PA_TX_CFG_DBG1_dbg_cfg_txfifo_err_START (12)
#define SOC_UFS_PA_TX_CFG_DBG1_dbg_cfg_txfifo_err_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DebugPwrChg : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_UFS_PA_DebugPwrChg_UNION;
#endif
#define SOC_UFS_PA_DebugPwrChg_DebugPwrChg_START (0)
#define SOC_UFS_PA_DebugPwrChg_DebugPwrChg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_tx_dl_send : 2;
        unsigned int reserved_0 : 14;
        unsigned int dbg_trace_tx_phy_cfg : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_UFS_PA_dbg_trace_01_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_01_dbg_trace_tx_dl_send_START (0)
#define SOC_UFS_PA_dbg_trace_01_dbg_trace_tx_dl_send_END (1)
#define SOC_UFS_PA_dbg_trace_01_dbg_trace_tx_phy_cfg_START (16)
#define SOC_UFS_PA_dbg_trace_01_dbg_trace_tx_phy_cfg_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_tx_lsu : 8;
        unsigned int reserved_0 : 8;
        unsigned int dbg_trace_tx_pacp : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_UFS_PA_dbg_trace_02_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_02_dbg_trace_tx_lsu_START (0)
#define SOC_UFS_PA_dbg_trace_02_dbg_trace_tx_lsu_END (7)
#define SOC_UFS_PA_dbg_trace_02_dbg_trace_tx_pacp_START (16)
#define SOC_UFS_PA_dbg_trace_02_dbg_trace_tx_pacp_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_tx_lr : 3;
        unsigned int reserved_0 : 5;
        unsigned int dbg_trace_tx_h8exit : 3;
        unsigned int reserved_1 : 5;
        unsigned int dbg_trace_rx : 6;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_UFS_PA_dbg_trace_03_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_03_dbg_trace_tx_lr_START (0)
#define SOC_UFS_PA_dbg_trace_03_dbg_trace_tx_lr_END (2)
#define SOC_UFS_PA_dbg_trace_03_dbg_trace_tx_h8exit_START (8)
#define SOC_UFS_PA_dbg_trace_03_dbg_trace_tx_h8exit_END (10)
#define SOC_UFS_PA_dbg_trace_03_dbg_trace_rx_START (16)
#define SOC_UFS_PA_dbg_trace_03_dbg_trace_rx_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_deskew0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_UFS_PA_dbg_trace_04_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_04_dbg_trace_deskew0_START (0)
#define SOC_UFS_PA_dbg_trace_04_dbg_trace_deskew0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_deskew1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_UFS_PA_dbg_trace_05_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_05_dbg_trace_deskew1_START (0)
#define SOC_UFS_PA_dbg_trace_05_dbg_trace_deskew1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_pa_cfg_ctrl0 : 32;
    } reg;
} SOC_UFS_PA_dbg_trace_06_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_06_dbg_trace_pa_cfg_ctrl0_START (0)
#define SOC_UFS_PA_dbg_trace_06_dbg_trace_pa_cfg_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_pa_cfg_ctrl1 : 32;
    } reg;
} SOC_UFS_PA_dbg_trace_07_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_07_dbg_trace_pa_cfg_ctrl1_START (0)
#define SOC_UFS_PA_dbg_trace_07_dbg_trace_pa_cfg_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_pa_cfg_ctrl2 : 32;
    } reg;
} SOC_UFS_PA_dbg_trace_08_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_08_dbg_trace_pa_cfg_ctrl2_START (0)
#define SOC_UFS_PA_dbg_trace_08_dbg_trace_pa_cfg_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_pa_cfg_ctrl3 : 32;
    } reg;
} SOC_UFS_PA_dbg_trace_09_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_09_dbg_trace_pa_cfg_ctrl3_START (0)
#define SOC_UFS_PA_dbg_trace_09_dbg_trace_pa_cfg_ctrl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_pacp1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_UFS_PA_dbg_trace_10_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_10_dbg_trace_pacp1_START (0)
#define SOC_UFS_PA_dbg_trace_10_dbg_trace_pacp1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_deskew2 : 9;
        unsigned int reserved_0 : 7;
        unsigned int dbg_trace_burst_state : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_UFS_PA_dbg_trace_11_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_11_dbg_trace_deskew2_START (0)
#define SOC_UFS_PA_dbg_trace_11_dbg_trace_deskew2_END (8)
#define SOC_UFS_PA_dbg_trace_11_dbg_trace_burst_state_START (16)
#define SOC_UFS_PA_dbg_trace_11_dbg_trace_burst_state_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_rx_lsu : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_UFS_PA_dbg_trace_12_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_12_dbg_trace_rx_lsu_START (0)
#define SOC_UFS_PA_dbg_trace_12_dbg_trace_rx_lsu_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_pacp0 : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_UFS_PA_dbg_trace_13_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_13_dbg_trace_pacp0_START (0)
#define SOC_UFS_PA_dbg_trace_13_dbg_trace_pacp0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_trace_align : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_UFS_PA_dbg_trace_14_UNION;
#endif
#define SOC_UFS_PA_dbg_trace_14_dbg_trace_align_START (0)
#define SOC_UFS_PA_dbg_trace_14_dbg_trace_align_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_rx_lsu : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_UFS_PA_dbg_cfg_rx_01_UNION;
#endif
#define SOC_UFS_PA_dbg_cfg_rx_01_dbg_cfg_rx_lsu_START (0)
#define SOC_UFS_PA_dbg_cfg_rx_01_dbg_cfg_rx_lsu_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_deskew0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_UFS_PA_dbg_cfg_rx_02_UNION;
#endif
#define SOC_UFS_PA_dbg_cfg_rx_02_dbg_cfg_deskew0_START (0)
#define SOC_UFS_PA_dbg_cfg_rx_02_dbg_cfg_deskew0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_deskew1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_UFS_PA_dbg_cfg_rx_03_UNION;
#endif
#define SOC_UFS_PA_dbg_cfg_rx_03_dbg_cfg_deskew1_START (0)
#define SOC_UFS_PA_dbg_cfg_rx_03_dbg_cfg_deskew1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_deskew2 : 6;
        unsigned int reserved_0 : 2;
        unsigned int dbg_cfg_clksel : 4;
        unsigned int reserved_1 : 4;
        unsigned int dbg_cfg_rx_top : 12;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_UFS_PA_dbg_cfg_rx_04_UNION;
#endif
#define SOC_UFS_PA_dbg_cfg_rx_04_dbg_cfg_deskew2_START (0)
#define SOC_UFS_PA_dbg_cfg_rx_04_dbg_cfg_deskew2_END (5)
#define SOC_UFS_PA_dbg_cfg_rx_04_dbg_cfg_clksel_START (8)
#define SOC_UFS_PA_dbg_cfg_rx_04_dbg_cfg_clksel_END (11)
#define SOC_UFS_PA_dbg_cfg_rx_04_dbg_cfg_rx_top_START (16)
#define SOC_UFS_PA_dbg_cfg_rx_04_dbg_cfg_rx_top_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_tpacpwait_timeout : 1;
        unsigned int savecfg_timeout : 1;
        unsigned int sys_mk2extguard_timeout : 1;
        unsigned int sys_burstend_timeout : 1;
        unsigned int thibernate_timeout : 1;
        unsigned int h8e_th8exit_timeout : 1;
        unsigned int pmc_tpacpadapt_timeout : 1;
        unsigned int pmc_tpacpeob_timeout : 1;
        unsigned int lpmc_tpacpwait_timeout : 1;
        unsigned int h8e_tactive_timeout : 1;
        unsigned int pmc_tactive_timeout : 1;
        unsigned int lr_tlinereset_timeout : 1;
        unsigned int lr_tactive_timeout : 1;
        unsigned int lsu_tlsu_timeout : 1;
        unsigned int lsu_tactive_timeout : 1;
        unsigned int tx_nocfg_timeout : 1;
        unsigned int tx_trailingclock_timeout : 1;
        unsigned int tx_skip_insert : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_UFS_PA_dbg_pa_tx_timer_UNION;
#endif
#define SOC_UFS_PA_dbg_pa_tx_timer_cfg_tpacpwait_timeout_START (0)
#define SOC_UFS_PA_dbg_pa_tx_timer_cfg_tpacpwait_timeout_END (0)
#define SOC_UFS_PA_dbg_pa_tx_timer_savecfg_timeout_START (1)
#define SOC_UFS_PA_dbg_pa_tx_timer_savecfg_timeout_END (1)
#define SOC_UFS_PA_dbg_pa_tx_timer_sys_mk2extguard_timeout_START (2)
#define SOC_UFS_PA_dbg_pa_tx_timer_sys_mk2extguard_timeout_END (2)
#define SOC_UFS_PA_dbg_pa_tx_timer_sys_burstend_timeout_START (3)
#define SOC_UFS_PA_dbg_pa_tx_timer_sys_burstend_timeout_END (3)
#define SOC_UFS_PA_dbg_pa_tx_timer_thibernate_timeout_START (4)
#define SOC_UFS_PA_dbg_pa_tx_timer_thibernate_timeout_END (4)
#define SOC_UFS_PA_dbg_pa_tx_timer_h8e_th8exit_timeout_START (5)
#define SOC_UFS_PA_dbg_pa_tx_timer_h8e_th8exit_timeout_END (5)
#define SOC_UFS_PA_dbg_pa_tx_timer_pmc_tpacpadapt_timeout_START (6)
#define SOC_UFS_PA_dbg_pa_tx_timer_pmc_tpacpadapt_timeout_END (6)
#define SOC_UFS_PA_dbg_pa_tx_timer_pmc_tpacpeob_timeout_START (7)
#define SOC_UFS_PA_dbg_pa_tx_timer_pmc_tpacpeob_timeout_END (7)
#define SOC_UFS_PA_dbg_pa_tx_timer_lpmc_tpacpwait_timeout_START (8)
#define SOC_UFS_PA_dbg_pa_tx_timer_lpmc_tpacpwait_timeout_END (8)
#define SOC_UFS_PA_dbg_pa_tx_timer_h8e_tactive_timeout_START (9)
#define SOC_UFS_PA_dbg_pa_tx_timer_h8e_tactive_timeout_END (9)
#define SOC_UFS_PA_dbg_pa_tx_timer_pmc_tactive_timeout_START (10)
#define SOC_UFS_PA_dbg_pa_tx_timer_pmc_tactive_timeout_END (10)
#define SOC_UFS_PA_dbg_pa_tx_timer_lr_tlinereset_timeout_START (11)
#define SOC_UFS_PA_dbg_pa_tx_timer_lr_tlinereset_timeout_END (11)
#define SOC_UFS_PA_dbg_pa_tx_timer_lr_tactive_timeout_START (12)
#define SOC_UFS_PA_dbg_pa_tx_timer_lr_tactive_timeout_END (12)
#define SOC_UFS_PA_dbg_pa_tx_timer_lsu_tlsu_timeout_START (13)
#define SOC_UFS_PA_dbg_pa_tx_timer_lsu_tlsu_timeout_END (13)
#define SOC_UFS_PA_dbg_pa_tx_timer_lsu_tactive_timeout_START (14)
#define SOC_UFS_PA_dbg_pa_tx_timer_lsu_tactive_timeout_END (14)
#define SOC_UFS_PA_dbg_pa_tx_timer_tx_nocfg_timeout_START (15)
#define SOC_UFS_PA_dbg_pa_tx_timer_tx_nocfg_timeout_END (15)
#define SOC_UFS_PA_dbg_pa_tx_timer_tx_trailingclock_timeout_START (16)
#define SOC_UFS_PA_dbg_pa_tx_timer_tx_trailingclock_timeout_END (16)
#define SOC_UFS_PA_dbg_pa_tx_timer_tx_skip_insert_START (17)
#define SOC_UFS_PA_dbg_pa_tx_timer_tx_skip_insert_END (17)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
