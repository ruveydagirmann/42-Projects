/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:38:13 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:38:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"ft_printf.h"

int	ft_control(char str, va_list variable)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += put_char(va_arg(variable, int));
	else if (str == 's')
		count += put_str(va_arg(variable, char *));
	else if (str == 'd' || str == 'i')
		count += put_nbr(va_arg(variable, int), 10, 0);
	else if (str == 'u')
		count += put_nbr(va_arg(variable, unsigned int), 10, 0);
	else if (str == 'x')
		count += put_nbr(va_arg(variable, unsigned int), 16, 0);
	else if (str == 'X')
		count += put_nbr(va_arg(variable, unsigned int), 16, 1);
	else if (str == 'p')
		count += put_point(va_arg(variable, unsigned long), 16, 0);
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
