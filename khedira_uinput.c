#include "khedira_shell.h"

/**
 * khedira_uinput - a function that recieves input from the user
 * Return: Void
 * @comm: the string of the command
 * @size: the size of the command
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
			khedira("Error while reading the input.\n");
			exit(EXIT_FAILURE);
		}
	}
	comm[strcspn(comm, "\n")] = '\0';

}
