/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:16:13 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/31 04:39:46 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

//Define some colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define WHITE "\033[1;00m"

// functions i added
float		get_player_angle(char c);
// initialize functions
int			init_data(t_mlx *data);

//parsing functions
int			parse(int ac, char **av, t_mlx **data);
int			check_map(int fd, t_mlx **data);
int			check_param(int fd, t_mlx **data);

//parse_utils functions
void		clear_buff(void *content);
int			ft_free_array(char **array, int exit);
void		fill_data(t_mlx **data, t_list *lines);
int			check_extension(char *path, char *extension);
t_player	get_pos(t_map *map, char c);
void		get_player_pos(t_map *map, t_player *pos);
int			dfs_check(t_map *map, int x, int y);
int			check_player(t_list *line);
int			check_line(t_list *line);
int			global_free(t_mlx *data, int exit_code);
int			print_msg(char *msg, int fd);
int			check_wall(char *buff);

//main functions
int			destroy_window(t_mlx *data);

#endif
