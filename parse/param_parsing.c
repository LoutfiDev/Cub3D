/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:08:37 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/22 09:55:20 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	is_rgb(char *rgb)
{
	int		i;
	int		j;
	int		comma;
	char	**array;

	i = 0;
	comma = 0;
	while (rgb[i])
		if (rgb[i++] == ',')
			comma++;
	array = ft_split(rgb, ',');
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
			if (!ft_isdigit(array[i][j++]) || ft_atoi(array[i]) > 255)
				return (ft_free_array(array, 1));
		i++;
	}
	if (i != 3 || comma > 2)
		return (ft_free_array(array, 1));
	return (ft_free_array(array, 0));
}

int	check_global(char *buff)
{
	char	**array;
	int		i;

	i = 0;
	if (buff[0] != '\0' && buff[ft_strlen(buff) - 1] == '\n')
		buff[ft_strlen(buff) - 1] = 0;
	array = ft_split(buff, ' ');
	if (!array)
		return (ft_free_array(array, 1));
	while (array[i])
		i++;
	if (i != 2)
		return (ft_free_array(array, 1));
	if (ft_strncmp(array[0], "NO", 0) && ft_strncmp(array[0], "SO", 0)
		&& ft_strncmp(array[0], "EA", 0) && ft_strncmp(array[0], "WE", 0)
		&& ft_strncmp(array[0], "F", 0) && ft_strncmp(array[0], "C", 0))
		return (ft_free_array(array, 1));
	else if (ft_strlen(array[0]) == 2 && check_extension(array[1], ".xpm"))
		return (ft_free_array(array, 1));
	else if (ft_strlen(array[0]) == 1 && is_rgb(array[1]))
		return (ft_free_array(array, 1));
	return (ft_free_array(array, 0));
}

int	is_dup(char *buff, t_list *lines)
{
	t_list	*tmp;
	char	*line;
	char	**array;

	array = ft_split(buff, ' ');
	if (!array)
		return (ft_free_array(array, 1));
	tmp = lines;
	while (tmp)
	{
		line = (char *)tmp->content;
		if (!ft_strncmp(array[0], line, ft_strlen(array[0])))
			return (ft_free_array(array, 1));
		tmp = tmp->next;
	}
	return (ft_free_array(array, 0));
}

int	free_param(t_list **lines, char *buff)
{
	ft_lstclear(lines, clear_buff);
	free(buff);
	return (1);
}

int	check_param(int fd, t_data **data)
{
	int		nbr_param;
	char	*buff;
	t_list	*lines;

	nbr_param = 0;
	lines = NULL;
	while (nbr_param < 6)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (!ft_strncmp(buff, "\n", 0))
		{
			free(buff);
			continue ;
		}
		if (check_global(buff) || is_dup(buff, lines))
			return (free_param(&lines, buff));
		ft_lstadd_back(&lines, ft_lstnew(ft_strtrim(buff, "\n")));
		nbr_param++;
	}
	fill_data(data, lines);
	ft_lstclear(&lines, clear_buff);
	return (0);
}
