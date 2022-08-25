/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:07 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:38:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"ft_printf.h"

int	put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	put_nbr(long double nbr, int base, int is_upper)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count++;
	}
	if (nbr >= base)
		count += put_nbr(((unsigned long)nbr / base), base, is_upper);
	if (is_upper)
		write(1, &UPPER_BASE[(unsigned long)nbr % base], 1);
	else
		write(1, &LOWER_BASE[(unsigned long)nbr % base], 1);
	return (count);
}

int	put_point(long double nbr, int base, int is_upper)
{
	int	count;

	count = 0;
	count += put_str("0x");
	count += put_nbr(nbr, base, is_upper);
	return (count);
}
