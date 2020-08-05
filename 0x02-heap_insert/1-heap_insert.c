#include "binary_trees.h"

/**
 * heap_insert - insert new node
 * @root: root node
 * @value: value to insert
 * Return: inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *push;
	int tmp;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}

	push = locnode(*root);
	new = binary_tree_node(push, value);
	if (push->left == NULL)
		push->left = new;
	else
		push->right = new;

	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->parent->n;
		new->parent->n = new->n;
		new->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * locnode - insert new node in location
 * @root: root node location
 * Return: new insertion
 */
heap_t *locnode(heap_t *root)
{
	heap_t *temp[50];
	heap_t *locnode = root;
	int start = 0, end = 0;

	while (locnode && locnode->left && locnode->right)
	{
		temp[start] = locnode->left;
		start += 1;
		if (start >= 49)
			start = 0;
		temp[start] = locnode->right;
		start += 1;
		if (start >= 49)
			start = 0;
		locnode = temp[end];
		end += 1;
		if (end >= 49)
			end = 0;
	}

	return (locnode);
}