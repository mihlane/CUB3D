/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:49:44 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/10 05:46:02 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "../Parsing/Parsing_Cub3d.h"

# define WALL_DIM 64

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 600

// SCREEN_WIDTH - 150 : Mini Map x
# define M_MPX 850

// SCREEN_HEIGHT - 150 : Mini Map y
# define M_MPY 450

// M_MPX + 75 : Mini Map Player X
# define M_MPPX 925

// M_MPY + 75 : Mini Map Player Y
# define M_MPPY 525

# define ESC 53

# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define MOUSE_EVENT 6
# define DESTROY_NOTIFY 17

# define REAL_WALL_HEIGHT 40000

# define SOUTH_VIEW 'S'
# define NORTH_VIEW 'N'
# define EAST_VIEW 'E'
# define WEST_VIEW 'W'

# define EMPTY '0'
# define WALL '1'
# define DOOR '2'

# define HORIZONTAL 1
# define VERTICAL 0

# define DOOR_OPEN_DIST 150

# define FOV 60.0
# define HFOV 30.0

# define PLAYER_WIDTH 7
# define M_H 8
# define M_W 48

# define ANIMATED_DOOR 4

# define SPEED 5.5
# define ROTATE_SPEED 0.045

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13

# define LEFT_VIEW 123
# define RIGHT_VIEW 124

# define AND &&
# define OR ||

# define DR 0.0174532925

// char **map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_data;

typedef struct s_door
{
	int		x;
	int		y;
	int		dd_animated;
	int		range;
}	t_door;

typedef struct s_player
{
	double	x;
	double	y;
	double	view_angle;
}	t_player;

typedef struct txt
{
	t_data	_w;
	t_data	_s;
	t_data	_e;
	t_data	_n;
}	t_txt;

typedef struct s_mouse
{
	int	curr_x;
	int	prev_x;
	int	valid;
}	t_mouse;

typedef struct raycast
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	h_x;
	double	h_y;
	double	h_dist;
	id_t	type_collision_h;
	double	v_x;
	double	v_y;
	double	v_dist;
	char	type_collision_v;
	double	ray_dist;
	char	type_collision;
	int		dir;
	t_data	*curr_txt;
}	t_raycast;

typedef struct s_game
{
	char		**map;
	double		dim_x;
	double		dim_y;
	int			map_width;
	int			map_height;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_game_win;
	int			keys[125];
	int			ceiling_color;
	int			floor_color;
	t_data		animated_door;
	t_door		*doors;
	t_door		*door_verti;
	t_door		*door_horizo;
	int			doors_size;
	int			dd_animated;
	char		*texters_path[4];
	t_mouse		mouse;
	t_data		mlx_game_img;
	t_player	p;
	t_txt		txt;
	t_raycast	cast;
}	t_game;

t_game			g_game;

//_________________________Prototypes______________________///

/////////////////////////////Init////////////////////////////

void			init_game(void);
void			init_player(int x, int y, char dir);
void			init_textures(void);
void			init_textures_adds(void);
void			init_textures_imgs(void);

////////////////////////////Update///////////////////////////

void			update_mouvement_vertical(double speed_sin, double speed_cos);
void			update_mouvement_horizontal(double speed_sin, double speed_cos);
void			update_mouvement(void);
void			update_view_angle(void);
int				update(void);

///////////////////Raycasting-Projection////////////////////

// - Find Distance

double			dist(double ax, double ay, double bx, double by);
void			find_horizontal_dist(void);
void			horizontal_dist(double ray_angle);
void			find_vertical_dist(void);
void			vertical_dist(double ray_angle);

// - Cast Rays

void			cast_rays_2d(int ray, double ray_angle);
void			raycasting(void);

// - Projection
void			project3d(double ray_angle, int ray);

// - Texture

void			get_texture_side(double ang);
void			project_texture(int px, double trn_of, double wall_h, int ray);

////////////////////////////Utils////////////////////////////

int				check_player_zone(void);
unsigned int	get_color(int x, int y);

double			min(double a, double b);
double			max(double a, double b);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			end_game_error(char *s);

////////////////////////////Events/////////////////////////////

int				key_press(int keycode);
int				key_release(int keycode);
int				mouse(int x, int y);
int				end_game(void);

void			mini_map(void);
void			init_door_animation(void);
void			animate(void);
t_door			*get_door(int x, int y);
void			count_doors(void);
void			init_doors(void);
int				player_zone(t_door *door);

///////////////////////////Parsing/////////////////////////////

t_cub			*parsing(int ac, char **av);

#endif