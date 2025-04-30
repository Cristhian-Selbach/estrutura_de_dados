#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

// Definição da lista
typedef struct {
    No *inicio;
} Lista;

// Inicializa a lista
void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
}

// Inserir no final
void inserirNoFinal(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;

    if (lista->inicio == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        lista->inicio = novo;
    } else {
        No *ultimo = lista->inicio->ant;

        novo->prox = lista->inicio;
        novo->ant = ultimo;

        ultimo->prox = novo;
        lista->inicio->ant = novo;
    }
}

// Remover do final
void removerNoFinal(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *ultimo = lista->inicio->ant;

    if (ultimo == lista->inicio) {
        // Apenas um elemento
        free(ultimo);
        lista->inicio = NULL;
    } else {
        No *penultimo = ultimo->ant;
        penultimo->prox = lista->inicio;
        lista->inicio->ant = penultimo;
        free(ultimo);
    }
}

// Exibir lista
void exibirLista(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != lista->inicio);
    printf("\n");
}

// Buscar valor
No *buscarValor(Lista *lista, int valor) {
    if (lista->inicio == NULL) return NULL;

    No *atual = lista->inicio;
    do {
        if (atual->valor == valor) return atual;
        atual = atual->prox;
    } while (atual != lista->inicio);

    return NULL;
}

// Função principal para teste
int main() {
    Lista lista;
    inicializarLista(&lista);

    inserirNoFinal(&lista, 10);
    inserirNoFinal(&lista, 20);
    inserirNoFinal(&lista, 30);

    printf("Lista: ");
    exibirLista(&lista);  // Esperado: 10 20 30

    removerNoFinal(&lista);
    printf("Após remover no final: ");
    exibirLista(&lista);  // Esperado: 10 20

    No *n = buscarValor(&lista, 20);
    if (n) {
        printf("Valor 20 encontrado!\n");
    } else {
        printf("Valor 20 não encontrado.\n");
    }

    removerNoFinal(&lista);
    removerNoFinal(&lista);
    printf("Após remover todos: ");
    exibirLista(&lista);  // Esperado: Lista vazia

    return 0;
}
