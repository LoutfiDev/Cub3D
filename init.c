/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:45:36 by yloutfi           #+#    #+#             */
/*   Updated: 2023/09/05 03:37:20 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft/libft.h"
#include "parser.h"
#include "struct.h"

t_mlx	*ft_init(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->player = ft_calloc(1, sizeof(t_player));
	if (!mlx->player)
		return (NULL);
	mlx->evt = ft_calloc(1, sizeof(t_event));
	if (!mlx->evt)
		return (NULL);
	return (mlx);
}

int	init_tex(t_mlx *mlx)
{
	t_list	*tmp;
	t_tex	*tex;

	tmp = mlx->texture;
	while (tmp)
	{
		tex = (t_tex *)tmp->content;
		tex->img = (t_data *)ft_calloc(1, sizeof(t_data));
		if (!tex->img)
			return (1);
		tex->img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, tex->path,
				&tex->width, &tex->height);
		if (!tex->img->img_ptr)
		{
			print_msg("=> invalid texture file\n", -1);
			destroy_window(mlx);
		}
		tex->img->addr = mlx_get_data_addr(tex->img->img_ptr,
				&tex->img->bpp, &tex->img->line_len, &tex->img->endian);
		if (!tex->img->addr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	init_data(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			WIDTH, HEIGHT, "CUB3D");
	if (!mlx->win_ptr)
		return (1);
	if (init_tex(mlx))
		return (1);
	return (0);
}
