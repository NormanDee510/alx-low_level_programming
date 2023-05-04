#include "lists.h"
#include <stdio.h>

size_t print_listint_safe(const listint_t *head);
size_t looped_listint_len(const listint_t *head);

/**
 * looped_listint_len - it counts the number of nodes in a looped
 * listint_t linked list.
 * @head: its a pointer to the head of the listint_t
 *
 * Return: If the function fails, exit the program with status 98
 * else the number of nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *first_node, *last_node;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	first_node = head->next;
	last_node = (head->next)->next;

	while (last_node)
	{
		if (first_node == last_node)
		{
			first_node = head;

			while (first_node != last_node)
			{
				nodes++;
				first_node = first_node->next;
			}

			return (nodes);
		}

		first_node = first_node->next;
		last_node = (last_node->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe -  Prints a listint_t list.
 * @head: its a pointer to the head of the listint_t list
 *
 * Return: returns the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("->[%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
