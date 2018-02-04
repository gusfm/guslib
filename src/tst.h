#ifndef GUSLIB_TST_H
#define GUSLIB_TST_H

#include <stdbool.h>

/* Ternary serach tree definition. */
typedef struct tst tst_t;

tst_t *tst_insert(tst_t *t, const char *s);
bool tst_search(tst_t *root, const char *s);
void tst_destroy(tst_t *t);

#endif /* GUSLIB_TST_H */
