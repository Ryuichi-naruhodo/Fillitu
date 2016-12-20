/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:29:04 by jclaudan          #+#    #+#             */
/*   Updated: 2016/12/20 00:55:53 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			sqrt_tetri(int nb)
{
	int	racine;

	racine = 2;
	while (racine * racine < nb)
		racine++;
	return (racine);
}

void		free_map(t_map *map)
{
	ft_free_all((void **)map->matrice);
	ft_memdel((void **)&map);
}

t_map		*new_map(int len_cote)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->matrice = (char **)malloc(sizeof(char *) * len_cote)))
		return (NULL);
	map->size = len_cote;
	j = 0;
	while (j < len_cote)
	{
		map->matrice[j] = ft_strnew(len_cote);
		i = 0;
		while (i < len_cote)
		{
			map->matrice[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

int			check_line(char *str)
{
	if (ft_strcmp(str, ft_strdup("....")) == 0)
		return (1);
	else
		return (0);
}

int			check_l_column(char **tetri)
{
	int						count[2];
	int						yx[2];

	yx[0] = 0;
	yx[1] = 0;
	count[1] = 0;
	while (tetri[yx[0]][yx[1]] && tetri[yx[0]][yx[1]] != '#' && tetri)
	{
		count[0] = 0;
		while (tetri[yx[0]])
		{
			if (tetri[yx[0]][yx[1]] == '.')
				count[0]++;
			yx[0]++;
		}
		if (count[0] == yx[0])
		{
			yx[0] = 0;
			count[1]++;
		}
		else
			break ;
		yx[1]++;
	}
	return (count[1]);
}
