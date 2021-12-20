/* TAD Processo */

// Includes e Defines
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MIN_PRIORIDADE 1
#define MAX_PRIORIDADE 5
#define MIN_PID 1000
#define MAX_PID 9999

// Struct Processo
typedef struct {
    char horaCriada[21];
    unsigned int pid;
    unsigned int prior;
} TProcesso;

// Função inicializadora:
TProcesso inicializaProcesso();

// Gets e sets:
void getPid(TProcesso processo);

void setPid(TProcesso* processo, unsigned int novoPid);

void getHora(TProcesso processo);

void setHora(TProcesso* processo, char hora[21]);

void getPrior(TProcesso processo);

void setPrior(TProcesso* processo, unsigned int novaPrior);
