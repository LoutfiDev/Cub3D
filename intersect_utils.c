/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:35:11 by anaji             #+#    #+#             */
/*   Updated: 2023/09/01 01:42:19 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "struct.h"

t_ray	create_ray(int x_hit, int y_hit, double angle, double d)
{
	t_ray	ray;

	ray.x_hit = x_hit;
	ray.y_hit = y_hit;
	ray.distance = d;
	ray.r_angle = angle;
	return (ray);
}

int	check_hangle(double angle)
{
	return (angle > 0 && angle < PI);
}

int	check_vangle(double angle)
{
	return (angle < PI / 2 || angle > 3 * PI / 2);
}

int	check_intersection(float point_a[2], t_map map, float x_step, float y_step)
{
	if (is_wall(point_a[0], point_a[1], map))
		return (1);
	point_a[0] += x_step;
	point_a[1] += y_step;
	return (0);
}
