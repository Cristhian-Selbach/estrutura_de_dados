#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct {
  char description[50];
  int code;
} Product;

typedef struct {
  int top;
  Product elements[MAX];
} Stack;

void initialize(Stack *stack){
  stack->top = -1;
}

int isEmpty(Stack *stack){
  return stack->top == -1;
}

int isFull(Stack *stack){
  return stack->top == MAX - 1;
}

void push(Stack *stack, Product product){
  if(isFull(stack)){
    printf("Stack is full!");
    return;
  }

  stack->top++;
  stack->elements[stack->top] = product;
  printf("product added!");
}

Product pop(Stack *stack) {
  if (isEmpty(stack)) {
      printf("Stack is empty!\n");
      Product empty = {"", -1};  // ordem correta: description, depois code
      return empty;
  }

  Product aux = stack->elements[stack->top];
  stack->top--;
  printf("Product removed:\nCode: %d - %s\n", aux.code, aux.description);
  return aux;
}

void show(Stack stack){

  if (isEmpty(&stack)) {
    return ;
  }

  for (int i = 0; i <= stack.top; i++) {
    printf("code: %d, description: %s\n", stack.elements[i].code, stack.elements[i].description);
  }
  printf("\n"); 
}

int main(){
  Stack stack;
  initialize(&stack);

  int option;
  do
  {
    printf("\n\nSelect one:\n1 - Add Product\n2 - Remove Product\n3 - Show Stack\n4 - Exit\n");
    scanf("%d", &option);

    if(option == 1){
      Product product;

      printf("\n\ncode:");
      scanf("%d", &product.code);
      getchar(); // limpa o \n
      printf("\ndescription:\n");
      fgets(product.description, 50, stdin);

      push(&stack, product);
      
    } else if (option == 2){
      pop(&stack);
    } else if (option == 3){
      show(stack);
    }
  } while (option != 4);
  
}