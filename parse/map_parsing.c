/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:10:36 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/21 11:25:10 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	get_length(t_list *lines)
{
	int		len;
	t_list	*tmp;
	char	*buff;

	tmp = lines;
	len = 0;
	while (tmp)
	{
		buff = (char *)tmp->content;
		if (ft_strlen(buff) > len)
			len = ft_strlen(buff);
		tmp = tmp->next;
	}
	return (len);
}

char	**set_map(int columns, int rows)
{
	char	**map;
	int		i;

	map = ft_calloc(columns + 1, sizeof(char *));
	i = 0;
	while (i < columns)
		map[i++] = ft_calloc(rows + 1, sizeof(char));
	return (map);
}

t_map	*fill_map(t_list *lines)
{
	t_map	*map;
	t_list	*tmp;
	char	*buff;
	int		len;
	int		i;

	tmp = lines;
	map = ft_calloc(1, sizeof(t_map));
	len = get_length(lines);
	map->map = set_map(ft_lstsize(lines), len);
	map->copy = set_map(ft_lstsize(lines), len);
	i = 0;
	while (tmp)
	{
		buff = (char *)tmp->content;
		ft_memset(map->map[i], ' ', len);
		ft_memcpy(map->map[i], buff, ft_strlen(buff));
		ft_memset(map->copy[i], ' ', len);
		ft_memcpy(map->copy[i], buff, ft_strlen(buff));
		i++;
		tmp = tmp->next;
	}
	map->width = ft_strlen(map->map[0]);
	map->height = ft_lstsize(lines);
	return (map);
}

t_list	*fill_lines(int fd)
{
	t_list	*line;
	int		k;
	char	*buff;

	line = NULL;
	k = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (!ft_strncmp(buff, "\n", 0) && !k)
		{
			free(buff);
			continue ;
		}
		k++;
		ft_lstadd_back(&line, ft_lstnew(ft_strtrim(buff, "\n")));
	}
	return (line);
}

int	check_map(int fd, t_data **data)
{
	t_list	*lines;

	lines = fill_lines(fd);
	if (!lines || check_line(lines) || check_player(lines))
	{
		ft_lstclear(&lines, clear_buff);
		return (1);
	}
	(*data)->map = fill_map(lines);
	ft_lstclear(&lines, clear_buff);
	get_player_pos((*data)->map, &(*data)->pos);
	if (dfs_check((*data)->map, (*data)->pos.x, (*data)->pos.y))
		return (1);
	if (dfs_check((*data)->map, get_pos((*data)->map, '0').x, 
			get_pos((*data)->map, '0').y))
		return (1);
	return (0);
}
