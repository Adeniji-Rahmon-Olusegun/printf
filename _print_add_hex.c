#include "main.h"

/**
 * printAddressHex - prints an anddress in
 * hexadecimal format
 *
 * @pointer: void pinter
 *
 * Return: length of characters
 */

int printAddressHex(void *pointer)
{
	int counter;
	char *null_str;
	
	counter = 0;
	null_str = "(nil)";

	if (pointer == NULL)
	{
		while (*null_str != '\0')
		{
			counter += printChar(*null_str);

			null_str++;
		}
	}

	write(STDOUT_FILENO, "0", 1);
	write(STDOUT_FILENO, "x", 1);

	counter += printDigit((long unsigned int)pointer, 16) + 2;

	return (counter);
}
