/*
 * Copyright (C) Jan 2013 Mellanox Technologies Ltd. All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ICMD_LAYOUTS_H
#define ICMD_LAYOUTS_H


#ifdef __cplusplus
extern "C" {
#endif

#include "adb_to_c_utils.h"
/* Description -   */
/* Size in bytes - 16 */
struct connectib_FW_VERSION {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
    /* Description -  */
    /* 0x0.16 - 0x0.31 */
     u_int16_t MAJOR;
/*---------------- DWORD[1] (Offset 0x4) ----------------*/
    /* Description -  */
    /* 0x4.0 - 0x4.15 */
     u_int16_t SUBMINOR;
    /* Description -  */
    /* 0x4.16 - 0x4.31 */
     u_int16_t MINOR;
/*---------------- DWORD[2] (Offset 0x8) ----------------*/
    /* Description -  */
    /* 0x8.8 - 0x8.15 */
     u_int8_t Hour;
    /* Description -  */
    /* 0x8.16 - 0x8.23 */
     u_int8_t Minutes;
    /* Description -  */
    /* 0x8.24 - 0x8.31 */
     u_int8_t Seconds;
/*---------------- DWORD[3] (Offset 0xc) ----------------*/
    /* Description -  */
    /* 0xc.0 - 0xc.7 */
     u_int8_t Day;
    /* Description -  */
    /* 0xc.8 - 0xc.15 */
     u_int8_t Month;
    /* Description -  */
    /* 0xc.16 - 0xc.31 */
     u_int16_t Year;
};


/* Description -   */
/* Size in bytes - 36 */
struct connectib_icmd_get_fw_info {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
    /* Description -  */
    /* 0x0.0 - 0x10.31 */
     struct connectib_FW_VERSION fw_version;
/*---------------- DWORD[4] (Offset 0x10) ----------------*/
    /* Description - Hash gen file signature */
    /* 0x10.0 - 0x10.15 */
     u_int16_t hash_signature;
/*---------------- DWORD[5] (Offset 0x14) ----------------*/
    /* Description -  */
    /* 0x14.24 - 0x24.23 */
     char psid[17];
};


/* Description -   */
/* Size in bytes - 16 */
struct connectx4_icmd_mh_sync {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
    /* Description - input mailbox: state of sync: IDLE, GET_READY, GO */
    /* 0x0.0 - 0x0.3 */
     u_int8_t input_state;
    /* Description - input mailbox: sync_type - 0x01 = FW_RESET */
    /* 0x0.8 - 0x0.15 */
     u_int8_t input_sync_type;
    /* Description - input mailbox: when set - ignore inactive hosts */
    /* 0x0.31 - 0x0.31 */
     u_int8_t input_ignore_inactive_hosts;
/*---------------- DWORD[1] (Offset 0x4) ----------------*/
    /* Description - output mailbox: state of sync: IDLE, GET_READY, GO */
    /* 0x4.0 - 0x4.3 */
     u_int8_t fsm_state;
    /* Description - output mailbox: sync_type - 0x01 = FW_RESET */
    /* 0x4.8 - 0x4.15 */
     u_int8_t fsm_sync_type;
    /* Description - output mailbox: when set - ignore inactive hosts */
    /* 0x4.31 - 0x4.31 */
     u_int8_t fsm_ignore_inactive_hosts;
/*---------------- DWORD[2] (Offset 0x8) ----------------*/
    /* Description - output mailbox: bit per host - indicates hosts already issued GET_READY */
    /* 0x8.0 - 0x8.3 */
     u_int8_t fsm_host_ready;
/*---------------- DWORD[3] (Offset 0xc) ----------------*/
    /* Description - output mailbox: NIC uptime since last reset in microsecondes at the moment of first GET_READY */
    /* 0xc.0 - 0x10.31 */
     u_int32_t fsm_start_uptime;
};


