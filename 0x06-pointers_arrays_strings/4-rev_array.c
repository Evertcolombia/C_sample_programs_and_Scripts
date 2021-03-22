/**
 * reverse_array - reverse
 * @a: value
 * @n: value
 * Return: none
 */
void reverse_array(int *a, int n)
{
	int curr, *tail, *head = a;

	n -= 1, tail = a + n;
	for (; head < tail; head++)
	{
		curr = (int) *head;
		*head = *tail;
		*tail-- = curr;
	}
}
