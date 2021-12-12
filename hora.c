//Esse arquivo é apenas um teste e contém anotações sobre as funções de tempo.
//https://www.tutorialspoint.com/c_standard_library/time_h.htm

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processo.h"

const char* getHra(TProcesso* processo) {
    char hora[21];
    strcpy(hora, processo->horaCriada);
    return &hora;
};

int main(void)
{
    char teste[25];
    time_t instant = time(NULL);
    struct tm *tempoInf = localtime(&instant);

    sprintf(teste, // String
            "[%d %d %d %d:%d:%d]", // Formato
            tempoInf->tm_mday, // Dia
            tempoInf->tm_mon + 1, // Mês
            tempoInf->tm_year + 1900, // Ano
            tempoInf->tm_hour, // Horas
            tempoInf->tm_min, // Minutos
            tempoInf->tm_sec); // Segundos

    TProcesso processo;
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

    char hora[20];
    strcpy(hora, getHra(&processo));
    printf("%s", hora);

}