#include "khedira_shell.h"
/**
 * khedira_char - a function that prints characters
 * Return: int
 * @myChar: the character to be printed
*/

int	khedira_char(int myChar)
{
	return (write(1, &myChar, 1));
}

/**
 * khedira_digit - a function that prints digits
 * Return: int
 * @x: a variable
 * @myBase: the base
*/

int	khedira_digit(long x, int myBase)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (x < 0)
	{
		write(1, "-", 1);
		return (khedira_digit(-x, myBase) + 1);
	}
	else if (x < myBase)
	{
		return (khedira_char(symbols[x]));
	}
	else
	{
		count = khedira_digit(x / myBase, myBase);
		return (count + khedira_digit(x % myBase, myBase));
	}
}

/**
 * khedira_str - a function that prints strings
 * Return: an int
 * @myString: the string to be printed
*/

int	khedira_str(char *myString)
{
	int	count;

	count = 0;
	while (*myString)
		count += write(1, myString++, 1);
	return (count);
}

/**
 * khedira_format - a function that specifies the format of the string
 * Return: an int
 * @khediraspec: the specifier
 * @khediraap: the list of the specifiers
*/

int	khedira_format(char khediraspec, va_list khediraap)
{
	int	myCount;

	myCount = 0;
	if (khediraspec == 'c')
		myCount = khedira_char(va_arg(khediraap, int));
	else if (khediraspec == 's')
		myCount = khedira_str(va_arg(khediraap, char *));
	else if (khediraspec == 'd')
		myCount = khedira_digit((long)va_arg(khediraap, int), 10);
	else if (khediraspec == 'x')
		myCount = khedira_digit((long)va_arg(khediraap, unsigned int), 16);
	else
		myCount += write(1, &khediraspec, 1);
	return (myCount);
}

/**
 * khedira - a function that prints an input
 * Return: int
 * @myFormat: the format of the string to be printed
*/
int	khedira(const char *myFormat, ...)
{
	va_list	khedira_ap;
	int		count;

	va_start(khedira_ap, myFormat);
	count = 0;
	while (*myFormat)
	{
		if (*myFormat == '%')
			count += khedira_format(*++myFormat, khedira_ap);
		else
			count += write(STDOUT_FILENO, myFormat, 1);
		++myFormat;
	}
	va_end(khedira_ap);
	return (count);
}
