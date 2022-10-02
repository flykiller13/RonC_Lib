#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* add(int data);

void remove(int data);

TreeNode* find(int data);

