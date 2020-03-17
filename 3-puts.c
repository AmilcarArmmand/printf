#include "holberton.h"

/**
 * _puts - prints a string form main
 * @str: from main
 * Return: void
 */
void _puts(char *str)
{
	int done = 0;
	int pos = 0;

	while (done == 0)
	{
		if (*(str + pos) != '\0')
		{
			_putchar(*(str + pos));
			pos++;
		}
		else
			done = 1;
	}
}
