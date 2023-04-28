//Rafael da Silva de Freitas
//20201917
#include <stdio.h>
#include <stdlib.h>


void selectionSort(int vetor[], int tamanho) {
    int i, j, maior, temp;

    for (i = 0; i < tamanho - 1; i++) {
        maior = vetor[i];

        for( j = i + 1; j < tamanho; j++){
            
            if (j >= 0 && vetor[j] >= maior) {
                maior = vetor[j];

                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

void maiorSequencia(int vetor[], int tamanho) {
    int i; 
    int soma = 0;
    int novoVetor[tamanho];

    for (i = 0; i < tamanho; i++) {
        novoVetor[i] = vetor[i];
        soma += novoVetor[i];
    }

    printf ("\n----Novo vetor----\n");

    for (i = 0; i < tamanho; i++) {
        printf (" %d", novoVetor[i]);
    }

    printf ("\nA soma da sequencia eh %d\n", soma);
}


int main() {
    int vetor[] = {2, 1, 3 ,4,10,12};
    int k = 4;

     printf("\n----Vetor original ----");
    printf("\n%d, %d, %d, %d, %d, %d\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5]);

    selectionSort(vetor,6); // organizo os maiores valores

    printf("\n----Vetor original Ordenado ----");
    printf("\n%d, %d, %d, %d, %d, %d\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5]);

    maiorSequencia(vetor, k); // com essa função crio um vetor com os maiores valores e somo eles, o tamanho do vetor é estipulado por K

    return 0;
}
