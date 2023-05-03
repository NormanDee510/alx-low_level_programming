#include "lists.h"

/**
 * print_listint - it prints all elements of a linked list.
 * @h: print listint_t linked list
 *
 * Return: the number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
