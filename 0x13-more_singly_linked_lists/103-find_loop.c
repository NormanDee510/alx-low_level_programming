#include "lists.h"

/**
 * find_listint_loop - it finds the loop in a linked list
 * @head: its a linked list to search for
 *
 * Return: the address of a node where a loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *shur = head;
	listint_t *mber = head;

	if (!head)
		return (NULL);

	while (shur && mber && mber->next)
	{
		mber = mber->next->next;
		shur = shur->next;
		if (mber == shur)
		{
			shur = head;
			while (shur != mber)
			{
				shur = shur->next;
				mber = mber->next;
			}
			return (mber);
		}
	}

	return (NULL);
}
