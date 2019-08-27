#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/* #include <signal.h> */

/* */
/* typedef struct node_s
{
	char *name;
	char *val;
	struct node_s *next;
} node_t;
*/

/* */
typedef struct list_s {
	char *str;
	struct list_s *next;
} list_t;

/* */
typedef struct shell_s
{
	char **environ;
	node_t *path_list;
	node_t *hist_list;
	char **args;
	char *rest;
} shell_t;

/* */
typedef struct builtin_sh
{
	char *name;
	char *extra;
	int (*fp)(char **args, char **env, node_t **path_list, node_t **hist_list);
} builtin_t;



/* Signal Control */
void signal_control(int out);

/* Functions in helpers.c */
int word_counter(char *str);
int forker(int argc, char **argv);
int signal_status(int argc, char **argv);

/* Functions in err_handlers.c */
void exit_toobig(char **av, char **argv, char *to_str);
void err_handler(char **av, char **argv, char *to_str);

/* Functions in conversions.c file */
int string_to_int(char *s);
char *counter_to_string(int i, char *to_str);

/* Functions in pathfuncs.c file */
void print_env(void);
char *search_path(list_t *head, char *c, char **av, char *to_str);
char *_strstr(char *haystack, char *needle);
int char_check(char *s, const char *in);
char *_getenv(const char *name);

/* Functions in lists.c */
void build_linked_list(char *path, list_t **head);
void free_list(list_t *head);
list_t *add_node_end(list_t **head, char *str);

/* Functions in strops.c file */
/* Need to divide into different files - only 5 functions per file */
int _strlen(const char *s);
char **split_string(char *str);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/* Called in pathfuncs.c */
extern char **environ;

/* Functions that have not been called and files not added */
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_memcpy(char *dest, const char *src, unsigned int n);
int _strncmp(char *s1, char *s2, size_t bytes);

#endif /* SHELL_H */
