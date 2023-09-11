#include "shell.h"
char *get_path(char *cmd)
{
       	char *delim = ":", *path, *path_copy, *path_token, *file_path;
	int cmd_length, directory_length;
	struct stat buff;
	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		cmd_length = strlen(cmd);
		path_token = strtok(path_copy, delim);
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc (cmd_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");
			if (stat(file_path, &buff) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(path_copy);
				path_token = strtok(NULL, delim);
			}
		}
		free (path_copy);
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
			return (NULL);
		}
	}
	return (NULL);
}
