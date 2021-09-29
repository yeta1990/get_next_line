/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:59:57 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/29 16:19:03 by albgarci         ###   ########.fr       */
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

	i = 0;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	if (left)
		ret = ft_strjoin(left, buff);
	else
		ret = ft_strdup(buff);
	while (!(ft_strchr2(ret, '\n')))
	{
		aux = ft_strdup(ret);
		read(fd, buff, BUFFER_SIZE);
		i = ft_strchr2(buff, '\n') + 1;
//		printf("->%li<-\n", i);	
		ret = ft_strjoin(aux, ft_substr(buff, 0, i));
	}
	if (i < ft_strlen(buff))
		left = ft_substr(buff, i, ft_strlen(buff) - i);
	return (ret);
}



