#include "BinTree.h"

TreeNode *root;

TreeNode* add(int data)
{
    TreeNode *new_node = malloc(sizeof(TreeNode));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void remove(int data)
{
    TreeNode *p = root;
    
}

// Driver Code
int main()
{
    return 0;
}