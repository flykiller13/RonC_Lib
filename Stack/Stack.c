#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

// Remove the top item from the stack and return it. Return -1 if the stack is empty
int pop(StackNode **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    // Store the data and remove the top node
    int temp_data = (*top)->data;
    StackNode *tmp = *top;
    *top = (*top)->next;
    free(tmp);

    return temp_data;
}

// Add an item to the top of the stack
void push(StackNode **top, int data)
{
    StackNode *new_node = malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = *top;

    *top = new_node;
    printf("Added %d at %p\n", (*top)->data, top);
}

// Return the top of the stack
int peek(StackNode *top)
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    return top->data;
}

// Return true iff the stack is empty
bool isEmpty(StackNode *top)
{
    return top == NULL;
}

// Print the stack
void printStack(StackNode *top)
{
    StackNode *p = top;
    printf("Printing stack:\n");

    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

// Driver code
int main()
{
    StackNode *top = malloc(sizeof(StackNode)); // Create first node

    top->data = 1;

    push(&top, 2);
    push(&top, 3);
    push(&top, 4);

    printStack(top);

    printf("Top elem: %d\n", peek(top));

    printf("Popped %d\n", pop(&top));
    printf("Popped %d\n", pop(&top));

    printStack(top);

    return 0;
}