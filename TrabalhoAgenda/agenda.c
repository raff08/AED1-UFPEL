//Nome: Rafael da Silva de Freitas
//Matricula: 20201917

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PRIMEIRA_DA_LISTA *(void **) lista
#define ULTIMA_DA_LISTA *(void **) (lista + sizeof(void **))
#define PESSOA_ANTERIOR (sizeof(char) * 10) + sizeof(int) + sizeof(int)
#define PESSOA_PROXIMA (sizeof(char) * 10) + sizeof(int) + sizeof(int) + sizeof(void **)
#define NOME (sizeof(char) * 10)
#define IDADE (sizeof(int))
#define NUMERO (sizeof(int))
#define TAMANHO_LISTA *(int *)pBuffer
#define OPCAO (int *) (pBuffer + sizeof(int))

bool Empty(void *lista) {
    return *(void **) (PRIMEIRA_DA_LISTA) == NULL;
}

void *ResetLista() {
    void *lista = malloc(sizeof(void *) + sizeof(void *)); // [PRIMEIRA_PESSOA + ULTIMA_PESSOA]
    if (!lista) {
        printf("Erro ao alocar memoria na lista!");
        exit(1);
    }

    PRIMEIRA_DA_LISTA = NULL;
    ULTIMA_DA_LISTA = NULL;

    return lista;
}

void *ResetPbuffer() {
    void *pBuffer = malloc(sizeof(int) + sizeof(int)); //[tamanho_lista + opcao]

    if (!pBuffer) {
        printf("Erro ao alocar memoria no pBuffer!");
        exit(1);
    }

    TAMANHO_LISTA = 0;

    return pBuffer;
}

/*------------------ADICIONA PESSOAS------------------*/

int adiciona_pessoa(void *pBuffer, void *lista) {

void *pessoa = malloc(NOME + IDADE + NUMERO + sizeof(void **) + sizeof(void **));
    if (!pessoa) {
    printf("Erro ao alocar memoria em Pessoa!\n");
    return -1;
}

*(void **)(pessoa + PESSOA_ANTERIOR) = NULL;
*(void **)(pessoa + PESSOA_PROXIMA) = NULL;

printf("-- Digite as informacoes da pessoa que deseja incluir:\n\n");
printf("\t Nome: ");
scanf("%s", (char *)pessoa);
printf("\t Idade: ");
scanf("%d", (int *)(pessoa + NOME));
printf("\t Telefone: ");
scanf("%d", (int *)(pessoa + NOME + IDADE));

if (TAMANHO_LISTA == 0) {
    
    PRIMEIRA_DA_LISTA = pessoa;
    ULTIMA_DA_LISTA = pessoa;
    TAMANHO_LISTA += 1;
    return 0;

} else {
    void *aux = PRIMEIRA_DA_LISTA;

    while (aux != NULL) {

        if (strcmp((char *)pessoa, (char *)aux) > 0) {

            if (*(void **)(aux + PESSOA_PROXIMA) == NULL) {
                *(void **)(pessoa + PESSOA_ANTERIOR) = aux;
                *(void **)(aux + PESSOA_PROXIMA) = pessoa;
                ULTIMA_DA_LISTA = pessoa;
                TAMANHO_LISTA += 1;
                return 0;

            } else if (strcmp((char *)(*(void **)(aux + PESSOA_PROXIMA) + NOME), (char *)pessoa) > 0) {

                *(void **)(pessoa + PESSOA_ANTERIOR) = aux;
                *(void **)(pessoa + PESSOA_PROXIMA) = *(void **)(aux + PESSOA_PROXIMA);
                *(void **)(aux + PESSOA_PROXIMA) = pessoa;
                *(void **)(*(void **)(aux + PESSOA_PROXIMA) + PESSOA_ANTERIOR) = pessoa;
                TAMANHO_LISTA += 1;
                return 0;

            }
        } else {

            *(void **)(pessoa + PESSOA_ANTERIOR) = *(void **)(aux + PESSOA_ANTERIOR);
            *(void **)(pessoa + PESSOA_PROXIMA) = aux;
            *(void **)(aux + PESSOA_ANTERIOR) = pessoa;

            if (aux == PRIMEIRA_DA_LISTA) {
                PRIMEIRA_DA_LISTA = pessoa;
            }

            TAMANHO_LISTA += 1;
            return 0;
        }

        aux = *(void **)(aux + PESSOA_PROXIMA);
    }
  }
return 0;
}


/*------------------REMOVE PESSOAS------------------*/

