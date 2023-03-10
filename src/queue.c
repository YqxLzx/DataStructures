#include <stdio.h>
#include <stdlib.h>
#include "../data.h"

#define MAX_SIZE 4

typedef struct
{
    Data storages[MAX_SIZE];
    int length;
    int front;
} Queue;

Queue createQueue()
{
    Queue queue;
    queue.length = 0;
    queue.front = 0;
    return queue;
}

int isFull(Queue *queue)
{
    return queue->length == MAX_SIZE;
}

int isEmpty(Queue *queue)
{
    return queue->length == 0;
}

void enqueue(Queue *queue, Data data)
{
    if (isFull(queue))
    {
        printf("enqueue error: queue is full\n");
        return;
    }
    int rear = (queue->front + queue->length) % MAX_SIZE;
    printf("rear:%d\n",rear);
    if (rear >= MAX_SIZE)
    {
        rear -= MAX_SIZE;
    }
    queue->storages[rear] = data;
    queue->length++;
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("dequeue error: queue is empty\n");
        return;
    }
    queue->storages[queue->front] = (Data){0, 0};
    queue->front++;
    queue->length--;
    if (queue->front == MAX_SIZE)
    {
        queue->front = 0;
    }
}

Data peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("peek error: queue is empty\n");
        return (Data){0, 0};
    }
    return queue->storages[queue->front];
}

void clear(Queue *queue)
{
    for (int i = 0; i < queue->length; i++)
    {
        queue->storages[(queue->front + i) % MAX_SIZE] = (Data){0, 0};
    }
    queue->length = 0;
    queue->front = 0;
}

int getSize(Queue *queue)
{
    return queue->length;
}


void printQueue(Queue *queue){
    for(int i = 0; i < queue->length ; i++){
        printf("i:%d,value:%d\n",i,queue->storages[i].value);
    }
    printf("current head:%d",queue->storages[queue->front].value);
}

int main()
{
    Queue queue = createQueue();

    Data data1 = {0, 50};
    Data data2 = {1, 100};
    Data data3 = {1, 200};
    Data data4 = {1, 300};
    enqueue(&queue, data1);
    enqueue(&queue, data2);
    enqueue(&queue, data3);

    enqueue(&queue, data4);
    dequeue(&queue);
    enqueue(&queue, data4);
    printQueue(&queue);
    return 0;
}
