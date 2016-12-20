/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:25:38 by slitim            #+#    #+#             */
/*   Updated: 2016/11/21 21:04:09 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;
	int		n;

	if (*little == '\0')
		return ((char *)big);
	str1 = (char *)big;
	str2 = (char *)little;
	n = ft_strlen(str2);
	i = 0;
	while (str1[i] != '\0' && (i + n) <= len)
	{
		if (ft_strncmp(big + i, little, n) == 0)
			return (str1 + i);
		i++;
	}
	return (NULL);
}
