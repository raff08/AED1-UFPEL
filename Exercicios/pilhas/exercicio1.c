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


bool Empty(PILHA *pilha) {





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


void pop(PILHA *p){
    NO *ptr = p->topo;
    int dado;

    if(ptr == NULL) {
        printf("pilha vazia\n");
    } else {
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
    }

    
}


/*A excelência é acompanhada por fazer coisas que não tem nada de excepcional quando separadas, 
mas que são realizadas de forma consistente até que se torne habitual.    */

