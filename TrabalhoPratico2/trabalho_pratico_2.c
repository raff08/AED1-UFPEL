#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct PILHA {
    ListNode *topo;
} PILHA;


void RESET (PILHA *p){
    p->topo = NULL;
}

void push(PILHA *p, int val) {
    ListNode *ptr = (ListNode*) malloc(sizeof(ListNode));
    if (ptr == NULL) {
        printf("Erro de alocacao!");
        free(ptr);
        return;
    } else {
        ptr->val = val;
        ptr->next = p->topo;
        p->topo = ptr;
    }
}

int pop(PILHA *p) {
    ListNode *ptr = p->topo;
    int val;
    if (ptr == NULL) {
        printf("Pilha vazia!");
        return -1;
    } else {
        p->topo = ptr->next;
        ptr->next = NULL;
        val = ptr->val;
        free(ptr);
        return val;
    }
}

bool isPalindrome(ListNode* head, PILHA *p) {
    ListNode *ptr = head;
    int tamanho = 0;

    // Empilha todos os valores da lista na pilha
    while (ptr != NULL) {
        push(p, ptr->val);
        ptr = ptr->next;
        tamanho++;
    }

    // Verifica se os valores desempilhados são iguais aos valores da lista
    ptr = head;
    for (int i = 0; i < tamanho; i++) {
        int valor_lista = ptr->val;
        int valor_pilha = pop(p);
        if (valor_lista != valor_pilha) {
            return false;
        }
        ptr = ptr->next;
    }
    return true;
}

int main() {
    // Cria uma lista encadeada
    ListNode *head = (ListNode*) malloc(sizeof(ListNode));
    head->val = 1;
    head->next = (ListNode*) malloc(sizeof(ListNode));
    head->next->val = 2;
    head->next->next = (ListNode*) malloc(sizeof(ListNode));
    head->next->next->val = 2;
    head->next->next->next = (ListNode*) malloc(sizeof(ListNode));
    head->next->next->next->val = 1;
    head->next->next->next->next = NULL;

    // Cria uma pilha vazia
    PILHA *p = (PILHA*) malloc(sizeof(PILHA));
    RESET(p);

    // Verifica se a lista é um palíndromo
    if (isPalindrome(head, p)) {
        printf("A lista eh um palindromo");
    } else {
        printf("A lista nao eh um palindromo");
        
    }

    // Libera a memória alocada para a lista encadeada
    ListNode *ptr = head;
    while (ptr != NULL) {
        ListNode *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    // Libera a memória da pilha
    while (p->topo != NULL) {
        pop(p);
    }
    free(p); 

    return 0;
}