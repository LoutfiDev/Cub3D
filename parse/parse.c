/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:25:58 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/21 12:12:06 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	ft_free_array(char **array, int exit)
{
	int	i;

	i = 0;
	if (!array)
		return (exit);
	while (array[i])
		free(array[i++]);
	free(array);
	return (exit);
}

int	print_msg(char *msg, int fd)
{
	write(1, "Error\n", ft_strlen("Error\n"));
	write(1, RED, ft_strlen(RED));
	write(1, msg, ft_strlen(msg));
	write(1, WHITE, ft_strlen(WHITE));
	close(fd);
	return (1);
}

void	clear_buff(void *content)
{
	char	*buff;

	buff = (char *)content;
	free(buff);
}

int	check_extension(char *path, char *extension)
{
	int	i;

	i = 0;
	if (!path)
		return (1);
	while (path[i])
		i++;
	i -= 4;
	path += i;
	if (ft_strncmp(path, extension, 0))
		return (1);
	return (0); 
}

int	parse(int ac, char **av, t_data **data)
{
	int	fd;

	fd = -1;
	if (ac != 2)
		return (print_msg("=> invalide number of argument\n", fd));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (print_msg("=> invalid file\n", fd));
	if (check_extension(av[1], ".cub"))
		return (print_msg("=> invalid extension\n", fd));
	if (check_param(fd, data))
		return (print_msg("=> invalid map parameters\n", fd));
	else if (check_map(fd, data))
		return (print_msg("=> invalid map\n", fd));
	close(fd);
	return (0);
}
