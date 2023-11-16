#include "simple_shell.h"

/**
 * input_to_value - change the input to the value
 * @h: the head
 * @o_str: the original string
 * @mod_str: the string to be modified
 * @mod_str_len: the length of the modified string
 * Return: the modified string
 */
char *input_to_value(var_node **h, char *o_str, char *mod_str, int mod_str_len)
{
	int input, new, value = 0;
	var_node *current_var;

	current_var = *h;
	new = input = 0;
	while (input < mod_str_len)
	{
		if ('$' == *(o_str + new))
		{
			if ((*current_var).var_length != 0 && (*current_var).value_length == 0)
			{
				while (value < (*current_var).var_length)
					value++;
				input--;
			}
			else if ((*current_var).var_length == 0 && (*current_var).value_length == 0)
			{
				*(mod_str + input) = *(o_str + new);
				new++;
			}
			else
			{
				while (value < (*current_var).value_length)
				{
					*(mod_str + input) = (*current_var).value[value];
					value++;
				}
				new = new + (*current_var).var_length;
				input--;
			}
		}
		else
		{
			*(mod_str + input) = *(o_str + new);
			new++;
		}
		input++;
	}
	return (mod_str);
}

