/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Wed Jun  6 03:07:37 KST 2018
 * 
 */

/* Generation options: */
#ifndef __mkBypassCop_h__
#define __mkBypassCop_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkBypassCop module */
class MOD_mkBypassCop : public Module {
 
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
  MOD_Reg<tUInt8> INST_bn_data_0_dummy2_0;
  MOD_Reg<tUInt8> INST_bn_data_0_dummy2_1;
  MOD_Wire<tUInt8> INST_bn_data_0_dummy_0_0;
  MOD_Wire<tUInt8> INST_bn_data_0_dummy_0_1;
  MOD_Wire<tUInt8> INST_bn_data_0_dummy_1_0;
  MOD_Wire<tUInt8> INST_bn_data_0_dummy_1_1;
  MOD_Wire<tUInt8> INST_bn_data_0_lat_0;
  MOD_Wire<tUInt8> INST_bn_data_0_lat_1;
  MOD_Reg<tUInt8> INST_bn_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_bn_deqP_dummy2_1;
  MOD_Wire<tUInt8> INST_bn_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_bn_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_bn_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_bn_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_bn_deqP_lat_0;
  MOD_Wire<tUInt8> INST_bn_deqP_lat_1;
  MOD_Reg<tUInt8> INST_bn_deqP_rl;
  MOD_Reg<tUInt8> INST_bn_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_bn_enqP_dummy2_1;
  MOD_Wire<tUInt8> INST_bn_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_bn_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_bn_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_bn_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_bn_enqP_lat_0;
  MOD_Wire<tUInt8> INST_bn_enqP_lat_1;
  MOD_Reg<tUInt8> INST_bn_enqP_rl;
  MOD_Reg<tUWide> INST_copFifo_data_0;
  MOD_Reg<tUWide> INST_copFifo_data_1;
  MOD_Reg<tUInt8> INST_copFifo_deqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_copFifo_deqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_copFifo_deqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_lat_0;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_lat_1;
  MOD_Wire<tUInt8> INST_copFifo_deqEn_lat_2;
  MOD_Reg<tUInt8> INST_copFifo_deqEn_rl;
  MOD_Reg<tUInt8> INST_copFifo_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_copFifo_deqP_dummy2_1;
  MOD_Reg<tUInt8> INST_copFifo_deqP_dummy2_2;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_copFifo_deqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_copFifo_deqP_lat_0;
  MOD_Wire<tUInt8> INST_copFifo_deqP_lat_1;
  MOD_Wire<tUInt8> INST_copFifo_deqP_lat_2;
  MOD_Reg<tUInt8> INST_copFifo_deqP_rl;
  MOD_Reg<tUInt8> INST_copFifo_enqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_copFifo_enqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_copFifo_enqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_lat_0;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_lat_1;
  MOD_Wire<tUInt8> INST_copFifo_enqEn_lat_2;
  MOD_Reg<tUInt8> INST_copFifo_enqEn_rl;
  MOD_Reg<tUInt8> INST_copFifo_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_copFifo_enqP_dummy2_1;
  MOD_Reg<tUInt8> INST_copFifo_enqP_dummy2_2;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_copFifo_enqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_copFifo_enqP_lat_0;
  MOD_Wire<tUInt8> INST_copFifo_enqP_lat_1;
  MOD_Wire<tUInt8> INST_copFifo_enqP_lat_2;
  MOD_Reg<tUInt8> INST_copFifo_enqP_rl;
  MOD_Reg<tUInt8> INST_copFifo_tempData_dummy2_0;
  MOD_Reg<tUInt8> INST_copFifo_tempData_dummy2_1;
  MOD_Wire<tUWide> INST_copFifo_tempData_dummy_0_0;
  MOD_Wire<tUWide> INST_copFifo_tempData_dummy_0_1;
  MOD_Wire<tUWide> INST_copFifo_tempData_dummy_1_0;
  MOD_Wire<tUWide> INST_copFifo_tempData_dummy_1_1;
  MOD_Wire<tUWide> INST_copFifo_tempData_lat_0;
  MOD_Wire<tUWide> INST_copFifo_tempData_lat_1;
  MOD_Reg<tUWide> INST_copFifo_tempData_rl;
  MOD_Reg<tUInt8> INST_copFifo_tempEnqP_dummy2_0;
  MOD_Reg<tUInt8> INST_copFifo_tempEnqP_dummy2_1;
  MOD_Wire<tUInt8> INST_copFifo_tempEnqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_copFifo_tempEnqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_copFifo_tempEnqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_copFifo_tempEnqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_copFifo_tempEnqP_lat_0;
  MOD_Wire<tUInt8> INST_copFifo_tempEnqP_lat_1;
  MOD_Reg<tUInt8> INST_copFifo_tempEnqP_rl;
  MOD_Reg<tUInt64> INST_cycles;
  MOD_ConfigReg<tUInt64> INST_finishCode;
  MOD_ConfigReg<tUInt8> INST_finishReg;
  MOD_ConfigReg<tUInt64> INST_numInsts;
  MOD_ConfigReg<tUInt8> INST_startReg;
  MOD_ConfigReg<tUInt64> INST_timeReg;
 
