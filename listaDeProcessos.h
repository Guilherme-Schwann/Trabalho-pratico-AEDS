/*
 * TAD Lista De Processos
*/

#include "processo.h"

typedef int cursor; // Definição do tipo "cursor"
typedef unsigned int posicao; // Definição de um tipo inteiro independente de sinal

typedef struct {
    TProcesso processo; // Informação da célula (processo)
    cursor prox; // Cursor que aponta para o próximo item na lista
    cursor ant; // Cursor que aponta para o item anterior na lista
} Celula;

typedef struct {
    Celula* listaDeProcessos; // Definição do ponteiro para o endereço da lista na memória
    cursor primeiro; // Cursor que aponta para o primeiro item da lista
    cursor ultimo; // Cursor que aponta para o último item na lista
    cursor celulasDisp; // Cursor que aponta para o primeiro item da lista de células disponíveis
    posicao maxTam; // Variável que define o número máximo de itens possíveis na lista
    posicao numCelOcupadas; // Variável que define o número de células ocupadas na lista
} TListaDeProcessos;

/* Inicialização e verificação de posições ocupadas */
void inicializaLista(TListaDeProcessos* plista, posicao N); // Função inicializadora da lista
int posOcupadas(TListaDeProcessos* plista); // Função que retorna o núm de posições ocupadas na lista

/* Inserção, Remoção e impressão do conteúdo */
void insereDado(TListaDeProcessos* plista, TProcesso processo); // Insere um dado (processo) na lista
void retiraPrimeiro(TListaDeProcessos* plista); // Retira o primeiro dado (processo) da lista
void imprimeConteudo(TListaDeProcessos* plista); // Imprime todos os dados (processos) da lista
