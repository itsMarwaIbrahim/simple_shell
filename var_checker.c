#include "simple_shell.h"

/**
 * var_checker - checks if there are '?', '$', '\t', '\0', ';', '\n', ' '
 * @h: a double pointer to a var_node, manipulates a linked list of var_nodes
 * @str: the inputted string
 * @last_stat: the last status
 * @info: data struct
 * Return: an integer value
 */
int var_checker(var_node **h, char *str, char *last_stat, data_of_inputs *info)
{
	int a, last_status_size, PID_len;

	last_status_size = strlen_(last_stat);
	PID_len = strlen_((*info).PID);
	for (a = 0; str[a]; a++)
	{
		if (str[a] == '$')
		{
			switch (str[a + 1])
			{
				case '?':
					add_var_node(h, 2, last_stat, last_status_size);
					break;
				case '$':
					add_var_node(h, 2, (*info).PID, PID_len);
					break;
				case '\t':
				case '\0':
				case ';':
				case '\n':
				case ' ':
					add_var_node(h, 0, NULL, 0);
					break;
				default:
					env_checker(h, str + a, info);
					break;
			}
		}
	}
	return (a);
}
