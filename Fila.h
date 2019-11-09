#ifndef FILA_H
#define FILA_H 1

#define MAXF 50                 //máximo de pessoas na fila

typedef struct NoFila   {   int chegada;    //ordem de chegada
                            char* senha;    //senha é uma string
                            bool prioridade;
                            int complexidade;   //podendo ser 3: 1 = 5 minutos; 2 = 10 minutos; 3 = 20 minutos;
                            int guiche;
                            struct NoFila* prox;
                        }   tNoFila;

typedef struct  {   tNoFila* inicio;
                    tNoFila* fim;
                    int numElem;
                    int contador;       //conta quantos clientes já passaram pelo sistema
                }   Fila;

bool initFila(Fila* F);

bool enfileira(Fila* F, bool prioridade, int complexidade, char senha[], int guiche);

bool desenfileira(Fila* F);

bool eVazia(Fila F);

void imprimeFila(Fila F);

#endif
