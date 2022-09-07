/* Please review: $(src-dir)/SPL-README for Licencing info. */

#undef TARGET_FPMATH_DEFAULT
#define TARGET_FPMATH_DEFAULT (TARGET_SSE2 ? FPMATH_SSE : FPMATH_387)

#undef TARGET_FPMATH_DEFAULT_P
#define TARGET_FPMATH_DEFAULT_P(x) \
  (TARGET_SSE2_P(x) ? FPMATH_SSE : FPMATH_387)

#undef TARGET_SUBTARGET32_ISA_DEFAULT
#define TARGET_SUBTARGET32_ISA_DEFAULT \
   (OPTION_MASK_ISA_MMX | OPTION_MASK_ISA_SSE | OPTION_MASK_ISA_SSE2)
