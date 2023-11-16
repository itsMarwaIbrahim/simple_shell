#include "simple_shell.h"

/**
 * memcpy_ - a function that copies memory area.
 * @destination: the buffer to be copied to
 * @source: the buffer to be copied
 * @n: number of bytes to be copied
 * Return: the modified buffer
 */
void *memcpy_(char *destination, char *source, size_t n)
{
	char *dest_ptr = destination;
	char *src_ptr = source;
	size_t i = 0;

	if (destination == NULL || source == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < n; i++)
	{
		dest_ptr[i] = src_ptr[i];
	}

	return (destination);
}
