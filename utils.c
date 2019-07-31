/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:34:50 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/31 19:16:53 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "functions.h"

int             limit_x(t_tetri *pt, int min_ou_max) // renvoi la valeur en abscisse (x) de la case le + a gauche ou a droite
{
	int     max_x;

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

void        set_zero(t_tetri *pt) // remet les coordonnes du tetri a 0 de sorte a ce quil soit le + en haut a gauche
{
	int		i;
	int 	min_x;
	int 	min_y;
	t_point	*point;

	if (pt)
	{
		min_y = pt->a.y;
		min_x = limit_x(pt, 0);
		while (min_x-- > 1 && (point = &pt->a) && (i = 0) == 0)
			while (i++ < 4 && ((*point).x -= 1))
				(void)*point++;
		while (min_y-- > 1 && (point = &pt->a) && (i = 0) == 0)
			while (i++ < 4 && ((*point).y -= 1))
				(void)*point++;
	}
}

int             nb_config(t_tetri *pt, int size) // calcul le nb total de configs (donc le lignes)
{
	int max_y;
	int max_x;
	int i;

	i = 0;
	max_y = pt->d.y;
	while (max_y++ <= size && (max_x = limit_x(pt, 1)))
		while (max_x++ <= size)
			i++;
	return (i);
}

void            tab_zero(char **tab, int size, int nb_conf) // rempli de 0 la matrice fraichement malloc
{
	int i;
	int j;

	i = 0;
	while (i < nb_conf)
	{
		j = 0;
		while (j < size * size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

int				nb_newconfig(char **tab, int j, int size)
{
	int		i;
	int		k;
	int		l;
	int		nb;
	int		total;

	if (tab && (i = 0) == 0 && (l = 0) == 0)
	{
		total = 0;
		while (tab[i] && tab[i][j] == '.')
			i++;
		while (tab[l][0] && (nb = 0) == 0 && (k = 0) == 0)
		{
			while (tab[l][k] != '\0')
			{
				if (tab[l][k] == tab[i][j] && i != l)
					break;
				if (tab[l][k] != '.' && tab[i][k] == '.' && l != i)
					nb++;
				k++;
			}
			if (l == i)
				printf("\n\n %s\n\n", tab[l]); // affichage de la "bonne" config
			if (nb == 4)
				total++;
			l++;
		}
		return (total);
	}
	return (0);
}
