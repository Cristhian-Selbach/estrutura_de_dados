#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Estrutura da lista circular
typedef struct {
    No *inicio;
} ListaCircular;

// Inicializa a lista
void inicializarLista(ListaCircular *lista) {
    lista->inicio = NULL;
}

// Insere no final da lista
void inserirFinal(ListaCircular *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;

    if (lista->inicio == NULL) {
        novo->prox = novo;
        lista->inicio = novo;
    } else {
        No *atual = lista->inicio;
        while (atual->prox != lista->inicio) {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->prox = lista->inicio;
    }
}

// Remove do final da lista
void removerFinal(ListaCircular *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    No *anterior = NULL;

    // Lista com apenas 1 elemento
    if (atual->prox == lista->inicio) {
        free(atual);
        lista->inicio = NULL;
        return;
    }

    // Percorre até o penúltimo
    while (atual->prox != lista->inicio) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = lista->inicio;
    free(atual);
}

// Busca um valor na lista
No* buscar(ListaCircular *lista, int valor) {
    if (lista->inicio == NULL) return NULL;

    No *atual = lista->inicio;
    do {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->prox;
    } while (atual != lista->inicio);

    return NULL;
}

// Exibe a lista
void exibir(ListaCircular *lista) {
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

// Função principal
int main() {
    ListaCircular lista;
    inicializarLista(&lista);

    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);

    printf("Lista: ");
    exibir(&lista);  // 10 20 30

    removerFinal(&lista);
    exibir(&lista);

    No *achado = buscar(&lista, 20);
    if (achado != NULL) {
        printf("Valor 20 encontrado!\n");
    } else {
        printf("Valor 20 não encontrado.\n");
    }

    removerFinal(&lista);
    removerFinal(&lista);
    printf("Apos remover todos: ");
    exibir(&lista);  // Lista vazia

    return 0;
}
