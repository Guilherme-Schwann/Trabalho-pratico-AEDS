/*
 * TAD Lista De Processos
*/

#include "processo.h"

typedef int cursor;
typedef unsigned int posicao;

typedef struct {
    TProcesso processo;
    cursor prox;
    cursor ant;
} Celula;

typedef struct {
    Celula* listaDeProcessos;
    cursor primeiro;
    cursor ultimo;
    cursor celulasDisp;
    posicao maxTam;
    posicao numCelOcupadas;
} TListaDeProcessos;

/* Inicialização e verificação de posições ocupadas */
void inicializaLista(TListaDeProcessos* plista, posicao N);
int posOcupadas(TListaDeProcessos* plista);


/* Inserção, Remoção e impressão do conteúdo */

void insereDado(TListaDeProcessos* plista, TProcesso processo);
void retiraPrimeiro(TListaDeProcessos* plista);
void imprimeConteudo(TListaDeProcessos* plista);
