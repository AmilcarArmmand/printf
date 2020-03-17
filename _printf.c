#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list ap, ap2;
	char *copy, *string, *finalstring;
	int i, letter, spacecount = 0;

	va_start(ap, format);
	copy = malloc(sizeof(format));
	_strcpy(copy, format);
	for (i = 0; copy[i]; i++)
	{
		if (copy[i] == '%')
		{
			i++;
			switch (copy[i])
			{
			case 'c':
			       	spacecount++;
				i++;
				break;
			case 's':
				string = va_arg(ap, char *);
				spacecount += _strlen(string);
				i++;
				break;
			case '\0':
				break;
			case '%':
				spacecount++;
				i++;
				break;
			default:
				i++;
			}
		}
	}
	va_end(ap);
	va_start(ap2, format);
	finalstring = malloc(sizeof(format) + spacecount);
	for (i = 0; copy[i]; i++)
	{
    	       	finalstring[i] = copy[i];
		if (copy[i] == '%')
		{
			i++;
			switch (copy[i])
			{
			case 'c':
				letter = va_arg(ap2, int);
				finalstring[i] += letter;
				break;
		       	case 's':
				string = va_arg(ap, char *);
				_strcat(finalstring, string);
				i++;
				break;
			case '\0':
				break;
			case '%':
				_strcat(finalstring, "%");
				i++;
			default:
				i++;
	      		}
		}
       	}
	va_end(ap2);
	printf("%s\n", finalstring);
	return (_strlen(finalstring));
}
