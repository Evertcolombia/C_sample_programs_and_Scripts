/**
 * reverse_array - reverse
 * @a: value
 * @n: value
 * Return: none
 */
void reverse_array(int *a, int n)
{
    int b[n], i, c = 0;

    for (i = n - 1; i >= 0; i--)
        b[c] = a[i], c++;    
    for (i = 0; i < n; i++)
        a[i] = b[i];
}