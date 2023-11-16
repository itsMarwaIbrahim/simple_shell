#include "simple_shell.h"

/**
 * var_to_value - replaces variables in the input string with their values
 * @input_str: the inputted string
 * @data_shell: data struct
 * Return: the modified string
 */
char *var_to_value(char *input_str, data_of_inputs *data_shell)
{
	var_node *head, *index;
	char *str_status, *new_str_input;
	int old_str_len, new_str_len;

	str_status = int_to_str((*data_shell).input_status);
	head = NULL;

	old_str_len = var_checker(&head, input_str, str_status, data_shell);

	if (head == NULL)
	{
		free(str_status);
		return (input_str);
	}

	index = head;
	new_str_len = 0;

	while (index != NULL)
	{
		new_str_len = new_str_len + ((*index).value_length - (*index).var_length);
		index = (*index).next;
	}

	new_str_len = new_str_len + old_str_len;

	new_str_input = malloc(sizeof(char) * (new_str_len + 1));
	new_str_input[new_str_len] = '\0';

	new_str_input = input_to_value(&head, input_str, new_str_input, new_str_len);

	free(input_str);
	free(str_status);
	free_variable_list(&head);

	return (new_str_input);
}
