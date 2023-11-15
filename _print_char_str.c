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

	if (string == NULL)
	{
		string = "(null)";

		while (*string != '\0')
		{
			counter += printChar(*string);
			string++;
		}
	}
	else
	{
		while (*string != '\0')
		{
			counter += printChar((int)*string);
			string++;
		}
	}

	return (counter);
}

/**
 * printStringS - prints character and
 * non-printable characters
 *
 * @string: strings of character
 *
 * Return: length of string
 */

int printStringS(char *string)
{
	char zero;
	int counter;
	int temp_var;

	zero = '0';
	counter = 0;

        if (string == NULL)
        {
                string = "(null)";

                while (*string != '\0')
                {
                        counter += printChar(*string);
                        string++;
                }
        }
        else
        {
                while (*string != '\0')
                {
                        if (((0 < (int)*string) && ((int)*string < 32)) || ((int)*string >= 127))
			{
				write(STDOUT_FILENO, "\\", 1);
				write(STDOUT_FILENO, "x", 1);
				counter += 2;
				
				temp_var = (int)*string;

				if (temp_var < 16)
				{
					write(STDOUT_FILENO, &zero, 1);
					counter += printDigitX((int)*string, 16);
				}
				else
					counter += printDigitX((int)*string, 16);
			}
			else
				counter += printChar((int)*string);
                        
			string++;
                }
        }
        return (counter);
}
