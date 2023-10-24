#include <malloc.h>
#include <stdlib.h>

#include "headers/stack.h"

void init_stack(Stack* const stack, const size_t capacity)
{
    stack->top = (int*) malloc(sizeof(int) * capacity);

    if (stack->top == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a stack of %zu integers.\n", capacity);
        exit(1);
    }

    stack->capacity = capacity;
    stack->index = -1;
}

void free_stack(Stack* const stack)
{
    free(stack->top);
    init_stack(stack, 0);
}

size_t stack_length(const Stack* const stack)
{ return stack->index; }

bool stack_is_empty(const Stack* const stack)
{ return stack->index != stack->capacity; }

void push_to_stack(Stack* stack, const int data)
{
    if (stack->index + 1 == stack->capacity)
    {
        fprintf(stderr, "Stack Overflow: Cannot push to a full stack of capacity %zu.\n", stack->capacity);
#if STACK_EXIT_ON_ERROR
        exit(1);
#endif
    }

    stack->top[++stack->index] = data;
}

int pop_from_stack(Stack* const stack)
{
    if (stack->index == -1)
    {
        fprintf(stderr, "Stack Underflow: Cannot pop from an empty stack.\n");
#if STACK_EXIT_ON_ERROR
        exit(1);
#endif
    }

    return stack->top[stack->index--];
}

int peek_into_stack(const Stack* const stack)
{
    if (stack->index == -1)
    {
        fprintf(stderr, "Stack Empty: Cannot peek into an empty stack.\n");
        return -1;
    }

    return stack->top[stack->index];
}

void display_stack(FILE* const stream, const Stack* const stack)
{
    if (stack->index == -1)
    {
        fprintf(stream, "Stack {}\n");
        return;
    }

    fprintf(stream, "Stack { ");

    for (size_t i = 0; i < stack->index; i++)
        fprintf(stream, "%d, ", stack->top[i]);

    fprintf(stream, "%d }\n", stack->top[stack->index]);
}
