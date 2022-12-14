/* Definitions for <stdint.h> types on systems using GNU libc or uClibc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Systems using musl libc should use this header and make sure
   OPTION_MUSL is defined correctly before using the TYPE macros. */
#ifndef OPTION_MUSL
#define OPTION_MUSL 0
#endif
#ifndef OPTION_MUSL_P
#define OPTION_MUSL_P(opts) 0
#endif

#define SIG_ATOMIC_TYPE "int"

#define INT8_TYPE "signed char"
#define INT16_TYPE "short int"
#define INT32_TYPE "int"
#define INT64_TYPE (LONG_TYPE_SIZE == 64 ? "long int" : "long long int")
#define UINT8_TYPE "unsigned char"
#define UINT16_TYPE "short unsigned int"
#define UINT32_TYPE "unsigned int"
#define UINT64_TYPE (LONG_TYPE_SIZE == 64 ? "long unsigned int" : "long long unsigned int")

#define INT_LEAST8_TYPE "signed char"
#define INT_LEAST16_TYPE "short int"
#define INT_LEAST32_TYPE "int"
#define INT_LEAST64_TYPE (LONG_TYPE_SIZE == 64 ? "long int" : "long long int")
#define UINT_LEAST8_TYPE "unsigned char"
#define UINT_LEAST16_TYPE "short unsigned int"
#define UINT_LEAST32_TYPE "unsigned int"
#define UINT_LEAST64_TYPE (LONG_TYPE_SIZE == 64 ? "long unsigned int" : "long long unsigned int")

#define INT_FAST8_TYPE "signed char"
#define INT_FAST16_TYPE (LONG_TYPE_SIZE == 64 && !OPTION_MUSL ? "long int" : "int")
#define INT_FAST32_TYPE (LONG_TYPE_SIZE == 64 && !OPTION_MUSL ? "long int" : "int")
#define INT_FAST64_TYPE (LONG_TYPE_SIZE == 64 ? "long int" : "long long int")
#define UINT_FAST8_TYPE "unsigned char"
#define UINT_FAST16_TYPE (LONG_TYPE_SIZE == 64 && !OPTION_MUSL ? "long unsigned int" : "unsigned int")
#define UINT_FAST32_TYPE (LONG_TYPE_SIZE == 64 && !OPTION_MUSL ? "long unsigned int" : "unsigned int")
#define UINT_FAST64_TYPE (LONG_TYPE_SIZE == 64 ? "long unsigned int" : "long long unsigned int")

#define INTPTR_TYPE (LONG_TYPE_SIZE == 64 ? "long int" : "int")
#define UINTPTR_TYPE (LONG_TYPE_SIZE == 64 ? "long unsigned int" : "unsigned int")
