#ifndef _mul_
#define _mul_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

unsigned char *mul_digits(
    unsigned char *a, size_t la,
    unsigned char *b, size_t lb,
    size_t *lr)
{
    unsigned char *r = calloc(la + lb, 1);

    for (size_t i = 0; i < la; i++) {
        int carry = 0;
        for (size_t j = 0; j < lb; j++) {
            int t = r[i + j] + a[i] * b[j] + carry;
            r[i + j] = t % 10;
            carry = t / 10;
        }
        r[i + lb] += carry;
    }

    size_t n = la + lb;
    while (n > 1 && r[n - 1] == 0) n--;

    *lr = n;
    return r;
}
#endif
