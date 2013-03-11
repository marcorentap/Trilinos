// @HEADER
//
// ***********************************************************************
//
//             Xpetra: A linear algebra interface package
//                  Copyright 2012 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
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
// Questions? Contact
//                    Jeremie Gaidamour (jngaida@sandia.gov)
//                    Jonathan Hu       (jhu@sandia.gov)
//                    Ray Tuminaro      (rstumin@sandia.gov)
//
// ***********************************************************************
//
// @HEADER
#ifndef XPETRA_TPETRACRSMATRIX_HPP
#define XPETRA_TPETRACRSMATRIX_HPP

/* this file is automatically generated - do not edit (see script/tpetra.py) */

#include "Xpetra_TpetraConfigDefs.hpp"

#include "Tpetra_CrsMatrix.hpp"

#include "Xpetra_CrsMatrix.hpp"
#include "Xpetra_TpetraMap.hpp"
#include "Xpetra_TpetraMultiVector.hpp"
#include "Xpetra_TpetraVector.hpp"
#include "Xpetra_TpetraCrsGraph.hpp"
//#include "Xpetra_TpetraRowMatrix.hpp"
#include "Xpetra_Exceptions.hpp"

namespace Xpetra {

  // TODO: move that elsewhere
  // template <class Scalar, class LocalOrdinal, class GlobalOrdinal, class Node, class LocalMatOps>
  // const Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> toTpetraCrsMatrix(const Xpetra::DistObject<char, LocalOrdinal, GlobalOrdinal, Node> &);
  //

