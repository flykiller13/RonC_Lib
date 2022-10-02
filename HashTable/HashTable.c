#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HashTable.h"

#define SIZE 15
Node* hashtable[SIZE]; // Create an array of linked lists

int hash_func(int key)
{
    return key%SIZE; // Use the size of the array to create a key
}

void addItem(int key)
{
    int keyIndex = hash_func(key);

    Node *new_node = malloc((sizeof(Node))); // Create new node and set data
    new_node->data = key; // Set key as data

    new_node->next = hashtable[keyIndex]; // Insert new node at the front of a list
    hashtable[keyIndex] = new_node; // Set new node as head of list

    printf("Added %d at %p\n", hashtable[keyIndex]->data, hashtable[keyIndex]);
}

void removeItem(int key)
{
    int keyIndex = hash_func(key);

    // Find the item to remove
    Node *p = hashtable[keyIndex];

    if (p != NULL && p->data == key) // Check if the head matches the key
    {
        hashtable[keyIndex] = hashtable[keyIndex]->next;
        return;
    }

    while (p->next != NULL) // Traver through the list
    {
        if (p->next->data == key)
        {
            p->next = p->next->next; // Remove the next node
            return;
        }

        p = p->next;
    }
    
    printf("Key not found");
}

bool find(int key) // Finds the item - O(1) - O(n)
{
    int keyIndex = hash_func(key);
    Node *p = hashtable[keyIndex];
    
    while(p != NULL)
    {
        if (p->data == key)
        {
            return true;
        }

        p = p->next;
    }

    return false;
}

void printList(Node* head)
{
    while (head != NULL)
    {
        printf("  %d  ",head->data);
        head = head->next;
    }
    
    printf("\n");
}

void printTable(Node* arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if(arr[i] != NULL)
        {
            printList(arr[i]);
        }
    }
}

// Driver code
int main()
{
    
    addItem(5);
    addItem(7);
    addItem(1);
    addItem(20);
    removeItem(20);

    printTable(hashtable);

    return 0;
}