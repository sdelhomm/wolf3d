/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:10:29 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/12 16:24:08 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Vue deformee proche d'un mur quand on regarde vers le haut ou le bas
//MAIS : sur la demo des ressources du sujet il y a le meme soucis...

#ifndef WOLF3D_H
# define WOLF3D_H

# define SCREEN_X 1280
# define SCREEN_Y 900
# define CEIL 1
# define FLOOR 2
# define W 3
# define NORTH 4
# define SOUTH 5
# define WEST 6
# define EAST 7
# define END 10
# define HAMMER_WALL 12
# define SERPI 13
# define WALL 14
# define TAG 15
# define SPIKE 16
# define HB 0.3

# define FILE_NORTH "texture/Assembly.xpm"
# define FILE_SOUTH "texture/Evilmacs.xpm"
# define FILE_WEST "texture/Winanzi.xpm"
# define FILE_EAST "texture/niel_wall.xpm"
# define FILE_TAG "texture/Tag.xpm"
# define FILE_HAMMER "texture/fps_hammer.xpm"
# define FILE_HWALL "texture/hammer.xpm"
# define FILE_HWALL2 "texture/hammer2.xpm"
# define FILE_HWALL3 "texture/hammer3.xpm"
# define FILE_SERPI "texture/serpi_wall.xpm"
# define FILE_SERPI2 "texture/serpi_wall2.xpm"
# define FILE_WSERPI "texture/fps_serpi.xpm"
# define FILE_WALL "texture/Wall.xpm"
# define FILE_WEXIT "texture/end_door.xpm"
# define FILE_WEXIT2 "texture/o_end_door.xpm"
# define FILE_KEY "texture/key.xpm"
# define FILE_MENU "texture/menu.xpm"
# define FILE_TUTO "texture/tuto.xpm"
# define FILE_CURSOR "texture/cursor.xpm"
# define FILE_SPIKES "texture/spikes.xpm"
# define FILE_WIN "texture/win_screen.xpm"
# define FILE_LOSE "texture/die.xpm"

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <ApplicationServices/ApplicationServices.h>
# include <time.h>

typedef struct	s_player
{
	double	x;
	double	y;
	double	a;
	int		item;
	int		v;
}				t_player;

typedef struct	s_map
{
	int		x;
	int		y;
	int		**map;
}				t_map;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*ptr_img;
	void		*ptr_img2;
	void		*ptr_img3;
	void		*ptr_img4;
	void		*ptr_img5;
	void		*ptr_img6;
	void		*ptr_img7;
	void		*ptr_img8;
	void		*ptr_img9;
	char		*img;
	int			bpp;
	int			sl;
	int			end;
	double		pos;
	int			dir;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*weap;
	char		*weap2;
	char		*tag;
	char		*wall;
	char		*hwall;
	char		*hwall2;
	char		*hwall3;
	char		*swall;
	char		*swall2;
	char		*wexit;
	char		*wexit2;
	char		*spike;
	char		*key;
	char		*menu;
	char		*cursor;
	char		*tuto;
	char		*s_win;
	char		*lose;
	int			cursorState;
	int			menuState;
	int			wexitState;
	int			hwallState;
	int			exitKey;
	int			img_x;
	int			img_y;
	int			img_x2;
	int			img_y2;
	int			img_x3;
	int			img_y3;
	t_player	j;
	t_map		map;
	int			pos_x;
	int			pos_y;
	float		vy;
	int			lx;
	int			ly;
	double		wx;
	double		wy;
	double		ry;
	double		rx;
	int			tm;
	int			fps;
	int			time;
}				t_param;

int				get_map(char *file, t_map *map, t_player *j);
t_map			*map_len(char *file, t_map *map);
int				wolf3d(t_param *p, int fps, int time);
int				key_hook(int keycode, t_param *p);
int				mouse_hook(int x, int y, t_param *p);
int				draw_pixel(int x, int y, t_param *p, int color);
int				copy_pixel(int x, int y, int y_img, t_param *p);
int				hook(t_param *p);
int				events_mouse(int bc, int x, int y, t_param *p);
int				ft_exit(t_param *p);
int				ft_show_menu(t_param *p);
int				ft_death(t_param *p);
int				ft_win(t_param *p);

#endif
