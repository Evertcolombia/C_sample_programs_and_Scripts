/**
 * swap_int - change values of two int between themself
 * @a: int
 * @b: int
 *
 * Return: None
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *b, *b = *a, *a = c;
}
