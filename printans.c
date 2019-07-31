/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:17:07 by amaupied          #+#    #+#             */
/*   Updated: 2019/07/31 22:44:51 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

int					ft_lstlen(t_double_list *alst)
{
	int				i;
	t_double_list	begin;

	begin = *alst;
	i = 0;
	while (alst)
	{
		i++;
		alst = (alst)->next;
	}
	alst = &begin;
	return (i);
}

void				get_answer(char **tab, int size, int nbtetri)
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
		while (i < nbtetri && print == 0)
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
}
