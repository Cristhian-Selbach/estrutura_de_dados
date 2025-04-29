#include <stdlib.h>
#include <stdio.h>

#define MAX 5

// Estrutura da pilha
typedef struct {
  int elementos[MAX];
  int topo;
} Pilha;

void inicializar(Pilha *pilha){
  pilha->topo = -1;
}

int estaVazia(Pilha *pilha){
  return (pilha->topo == -1);
}

int estaCheia(Pilha *pilha){
  return (pilha->topo == MAX - 1);
}

void empilhar(Pilha *pilha, int valor){

  if(estaCheia(pilha)){
    return;
  }

  pilha->topo++;
  pilha->elementos[pilha->topo] = valor;
  printf("empilhado: %d\n", valor);
}

void desempilhar(Pilha *pilha){
  if(estaVazia(pilha)){
    return;
  }

  int aux = pilha->elementos[pilha->topo];
  pilha->topo--;
  printf("desempilhado: %d\n", aux);
}

void listarPilha(Pilha *pilha){
  if(estaVazia(pilha)){
    return;
  }
  for(int i = 0; i <= pilha->topo; i++){
    printf("%d - ", pilha->elementos[i]);
  }
}

int main() {
  printf("\nPilha\n\n");

  Pilha p;
  inicializar(&p);

  empilhar(&p, 10);
  empilhar(&p, 20);
  empilhar(&p, 30);

  desempilhar(&p);

  empilhar(&p, 50);

  listarPilha(&p);
  
  return 0;
}