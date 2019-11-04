#ifndef PILHA_H
#define PILHA_H 1

#define TAMSENHA 4              //tamanho da senha, sendo um caracter e 2 números

typedef struct { 	char** pilha;		//pilha de strings
					int maxElems;
					int topo;
					int contador;		//conta o character da string a ser empilhado/desempilhado
                } Pilha;

bool initPilha(Pilha* p, int n, int m);		//n é o num de strings; m é o tamanho de cada string

bool pilhaEVazia(Pilha p);

bool pilhaECheia(Pilha p);

void empilha(Pilha* p, char c);			//c é a string

void desempilha(Pilha* p);

char* ler(Pilha p, char* senha);

void empilhaString(Pilha*p, char str[]);

void desempilhaString(Pilha*p);

#endif
