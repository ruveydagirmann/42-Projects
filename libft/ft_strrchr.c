/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:50:08 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:36:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		idx;

	idx = ft_strlen((char *)str) + 1;
	while (idx--)
	{
		if (*(str + idx) == (unsigned char)c)
			return ((char *)(str + idx));
	}
	return (0);
}

// #include <stdio.h>
// int main( void )
// {
//     char cdizi[] = "Bilgisayar";
//     char cd = 's';
//     char *ret;

//     ret = ft_strrchr(cdizi, cd);
//     printf("Bulunan son %c karakterinden 
//		itibaren dizi içeriği: %c", cd, *ret);
//     return 0;
// }