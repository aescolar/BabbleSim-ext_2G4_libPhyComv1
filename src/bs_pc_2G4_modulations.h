/*
 * Copyright 2018 Oticon A/S
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef BS_P2G4_MODULATIONS_H
#define BS_P2G4_MODULATIONS_H

#ifdef __cplusplus
extern "C"{
#endif

#define P2G4_MOD_SIMILAR_MASK 0xFFF0
/*
 * If two modulations are the same after masking with P2G4_MOD_SIMILAR_MASK
 * it means they are compatible (one can be received with the modem configured
 * for the other) although probably with limited performance.
 *
 * Note: All modems for this phy would need to understand these modulations
 * to be able to, at least, account for their interference.
 * To ease this process, a modem model may treat several modulations equally
 * if they share the P2G4_MOD_SIMILAR_MASK bits.
 * In this manner a modem model can tell that an otherwise unknown modulation
 * is close to another known one and just treat it as if it were the same
 */

#define P2G4_MOD_BLE             0x10 //Standard 1Mbps BLE modulation
#define P2G4_MOD_BLE2M           0x20 //Standard 2Mbps BLE
#define P2G4_MOD_PROP2M          0x21 //Proprietary 2Mbps
#define P2G4_MOD_PROP3M          0x31 //Proprietary 3Mbps
#define P2G4_MOD_PROP4M          0x41 //Proprietary 4Mbps
#define P2G4_MOD_BLE_CODED       0x50 //Standard BLE CodedPhy (both S=2 & S=8)
/* BLE HDT modulations (Note all have the same BW and spectral shape) */
#define P2G4_MOD_BLE_HDT         0x60 //BLE HDT
#define P2G4_MOD_BLE_HDT_QPSK    0x60 //BLE HDT - QPSK modulation
#define P2G4_MOD_BLE_HDT_8PSK    0x61 //BLE HDT - 8PSK modulation
#define P2G4_MOD_BLE_HDT_16QAM   0x62 //BLE HDT - 16QAM modulation

#define P2G4_MOD_154_250K_DSS   0x100 //IEEE 802.15.4-2006 DSS 250kbps O-QPSK PHY

/* Non receivable modulations (interferers) */
#define P2G4_MOD_BLEINTER        0x8000  //BLE shaped interference
#define P2G4_MOD_WLANINTER       0x8010  //WLAN shaped interference (for all WLAN modulations)
#define P2G4_MOD_CWINTER         0x8020  //CW interference
/* Non receivable white noise of a given bandwidth: */
#define P2G4_MOD_WHITENOISE1MHz  0x8030
#define P2G4_MOD_WHITENOISE2MHz  0x8040
#define P2G4_MOD_WHITENOISE4MHz  0x8050
#define P2G4_MOD_WHITENOISE8MHz  0x8060
#define P2G4_MOD_WHITENOISE16MHz 0x8070
#define P2G4_MOD_WHITENOISE20MHz 0x8080
#define P2G4_MOD_WHITENOISE40MHz 0x8090
#define P2G4_MOD_WHITENOISE80MHz 0x80A0


/* BLE Coded Phy coding rates */
#define P2G4_CODRATE_BLE_S2 2
#define P2G4_CODRATE_BLE_S8 8

/* BLE HDT coding rates (for format 0; and format 1 data) */
#define P2G4_CODRATE_BLE_HDT2   2
#define P2G4_CODRATE_BLE_HDT3   3
#define P2G4_CODRATE_BLE_HDT4   4
#define P2G4_CODRATE_BLE_HDT6   6
#define P2G4_CODRATE_BLE_HDT7_5 8

/* HDT format *1* header coding */
#define P2G4_CODRATE_BLE_HEADHDT2   2 /* Same coding as HDT2 */
#define P2G4_CODRATE_BLE_HEADHDT3   2 /* Same coding as HDT2 */
#define P2G4_CODRATE_BLE_HEADHDT4   5 /* Different coding than anything else */
#define P2G4_CODRATE_BLE_HEADHDT6   7 /* Different coding than data */
#define P2G4_CODRATE_BLE_HEADHDT7_5 7 /* Different coding than data but same as HEADHDT6 */

#ifdef __cplusplus
}
#endif

#endif
