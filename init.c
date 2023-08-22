/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:45:36 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/22 10:03:44 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./libft/libft.h"

t_img	*init_img(void *mlx_ptr)
{
	t_img	*image;

	image = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!image)
		return (NULL);
	image->img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (!image->img_ptr)
		return (NULL);
	image->addr = mlx_get_data_addr(image->img_ptr,
			&image->bpp, &image->line_len, &image->endian);
	if (!image->addr)
		return (NULL);
	return (image);
}

t_data	*set_default(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	return (data);
}

int	init_tex(t_data **data)
{
	t_list	*tmp;
	t_tex	*tex;

	tmp = (*data)->texture;
	while (tmp)
	{
		tex = (t_tex *)tmp->content;
		tex->img = (t_img *)ft_calloc(1, sizeof(t_img));
		if (!tex->img)
			return (1);
		tex->img->img_ptr = mlx_xpm_file_to_image((*data)->mlx_ptr, tex->path,
				&tex->width, &tex->height);
		if (!tex->img->img_ptr)
		{
			print_msg("=> invalid texture file\n", -1);
			return (destroy_window(*data));
		}
		tex->img->addr = mlx_get_data_addr(tex->img->img_ptr,
				&tex->img->bpp, &tex->img->line_len, &tex->img->endian);
		if (!tex->img->addr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	init_data(t_data **data)
{
	(*data)->mlx_ptr = mlx_init();
	if (!(*data)->mlx_ptr)
		return (1);
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr,
			WIDTH, HEIGHT, "CUB3D");
	if (!(*data)->win_ptr)
		return (1);
	(*data)->img = init_img((*data)->mlx_ptr);
	if (!(*data)->img)
		return (1);
	if (init_tex(data))
		return (1);
	return (0);
}
