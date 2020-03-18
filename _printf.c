#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <math.h>
#include "holberton.h"

int powten(int a)
{
	int pow = 0;
	int result = 1;
	int base = 10;
	while (a / result > 1)
	{
		result *= base;
		pow++;
	}
	return (pow);
}

int _printf(const char *format, ...)
{
	va_list ap;
	int number_of_chars, letter, number, numberofdigits;
	char *string, *numberstring;

	number_of_chars = 0;
	va_start(ap, format);
	while (*format)
	{
		number_of_chars++;
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				letter = va_arg(ap, int);
				format--;
				_putchar(letter);
			       	format += 2;
				break;
			case 's':
				string = va_arg(ap, char *);
				format--;
				_puts(string);
				format += 2;
				number_of_chars += _strlen(string);
				break;
			case 'd':
				number = va_arg(ap, int);
				numberofdigits = powten(number);
				format--;
				numberstring = malloc(sizeof(char) * numberofdigits);
				numberstring = _itoa(number, numberstring, 10);
				_puts(numberstring);
			       	format += 2;
				number_of_chars += _strlen(numberstring);
				break;
			case 'i':
				number = va_arg(ap, int);
                                format--;
                                numberstring = _itoa(number, numberstring, 10);
                                _puts(numberstring);
                                format += 2;
                                number_of_chars += _strlen(numberstring);
				break;
			case '%':
				_putchar('%');
				format++;
				number_of_chars++;
			default:
				continue;  /* int i;  switch cases  */
			}
		}
		else if (*format != '%')
		{
			_putchar(*format);
			format++;
		}
	}
	va_end(ap);
	return (number_of_chars);
}
