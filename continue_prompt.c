#include "simple_shell.h"

/**
 * continue_prompt - the loop of the shell program
 * @data_shell: the struct of the shell program
 */
void continue_prompt(data_of_inputs *data_shell)
{
	char *user_input;
	int EOF_indec, continue_prom = 1;

	for (; continue_prom == 1 ;)
	{
		write(STDIN_FILENO, "$ ", 2);
		user_input = input_line(&EOF_indec);

		if (EOF != -1)
		{
			user_input = remove_comments(user_input);
			if (!user_input)
				continue;

			user_input = var_to_value(user_input, data_shell);
		}
		else
		{
			free(user_input);
			break;
		}
	}
}
