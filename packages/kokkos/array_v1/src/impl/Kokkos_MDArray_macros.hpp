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

#if ! defined(KOKKOS_MACRO_DEVICE_TEMPLATE_SPECIALIZATION) || \
    ! defined(KOKKOS_MACRO_DEVICE)                  || \
    ! defined(KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION)

#error "Including <impl/Kokkos_MDArray_macros.hpp> without macros defined"

#else

namespace Kokkos {

#ifdef KOKKOS_MACRO_MDARRAY_TEMPLATE_ARGUMENT
template< typename ValueType , KOKKOS_MACRO_MDARRAY_TEMPLATE_ARGUMENT >
#else
template< typename ValueType >
#endif
class MDArray< ValueType , KOKKOS_MACRO_DEVICE >
{
public:
  typedef ValueType                           value_type ;
  typedef KOKKOS_MACRO_DEVICE                 device_type ;
  typedef typename device_type::mdarray_map   mdarray_map ;
  typedef typename device_type::size_type     size_type ;

  typedef typename
    Impl::MDArrayHostMirror< value_type , mdarray_map >::type HostMirror ;

  /*------------------------------------------------------------------*/
  /** \brief  Query rank of the array */
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return m_map.rank(); }

  /** \brief  Query dimension of the given ordinate of the array */
  template < typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & rank_ordinate ) const
  { return m_map.dimension( rank_ordinate ); }

  template < typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  { m_map.dimensions( dims ); }

  /** \brief  Query rank of the array */
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return m_map.size(); }

  /*------------------------------------------------------------------*/

