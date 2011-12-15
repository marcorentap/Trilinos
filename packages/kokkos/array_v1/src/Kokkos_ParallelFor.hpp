/*
//@HEADER
// ************************************************************************
// 
//          Kokkos: Node API and Parallel Node Kernels
//              Copyright (2008) Sandia Corporation
// 
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Michael A. Heroux (maherou@sandia.gov) 
// 
// ************************************************************************
//@HEADER
*/

#ifndef KOKKOS_PARALLELFOR_HPP
#define KOKKOS_PARALLELFOR_HPP

#include <cstddef>
#include <impl/Kokkos_Timer.hpp>

namespace Kokkos {

//----------------------------------------------------------------------------

namespace Impl {

/** \brief Implementation of ParallelFor operator that has a
 *         partial specialization for the device.
 */
template< class FunctorType ,
          class DeviceType = typename FunctorType::device_type >
class ParallelFor {
public:
  static
  void execute( const size_t        work_count ,
                const FunctorType & functor );
};

} // namespace Impl

//----------------------------------------------------------------------------

/** \brief  Call the functor in parallel 'work_count' times. */
template< class FunctorType >
inline
void parallel_for( const size_t work_count ,
                   const FunctorType & functor )
{
  Impl::ParallelFor< FunctorType >::execute( work_count , functor );
}

/** \brief  Call the functor in parallel 'work_count' times,
 *          wait for all calls to complete and then
 *          output the wall-clock time spent in execution.
 */
template< class FunctorType >
inline
void parallel_for( const size_t work_count ,
                   const FunctorType & functor ,
                   double & seconds )
{
  typedef typename FunctorType::device_type device_type ;

  Impl::Timer timer ; // Construct and initialize the timer

  Impl::ParallelFor< FunctorType >::execute( work_count , functor );

  // The ParallelFor may launch the functor and return immediately.
  // Must wait for functor to complete to get correct timing data.
  device_type::fence();

  seconds = timer.seconds(); // Time since construction
}

//----------------------------------------------------------------------------

template< class DeviceType >
class MultiFunctorParallelFor ;

} // namespace Kokkos

#endif /* KOKKOS_DEVICEHOST_PARALLELFOR_HPP */
