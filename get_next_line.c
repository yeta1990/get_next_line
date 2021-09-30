/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:59:57 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/30 16:22:04 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	size_t		i;
	char	*ret;
	char	*aux;
	static char *left;

	aux = 0;	
	buff = 0;
	if (left && ft_strchr2(left, '\n'))
	{
		i = ft_strchr2(left, '\n') + 1;
		ret = ft_strdup(left);
	}
	else if (left)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		read(fd, buff, BUFFER_SIZE);
		ret = ft_strjoin(left, buff);
	}
	else
	{	
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		read(fd, buff, BUFFER_SIZE);
		i = ft_strchr2(buff, '\n') + 1;
		ret = ft_strdup(buff);
	}
/*	while (!(ft_strchr2(ret, '\n')) || !(ft_strchr2(ret, EOF)))
	{
		aux = ft_strdup(ret);
		read(fd, buff, BUFFER_SIZE);
		i = ft_strchr2(buff, '\n') + 1;
		ret = ft_strjoin(aux, ft_substr(buff, 0, i));

	}
*/	i = ft_strchr2(ret, '\n') + 1;
	if (ret && i < ft_strlen(ret) && BUFFER_SIZE > i)
	{
		aux = ft_strdup(ret);
		free(ret);
		ret = ft_substr(aux, 0, i);
		left = ft_substr(aux, i, BUFFER_SIZE - i);
//		free(buff);
	}
	else
	{
		i = ft_strchr2(buff, '\n') + 1;
		left = ft_substr(buff, i - 1, BUFFER_SIZE + 1);
//		free(buff);
	}
//	printf("left: %s\n", left);
	if (left && !ft_strlen(left))
		free(left);
	free(aux);
	return (ret);
}

