#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <fcntl.h>
#include <dirent.h>

#define DELIMITERS " \n\t"
extern char **environ;

/**
 * struct list_path - singly linked list.
 * @dir: directorie name.
 * @next: points to the next node.
 * Description: singly linked list node structure.
 */
typedef struct list_path
{
	char *dir;
	unsigned int len;
	struct list_path *next;
} list_path;
/**
 * struct builtins - bultin and its function.
 * @builtin: the builtin name.
 * @func: function to handle the builtin.
 * Description: shell builtins.
 */
typedef struct builtins
{
	char *builtin;
	void (*f)(char **, char **, int*, int, char**);
} builtins;

/**
 * struct fileIN - fileIN data.
 * @lines: file input line.
 * @len: number of lines in the file.
 * Description: file input datas.
 */
typedef struct fileIN
{
	char *lines[1024];
	int len;
} fileIN;

/* ========== 02-getline.c ========== */
char *getLine(void);

/* ========== 03-splitLine.c ========== */
char **splitLine(char *line);

/* ========== 04-execute.c ========== */
int _execute(char **command, char **argv, int idx, char **environment);

/* ========== 05-getenv.c ========== */
char *getEnv(char *variable);

/* ========== 06-getpath.c ========== */
list_path *buildDirList(void);
char *getPath(char *command);

/* ========== 07-bultins.c ========== */
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx,
char **new_env);
void exit_shell(char **command, char **argv, int *status, int idx,
char **new_env);
void print_env(char **command, char **argv, int *status, int idx,
char **new_env);

/* ========== 08-builtins2.c ========== */
void _setenv(char **command, char **argv, int *status, int idx,
char **new_env);
void _unsetenv(char **command, char **argv, int *status, int idx,
char **new_env);
void change_directory(char **command, char **argv, int *status, int idx,
char **new_env);

/* ========== 09-var_replace.c ========== */
void replace_variable(char **command, int status);

/* ========== 10-comments_handler.c ========== */
void comments_handler(char ***command);

/* ========== 11-fileIN.c ========== */
fileIN get_file_input(char **argv);

/* ========== 14-linked_list.c ========== */
list_path *add_node_end(list_path **head, const char *str);
void free_list_dir(list_path *head);

/* ========== 15-string.c ========== */
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* ========== 16-tools.c ========== */
void free2Darray(char **array);
void print_error(char *name, int idx, char *cmd);
void print_cd_error(char *name, int idx, char *path);
void set_wd_env(char *env_key, char *env_value, char **new_env);


/* ========== 17-tools2.c ========== */
char *_itoa(int n);
void reverse_string(char *str, int len);
int is_positive_number(char *str);
int _atoi(char *str);


#endif
