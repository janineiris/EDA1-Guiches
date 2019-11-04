#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#define MAXL 12              //máximo de guichês
#define TEMPOPAUSA 90

typedef struct NoLista { int num;
                    bool ativo;
                    bool prioridade;
                    int contRegressiva;     //tempo até pausa, em minutos
                    int tempoAtendimento;
                 	struct NoLista* prox;
                } tNoLista;

typedef struct { tNoLista* inicio;
                 int numElem;
                 int numAtivos;
                 int* ativos;
               } tListaEncadeada;


bool initLista( tListaEncadeada* L);

tNoLista* alocaNo(int valor, bool ativo, bool prioridade);

bool insereInicioLista(tListaEncadeada* L, bool ativo, bool prioridade);

bool insereFinalLista(tListaEncadeada* L, bool ativo, bool prioridade);

bool removeElemento(tListaEncadeada* L, int valor);

void limpaLista(tListaEncadeada* L);

int tamLista(tListaEncadeada L);

bool buscaElemento(tListaEncadeada L, int elem);

void imprimeAtivosLista(tListaEncadeada L);

bool insereOrdenadoLista(tListaEncadeada* L, bool ativo, bool prioridade);

bool mudaStatus(tListaEncadeada *L, int n);     //n é o identificador do guichê

int qntdAtivos(tListaEncadeada L);

void listaAtivos(tListaEncadeada L);

#endif
