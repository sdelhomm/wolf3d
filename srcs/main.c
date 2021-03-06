/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:01:10 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/13 18:08:23 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_param	init_value(t_param p)
{
	p.j.a = 0;
	p.j.item = 0;
	p.hwallState = 0;
	p.wexitState = 0;
	p.exitKey = 0;
	p.tm = time(NULL);
	p.lx = SCREEN_X / 2;
	p.ly = SCREEN_Y / 2;
	p.vy = SCREEN_Y / 2;
	p.wx = SCREEN_X * 0.5;
	p.wy = SCREEN_Y * 0.5;
	p.cursorState = 1;
	p.clean_tag = 0;
	return (p);
}

t_param	init(t_param p)
{
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_NORTH, &p.img_x, &p.img_y);
	p.north = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_SOUTH, &p.img_x, &p.img_y);
	p.south = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_WEST, &p.img_x, &p.img_y);
	p.west = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_EAST, &p.img_x, &p.img_y);
	p.east = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_TAG, &p.img_x, &p.img_y);
	p.tag = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_HWALL, &p.img_x, &p.img_y);
	p.hwall = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_HWALL2, &p.img_x, &p.img_y);
	p.hwall2 = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_HWALL3, &p.img_x, &p.img_y);
	p.hwall3 = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_SERPI, &p.img_x, &p.img_y);
	p.swall = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_SERPI2, &p.img_x, &p.img_y);
	p.swall2 = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_WALL, &p.img_x, &p.img_y);
	p.wall = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_WEXIT, &p.img_x, &p.img_y);
	p.wexit = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_WEXIT2, &p.img_x, &p.img_y);
	p.wexit2 = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_xpm_file_to_image(p.mlx, FILE_SPIKES, &p.img_x, &p.img_y);
	p.spike = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	p.ptr_img2 = mlx_xpm_file_to_image(p.mlx, FILE_HAMMER, &p.img_x2, &p.img_y2);
	p.weap = mlx_get_data_addr(p.ptr_img2, &p.sl, &p.end, &p.bpp);
	p.ptr_img3 = mlx_xpm_file_to_image(p.mlx, FILE_WSERPI, &p.img_x2, &p.img_y2);
	p.weap2 = mlx_get_data_addr(p.ptr_img3, &p.sl, &p.end, &p.bpp);
	p.ptr_img4 = mlx_xpm_file_to_image(p.mlx, FILE_KEY, &p.img_x3, &p.img_y3);
	p.key = mlx_get_data_addr(p.ptr_img4, &p.sl, &p.end, &p.bpp);
	p.ptr_img5 = mlx_xpm_file_to_image(p.mlx, FILE_MENU, &p.img_x3, &p.img_y3);
	p.menu = mlx_get_data_addr(p.ptr_img5, &p.sl, &p.end, &p.bpp);
	p.ptr_img6 = mlx_xpm_file_to_image(p.mlx, FILE_TUTO, &p.img_x3, &p.img_y3);
	p.tuto = mlx_get_data_addr(p.ptr_img6, &p.sl, &p.end, &p.bpp);
	p.ptr_img7 = mlx_xpm_file_to_image(p.mlx, FILE_CURSOR, &p.img_x3, &p.img_y3);
	p.cursor = mlx_get_data_addr(p.ptr_img7, &p.sl, &p.end, &p.bpp);
	p.ptr_img8 = mlx_xpm_file_to_image(p.mlx, FILE_WIN, &p.img_x3, &p.img_y3);
	p.s_win = mlx_get_data_addr(p.ptr_img8, &p.sl, &p.end, &p.bpp);
	p.ptr_img9 = mlx_xpm_file_to_image(p.mlx, FILE_LOSE, &p.img_x3, &p.img_y3);
	p.lose = mlx_get_data_addr(p.ptr_img9, &p.sl, &p.end, &p.bpp);
	p.ptr_img10 = mlx_xpm_file_to_image(p.mlx, FILE_SLOT, &p.img_x3, &p.img_y3);
	p.slot = mlx_get_data_addr(p.ptr_img10, &p.sl, &p.end, &p.bpp);
	p.ptr_img11 = mlx_xpm_file_to_image(p.mlx, FILE_SLOT_HAMMER, &p.img_x3, &p.img_y3);
	p.slot_hammer = mlx_get_data_addr(p.ptr_img11, &p.sl, &p.end, &p.bpp);
	p.ptr_img12 = mlx_xpm_file_to_image(p.mlx, FILE_SLOT_SERPI, &p.img_x3, &p.img_y3);
	p.slot_serpi = mlx_get_data_addr(p.ptr_img12, &p.sl, &p.end, &p.bpp);
	p.ptr_img13 = mlx_xpm_file_to_image(p.mlx, FILE_SLOT2, &p.img_x3, &p.img_y3);
	p.slot2 = mlx_get_data_addr(p.ptr_img13, &p.sl, &p.end, &p.bpp);
	p.ptr_img = mlx_new_image(p.mlx, SCREEN_X, SCREEN_Y);
	p.img = mlx_get_data_addr(p.ptr_img, &p.sl, &p.end, &p.bpp);
	if (FMOD_System_CreateSound(p.s.system, FILE_WASH, FMOD_CREATESAMPLE, 0, &p.s.wash)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_APPLAUSE, FMOD_CREATESAMPLE, 0, &p.s.applause)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_DOOR, FMOD_CREATESAMPLE, 0, &p.s.door_open)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_GLASS, FMOD_CREATESAMPLE, 0, &p.s.glass_break)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_GRAB, FMOD_CREATESAMPLE, 0, &p.s.grab)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_PIANO, FMOD_CREATESAMPLE, 0, &p.s.piano)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_SPIKES_S, FMOD_CREATESAMPLE, 0, &p.s.spikes_sound)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_WALL_FALL, FMOD_CREATESAMPLE, 0, &p.s.wall_fall)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_TIC, FMOD_CREATESAMPLE, 0, &p.s.tic)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	if (FMOD_System_CreateSound(p.s.system, FILE_WRONG, FMOD_CREATESAMPLE, 0, &p.s.wrong)
		!= FMOD_OK)
	{
		ft_putstr_fd("Sound error\n", 2);
		ft_exit(&p);
	}
	return (init_value(p));
}

int		ft_exit(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	free_map(p->map);
	FMOD_Sound_Release(p->s.wash);
	//FMOD_System_Close(system);
	//FMOD_System_Release(system);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	p;

	p.arg1 = argv[1];
	p.j.a = 1;
	p.tags = 0;
	p.menuState = 1;
	p.pos_x = 0;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, SCREEN_X, SCREEN_Y, "Wolf3D");
	CGWarpMouseCursorPosition(CGPointMake(0, 0));
	CGDisplayHideCursor((CGDirectDisplayID)NULL);
	FMOD_System_Create(&p.s.system);
	FMOD_System_Init(p.s.system, 10, FMOD_INIT_NORMAL, NULL);
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./wolf3d [map]\n", 2);
		return (-1);
	}
	if (get_map(p.arg1, map_len(p.arg1, &p.map), &p.j, &p) < 0 || p.j.a != 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	p = init(p);
	wolf3d(&p, 0, 0);
	mlx_loop_hook(p.mlx, hook, &p);
	mlx_hook(p.win, 6, 1L << 6, mouse_hook, &p);
	mlx_hook(p.win, 2, 3, key_hook, &p);
	mlx_mouse_hook(p.win, events_mouse, &p);
	mlx_hook(p.win, 17, 0, ft_exit, &p);
	mlx_loop(p.mlx);
	return (0);
}
