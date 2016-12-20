/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:57:52 by slitim            #+#    #+#             */
/*   Updated: 2016/11/19 21:47:47 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				neg;

	neg = -1;
	if (n >= 0)
		neg = 1;
	i = ft_countnumbers(n);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	str[--i] = (n % 10) * neg + '0';
	while ((n = n / 10))
		str[--i] = (n % 10) * neg + '0';
	if (i)
		str[--i] = '-';
	return (str);
}
