
#include <stdio.h>
#include <iostream>
#include "mpi.h"

int main(int argc, char const *argv[]) {
    
    // Declaracao de variaveis
    int size, rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rakn == 0)
        for(int i = size / 2; i != 0; i /= 2) {
            for(int j = 0; j < size; j += 2*i)
                std::cout << "| " << j << " -> " << j + i << " |";
            std::cout << std::endl;
        }

    MPI_Finalize();

    return 0;
}
