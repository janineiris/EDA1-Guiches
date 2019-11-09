#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "time.h"
#include "string.h"

#include "Fila.h"

bool initFila(Fila* F){
    F->numElem = 0;
    F->contador = 0;
    F->inicio = NULL;
    F->fim = NULL;
    return true;
}

bool enfileira(Fila* F, bool prioridade, int complexidade, char senha[], int guiche){
    tNoFila* new = (tNoFila *)malloc(sizeof(tNoFila));

    if(new == NULL || F->numElem >= MAXF){
        return false;
    }

    new->senha = (char*) malloc(sizeof(char) * 5);

    if(new->senha == NULL){
        return false;
    }

    new->prioridade = prioridade;
    new->complexidade = complexidade;
    strcpy(new->senha, senha);
    new->guiche = guiche;
    new->prox = NULL;

    if(F->inicio == NULL){
        F->inicio = new;
    }

    if(F->fim != NULL){
        (F->fim)->prox = new;
    }

    F->contador++;
    new->chegada = F->contador;

    F->fim = new;
    F->numElem++;

    return true;
}

bool desenfileira(Fila* F){
    if(F->inicio == NULL || F->fim == NULL){
        return false;
    }

    tNoFila* atual = F->inicio;

    F->inicio = atual->prox;
    if(F->inicio == NULL){
        F->fim = NULL;
    }
    F->numElem--;
    free(atual);

    return true;
}

bool eVazia(Fila F){
    if(F.numElem > 0){
        return false;
    }
    return true;
}

bool eCheia(Fila F){
    return F.numElem >= MAXF;
}

void imprimeFila(Fila F){
    if(F.numElem == 0){
        printf("            FILA VAZIA            \n");
    }else{
        tNoFila* atual = F.inicio;
        for(int i = 0; i < F.numElem; i++){
            printf("    %i,", atual->chegada);
            atual = atual->prox;
        }
        printf("\n");/*
        atual = F.inicio;
        for(int i = 0; i < F.numElem; i++){
            printf("   %s  ", atual->senha);
            atual = atual->prox;
        }
        printf("\n");*/
    }
    return;
}
