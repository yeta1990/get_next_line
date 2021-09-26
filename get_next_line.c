/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:59:57 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/26 02:20:01 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buff;
//	char	b;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
//	char beff[1024];

	//	read(fd, &buff, 5);
//	buff[5] = '\0';
	while (read(fd, &buff, 150))//BUFFER_SIZE - 1 ))
	{
		printf("%s\n\n", buff);
		//printf("holi");
		//free(buff);
		//buff = malloc(sizeof(char) * 5);
	}
	return (buff);
}
