
#include <stdio.h>
#include <iostream>
#include "mpi.h"
#include <math.h>

int main(int argc, char *argv[]) {
    
    // Variáveis
    int menu_input;
    int number_input;

    do {
        menu_input = menu();
        switch (menu_input) {
        case 1:
            LinearDispersion(number_input);
            break;
        case 2:
            HypercubeDispersion(number_input);
            break;
        }
    } while(menu_input != 0);

    return 0;
}

int menu() {

    int input;

    std::cout << "---------------------" << std::endl;
    std::cout << "|Selecione sua opcao| " << std::endl;
    std::cout << "|1. Linear          |" << std::endl;
    std::cout << "|2. Hypercubo       |" << std::endl;
    std::cout << "|0. Sair            |" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << " >";
    std::cin >> input;
    
    while(input < 0 || input > 2) {
        std::cout << "Digite uma opcao valida!!!" << std::endl;
        std::cin >> input;
    }

    return input;
}

double LinearDispersion(int number) {
    int msg_dest, msg_src;
    int rank, size;
    int input;
    double start, end;
    double d;

    // Inicializacao
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Obtem dd = log(size)

    // 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
    // https://github.com/raphaelprados/UFGDTrabalho1TopAvanComp3-2022-2

    if(rank == 0) 
        input = number;

    // Inicializa d
    d = log2(size);

    int mask = (int) pow(2.0, d) - 1;
    for(int i = d - 1; i >= 0; i--) {
        mask ^= (int) pow(2.0, i);
        if(!(rank & mask)) {
            if((rank & (int) pow(2.0, i)) == 0) {
                msg_dest = rank ^ (int) pow(2.0, i);
                MPI_Send(&input, 1, MPI_INT, msg_src, 0, MPI_COMM_WORLD);
                std::cout << "Process n" << rank << " sent " << input << " to n" << msg_dest << std::endl;
            } else {
                msg_src = rank ^ (int) pow(2.0, i);
                MPI_Recv(&input, 1, MPI_INT, msg_src, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                std::cout << "Process n" << rank << " received " << input << " from n" << msg_src << std::endl;
            }
        }
    }

    // Finalizacao
    MPI_Finalize();

    return 0.0;
}

double HypercubeDispersion(int number) {
    int msg_dest, msg_src;
    int rank, size;
    int input;
    double start, end;
    double d;

    // Inicializacao
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Obtem dd = log(size)

    // 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
    // https://github.com/raphaelprados/UFGDTrabalho1TopAvanComp3-2022-2

    if(rank == 0) 
        input = number;

    // Inicializa d
    d = log2(size);

    int mask = (int) pow(2.0, d) - 1;
    for(int i = d - 1; i >= 0; i--) {
        mask ^= (int) pow(2.0, i);
        if(!(rank & mask)) {
            if((rank & (int) pow(2.0, i)) == 0) {
                msg_dest = rank ^ (int) pow(2.0, i);
                MPI_Send(&input, 1, MPI_INT, msg_src, 0, MPI_COMM_WORLD);
                std::cout << "Process n" << rank << " sent " << input << " to n" << msg_dest << std::endl;
            } else {
                msg_src = rank ^ (int) pow(2.0, i);
                MPI_Recv(&input, 1, MPI_INT, msg_src, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                std::cout << "Process n" << rank << " received " << input << " from n" << msg_src << std::endl;
            }
        }
    }

    // Finalizacao
    MPI_Finalize();

    return 0.0;
}

