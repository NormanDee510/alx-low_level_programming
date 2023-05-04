#include "lists.h"

/**
 * find_listint_loop - it finds the loop in the linked list
 * @head: the linked list to search
 *
 * Return: the address of the node on where the loop starts
 * else NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *last = head;
	listint_t *first = head;

	if (!head)
		return (NULL);

	while (last && first && first->next)
	{
		first = first->next->next
			last = last->next;
		if (first == last)
		{
			last = head;
			while (last != first)
			{
				last = last->next;
				first = first->next;
			}
			return (fast);
		}
	}

	return (NULL);
}
