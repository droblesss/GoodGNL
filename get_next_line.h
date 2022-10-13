/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:36:13 by marvin            #+#    #+#             */
/*   Updated: 2022/10/13 16:17:57 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char 	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif

