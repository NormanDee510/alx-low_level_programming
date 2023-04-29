#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list _t list
 * @head: double pointer to the head of the list
 * @str: string to be added as the str member of the new node
 *
 * Return: the address of the new element, or NULL if it fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->len = strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}
