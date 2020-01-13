/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 01:51:54 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/21 22:00:20 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_minmax
{
	int			max_x;
	int			max_y;
	int			min_x;
	int			min_y;
}				t_minmax;

typedef struct	s_tetri
{
	t_point		a;
	t_point		b;
	t_point		c;
	t_point		d;
}				t_tetri;

int				check_line(const char *line);
int				is_touching(t_point *case1, t_point *case2);
int				check_piece(t_double_list **tetri, char **line);
int				limit_x(t_tetri *pt, int min_ou_max);
int				ft_lstlen(t_double_list *alst);
int				get_size(int nb);
int				is_solved(char **ew, int lst_len);
int				master_solve(t_double_list *l, char **s, int p, int size);
int				is_valid(char **solved);
int				master_check(char *file, t_double_list **tetri);
int				free_me(int fd, char *line, char *tmp, t_double_list *tetri);
char			**new_solved(char **solved, int lst_len);
char			*new_conf(t_tetri *tetri, int size, int piece);
void			set_point(t_point *point, int i, int size);
void			set_zero(t_tetri *pt);
void			mv_tetri(t_tetri *tetri, int size);
void			get_answer(char **tab, int size);
void			free_me2(t_double_list *tetri, char **solved);
void			move_me(t_minmax lmt, t_point *tetri, int size);
t_tetri			*get_points(char *s, int size);
t_double_list	*get_grille(int fd);

#endif
