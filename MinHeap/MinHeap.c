#include "MinHeap.h"

#define SIZE 20

/*
* The heap tree is represented with an array where heap[0] is the root node
* and for each node of index i it's left child node is at (2*i + 1)
* and the right is at (2*i + 2).
* Each node's parent is at [(i-1)/2]
*/
int heap[SIZE];

void initHeap(int heap[])
{
    
}

void printHeap()
{
    printf("Printing heap: \n");
    for (int i = 0; i < SIZE; i++)
    {
            printf(" %d ", heap[i]);
    }
    printf("\n");
}

// Driver Code
int main()
{
    heap[0] = 1;

    printHeap();

    return 0;
}