/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:33:08 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/12 16:25:08 by sdelhomm         ###   ########.fr       */
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

static int	check_spike(t_param *p, t_map map)
{
	int	x;
	int	y;

	x = floor(p->j.x);
	y = floor(p->j.y);
	if ((x >= 1 && map.map[y][x - 1] == 6) ||
		(y >= 1 && map.map[y - 1][x] == 6) ||
		(x < map.x - 1 && map.map[y][x + 1] == 6) ||
		(y < map.y - 1 && map.map[y + 1][x] == 6))
		return (0);
	return (1);
}

static int	check_collision(int kc, t_param *p, t_map map)
{
	double	x;
	double	y;
	double	a;

	x = p->j.x;
	y = p->j.y;
	a = p->j.a * M_PI / 180;
	a += (kc == 0 ? -M_PI_2 : 0);
	a += (kc == 2 ? M_PI_2 : 0);
	a += (kc == 1 ? M_PI : 0);
	x = x + HB * cos(a);
	y = y + HB * sin(a);
	if (kc >= 0 && kc <= 13 && x >= 0 && y >= 0 && x < map.x && y < map.y &&
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
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 6
		&& map.map[(int)floor(y)][(int)floor(x)] != 6 &&
		map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 8
		&& map.map[(int)floor(y)][(int)floor(x)] != 8)
	{
		p->j.x = p->j.x + 0.1 * cos(a);
		p->j.y = p->j.y + 0.1 * sin(a);
		return (check_spike(p, map));
	}
	return (1);
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
	//ft_putnbr(time(NULL) - p->tm); //INCROYABLE ... C'EST LE KEYCODE QUI EST AFFICHE ...
	//ft_putchar('\n');
	if (keycode == 126 && p->menuState == 1)
	{
		if (p->cursorState - 1 != 0)
			p->cursorState--;
		else
			p->cursorState = 3;
	}
	if (keycode == 125 && p->menuState == 1)
	{
		if (p->cursorState + 1 != 4)
			p->cursorState++;
		else
			p->cursorState = 1;
	}
	if (keycode == 36)
	{
		if (p->menuState == 1)
		{
			if (p->cursorState == 1)
			{
				p->tm = time(NULL);
				p->menuState = 0;
				p->cursorState = 0;
			}
			else if (p->cursorState == 2)
			{
				p->menuState = 2;
				p->cursorState = 0;
			}
			else if (p->cursorState == 3)
				ft_exit(p);
		}
		else if (p->menuState == 2 || p->menuState == 3)
		{
			p->menuState = 1;
			p->cursorState = 2;
		}
	}
	if (!check_collision(keycode, p, p->map))
		p->j.v = 0;
	return (0);
}

int			hook(t_param *p)
{
	static int	state = 1;
	static int	cfps = 0;
	static int	prevtime = 0;
	static int	fps = 0;
	
	cfps++;
	if (prevtime != time(NULL) - p->tm)
	{
		prevtime = time(NULL) - p->tm;
		fps = cfps;
		cfps = 0;
	}
	if (p->wy > SCREEN_Y * 0.535 && state == 1)
		state = -1;
	if (p->wy < SCREEN_Y * 0.465 && state == -1)
		state = 1;
	p->wy += state;
	p->wx += (double)state / 2;
	p->ptr_img = mlx_new_image(p->mlx, SCREEN_X, SCREEN_Y);
	p->img = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	wolf3d(p, fps, prevtime);
	return (0);
}
