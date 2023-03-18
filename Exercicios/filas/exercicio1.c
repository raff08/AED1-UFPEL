#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



typedef struct NO {
    int dado;
    struct NO *prox;
} NO;

typedef struct FILA {
    NO *inicio;
    NO *fim;
}FILA;

void RESET (FILA *f) {

    f->inicio = NULL;
    
}

push (FILA *f, int dado) {
    NO *ptr = (NO*) malloc(sizeof(NO));
    if (ptr == NULL) {
        printf("Erro de alocacao\n");
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = NULL;

        if (f->inicio == NULL) {
            f->inicio = ptr;
        } else {
            f->fim->prox = ptr;
        }

        f->fim = ptr; 
    }
}

int pop (FILA *f ) {
    NO *ptr = f->inicio;
    int dado;

    if(ptr != NULL) {

        f->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->inicio == NULL ) {
            f->fim = NULL;
        }
        return dado;
    } else {
        printf ("Fila vazia!");
        return;
    }

}


void imprimeFila(FILA *f) {
    NO *ptr = f->inicio;
    if (ptr!= NULL) {
        while (ptr!= NULL) {
            printf("%d", ptr->dado);
            ptr = ptr->prox;
        }
        
    }
}