/* Description -   */
/* Size in bytes - 8 */
struct connectx4_icmd_query_cap_general {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
    /* Description - When set, device supports FW components updated through ICMD interface.
See
"Firmware Components Update" on page 428
 */
    /* 0x0.26 - 0x0.26 */
     u_int8_t fw_ctrl_update_icmd;
    /* Description - When set, the
"
ICMD_KDNET_CTRL - Control KDNET PF
"
 com
mand is supported. */
    /* 0x0.27 - 0x0.27 */
     u_int8_t kdnet_ctrl;
    /* Description - When set, multi-host synchronization through the device is supported.
 See
Section 25.4.3, "
ICMD_MH_SYNC - Multi-Host Synchronization
," on
page 772
. */
    /* 0x0.28 - 0x0.28 */
     u_int8_t mh_sync;
    /* Description - If set, ICMD_ACCESS_REGISTER supports every register. (in the past it sup
ported some of them). */
    /* 0x0.29 - 0x0.29 */
     u_int8_t allow_icmd_access_reg_on_all_registers;
    /* Description - When set, ICMD_QUERY_FW_INFO returns the
psid
 field. */
    /* 0x0.30 - 0x0.30 */
     u_int8_t fw_info_psid;
    /* Description - When set, ICMD_ACCESS_REGISTER supports the following registers:
NVDA
NVDI
NVIA
NVQC */
    /* 0x0.31 - 0x0.31 */
     u_int8_t nv_access;
/*---------------- DWORD[1] (Offset 0x4) ----------------*/
    /* Description - If set, wake on phy activity is supported. */
    /* 0x4.0 - 0x4.0 */
     u_int8_t wol_p;
    /* Description - If set, wake on unicast packet is supported. */
    /* 0x4.1 - 0x4.1 */
     u_int8_t wol_u;
    /* Description - If set, wake on multicast packet is supported. */
    /* 0x4.2 - 0x4.2 */
     u_int8_t wol_m;
    /* Description - If set, wake on broadcast packet is supported. */
    /* 0x4.3 - 0x4.3 */
     u_int8_t wol_b;
    /* Description - If set, wake on ARP is supported. */
    /* 0x4.4 - 0x4.4 */
     u_int8_t wol_a;
    /* Description - If set, wake on magic packet is supported. */
    /* 0x4.5 - 0x4.5 */
     u_int8_t wol_g;
    /* Description - If set, wake on secured magic packet is supported. */
    /* 0x4.6 - 0x4.6 */
     u_int8_t wol_s;
    /* Description - If set, reset on magic packet is supported. */
    /* 0x4.8 - 0x4.8 */
     u_int8_t rol_g;
    /* Description - If set, reset on secured magic packet is supp
o
rted. */
    /* 0x4.9 - 0x4.9 */
     u_int8_t rol_s;
    /* Description - If set, FPGA device is supported by the device. See TBD */
    /* 0x4.10 - 0x4.10 */
     u_int8_t fpga;
};

/* FW_VERSION */
void connectib_FW_VERSION_pack(const struct connectib_FW_VERSION *ptr_struct, u_int8_t* ptr_buff);
void connectib_FW_VERSION_unpack(struct connectib_FW_VERSION *ptr_struct, const u_int8_t* ptr_buff);
void connectib_FW_VERSION_print(const struct connectib_FW_VERSION *ptr_struct, FILE* file, int indent_level);
int connectib_FW_VERSION_size(void);
#define CONNECTIB_FW_VERSION_SIZE    (0x10)
void connectib_FW_VERSION_dump(const struct connectib_FW_VERSION *ptr_struct, FILE* file);
/* icmd_get_fw_info */
void connectib_icmd_get_fw_info_pack(const struct connectib_icmd_get_fw_info *ptr_struct, u_int8_t* ptr_buff);
void connectib_icmd_get_fw_info_unpack(struct connectib_icmd_get_fw_info *ptr_struct, const u_int8_t* ptr_buff);
void connectib_icmd_get_fw_info_print(const struct connectib_icmd_get_fw_info *ptr_struct, FILE* file, int indent_level);
int connectib_icmd_get_fw_info_size(void);
#define CONNECTIB_ICMD_GET_FW_INFO_SIZE    (0x24)
void connectib_icmd_get_fw_info_dump(const struct connectib_icmd_get_fw_info *ptr_struct, FILE* file);
/* icmd_mh_sync */
void connectx4_icmd_mh_sync_pack(const struct connectx4_icmd_mh_sync *ptr_struct, u_int8_t* ptr_buff);
void connectx4_icmd_mh_sync_unpack(struct connectx4_icmd_mh_sync *ptr_struct, const u_int8_t* ptr_buff);
void connectx4_icmd_mh_sync_print(const struct connectx4_icmd_mh_sync *ptr_struct, FILE* file, int indent_level);
int connectx4_icmd_mh_sync_size(void);
#define CONNECTX4_ICMD_MH_SYNC_SIZE    (0x10)
void connectx4_icmd_mh_sync_dump(const struct connectx4_icmd_mh_sync *ptr_struct, FILE* file);
/* icmd_query_cap_general */
void connectx4_icmd_query_cap_general_pack(const struct connectx4_icmd_query_cap_general *ptr_struct, u_int8_t* ptr_buff);
void connectx4_icmd_query_cap_general_unpack(struct connectx4_icmd_query_cap_general *ptr_struct, const u_int8_t* ptr_buff);
void connectx4_icmd_query_cap_general_print(const struct connectx4_icmd_query_cap_general *ptr_struct, FILE* file, int indent_level);
int connectx4_icmd_query_cap_general_size(void);
#define CONNECTX4_ICMD_QUERY_CAP_GENERAL_SIZE    (0x8)
void connectx4_icmd_query_cap_general_dump(const struct connectx4_icmd_query_cap_general *ptr_struct, FILE* file);


#ifdef __cplusplus
}
#endif
#endif
