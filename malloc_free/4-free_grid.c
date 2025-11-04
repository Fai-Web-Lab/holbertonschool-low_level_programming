#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: pointer to the 2D grid
 * @height: height of the grid
 *
 * Description: Frees the memory allocated for a 2-dimensional
 * array of integers. Does nothing if grid is NULL or height <= 0.
 *
 * Return: void
*/
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
