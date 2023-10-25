#include <malloc.h>
#include <stdlib.h>

#include "headers/linked_list.h"

LinkedList* init_linked_list(void)
{
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));

    if (list == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a linked list.\n");
        exit(1);
    }

    list->head = NULL;
    list->length = 0;

    return list;
}

void free_linked_list(LinkedList* const list)
{
    if (list->head == NULL)
    {
        free(list);
        return;
    }

    ListNode* current = list->head;
    while (current->next != NULL)
    {
        ListNode* const next = current->next;
        free_list_node(current);

        current = next;
    }

    list->length = 0;
    free(list);
}

void insert_at_head_linked_list(LinkedList* const list, const int data)
{
    list->head = init_list_node(data, list->head);
    list->length++;
}

void insert_at_tail_linked_list(LinkedList* const list, const int data)
{
    if (list->head == NULL)
    {
        list->head = init_list_node_default(data);
        list->length = 1;

        return;
    }

    ListNode* current = list->head;
    while (current->next != NULL)
        current = current->next;

    current->next = init_list_node_default(data);
    list->length++;
}

int remove_from_head_linked_list(LinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "Cannot remove the head of an empty linked list.\n");
        exit(1);
    }

    ListNode* const old_head = list->head;
    list->head = list->head->next;

    const int data = old_head->data;
    free_list_node(old_head);
    list->length--;

    return data;
}

int remove_from_tail_linked_list(LinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "Cannot remove the tail of an empty linked list.\n");
        exit(1);
    }

    ListNode* current = list->head;
    while (current->next != NULL && current->next->next != NULL)
        current = current->next;

    ListNode* const old_tail = current->next;
    current->next = NULL;

    const int data = old_tail->data;
    free_list_node(old_tail);
    list->length--;

    return data;
}

bool search_in_linked_list(const LinkedList* const list, const int target)
{
    if (list->head == NULL)
        return false;

    ListNode* current = list->head;

    while (current != NULL)
    {
        if (current->data == target)
            return true;

        current = current->next;
    }

    return false;
}

void display_linked_list(FILE* const stream, const LinkedList* const list)
{
    if (list->head == NULL)
    {
        fprintf(stream, "Linked List {}\n");
        return;
    }

    fprintf(stream, "Linked List {");

    ListNode* current = list->head;
    while (current->next != NULL)
    {
        fprintf(stream, " %d ->", current->data);
        current = current->next;
    }

    fprintf(stream, " %d }\n", current->data);
}
