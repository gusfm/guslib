#include "stack.h"

stack_t *stack_create(void)
{
    return list_create();
}

void stack_destroy(stack_t *q)
{
    list_destroy(q);
}

bool stack_empty(stack_t *q)
{
    return list_empty(q);
}

size_t stack_size(stack_t *q)
{
    return list_size(q);
}

void stack_push(stack_t *q, void *data)
{
    list_insert(q, data);
}

void *stack_pop(stack_t *q)
{
    node_t *node = list_get_last(q);
    void *data = node->data;
    list_remove(q, node);
    return data;
}
