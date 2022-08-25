/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:37:18 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:37:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include	"get_next_line.h"

char	*ft_queue(char *save)
{
	char	*queue;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	queue = malloc(sizeof(char) * ft_strlen(save) - i + 1);
	if (!queue)
		return (0);
	i++;
	while (save[i])
		queue[c++] = save[i++];
	queue[c] = 0;
	free(save);
	return (queue);
}

char	*ft_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof (char) * i + 2);
	if (!line)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[read_bytes] = 0;
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_queue(save);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
// 	int fd;
// 	fd = open("deneme", O_RDONLY, 0777);
// 	printf("%d\n", fd);
// 	//printf ("%s\n", get_next_line(fd));
// 	return(0);
// }