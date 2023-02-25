#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma string por ˆ
//outro caractere ‘1’.





int main()
{
    int i, len;
    char *frase = (char*) malloc(sizeof(char)+1);


    printf("Insira a frase: ");
    gets(frase);
    len = strlen(frase);

   
   for (i=0; i<len; i++) {

    if (frase[i] == '0')
    {
        frase[i] = '1';
    }

   }

   printf("%s", frase);
 

  
}
