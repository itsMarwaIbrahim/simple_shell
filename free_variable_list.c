#include "simple_shell.h"

/**
 * free_variable_list - free the memory of the list
 * @h: head
 */
void free_variable_list(var_node **h)
{
	var_node *current_node, *store_node;

	if (h)
	{
		for (current_node = *h; (store_node = current_node) ;)
		{
			current_node = (*current_node).next;
			free(store_node);
		}

		*h = NULL;
	}
}
