#include "khedira_shell.h"

/**
 * khedira_printenv - a function that prints the environment variable
 * Return: Void
 * @envcomm: the command to print env
*/

int khedira_printenv(char *envcomm)
{
	return (strcmp(envcomm, "env") == 0);
}
