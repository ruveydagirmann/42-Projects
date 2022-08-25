/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:48:47 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:35:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp2;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + 1;
	cp2 = (char *)malloc(sizeof(char) * len);
	if (!cp2)
		return (0);
	while (s1[i])
	{
		cp2[i] = s1[i];
		i++;
	}
	cp2[i] = '\0';
	return (cp2);
}

// #include <stdio.h>
// int		main(void)
// {
// 	char	*str;
// 	char	*a;

// 	str = "bilgisayar";
// 	a  = ft_strdup(str);
// 	printf("%s",a);
// }