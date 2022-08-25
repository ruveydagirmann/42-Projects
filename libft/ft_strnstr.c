/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:50:02 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:36:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t	c;

	c = ft_strlen(src);
	if (!*src)
		return ((char *)dest);
	if (!*dest || len <= 0)
		return (0);
	while (len-- >= c && *dest)
	{
		if (*dest == *src && !ft_memcmp(dest, src, c))
			return ((char *)dest);
		++dest;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main( void )
// {
//     const char *cp1 = "bilgisayar";
//     const char *cp2 = "sayar";
//     char *ret = ft_strnstr(cp1, cp2, 10);
// //	printf("%s\n", strnstr(cp1, cp2, 10));
// 	printf("%s\n", ret);
//     return 0; 
// }