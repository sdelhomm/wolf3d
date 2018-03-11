/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:37:52 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/11 13:07:00 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		events_mouse(int bc, int x, int y, t_param *p)
{
	if (bc == 1)
	{
		x = (int)floor(p->j.x + 0.5 * cos(p->j.a * M_PI / 180));
		y = (int)floor(p->j.y + 0.5 * sin(p->j.a * M_PI / 180));
		if (x >= 0 && y >= 0 &&
			x < p->map.x && y < p->map.y && p->map.map[y][x] == 1 && p->j.item == 1)
			p->map.map[(int)floor(y)][(int)floor(x)] = 0;
		else if (x >= 0 && y >= 0 &&
			x < p->map.x && y < p->map.y && p->map.map[y][x] == 3 && p->j.item == 2)
		{
			p->map.map[(int)floor(y)][(int)floor(x)] = 5;
			if (!(ft_intchr(p->map.map, 3, p->map.x, p->map.y)))
				p->exitKey = 1;
		}
	}
	return (0);
}

static void	check_collision(int kc, t_param *p, t_map map)
{
	double	x;
	double	y;
	double	a;

	x = p->j.x;
	y = p->j.y;
	a = p->j.a * M_PI / 180;
	a += (kc == 123 ? -M_PI_2 : 0);
	a += (kc == 124 ? M_PI_2 : 0);
	a += (kc == 125 ? M_PI : 0);
	x = x + HB * cos(a);
	y = y + HB * sin(a);
	if (kc >= 123 && kc <= 126 && x >= 0 && y >= 0 && x < map.x && y < map.y &&
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 1
		&& map.map[(int)floor(y)][(int)floor(x)] != 1 &&
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 2
		&& map.map[(int)floor(y)][(int)floor(x)] != 2 &&
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 3
		&& map.map[(int)floor(y)][(int)floor(x)] != 3 &&
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 4
		&& map.map[(int)floor(y)][(int)floor(x)] != 4 &&
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 5
		&& map.map[(int)floor(y)][(int)floor(x)] != 5 &&
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 8
		&& map.map[(int)floor(y)][(int)floor(x)] != 8)
	{
		p->j.x = p->j.x + 0.1 * cos(a);
		p->j.y = p->j.y + 0.1 * sin(a);
	}
}

int			mouse_hook(int x, int y, t_param *p)
{
	if (!p->pos_x)
	{
		p->pos_x = abs(x);
		p->pos_y = abs(y);
	}
	if (x < p->lx)
		p->j.a -= 2.5;
	if (x > p->lx)
		p->j.a += 2.5;
	if (y < p->ly && p->vy < SCREEN_Y * 2)
		p->vy += 20;
	if (y > p->ly && p->vy > -SCREEN_Y)
		p->vy -= 20;
	if (x <= 5 || x >= SCREEN_X - 5 || y <= 5 || y >= SCREEN_Y - 5)
	{
		CGWarpMouseCursorPosition(CGPointMake(SCREEN_X / 2 + p->pos_x, SCREEN_Y / 2 + p->pos_y));
		p->lx = SCREEN_X / 2 - p->pos_x;
		p->ly = SCREEN_Y / 2 - p->pos_y;
	}
	else
	{
		p->lx = x;
		p->ly = y;
	}
	return (0);
}

int			key_hook(int keycode, t_param *p)
{
	int x;
	int y;
	//struct tm tm;
	if (keycode == 53)
		exit(0);
	if (keycode == 14)
	{
		x = (int)floor(p->j.x + 0.5 * cos(p->j.a * M_PI / 180));
		y = (int)floor(p->j.y + 0.5 * sin(p->j.a * M_PI / 180));
		if (p->map.map[y][x] == 2)
		{
			if (p->hwallState == 0)
			{
				p->hwallState = 1;
				p->hwall = p->hwall2;
			}
			else if (p->hwallState == 1)
			{
				p->j.item = 1;
				p->hwall = p->hwall3;
				p->hwallState = 2;
			}
		}
		else if (p->map.map[y][x] == 4)
		{
			p->j.item = 2;
			p->swall = p->swall2;
		}
		else if (p->map.map[y][x] == 8 && p->exitKey == 1)
		{
			if (p->wexitState == 0)
			{
				p->wexit = p->wexit2;
				p->wexitState = 1;
			}
			else if (p->wexitState == 1)
				ft_exit(p);
		}
	}
	//ft_putnbr(tm.tm_sec); //INCROYABLE ... C'EST LE KEYCODE QUI EST AFFICHE ...
	//ft_putchar('\n');               
	check_collision(keycode, p, p->map);
	return (0);
}

int			hook(t_param *p)
{
	static int state = 1;

	if (p->wy > SCREEN_Y * 0.535 && state == 1)
		state = -1;
	if (p->wy < SCREEN_Y * 0.465 && state == -1)
		state = 1;
	p->wy += state;
	p->wx += (double)state / 2;
	p->ptr_img = mlx_new_image(p->mlx, SCREEN_X, SCREEN_Y);
	p->img = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	wolf3d(p);
	return (0);
}
