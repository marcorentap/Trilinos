#!/bin/bash
#
# Prerequisites:
# - eg or git is in the PATH
# - this machine is set up to pull/clone Trilinos using eg or git
# - python is in the PATH and is version 2.4 or later

# Ross Bartlett: This entire script needs to be rewritten as a python script
# so the Unix and Linux testing can be driven from the same script.  We can't
# have this duplication.  Other thihng things that need to be done:
#
#  1) The update of the master Trilinos git repo needs to be driven as a CTest test
#     along with the other SERIAL_DEBUG, MPI_DEBUG tests.  If it fails, we need
#     to know it.
#
#  2) The update of the inner CMake/CTest needs to be driven as a test along
#     with the other CTest tests.  If it fails, we need to know it.

MACHINE=`uname -n`

# SCRIPT_DIR is the directory where *this* script is:
#
SCRIPT_DIR=`cd "\`dirname \"$0\"\`";pwd`

# BASE_DIR is the parent directory of the "Trilinos" source tree,
# which we compute as relative to SCRIPT_DIR:
#
BASE_DIR=`cd "\`dirname \"$SCRIPT_DIR/../../../../..\"\`";pwd`

# LOGFILE is located in $BASE_DIR/logs. Use current day of week in
# log file name (most recent 7 saved before cycling around to the
# same log file name...)
#
WEEKDAY=`date "+%a"`

LOGFILE=$BASE_DIR/logs/cron_driver_"$MACHINE"_"$WEEKDAY".log

rm -f "$LOGFILE"

# Make sure logs and tools directories exist:
#
if [ ! -d "$BASE_DIR/logs" ]; then
  mkdir -p "$BASE_DIR/logs"
  if [ ! -d "$BASE_DIR/logs" ]; then
    echo error: could not create directory "\"$BASE_DIR/logs\""
    exit 1
  fi
fi

if [ ! -d "$BASE_DIR/tools" ]; then
  mkdir -p "$BASE_DIR/tools"
  if [ ! -d "$BASE_DIR/tools" ]; then
    echo error: could not create directory "\"$BASE_DIR/tools\"" >>"$LOGFILE"
    exit 2
  fi
fi

# Use which to get full paths to eg/git and python -- override by
# setting EG_EXE and/or PYTHON_EXE in the environment before calling
# this script.
#
if [ "x$EG_EXE" = "x" ]; then
  EG_EXE=`which eg`
fi
if [ "x$EG_EXE" = "x" ]; then
  EG_EXE=`which git`
fi

if [ "x$PYTHON_EXE" = "x" ]; then
  PYTHON_EXE=`which python`
fi

if [ "x$EG_EXE" = "x" ]; then
  echo error: no eg or git in the PATH >>"$LOGFILE"
  exit 3
fi

if [ "x$PYTHON_EXE" = "x" ]; then
  echo error: no python in the PATH >>"$LOGFILE"
  exit 4
fi

TRILINOS_REPOSITORY="software.sandia.gov:/space/git/Trilinos"


echo MACHINE=+$MACHINE+ >>"$LOGFILE"
echo SCRIPT_DIR=+$SCRIPT_DIR+ >>"$LOGFILE"
echo BASE_DIR=+$BASE_DIR+ >>"$LOGFILE"
echo WEEKDAY=+$WEEKDAY+ >>"$LOGFILE"
echo LOGFILE=+$LOGFILE+ >>"$LOGFILE"
echo EG_EXE=+$EG_EXE+ >>"$LOGFILE"
echo PYTHON_EXE=+$PYTHON_EXE+ >>"$LOGFILE"
echo TRILINOS_REPOSITORY=+$TRILINOS_REPOSITORY+ >>"$LOGFILE"


# Begin
#
echo >>"$LOGFILE"
echo "Starting nightly TrilinosDriver dashboard on $MACHINE: `date`" >>"$LOGFILE"
echo >>"$LOGFILE"

echo >>"$LOGFILE"
echo "Checking out / updating the scripts:" >>"$LOGFILE"
echo >>"$LOGFILE"

# Checkout / update the Trilinos repository for the latest *.cmake scripts
#
cd "$BASE_DIR"
if [ -d Trilinos ]; then
  echo Doing an update of existing directory >>"$LOGFILE"
  cd Trilinos
  "$EG_EXE" pull >>"$LOGFILE"
  cd ..
  # Ross Bartlett:  If this pull fails for any reason, we will *never* know it.
  # This pull must be driven as a ctest test so that it will show up on the
  # Trilinos driver dashbaord pass or fail.
else
  echo Cloning the repository because none exists yet >>"$LOGFILE"
  "$EG_EXE" clone $TRILINOS_REPOSITORY >>"$LOGFILE"
  # Ross Barlett: We never need this script to clone from scratch.  It is
  # critical that the developer does this manually in order to bootstrap the
  # process.  Also, when testing on a branch of Trilinos, this must be first
  # cloned and switched to the branch manually.  We don't need this else
  # statement.
fi

# Download and install CMake/CTest 'release' build
#
echo Downloading/installing CMake >>"$LOGFILE"

rm -rf "$BASE_DIR/tools/cmake-release"

"$PYTHON_EXE" "$BASE_DIR/Trilinos/cmake/python/download-cmake.py" \
  --skip-detect "--install-dir=$BASE_DIR/tools/cmake-release" \
  --installer-type=release >>"$LOGFILE"
# Ross Bartlett: ToDo: We need to allow --installer-type to be variable so
# that we can test development versions of CMake/CTest?

# Roscoe Bartlett: NOTE: If the upgrade of CMake/CTest above failes for any
# reason, this failure will be silent and you will never know it.  The upgrade
# of CTest/CMake used to drive the individual builds should be run as a CTest
# test so that it gets sent to the CDash dashbaord and we get error emails.

CTEST_EXE=`find "$BASE_DIR/tools/cmake-release" | grep "bin/ctest"`

echo CTEST_EXE=+$CTEST_EXE+ >>"$LOGFILE"

if [ ! -f "$CTEST_EXE" ]; then
  echo error: ctest not found after installation... >>"$LOGFILE"
  exit 5
fi

# Run a single TrilinosDriver dashboard on this machine:
#
echo CTEST_VERSION=+`"$CTEST_EXE" --version`+ >>"$LOGFILE"

#export TDD_CRON_DRIVER_LOGFILE=$LOGFILE
export TDD_CRON_DRIVER_SCRIPT=$SCRIPT_DIR/cron_driver.sh

echo Running ctest -S TrilinosDriverDashboard.cmake >>"$LOGFILE"

"$CTEST_EXE" -S "$SCRIPT_DIR/TrilinosDriverDashboard.cmake" >>"$LOGFILE" 2>&1

CTEST_RESULT=`echo $?`
echo CTEST_RESULT=+$CTEST_RESULT+ >>"$LOGFILE"

if [ "x$CTEST_RESULT" != "x0" ]; then
  echo error: ctest returned non-zero error value, script will exit with $CTEST_RESULT >>"$LOGFILE"
fi

# Done
#
echo >>"$LOGFILE"
echo "Ending nightly TrilinosDriver dashboard on $MACHINE: `date`" >>"$LOGFILE"
echo >>"$LOGFILE"

# Propagate ctest return value
#
exit $CTEST_RESULT