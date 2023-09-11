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
		if (path_copy == NULL)
		{
			perror("get_path");
			exit(EXIT_FAILURE);
		}
		cmd_length = strlen(cmd);
		path_token = strtok(path_copy, delim);
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(cmd_length + directory_length + 2);
			if (file_path == NULL)
			{
				perror("get_path");
				exit(EXIT_FAILURE);
			}
			snprintf(file_path, cmd_length + directory_length + 2, "%s/%s", path_token, cmd);
			if (stat(file_path, &buff) == 0)
			{
				free(path_copy);
				return file_path;
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, delim);
			}
		}
		free(path_copy);
	}
	if (stat(cmd, &buff) == 0)
	{
		return strdup(cmd);
	}
	return NULL;
}
