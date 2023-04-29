#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *last;

	/*Allocate memory for the new node*/
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	/*Populate the new node*/
	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	/* If the list is empty, new node is the head */
	if (*head == NULL)
	{
		*head = new;

		return (new);
	}

	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;

	return (new);
}
