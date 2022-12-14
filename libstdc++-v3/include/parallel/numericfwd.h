// <parallel/numeric> Forward declarations -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/numericfwd.h
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

#ifndef _GLIBCXX_PARALLEL_NUMERICFWD_H
#define _GLIBCXX_PARALLEL_NUMERICFWD_H 1

#pragma GCC system_header

#include <parallel/tags.h>
#include <parallel/settings.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
namespace __parallel
{
  template<typename _IIter, typename _Tp>
    _Tp
    accumulate(_IIter, _IIter, _Tp);

  template<typename _IIter, typename _Tp>
    _Tp
    accumulate(_IIter, _IIter, _Tp, __gnu_parallel::sequential_tag);

  template<typename _IIter, typename _Tp>
    _Tp
    accumulate(_IIter, _IIter, _Tp, __gnu_parallel::_Parallelism);

  template<typename _IIter, typename _Tp, typename _Tag>
    _Tp
    __accumulate_switch(_IIter, _IIter, _Tp, _Tag);

  template<typename _IIter, typename _Tp, typename _BinaryOper>
    _Tp
    accumulate(_IIter, _IIter, _Tp, _BinaryOper);

  template<typename _IIter, typename _Tp, typename _BinaryOper>
    _Tp
    accumulate(_IIter, _IIter, _Tp, _BinaryOper,
               __gnu_parallel::sequential_tag);

  template<typename _IIter, typename _Tp, typename _BinaryOper>
    _Tp
    accumulate(_IIter, _IIter, _Tp, _BinaryOper,
               __gnu_parallel::_Parallelism);

  template<typename _IIter, typename _Tp, typename _BinaryOper,
           typename _Tag>
    _Tp
    __accumulate_switch(_IIter, _IIter, _Tp, _BinaryOper, _Tag);

  template<typename _RAIter, typename _Tp, typename _BinaryOper>
    _Tp
    __accumulate_switch(_RAIter, _RAIter, _Tp, _BinaryOper,
                      random_access_iterator_tag,
                      __gnu_parallel::_Parallelism __parallelism
                      = __gnu_parallel::parallel_unbalanced);

  template<typename _IIter, typename _OIter>
    _OIter
    adjacent_difference(_IIter, _IIter, _OIter);

  template<typename _IIter, typename _OIter, typename _BinaryOper>
    _OIter
    adjacent_difference(_IIter, _IIter, _OIter, _BinaryOper);

  template<typename _IIter, typename _OIter>
    _OIter
    adjacent_difference(_IIter, _IIter, _OIter,
                        __gnu_parallel::sequential_tag);

  template<typename _IIter, typename _OIter, typename _BinaryOper>
    _OIter
    adjacent_difference(_IIter, _IIter, _OIter, _BinaryOper, 
                        __gnu_parallel::sequential_tag);

  template<typename _IIter, typename _OIter>
    _OIter
    adjacent_difference(_IIter, _IIter, _OIter,
                        __gnu_parallel::_Parallelism);

  template<typename _IIter, typename _OIter, typename _BinaryOper>
    _OIter
    adjacent_difference(_IIter, _IIter, _OIter, _BinaryOper, 
                        __gnu_parallel::_Parallelism);

  template<typename _IIter, typename _OIter, typename _BinaryOper,
           typename _Tag1, typename _Tag2>
    _OIter
    __adjacent_difference_switch(_IIter, _IIter, _OIter, _BinaryOper,
                               _Tag1, _Tag2);

  template<typename _IIter, typename _OIter, typename _BinaryOper>
    _OIter
    __adjacent_difference_switch(_IIter, _IIter, _OIter, _BinaryOper, 
                               random_access_iterator_tag, 
                               random_access_iterator_tag, 
                               __gnu_parallel::_Parallelism __parallelism
                               = __gnu_parallel::parallel_unbalanced);

  template<typename _IIter1, typename _IIter2, typename _Tp>
    _Tp
    inner_product(_IIter1, _IIter1, _IIter2, _Tp);

  template<typename _IIter1, typename _IIter2, typename _Tp>
    _Tp
    inner_product(_IIter1, _IIter1, _IIter2, _Tp,
                  __gnu_parallel::sequential_tag);

  template<typename _IIter1, typename _IIter2, typename _Tp>
    _Tp
    inner_product(_IIter1, _IIter1, _IIter2, _Tp,
                  __gnu_parallel::_Parallelism);

  template<typename _IIter1, typename _IIter2, typename _Tp,
           typename _BinaryFunction1, typename _BinaryFunction2>
    _Tp
    inner_product(_IIter1, _IIter1, _IIter2, _Tp,
                  _BinaryFunction1, _BinaryFunction2);

  template<typename _IIter1, typename _IIter2, typename _Tp,
           typename _BinaryFunction1, typename _BinaryFunction2>
    _Tp
    inner_product(_IIter1, _IIter1, _IIter2, _Tp, _BinaryFunction1,
                  _BinaryFunction2, __gnu_parallel::sequential_tag);

  template<typename _IIter1, typename _IIter2, typename _Tp,
           typename _BinaryFunction1, typename _BinaryFunction2>
    _Tp
    inner_product(_IIter1, _IIter1, _IIter2, _Tp, _BinaryFunction1,
                  _BinaryFunction2, __gnu_parallel::_Parallelism);

  template<typename _RAIter1, typename _RAIter2, typename _Tp,
           typename _BinaryFunction1, typename _BinaryFunction2>
    _Tp
    __inner_product_switch(_RAIter1, _RAIter1, _RAIter2, _Tp, _BinaryFunction1,
                         _BinaryFunction2, random_access_iterator_tag,
                         random_access_iterator_tag,
                         __gnu_parallel::_Parallelism
                         = __gnu_parallel::parallel_unbalanced);

  template<typename _IIter1, typename _IIter2, typename _Tp,
           typename _BinaryFunction1, typename _BinaryFunction2,
           typename _Tag1, typename _Tag2>
    _Tp
    __inner_product_switch(_IIter1, _IIter1, _IIter2, _Tp, _BinaryFunction1, 
                         _BinaryFunction2, _Tag1, _Tag2);


  template<typename _IIter, typename _OIter>
    _OIter
    partial_sum(_IIter, _IIter, _OIter, __gnu_parallel::sequential_tag);

  template<typename _IIter, typename _OIter, typename _BinaryOper>
    _OIter
    partial_sum(_IIter, _IIter, _OIter, _BinaryOper,
                __gnu_parallel::sequential_tag);

  template<typename _IIter, typename _OIter>
    _OIter
    partial_sum(_IIter, _IIter, _OIter __result);

  template<typename _IIter, typename _OIter, typename _BinaryOper>
    _OIter
    partial_sum(_IIter, _IIter, _OIter, _BinaryOper);

  template<typename _IIter, typename _OIter, typename _BinaryOper,
           typename _Tag1, typename _Tag2>
    _OIter
    __partial_sum_switch(_IIter, _IIter, _OIter, _BinaryOper, _Tag1, _Tag2);

  template<typename _IIter, typename _OIter, typename _BinaryOper>
    _OIter
    __partial_sum_switch(_IIter, _IIter, _OIter, _BinaryOper,
                       random_access_iterator_tag, random_access_iterator_tag);
} // end namespace
} // end namespace

#endif /* _GLIBCXX_PARALLEL_NUMERICFWD_H */
