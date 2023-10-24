#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#define STACK_EXIT_ON_ERROR true

#include <glob.h>
#include <stdbool.h>

typedef struct
{
    int* top;
    size_t capacity;
    size_t index;
} Stack;

void init_stack(Stack* stack, size_t capacity);

void free_stack(Stack* stack);

size_t stack_length(const Stack* stack);

bool stack_is_empty(const Stack* stack);

void push_to_stack(Stack* stack, int data);

int pop_from_stack(Stack* stack);

int peek_into_stack(const Stack* stack);

void display_stack(FILE* stream, const Stack* stack);

#endif //DATA_STRUCTURES_STACK_H
