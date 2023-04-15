#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO* ArvBinaria;

struct NO  {
    int dado;
    struct NO *esq;
    struct NO *dir; 
};

ArvBinaria* cria_Arvore();
void preOrdem(ArvBinaria *raiz);
void emOrdem(ArvBinaria *raiz);
void posOrdem(ArvBinaria *raiz);


int insere_arv(ArvBinaria *raiz, int valor);
int remove_arv(ArvBinaria *raiz, int valor);
int consulta_arv(ArvBinaria *raiz, int valor);




int main() {

    ArvBinaria* raiz = cria_Arvore();
    

    return 0;
}


ArvBinaria* cria_Arvore(){
    ArvBinaria* raiz = (ArvBinaria*) malloc(sizeof(ArvBinaria));
    if (raiz != NULL) {
        *raiz = NULL;
        return raiz;
    }
}

void preOrdem(ArvBinaria *raiz) {
    if (raiz == NULL) {
        return; 
    }

    if (*raiz != NULL) {
        printf("%d\n", (*raiz)->dado);
        preOrdem (&((*raiz)->esq));
        preOrdem (&((*raiz)->dir));
    } 
}

void emOrdem(ArvBinaria *raiz){
    if (raiz == NULL) {
        return; 
    }

    if(*raiz != NULL) {
        emOrdem(&((*raiz)->esq));
        printf("%d\n",(*raiz)->dado);
        emOrdem(&((*raiz)->dir));
    }
}

void posOrdem(ArvBinaria *raiz){
    if (raiz == NULL) {
        return; 
    }

    if(*raiz != NULL) {
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));
        printf("%d\n",(*raiz)->dado);
    } 
}

int insere_arv(ArvBinaria *raiz, int valor){
    if (raiz == NULL) {
        return 0;
    }
    struct NO* novo = (struct NO*) malloc(sizeof(struct NO));

    if (novo == NULL){
        printf("Erro de alocacao!");
        return 0;
    }

    novo->dado = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if (*raiz == NULL) {
        *raiz = novo; 
    } else {

        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while (atual != NULL) {
            ant = atual;
            if (valor == atual->dado) {
                printf("elemento ja existe");
                free(novo);
                return 0;
            } 

            if (valor > atual->dado) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }

        if (valor > ant->dado){
            ant->dir = novo;
        } else {
            ant->esq = novo;
        }
    }
    return 1;
}



int remove_arv(ArvBinaria *raiz, int valor){
    if(raiz == NULL) { 
        printf("arvore vazia");
        return 0;
    }

    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    
    while (atual != NULL) {
        if(valor == atual->dado){
            if (atual == *raiz){
                *raiz = remove_atual(atual);
            } else {
                if (ant->dir == atual){ 
                    ant->dir = remove_atual(atual);
                } else {
                    ant->esq = remove_atual(atual);
                }
            }
            return 1;
        }

        ant = atual;
        if(valor> atual->dado) {
            atual =atual->dir;
        } else {
            atual = atual->esq;
        }
    }
    
}


struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;
    if (atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;
    while (no2->dir != NULL) {
        no1 = no2;
        no2 = no2->dir;
    }

    if (no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }

    no2->dir = atual->dir;
    free(atual);
    return no2;   
}

int consulta_arv(ArvBinaria *raiz, int valor){
    if (raiz == NULL){
        printf("arvore n existe");
        return 0;
    }

    struct NO* atual = *raiz;
    while (atual != NULL) {
        if (valor == atual->dado){
            printf("valor procurado eh %d", atual->dado);
            return 1;
        }
        if (valor > atual->dado){
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
        return 0;
    }
    
}


