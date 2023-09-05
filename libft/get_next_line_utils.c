/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:56 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/25 02:51:38 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	m_memchr(char *str, int c, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*m_strdup(char *s1)
{
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	ptr = (char *)malloc(ft_len(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*substr(char *str, int start, int len)
{
	char	*substr;
	int		i;

	if (!str)
		return (0);
	if (start + len > ft_len(str))
		len = ft_len(str) - start;
	if (start >= ft_len(str))
		return (NULL);
	i = 0;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (0);
	while (str[i] && i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	int		lenght;
	char	*res;

	if (!s1 || !s1[0])
		return (m_strdup(s2));
	if (!s2 || !s2[0])
		return (NULL);
	lenght = ft_len(s1) + ft_len(s2);
	res = malloc((lenght + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	lenght = 0;
	i = 0;
	len = ft_len(s1);
	while (s1[i] && i < len)
		res[lenght++] = s1[i++];
	len = ft_len(s2);
	i = 0;
	while (s2[i] && i < len)
		res[lenght++] = s2[i++];
	res[lenght] = '\0';
	free(s1);
	return (res);
}
