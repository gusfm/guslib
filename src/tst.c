#include "tst.h"
#include <stdio.h>
#include <stdlib.h>

struct tst {
    tst_t *left;
    tst_t *equal;
    tst_t *right;
    char ch;
};

static tst_t *tst_create(char ch)
{
    tst_t *t = (tst_t *)malloc(sizeof(tst_t));
    t->left = NULL;
    t->equal = NULL;
    t->right = NULL;
    t->ch = ch;
    return t;
}

void tst_destroy(tst_t *t)
{
    if (t->left)
        tst_destroy(t->left);
    if (t->equal)
        tst_destroy(t->equal);
    if (t->right)
        tst_destroy(t->right);
    free(t);
}

tst_t *tst_insert(tst_t *t, const char *s)
{
    char c = *s;
    if (t == NULL) {
        t = tst_create(c);
    }
    if (c < t->ch) {
        t->left = tst_insert(t->left, s);
    } else if (c > t->ch) {
        t->right = tst_insert(t->right, s);
    } else if (c != '\0') {
        t->equal = tst_insert(t->equal, ++s);
    }
    return t;
}

bool tst_search(tst_t *root, const char *s)
{
    tst_t *t = root;
    while (t) {
        if (*s < t->ch) {
            t = t->left;
        } else if (*s == t->ch) {
            if (*s++ == '\0')
                return true;
            t = t->equal;
        } else {
            t = t->right;
        }
    }
    return false;
}
