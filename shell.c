#include "shell.h"
/**
 * main - the main function.
 * @tokens: the array of pointers to be execluded.
 *
 * Return: 0.
 */

int main(void)
{
	pid_t pid;
	char **tokens = NULL;
	
	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		tokens = token_save();
		if (tokens[0] != NULL)
		{
			execute_builtin(tokens)
		}
		pid = fork();
		
		if (pid == -1)
		{
			perror("fork");
			free_tokens(tokens);
			return (-1);
		}
		if (pid == 0)
		{
			if (execvp(tokens[0], tokens) == -1)
			{
				perror(tokens[0]);
				free_tokens(tokens);
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(NULL);
			free_tokens(tokens);
		}
		else
		{
			free_tokens(tokens);
		}
		return (0);
}
#include "shell.h"
/**
 * main - the main function.
 * @tokens: the array of pointers to be execluded.
 * 
 * Return: 0.
 */

int main(void)
{
	pid_t pid;
	char **tokens = NULL;
	
	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		tokens = token_save();
		if (tokens[0] != NULL)
		{
			execute_builtin(tokens);
			pid = fork();
			
			if (pid == -1)
			{
				perror("fork");
				free_tokens(tokens);
				return (-1);
			}
			if (pid == 0)
			{
				if (execvp(tokens[0], tokens) == -1)
				{
					perror(tokens[0]);
					free_tokens(tokens);
					exit(EXIT_FAILURE);
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
				free_tokens(tokens);
			}
			else
		}
		free_tokens(tokens);
	}
}
return (0);
}
