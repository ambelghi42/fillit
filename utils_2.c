/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 23:40:27 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/21 22:11:34 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "functions.h"

void		mv_tetri(t_tetri *tetri, int size)
{
	t_minmax	lmt;
	t_point		*tmp;

	if (tetri)
	{
		lmt.max_y = tetri->d.y;
		lmt.max_x = limit_x(tetri, 1);
		lmt.min_x = limit_x(tetri, 0);
		tmp = &tetri->a;
		move_me(lmt, tmp, size);
	}
}

int			free_me(int fd, char *line, char *tmp, t_double_list *tetri)
{
	int i;

	i = 0;
	if (line)
	{
		ft_d_lstdestroy(&tetri);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&line);
		while (get_next_line(fd, &line) > 0)
		{
			if (i++ > 135)
				close(fd);
			free(line);
		}
	}
	return (1);
}

void		free_me2(t_double_list *tetri, char **solved)
{
	int i;

	if (tetri && solved)
	{
		i = 0;
		ft_d_lstdestroy(&tetri);
		while (solved[i])
			ft_strdel(&solved[i++]);
		free(solved);
	}
}
