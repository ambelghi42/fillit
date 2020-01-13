/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:26:22 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/21 22:26:19 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "functions.h"

int		is_solved(char **ew, int lst_len)
{
	int a;
	int i;
	int j;

	if (ew)
	{
		i = 0;
		while (ew[i] && ew[i][0] != '\0' && (j = 0) == 0)
		{
			while (ew[i][j] != '\0' && (a = 0) == 0)
			{
				if (ew[i][j] != '.')
					while (ew[a] && ew[a][0])
						if (ew[a++][j] != '.' && a != i + 1)
							return (0);
				j++;
			}
			i++;
		}
		return (i == lst_len ? 1 : 0);
	}
	return (0);
}

char	**new_solved(char **solved, int lst_len)
{
	int i;

	i = 0;
	if (solved)
	{
		free(solved);
		if (!(solved = (char **)malloc(sizeof(char *) * lst_len + 1)))
			return (NULL);
		solved[lst_len] = NULL;
		while (i < lst_len)
			solved[i++] = ft_strnew(1);
	}
	else if ((solved = (char **)malloc(sizeof(char *) * (lst_len + 1))))
	{
		solved[lst_len] = NULL;
		while (i < lst_len)
			solved[i++] = ft_strnew(1);
	}
	return (solved);
}

char	*new_conf(t_tetri *tetri, int size, int piece)
{
	int		i;
	t_tetri tmp;
	t_point *pt;
	char	*new;

	if (tetri && (new = ft_strnew(size * size)))
	{
		i = 0;
		tmp = *tetri;
		ft_memset(new, '.', size * size);
		i = 0;
		pt = &tmp.a;
		while (i++ < 4 && (new[pt->x + pt->y * size - size - 1] = 'A' + piece))
			(void)*pt++;
		return (new);
	}
	return (NULL);
}

int		is_valid(char **solved)
{
	int	i;
	int	j;
	int	nb;

	if (solved && solved[0])
	{
		j = 0;
		while (solved[0][j])
		{
			i = 0;
			nb = 0;
			while (solved[i] && solved[i][0])
				if (solved[i++][j] != '.')
					nb++;
			if (nb > 1)
				return (0);
			j++;
		}
		return (1);
	}
	return (0);
}

int		master_solve(t_double_list *lst, char **solved, int piece, int size)
{
	int				i;
	int				nb_conf;
	int				lst_len;
	t_tetri			tetri;

	lst_len = ft_lstlen(lst) + piece;
	if (is_solved(solved, lst_len) == 1)
		return (1);
	tetri = *((t_tetri *)lst->content);
	if (lst && piece < lst_len && (t_tetri *)&tetri
		&& (nb_conf = (size - limit_x(&tetri, 1) + 1) * (size - tetri.d.y + 1)))
	{
		i = 0;
		while (i++ < nb_conf)
		{
			ft_strdel(&solved[piece]);
			solved[piece] = new_conf(&tetri, size, piece);
			mv_tetri(&tetri, size);
			if (is_valid(solved)
				&& master_solve(lst->next, solved, piece + 1, size) == 1)
				return (1);
		}
		ft_strdel(&solved[piece]);
	}
	return (0);
}
