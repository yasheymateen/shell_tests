#include "shell.h"

void err_handler(char **av, char **argv, char *to_str)
{
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, to_str, _strlen(to_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": not found\n", 12);
}

void exit_toobig(char **av, char **argv, char *to_str)
{
	write(2, av[0], _strlen(av[0]));
	write(2, ": ", 2);
	write(2, to_str, _strlen(to_str));
	write(2, ": exit: Illegal number: ", 24);
	write(2, argv[1], _strlen(argv[1]));
	write(2, "\n", 1);
}
