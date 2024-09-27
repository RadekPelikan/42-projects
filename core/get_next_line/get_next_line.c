/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:41:54 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/27 15:00:52 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s && *s != '\0')
	{
		++count;
		++s;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src && n)
	{
		*(dest + i++) = *src++;
		--n;
	}
	while (n--)
		*(dest + i++) = '\0';
	return (dest);
}

void	str_append(char **str, char *tail)
{
	char	*new_str;
	size_t	str_len;

	str_len = ft_strlen(*str);
	new_str = malloc(sizeof(char) * (str_len + ft_strlen(tail) + 1));
	ft_strncpy(new_str, *str, str_len);
	ft_strncpy(new_str + str_len, tail, ft_strlen(tail));
	free(*str);
	free(tail);
	tail = NULL;
	*str = new_str;
}

int	str_index_of(char	*str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while(str[i] != c && str[i] != '\0')
		++i;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

void	fill_buffer_until_nl(char **static_buffer, int fd)
{
	int		read_count;
	char	*buffer;

	while (str_index_of(*static_buffer, '\n') == -1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (!read_count)
		{
			free(buffer);
			return ;
		}
		buffer[read_count] = '\0';
		str_append(static_buffer, buffer);
	}
}

char	*get_line(char	*static_buffer)
{
	char	*line;
	int		nl_index;
	
	nl_index = str_index_of(static_buffer, '\n');
	if (nl_index == -1)
		nl_index = ft_strlen(static_buffer);
	line = malloc(sizeof(char) * (nl_index + 1));
	ft_strncpy(line, static_buffer, nl_index);
	return (line);
}

void	buffer_strip_line(char **static_buffer)
{
	char	*new_buffer;
	size_t	new_len;
	int		nl_index;

	nl_index = str_index_of(*static_buffer, '\n');
	if (nl_index == -1)
		nl_index = ft_strlen(*static_buffer);
	new_len = ft_strlen(*static_buffer) - nl_index;
	new_buffer = malloc(sizeof(char) * (new_len + 1));
	ft_strncpy(new_buffer, *static_buffer + nl_index + 1, new_len);
	free(*static_buffer);
	*static_buffer = new_buffer;
}

char	*get_next_line(int fd)
{
	static char		*static_buffer;
	char			*line;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, BUFFER_SIZE) < 0)
		return (NULL);
	if (!static_buffer)
		static_buffer = malloc(sizeof(char) * (ft_strlen(line) + 1));
	else
		str_append(&static_buffer, line);
	ft_strncpy(static_buffer, line, ft_strlen(line));
	free(line);
	fill_buffer_until_nl(&static_buffer, fd);
	line = get_line(static_buffer);
	buffer_strip_line(&static_buffer);
	return (line);
}
