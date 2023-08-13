/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:15:28 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/13 15:17:32 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


int	handle_mouse_event(int key, int x, int y, t_data *data)
{
	render(data);
	return (0);
}

int	handle_key_event(int key, t_data *data)
{
	if (key == 53)
		destroy_window(data);
	render(data);
	return (0);
}

