/**
 * _strlen - show the lenght of a string
 * @s: pointe to  pass the array
 *
 * Return: none
 */
int _strlen(char *s)
{
	int len = 0;

	for (len = 0; *s != '\0'; s++)
		len++;

	return (len);
}
