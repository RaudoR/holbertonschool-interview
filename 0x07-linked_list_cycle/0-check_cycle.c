#include "lists.h"

/**
 * check_cycle - check if a linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
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