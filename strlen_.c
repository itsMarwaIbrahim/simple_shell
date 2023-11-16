#include "simple_shell.h"

/**
 * strlen_ - calculate the length of a string
 * @string: where the length is to be calculated
 * Return: the length of the input string
 */
int strlen_(char *string)
{
	int counter = 0;

	while (*string)
	{
		string++;
		counter++;
	}

	return (counter);
}
