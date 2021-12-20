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

// Includes e Defines
#include "../listaDeProcessos/listaDeProcessos.h"
#define OP_INSERIR 0
#define OP_REMOVER 1
#define NUM_ARQUIVOS_TESTE 6  // teste100000, teste200000, ..., teste600000

/* Declaração de funções */
void criacao_manual();
void criacao_por_arquivo();
void criacao_teste();
char escolhe_arquivo();
int repetir_teste();
char nome_arquivo_testes(int i);
void realiza_operacoes(TListaDeProcessos* lista, TProcesso* processo1, unsigned int Op, unsigned int Qt);
void libera_lista(TListaDeProcessos* lista);

// Main
int main()
{
    do
    {
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
    }
    while (repetir_teste());

    return 0;
}

// Pergunta se o usuário deseja realizar outro teste com as listas.
int repetir_teste()
{
    char voce_quer;
    // Processo de repetição de teste
    printf("Voce quer realizar outro teste? S / N\n");
    while (voce_quer != 'S' && voce_quer != 'N')
    {
        scanf("%c", &voce_quer);
    }
    if (voce_quer == 'N')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Libera o espaço de memória das listas de processos.
void libera_lista(TListaDeProcessos* lista)
{
    free(lista);
}

// Realiza as operações de inserção e remoção
void realiza_operacoes(TListaDeProcessos* lista, TProcesso* processo1, unsigned int Op, unsigned int Qt)
{
   if (Op == OP_INSERIR)
   {
        for (int i = 0; i < Qt; i++)
        {
            *processo1 = inicializaProcesso();
            insereDado(lista, *processo1); 
        }
   }
       
    if (Op == OP_REMOVER)
    {
        for (int i = 0; i < Qt; i++)
        {
            if (lista->celulasDisp == 0) // Lista é vazia, não tem como fazer nenhuma remoção
            {
                return;
            }
            retiraPrimeiro(lista); 
        }
    }
    return;

    // Caso de erro
    printf("Houve um erro ao realizar operacoes.\n");
    exit(1);
}

// Usado em criação por arquivo (2)
char escolhe_arquivo()
{
    char nomeArquivo[25];
    printf("Insira o nome do arquivo (com .txt): ");
    scanf("%s", &nomeArquivo);
    return nomeArquivo;
}

// Usado em criação de arquivos teste (3)
char nome_arquivo_testes(int i)
{
    char nome_arquivo[17];
    switch (i)  /* Caso mais testes sejam criados, manutenção aqui é necessária */
    {
    case 1:
        strcpy(nome_arquivo, "teste100000.txt");
        break;
    case 2:
        strcpy(nome_arquivo, "teste200000.txt");
        break;
    case 3:
        strcpy(nome_arquivo, "teste300000.txt");
        break;
    case 4:
        strcpy(nome_arquivo, "teste400000.txt");
        break;
    case 5:
        strcpy(nome_arquivo, "teste500000.txt");
        break;
    case 6:
        strcpy(nome_arquivo, "teste600000.txt");
        break;

    // Caso de erro
    default:
        printf("Arquivo nao existe.\n");
        exit(1);
    }

    return nome_arquivo;
}

// Processo de criação de lista guiado pelo usuário (I/O padrão)
void criacao_manual()
{
    TListaDeProcessos lista;
    TProcesso *processo1;
    posicao N; // Tamanho do vetor
    unsigned int NLO; // Número de linhas de operações
    unsigned int Op; // 0 = inserção, 1 = remoção
    unsigned int Qt; // Quantidade de vezes que a operação é realizada
    int i;
    clock_t start, end; // Clock

    printf("Digite o tamanho do vetor: ");
    scanf("%u", &N);

    inicializaLista(&lista, N);

    printf("Digite o numero de sequencias de operacoes que serao realizadas: ");
    scanf("%u", &NLO);

    unsigned int num_teste = 0;
    for (i = 1; i <= NLO; i++) /* Sequências de operação */
    {
        num_teste++;
        printf("-***************************-\n");
        printf("Sequencia de operacao no. %d \n", i);
        printf("-***************************-\n");
        printf("  Qual operacao sera feita?  \n");
        printf("%d = Insercao      %d = Remocao\n", OP_INSERIR, OP_REMOVER);
        scanf("%u", &Op);

        printf("Quantas vezes a operacao sera realizada?\n");
        scanf("%u", &Qt);

        start = clock();
        realiza_operacoes(&lista, processo1, Op, Qt);
        end = clock();
        double tempo_total = (end - start) / CLOCKS_PER_SEC; // Guarda o tempo gasto para a realização de operações
        printf("TESTE %u | TEMPO GASTO: %f", num_teste, tempo_total); // Imprime o tempo gasto no console
    }
    
    imprimeConteudo(&lista); // Impressão básica
    libera_lista(&lista); // Libera espaço de memória
}

// Processo de criação de lista a partir de um arquivo especificado pelo usuário
void criacao_por_arquivo()
{
    // Declarações 
    char arquivo = escolhe_arquivo();
    TListaDeProcessos lista;
    TProcesso *processo1;
    posicao N;  // Tamanho do vetor, linha 1
    unsigned int NLO;  // Número de linhas de operações, linha 2
    unsigned int Op;  // 0 = inserção, 1 = remoção, linha 3
    unsigned int Qt;  // Quantidade de vezes que a operação é realizada, linha 3
    int i;
    clock_t start, end;  // Clock
    FILE* input;  // Arquivo de entrada

    input = fopen(arquivo, "r");
    if (input == NULL)
    {
        printf("Erro na abertura do arquivo de teste.\n");
        exit(1);  // aborta o programa
    }
    
    /* Linha 1 */
    fscanf(input, "%u", &N);  // Pega o tamanho do vetor

    inicializaLista(&lista, N);
    
    /* Linha 2 */
    fscanf(input, "%u", &NLO);  // Pega o número de linhas

    unsigned int num_teste = 0;
    for (i = 0; i <= NLO; i++)  /* Linhas seguintes */
    {
        num_teste++;
        fscanf(input, "%u %u", &Op, &Qt);

        start = clock();
        realiza_operacoes(&lista, processo1, Op, Qt);
        end = clock();
        double tempo_total = (end - start) / CLOCKS_PER_SEC;  // Guarda o tempo gasto para a realização de operações
        printf("TESTE %u | TEMPO GASTO: %f", num_teste, tempo_total);  // Imprime o tempo gasto no console
    }

    fclose(input);
    imprimeConteudo(&lista);  // Impressão básica
    libera_lista(&lista);  // Libera espaço de memória
}

// Processo de criação de lista automatizado. Lê os arquivos de teste disponibilizados.
void criacao_teste()
{
    // Declarações
    TListaDeProcessos lista;
    TProcesso *processo1;
    posicao N;  // Tamanho do vetor, linha 1
    unsigned int NLO;  // Número de linhas de operações, linha 2
    unsigned int Op;  // 0 = inserção, 1 = remoção, linha 3
    unsigned int Qt;  // Quantidade de vezes que a operação é realizada, linha 3
    unsigned int num_teste = 0;
    clock_t start, end;  // Clock
    FILE* input;  // Arquivo de entrada
    FILE* output;  // Arquivo de saída
    
    for (int i = 1; i <= NUM_ARQUIVOS_TESTE; i++) // Função lê TODOS os arquivos de teste sucessivamente
    {
        char nome_arquivo = nome_arquivo_testes(i);
        input = fopen(nome_arquivo, "r");
        free(nome_arquivo);

        /* Linha 1 */
        fscanf(input, "%u", &N);  // Pega o tamanho do vetor
        inicializaLista(&lista, N);
        
        /* Linha 2 */
        fscanf(input, "%u", &NLO);  // Pega o número de linhas

        for (int j = 0; j <= NLO; j++)  /* Linhas seguintes */
        {
            num_teste++;
            fscanf(input, "%u %u", &Op, &Qt);

            start = clock();
            realiza_operacoes(&lista, processo1, Op, Qt);
            end = clock();
            double tempo_total = (end - start) / CLOCKS_PER_SEC;  // Guarda o tempo gasto para a realização de operações

            // Registra número de teste e tempo total em arquivo output.txt
            output = fopen("output.txt", "r+");
            fseek(output, 0, SEEK_END);  // Feito para imprimir no final da lista
            fprintf(output, "%u %f", num_teste, tempo_total);
            fclose(output);
        }

        fclose(input);
        imprimeConteudo(&lista);  // Impressão básica
        libera_lista(&lista);  // Libera espaço de memória
    }
}
