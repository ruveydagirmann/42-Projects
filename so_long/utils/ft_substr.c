/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:40:11 by marvin            #+#    #+#             */
/*   Updated: 2022/08/25 12:40:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"utils.h"

char	*ft_substr(char const *s, unsigned int b, size_t sayi)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if (len <= sayi)
		sayi = len;
	str = malloc(sizeof(char) * (sayi + 1));
	if (!str)
		return (0);
	while (i < sayi && s[b + i] && b < len)
	{
		str[i] = s[b + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
