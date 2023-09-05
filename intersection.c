/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:03:33 by anaji             #+#    #+#             */
/*   Updated: 2023/09/01 01:41:56 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "struct.h"
#include <math.h>
#include <stdio.h>

//point_a[2] => a[0] = a_x | a[1] = a_y

t_ray	horizontal_intersection(t_player p, double angle, t_map map)
{
	float	point_a[2];
	float	x_step;
	float	y_step;
	t_ray_p	ray;

	ray.ray_down = check_hangle(angle);
	ray.ray_right = check_vangle(angle);
	ray.angle_tan = tan(angle);
	point_a[1] = floor((double)p.y / TALE_SIZE) * TALE_SIZE;
	if (ray.ray_down)
		point_a[1] += TALE_SIZE;
	point_a[0] = p.x + (point_a[1] - p.y) / ray.angle_tan;
	y_step = TALE_SIZE;
	if (!ray.ray_down)
		y_step *= -1;
	x_step = TALE_SIZE / ray.angle_tan;
	if ((!ray.ray_right && x_step > 0) || (ray.ray_right && x_step < 0))
		x_step *= -1;
	if (!ray.ray_down)
		point_a[1] -= 1.0;
	while (point_a[0] >= 0 && point_a[0] < map.width * TALE_SIZE
		&& point_a[1] >= 0 && point_a[1] < map.height * TALE_SIZE)
		if (check_intersection(point_a, map, x_step, y_step))
			break ;
	return (create_ray(point_a[0], point_a[1], angle, 0));
}

t_ray	vertical_intersection(t_player p, double angle, t_map map)
{
	float	point_a[2];
	float	x_step;
	float	y_step;
	t_ray_p	ray;

	ray.ray_down = check_hangle(angle);
	ray.ray_right = check_vangle(angle);
	ray.angle_tan = tan(angle);
	point_a[0] = floor((double)p.x / TALE_SIZE) * TALE_SIZE;
	if (ray.ray_right)
		point_a[0] += TALE_SIZE;
	point_a[1] = p.y + (point_a[0] - p.x) * ray.angle_tan;
	x_step = TALE_SIZE;
	if (!ray.ray_right)
		x_step *= -1;
	y_step = TALE_SIZE * ray.angle_tan;
	if ((ray.ray_down && y_step < 0) || (!ray.ray_down && y_step > 0))
		y_step *= -1;
	if (ray.ray_right == 0)
		point_a[0] -= 1.0;
	while (point_a[0] >= 0 && point_a[0] < map.width * TALE_SIZE
		&& point_a[1] >= 0 && point_a[1] < map.height * TALE_SIZE)
		if (check_intersection(point_a, map, x_step, y_step))
			break ;
	return (create_ray(point_a[0], point_a[1], angle, 0));
}
