#include "lists.h"

/**
 * reverse_list - reverse the list
 * @head: first node
 */
void reverse_list(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *curr = *head, *next;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

/**
 * compare_l - check if 2 lists are the same
 * @head1: first list
 * @head2: second list
 * Return: 1 if they're the same, 0 on failure
 */
int compare_l(listint_t *head1, listint_t *head2)
{
	listint_t *first = head1;
	listint_t *second = head2;

	while (first && second)
	{
		if (first->n != second->n)
			return (0);
		first = first->next;
		second = second->next;
	}

	if (!first && !second)
		return (1);
	return (0);
}

/**
 * is_palindrome - check for palindrome
 * @head: first node
 * Return: 1 if it's a palindrome, 0 on failure
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	listint_t *second_half, *prev = *head;
	listint_t *mid = NULL;
	int palindrome = 1;

	if (fast && fast->next)
	{
		while (fast && fast->next)
		{
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}

		if (fast)
		{
			mid = slow;
			slow = slow->next;
		}

		second_half = slow;
		prev->next = NULL;
		reverse_list(&second_half);
		palindrome = compare_lists(*head, second_half);
		reverse_list(&second_half);

		if (mid)
		{
			prev->next = mid;
			mid->next = second_half;
		}
		else
			prev->next = second_half;
	}

	return (palindrome);
}