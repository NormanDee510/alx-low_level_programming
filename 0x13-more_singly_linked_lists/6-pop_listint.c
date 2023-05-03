#include "lists.h"

/**
 * pop_listint - removes the head node of a linked list.
 * @head: its a pointer to the first element in the linked list.
 *
 * Return: th data in the elements that was removed,
 * else NULL if the list is empty.
 */
int  pop_listint(listint_t **head)
{
	int num;
	listint_t *tmp;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;

	return (num);
}
