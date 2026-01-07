#ifndef _subf_h_
#define _subf_h_
#include <stddef.h>

int cmp_digits(unsigned char* a, size_t la, unsigned char* b, size_t lb);
int isdigits(char *av);
char *digits2str(unsigned char *d, size_t len);
unsigned char *str2digits(const char *s, size_t *len);

unsigned char *add_digits(unsigned char* a, size_t la, unsigned char* b, size_t lb, size_t* lr);
unsigned char *div_digits(unsigned char* a, size_t la, unsigned char* b, size_t lb, size_t* lr);
unsigned char *mod_digits(unsigned char* a, size_t la, unsigned char* b, size_t lb, size_t* lr);
unsigned char *mul_digits(unsigned char* a, size_t la, unsigned char* b, size_t lb, size_t* lr);
unsigned char *sub_digits(unsigned char* a, size_t la, unsigned char* b, size_t lb, size_t* lr);

#endif
