/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:36:48 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/12 16:37:02 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		free_map(t_map map)
{
	int	y;

	y = 0;
	while (y < map.y)
		free(map.map[y++]);
	free(map.map);
	return (1);
}
