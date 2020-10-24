/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:05:07 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 13:49:55 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
**	BONUS define
**	Set game mode.
**	Without bonuses mode	- 0;
**	With bonuses mode		- 1;
*/

# define BONUS 0

# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

/*
**	Image structer.
**	Is used to contain information about one loaded image.
*/

typedef	struct	s_img
{
	void	*image;
	char	*img_addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

/*
**	Texture structer.
**	IS used in work with image.
*/

typedef	struct	s_tex
{
	t_img	img;
	int		width;
	int		height;
	double	offset;
	int		proj_copy;
	double	step;
	double	step_x;
	double	x_screen;
	double	y_screen;
	double	x_texture;
	double	y_texture;
}				t_tex;

/*
**	Map structer.
**	Is used to contain all information about map. Also contains minimap
**		parameters.
*/

typedef	struct	s_map
{
	int	x_scale;
	int	y_scale;
	int	scale;
	int	x_pos;
	int	y_pos;
	int	map_lines;
	int	map_colunms;
	int	block_size;
}				t_map;

/*
**	Sprite structer.
**	Is used to contain all information and parameters about one single sprite.
*/

typedef	struct	s_sprite
{
	char	type;
	double	x;
	double	y;
	double	z;
	double	depth;
	double	heigth;
	double	width;
	double	ch;
	double	cw;
	double	scale_x;
	double	scale_y;
	double	angle;
	double	dx;
	double	dy;
	double	gamma;
	double	theta;
	double	drays;
	double	ray;
	int		volume;
	int		a_tmp;
	int		a_speed;
	t_list	*a_buff;
}				t_sprite;

/*
**	Object structer.
**	Is used to contain all needed images and parameters about one object, what
**		means sprites of one type.
*/

typedef	struct	s_object
{
	t_tex		*tex;
	t_sprite	*pos;
	t_tex		*anim;
	int			quantity;
}				t_object;

/*
**	Background structer.
**	Is used to fit a large number of variables, used by floor drowing function.
*/

typedef	struct	s_flr_ceil
{
	double	floor_x;
	double	floor_y;
	double	dist_to_wall;
	double	screen_dist;
	int		lineheight;
	double	weight;
	double	screen_floor_x;
	double	screen_floor_y;
}				t_flr_ceil;

/*
**	Ray cast structer.
**	Is used to contain all needed parameters about one ray.
*/

typedef	struct	s_ray_cast
{
	char	type;
	double	current_angle;
	int		num_rays;
	double	wall_height;
	double	x;
	double	y;
	double	xh;
	double	yv;
	double	dx;
	double	dy;
	double	xm;
	double	ym;
	double	depth;
	double	depth_v;
	double	depth_h;
}				t_ray_cast;

/*
**	Buttons structer.
**	Is used to contain state off all used keys.
*/

typedef	struct	s_buttons
{
	int a;
	int s;
	int d;
	int w;
	int left;
	int right;
	int up;
	int down;
	int m;
	int	shift;
}				t_buttons;

/*
**	Player structer.
**	Is used to contain all player settings and parameters.
*/

typedef	struct	s_player
{
	double	angle;
	double	speed;
	double	cur_speed;
	double	fast_speed;
	double	button_angle_speed;
	double	mouse_angle_speed;
	double	radius;
	double	fov;
	int		num_rays;
	double	delta_angle;
	double	x;
	double	y;
}				t_player;

/*
**	Parser structer.
**	Is used by parser to contain all readed parameters from file.
*/

typedef	struct	s_pars
{
	int		r[2];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f[3];
	int		c[3];
	char	**map;
}				t_pars;

/*
**	Main structer.
**	All global parameters, like mlx pointers, game parameters, textures,
**		sprites, etc. are defined here. This structer is used almost
**		everywhere in program.
*/

typedef	struct	s_core
{
	t_pars		*params;
	int			save;
	void		*mlx;
	void		*window;
	t_ray_cast	*buffer;
	int			center_x;
	int			center_y;
	int			color;
	double		shadow;
	t_buttons	button;
	t_map		map;
	t_player	player;
	t_img		frame;
	t_tex		west;
	t_tex		north;
	t_tex		south;
	t_tex		east;
	t_tex		wall;
	t_tex		wall_dirty;
	t_tex		sky;
	t_tex		floor;
	t_tex		face;
	t_object	basic;
	t_object	devil;
	t_object	ghost;
	t_object	fire;
	t_object	barrel;
	t_object	pedestal;
	t_object	skull;
	t_object	**objects;
}				t_core;

/*
**	Main function - cub3d.
*/

int				cub3d(char *path, char *flag);

/*
**	Parser function.
**	This function checks given file for errors in parameters and creates
**		a structer with given game parameters and map.
*/

int				parser(char *path, t_pars *params);

/*
**	Initialization functions.
**	This functions are only called at the beggining of program execution.
*/
/*
**		init_pointers		- initializes all pointers used by program as NULL.
**		init_window			- calculates window parameters and creates the
**								system window.
**		init_game_settings	- calculates and set all needed game parameters,
**								such as:
**								* player's coordinates, angle, speed, FOV, etc;
**								* map block's size, quntity of map's colums
**									and lines;
**								* creates an array of structers, which will
**									contain parameters of every ray.
**		init_textures		- creates main frame image and load needed
**								texture images, like wall, sky and floor
**								textures, etc.
**		init_sprites		- calls the sprites initialization
**								functions (see below) and creates an array of
**								structers, containing links to all sprites.
*/

void			init_pointers(t_core *game);
void			init_window(t_core *game);
void			init_game_settings(t_core *game);
void			init_textures(t_core *game);
void			init_sprites(t_core *game);

/*
**		Seven functions below initialize all sprites, used by game, depending
**			on game mode.
**		Every function load images needed by each sprite, depending on
**			it's type and parameters, like standart view, animation, etc.
**		Also, this functions creates some arrays, depending on sprite needs:
**			* array of sprite basic view images, it can ba only one image,
**				or more, if sprite has a different view from several sides;
**			* array of spite animation images, if sprite has animation;
**			* array of sprites, containing sprite's parameters like sprite's
**				coordinates, size scale, animation speed, etc. Each element of
**				this array is one sprite;
**		Eventually, this functions set all sprite parameters.
*/

void			init_basic(t_core *game, char *path);
void			init_ghost(t_core *game, char *path);
void			init_devil(t_core *game, char *path);
void			init_fire(t_core *game, char *path);
void			init_barrel(t_core *game, char *path);
void			init_pedestal(t_core *game, char *path);
void			init_skull(t_core *game, char *path);

/*
**		init_minimap	- initialize minimap parameters, like position
**							on screen and scale.
*/

void			init_minimap(t_core *game);

/*
**		Functions below are secondary functions for init_ functions.
**		load_image				- load .xpm image from file system, set image
**									parameters and creates an array with it's
**									pixels.
**		init_a_buff				- initialize sprite's animation list's pointers
**									as NULL.
**		init_load_tex_images	- used for memory leak free loading and
**									initialization of many images. Using when
**									basic view images need to load.
**		init_load_anim_images	- same as previous function, but using when
**									animation images need to load.
**		create_anim_buff		- creates list of pointers to sprite's
**									animation images, which will be used
**									in animation drawing machanism. It is
**									some kind of queue, representing the
**									sequence of images, which are animation.
**		set_spr					- small function, that's set's one sprite
**									coordinates. Created for code reducrion.
**		place_on_map			- changes map's block type to another, setting
**									sprite on map by that.
*/

void			load_image(t_core *game, t_tex *texture, char *path);
void			init_a_buff(t_object *sprite, int quant);
void			init_load_tex_images(t_core *game, t_object *object, \
	char *path, int quantity);
void			init_load_anim_images(t_core *game, t_object *object, \
	char *path, int quantity);
void			create_anim_buff(t_core *game, t_tex *anim, t_list **a_buff, \
	int quant);
void			set_spr(t_sprite *sprite, double x, double y, double z);
void			place_on_map(t_core *game, double x, double y, char object);

/*
**	Handler function.
**	This function processes key presses and mouse moves.
*/

void			handler(t_core *game);

/*
**	Render function.
**	This function is colling in a loop and responsible for permanently
**		frame rendering and appearing of frame on the screen.
**	If needed, this function will not put any image to window, instead of this,
**		it will call a screenshot creating function and exit after.
**	This function contains some volume and complex functions, which will be
**		describe below.
*/

int				render(t_core *game);

/*
**	Player function, subfunction on Render function.
**	This function is responsible for player movement and collision with walls
**		and sprites.
*/

void			player(t_core *game);

/*
**	Back ground functions, subfunctions of Render function.
**	This functions draws background, depending on game mod.
**	set_back_colors - draw sky and groung using given color, gave in
**		parameters.
**	set_sky			- draw sky box using loaded seamless image.
*/

void			set_back_colors(t_core *game);
void			set_sky(t_core *game);

/*
**	Ray casting function, subfunction of Render function.
**	This function includes realization of DDA algoritm, counting the distance
**		to walls' stripes.
**	It creates a stucter element for each ray with all it's parameters and adds
**		it to the array with rays, created in the init_game_setting function
**		before.
*/

void			ray_casting(t_core *game);

/*
**	Make frame function, subfunction of Render function.
**	This function is responsible for creating frame. There several things going
**		on here, in turn:
**		1. creating two lists, first is list of walls, second is list of
**			sprites. These lists will be used to create queue of drawing.
**		2. calculating some parameters for all sprites.
**		3. finding visiable sprites for current player position and FOV.
**		4. using "z_boofer" algoritm draw walls and sprites.
**	Here is functions, used by make_frame function:
**		calc_sprites_params		- calculate sprite parameters, such as:
**			* distance to sprite;
**			* angle relative player to sprite;
**			* angle relative sprite to player;
**			* current postition of the sprite on the screen, which means ray.
**		find_visible_sprites	- determines if player can see sprite in his
**			position. If yes, function will add a link to this sprite to list
**			of sprites in descending order by distance to sprite.
**		sort_walls				- takes the array of walls, created in ray
**			casting function and adds links to list of walls in descending
**			order by distance to wall.
**	Next, the z_boofer function, which is not prototyped here, calling some
**		functions (see below) to draw walls and sprites in order of their
**		approach to the player, from most distant to most near objects.
**	Here is functions, used by z_boofer function:
**		set_floor_ceiling		- draws textured floor.
**		texture_wall			- draws textured wall stripe.
**		draw_sprite				- draws	needed sprite.
*/

void			make_frame(t_core *game);
void			calc_sprites_params(t_core *game, t_object *object);
void			find_visible_sprites(t_core *game, t_object *object, \
	t_list **sprites);
int				sort_walls(t_core *game, t_ray_cast **buffer, t_list **walls);
void			set_floor_ceiling(t_core *game, t_ray_cast *ray);
void			texture_wall(t_core *game, t_ray_cast *ray);
void			draw_sprite(t_core *game, t_sprite *sprite);

/*
**	Minimap function, subfunction of Render function.
**	This function draws minimap with player on his current position.
*/

int				minimap(t_core *game);

/*
**	Functions below are using by different functions in the project.
**	set_pixel		- changes needed pixel of frame, using color of needed
**						pixel in given image. This function use function
**						make_darker (see below) to make color darker
**						depending on distance to drawing object.
**	make_darker		- takes the color in RGB format and returns it's
**						darker version depending on depth parameter.
**	object_check	- trying to find an object of the specified type on the
**						specified coordinates of map. If object was found
**						on these coordinates, function returns 1, else 0.
*/

void			set_pixel(t_core *game, t_tex *texture, double depth);
int				make_darker(double depth, int r, int g, int b);
int				object_check(t_core *game, double x, double y, char object);

/*
**	Functions below are using by many different functions to treat errors.
**	There will be no detailed description for this functions. All of them
**		prints error massage on the terminal and exit the program safely,
**		without memory leaks.
*/

void			error_creation_window(t_core *game);
void			error_mlx_init(t_core *game);
void			error_malloc_buffer(t_core *game);
void			error_creation_frame_image(t_core *game);
void			error_open_xpm_file(t_core *game, char *path);
void			error_malloc(t_core *game);
void			error_newlst(t_core *game, t_list **list);
void			error_newlsts(t_core *game, t_list **list_1, t_list **list_2);
void			error_creating_file(t_core *game, unsigned char **memory);

/*
**	Functions below are using by error functions and some else in project
**	free_lst		- apply free function to every element of given list.
**						NOTE: this function frees ONLY list's elemnts, not
**						their content.
**	free_structer	- frees structer with game parameters, created by parser
**						function.
**	free_images		- frees memory used to contain frame and texture's images.
**	free_sprites	- frees memory used to contain all sprites, including
**						sprites' animation buffers, etc.
**	exit_cub3d		- realize clean exit from program, without memory leaks.
*/

void			free_lst(t_list **lst);
int				free_structer(t_pars *params);
void			free_images(t_core *game);
void			free_sprites(t_core *game);
int				exit_cub3d(t_core *game);

#endif
