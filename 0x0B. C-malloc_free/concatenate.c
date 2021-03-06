
/**
 * *str_concat - concatenate two strings
 * @s1 - pointer to a string
 * @s2 - pointer to a string
 *
 * Return: pointer to a string (str)
 */
char *str_concat(char *s1, char *s2)
{
        int i = 0, z = 0, h = 0, count, length, length1, lengthto;
        char *str;

        if (s1 == NULL || s2 == NULL)
                return (NULL);

        while (s1[i])
                i++;
        length = i - 1;

        while (s2[z])
                z++;
        length1 = z;
        lengthto = length + length1;

        str = malloc(sizeof(char) * length);
        if (str == NULL)
                return (NULL);

        for (count = 0; count <= lengthto; count++)
        {
                if (count > length)
                        str[count] = s2[h], h++;
                else
                        str[count] = s1[count];
        }
        return (str);
}
