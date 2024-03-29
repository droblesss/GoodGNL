/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:39:34 by drobles           #+#    #+#             */
/*   Updated: 2022/10/18 16:56:58 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char	*getstatic(int fd, char *box)
{
	char	*buf;
	int		nr_bytes;

	if (!box)
		box = ft_calloc(sizeof(char), BUFFER_SIZE);
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nr_bytes = 1;
	while (!ft_strchr(buf, '\n') && nr_bytes != 0)
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free(buf);
			free(box);
			return (NULL);
		}
		buf[nr_bytes] = '\0';
		box = ft_strjoin(box, buf);
	}
	free (buf);
	return (box);
}

char	*ft_getline(char *box)
{
	char	*linea;
	int		i;

	i = 0;
	linea = NULL;
	if (!box[i])
		return (NULL);
	if (ft_strchr(box, '\n'))
	{
		while (box[i] != '\n')
			i++;
		linea = ft_substr(box, 0, i +1);
		return (linea);
	}
	linea = ft_strdup(box);
	return (linea);
}

char	*cleaner(char *box)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	while (box[i] != '\n' && box[i] != '\0')
		i++;
	if (!box[i])
	{
		free (box);
		return (NULL);
	}
	copy = ft_calloc(sizeof(char), ft_strlen(box) - i + 1);
	if (!copy)
		return (NULL);
	i++;
	while (box[i])
		copy[j++] = box[i++];
	free (box);
	return (copy);
}

char	*get_next_line(int fd)
{
	char		*linea;
	static char	*box;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	box = getstatic(fd, box);
	if (!box)
		return (NULL);
	linea = ft_getline(box);
	box = cleaner(box);
	return (linea);
}
// int main()
// {
// 	int fd;
// 	char *ptr;
// 	fd = open("/Users/drobles/Goodgnl/GoodGNL/el_quijote.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	while (fd) 
// 	{
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	free(ptr);
// 	}
// 	// ptr = get_next_line(fd);
// 	// printf("Output -->%s\n", ptr);
// 	// free(ptr);
// 	close(fd);
// 	return(0);
// }
