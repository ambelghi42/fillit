/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:41:06 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/21 22:24:26 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_double_list	*tetriminos;
	char			**solved;
	int				lst_len;
	int				size;

	if (ac == 2)
	{
		solved = NULL;
		if (master_check(av[1], &tetriminos) == 1)
		{
			lst_len = ft_lstlen(tetriminos);
			size = get_size(lst_len * 4);
			solved = new_solved(solved, lst_len);
			while (master_solve(tetriminos, solved, 0, size) != 1)
				size++;
			get_answer(solved, size);
		}
		else
			ft_putstr("error\n");
		free_me2(tetriminos, solved);
	}
	else
		ft_putstr("Usage: ./fillit source_file\n");
	return (0);
}
