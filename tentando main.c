#include "listaDeProcesso.h"
int main (){
    TListaDeProcessos lista;
    char nomeArquivo[30];
    int N;
    int NLO;
    int Op;
    int Qt;
    
    
    FILE *f;
    f = fopen("teste","r");
    if (f==NULL){
        printf("Erro na abertura!\n");
        exit(1);//aborta o programa
    }
    /*possiveis funcoes para usar na leitura do arquivo
      mas nao tenho ideia de qual e nem de como
    
    
    fgetc() - ler caractere de um arquivo
    : int fgetc(FILE *fp);
    https://youtu.be/FwW2T3jGvdg - Linguagem C Descomplicada

    fgets() - ler uma sequência de caracteres de um arquivo e armazená-la dentre de uma string
    : int fgets(char* str,int tamanho,FILE *fp);
    https://youtu.be/GDVPYnD-T_w - Linguagem C Descomplicada

    fread() - https://youtu.be/ZxuacsaCdaI
    : int fread(void *buffer, int bytes, int count,FILE *fp);
    https://youtu.be/ZxuacsaCdaI - Linguagem C Descomplicada

    fscanf() - permite a leitura de uma lista de dados formatados do arquivos
    : fscanf(FILE *f,"Tipos de Entrada",variaveis);
    // Exemplo: fscanf(arquivo,"%s %s %s %d",nome,telefone,endereco,&idade);
    https://youtu.be/jnotzdaKjOI - Linguagem C Descomplicada
    
    
    
    */
    
    fclose(f);
    

    
    //ou leitura por arquivo entrada
    
    inicializaLista(&lista, N);
    
    TProcesso *processo1;
    
    if (Op == 0){
        for(int i = 0 ; i < Qt; i++){
            insereDado(&lista, *processo1); 
        }
    }
    
    if (Op == 1){
        for(int i = 0 ; i < Qt; i++){
            retiraPrimeiro(&lista); 
        }
    }
    
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
