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
	char ch;
	char *string_holder;
	size_t tot_string_counter;
	va_list _printf_arg;

	va_start(_printf_arg, format);
	tot_string_counter = 0;
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(_printf_arg, int);
					write(STDOUT_FILENO, &ch, 1);
					tot_string_counter++;
					break;
				case 's':
					string_holder = va_arg(_printf_arg, char *);
					if (string_holder != NULL)
					{
						write(STDOUT_FILENO, string_holder, strlen(string_holder));
						tot_string_counter += strlen(string_holder);
					}
					break;
				case '%':
					write(STDOUT_FILENO, "%%", 1);
					tot_string_counter++;
					break;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			tot_string_counter++;
		}
		format++;
	}
	va_end(_printf_arg);
	return ((int)(tot_string_counter));
}
