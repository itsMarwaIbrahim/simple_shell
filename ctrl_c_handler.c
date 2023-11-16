#include "simple_shell.h"

/**
 * ctrl_c_handler - handle the case of pressing ctr + c
 * @ctrl: an integer
 */
void ctrl_c_handler(int ctrl __attribute__((unused)))
{
	write(STDOUT_FILENO, "\nExiting...\n", 12);
}
