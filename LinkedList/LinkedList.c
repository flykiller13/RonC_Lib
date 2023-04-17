#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

void appendToTail(Node* head, int d)
{
    Node *end = malloc((sizeof(Node))); // Create new node
    end->data = d; // Set new node data
    Node *n = head;

    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = end;
}

void removeNode(Node **head, int d)
{
    if ((*head)->data == d)
    {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    Node *n = *head;

    while (n->next != NULL)
    {
        if (n->next->data == d)
        {
            Node *tmp = n->next;
            n->next = n->next->next;
            free(tmp);
            return;
        }
        n = n->next;
    }
}

void printLinkedList(Node* head)
{
    Node *n = head;
    printf("%d", n->data);
    while (n->next != NULL)
    {
        n = n->next;
        printf("->%d", n->data);
    }
    printf("\n");
}

void removeDups(Node **head)
{
    Node *current = *head;
    
    while (current != NULL)
    {
        Node *runner = current;
        while (runner->next != NULL)
        {
            if (runner->next->data == current->data)
            {
                printf("deleting %d \n", runner->next->data);
                removeNode(&runner, current->data);
            }
            runner = runner->next;
        }
        current = current->next;
    }
    
}

int main(){

    Node *head = malloc((sizeof(Node))); // Create head node
    head->data = 1; // Set new node data

    appendToTail(head, 2);
    appendToTail(head, 3);
    appendToTail(head, 2);
    appendToTail(head, 5);
    appendToTail(head, 2);
    appendToTail(head, 2);
    appendToTail(head, 5);
    removeDups(&head);
    printLinkedList(head);

    return 0;
}