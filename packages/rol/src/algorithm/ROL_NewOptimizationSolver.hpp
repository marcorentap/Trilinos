// @HEADER
// ************************************************************************
//
//               Rapid Optimization Library (ROL) Package
//                 Copyright (2014) Sandia Corporation
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
// Questions? Contact lead developers:
//              Drew Kouri   (dpkouri@sandia.gov) and
//              Denis Ridzal (dridzal@sandia.gov)
//
// ************************************************************************
// @HEADER

#ifndef ROL_NEWOPTIMIZATIONSOLVER_HPP
#define ROL_NEWOPTIMIZATIONSOLVER_HPP

#include "ROL_Algorithm_U_Factory.hpp"
#include "ROL_Algorithm_B_Factory.hpp"
#include "ROL_Algorithm_E_Factory.hpp"
#include "ROL_Algorithm_G_Factory.hpp"
#include "ROL_NewOptimizationProblem.hpp"

#include "ROL_ParameterList.hpp"
#include "ROL_Stream.hpp"

/** \class ROL::NewOptimizationSolver
    \brief Provides a simplified interface for solving a wide range of
           optimization problems
 */

namespace ROL {

template<typename Real>
class NewOptimizationSolver {
private:

  const Ptr<NewOptimizationProblem<Real>> opt_;
  const EProblem problemType_;

  Ptr<Algorithm_U<Real>> algoU_;
  Ptr<Algorithm_B<Real>> algoB_;
  Ptr<Algorithm_E<Real>> algoE_;
  Ptr<Algorithm_G<Real>> algoG_;

  std::vector<std::string>  output_;

public:

  /** \brief Constructor.
  
       @param[in] opt       the OptimizationProblem to be solved
       @param[in] parlist   algorithm and step input parameters

      ---
  */
  NewOptimizationSolver( const Ptr<NewOptimizationProblem<Real>> &opt,
                         ParameterList                           &list );

  /** \brief Returns iteration history as a vector of strings.

      ---
  */
  std::vector<std::string> getOutput(void) const;

  /** \brief Solve optimization problem with no iteration output.

      @param[in] status          is a user-defined StatusTest
      @param[in] combineStatus   if true, the user-defined StatusTest will be combined with the default StatusTest

      ---
  */
  int solve(const Ptr<StatusTest<Real>> &status = nullPtr,
            const bool combineStatus = true);

  /** \brief Solve optimization problem.

      @param[in] outStream       is the output stream to collect iteration history
      @param[in] status          is a user-defined StatusTest
      @param[in] combineStatus   if true, the user-defined StatusTest will be combined with the default StatusTest

      ---
  */
  int solve( std::ostream &outStream,
       const Ptr<StatusTest<Real>> &status = nullPtr,
       const bool combineStatus = true );

  /** \brief Return the AlgorithmState.

      ---
  */
  Ptr<const AlgorithmState<Real>> getAlgorithmState(void) const;

  /** \brief Reset both Algorithm and Step.

      This function will reset the AlgorithmState and reinitialize the
      Step.  This function does not permit changing the Step specified
      upon construction.  To change the Step, reinitialize the
      OptimizationSolver.

      ---
  */
  void reset(void);

}; // class NewOptimizationSolver

} // namespace ROL

#include "ROL_NewOptimizationSolver_Def.hpp"

#endif // ROL_NEWOPTIMIZATIONSOLVER_HPP


