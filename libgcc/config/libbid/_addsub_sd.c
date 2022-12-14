/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal32
__bid_addsd3 (_Decimal32 x, _Decimal32 y) {
  UINT64 x64, y64, res64;
  union decimal32 ux, uy, res;

  ux.d = x;
  uy.d = y;
  x64 = __bid32_to_bid64 (ux.i);
  y64 = __bid32_to_bid64 (uy.i);
  res64 = __bid64_add (x64, y64);
  res.i = __bid64_to_bid32 (res64);
  return (res.d);
}

_Decimal32
__bid_subsd3 (_Decimal32 x, _Decimal32 y) {
  UINT64 x64, y64, res64;
  union decimal32 ux, uy, res;

  ux.d = x;
  uy.d = y;
  x64 = __bid32_to_bid64 (ux.i);
  y64 = __bid32_to_bid64 (uy.i);
  res64 = __bid64_sub (x64, y64);
  res.i = __bid64_to_bid32 (res64);
  return (res.d);
}
