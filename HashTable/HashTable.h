#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct Node{
    struct Node* next;
    int data;
} Node;

void addToList(Node* head, int data);

int hash(int key);

void addItem(int key);

void removeItem(int key);

bool find(int key);

void printList(Node* head);

void printTable(Node* arr[]);

#endif