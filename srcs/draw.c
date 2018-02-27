/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:26:54 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/02/27 17:47:08 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		draw_pixel(int x, int y, t_param *p, int color)
{
	int		pos;

	if (x < 0 || y < 0 || x > SCREEN_X || y > SCREEN_Y)
		return (-1);
	pos = x * 4 + y * 4 * SCREEN_X;
	if (color == FLOOR)
	{
		p->img[pos] = (char)125;
		p->img[pos + 1] = (char)125;
		p->img[pos + 2] = (char)125;
	}
	if (color == CEIL)
	{
		p->img[pos] = (char)255;
		p->img[pos + 1] = (char)125;
		p->img[pos + 2] = (char)125;
	}
	return (0);
}

int		copy_pixel(int x, int y, int y_img, t_param *p)
{
	char	*img;
	int		pos;
	int		pos_img;

	if (x < 0 || y < 0 || x > SCREEN_X || y > SCREEN_Y || y_img < 0 ||
	(int)p->pos < 0 || (int)p->pos > p->img_x || y_img > p->img_y)
		return (-1);
	if (p->dir == NORTH || p->dir == W)
		img = p->north;
	if (p->dir == SOUTH)
		img = p->south;
	if (p->dir == EAST)
		img = p->east;
	if (p->dir == WEST)
		img = p->west;
	if (p->dir == HAMMER_WALL)
		img = p->hwall;
	if (p->dir == TAG)
		img = p->tag;
	if (p->dir == SERPI)
		img = p->swall;
	pos = x * 4 + y * 4 * SCREEN_X;
	pos_img = (int)p->pos * 4 + y_img * 4 * p->img_x;
	p->img[pos] = img[pos_img];
	p->img[pos + 1] = img[pos_img + 1];
	p->img[pos + 2] = img[pos_img + 2];
	p->img[pos + 3] = img[pos_img + 3];
	return (0);
}
