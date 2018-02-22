/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:38:43 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/02/22 13:58:46 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define HAMMER 8
# define B_HAMMER 9
# define END 10
# define O_END 11
# define HB 0.3

# define FILE_NORTH "texture/Assembly.xpm"
# define FILE_SOUTH "texture/Evilmacs.xpm"
# define FILE_WEST "texture/Winanzi.xpm"
# define FILE_EAST "texture/Tag.xpm"

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
#include <ApplicationServices/ApplicationServices.h>

typedef struct	s_player
{
	double	x;
	double	y;
	double	a;
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
	int			img_x;
	int			img_y;
	t_player	j;
	t_map		map;
	int			pos_x;
	int			pos_y;
	int			lx;
	int			ly;
	float		vy;
}				t_param;

int				get_map(char *file, t_map *map, t_player *j);
t_map			*map_len(char *file, t_map *map);
int				wolf3d(t_param *p);
int				key_hook(int keycode, t_param *p);
int				mouse_hook(int x, int y, t_param *p);
int				draw_pixel(int x, int y, t_param *p, int color);
int				copy_pixel(int x, int y, int y_img, t_param *p);
int				hook(t_param *p);

#endif
