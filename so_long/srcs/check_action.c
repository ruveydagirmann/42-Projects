/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:51 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:38:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	check_action(t_data *data, int x)
{
	if (data->map[x] != '1')
	{
		if (data->map[x] == 'C')
		{
			data->collectable_count--;
			data->map[x] = '0';
		}
		if (data->map[x] == 'E' && data->collectable_count < 1)
		{
			ft_printf("Moves: %d\nYou won!\n", ++(data->move_count));
			end_game(0, data);
		}
		if (data->map[x] == 'E')
		{
			return (0);
		}
		ft_printf("Moves: %d\n", ++(data->move_count));
		return (1);
	}
	return (0);
}

void	updown(int keycode, t_data *data)
{
	if (keycode == W)
	{
		if (check_action(data, ((data->playerindex) - (data->cols + 1))))
		{
			data->map[data->playerindex] = '0';
			data->playerindex -= (data->cols + 1);
			data->map[data->playerindex] = 'P';
			data->curr_pos = 'U';
		}
		get_wall (data);
	}
	if (keycode == S)
	{
		if (check_action(data, ((data->playerindex) + (data->cols + 1))))
		{
			data->map[data->playerindex] = '0';
			data->playerindex += (data->cols + 1);
			data->map[data->playerindex] = 'P';
			data->curr_pos = 'D';
		}
		get_wall(data);
	}
}

void	rightleft(int keycode, t_data *data)
{
	if (keycode == A)
	{
		if (check_action(data, ((data->playerindex) - 1)))
		{
			data->map[data->playerindex] = '0';
			data->playerindex -= 1;
			data->map[data->playerindex] = 'P';
			data->curr_pos = 'L';
		}
		get_wall(data);
	}
	if (keycode == D)
	{
		if (check_action(data, ((data->playerindex) + 1)))
		{
			data->map[data->playerindex] = '0';
			data->playerindex += 1;
			data->map[data->playerindex] = 'P';
			data->curr_pos = 'R';
		}
		get_wall(data);
	}
}

int	key_hook(int keycode, t_data *data)
{
	playerindex(data);
	if (keycode == ESC)
		closewin(data);
	if (keycode == A || keycode == D)
		rightleft(keycode, data);
	if (keycode == W || keycode == S)
		updown(keycode, data);
	return (0);
}

void	setup_event_hooks(t_data *data)
{
	mlx_hook(data->win, 2, (1L << 0), key_hook, data);
	mlx_hook(data->win, 17, (1L << 2), closewin, data);
}
