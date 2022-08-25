/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:48:07 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:34:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)str + i) = c;
		i++;
	}
	return (str);
}
/*
int main( void )
{
    char cdizi[] = "Bilgisayar";

    printf("cdizi bellek içeriği: %s\n", cdizi);

   ft_memset(cdizi, 'x', 5);

    printf("cdizi bellek içeriği: %s", cdizi);

    return 0;
}
*/
