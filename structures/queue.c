#include <malloc.h>
#include <stdlib.h>

#include "headers/queue.h"

void init_queue(Queue* const queue, const size_t capacity)
{
    queue->front = (int*) malloc(sizeof(int) * capacity);

    if (queue->front == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a queue of %zu integers.\n", capacity);
        exit(1);
    }

    queue->rear = queue->front;
    queue->capacity = capacity;
    queue->length = 0;
    queue->index = 0;
}

void free_queue(Queue* const queue)
{
    free(queue->front);
    init_queue(queue, 0);
}

size_t queue_length(const Queue* const queue)
{ return queue->length; }

bool queue_is_empty(const Queue* const queue)
{ return queue->front + queue->index == queue->rear; }

void enqueue_in_queue(Queue* const queue, const int data)
{
    if (queue->length == queue->capacity)
    {
        fprintf(stderr, "Queue Full: Cannot enqueue to a full queue of capacity %zu.\n", queue->capacity);
#if QUEUE_EXIT_ON_ERROR
        exit(1);
#endif
    }

    *queue->rear++ = data;
    queue->length++;
}

int deque_from_queue(Queue* const queue)
{
    if (queue->length == 0 || queue->front + queue->index + 1 > queue->rear)
    {
        fprintf(stderr, "Queue Empty: Cannot deque from an empty queue.\n");
#if QUEUE_EXIT_ON_ERROR
        exit(1);
#endif
    }

    const int data = queue->front[queue->index++];
    queue->length--;

    return data;
}

int peek_into_queue(const Queue* const queue)
{
    if (queue->length == 0)
    {
        fprintf(stderr, "Queue Empty: Cannot peek into an empty queue.\n");
#if QUEUE_EXIT_ON_ERROR
        exit(1);
#endif
    }

    return queue->front[queue->index];
}

void display_queue(FILE* const stream, const Queue* const queue)
{
    if (queue->length == 0)
    {
        fprintf(stream, "Queue {}\n");
        return;
    }

    fprintf(stream, "Queue { ");

    for (size_t i = 0; i < queue->length - 1; i++)
        fprintf(stream, "%d, ", queue->front[i]);

    fprintf(stream, "%d }\n", queue->front[queue->length - 1]);
}
