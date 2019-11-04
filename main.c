#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "Fila.h"
#include "ListaEncadeada.h"
#include "Pilha.h"

void chamaProximo(tListaEncadeada *L, Fila *F){

}

int main(){
    tListaEncadeada guiches;        //lista de guichês
    Fila clientesComum, clientesPrioridade;                  //fila de Clientes
    Pilha   senhasPrioridade,
            senhasComum;                   //pilha de senhas

    char o[6];
    // oi = (char*) malloc(sizeof(char)*6);
    srand(time(NULL));

    initLista(&guiches);
    initFila(&clientesComum);
    initFila(&clientesPrioridade);
    initPilha(&senhasPrioridade, 288, TAMSENHA);
    initPilha(&senhasComum, 288, TAMSENHA);
    //288 é o número máximo de clientes que podem ser atendidos num expediente, considerando que entram até 3 a cada 5 minutos

    int cont = 0;               //controle um expediente de trabalho; cada unidade de contador equivale a 5 minutos reais
    int novosClientes;          //conta a quantidade de clientes que entram num período de 5  minutos
    int complexidade;
    bool prioridade;
    bool ativo = true;
    int guiche;

    guiche = (rand() % 10) + 2;
    if(guiche%2 != 0){
        if(guiche == 11){
            guiche--;
        }else{
            guiche++;
        }
    }

    for(int i = 0; i < MAXL; i++){      //preenche lista com todos os guichês ímpares ativos, menos um, um total de 5
        ativo = true;
        if(i%2 != 0 || i == guiche){
            ativo = false;
        }
        if(i < 2){                      //os dois primeiros guichês são de prioridade
            insereFinalLista(&guiches, ativo, true);
        }else{
            insereFinalLista(&guiches, ativo, false);
        }
    }

    char senhas[96][3];             //vetor que armazena a base das senhas
    int k, j;
    for(int i = 0; i < 96; i++){
        senhas[i][0] = '0' + i/10;
        k = rand()%10;
        j = i - 1;
        while(j >= (i - i%10)){
            if(senhas[j][1] == ('0') + k){
                j = i - 1;
                k = rand()%10;
            }else{
                j--;
            }
        }
        senhas[i][1] = '0' + k;
        senhas[i][2] = '\0';
    }

    char c = 'B';                   //primeiro caracter da senha de clientes comuns
    char senha[5];                  //string auxiliar de senha

    while(cont < 2){            //96*5 = 8h
        if(pilhaEVazia(senhasComum)){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    senha[0] = c;
                    senha[1] = senhas[i][0];
                    senha[2] = '3' + (3*j);
                    senha[3] = senhas[i][1];
                    senha[4] = '\0';
                    empilhaString(&senhasComum, senha);
                    //printf("str %s\n",ler(senhasComum, o));
                }
            }
            //printf("\n\n");
            c++;
        }
        if(pilhaEVazia(senhasPrioridade)){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    senha[0] = 'A';
                    senha[1] = senhas[i][0];
                    senha[2] = '3' + (3*j);
                    senha[3] = senhas[i][1];
                    senha[4] = '\0';
                    empilhaString(&senhasPrioridade, senha);
                    //printf("str %s\n",ler(senhasPrioridade, o));
                }
                //printf("\n");
            }
            c++;
        }

        novosClientes = rand()%4 + 1;           //entra até 3 clientes a cada 5 minutos;
        for(int i = 0; i < novosClientes; i++){
            complexidade = rand()%3 + 1;
            prioridade = rand()%2;

            if(prioridade){
                enfileira(&clientesPrioridade, prioridade, complexidade, ler(senhasPrioridade, o), NULL);
                desempilhaString(&senhasPrioridade);
            }else{
                enfileira(&clientesComum, prioridade, complexidade, ler(senhasComum, o), NULL);
                desempilhaString(&senhasComum);
            }
        }

        while(qntdAtivos(guiches) <= 3){
            for(int i = 0; i < 4; i++){
                guiche = rand()%(MAXL - 2) + 2;     //troca pessoas em guichês, excluindo os de prioridade
                mudaStatus(&guiches, guiche);
            }
        }

        // printf("COMUM\n");
        imprimeFila(clientesComum);
        // printf("PRIORIDADE\n");
        // imprimeFila(clientesPrioridade);
        //imprimeAtivosLista(guiches);
        cont++;
    }
    //ler(senhasComum, oi);
    // //o = ler(senhasComum);
    // //senha = *oi;      //NUM POTI
    // //printf("%c\n", ler(senhasComum)[0]);
    //printf("%s\n",*oi);
    // printf(*oi);
    //printf("%s  o com *\n", *o);
    //printf("%s  o sem *\n", &o);


    /*printf("%i\n", senhasComum.topo);
    for(int i = 0; i < 5; i++){
        printf("Antes %s\n",ler(senhasComum, o));
        printf("DESEMPILHANDO\n");
        desempilhaString(&senhasComum);
        printf("Depois %s\n",ler(senhasComum, o));
    }
    printf("%i\n", senhasComum.topo);*/
}
