// TAD processo:
typedef struct {
    int pid;
    char horaCriada[21];
    int prior;
} TProcesso;

// Função inicializadora:
TProcesso inicializaProcesso();

// Gets e sets:
int getPid(TProcesso processo);

void setPid(TProcesso* processo, int novoPid);

void getHora(TProcesso processo);

void setHora(TProcesso* processo, char hora[21]);

int getPrior(TProcesso processo);

void setPrior(TProcesso* processo, int novaPrior);

