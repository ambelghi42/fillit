/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:33:56 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/31 19:20:49 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "functions.h"

t_double_list   *get_grille(int fd) // renvoi liste chainee des tetri & verif grille
{
	int             i;
	char            *line;
	char            *tmp;
	char            *p;
	t_double_list   *tetri;

	i = 0;
	tetri = NULL;
	tmp = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if ((!tetri && i == -1) || (!*line && i != -1))
			return (NULL);
		if (*line && ft_strlen(line) == 4)
		{
			p = tmp;
			tmp = ft_strjoin(tmp, line);
			ft_memdel((void **)&p);
		}
		if (i++ == 3 && check_piece(&tetri, &tmp))
			i = -1;
		free(line);
	}
	return (tetri);
}

char			**set_config(t_double_list *list, char **tab, int size) // rempli la matrice avec tte les configs
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	int				max_x;
	int				max_y;
	t_double_list	*tmp;
	t_point			*pt;

	tmp = list;
	i = 0;
	m = 0;
	while (tmp)
	{
		l = 0;
		max_y = ((t_tetri*)tmp->content)->d.y;
		while (max_y++ <= size && (max_x = limit_x((t_tetri*)tmp->content, 1)))
		{
			k = 0;
			while (max_x++ <= size)
			{
				j = 0;
				pt = &((t_tetri*)tmp->content)->a;
				while (j++ < 4 && (tab[i][k + pt->x + pt->y * size - size + size * l - 1] = 'A' + m))
					(void)*pt++;
				i++;
				k++;
			}
			l++;
		}
		tmp = tmp->next;
		m++;
	}
	return (tab);
}

char			**init_config(t_double_list *pcs, int size) //renvoi la matrice remplie
{
	t_double_list	*tmp;
	char			**config;
	int				nb_conf;	
	int				i;

	config = NULL;
	if (pcs && size > 0)
	{
		tmp = pcs;
		nb_conf = 0;
		while (tmp && (nb_conf += nb_config((t_tetri *)tmp->content, size)))
			tmp = tmp->next;
		if (!(config = (char **)malloc(sizeof(char*) * (nb_conf + 1))))
			return (NULL);
		i = 0;
		config[nb_conf] = "\0";
		while (i < nb_conf
				&& (config[i] = ft_strnew(size * size)))
			i++;
		tab_zero(config, size, nb_conf);
		if (i != nb_conf || !set_config(pcs, config, size))
			return (NULL);
	}
	return (config);
}

int				get_col(char **tab, int start, int nb_conf, int size)
{
	int	i;
	int	j;
	int	nb;
	int	col;
	int	tmp;

	if (tab && (j = start) >= 0)
	{
		col = 0;
		tmp = 0;
		while (j < size * size && (nb = 0) == 0 && (i = 0) == 0)
		{
			while (i < nb_conf)
				if (tab[i++][j] != '.')
					nb++;
			if (tmp == 0 || (nb < tmp && nb > 0))
			{
				col = j;
				tmp = nb;
			}
			j++;
		}
		return (col);
	}
	return (-1);
}

char			**init_newconfig(char **tab, int j, int size)
{
	char	**new;
	int		i;
	int		nb_conf;
	int     k;
	int     l;
	int		z;
	int     nb;

	nb_conf = nb_newconfig(tab, j, size);
	if (tab && (new = (char **)malloc(sizeof(char *) * (nb_conf + 1))))
	{
		i = 0;
		new[nb_conf] = "\0";
		while (tab[i][j] != '\0' && tab[i][j] == '.')
			i++;
		z = 0;
		l = 0;
		while (tab[l][0] != '\0' && (nb = 0) == 0 && (k = 0) == 0)
		{
			while (tab[l][k] != '\0')
			{
				if (tab[l][k] == tab[i][j] && i != l)
					break;
				if (tab[l][k] != '.' && tab[i][k] == '.' && l != i)
					nb++;
				k++;
			}
			if (nb == 4)
				new[z++] = ft_strdup(tab[l]);
			l++;
		}
		return (new);
	}
	return (NULL);
}
