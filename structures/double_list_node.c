#include <malloc.h>
#include <stdlib.h>

#include "headers/double_list_node.h"

DoubleListNode* init_double_list_node(const int data, DoubleListNode* const next, DoubleListNode* const previous)
{
    DoubleListNode* node = (DoubleListNode*) malloc(sizeof(DoubleListNode));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a double list node.\n");
        exit(1);
    }

    node->data = data;
    node->next = next;
    node->previous = previous;

    return node;
}

DoubleListNode* init_double_list_node_default(const int data)
{
    DoubleListNode* node = (DoubleListNode*) malloc(sizeof(DoubleListNode));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a double list node.");
        exit(1);
    }

    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

void free_double_list_node(DoubleListNode* const node)
{ free(node); }
