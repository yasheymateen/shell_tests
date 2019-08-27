#include "shell.h"

/**
  * signal_control - Calls function
  * @out: ...
  * Description: ...
  * Return: 0
  */
void signal_control(int out)
{
	(void) out;

	signal(SIGINT, signal_control);
	write(1, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
