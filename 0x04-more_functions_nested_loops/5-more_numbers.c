#include "main.h"
/**
 * more_numbers - function that prints 10 times the numbers from 0 to 14
 * _putchar only 3 times
 * Return: 0-14 10times
 */
void more_numbers(void)
{
	int i, j;

	for (i = 1; i <= 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j >= 10)
			putchar('1');
			putchar(j % 10 + '0');
		}
		_putchar('\n');
	}
}
