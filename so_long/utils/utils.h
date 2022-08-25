/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:40:16 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:40:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

# include	"../mlx/mlx.h"
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdarg.h>

int		ft_word_counter(char const *s, char c);
int		ft_letter_counter(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_read_save(int fd, char *save);
char	*ft_line(char *save);
char	*ft_substr(char const *s, unsigned int b, size_t sayi);
int		ft_printf(const char *str, ...);

#endif
