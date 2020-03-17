#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "printf_header.h"
#include "printf_functions.c"

void _printf(const char *format, ...)
{
	va_list ap, apcopy;
	char *copy, *string, *finalstring /* ,*intstring */;
	int copyindex, finalStringIndex, /*number,*/ letter, spacecount = 0;
	char percent = '%';

	va_start(ap, format);
	copy = malloc(sizeof(format));
	if (!copy)
		exit (98);
	_strcpy(copy, (char *)format);
	for (copyindex = 0; copy[copyindex]; copyindex++)
	{
		if (copy[i] == '%')
		{
			i++;
			switch (copy[i])
			{
			case 'c':
				letter = va_arg(ap, int);
				spacecount += _strlen(letter);
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
				spacecount += 2;
			}
		}
		else
		{
			spacecount++;
			i++;
		}
	}
	va_end(ap);
	finalstring = malloc(sizeof(char) * spacecount);
	va_start (apcopy, format);
	finalStringIndex = 0;
	for (copyindex = 0; copy[copyindex]; copyindex++, finalStringIndex++)
        {
                if (copy[i] == '%')
                {
                        i++;
                        switch (copy[i])
                        {
                        case 'c':
                                letter = va_arg(apcopy, int);
				_strcat(finalstring, letter);
				break;
                        case 's':
                                string = va_arg(apcopy, char *);
                                _strcat(finalstring, letter);
				i++;
                                break;
                        case '\0':
                                break;
                        case '%':
				_strcat(finalstring, percent);
				i++;
                                break;
                        default:
                                i++;
                        }
                }
                else
                {
                        i++;
                }
        }
}
