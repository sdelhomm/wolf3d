/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:26:52 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/11 12:44:14 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_intchr(int **tab, const int n, const int sizex, const int sizey)
{
	int x;
	int y;

	y = 0;
	while (y < sizey)
	{
		x = 0;
		while (x < sizex)
		{
			if (tab[y][x] == n)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
