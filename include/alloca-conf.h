/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

/* This is a merge of code recommended in the autoconf-2.61 documentation
   with that recommended in the autoconf-2.13 documentation, with added
   tweaks to heed C_ALLOCA.  */

#if defined HAVE_ALLOCA_H && !defined C_ALLOCA
# include <alloca.h>
#else
# if defined __GNUC__ && !defined C_ALLOCA
#  if !defined alloca
#   define alloca __builtin_alloca
#  endif
# else
#  if defined _AIX
/* Indented so that pre-ansi C compilers will ignore it, rather than
   choke on it.  Some versions of AIX require this to be the first
   thing seen by the compiler except for comments and preprocessor
   directives.  */
    #pragma alloca
#  else
#   if defined _MSC_VER && !defined C_ALLOCA
#    include <malloc.h>
#    define alloca _alloca
#   else
#    if !defined alloca
#     if defined __STDC__ || defined __hpux
#      if defined HAVE_STDDEF_H
#       include <stddef.h>
#       if defined  __cplusplus
extern "C" void *alloca (size_t);
#       else
extern void *alloca (size_t);
#       endif
#      else
extern void *alloca ();
#      endif
#     else
extern char *alloca ();
#     endif
#    endif
#   endif
#  endif
# endif
#endif
