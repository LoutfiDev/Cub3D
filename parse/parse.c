/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:25:58 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/13 21:28:42 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void	print_msg(char *msg)
{
	write(1, "Error\n", ft_strlen("Error\n"));
	write(1, RED, ft_strlen(RED));
	write(1, msg, ft_strlen(msg));
	write(1, WHITE, ft_strlen(WHITE));
	exit(0);
	return ;
}
int check_extension(char *path)
{
    int i;

    i = 0;
    while (path[i])
        i++;
    i -= 4;
    path += i;
    if (ft_strncmp(path, ".cub", 0))
        return (1);
    return (0); 
}

int check_param(char *path)
{
    int     nbr_param;
    int     i;
    char    *line;
    char    **array;
    int x=0;
    int y=0;
    int     fd;
    void *mlx_ptr = mlx_init();
    
    fd = open(path, O_RDONLY);
  	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
        if (!ft_strncmp(line, "\n", 0))
            continue ;
        array = ft_split(line, ' ');
        i = 0;
        while (array[i])
            i++;
        printf("%s\t%s\n", array[0], array[1]);
        // || ft_strncmp(array[0], "NO", 0) || ft_strncmp(array[0], "SO", 0)
        //     || ft_strncmp(array[0], "WE", 0) || ft_strncmp(array[0], "EA", 0)
        //     || ft_strncmp(array[0], "F", 0) || ft_strncmp(array[0], "C", 0)
        if (i > 1)
            break;
        // if (!ft_strncmp(array[0], "NO", 0) || !ft_strncmp(array[0], "SO", 0) ||
        //     !ft_strncmp(array[0], "WE", 0) || !ft_strncmp(array[0], "EA", 0))
        // {
        //     if (!mlx_xpm_file_to_image(mlx_ptr, array[1], &x, &y))
        //         break ;
        // }
        nbr_param++;
	}
	close(fd);
	free(line);
    if (nbr_param != 6)
        return (1);
    return (0);
}
void	parse(int ac, char **av)
{
	if (ac != 2)
		print_msg("=> invalide number of argument\n");
    else if (check_extension(av[1]))
		print_msg("=> invalid extension\n");
    else if (check_param(av[1]))
		print_msg("=> invalid map parameters\n");
    // else if (check_map(av[1]))
	// 	print_msg("=> invalid map\n");
	return ;
}