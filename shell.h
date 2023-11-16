#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIMITERS " \t\n" 
extern char **environ;


char *readLine(void);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, char *source);
int _execute(char **command, char **argv, char **environment, int index);

char **strToken(char *line);

void freeArr(char **arr);
char *_getenv(char *name);
char *_getpath(char *commandLine);
void _perror(char *name, char *command, int index);
char *_atoi(int n);
void revString(char *str, int length);


#endif
