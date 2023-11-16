#include "simple_shell.h"

/**
 * remove_comments - removes the comments and returns
 * a copy of the string with no comments
 * @input: input string
 * Return: input with no comments (ON SUCCESS) or NULL (ON FAILURE)
 */
char *remove_comments(char *input)
{
	int a = 0, comment_position = 0;
	char *result;

	while (input[a] != '\0')
	{
		if (input[a] == '#')
		{
			if (a == 0)
				return (NULL);

			if (input[a - 1] == '\t' ||
				input[a - 1] == ';' ||
				input[a - 1] == ' ')
				comment_position = a;
		}
		a++;
	}

	if (comment_position != 0)
	{
		result = (char *)malloc(comment_position + 1);
		if (result == NULL)
			return (NULL);

		strncpy_(result, input, comment_position);
		result[comment_position] = '\0';
		return (result);
	} else
		return (strdup_(input));
}
