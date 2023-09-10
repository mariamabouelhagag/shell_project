#ifndef SHELL_H
#define SHELL_H
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **token_save();
void free_tokens(char **tokens);
void execute_builtin(char **tokens);
char *get_path(char *cmd);

#endif
