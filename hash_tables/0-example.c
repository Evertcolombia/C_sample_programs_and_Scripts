#include <stdio.h>
#include <stdlib.h>

unsigned int hashpjw(const void *key);

int  main (void)
{
	const char *key = "12345";
	unsigned int val = hashpw(key);
	printf("paso\n");
	return(0);
}

unsigned int hashpjw(const void *key)
{
        const char *ptr = NULL;
        unsigned int val, tmp = 0;

       /*Hash the key by performing a number of bit operations on it*/
        val = 0;
        ptr = key;

        while (*ptr != '\0')
        {
                tmp =  0;
                val = (val << 4) + (*ptr);

                if (tmp = (val & 0xf0000000))
                {
                        val = val ^ (tmp >> 24);
                        val = val ^ tmp;
                }
                ptr++;
        }
        /*in practice replace PRI... with the actual table size */
        return (val % 4650);
}


