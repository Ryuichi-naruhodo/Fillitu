/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:34:24 by slitim            #+#    #+#             */
/*   Updated: 2016/11/20 19:08:15 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	while (s[j] == '\n' || s[j] == '\t' || s[j] == ' ')
		j--;
	if (j < i)
		return (ft_strdup(s + i));
	j = j - i + 1;
	str = ft_strsub(s, i, j);
	return (str);
}
