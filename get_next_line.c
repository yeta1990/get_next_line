
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
 	if (left)
	{
		if (ft_strchr2(left, '\n') != -1)
		{
			i = ft_strchr2(left, '\n') + 1;
			line = ft_substr(left, 0, i);
			aux = ft_substr(left, i, ft_strlen(left) - i);
			free(left);
			left = aux;
			return (line);
		}
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (0);
		while (read(fd, buff, BUFFER_SIZE))
		{
			aux = ft_strjoin(left, buff);
			free(left);
			left = aux;
			if (ft_strchr2(buff, '\n') != -1)
			{
				free(buff);
				return (get_next_line(fd));
			}
			ft_bzero(buff, BUFFER_SIZE + 1);
		}
		free(buff);
		if (!end)
		{
			end = 1;
			if (ft_strlen(left))
				return (left);
			free(left);
		}
		return (0);
	}
	else
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (0);
		if (read(fd, buff, BUFFER_SIZE))
		{
			left = ft_substr(buff, 0, BUFFER_SIZE + 1);
	 		free(buff);
			buff = 0;
			return get_next_line(fd);
		}
		free(buff);
	}
	return 0;
}
