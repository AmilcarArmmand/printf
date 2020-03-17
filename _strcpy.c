#include "holberton.h"

/**
 * _strcpy - a function that copies a string including the '\0'
 * @dest: copy of string pointed to by src
 * @src: string to be copied
 *
 * Return: *_strcpy
 */
void *_strcpy(char *dest, char *src)
{
	while ((*dest++ = *src++))
		;
}
