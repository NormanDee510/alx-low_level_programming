#include "lists.h"

/**
 * free_listint2 - it free a linked list
 * @head: its a pointer to the listint_t list to be free
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}
