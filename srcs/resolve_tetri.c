/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:59:32 by jclaudan          #+#    #+#             */
/*   Updated: 2016/12/20 00:53:29 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		put_point(t_tetri *tetri, t_map *map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < tetri->y)
	{
		i = 0;
		while (i < tetri->x)
		{
			if (tetri->t[j][i] == '#')
				map->matrice[y + j][x + i] = '.';
			i++;
		}
		j++;
	}
}

void		put_tetri(t_tetri *tetri, t_map *map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < tetri->y)
	{
		i = 0;
		while (i < tetri->x)
		{
			if (tetri->t[j][i] == '#')
				map->matrice[y + j][x + i] = tetri->name;
			i++;
		}
		j++;
	}
}

int			place_tetri(t_tetri *tetri, t_map *map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < tetri->y)
	{
		i = 0;
		while (i < tetri->x)
		{
			if (tetri->t[j][i] == '#' && map->matrice[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	put_tetri(tetri, map, x, y);
	return (1);
}

int			resolve_map(t_map *map, t_tetri *tetri)
{
	int		x;
	int		y;
	t_tetri *tp;

	tp = tetri;
	if (tetri == NULL)
		return (1);
	y = 0;
	while (y <= map->size - tetri->y)
	{
		x = 0;
		while (x <= map->size - tetri->x)
		{
			if (place_tetri(tp, map, x, y))
			{
				if (resolve_map(map, tetri->next))
					return (1);
				else
					put_point(tp, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map		*resolve(t_tetri *tetri)
{
	int		len_cote;
	t_map	*map;

	len_cote = sqrt_tetri((tetri->nb_tetri * 4));
	map = new_map(len_cote);
	while (!resolve_map(map, tetri))
	{
		len_cote++;
		free(map);
		map = new_map(len_cote);
	}
	return (map);
}
