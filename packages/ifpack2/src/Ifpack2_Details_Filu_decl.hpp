// @HEADER
// *****************************************************************************
//       Ifpack2: Templated Object-Oriented Algebraic Preconditioner Package
//
// Copyright 2009 NTESS and the Ifpack2 contributors.
// SPDX-License-Identifier: BSD-3-Clause
// *****************************************************************************
// @HEADER

/// @file Ifpack2_filu_decl.hpp

#ifndef __IFPACK2_FILU_DECL_HPP__ 
#define __IFPACK2_FILU_DECL_HPP__ 

#include <Ifpack2_Details_FastILU_Base.hpp>

//forward-declare the local preconditioner type
template<typename LocalOrdinal, typename Scalar, typename execution_space, bool BlockCrsEnabled>
class FastILUPrec;

namespace Ifpack2
{
namespace Details
{

/// \class Filu
/// \brief The Ifpack2 wrapper to the ILU preconditioner of ShyLU FastILU.
template<typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node, bool BlockCrsEnabled>
class Filu : public FastILU_Base<Scalar, LocalOrdinal, GlobalOrdinal, Node>
{
  public:
    typedef FastILU_Base<Scalar, LocalOrdinal, GlobalOrdinal, Node> Base;
    typedef typename Base::TRowMatrix TRowMatrix;
    typedef typename Base::ImplScalar ImplScalar;
    typedef typename Base::ImplScalarArray ImplScalarArray;
    typedef FastILUPrec<LocalOrdinal, ImplScalar, typename Base::execution_space, BlockCrsEnabled> LocalFILU;

    //! Constructor
    Filu(Teuchos::RCP<const TRowMatrix> mat_);

    //! Get the sweeps (\"nFact\") from localPrec_
    int getSweeps() const;

    //! Get the name of triangular solve algorithm
    std::string getSpTrsvType() const;

    //! Get the number of triangular solves (\"nTrisol\") from localPrec_
    int getNTrisol() const;

    //! Verify and print debug info about the internal ILU preconditioner
    void checkLocalILU() const;

    //! Verify and print debug info about the internal IC preconditioner
    void checkLocalIC() const;

  protected:
    mutable Teuchos::RCP<LocalFILU> localPrec_;

    void initLocalPrec();
    //compute() takes A's local values
    void computeLocalPrec();
    void applyLocalPrec(ImplScalarArray x, ImplScalarArray y) const;
    std::string getName() const;
};

} //namespace Details
} //namespace Ifpack2

#endif

