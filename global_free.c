/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:15:04 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/21 13:00:35 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void	clear_tex(void *content)
{
	t_tex	*tex;

	tex = (t_tex *)content;
	if (tex && tex->id)
		free(tex->id);
	if (tex && tex->path)
		free(tex->path);
	if (tex && tex->img)
		free(tex->img);
	if (tex)
		free(tex);
}

int	global_free(t_data *data, int exit_code)
{
	if (data && data->mlx_ptr)
		free(data->mlx_ptr);
	if (data && data->win_ptr)
		free(data->win_ptr);
	if (data && data->img)
		free(data->img);
	if (data && data->texture)
		ft_lstclear(&data->texture, clear_tex);
	if (data && data->map)
	{
		ft_free_array(data->map->map, 0);
		ft_free_array(data->map->copy, 0);
		free(data->map);
	}
	if (data)
		free(data);
	return (exit_code);
}
