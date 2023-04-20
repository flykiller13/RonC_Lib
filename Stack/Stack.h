#ifndef STACK
#define STACK

typedef struct StackNode{
    struct StackNode *next;
    int data;
} StackNode;

int pop(StackNode **top);

void push(StackNode **top, int data);

int peek(StackNode *top);

bool isEmpty(StackNode *top);

void printStack(StackNode *top);

#endif