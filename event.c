/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:41:02 by anaji             #+#    #+#             */
/*   Updated: 2023/09/05 02:53:39 by anaji            ###   ########.fr       */
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
	update(*mlx->evt, mlx);
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

void	update_player(float *x, float *y, float old_x, float old_y)
{
	*x = old_x;
	*y = old_y;
}

int	re_render(t_mlx *mlx)
{
	if (mlx->evt->is_moving || mlx->evt->is_rotating || mlx->evt->is_side_move)
		render(mlx);
	return (1);
}

void	update(t_event evt, t_mlx *mlx)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = mlx->player->x + evt.is_moving * (cos(mlx->player->angle) * 20);
	tmp_y = mlx->player->y + evt.is_moving * (sin(mlx->player->angle) * 20);
	if (is_wall(tmp_x, tmp_y, *mlx->map) == 0 && evt.is_moving)
		update_player(&mlx->player->x, &mlx->player->y, tmp_x, tmp_y);
	tmp_x = mlx->player->x + evt.is_side_move * (cos(mlx->player->angle
				+ PI / 2.0) * 20);
	tmp_y = mlx->player->y + evt.is_side_move * (sin(mlx->player->angle
				+ PI / 2.0) * 20);
	if (is_wall(tmp_x, tmp_y, *mlx->map) == 0 && evt.is_side_move)
		update_player(&mlx->player->x, &mlx->player->y, tmp_x, tmp_y);
	mlx->player->angle += evt.is_rotating * 5.0 * (PI / 180.0);
	mlx->player->angle = normalize_ray_angle(mlx->player->angle);
	if (evt.is_moving || evt.is_rotating || evt.is_side_move)
		render(mlx);
}
