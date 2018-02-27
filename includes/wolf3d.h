/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:38:43 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/02/27 17:46:55 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Vue deformee proche d'un mur quand on regarde vers le haut ou le bas

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
# define O_END 11
# define HAMMER_WALL 12
# define SERPI 13
# define TAG 15
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
	char		*hwall;
	char		*hwall2;
	char		*hwall3;
	char		*swall;
	char		*swall2;
	int			hwallState;
	int			img_x;
	int			img_y;
	int			img_x2;
	int			img_y2;
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
}				t_param;

int				get_map(char *file, t_map *map, t_player *j);
t_map			*map_len(char *file, t_map *map);
int				wolf3d(t_param *p);
int				key_hook(int keycode, t_param *p);
int				mouse_hook(int x, int y, t_param *p);
int				draw_pixel(int x, int y, t_param *p, int color);
int				copy_pixel(int x, int y, int y_img, t_param *p);
int				hook(t_param *p);
int				events_mouse(int bc, int x, int y, t_param *p);

#endif
