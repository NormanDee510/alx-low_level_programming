#include "lists.h"

/**
 * listint_len - it return the total number of elements in a linked lists.
 * @h: it traverse  listint_t linked list
 *
 * Return: total number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
