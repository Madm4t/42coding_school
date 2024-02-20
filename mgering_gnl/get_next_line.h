/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:46:12 by mgering           #+#    #+#             */
/*   Updated: 2024/02/20 16:19:26 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>		//for open
# include <stdlib.h>	//for malloc
# include <unistd.h>	//for read
# include <stdio.h>		//for printf and FOPEN_MAX

char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer);
char	*cut_line(char *buffer);
char	*buffer_left(char *buffer, size_t line_length);

char	*ft_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t nitems, size_t size);

#endif