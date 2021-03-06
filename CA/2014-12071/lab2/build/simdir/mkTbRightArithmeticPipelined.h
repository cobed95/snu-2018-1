/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Tue Apr  3 15:42:19 KST 2018
 * 
 */

/* Generation options: */
#ifndef __mkTbRightArithmeticPipelined_h__
#define __mkTbRightArithmeticPipelined_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTbRightArithmeticPipelined module */
class MOD_mkTbRightArithmeticPipelined : public Module {
 
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
  MOD_Fifo<tUWide> INST_bsrap_bsrp_fifo0;
  MOD_Fifo<tUWide> INST_bsrap_bsrp_fifo1;
  MOD_Fifo<tUWide> INST_bsrap_bsrp_fifo2;
  MOD_Fifo<tUWide> INST_bsrap_bsrp_fifo3;
  MOD_Fifo<tUWide> INST_bsrap_bsrp_fifo4;
  MOD_Fifo<tUWide> INST_bsrap_bsrp_inFifo;
  MOD_Fifo<tUInt64> INST_bsrap_bsrp_outFifo;
  MOD_Reg<tUInt32> INST_correct;
  MOD_Reg<tUInt32> INST_input_cycle;
  MOD_Reg<tUInt32> INST_output_cycle;
  MOD_Reg<tUInt8> INST_randomShift_init;
  MOD_Reg<tUInt8> INST_randomVal_init;
  MOD_Fifo<tUWide> INST_valFifo;
 
 /* Constructor */
 public:
  MOD_mkTbRightArithmeticPipelined(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt32 DEF_x__h54906;
  tUInt32 DEF_x__h54519;
  tUInt8 DEF_output_cycle_05_EQ_128___d106;
 
 /* Local definitions */
 private:
  tUWide DEF_ab__h46709;
  tUWide DEF_ab__h38105;
  tUWide DEF_ab__h29250;
  tUWide DEF_ab__h20271;
  tUWide DEF_ab__h11230;
  tUWide DEF_ab__h2149;
  tUInt64 DEF_x__h54253;
  tUInt64 DEF_TASK_getRandom___d98;
  tUWide DEF_TASK_getRandom_8_CONCAT_TASK_getRandom_9_BITS__ETC___d101;
  tUWide DEF_ab__h54686;
  tUWide DEF_IF_bsrap_bsrp_fifo3_first__5_BIT_5_6_THEN_bsra_ETC___d67;
  tUWide DEF_IF_bsrap_bsrp_fifo2_first__1_BIT_4_2_THEN_bsra_ETC___d51;
  tUWide DEF_IF_bsrap_bsrp_fifo1_first__8_BIT_3_9_THEN_bsra_ETC___d37;
  tUWide DEF_IF_bsrap_bsrp_inFifo_first_BIT_1_THEN_bsrap_bs_ETC___d12;
  tUWide DEF_IF_bsrap_bsrp_fifo0_first__6_BIT_2_7_THEN_bsra_ETC___d24;
  tUWide DEF_TASK_getRandom_8_CONCAT_TASK_getRandom_9_BITS__ETC___d103;
 
 /* Rules */
 public:
  void RL_bsrap_bsrp_shift0();
  void RL_bsrap_bsrp_shift1();
  void RL_bsrap_bsrp_shift2();
  void RL_bsrap_bsrp_shift3();
  void RL_bsrap_bsrp_shift4();
  void RL_bsrap_bsrp_shift5();
  void RL_randomVal_initialize();
  void RL_randomShift_initialize();
  void RL_test_request();
  void RL_test_response();
 
 /* Methods */
 public:
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbRightArithmeticPipelined &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTbRightArithmeticPipelined &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTbRightArithmeticPipelined &backing);
};

#endif /* ifndef __mkTbRightArithmeticPipelined_h__ */
