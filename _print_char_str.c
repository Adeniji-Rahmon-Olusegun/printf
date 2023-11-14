#include "main.h"

/**
 * printChar - prints character
 *
 * @c: charater
 *
 * Return: 1
 */

int printChar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * printString - prints character
 *
 * @string: strings of character
 *
 * Return: length of string
 */

int printString(char *string)
{
	int counter;

	counter = 0;

	while (*string != '\0')
	{
		printChar((int)*string);
		string++;
		counter++;
	}

	return (counter);
}
