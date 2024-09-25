/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:41:54 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/25 23:36:08 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*read_buffer(int fd)
{
	char	*buffer;
	size_t	read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (!read_bytes)
	{
		free(buffer);
		buffer = NULL;
		return (buffer);
	}
	buffer[read_bytes] = '\0';
	return (buffer);
}

char	*get_line(char	*buffer)
{
	size_t	i;

	i = 0;
	while(buffer[i])
	{
		if(buffer[i] == '\n')
			return (buffer + i);
		++i;
	}
	return (NULL);
}

char	*str_dup(char *src, size_t count)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (count + 1));
	i = 0;
	while(src[i] && i < count)
	{
		dest[i] = src[i];
		++i;
	}
	while(i < count + 1)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

char	*str_slice(char *str, size_t start, size_t count)
{
	char	*new_str;

	new_str = str_dup(str + start, count);
	free(str);
	return(new_str);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*tail;
	char			*line;
	size_t			index;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while(1)
	{	
		tail = read_buffer(fd);
		buffer = str_join(buffer, tail);
		if (!*buffer)
			return (NULL);
		line = get_line(buffer);
		if (line)
		{
			index = line - buffer + 1;
			line = str_dup(buffer, index);
			break;
		}
		if (!line && !buffer)
			return (buffer);
	}
	buffer = str_slice(buffer, index,str_len(buffer) - str_len(line));
	return (line);
}




