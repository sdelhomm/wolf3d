/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:43:32 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/03/11 15:16:28 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

int		set_direction(double x, double y, t_player j, t_param *p)
{
	int dir;

	dir = 0;
	dir = (x == 0 || x == p->map.x || y == 0 || y == p->map.y ? W : dir);
	dir = (x == nearbyint(x) && x < j.x ? WEST : dir);
	dir = (x == nearbyint(x) && x > j.x ? EAST : dir);
	dir = (y == nearbyint(y) && y < j.y ? NORTH : dir);
	dir = (y == nearbyint(y) && y > j.y ? SOUTH : dir);
	if ((int)floor(p->rx) >= 0 && (int)floor(p->ry) >= 0 &&
		(int)floor(p->rx) < p->map.x && (int)floor(p->ry) < p->map.y)
	{
		dir = (p->map.map[(int)floor(p->ry)][(int)floor(p->rx)] == 2 ? HAMMER_WALL : dir);
		dir = (p->map.map[(int)floor(p->ry)][(int)floor(p->rx)] == 3 ? TAG : dir);
		dir = (p->map.map[(int)floor(p->ry)][(int)floor(p->rx)] == 4 ? SERPI : dir);
		dir = (p->map.map[(int)floor(p->ry)][(int)floor(p->rx)] == 5 ? WALL : dir);
		dir = (p->map.map[(int)floor(p->ry)][(int)floor(p->rx)] == 8 ? END : dir);
	}
	return (dir);
}

double	raycast(double coefx, double coefy, t_player j, t_param *p)
{
	double	x;
	double	y;

	x = j.x;
	y = j.y;
	while (x >= 0 && y >= 0 && x < p->map.x && y < p->map.y &&
			p->map.map[(int)floor(y)][(int)floor(x)] != 1 &&
			p->map.map[(int)floor(y)][(int)floor(x)] != 2 &&
			p->map.map[(int)floor(y)][(int)floor(x)] != 3 &&
			p->map.map[(int)floor(y)][(int)floor(x)] != 4 &&
			p->map.map[(int)floor(y)][(int)floor(x)] != 5 &&
			p->map.map[(int)floor(y)][(int)floor(x)] != 8)
	{
		x += coefx / 500;
		y += coefy / 500;
	}
	p->rx = x;
	p->ry = y;
	if (nearbyint(x) + 0.01 >= x && nearbyint(x) - 0.01 <= x)
	{
		x = nearbyint(x);
		p->pos = y - floor(y);
	}
	if (nearbyint(y) + 0.01 >= y && nearbyint(y) - 0.01 <= y)
	{
		p->pos = x - floor(x);
		y = nearbyint(y);
	}
	p->dir = set_direction(x, y, j, p);
	return (sqrt(pow(x - j.x, 2) + pow(y - j.y, 2)));
}

void	draw_column(double d, t_param *p, int x)
{
	int		y;
	double	y_img;

	d = SCREEN_Y / d;
	y = (floor(p->vy - d / 2) < 0 ? floor(p->vy - d / 2) : 0);
	while (y < floor(p->vy - d / 2))
		draw_pixel(x, y++, p, CEIL);
	y_img = 0;
	p->pos = p->pos * (double)p->img_x;
	while (y < SCREEN_Y && y < floor(p->vy + d / 2))
	{
		copy_pixel(x, y++, (int)floor(y_img), p);
		y_img += (p->img_y / d);
	}
	while (y < SCREEN_Y)
		draw_pixel(x, y++, p, FLOOR);
}

int		wolf3d(t_param *p)
{
	double	a;
	double	d;
	int		x;

	a = p->j.a - 30;
	x = 0;
	while (x < SCREEN_X)
	{
		if (a > 360 || a < -360)
			a = copysign(fabsl(a) - 360, a);
		d = raycast(cos(a * M_PI / 180), sin(a * M_PI / 180), p->j, p);
		d *= cos((a - p->j.a) * M_PI / 180);
		draw_column(d, p, x++);
		a += ((double)60 / (double)SCREEN_X);
	}
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	if (p->j.item == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img2, p->wx, p->wy);
	if (p->j.item == 2)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img3, p->wx, p->wy);
	if (p->exitKey == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_img4,
			SCREEN_X * 0.05, SCREEN_Y * 0.05);
	//show_menu(p);
	mlx_destroy_image(p->mlx, p->ptr_img);
	return (0);
}
