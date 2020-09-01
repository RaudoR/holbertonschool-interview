#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * grid_sum - adds two grids
 * @grid1: grid 1
 * @grid2: grid 2
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * print_grid - prints the grid
 * @grid: grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * refill_grid - rewrites grid with 0
 * @grid: grid to rewrite
 */
void refill_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = 0;
	}
}
/**
 * overflow - spreads to sides if num > 3
 * @grid1: grid 1
 * @grid2: grid 2
 */
void overflow(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] == 1)
			{
				grid1[i][j] -= 4;
				if (j + 1 < 3)
					grid1[i][j + 1] += 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] += 1;
				if (i + 1 < 3)
					grid1[i + 1][j] += 1;
				if (i - 1 >= 0)
					grid1[i - 1][j] += 1;
			}
		}
	}
}
/**
 * sandpiles_sum - computes the sum of two matrixes
 * @grid1: matrix1
 * @grid2: matrix2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, flag;

	grid_sum(grid1, grid2);
	while (1)
	{
		refill_grid(grid2);
		flag = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid2[i][j] = 1;
					flag = 1;
				}
			}
		}
		if (flag)
		{
			printf("=\n");
			print_grid(grid1);
		}
		else if (flag == 0)
			break;
		overflow(grid1, grid2);
	}
}