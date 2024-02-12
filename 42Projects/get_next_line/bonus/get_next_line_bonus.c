/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:30:48 by mgering           #+#    #+#             */
/*   Updated: 2024/01/30 15:56:10 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (0 > fd || 0 >= BUFFER_SIZE)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = cut_line(buffer[fd]);
	if (line[0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		free(line);
		return (NULL);
	}
	buffer[fd] = buffer_left(buffer[fd], ft_strlen(line));
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (NULL);
	while (0 < bytes_read && !ft_strchr(temp_buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (0 > bytes_read)
			return (free(temp_buffer), free(buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
	}
	return (free(temp_buffer), buffer);
}

char	*cut_line(char *temp_buf)
{
	char	*line;
	size_t	line_length;
	size_t	i;

	line_length = 0;
	i = 0;
	if (!temp_buf)
		return (NULL);
	while ('\0' != temp_buf[line_length] && '\n' != temp_buf[line_length])
		line_length++;
	if (temp_buf[line_length] == '\n')
		line_length++;
	line = ft_calloc((line_length + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (i < line_length)
	{
		line[i] = temp_buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*buffer_left(char *temp_buffer, size_t line_length)
{
	char	*temp;
	size_t	temp_length;
	size_t	i;

	if (!temp_buffer)
		return (NULL);
	temp_length = ft_strlen(temp_buffer);
	i = 0;
	temp = ft_calloc((temp_length - line_length + 1), sizeof(char));
	if (!temp)
		return (NULL);
	while (temp_buffer[line_length] != '\0')
	{
		temp[i] = temp_buffer[line_length];
		i++;
		line_length++;
	}
	temp[i] = '\0';
	return (free(temp_buffer), temp);
}
