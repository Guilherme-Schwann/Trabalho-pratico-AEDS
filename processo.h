/*
 * TAD Processo
*/

// Includes e Defines
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#define MIN_PRIORIDADE 1
#define MAX_PRIORIDADE 5
#define MIN_PID 1000
#define MAX_PID 9999

typedef struct {
    int pid;
    char horaCriada[21];
    int prior;
} TProcesso;

// Função inicializadora:
TProcesso inicializaProcesso();
TProcesso registraHorario(TProcesso* processo);

// Gets e sets:
int getPid(TProcesso processo);

void setPid(TProcesso* processo, int novoPid);

void getHora(TProcesso processo);

void setHora(TProcesso* processo, char hora[21]);

int getPrior(TProcesso processo);

void setPrior(TProcesso* processo, int novaPrior);

/* Funções randomizadoras (clareza) */

void cria_semente();
int gera_numero_entre(unsigned int numero_min, unsigned int numero_max);