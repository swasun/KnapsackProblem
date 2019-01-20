/*******************************************************************************
 * Copyright (C) 2019 Charly Lamothe                                           *
 *                                                                             *
 * This file is part of KnapsackProblem.                                       *
 *                                                                             *
 *   Licensed under the Apache License, Version 2.0 (the "License");           *
 *   you may not use this file except in compliance with the License.          *
 *   You may obtain a copy of the License at                                   *
 *                                                                             *
 *   http://www.apache.org/licenses/LICENSE-2.0                                *
 *                                                                             *
 *   Unless required by applicable law or agreed to in writing, software       *
 *   distributed under the License is distributed on an "AS IS" BASIS,         *
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
 *   See the License for the specific language governing permissions and       *
 *   limitations under the License.                                            *
 *******************************************************************************/

#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

queue *queue_create(void *(*alloc_func)(void *data)) {
    queue *q;

    q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    q->count = 0;
    q->user_alloc_func = alloc_func;
    q->user_display_func = NULL;
    q->user_free_func = free;

    return q;
}

void queue_destroy(queue *q) {
    int i;

    if (q) {
        for (i = 0; i < q->count; i++) {
            queue_pop(q);
        }

        free((void *)q);
    }
}

void queue_push(queue *q, void *data) {
    if (q->rear == NULL) {
        q->rear = (struct queue_node *)malloc(sizeof(struct queue_node));
        q->rear->ptr = NULL;
        q->rear->data = q->user_alloc_func(data);
        q->front = q->rear;
    }
    else {
        q->temp = (struct queue_node *)malloc(sizeof(struct queue_node));
        q->rear->ptr = q->temp;
        q->temp->data = q->user_alloc_func(data);
        q->temp->ptr = NULL;

        q->rear = q->temp;
    }

    q->count++;
}

void queue_pop(queue *q) {
    q->front1 = q->front;

    if (q->front1 == NULL) {
        return;
    }
    else {
        if (q->front1->ptr != NULL) {
            q->front1 = q->front1->ptr;
            if (q->user_free_func) {
                q->user_free_func(q->front->data);
            } else {
                free((void *)q->front->data);
            }
            free((void *)q->front);
            q->front = q->front1;
        }
        else {
            if (q->user_free_func) {
                q->user_free_func(q->front->data);
            } else {
                free((void *)q->front->data);
            }
            free((void *)q->front);
            q->front = NULL;
            q->rear = NULL;
        }
        q->count--;
    }
}

int queue_size(queue *q) {
    return q->count;
}

void *queue_front(queue *q) {
    if ((q->front != NULL) && (q->rear != NULL)) {
        return q->front->data;
    } else {
        return NULL;
    }
}

int queue_empty(queue *q) {
     return (q->front == NULL) && (q->rear == NULL);
}

void queue_display(queue *q) {
    q->front1 = q->front;

    if ((q->front1 == NULL) && (q->rear == NULL)) {
        return;
    }

    if (q->user_display_func == NULL) {
        fprintf(stderr, "[ERROR] No print function specified\n");
        return;
    }

    while (q->front1 != q->rear) {
        q->user_display_func(q->front1->data);
        q->front1 = q->front1->ptr;
    }

    if (q->front1 == q->rear) {
        q->user_display_func(q->front1->data);
    }
}

void queue_set_display_func(queue *q, void (*display_func)(void *data)) {
    q->user_display_func = display_func;
}

void queue_set_free_func(queue *q, void (*free_func)(void *data)) {
    q->user_free_func = free_func;
}
