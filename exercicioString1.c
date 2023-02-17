#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma string por ˆ
//outro caractere ‘1’.


char* frase; //usei ponteiro para treinar


int main()
{
    int i;
    frase = (char*) malloc(sizeof(char));

    printf("Insira a frase: ");
    scanf("%s", frase);

   
   for (i=0; i<sizeof(frase); i++) {

    if (frase[i] = '0')
    {
        frase[i] = '1';
    }

   }

   printf("%s", frase);

    return 0;
}
