/* IP2xxx ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_IP2K_H
#define _ELF_IP2K_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_ip2k_reloc_type)
  RELOC_NUMBER (R_IP2K_NONE, 0)
  RELOC_NUMBER (R_IP2K_16, 1)
  RELOC_NUMBER (R_IP2K_32, 2)
  RELOC_NUMBER (R_IP2K_FR9, 3)
  RELOC_NUMBER (R_IP2K_BANK, 4)
  RELOC_NUMBER (R_IP2K_ADDR16CJP, 5)
  RELOC_NUMBER (R_IP2K_PAGE3, 6)
  RELOC_NUMBER (R_IP2K_LO8DATA, 7)
  RELOC_NUMBER (R_IP2K_HI8DATA, 8)
  RELOC_NUMBER (R_IP2K_LO8INSN, 9)
  RELOC_NUMBER (R_IP2K_HI8INSN, 10)
  RELOC_NUMBER (R_IP2K_PC_SKIP, 11)
  RELOC_NUMBER (R_IP2K_TEXT, 12)
  RELOC_NUMBER (R_IP2K_FR_OFFSET, 13)
  RELOC_NUMBER (R_IP2K_EX8DATA, 14)
END_RELOC_NUMBERS(R_IP2K_max)


/* Define the data & instruction memory discriminator.  In a linked
   executable, an symbol should be deemed to point to an instruction
   if ((address & IP2K_INSN_MASK) == IP2K_INSN_VALUE), and similarly
   for the data space.  See also `ld/emulparams/elf32ip2k.sh'.  */
/* ??? Consider extending the _MASK values to include all the
   intermediate bits that must be zero due to the limited physical
   memory size on the IP2K.  */

#define IP2K_DATA_MASK   0xff000000
#define IP2K_DATA_VALUE  0x01000000
#define IP2K_INSN_MASK   0xff000000
#define IP2K_INSN_VALUE  0x02000000

/* The location of the memory mapped hardware stack.  */
#define IP2K_STACK_VALUE 0x0f000000
#define IP2K_STACK_SIZE  0x20

#endif /* _ELF_IP2K_H */
