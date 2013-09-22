/* WCC: Modifined from "pbdMPI/src/spmd_bcast.c". */

#include "Rmpi_spmd.h"

int mpi_errhandler(int errcode);

void MPI_Bcast_spmd(void *C_buffer, R_len_t C_count, MPI_Datatype C_datatype,
		int C_root, MPI_Comm C_comm){
#ifdef LONG_VECTOR_SUPPORT
	void *C_send_data = C_buffer;
	R_xlen_t C_length_send_data = C_count;
	#if (MPI_LONG_DEBUG & 1) == 1
		int C_comm_rank;
		MPI_Comm_rank(C_comm, &C_comm_rank);
	#endif

	/* Loop through all. */
	while(C_length_send_data > SPMD_SHORT_LEN_MAX){
		#if (MPI_LONG_DEBUG & 1) == 1
			if(C_comm_rank == 0){
				Rprintf("C_length_send_data: %ld\n",
					C_length_send_data);
			}
		#endif

		if(C_datatype == MPI_INT){
			mpi_errhandler(MPI_Bcast(C_send_data,
					SPMD_SHORT_LEN_MAX,
					MPI_INT, C_root, C_comm));
			C_send_data = (int*) C_send_data + SPMD_SHORT_LEN_MAX;
		} else if(C_datatype == MPI_DOUBLE){
			mpi_errhandler(MPI_Bcast(C_send_data,
					SPMD_SHORT_LEN_MAX,
					MPI_DOUBLE, C_root, C_comm));
			C_send_data = (double*) C_send_data + SPMD_SHORT_LEN_MAX;
		} else if(C_datatype == MPI_BYTE){
			mpi_errhandler(MPI_Bcast(C_send_data,
					SPMD_SHORT_LEN_MAX,
					MPI_BYTE, C_root, C_comm));
			C_send_data = (Rbyte*) C_send_data + SPMD_SHORT_LEN_MAX;
		} else{
			REprintf("C_datatype (%d) is not supported.\n", C_datatype);
		}

		C_length_send_data = C_length_send_data - SPMD_SHORT_LEN_MAX;
	}

	/* Remainder. */
	if(C_length_send_data > 0){
		#if (MPI_LONG_DEBUG & 1) == 1
			if(C_comm_rank == 0){
				Rprintf("C_length_send_data: %ld\n",
					C_length_send_data);
			}
		#endif

		if(C_datatype == MPI_INT){
			mpi_errhandler(MPI_Bcast(C_send_data,
					C_length_send_data,
					MPI_INT, C_root, C_comm));
		} else if(C_datatype == MPI_DOUBLE){
			mpi_errhandler(MPI_Bcast(C_send_data,
					C_length_send_data,
					MPI_DOUBLE, C_root, C_comm));
		} else if(C_datatype == MPI_BYTE){
			mpi_errhandler(MPI_Bcast(C_send_data,
					C_length_send_data,
					MPI_BYTE, C_root, C_comm));
		} else{
			REprintf("C_datatype (%d) is not supported.\n", C_datatype);
		}
	}
#else
	mpi_errhandler(MPI_Bcast(C_buffer, (int) C_count, C_datatype,
			C_root, C_comm));
#endif
} /* End of MPI_Bcast_spmd(). */

