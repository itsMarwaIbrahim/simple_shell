#include "simple_shell.h"

/**
 * strcpy_ - copy a string from the source to the destination
 * @destination: where the string from source will be copied
 * @source: A pointer to a null-terminated string
 * Return: a pointer to the beginning of the destination
 */
char *strcpy_(char *destination, char *source)
{
	char *startDest;

	startDest = destination;

	for (; *source != '\0'; destination++, source++)
		*destination = *source;

	*destination = '\0';

	return (startDest);
}
