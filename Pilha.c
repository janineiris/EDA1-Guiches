#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Pilha.h"

bool initPilha(Pilha* p, int n, int m) {
	if(m > TAMSENHA){
		m = TAMSENHA;
	}

	p->pilha = (char**) malloc(sizeof(char*) * n);	//aloca a pilha
    if(p->pilha == NULL){
		return false;
	}
	for(int i = 0; i < n; i++){				//aloca cada string
		p->pilha[i] = (char*) malloc(sizeof(char) * m);
		if(p->pilha[i] == NULL){
			return false;
		}
	}
	p->maxElems = n;
	p->topo = 0;
	p->contador = 0;
	return true;
}

bool pilhaEVazia(Pilha p) {
	return p.topo == 0 && p.contador == 0;;
}


bool pilhaECheia(Pilha p) {
    return p.topo == p.maxElems && p.contador == TAMSENHA - 1;
}

void empilha(Pilha* p, char c) {
    if(pilhaECheia(*p)){
		return;
	}
	p->pilha[p->topo][p->contador] = c;
	if(p->contador < (TAMSENHA - 1)){			//o topo só é incrementado quando uma string é completa
		p->contador++;
	}else{
		p->contador = 0;
		p->topo++;
	}
}

void desempilha(Pilha* p) {
	if(pilhaEVazia(*p)){
		return;
	}
	if(p->contador == 0){			//se atingir o inicio da string, quer dizer que ela acabou e o topo é decrementado
		p->topo--;
		p->contador = TAMSENHA - 1;
	}else{
		p->contador--;
	}
    return;
}

char* ler(Pilha p, char* senha){			//lê a string do topo
	char pass[TAMSENHA+1];
	for(int i = 0; i < TAMSENHA; i++){
		pass[i] = p.pilha[p.topo-1][i];
	}
	pass[TAMSENHA] = '\0';
	senha = pass;
	return senha;
}

void empilhaString(Pilha* p, char str[]) {		//empilha a senha supondo que seu tamanho é TAMSENHA
	for(int i = 0; i < TAMSENHA; i++){
		//printf("\nCHARACTER A EMPILHAR : %c\n", str[i]);
		empilha(p, str[i]);
		//printf("EMPILHADO ? %c\n", p->pilha[p->topo][p->contador-1]);
	}
	return;
}

void desempilhaString(Pilha*p){
	for(int i = 0; i < TAMSENHA; i++){
		desempilha(p);
	}
}
