#ifndef PRINTF_H
#define PRINTF_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
void _puts(char *str);

#endif /* PRINTF_H */
