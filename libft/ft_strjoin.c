/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:49:03 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:35:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	total_len;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
		*str++ = *s2++;
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (str - total_len);
}

// #include <stdio.h>
// int main() 
// {
// 	const char buffer[] = {'e', 'f'};
// 	const char *result;
// 	char s2[] = {'-'};
// 	result = ft_strjoin(buffer, s2);
// 	printf("%s", result);
// 	return 0;
// }
