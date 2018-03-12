/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:20:13 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/03/12 16:25:09 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		free_map(t_map map)
{
	int	y;

	while (y < map.y)
		free(map.map[y++]);
	free(map.map);
	return (1);
}
