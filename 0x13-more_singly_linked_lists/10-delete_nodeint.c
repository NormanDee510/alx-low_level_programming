#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node on a particular index
 * @head: its a pointer to the first element in the list.
 * @index:the index of the node to be deleted.
 *
 * Return: 1 for Success or -1 for fail.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head;
	listint_t *current = NULL;
	unsigned int j = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	while (j < index - 1)
	{
		if (!tmp || !(tmp->next))
			return (-1);
		tmp = tmp->next;
		j++;
	}

	current = tmp->next;
	tmp->next = current->next;
	free(current);

	return (1);
}
