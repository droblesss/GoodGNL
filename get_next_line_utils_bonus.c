/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:10:26 by drobles           #+#    #+#             */
/*   Updated: 2022/10/18 16:49:00 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//	system("leaks a.out");

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	size_t			j;
	unsigned int	slen;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen)
		len = slen;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (j < len)
	{
		sub[j] = s[start];
			j++;
			start++;
	}
	sub[j] = '\0';
	return (sub);
}

int	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

char	*ft_strdup(const char	*s1)
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = ft_calloc (sizeof(char) * ft_strlen(s1) + 1, 1);
	if (aux == NULL)
		return (NULL);
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*con;
	size_t	i;
	size_t	z;

	if (!s1)
		return (NULL);
	i = 0;
	z = 0;
	con = ft_calloc(sizeof(char), ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!con || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		con[i] = s1[i];
		i++;
	}
	while (s2[z])
	{
		con[i + z] = s2[z];
		z++;
	}
	free(s1);
	return (con);
}
