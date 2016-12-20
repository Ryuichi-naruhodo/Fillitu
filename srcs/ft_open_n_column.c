/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:40:55 by jclaudan          #+#    #+#             */
/*   Updated: 2016/12/20 00:50:37 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			open_for_read(char *file_name)
{
	int		fd;

	if (!(fd = open(file_name, O_RDONLY)))
		return (0);
	return (fd);
}

char		**cut_column(char **tetri)
{
	int						y;
	char					**tmp;
	size_t					len;
	int						start;

	tmp = NULL;
	y = 0;
	if (check_l_column(tetri) == 0)
		return (tetri);
	if ((start = check_l_column(tetri)) != 0)
	{
		if (!(tmp = (char **)malloc(sizeof(char *) * 5)))
			return (NULL);
		while (tetri[y])
		{
			len = ft_strlen(tetri[y]);
			tmp[y] = ft_strsub(tetri[y], start, len);
			y++;
		}
		tmp[y] = NULL;
	}
	ft_free_all((void **)tetri);
	return (tmp);
}
