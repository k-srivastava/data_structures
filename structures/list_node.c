#include <malloc.h>
#include <stdlib.h>

#include "headers/list_node.h"

ListNode* init_list_node(const int data, ListNode* const next)
{
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a list node.\n");
        exit(1);
    }

    node->data = data;
    node->next = next;

    return node;
}

ListNode* init_list_node_default(const int data)
{
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a list node.\n");
        exit(1);
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void free_list_node(ListNode* const node)
{ free(node); }
