/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:39:50 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:39:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"utils.h"

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

int	put_nbr(long double nbr, int is_upper)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count++;
	}
	if (nbr >= 10)
		count += put_nbr(nbr / 10, is_upper);
	write(1, &"0123456789"[(unsigned long)nbr % 10], 1);
	return (count);
}

int	ft_control(char str, va_list variable)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += put_char(va_arg(variable, int));
	else if (str == 's')
		count += put_str(va_arg(variable, char *));
	else if (str == 'd' || str == 'i')
		count += put_nbr(va_arg(variable, int), 0);
	else
		count += put_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	variable;
	int		count;

	va_start(variable, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_control(*(str + 1), variable);
			str++;
		}
		else
			count += put_char(*str);
		str++;
	}
	va_end(variable);
	return (count);
}
