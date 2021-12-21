/*
 * --------------------------------
 * main - Implementação
 * Trabalho Prático realizado por:
 * Guilherme Augusto Schwann Wilke
 * Letícia Oliveira Silva
 * Lucas Barbosa Pena
 *
 * Universidade Federal de Viçosa
 * --------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "../listaDeProcessos/listaDeProcessos.h"
#define OP_INSERIR 0
#define OP_REMOVER 1
#define NUM_ARQUIVOS_TESTE 6

void criacao_manual();
void criacao_por_arquivo();
void criacao_teste();

void realiza_operacoes(TListaDeProcessos* plista, unsigned int Op, unsigned int Qt);
void escolhe_arquivo(char* parquivo);
void nome_arquivo_testes(unsigned int i, char* pnome_arquivo);
void libera_lista(TListaDeProcessos* lista);

int main() {
    int menu = 0;

    printf("Escolha um tipo de criacao de lista:\n");
    printf("1: Criacao Manual | 2: Criacao por leitura de arquivo | 3: Criacao pelos testes 1-12\n");

    while (menu != 1 && menu != 2 && menu != 3)
    {
        scanf("%d", &menu);
    }
    if (menu == 1)
    {
        criacao_manual();
    }
    else if (menu == 2)
    {
        criacao_por_arquivo();
    }
    else  // if (menu == 3)
    {
        criacao_teste();
    }
    return 0;
}

void criacao_manual() {
    TListaDeProcessos lista;
    int N, i;  // Tamanho do vetor
    unsigned int NLO;  // Número de linhas de operações
    unsigned int Op;  // 0 = inserção, 1 = remoção
    unsigned int Qt;  // Quantidade de vezes que a operação é realizada
    clock_t start, end;  // Clock
    int pergunta;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    inicializaLista(&lista, N);

    printf("Digite o numero de sequencias de operacoes que serao realizadas: ");
    scanf("%u", &NLO);

    unsigned int num_teste = 0;
    for (i = 1; i <= NLO; i++) /* Sequências de operação */
    {
        num_teste++;
        printf("-**************************-\n");
        printf("Sequencia de operacao no. %d \n", i);
        printf("-**************************-\n");
        printf("  Qual operacao sera feita?  \n");
        printf("%d = Insercao      %d = Remocao\n", OP_INSERIR, OP_REMOVER);
        scanf("%u", &Op);

        printf("Quantas vezes a operacao sera realizada?\n");
        scanf("%u", &Qt);

        start = clock();
        realiza_operacoes(&lista, Op, Qt);
        end = clock();
        double tempo_total = ((double) (end - start) / CLOCKS_PER_SEC); // Guarda o tempo gasto para a realização de operações
        printf("TESTE %u | TEMPO GASTO: %f\n", num_teste, tempo_total); // Imprime o tempo gasto no console
        printf("Deseja imprimir a lista no console?\nInsira 1 para 'sim' ou 0 para 'nao':\n");
        scanf("%d", &pergunta);
        if (pergunta == 1) {
            imprimeConteudo(&lista);
        }
    }

    libera_lista(&lista); // Libera espaço de memória
}
void criacao_por_arquivo() {
    // Declarações
    TListaDeProcessos lista;
    int N;  // Tamanho do vetor, linha 1
    unsigned int NLO;  // Número de linhas de operações, linha 2
    unsigned int Op;  // 0 = inserção, 1 = remoção, linha 3
    unsigned int Qt;  // Quantidade de vezes que a operação é realizada, linha 3
    clock_t start, end;  // Clock
    FILE* input;  // Arquivo de entrada
    int pergunta;

    char arquivo[25];
    char* parquivo = arquivo;
    escolhe_arquivo(parquivo);

    input = fopen(arquivo, "r");
    if (input == NULL)
    {
        printf("Erro na abertura do arquivo de teste.\n");
        return;  // aborta a execução
    }

    /* Linha 1 */
    fscanf(input, "%d", &N);  // Pega o tamanho do vetor

    inicializaLista(&lista, N);

    /* Linha 2 */
    fscanf(input, "%u", &NLO);  // Pega o número de linhas

    unsigned int num_teste = 0;
    for (unsigned int i = 0; i < NLO; i++)  /* Linhas seguintes */
    {
        num_teste++;
        fscanf(input, "%u %u", &Op, &Qt);

        start = clock();
        realiza_operacoes(&lista, Op, Qt);
        end = clock();
        double tempo_total = ((double)(end - start) / CLOCKS_PER_SEC);  // Guarda o tempo gasto para a realização de operações
        printf("TESTE %u | TEMPO GASTO: %f\n", num_teste, tempo_total);  // Imprime o tempo gasto no console
        printf("Deseja imprimir a lista no console?\nInsira 1 para 'sim' ou 0 para 'nao':\n");
        scanf("%d", &pergunta);
        if (pergunta == 1) {
            imprimeConteudo(&lista);
        }
    }

    fclose(input);
    libera_lista(&lista);  // Libera espaço de memória
}
void criacao_teste() {
    TListaDeProcessos lista;
    int N;  // Tamanho do vetor, linha 1
    unsigned int NLO;  // Número de linhas de operações, linha 2
    unsigned int Op;  // 0 = inserção, 1 = remoção, linha 3
    unsigned int Qt;  // Quantidade de vezes que a operação é realizada, linha 3
    unsigned int num_teste = 0;
    clock_t start, end;  // Clock
    FILE* input;  // Arquivo de entrada
    FILE* output;  // Arquivo de saída

    for (int i = 1; i <= NUM_ARQUIVOS_TESTE; i++) // Função lê TODOS os arquivos de teste sucessivamente
    {
        char nome_arquivo[25];
        char *pnome_arquivo = nome_arquivo;
        nome_arquivo_testes(i, pnome_arquivo);
        input = fopen(nome_arquivo, "r");

        /* Linha 1 */
        fscanf(input, "%d", &N);  // Pega o tamanho do vetor
        inicializaLista(&lista, N);

        /* Linha 2 */
        fscanf(input, "%u", &NLO);  // Pega o número de linhas

        for (int j = 0; j < NLO; j++)  /* Linhas seguintes */
        {
            num_teste++;
            fscanf(input, "%u %u", &Op, &Qt);

            start = clock();
            realiza_operacoes(&lista, Op, Qt);
            end = clock();
            double tempo_total = ((double) (end - start) / CLOCKS_PER_SEC);  // Guarda o tempo gasto para a realização de operações

            // Registra número de teste e tempo total em arquivo output.txt
            output = fopen("../output.txt", "r+");
            fseek(output, 0, SEEK_END);  // Feito para imprimir no final da lista
            fprintf(output, "%u %f\n", num_teste, tempo_total);
            fclose(output);
        }

        fclose(input);
        // imprimeConteudo(&lista);  // Impressão básica
        libera_lista(&lista);  // Libera espaço de memória
    }
}

