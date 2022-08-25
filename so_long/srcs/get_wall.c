/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:57 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:38:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	get_wall_utils(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->ground, x, y);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->clc, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->trunks, x, y);
	else if (c == 'P')
	{
		if (data->curr_pos == 'R')
			mlx_put_image_to_window(data->mlx, data->win, data->playerrh, x, y);
		else if (data->curr_pos == 'L')
			mlx_put_image_to_window(data->mlx, data->win, data->playerlf, x, y);
		else if (data->curr_pos == 'U')
			mlx_put_image_to_window(data->mlx, data->win, data->playerbc, x, y);
		else if (data->curr_pos == 'D')
			mlx_put_image_to_window(data->mlx, data->win, data->playerfr, x, y);
	}
}

int	get_wall(t_data	*data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (data->map[i] != '1')
		i++;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[i])
	{
		get_wall_utils(data, data->map[i], x, y);
		if (data->map[i] == '\n')
		{
			x = -64;
			y += 64;
		}
		i++;
		x += 64;
	}
	return (0);
}
