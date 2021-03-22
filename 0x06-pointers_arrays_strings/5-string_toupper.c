/**
 * *string_toupper - string upper
 * @str: string
 * Return: string upper
 */
char *string_toupper(char *str)
{
	char *cp = str;

	while (*cp != '\0')
	{
		if (*cp > 97 && *cp < 123)
			*cp = *cp - 32;
		cp++;
	} return (str);
}
