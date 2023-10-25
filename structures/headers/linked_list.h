#ifndef DATA_STRUCTURES_LINKED_LIST_H
#define DATA_STRUCTURES_LINKED_LIST_H

#include <glob.h>
#include <stdbool.h>

#include "list_node.h"

typedef struct
{
    ListNode* head;
    size_t length;
} LinkedList;

LinkedList* init_linked_list(void);

void free_linked_list(LinkedList* list);

void insert_at_head_linked_list(LinkedList* list, int data);

void insert_at_tail_linked_list(LinkedList* list, int data);

int remove_from_head_linked_list(LinkedList* list);

int remove_from_tail_linked_list(LinkedList* list);

bool search_in_linked_list(const LinkedList* list, int target);

void display_linked_list(FILE* stream, const LinkedList* list);

#endif //DATA_STRUCTURES_LINKED_LIST_H
