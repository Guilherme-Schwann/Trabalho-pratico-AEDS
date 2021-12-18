#include "listaDeProcessos.h"

void realiza_operacoes(TListaDeProcessos* lista, TProcesso* processo1, unsigned int Op, unsigned int Qt)
{
   if (Op == 0){
        for(int i = 0 ; i < Qt; i++){
            insereDado(lista, *processo1); 
        }
    }
    
    if (Op == 1){
        for(int i = 0 ; i < Qt; i++){
            retiraPrimeiro(lista); 
        }
    }
}

int main (){

    // Declarações 
    TListaDeProcessos lista;
    TProcesso *processo1;
    char nome_arquivo[30];
    posicao N; // Tamanho do vetor, linha 1
    unsigned int NLO; // Número de linhas de operações, linha 2
    unsigned int Op; // 0 = inserção, 1 = remoção, linha 3
    unsigned int Qt; // Quantidade de vezes que a operação é realizada, linha 3
    int i;
    FILE *f;

    printf("NOME DO ARQUIVO DE TESTE: ");

    f = fopen("testeMoodle.txt", "r");
    if (f==NULL)
    {
        printf("Erro na abertura do arquivo de teste.\n");
        exit(1); //aborta o programa
    }
    
    /* Linha 1 */
    fscanf(f, "%u", &N); // Pega o tamanho do vetor
    inicializaLista(&lista, N);
    /* Linha 2 */
    fscanf(f, "%u", &NLO); // Pega o número de linhas

    for (i = 0; i <= NLO; i++)
    {
        /* Linhas seguintes */
        fscanf(f, "%u %u", &Op, &Qt);

        realiza_operacoes(&lista, processo1, Op, Qt);
    }


    
    // fclose(f);
    
    //ou leitura por arquivo entrada
    
    
    
    
 
    imprimeConteudo(&lista);
    
  return 0;
}


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
