#include <stdio.h>
#include "lists.h"

/**
 * print_list - it prints all of the elements of a linked list
 * @h: its a pointer to the list_t list to the print
 *
 * Return: the total number of nodes printed
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		int len = 0;
		char *str = h->str ? h->str : "(nil)";

		while (str[len])
			len++;
		_putchar('[');
		print_unsigned_int(h->len);
		_putchar(']');
		_putchar(' ');
		for (int i = 0; i < len; i++)
			_putchar(str[i]);
		_putchar('\n');
		h = h->next;
		count++;
	}
	return (count);
}

