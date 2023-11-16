#include "simple_shell.h"

/**
 * strchr_ - searches for the first occurrence of
 *	a specific character in a string
 * @string: a pointer to a null-terminated string
 * @c: representing the character to be located within string
 * Return: a pointer to the first occurrence of the character
 *	c within the string, or NULL
 */
char *strchr_(char *string, int c)
{
	for (; *string != '\0'; string++)
	{
		if (*string == c)
			return ((char *)string);
	}

	return (NULL);
}
