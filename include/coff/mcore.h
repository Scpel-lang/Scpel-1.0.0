/* Motorola MCore support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This file holds definitions specific to the MCore COFF/PE ABI. */

#ifndef _COFF_MORE_H
#define _COFF_MORE_H

#define INCLUDE_COMDAT_FIELDS_IN_AUXENT
#define L_LNNO_SIZE 2
#include "coff/external.h"

#define	MCOREMAGIC	0xb00  /* I just made this up */ 

#define MCOREBADMAG(x) (((x).f_magic != MCOREMAGIC))

#define E_DIMNUM	4	/* # array dimensions in auxiliary entry */

#define IMAGE_REL_MCORE_ABSOLUTE          	0x0000
#define IMAGE_REL_MCORE_ADDR32            	0x0001
#define IMAGE_REL_MCORE_PCREL_IMM8BY4		0x0002
#define IMAGE_REL_MCORE_PCREL_IMM11BY2		0x0003
#define IMAGE_REL_MCORE_PCREL_IMM4BY2		0x0004
#define IMAGE_REL_MCORE_PCREL_32		0x0005
#define IMAGE_REL_MCORE_PCREL_JSR_IMM11BY2	0x0006
#define IMAGE_REL_MCORE_RVA			0x0007

#define PEMCORE

#define OMAGIC          0404    /* object files, eg as output */
#define ZMAGIC          0413    /* demand load format, eg normal ld output */
#define STMAGIC		0401	/* target shlib */
#define SHMAGIC		0443	/* host   shlib */

/* From winnt.h */
#define IMAGE_NT_OPTIONAL_HDR_MAGIC        0x10b

/* Define some NT default values. */
#define NT_SECTION_ALIGNMENT 0x1000
#define NT_FILE_ALIGNMENT    0x200  
#define NT_DEF_RESERVE       0x100000
#define NT_DEF_COMMIT        0x1000

struct external_reloc
{
  char r_vaddr  [4];
  char r_symndx [4];
  char r_type   [2];
  char r_offset [4];
};

#define RELOC struct external_reloc
#define RELSZ 14

#endif /* __COFF_MCORE_H */
