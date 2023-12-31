#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 * Return: A pointer to the value of the environment variable if found,
 * otherwise NULL.
 */
char *_getenv(const char *name)
{
	int i, len;
	char **env;
	char *value;

	if (!name)
		return (NULL); /* invalid input, name is NULL */

	env = environ;

	for (i = 0; env[i]; i++)
	{
		/* find the length of the variable's name (before '=') */
		for (len = 0; env[i][len] != '='; len++)
			;
		/* compare the variable's name with the provided name */
		if (_strncmp(name, env[i], len) == 0)
		{
			/* return a pointer to the value part of the variable */
			value = &env[i][len + 1];
			return (value);
		}
	}

	return (NULL); /* rariable not found in the environment */
}
