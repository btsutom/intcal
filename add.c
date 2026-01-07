#ifndef _add_
#define _add_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

unsigned char *add_digits(
    unsigned char *a, size_t la,
    unsigned char *b, size_t lb,
    size_t *lr)
{
    size_t n = (la > lb) ? la : lb;
    unsigned char *r = calloc(n + 1, 1);

    int carry = 0;
    for (size_t i = 0; i < n; i++) {
        int da = (i < la) ? a[i] : 0;
        int db = (i < lb) ? b[i] : 0;
        int s = da + db + carry;
        r[i] = s % 10;
        carry = s / 10;
    }
    if (carry) r[n++] = carry;

    *lr = n;
    return r;
}
#endif
