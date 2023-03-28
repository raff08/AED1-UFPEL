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

void push (int dado, FILA *f) {
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
        return;
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
        return 0;
    }

}


void imprimeFila(FILA *f) {
    NO *ptr = f->inicio;
    if (ptr!= NULL) {
        while (ptr!= NULL) {
            printf("\n%d", ptr->dado);
            ptr = ptr->prox;
        }
    } else {
        printf("Fila vazia.\n");
        return;
    }
}

int main() {

    FILA *f1 = (FILA*) malloc(sizeof(FILA));
    if (f1 == NULL) {
        printf ("Erro de alocacao de memoria");
        exit(-1);
    } else {
        RESET(f1);
        push(10,f1);
        push(20,f1);
        push(30,f1);
        imprimeFila(f1);

        printf ("\nTentando retirar - resultado: %d\n", pop(f1));
        imprimeFila(f1);
        printf ("\nTentando retirar - resultado: %d\n", pop(f1));
        imprimeFila(f1);
        printf ("\nTentando retirar - resultado: %d\n", pop(f1));
        imprimeFila(f1);
    }
    
    return 0;
}

