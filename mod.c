#ifndef _mod_
#define _mod_

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "comp.h"
#include "sub.h"

unsigned char *mod_digits(
    unsigned char *a, size_t la,
    unsigned char *b, size_t lb,
    size_t *lr)
{
    /* a < b → a がそのまま余り */
    if (cmp_digits(a, la, b, lb) < 0) {
        unsigned char *r = calloc(la, 1);
        memcpy(r, a, la);
        *lr = la;
        return r;
    }

    unsigned char *rem = calloc(la, 1);
    size_t lr_rem = 0;

    for (size_t i = la; i-- > 0;) {
        /* rem = rem * 10 + a[i] */
        memmove(rem + 1, rem, lr_rem);
        rem[0] = a[i];
        lr_rem++;

        /* rem >= b の間、b を引く */
        while (cmp_digits(rem, lr_rem, b, lb) >= 0) {
            unsigned char *tmp;
            size_t ltmp;
            tmp = sub_digits(rem, lr_rem, b, lb, &ltmp);
            free(rem);
            rem = tmp;
            lr_rem = ltmp;
        }
    }

    while (lr_rem > 1 && rem[lr_rem - 1] == 0)
        lr_rem--;

    *lr = lr_rem;
    return rem;
}
#endif
