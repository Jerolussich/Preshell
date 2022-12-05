#include "main.h"

/**
 * free_grid - Frees a 2 dimensional grid
 * @grid: Grid to be freed
 * @height: Height of the grid
*/

void free_grid(char **grid)
{
	int height= 0, i;

	for (i = 0; grid[i]; i++)
		heigth++;

	if (grid)
	{
		for (i = 0; i <= height; i++)
		{
			free(grid[i]);
		}
		free(grid);
	}
}
