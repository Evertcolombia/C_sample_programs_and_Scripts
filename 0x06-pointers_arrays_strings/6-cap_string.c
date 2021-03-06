/**
 * cap_string - capitalice all words in a string
 * @str: string
 * 
 * Return: string
 */
char *cap_string(char *str)
{
    int i = 0;

    while (str[i])
    {
        if ((str[i] == ',') ||(str[i] == ';') ||
		(str[i] == '!') || (str[i] == '.') ||
		(str[i] == '?') || (str[i] == '"') ||
		(str[i] == '(') || (str[i] == ')') ||
        (str[i] == '}') || (str[i] == '{') ||
		(str[i] == '\n') || (str[i] == ' '))
        {
            i++;
            if (str[i] >= 97 && str[i] <= 122)
                str[i] = (str[i] - 32);
            i--;    
        }
        else if (str[i] == '\t')
        {
            i++;
            if (str[i] >= 97 && str[i] <= 122)
                str[i] = (str[i] - 32);
            i--;
            str[i] = (str[i] + 23);
        }
        i++;    
    } return (str);   
}