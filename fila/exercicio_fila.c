#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
  char nomes[MAX][30];
  int fim;
  int inicio;
} Fila;

void inicializar(Fila *fila){
  fila->inicio = 0;
  fila->fim = -1;
}

int estaVazia(Fila *fila){
  return fila->inicio > fila->fim;
}

int estaCheia(Fila *fila){
  return fila->fim == MAX - 1;
}

void enqueue(Fila *fila, char valor[]){
  if(estaCheia(fila)){
    printf("fila cheia.\n");
    return;
  }

  fila->fim++;
  strcpy(fila->nomes[fila->fim], valor);

  printf("o cliente '%s' chegou!\n", valor);

}

char* dequeue(Fila *fila){
  if(estaVazia(fila)){
    printf("fila vazia.\n");
    return NULL;
  }

  char *cliente = fila->nomes[fila->inicio];
  printf("o cliente '%s' foi atendido.\n", cliente);
  fila->inicio++;
  
  return cliente;
}

void listar(Fila *fila){
  printf("Na fila: ");
  for (int i = fila->inicio; i <= fila->fim; i++)
  {
    printf("%s - ", fila->nomes[i]);
  }
  printf("\n");
}

int main(){
  Fila fila;
  inicializar(&fila);
  int opcao;

  printf("\n1. Adicionar cliente \n");
  printf("2. Atender cliente \n");
  printf("3. Listar fila \n");
  printf("4. Sair");

  do {
    printf("\nEscolha: ");
    scanf("%d", &opcao);
    getchar();

    if(opcao == 1){
      char nome[30];
      printf("nome: ");
      fgets(nome, 30, stdin);
      nome[strcspn(nome, "\n")] = '\0';

      enqueue(&fila, nome);
    }
    else if(opcao == 2){
      dequeue(&fila);
    }
    else if(opcao == 3){
      listar(&fila);
    }

  } while (opcao != 4);

  return 1;
}