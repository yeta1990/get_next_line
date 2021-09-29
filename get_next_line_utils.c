/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:30:47 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/29 15:35:46 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(ft_strlen(s1) + 1);
	if (!s)
		return (0);
	if (s1 == s && s1 == 0)
		return (s);
	while (i < ft_strlen(s1) + 1)
	{
		*(unsigned char *)(s + i) = *(unsigned char *)(s1 + i);
		i++;
	}
	return (s);
}

size_t	ft_strchr2(const char *s, int c)
{
	size_t	i;
	char	*s2;

	i = 0;
	c = (char) c;
	s2 = (char *)s;
	while (s2[i])
	{
		if (s2[i] == c)
			return (i);
		i++;
	}
	if (s2[i] == c)
		return (i);
	return (0);
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	src = (char *) src;
	if (src == dst && src == 0 && n > 0)
		return (dst);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*s2;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (s2 = ft_strdup(""));
	if (len >= ft_strlen(s))
		size = ft_strlen(s) - start + 1;
	else
		size = len + 1;
	s2 = malloc(sizeof(char) * size);
	if (!s2)
		return (0);
	s2 = ft_memcpy(s2, (s + start), size);
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
