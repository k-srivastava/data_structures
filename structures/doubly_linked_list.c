#include <malloc.h>
#include <stdlib.h>

#include "headers/doubly_linked_list.h"

DoublyLinkedList* init_doubly_linked_list(void)
{
    DoublyLinkedList* list = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));

    if (list == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a doubly linked list.\n");
        exit(1);
    }

    list->head = NULL;
    list->length = 0;

    return list;
}

void free_doubly_linked_list(DoublyLinkedList* const list)
{
    if (list->head == NULL)
    {
        free(list);
        return;
    }

    DoubleListNode* current = list->head;
    while (current->next != NULL)
    {
        DoubleListNode* const next = current->next;
        free_double_list_node(current);

        current = next;
    }

    list->length = 0;
    free(list);
}

void insert_at_head_doubly_linked_list(DoublyLinkedList* const list, const int data)
{
    if (list->head == NULL)
    {
        list->head = init_double_list_node_default(data);
        list->length = 1;

        return;
    }

    DoubleListNode* const new_head = init_double_list_node(data, list->head, NULL);
    list->head->previous = new_head;
    list->head = new_head;

    list->length++;
}

void insert_at_tail_doubly_linked_list(DoublyLinkedList* const list, const int data)
{
    if (list->head == NULL)
    {
        list->head = init_double_list_node_default(data);
        list->length = 1;

        return;
    }

    DoubleListNode* current = list->head;
    while (current->next != NULL)
        current = current->next;

    current->next = init_double_list_node(data, NULL, current);
    list->length++;
}

int remove_from_head_doubly_linked_list(DoublyLinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "Cannot remove the head of an empty doubly linked list.\n");
        exit(1);
    }

    DoubleListNode* const old_head = list->head;
    list->head = list->head->next;
    list->head->previous = NULL;

    const int data = old_head->data;
    free_double_list_node(old_head);
    list->length--;

    return data;
}

int remove_from_tail_doubly_linked_list(DoublyLinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "Cannot remove the tail of a doubly linked list.\n");
        exit(1);
    }

    DoubleListNode* current = list->head;
    while (current->next != NULL && current->next->next != NULL)
        current = current->next;

    DoubleListNode* const old_tail = current->next;
    current->next = NULL;

    const int data = old_tail->data;
    free_double_list_node(old_tail);
    list->length--;

    return data;
}

bool search_in_doubly_linked_list(const DoublyLinkedList* const list, const int target)
{
    if (list->head == NULL)
        return false;

    DoubleListNode* current = list->head;

    while (current != NULL)
    {
        if (current->data == target)
            return true;

        current = current->next;
    }

    return false;
}

void display_doubly_linked_list(FILE* const stream, const DoublyLinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stream, "Doubly Linked List {}\n");
        return;
    }

    fprintf(stream, "Doubly Linked List {");

    DoubleListNode* current = list->head;
    while (current->next != NULL)
    {
        fprintf(stream, " %d <->", current->data);
        current = current->next;
    }

    fprintf(stream, " %d }\n", current->data);
}
