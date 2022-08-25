/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:39:04 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:39:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	game_window(t_data *data)
{
	data->rows = 0;
	while (data->new_map[data->rows])
	{
		data->rows++;
	}
	data->curr_pos = 'D';
	data->cols = ft_strlen(data->new_map[0]);
	data->win = mlx_new_window(data->mlx, 64 * (data->cols), \
	64 * (data->rows), "so_long");
	if (!data->win)
		end_game("MLX couldn't create a new window.", data);
	return (0);
}

void	free_function(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
		free(data->map);
	if (data->new_map)
	{
		while (data->new_map[i])
		{
			free(data->new_map[i]);
			i++;
		}
		free(data->new_map);
	}
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->clc);
	mlx_destroy_image(data->mlx, data->trunks);
	mlx_destroy_image(data->mlx, data->playerfr);
	mlx_destroy_image(data->mlx, data->playerbc);
	mlx_destroy_image(data->mlx, data->playerlf);
	mlx_destroy_image(data->mlx, data->playerrh);
	free(data);
}

int	end_game(char *error_message, t_data *data)
{
	free_function(data);
	if (error_message)
	{
		ft_printf("Error\n%s\n", error_message);
		exit(EXIT_FAILURE);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	image_path(t_data *data)
{
	data->ground = mlx_xpm_file_to_image(data->mlx, "./image/ground.xpm", \
	&data->weight, &data->height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./image/wall.xpm", \
	&data->weight, &data->height);
	data->clc = mlx_xpm_file_to_image(data->mlx, "./image/collectable.xpm", \
	&data->weight, &data->height);
	data->trunks = mlx_xpm_file_to_image(data->mlx, "./image/trunks.xpm", \
	&data->weight, &data->height);
	data->playerfr = mlx_xpm_file_to_image(data->mlx, "./image/playerfr.xpm", \
	&data->weight, &data->height);
	data->playerbc = mlx_xpm_file_to_image(data->mlx, "./image/playerback.xpm", \
	&data->weight, &data->height);
	data->playerlf = mlx_xpm_file_to_image(data->mlx, "./image/playerlf.xpm", \
	&data->weight, &data->height);
	data->playerrh = mlx_xpm_file_to_image(data->mlx, "./image/playerrh.xpm", \
	&data->weight, &data->height);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 2 && checkmappath(av[1]))
	{
		data->mlx = mlx_init();
		data->map = NULL;
		data->new_map = NULL;
		image_path(data);
		read_map(data, av[1]);
		game_window(data);
		check_map_value(data);
		check_map(data);
		get_wall(data);
		setup_event_hooks(data);
		mlx_loop(data->mlx);
	}
	else
	{
		free(data);
		ft_printf("argüman sayısı veya dosya ismi hatalı");
		exit(EXIT_FAILURE);
	}
}
