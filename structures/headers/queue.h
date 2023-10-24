#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#define QUEUE_EXIT_ON_ERROR true

#include <glob.h>
#include <stdbool.h>

typedef struct
{
    int* front;
    int* rear;

    size_t capacity;
    size_t length;
    size_t index;
} Queue;

void init_queue(Queue* queue, size_t capacity);

void free_queue(Queue* queue);

size_t queue_length(const Queue* queue);

bool queue_is_empty(const Queue* queue);

void enqueue_in_queue(Queue* queue, int data);

int deque_from_queue(Queue* queue);

int peek_into_queue(const Queue* queue);

void display_queue(FILE* stream, const Queue* queue);

#endif //DATA_STRUCTURES_QUEUE_H
