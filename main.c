/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:08:56 by yloutfi           #+#    #+#             */
/*   Updated: 2023/09/05 03:23:32 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parser.h"
#include "struct.h"
#include <mlx.h>
#include <stdlib.h>

int	destroy_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = ft_init();
	if (!mlx)
		return (0);
	if (parse(ac, av, &mlx) || init_data(mlx))
		return (global_free(mlx, 1));
	player_pos(mlx->player);
	mlx->data.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img_ptr, &mlx->data.bpp,
			&mlx->data.line_len, &mlx->data.endian);
	render(mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_down, mlx);
	mlx_hook(mlx->win_ptr, 3, 1L << 1, key_up, mlx);
	mlx_hook(mlx->win_ptr, 17, 1, destroy_window, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
