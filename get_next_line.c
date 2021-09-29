/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:59:57 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/29 17:54:51 by albgarci         ###   ########.fr       */
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

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	if (left)
	{
		i = ft_strchr2(left, '\n') + 1;
		ret = ft_strjoin(left, buff);
	}
	else
	{	
		i = ft_strchr2(buff, '\n') + 1;
		ret = ft_strdup(buff);
	}
	while (!(ft_strchr2(ret, '\n')))
	{
		aux = ft_strdup(ret);
		read(fd, buff, BUFFER_SIZE);
		i = ft_strchr2(buff, '\n') + 1;
	//	printf("->%li<-\n", i);	
		ret = ft_strjoin(aux, ft_substr(buff, 0, i));
	}
	if (i < ft_strlen(buff))
	{	
	//	printf("hol\n");
		free(ret);
		printf("->%li<-\n", i);	
		if (BUFFER_SIZE > i && BUFFER_SIZE > ft_strlen(buff))
		{
			ret = ft_strjoin(aux, ft_substr(buff, 0, i));
			left = ft_substr(buff, i, ft_strlen(buff) - i);
		}
		else
			return (ft_substr(buff, 0, i));					
	//	printf("left: %s\n", left);
	}

/*	else if (i < ft_strlen(left) && left)
	{
		free(ret);
		ret = ft_substr(left, 0, i);
		left = ft_substr(left, i, ft_strlen(left) - i);
	}
*/	return (ret);
}



