#include "lists.h"

/**
 * free_listint_safe - it sets free a linked list
 * @h: its a pointer to the 1st node in the linked list
 *
 * Return: the number of elements in the list set free
 */
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int diffnt;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diffnt = *h - (*h)->next;
		if (diffnt > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}

	*h = NULL;

	return (length);
}
