#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
  char elementos[MAX];
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

void push(Pilha *pilha, char elemento){
  if(estaCheia(pilha)){
    printf("Pilha cheia!");
    return;
  }

  pilha->topo++;
  pilha->elementos[pilha->topo] = elemento;

}

char pop(Pilha *pilha){
  if(estaVazia(pilha)){
    printf("Pilha vazia!");
    return '\0';
  }

  char aux = pilha->elementos[pilha->topo];
  pilha->topo--;
  return aux;
}

char topo(Pilha *pilha){
  if(estaVazia(pilha)) return '\0';
  return pilha->elementos[pilha->topo];
}

int main(){
  Pilha pilha;
  inicializar(&pilha);

  while (1 == 1)
  {
    printf("insira a expressao: ");
    char entrada[100];
    fgets(entrada, 100, stdin);
  
    for (int i = 0; i < (int)strlen(entrada); i++) {
  
      if(entrada[i] == '(' || entrada[i] == '{' || entrada[i] == '['){
        push(&pilha, entrada[i]);
      }
  
      else if (
        (entrada[i] == ')' && topo(&pilha) == '(') ||
        (entrada[i] == '}' && topo(&pilha) == '{') ||
        (entrada[i] == ']' && topo(&pilha) == '[')
      ) {
        pop(&pilha);
      }
  
      else if(entrada[i] == ')' || entrada[i] == '}' || entrada[i] == ']'){
        if (estaVazia(&pilha)) {
          printf("Saida: Parenteses nao balanceados. (fechamento sem abertura).\n");
          return 0;
        }
      }
  
    }
  
    if(estaVazia(&pilha)){
      printf("Saida: Parenteses balanceados.\n");
    }
    else {
      printf("Saida: Parenteses nao balanceados.\n");
    }
  }
  
 

  return 0;
}