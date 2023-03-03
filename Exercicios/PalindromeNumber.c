#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome (int x) {
    //converte o numero em uma string
    char str[32];
    sprintf(str, "%d", x);

    // obtém o tamanho da string

    int len = strlen(str);

    //verifica se a strinf é palindromo

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]){
            return false;
        }
    }
    return true;
}

int main() {

    printf("%d\n", isPalindrome(121));   // 1 (true)
    printf("%d\n", isPalindrome(12321)); // 1 (true)
    printf("%d\n", isPalindrome(12345)); // 0 (false)
    return 0;
}

