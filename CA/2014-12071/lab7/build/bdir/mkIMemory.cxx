/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Wed Jun  6 21:41:08 KST 2018
 * 
 */
#include "bluesim_primitives.h"
#include "mkIMemory.h"


/* String declarations */
static std::string const __str_literal_1("memory.vmh", 10u);


/* Constructor */
MOD_mkIMemory::MOD_mkIMemory(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_iMem(simHdl, "iMem", this, __str_literal_1, 26u, 64u, 0u, 67108863u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15(80u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19(80u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23(80u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27(80u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34(80u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40(80u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31(80u),
    DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11(80u)
{
  PORT_req.setSize(80u);
  PORT_req.clear();
  symbol_count = 2u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkIMemory::init_symbols_0()
{
  init_symbol(&symbols[0u], "iMem", SYM_MODULE, &INST_iMem);
  init_symbol(&symbols[1u], "req", SYM_PORT, &PORT_req, 80u);
}


/* Rule actions */


/* Methods */

tUWide MOD_mkIMemory::METH_req(tUInt64 ARG_req_a)
{
  tUInt64 DEF_idx__h238;
  tUInt8 DEF_offset__h239;
  tUInt64 DEF_x__h432;
  tUInt64 DEF_x__h451;
  tUInt32 DEF_i__h428;
  tUInt64 DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9;
  tUInt32 DEF_i__h396;
  tUInt64 DEF_iMem_sub_req_a_BITS_28_TO_3___d4;
  tUInt32 DEF_i__h447;
  DEF_i__h396 = (tUInt32)(67108863u & (ARG_req_a >> 3u));
  DEF_iMem_sub_req_a_BITS_28_TO_3___d4 = INST_iMem.METH_sub(DEF_i__h396);
  DEF_offset__h239 = (tUInt8)((tUInt8)7u & ARG_req_a);
  DEF_idx__h238 = (((tUInt64)((tUInt8)0u)) << 61u) | (tUInt64)(ARG_req_a >> 3u);
  DEF_x__h451 = DEF_idx__h238 + 2llu;
  DEF_i__h447 = (tUInt32)(67108863u & DEF_x__h451);
  DEF_x__h432 = DEF_idx__h238 + 1llu;
  DEF_i__h428 = (tUInt32)(67108863u & DEF_x__h432);
  DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 = INST_iMem.METH_sub(DEF_i__h428);
  DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15.set_bits_in_word((tUInt32)(65535u & (DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 40u)),
										2u,
										0u,
										16u).set_whole_word((tUInt32)(DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 8u),
												    1u).set_whole_word((((tUInt32)((tUInt8)((tUInt8)255u & DEF_iMem_sub_req_a_BITS_28_TO_3___d4))) << 24u) | (tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 40u),
														       0u);
  DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19.set_bits_in_word((tUInt32)(65535u & (DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 32u)),
										2u,
										0u,
										16u).build_concat((((tUInt64)((tUInt32)(DEF_iMem_sub_req_a_BITS_28_TO_3___d4))) << 32u) | (tUInt64)((tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 32u)),
												  0u,
												  64u);
  DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23.set_bits_in_word((tUInt32)(65535u & (DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 24u)),
										2u,
										0u,
										16u).set_whole_word((((tUInt32)(16777215u & DEF_iMem_sub_req_a_BITS_28_TO_3___d4)) << 8u) | (tUInt32)((tUInt8)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 56u)),
												    1u).set_whole_word((tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 24u),
														       0u);
  DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27.set_bits_in_word((tUInt32)(65535u & (DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 16u)),
										2u,
										0u,
										16u).set_whole_word((((tUInt32)(65535u & DEF_iMem_sub_req_a_BITS_28_TO_3___d4)) << 16u) | (tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 48u),
												    1u).set_whole_word((tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 16u),
														       0u);
  DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34.build_concat(281474976710655llu & ((((tUInt64)((tUInt32)(65535u & DEF_iMem_sub_req_a_BITS_28_TO_3___d4))) << 32u) | (tUInt64)((tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 32u))),
									    32u,
									    48u).set_whole_word((tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9),
												0u);
  DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40.set_bits_in_word(65535u & ((((tUInt32)((tUInt8)((tUInt8)255u & DEF_iMem_sub_req_a_BITS_28_TO_3___d4))) << 8u) | (tUInt32)((tUInt8)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 56u))),
										2u,
										0u,
										16u).set_whole_word((tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 24u),
												    1u).set_whole_word((((tUInt32)(16777215u & DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9)) << 8u) | (tUInt32)((tUInt8)(INST_iMem.METH_sub(DEF_i__h447) >> 56u)),
														       0u);
  DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11.set_bits_in_word((tUInt32)(DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 48u),
										2u,
										0u,
										16u).set_whole_word((tUInt32)(DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 16u),
												    1u).set_whole_word((((tUInt32)(65535u & DEF_iMem_sub_req_a_BITS_28_TO_3___d4)) << 16u) | (tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 48u),
														       0u);
  DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31.set_bits_in_word((tUInt32)(65535u & (DEF_iMem_sub_req_a_BITS_28_TO_3___d4 >> 8u)),
										2u,
										0u,
										16u).set_whole_word((((tUInt32)((tUInt8)((tUInt8)255u & DEF_iMem_sub_req_a_BITS_28_TO_3___d4))) << 24u) | (tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 40u),
												    1u).set_whole_word((tUInt32)(DEF_iMem_sub_0_CONCAT_req_a_BITS_63_TO_3_PLUS_1_BI_ETC___d9 >> 8u),
														       0u);
  switch (DEF_offset__h239) {
  case (tUInt8)0u:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11;
    break;
  case (tUInt8)1u:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15;
    break;
  case (tUInt8)2u:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19;
    break;
  case (tUInt8)3u:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23;
    break;
  case (tUInt8)4u:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27;
    break;
  case (tUInt8)5u:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31;
    break;
  case (tUInt8)6u:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34;
    break;
  default:
    PORT_req = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40;
  }
  return PORT_req;
}

tUInt8 MOD_mkIMemory::METH_RDY_req()
{
  tUInt8 PORT_RDY_req;
  tUInt8 DEF_CAN_FIRE_req;
  DEF_CAN_FIRE_req = (tUInt8)1u;
  PORT_RDY_req = DEF_CAN_FIRE_req;
  return PORT_RDY_req;
}


/* Reset routines */

void MOD_mkIMemory::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkIMemory::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkIMemory::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_iMem.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkIMemory::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 11u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11", 80u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "req", 80u);
  num = INST_iMem.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkIMemory::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkIMemory &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkIMemory::vcd_defs(tVCDDumpType dt, MOD_mkIMemory &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
    vcd_write_x(sim_hdl, num++, 80u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34) != DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31) != DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27) != DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23) != DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19) != DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15) != DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40) != DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40;
      }
      ++num;
      if ((backing.DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11) != DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11)
      {
	vcd_write_val(sim_hdl, num, DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11, 80u);
	backing.DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11 = DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11;
      }
      ++num;
      if ((backing.PORT_req) != PORT_req)
      {
	vcd_write_val(sim_hdl, num, PORT_req, 80u);
	backing.PORT_req = PORT_req;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_15_TO_0_3_CON_ETC___d34;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_23_TO_0_9_CON_ETC___d31;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_31_TO_0_5_CON_ETC___d27;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_39_TO_0_1_CON_ETC___d23;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_47_TO_0_7_CON_ETC___d19;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_55_TO_0_3_CON_ETC___d15;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40 = DEF_iMem_sub_req_a_BITS_28_TO_3_BITS_7_TO_0_5_CONC_ETC___d40;
      vcd_write_val(sim_hdl, num++, DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11, 80u);
      backing.DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11 = DEF_iMem_sub_req_a_BITS_28_TO_3_CONCAT_iMem_sub_0__ETC___d11;
      vcd_write_val(sim_hdl, num++, PORT_req, 80u);
      backing.PORT_req = PORT_req;
    }
}

void MOD_mkIMemory::vcd_prims(tVCDDumpType dt, MOD_mkIMemory &backing)
{
  INST_iMem.dump_VCD(dt, backing.INST_iMem);
}
