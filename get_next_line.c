/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:59:57 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/29 14:27:17 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	int		i;
	char	*ret;
	char	*aux;

	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	ret = ft_strdup(buff);
	
	if (!ft_memchr(ret, '\n', BUFFER_SIZE))
		return (ret);
	while (!(ft_memchr(ret, '\n', BUFFER_SIZE * i)))
	{
			aux = ft_strdup(ret);
			read(fd, buff, BUFFER_SIZE);
			ret = ft_strjoin(aux, buff);
		i++;
	}
	return (ret);
}

