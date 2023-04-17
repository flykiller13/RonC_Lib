#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node{
    struct Node* next;
    int data;
} Node;

void appendToTail(Node* head, int d);

void removeNode(Node **head, int d);

void printLinkedList(Node* head);

void removeDups(Node **head);

#endif