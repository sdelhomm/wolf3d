/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:43:32 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/02/22 13:52:32 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		set_direction(double x, double y, t_player j, t_map map)
{
	int dir;

	dir = 0;
	dir = (x == 0 || x == map.x || y == 0 || y == map.y ? W : dir);
	dir = (x == nearbyint(x) && x < j.x ? WEST : dir);
	dir = (x == nearbyint(x) && x > j.x ? EAST : dir);
	dir = (y == nearbyint(y) && y < j.y ? NORTH : dir);
	dir = (y == nearbyint(y) && y > j.y ? SOUTH : dir);
	if ((int)floor(x) >= 0 && (int)floor(y) >= 0 &&
		(int)floor(x) < map.x && (int)floor(y) < map.y)
	{
		dir = (map.map[(int)floor(y)][(int)floor(x)] == 2 ? HAMMER : dir);
		dir = (map.map[(int)floor(y)][(int)floor(x)] == 3 ? B_HAMMER : dir);
		dir = (map.map[(int)floor(y)][(int)floor(x)] == 4 ? END : dir);
		dir = (map.map[(int)floor(y)][(int)floor(x)] == 5 ? O_END : dir);
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
			p->map.map[(int)floor(y)][(int)floor(x)] != 1)
	{
		x += coefx / 500;
		y += coefy / 500;
	}
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
	p->dir = set_direction(x, y, j, p->map);
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
	mlx_destroy_image(p->mlx, p->ptr_img);
	return (0);
}
