#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>

/**
 * struct printf - the structure for type parameter
 * @type: type of the argument
 * @ptr: pointer to a function
 *
 */
typedef struct printf
{
	char *type;
	int (*ptr)();
}print_f;
int _printf(const char *format, ...);
int print_decimal(va_list list);
int print_integer(va_list list);
#endif
