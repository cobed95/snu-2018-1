/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Thu May 31 15:42:45 KST 2018
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
  MOD_Reg<tUInt8> INST_bypassE_data_0_dummy2_0;
  MOD_Reg<tUInt8> INST_bypassE_data_0_dummy2_1;
  MOD_Wire<tUWide> INST_bypassE_data_0_dummy_0_0;
  MOD_Wire<tUWide> INST_bypassE_data_0_dummy_0_1;
  MOD_Wire<tUWide> INST_bypassE_data_0_dummy_1_0;
  MOD_Wire<tUWide> INST_bypassE_data_0_dummy_1_1;
  MOD_Wire<tUWide> INST_bypassE_data_0_lat_0;
  MOD_Wire<tUWide> INST_bypassE_data_0_lat_1;
  MOD_Reg<tUWide> INST_bypassE_data_0_rl;
  MOD_Reg<tUInt8> INST_bypassE_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_bypassE_deqP_dummy2_1;
  MOD_Wire<tUInt8> INST_bypassE_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_bypassE_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_bypassE_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_bypassE_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_bypassE_deqP_lat_0;
  MOD_Wire<tUInt8> INST_bypassE_deqP_lat_1;
  MOD_Reg<tUInt8> INST_bypassE_deqP_rl;
  MOD_Reg<tUInt8> INST_bypassE_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_bypassE_enqP_dummy2_1;
  MOD_Wire<tUInt8> INST_bypassE_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_bypassE_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_bypassE_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_bypassE_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_bypassE_enqP_lat_0;
  MOD_Wire<tUInt8> INST_bypassE_enqP_lat_1;
  MOD_Reg<tUInt8> INST_bypassE_enqP_rl;
  MOD_Reg<tUInt8> INST_bypassM_data_0_dummy2_0;
  MOD_Reg<tUInt8> INST_bypassM_data_0_dummy2_1;
  MOD_Wire<tUWide> INST_bypassM_data_0_dummy_0_0;
  MOD_Wire<tUWide> INST_bypassM_data_0_dummy_0_1;
  MOD_Wire<tUWide> INST_bypassM_data_0_dummy_1_0;
  MOD_Wire<tUWide> INST_bypassM_data_0_dummy_1_1;
  MOD_Wire<tUWide> INST_bypassM_data_0_lat_0;
  MOD_Wire<tUWide> INST_bypassM_data_0_lat_1;
  MOD_Reg<tUWide> INST_bypassM_data_0_rl;
  MOD_Reg<tUInt8> INST_bypassM_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_bypassM_deqP_dummy2_1;
  MOD_Wire<tUInt8> INST_bypassM_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_bypassM_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_bypassM_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_bypassM_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_bypassM_deqP_lat_0;
  MOD_Wire<tUInt8> INST_bypassM_deqP_lat_1;
  MOD_Reg<tUInt8> INST_bypassM_deqP_rl;
  MOD_Reg<tUInt8> INST_bypassM_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_bypassM_enqP_dummy2_1;
  MOD_Wire<tUInt8> INST_bypassM_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_bypassM_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_bypassM_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_bypassM_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_bypassM_enqP_lat_0;
  MOD_Wire<tUInt8> INST_bypassM_enqP_lat_1;
  MOD_Reg<tUInt8> INST_bypassM_enqP_rl;
  MOD_ConfigReg<tUInt64> INST_rfile_0;
  MOD_ConfigReg<tUInt64> INST_rfile_1;
  MOD_ConfigReg<tUInt64> INST_rfile_10;
  MOD_ConfigReg<tUInt64> INST_rfile_11;
  MOD_ConfigReg<tUInt64> INST_rfile_12;
  MOD_ConfigReg<tUInt64> INST_rfile_13;
  MOD_ConfigReg<tUInt64> INST_rfile_14;
  MOD_ConfigReg<tUInt64> INST_rfile_2;
  MOD_ConfigReg<tUInt64> INST_rfile_3;
  MOD_ConfigReg<tUInt64> INST_rfile_4;
  MOD_ConfigReg<tUInt64> INST_rfile_5;
  MOD_ConfigReg<tUInt64> INST_rfile_6;
  MOD_ConfigReg<tUInt64> INST_rfile_7;
  MOD_ConfigReg<tUInt64> INST_rfile_8;
  MOD_ConfigReg<tUInt64> INST_rfile_9;
 
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
  tUInt8 DEF_upd__h8703;
  tUInt8 DEF_upd__h11405;
  tUInt8 DEF_upd__h8235;
  tUInt8 DEF_upd__h10913;
  tUInt8 DEF_bypassM_deqP_dummy2_1__h8823;
  tUInt8 DEF_bypassM_deqP_dummy2_0__h8810;
  tUInt8 DEF_bypassM_enqP_dummy2_1__h8604;
  tUInt8 DEF_bypassM_enqP_dummy2_0__h11441;
  tUInt8 DEF_bypassE_deqP_dummy2_1__h8355;
  tUInt8 DEF_bypassE_deqP_dummy2_0__h8342;
  tUInt8 DEF_bypassE_enqP_dummy2_1__h8136;
  tUInt8 DEF_bypassE_enqP_dummy2_0__h10949;
  tUInt8 DEF_n__read__h11404;
  tUInt8 DEF_n__read__h10912;
  tUInt8 DEF_y__h8856;
  tUInt8 DEF_y__h8388;
 
 /* Local definitions */
 private:
  tUInt8 DEF_eDst__h9408;
  tUInt8 DEF_mDst__h9410;
  tUInt8 DEF_cnt1__h4520;
  tUInt8 DEF_cnt1__h7944;
  tUInt8 DEF_NOT_IF_IF_bypassE_enqP_dummy2_1_3_THEN_IF_bypa_ETC___d77;
  tUInt64 DEF_eData__h9409;
  tUInt64 DEF_mData__h9411;
  tUWide DEF_ab__h5691;
  tUWide DEF_ab__h5645;
  tUWide DEF_ab__h5687;
  tUWide DEF_ab__h2267;
  tUWide DEF_ab__h2221;
  tUWide DEF_ab__h2263;
  tUInt64 DEF__read__h1042;
  tUInt64 DEF__read__h1004;
  tUInt64 DEF__read__h966;
  tUInt64 DEF__read__h928;
  tUInt64 DEF__read__h890;
  tUInt64 DEF__read__h852;
  tUInt64 DEF__read__h814;
  tUInt64 DEF__read__h776;
  tUInt64 DEF__read__h738;
  tUInt64 DEF__read__h700;
  tUInt64 DEF__read__h662;
  tUInt64 DEF__read__h624;
  tUInt64 DEF__read__h586;
  tUInt64 DEF__read__h548;
  tUInt64 DEF__read__h510;
  tUInt8 DEF_upd__h8636;
  tUInt8 DEF_upd__h8168;
  tUInt8 DEF_bypassM_data_0_dummy2_1__h9894;
  tUInt8 DEF_bypassM_data_0_lat_0_whas____d24;
  tUInt8 DEF_bypassE_data_0_dummy2_1__h9622;
  tUInt8 DEF_bypassE_data_0_lat_0_whas____d3;
  tUInt64 DEF__read_snd__h5694;
  tUInt64 DEF_x_wget_snd__h5690;
  tUInt64 DEF_x_wget_snd__h2266;
  tUInt64 DEF__read_snd__h2270;
  tUInt8 DEF__read_fst__h5693;
  tUInt8 DEF_x_wget_fst__h5689;
  tUInt8 DEF_x_wget_fst__h2265;
  tUInt8 DEF__read_fst__h2269;
  tUWide DEF_IF_bypassM_data_0_lat_1_whas__2_THEN_bypassM_d_ETC___d28;
  tUWide DEF_IF_bypassM_data_0_lat_0_whas__4_THEN_bypassM_d_ETC___d27;
  tUWide DEF_IF_bypassE_data_0_lat_0_whas_THEN_bypassE_data_ETC___d6;
  tUWide DEF_IF_bypassE_data_0_lat_1_whas_THEN_bypassE_data_ETC___d7;
  tUInt64 DEF_IF_bypassM_data_0_lat_0_whas__4_THEN_bypassM_d_ETC___d139;
  tUInt64 DEF_IF_bypassE_data_0_lat_0_whas_THEN_bypassE_data_ETC___d88;
  tUInt8 DEF_IF_IF_bypassM_enqP_dummy2_1_7_THEN_IF_bypassM__ETC___d66;
  tUInt8 DEF_IF_IF_bypassE_enqP_dummy2_1_3_THEN_IF_bypassE__ETC___d52;
  tUInt8 DEF_IF_bypassM_data_0_lat_0_whas__4_THEN_bypassM_d_ETC___d81;
  tUInt8 DEF_IF_bypassE_data_0_lat_0_whas_THEN_bypassE_data_ETC___d74;
  tUInt8 DEF_n__read__h8502;
  tUInt8 DEF_IF_bypassM_enqP_lat_0_whas__1_THEN_bypassM_enq_ETC___d34;
  tUInt8 DEF_n__read__h8034;
  tUInt8 DEF_IF_bypassE_enqP_lat_0_whas__0_THEN_bypassE_enq_ETC___d13;
  tUInt8 DEF_NOT_IF_IF_bypassE_enqP_dummy2_1_3_THEN_IF_bypa_ETC___d53;
  tUInt8 DEF_NOT_IF_IF_bypassM_enqP_dummy2_1_7_THEN_IF_bypa_ETC___d67;
  tUWide DEF_wrM_rindx_CONCAT_wrM_data___d217;
  tUWide DEF_wrE_rindx_CONCAT_wrE_data___d207;
 
 /* Rules */
 public:
  void RL_bypassE_data_0_canon();
  void RL_bypassE_enqP_canon();
  void RL_bypassE_deqP_canon();
  void RL_bypassM_data_0_canon();
  void RL_bypassM_enqP_canon();
  void RL_bypassM_deqP_canon();
  void RL_update();
 
 /* Methods */
 public:
  void METH_wrE(tUInt8 ARG_wrE_rindx, tUInt64 ARG_wrE_data);
  tUInt8 METH_RDY_wrE();
  void METH_wrM(tUInt8 ARG_wrM_rindx, tUInt64 ARG_wrM_data);
  tUInt8 METH_RDY_wrM();
  tUInt64 METH_rdA(tUInt8 ARG_rdA_rindx);
  tUInt8 METH_RDY_rdA();
  tUInt64 METH_rdB(tUInt8 ARG_rdB_rindx);
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