/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:46:55 by ambelghi          #+#    #+#             */
/*   Updated: 2019/08/15 19:48:02 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdchr(char const *s, int c)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] == (char)c && s[i] != '\0')
			i++;
		if (s[i] != (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
