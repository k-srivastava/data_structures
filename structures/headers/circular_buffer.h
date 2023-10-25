#ifndef DATA_STRUCTURES_CIRCULAR_BUFFER_H
#define DATA_STRUCTURES_CIRCULAR_BUFFER_H

#define CIRCULAR_BUFFER_EXIT_ON_ERROR true

#include <glob.h>
#include <stdbool.h>
#include <bits/types/FILE.h>

typedef struct
{
    int* buffer;

    size_t read_index;
    size_t write_index;
    size_t capacity;
} CircularBuffer;

void init_circular_buffer(CircularBuffer* buffer, size_t capacity);

void free_circular_buffer(CircularBuffer* buffer);

size_t circular_buffer_length(const CircularBuffer* buffer);

bool is_circular_buffer_empty(const CircularBuffer* buffer);

void put_into_circular_buffer(CircularBuffer* buffer, int data);

int get_from_circular_buffer(CircularBuffer* buffer);

int peek_into_circular_buffer(CircularBuffer* buffer);

void display_circular_buffer(FILE* stream, const CircularBuffer* buffer);

#endif //DATA_STRUCTURES_CIRCULAR_BUFFER_H
