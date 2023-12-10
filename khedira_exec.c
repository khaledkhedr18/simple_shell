#include "khedira_shell.h"

/**
 * khedira_exec - a function that executes commands
 * Return: void
 * @exec_comm: the string of the command to be executed
 * @mystatus: the return status of the shell
*/

int khedira_exec(char *exec_comm, int mystatus)
{
	pid_t pid = fork();
	char *command[4];

	command[0] = "/bin/sh";
	command[1] = "-c";
	command[2] = (char *)exec_comm;
	command[3] = NULL;


	if (pid == -1)
	{
		perror("fork");
		exit(mystatus);
	}

	else if (pid == 0)
	{
		execve(command[0], command, environ);
		perror("execve");
		exit(mystatus);
	}
	else
	{
		int childstatus = 0;

		if (wait(&mystatus) == -1)
		{
			perror("wait");
			exit(mystatus);
		}
		childstatus = WEXITSTATUS(mystatus);
		return (childstatus);
	}
}
