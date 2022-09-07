// Wrapper for underlying C-language localization -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.8  Standard locale categories.
//

#ifndef _GLIBCXX_CXX_LOCALE_H
#define _GLIBCXX_CXX_LOCALE_H 1

#pragma GCC system_header

#include <clocale>

#define _GLIBCXX_NUM_CATEGORIES 0

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  typedef int*			__c_locale;

  // Convert numeric value of type double and long double to string and
  // return length of string.  If vsnprintf is available use it, otherwise
  // fall back to the unsafe vsprintf which, in general, can be dangerous
  // and should be avoided.
  inline int
  __convert_from_v(const __c_locale&, char* __out,
		   const int __size __attribute__((__unused__)),
		   const char* __fmt, ...)
  {
    char* __old = std::setlocale(LC_NUMERIC, 0);
    char* __sav = 0;
    if (__builtin_strcmp(__old, "C"))
      {
	const size_t __len = __builtin_strlen(__old) + 1;
	__sav = new char[__len];
	__builtin_memcpy(__sav, __old, __len);
	std::setlocale(LC_NUMERIC, "C");
      }

    __builtin_va_list __args;
    __builtin_va_start(__args, __fmt);

#if _GLIBCXX_USE_C99_STDIO && !_GLIBCXX_HAVE_BROKEN_VSNPRINTF
    const int __ret = __builtin_vsnprintf(__out, __size, __fmt, __args);
#else
    const int __ret = __builtin_vsprintf(__out, __fmt, __args);
#endif

    __builtin_va_end(__args);

    if (__sav)
      {
	std::setlocale(LC_NUMERIC, __sav);
	delete [] __sav;
      }
    return __ret;
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
