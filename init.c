/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:20:57 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/13 18:25:00 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"
# include "./libft/libft.h"

t_img	*init_img(void *mlx_ptr)
{
	t_img	*image;

	image = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!image)
		return (NULL);
	image->img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img_ptr,
			&image->bpp, &image->line_len, &image->endian);
	return (image);
}

t_data	*set_default(char **av, int ac)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	return (data);
}
