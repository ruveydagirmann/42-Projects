/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:48:01 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:34:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	char	*lasts;
	char	*lastd;

	d = (char *)dest;
	s = (char *)src;
	if (d == s)
		return (0);
	if (d < s)
	{
		while (len--)
		*d++ = *s++;
	}
	else
	{
		lasts = (s + (len - 1));
		lastd = (d + (len - 1));
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dest);
}

// #include <stdio.h>
// int main()
// {	    const char cdizi2[] = "Programlar";
// char cdizi1[] = "Bilgifjkldsafla";
//    ft_memmove(cdizi1, cdizi2, 10);
//     printf("cdizi1 bellek içeriği: %s ,
//  cdizi2 bellek içeriği: %s\n", cdizi1, cdizi2);
//     return 0;
// }