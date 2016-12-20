/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strctrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:24:37 by slitim            #+#    #+#             */
/*   Updated: 2016/11/21 13:26:33 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == c)
		i++;
	while (s[j] == c)
		j--;
	if (j < i)
		return (ft_strdup(s + i));
	j = j - i + 1;
	str = ft_strsub(s, i, j);
	return (str);
}
