
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
	static int end;
	unsigned long long	i;

	buff = 0;
	if (!fd)
			return (0);
	if (fd == -1)
		return 0;
 	if (left)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		while (read(fd, buff, BUFFER_SIZE))
		{
			aux = ft_strjoin(left, buff);
			free(left);
			left = aux;
			if (ft_strchr2(buff, '\n') != -1)
			{
				i = ft_strchr2(left, '\n') + 1;
				line = ft_substr(left, 0, i);
				aux = ft_substr(left, i, ft_strlen(left) - i);
				free(left);
				left = aux;
				free(buff);
				return (line);
			}
		}
		free(buff);
		if (!end)
		{
			end = 1;
			return (left);
		}
		return (0);
	}
	else
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (read(fd, buff, BUFFER_SIZE))
		{
			left = ft_substr(buff, 0, BUFFER_SIZE + 1);
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
