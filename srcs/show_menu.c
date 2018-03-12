/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:36:48 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/12 18:18:58 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_show_menu(t_param *p)
{
	if (p->menuState == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img5, 0, 0);
	if (p->menuState == 2)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img6, 0, 0);
	if (p->cursorState == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img7, 450, 500);
	if (p->cursorState == 2)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img7, 350, 625);
	if (p->cursorState == 3)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img7, 450, 740);
	return (0);
}

int		ft_death(t_param *p)
{
	free_map(p->map);
	get_map(p->arg1, map_len(p->arg1, &p->map), &p->j);
	*p = init(*p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img9, 0, 0);
	return (0);
}


int		ft_win(t_param *p)
{
	free_map(p->map);
	get_map(p->arg1, map_len(p->arg1, &p->map), &p->j);
	*p = init(*p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img8, 0, 0);
	return (0);
}