  template <class Scalar, class LocalOrdinal = int, class GlobalOrdinal = LocalOrdinal, class Node = Kokkos::DefaultNode::DefaultNodeType, class LocalMatOps = typename Kokkos::DefaultKernels<Scalar,LocalOrdinal,Node>::SparseOps>
  class TpetraCrsMatrix
    : public CrsMatrix<Scalar,LocalOrdinal,GlobalOrdinal,Node,LocalMatOps>//, public TpetraRowMatrix<Scalar,LocalOrdinal,GlobalOrdinal,Node>
  {

    // The following typedef are used by the XPETRA_DYNAMIC_CAST() macro.
    typedef TpetraCrsMatrix<Scalar,LocalOrdinal,GlobalOrdinal,Node,LocalMatOps> TpetraCrsMatrixClass;
    typedef TpetraVector<Scalar,LocalOrdinal,GlobalOrdinal,Node> TpetraVectorClass;
    typedef TpetraImport<LocalOrdinal,GlobalOrdinal,Node> TpetraImportClass;

  public:

    //! @name Constructor/Destructor Methods
    //@{

    //! Constructor specifying fixed number of entries for each row.
    TpetraCrsMatrix(const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &rowMap, size_t maxNumEntriesPerRow, ProfileType pftype=DynamicProfile, const Teuchos::RCP< Teuchos::ParameterList > &params=Teuchos::null)
      : mtx_(Teuchos::rcp(new Tpetra::CrsMatrix< Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps >(toTpetra(rowMap), maxNumEntriesPerRow, toTpetra(pftype), params))) {  }

    //! Constructor specifying (possibly different) number of entries in each row.
    TpetraCrsMatrix(const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &rowMap, const ArrayRCP< const size_t > &NumEntriesPerRowToAlloc, ProfileType pftype=DynamicProfile, const Teuchos::RCP< Teuchos::ParameterList > &params=Teuchos::null)
      : mtx_(Teuchos::rcp(new Tpetra::CrsMatrix< Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps >(toTpetra(rowMap), NumEntriesPerRowToAlloc, toTpetra(pftype), params))) {  }

    //! Constructor specifying column Map and fixed number of entries for each row.
    TpetraCrsMatrix(const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &rowMap, const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &colMap, size_t maxNumEntriesPerRow, ProfileType pftype=DynamicProfile, const Teuchos::RCP< Teuchos::ParameterList > &params=Teuchos::null)
      : mtx_(Teuchos::rcp(new Tpetra::CrsMatrix< Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps >(toTpetra(rowMap), toTpetra(colMap), maxNumEntriesPerRow, toTpetra(pftype), params))) {  }

    //! Constructor specifying column Map and number of entries in each row.
    TpetraCrsMatrix(const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &rowMap, const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &colMap, const ArrayRCP< const size_t > &NumEntriesPerRowToAlloc, ProfileType pftype=DynamicProfile, const Teuchos::RCP< Teuchos::ParameterList > &params=Teuchos::null)
      : mtx_(Teuchos::rcp(new Tpetra::CrsMatrix< Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps >(toTpetra(rowMap), toTpetra(colMap), NumEntriesPerRowToAlloc, toTpetra(pftype), params))) {  }

    //! Constructor specifying a previously constructed graph.
    TpetraCrsMatrix(const Teuchos::RCP< const CrsGraph< LocalOrdinal, GlobalOrdinal, Node, LocalMatOps > > &graph, const Teuchos::RCP< Teuchos::ParameterList > &params=Teuchos::null)
      : mtx_(Teuchos::rcp(new Tpetra::CrsMatrix< Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps >(toTpetra(graph), params))) {  }



    //! Constructor for a fused import
    TpetraCrsMatrix(const Teuchos::RCP<const CrsMatrix<Scalar,LocalOrdinal,GlobalOrdinal,Node> >& sourceMatrix,
		    const Import<LocalOrdinal,GlobalOrdinal,Node> & importer,
		    const Teuchos::RCP<const Map<LocalOrdinal,GlobalOrdinal,Node> >& domainMap = Teuchos::null,
		    const Teuchos::RCP<const Map<LocalOrdinal,GlobalOrdinal,Node> >& rangeMap = Teuchos::null,
		    const Teuchos::RCP<Teuchos::ParameterList>& params = Teuchos::null)
    {
      typedef Tpetra::CrsMatrix<Scalar,LocalOrdinal,GlobalOrdinal,Node,LocalMatOps> MyTpetraCrsMatrix;
      XPETRA_DYNAMIC_CAST(const TpetraCrsMatrixClass, *sourceMatrix, tSourceMatrix, "Xpetra::TpetraCrsMatrix constructor only accepts Xpetra::TpetraCrsMatrix as the input argument.");//TODO: remove and use toTpetra()
      RCP< const Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > v = tSourceMatrix.getTpetra_CrsMatrix();

      mtx_=Tpetra::importAndFillCompleteCrsMatrix<MyTpetraCrsMatrix>(tSourceMatrix.getTpetra_CrsMatrix(),toTpetra(importer),toTpetra(domainMap),toTpetra(rangeMap),params);
      
    }
      

    //! Destructor.
    virtual ~TpetraCrsMatrix() {  }

    //@}

    //! @name Insertion/Removal Methods
    //@{

    //! Insert matrix entries, using global IDs.
    void insertGlobalValues(GlobalOrdinal globalRow, const ArrayView< const GlobalOrdinal > &cols, const ArrayView< const Scalar > &vals) { XPETRA_MONITOR("TpetraCrsMatrix::insertGlobalValues"); mtx_->insertGlobalValues(globalRow, cols, vals); }

    //! Insert matrix entries, using local IDs.
    void insertLocalValues(LocalOrdinal localRow, const ArrayView< const LocalOrdinal > &cols, const ArrayView< const Scalar > &vals) { XPETRA_MONITOR("TpetraCrsMatrix::insertLocalValues"); mtx_->insertLocalValues(localRow, cols, vals); }

    //! Replace matrix entries, using global IDs.
    void replaceGlobalValues(GlobalOrdinal globalRow, const ArrayView< const GlobalOrdinal > &cols, const ArrayView< const Scalar > &vals) { XPETRA_MONITOR("TpetraCrsMatrix::replaceGlobalValues"); mtx_->replaceGlobalValues(globalRow, cols, vals); }

    //! Replace matrix entries, using local IDs.
    void replaceLocalValues(LocalOrdinal localRow, const ArrayView< const LocalOrdinal > &cols, const ArrayView< const Scalar > &vals) { XPETRA_MONITOR("TpetraCrsMatrix::replaceLocalValues"); mtx_->replaceLocalValues(localRow, cols, vals); }

    //! Set all matrix entries equal to scalarThis.
    void setAllToScalar(const Scalar &alpha) { XPETRA_MONITOR("TpetraCrsMatrix::setAllToScalar"); mtx_->setAllToScalar(alpha); }

    //! Scale the current values of a matrix, this = alpha*this.
    void scale(const Scalar &alpha) { XPETRA_MONITOR("TpetraCrsMatrix::scale"); mtx_->scale(alpha); }

    //@}

    //! @name Transformational Methods
    //@{

    //!
    void resumeFill(const RCP< ParameterList > &params=null) { XPETRA_MONITOR("TpetraCrsMatrix::resumeFill"); mtx_->resumeFill(params); }

    //! Signal that data entry is complete, specifying domain and range maps.
    void fillComplete(const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &domainMap, const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > &rangeMap, const RCP< ParameterList > &params=null) { XPETRA_MONITOR("TpetraCrsMatrix::fillComplete"); mtx_->fillComplete(toTpetra(domainMap), toTpetra(rangeMap), params); }

    //! Signal that data entry is complete.
    void fillComplete(const RCP< ParameterList > &params=null) { XPETRA_MONITOR("TpetraCrsMatrix::fillComplete"); mtx_->fillComplete(params); }

    
    //!  Replaces the current domainMap and importer with the user-specified objects.
    void replaceDomainMapAndImporter(const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > >& newDomainMap, Teuchos::RCP<const Import<LocalOrdinal,GlobalOrdinal,Node> >  & newImporter) { 
      XPETRA_MONITOR("TpetraCrsMatrix::replaceDomainMapAndImporter"); 
      XPETRA_DYNAMIC_CAST( const TpetraImportClass , *newImporter, tImporter, "Xpetra::EpetraCrsMatrix::replaceDomainMapAndImporter only accepts Xpetra::EpetraImport.");
      RCP<const Tpetra::Import<LocalOrdinal,GlobalOrdinal,Node> > myImport = tImporter.getTpetra_Import();
      //      mtx_->replaceDomainMapAndImporter( toTpetra(newDomainMap),tImporter.getTpetra_Import());
            mtx_->replaceDomainMapAndImporter( toTpetra(newDomainMap),myImport);
    }
    //@}

    //! @name Methods implementing RowMatrix
    //@{

    //! Returns the Map that describes the row distribution in this matrix.
    const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > >  getRowMap() const { XPETRA_MONITOR("TpetraCrsMatrix::getRowMap"); return toXpetra(mtx_->getRowMap()); }

    //! Returns the Map that describes the column distribution in this matrix.
    const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > >  getColMap() const { XPETRA_MONITOR("TpetraCrsMatrix::getColMap"); return toXpetra(mtx_->getColMap()); }

    //! Returns the CrsGraph associated with this matrix.
    RCP< const CrsGraph< LocalOrdinal, GlobalOrdinal, Node, LocalMatOps > > getCrsGraph() const { XPETRA_MONITOR("TpetraCrsMatrix::getCrsGraph"); return toXpetra(mtx_->getCrsGraph()); }

    //! Number of global elements in the row map of this matrix.
    global_size_t getGlobalNumRows() const { XPETRA_MONITOR("TpetraCrsMatrix::getGlobalNumRows"); return mtx_->getGlobalNumRows(); }

    //! Number of global columns in the matrix.
    global_size_t getGlobalNumCols() const { XPETRA_MONITOR("TpetraCrsMatrix::getGlobalNumCols"); return mtx_->getGlobalNumCols(); }

    //! Returns the number of matrix rows owned on the calling node.
    size_t getNodeNumRows() const { XPETRA_MONITOR("TpetraCrsMatrix::getNodeNumRows"); return mtx_->getNodeNumRows(); }

    //! Returns the number of columns connected to the locally owned rows of this matrix.
    size_t getNodeNumCols() const { XPETRA_MONITOR("TpetraCrsMatrix::getNodeNumCols"); return mtx_->getNodeNumCols(); }

    //! Returns the global number of entries in this matrix.
    global_size_t getGlobalNumEntries() const { XPETRA_MONITOR("TpetraCrsMatrix::getGlobalNumEntries"); return mtx_->getGlobalNumEntries(); }

    //! Returns the local number of entries in this matrix.
    size_t getNodeNumEntries() const { XPETRA_MONITOR("TpetraCrsMatrix::getNodeNumEntries"); return mtx_->getNodeNumEntries(); }

    //! Returns the current number of entries on this node in the specified local row.
    size_t getNumEntriesInLocalRow(LocalOrdinal localRow) const { XPETRA_MONITOR("TpetraCrsMatrix::getNumEntriesInLocalRow"); return mtx_->getNumEntriesInLocalRow(localRow); }

    //! Returns the number of global diagonal entries, based on global row/column index comparisons.
    global_size_t getGlobalNumDiags() const { XPETRA_MONITOR("TpetraCrsMatrix::getGlobalNumDiags"); return mtx_->getGlobalNumDiags(); }

    //! Returns the number of local diagonal entries, based on global row/column index comparisons.
    size_t getNodeNumDiags() const { XPETRA_MONITOR("TpetraCrsMatrix::getNodeNumDiags"); return mtx_->getNodeNumDiags(); }

    //! Returns the maximum number of entries across all rows/columns on all nodes.
    size_t getGlobalMaxNumRowEntries() const { XPETRA_MONITOR("TpetraCrsMatrix::getGlobalMaxNumRowEntries"); return mtx_->getGlobalMaxNumRowEntries(); }

    //! Returns the maximum number of entries across all rows/columns on this node.
    size_t getNodeMaxNumRowEntries() const { XPETRA_MONITOR("TpetraCrsMatrix::getNodeMaxNumRowEntries"); return mtx_->getNodeMaxNumRowEntries(); }

    //! If matrix indices are in the local range, this function returns true. Otherwise, this function returns false.
    bool isLocallyIndexed() const { XPETRA_MONITOR("TpetraCrsMatrix::isLocallyIndexed"); return mtx_->isLocallyIndexed(); }

    //! If matrix indices are in the global range, this function returns true. Otherwise, this function returns false.
    bool isGloballyIndexed() const { XPETRA_MONITOR("TpetraCrsMatrix::isGloballyIndexed"); return mtx_->isGloballyIndexed(); }

    //! Returns true if the matrix is in compute mode, i.e. if fillComplete() has been called.
    bool isFillComplete() const { XPETRA_MONITOR("TpetraCrsMatrix::isFillComplete"); return mtx_->isFillComplete(); }

    //! Returns true if the matrix is in edit mode.
    bool isFillActive() const { XPETRA_MONITOR("TpetraCrsMatrix::isFillActive"); return mtx_->isFillActive(); }

    //! Returns the Frobenius norm of the matrix.
    typename ScalarTraits< Scalar >::magnitudeType getFrobeniusNorm() const { XPETRA_MONITOR("TpetraCrsMatrix::getFrobeniusNorm"); return mtx_->getFrobeniusNorm(); }

    //! Returns true if getLocalRowView() and getGlobalRowView() are valid for this class.
    bool supportsRowViews() const { XPETRA_MONITOR("TpetraCrsMatrix::supportsRowViews"); return mtx_->supportsRowViews(); }

    //! Extract a list of entries in a specified local row of the matrix. Put into storage allocated by calling routine.
    void getLocalRowCopy(LocalOrdinal LocalRow, const ArrayView< LocalOrdinal > &Indices, const ArrayView< Scalar > &Values, size_t &NumEntries) const { XPETRA_MONITOR("TpetraCrsMatrix::getLocalRowCopy"); mtx_->getLocalRowCopy(LocalRow, Indices, Values, NumEntries); }

    //! Extract a const, non-persisting view of global indices in a specified row of the matrix.
    void getGlobalRowView(GlobalOrdinal GlobalRow, ArrayView< const GlobalOrdinal > &indices, ArrayView< const Scalar > &values) const { XPETRA_MONITOR("TpetraCrsMatrix::getGlobalRowView"); mtx_->getGlobalRowView(GlobalRow, indices, values); }

    //! Extract a const, non-persisting view of local indices in a specified row of the matrix.
    void getLocalRowView(LocalOrdinal LocalRow, ArrayView< const LocalOrdinal > &indices, ArrayView< const Scalar > &values) const { XPETRA_MONITOR("TpetraCrsMatrix::getLocalRowView"); mtx_->getLocalRowView(LocalRow, indices, values); }

    //@}

    //! @name Methods implementing Operator
    //@{

    //! Computes the sparse matrix-multivector multiplication.
    void apply(const MultiVector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &X, MultiVector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &Y, Teuchos::ETransp mode=Teuchos::NO_TRANS, Scalar alpha=ScalarTraits< Scalar >::one(), Scalar beta=ScalarTraits< Scalar >::zero()) const { XPETRA_MONITOR("TpetraCrsMatrix::apply"); mtx_->apply(toTpetra(X), toTpetra(Y), mode, alpha, beta); }

    //! Returns the Map associated with the domain of this operator. This will be null until fillComplete() is called.
    const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > >  getDomainMap() const { XPETRA_MONITOR("TpetraCrsMatrix::getDomainMap"); return toXpetra(mtx_->getDomainMap()); }

    //!
    const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > >  getRangeMap() const { XPETRA_MONITOR("TpetraCrsMatrix::getRangeMap"); return toXpetra(mtx_->getRangeMap()); }

    //@}

    //! @name Overridden from Teuchos::Describable
    //@{

    //! A simple one-line description of this object.
    std::string description() const { XPETRA_MONITOR("TpetraCrsMatrix::description"); return mtx_->description(); }

    //! Print the object with some verbosity level to an FancyOStream object.
    void describe(Teuchos::FancyOStream &out, const Teuchos::EVerbosityLevel verbLevel=Teuchos::Describable::verbLevel_default) const { XPETRA_MONITOR("TpetraCrsMatrix::describe"); mtx_->describe(out, verbLevel); }

    //@}

#ifdef HAVE_XPETRA_EXPERIMENTAL
    //! Deep copy constructor
    TpetraCrsMatrix(const TpetraCrsMatrix& matrix)
    : mtx_(matrix.mtx_->template convert<Scalar>()) {
    }
#endif


    //! Get a copy of the diagonal entries owned by this node, with local row idices.
    void getLocalDiagCopy(Vector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &diag) const {
      XPETRA_MONITOR("TpetraCrsMatrix::getLocalDiagCopy");
      XPETRA_DYNAMIC_CAST(TpetraVectorClass, diag, tDiag, "Xpetra::TpetraCrsMatrix.getLocalDiagCopy() only accept Xpetra::TpetraVector as input arguments.");
      mtx_->getLocalDiagCopy(*tDiag.getTpetra_Vector());
      // mtx_->getLocalDiagCopy(toTpetra(diag));
    }

    //! Implements DistObject interface
    //{@

    //! Access function for the Tpetra::Map this DistObject was constructed with.
    const Teuchos::RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > > getMap() const { XPETRA_MONITOR("TpetraCrsMatrix::getMap"); return rcp( new TpetraMap< LocalOrdinal, GlobalOrdinal, Node >(mtx_->getMap()) ); }

    //! Import.
    void doImport(const DistObject<char, LocalOrdinal, GlobalOrdinal, Node> &source,
                  const Import< LocalOrdinal, GlobalOrdinal, Node > &importer, CombineMode CM) {
      XPETRA_MONITOR("TpetraCrsMatrix::doImport");

      XPETRA_DYNAMIC_CAST(const TpetraCrsMatrixClass, source, tSource, "Xpetra::TpetraCrsMatrix::doImport only accept Xpetra::TpetraCrsMatrix as input arguments.");//TODO: remove and use toTpetra()
      RCP< const Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > v = tSource.getTpetra_CrsMatrix();
      //mtx_->doImport(toTpetraCrsMatrix(source), *tImporter.getTpetra_Import(), toTpetra(CM));
      mtx_->doImport(*v, toTpetra(importer), toTpetra(CM));
    }

    //! Export.
    void doExport(const DistObject<char, LocalOrdinal, GlobalOrdinal, Node> &dest,
                  const Import< LocalOrdinal, GlobalOrdinal, Node >& importer, CombineMode CM) {
      XPETRA_MONITOR("TpetraCrsMatrix::doExport");

      XPETRA_DYNAMIC_CAST(const TpetraCrsMatrixClass, dest, tDest, "Xpetra::TpetraCrsMatrix::doImport only accept Xpetra::TpetraCrsMatrix as input arguments.");//TODO: remove and use toTpetra()
      RCP< const Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > v = tDest.getTpetra_CrsMatrix();
      mtx_->doExport(*v, toTpetra(importer), toTpetra(CM));

    }

    //! Import (using an Exporter).
    void doImport(const DistObject<char, LocalOrdinal, GlobalOrdinal, Node> &source,
                  const Export< LocalOrdinal, GlobalOrdinal, Node >& exporter, CombineMode CM) {
      XPETRA_MONITOR("TpetraCrsMatrix::doImport");

      XPETRA_DYNAMIC_CAST(const TpetraCrsMatrixClass, source, tSource, "Xpetra::TpetraCrsMatrix::doImport only accept Xpetra::TpetraCrsMatrix as input arguments.");//TODO: remove and use toTpetra()
      RCP< const Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > v = tSource.getTpetra_CrsMatrix();
      mtx_->doImport(*v, toTpetra(exporter), toTpetra(CM));

    }

    //! Export (using an Importer).
    void doExport(const DistObject<char, LocalOrdinal, GlobalOrdinal, Node> &dest,
                  const Export< LocalOrdinal, GlobalOrdinal, Node >& exporter, CombineMode CM) {
      XPETRA_MONITOR("TpetraCrsMatrix::doExport");

      XPETRA_DYNAMIC_CAST(const TpetraCrsMatrixClass, dest, tDest, "Xpetra::TpetraCrsMatrix::doImport only accept Xpetra::TpetraCrsMatrix as input arguments.");//TODO: remove and use toTpetra()
      RCP< const Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > v = tDest.getTpetra_CrsMatrix();
      mtx_->doExport(*v, toTpetra(exporter), toTpetra(CM));

    }

    // @}

    //! @name Xpetra specific
    //@{

    //! TpetraCrsMatrix constructor to wrap a Tpetra::CrsMatrix object
    TpetraCrsMatrix(const Teuchos::RCP<Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > &mtx) : mtx_(mtx) {  }

    //! Get the underlying Tpetra matrix
    RCP<const Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > getTpetra_CrsMatrix() const { return mtx_; }

    //! Get the underlying Tpetra matrix
    RCP<Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > getTpetra_CrsMatrixNonConst() const { return mtx_; } //TODO: remove

   //@}

  private:

    RCP< Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> > mtx_;

  }; // TpetraCrsMatrix class

  // TODO: move that elsewhere
  // template <class Scalar, class LocalOrdinal, class GlobalOrdinal, class Node, class LocalMatOps>
  // const Tpetra::DistObject<char, LocalOrdinal, GlobalOrdinal, Node> toTpetraCrsMatrix(const DistObject<char, LocalOrdinal, GlobalOrdinal, Node> &mtx) {
  //   typedef TpetraCrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node, LocalMatOps> TpetraCrsMatrixClass;
  //   XPETRA_DYNAMIC_CAST(const TpetraCrsMatrixClass, mtx, tMtx, "toTpetra");
  //   return *tMtx.getTpetra_CrsMatrix();
  // }
  //

} // Xpetra namespace

#define XPETRA_TPETRACRSMATRIX_SHORT
#endif // XPETRA_TPETRACRSMATRIX_HPP
