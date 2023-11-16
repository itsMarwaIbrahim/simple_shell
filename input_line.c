#include "simple_shell.h"

/**
 * input_line - reads an inputed line from users
 * @EOF_status: pointer to store getline function's return value
 * Return: the input string
 */
char *input_line(int *EOF_status)
{
	char *input_str = NULL;
	size_t buffer_size = 0;

	*EOF_status = getline(&input_str, &buffer_size, stdin);

	return (input_str);
}
