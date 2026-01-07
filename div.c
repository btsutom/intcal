#ifndef _div_
#define _div_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "comp.h" 
#include "sub.h"

unsigned char *div_digits(
    unsigned char *a, size_t la,
    unsigned char *b, size_t lb,
    size_t *lr)
{
    if (cmp_digits(a, la, b, lb) < 0) {
        unsigned char *z = calloc(1, 1);
        z[0] = 0;
        *lr = 1;
        return z;
    }

    unsigned char *q = calloc(la, 1);
    unsigned char *rem = calloc(la, 1);
    size_t lr_rem = 0;

    for (size_t i = la; i-- > 0;) {
        memmove(rem + 1, rem, lr_rem);
        rem[0] = a[i];
        lr_rem++;

        unsigned char cnt = 0;
        while (cmp_digits(rem, lr_rem, b, lb) >= 0) {
            unsigned char *tmp;
            size_t ltmp;
            tmp = sub_digits(rem, lr_rem, b, lb, &ltmp);
            free(rem);
            rem = tmp;
            lr_rem = ltmp;
            cnt++;
        }
        q[i] = cnt;
    }

    size_t n = la;
    while (n > 1 && q[n - 1] == 0) n--;

    free(rem);
    *lr = n;
    return q;
}
#endif
