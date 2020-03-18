#include "holberton.h"

/**
 * powten - calculates powers of 10
 * Return: exponent
 * @a: number from main
 */

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
