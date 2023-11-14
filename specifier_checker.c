#include "main.h"

/**
 * specifier_checker - checks for the corresponding
 * format specifier
 *
 * @f_spec: format type
 * @anything_arg: pointer to the argumet
 *
 * Return: count of character
 */

int specifier_checker(char f_spec, va_list anything_arg)
{
	int counter;

	counter = 0;

	if (f_spec == 'c')
		counter += printChar(va_arg(anything_arg, int));
	else if (f_spec == 's')
		counter += printString(va_arg(anything_arg, char *));
	else if (f_spec == 'd')
		counter += printDigit(va_arg(anything_arg, int), 10);
	else if (f_spec == 'i')
		counter += printDigit((long)(va_arg(anything_arg, int)), 10);
	else if (f_spec == 'x')
		counter += printDigit((long)(va_arg(anything_arg, unsigned int)), 16);
	else if (f_spec == '%')
		counter += printChar('%');
	else if (f_spec == 'b')
		counter += printDigit((long)(va_arg(anything_arg, unsigned int)), 2);
	else if (f_spec == 'u')
		counter += printDigit((long)(va_arg(anything_arg, unsigned int)), 10);
	else if (f_spec == 'o')
		counter += printDigit((long)(va_arg(anything_arg, unsigned int)), 8);
	else if (f_spec == 'X')
		counter += printDigitX((long)(va_arg(anything_arg, unsigned int)), 16);
	else
	{
		counter += printChar('%');
		counter += write(STDOUT_FILENO, &f_spec, 1);
	}
	return (counter);
}
