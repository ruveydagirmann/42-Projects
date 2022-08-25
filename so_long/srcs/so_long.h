/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:39:38 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:39:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include	"../mlx/mlx.h"
# include	"../utils/utils.h"
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<stdarg.h>
# include	<unistd.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**new_map;
	char	*map;
	void	*ground;
	void	*wall;
	void	*clc;
	void	*trunks;
	void	*playerfr;
	void	*playerlf;
	void	*playerrh;
	void	*playerbc;
	char	curr_pos;
	int		player_x;
	int		player_y;
	int		playerindex;
	int		exit_count;
	int		player_count;
	int		collectable_count;
	int		move_count;
	int		cols;
	int		rows;
	int		weight;
	int		height;
}			t_data;

int		key_hook(int keycode, t_data *data);
int		ft_word_counter(char const *s, char c);
int		ft_letter_counter(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_read_save(int fd, char *save);
char	*ft_line(char *save);
int		read_map(t_data *data, char *mappath);
void	check_map_value(t_data *data);
void	check_map(t_data *data);
void	setup_event_hooks(t_data *data);
int		get_wall(t_data	*data);
void	playerindex(t_data *data);
void	free_function(t_data *data);
int		end_game(char *error_message, t_data *data);
int		checkmappath(char *mappath);
int		closewin(t_data *data);

enum {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	EXPOSE = 12,
	DESTROY = 17
};

#endif