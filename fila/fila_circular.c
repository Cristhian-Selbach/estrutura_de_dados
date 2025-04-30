#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct 
{
  int elementos[MAX];
  int inicio;
  int fim;
  int contador;
} FilaCircular;

void inicializar(FilaCircular *fila){
  fila->fim = -1;
  fila->inicio = 0;
  fila->contador = 0;
}

int estaCheia(FilaCircular *fila){
  return (fila->contador == MAX); //retorna 1 se cheia
}

int estaVazia(FilaCircular *fila){
  return (fila->contador == 0); //retorna 1  se vazia
}

void enqueue(FilaCircular *fila, int valor){
  if(estaCheia(fila)){
    printf("fila cheia!\n");
    return;
  }


  fila->fim = (fila->fim + 1) % MAX;
  //é o mesmo que fazer fim++, porém quando fim = max, ao invés de ser fim++ será fim = 0;

  fila->elementos[fila->fim] = valor;
  fila->contador++;
  printf("- adicionado %d a fila.\n", valor);
}

int dequeue(FilaCircular *fila){
  if(estaVazia(fila)){
    printf("fila vazia!\n");
    return -1;
  }

  int aux = fila->elementos[fila->inicio]; //armazenar temporariamente o valor que será removido

  fila->inicio = (fila->inicio + 1) % MAX;
  //é o mesmo que fazer inicio++, porém quando inicio = max, ao invés de ser inicio++ será inicio = 0;

  fila->contador--;
  printf("Removido %d da fila.\n", aux);
  return aux;
}

void mostrarFila(FilaCircular *fila){
  if(estaVazia(fila)){
    printf("fila vazia!\n");
    return;
  }

  int indiceAtual = fila->inicio;

  for (int i = 0; i < fila->contador; i++) {
    printf("%d \n", fila->elementos[indiceAtual]);
    indiceAtual = (indiceAtual + 1) % MAX;
  }
  printf("\n");
}

int main() {
  FilaCircular minhaFila;

  inicializar(&minhaFila);

  enqueue(&minhaFila, 10);
  enqueue(&minhaFila, 20);
  enqueue(&minhaFila, 30);

  mostrarFila(&minhaFila); // Deve mostrar: 10 20 30 

  enqueue(&minhaFila, 40); // Deve mostrar: fila cheia

  dequeue(&minhaFila);
  mostrarFila(&minhaFila); // Deve mostrar: 20 30

  enqueue(&minhaFila, 40); 
  mostrarFila(&minhaFila); // Deve mostrar: 20 30 40

  return 0;
}
