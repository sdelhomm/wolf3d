/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:37:52 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/02/20 16:13:37 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/wolf3d.h"

static void	check_collision(int keycode, t_param *p, t_map map)
{
	double	x;
	double	y;
	double	a;

	x = p->j.x;
	y = p->j.y;
	a = p->j.a * M_PI / 180;
	a += (keycode == 123 ? -M_PI_2 : 0);
	a += (keycode == 124 ? M_PI_2 : 0);
	a += (keycode == 125 ? M_PI : 0);
	x = x + HB * cos(a);
	y = y + HB * sin(a);
	if (x >= 0 && y >= 0 && x < map.x && y < map.y &&
		map.map[(int)floor(y + 0.1 * sin(a))][(int)floor(x + 0.1 * cos(a))] != 1
		&& map.map[(int)floor(y)][(int)floor(x)] != 1)
	{
		p->j.x = p->j.x + 0.1 * cos(a);
		p->j.y = p->j.y + 0.1 * sin(a);
	}
}

int			mouse_hook(int x, int y, t_param *p)
{
	y = 0;
	if (!p->pos_x)
	{
		p->pos_x = abs(x);
		p->pos_y = abs(y);
	}
	if (x < p->lx - 1)
		p->j.a -= 2.5;
	if (x > p->lx + 1)
		p->j.a += 2.5;
	if (x  <= 5 || x >= SCREEN_X - 5)
	{
		CGWarpMouseCursorPosition(CGPointMake(SCREEN_X / 2 + p->pos_x, SCREEN_Y / 2 + p->pos_y));
		p->lx = SCREEN_X / 2 - p->pos_x;
		x = (x + p->pos_x <= 10 ? p->lx + 100 : p->lx - 100);
	}
	p->lx = x;
	return (0);
}

int			key_hook(int keycode, t_param *p)
{
	int x;
	int y;

	if (keycode == 53)
		exit(0);
	if (keycode == 49)
	{
		x = (int)floor(p->j.x + cos(p->j.a * M_PI / 180) / 2);
		y = (int)floor(p->j.y + sin(p->j.a * M_PI / 180) / 2);
		if (x >= 0 && y >= 0 &&
			x < p->map.x && y < p->map.y && p->map.map[y][x] == 1)
			p->map.map[(int)floor(y)][(int)floor(x)] = 0;
	}
	check_collision(keycode, p, p->map);
	return (0);
}

int			hook(t_param *p)
{
	p->ptr_img = mlx_new_image(p->mlx, SCREEN_X, SCREEN_Y);
	p->img = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	wolf3d(p);
	return (0);
}
