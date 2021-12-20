#include <stdio.h>
#include <stdlib.h>
#include "codigo/listaDeProcessos/listaDeProcessos.h"

int main() {
    TProcesso processo[100];
    TListaDeProcessos lista;
    inicializaLista(&lista, 100);
    for (int i = 0; i < 100; i++) {
        processo[i] = inicializaProcesso();
        insereDado(&lista, processo[i]);
        imprimeConteudo(&lista);
        printf("----------------------------------------------------------------------------\n");
    }
printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    for (int i = 0; i < 102; i++) {
        retiraPrimeiro(&lista);
        imprimeConteudo(&lista);
        printf("----------------------------------------------------------------------------\n");
    }
    return 0;
}