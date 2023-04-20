#ifndef QUEUE
#define QUEUE

typedef struct QueueNode{
    struct QueueNode *next;
    int data;
} QueueNode;

typedef struct Queue{
    QueueNode *first, *last;
} Queue;

Queue* createQueue();

void add(Queue *queue, int data);

int pop(Queue *queue);

int peek(Queue *queue);

bool isEmpty(Queue *queue);

void printQueue(Queue *queue);

#endif