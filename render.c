/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:20:01 by anaji             #+#    #+#             */
/*   Updated: 2023/09/06 04:41:39 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft/libft.h"
#include "parser.h"
#include "struct.h"
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

t_ray	*get_rays(t_mlx *mlx, double fov, double r_num)
{
	int		i;
	double	angle;
	t_ray	h_r;
	t_ray	v_r;
	t_ray	*rays;

	rays = malloc(NUM_RAYS * sizeof(t_ray));
	angle = mlx->player->angle - (fov / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		h_r = horizontal_intersection(*mlx->player,
				normalize_ray_angle(angle), *mlx->map);
		v_r = vertical_intersection(*mlx->player,
				normalize_ray_angle(angle), *mlx->map);
		rays[i] = get_best_ray(*mlx->player, h_r, v_r);
		angle += (double)fov / r_num;
		i++;
	}
	return (rays);
}

t_draw	fill_wall_data(int x, int y, int hieght, t_draw wall)
{
	wall.x = x;
	wall.y = y;
	if (y < 0)
		y = 0;
	wall.width = 1;
	wall.hieght = hieght;
	wall.wall_hieght = HEIGHT;
	return (wall);
}

t_tex	*get_tex(t_list *lst, char type)
{
	t_tex	*tex;

	while (lst)
	{
		tex = lst -> content;
		if (tex->id[0] == type)
			return (tex);
		lst = lst -> next;
	}
	return (NULL);
}

void	render_game(t_ray *r, t_data *img, float angle, t_mlx *mlx)
{
	int		i;
	float	distance_to_vp;
	float	wall_hieght;

	distance_to_vp = ((WIDTH / 2.0) / tan(FOV / 2.0)) * TALE_SIZE;
	i = 0;
	while (i < NUM_RAYS)
	{
		wall_hieght = distance_to_vp / r[i].distance;
		wall_hieght /= cos(angle - r[i].r_angle);
		mlx->wall = fill_wall_data(i, (HEIGHT - wall_hieght) / 2.0,
				wall_hieght, mlx->wall);
		draw_wall(mlx->wall, &mlx->data, r[i], mlx->texture);
		draw_celling(img, i, (HEIGHT / 2.0) - (wall_hieght / 2), mlx->color.c);
		draw_floor(img, i, (HEIGHT / 2.0) + (wall_hieght / 2), mlx->color.f);
		i++;
	}
}

// void render_map(t_map map, t_data *img)
// {
// 	int i = 0, j;
//
// 	while (i < map.height) {
// 		j = 0;
// 		while (j < map.width) {
// 			if (map.map[i][j] == '1')
// 				draw_rect(img, j * TALE_SIZE * .1, i * TALE_SIZE * .1,
// 						(TALE_SIZE)*.1, (TALE_SIZE)*.1, 0x00FFFFFF);
// 			else
// 				draw_rect(img, j * TALE_SIZE * 0.1, i * TALE_SIZE * 0.1,
// 						(TALE_SIZE)*0.1, (TALE_SIZE)*0.1, 0);
// 			j++;
// 		}
// 		i++;
// 	}
// }
//
// void render_player(t_data *img, t_player p) {
// 	draw_line(img, (p.x + 2) * 0.1, (p.y + 2) * 0.1,
// 			(p.x + 40 * cos(p.angle)) * .1, (p.y + 40 * sin(p.angle)) * .1,
// 			0x0000FF00);
// 	draw_rect(img, p.x * 0.1, p.y * 0.1, TALE_SIZE * .1, TALE_SIZE * .1,
// 			0xFF0000);
// }

void	render(t_mlx *mlx)
{
	t_ray	*rays;

	rays = get_rays(mlx, FOV, (double)NUM_RAYS);
	render_game(rays, &mlx->data, mlx->player->angle, mlx);
	free(rays);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->data.img_ptr, 0, 0);
}
