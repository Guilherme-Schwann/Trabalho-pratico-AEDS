//vixe
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
    int celulasDisp;
} TListaDeProcessos;

void inicializaLista(TListaDeProcessos* plista, int N);

int posOcupadas(TListaDeProcessos* plista);

void insereDado(TListaDeProcessos* plista, TProcesso processo);

void retiraPrimeiro(TListaDeProcessos* plista);

// void retiraUltimo();

void imprimeConteudo(TListaDeProcessos* plista);