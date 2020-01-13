/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:17:07 by amaupied          #+#    #+#             */
/*   Updated: 2019/08/21 20:07:34 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "functions.h"

int					ft_lstlen(t_double_list *alst)
{
	int				i;
	t_double_list	*tmp;

	tmp = alst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void				print_piece(char *s, int size)
{
	int	i;
	int	z;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			z = 0;
			while (s[i] && z++ < size)
			{
				ft_putchar(s[i++]);
			}
			ft_putstr("\n");
		}
	}
}

void				get_answer(char **tab, int size)
{
	int				i;
	int				j;
	int				print;

	j = 0;
	while (j < size * size)
	{
		print = 0;
		i = 0;
		if (j && j % size == 0)
			ft_putchar('\n');
		while (tab[i] && print == 0)
		{
			if (tab[i][j] < 91 && tab[i][j] > 64)
			{
				ft_putchar((char)tab[i][j]);
				print++;
			}
			i++;
		}
		if (!print)
			ft_putchar('.');
		j++;
	}
	ft_putstr("\n");
}

int					master_check(char *file, t_double_list **tetri)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd >= 0 && (*tetri = get_grille(fd)))
	{
		close(fd);
		i = 0;
		fd = open(file, O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			i++;
			free(line);
		}
		close(fd);
		if (ft_lstlen(*tetri) > 26 || i / ft_lstlen(*tetri) != 4)
		{
			ft_d_lstdestroy(tetri);
			return (0);
		}
		return (1);
	}
	return (0);
}
