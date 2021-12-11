//Implementar funções!
#include <stdlib.h>
#include <time.h>
#include "processo.h"

TProcesso inicializaProcesso() {
    TProcesso processo;
    //registra a hora na qual o processo foi criado:
    time_t instante = time(NULL);
    processo.horaCriada = localtime(&instante);
    srand(time(0));
    //cria ID aleatório de 4 dígitos :
    processo.pId = (rand() % 9000) + 1000;
    //cria prioridade aleatória de 1 a 5:
    processo.prior = (rand() % 5) + 1;
    return processo;
}