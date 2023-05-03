#include "lists.h"

/**
 * sum_listint - it sums up all the data in the listint_t list.
 * @head: its the first node inthe linked list
 *
 * Return: the summation
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *tmp = head;

	while (tmp)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}
	return (sum);
}
