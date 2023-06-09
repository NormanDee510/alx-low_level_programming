#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 * _isalpha - checks for aphabetic character
 * @c: the character to be checked
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
