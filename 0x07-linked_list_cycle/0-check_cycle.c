#include "lists.h"

/**
 * check_cycle - check for a cycle in the linked list
 * @list: head of the list
 * Return: 0 if failure to find a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *t = list, *h = list;

	while (t && h && h->next)
	{
		t = t->next;
		h = h->next->next;
		if (t == h)
			return (1);
	}

	return (0);
}