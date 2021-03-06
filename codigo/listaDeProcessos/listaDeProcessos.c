/* Funções do TAD Lista de Processos */

#include "listaDeProcessos.h"

/* Protótipos de funções extras (miscelânea) */
void inicializaCelulasDisp(TListaDeProcessos* plista);
int achaAnterior(TListaDeProcessos* plista, TProcesso processo, Celula* vendoCelula);
void getConteudo(TProcesso processo);

/* Inicialização da lista */
void inicializaLista(TListaDeProcessos* plista, int N) {
    plista->listaDeProcessos = (Celula*) malloc(sizeof(Celula) * N); // Aloca memória correspondente a N celulas
    plista->primeiro = 0; // Aponta o cursor primeiro para a posição 0
    plista->ultimo = 0; // Aponta o cursor último para a posição 0
    plista->maxTam = N; // Define o tamanho máximo da lista como N
    plista->numCelOcupadas = 0; // Define o número de células ocupadas como 0
    plista->celulasDisp = 0; // Aponta o início da lista de células disponíveis na posição 0
    inicializaCelulasDisp(plista); // Configura os cursores das células disponíveis na lista vazia
}

/* Retorna o número de posições ocupadas na lista */
int posOcupadas(TListaDeProcessos* plista) {
    return plista->numCelOcupadas;
}

/* Insere um dado (processo) na lista de processos, ordenadamente */
void insereDado(TListaDeProcessos* plista, TProcesso processo) {
    cursor posterior, anterior; // Apontam para a célula anterior e posterior da célula a ser inserida
    plista->listaDeProcessos[plista->celulasDisp].processo = processo; // Define o processo a ser inserido na lista

    // A lista está vazia ou contém células ocupadas?
    if (plista->numCelOcupadas > 0) {

        // A célula em questão será inserida na primeira posição?
        if (processo.pid < plista->listaDeProcessos[plista->primeiro].processo.pid) {
            // Inserção na primeira posição da lista:
            plista->listaDeProcessos[plista->primeiro].ant = plista->celulasDisp;
            plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
            plista->listaDeProcessos[plista->listaDeProcessos[plista->primeiro].ant].prox = plista->primeiro;
            plista->primeiro = plista->listaDeProcessos[plista->primeiro].ant;
        } else {
            anterior = achaAnterior(plista, processo, &plista->listaDeProcessos[plista->primeiro]);

            // A célula em questão será inserida na última posição?
            if (plista->listaDeProcessos[anterior].prox == -1) {
                // Inserção na última posição da lista:
                plista->listaDeProcessos[anterior].prox = plista->celulasDisp;
                plista->listaDeProcessos[plista->celulasDisp].ant = anterior;
                plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
                plista->ultimo = plista->listaDeProcessos[anterior].prox;
                plista->listaDeProcessos[plista->ultimo].prox = -1;
            } else {
                // Inserção em qualquer posição no meio da lista:
                plista->listaDeProcessos[plista->celulasDisp].ant = anterior;
                posterior = plista->listaDeProcessos[anterior].prox;
                plista->listaDeProcessos[anterior].prox = plista->celulasDisp;
                plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox;
                plista->listaDeProcessos[plista->listaDeProcessos[anterior].prox].prox = posterior;
                plista->listaDeProcessos[posterior].ant = plista->listaDeProcessos[anterior].prox;
            }
        }
    } else {
        // Inserção na lista vazia:
        plista->celulasDisp = plista->listaDeProcessos[plista->celulasDisp].prox; // Passa o cursor celulasDisp para a próxima célula
        plista->listaDeProcessos[plista->primeiro].prox = -1;
    }
    plista->numCelOcupadas += 1;
}

/* Desconecta a primeira célula da lista de processos e associa-a à lista de células disponíveis */
void retiraPrimeiro(TListaDeProcessos* plista) {
    // A lista tem apenas uma célula?
    if (plista->numCelOcupadas > 1) {
        // Caso a lista tenha mais de uma célula:
        plista->primeiro = plista->listaDeProcessos[plista->primeiro].prox; // Define o cursor primeiro para a próxima célula
        plista->listaDeProcessos[plista->listaDeProcessos[plista->primeiro].ant].prox = plista->celulasDisp; // Define o próx da antiga primeira célula como a celulasDisp
        plista->celulasDisp = plista->listaDeProcessos[plista->primeiro].ant; // Define o cursor celulasDisp para a antiga primeira célula
        plista->listaDeProcessos[plista->primeiro].ant = -1; // Encerra conexão da primeira célula com a anterior
    } else if (plista->numCelOcupadas == 1){
        // Retirando a última célula da lista:
        plista->listaDeProcessos[plista->primeiro].prox = plista->celulasDisp; // Define o próx da antiga primeira célula como a celulasDisp
        plista->celulasDisp = plista->primeiro; // Define o cursor celulasDisp para a antiga primeira célula
        plista->primeiro = 0; // Define cursor primeiro para a posição 0
        plista->ultimo = 0; // Define cursor ultimo para a posição 0
    }
    plista->numCelOcupadas -= 1;
}

/* Imprime todos os dados (processos) da lista de processos */
void imprimeConteudo(TListaDeProcessos* plista) {
    if (plista->numCelOcupadas > 0) {
        int i;
        Celula *vendocelula = &(plista->listaDeProcessos[plista->primeiro]); // Vê uma célula por vez na lista começando pela primeira
        // Para todas as células na lista:
        for (i = 0; i < plista->numCelOcupadas; i++) {
            getConteudo(vendocelula->processo); // Função que chama todos os métodos gets do TAD Processo
            printf("\n");
            if (vendocelula->prox != -1) // Se não for a última célula da lista...
                vendocelula = &(plista->listaDeProcessos[vendocelula->prox]); // ...continua vendo as próximas
        }
    }
}

/* Miscelânea */

/* Configura as células disponíveis quando inicializa-se uma lista vazia */
void inicializaCelulasDisp(TListaDeProcessos* plista) {
    int i;
    // Para todas as células da lista:
    for (i = 0; i < plista->maxTam; i++) {
        if (i == plista->maxTam - 1) {
            // Caso seja a última célula:
            plista->listaDeProcessos[i].prox = -1;
        } else {
            // Caso não seja a última célula:
            plista->listaDeProcessos[i].ant = -1;
            plista->listaDeProcessos[i].prox = i+1;
        }
    }
}

/* Encontra a célula anterior à célula a ser inserida na lista, baseada em seu PID */
int achaAnterior(TListaDeProcessos* plista, TProcesso processo, Celula* vendoCelula) {
    int i;
    // Para todas as células na lista:
    for (i = 0; i < plista->numCelOcupadas; i++) {
        // Caso a célula tenha o PID do processo menor ou igual ao PID da célula que queremos inserir...
        if (processo.pid >= vendoCelula->processo.pid) {
            // ...e sua próxima célula não seja igual a si mesma...
            if (vendoCelula->processo.pid != plista->listaDeProcessos[vendoCelula->prox].processo.pid)
                break;
        }
        vendoCelula = &plista->listaDeProcessos[vendoCelula->prox];
    }
    // Se a célula anterior for a primeira célula:
    if (vendoCelula->ant == -1) {
        // ...retorna a primeira célula
        return plista->primeiro;
    } else {
        // ...retorna a célula anterior
        return plista->listaDeProcessos[vendoCelula->ant].prox;
    }
}

/* Executa todos os métodos "gets" do processo de uma célula */
void getConteudo(TProcesso processo) {
    getPid(processo);
    getHora(processo);
    getPrior(processo);
}
