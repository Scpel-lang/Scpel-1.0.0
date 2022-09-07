/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_HF_MODE || BID_HAS_HF_MODE
HFtype
__bid_truncddhf (_Decimal64 x) {
  HFtype res;
  union decimal64 ux;

  ux.d = x;
  res = __bid64_to_binary32 (ux.i);
  return (res);
}
#endif