 /* Constructor */
 public:
  MOD_mkBypassCop(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_cpuToHost;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_copFifo_deqEn_rl__h6950;
  tUInt8 DEF_copFifo_deqEn_dummy2_2__h11106;
  tUInt8 DEF_copFifo_enqEn_dummy2_2__h9612;
  tUInt8 DEF_upd__h16310;
  tUInt8 DEF_upd__h18977;
  tUInt8 DEF_upd__h16243;
  tUInt8 DEF_bn_deqP_dummy2_1__h16430;
  tUInt8 DEF_bn_deqP_dummy2_0__h16417;
  tUInt8 DEF_bn_enqP_dummy2_1__h16211;
  tUInt8 DEF_bn_enqP_dummy2_0__h19013;
  tUInt8 DEF_copFifo_enqEn_rl__h5325;
  tUInt8 DEF_IF_IF_bn_enqP_dummy2_1_45_THEN_IF_bn_enqP_lat__ETC___d154;
  tUInt8 DEF_n__read__h18976;
  tUInt8 DEF_cnt1__h15905;
  tUInt8 DEF_y__h16463;
  tUInt8 DEF_n__read__h16109;
  tUInt8 DEF_IF_bn_enqP_lat_0_whas__31_THEN_bn_enqP_lat_0_w_ETC___d134;
 
 /* Local definitions */
 private:
  tUInt8 DEF_IF_copFifo_tempEnqP_lat_0_whas__1_THEN_copFifo_ETC___d56;
  tUInt8 DEF_IF_copFifo_tempEnqP_lat_0_whas__1_THEN_NOT_cop_ETC___d61;
  tUInt8 DEF_copFifo_deqEn_lat_1_whas____d33;
  tUInt8 DEF_copFifo_enqEn_lat_1_whas____d23;
  tUWide DEF_ab__h8096;
  tUWide DEF_ab__h8050;
  tUWide DEF_ab__h8092;
  tUWide DEF_ab__h20170;
  tUWide DEF_ab__h20166;
  tUInt64 DEF_x__h16036;
  tUInt64 DEF_x__h18405;
  tUInt8 DEF_copFifo_tempEnqP_rl___d54;
  tUInt8 DEF_copFifo_tempEnqP_lat_0_wget____d52;
  tUInt8 DEF_upd__h19875;
  tUInt8 DEF_upd__h10231;
  tUInt8 DEF_upd__h10264;
  tUInt8 DEF_upd__h17388;
  tUInt8 DEF_upd__h9948;
  tUInt8 DEF_upd__h9981;
  tUInt8 DEF_copFifo_tempEnqP_lat_0_whas____d51;
  tUInt8 DEF_copFifo_deqEn_lat_1_wget____d34;
  tUInt8 DEF_copFifo_deqEn_lat_0_whas____d35;
  tUInt8 DEF_copFifo_deqEn_lat_0_wget____d36;
  tUInt8 DEF_copFifo_enqEn_lat_1_wget____d24;
  tUInt8 DEF_copFifo_enqEn_lat_0_whas____d25;
  tUInt8 DEF_copFifo_enqEn_lat_0_wget____d26;
  tUInt8 DEF_copFifo_deqP_dummy2_2__h10192;
  tUInt8 DEF_copFifo_enqP_dummy2_2__h9909;
  tUInt8 DEF_x__h9344;
  tUInt8 DEF_x__h9343;
  tUInt8 DEF_copFifo_tempEnqP_rl_4_BIT_3___d55;
  tUInt8 DEF_copFifo_tempEnqP_lat_0_wget__2_BIT_3___d53;
  tUWide DEF_IF_copFifo_tempData_dummy2_1_19_THEN_IF_copFif_ETC___d120;
  tUWide DEF_IF_copFifo_tempData_lat_0_whas__3_THEN_copFifo_ETC___d46;
  tUWide DEF_IF_copFifo_tempData_lat_1_whas__1_THEN_copFifo_ETC___d47;
  tUInt64 DEF_x__h18404;
  tUInt8 DEF_IF_copFifo_tempEnqP_lat_0_whas__1_THEN_copFifo_ETC___d66;
  tUInt8 DEF_IF_copFifo_deqP_lat_1_whas__3_THEN_copFifo_deq_ETC___d19;
  tUInt8 DEF_IF_copFifo_enqP_lat_1_whas_THEN_copFifo_enqP_l_ETC___d9;
  tUWide DEF_IF_IF_wr_idx_BIT_5_63_THEN_wr_idx_BITS_3_TO_0__ETC___d176;
 
 /* Rules */
 public:
  void RL_copFifo_enqP_canon();
  void RL_copFifo_deqP_canon();
  void RL_copFifo_enqEn_canon();
  void RL_copFifo_deqEn_canon();
  void RL_copFifo_tempData_canon();
  void RL_copFifo_tempEnqP_canon();
  void RL_copFifo_canonicalize();
  void RL_bn_enqP_canon();
  void RL_bn_deqP_canon();
  void RL_count();
  void RL_move();
 
 /* Methods */
 public:
  void METH_start();
  tUInt8 METH_RDY_start();
  tUInt8 METH_started();
  tUInt8 METH_RDY_started();
  tUInt64 METH_rd(tUInt8 ARG_rd_idx);
  tUInt8 METH_RDY_rd();
  void METH_wr(tUInt8 ARG_wr_idx, tUInt64 ARG_wr_val);
  tUInt8 METH_RDY_wr();
  tUWide METH_cpuToHost();
  tUInt8 METH_RDY_cpuToHost();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkBypassCop &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkBypassCop &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkBypassCop &backing);
};

#endif /* ifndef __mkBypassCop_h__ */
