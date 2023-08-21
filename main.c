/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:08:56 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/21 13:00:20 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	exit(0);
	return (0);
}

int	render(t_data *data)
{
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->img_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = set_default();
	if (!data || parse(ac, av, &data) || init_data(&data))
		return (global_free(data, 1));
	mlx_hook(data->win_ptr, 17, 1, destroy_window, data);
	mlx_hook(data->win_ptr, 2, (1L << 0), handle_key_event, data);
	mlx_hook(data->win_ptr, 6, (1L << 6), handle_mouse_event, data);
	render(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
