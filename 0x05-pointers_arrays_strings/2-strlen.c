 
/**
 * Write a function that returns the length of a string.
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
    return(i);
}