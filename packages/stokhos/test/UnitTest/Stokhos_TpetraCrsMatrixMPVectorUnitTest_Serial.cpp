// @HEADER
// *****************************************************************************
//                           Stokhos Package
//
// Copyright 2009 NTESS and the Stokhos contributors.
// SPDX-License-Identifier: BSD-3-Clause
// *****************************************************************************
// @HEADER

#include "Teuchos_UnitTestHarness.hpp"
#include "Teuchos_UnitTestRepository.hpp"
#include "Teuchos_GlobalMPISession.hpp"

#include "Stokhos_TpetraCrsMatrixMPVectorUnitTest.hpp"

#include "Kokkos_Core.hpp"
#include <Tpetra_KokkosCompat_ClassicNodeAPI_Wrapper.hpp>

// Instantiate tests for serial node
typedef Tpetra::KokkosCompat::KokkosDeviceWrapperNode<Kokkos::Serial> SerialWrapperNode;
CRSMATRIX_MP_VECTOR_TESTS_N( SerialWrapperNode )

int main( int argc, char* argv[] ) {
  Teuchos::GlobalMPISession mpiSession(&argc, &argv);

  Kokkos::global_sacado_mp_vector_size = VectorSize;

  // Initialize serial
  Kokkos::initialize();

  // Run tests
  Teuchos::UnitTestRepository::setGloballyReduceTestResult(true);
  int ret = Teuchos::UnitTestRepository::runUnitTestsFromMain(argc, argv);

  // Finish up
  Kokkos::finalize();

  return ret;
}
