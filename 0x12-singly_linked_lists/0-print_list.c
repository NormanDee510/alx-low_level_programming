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

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			_putchar('[');
			_putchar('0');
			_putchar(']');
			_putchar(' ');
			_putchar('(');
			_putchat('n');
			_putchar('i');
			_putchar('l');
			_putchar(')');
			_putchar('\n');
		}
		else
		{
			_putchar('[');
			print_unsigned_int(h->len);
			_putchar(']');
			_putchar(' ');
			for (int i = 0; h->str[i]; i++)
				_putchar(h->str[i]);
			_putchar('\n');
		}
		h = h->next;
		count++;
	}
	return (count);
}

