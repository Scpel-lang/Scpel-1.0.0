/* s12z ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_S12Z_H
#define _ELF_S12Z_H

#include "elf/reloc-macros.h"

/* Relocation types.  */
START_RELOC_NUMBERS (elf_s12z_reloc_type)
  RELOC_NUMBER (R_S12Z_NONE, 0)
  RELOC_NUMBER (R_S12Z_OPR, 1)
  RELOC_NUMBER (R_S12Z_UKNWN_2, 2)
  RELOC_NUMBER (R_S12Z_PCREL_7_15, 3)
  RELOC_NUMBER (R_S12Z_EXT24, 4)
  RELOC_NUMBER (R_S12Z_EXT18, 5)
  RELOC_NUMBER (R_S12Z_CW32, 6)
  RELOC_NUMBER (R_S12Z_EXT32, 7)
END_RELOC_NUMBERS (R_S12Z_max)

#endif
