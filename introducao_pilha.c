#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
  int content[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *stack){
  stack->top = -1; //inicializa o topo para indicar uma pilha vazia
}

bool isEmpty(Stack *stack){
  return stack->top == -1; //é o mesmo que if(stack.top == 1){ return true } 
}

bool isFull(Stack *stack) {
  // If o topo é MAX_SIZE - 1, então a pilha está cheia
  return stack->top == MAX_SIZE - 1;  
}

void push(Stack *stack, int value){
  if(isFull(stack)){
    printf("Error: Stack Overflow\n");
    return;
  }
  stack->top++; // Aumenta o topo
  stack->content[stack->top] = value; //Insere o Value na posição topo
  printf("stacked: %d\n", value);
}

void pop(Stack *stack) {
  if (isEmpty(stack)){
    printf("Error: Stack Underflow\n");
  }

  return stack->content[stack->top--]; //Decrementa o topo e retorna o valor que foi removido
  
  // é o mesmo que:
  // int valor = stack->elementos[stack->top]; 
  // stack->top--;
  // return valor;
}

int main(){
  printf("hello");
  return 0;
}