/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 01:11:22 by jclaudan          #+#    #+#             */
/*   Updated: 2016/12/20 00:51:30 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**rogne_tetri(char **tetri)
{
	int						y;
	int						i;
	char					**tmp;
	char					**tmp2;

	y = 0;
	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (tetri[y])
	{
		if (check_line(tetri[y]) == 0)
			tmp[i++] = ft_strdup(tetri[y]);
		y++;
	}
	tmp[i] = NULL;
	ft_free_all((void **)tetri);
	tetri = NULL;
	tmp2 = cut_column(tmp);
	return (tmp2);
}

int			len_tetri_x(char **tetri)
{
	int		j;
	int		i;
	int		imin;
	int		imax;
	int		diez;

	imin = 0;
	imax = 0;
	diez = 0;
	j = -1;
	while (tetri[++j])
	{
		i = -1;
		while (tetri[j][++i])
		{
			if (tetri[j][i] == '#')
			{
				if (++diez == 1)
					imin = i;
				i < imin ? imin = i : 0;
				i > imax ? imax = i : 0;
			}
		}
	}
	return (imax - imin + 1);
}

int			len_tetri_y(char **tetri)
{
	int					y;

	y = 0;
	while (tetri[y])
	{
		y++;
	}
	return (y);
}

t_tetri		*ft_tetrinew(void const *content, char name, int nb)
{
	t_tetri	*new_lst;

	if (!(new_lst = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	if (nb == 20)
	{
		new_lst->name = 'A';
		new_lst->nb_tetri = 1;
	}
	else
		new_lst->name = name + 1;
	if (content != NULL)
	{
		new_lst->y = len_tetri_y(rogne_tetri(ft_strsplit(content, '\n')));
		new_lst->x = len_tetri_x(rogne_tetri(ft_strsplit(content, '\n')));
		new_lst->t = rogne_tetri(ft_strsplit(content, '\n'));
		new_lst->next = NULL;
	}
	else
	{
		new_lst->t = NULL;
		new_lst->next = NULL;
	}
	return (new_lst);
}

t_tetri		*read_tetri(char *file_name, t_tetri *tetri, int fd)
{
	t_tetri	*tmp;
	char	*buff;

	buff = ft_strnew(21);
	fd = open_for_read(file_name);
	if (!read(fd, buff, 20))
		return (NULL);
	if (ft_is_valid_tetri(buff, 20) == 1)
		tetri = ft_tetrinew(buff, tetri->name, 20);
	else
		return (NULL);
	tmp = tetri;
	while (read(fd, buff, 21) != 0)
	{
		if (ft_is_valid_tetri(buff, 21) == 1)
		{
			tetri->next = ft_tetrinew(buff, tetri->name, 21);
			tetri = tetri->next;
			tmp->nb_tetri++;
		}
		else
			return (NULL);
		buff = ft_strnew(21);
	}
	return (tmp);
}
