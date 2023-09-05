/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:57:01 by anaji             #+#    #+#             */
/*   Updated: 2023/09/05 03:00:08 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <math.h>
# include <mlx.h>

# define WIDTH 900
# define HEIGHT 800
# define MLX_ERROR 1

# define PI 3.141593

# define FOV 1.0472
# define NUM_RAYS WIDTH

# define TALE_SIZE 64

# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

typedef struct s_ray_p 
{
	int		ray_down;
	int		ray_right;
	double	angle_tan;
}			t_ray_p;

typedef struct s_draw
{
	unsigned int	*n_tex;
	unsigned int	*s_tex;
	unsigned int	*w_tex;
	unsigned int	*e_tex;
	int				x;
	int				y;
	int				width;
	int				hieght;
	int				wall_hieght;
}		t_draw;

// typedef struct s_player
// {
// 	int		x;
// 	int		y;
// 	double	angle;
// }			t_player;

typedef struct s_ray
{
	char		id;
	int			x_hit;
	int			y_hit;
	double		r_angle;
	float		distance;
	char		direction;
}				t_ray;

typedef struct s_event
{
	int	is_moving;
	int	is_side_move;
	int	is_rotating;
}		t_event;

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_tex
{
	char	*path;
	char	*id;
	int		width;
	int		height;
	t_data	*img;
}	t_tex;

typedef struct s_color
{
	int	f;
	int	c;
}	t_color;

typedef struct s_player
{
	float	angle;
	float	x;
	float	y;
}	t_player;

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		width;
	int		height;
}	t_map;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		data;
	t_list		*texture;
	t_map		*map;
	t_player	*player;
	t_color		color;
	t_event		*evt;
	t_draw		wall;
}				t_mlx;
#endif 
