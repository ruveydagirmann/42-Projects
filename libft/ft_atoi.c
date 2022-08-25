/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:45:36 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_atoi(const char *str)
{	
	int				i;
	long long int	result;

	result = 0;
	i = 1;
	if (*str == '\0')
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}	
	while (*str >= '0' && *str <= '9')
	{
		result = (10 * result) + (*str - '0') * i;
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		str++;
	}
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
//     char cdizi[40] = "-91";
// 	printf("%d", ft_atoi(cdizi));
//     return 0;	
// }
