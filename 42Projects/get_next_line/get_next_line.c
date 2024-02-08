/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:45:59 by mgering           #+#    #+#             */
/*   Updated: 2024/02/06 17:53:02 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			finished = 0;

	if (0 > fd || 0 >= BUFFER_SIZE)
		return (NULL);
	buffer = read_line(fd, buffer, &finished);
	if (!buffer)
		return (NULL);
	line = cut_line(buffer);
	if (!line || line[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		if (line)
			free(line);
		return (NULL);
	}
	buffer = buffer_left(buffer, ft_strlen(line));
	return (line);
}

char	*read_line(int fd, char *buffer, int *finished)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (0 < bytes_read && !ft_strchr(temp_buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (0 > bytes_read)
		{
			if (buffer)
				free(buffer);
			return (free(temp_buffer), NULL);
		}
		temp_buffer[bytes_read] = '\0';
		if (bytes_read < BUFFER_SIZE)
		{
			*finished = 1;
			if (bytes_read)
				buffer = ft_strjoin(buffer, temp_buffer);
			free(temp_buffer);
			return (buffer);
			
		}
		buffer = ft_strjoin(buffer, temp_buffer);
		if (buffer == NULL)
		{
			free(temp_buffer);
			return(NULL);
		}
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
	while (temp_buf[line_length] != '\0' && temp_buf[line_length] != '\n')
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

/* int main()
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("[%d]-> %s", count++, line);
	}
	close (fd);
	return (0);
} */