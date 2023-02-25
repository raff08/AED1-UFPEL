#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

char *inserirNome(char *nome);
char *removerNome(char *nome);
int listarNome(char *nome);
int menu();





int main() {
    int* ponteiro = (int*)malloc(sizeof(int));
    
    int opcao;
    char* ptr = (char*)malloc(sizeof(char) + 1);

    if (!ptr) {
        printf("Erro ao alocar a memoria!");
        return 1;
    }
    *ptr = NULL;
    
    
    do {
        opcao = menu();
        switch (opcao) {
    
        case 1:
            getchar();
            ptr = inserirNome(ptr);
            break;
        case 2:
            getchar();
            //ptr = removerNome(ptr);
            break;
        case 3:
            getchar();
            ptr = listarNome(ptr);
            break;
        case 4:
            getchar();
            printf("\nVoce saiu!");
            free(ptr);
            exit(0);
            break;
        
        default:
            break;
        }
   }  while (opcao!=4);

    return 0;
}


int menu(){
    int opcao;
    do {
        printf("\n1- Adicionar nome\n");
        printf("2- Remover nome\n");
        printf("3- Listar\n");
        printf("4- Sair\n");
        printf("Digite a opcao: ");
        scanf ("%d", &opcao);
    } while (opcao < 1 || opcao > 4);
    return opcao;
}

char *inserirNome(char *nome){
    char nomeDigitado[MAX_NOME];
    printf("\n ---Adicionando Nome---");
    printf("\nDigite o nome para ser adicionado: ");
    gets(nomeDigitado);

    if (nome == NULL){
        nome = (char*) malloc((strlen(nomeDigitado)+1) * sizeof(char));
    } else {
        nome = (char*) realloc(nome, (strlen(nome)+strlen(nomeDigitado)+2) * sizeof(char));
        strcat(nome, ";");
    }

    strcat(nome,nomeDigitado);
    return nome;
}

int listarNome(char *nome){
    
    int i = 0;

	if(nome[0] == NULL){
		printf("\nNao existem nomes no registro!\n");
		return 1;
	}

	printf("\nNomes registrados: \n");

	while(nome[i] != '\0'){

		if(nome[i] == ';'){
			printf("\n");
		} else {
			printf("%c", nome[i]);
		}
		i++;
	}
	return 0;

}