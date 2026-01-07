#ifndef _sub_
#define _sub_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

unsigned char *sub_digits(
    unsigned char *a, size_t la,
    unsigned char *b, size_t lb,
    size_t *lr)
{
    unsigned char *r = calloc(la, 1);
    int borrow = 0;

    for (size_t i = 0; i < la; i++) {
        int da = a[i] - borrow;
        int db = (i < lb) ? b[i] : 0;

        if (da < db) {
            da += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        r[i] = da - db;
    }

    size_t n = la;
    while (n > 1 && r[n - 1] == 0) n--;

    *lr = n;
    return r;
}
#endif
