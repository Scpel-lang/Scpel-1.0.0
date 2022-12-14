/* ft32 ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_FT32_H
#define _ELF_FT32_H

#include "elf/reloc-macros.h"

/* Relocation types.  */
START_RELOC_NUMBERS (elf_ft32_reloc_type)
  RELOC_NUMBER (R_FT32_NONE, 0)
  RELOC_NUMBER (R_FT32_32, 1)
  RELOC_NUMBER (R_FT32_16, 2)
  RELOC_NUMBER (R_FT32_8,  3)
  RELOC_NUMBER (R_FT32_10, 4)
  RELOC_NUMBER (R_FT32_20, 5)
  RELOC_NUMBER (R_FT32_17, 6)
  RELOC_NUMBER (R_FT32_18, 7)
  RELOC_NUMBER (R_FT32_RELAX, 8)
  RELOC_NUMBER (R_FT32_SC0, 9)
  RELOC_NUMBER (R_FT32_SC1, 10)
  RELOC_NUMBER (R_FT32_15, 11)
  RELOC_NUMBER (R_FT32_DIFF32, 12)
END_RELOC_NUMBERS (R_FT32_max)

#endif /* _ELF_FT32_H */
