/* Definitions of target machine for Intel MCU psABI.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Intel MCU has no 80387.  Default to Intel MCU psABI.  */
#undef TARGET_SUBTARGET_DEFAULT
#define TARGET_SUBTARGET_DEFAULT MASK_IAMCU

/* Output at beginning of assembler file.  */
/* The .file command should always begin the output.  */
#define TARGET_ASM_FILE_START_FILE_DIRECTIVE true

#undef ASM_COMMENT_START
#define ASM_COMMENT_START "#"

#undef DBX_REGISTER_NUMBER
#define DBX_REGISTER_NUMBER(n) \
  (TARGET_64BIT ? dbx64_register_map[n] : svr4_dbx_register_map[n])

#undef ASM_SPEC
#define ASM_SPEC "--32 -march=iamcu"

#undef LINK_SPEC
#define LINK_SPEC "-m elf_iamcu"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC ""

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s"

#undef LIB_SPEC
#define LIB_SPEC "--start-group -lc -lgloss --end-group"

/* A C statement (sans semicolon) to output to the stdio stream
   FILE the assembler definition of uninitialized global DECL named
   NAME whose size is SIZE bytes and alignment is ALIGN bytes.
   Try to use asm_output_aligned_bss to implement this macro.  */

#define ASM_OUTPUT_ALIGNED_BSS(FILE, DECL, NAME, SIZE, ALIGN) \
  asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)

/* A C statement to output to the stdio stream FILE an assembler
   command to advance the location counter to a multiple of 1<<LOG
   bytes if it is within MAX_SKIP bytes.  */

#define SUBALIGN_LOG 3

/* Handle special EH pointer encodings.  Absolute, pc-relative, and
   indirect are handled automatically.  */
#define ASM_MAYBE_OUTPUT_ENCODED_ADDR_RTX(FILE, ENCODING, SIZE, ADDR, DONE) \
  do {									\
    if ((SIZE) == 4 && ((ENCODING) & 0x70) == DW_EH_PE_datarel)		\
      {									\
        fputs (ASM_LONG, FILE);						\
        assemble_name (FILE, XSTR (ADDR, 0));				\
	fputs (((ENCODING) & DW_EH_PE_indirect ? "@GOT" : "@GOTOFF"), FILE); \
        goto DONE;							\
      }									\
  } while (0)

#undef SIZE_TYPE
#define SIZE_TYPE "unsigned int"

#undef PTRDIFF_TYPE
#define PTRDIFF_TYPE "int"

#undef WCHAR_TYPE
#define WCHAR_TYPE "long int"

#undef WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE BITS_PER_WORD

/* Use int, instead of long int, for int32_t and uint32_t.  */
#undef STDINT_LONG32
#define STDINT_LONG32 0
