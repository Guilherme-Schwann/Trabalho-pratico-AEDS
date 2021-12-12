/* 
    * Funções relacionadas ao TAD Processo
*/

#include "processo.h"


/* Funções Randomizadoras */

void cria_semente()
{
    /* 
        * Inicializa o gerador de números aleatórios a partir do tempo Epoch 
        * (que sempre será diferente a cada teste do programa)
        * Logo, a semente sempre será diferente.
    */
    srand(time(0));
}

int gera_numero_entre(unsigned int numero_min, unsigned int numero_max)
{
    // a ideia: ir de numero_min a numero_max
    // o problema: rand vai começar do 0
    // solução: vamos supor que está sendo usado pro ID de processo (1000 a 10000)
    numero_max = numero_max - numero_min; // 10000 -> 9000, agora vai de 0 a 9000
    return ((rand() % numero_max) + numero_min); // agora vai de 1000 a 10000 (correto)
}

void cria_processo(Processo* processo)
{
    processo = (Processo *) malloc(sizeof(Processo));

    processo->pid = gera_numero_entre(MIN_PID, MAX_PID);
    // cria_horario(&processo); Comentado para fora pq a implementação vai mudar
    processo->prioridade = gera_numero_entre(MIN_PRIORIDADE, MAX_PRIORIDADE);
}

/* 
void cria_horario(Processo* processo) // Adendo : foi pego do stack overflow
{
    time_t tempo_epoch;
    struct tm* tempo_info;

    time(&tempo_epoch);
    tempo_info = localtime(&tempo_epoch);

    // Guarda o horário de criação no formato DD MM AAAA HH:MM:SS
    
    sprintf(processo->horario, // String
            "[%d %d %d %d:%d:%d]", // Formato
            tempo_info->tm_mday, // Dia
            tempo_info->tm_mon + 1, // Mês
            tempo_info->tm_year + 1900, // Ano
            tempo_info->tm_hour, // Horas
            tempo_info->tm_min, // Minutos
            tempo_info->tm_sec); // Segundos
}
*/

/* Get e Set */

int get_pid(Processo* processo)
{
    return processo->pid;
}
void set_pid(Processo* processo, unsigned int novo_pid)
{
    processo->pid = novo_pid;
}

int get_prioridade(Processo* processo)
{
    return processo->prioridade;
}

void set_prioridade(Processo* processo, int nova_prioridade)
{
    processo->prioridade = nova_prioridade;
}