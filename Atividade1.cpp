
#include <stdio.h>
#include <iostream>
#include <mpi.h>

int main(int argc, char const *argv[]) {
    
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(&size);
    MPI_Comm_rank(&rank);

    for(int i = size / 2; i != 0; i /= 2) {
        for(int j = 0; j < size; j += 2*i)
            std::cout << "| " << j << " -> " << j + i << " |";
        std::cout << std::endl;
    }

    MPI_Finalize();

    return 0;
}
