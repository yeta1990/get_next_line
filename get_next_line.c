/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:59:57 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/28 20:35:42 by albgarci         ###   ########.fr       */
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
//	ret = NULL;
	ret = ft_strdup(buff);
	read(fd, buff, BUFFER_SIZE);

//	while (!(ft_memchr(ret, '\n', BUFFER_SIZE * i)))
	while (!(ft_memchr(buff, '\n', BUFFER_SIZE)))
	{
/*		if (i == 0)
		{
			ret = ft_strdup(buff);
			read(fd, buff, BUFFER_SIZE);
		}
		else
		{*/
			aux = ft_strdup(ret);
		//	free(ret);
			read(fd, buff, BUFFER_SIZE);
			ret = ft_strjoin(aux, buff);
	/*	}
		i++;*/
	}
	return (ret);
}

