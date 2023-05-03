#include "lists.h"

/**
 * add_nodeint_end - it adds a new node at the end of the linked list.
 * @head: its a pointer to the first node in the list
 * @n: its the data to be inserted into the new_node.
 *
 * Return: a pointer to the new_node else a NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp = *head;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}
