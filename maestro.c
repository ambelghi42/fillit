/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maestro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:21:41 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/31 23:52:26 by ambelghi         ###   ########.fr       */
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

int	maestro(char **ew, char	**solved, int lst_len, int nb_conf)
{
	int		col;
	int		nb_conf;
	char	**solved;

	size = get_size(lst_len);
	if (ew && check_solved(ew) > 0)
	{
		col = get_col(ew, start, nb_conf, 4);
		nb_conf = nb_newconfig(ew, col, 4);
		ew = init_newconfig(ew, col, 4);
		if (maestro(ew, solved, lst_len, nb_conf) == 1)
			return (1);
		free(ew);
	}
	return (0);
}
