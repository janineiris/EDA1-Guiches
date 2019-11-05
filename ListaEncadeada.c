#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "ListaEncadeada.h"

bool initLista(tListaEncadeada* L) {
	L->ativos = (int*) malloc(sizeof(int) * MAXL);
	L->numElem = 0;
	L->numAtivos = 0;
	L->inicio = NULL;
	if(L->ativos == NULL){
		return false;
	}
	return true;
}

tNoLista* alocaNo(int valor, bool ativo, bool prioridade) {
	tNoLista* novo = (tNoLista *)malloc(sizeof(tNoLista));
	if (novo != NULL) {
		novo->num = valor;
		novo->prox = NULL;
        novo->ativo = ativo;
        novo->prioridade = prioridade;
        novo->contRegressiva = 90;
		novo->tempoAtendimento = 0;
	}
	return novo;
}

bool insereInicioLista(tListaEncadeada* L, bool ativo, bool prioridade) {
	tNoLista* novo = alocaNo(L->numElem, ativo, prioridade);
	if(novo == NULL || L->numElem >= MAXL){
		return false;
	}
	novo->prox = L->inicio;
	L->inicio = novo;
	L->numElem++;
	if(ativo){
		L->ativos[L->numAtivos] = L->numElem;
		L->numAtivos++;
	}
	return true;
}

bool insereFinalLista(tListaEncadeada* L, bool ativo, bool prioridade) {
	tNoLista* novo = alocaNo(L->numElem, ativo, prioridade);
	if (novo == NULL || L->numElem >= MAXL){
		return false;
    }

	tNoLista* ultimo = L->inicio;

	if (ultimo == NULL){		// Lista Vazia
		L->inicio = novo;
    }else{ 							// Lista nao Vazia
		while (ultimo->prox != NULL)
			ultimo = ultimo->prox;
		ultimo->prox = novo;
	}
	L->numElem++;
	if(ativo){
		L->ativos[L->numAtivos] = L->numElem;
		L->numAtivos++;
	}
	return true;
}

bool removeElemento(tListaEncadeada* L, int valor) {
	if(L->inicio != NULL){
		tNoLista* atual = L->inicio;
		tNoLista* anterior;
		while( (atual->prox != NULL) && (atual->num != valor) ){
			anterior = atual;
			atual = atual->prox;
		}
		if(atual->num == valor){
			if(atual == L->inicio){
				L->inicio = atual->prox;
			}else{
				anterior->prox = atual->prox;
			}
			if(atual->ativo){
				L->numAtivos--;
			}
			L->numElem--;
		}
		return true;
	}
	return false;
}

void limpaLista(tListaEncadeada* L) {
	tNoLista* current = L->inicio;
	tNoLista* next;
	tNoLista* last;
	if(current == NULL){
		return;
	}
	while(current->prox != NULL){
		next = current->prox;
		last = current;
		while(next->prox != NULL){
			last = next;
			next = next->prox;
		}
		last->prox = NULL;
		if(next->ativo){
			L->numAtivos--;
		}
		free(next);
		L->numElem--;
	}
	L->inicio = NULL;
	if(current->ativo){
		L->numAtivos--;
	}
	free(current);
	L->numElem--;
	return;
}

int tamLista(tListaEncadeada L) {
    return L.numElem;
}

bool buscaElemento(tListaEncadeada L, int valor) {
	if(L.inicio != NULL){
		tNoLista* atual = L.inicio;
		while( (atual->prox != NULL) && (atual->num != valor) ){
			atual = atual->prox;
		}
		if(atual->num == valor){
			return true;
		}
	}
    return false;
}

void imprimeAtivosLista(tListaEncadeada L) {
	tNoLista* pos = L.inicio;
	while (pos != NULL) {
		if(pos->ativo == true){
			printf("  Guichê  ");
		}
		pos = pos->prox;
	}
	printf("\n");
	pos = L.inicio;
	while (pos != NULL) {
		if(pos->ativo == true){
			if(pos->num < 10){
				//printf("     %d    ", pos->num);
				printf("  %d - %i  ",pos->num, pos->contRegressiva );
			}else{
				//printf("    %d    ", pos->num);
				printf("  %d - %i  ",pos->num, pos->contRegressiva );
			}
		}
		pos = pos->prox;
	}
	printf("\n");
}

bool mudaStatus(tListaEncadeada *L, int n){
	printf("N É ZERO - %i\n", n);
	if(L->inicio != NULL){
		tNoLista* atual = L->inicio;
		while( (atual->prox != NULL) && (atual->num != n) ){
			atual = atual->prox;
		}
		if(atual->num == n){
			if(atual->ativo == false && atual->contRegressiva >= 0){
				atual->ativo = true;
				L->ativos[L->numAtivos] = L->numElem;
				L->numAtivos++;
				atual->contRegressiva = TEMPOPAUSA;
			}else{
				if(atual->contRegressiva <= 30){
					atual->ativo = false;
					L->numAtivos--;
					atual->contRegressiva = -10;
				}else if(atual->contRegressiva < 0){
					atual->contRegressiva += 5;
				}else{
					return false;
				}
			}
			return true;
		}
	}
    return false;
}

int qntdAtivos(tListaEncadeada L){
	return L.numAtivos;
}

void listaAtivos(tListaEncadeada L){
	for(int i = 0; i < L.numAtivos; i++){
		printf("%i\n", L.ativos[i]);
	}
}

void pausaGuiche(tListaEncadeada *L){
	if(L->inicio != NULL){
		tNoLista* atual = L->inicio->prox->prox;
		while(atual->prox != NULL){
			if(atual->ativo == true && atual->contRegressiva <= 0 && atual->tempoAtendimento <= 0){
				atual->ativo = false;
			}
			atual = atual->prox;
		}

	}
}
