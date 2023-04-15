#include <stdio.h>
#include <stdlib.h>


typedef struct NO* arv_bin;

struct NO {
    int dado;
    struct NO *esq;
    struct NO *dir;
};

arv_bin* cria_arvore(){
    arv_bin* raiz = (arv_bin*) malloc(sizeof(arv_bin));
    if(raiz!=NULL)
    *raiz = NULL;
    return raiz;
}



int insere_elemento(arv_bin *raiz, int valor) {
    
    if (raiz == NULL) {
        return 0;
    }

    struct NO *novo = (struct NO*)malloc(sizeof(struct NO));

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

        struct NO *atual = *raiz;
        struct NO *ant = NULL; 

        while (atual != NULL) {
            ant = atual;
            if (valor < atual->dado) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }   

        if (valor < ant->dado) {
                 ant->esq = novo;
            } else {
                 ant->dir = novo;
            }
    }
    return 1; 
}

int maior(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int calcula_altura(struct NO *raiz){
    if (raiz == NULL) {
        return 0;
    }

    int alturaEsquerda = calcula_altura(raiz->esq);
    int alturaDireita = calcula_altura(raiz->dir);
    return maior(alturaEsquerda, alturaDireita) + 1;
}




int diametro_arvore (struct NO* raiz) {

    if (raiz == NULL) {
        return 0;
    }

    int alturaEsquerda = calcula_altura(raiz->esq);
    int alturaDireita = calcula_altura(raiz->dir);
    int diametroEsquerda = diametro_arvore(raiz->esq);
    int diametroDireita = diametro_arvore(raiz->dir);
    return maior(alturaEsquerda + alturaDireita, maior(diametroEsquerda, diametroDireita));
}


void emOrdem(arv_bin *raiz){
    if (raiz == NULL) {
        return; 
    }

    if(*raiz != NULL) {
        emOrdem(&((*raiz)->esq));
        printf("%d\n",(*raiz)->dado);
        emOrdem(&((*raiz)->dir));
    }
}

void libera_arvore(arv_bin *raiz) {
    if (raiz == NULL) {
        return;
    }

    if (*raiz != NULL) {
        libera_arvore(&((*raiz)->esq));
        libera_arvore(&((*raiz)->dir));
        free(*raiz);
        *raiz = NULL;
    }

    free(raiz);
}





int main() {
    arv_bin* raiz = cria_arvore();
    if (raiz == NULL) {
        printf ("erro de alocacao");
    }

    insere_elemento(raiz, 1);
    insere_elemento(raiz, 2);
    insere_elemento(raiz, 3);
    insere_elemento(raiz, 4);
    insere_elemento(raiz, 5);

     int tamanho = diametro_arvore(*raiz);
     printf("O tamanho do diametro da arvore eh %d",tamanho);
     libera_arvore(raiz);
     
    
    return 0;
}
 /* meu racicionio foi percorrer o caminho da arvore recursivamente como se fosse
 uma funçao de pre ordem e conseguir contar e comparar qual é o caminho mais longo */