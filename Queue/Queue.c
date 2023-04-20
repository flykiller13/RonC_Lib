#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Queue.h"

Queue* createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->first = q->last = NULL;

    return q;
}

// Add an item to the end of the list
void add(Queue *queue, int data)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));
    new_node->data = data;

    if (queue->last == NULL) // Queue is empty
    {
        queue->first = queue->last = new_node;
        return;
    }
    
    // Add new node at the end and change last node
    queue->last->next = new_node;
    queue->last = new_node;
}

// Remove the first item in the list. Return -1 if the list is empty
int pop(Queue *queue)
{
    if (queue->first == NULL) // Queue is empty
    {
        return -1;
    }
    // Store node to be removed
    QueueNode *tmp = queue->first;
    int tmp_data = queue->first->data;

    queue->first = queue->first->next; // Move first node

    // If first node is null change the last to null as well
    if (queue->first == NULL)
        queue->last = NULL;

    free(tmp);
    return tmp_data;
}

// Return the top of the queue. If the queue is null returns -1.
int peek(Queue *queue)
{
    if (queue->first == NULL)
    {
        return -1;
    }
    
    return queue->first->data;
}

// Return true iff the queue is empty
bool isEmpty(Queue *queue)
{
    return queue->first == NULL;
}

// Print the queue
void printQueue(Queue *queue)
{
    QueueNode *p = queue->first;
    printf("Printing queue:\n");

    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

// Driver code
int main()
{
    Queue *q = createQueue();

    add(q, 1);
    add(q, 2);
    add(q, 4);
    add(q, 5);

    printQueue(q);

    printf("Popped %d\n", pop(q));

    printQueue(q);

    printf("First elem: %d\n", peek(q));

    return 0;
}