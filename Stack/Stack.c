#include "Stack.h"

StackNode *top;

// Remove the top item from the stack and return it. Return -1 if the stack is empty
int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    // Store the data and remove the top node
    int temp_data = top->data;
    top = top->next;

    return temp_data;
}

// Add an item to the top of the stack
void push(int data)
{
    StackNode *new_node = malloc(sizeof(StackNode));
    new_node->data = data;

    new_node->next = top;
    top = new_node;
}

// Return the top of the stack
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    return top->data;
}

// Return true iff the stack is empty
bool isEmpty()
{
    return top == NULL;
}

// Print the stack
void printStack()
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
    push(1);
    push(2);
    push(3);
    push(4);

    printf("Popped: %d\n", pop());
    printf("Top item: %d\n", peek());

    printStack();

    pop();
    pop();
    pop();
    pop();

    push(7);

    printStack();

    return 0;
}