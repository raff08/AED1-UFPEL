#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[10];
    int idade;
    int telefone;
}Pessoa;

int menu();
char *inserirPessoa();
char *removerPessoa();
int listarPessoa();
int buscarPessoa();




int main() {
    int opcao;
    void *pBuffer = malloc(sizeof(int));
   
   
    if (!pBuffer) {
        printf("Erro ao alocar memoria!\n");
        return -1;
    }

    *(int *)pBuffer = 0;

    do {
       opcao = menu();

       switch (opcao) {
        
        case 1:
            getchar();
            pBuffer = inserirPessoa(pBuffer);
            break;
       
        case 2:
            getchar();
            pBuffer = removerPessoa(pBuffer);
            break;
        
        case 3:
            getchar();
            pBuffer = listarPessoa(pBuffer);
            break;

        case 4:
            getchar();
            pBuffer = buscarPessoa(pBuffer);
            break;

        case 5:
            getchar();
            printf("\nVoce saiu!");
            free(pBuffer);
            exit(0);
            break;
       }
    } while (opcao != 5);
    
    
    return 0;
}


char *inserirPessoa(char *pBuffer) {

   
    Pessoa *pBuffer = (Pessoa *)malloc(sizeof(Pessoa));

    printf("Digite o nome da pessoa");
    scanf("%s",&(*pBuffer).nome);
    


}