int remove_pessoa(void *pBuffer, void *lista) {
    
    if (Empty(lista)) { // Verifica se a lista está vazia
        printf("\nAgenda vazia! Preencha com alguns registros!\n");
        return -1; 
    }

    char comparaNome[10];
    void *pessoa = PRIMEIRA_DA_LISTA; // Inicializa o ponteiro para a primeira pessoa na lista
    void *temp = NULL;

    printf("\n -- Digite o nome para remover da agenda: ");
    scanf("%s", comparaNome);

    while (pessoa != NULL) { // Percorre a lista enquanto houver pessoas

        if (strcmp(comparaNome, (char *)pessoa) == 0) { // Compara o nome buscado com o nome da pessoa atual

            if (TAMANHO_LISTA == 1) { // Caso a lista tenha apenas um elemento

                temp = PRIMEIRA_DA_LISTA;
                free(temp);
                PRIMEIRA_DA_LISTA = NULL;
                ULTIMA_DA_LISTA = NULL;
                TAMANHO_LISTA = 0;
                printf("Nome excluido com sucesso, agenda esta vazia!\n");
                return 0;

            } else if (*(void **)(pessoa + PESSOA_ANTERIOR) == NULL) { // Caso seja a primeira pessoa da lista

                temp = PRIMEIRA_DA_LISTA;
                PRIMEIRA_DA_LISTA = *(void **)(temp + PESSOA_PROXIMA);
                free(temp);
                *(void **)((PRIMEIRA_DA_LISTA) + PESSOA_ANTERIOR) = NULL;
                TAMANHO_LISTA -= 1;
                printf("\nNome excluido com sucesso!\n");
                return 0;

            } else if (*(void **)(pessoa + PESSOA_PROXIMA) == NULL) { // Caso seja a última pessoa da lista

                temp = ULTIMA_DA_LISTA;
                ULTIMA_DA_LISTA = *(void **)(temp + PESSOA_ANTERIOR);
                free(temp);
                *(void **)((ULTIMA_DA_LISTA) + PESSOA_PROXIMA) = NULL;
                TAMANHO_LISTA -= 1;
                printf("\nNome excluido da agenda com sucesso!\n");
                return 0;

            } else { // Caso esteja no meio da lista
               
                *(void **)(temp + PESSOA_PROXIMA) = *(void **)(pessoa + PESSOA_PROXIMA); // Atualiza o ponteiro prox do nó anterior
                temp = pessoa;
                pessoa = *(void **)(pessoa + PESSOA_PROXIMA); // Atualiza o ponteiro atual
                *(void **)(pessoa + PESSOA_ANTERIOR) = *(void **)(temp + PESSOA_ANTERIOR); // Atualiza o ponteiro anterior
                free(temp);
                TAMANHO_LISTA -= 1;
                printf("\nNome excluido da agenda com sucesso!\n");
                return 0;

            }
        } else {

            temp = pessoa; // Pega posição antes da atualização
            pessoa = *(void **)(pessoa + PESSOA_PROXIMA); // Pega a prox posição

        }
    }
    printf("Nome nao encontrado.");
    return 0;
}

/*------------------BUSCA PESSOAS------------------*/
int busca_pessoa(void *pBuffer, void *lista) {
    if (TAMANHO_LISTA == 0) {
        printf("\nAgenda vazia! Preencha com alguns registros!\n");
        return -1;
    }

    char comparaNome[10];

    void *pessoa = PRIMEIRA_DA_LISTA;
    printf("\n -- Digite o nome da pessoa que deseja buscar: ");
    scanf("%s", comparaNome);

    while (pessoa != NULL) {

        if ((strcmp(comparaNome, (char*)pessoa)) == 0) {

            printf("\nNome: %s", (char*)pessoa);
            printf("\nIdade: %d", *(int*)(pessoa + NOME));
            printf("\nTelefone: %d\n", *(int*)(pessoa + NOME + IDADE));
            return 0;

        } else {
            pessoa = *(void**)(pessoa + PESSOA_PROXIMA);
        }
    
    }

    // Apenas em caso de não encontrar nenhum nome
    printf("\nO nome não existe na agenda! Tente procurar apenas por nomes já registrados!\n");
    return -1;
}


/*------------------LISTA PESSOAS------------------*/
int listar (void *pBuffer, void *lista) {
   
    if (TAMANHO_LISTA == 0) {
        printf ("Agenda  vazia!");
        return -1;
    }

    void *pessoa = PRIMEIRA_DA_LISTA;

    printf ("\n -- Lista de Pessoas --");

    while (pessoa != NULL) {

        printf ("\nNome: %s", (char *)pessoa);
        printf ("\nIdade: %d", *(int *)(pessoa + NOME));
        printf ("\nTelefone: %d", *(int*)(pessoa + NOME + IDADE));
        printf("\n------------------------------\n");
        pessoa = *(void**)(pessoa + PESSOA_PROXIMA);

    }
    return 0;
}


/*------------------MENU------------------*/
void menu(int *opcao){
	do {
		printf("\n-- AGENDA DE PESSOAS:\n\n");
		printf("\t 1. Incluir registro\n");
		printf("\t 2. Apagar registro\n");
		printf("\t 3. Buscar por nome\n");
		printf("\t 4. Listar registros\n");
		printf("\t 5. Sair\n");
		printf("\n-- Digite sua escolha: ");
		scanf("%d", opcao);
	} while (*opcao <= 0 || *opcao > 5);
	getchar();
}

 /*------------------LIBERA MEMORIA AO SAIR------------------*/

 int libera_memoria(void *pBuffer, void *lista) {
   
    if (TAMANHO_LISTA == 0) {
        return 0;
    }

    void *temp = NULL;

    while (PRIMEIRA_DA_LISTA != NULL) {
        temp = PRIMEIRA_DA_LISTA;
        PRIMEIRA_DA_LISTA = *(void**)(temp + PESSOA_PROXIMA);
        free(temp);
    }
    return 0;
 }


int main() {
    
    void *lista = NULL;
    void *pBuffer = NULL;
    lista = ResetLista();
    pBuffer = ResetPbuffer();

    do {
       *OPCAO = 0;
        menu(OPCAO);
		switch (*OPCAO) {
		case 1:
			adiciona_pessoa(pBuffer, lista);
			break;
		case 2:
			remove_pessoa(pBuffer, lista);
			break;
		case 3:
            busca_pessoa(pBuffer, lista);
            break;
        case 4:
			listar(pBuffer, lista);
			break;
		case 5:
            libera_memoria(pBuffer, lista);
			break; 

        default:
            break;
        } 
    } while (*OPCAO != 5);

    free(lista);
    free(pBuffer);
    return 0;
}
