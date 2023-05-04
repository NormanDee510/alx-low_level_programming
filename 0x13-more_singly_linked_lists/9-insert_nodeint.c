#include "lists.h"

/**
 * insert_nodeint_at_index - it inserts a node in a linked list at a
 * any given position.
 * @head: its a pointer to the first node in the linked list
 * @idx: locates the index where the new node is added.
 * @n: the data to be inserted into the new node.
 *
 * Return: the pointer to the new node else a NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *new_node;
	listint_t *tmp = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (j = 0; tmp && j < idx; j++)
	{
		if (j == idx - 1)
		{
			new_node->next = tmp->next;
			tmp->next = new_node;
			return (new_node);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);
}
