#ifndef DATA_STRUCTURES_DOUBLE_LIST_NODE_H
#define DATA_STRUCTURES_DOUBLE_LIST_NODE_H

typedef struct DoubleListNode
{
    int data;
    struct DoubleListNode* next;
    struct DoubleListNode* previous;
} DoubleListNode;

DoubleListNode* init_double_list_node(int data, DoubleListNode* next, DoubleListNode* previous);

DoubleListNode* init_double_list_node_default(int data);

void free_double_list_node(DoubleListNode* node);

#endif //DATA_STRUCTURES_DOUBLE_LIST_NODE_H
