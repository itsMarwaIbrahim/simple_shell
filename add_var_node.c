#include "simple_shell.h"

/**
 * add_var_node - adds a variable node at the end of the var_node list.
 * @h: pointer to the head of the linked list var_node
 * @var_len: the variable's length
 * @value: the variable's value
 * @value_len: the value's length
 * Return: address of the head
 */
var_node *add_var_node(var_node **h, int var_len, char *value, int value_len)
{
	var_node *new_node, *temp;

	new_node = malloc(sizeof(var_node));
	if (new_node == NULL)
		return (NULL);

	(*new_node).var_length = var_len;
	(*new_node).value = value;
	(*new_node).value_length = value_len;
	(*new_node).next = NULL;

	temp = *h;

	if (temp == NULL)
	{
		*h = new_node;
	}
	else
	{
		while ((*temp).next != NULL)
			temp = (*temp).next;
		(*temp).next = new_node;
	}

	return (*h);
}
