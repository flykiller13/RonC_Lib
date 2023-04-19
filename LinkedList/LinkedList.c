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
        printf(" -> %d", n->data);
    }
    printf("\n");
}

// Removes duplicates from given list
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
                Node *tmp = runner->next;
                runner->next = runner->next->next;
                free(tmp);
                printLinkedList(*head);
            }
            runner = runner->next != NULL ? runner->next : runner; // Check if last node was deleted
        }
        current = current->next;
    }
}

// Returns Kth to last node
int KthToLast(Node* head, int k)
{
    Node *p1 = head;
    Node *p2 = head;

    // Move p1 k steps forward
    for (int i = 0; i < k; i++)
    {
        if (p1 == NULL) {return -1;} // Out of bounds
        p1 = p1->next;
    }
    
    // Move both pointers until p1 reaches the end, p2 reaches the kth to last node
    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p2->data;
}

int main(){

    Node *head = malloc((sizeof(Node))); // Create head node
    head->data = 1; // Set new node data

    appendToTail(head, 1);
    appendToTail(head, 2);
    appendToTail(head, 3);
    appendToTail(head, 2);
    appendToTail(head, 5);
    appendToTail(head, 2);
    appendToTail(head, 5);
    printLinkedList(head);
    int k = 5;
    printf("%dth to last node: %d\n", k, KthToLast(head, k));

    return 0;
}