/*
 * TAD Lista De Processos
 * Fudeu
*/

#include "processo.h"

typedef struct {
    TProcesso processo;
    int prox;
    int ant;
} Celula;

typedef struct {
    Celula* listaDeProcessos;
    int primeiro;
    int ultimo;
    int maxTam;
    int numCelOcupadas;
    int celulasDisp; // Cursor
} TListaDeProcessos;

/* Inicialização e Impressão */
void inicializaLista(TListaDeProcessos* plista, int N);
void imprimeConteudo(TListaDeProcessos* plista);
int posOcupadas(TListaDeProcessos* plista);

/* Miscelânea */

void inicializaCelulasDisp(TListaDeProcessos* plista);
void evitarRepeticao(TListaDeProcessos* plista, TProcesso* processo);
int achaAnterior(TListaDeProcessos* plista, TProcesso processo, Celula* vendoCelula);
void getConteudo(TProcesso processo);
void ordenaLista(TListaDeProcessos* plista);

/* Inserção e Remoção */

void insereDado(TListaDeProcessos* plista, TProcesso processo);

void retiraPrimeiro(TListaDeProcessos* plista);

// void retiraUltimo();
