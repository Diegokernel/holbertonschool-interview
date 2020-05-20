#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid
 * @grid: 3x3 grid
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
 * is_unstable - checks if sandpile is unstable
 * @grid: the sandpile to check
 * Return: 1 if unstable else 0
 */
int is_unstable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * add_sandpiles - adds two sandpiles, saves result in grid1
 * @grid1: sandpile #1
 * @grid2: sandpile #2
 */
void add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * check_piles- tumble a sandpile grid square
 * @grid: grid to tumble on
 * Return: void
 */
void check_piles(int grid[3][3])
{
	int i, j;
	int r_grid[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{   grid[i][j] -= 4;
				if ((i + 1) >= 0 && (i + 1) < 3)
					r_grid[i + 1][j] += 1;
				if ((j + 1) >= 0 && (j + 1) < 3)
					r_grid[i][j + 1] += 1;
				if ((i - 1) >= 0 && (i - 1) < 3)
					r_grid[i - 1][j] += 1;
				if ((j - 1) >= 0 && (j - 1) < 3)
					r_grid[i][j - 1] += 1;
			}
		}
	}
	add_sandpiles(grid, r_grid);
}

/**
 * sandpiles_sum - computes the final stable sum of two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_sandpiles(grid1, grid2);
	while (is_unstable(grid1) == 0)
	{
		printf("=\n");
		print_grid(grid1);
		check_piles(grid1);
	}

}
