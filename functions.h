/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 01:51:54 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/31 22:44:24 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define  FUNCTIONS_H

# include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	t_point		a;
	t_point		b;
	t_point		c;
	t_point		d;
}				t_tetri;

int             nb_config(t_tetri *pt, int size);
int             check_line(const char *line);
int				is_touching(t_point *case1, t_point *case2);
int				check_piece(t_double_list **tetri, char **line);
int             limit_x(t_tetri *pt, int min_ou_max);
int				get_col(char **tab, int start, int nb_conf, int size);
int             nb_newconfig(char **tab, int j, int size);
int				ft_lstlen(t_double_list *alst);
int				get_size(int nb);
char            **init_config(t_double_list *pcs, int size);
char            **set_config(t_double_list *tetri, char **tab, int size);
char            **init_newconfig(char **tab, int j, int size);
void			set_point(t_point *point, int i, int size);
void            tab_zero(char **tab, int size, int nb_conf);
void        	set_zero(t_tetri *pt);
t_double_list   *get_grille(int fd);
t_tetri         *get_points(char *s);

#endif
