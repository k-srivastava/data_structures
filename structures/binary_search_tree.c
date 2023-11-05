#include <malloc.h>
#include <stdlib.h>

#include "headers/binary_search_tree.h"

BinarySearchTree* init_binary_search_tree(void)
{
    BinarySearchTree* tree = (BinarySearchTree*) malloc(sizeof(BinarySearchTree));

    if (tree == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a binary search tree.\n");
        exit(1);
    }

    tree->root = NULL;
    return tree;
}

void free_binary_search_tree(BinarySearchTree* const tree)
{
    if (tree->root == NULL)
    {
        free(tree);
        return;
    }

    free(tree);
}

void insert_in_binary_search_tree(BinarySearchTree* const tree, const int data)
{
    if (tree->root == NULL)
    {
        tree->root = init_binary_tree_node_default(data);
        return;
    }

    BinaryTreeNode* parent = tree->root;
    BinaryTreeNode* node = tree->root;
    bool is_left_child = true;

    while (node != NULL)
    {
        parent = node;
        if (node->data == data)
        {
            fprintf(stderr, "Cannot enter a duplicate value: %d, in a binary search tree.\n", data);
            return;
        }

        else if (node->data > data)
        {
            node = node->left;
            is_left_child = true;
        }

        else
        {
            node = node->right;
            is_left_child = false;
        }
    }

    if (is_left_child)
        parent->left = init_binary_tree_node_default(data);
    else
        parent->right = init_binary_tree_node_default(data);
}

BinaryTreeNode* delete_binary_tree_node(BinaryTreeNode* const root, const int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete_binary_tree_node(root->left, data);
    else if (data > root->data)
        root->right = delete_binary_tree_node(root->right, data);

    else
    {
        if (root->left == NULL)
        {
            BinaryTreeNode* temp = root->right;
            free_binary_tree_node(root);
            return temp;
        }

        if (root->right == NULL)
        {
            BinaryTreeNode* temp = root->left;
            free_binary_tree_node(root);
            return temp;
        }

        BinaryTreeNode* current = root->right;
        while (current->left != NULL)
            current = current->left;

        BinaryTreeNode* temp = current;
        root->data = temp->data;
        root->right = delete_binary_tree_node(root->right, temp->data);
    }

    return root;
}

void remove_from_binary_search_tree(BinarySearchTree* const tree, const int data)
{ tree->root = delete_binary_tree_node(tree->root, data); }

bool search_in_binary_search_tree(BinarySearchTree* const tree, const int data)
{
    BinaryTreeNode* current = tree->root;
    while (current != NULL)
    {
        if (current->data == data)
            return true;

        current = current->data > data ? current->left : current->right;
    }

    return false;
}

int min_in_binary_search_tree(const BinarySearchTree* const tree)
{
    if (tree->root == NULL)
    { return -1; }

    BinaryTreeNode* parent = tree->root;
    BinaryTreeNode* node = tree->root;

    while (node != NULL)
    {
        parent = node;
        node = node->left;
    }

    return parent->data;
}

int max_in_binary_search_tree(const BinarySearchTree* const tree)
{
    if (tree->root == NULL)
    { return -1; }

    BinaryTreeNode* parent = tree->root;
    BinaryTreeNode* node = tree->root;

    while (node != NULL)
    {
        parent = node;
        node = node->right;
    }

    return parent->data;
}

void display_binary_search_tree_pre_order(FILE* const stream, const BinaryTreeNode* const node)
{
    if (node != NULL)
    {
        fprintf(stream, "%d, ", node->data);
        display_binary_search_tree_pre_order(stream, node->left);
        display_binary_search_tree_pre_order(stream, node->right);
    }
}

void display_binary_search_tree_in_order(FILE* const stream, const BinaryTreeNode* const node)
{
    if (node != NULL)
    {
        display_binary_search_tree_in_order(stream, node->left);
        fprintf(stream, "%d, ", node->data);
        display_binary_search_tree_in_order(stream, node->right);
    }
}

void display_binary_search_tree_post_order(FILE* const stream, const BinaryTreeNode* const node)
{
    if (node != NULL)
    {
        display_binary_search_tree_post_order(stream, node->left);
        display_binary_search_tree_post_order(stream, node->right);
        fprintf(stream, "%d, ", node->data);
    }
}

void
display_binary_search_tree(FILE* const stream, const BinarySearchTree* const tree, const BinaryTreeTraversal traversal)
{
    fprintf(stream, "Binary Search Tree { ");

    switch (traversal)
    {
        case BT_PRE_ORDER:
            display_binary_search_tree_pre_order(stream, tree->root);
            break;

        case BT_IN_ORDER:
            display_binary_search_tree_in_order(stream, tree->root);
            break;

        case BT_POST_ORDER:
            display_binary_search_tree_post_order(stream, tree->root);
            break;
    }

    fprintf(stream, "}\n");
}
