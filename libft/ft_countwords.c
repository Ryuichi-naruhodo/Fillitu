/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:17:18 by slitim            #+#    #+#             */
/*   Updated: 2016/11/21 12:17:34 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char *str, char c)
{
	int		change;
	int		i;

	change = 0;
	i = 0;
	while (*str)
	{
		if (change == 0 && *str != c)
		{
			i++;
			change = 1;
		}
		else if (change == 1 && *str == c)
			change = 0;
		str++;
	}
	return (i);
}
