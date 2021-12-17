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
    if (plista->numCelOcupadas > 0) {
        int i;
        Celula *vendocelula = &(plista->listaDeProcessos[plista->primeiro]);
        for (i = 0; i < plista->numCelOcupadas; i++) {
            getConteudo(vendocelula->processo);
            printf("ant: %d | prox: %d\n", vendocelula->ant, vendocelula->prox);
            if (vendocelula->prox != -1)
                vendocelula = &(plista->listaDeProcessos[vendocelula->prox]);
        }
    }
}

int posOcupadas(TListaDeProcessos* plista) {
    return plista->numCelOcupadas;
}

void insereDado(TListaDeProcessos* plista, TProcesso processo) {
    // evitarRepeticao(plista, &processo);
    cursor posterior, anterior;
    plista->listaDeProcessos[plista->celulasDisp].processo = processo;
    if (plista->numCelOcupadas > 0) {
        if (processo.pid <= plista->listaDeProcessos[plista->primeiro].processo.pid) {
            plista->listaDeProcessos[plista->primeiro].ant = plista->celulasDisp;
            plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
            plista->listaDeProcessos[plista->listaDeProcessos[plista->primeiro].ant].prox = plista->primeiro;
            plista->primeiro = plista->listaDeProcessos[plista->primeiro].ant;
        } else {
            anterior = achaAnterior(plista, processo, &plista->listaDeProcessos[plista->primeiro]);
            if (plista->listaDeProcessos[anterior].prox == -1) {
                plista->listaDeProcessos[anterior].prox = plista->celulasDisp;
                plista->listaDeProcessos[plista->celulasDisp].ant = anterior;
                plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
                plista->ultimo = plista->listaDeProcessos[anterior].prox;
                plista->listaDeProcessos[plista->ultimo].prox = -1;
            } else {
                plista->listaDeProcessos[plista->celulasDisp].ant = anterior;
                posterior = plista->listaDeProcessos[anterior].prox;
                plista->listaDeProcessos[anterior].prox = plista->celulasDisp;
                plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
                plista->listaDeProcessos[plista->listaDeProcessos[anterior].prox].prox = posterior;
                plista->listaDeProcessos[posterior].ant = plista->listaDeProcessos[anterior].prox;
            }
        }
    } else {
        plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
        plista->listaDeProcessos[plista->primeiro].prox = -1;
    }
    plista->numCelOcupadas += 1;
}

// consertar:
void retiraPrimeiro(TListaDeProcessos* plista) {
    if (plista->numCelOcupadas > 1) {
        plista->primeiro = plista->listaDeProcessos[plista->primeiro].prox;
        plista->listaDeProcessos[plista->listaDeProcessos[plista->primeiro].ant].prox = plista->celulasDisp;
        plista->celulasDisp = plista->listaDeProcessos[plista->primeiro].ant;
        plista->listaDeProcessos[plista->primeiro].ant = -1;
    } else if (plista->numCelOcupadas == 1){
        plista->listaDeProcessos[plista->primeiro].prox = plista->celulasDisp;
        plista->celulasDisp = plista->primeiro;
        plista->primeiro = 0;
        plista->ultimo = 0;
    }
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

void getConteudo(TProcesso processo) {
    getPid(processo);
    getHora(processo);
    getPrior(processo);
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

int achaAnterior(TListaDeProcessos* plista, TProcesso processo, Celula* vendoCelula) {
    int i;
    for (i = 0; i < plista->numCelOcupadas; i++) {
        if (processo.pid >= vendoCelula->processo.pid) {
            if (vendoCelula->processo.pid != plista->listaDeProcessos[vendoCelula->prox].processo.pid)
                break;
        }
        vendoCelula = &plista->listaDeProcessos[vendoCelula->prox];
    }
    if (vendoCelula->ant == -1) {
        return plista->primeiro;
    } else {
        return plista->listaDeProcessos[vendoCelula->ant].prox;
    }
}

/*
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
 */