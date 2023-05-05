#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[10];
    int idade;
    int telefone;
} Pessoa;

void flush_stdin(){ //limpa quaisquer caracteres restantes do input pelo usuario
    int c;
    do {
        c = fgetc(stdin);
    } while (c != EOF && c != '\n');
}

int get_index(char *pBuffer, char *nome){
    int index;
    int tamanhoLista = *(int *)pBuffer;
    Pessoa pessoa;

    for(index = 0; index < tamanhoLista; index++){
        pessoa = *(Pessoa *)(pBuffer + sizeof(int) + (sizeof(Pessoa) * index));

        if((strcmp(pessoa.nome, nome)) == 0){
            printf("\nOperacao realizada com sucesso!\n");
            return index;
        }
    }

    //caso não caia em nenhuma condicao do loop acima
    printf("\nNao foi possivel localizar o registro!\n");
    return -1;
}

char *remover_pessoa(char *pBuffer){
    int index = -1;
    int proxIndex;
    int antigaLista = *(int *)pBuffer;
    int novaLista;
    char rmvNome[10];
    Pessoa pessoa;

    if(antigaLista == 0){
        novaLista = 0;
    } else {
        novaLista = antigaLista - 1;
    }

    printf("\n-- Digite o nome da pessoa que deseja apagar da agenda: ");
    scanf("%10s^\n", rmvNome);
    flush_stdin();
    
    index = get_index(pBuffer, rmvNome);
    if(index == -1){
        return NULL;
    }

    proxIndex = index + 1;

    //a partir do index, traz as informações um indice para trás, para poder diminuir o tamanho do buffer no final
    while(proxIndex < antigaLista){
        pessoa = *(Pessoa *)(pBuffer + sizeof(int) + (sizeof(Pessoa) * proxIndex));
        *(Pessoa *)(pBuffer + sizeof(int) + (sizeof(Pessoa) * index)) = pessoa;
        index++;
        proxIndex++;
    }
 
    pBuffer = realloc(pBuffer, sizeof(int) + (sizeof(Pessoa) * novaLista));
    *(int *)pBuffer = novaLista;
    
    return pBuffer;
}

char *adiciona_pessoa(char *pBuffer){
    int antigaLista = *(int *)pBuffer;
    int novaLista = antigaLista + 1;
    Pessoa pessoa;

    printf("\n-- Prossiga com as informacoes da pessoa que deseja incluir:\n\n");
	printf("\t Nome: ");
    scanf("%10s^\n", pessoa.nome);
    flush_stdin();
	printf("\t Idade: ");
    scanf("%i", &pessoa.idade);
	printf("\t Telefone: ");
    scanf("%i", &pessoa.telefone);
    
    pBuffer = realloc(pBuffer, sizeof(int) + (sizeof(Pessoa) * novaLista));
    if (!pBuffer){
        printf("\nErro ao alocar memoria!\n");
        return NULL;
    }

    *(Pessoa *)(pBuffer + sizeof(int) + (sizeof(Pessoa) * antigaLista)) = pessoa;
    *(int *)pBuffer = novaLista;
    return pBuffer;
}

int procura_pessoa(char *pBuffer){
    int index = -1;
    int tamanhoLista = *(int *)pBuffer;
    char nome[10];
    Pessoa pessoa;

    printf("\n-- Digite o nome da pessoa que deseja buscar: ");
    scanf("%10s^\n", nome);
    flush_stdin();

    index = get_index(pBuffer, nome);
    if(index == -1){
        return -1;
    } else {
        pessoa = *(Pessoa *)(pBuffer + sizeof(int) + (sizeof(Pessoa) * index));
        printf("\nREGISTRO %i: \n", index + 1);
        printf("\nNome: %s", pessoa.nome);
        printf("\nIdade: %i", pessoa.idade);
        printf("\nTelefone: %i\n", pessoa.telefone);
    }

    return 0;
}

int listar(char *pBuffer){
    int i = 0;
    int tamanhoLista = *(int *)pBuffer;
    Pessoa pessoa;

    if (tamanhoLista != 0){
        printf("\n-- LISTA DE PESSOAS REGISTRADAS:\n");
        for(i = 0; i < tamanhoLista; i++){
            pessoa = *(Pessoa *)(pBuffer + sizeof(int) + (sizeof(Pessoa) * i));
            printf("\nREGISTRO %i: \n", i + 1);
            printf("\nNome: %s", pessoa.nome);
            printf("\nIdade: %i", pessoa.idade);
            printf("\nTelefone: %i\n", pessoa.telefone);
        }
    } else {
        printf("\nAgenda vazia! Preencha-a com alguns registros antes e tente novamente!\n");
        return -1;
    }
    return 0;
}


int menu(void){
	int c = 0;

	do {
		printf("\n-- AGENDA DE PESSOAS:\n\n");
		printf("\t 1. Incluir registro\n");
		printf("\t 2. Apagar registro\n");
		printf("\t 3. Buscar por nome\n");
		printf("\t 4. Listar registros\n");
		printf("\t 5. Sair\n");
		printf("\n-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 5);
	getchar();
	return c;
}

int main(int argc, char *argv[]){
    int op;

    void *pBuffer = malloc(sizeof(int));
    if (!pBuffer) {
        printf("\nErro ao alocar memoria!\n");
        return -1;
    }

    *(int *)pBuffer = 0;
    

    while(op != 5) {
		op = menu();
		switch (op) {
		case 1:
			pBuffer = adiciona_pessoa(pBuffer);
			break;
		case 2:
			pBuffer = remover_pessoa(pBuffer);
			break;
		case 3:
            procura_pessoa(pBuffer);
            break;
        case 4:
			listar(pBuffer);
			break;
		case 5:
			break;
		}
	}

    free(pBuffer);
	return 0;
}
