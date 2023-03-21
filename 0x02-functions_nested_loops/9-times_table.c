#include "main.h"
/**
 * void times_table -  function that prints the 9 times table, starting with 0
 *
 * Description: 'the function prints the 9 times table and display the output
 *
 * Return: no return
 */
void times_table(void)
{
	int row;
	int col;

	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			int result = row * col;

			printf("%d, ", result);
		}
		printf('\n');
	}
}
