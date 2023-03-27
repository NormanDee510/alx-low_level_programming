#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * if odd len, n - (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */
void puts_half(char *str)
{
	int count = 0, i;

	while (*str)
	{
		count++;
		str++;
	}

	for (i = 0; i < count; i++)
		str--;
	i = (count % 2 == 0) ? count / 2 : (count + 1);

		for (; i < count; i++)
			_putchar(str[i]);
}
