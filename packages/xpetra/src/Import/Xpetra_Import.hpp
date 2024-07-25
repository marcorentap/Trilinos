// @HEADER
// *****************************************************************************
//             Xpetra: A linear algebra interface package
//
// Copyright 2012 NTESS and the Xpetra contributors.
// SPDX-License-Identifier: BSD-3-Clause
// *****************************************************************************
// @HEADER

#ifndef XPETRA_IMPORT_HPP
#define XPETRA_IMPORT_HPP

/* this file is automatically generated - do not edit (see script/interfaces.py) */

#include <Tpetra_KokkosCompat_DefaultNode.hpp>
#include <Teuchos_Describable.hpp>
#include <Teuchos_as.hpp>
#include "Xpetra_Map.hpp"
#include <iterator>

namespace Xpetra {

template <class LocalOrdinal,
          class GlobalOrdinal,
          class Node = Tpetra::KokkosClassic::DefaultNode::DefaultNodeType>
class Import
  : public Teuchos::Describable {
 public:
  typedef LocalOrdinal local_ordinal_type;
  typedef GlobalOrdinal global_ordinal_type;
  typedef Node node_type;
  typedef Map<LocalOrdinal, GlobalOrdinal, Node> map_type;

  //! @name Constructor/Destructor Methods
  //@{

  //! Destructor.
  virtual ~Import() {}

  //! Special "constructor"
  virtual Teuchos::RCP<const Import<LocalOrdinal, GlobalOrdinal, Node> >
  createRemoteOnlyImport(const Teuchos::RCP<const map_type>& remoteTarget) const = 0;

  //@}

  //! @name Import Attribute Methods
  //@{

  //! Number of initial identical IDs.
  virtual size_t getNumSameIDs() const = 0;

  //! Number of IDs to permute but not to communicate.
  virtual size_t getNumPermuteIDs() const = 0;

  //! List of local IDs in the source Map that are permuted.
  virtual ArrayView<const LocalOrdinal> getPermuteFromLIDs() const = 0;

  //! List of local IDs in the target Map that are permuted.
  virtual ArrayView<const LocalOrdinal> getPermuteToLIDs() const = 0;

  //! Number of entries not on the calling process.
  virtual size_t getNumRemoteIDs() const = 0;

  //! List of entries in the target Map to receive from other processes.
  virtual ArrayView<const LocalOrdinal> getRemoteLIDs() const = 0;

  //! Number of entries that must be sent by the calling process to other processes.
  virtual size_t getNumExportIDs() const = 0;

  //! List of entries in the source Map that will be sent to other processes.
  virtual ArrayView<const LocalOrdinal> getExportLIDs() const = 0;

  //! List of processes to which entries will be sent.
  virtual ArrayView<const int> getExportPIDs() const = 0;

  //! The Source Map used to construct this Import object.
  virtual Teuchos::RCP<const Map<LocalOrdinal, GlobalOrdinal, Node> > getSourceMap() const = 0;

  //! The Target Map used to construct this Import object.
  virtual Teuchos::RCP<const Map<LocalOrdinal, GlobalOrdinal, Node> > getTargetMap() const = 0;

  //! Set parameters on the underlying object
  virtual void setDistributorParameters(const Teuchos::RCP<Teuchos::ParameterList> params) const = 0;

  //@}

  //! @name I/O Methods
  //@{

  //! Print the Import's data to the given output stream.
  virtual void print(std::ostream& os) const = 0;

  //@}

};  // Import class

}  // namespace Xpetra

#define XPETRA_IMPORT_SHORT
#endif  // XPETRA_IMPORT_HPP
