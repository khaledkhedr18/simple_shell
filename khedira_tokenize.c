#include "khedira_shell.h"

#define MAX_ARGINPUT_SIZE 100
#define MAX_ARGUMENTS 10

/**
 * khedira_tokenize - a function that tokenizes strings
 * Return: int
 * @myinp: the input of the string
 * @myargs: the list of the args
*/

int khedira_tokenize(char *myinp, char *myargs[])
{
	int argc = 0;

	char *mytoken = strtok(myinp, " ");

	while (mytoken != NULL && argc < MAX_ARGUMENTS - 1)
	{
		myargs[argc++] = mytoken;
		mytoken = strtok(NULL, " ");
	}

	myargs[argc] = NULL;

	return (argc);
}
