/*
 * Implementação das funções do TAD Lista de Processos
*/

#include "listaDeProcessos.h"

// Inicialização da lista
void inicializaLista(TListaDeProcessos* plista, int N) {
    plista->listaDeProcessos = (Celula*) malloc(sizeof(Celula) * N); // Aloca memória
    plista->primeiro = 0;
    plista->ultimo = 0;
    plista->maxTam = N;
    plista->numCelOcupadas = 0;
    plista->celulasDisp = 0;
    inicializaCelulasDisp(plista);
}

void imprimeConteudo(TListaDeProcessos* plista) {

}

int posOcupadas(TListaDeProcessos* plista) {
    return plista->numCelOcupadas;
}

void insereDado(TListaDeProcessos* plista, TProcesso processo) {
    evitarRepeticao(plista, &processo);
    plista->listaDeProcessos[plista->celulasDisp].processo = processo;
    if (plista->numCelOcupadas > 0) {
        plista->listaDeProcessos[plista->ultimo].prox = plista->celulasDisp;
        plista->listaDeProcessos[plista->celulasDisp].ant = plista->ultimo;
        plista->ultimo = plista->celulasDisp;
    }
    plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
    plista->listaDeProcessos[plista->ultimo].prox = -1;
    plista->numCelOcupadas++;
    ordenaLista(plista);
}

void retiraPrimeiro(TListaDeProcessos* plista) {
    plista->primeiro = plista->listaDeProcessos[plista->primeiro].prox;
    plista->listaDeProcessos[plista->listaDeProcessos[plista->primeiro].ant].prox = plista->celulasDisp;
    plista->celulasDisp = plista->listaDeProcessos[plista->primeiro].ant;
    plista->listaDeProcessos[plista->primeiro].ant = -1;
    plista->numCelOcupadas -= 1;
}

/* Miscelânea */

void inicializaCelulasDisp(TListaDeProcessos* plista) {
    int i;
    
    for (i = 0; i < plista->maxTam; i++) {
        if (i == plista->maxTam - 1) {
            plista->listaDeProcessos[i].prox = -1;
        }
        else {
            plista->listaDeProcessos[i].ant = -1;
            plista->listaDeProcessos[i].prox = i+1;
        }
    }
}

// Prevenção de PIDs repetidos na lista de processos
void evitarRepeticao(TListaDeProcessos* plista, TProcesso* processo) {
    int i;
    Celula *vendocelula = &(plista->listaDeProcessos[plista->primeiro]);

    // Percorre toda a lista para verificação
    for (i = 0; i < plista->numCelOcupadas; i++) {
        // Um único elemento:
        if (vendocelula->processo.pid == processo->pid) {
            setPid(processo, processo->pid + 1);
        }
        // Passa para o próximo elemento:
        vendocelula = &(plista->listaDeProcessos[vendocelula->prox]);
    }
}

void ordenaLista(TListaDeProcessos* plista) {
    int i, j;
    TProcesso temporario;
    Celula *vendocelula = &(plista->listaDeProcessos[plista->primeiro]);
    for (i = 0; i < plista->numCelOcupadas; i++) {
        for (j = 0; j < plista->numCelOcupadas - 1; j++){
            if (vendocelula->processo.pid > plista->listaDeProcessos[vendocelula->prox].processo.pid) {
                temporario = vendocelula->processo;
                vendocelula->processo = plista->listaDeProcessos[vendocelula->prox].processo;
                plista->listaDeProcessos[vendocelula->prox].processo = temporario;
            }
            vendocelula = &(plista->listaDeProcessos[vendocelula->prox]);
        }
        vendocelula = &(plista->listaDeProcessos[plista->primeiro]);
    }
}