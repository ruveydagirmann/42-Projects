/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:50:20 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:35:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int b, size_t sayi)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < sayi)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		str = (char *)malloc(sizeof(char) * (sayi + 1));
	if (!str)
		return (0);
	while (i < sayi && s[b] && b < ft_strlen(s))
		str[i++] = s[b++];
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	 char *a;
// 	 a = "Ebrar Agirman";
// 	 printf("%s", ft_substr(a, 3, 5));
// 	 return(0);
// }