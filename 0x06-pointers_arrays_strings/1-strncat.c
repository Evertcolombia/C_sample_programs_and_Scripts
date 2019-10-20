/*This program concatenae two strings*/

/**
 * _strlen - show the lenght of a string
 * @s: pointe to  pass the array
 *
 * Return: none
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i])
        ++i;
    return (i);
}

/**
 * *_strncat - concatenate two  strings with n bytes for the second
 * @dest: pointer to a string
 * @src: pointer to the strign to concatenate
 *
 * Return: dest
 */ 
char *_strncat(char *dest, char *src, int n)
{
    int i = 0,  a;

    a = _strlen(dest);

    for (; i < n && src[i] != '\0'; i++)
        dest[a + i] = src[i];
    dest[a + i] = '\0';
 
    return (dest);
}
