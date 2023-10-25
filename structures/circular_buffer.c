#include <malloc.h>
#include <stdlib.h>

#include "headers/circular_buffer.h"

void init_circular_buffer(CircularBuffer* const buffer, const size_t capacity)
{
    buffer->buffer = (int*) malloc(sizeof(int) * capacity);

    if (buffer->buffer == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a circular buffer of %zu integers.\n", capacity);
        exit(1);
    }

    buffer->read_index = 0;
    buffer->write_index = 0;
    buffer->capacity = capacity;
}

void free_circular_buffer(CircularBuffer* const buffer)
{
    free(buffer->buffer);
    init_circular_buffer(buffer, 0);
}

size_t circular_buffer_length(const CircularBuffer* const buffer)
{
    if (is_circular_buffer_empty(buffer))
        return 0;

    if (buffer->write_index > buffer->read_index)
        return buffer->write_index - buffer->read_index;

    return buffer->capacity - buffer->read_index + buffer->write_index;
}

bool is_circular_buffer_empty(const CircularBuffer* const buffer)
{ return buffer->read_index == buffer->write_index; }

void put_into_circular_buffer(CircularBuffer* const buffer, const int data)
{
    if ((buffer->write_index + 1) % buffer->capacity == buffer->read_index)
    {
        fprintf(
            stderr, "Circular Buffer Full: Cannot put into a full circular buffer of capacity %zu.\n", buffer->capacity
        );
#if CIRCULAR_BUFFER_EXIT_ON_ERROR
        exit(1);
#endif
    }

    buffer->buffer[buffer->write_index] = data;
    buffer->write_index = (buffer->write_index + 1) % buffer->capacity;
}

int get_from_circular_buffer(CircularBuffer* const buffer)
{
    if (is_circular_buffer_empty(buffer))
    {
        fprintf(stderr, "Circular Buffer Empty: Cannot get from an empty circular buffer.\n");
#if CIRCULAR_BUFFER_EXIT_ON_ERROR
        exit(1);
#endif
    }

    const int data = buffer->buffer[buffer->read_index];
    buffer->read_index = (buffer->read_index + 1) % buffer->capacity;

    return data;
}

int peek_into_circular_buffer(CircularBuffer* const buffer)
{
    if (is_circular_buffer_empty(buffer))
    {
        fprintf(stderr, "Circular Buffer Empty: Cannot peek into an empty circular buffer.\n");
#if CIRCULAR_BUFFER_EXIT_ON_ERROR
        exit(1);
#endif
    }

    return buffer->buffer[buffer->read_index];
}

void display_circular_buffer(FILE* const stream, const CircularBuffer* const buffer)
{
    if (is_circular_buffer_empty(buffer))
    {
        fprintf(stream, "Circular Buffer {}\n");
        return;
    }

    fprintf(stream, "Circular Buffer { ");

    for (size_t i = buffer->read_index; i < buffer->write_index - 1; i = (i + 1) % buffer->capacity)
        fprintf(stream, "%d, ", buffer->buffer[i]);

    fprintf(stream, "%d }\n", buffer->buffer[buffer->write_index - 1]);
}
