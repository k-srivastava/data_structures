#ifndef DATA_STRUCTURES_CIRCULAR_LINKED_LIST_H
#define DATA_STRUCTURES_CIRCULAR_LINKED_LIST_H

#include <glob.h>
#include <stdbool.h>

#include "list_node.h"

typedef struct
{
    ListNode* head;
    size_t length;
} CircularLinkedList;

CircularLinkedList* init_circular_linked_list(void);

void free_circular_linked_list(CircularLinkedList* list);

void insert_at_head_circular_linked_list(CircularLinkedList* list, int data);

void insert_at_tail_circular_linked_list(CircularLinkedList* list, int data);

int remove_from_head_circular_linked_list(CircularLinkedList* list);

int remove_from_tail_circular_linked_list(CircularLinkedList* list);

bool search_in_circular_linked_list(const CircularLinkedList* list, int target);

void display_circular_linked_list(FILE* stream, const CircularLinkedList* list);

#endif //DATA_STRUCTURES_CIRCULAR_LINKED_LIST_H
