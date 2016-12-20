/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:37:07 by slitim            #+#    #+#             */
/*   Updated: 2016/11/14 14:29:41 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (*little == '\0')
		return ((char*)big);
	if (*big == '\0')
		return (NULL);
	while (*big)
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
