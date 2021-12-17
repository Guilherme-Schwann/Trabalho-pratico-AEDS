#include <stdio.h>
#include <stdlib.h>
#include "listaDeProcessos.h"

int main() {
    TProcesso processo[10];
    TListaDeProcessos lista;
    inicializaLista(&lista, 10);
    for (int i = 0; i < 10; i++) {
        processo[i] = inicializaProcesso();
        insereDado(&lista, processo[i]);
        imprimeConteudo(&lista);
        printf("\n");
    }
    printf("-----------------------\n");
    for (int i = 0; i < 10; i++) {
        retiraPrimeiro(&lista);
        imprimeConteudo(&lista);
    }
    return 0;
}