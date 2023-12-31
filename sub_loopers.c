#include "main.h"

/**
 * passed_path - a function to identify the path of the command(*args) that
 * is being passed to it.
 *
 * @foundpath: the command that is being passed to it
 * Return: the complete path of the command or 0 on failure
 */

char **passed_path(char *foundpath)
{
	int size = TOK_BUFSIZE, i = 0;
	char *copy_path = NULL, *tokens = NULL, *sparse = ":=";
	char **dir = allocate_memory(sizeof(char *), size);

	if (foundpath == NULL)
	{
		free(foundpath);
		return (0);
	}
	if (dir == NULL)
	{
		free(foundpath);
		perror("Error allocating memory");
		return (NULL);
	}

	copy_path = _strdup(foundpath);
	tokens = strtok(copy_path, sparse);
	while (tokens != NULL)
	{
		dir[i] = tokens;
		i++;
		tokens = strtok(NULL, sparse);
	}

	return (dir);
}


/**
 * child_process - executes a command if the path of it is an executable file
 * @args: the command to be executed
 * @env: environment variable
 * @status_main: status variable
 * @av: name of program
 * @cnt: count of prompt
 * Return: 1
 */

int child_process(char **av, char **args, char **env, int status_main, int cnt)
{
	pid_t pid;
	int status;

	if (args == NULL)
	return (-1);

	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			output_error(av[0], cnt, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (status_main == 1)
		free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

/**
 * execute_path - a function that gets the path to execute commands
 * @env: Environment variable
 * Return: token_path
 **/

char **execute_path(char **env)
{
	int location;
	char **token_path;

	for (location = 0; env[location] != NULL ; location++)
	{
		if (env[location][0] == 'P' && env[location][2] == 'T')
		{
			token_path = passed_path(env[location]);
		}
	}
	return (token_path);
}
