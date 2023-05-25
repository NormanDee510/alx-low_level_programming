#include "main.h"

/**
 * get_endianness - it checks if a machine is a little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *e = (char *) &n;

	return (*e);
}
