#include <stdio.h>
#include "get_next_line.h"
#include <stdio.h>

int main (void)
{
    int fd;
    fd = open("/Users/qduong/Documents/gnl/text1", O_RDONLY);
    while (get_next_line(fd) != NULL)
    {
        printf("%s", get_next_line(fd));
    }
    close(fd);
    return (0);
}