/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:39:09 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:39:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	check_2(t_data *data, int x, int y)
{
	while (data->new_map[x][y])
	{
		if (x == 0 && data->new_map[0][y] != '1')
			end_game("ilk sıra hatalı", data);
		else if (!ft_strchr("01CPE", data->new_map[x][y]))
			end_game("Haritada geçersiz karakter.", data);
		else if (data->new_map[x][y] == 'C')
			data->collectable_count++;
		else if (data->new_map[x][y] == 'E')
			data->exit_count++;
		else if (data->new_map[x][y] == 'P')
		{
			data->player_x = x;
			data->player_y = y;
			data->player_count++;
		}
		y++;
	}
}

void	check_map_value(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->collectable_count = 0;
	data->exit_count = 0;
	data->player_count = 0;
	while (data->new_map[x])
	{
		y = 0;
		check_2(data, x, y);
		x++;
	}
	y = 0;
	while (data->new_map[data->rows - 1][y])
	{
		if (data->new_map[data->rows - 1][y] != '1')
			end_game("son sıra hatalı", data);
		y++;
	}
}

void	check_line(t_data *data)
{	
	int		i;
	size_t	cols;

	i = 1;
	cols = ft_strlen(data->new_map[0]);
	while (data->new_map[i])
	{		
		if (cols != ft_strlen(data->new_map[i]))
			end_game("satır hizası hatası", data);
		i++;
	}
}

void	check_map(t_data *data)
{
	int	j;

	j = 0;
	if (data->collectable_count < 1 || data->player_count != 1 || \
	data->exit_count < 1)
		end_game("karakter sayısı hatalı", data);
	while (data->map[j] != '1')
		j++;
	while (data->map[j])
	{	
		if (data->map[j] == '\n')
		{
			if (data->map[j - 1] != '1')
				end_game("satır sonu hatası", data);
			else if (data->map[j + 1] != '1')
				end_game("satır başı hatası", data);
		}
		j++;
	}
	check_line(data);
}

void	playerindex(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == 'P')
			data->playerindex = i;
		i++;
	}
}
