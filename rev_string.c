#include <stdlib.h>

/**
 * rev_string - a function that reverses a string
 * @s: string that will be reversed
 *
 * Return: void (No return value)
 */
void rev_string(char *s)
{
	char temp;
	int len;
	int i;

	for (len = 0; s[len] != '\0'; len++)
		;

	for (i = 0;  i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
