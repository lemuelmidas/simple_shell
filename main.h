#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define USE_GETLINE 0
#define USE_STRTOK 0
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	5000

/* environment.c */
void current_env(char **env);


/* errorhandler.c */
void signal_handler(int signal);
int *output_error(char *argv, int count, char *args);
int _stat(char **cmd, char **path);

/* for_str.c */
void _puts(char *str);
int _strlen(const char *s);
int _putchar(char c);
char *str_concat(char *c1, char *c2);
int _strcmp(char *c1, char *c2);

/* loopers.c */
char *standard_input(void);
char **seperate_str(char *line, char **env);
void prompt(void);

/* main_prompt.c */
int main_prompt(int ac __attribute__((unused)), char **av, char **env);

/* other_str.c */
char *_strdup(char *str);
char *_itoa(int num, int base);

/* sub_loopers.c */
char **passed_path(char *foundpath);
int child_process(char **av, char **args, char **env, int status_main, int cnt);
char **execute_path(char **env);

void *allocate_memory(unsigned int nmemb, unsigned int size);

#endif
