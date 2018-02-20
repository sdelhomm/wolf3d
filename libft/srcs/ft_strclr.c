/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:20:10 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:51:21 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strclr(char *s)
{
	int	count;

	if (s != NULL)
	{
		count = 0;
		while (s[count] != '\0')
		{
			s[count] = '\0';
			count++;
		}
	}
}