#if defined( KOKKOS_MACRO_DEVICE_FUNCTION )

  /** \brief  Because memory is contiguous this is exposed */
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type * ptr_on_device() const
  {
    // TBD: If memory is not contiguous and can throw then throw !
    return m_memory.ptr_on_device();
  }

  /*------------------------------------------------------------------*/
  /** \brief  Query value of a rank 8 array */
  template< typename iTypeP , typename iType1 ,
            typename iType2 , typename iType3 ,
            typename iType4 , typename iType5 ,
            typename iType6 , typename iType7 >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP , const iType1 & i1 ,
                           const iType2 & i2 , const iType3 & i3 ,
                           const iType4 & i4 , const iType5 & i5 ,
                           const iType6 & i6 , const iType7 & i7 ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP,i1,i2,i3,i4,i5,i6,i7) ]; }

  /** \brief  Query value of a rank 7 array */
  template< typename iTypeP , typename iType1 ,
            typename iType2 , typename iType3 ,
            typename iType4 , typename iType5 ,
            typename iType6 >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP , const iType1 & i1 ,
                           const iType2 & i2 , const iType3 & i3 ,
                           const iType4 & i4 , const iType5 & i5 ,
                           const iType6 & i6 ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP,i1,i2,i3,i4,i5,i6) ]; }

  /** \brief  Query value of a rank 6 array */
  template< typename iTypeP , typename iType1 ,
            typename iType2 , typename iType3 ,
            typename iType4 , typename iType5 >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP , const iType1 & i1 ,
                           const iType2 & i2 , const iType3 & i3 ,
                           const iType4 & i4 , const iType5 & i5 ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP,i1,i2,i3,i4,i5) ]; }

  /** \brief  Query value of a rank 5 array */
  template< typename iTypeP , typename iType1 ,
            typename iType2 , typename iType3 ,
            typename iType4 >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP , const iType1 & i1 ,
                           const iType2 & i2 , const iType3 & i3 ,
                           const iType4 & i4 ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP,i1,i2,i3,i4) ]; }

  /** \brief  Query value of a rank 4 array */
  template< typename iTypeP , typename iType1 ,
            typename iType2 , typename iType3 >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP , const iType1 & i1 ,
                           const iType2 & i2 , const iType3 & i3 ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP,i1,i2,i3) ]; }

  /** \brief  Query value of a rank 3 array */
  template< typename iTypeP , typename iType1 ,
            typename iType2 >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP , const iType1 & i1 ,
                           const iType2 & i2 ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP,i1,i2) ]; }

  /** \brief  Query value of a rank 2 array */
  template< typename iTypeP , typename iType1 >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP , const iType1 & i1 ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP,i1) ]; }

  /** \brief  Query value of a rank 1 array */
  template< typename iTypeP >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  value_type & operator()( const iTypeP & iP ) const
  { return m_memory.ptr_on_device()[ m_map.offset(iP) ]; }

  /*------------------------------------------------------------------*/

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<8> & , const size_type iP ,
               const value_type & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
    for ( size_type i5 = 0 ; i5 < dimension(5) ; ++i5 ) {
    for ( size_type i6 = 0 ; i6 < dimension(6) ; ++i6 ) {
    for ( size_type i7 = 0 ; i7 < dimension(7) ; ++i7 ) {
      operator()(iP,i1,i2,i3,i4,i5,i6,i7) = src ;
    }}}}}}}
  }

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<7> & , const size_type iP ,
               const value_type & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
    for ( size_type i5 = 0 ; i5 < dimension(5) ; ++i5 ) {
    for ( size_type i6 = 0 ; i6 < dimension(6) ; ++i6 ) {
      operator()(iP,i1,i2,i3,i4,i5,i6) = src ;
    }}}}}}
  }

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<6> & , const size_type iP ,
               const value_type & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
    for ( size_type i5 = 0 ; i5 < dimension(5) ; ++i5 ) {
      operator()(iP,i1,i2,i3,i4,i5) = src ;
    }}}}}
  }

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<5> & , const size_type iP ,
               const value_type & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
      operator()(iP,i1,i2,i3,i4) = src ;
    }}}}
  }

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<4> & , const size_type iP ,
               const value_type & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
      operator()(iP,i1,i2,i3) = src ;
    }}}
  }

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<3> & , const size_type iP ,
               const value_type & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
      operator()(iP,i1,i2) = src ;
    }}
  }

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<2> & , const size_type iP ,
               const value_type & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
      operator()(iP,i1) = src ;
    }
  }

  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void fill( const Impl::Rank<1> & , const size_type iP ,
               const value_type & src ) const
  {
    operator()(iP) = src ;
  }

  /*------------------------------------------------------------------*/
  /*------------------------------------------------------------------*/

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<8> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
    for ( size_type i5 = 0 ; i5 < dimension(5) ; ++i5 ) {
    for ( size_type i6 = 0 ; i6 < dimension(6) ; ++i6 ) {
    for ( size_type i7 = 0 ; i7 < dimension(7) ; ++i7 ) {
      operator()(iP,i1,i2,i3,i4,i5,i6,i7) = src(iP,i1,i2,i3,i4,i5,i6,i7);
    }}}}}}}
  }

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<7> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
    for ( size_type i5 = 0 ; i5 < dimension(5) ; ++i5 ) {
    for ( size_type i6 = 0 ; i6 < dimension(6) ; ++i6 ) {
      operator()(iP,i1,i2,i3,i4,i5,i6) = src(iP,i1,i2,i3,i4,i5,i6);
    }}}}}}
  }

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<6> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
    for ( size_type i5 = 0 ; i5 < dimension(5) ; ++i5 ) {
      operator()(iP,i1,i2,i3,i4,i5) = src(iP,i1,i2,i3,i4,i5);
    }}}}}
  }

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<5> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
    for ( size_type i4 = 0 ; i4 < dimension(4) ; ++i4 ) {
      operator()(iP,i1,i2,i3,i4) = src(iP,i1,i2,i3,i4);
    }}}}
  }

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<4> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
    for ( size_type i3 = 0 ; i3 < dimension(3) ; ++i3 ) {
      operator()(iP,i1,i2,i3) = src(iP,i1,i2,i3);
    }}}
  }

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<3> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
    for ( size_type i2 = 0 ; i2 < dimension(2) ; ++i2 ) {
      operator()(iP,i1,i2) = src(iP,i1,i2);
    }}
  }

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<2> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    for ( size_type i1 = 0 ; i1 < dimension(1) ; ++i1 ) {
      operator()(iP,i1) = src(iP,i1);
    }
  }

  template< class DeviceSrc >
  inline
  KOKKOS_MACRO_DEVICE_FUNCTION
  void assign( const Impl::Rank<1> & , const size_type iP ,
               const MDArray< value_type , DeviceSrc > & src ) const
  {
    operator()(iP) = src(iP);
  }

  /*------------------------------------------------------------------*/

