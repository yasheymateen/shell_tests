#include "shell.h"

/**
  * word_counter - Calls Function
  * @str: ...
  * Description: ...
  * Return: ...
  */
int word_counter(char *str)
{
	int i, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

int signal_status(int argc, char **argv)
{
	int i, is_on = 1, counter = 1;
	size_t buf_size = 0;
	char **argv = NULL, *buf = NULL;

	while (is_on)
				{
					signal(SIGINT, signal_control);
					if (isatty(0) == 1)
						write(STDOUT_FILENO, "$ ", 2);
					if (getline(&buf, &buf_size, stdin) == EOF)
					{
						if (isatty(0) == 1)
							write(STDOUT_FILENO, "\n", 1);
						break;
					}
					i = _strlen(buf);
					if (i > 1)
						buf[i - 1] = '\0';
					argv = split_string(buf);

					if (!argv)
					{
						counter++;
						continue;
					}
				}
	return (0);
}


int forker(int argc, char **argv)
{
	pid_t child_pid;
	int status, is_on = 1, exit_stat = 0, counter = 1;
	size_t too_big = 0;
	char *to_str, *full_command = NULL, **argv = NULL;
	list_t *head = NULL;

	while (is_on);
	{

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			exit(1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);

			if (_strcmp(argv[0], "exit") == 0)
			{
				free(argv);
				break;
			}
			if (_strcmp(argv[0], "env") == 0)
			{
				print_env();
				free(argv);
				break;
			}
			else if (argv[0][0] != '/')
			{
				counter_to_string(counter, to_str);
				full_command = search_path(head, argv[0], av, to_str);
				if (full_command)
					execve(full_command, argv, NULL);
			}
			if (argv[0][0] != '\n' && full_command == NULL)
			{
				counter_to_string(counter, to_str);
				err_handler(&av[0], &argv[0], to_str);
				free(to_str);
				exit_stat = 127;
				free(argv);
			}
			exit(exit_stat);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				exit_stat = WEXITSTATUS(status);
			if (_strcmp(argv[0], "exit") == 0)
			{
				is_on = 0;
				if (argv[1])
				{
					counter_to_string(counter, to_str);
					too_big = string_to_int(argv[1]);
					if (too_big > 2147483647 || _strlen(argv[1]) > 10)
					{
						exit_toobig(&av[0], &argv[0], to_str);
						is_on = 1;
						exit_stat = 2;
						continue;
					}
					exit(string_to_int(argv[1]));
				}
			}
			if (full_command)
				free(full_command);
		}
		counter++;
		free(argv);
	}
	return (0);
}
