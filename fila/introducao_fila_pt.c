#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
  int elementos[MAX];
  int inicio;
  int fim;
} Fila;

void inicializar(Fila *fila){
  fila->fim = -1;
  fila->inicio = 0; 
  // é zero pois ao adicionar o primeiro elemento, o fim será fim++(0); e quando só há um elemento tanto fim quanto inicio devem ser iguais
}

int estaCheia(Fila *fila){
  return (fila->fim == MAX - 1);
}

int estaVazia(Fila *fila){
  return (fila->inicio > fila->fim);
}

void enqueue(Fila *fila, int valor) {

  if (estaCheia(fila)) {
    printf("Erro: A fila esta cheia! \n");
    return; // Sai da função se a fila estiver cheia
  }

  fila->fim++;
  fila->elementos[fila->fim] = valor;
  printf("Adicionado %d a fila.\n", valor);
}

int dequeue(Fila *fila){
  if (estaVazia(fila)) {
    printf("Erro: A fila esta vazia! \n");
    return; // Sai da função se a fila estiver vazia
  }

  int aux = fila->elementos[fila->inicio];
  fila->inicio++;

  printf("Removido %d da fila.\n", aux);
  return aux; // Retorna o valor removido
}

void mostrarFila(Fila *fila) {

  if (estaVazia(fila)) {
    printf("A fila esta vazia.\n");
    return;
  }

  printf("Elementos da fila (inicio para fim): ");
  // Percorre o array a partir do 'inicio' até o 'fim'
  for (int i = fila->inicio; i <= fila->fim; i++) {
      printf("%d ", fila->elementos[i]);
  }
  printf("\n");
}

int main() {
  Fila minhaFila;

  // Inicializa a fila
  inicializar(&minhaFila);

  enqueue(&minhaFila, 10);
  enqueue(&minhaFila, 20);
  enqueue(&minhaFila, 30);

  mostrarFila(&minhaFila); // Deve mostrar: 10 20 30

  dequeue(&minhaFila); // Remove o 10
  mostrarFila(&minhaFila); // Deve mostrar: 20 30

  enqueue(&minhaFila, 40);
  enqueue(&minhaFila, 50);
  enqueue(&minhaFila, 60); // Tentando adicionar quando a fila está cheia

  mostrarFila(&minhaFila); // Deve mostrar: 20 30 40 50

  dequeue(&minhaFila); // Remove o 20
  dequeue(&minhaFila); // Remove o 30
  mostrarFila(&minhaFila); // Deve mostrar: 40 50

  dequeue(&minhaFila); // Remove o 40
  dequeue(&minhaFila); // Remove o 50
  dequeue(&minhaFila); // Tentando remover quando a fila está vazia

  mostrarFila(&minhaFila); // Deve mostrar: A fila esta vazia.

  return 0;
}