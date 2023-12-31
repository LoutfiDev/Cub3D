/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:28:35 by anaji             #+#    #+#             */
/*   Updated: 2023/09/08 01:32:57 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "struct.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall(t_draw wall, t_data *img, t_ray ray, t_list *lst)
{
	int		x_offset;
	int		y_offset;
	t_tex	*tex;
	int		i;
	float	distortion;

	i = wall.y;
	tex = get_tex(lst, ray.direction);
	x_offset = (int)(ray.x_hit + ray.y_hit) % TALE_SIZE;
	while (i <= wall.wall_hieght + wall.y)
	{
		distortion = i - (HEIGHT - wall.hieght) / 2.0;
		y_offset = distortion * (float)tex->height / wall.hieght;
		my_mlx_pixel_put(img, wall.x, i,
			get_pixel(tex->img, x_offset, y_offset, tex));
		i++;
	}
}

void	draw_celling(t_data *data, int x, int h, int color)
{
	int	j;

	j = 0;
	while (j < h)
	{
		my_mlx_pixel_put(data, x, j, color);
		j++;
	}
}

void	draw_floor(t_data *data, int x, int y, int color)
{
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		my_mlx_pixel_put(data, x, y + j, color);
		j++;
	}
}

unsigned int	get_pixel(t_data *data, int x, int y, t_tex *tex)
{
	char	*dst;

	if (x >= tex->width || y >= tex->height || x < 0 || y < 0)
		return (0);
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}
