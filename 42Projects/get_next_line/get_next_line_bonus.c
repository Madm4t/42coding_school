/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:06:04 by mgering           #+#    #+#             */
/*   Updated: 2024/02/15 13:20:46 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (0 > fd || 0 >= BUFFER_SIZE || 0 == FOPEN_MAX)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = cut_line(buffer[fd]);
	if (!line || '\0' == line[0])
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		if (line)
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
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	while (0 < bytes_read && !ft_strchr(temp_buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (0 > bytes_read)
			return (free(temp_buffer), free(buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = gnl_strjoin(buffer, temp_buffer);
		if (!buffer)
			return (free(temp_buffer), NULL);
	}
	if (temp_buffer)
		free(temp_buffer);
	return (buffer);
}

char	*cut_line(char *buffer)
{
	char	*line;
	size_t	line_length;
	size_t	i;

	if (!buffer)
		return (NULL);
	line_length = 0;
	i = 0;
	while (buffer[line_length] && '\n' != buffer[line_length])
		line_length++;
	if ('\n' == buffer[line_length])
		line_length++;
	line = ft_calloc((line_length + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (i < line_length)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*buffer_left(char *buffer, size_t line_length)
{
	char	*temp;
	size_t	temp_length;
	size_t	i;

	if (!buffer)
		return (NULL);
	temp_length = ft_strlen(buffer);
	i = 0;
	if ((temp_length - line_length) < 1)
		return (free(buffer), NULL);
	temp = ft_calloc((temp_length - line_length + 1), sizeof(char));
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	while ('\0' != buffer[line_length])
	{
		temp[i] = buffer[line_length];
		i++;
		line_length++;
	}
	temp[i] = '\0';
	free(buffer);
	return (temp);
}