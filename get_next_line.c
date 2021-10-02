
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
	unsigned long long	i;

	buff = 0;
	if (!fd)
			return (0);
	if (fd == -1)
		return 0;
	if (left && ft_strchr2(left, '\n') != -1)
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
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); //malloc(sizeof(char) * BUFFER_SIZE);
		if (read(fd, buff, BUFFER_SIZE))
		{
			aux = ft_strjoin(left, buff);
			free(left);
			left = aux;
			free(buff);
			buff = 0;
			return get_next_line(fd);
		}
		else
		{
			if ((ft_strchr2(left, '\n')) != -1)
			{
				line = ft_strdup(left);
				free(left);
				free(buff);
				return (get_next_line(fd));
			}
			i = ft_strchr2(left, '\n') + 1;
			line = ft_substr(left, 0, i);
			aux = ft_substr(left, i, ft_strlen(left) - i);
			free(left);
			if (ft_strlen(aux) == 0)
				return (get_next_line(-1));
			left = aux;
			free(buff);
			buff = 0;
//			return (get_next_line(-1));
			return (line);
		}
	}
	else
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (read(fd, buff, BUFFER_SIZE))
		{
			left = ft_strdup(buff);
	 		free(buff);
			buff = 0;
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
