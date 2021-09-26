/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:59:57 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/27 00:55:51 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buff;
	buff = malloc(sizeof(char) * BUFFER_SIZE);

	read(fd, buff, BUFFER_SIZE);
	/*while (read(fd, buff, BUFFER_SIZE))
	{
		printf("%s", buff);
		//printf("holi");
		//free(buff);
		//buff = malloc(sizeof(char) * 5);
	}*/
	return (buff);
}
