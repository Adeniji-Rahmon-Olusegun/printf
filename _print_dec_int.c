#include "main.h"

/**
 * printDigit - prints decimal, integer and
 * hexadecimal
 *
 * @number: decimal number
 * @base: base to whic it is to be converted
 *
 * Return: count of digits and (-) if signed
 */

int printDigit(long number, int base)
{
	int counter;
	char *hex_dec_symbols;

	hex_dec_symbols = "0123456789abcdef";

	if (number < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		return (printDigit(-number, base) + 1);
	}
	else if (number < base)
		return (printChar(hex_dec_symbols[number]));

	counter = printDigit((number / base), base);
	return (counter + printDigit((number % base), base));
}

/**
 * printDigitX - prints decimal, integer and
 * hexadecimal
 *
 * @number: decimal number
 * @base: base to whic it is to be converted
 *
 * Return: count of digits and (-) if signed
 */

int printDigitX(long number, int base)
{
	int counter;
	char *hex_dec_symbols;

	hex_dec_symbols = "0123456789ABCDEF";

	if (number < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		return (printDigitX(-number, base) + 1);
	}
	else if (number < base)
		return (printChar(hex_dec_symbols[number]));

	counter = printDigitX((number / base), base);
	return (counter + printDigitX((number % base), base));
}
