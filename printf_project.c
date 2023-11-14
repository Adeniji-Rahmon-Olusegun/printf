#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

/**
 * _printf - mimics actual printf function in
 * standard C library.
 *
 * @format: string contatining format specifier
 * @...: elipse for varible argument
 *
 * Return: integer
 */

int _printf(const char *format, ...)
{
	va_list anything_arg;
	int char_count;

	va_start(anything_arg, format);
	char_count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
			char_count += specifier_checker(*(++format), anything_arg);
		else
			char_count += write(STDOUT_FILENO, format, 1);
		format++;
	}

	va_end(anything_arg);

	return (char_count);

}
