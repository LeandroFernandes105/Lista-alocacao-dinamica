#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 15

// Definição da estrutura da pilha
typedef struct {
    int *itens;
    int topo;
         int capacidade;
} Pilha;


Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
           pilha->itens = (int*)malloc(capacidade * sizeof(int));


     pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}


int pilhaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}


int pilhaCheia(Pilha* pilha) {
       return pilha->topo == pilha->capacidade - 1;
}


void empilhar(Pilha* pilha, int item) {
    if (pilhaCheia(pilha)) {
            printf("Erro: A pilha está cheia.\n");
        return;
    }
    pilha->itens[++pilha->topo] = item;
}


int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: A pilha está vazia.\n");
            return -1; // Valor de retorno indicando erro
    }
    return pilha->itens[pilha->topo--];
}


int elementoTopo(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
            printf("Erro: A pilha está vazia.\n");
        return -1; // Valor de retorno indicando erro
    }
    return pilha->itens[pilha->topo];
}


void destruirPilha(Pilha* pilha) {
    free(pilha->itens);

    free(pilha);
}

int main() {
    // Criando uma pilha com capacidade TAMANHO_MAX
    Pilha* pilha = criarPilha(TAMANHO_MAX);

    empilhar(pilha, 610);
    empilhar(pilha, 20);
    empilhar(pilha, 30);
    empilhar(pilha, 33290);
    empilhar(pilha, 11290);
     empilhar(pilha, 9011);
    empilhar(pilha, 923230);
     empilhar(pilha, 9089);
    empilhar(pilha, 1190);
     empilhar(pilha, 20);





    printf("Elemento no topo: %d\n", elementoTopo(pilha));

    desempilhar(pilha);

    printf("Elemento no topo após desempilhar: %d\n", elementoTopo(pilha));

    // Liberando a memória alocada para a pilha
    destruirPilha(pilha);

    return 0;
}
