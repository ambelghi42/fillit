/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:34:50 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/21 01:24:47 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "functions.h"

int			limit_x(t_tetri *pt, int min_ou_max)
{
	int	max_x;

	max_x = 0;
	if (pt)
	{
		if (min_ou_max == 0)
		{
			max_x = (pt->a.x > pt->b.x ? pt->b.x : pt->a.x);
			max_x = (max_x > pt->c.x ? pt->c.x : max_x);
			max_x = (max_x > pt->d.x ? pt->d.x : max_x);
		}
		else
		{
			max_x = (pt->a.x < pt->b.x ? pt->b.x : pt->a.x);
			max_x = (max_x < pt->c.x ? pt->c.x : max_x);
			max_x = (max_x < pt->d.x ? pt->d.x : max_x);
		}
	}
	return (max_x);
}

void		set_zero(t_tetri *pt)
{
	int		i;
	int		min_x;
	int		min_y;
	t_point	*point;

	if (pt)
	{
		min_y = pt->a.y;
		min_x = limit_x(pt, 0);
		while (min_x-- > 1 && (point = &pt->a))
		{
			i = 0;
			while (i++ < 4 && ((*point).x -= 1))
				(void)*point++;
		}
		while (min_y-- > 1 && (point = &pt->a))
		{
			i = 0;
			while (i++ < 4 && ((*point).y -= 1))
				(void)*point++;
		}
	}
}

int			get_size(int nb)
{
	int i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

int			ft_getcol2(char **tmp, int i)
{
	int col;

	col = 0;
	while (tmp && tmp[0] && tmp[i] && tmp[i][col] && tmp[i][col] == '.')
	{
		col++;
	}
	return (tmp[i] && tmp[i][col] != '\0' ? col : 0);
}

void		move_me(t_minmax lmt, t_point *tetri, int size)
{
	int		i;
	t_point	*tmp;

	if (lmt.max_x == size && lmt.max_y != size)
	{
		while (lmt.min_x-- > 1 && (tmp = tetri))
		{
			i = 0;
			while (i++ < 4 && tmp->x-- > 1)
				(void)*tmp++;
		}
		tmp = tetri;
		i = 0;
		while (i++ < 4 && tmp->y++ <= size)
			(void)*tmp++;
	}
	else if (lmt.max_x < size && (tmp = tetri))
	{
		i = 0;
		while (i++ < 4 && tmp->x++ <= size)
			(void)*tmp++;
	}
}
