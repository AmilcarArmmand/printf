#include "holberton.h"

/**
 * _strlen - a function that returns the length of a string
 * @s: pointer to string s
 * Return: length of the string
 */
int _strlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return (n);
}
