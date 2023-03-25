#include "main.h"
/**
 * print_line - function that draws a stright line in the term
 * @n:input number
 * Return: straight line
 */
void print_line(int n)
{
int i;

if (n <= 0)
{
_putchar('\n');
}
else
{
for (i = 1; i <= 5; i++)
{
_putchar('-');
}
_putchar('\n');
}
}
