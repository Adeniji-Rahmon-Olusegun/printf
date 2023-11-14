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
	/**
	 *else if (f_spec == 'd')
	 *	counter += printDigit(va_arg(anything_arg, int), 10);
	 *else if (f_spec == 'x')
	 *	counter += printDigit(va_arg(anything_arg, unsigned int), 16);
	 */
	else
		counter += write(STDOUT_FILENO, &f_spec, 1);
	return (counter);
}
