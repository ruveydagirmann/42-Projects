/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:46:40 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:33:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	number_control(int n)
{
	int		len;
	long	number;

	number = n;
	len = 0;
	if (n == 0)
		len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}	
	while (number > 0)
	{
		len++;
		number = number / 10;
	}
	return (len);
}

void	mywrite(char *str, int n, int len)
{
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = number_control(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	mywrite(str, n, len);
	str[len] = '\0';
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	int t;
// 	t = 0;
// 	printf("%s", ft_itoa(t));
// 	return(0);
// }