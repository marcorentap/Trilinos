// @HEADER
// *****************************************************************************
//        MueLu: A package for multigrid based preconditioning
//
// Copyright 2012 NTESS and the MueLu contributors.
// SPDX-License-Identifier: BSD-3-Clause
// *****************************************************************************
// @HEADER

/*
 * ThresholdAFilterFactory.cpp
 *
 *  Created on: 16.10.2011
 *      Author: tobias
 */

#include <Teuchos_UnitTestHarness.hpp>
#include <MueLu_config.hpp>
#include <MueLu_ConfigDefs.hpp>
#include <MueLu_Version.hpp>

#include <MueLu_Utilities.hpp>

#include <MueLu_NoFactory.hpp>

#include <MueLu_TestHelpers.hpp>

#include <MueLu_Level.hpp>
#include <MueLu_ThresholdAFilterFactory.hpp>

namespace MueLuTests {

TEUCHOS_UNIT_TEST_TEMPLATE_4_DECL(ThresholdAFilterFactory, Basic, Scalar, LocalOrdinal, GlobalOrdinal, Node) {
#include <MueLu_UseShortNames.hpp>
  MUELU_TESTING_SET_OSTREAM;
  MUELU_TESTING_LIMIT_SCOPE(Scalar, GlobalOrdinal, Node);
  out << "version: " << MueLu::Version() << std::endl;

  Level aLevel;
  TestHelpers::TestFactory<SC, LO, GO, NO>::createSingleLevelHierarchy(aLevel);

  RCP<Matrix> A = TestHelpers::TestFactory<SC, LO, GO, NO>::Build1DPoisson(20);  // can be an empty operator

  RCP<ThresholdAFilterFactory> AfilterFactory0 = rcp(new ThresholdAFilterFactory("A", 0.1));  // keep all
  RCP<ThresholdAFilterFactory> AfilterFactory1 = rcp(new ThresholdAFilterFactory("A", 1.1));  // keep only diagonal
  RCP<ThresholdAFilterFactory> AfilterFactory2 = rcp(new ThresholdAFilterFactory("A", 3));    // keep only diagonal

  aLevel.Set("A", A);

  aLevel.Request("A", AfilterFactory0.get());
  AfilterFactory0->Build(aLevel);
  TEST_EQUALITY(aLevel.IsAvailable("A", AfilterFactory0.get()), true);
  RCP<Matrix> A0 = aLevel.Get<RCP<Matrix> >("A", AfilterFactory0.get());
  aLevel.Release("A", AfilterFactory0.get());
  TEST_EQUALITY(aLevel.IsAvailable("A", AfilterFactory0.get()), false);
  TEST_EQUALITY(A0->getLocalNumEntries(), A->getLocalNumEntries());
  TEST_EQUALITY(A0->getGlobalNumEntries(), A->getGlobalNumEntries());

  aLevel.Request("A", AfilterFactory1.get());
  AfilterFactory1->Build(aLevel);
  TEST_EQUALITY(aLevel.IsAvailable("A", AfilterFactory1.get()), true);
  RCP<Matrix> A1 = aLevel.Get<RCP<Matrix> >("A", AfilterFactory1.get());
  aLevel.Release("A", AfilterFactory1.get());
  TEST_EQUALITY(aLevel.IsAvailable("A", AfilterFactory1.get()), false);
  TEST_EQUALITY(A1->getGlobalNumEntries(), A1->getGlobalNumRows());

  aLevel.Request("A", AfilterFactory2.get());
  AfilterFactory2->Build(aLevel);
  TEST_EQUALITY(aLevel.IsAvailable("A", AfilterFactory2.get()), true);
  RCP<Matrix> A2 = aLevel.Get<RCP<Matrix> >("A", AfilterFactory2.get());
  aLevel.Release("A", AfilterFactory2.get());
  TEST_EQUALITY(aLevel.IsAvailable("A", AfilterFactory2.get()), false);
  TEST_EQUALITY(A2->getGlobalNumEntries(), A2->getGlobalNumRows());
}

#define MUELU_ETI_GROUP(Scalar, LocalOrdinal, GlobalOrdinal, Node) \
  TEUCHOS_UNIT_TEST_TEMPLATE_4_INSTANT(ThresholdAFilterFactory, Basic, Scalar, LocalOrdinal, GlobalOrdinal, Node)

#include <MueLu_ETI_4arg.hpp>

}  // namespace MueLuTests
