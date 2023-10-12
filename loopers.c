#include "main.h"

/**
 * standard_input - a function to store whatever is passed to it as standard input
 * Return: string containing the input
 */
char *standard_input(void)
{
  char *line = NULL;
  ssize_t signal;
  size_t bufsize = 0;
  int i;

  signal = getline(&line, &bufsize, stdin);
  if (!line)
    {
      perror("Error allocating memory for buffer");
      return (0);
    }
  if (signal == 1)
    {
      free(line);
      return (NULL);
    }
  else if (signal == EOF)
    {
      if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "\n", 1);
      free(line);
      exit(0);
    }
  else
    {
      for (i = 0; line[i] == ' ' && line[i + 1] == ' '; i++)
	;
      if (!line[i] && line[i + 1] == '\n')
	{
	  free(line);
	  return (0);
	}
    }
  return (line);
}

/**
 * seperate_str - to seperate/convert a string into an array of strings
 * @line: the string to be separated
 * @env: environment variable
 * Return: tokens(array of strings) on succes or EXIT_FAILURE if fails
 */
char **seperate_str(char *line, char **env)
{
  int bufsize = TOK_BUFSIZE, location = 0;
  char **tokens;
  char *token;

  if (line == NULL)
    {
      return (0);
    }
  tokens = _calloc(sizeof(char *), bufsize);
  if (!tokens)
    {
      perror("error");
      exit(EXIT_FAILURE);
    }
  token = strtok(line, TOK_DELIM);
  while (token != NULL)
    {
      tokens[location] = token;
      location++;
      token = strtok(NULL, TOK_DELIM);
    }
  if (tokens[0] == NULL)
    tokens[location] = "\n";


  if ((_strcmp(tokens[0], "exit") == 0) && tokens[1] == NULL)
    {
      free(line);
      free(tokens);
      exit(0);
    }
  if ((_strcmp(tokens[0], "env") == 0) && tokens[1] == NULL)
    current_env(env);

  return (tokens);
}


/**
 * prompt - to print the '$' sign and wait for a user's input
 */
void prompt(void)
{
  char *prompt = {"{^_^} "};
  char *buffer = getcwd(NULL, 0);

  if (isatty(STDIN_FILENO))
    {
      write(STDOUT_FILENO, prompt, _strlen(prompt));
    }
  free(buffer);
}
