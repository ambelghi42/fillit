/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 00:29:42 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/25 22:30:22 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "functions.h"

t_tetri			*get_points(char *s) // renvoi les coordonnes des cases du tetri
{
	t_tetri	*tetri;
	t_point	*point;
	char	*p;
	int		i;
	int		z;

	tetri = NULL;
	if ((p = s) && (tetri = (t_tetri *)malloc(sizeof(t_tetri))))
	{
		i = 0;
		point = &tetri->a;
		while ((p = ft_strchr(p, '#')) != NULL && i++ < 4)
		{
			if (((p - s) + 1) < 4)
				point->y = ((p - s) + 1) / 4 + 1;
			else if (((p - s) + 1) % 4 > 0)
				point->y = ((p - s) + 1) / 4 + 1;
			else
				point->y = ((p - s) + 1) / 4;
			point->x = (((p - s) + 1) % 4 == 0 ? 4 : ((p - s) + 1) % 4);
			(void)*point++;
			(void)*p++;
		}
	}
	return (tetri);
}

int				is_touching(t_point *case1, t_point *case2) // verif si 2 cases se touchent
{
	if (case1 && case2)
	{
		if (case1->x == case2->x && (case1->y - case2->y == 1
					|| case1->y - case2->y == -1))
			return (1);
		if (case1->y == case2->y && (case1->x - case2->x == 1
					|| case1->x - case2->x == -1))
			return (1);
	}
	return (0);
}

int				check_piece(t_double_list **tetri, char **line) // check si un tetri est valide
{
	t_double_list	*new;
	t_tetri			*pt;

	if (*line && tetri)
	{
		if ((pt = get_points(*line)) && check_line(*line) > 0
				&& (is_touching(&pt->a, &pt->b) + is_touching(&pt->a, &pt->c)
					+ is_touching(&pt->a, &pt->d) + is_touching(&pt->b, &pt->a)
					+ is_touching(&pt->b, &pt->c) + is_touching(&pt->b, &pt->d)
					+ is_touching(&pt->c, &pt->a) + is_touching(&pt->c, &pt->b)
					+ is_touching(&pt->c, &pt->d) + is_touching(&pt->d, &pt->a)
					+ is_touching(&pt->d, &pt->c) + is_touching(&pt->d, &pt->b) >= 6))
		{
			set_zero(pt);
			new = ft_d_lstnew(NULL, 0);
			new->content = pt;
			ft_d_lstaddback(tetri, new);
		}
		else
			ft_d_lstdestroy(tetri);
		ft_memdel((void **)line);
	}
	return (1);
}

int				check_line(const char *line)
{
	int i;

	if (line)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] != '.' && line[i] != '#')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
