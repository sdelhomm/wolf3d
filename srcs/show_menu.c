/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:04:56 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/12 15:32:24 by sdelhomm         ###   ########.fr       */
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
	char	*str_time;

	p->menuState = 3;
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img9, 0, 0);         
	str_time = ft_itoa(time(NULL) - p->tm);
	mlx_string_put(p->mlx, p->win, SCREEN_X / 2, SCREEN_Y / 2, 0xFFFFFF, str_time);
	free(str_time);
}