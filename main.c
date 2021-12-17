//para testar a implementacao dos seu TAD, voce devera implementar um 
//programa principal que simula a gerencia de uma lista de processos feita pelo sistema operacional 
//este deve possuir as funcionalidade de:
//- Inicializacao da lista de processos;
//- Insercao de novos processos na lista;
//- Remocao de processos da lista (primeiro);
//- Impressao da lista (na saida padrao);

//devera permitir a criaca interativa de uma lista, bem como o carregamento de uma nova lista a partir de um arquivo 
//o tamanho da lista e, portanto, definido pelo usuario
//em seguida, devera permitir que o usuario indique o numero de insercoes ou remocoes que deseja realizar sobre a lista 
//ou le essas informacoes do arquivo (?) efetuando tais operacoes
//por fim, o seu sistema de testes devera medir qual o tempo gasto para a realizacao de cada teste.

//arquivo entrada
//devera possuir o seguinte formato:
//N // Tamanho do vetor para cursores
//NLO // NC:mero de linhas de operacoes especificadas abaixo
//Op Qt // Op = 0 para insercao e 1 para remocao inicio
	// Qt = quantidade de vezes que a operacao sera realizada

//arquivo saida
//devera ser uma tabela constando o numero do teste e o tempo total de execucaoo encontrado para sua realizacao.
//NUM_TESTE <tempo> // NC:mero do teste, valor para TAD cursores(?)


#include <stdio.h>
#include <stdlib.h>
#include "listaDeProcessos.h"

void leArquivo();
void manualmente();

int main() {
    int menu = 0;
    printf("Escolha qual operacao sera feita: (1: manualmente // 2: por arquivo)\n");
    while (menu != 1 && menu != 2) {
        scanf("%d", &menu);
    }
    if (menu == 1) {
        manualmente();
    } else {
        leArquivo();
    }
    return 0;
}

void manualmente() {
    char nomeArquivo[25];
    printf("Insira o nome do arquivo: ");
}

void leArquivo() {
    char nomeArquivo[25];
    printf("Insira o nome do arquivo: ");
}