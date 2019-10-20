/**
 * *string_toupper - string upper
 * @str: string
 * Return: string upper
 */
char *string_toupper(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] > 97 && str[i] < 123)
            str[i] = str[i] - 32;
        i++;
    }return (str);
}