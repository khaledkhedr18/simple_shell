#include "khedira_shell.h"

/**
 * main - an entry point to the app
 * Return: int
 *
*/

int main(void)
{
	char myInput[MAX_ARGINPUT_SIZE];
	int mystatus = 0;

	while (1)
	{
		if (isatty(0))
			khedira_prompt();
		khedira_uinput(myInput, sizeof(myInput), mystatus);
		if (khedira_is_exit(myInput))
		{
			khedira_exit(mystatus);
		}

		else if (khedira_printenv(myInput))
		{
			int i = 0;

			while (environ[i])
			{
				khedira("%s\n", environ[i++]);
			}
		}
		else
		{
			int childstatus = khedira_exec(myInput, mystatus);

			if (childstatus == 0)
				mystatus = 0;
			else if (childstatus == 2)
				mystatus = 2;
			else if (childstatus == 127)
				mystatus = 127;
		}
	}
	return (0);
}
