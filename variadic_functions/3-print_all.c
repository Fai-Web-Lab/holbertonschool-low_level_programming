#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_all - prints anything
 * @format: list of argument types passed to the function
 *
 * Description: c = char, i = int, f = float, s = string
 * If a string is NULL, (nil) is printed instead.
 * Any other format character is ignored.
 * Return: Nothing
*/
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *s, *sep = "";
	int c, d;
	float f;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == 'c' || format[i] == 'i' ||
		    format[i] == 'f' || format[i] == 's')
		{
			printf("%s", sep);
			switch (format[i])
			{
			case 'c':
				c = va_arg(args, int);
				printf("%c", c);
				break;
			case 'i':
				d = va_arg(args, int);
				printf("%d", d);
				break;
			case 'f':
				f = (float)va_arg(args, double);
				printf("%f", f);
				break;
			case 's':
				s = va_arg(args, char *);
				if (!s)
					s = "(nil)";
				printf("%s", s);
				break;
			}
			sep = ", ";
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
