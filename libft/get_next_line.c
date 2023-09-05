/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:58 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/25 02:49:09 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_mbzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_mcalloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	lenght;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	lenght = count * size;
	ptr = malloc(lenght);
	if (ptr == NULL)
		return (0);
	ft_mbzero (ptr, lenght);
	return (ptr);
}

char	*ft_get_line(char *haystack)
{
	char	*line;
	int		i;

	i = 0;
	if (!haystack || !haystack[i])
		return (NULL);
	while (haystack[i] && haystack[i] != '\n')
		i++;
	line = ft_mcalloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (haystack[i] && haystack[i] != '\n')
	{
		line[i] = haystack[i];
		i++;
	}
	if (haystack[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_read(int fd, char *store)
{
	char	*buff;
	int		bytes_read;

	buff = ft_mcalloc((BUFFER_SIZE + 1), 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && !m_memchr(buff, '\n', BUFFER_SIZE))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buff);
			return (NULL);
		}
		if (bytes_read)
		{
			buff[bytes_read] = 0;
			store = strjoin(store, buff);
		}
	}
	free(buff);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	char		*haystack;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	haystack = ft_read(fd, store);
	if (!haystack)
		free(store);
	line = ft_get_line(haystack);
	store = substr(haystack, ft_len(line), ft_len(haystack));
	free(haystack);
	return (line);
}
