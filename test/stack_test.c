#include <stdlib.h>
#include "stack.h"
#include "ut.h"

static int basic(void)
{
    stack_t *q = stack_create();
    /* Insert stack. */
    int *data;
    for (int i = 0; i < 10; ++i) {
        data = (int *)malloc(sizeof(int));
        *data = i;
        stack_push(q, (void *)data);
    }
    ASSERT(10 == stack_size(q));
    /* Remove stack. */
    for (int i = 10; i > 5; --i) {
        data = (int *)stack_pop(q);
        ASSERT(i == *data);
        free(data);
    }
    ASSERT(5 == stack_size(q));
    /* Clear stack. */
    while (!stack_empty(q)) {
        data = (int *)stack_pop(q);
        free(data);
    }
    ASSERT(0 == stack_size(q));
    stack_destroy(q);
    return 0;
}

void stack_test(void)
{
    ut_run(basic);
}
