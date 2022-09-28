// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/omp_loop.h
 *  @brief Parallelization of embarrassingly parallel execution by
 *  means of an OpenMP for loop.
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Felix Putze.

#ifndef _GLIBCXX_PARALLEL_OMP_LOOP_H
#define _GLIBCXX_PARALLEL_OMP_LOOP_H 1

#include <omp.h>

#include <parallel/settings.h>
#include <parallel/basic_iterator.h>
#include <parallel/base.h>

namespace __gnu_parallel
{
  /** @brief Embarrassingly parallel algorithm for random access
   * iterators, using an OpenMP for loop.
   *
   *  @param __begin Begin iterator of element sequence.
   *  @param __end End iterator of element sequence.
   *  @param __o User-supplied functor (comparator, predicate, adding
   *  functor, etc.).
   *  @param __f Functor to @a process an element with __op (depends on
   *  desired functionality, e. g. for std::for_each(), ...).
   *  @param __r Functor to @a add a single __result to the already
   *  processed elements (depends on functionality).
   *  @param __base Base value for reduction.
   *  @param __output Pointer to position where final result is written to
   *  @param __bound Maximum number of elements processed (e. g. for
   *  std::count_n()).
   *  @return User-supplied functor (that may contain a part of the result).
   */
  template<typename _RAIter,
	   typename _Op,
	   typename _Fu,
	   typename _Red,
	   typename _Result>
    _Op
    __for_each_template_random_access_omp_loop(_RAIter __begin, _RAIter __end,
					       _Op __o, _Fu& __f, _Red __r,
					       _Result __base,
					       _Result& __output,
      typename std::iterator_traits<_RAIter>::difference_type __bound)
    {
      typedef typename std::iterator_traits<_RAIter>::difference_type
        _DifferenceType;

      _DifferenceType __length = __end - __begin;
      _ThreadIndex __num_threads = __gnu_parallel::min<_DifferenceType>
	(__get_max_threads(), __length);

      _Result *__thread_results;

#     pragma omp parallel num_threads(__num_threads)
      {
#       pragma omp single
	{
	  __num_threads = omp_get_num_threads();
	  __thread_results = new _Result[__num_threads];

	  for (_ThreadIndex __i = 0; __i < __num_threads; ++__i)
	    __thread_results[__i] = _Result();
	}

        _ThreadIndex __iam = omp_get_thread_num();

#pragma omp for schedule(dynamic, _Settings::get().workstealing_chunk_size)
        for (_DifferenceType __pos = 0; __pos < __length; ++__pos)
          __thread_results[__iam] = __r(__thread_results[__iam],
					__f(__o, __begin+__pos));
      } //parallel

      for (_ThreadIndex __i = 0; __i < __num_threads; ++__i)
        __output = __r(__output, __thread_results[__i]);

      delete [] __thread_results;

      // Points to last element processed (needed as return value for
      // some algorithms like transform).
      __f._M_finish_iterator = __begin + __length;

      return __o;
    }

} // end namespace

#endif /* _GLIBCXX_PARALLEL_OMP_LOOP_H */
