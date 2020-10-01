#include "slide_line.h"
/**
 * slide_line - function that slides and merges an array of integers
 * @line: array of integers
 * @size: size of elements
 * @direction: direction duh
 * Return: 1 on success or 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction == SLIDE_LEFT)
	{
		slide_zero(line, size);
		slide_non_zero(line, size);
		slide_zero(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		a_reverse(line, size);
		slide_zero(line, size);
		slide_non_zero(line, size);
		slide_zero(line, size);
		a_reverse(line, size);
		return (1);
	}
	return (0);
}
/**
 * a_reverse - reverse array
 * @line: pointer to the array
 * @size: size of array
 * Return: void
 **/
void a_reverse(int *line, size_t size)
{
	size_t a, b;

	a = 0;
	b = size - 1;
	while (a < b)
	{
		int temp = line[a];

		line[a] = line[b];
		line[b] = temp;
		a++;
		b--;
	}
}

/**
 * slide_zero - moves zeros
 * @line: pointer to the array
 * @size: size of array
 * Return: void
 **/
void slide_zero(int *line, size_t size)
{
	size_t i;
	size_t zero = 0;

	i = 0;
	while (i < size)
	{
		if (line[i] == 0)
			zero++;
		else if (zero)
			line[i - zero] = line[i];
		i++;
	}
	while (zero > 0)
	{
		line[i - 1] = 0;
		zero--;
		i--;
	}
}

/**
 * slide_non_zero - moves non zeros
 * @line: pointer to the array
 * @size: size of array
 * Return: void
 **/
void slide_non_zero(int *line, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
		i += 2;
	}
}
