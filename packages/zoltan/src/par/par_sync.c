// @HEADER
// *****************************************************************************
//  Zoltan Toolkit for Load-balancing, Partitioning, Ordering and Coloring
//
// Copyright 2012 NTESS and the Zoltan contributors.
// SPDX-License-Identifier: BSD-3-Clause
// *****************************************************************************
// @HEADER


#ifdef __cplusplus
/* if C++, define the rest of this header file as extern C */
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>
#include "zoltan_util.h"
#include "par_const.h"
#include "zz_const.h"


#define PRINT_SYNC 5000   /* definition needed for print sync */

/************ R O U T I N E S   I N   T H I S   F I L E  **********************

       NAME                             TYPE
----------------------------------------------------------------------
	Zoltan_Print_Sync_Start		void
	Zoltan_Print_Sync_End		void

******************************************************************************/

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

void Zoltan_Print_Sync_Start(MPI_Comm communicator, int do_print_line)
{
/* 
 * Routine to allow I/O between Zoltan_Print_Sync_Start and Zoltan_Print_Sync_End to be 
 * printed by each processor in the communicator entirely before the next
 * processor begins its I/O.  The printing sequence is from proc = 0 to the
 * last processor, where the last processor is num_proc - 1.
 *
 * The do_print_line argument is a boolean variable.  If true, a line of # 
 * is printed to indicate the start of a Print_Sync I/O block.
 *
 * NOTE: THERE CAN BE NO COMMUNICATION BETWEEN THESE CALLS.
 *
 * Author: John Shadid (9221, SNL)
 */

int        flag = 1, from, type;
static int offset = 0;
MPI_Status st;
char *yo = "Zoltan_Print_Sync_Start";
char msg[256];
int proc;

  MPI_Comm_rank(communicator, &proc);

  /* This strategy for computing the type assumes that all calls to 
   * Zoltan_Print_Sync_Start and Zoltan_Print_Sync_End are made with
   * the same sized communicator.
   */
  offset = (offset + 1)%100;
  type   = PRINT_SYNC + offset;

  if (proc != 0) {
    from = proc -1;
    if (MPI_Recv((void *) &flag, 1, MPI_INT, from, type, communicator, &st)
        != MPI_SUCCESS) {
      sprintf(msg, "MPI_Recv failed, message type %d.", type);
      ZOLTAN_PRINT_ERROR(proc, yo, msg);
      exit (-1);
    }
  }
  else {
    if (do_print_line) {
      printf("\n");
      for (flag = 0; flag < 37; flag++) printf("#");
      printf(" PRINT_SYNC_START ");
      for (flag = 0; flag < 25; flag++) printf("#");
      printf("\n");
    }
  }
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

void Zoltan_Print_Sync_End(MPI_Comm communicator, int do_print_line)
{
/*
 * Routine to allow I/O between Zoltan_Print_Sync_Start and Zoltan_Print_Sync_End to be 
 * printed by each processor in the communicator entirely before the next
 * processor begins its I/O.  The printing sequence is from proc = 0 to the
 * last processor, where the last processor is num_proc - 1.
 *
 * The do_print_line argument is a boolean variable.  If true, a line of # 
 * is printed to indicate the start of a Print_Sync I/O block.
 *
 * NOTE: THERE CAN BE NO COMMUNICATION BETWEEN THESE CALLS.
 *
 * Author: John Shadid (9221, SNL)
 */

int         flag = 1, type, to;
static int  offset = 0;
int proc, num_proc;
char *yo = "Zoltan_Print_Sync_End";
char msg[256];

  MPI_Comm_rank(communicator, &proc);
  MPI_Comm_size(communicator, &num_proc);

  fflush(stdout);

  /* This strategy for computing the type assumes that all calls to 
   * Zoltan_Print_Sync_Start and Zoltan_Print_Sync_End are made with
   * the same sized communicator.
   */
  offset = (offset + 1)%100;
  type   = PRINT_SYNC + offset;

  if (proc < num_proc -1) {
    to = proc + 1;
    if (MPI_Send((void *) &flag, 1, MPI_INT, to, type, communicator) 
        != MPI_SUCCESS ) {
      sprintf(msg, "MPI_Send failed, message type %d.", type);
      ZOLTAN_PRINT_ERROR(proc, yo, msg);
      exit (-1);
    }
  }
  else {
    if (do_print_line) {
      printf("\n");
      for (flag = 0; flag < 37; flag++) printf("#");
      printf(" PRINT_SYNC_END__ ");
      for (flag = 0; flag < 25; flag++) printf("#");
      printf("\n\n");
    }
  }

  /*
   * Do a final sync among all the processors.
   */

  MPI_Barrier(communicator);
}

#ifdef __cplusplus
} /* closing bracket for extern "C" */
#endif
