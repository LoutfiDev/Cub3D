/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:36:38 by anaji             #+#    #+#             */
/*   Updated: 2023/09/08 01:02:07 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "parser.h"
# include <stdio.h>

//init

t_mlx			*ft_init(void);

int				key_up(int key, t_mlx *mlx);
int				key_down(int key, t_mlx *mlx);
int				update(t_mlx *mlx);
void			event_handler(void *mlx, void *win);
void			draw_wall(t_draw wall, t_data *img, t_ray ray, t_list *lst);
void			draw_celling(t_data *data, int x, int h, int color);
void			draw_floor(t_data *data, int x, int y, int color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

// ray utils
t_ray			create_ray(int x_hit, int y_hit, double angle, double d);
int				check_hangle(double angle);
int				check_vangle(double angle);
int				check_intersection(float point_a[2], t_map map,
					float x_step, float y_step);
t_ray			horizontal_intersection(t_player p, double angle, t_map map);
t_ray			vertical_intersection(t_player p, double angle, t_map map);
t_ray			get_best_ray(t_player, t_ray h_r, t_ray v_r);

//utils
int				is_wall(float x, float y, t_map map);
t_tex			*get_tex(t_list *lst, char type);
void			player_pos(t_player *p);
float			normalize_ray_angle(float angle);

//image
unsigned int	get_pixel(t_data *data, int x, int y, t_tex *tex);
//render
void			render(t_mlx *mlx);
int				re_render(t_mlx *mlx);
#endif
