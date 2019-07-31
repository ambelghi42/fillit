/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:41:06 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/31 22:45:51 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "libft/libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_double_list	*tetriminos;
	t_double_list	*tmp;
	int 			fd;
	char			*trim;
	t_tetri			*point;
	int				i;
	char			*new;
	int				nb_conf;
	int				col;

	if (ac == 2 && (fd = open(av[1], O_RDONLY)) >= 0)
	{
		if ((tetriminos = get_grille(fd))) // [parsing]recup de la liste chainee avec les pieces
		{
			tmp = tetriminos;
			char **ew;
			ew = init_config(tmp, 4); // creation des configs
			i = 0;
			nb_conf = 0;
			while (ew[i] && ew[i][0] != '\0')
				printf(" %s\n", ew[i++]);
			printf("\n\n%i\n\n", get_size(ft_lstlen(tetriminos) * 4));
			printf("------------------------------------\n");
			while (tmp && (nb_conf += nb_config((t_tetri *)tmp->content, 4)))
				tmp = tmp->next;			
			col = get_col(ew, 3, nb_conf, 4);
			nb_conf = nb_newconfig(ew, col, 4);
			printf("col : %i | nombre de lignes a copier : %i\n", col, nb_conf);
			ew = init_newconfig(ew, col, 4);
			tmp = tetriminos;
			i = 0;
			while (ew[i] && ew[i][0] != '\0')
				printf(" %s\n", ew[i++]);
			printf("------------------------------------\n\n");

			printf("------------------------------------\n");
			//nb_conf = nb_newconfig(ew, col, 4);	
			col = get_col(ew, 0, nb_conf, 4);
			printf("col : %i | nombre de lignes a copier : %i\n", col, nb_conf);
			ew = init_newconfig(ew, col, 4);
			tmp = tetriminos;
			i = 0;
			while (ew[i] && ew[i][0] != '\0')
				printf(" %s\n", ew[i++]);
			printf("------------------------------------\n\n");

			printf("------------------------------------\n");
			nb_conf = nb_newconfig(ew, col, 4);
			col = get_col(ew, 0, nb_conf, 4);
			ew = init_newconfig(ew, col, 4);
			printf("col : %i | nombre de lignes a copier : %i\n", col, nb_conf);
			tmp = tetriminos;
			i = 0;
			while (ew[i] && ew[i][0] != '\0')
				printf(" %s\n", ew[i++]);
			printf("------------------------------------\n\n");

			printf("------------------------------------\n");
			nb_conf = nb_newconfig(ew, col, 4);
			col = get_col(ew, 0, nb_conf, 4);
			ew = init_newconfig(ew, col, 4);
			printf("col : %i | nombre de lignes a copier : %i\n", col, nb_conf);
			tmp = tetriminos;
			i = 0;
			while (ew[i] && ew[i][0] != '\0')
				printf(" %s\n", ew[i++]);
			printf("------------------------------------\n\n");

			while (tetriminos)
			{
				i = 0;
				point = (t_tetri *)tetriminos->content;
				printf("\n\nA: x=%i y=%i | B: x=%i y=%i | C: x=%i y=%i | D: x=%i y=%i\n", point->a.x, point->a.y, point->b.x,
						point->b.y, point->c.x, point->c.y, point->d.x, point->d.y);
				printf("\n\n\n\n");
				tetriminos = tetriminos->next;
			}
		}
		else
			printf("mawaiiiiii");
	}
	return (0);
}
