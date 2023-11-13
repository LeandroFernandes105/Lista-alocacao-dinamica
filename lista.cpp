#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
        int    valor;
    struct Node* proximo;
} No;


No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));


    if (novoNo == NULL) {
            perror("Erro ao alocar memória para o nó");
         exit(EXIT_FAILURE);
    }
    novoNo->valor = dado;
         novoNo->proximo = NULL;
    return novoNo;
}

// Função para adicionar um nó no final da lista
void adicionar(No** cabeca, int dado) {
    No* novoNo = criarNo(dado);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
    while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
            atual->proximo = novoNo;
    }
}





void imprimirLista(No* cabeca) {
          No* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


void liberarLista(No** cabeca) {
    No* atual = *cabeca;
    No* proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *cabeca = NULL;
}

int main() {
    // Inicializando a lista como vazia
    No* lista = NULL;


    adicionar(&lista, 10);
    adicionar(&lista, 60);
    adicionar(&lista, 30);
     adicionar(&lista, 390);


    printf("Lista: ");


    imprimirLista(lista);


        liberarLista(&lista);

    return 0;
}
