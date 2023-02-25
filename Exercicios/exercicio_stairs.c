#include <stdio.h>
#include <stdlib.h>

// Função recursiva para calcular o número de maneiras de subir n escadas
int subirEscadas(int n) {
    if (n <= 1) {
        return 1;
    }
    int maneiras = 0;
    for (int i = 1; i <= 2; i++) {
        if (n >= i) {
            maneiras += subirEscadas(n - i);
        }
    }
    return maneiras;
}

int main() {
    int n;
    int maneiras;

    printf("Digite a quantidade de degraus que quer subir: ");
    scanf("%d", &n);

    if ( n < 0 && n > 45)
    {
        printf ("Digite um numero entre 1 e 45!");
    } else {

         maneiras = subirEscadas(n);
         printf("Numero de maneiras de subir %d escadas: %d", n, maneiras);

    }
    
    return 0;
}