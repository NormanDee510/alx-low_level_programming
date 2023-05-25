#include "main.h"

/**
 * get_bit - it returns a value of a bit at an index in a decimal number
 * @n: its the number to search
 * @index: its an index of the bit
 *
 * Return: value of a bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bt_value;

	if (index > 63)
		return (-1);

	bt_value = (n >> index) & 1;

	return (bt_value);
}
