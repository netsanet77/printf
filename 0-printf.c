#include "main.h"
/**
 * print_integer - print an integer
 * @list: the given argument
 * Return: number of integer character printed (1)
 */

int print_integer (va_list list)
{
	int a = va_arg(list, int);
	int n, i = 0;

	n = a;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (n < 0)
		i++;

	printf("%d", a);
	return (i);
}
/**
 * print_decimal - print the percent
 * @list: the given argument
 * Return: number of decimal number printed (1)
 */

int print_decimal(va_list list)
{
	int a = va_arg(list, int);
	int n, i = 0;

	n = a;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (n < 0)
		i++;
	printf("%d", a);
	return (i);
}

/**
 * _printf - produce an output based on format
 * @format: a character string
 *
 * Return: the number of character printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j, no_char = 0;

	print_f print[] = {
	{"%i", print_integer},
	{"%d", print_decimal}
	};

	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 2)
		{
		if (format[i] == print[j].type[0] && format[i + 1] == print[j].type[1])
		{
			no_char += print[j].ptr(ap);
			 i = i + 2;
			 break;
		}
		else
			j++;
		}
		printf("%c", format[i]);
		no_char++;
		i++;

	}
	va_end(ap);
	return (no_char);
}

