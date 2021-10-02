
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	char		*aux;
	static char	*left;
	size_t		i;
		
	buff = 0;
/*	if (fd > 2)
		return 0;
*/	if (left && ft_strchr2(left, '\n') != -1)
	{
//		printf("j");

		i = ft_strchr2(left, '\n') + 1;

		line = ft_substr(left, 0, i);
		aux = ft_substr(left, i, ft_strlen(left) - i);
		free(left);
		left = aux;
		return (line);
	}
	else if (left)
	{
/*		buff = malloc(sizeof(char) * BUFFER_SIZE);
		while (read(fd, buff, BUFFER_SIZE))
		{
			printf("\nleft: %s<-", left);
			printf("\nbuff: %s<-", buff);
			aux = ft_strjoin(left, buff);
			printf("\naux: %s<-\n", aux);
			free(left);
		//	printf("k");
			left = aux;
			if (ft_strchr2(buff, '\n') != -1)
			{
				break ;
			}
			free(buff);
		}
		return (get_next_line(fd));*/

//printf("i");
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		if (read(fd, buff, BUFFER_SIZE))
		{
//			printf("\nleft: %s<-", left);
//			printf("\nbuff: %s<-", buff);
			aux = ft_strjoin(left, buff);
			
//			printf("\naux: %s<-", aux);
			free(left);
			left = aux;
	//		buff[BUFFER_SIZE] = '\0';
			free(buff);
			return get_next_line(fd);
		}
		else
		{
			if ((ft_strchr2(left, '\n')) != -1)
			{
				line = ft_strdup(left);
				free(left);
				free(buff);
				return (line);
			}
			i = ft_strchr2(left, '\n') + 1;
			line = ft_substr(left, 0, i);
			aux = ft_substr(left, i, ft_strlen(left) - i);
			free(left);
			left = aux;
			free(buff);
			return (line);
		}
	}
	else
	{
//		printf("h");

		buff = malloc(sizeof(char) * BUFFER_SIZE);
		if (read(fd, buff, BUFFER_SIZE))
		{
			left = ft_strdup(buff);
	 		free(buff);
			return get_next_line(fd);
		}
		else
		{
			free(buff);
			return 0;
		}
	}
	return 0;
}
