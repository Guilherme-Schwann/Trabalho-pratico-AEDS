/*
 * TAD Lista De Processos
*/

#include "processo.h"

typedef int cursor;

typedef struct {
    TProcesso processo;
    cursor prox, ant;
} Celula;

typedef struct {
    Celula* listaDeProcessos;
    cursor primeiro, ultimo,celulasDisp;
    int maxTam, numCelOcupadas;
} TListaDeProcessos;

/* Inicialização e verificação de posições ocupadas */
void inicializaLista(TListaDeProcessos* plista, int N);
int posOcupadas(TListaDeProcessos* plista);


/* Inserção, Remoção e impressão do conteúdo */

void insereDado(TListaDeProcessos* plista, TProcesso processo);
void retiraPrimeiro(TListaDeProcessos* plista);
// void retiraUltimo();
void imprimeConteudo(TListaDeProcessos* plista);

/* Miscelânea */

void inicializaCelulasDisp(TListaDeProcessos* plista);
void evitarRepeticao(TListaDeProcessos* plista, TProcesso* processo);
int achaAnterior(TListaDeProcessos* plista, TProcesso processo, Celula* vendoCelula);
void getConteudo(TProcesso processo);
// void ordenaLista(TListaDeProcessos* plista);

