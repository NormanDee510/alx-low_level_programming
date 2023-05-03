#include "lists.h"

/**
 * get_nodeint_at_index - it returns a node at a paticular index
 * @head: it is a 1st node in the linked list
 * @index: it is an index of the node that should be returned.
 *
 * Return: a pointer to the node else a NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n = 0;
	listint_t *tmp = head;

	while (tmp && n < index)
	{
		tmp = tmp->next;
		n++;
	}

	return (tmp ? tmp : NULL);
}
