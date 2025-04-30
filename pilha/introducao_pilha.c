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

int pop(Stack *stack) {
  if (isEmpty(stack)){
    printf("Error: Stack Underflow\n");
    return 0;
  }

  // Decrementa o topo e retorna o valor que foi removido

  int value = stack->content[stack->top]; 
  stack->top--;
  printf("poped: %d\n", value);
  return value;

  // é o mesmo que:
  // return stack->content[stack->top--])
}

int peek(Stack *stack){
  if(isEmpty(stack)){
    printf("Error: Stack empty\n");
    return 0;
  }

  return stack->content[stack->top];
}

int main(){
  Stack myStack;

  initialize(&myStack);
  push(&myStack, 10);
  push(&myStack, 20);
  push(&myStack, 30);

  pop(&myStack);
  pop(&myStack);

  peek(&myStack);

  pop(&myStack);

  peek(&myStack);

  return 0;
}
