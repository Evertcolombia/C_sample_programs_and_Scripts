#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "holberton.h"

int create_file(const char *filename, char *text_content)
{
        /*init fd and counter*/
        int fd, len;
        
        /*get the length of the content*/
        len = _strlen(text_content);

        /*test the pointer file*/
        if (filename == NULL)
                return (-1);
        /*create a file  specifing permisions and flags*/
        fd = open(filename, O_CREAT | O_WRONLY | O_APPEND |O_TRUNC, 0600);
        if (fd == -1)
            return(-1);

        /*if text_content == null*/
        if (text_content == NULL)
        {
            /*return -1 if the  content is not same as length */
            if (write(fd, text_content, len) != len)
                return(-1);
        }

        close(fd);
        return (1);
}
