#include "simple_shell.h"

/**
 * env_checker - checks whether the variable is an env variable
 * @head: head of linked list var_node
 * @input_str: input string
 * @data_shell: data struct
 * Return: void
 */
void env_checker(var_node **head, char *input_str, data_of_inputs *data_shell)
{
	int i, j, match_index, value_len;
	char **env_vars;

	env_vars = (*data_shell).my_environ;
	for (i = 0; env_vars[i]; i++)
	{
		for (match_index = 1, j = 0; env_vars[i][j]; j++)
		{
			if (env_vars[i][j] == '=')
			{
				value_len = strlen_(env_vars[i] + j + 1);
				add_var_node(head, match_index, env_vars[i] + j + 1, value_len);
				return;
			}
			else if (input_str[match_index] == env_vars[i][j])
				match_index++;
			else
				break;
		}
	}

	for (match_index = 0; input_str[match_index]; match_index++)
	{
		if (input_str[match_index] == '\n' ||
				input_str[match_index] == ';' ||
				input_str[match_index] == ' ' ||
				input_str[match_index] == '\t')
			break;
	}

	add_var_node(head, match_index, NULL, 0);
}
