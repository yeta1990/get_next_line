/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorozco- <rorozco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:44:52 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/15 15:54:52 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				main()
{
	int			fd;
	char		*str;
	int			i;

	i = 0;
	fd = open("lotr.txt", O_RDONLY);
/* 	get_next_line(fd, &str);
	printf("%s", str); */
	while ((str = get_next_line(fd)))
	{
		printf("line %i=>%s\n", i + 1, str);
		free(str);
		i++;
	}
	// printf("%s\n", str);
	// system("leaks a.out");
	return (0);
}
