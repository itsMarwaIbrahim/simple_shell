#include "simple_shell.h"

/**
 * strcat_ - string concatenation operation
 * @destination: where the concatenation result will be stored
 * @source: contains the string to be concatenated to the destination
 * Return: a pointer to the beginning of
 *	the destination string after the concatenation
 */
char *strcat_(char *destination, char *source)
{
	char *startDest;

	startDest = destination;

	for (; *destination != '\0'; destination++)
		;

	strncpy_(destination, source, strlen_(source));

	return (startDest);
}
