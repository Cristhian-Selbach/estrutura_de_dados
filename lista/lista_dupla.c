#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int valor;
  No* prox;
  No* ant;

} No;

void inserirInicio(No** inicio, int valor){ //*inicio eh um ponteiro para o primeiro no da lista.

  No *novo = malloc(sizeof(No));  // 1. Aloca memoria para o novo no
  novo->valor = valor;            // 2. Atribui o valor ao novo no

  if (*inicio == NULL) {          // 3. Verifica se a lista esta vazia
    novo->prox = novo;            // 4. Se vazia, o no aponta para si mesmo
    novo->ant = novo;
    *inicio = novo;               // 5. O novo no é o inicio (e unico no) da lista

    //Como a lista esta vazia, o novo no precisa ser o unico nela.
    //Em uma lista circular, o unico no aponta para si mesmo tanto no campo prox (proximo) quanto em ant (anterior).
  } 
  else {
    No* ultimo = (*inicio)->ant; // 6. Encontra o último nó (anterior ao início)
    novo->prox = *inicio;        // 7. O próximo do novo nó é o antigo início
    novo->ant = ultimo;          // 8. O anterior do novo nó é o último
    ultimo->prox = novo;         // 9. O próximo do último nó é o novo nó
    (*inicio)->ant = novo;       // 10. O anterior do antigo início é o novo nó
    *inicio = novo;              // 11. O novo nó agora é o início da lista
  }
} 