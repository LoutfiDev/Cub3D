/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:16:13 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/21 12:49:02 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "/nfs/homes/yloutfi/minilibx-linux/mlx.h"
# include <math.h>

//Globab macros
# define WIDTH 960
# define HEIGHT 900
# define MLX_ERROR 1

//Define some colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define WHITE "\033[1;00m"

typedef struct s_img
{
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}	t_img;

typedef struct s_tex
{
	char	*path;
	char	*id;
	int		width;
	int		height;
	t_img	*img;
}	t_tex;

typedef struct s_color
{
	int	f;
	int	c;
}	t_color;

typedef struct s_pos
{
	char	angle;
	float	x;
	float	y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_list		*texture;
	t_map		*map;
	t_pos		pos;
	t_color		color;
}	t_data;

// events functions
int		handle_mouse_event(int x, int y, t_data *data);
int		handle_key_event(int key, t_data *data);

// initialize functions
t_img	*init_img(void *mlx_ptr);
t_data	*set_default(void);
int		init_data(t_data **data);

//parsing functions
int		parse(int ac, char **av, t_data **data);
int		check_map(int fd, t_data **data);
int		check_param(int fd, t_data **data);

//parse_utils functions
void	clear_buff(void *content);
int		ft_free_array(char **array, int exit);
void	fill_data(t_data **data, t_list *lines);
int		check_extension(char *path, char *extension);
t_pos	get_pos(t_map *map, char c);
void	get_player_pos(t_map *map, t_pos *pos);
int		dfs_check(t_map *map, int x, int y);
int		check_player(t_list *line);
int		check_line(t_list *line);
int		global_free(t_data *data, int exit_code);
int		print_msg(char *msg, int fd);

//main functions
void	draw(t_data *data);
int		render(t_data *data);
int		destroy_window(t_data *data);

#endif