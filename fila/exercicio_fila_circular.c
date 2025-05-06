#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3
#define STR_MAX 30

typedef struct 
{
  char documentos[MAX][STR_MAX];
  int contador;
  int inicio;
  int fim;
} Fila;

void inicializar(Fila *fila){
  fila->contador = 0;
  fila->inicio = 0;
  fila->fim = -1;
}

int estaVazia(Fila *fila){
  return fila->contador == 0;
}
int estaCheia(Fila *fila){
  return fila->contador == MAX;
}

void enqueue(Fila *fila, char documento[]){
  if(estaCheia(fila)){
    printf("lista cheia!\n");
    return;
  }

  fila->fim = (fila->fim + 1) % MAX;   //é o mesmo que fazer fim++, porém quando fim = max, ao invés de ser fim++ será fim = 0;
  fila->contador++;

  strcpy(fila->documentos[fila->fim], documento);
  printf("adicionado a fila: '%s'\n", documento);
}

char* dequeue(Fila *fila){
  if(estaVazia(fila)){
    printf("lista vazia!\n");
    return NULL;
  }

  char *aux = fila->documentos[fila->inicio];

  fila->inicio = (fila->inicio + 1) % MAX;
  fila->contador--;

  printf("'%s' imprimido!\n", aux);
  return aux;
}

void listar(Fila *fila){
  printf("na fila: ");
  int indiceAtual = fila->inicio;

  for (int i = 0; i < fila->contador; i++){
    printf("%s - ", fila->documentos[indiceAtual]);
    indiceAtual = (indiceAtual + 1) % MAX;
  }
  printf("\n");
}

int main(){
  Fila fila;
  inicializar(&fila);
  int opcao;

  printf("\n1. Adicionar documento \n");
  printf("2. Imprimir proximo documento \n");
  printf("3. Listar fila \n");
  printf("4. Sair");

  do {
    printf("\nEscolha: ");
    scanf("%d", &opcao);
    getchar();

    if(opcao == 1){
      char documento[30];
      printf("documento: ");
      fgets(documento, 30, stdin);
      documento[strcspn(documento, "\n")] = '\0';

      enqueue(&fila, documento);
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