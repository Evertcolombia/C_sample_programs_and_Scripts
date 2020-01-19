#include "hash_tables.h"

int main(void)
{
	char *s;

	/*s = str to gt a hash*/
	s = "cisfun";
	/*print th hash*/
	printf("%lu\n", hash_djb2(unsigned char *s));
	s = "Dont forget to tweet today";0
	printf("%lu\n", hash_djb2((unsigned char *)s));
	s = "98";
	printf("%lu\n", hash_djb2((unsigned char *)s));

	return (EXIT_SUCCESS);
}
