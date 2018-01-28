#ifndef GUSLIB_VECTOR_H
#define GUSLIB_VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct vector vector_t;

vector_t *vector_create(void);
void vector_destroy(vector_t *v);
bool vector_empty(vector_t *v);
size_t vector_size(vector_t *l);
void vector_insert(vector_t *v, size_t pos, void *data);
void *vector_at(vector_t *v, size_t pos);
void *vector_remove(vector_t *v, size_t pos);

#endif /* GUSLIB_VECTOR_H */
