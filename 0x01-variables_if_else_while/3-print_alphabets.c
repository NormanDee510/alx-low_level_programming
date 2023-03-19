#include <stdio.h>
/**
 * main - Entry point
 * Description: Print the alphabets in lowercase and in uppercase
 * Return Always 0 (Success)
 */
int main(void)
{

	int n = 97;
	int i = 65;

	while (n <= 122)
	{
		putchar(n);
		n++;
	}
	while (i <= 90)
	{
		putchar(i);
		i++;
	}
	putchar('\n');
	return (0);
}
