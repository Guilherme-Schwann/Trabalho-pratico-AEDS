/* TAD Processo

 * Implementação
 
*/

/* Includes e Defines */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necessário para a operação de criação do processo.
#define MIN_PRIORIDADE 1
#define MAX_PRIORIDADE 5
#define MIN_PID 1000
#define MAX_PID 10000

/* Struct */

typedef struct
{
    unsigned int pid;
    char horario[20]; // Talvez a implementação como struct tm seja melhor
    int prioridade;
} Processo;

/* 
 * Funções
*/


void cria_processo(Processo* processo); // Inicializa o TAD



void cria_horario(Processo* processo);

/* Get e Set */

int get_pid(Processo* processo);

//get_horario


int get_prioridade(Processo* processo);
void set_prioridade(Processo* processo, int nova_prioridade);


/* Funções randomizadoras (clareza) */

void cria_semente();
int gera_numero_entre(unsigned int numero_min, unsigned int numero_max);