
/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2018 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 *
 *  Portions of this code were written by Intel Corporation.
 *  Copyright (C) 2011-2017 Intel Corporation.  Intel provides this material
 *  to Argonne National Laboratory subject to Software Grant and Corporate
 *  Contributor License Agreement dated February 8, 2012.
 */

#include "mpidimpl.h"

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

cvars:
    - name        : MPIR_CVAR_BCAST_POSIX_INTRA_ALGORITHM
      category    : COLLECTIVE
      type        : string
      default     : auto
      class       : device
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Variable to select algorithm for intra-node bcast
        auto - Internal algorithm selection from pt2pt based algorithms

    - name        : MPIR_CVAR_REDUCE_POSIX_INTRA_ALGORITHM
      category    : COLLECTIVE
      type        : string
      default     : auto
      class       : device
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Variable to select algorithm for intra-node reduce
        auto - Internal algorithm selection from pt2pt based algorithms

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

MPIDI_POSIX_Bcast_id_t MPIDI_POSIX_Bcast_algo_choice = MPIDI_POSIX_Bcast_intra_auto_id;
MPIDI_POSIX_Reduce_id_t MPIDI_POSIX_Reduce_algo_choice = MPIDI_POSIX_Reduce_intra_auto_id;

int collective_cvars_init(void);

int collective_cvars_init(void)
{
    int mpi_errno = MPI_SUCCESS;

    /* Bcast */
    MPIDI_POSIX_Bcast_algo_choice = MPIDI_POSIX_Bcast_intra_auto_id;

    /* Reduce */
    MPIDI_POSIX_Reduce_algo_choice = MPIDI_POSIX_Reduce_intra_auto_id;

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}
