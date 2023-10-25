#ifndef DATA_STRUCTURES_LIST_NODE_H
#define DATA_STRUCTURES_LIST_NODE_H

typedef struct ListNode
{
    int data;
    struct ListNode* next;
} ListNode;

ListNode* init_list_node(int data, ListNode* next);

ListNode* init_list_node_default(int data);

void free_list_node(ListNode* node);

#endif //DATA_STRUCTURES_LIST_NODE_H
