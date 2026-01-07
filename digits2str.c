#ifndef _dig2str_
#define _dig2str_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *digits2str(unsigned char *d, size_t len)
{
    while (len > 1 && d[len - 1] == 0) len--;

    char *s = malloc(len + 1);
    if (!s) return NULL;

    for (size_t i = 0; i < len; i++)
        s[i] = d[len - 1 - i] + '0';

    s[len] = '\0';
    return s;
}

#endif
