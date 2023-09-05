/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:15:04 by yloutfi           #+#    #+#             */
/*   Updated: 2023/09/05 03:19:05 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parser.h"
#include <mlx.h>

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

int	global_free(t_mlx *mlx, int exit_code)
{
	if (mlx && mlx->texture)
		ft_lstclear(&mlx->texture, clear_tex);
	if (mlx && mlx->map)
	{
		ft_free_array(mlx->map->map, 0);
		ft_free_array(mlx->map->copy, 0);
		free(mlx->map);
	}
	if (mlx && mlx->player)
		free(mlx->player);
	if (mlx && mlx -> evt)
		free(mlx->evt);
	if (mlx)
		free(mlx);
	return (exit_code);
}
