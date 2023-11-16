#include "simple_shell.h"

/**
 * find_non_whitespace_char - find non-whitespace character
 * @user_input: the input string
 * @counter: a pointer to an integer
 * Return: 0 if it successfully done
 */
int find_non_whitespace_char(char *user_input, int *counter)
{
	char *symbols1;
	char *symbols2;


	symbols1 = "\t ";
	symbols2 = "|;&";
	counter = 0;
	while (user_input[*counter])
	{
		if (strchr_(symbols1, user_input[*counter]))
		{
			counter++;
			continue;
		}


		if (strchr_(symbols2, user_input[*counter]))
			return (-1);


		break;
	}
	return (0);
}
