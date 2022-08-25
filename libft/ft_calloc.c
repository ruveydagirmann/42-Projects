/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:46:03 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:33:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*str;

	str = malloc (size * len);
	if (!str)
		return (NULL);
	ft_bzero (str, size * len);
	return (str);
}
/*
int main(void)
{
    int *ip, id;

    ip = (int *) ft_calloc(10, sizeof(int));

    for (id=0; id<10; id++) {
         *(ip+id) = (id+1) * 5;
         printf("%p adresindeki değer: %d\n", (ip+id), *(ip+id));
    }
    free(ip);
}
*/