#endif /* defined( KOKKOS_MACRO_DEVICE_FUNCTION ) */

  /*------------------------------------------------------------------*/
  /** \brief  Construct a NULL view */
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  MDArray() : m_memory(), m_map() {}

  /** \brief  Construct a view of the array */
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  MDArray( const MDArray & rhs )
    : m_memory( rhs.m_memory ), m_map( rhs.m_map ) {}

  /** \brief  Assign to a view of the rhs array.
   *          If the old view is the last view
   *          then allocated memory is deallocated.
   */
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  MDArray & operator = ( const MDArray & rhs )
    {
      m_memory.operator=( rhs.m_memory );
      m_map   .operator=( rhs.m_map );
      return *this ;
    }

  /**  \brief  Destroy this view of the array.
   *           If the last view then allocated memory is deallocated.
   */
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  ~MDArray() {}

  /*------------------------------------------------------------------*/
  /** \brief  Assign view if memory space and map are compatible.
   *          Intended use is to optimize mirroring by eliminating
   *          unnecessary deep copies.
   */
  template< class DeviceRHS >
  inline
  explicit
  MDArray( const MDArray< value_type , DeviceRHS > & rhs )
    : m_memory( rhs.m_memory )
    , m_map( rhs.m_map.dimension(0), rhs.m_map.dimension(1),
             rhs.m_map.dimension(2), rhs.m_map.dimension(3),
             rhs.m_map.dimension(4), rhs.m_map.dimension(5),
             rhs.m_map.dimension(6), rhs.m_map.dimension(7) )
  {
    typedef typename DeviceRHS::mdarray_map rhs_mdarray_map ;

    enum { SameMap = Impl::SameType< mdarray_map , rhs_mdarray_map >::value };

    Impl::StaticAssert< SameMap >::ok();
  }
  /*------------------------------------------------------------------*/
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  operator bool () const
  { return m_memory.operator bool(); }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  bool operator == ( const MDArray & rhs ) const
  { return m_memory.operator == ( rhs.m_memory ); }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  bool operator != ( const MDArray & rhs ) const
  { return m_memory.operator != ( rhs.m_memory ); }

  /*------------------------------------------------------------------*/
  template< class DeviceRHS >
  inline
  bool operator == ( const MDArray< value_type , DeviceRHS > & rhs ) const
  { return m_memory.operator == ( rhs.m_memory ); }

  template< class DeviceRHS >
  inline
  bool operator != ( const MDArray< value_type , DeviceRHS > & rhs ) const
  { return m_memory.operator != ( rhs.m_memory ); }

  /*------------------------------------------------------------------*/

private:

  typedef typename device_type::memory_space  memory_space ;
  typedef Impl::MemoryView< value_type , memory_space >  memory_view ;

  memory_view  m_memory ;
  mdarray_map  m_map ;

  inline
  MDArray( const std::string & label ,
           size_t nP , size_t n1 , size_t n2 , size_t n3 ,
           size_t n4 , size_t n5 , size_t n6 , size_t n7 )
    : m_memory()
    , m_map()
    {
      m_map.template assign<value_type>(nP,n1,n2,n3,n4,n5,n6,n7);
      m_memory.allocate( m_map.allocation_size() , label );

      Impl::Initialize< MDArray<value_type,device_type> >::run( *this );
    }

  template< typename V , class D >
  friend
  MDArray< V , D >
  create_labeled_mdarray( const std::string & label ,
                          size_t nP , size_t n1 , size_t n2 , size_t n3 ,
                          size_t n4 , size_t n5 , size_t n6 , size_t n7 );

  template< typename V , class D > friend class MDArray ;
  template< class Dst , class Src > friend class Impl::DeepCopy ;
};

//----------------------------------------------------------------------------

} // namespace Kokkos

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif

