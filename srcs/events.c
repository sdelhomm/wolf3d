/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:37:52 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/02/20 12:00:47 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/wolf3d.h"

static void	movement(int keycode, t_param *p)
{
	if (keycode == 0)
		p->j.a -= 5;
	if (keycode == 2)
		p->j.a += 5;
	if (keycode == 126 && p->map.y - 0.1 > (p->j.y + (0.1 * sin(p->j.a * M_PI / 180)))
		&& (p->j.y + (0.1 * sin(p->j.a * M_PI / 180))) > 0.1
		&& p->map.x - 0.1 > (p->j.x + (0.1 * cos(p->j.a * M_PI / 180))) 
		&& (p->j.x + (0.1 * cos(p->j.a * M_PI / 180))) > 0.1
		&& p->map.map[(int)floor(p->j.y + (0.1 * sin(p->j.a * M_PI / 180)))][(int)floor(p->j.x + (0.1 * cos(p->j.a * M_PI / 180)))] != 1)
	{
		p->j.y += 0.1 * sin(p->j.a * M_PI / 180);
		p->j.x += 0.1 * cos(p->j.a * M_PI / 180);
	}
	if (keycode == 125 && p->map.y - 0.1 > (p->j.y + (0.1 * sin((p->j.a + 180) * M_PI / 180)))
		&& (p->j.y + (0.1 * sin((p->j.a + 180) * M_PI / 180))) > 0.1
		&& p->map.x - 0.1 > (p->j.x + (0.1 * cos((p->j.a + 180) * M_PI / 180))) 
		&& (p->j.x + (0.1 * cos((p->j.a + 180) * M_PI / 180))) > 0.1
		&& p->map.map[(int)floor(p->j.y + (0.1 * sin((p->j.a + 180) * M_PI / 180)))][(int)floor(p->j.x + (0.1 * cos((p->j.a + 180) * M_PI / 180)))] != 1)
	{
		p->j.y += 0.1 * sin((p->j.a + 180) * M_PI / 180);
		p->j.x += 0.1 * cos((p->j.a + 180) * M_PI / 180);
	}
	if (keycode == 123 && p->map.y - 0.1 > (p->j.y + (0.1 * sin((p->j.a - 90) * M_PI / 180)))
		&& (p->j.y + (0.1 * sin((p->j.a - 90) * M_PI / 180))) > 0.1
		&& p->map.x - 0.1 > (p->j.x + (0.1 * cos((p->j.a - 90) * M_PI / 180))) 
		&& (p->j.x + (0.1 * cos((p->j.a - 90) * M_PI / 180))) > 0.1
		&& p->map.map[(int)floor(p->j.y + (0.1 * sin((p->j.a - 90) * M_PI / 180)))][(int)floor(p->j.x + (0.1 * cos((p->j.a - 90) * M_PI / 180)))] != 1)
	{
		p->j.y += 0.1 * sin((p->j.a - 90) * M_PI / 180);
		p->j.x += 0.1 * cos((p->j.a - 90) * M_PI / 180);
	}
	if (keycode == 124 && p->map.y - 0.1 > (p->j.y + (0.1 * sin((p->j.a + 90) * M_PI / 180)))
		&& (p->j.y + (0.1 * sin((p->j.a + 90) * M_PI / 180))) > 0.1
		&& p->map.x - 0.1 > (p->j.x + (0.1 * cos((p->j.a + 90) * M_PI / 180)))
		&& (p->j.x + (0.1 * cos((p->j.a + 90) * M_PI / 180))) > 0.1
		&& p->map.map[(int)floor(p->j.y + (0.1 * sin((p->j.a + 90) * M_PI / 180)))][(int)floor(p->j.x + (0.1 * cos((p->j.a + 90) * M_PI / 180)))] != 1)
	{
		p->j.y += 0.1 * sin((p->j.a + 90) * M_PI / 180);
		p->j.x += 0.1 * cos((p->j.a + 90) * M_PI / 180);
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
	//p->ptr_img = mlx_new_image(p->mlx, SCREEN_X, SCREEN_Y);
	//p->img = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	//wolf3d(p);
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
		x = (int)floor(p->j.x + cos(p->j.a * M_PI / 180));
		y = (int)floor(p->j.y + sin(p->j.a * M_PI / 180));
		if (x >= 0 && y >= 0 && x < p->map.x && y < p->map.y && p->map.map[y][x] == 1)
			p->map.map[(int)floor(y)][(int)floor(x)] = 0;
	}
	movement(keycode, p);
	//p->ptr_img = mlx_new_image(p->mlx, SCREEN_X, SCREEN_Y);
	//p->img = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	//wolf3d(p);
	return (0);
}

int			hook(t_param *p)
{
	static int x = 0;

	printf("%d\n", x++);
	p->ptr_img = mlx_new_image(p->mlx, SCREEN_X, SCREEN_Y);
	p->img = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	wolf3d(p);
	return (0);
}
