/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Wed Jun  6 21:41:08 KST 2018
 * 
 */

/* Generation options: */
#ifndef __mkBtb_h__
#define __mkBtb_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkBtb module */
class MOD_mkBtb : public Module {
 
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
  MOD_RegFile<tUInt8,tUInt64> INST_ppcArr;
  MOD_RegFile<tUInt8,tUInt64> INST_tagArr;
 
 /* Constructor */
 public:
  MOD_mkBtb(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_update_rd;
 
 /* Publicly accessible definitions */
 public:
 
 /* Local definitions */
 private:
 
 /* Rules */
 public:
 
 /* Methods */
 public:
  tUInt64 METH_predPc(tUInt64 ARG_predPc_pc, tUInt8 ARG_predPc_iCode);
  tUInt8 METH_RDY_predPc();
  void METH_update(tUWide ARG_update_rd);
  tUInt8 METH_RDY_update();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkBtb &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkBtb &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkBtb &backing);
};

#endif /* ifndef __mkBtb_h__ */
