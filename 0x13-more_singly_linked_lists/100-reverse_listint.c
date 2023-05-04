#include "lists.h"

/**
 * reverse_listint - it reverses a linked list.
 * @head: its a pointer to the first node in the linked list.
 *
 * Return: its a pointer to the first node.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = next;
	}

	*head = previous;

	return (*head);
}
