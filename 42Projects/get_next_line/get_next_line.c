/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:53:30 by mgering           #+#    #+#             */
/*   Updated: 2024/03/12 15:31:39 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (0 > fd || 0 >= BUFFER_SIZE)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = cut_line(buffer);
	if (!line || line[0] == '\0')
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		if (line)
			free(line);
		return (NULL);
	}
	buffer = buffer_left(buffer, ft_strlen(line));
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
		buffer = ft_strjoin(buffer, temp_buffer);
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
	if (buffer[line_length] == '\n')
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
	while (buffer[line_length] != '\0')
	{
		temp[i] = buffer[line_length];
		i++;
		line_length++;
	}
	temp[i] = '\0';
	free(buffer);
	return (temp);
}

