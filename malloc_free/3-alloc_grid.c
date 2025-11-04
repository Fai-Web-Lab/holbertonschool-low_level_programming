#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a 2D aray of integers
 * @width: number of columns
 * @height: numbeer of rows
 *
 * Description: allocates memory for a 2D grid initialized to 0
 * if width or height is 0 or negative, returns NULL
 * if memory allocation fails, frees previously allocated memory
 *
 * Return: pointer to the 2D array, or NULL on failure
*/
int **alloc_grid(int width, int height)
{
	int **ggrid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (i - 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			while (i >= 0)
			{
				free(grid[i]);
				i--;
			}
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
