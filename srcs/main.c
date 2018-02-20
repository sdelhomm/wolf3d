/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:05:49 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/02/20 17:35:03 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_param	init(t_param p)
{
	p.lx = SCREEN_X / 2;
	p.ly = SCREEN_Y / 2;
	p.vy = 2;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, SCREEN_X, SCREEN_Y, "Wolf3D");
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_NORTH, &p.img_x, &p.img_y);
	p.north = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_SOUTH, &p.img_x, &p.img_y);
	p.south = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_WEST, &p.img_x, &p.img_y);
	p.west = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_EAST, &p.img_x, &p.img_y);
	p.east = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_new_image(p.mlx, SCREEN_X, SCREEN_Y);
	p.img = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	//CGDisplayHideCursor((CGDirectDisplayID)NULL);
	CGWarpMouseCursorPosition(CGPointMake(0, 0));
	return (p);
}

int		ft_exit(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	p;

	p.j.a = 1;
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./wolf3d [map]\n", 2);
		return (-1);
	}
	if (get_map(argv[1], map_len(argv[1], &p.map), &p.j) < 0 || p.j.a != 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	p = init(p);
	wolf3d(&p);
	mlx_loop_hook(p.mlx, hook, &p);
	mlx_hook(p.win, 6, 1L << 6, mouse_hook, &p);
	mlx_hook(p.win, 2, 3, key_hook, &p);
	mlx_hook(p.win, 17, 0, ft_exit, &p);
	mlx_loop(p.mlx);
	return (0);
}
