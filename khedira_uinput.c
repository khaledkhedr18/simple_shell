#include "khedira_shell.h"

/**
 * khedira_uinput - a function that recieves input from the user
 * Return: Void
 * @comm: the string of the command
 * @size: the size of the command
 * @mystatus: the status return value
*/

void khedira_uinput(char *comm, size_t size, int mystatus)
{
	if (fgets(comm, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			exit(mystatus);
		}

		else
		{
			exit(mystatus);
		}
	}
	comm[strcspn(comm, "\n")] = '\0';

}
