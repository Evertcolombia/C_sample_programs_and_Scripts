/*this function concatenates two strings
 with out use malloc function to get memory */
#include <stdio.h>

char *str_concat(char *s1, char *s2);
int _strlen(char *str);

/*main function*/
int main (int argc, char *argv[])
{
	char *str;

	if (argc < 3)
	{
		printf("Ingress almost two string\n");
		return (1);
	}

	str = str_concat(argv[1], argv[2]);

	printf("concatenate string: \n %s\n", str);

	return (0);
}

/*functon to concatenate two string*/
char *str_concat(char *s1, char *s2)
{
	int s1_length, s2_length, tmp, i, count = 0;

	s1_length = _strlen(s1);
	s1[s1_length] = " ";
	s2_length = _strlen(s2);
	tmp = (s1_length + s2_length) + 1;

	for (i = s1_length; i <= tmp; i++)
	{
		s1[i] = s2[count];
		count++;
	}
	s1[i] = '\0';

	return (s1);
}

/*functon to get the length of a string*/
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		++i;
	return (i);
}
