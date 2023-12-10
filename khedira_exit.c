#include "khedira_shell.h"

/**
* khedira_is_exit - a function that exits the shell
* Return: Void
* @excomm: the exit keyword
*/

int khedira_is_exit(char *excomm)
{
	return (strcmp(excomm, "exit") == 0);
}

/**
 * khedira_exit - a function that exits the shell
 * Return: void
 * @status: the status return value
*/

void khedira_exit(int status)
{
	exit(status);
}
