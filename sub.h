#ifndef _sub_h_
#define _sub_h_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

unsigned char *sub_digits(
    unsigned char *a, size_t la,
    unsigned char *b, size_t lb,
    size_t *lr);

#endif
