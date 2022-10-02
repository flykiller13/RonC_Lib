#include "Queue.h"

QueueNode *first;
QueueNode *last;

// Add an item to the end of the list
void add(int data)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));
    new_node->data = data;

    if (last != NULL)
    {
        last->next = new_node;
    }

    last = new_node;

    if (first == NULL)
    {
        first = new_node;
    }
    
}

// Remove the first item in the list. Return -1 if the list is empty
int removeNode()
{
    if (first == NULL)
    {
        return -1;
    }
    
    int temp_data = first->data;

    first = first->next;
    if (first == NULL)
    {
        last = NULL;
    }

    return temp_data;
}

// Return the top of the queue. If the queue is null returns -1.
int peek()
{
    if (first == NULL)
    {
        return -1;
    }
    
    return first->data;
}

// Return true iff the queue is empty
bool isEmpty()
{
    return first == NULL;
}

// Print the queue
void printQueue()
{
    QueueNode *p = first;
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
    printf("%s", isEmpty() ? "List is empty\n" : "List contains some elements");

    add(1);
    add(2);
    add(500);
    add(501);

    printQueue();
    printf("Top element is %d\n", peek());

    printf("%s", isEmpty() ? "List is empty\n" : "List contains some elements\n");

    removeNode();

    printQueue();

    return 0;
}