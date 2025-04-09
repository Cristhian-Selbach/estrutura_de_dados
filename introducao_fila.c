#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
  int data[SIZE];
  int front;
  int rear;
} Queue;

void initialize(Queue *queue){
  queue->rear = -1;
  queue->front = 0;
}

int isEmpty(Queue *queue){
  return queue->front > queue->rear;
}

int isFull(Queue *queue){
  return queue->rear == SIZE - 1;
}

void enqueue(Queue *queue, int value){

  if(isFull(queue)){
    printf("Queue is full!\n");
    return;
  }

  queue->rear++;
  queue->data[queue->rear] = value;
  printf("enqueued: %d\n", value);
}

int dequeue(Queue *queue){
  if(isEmpty(queue)){
    printf("Queue is empty!\n");
    return -1;
  }
  
  int aux = queue->data[queue->front];
  queue->front++;
  return aux;
}

int peek(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }
  printf("Queue: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->data[i]);
  }
  printf("\n");
}

int main() {
  Queue myQueue;
  initialize(&myQueue);

  enqueue(&myQueue, 10);
  enqueue(&myQueue, 20);
  enqueue(&myQueue, 30);

  peek(&myQueue);

  printf("Removed: %d\n", dequeue(&myQueue));
  printf("Removed: %d\n", dequeue(&myQueue));
  printf("Removed: %d\n", dequeue(&myQueue));
  printf("Removed: %d\n", dequeue(&myQueue));
  
  peek(&myQueue);

  return 0;
}