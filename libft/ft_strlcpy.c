/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:49:34 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:36:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = (unsigned int)ft_strlen(src);
	if (!dstsize)
		return (counter);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (counter);
}
/*
int main( void )
{
    char cdizi1[] = "ruveyda";
    const char cdizi2[] = "agirman";
	
    printf("%lu\n",  strlcpy(cdizi1, cdizi2, 7));
	printf("%s\n", cdizi1);
	printf("%s", cdizi2);

    return 0;
}
*/
