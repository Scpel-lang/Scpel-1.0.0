/* Make configure files to produce biarch compiler defaulting to x32 mode.
   This file must be included very first, while the OS specific file later
   to overwrite otherwise wrong defaults.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define TARGET_64BIT_DEFAULT (OPTION_MASK_ISA_64BIT | OPTION_MASK_ABI_X32)
#define TARGET_BI_ARCH 2
