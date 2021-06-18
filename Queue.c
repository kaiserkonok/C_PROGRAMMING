// Implementation of queue Data Structure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct {
    int data[SIZE + 1];
    int head, tail;
} Queue;

void enQueue(Queue *q, int item);
int deQueue(Queue *q);

int main() {
    Queue q;
    q.head = 0;
    q.tail = 0;
    enQueue(&q, 3);
    enQueue(&q, 4);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    return 0;
}

void enQueue(Queue *q, int item)
{
    if ((q -> tail + 1) % (SIZE + 1) == q -> head) {
        printf("Queue is full!\n");
    } else {
        q -> data[q ->tail] = item;
        printf("Added %d in our array\n", item);
        q -> tail = (q -> tail + 1) % (SIZE + 1);
        printf("Now, The value of tail is %d\n", q -> tail);
    }
}

int deQueue(Queue *q)
{
    int item;
    if (q -> head == q -> tail) {
        printf("Queue is empty!\n");
        printf("Reason: The value of head is %d and the value of tail is %d\n", q -> head, q -> tail);
    } else {
        item = q -> data[q -> head];
        printf("Removed %d from our array\n", item);
        printf("Now, The value of tail is %d\n", q -> tail);
        q -> head = (q -> head + 1) % (SIZE + 1);
    }
}
