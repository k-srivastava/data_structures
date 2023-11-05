#ifndef DATA_STRUCTURES_BINARY_SEARCH_TREE_H
#define DATA_STRUCTURES_BINARY_SEARCH_TREE_H

#include <glob.h>
#include <stdbool.h>
#include <bits/types/FILE.h>

#include "binary_tree_node.h"

typedef struct
{
    BinaryTreeNode* root;
} BinarySearchTree;

BinarySearchTree* init_binary_search_tree(void);

void free_binary_search_tree(BinarySearchTree* tree);

void insert_in_binary_search_tree(BinarySearchTree* tree, int data);

void remove_from_binary_search_tree(BinarySearchTree* tree, int data);

bool search_in_binary_search_tree(BinarySearchTree* tree, int target);

int min_in_binary_search_tree(const BinarySearchTree* tree);

int max_in_binary_search_tree(const BinarySearchTree* tree);

void display_binary_search_tree(FILE* stream, const BinarySearchTree* tree, BinaryTreeTraversal traversal);

#endif //DATA_STRUCTURES_BINARY_SEARCH_TREE_H
