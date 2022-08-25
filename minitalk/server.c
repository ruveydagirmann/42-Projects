/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:37:59 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:38:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	binarytochar(int nbr)
{
	static int	i = 7;
	static int	chr = 0;

	chr += nbr << i;
	if (i == 0)
	{
		i = 7;
		write(1, &chr, 1);
		chr = 0;
	}
	else
		i--;
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		binarytochar(1);
	}
	else if (signal == SIGUSR2)
	{
		binarytochar(0);
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_itoa(getpid());
	while (1)
		pause();
}
