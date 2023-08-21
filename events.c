/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:15:28 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/21 10:56:55 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse_event(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	render(data);
	return (0);
}

int	handle_key_event(int key, t_data *data)
{
	if (key == 65307)
		destroy_window(data);
	render(data);
	return (0);
}
