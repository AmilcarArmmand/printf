#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse(char *str, int len)
{
	int i = 0, j = len - 1, temp;

	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

/**
 *
 *
 *
 */
char *_itoa(int num, char *str, int base)
{
	int i, value;
	bool flagIsNegative;

	i = 0;
	flagIsNegative = false;

	if (num == 0)  /* if number is zero */
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (num < 0 && base == 10) /* if negative and base 10 */
	{
		flagIsNegative = true;
		num = -num;
	}

	while (num != 0)
	{
		value = num % base;
		if (value > 9)
			str[i] = (value - 10) + 'a';
		else
			str[i] = value + '0';
		i++;
	}
	if (flagIsNegative)
		str[i++] = '-';

	str[i] = '\0';
/* reverse string */
	reverse(str, strlen(str));
	return (str);
}
