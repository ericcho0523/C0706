#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAX 100

typedef struct {
  int data[MAX];
  int front;
  int rear;
} Queue;


void initQueue(Queue *q) {
  q->front = 0; 
  q->rear = -1; 
}

int isEmpty(Queue *q) {
  return q->front > q->rear;
}

int isFull(Queue *q) {
  return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
  if (isFull(q)) {
  printf("Queue Overflow.\n");
  return;
}
  q->data[++(q->rear)] = value;
}

int dequeue(Queue *q) {
  if (isEmpty(q)) {
  printf("Queue Underflow.\n");
  return -1;
}
  return q->data[(q->front)++];
}

int main(){
  Queue q;
  initQueue(&q);
  isEmpty(&q);
  isFull(&q);
  enqueue(&q,10);
  dequeue(&q,1);
}