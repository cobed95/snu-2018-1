/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Tue Jun  5 12:22:20 KST 2018
 * 
 */

/* Generation options: */
#ifndef __mkTestBench_h__
#define __mkTestBench_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkProc.h"


/* Class declaration for the mkTestBench module */
class MOD_mkTestBench : public Module {
 
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
  MOD_Reg<tUInt32> INST_cycle;
  MOD_mkProc INST_proc;
  MOD_Reg<tUInt8> INST_tState;
 
 /* Constructor */
 public:
  MOD_mkTestBench(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUWide DEF_ab__h349;
  tUWide DEF_ab__h375;
  tUInt32 DEF__read__h131;
 
 /* Rules */
 public:
  void RL_start();
  void RL_countCycle();
  void RL_run();
  void RL_halt();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTestBench &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTestBench &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTestBench &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkTestBench &backing);
};

#endif /* ifndef __mkTestBench_h__ */
