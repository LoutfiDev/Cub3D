/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:08:56 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/13 15:25:00 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"
 
int	destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
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

	parse(ac, av);
	data = set_default(av, ac);
	if (!data)
		return (MLX_ERROR);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIDTH, HEIGHT, "CUB3D");
	if (!data->win_ptr)
		return (MLX_ERROR);
	data->img = init_img(data->mlx_ptr);
	if (!data->img)
		return (MLX_ERROR);
	mlx_hook(data->win_ptr, 17, 0, destroy_window, data);
	mlx_hook(data->win_ptr, 2, 0, handle_key_event, data);
	mlx_hook(data->win_ptr, 4, 0, handle_mouse_event, data);
	render(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}