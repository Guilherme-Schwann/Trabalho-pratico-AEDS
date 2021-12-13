// Funções do TAD Processo

#include "processo.h"

/* 
 * Funções Randomizadoras 
*/

void cria_semente() {
    /* 
        * Inicializa o gerador de números aleatórios a partir do tempo Epoch 
        * (que sempre será diferente a cada teste do programa)
        * Logo, a semente sempre será diferente.
    */
    srand(time(0));
}

int gera_numero_entre(unsigned int numero_min, unsigned int numero_max) {
    // a ideia: ir de numero_min a numero_max
    // o problema: rand vai começar do 0
    // solução: vamos supor que está sendo usado pro ID de processo (1000 a 10000)
    numero_max = numero_max - numero_min; // 10000 -> 9000, agora vai de 0 a 9000
    return ((rand() % numero_max) + numero_min); // agora vai de 1000 a 10000 (correto)
}

TProcesso registraHorario(TProcesso* processo) {
    time_t instante = time(NULL);
    struct tm *tempoInfo = localtime(&instante);

    // Guarda o horário de criação no formato DD MM AAAA HH:MM:SS

    sprintf(processo->horaCriada, // String
            "[%d %d %d %d:%d:%d]", // Formato
            tempoInfo->tm_mday, // Dia
            tempoInfo->tm_mon + 1, // Mês
            tempoInfo->tm_year + 1900, // Ano
            tempoInfo->tm_hour, // Horas
            tempoInfo->tm_min, // Minutos
            tempoInfo->tm_sec); // Segundos
}

// Função inicializadora:
TProcesso inicializaProcesso() {
    TProcesso processo;

    cria_semente();

    processo.pid = gera_numero_entre(MIN_PID, MAX_PID);  // Cria ID aleatório de 4 dígitos (de 1000 a 9999):
    registraHorario(&processo);  // Registra a hora na qual o processo foi criado:
    processo.prior = gera_numero_entre(MIN_PRIORIDADE, MAX_PRIORIDADE);//cria prioridade aleatória de 1 a 5:

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
