#ifndef DATA_STRUCTURES_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURES_DOUBLY_LINKED_LIST_H

#include <glob.h>
#include <stdbool.h>

#include "double_list_node.h"

typedef struct
{
    DoubleListNode* head;
    size_t length;
} DoublyLinkedList;

DoublyLinkedList* init_doubly_linked_list(void);

void free_doubly_linked_list(DoublyLinkedList* list);

void insert_at_head_doubly_linked_list(DoublyLinkedList* list, int data);

void insert_at_tail_doubly_linked_list(DoublyLinkedList* list, int data);

int remove_from_head_doubly_linked_list(DoublyLinkedList* list);

int remove_from_tail_doubly_linked_list(DoublyLinkedList* list);

bool search_in_doubly_linked_list(const DoublyLinkedList* list, int target);

void display_doubly_linked_list(FILE* stream, const DoublyLinkedList* list);

#endif //DATA_STRUCTURES_DOUBLY_LINKED_LIST_H
