#include <malloc.h>
#include <stdlib.h>

#include "headers/circular_linked_list.h"

CircularLinkedList* init_circular_linked_list(void)
{
    CircularLinkedList* list = (CircularLinkedList*) malloc(sizeof(CircularLinkedList));

    if (list == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a circular linked list.\n");
        exit(1);
    }

    list->head = NULL;
    list->length = 0;

    return list;
}

void free_circular_linked_list(CircularLinkedList* const list)
{
    if (list->head == NULL)
    {
        free(list);
        return;
    }

    ListNode* current = list->head;
    while (current->next != list->head)
    {
        ListNode* const next = current->next;
        free_list_node(current);

        current = next;
    }

    list->length = 0;
    free(list);
}

void insert_at_head_circular_linked_list(CircularLinkedList* const list, const int data)
{
    if (list->head == NULL)
    {
        list->head = init_list_node_default(data);
        list->head->next = list->head;
        list->length = 1;

        return;
    }

    ListNode* current = list->head;
    while (current->next != list->head)
        current = current->next;

    list->head = init_list_node(data, list->head);
    current->next = list->head;

    list->length++;
}

void insert_at_tail_circular_linked_list(CircularLinkedList* const list, const int data)
{
    if (list->head == NULL)
    {
        list->head = init_list_node_default(data);
        list->head->next = list->head;
        list->length = 1;

        return;
    }

    ListNode* current = list->head;
    while (current->next != list->head)
        current = current->next;

    current->next = init_list_node(data, list->head);
    list->length++;
}

int remove_from_head_circular_linked_list(CircularLinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "Cannot remove the head of an empty circular linked list.\n");
        exit(1);
    }

    ListNode* const old_head = list->head;
    ListNode* current = list->head;

    while (current->next != list->head)
        current = current->next;

    list->head = list->head->next;
    current->next = list->head;

    const int data = old_head->data;
    free_list_node(old_head);
    list->length--;

    return data;
}

int remove_from_tail_circular_linked_list(CircularLinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "Cannot remove the tail of an empty circular linked list.\n");
        exit(1);
    }

    ListNode* current = list->head;
    while (current->next != list->head && current->next->next != list->head)
        current = current->next;

    ListNode* const old_tail = current->next;
    current->next = list->head;

    const int data = old_tail->data;
    free_list_node(old_tail);
    list->length--;

    return data;
}

bool search_in_circular_linked_list(const CircularLinkedList* const list, const int target)
{
    if (list->head == NULL)
        return false;

    ListNode* current = list->head;

    while (current->next != list->head)
    {
        if (current->data == target)
            return true;

        current = current->next;
    }

    return current->data == target;
}

void display_circular_linked_list(FILE* const stream ,const CircularLinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stream, "Circular Linked List {}\n");
        return;
    }

    fprintf(stream, "Circular Linked List {");

    ListNode* current = list->head;
    while (current->next != list->head)
    {
        fprintf(stream, " %d ->", current->data);
        current = current->next;
    }

    fprintf(stream, " %d }\n", current->data);
}
