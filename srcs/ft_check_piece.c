/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:16:19 by slitim            #+#    #+#             */
/*   Updated: 2016/12/20 00:30:39 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_piece(char *te)
{
	int i;
	int check;

	check = 0;
	i = 0;
	while (i < 20)
	{
		if (te[i] == '#')
		{
			if (i + 1 < 20 && te[i + 1] == '#')
				check++;
			if (i - 1 >= 0 && te[i - 1] == '#')
				check++;
			if (i + 5 < 20 && te[i + 5] == '#')
				check++;
			if (i - 5 >= 0 && te[i - 5] == '#')
				check++;
		}
		i++;
	}
	if (check == 6 || check == 8)
		return (1);
	return (0);
}

int		ft_check_valid(char *te, int nb)
{
	int ca[4];

	ca[0] = 0;
	ca[1] = 0;
	ca[2] = 0;
	ca[3] = -1;
	while (te[++ca[3]])
		if (te[ca[3]] == '#')
			ca[0]++;
		else if (te[ca[3]] == '.')
			ca[2]++;
		else if (te[ca[3]] == '\n')
			ca[1]++;
		else
			return (0);
	if (nb == 20 && ca[2] == 12 && ca[1] == 4 && ca[0] == 4)
		return (1);
	else if (nb == 21 && ca[2] == 12 && ca[1] == 5 && ca[0] == 4)
	{
		if (te[0] != '\n' || te[1] == '\n')
			return (0);
		return (1);
	}
	else
		return (0);
}

int		ft_check_format(char *te)
{
	char	**tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tmp = ft_strsplit(te, '\n');
	while (tmp[y])
	{
		while (tmp[y][x])
		{
			x++;
		}
		if (x != 4)
			return (0);
		else
			x = 0;
		y++;
	}
	if (y != 4)
		return (0);
	ft_free_all((void **)tmp);
	return (1);
}

int		ft_is_valid_tetri(char *te, int nb)
{
	if (ft_check_piece(te) == 1 && ft_check_valid(te, nb) == 1
			&& ft_check_format(te) == 1)
		return (1);
	else
		return (0);
}
