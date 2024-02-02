#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print a 3x3 grid
 * @grid: The grid to print
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
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: The first sandpile
 * @grid2: The second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int stable, tmp[3][3], i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	do {
		stable = 1;
		for (i = 0; i < 3 && stable; i++)
			for (j = 0; j < 3 && stable; j++)
				stable = grid1[i][j] <= 3;

		if (!stable)
		{
			printf("=\n");
			print_grid(grid1);
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
					tmp[i][j] = grid1[i][j];

			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (tmp[i][j] > 3)
					{
						grid1[i][j] -= 4;
						if (i > 0)
							grid1[i - 1][j]++;
						if (i < 2)
							grid1[i + 1][j]++;
						if (j > 0)
							grid1[i][j - 1]++;
						if (j < 2)
							grid1[i][j + 1]++;
					}
				}
			}
		}
	} while (!stable);
}
