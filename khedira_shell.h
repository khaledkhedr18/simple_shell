
#ifndef KHEDIRA_SHELL_H
#define KHEDIRA_SHELL_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

extern char **environ;

#define MAX_ARGINPUT_SIZE 100
#define MAX_ARGUMENTS 10

void khedira_prompt(void);
int	khedira_char(int c);
int	khedira_digit(long n, int base);
int	khedira_str(char *string);
int	khedira_format(char khediraspec, va_list khediraap);
int	khedira(const char *myFormat, ...);
void khedira_uinput(char *comm, size_t size, int mystatus);
int khedira_exec(char *exec_comm, int mystatus);
int khedira_tokenize(char *myinp, char *myargs[]);
int khedira_is_exit(char *excomm);
void khedira_exit(int status);
int khedira_printenv(char *envcomm);

#endif
