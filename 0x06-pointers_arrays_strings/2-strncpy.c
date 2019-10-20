/*This program copy two strings with n of bytes*/

/**
 * *_strncat - concatenate two  strings with n bytes for the second
 * @dest: pointer to a string
 * @src: pointer to the strign to concatenate
 *
 * Return: dest
 */ 
char *_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
 
    return (dest);
}
