#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
  int dados[MAX];
  int tamanho;
} Lista;

void inicializar(Lista *lista){
  lista->tamanho = 0;
}

int estaCheia(Lista *lista) {
  return lista->tamanho == MAX;
}

int estaVazia(Lista *lista) {
  return lista->tamanho == 0;
}

void inserirFinal(Lista *lista, int valor){
  if(estaCheia(lista)){
    printf("lista cheia!\n");
    return;
  }

  lista->dados[lista->tamanho] = valor;
  lista->tamanho++;
  printf("valor inserido: %d\n", valor);
}

void removerFinal(Lista *lista){
  if(estaVazia(lista)){
    printf("lista vazia!\n");
    return;
  }

  printf("valor removido: %d\n", lista->dados[lista->tamanho-1]);
  lista->tamanho--;
}

void exibir(Lista *lista) {
  if(estaVazia(lista)){
    printf("lista vazia!\n");
    return;
  }
  printf("Elementos da lista: ");
  for (int i = 0; i < lista->tamanho; i++) {
    printf("%d ", lista->dados[i]);
  }
  printf("\n");
}

void inserirPosicao(Lista *lista, int posicao, int valor){

  if(estaCheia(lista)){
    printf("lista cheia!\n");
    return;
  }

  if (posicao < 0 || posicao > lista->tamanho) {
    printf("posicao invalida!\n");
    return;
  }

  for (int i = lista->tamanho - 1; i >= posicao; i--) {
    //descola todos os elementos a partir de posicao para direita para dar espaco ao novo elemento
    lista->dados[i + 1] = lista->dados[i];
  }

  lista->dados[posicao] = valor;
  lista->tamanho++;

}

int removerPosicao(Lista *lista, int posicao) {
  if (estaVazia(lista)) {
    printf("lista vazia!\n");
    return -1;
  }

  if (posicao < 0 || posicao >= lista->tamanho) {
    printf("erro ao remover\n");
    return -1;
  }

  int valorRemovido = lista->dados[posicao];

  for(int i = posicao + 1; i < lista->tamanho; i++) {
    lista->dados[i - 1] = lista->dados[i];
  }

  lista->tamanho--;

  printf("elemento %d removido da posicao %d.\n", valorRemovido, posicao);
  return valorRemovido;
}

int main() {
  Lista l;
  int opcao;

  inicializar(&l);

  do {
    printf("\n\n");
    printf("1. inserir no final\n");
    printf("2. remover o final\n");
    printf("3. buscar valor\n");
    printf("4. exibir lista\n");
    printf("5. inserir na posicao\n");
    printf("6. remover na posicao\n");
    printf("7. Sair\n");
    printf("Escolha:");
    scanf("%d", &opcao);

    if(opcao == 1){
      int valor;
      printf("\nvalor: ");
      scanf("%d", &valor);
      inserirFinal(&l, valor);
    }
    else if(opcao == 2){
      removerFinal(&l);
    }
    else if(opcao == 3){
      printf("nao tem: ");
    }
    else if(opcao == 4){
      exibir(&l);
    }
    else if(opcao == 5){
      int valor, posicao;
      printf("\nvalor: ");
      scanf("%d", &valor);
      printf("\nposicao: ");
      scanf("%d", &posicao);
      inserirPosicao(&l,posicao,valor);
    }
    else if(opcao == 6){
      int posicao;
      printf("\nposicao: ");
      scanf("%d", &posicao);
      removerPosicao(&l,posicao);
    }
  } while(opcao != 7);

  return 0;
}