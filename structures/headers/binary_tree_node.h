#ifndef DATA_STRUCTURES_BINARY_TREE_NODE_H
#define DATA_STRUCTURES_BINARY_TREE_NODE_H

typedef enum
{
    BT_PRE_ORDER,
    BT_IN_ORDER,
    BT_POST_ORDER
} BinaryTreeTraversal;

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* init_binary_tree_node(int data, BinaryTreeNode* left, BinaryTreeNode* right);

BinaryTreeNode* init_binary_tree_node_default(int data);

void free_binary_tree_node(BinaryTreeNode* node);

#endif //DATA_STRUCTURES_BINARY_TREE_NODE_H
