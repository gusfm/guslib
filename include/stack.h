#ifndef GUSLIB_STACK_H
#define GUSLIB_STACK_H

#include "list.h"

typedef list_t stack_t;

stack_t *stack_create(void);
void stack_destroy(stack_t *q);
bool stack_empty(stack_t *q);
size_t stack_size(stack_t *q);
void stack_push(stack_t *q, void *data);
void *stack_pop(stack_t *q);

#endif /* GUSLIB_STACK_H */
