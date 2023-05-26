#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - it prints anything
 * @format: its a list of types of arguments passed to a function
 */
void print_all(const char * const format, ...)
{
	int n = 0;
	char *strng, *seprt = "";

	va_list list;

	va_start(list, format);

	if (format)
	{
		while (format[n])
		{
			switch (format[n])
			{
				case 'c':
					printf("%s%c", seprt, va_arg(list, int));
					break;
				case 'n':
					printf("%s%d", seprt, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", seprt, va_arg(list, double));
					break;
				case 's':
					strng = va_arg(list, char *);
					if (!strng)
						strng = "(nil)";
					printf("%s%s", seprt, strng);
					break;
				default:
					n++;
					continue;
			}
			seprt = ", ";
			n++;
		}
	}

	printf("\n");
	va_end(list);
}
