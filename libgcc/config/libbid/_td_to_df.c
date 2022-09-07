/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

DFtype
__bid_trunctddf (_Decimal128 x) {
  DFtype res;
  union decimal128 ux;

  ux.d = x;
  res = __bid128_to_binary64 (ux.i);
  return (res);
}
