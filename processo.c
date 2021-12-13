// Implementar funções!
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "processo.h"

// Função inicializadora:
TProcesso inicializaProcesso() {
    TProcesso processo;

    // Registra a hora na qual o processo foi criado:
    time_t instante = time(NULL);
    struct tm *tempoInfo = localtime(&instante);

    sprintf(processo.horaCriada, // String
            "[%d %d %d %d:%d:%d]", // Formato
            tempoInfo->tm_mday, // Dia
            tempoInfo->tm_mon + 1, // Mês
            tempoInfo->tm_year + 1900, // Ano
            tempoInfo->tm_hour, // Horas
            tempoInfo->tm_min, // Minutos
            tempoInfo->tm_sec); // Segundos

    // Seed para random:
    srand(time(0));

    //cria ID aleatório de 4 dígitos:
    processo.pid = (rand() % 9000) + 1000;

    //cria prioridade aleatória de 1 a 5:
    processo.prior = (rand() % 5) + 1;
    return processo;
}

// Gets e Sets:
int getPid(TProcesso processo) {
    int pid;
    pid = processo.pid;
    return pid;
}

void setPid(TProcesso* processo, int novoPid) {
    processo->pid = novoPid;
}


void getHora(TProcesso processo) {
    puts(processo.horaCriada);
}

void setHora(TProcesso* processo, char hora[21]) {
    strcpy(processo->horaCriada, hora);
}

int getPrior(TProcesso processo) {
    int prior;
    prior = processo.prior;
    return prior;
}

void setPrior(TProcesso* processo, int novaPrior) {
    processo->prior = novaPrior;
}
