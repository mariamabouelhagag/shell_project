#include "shell.h"
/**
 * execute_builtin - prints the current environment.
 * @tokens: array of pointers.
 * Return: 0
 */

void execute_builtin(char **tokens)
{
	if (strcmp(tokens[0], "exit") == 0)
	{
		free_tokens(tokens);
		exit(EXIT_SUCCESS);
	}
		else if (strcmp(tokens[0], "env") == 0)
		{
			extern char **environ;
			char **env = environ;
			
			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}

			free_tokens(tokens);
		}
}
