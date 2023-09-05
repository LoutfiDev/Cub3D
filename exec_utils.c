/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:24:08 by anaji             #+#    #+#             */
/*   Updated: 2023/09/02 23:35:32 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "struct.h"
#include <math.h>

void	player_pos(t_player *p)
{
	p->x *= TALE_SIZE;
	p->y *= TALE_SIZE;
}

float	get_player_angle(char c)
{
	if (c == 'W')
		return (PI);
	if (c == 'E')
		return (0);
	if (c == 'N')
		return (3.0 * PI / 2.0);
	if (c == 'S')
		return (PI / 2.0);
	return (0);
}

int	is_wall(float x, float y, t_map map)
{
	float	grid_x;
	float	grid_y;

	grid_x = y / TALE_SIZE;
	grid_y = x / TALE_SIZE;
	if (grid_x >= map.height || grid_x < 0
		|| grid_y >= map.width || grid_y < 0)
		return (1);
	if (map.map[(int)grid_x][(int)grid_y] == '1')
		return (1);
	return (0);
}

t_ray	get_best_ray(t_player p, t_ray h_r, t_ray v_r)
{
	float	v_dis;
	float	h_dis;

	v_dis = sqrtf(powf(v_r.x_hit - p.x, 2) + powf(v_r.y_hit - p.y, 2));
	h_dis = sqrtf(powf(h_r.x_hit - p.x, 2) + powf(h_r.y_hit - p.y, 2));
	if (v_dis < h_dis)
	{
		v_r.distance = v_dis;
		v_r.id = 'v';
		if (v_r.r_angle <= PI / 2.0 || v_r.r_angle >= 3.0 * PI / 2.0)
			v_r.direction = 'E';
		else
			v_r.direction = 'W';
		return (v_r);
	}
	h_r.id = 'h';
	h_r.distance = h_dis;
	if (h_r.r_angle >= 0 && h_r.r_angle <= PI)
		h_r.direction = 'S';
	else
		h_r.direction = 'N';
	return (h_r);
}

float	normalize_ray_angle(float angle)
{
	float	res_angle;

	res_angle = fmod(angle, (float)2 * PI);
	if (res_angle < 0)
		res_angle += 2 * PI;
	return (res_angle);
}
