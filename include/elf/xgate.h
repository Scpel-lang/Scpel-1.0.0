/* XGATE ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_XGATE_H
#define _ELF_XGATE_H

#include "elf/reloc-macros.h"

/* Relocation types.  */
START_RELOC_NUMBERS (elf_xgate_reloc_type)
  RELOC_NUMBER (R_XGATE_NONE, 0)
  RELOC_NUMBER (R_XGATE_8, 1)
  RELOC_NUMBER (R_XGATE_PCREL_8, 2)
  RELOC_NUMBER (R_XGATE_16, 3)
  RELOC_NUMBER (R_XGATE_32, 4)
  RELOC_NUMBER (R_XGATE_PCREL_16, 5)
  /* These are GNU extensions to enable C++ vtable garbage collection.  */
  RELOC_NUMBER (R_XGATE_GNU_VTINHERIT, 6)
  RELOC_NUMBER (R_XGATE_GNU_VTENTRY, 7)

  RELOC_NUMBER (R_XGATE_24, 8)
  RELOC_NUMBER (R_XGATE_LO16, 9)
  RELOC_NUMBER (R_XGATE_GPAGE, 10)
  RELOC_NUMBER (R_XGATE_PCREL_9, 11)
  RELOC_NUMBER (R_XGATE_PCREL_10, 12)
  RELOC_NUMBER (R_XGATE_IMM8_LO, 13)
  RELOC_NUMBER (R_XGATE_IMM8_HI, 14)
  RELOC_NUMBER (R_XGATE_IMM3, 15)
  RELOC_NUMBER (R_XGATE_IMM4, 16)
  RELOC_NUMBER (R_XGATE_IMM5, 17)

  /* GNU extension for linker relaxation.
     Mark beginning of a jump instruction (any form).  */
  RELOC_NUMBER (R_XGATE_RL_JUMP, 18)

  /* Mark beginning of Gcc relaxation group instruction.  */
  RELOC_NUMBER (R_XGATE_RL_GROUP, 19)
END_RELOC_NUMBERS (R_XGATE_max)

/* Processor specific flags for the ELF header e_flags field.  */

/* ABI identification.  */
#define EF_XGATE_ABI  0x00000000F

/* Integers are 32-bit long.  */
#define E_XGATE_I32   0x000000001

/* Doubles are 64-bit long.  */
#define E_XGATE_F64   0x000000002

#define EF_XGATE_MACH_MASK  0xF0

#define EF_XGATE_MACH       0x80 /* XGATE microcontroller.  */

#define E_M68HCS12X_GLOBAL  0x100

/* Identify interrupt handlers.  This is used by the debugger to
   correctly compute the stack frame.  */
#define STO_XGATE_INTERRUPT 0x40
     
#endif
