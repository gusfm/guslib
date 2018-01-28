#include <stdlib.h>
#include "ut.h"
#include "vector.h"

static int basic(void)
{
    vector_t *v = vector_create();
    ASSERT(vector_empty(v) == true);
    ASSERT(vector_size(v) == 0u);
    /* Insert */
    int *data;
    for (int i = 0; i < 10; ++i) {
        data = (int *)malloc(sizeof(int));
        *data = i;
        vector_insert(v, i, (void *)data);
    }
    ASSERT(vector_size(v) == 10);
    /* Remove */
    data = (int *)vector_remove(v, 5);
    ASSERT(5 == *data);
    free(data);
    ASSERT(vector_size(v) == 9);
    /* Access */
    data = (int *)vector_at(v, 5);
    ASSERT(6 == *data);
    /* Clear */
    while (!vector_empty(v)) {
        data = (int *)vector_remove(v, 0);
        free(data);
    }
    ASSERT(vector_empty(v) == true);
    /* Finish */
    vector_destroy(v);
    return 0;
}

void vector_test(void)
{
    ut_run(basic);
}
