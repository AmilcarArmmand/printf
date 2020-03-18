#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int powten(int a);
int _printf(const char *format, ...);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
void *_strcpy(char *dest, char *src);
char *_itoa(int num, char *str, int base);
void reverse(char *str, int len);
void rev_string(char *s);

#endif /* PRINTF_H */
