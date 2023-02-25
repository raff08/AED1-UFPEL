#include <stdio.h>
#include <stdlib.h>


//Faça um programa que leia 2 valores inteiros e chame uma funcao que receba estas
//2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas
//variaveis A e B por exemplo e, apos a execucao da funcao, A contera o valor de B e B 
//tera o valor de A.

void trocar();

int main() {

    int A, B; 

    printf ("Digite o inteiro A: ");
    scanf ("%d", &A);
    printf ("Digite o inteiro B: ");
    scanf ("%d", &B);

    trocar(&A,&B);

    printf("valor de A eh %d e o valor de B eh %d", A, B);

    return 0;
}

void trocar(int *A, int *B) {

    int aux;

    aux = *B;
    *B = *A;
    *A = aux;
}
