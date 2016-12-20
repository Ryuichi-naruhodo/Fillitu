/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:50:38 by slitim            #+#    #+#             */
/*   Updated: 2016/11/21 12:18:51 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_countletters(char *str, char c)
{
	int		i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		word;

	i = 0;
	if (!s)
		return (NULL);
	word = ft_countwords((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (ft_countwords((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (word--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strsub(s, 0, ft_countletters((char *)s, c));
		if (!tab[i])
			return (NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
