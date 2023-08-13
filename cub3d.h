/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:16:13 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/13 18:26:50 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
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
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
}	t_data;


// events functions
int		handle_mouse_event(int key, int x, int y, t_data *data);
int		handle_key_event(int key, t_data *data);

// initialize functions
t_img	*init_img(void *mlx_ptr);
t_data	*set_default(char **av, int ac);

//parsing functions
void	parse(int ac, char **av);

//main functions
void	draw(t_data *data);
int		render(t_data *data);
int		destroy_window(t_data *data);

# endif