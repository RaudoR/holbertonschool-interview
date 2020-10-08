#include "menger.h"

/**
 * fill_sponge - Recursively fill the menger sponge grid
 * @grid: menger sponge array
 * @x_start: starting x coordinate
 * @x_end: ending x coordinate
 * @y_start: starting y coordinate
 * @y_end: ending y coordinate
 */
void fill_sponge(int **grid, int x_start, int x_end, int y_start, int y_end)
{
	int step = (x_end - x_start) / 3;

	if (step == 0)
		grid[x_start][y_start] = 1;
	else
	{
		fill_sponge(grid, x_start, x_start + step,
			    y_start, y_start + step);
		fill_sponge(grid, x_start, x_start + step,
			    y_start + step, y_end - step);
		fill_sponge(grid, x_start, x_start + step,
			    y_end - step, y_end);

		fill_sponge(grid, x_start + step, x_start + step * 2,
			    y_start, y_start + step);
		fill_sponge(grid, x_start + step, x_start + step * 2,
			    y_end - step, y_end);

		fill_sponge(grid, x_end - step, x_end,
			    y_start, y_start + step);
		fill_sponge(grid, x_end - step, x_end,
			    y_start + step, y_end - step);
		fill_sponge(grid, x_end - step, x_end,
			    y_end - step, y_end);
	}
}

/**
 * draw_sponge - Draw the menger sponge
 * @grid: menger sponge array
 * @size: length of each row/column
 */
void draw_sponge(int **grid, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (grid[i][j])
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

/**
 * alloc_grid - Allocate a 2 dimensional array of integers
 * @width: The width of the array
 * @height: The height of the array
 * Return: Pointer to newly allocated space with array
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			free(grid);
			for (j = 0; j <= i; j++)
				free(grid[j]);

			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}

/**
 * free_grid - free a 2d array of integers
 * @grid: grid to be freed
 * @height: height of the array
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}

/**
 * menger - Draw a 2D menger sponge
 * @level: level to draw
 */
void menger(int level)
{
	int size;
	int **grid;

	if (level < 0)
		return;

	size = pow(3, level);
	grid = alloc_grid(size, size);
	if (grid == NULL)
		return;

	fill_sponge(grid, 0, size, 0, size);
	draw_sponge(grid, size);
	free_grid(grid, size);
}
