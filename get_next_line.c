/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:28:00 by albgarci          #+#    #+#             */
/*   Updated: 2021/10/14 15:42:44 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char			*lft;

	if (fd < 0 || read(fd, lft, 0) == -1 || BUFFER_SIZE <= 0)
		return (0);
	return (ft_read_loop(fd, &lft));
}

char	*ft_create_line(char **lft)
{
	char	*line;
	char	*aux;

	if (ft_c(*lft, 10))
	{
		line = ft_substr(*lft, 0, ft_c(*lft, 10));
		aux = ft_substr(*lft, ft_c(*lft, 10), ft_strlen(*lft) - ft_c(*lft, 10));
	}
	else
		return (*lft);
	if (*lft)
		free(*lft);
	*lft = aux;
	return (line);
}


char *ft_read_loop(int fd, char **lft)
{
	char	*aux;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*lft))
		*lft = malloc(1);
	if (!buff)
		return (0);
	ft_bzero(buff, BUFFER_SIZE + 1);
	while (read(fd, buff, BUFFER_SIZE))
	{
		aux = ft_strjoin(*lft, buff);
		free(*lft);
		*lft = aux;
		if (ft_c(buff, '\n') != -1)
		{
			free(buff);
			return (ft_create_line(lft));
		}
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	if (*lft && ft_strlen(*lft))
	{
		free(buff);
		return (ft_create_line(lft));
	}
	free(buff);
	if (*lft)
		free(*lft);
	return (0);
}

int	ft_c(const char *s, int c)
{
	size_t	i;
	char	*s2;

	i = 0;
	c = (char) c;
	s2 = (char *)s;
	if (!s)
		return (-1);
	while (s2[i])
	{
		if (s2[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}
