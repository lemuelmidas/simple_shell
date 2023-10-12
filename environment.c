#include "main.h"

/**
 * current_env - a function to print the current environment
 * @env: environment variable
 */
void current_env(char **env)
{
	int i;

	for (i = 0; env[i] ; i++)
	_puts(env[i]);
}
