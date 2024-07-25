// @HEADER
// *****************************************************************************
//             Xpetra: A linear algebra interface package
//
// Copyright 2012 NTESS and the Xpetra contributors.
// SPDX-License-Identifier: BSD-3-Clause
// *****************************************************************************
// @HEADER

#ifndef XPETRA_ROWMATRIX_HPP
#define XPETRA_ROWMATRIX_HPP

/* this file is automatically generated - do not edit (see script/interfaces.py) */

// WARNING: This code is experimental. Backwards compatibility should not be expected.

#include <Teuchos_Describable.hpp>
#include <Tpetra_KokkosCompat_DefaultNode.hpp>
#include "Xpetra_ConfigDefs.hpp"
#include "Xpetra_Map.hpp"
#include "Xpetra_Operator.hpp"
#include "Xpetra_Vector.hpp"

namespace Xpetra {

template <class Scalar,
          class LocalOrdinal,
          class GlobalOrdinal,
          class Node = Tpetra::KokkosClassic::DefaultNode::DefaultNodeType>
class RowMatrix : virtual public Operator<Scalar, LocalOrdinal, GlobalOrdinal, Node> {
 public:
  typedef Scalar scalar_type;
  typedef LocalOrdinal local_ordinal_type;
  typedef GlobalOrdinal global_ordinal_type;
  typedef Node node_type;

  //! @name Constructor/Destructor Methods
  //@{

  //! Destructor.
  virtual ~RowMatrix() {}

  //@}

  //! @name Matrix Query Methods
  //@{

  //! Returns the Map that describes the row distribution in this matrix.
  virtual const Teuchos::RCP<const Map<LocalOrdinal, GlobalOrdinal, Node> > getRowMap() const = 0;

  //! Returns the Map that describes the column distribution in this matrix.
  virtual const Teuchos::RCP<const Map<LocalOrdinal, GlobalOrdinal, Node> > getColMap() const = 0;

  //! Returns the number of global rows in this matrix.
  virtual global_size_t getGlobalNumRows() const = 0;

  //! Returns the number of global columns in this matrix.
  virtual global_size_t getGlobalNumCols() const = 0;

  //! Returns the number of rows owned on the calling node.
  virtual size_t getLocalNumRows() const = 0;

  //! Returns the number of columns needed to apply the forward operator on this node, i.e., the number of elements listed in the column map.
  virtual size_t getLocalNumCols() const = 0;

  //! Returns the global number of entries in this matrix.
  virtual global_size_t getGlobalNumEntries() const = 0;

  //! Returns the local number of entries in this matrix.
  virtual size_t getLocalNumEntries() const = 0;

  //! Returns the current number of entries on this node in the specified local row.
  virtual size_t getNumEntriesInLocalRow(LocalOrdinal localRow) const = 0;

  //! Returns the maximum number of entries across all rows/columns on all nodes.
  virtual size_t getGlobalMaxNumRowEntries() const = 0;

  //! Returns the maximum number of entries across all rows/columns on this node.
  virtual size_t getLocalMaxNumRowEntries() const = 0;

  //! If matrix indices are in the local range, this function returns true. Otherwise, this function returns false. */.
  virtual bool isLocallyIndexed() const = 0;

  //! If matrix indices are in the global range, this function returns true. Otherwise, this function returns false. */.
  virtual bool isGloballyIndexed() const = 0;

  //! Returns true if fillComplete() has been called.
  virtual bool isFillComplete() const = 0;

  //! Returns true if getLocalRowView() and getGlobalRowView() are valid for this class.
  virtual bool supportsRowViews() const = 0;

  //@}

  //! @name Extraction Methods
  //@{

  //! Extract a list of entries in a specified local row of the graph. Put into storage allocated by calling routine.
  virtual void getLocalRowCopy(LocalOrdinal LocalRow, const Teuchos::ArrayView<LocalOrdinal> &Indices, const Teuchos::ArrayView<Scalar> &Values, size_t &NumEntries) const = 0;

  //! Extract a const, non-persisting view of global indices in a specified row of the matrix.
  virtual void getGlobalRowView(GlobalOrdinal GlobalRow, ArrayView<const GlobalOrdinal> &indices, ArrayView<const Scalar> &values) const = 0;

  //! Extract a const, non-persisting view of local indices in a specified row of the matrix.
  virtual void getLocalRowView(LocalOrdinal LocalRow, ArrayView<const LocalOrdinal> &indices, ArrayView<const Scalar> &values) const = 0;

  //! Get a copy of the diagonal entries owned by this node, with local row indices.
  virtual void getLocalDiagCopy(Vector<Scalar, LocalOrdinal, GlobalOrdinal, Node> &diag) const = 0;

  //@}

  //! @name Mathematical Methods
  //@{

  //! Returns the Frobenius norm of the matrix.
  virtual typename ScalarTraits<Scalar>::magnitudeType getFrobeniusNorm() const = 0;

  //@}

  //! @name Pure virtual functions to be overridden by subclasses.
  //@{

  //! Returns the Map associated with the domain of this operator, which must be compatible with X.getMap().
  virtual const Teuchos::RCP<const Map<LocalOrdinal, GlobalOrdinal, Node> > getDomainMap() const = 0;

  //! Returns the Map associated with the range of this operator, which must be compatible with Y.getMap().
  virtual const Teuchos::RCP<const Map<LocalOrdinal, GlobalOrdinal, Node> > getRangeMap() const = 0;

  //! Computes the operator-multivector application.
  virtual void apply(const MultiVector<Scalar, LocalOrdinal, GlobalOrdinal, Node> &X, MultiVector<Scalar, LocalOrdinal, GlobalOrdinal, Node> &Y, Teuchos::ETransp mode = Teuchos::NO_TRANS, Scalar alpha = Teuchos::ScalarTraits<Scalar>::one(), Scalar beta = Teuchos::ScalarTraits<Scalar>::zero()) const = 0;

  //@}

};  // RowMatrix class

}  // namespace Xpetra

#define XPETRA_ROWMATRIX_SHORT
#endif  // XPETRA_ROWMATRIX_HPP
