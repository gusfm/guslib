#include <stdlib.h>
#include "queue.h"
#include "ut.h"

static int basic(void)
{
    queue_t *q = queue_create();
    /* Insert queue. */
    int *data;
    for (int i = 0; i < 10; ++i) {
        data = (int *)malloc(sizeof(int));
        *data = i;
        queue_push(q, (void *)data);
    }
    ASSERT(10 == queue_size(q));
    /* Remove queue. */
    for (int i = 0; i < 5; ++i) {
        data = (int *)queue_pop(q);
        ASSERT(i == *data);
        free(data);
    }
    ASSERT(5 == queue_size(q));
    /* Clear queue. */
    while (!queue_empty(q)) {
        data = (int *)queue_pop(q);
        free(data);
    }
    ASSERT(0 == queue_size(q));
    queue_destroy(q);
    return 0;
}

void queue_test(void)
{
    ut_run(basic);
}
