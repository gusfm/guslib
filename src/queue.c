#include "queue.h"

queue_t *queue_create(void)
{
    return list_create();
}

void queue_destroy(queue_t *q)
{
    list_destroy(q);
}

bool queue_empty(queue_t *q)
{
    return list_empty(q);
}

size_t queue_size(queue_t *q)
{
    return list_size(q);
}

void queue_push(queue_t *q, void *data)
{
    list_insert(q, data);
}

void *queue_pop(queue_t *q)
{
    node_t *node = list_get_first(q);
    void *data = node->data;
    list_remove(q, node);
    return data;
}
