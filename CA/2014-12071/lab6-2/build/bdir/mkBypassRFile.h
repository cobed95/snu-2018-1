/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Mon May 28 15:24:46 KST 2018
 * 
 */

/* Generation options: */
#ifndef __mkBypassRFile_h__
#define __mkBypassRFile_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkBypassRFile module */
class MOD_mkBypassRFile : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt8> INST_rFile_0_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_0_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_0_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_0_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_0_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_0_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_0_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_0_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_0_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_0_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_0_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_0_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_0_lat_0;
  MOD_Wire<tUInt64> INST_rFile_0_lat_1;
  MOD_Wire<tUInt64> INST_rFile_0_lat_2;
  MOD_Reg<tUInt64> INST_rFile_0_rl;
  MOD_Reg<tUInt8> INST_rFile_10_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_10_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_10_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_10_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_10_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_10_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_10_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_10_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_10_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_10_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_10_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_10_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_10_lat_0;
  MOD_Wire<tUInt64> INST_rFile_10_lat_1;
  MOD_Wire<tUInt64> INST_rFile_10_lat_2;
  MOD_Reg<tUInt64> INST_rFile_10_rl;
  MOD_Reg<tUInt8> INST_rFile_11_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_11_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_11_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_11_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_11_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_11_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_11_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_11_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_11_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_11_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_11_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_11_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_11_lat_0;
  MOD_Wire<tUInt64> INST_rFile_11_lat_1;
  MOD_Wire<tUInt64> INST_rFile_11_lat_2;
  MOD_Reg<tUInt64> INST_rFile_11_rl;
  MOD_Reg<tUInt8> INST_rFile_12_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_12_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_12_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_12_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_12_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_12_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_12_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_12_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_12_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_12_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_12_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_12_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_12_lat_0;
  MOD_Wire<tUInt64> INST_rFile_12_lat_1;
  MOD_Wire<tUInt64> INST_rFile_12_lat_2;
  MOD_Reg<tUInt64> INST_rFile_12_rl;
  MOD_Reg<tUInt8> INST_rFile_13_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_13_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_13_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_13_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_13_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_13_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_13_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_13_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_13_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_13_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_13_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_13_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_13_lat_0;
  MOD_Wire<tUInt64> INST_rFile_13_lat_1;
  MOD_Wire<tUInt64> INST_rFile_13_lat_2;
  MOD_Reg<tUInt64> INST_rFile_13_rl;
  MOD_Reg<tUInt8> INST_rFile_14_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_14_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_14_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_14_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_14_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_14_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_14_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_14_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_14_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_14_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_14_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_14_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_14_lat_0;
  MOD_Wire<tUInt64> INST_rFile_14_lat_1;
  MOD_Wire<tUInt64> INST_rFile_14_lat_2;
  MOD_Reg<tUInt64> INST_rFile_14_rl;
  MOD_Reg<tUInt8> INST_rFile_1_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_1_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_1_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_1_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_1_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_1_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_1_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_1_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_1_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_1_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_1_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_1_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_1_lat_0;
  MOD_Wire<tUInt64> INST_rFile_1_lat_1;
  MOD_Wire<tUInt64> INST_rFile_1_lat_2;
  MOD_Reg<tUInt64> INST_rFile_1_rl;
  MOD_Reg<tUInt8> INST_rFile_2_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_2_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_2_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_2_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_2_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_2_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_2_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_2_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_2_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_2_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_2_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_2_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_2_lat_0;
  MOD_Wire<tUInt64> INST_rFile_2_lat_1;
  MOD_Wire<tUInt64> INST_rFile_2_lat_2;
  MOD_Reg<tUInt64> INST_rFile_2_rl;
  MOD_Reg<tUInt8> INST_rFile_3_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_3_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_3_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_3_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_3_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_3_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_3_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_3_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_3_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_3_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_3_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_3_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_3_lat_0;
  MOD_Wire<tUInt64> INST_rFile_3_lat_1;
  MOD_Wire<tUInt64> INST_rFile_3_lat_2;
  MOD_Reg<tUInt64> INST_rFile_3_rl;
  MOD_Reg<tUInt8> INST_rFile_4_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_4_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_4_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_4_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_4_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_4_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_4_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_4_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_4_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_4_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_4_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_4_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_4_lat_0;
  MOD_Wire<tUInt64> INST_rFile_4_lat_1;
  MOD_Wire<tUInt64> INST_rFile_4_lat_2;
  MOD_Reg<tUInt64> INST_rFile_4_rl;
  MOD_Reg<tUInt8> INST_rFile_5_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_5_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_5_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_5_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_5_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_5_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_5_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_5_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_5_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_5_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_5_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_5_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_5_lat_0;
  MOD_Wire<tUInt64> INST_rFile_5_lat_1;
  MOD_Wire<tUInt64> INST_rFile_5_lat_2;
  MOD_Reg<tUInt64> INST_rFile_5_rl;
  MOD_Reg<tUInt8> INST_rFile_6_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_6_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_6_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_6_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_6_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_6_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_6_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_6_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_6_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_6_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_6_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_6_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_6_lat_0;
  MOD_Wire<tUInt64> INST_rFile_6_lat_1;
  MOD_Wire<tUInt64> INST_rFile_6_lat_2;
  MOD_Reg<tUInt64> INST_rFile_6_rl;
  MOD_Reg<tUInt8> INST_rFile_7_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_7_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_7_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_7_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_7_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_7_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_7_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_7_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_7_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_7_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_7_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_7_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_7_lat_0;
  MOD_Wire<tUInt64> INST_rFile_7_lat_1;
  MOD_Wire<tUInt64> INST_rFile_7_lat_2;
  MOD_Reg<tUInt64> INST_rFile_7_rl;
  MOD_Reg<tUInt8> INST_rFile_8_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_8_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_8_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_8_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_8_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_8_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_8_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_8_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_8_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_8_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_8_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_8_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_8_lat_0;
  MOD_Wire<tUInt64> INST_rFile_8_lat_1;
  MOD_Wire<tUInt64> INST_rFile_8_lat_2;
  MOD_Reg<tUInt64> INST_rFile_8_rl;
  MOD_Reg<tUInt8> INST_rFile_9_dummy2_0;
  MOD_Reg<tUInt8> INST_rFile_9_dummy2_1;
  MOD_Reg<tUInt8> INST_rFile_9_dummy2_2;
  MOD_Wire<tUWide> INST_rFile_9_dummy_0_0;
  MOD_Wire<tUWide> INST_rFile_9_dummy_0_1;
  MOD_Wire<tUWide> INST_rFile_9_dummy_0_2;
  MOD_Wire<tUWide> INST_rFile_9_dummy_1_0;
  MOD_Wire<tUWide> INST_rFile_9_dummy_1_1;
  MOD_Wire<tUWide> INST_rFile_9_dummy_1_2;
  MOD_Wire<tUWide> INST_rFile_9_dummy_2_0;
  MOD_Wire<tUWide> INST_rFile_9_dummy_2_1;
  MOD_Wire<tUWide> INST_rFile_9_dummy_2_2;
  MOD_Wire<tUInt64> INST_rFile_9_lat_0;
  MOD_Wire<tUInt64> INST_rFile_9_lat_1;
  MOD_Wire<tUInt64> INST_rFile_9_lat_2;
  MOD_Reg<tUInt64> INST_rFile_9_rl;
 
 /* Constructor */
 public:
  MOD_mkBypassRFile(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
 
 /* Local definitions */
 private:
  tUInt64 DEF_upd__h34596;
  tUInt64 DEF_upd__h34665;
  tUInt64 DEF_upd__h34698;
  tUInt64 DEF_upd__h34473;
  tUInt64 DEF_upd__h34542;
  tUInt64 DEF_upd__h34575;
  tUInt64 DEF_upd__h34350;
  tUInt64 DEF_upd__h34419;
  tUInt64 DEF_upd__h34452;
  tUInt64 DEF_upd__h34227;
  tUInt64 DEF_upd__h34296;
  tUInt64 DEF_upd__h34329;
  tUInt64 DEF_upd__h34104;
  tUInt64 DEF_upd__h34173;
  tUInt64 DEF_upd__h34206;
  tUInt64 DEF_upd__h33981;
  tUInt64 DEF_upd__h34050;
  tUInt64 DEF_upd__h34083;
  tUInt64 DEF_upd__h33858;
  tUInt64 DEF_upd__h33927;
  tUInt64 DEF_upd__h33960;
  tUInt64 DEF_upd__h33735;
  tUInt64 DEF_upd__h33804;
  tUInt64 DEF_upd__h33837;
  tUInt64 DEF_upd__h33612;
  tUInt64 DEF_upd__h33681;
  tUInt64 DEF_upd__h33714;
  tUInt64 DEF_upd__h33489;
  tUInt64 DEF_upd__h33558;
  tUInt64 DEF_upd__h33591;
  tUInt64 DEF_upd__h33366;
  tUInt64 DEF_upd__h33435;
  tUInt64 DEF_upd__h33468;
  tUInt64 DEF_upd__h33243;
  tUInt64 DEF_upd__h33312;
  tUInt64 DEF_upd__h33345;
  tUInt64 DEF_upd__h33120;
  tUInt64 DEF_upd__h33189;
  tUInt64 DEF_upd__h33222;
  tUInt64 DEF_upd__h32997;
  tUInt64 DEF_upd__h33066;
  tUInt64 DEF_upd__h33099;
  tUInt64 DEF_upd__h32874;
  tUInt64 DEF_upd__h32943;
  tUInt64 DEF_upd__h32976;
  tUInt8 DEF_rFile_14_dummy2_2__h34626;
  tUInt8 DEF_rFile_14_lat_0_whas____d145;
  tUInt8 DEF_rFile_13_dummy2_2__h34503;
  tUInt8 DEF_rFile_13_lat_0_whas____d135;
  tUInt8 DEF_rFile_12_dummy2_2__h34380;
  tUInt8 DEF_rFile_12_lat_0_whas____d125;
  tUInt8 DEF_rFile_11_dummy2_2__h34257;
  tUInt8 DEF_rFile_11_lat_0_whas____d115;
  tUInt8 DEF_rFile_10_dummy2_2__h34134;
  tUInt8 DEF_rFile_10_lat_0_whas____d105;
  tUInt8 DEF_rFile_9_dummy2_2__h34011;
  tUInt8 DEF_rFile_9_lat_0_whas____d95;
  tUInt8 DEF_rFile_8_dummy2_2__h33888;
  tUInt8 DEF_rFile_8_lat_0_whas____d85;
  tUInt8 DEF_rFile_7_dummy2_2__h33765;
  tUInt8 DEF_rFile_7_lat_0_whas____d75;
  tUInt8 DEF_rFile_6_dummy2_2__h33642;
  tUInt8 DEF_rFile_6_lat_0_whas____d65;
  tUInt8 DEF_rFile_5_dummy2_2__h33519;
  tUInt8 DEF_rFile_5_lat_0_whas____d55;
  tUInt8 DEF_rFile_4_dummy2_2__h33396;
  tUInt8 DEF_rFile_4_lat_0_whas____d45;
  tUInt8 DEF_rFile_3_dummy2_2__h33273;
  tUInt8 DEF_rFile_3_lat_0_whas____d35;
  tUInt8 DEF_rFile_2_dummy2_2__h33150;
  tUInt8 DEF_rFile_2_lat_0_whas____d25;
  tUInt8 DEF_rFile_1_dummy2_2__h33027;
  tUInt8 DEF_rFile_1_lat_0_whas____d15;
  tUInt8 DEF_rFile_0_dummy2_2__h32904;
  tUInt8 DEF_rFile_0_lat_0_whas____d5;
  tUInt64 DEF_n__read__h32872;
  tUInt64 DEF_IF_rFile_14_lat_1_whas__43_THEN_rFile_14_lat_1_ETC___d149;
  tUInt64 DEF_n__read__h32870;
  tUInt64 DEF_IF_rFile_13_lat_1_whas__33_THEN_rFile_13_lat_1_ETC___d139;
  tUInt64 DEF_n__read__h32868;
  tUInt64 DEF_IF_rFile_12_lat_1_whas__23_THEN_rFile_12_lat_1_ETC___d129;
  tUInt64 DEF_n__read__h32866;
  tUInt64 DEF_IF_rFile_11_lat_1_whas__13_THEN_rFile_11_lat_1_ETC___d119;
  tUInt64 DEF_n__read__h32864;
  tUInt64 DEF_IF_rFile_10_lat_1_whas__03_THEN_rFile_10_lat_1_ETC___d109;
  tUInt64 DEF_n__read__h32862;
  tUInt64 DEF_IF_rFile_9_lat_1_whas__3_THEN_rFile_9_lat_1_wg_ETC___d99;
  tUInt64 DEF_n__read__h32860;
  tUInt64 DEF_IF_rFile_8_lat_1_whas__3_THEN_rFile_8_lat_1_wg_ETC___d89;
  tUInt64 DEF_n__read__h32858;
  tUInt64 DEF_IF_rFile_7_lat_1_whas__3_THEN_rFile_7_lat_1_wg_ETC___d79;
  tUInt64 DEF_n__read__h32856;
  tUInt64 DEF_IF_rFile_6_lat_1_whas__3_THEN_rFile_6_lat_1_wg_ETC___d69;
  tUInt64 DEF_n__read__h32854;
  tUInt64 DEF_IF_rFile_5_lat_1_whas__3_THEN_rFile_5_lat_1_wg_ETC___d59;
  tUInt64 DEF_n__read__h32852;
  tUInt64 DEF_IF_rFile_4_lat_1_whas__3_THEN_rFile_4_lat_1_wg_ETC___d49;
  tUInt64 DEF_n__read__h32850;
  tUInt64 DEF_IF_rFile_3_lat_1_whas__3_THEN_rFile_3_lat_1_wg_ETC___d39;
  tUInt64 DEF_n__read__h32848;
  tUInt64 DEF_IF_rFile_2_lat_1_whas__3_THEN_rFile_2_lat_1_wg_ETC___d29;
  tUInt64 DEF_n__read__h32846;
  tUInt64 DEF_IF_rFile_1_lat_1_whas__3_THEN_rFile_1_lat_1_wg_ETC___d19;
  tUInt64 DEF_n__read__h32844;
  tUInt64 DEF_IF_rFile_0_lat_1_whas_THEN_rFile_0_lat_1_wget__ETC___d9;
  tUWide DEF_rFile_14_lat_0_whas__45_CONCAT_IF_rFile_14_lat_ETC___d210;
  tUWide DEF_rFile_13_lat_0_whas__35_CONCAT_IF_rFile_13_lat_ETC___d207;
  tUWide DEF_rFile_12_lat_0_whas__25_CONCAT_IF_rFile_12_lat_ETC___d204;
  tUWide DEF_rFile_11_lat_0_whas__15_CONCAT_IF_rFile_11_lat_ETC___d201;
  tUWide DEF_rFile_10_lat_0_whas__05_CONCAT_IF_rFile_10_lat_ETC___d198;
  tUWide DEF_rFile_9_lat_0_whas__5_CONCAT_IF_rFile_9_lat_0__ETC___d195;
  tUWide DEF_rFile_8_lat_0_whas__5_CONCAT_IF_rFile_8_lat_0__ETC___d192;
  tUWide DEF_rFile_7_lat_0_whas__5_CONCAT_IF_rFile_7_lat_0__ETC___d189;
  tUWide DEF_rFile_6_lat_0_whas__5_CONCAT_IF_rFile_6_lat_0__ETC___d186;
  tUWide DEF_rFile_5_lat_0_whas__5_CONCAT_IF_rFile_5_lat_0__ETC___d183;
  tUWide DEF_rFile_4_lat_0_whas__5_CONCAT_IF_rFile_4_lat_0__ETC___d180;
  tUWide DEF_rFile_3_lat_0_whas__5_CONCAT_IF_rFile_3_lat_0__ETC___d177;
  tUWide DEF_rFile_2_lat_0_whas__5_CONCAT_IF_rFile_2_lat_0__ETC___d174;
  tUWide DEF_rFile_1_lat_0_whas__5_CONCAT_IF_rFile_1_lat_0__ETC___d171;
  tUWide DEF_rFile_0_lat_0_whas_CONCAT_IF_rFile_0_lat_0_wha_ETC___d168;
 
 /* Rules */
 public:
  void RL_rFile_0_canon();
  void RL_rFile_1_canon();
  void RL_rFile_2_canon();
  void RL_rFile_3_canon();
  void RL_rFile_4_canon();
  void RL_rFile_5_canon();
  void RL_rFile_6_canon();
  void RL_rFile_7_canon();
  void RL_rFile_8_canon();
  void RL_rFile_9_canon();
  void RL_rFile_10_canon();
  void RL_rFile_11_canon();
  void RL_rFile_12_canon();
  void RL_rFile_13_canon();
  void RL_rFile_14_canon();
 
 /* Methods */
 public:
  void METH_wrE(tUInt8 ARG_wrE_rIdx, tUInt64 ARG_wrE_data);
  tUInt8 METH_RDY_wrE();
  void METH_wrM(tUInt8 ARG_wrM_rIdx, tUInt64 ARG_wrM_data);
  tUInt8 METH_RDY_wrM();
  tUInt64 METH_rdA(tUInt8 ARG_rdA_rIdx);
  tUInt8 METH_RDY_rdA();
  tUInt64 METH_rdB(tUInt8 ARG_rdB_rIdx);
  tUInt8 METH_RDY_rdB();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkBypassRFile &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkBypassRFile &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkBypassRFile &backing);
};

#endif /* ifndef __mkBypassRFile_h__ */
