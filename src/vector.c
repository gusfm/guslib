#include "vector.h"
#include <assert.h>
#include <stdlib.h>

struct vector {
    size_t numelem; /* number of elements */
    size_t size;    /* allocated size */
    void **data;    /* array of elements */
};

vector_t *vector_create(void)
{
    vector_t *v = malloc(sizeof(vector_t));
    v->numelem = 0;
    v->size = 10;
    v->data = (void **)malloc(sizeof(void *) * v->size);
    return v;
}

void vector_destroy(vector_t *v)
{
    assert(v->numelem == 0);
    free(v->data);
    free(v);
}

bool vector_empty(vector_t *v)
{
    return v->numelem == 0;
}

size_t vector_size(vector_t *v)
{
    return v->numelem;
}

void vector_insert(vector_t *v, size_t pos, void *data)
{
    if (v->numelem >= v->size) {
        v->size *= 2;
        v->data = (void **)realloc(v->data, sizeof(void *) * v->size);
    }
    for (size_t i = v->numelem; i > pos; --i) {
        v->data[i] = v->data[i - 1];
    }
    v->data[pos] = data;
    v->numelem++;
}

void *vector_at(vector_t *v, size_t pos)
{
    return v->data[pos];
}

void *vector_remove(vector_t *v, size_t pos)
{
    void *obj;
    if (pos >= v->numelem)
        return NULL;
    obj = vector_at(v, pos);
    for (size_t i = pos; i < v->numelem - 1; ++i) {
        v->data[i] = v->data[i + 1];
    }
    v->numelem--;
    return obj;
}
