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

#include "listaDeProcessos.h"

void criacao_auto();
void criacao_manual();
char escolhe_arquivo();
void realiza_operacoes(TListaDeProcessos* lista, TProcesso* processo1, unsigned int Op, unsigned int Qt);

int main() {
    int menu = 0;
    int repetir = 0;

    do
    {
        printf("Escolha um tipo de criacao de lista:\n");
        printf("1: Criacao Manual | 2: Criação Automatica\n");

        while (menu != 1 && menu != 2)
        {
            scanf("%d", &menu);
        }
        if (menu == 1)
        {
            criacao_manual();
        }
        else
        {
            criacao_auto();
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

        realiza_operacoes(&lista, processo1, Op, Qt);
    }
    
    imprimeConteudo(&lista); // Impressão básica
}

void criacao_auto()
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
    clock_t start, end;
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