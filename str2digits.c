
#ifndef _str2dig_
#define _str2dig_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

unsigned char *str2digits(const char *s, size_t *len)
{
    while (*s == '0' && s[1]) s++;   /* 先頭0除去 */

    size_t n = strlen(s);
    unsigned char *d = calloc(n, 1);
    if (!d) return NULL;

    for (size_t i = 0; i < n; i++)
        d[i] = s[n - 1 - i] - '0';

    *len = n;
    return d;
}
#endif
