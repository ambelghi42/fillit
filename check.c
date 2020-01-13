/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 00:29:42 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/21 22:23:52 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "functions.h"

t_double_list	*get_grille(int fd)
{
	int				i;
	char			*line;
	char			*tmp;
	char			*p;
	t_double_list	*tetri;

	i = 0;
	tetri = NULL;
	tmp = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (((!tetri && i == -1) || (!*line && i != -1))
			&& free_me(fd, line, tmp, tetri))
			return (NULL);
		if (*line && ft_strlen(line) == 4 && ((p = tmp) || !p))
		{
			tmp = ft_strjoin(tmp, line);
			ft_memdel((void **)&p);
		}
		if (i++ == 3 && check_piece(&tetri, &tmp))
			i = -1;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&tmp);
	return (tetri);
}

t_tetri			*get_points(char *s, int size)
{
	t_tetri	*tetri;
	t_point	*pt;
	char	*p;
	int		i;

	tetri = NULL;
	p = s;
	if (p && (tetri = (t_tetri *)malloc(sizeof(t_tetri))))
	{
		i = 0;
		pt = &tetri->a;
		while ((p = ft_strdchr(p, '.')) && *p && i++ < 4)
		{
			if (((p - s) + 1) < size)
				pt->y = ((p - s) + 1) / size + 1;
			else if (((p - s) + 1) % size > 0)
				pt->y = ((p - s) + 1) / size + 1;
			else
				pt->y = ((p - s) + 1) / size;
			pt->x = (((p - s) + 1) % size == 0 ? size : ((p - s) + 1) % size);
			(void)*pt++;
			(void)*p++;
		}
	}
	return (tetri);
}

int				is_touching(t_point *case1, t_point *case2)
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

int				check_piece(t_double_list **tetri, char **line)
{
	t_double_list	*new;
	t_tetri			*pt;

	if (*line && tetri)
	{
		if (check_line(*line) > 0 && (pt = get_points(*line, 4))
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
		ft_strdel(line);
	}
	return (1);
}

int				check_line(const char *line)
{
	int i;
	int	nb;

	if (line)
	{
		nb = 0;
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == '#')
				nb++;
			if (nb > 4 || (line[i] != '.' && line[i] != '#'))
				return (0);
			i++;
		}
		return (i == 16 && nb == 4 ? 1 : 0);
	}
	return (0);
}
