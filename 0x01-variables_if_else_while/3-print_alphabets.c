#include <stdio.h>

/**
 * main - Print the alphabets in lowercase and in uppercase
 *
 * Return Always 0 (Success)
 */
int main(void)
{
char alphabet[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n = 97;
	int i = 65;

	while (n <= 122)
	{
		putchar(n);
	}
	while (i <= 90)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
