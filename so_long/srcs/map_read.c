/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:39:15 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:39:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	closewin(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_function(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	checkmappath(char *mappath)
{
	int		len;
	int		i;
	char	*ext;

	ext = "reb.";
	len = ft_strlen(mappath);
	i = 4;
	if (len < 5)
		return (0);
	while (len >= 5 && mappath[len - i])
	{
		if (mappath[len - i] != ext[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	get_file_len(char *mappath)
{
	char	c;
	int		file_len;
	int		fd;

	file_len = 0;
	fd = open(mappath, O_RDONLY);
	while (read(fd, &c, 1))
		file_len++;
	close(fd);
	return (file_len);
}

int	read_map(t_data *data, char *mappath)
{
	int	fd;
	int	i;
	int	file_len;

	fd = open(mappath, O_RDONLY);
	if (fd < 0)
		end_game("dosya acılmadi", data);
	file_len = get_file_len(mappath);
	data->map = malloc(file_len + 1);
	if (!(data->map))
		return (0);
	i = read(fd, data->map, file_len);
	if (i < 0)
		end_game("dosya okunmadı", data);
	data->map[i] = 0;
	data->new_map = ft_split(data->map, '\n');
	close(fd);
	return (0);
}
