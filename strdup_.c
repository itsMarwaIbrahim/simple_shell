#include "simple_shell.h"

/**
 * strdup_ - allocates memory for a new string and copies
 * the contents of the original string into it
 * @string: the string passed to the function
 * Return: a pointer to char
 */
char *strdup_(char *string)
{
	int counter = 0, strlen;
	char *ptrChar;

	if (!string)
		return (NULL);

	strlen = strlen_(string);

	ptrChar = (char *)malloc(strlen + 1);
	if (!ptrChar)
		return (NULL);

	memcpy_(ptrChar, string, counter + 1);

	return (ptrChar);
}
