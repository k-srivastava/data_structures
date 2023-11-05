#include <malloc.h>
#include <stdlib.h>

#include "headers/binary_tree_node.h"

BinaryTreeNode* init_binary_tree_node(const int data, BinaryTreeNode* const left, BinaryTreeNode* const right)
{
    BinaryTreeNode* node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a binary tree node.\n");
        exit(1);
    }

    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}

BinaryTreeNode* init_binary_tree_node_default(const int data)
{
    BinaryTreeNode* node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a binary tree node.\n");
        exit(1);
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void free_binary_tree_node(BinaryTreeNode* const node)
{ free(node); }
