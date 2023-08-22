/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:20:57 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/22 08:34:59 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	check_wall(char *buff)
{
	int	i;
	int	wall;

	i = 0;
	wall = 0;
	while (buff && buff[i])
	{
		if (buff[i] == '1')
			wall++;
		i++;
	}
	if (wall < 2)
		return (1);
	return (0);
}

t_tex	*create_texture(char **array)
{
	t_tex	*texture;

	texture = (t_tex *)ft_calloc(1, sizeof(t_tex));
	if (!texture)
		return (NULL);
	texture->id = ft_strdup(array[0]);
	texture->path = ft_strdup(array[1]);
	return (texture);
}

int	convert_rgb(char *rgb)
{
	char	**array;
	int		channel[3];
	int		i;

	array = ft_split(rgb, ',');
	i = -1;
	while (++i < 3)
		array[i] = ft_strtrim(array[i], " ");
	channel[0] = ft_atoi(array[0]);
	channel[1] = ft_atoi(array[1]);
	channel[2] = ft_atoi(array[2]);
	ft_free_array(array, 0);
	return (0 << 24 | channel[0] << 16 | channel[1] << 8 | channel[2]);
}

void	fill_data(t_data **data, t_list *lines)
{
	t_list	*tmp;
	char	*buff;
	char	**array;

	tmp = lines;
	while (tmp)
	{
		buff = (char *)tmp->content;
		array = ft_split(buff, ' ');
		if (ft_strlen(array[0]) == 2)
			ft_lstadd_back(&(*data)->texture, ft_lstnew(create_texture(array)));
		if (!ft_strncmp(array[0], "F", 0))
			(*data)->color.f = convert_rgb(array[1]);
		else if (!ft_strncmp(array[0], "C", 0))
			(*data)->color.c = convert_rgb(array[1]);
		ft_free_array(array, 0);
		tmp = tmp->next;
	}
	return ;
}
