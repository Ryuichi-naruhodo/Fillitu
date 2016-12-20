/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 23:15:22 by slitim            #+#    #+#             */
/*   Updated: 2016/12/20 00:52:04 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetri
{
	char			**t;
	char			name;
	int				x;
	int				y;
	int				nb_tetri;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	char			**matrice;
	int				size;
}					t_map;

int					ft_check_piece(char *te);
int					ft_check_valid(char *te, int nb);
int					ft_check_format(char *te);
int					ft_is_valid_tetri(char *te, int nb);
t_tetri				*read_tetri(char *file_mane, t_tetri *tetri, int nb);
t_tetri				*ft_tetrinew(void const *content, char name, int nb);
void				ft_display_tetri(t_tetri *dis_lst);
t_map				*resolve(t_tetri *tetri);
int					check_line(char *str);
int					check_l_column(char **tetri);
char				**cut_column(char **tetri);
char				**rogne_tetri(char **tetri);
int					len_tetri_x(char **tetri);
int					len_tetri_y(char **tetri);
int					sqrt_tetri(int nb);
void				free_map(t_map *map);
t_map				*new_map(int len_cote);
void				put_point(t_tetri *tetri, t_map *map, int x, int y);
void				put_tetri(t_tetri *tetri, t_map *map, int x, int y);
int					place_tetri(t_tetri *tetri, t_map *map, int x, int y);
int					resolve_map(t_map *map, t_tetri *tetri);
t_map				*resolve(t_tetri *tetri);
int					open_for_read(char *file_name);

#endif
