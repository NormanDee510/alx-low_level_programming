#include "main.h"

/**
 * binary_to_uint - it converts a binary number to an unsigned int
 * @b: its the string containing the binary number
 *
 * Return: a converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int k;
	unsigned int d_value = 0;

	if (!b)
		return (0);

	for (k = 0; b[k]; k++)
	{
		if (b[k] < '0' || b[k] > '1')
			return (0);
		d_value = 2 * d_value + (b[k] - '0');
	}

	return (d_value);
}
