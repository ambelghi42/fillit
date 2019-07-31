/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maestro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:21:41 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/01 00:10:57 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "functions.h"

int	get_size(int nb)
{
	int	i;
	int	max;
	i = 0;

	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

int	nb_lines(char **ew, int j)
{
	int	i;
	int	nb;

	if (ew && j >= 0)
	{
		nb = 0;
		i = 0;
		while (ew[i] && *ew[i])
			if (ew[i][j] != '.')
				nb++;
		return (i);
	}
	return (0);
}

int	maestro(char **ew, char	**solved, int lst_len, int nb_conf)
{
	int		col;
	int		nb_conf;
	int		i_line;
	int		i_col;
	char	**solved;

	size = get_size(lst_len * 4);
	if (ew)
	{
		if (is_solved(ew, lst_len) == 1) // check si on a une matrice resolue (soit 1 config valide / piece)
			return (1);
		start = 0;
		i_line = 0;
		i_col = 0;
		while (start < size * size) // au cas ou il faudrait passer a la colonne dapres
		{
			col = get_col(ew, start, nb_conf, 4);
			while (i_line++ < nb_lines(ew, col)) // au cas ou on a plusieurs lignes dans la colonne selectionnee
			{
				nb_conf = nb_newconfig(ew, col, 4);
				ew = init_newconfig(ew, col, 4);
				if (is_solvable(ew) && maestro(ew, solved, lst_len, nb_conf) == 1) // elle est al la recursive, on check dabord avec is_solvable si la matrice est solvable (soit la possibilite de placer les pieces sans quelles se touche)
					return (1);
			}
			free(ew);
			start++;
		}
	}
	return (0);
}
