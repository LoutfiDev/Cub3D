/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:54:16 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/21 11:30:57 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	check_line(t_list *line)
{
	t_list	*tmp;
	char	*buff;
	int		i;

	tmp = line;
	while (tmp)
	{
		i = 0;
		buff = (char *)tmp->content;
		while (buff && buff[i])
		{
			if (buff[i] != '1' && buff[i] != '0' && buff[i] != ' '
				&& buff[i] != 'N' && buff[i] != 'W' && buff[i] != 'E'
				&& buff[i] != 'S')
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_player(t_list *line)
{
	t_list	*tmp;
	char	*buff;
	int		i;
	int		p;

	tmp = line;
	p = 0;
	while (tmp)
	{
		i = 0;
		buff = (char *)tmp->content;
		while (buff && buff[i])
		{
			if (buff[i] == 'N' || buff[i] == 'W'
				|| buff[i] == 'E' || buff[i] == 'S')
				p++;
			i++;
		}
		tmp = tmp->next;
	}
	if (p > 1)
		return (1);
	return (0);
}

int	dfs_check(t_map *map, int x, int y)
{
	if (map->copy[y][x] == '1' || map->copy[y][x] == '2')
		return (0);
	if (x <= 0 || y <= 0 || x >= map->width || y >= map->height
		|| map->copy[y][x] == ' ')
		return (1);
	if (ft_strchr("NEWS0", map->copy[y][x]))
		map->copy[y][x] = '2';
	if (dfs_check(map, x + 1, y))
		return (1);
	if (dfs_check(map, x - 1, y))
		return (1);
	if (dfs_check(map, x, y + 1))
		return (1);
	if (dfs_check(map, x, y - 1))
		return (1);
	return (0);
}

void	get_player_pos(t_map *map, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	pos->x = -1;
	pos->y = -1;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
				map->map[i][j] == 'W' || map->map[i][j] == 'E')
			{
				pos->x = j;
				pos->y = i;
				pos->angle = map->map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

t_pos	get_pos(t_map *map, char c)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->copy[i][j] == c)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}
