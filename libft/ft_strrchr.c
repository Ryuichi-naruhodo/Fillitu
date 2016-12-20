/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:16:02 by slitim            #+#    #+#             */
/*   Updated: 2016/11/11 23:34:40 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = (char*)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		tmp = (char*)&s[i];
	return (tmp);
}
