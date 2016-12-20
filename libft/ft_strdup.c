/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:22:17 by slitim            #+#    #+#             */
/*   Updated: 2016/11/11 16:59:47 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		i;
	char	*d;

	i = 0;
	d = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}
