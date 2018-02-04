#include <stdlib.h>
#include "tst.h"
#include "ut.h"

static int basic(void)
{
    tst_t *t = tst_insert(NULL, "cute");
    ASSERT(t != NULL);
    tst_insert(t, "cup");
    tst_insert(t, "at");
    tst_insert(t, "as");
    tst_insert(t, "he");
    tst_insert(t, "us");
    tst_insert(t, "i");
    ASSERT(tst_search(t, "cat") == false);
    ASSERT(tst_search(t, "cup") == true);
    ASSERT(tst_search(t, "i") == true);
    ASSERT(tst_search(t, "as") == true);
    tst_destroy(t);
    return 0;
}

void tst_test(void)
{
    ut_run(basic);
}

