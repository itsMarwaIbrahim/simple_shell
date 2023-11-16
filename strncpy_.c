#include "simple_shell.h"

/**
 * *strncpy_ - copies a string to the destination string
 * @destination: the string to be copied to
 * @source: the string to be copied
 * @n: the number of characters/bytes to be copied
 * Return: destination
 */
char *strncpy_(char *destination, char *source, int n)
{
	int a = 0;

	if (n == 0)
		return (destination);

	for (a = 0; a < n && source[a] != '\0'; a++)
		destination[a] = source[a];

	for (a = 0; a < n; a++)
		destination[a] = '\0';

	return (destination);
}
