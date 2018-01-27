#ifndef GUSLIB_QUEUE_H
#define GUSLIB_QUEUE_H

#include "list.h"

typedef list_t queue_t;

queue_t *queue_create(void);
void queue_destroy(queue_t *q);
bool queue_empty(queue_t *q);
size_t queue_size(queue_t *q);
void queue_push(queue_t *q, void *data);
void *queue_pop(queue_t *q);

#endif /* GUSLIB_QUEUE_H */
