/* Definitions for AMD x86-64 using GNU userspace.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Provide a LINK_SPEC.  Here we provide support for the special GCC
   options -static and -shared, which allow us to link things in one
   of these three modes by applying the appropriate combinations of
   options at link-time.

   When the -shared link option is used a final link is not being
   done.  */

#if TARGET_64BIT_DEFAULT
#define SPEC_32 "m16|m32"
#if TARGET_BI_ARCH == 2
#define SPEC_64 "m64"
#define SPEC_X32 "m16|m32|m64:;"
#else
#define SPEC_64 "m16|m32|mx32:;"
#define SPEC_X32 "mx32"
#endif
#else
#define SPEC_32 "m64|mx32:;"
#define SPEC_64 "m64"
#define SPEC_X32 "mx32"
#endif

#undef ASM_SPEC
#define ASM_SPEC "%{" SPEC_32 ":--32} \
 %{" SPEC_64 ":--64} \
 %{" SPEC_X32 ":--x32} \
 %{msse2avx:%{!mavx:-msse2avx}}"

#define GNU_USER_TARGET_LINK_SPEC				   \
                  "%{" SPEC_64 ":-m " GNU_USER_LINK_EMULATION64 "} \
                   %{" SPEC_32 ":-m " GNU_USER_LINK_EMULATION32 "} \
                   %{" SPEC_X32 ":-m " GNU_USER_LINK_EMULATIONX32 "} \
  %{shared:-shared} \
  %{!shared: \
    %{!static: \
      %{!static-pie: \
	%{rdynamic:-export-dynamic} \
	%{" SPEC_32 ":-dynamic-linker " GNU_USER_DYNAMIC_LINKER32 "} \
	%{" SPEC_64 ":-dynamic-linker " GNU_USER_DYNAMIC_LINKER64 "} \
	%{" SPEC_X32 ":-dynamic-linker " GNU_USER_DYNAMIC_LINKERX32 "}}} \
    %{static:-static} %{static-pie:-static -pie --no-dynamic-linker -z text}}"

#undef	LINK_SPEC
#define LINK_SPEC GNU_USER_TARGET_LINK_SPEC

#if TARGET_64BIT_DEFAULT
#if TARGET_BI_ARCH == 2
#define MULTILIB_DEFAULTS { "mx32" }
#else
#define MULTILIB_DEFAULTS { "m64" }
#endif
#else
#define MULTILIB_DEFAULTS { "m32" }
#endif

#ifdef TARGET_LIBC_PROVIDES_SSP
/* i386 glibc provides __stack_chk_guard in %gs:0x14,
   x32 glibc provides it in %fs:0x18.
   x86_64 glibc provides it in %fs:0x28.  */
#define TARGET_THREAD_SSP_OFFSET \
  (TARGET_64BIT ? (TARGET_X32 ? 0x18 : 0x28) : 0x14)

/* i386 glibc provides __private_ss in %gs:0x30.
   x32 glibc provides it in %fs:0x40.
   x86_64 glibc provides it in %fs:0x70.  */
#define TARGET_THREAD_SPLIT_STACK_OFFSET \
  (TARGET_64BIT ? (TARGET_X32 ? 0x40 : 0x70) : 0x30)
#endif

#undef WCHAR_TYPE
#define WCHAR_TYPE (TARGET_LP64 ? "int" : "long int")
