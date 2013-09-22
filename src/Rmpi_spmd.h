/* WCC: Modified from "pbdMPI/src/spmd.h". */

#ifndef __RMPI_SPMD_
#define __RMPI_SPMD_

#include <mpi.h>
#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>

/* 64-bit and long vector support. */
#define SPMD_INT8_LEN_MAX 127                           // 2^7 - 1
#define SPMD_INT16_LEN_MAX 32767                        // 2^15 - 1
#define SPMD_INT32_LEN_MAX 2147483647                   // 2^31 - 1
#define SPMD_INT64_LEN_MAX 4503599627370496             // 2^52 - 1
#define MPI_LONG_DEBUG 0
#if (MPI_LONG_DEBUG & 1) == 0
        /* 1.
           gcc -m64 gives 4 byes to an integer (int), and
           gcc -m32 gives 4 byes to an integer (int), too.
           2.
           gcc -m64 gives 8 byes to an integer pointer (int*), but
           gcc -m32 gives 4 byes to an integer pointer (int*).
         */
        #define SPMD_SHORT_LEN_MAX R_SHORT_LEN_MAX      // SPMD_INT32_LEN_MAX
#else
        #define SPMD_SHORT_LEN_MAX SPMD_INT8_LEN_MAX
#endif

void MPI_Bcast_spmd(void *C_buffer, R_len_t C_count, MPI_Datatype C_datatype,
		int C_root, MPI_Comm C_comm);

#endif
