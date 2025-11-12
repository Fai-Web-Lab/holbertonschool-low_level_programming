#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_all - prints anything
 * @format: list of arguement types passed to the function
 *
 * Description: c = char, i = integer, f = float, s = string
 * Any other character is ignored
*/
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str, *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f'
i|| format[i] == 's')
		{
			prints("%s", sep);
			if (format[i] == 'c')
				printf("%c", va_arg(args, int));
			if (format[i] == 'i')
				printf("%d", va_arg(args, int));
			if (format[i] == 'f')
				printf("%f", va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *)
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
			}
			sep = ", ";
		}
		i++;
	}
	printf("\n");
	va_end(args);
}

