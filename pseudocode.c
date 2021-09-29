#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*pch;
	int		lstr;

	pch = (char *) s;
	lstr = (ft_strlen(s));
	while (lstr >= 0)
	{
		if (pch[lstr] == (unsigned char) c)
		{
			return (pch + lstr);
		}
		lstr--;
	}
	return (NULL);
}

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	char	*newstring;
//	size_t	i;
//	size_t	j;
//
//	j = 0;
//	i = 0;
//	if (!s1 || !s2)
//		return (NULL);
//	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
//	if (!newstring)
//		return (NULL);
//	while (s1[i] != '\0')
//	{
//		newstring[i] = s1[i];
//		i++;
//	}
//	while (s2[j] != '\0')
//	{
//		newstring[i] = s2[j];
//		j++;
//		i++;
//	}
//	newstring[i] = '\0';
//	return (newstring);
//}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char *returnline = ft_calloc(1, sizeof(char));
	char *temp;
    int bytes_read;
    temp = "";
	// int index;
	// char *append = NULL;
	// index = 0;
    //while(bytes_read > 0) (?)
    while (!ft_strrchr(buf, '\n'))
    {
        if (*buf)
		{
			temp = ft_strjoin(returnline, buf);
			free (returnline);
			returnline = temp;
			ft_bzero(buf, BUFFER_SIZE);
		}
        bytes_read = read(fd, buf, BUFFER_SIZE);
        buf[bytes_read] = '\0';
        if (bytes_read <= 0 && !(*returnline))
        {
            return NULL;
        }
        if (bytes_read < BUFFER_SIZE && !ft_strrchr(buf, '\n'))
			return(buf);
    }
	
    //function to seperate into returnline and leftover;
    return(returnline);
}

int main (void)
{
    int fd;
    fd = open("/Users/qduong/Documents/gnl_test/text1", O_RDONLY);
    char *str;
	str = "";
    while (str)
    {
        str = get_next_line(fd);  
        printf("%s", str);
    }
    close(fd);
    return (0);
}
