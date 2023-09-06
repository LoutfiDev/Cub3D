/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:41:02 by anaji             #+#    #+#             */
/*   Updated: 2023/09/06 04:27:12 by anaji            ###   ########.fr       */
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
		exit(0);
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

void	update_player(t_player *p, float x, float y, t_map map)
{
	if (is_wall(x, p->y, map) == 0 && is_wall(p->x, y, map) == 0)
	{
		p->x = x;
		p->y = y;
	}
}

int	re_render(t_mlx *mlx)
{
	if (mlx->evt->is_moving || mlx->evt->is_rotating || mlx->evt->is_side_move)
		render(mlx);
	return (1);
}

void	update(t_event evt, t_mlx *mlx)
{
	float	new_x;
	float	new_y;

	new_x = mlx->player->x + evt.is_moving * (cos(mlx->player->angle) * 3);
	new_y = mlx->player->y + evt.is_moving * (sin(mlx->player->angle) * 3);
	if (evt.is_moving)
		update_player(mlx->player, new_x, new_y, *mlx->map);
	new_x = mlx->player->x + evt.is_side_move * (cos(mlx->player->angle
				+ PI / 2.0) * 3);
	new_y = mlx->player->y + evt.is_side_move * (sin(mlx->player->angle
				+ PI / 2.0) * 3);
	if (is_wall(new_x, new_y, *mlx->map) == 0 && evt.is_side_move)
		update_player(mlx->player, new_x, new_y, *mlx->map);
	mlx->player->angle += evt.is_rotating * 1 * (PI / 180.0);
	mlx->player->angle = normalize_ray_angle(mlx->player->angle);
	if (evt.is_moving || evt.is_rotating || evt.is_side_move)
		render(mlx);
}
