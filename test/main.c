#include "ut.h"

struct ut unit_test;

extern void list_test(void);
extern void queue_test(void);

int main(void)
{
    list_test();
    queue_test();
    ut_result();
    return 0;
}
