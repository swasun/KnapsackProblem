#ifndef QUEUE_H
#define QUEUE_H

/**
 * Inspired from: http://www.sanfoundry.com/c-program-queue-using-linked-list
 */

/**
 * Data structure of the node of the queue.
 */
struct queue_node {
    /* User data manipulable using the specified functions. */
    void *data;
    struct queue_node *ptr;
};

/**
 * Data structure of the queue.
 */
typedef struct {
    struct queue_node *front, *rear, *temp, *front1;
    int count;
    void (*user_display_func)(void *data);
    void *(*user_alloc_func)(void *data);
    void (*user_free_func)(void *data);
} queue;

queue *queue_create(void *(*user_alloc_func)(void *data));

void queue_destroy(queue *q);

/**
 * Stack an element.
 * Use the allocation function user_alloc_func(), specified
 * by the user creating the queue.
 */
void queue_push(queue *q, void *data);

/**
 * Unstack an element.
 * Use the deallocation function user_free_func() if
 * it has been specified by the user with the function
 * queue_set_free_func(). Else, the free() function from
 * stdlib.h is used.
 */
void queue_pop(queue *q);

/**
 * Return the size of the queue.
 */
int queue_size(queue *q);

/**
 * Return the front element of the queue.
 */
void *queue_front(queue *q);

/**
 * Return 1 if the queue is empty, 0 otherwise.
 */
int queue_empty(queue *q);

/**
 * Print all the elements of the queue using the
 * function user_display_func(), specified by the user
 * with the function queue_set_display_func().
 */
void queue_display(queue *q);

void queue_set_display_func(queue *q, void (*display_func)(void *data));

void queue_set_alloc_func(queue *q, void *(*alloc_func)(void *data));

void queue_set_free_func(queue *q, void (*free_func)(void *data));

#endif
