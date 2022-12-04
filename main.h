#ifndef main_h
#define main_h
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
extern char **environ;
int main(int ac, char **av);
char *get_env(char *name);
char *find_path(char *str, char *input);
char * attach_path(char *str, char **input);
void free_grid(char **grid, int height);
void print_env();
#endif
