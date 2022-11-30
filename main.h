#ifndef main_h
#define main_h
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
extern char **environ;
int main(int ac __attribute__((unused)), char **av);
char * get_env(char *name)
#endif
