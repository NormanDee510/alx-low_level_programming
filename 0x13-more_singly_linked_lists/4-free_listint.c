#include "lists.h"

/**
 * free_listint - it free a linked list.
 * @head: to free listint_t list.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
