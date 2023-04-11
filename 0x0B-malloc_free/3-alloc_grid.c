#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
int **tee;
int x, y;

if (width <= 0 || height <= 0)
return (NULL);

tee = malloc(sizeof(int *) * height);

if (tee == NULL)
return (NULL);

for (x = 0; x < height; x++)
{
tee[x] = malloc(sizeof(int) * width);

if (tee[x] == NULL)
{
for (; x >= 0; x--)
free(tee[x]);

free(tee);
return (NULL);
}
}
for (x = 0; x < height; x++)
{
for (y = 0; y < width; y++)
tee[x][y] = 0;
}

return (tee);
}
