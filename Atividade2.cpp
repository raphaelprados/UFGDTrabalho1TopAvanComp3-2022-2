
#include <stdio.h>
#include <iostream>
#include "mpi.h"
#include <math.h>

int main(int argc, char const *argv[])
{

    int rank, size;
    int msg_dest, msg_src;
    int input;
    double d;

    // Inicializacao
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Obtem dd = log(size)

    d = log2(size);
    if(rank == 0)
        input = 25;

    int mask = (int) pow(2.0, d) - 1;
    for(int i = d - 1; i >= 0; i--) {
        mask ^= (int) pow(2.0, i);
        if(!(rank & mask)) {
            if(!(rank & (int) pow(2.0, i))); {
                msg_dest = rank ^ (int) pow(2.0, i);
                MPI_Send();
            } else {
                msg_src = rank ^ (int) pow(2.0, i);
                MPI_Recv();
            }
        }
    }

    // Finalizacao
    MPI_Finalize();

    return 0;
}


