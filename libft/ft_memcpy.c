/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:47:55 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:34:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (0);
	while (len--)
		*d++ = *s++;
	return (dest);
}
/*
int main(void)
{
    char cp[] = "bilgisayar&Programlama";
    const char dest[]= "ab";
	
    char cp1[] = "bilgisayar&Programlama";
    const char dest1[] = "ab";


	ft_memcpy(cp1, dest1, 50);
	puts(cp1);	memcpy(cp, dest, 22);

	puts(cp);
}
*/