void realiza_operacoes(TListaDeProcessos* plista, unsigned int Op, unsigned int Qt) {
    int i;
    TProcesso processo;
    if (Op == OP_INSERIR) {
        for (i = 0; i < Qt; i++)
        {
            if (plista->numCelOcupadas == plista->maxTam) {
                printf("Tamanho maximo alcancado, insercao bloqueada.");
                return;
            }
            processo = inicializaProcesso();
            insereDado(plista, processo);
        }
    } else if (Op == OP_REMOVER) {
        for (i = 0; i < Qt; i++)
        {
            if (plista->numCelOcupadas == 0) // Lista é vazia, não tem como fazer nenhuma remoção
            {
                printf("Lista vazia, remocao bloqueada.");
                return;
            }
            retiraPrimeiro(plista);
        }
    } else {
        printf("Operacao invalida.");
    }
}

void escolhe_arquivo(char* parquivo) {
    printf("Insira o nome do arquivo (com .txt): ");
    scanf("%s", parquivo);
}

void nome_arquivo_testes(unsigned int i, char* pnome_arquivo)
{
    switch (i)  /* Caso mais testes sejam criados, manutenção aqui é necessária */
    {
        case 1:
            strcpy(pnome_arquivo, "../testes/teste100000.txt");
            break;
        case 2:
            strcpy(pnome_arquivo, "../testes/teste200000.txt");
            break;
        case 3:
            strcpy(pnome_arquivo, "../testes/teste300000.txt");
            break;
        case 4:
            strcpy(pnome_arquivo, "../testes/teste400000.txt");
            break;
        case 5:
            strcpy(pnome_arquivo, "../testes/teste500000.txt");
            break;
        case 6:
            strcpy(pnome_arquivo, "../testes/teste600000.txt");
            break;

            // Caso de erro
        default:
            printf("Arquivo nao existe.\n");
            exit(1);
    }
}

void libera_lista(TListaDeProcessos* lista)
{
    free(lista);
}