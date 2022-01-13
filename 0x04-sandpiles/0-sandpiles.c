#include "sandpiles.h"

/**
 * print_grid - function that print a grid
 * @grid: the first grid
 * Return: void
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
 * sandpiles_sum - function that computes the sum of two sandpiles 3x3
 * @grid1: the first grid
 * @grid2: the second grid
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int k = 0;
	int grid[3][3];

	simple_sand_sum(grid1, grid2);
	copy_grid(grid1, grid);
	do {
		k = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (k == 0)
					{
						printf("=\n");
						print_grid(grid1);
						k++;
					}
					make_topple(grid, i, j);
					k = 1;
				}
			}
		}
		copy_grid(grid, grid1);
	} while (k);
}

/**
 * copy_grid - function that copy the data of the first matrix into the
 * second that have 3x3 dimension
 * @grid1: the first grid
 * @grid2: the second grid
 * Return: void
 */
void copy_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}
}


/**
 * simple_sand_sum - function that computes the sum of two sandpiles 3x3
 * without topple
 * @grid1: the first grid
 * @grid2: the second grid
 * Return: void
 */
void simple_sand_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * make_topple - function that computes a sand topple
 * @grid: a grid
 * @i: the row index
 * @j: the column index
 * Return: void
 */
void make_topple(int grid[3][3], int i, int j)
{

	grid[i][j] -= 4;

	if (i + 1 < 3)
	{

		grid[i + 1][j]++;
	}
	if (i - 1 >= 0)
	{

		grid[i - 1][j]++;
	}
	if (j + 1 < 3)
	{

		grid[i][j + 1]++;
	}
	if (j - 1 >= 0)
	{

		grid[i][j - 1]++;
	}

}
