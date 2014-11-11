# @HEADER
# ************************************************************************
#
#            Trilinos: An Object-Oriented Solver Framework
#                 Copyright (2001) Sandia Corporation
#
#
# Copyright (2001) Sandia Corporation. Under the terms of Contract
# DE-AC04-94AL85000, there is a non-exclusive license for use of this
# work by or on behalf of the U.S. Government.  Export of this program
# may require a license from the United States Government.
#
# 1. Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the Corporation nor the names of the
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# NOTICE:  The United States Government is granted for itself and others
# acting on its behalf a paid-up, nonexclusive, irrevocable worldwide
# license in this data to reproduce, prepare derivative works, and
# perform publicly and display publicly.  Beginning five (5) years from
# July 25, 2001, the United States Government is granted for itself and
# others acting on its behalf a paid-up, nonexclusive, irrevocable
# worldwide license in this data to reproduce, prepare derivative works,
# distribute copies to the public, perform publicly and display
# publicly, and to permit others to do so.
#
# NEITHER THE UNITED STATES GOVERNMENT, NOR THE UNITED STATES DEPARTMENT
# OF ENERGY, NOR SANDIA CORPORATION, NOR ANY OF THEIR EMPLOYEES, MAKES
# ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LEGAL LIABILITY OR
# RESPONSIBILITY FOR THE ACCURACY, COMPLETENESS, OR USEFULNESS OF ANY
# INFORMATION, APPARATUS, PRODUCT, OR PROCESS DISCLOSED, OR REPRESENTS
# THAT ITS USE WOULD NOT INFRINGE PRIVATELY OWNED RIGHTS.
#
# ************************************************************************
# @HEADER

# TPL finding routine for MATLAB.  A bit more advanced and general than the FindMatlab.cmake included w/ cmake.
#
# Any questions as to how this works? Ask Chris Siefert <csiefer@sandia.gov>


# Check to make sure MATLAB_ARCH is set
IF(NOT MATLAB_ARCH)
  MESSAGE(FATAL_ERROR "You need to set MATLAB_ARCH to use MATLAB with Trilinos (hint: It's probably something like glnx86, glnxa64, mac, maci, maci64, sol2, or sol64).")
ENDIF()

# Check to make sure MATLAB_ROOT is set
IF(NOT MATLAB_ROOT)
  MESSAGE(FATAL_ERROR "You need to set MATLAB_ROOT to use MATLAB with Trilinos.  This should be set to the root of your MATLAB install.")
ENDIF()

# Check to make sure MPI is OFF
IF(TPL_ENABLE_MPI)
  MESSAGE(FATAL_ERROR "MATLAB TPL is incompatible with MPI.  Please disable MPI if you want to use MATLAB.")
ENDIF()

# Add Include/Library directories
# Note #1: I have to add this to the cache otherwise TRIBITS_TPL_FIND_INCLUDE_DIRS_AND_LIBRARIES will clobber them completely.
# Note #2: ADVANCED_SET does not handle extra parameters (like CACHE) correctly, hence why I can't use it here
SET(MATLAB_INCLUDE_DIRS ${MATLAB_ROOT}/extern/include CACHE PATH "Include directories for Matlab")
MARK_AS_ADVANCED(MATLAB_INCLUDE_DIRS)
SET(MATLAB_LIBRARY_DIRS ${MATLAB_ROOT}/bin/${MATLAB_ARCH} CACHE PATH "Lib directories for Matlab")
MARK_AS_ADVANCED(MATLAB_LIBRARY_DIRS)

# Make sure we can find the matlab libs
TRIBITS_TPL_FIND_INCLUDE_DIRS_AND_LIBRARIES( MATLAB
  REQUIRED_HEADERS engine.h mex.h
  REQUIRED_LIBS_NAMES mex mx eng
  )

# Find mex & mexext
SET(MATLAB_MEX_DIR ${MATLAB_ROOT}/bin)
FIND_PROGRAM(MEX_COMPILER mex ${MATLAB_MEX_DIR})
IF(NOT MEX_COMPILER)
  MESSAGE(FATAL_ERROR " Could not find mex.")
ENDIF()
IF (${PROJECT_NAME}_VERBOSE_CONFIGURE)
  MESSAGE("Found mex: " ${MEX_COMPILER})
ENDIF()

FIND_PROGRAM(MEX_MEXEXT mexext ${MATLAB_MEX_DIR})
IF(NOT MEX_MEXEXT)
  MESSAGE(FATAL_ERROR " Could not find mexext.")
ENDIF()
IF (${PROJECT_NAME}_VERBOSE_CONFIGURE)
  MESSAGE("Found mexext: " ${MEX_MEXEXT})
ENDIF()

# Find the matlab file exension from mexext
EXECUTE_PROCESS(COMMAND ${MEX_MEXEXT} OUTPUT_VARIABLE MEX_EXTENSION OUTPUT_STRIP_TRAILING_WHITESPACE)
IF(NOT MEX_EXTENSION)
  MESSAGE(FATAL_ERROR " Platform-specific mex extension could not be found (hint: check to be sure mexext runs correctly).")
ENDIF()
IF (${PROJECT_NAME}_VERBOSE_CONFIGURE)
  MESSAGE("Platform-specific mex extension: " ${MEX_EXTENSION})
ENDIF()
