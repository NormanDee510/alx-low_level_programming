#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _islower - checcks for lowercase character
 * @c: the character to check
 * Return: 1 if c is lowercase, 0 otherwisw
 */
int _islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
