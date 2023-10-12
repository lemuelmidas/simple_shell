#include "main.h"

/**
 * signal_handler - to print new line and prompt when CTRL + C is passed
 * as input
 *
 * @signal: name of sig
 */

void signal_handler(int signal)
{
	char *prompt = {"\n{^_^} "};
	(void) signal;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	fflush(stdout);
}

/**
 * output_error - to print the error output of a file
 * @argv: name of program
 * @count: number of prompt
 * @args: command to be put in
 * Return: if successful, 0.
 */

int *output_error(char *argv, int count, char *args)
{
	char *number;

	number = _itoa(count, 10);

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, number, _strlen(number));
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	perror(" ");

	return (0);
}

/**
 * _stat - to get a file's status
 * @cmd: point with commands
 * @path: location of each directory
 * Return: if successful, 1
 **/

int _stat(char **cmd, char **path)
{
	char *conc_str = NULL, *new_concat = NULL;
	int count;

	struct stat sb;

	if (path == NULL)
	{
		free(path);
		free(cmd);
		return (0);
	}

	for (count = 0; path[count] != NULL ; count++)
	{
		conc_str = str_concat(path[count], "/");
		new_concat = str_concat(conc_str, cmd[0]);
		if (stat(new_concat, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			cmd[0] = new_concat;
			free(conc_str);
			free(path[0]);
			free(path);
			return (1);
		}
		free(conc_str);
		free(new_concat);
	}
	free(path[0]);
	free(path);
	return (0);
}
