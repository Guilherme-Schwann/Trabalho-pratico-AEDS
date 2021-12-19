/*
 * ----------------------
 * main.c - Implementação
 * ----------------------
*/

#include "listaDeProcessos.h"

/* Declaração de funções */
void criacao_manual();
void criacao_por_arquivo();
void criacao_teste();
char escolhe_arquivo();
void realiza_operacoes(TListaDeProcessos* lista, TProcesso* processo1, unsigned int Op, unsigned int Qt);
void libera_lista(TListaDeProcessos* lista);

/* Main */
int main() {
    int menu = 0;
    int repetir = 0;

    do
    {
        printf("Escolha um tipo de criacao de lista:\n");
        printf("1: Criacao Manual | 2: Criacao por leitura de arquivo | 3: Criacao pelos testes 1-12");

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
    while (!repetir);

    return 0;
}

void realiza_operacoes(TListaDeProcessos* lista, TProcesso* processo1, unsigned int Op, unsigned int Qt)
{
   if (Op == 0){
        for(int i = 0; i < Qt; i++){
            *processo1 = inicializaProcesso();
            insereDado(lista, *processo1); 
        }
    }
    
    if (Op == 1){
        for(int i = 0; i < Qt; i++){
            retiraPrimeiro(lista); 
        }
    }
}

char escolhe_arquivo()
{
    char nomeArquivo[25];
    printf("Insira o nome do arquivo (com .txt): ");
    scanf("%s", &nomeArquivo);
    return nomeArquivo;
}

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

    for (i = 1; i <= NLO; i++) /* Sequências de operação */
    {
        printf("-***************************-\n");
        printf("Sequencia de operacao no. %d \n", i);
        printf("-***************************-\n");
        printf("  Qual operacao sera feita?  \n");
        printf("0 = Insercao      1 = Remocao\n");
        scanf("%u", &Op);

        printf("Quantas vezes a operacao sera realizada?\n");
        scanf("%u", &Qt);

        start = clock();
        realiza_operacoes(&lista, processo1, Op, Qt);
        end = clock();
    }
    
    imprimeConteudo(&lista); // Impressão básica
}

void criacao_por_arquivo()
{
    // Declarações 
    char arquivo = escolhe_arquivo();
    TListaDeProcessos lista;
    TProcesso *processo1;
    posicao N; // Tamanho do vetor, linha 1
    unsigned int NLO; // Número de linhas de operações, linha 2
    unsigned int Op; // 0 = inserção, 1 = remoção, linha 3
    unsigned int Qt; // Quantidade de vezes que a operação é realizada, linha 3
    unsigned int num_teste;
    int i;
    clock_t start, end; // Clock
    FILE *input; // Arquivo de entrada
    FILE *output; // Arquivo de saída

    input = fopen(arquivo, "r");
    if (input==NULL)
    {
        printf("Erro na abertura do arquivo de teste.\n");
        exit(1); //aborta o programa
    }
    
    /* Linha 1 */
    fscanf(input, "%u", &N); // Pega o tamanho do vetor

    inicializaLista(&lista, N);
    
    /* Linha 2 */
    fscanf(input, "%u", &NLO); // Pega o número de linhas

    for (i = 0; i <= NLO; i++)  /* Linhas seguintes */
    {
        fscanf(input, "%u %u", &Op, &Qt);

        start = clock();
        realiza_operacoes(&lista, processo1, Op, Qt);
        end = clock();
        double tempo_total = (end - start) / CLOCKS_PER_SEC;

        // Registra a tabela em um arquivo
        output = fopen(output, "r+");
        if (output == NULL)
        {
            printf("Erro na abertura do arquivo de saída.\n");
            exit(1);
        }

        fseek(output, 0, SEEK_END);
        fprintf("%d %f", num_teste, tempo_total);
    }

    imprimeConteudo(&lista);
}