#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: string
 *
 * Return: nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
	{
		return;
	}
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: character
 *
 * Return: 1 on success
 * -1 on error
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}
	return (1);
}

/**
 * _putfd - writes character to fd
 * @c: character
 * @fd: file descriptor
 *
 * Return: 1 on success
 * -1 on failure
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
