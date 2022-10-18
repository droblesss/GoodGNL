/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:36:13 by marvin            #+#    #+#             */
/*   Updated: 2022/10/17 17:05:51 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);
int		ft_strlen(const char	*str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char	*s, int c);
char	*ft_strjoin(char	*s1, char	*s2);

#endif