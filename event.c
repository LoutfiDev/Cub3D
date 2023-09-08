/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:41:02 by anaji             #+#    #+#             */
/*   Updated: 2023/09/08 01:41:33 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parser.h"
#include "struct.h"
#include <mlx.h>
#include <stdio.h>
#include <time.h>

int	key_down(int key, t_mlx *mlx)
{
	if (key == 65307)
		destroy_window(mlx);
	if (key == RIGHT_ARROW)
		mlx->evt->is_rotating = 1;
	if (key == LEFT_ARROW)
		mlx->evt->is_rotating = -1;
	if (key == 'w')
		mlx->evt->is_moving = 1;
	if (key == 's')
		mlx->evt->is_moving = -1;
	if (key == 'd')
		mlx->evt->is_side_move = 1;
	if (key == 'a')
		mlx->evt->is_side_move = -1;
	return (0);
}

int	key_up(int key, t_mlx *mlx)
{
	if (key == RIGHT_ARROW)
		mlx->evt->is_rotating = 0;
	if (key == LEFT_ARROW)
		mlx->evt->is_rotating = 0;
	if (key == 'w')
		mlx->evt->is_moving = 0;
	if (key == 's')
		mlx->evt->is_moving = 0;
	if (key == 'd')
		mlx->evt->is_side_move = 0;
	if (key == 'a')
		mlx->evt->is_side_move = 0;
	return (0);
}

int	update_player(t_player *p, float x, float y, t_map map)
{
	if (is_wall(x, p->y, map) == 0 && is_wall(p->x, y, map) == 0)
	{
		p->x = x;
		p->y = y;
		return (1);
	}
	return (0);
}

int	re_render(t_mlx *mlx)
{
	if (mlx->evt->is_moving || mlx->evt->is_rotating || mlx->evt->is_side_move)
		render(mlx);
	return (1);
}

int	update(t_mlx *mlx)
{
	float	new_x;
	float	new_y;
	int		c;

	c = 0;
	new_x = mlx->player->x + mlx->evt->is_moving
		* (cos(mlx->player->angle) * 2);
	new_y = mlx->player->y + mlx->evt->is_moving
		* (sin(mlx->player->angle) * 2);
	if (mlx->evt->is_moving)
		c += update_player(mlx->player, new_x, new_y, *mlx->map);
	new_x = mlx->player->x + mlx->evt->is_side_move * (cos(mlx->player->angle
				+ PI / 2.0) * 1);
	new_y = mlx->player->y + mlx->evt->is_side_move * (sin(mlx->player->angle
				+ PI / 2.0) * 1);
	if (mlx->evt->is_side_move)
		c += update_player(mlx->player, new_x, new_y, *mlx->map);
	mlx->player->angle += mlx->evt->is_rotating * 0.6 * (PI / 180.0);
	mlx->player->angle = normalize_ray_angle(mlx->player->angle);
	if (mlx->evt->is_rotating || c)
		render(mlx);
	return (0);
}
