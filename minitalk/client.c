/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:37:30 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:37:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	chartobinary(unsigned char c, int pid)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c / i)
		{
			c -= i;
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		i /= 2;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (*str)
		{
			chartobinary(*str, pid);
			str++;
		}
		if (*argv[2])
			chartobinary('\n', pid);
	}
}
