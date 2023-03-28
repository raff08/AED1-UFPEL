#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct NO 
{
    int dado;
    struct NO *prox;
} NO;

typedef struct PILHA 
{
    NO *topo;
} PILHA;

void RESET (PILHA *p){
   p->topo = NULL;
}


void PUSH (int dado, PILHA *p) {

    NO *ptr = (NO*) malloc(sizeof(NO));
    if (ptr == NULL) {
        printf ("Erro de alocacao de memoria\n");
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}


int pop(PILHA *p){
    NO *ptr = p->topo;
    int dado;

    if(ptr == NULL) {
        printf("pilha vazia\n");
    } else {
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimePilha(PILHA *p){
    NO *ptr = p->topo;
    if(ptr == NULL) {
        printf ("pilha vazia");
        return;
    } else {
        while (ptr != NULL) {
            printf("%d", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}

int main () {

    PILHA *p1 = (PILHA* )malloc(sizeof(PILHA));
    if (p1 == NULL) {
        printf("erro de alocacao");
        exit(0);
    } else {
        RESET(p1);
        PUSH (10,p1);
        PUSH (20, p1);
        PUSH (30, p1);
        imprimePilha(p1);

        printf("Desempilha - resultado %d\n", pop(p1));
        imprimePilha(p1);
        printf("Desempilha - resultado %d\n", pop(p1));
        imprimePilha(p1);
        printf("Desempilha - resultado %d\n", pop(p1));
    }


    return 0;
}


