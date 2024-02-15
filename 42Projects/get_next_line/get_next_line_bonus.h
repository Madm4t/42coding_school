/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:11:49 by mgering           #+#    #+#             */
/*   Updated: 2024/02/15 13:29:19 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>		//for open
# include <stdlib.h>	//for malloc
# include <unistd.h>	//for read
# include <stdio.h>		//for printf and FOPEN_MAX

char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer);
char	*cut_line(char *temp_buf);
char	*buffer_left(char *temp_buffer, size_t line_length);

char	*ft_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t nitems, size_t size);

#endif