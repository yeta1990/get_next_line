/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:30:47 by albgarci          #+#    #+#             */
/*   Updated: 2021/10/02 19:00:33 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_c(const char *s, int c)
{
	size_t	i;
	char	*s2;

	i = 0;
	c = (char) c;
	s2 = (char *)s;
	while (s2[i])
	{
		if (s2[i] == c)
			return (i + 1);
		i++;
	}
	if (s2[i] == c)
		return (i + 1);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	ft_memmove(s3, (char *)s1, ft_strlen(s1));
	ft_memmove(s3 + ft_strlen(s1), (char *)s2, ft_strlen(s2));
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*s2;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (s2 = ft_calloc(sizeof(char), 1));
	if (len >= ft_strlen(s))
		size = ft_strlen(s) - start + 1;
	else
		size = len + 1;
	s2 = malloc(sizeof(char) * size);
	if (!s2)
		return (0);
	s2 = ft_memmove(s2, (s + start), size);
	s2[size - 1] = '\0';
	return (s2);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	s = (char *) src;
	d = (char *) dst;
	i = 0;
	if (!s && !d && len > 0)
		return (dst);
	if (d > s)
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
		return (dst);
	}
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(size * count);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
