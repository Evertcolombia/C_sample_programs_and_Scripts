/*Write a function that reverses a string.*/

/**
 * rev_string - reverse a string
 * @s: pointer for a char
 *
 * return  - nothing
 */
void rev_string(char *s)
{
    int i = 0, b = 0, d, c;
    char a[1024];

	while (s[i])
        ++i;
    
    for (c = i - 1; c >= 0; c--)
        a[b] = s[c], b++;
    for (d = 0; d <= i - 1; d++)
        s[d] = a[d];
}
