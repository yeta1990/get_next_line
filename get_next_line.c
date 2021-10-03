#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char				*buff;
	char				*line;
	char				*aux;
	static char			*lft;
	static int			end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
 	if (lft)
	{
		if (ft_c(lft, 10) != -1)
		{
			line = ft_substr(lft, 0, ft_c(lft, 10));
			aux = ft_substr(lft, ft_c(lft, 10), ft_strlen(lft) - ft_c(lft, 10));
			free(lft);
			lft = aux;
			return (line);
		}
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (0);
		while (read(fd, buff, BUFFER_SIZE))
		{
			aux = ft_strjoin(lft, buff);
			free(lft);
			lft = aux;
			if (ft_c(buff, '\n') != -1)
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
			if (ft_strlen(lft))
				return (lft);
			free(lft);
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
			lft = ft_substr(buff, 0, BUFFER_SIZE + 1);
	 		free(buff);
			buff = 0;
			return get_next_line(fd);
		}
		free(buff);
	}
	return 0;
}
