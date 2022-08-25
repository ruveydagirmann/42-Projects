/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:48:40 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:35:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char) c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

// #include	<stdio.h>

// int main( void )
// {
//     const char cdizi[] = "Bilgisayar";
//     char *ret;

//     ret = ft_strchr(cdizi, '\0');

//     printf("Bulunan karakterden itibaren dizi içeriği: %s\n", ret);

//     return 0;
// }