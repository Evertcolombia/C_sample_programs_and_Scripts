/**
 * *_strncat - concatenate two  strings with n bytes for the second
 * @dest: pointer to a string
 * @src: pointer to the strign to concatenate
 *
 * Return: dest
 */ 
char *_strncat(char *dest, char *src, int n)
{
	int i;
	char *head = dest;

	for (; *dest != '\0'; dest++)
		;

   	for (i = 0; i < n && *src != '\0'; i++)
        	*dest++ = *src++;
	dest = '\0', dest= head;
    return (dest);
}
