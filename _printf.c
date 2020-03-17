#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list ap;
	int number_of_chars, letter, number;
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
				format--;
				_itoa(number, numberstring, 10);
				_puts(numberstring);
			       	format += 2;
				number_of_chars += _strlen(numberstring);
			case 'i':
				number = va_arg(ap, int);
                                format--;
                                numberstring = _itoa(number, numberstring, 10);
                                _puts(numberstring);
                                format += 2;
                                number_of_chars += _strlen(numberstring);
			default:
				continue;  /* int i;  switch cases  */
			}
		}
		else if (*format != '%' || *format != '\n')
		{
			_putchar(*format);
			format++;
		}
	}
	va_end(ap);
	return (number_of_chars);
}
