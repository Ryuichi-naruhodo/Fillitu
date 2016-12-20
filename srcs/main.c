/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:55:31 by slitim            #+#    #+#             */
/*   Updated: 2016/12/20 00:32:37 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_tetri	*tetri;
	t_map	*r_map;

	i = -1;
	fd = 0;
	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	if (argc != 2)
		ft_error("error", 1);
	if (argv[1])
	{
		if (!(tetri = read_tetri(argv[1], tetri, fd)) || tetri->nb_tetri > 26)
			ft_error("error", 1);
		else
		{
			r_map = resolve(tetri);
			while (++i < r_map->size)
				ft_putendl(r_map->matrice[i]);
		}
	}
	return (0);
}
