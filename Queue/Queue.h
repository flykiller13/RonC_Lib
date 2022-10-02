#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct QueueNode{
    struct QueueNode *next;
    int data;
} QueueNode;

void add(int data);

int removeNode();

int peek();

bool isEmpty();

void printQueue();
