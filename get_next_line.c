
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
	if (left && ft_strchr2(left, '\n'))
	{
		i = ft_strchr2(left, '\n') + 1;
		line = ft_substr(left, 0, i);
		aux = ft_substr(left, i, ft_strlen(left) - i);
		free(left);
		left = aux;
		return (line);
	}
	else if (left)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		if (read(fd, buff, BUFFER_SIZE))
		{			
		//	write(1, "holi", 4);
			ft_strjoin(left, buff);
			free(buff);
/*			if (!(ft_strchr2(buff, '\n')))
			{
				write(1, "pepa", 4);
				left = buff;
				return (get_next_line(fd));
			}
*/			return get_next_line(fd);
		}
		else
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
	else
	{
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
