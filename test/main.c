#include "ut.h"

struct ut unit_test;

extern void list_test(void);
extern void queue_test(void);
extern void vector_test(void);
extern void fsm_test(void);
extern void tst_test(void);

int main(void)
{
    list_test();
    queue_test();
    vector_test();
    fsm_test();
    tst_test();
    ut_result();
    return 0;
}
