#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct StackNode{
    struct StackNode *next;
    int data;
} StackNode;

int pop();

void push(int data);

int peek();

bool isEmpty();

void printStack();
