#ifndef _comp_
#define _comp_

#include <stddef.h>

int cmp_digits(
    unsigned char *a, size_t la,
    unsigned char *b, size_t lb)
{
    if (la != lb) return (la > lb) ? 1 : -1;
    for (size_t i = la; i-- > 0;) {
        if (a[i] != b[i])
            return (a[i] > b[i]) ? 1 : -1;
    }
    return 0;
}
#endif
