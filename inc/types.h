/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:19:12 by ptopping          #+#    #+#             */
/*   Updated: 2022/11/10 18:32:35 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"
# include "parser.h"

/*
** Data
** img					— image identifier
** addr					— image
** bpp					— depth of image
** line_length			— number of bytes used to store one line of image
** endian				-little or big endian
** img_height			- height of image
** img_width			- width of image
*/

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}				t_image;

typedef struct s_point {
	double	x;
	double	y;
}				t_point;

/*
** Raycast
*/

/*
** map_x				- represent the current square of the map the ray is in
** map_y				- represent the current square of the map the ray is in
** step_x				- what direction to step in x-direction (either +1 or -1)
** step_y				- what direction to step in y-direction (either +1 or -1)
** side					- side of a wall
** tex_x				- x-coordinate of the texture
** tex_y				- y-coordinate of the texture
** perp_walldst			- perpendicular on the direction vector
** step					- ray step
** wall_x				- represents the exact value where the wall was hit
** tex_pos				- starting texture coordinate
** dir					- initial direction vector
** plane				- the 2d raycaster version of camera plane
** camera				- camera plane vector
** ray_dir				- ray direction
** delta_dist			- length of ray from one x or y-side to next x or y-side
** side_dist			- length of ray from current position to next x or y-side
*/

typedef struct s_raycast {
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		tex_x;
	int		tex_y;
	double	perp_walldst;
	double	step;
	double	wall_x;
	double	tex_pos;
	t_point	dir;
	t_point	plane;
	t_point	camera;
	t_point	ray_dir;
	t_point	delta_dist;
	t_point	side_dist;
}				t_raycast;

/*
** Player
** name				- the symbol of the player on the map, determines his initial direction
** move_key			- button click flag
** x				- start x-position of player
** y				- start y-position of player
*/

typedef struct s_player
{
	char		name;
	int			move_key;	
	double		x;
	double		y;
}	t_player;

/*
** Draw_limits
** line_height		- wall height at current x value
** draw_start		- the top edge of the wall at current x value
** draw_end			- the bottom edge of the wall at current x value
*/

typedef struct s_draw_limits
{
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_draw_limits;

/*
** Minimap
** minimap_x		- x-coordinate of the 2D map
** minimap_y		- y-coordinate of the 2D map
** minimap_scale	- map scale in relation to the base image size
** colour			- color of current coordinate in minimap
*/

typedef struct s_minimap
{
	int		minimap_x;
	int		minimap_y;
	int		minimap_scale;
	int		colour;
}				t_minimap;

/*
** Parser
** north			- north wall texture path
** south			- south wall texture path
** west				- west wall texture path
** east				- east wall texture path
** floor			- floor colour
** ceilling			- ceilling colour
*/

typedef struct s_parser
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceilling;
}	t_parser;

/*
** Textures
** txt_east			- east texture info
** txt_west			- west texture info
** txt_north		- north texture info
** txt_south		- south texture info
** 
*/

typedef struct s_textures
{
	t_image		*txt_east;
	t_image		*txt_west;
	t_image		*txt_north;
	t_image		*txt_south;
}				t_textures;

typedef struct s_data {
	void			*mlx;
	void			*win;
	char			**map;
	t_image			*image;
	t_player		*player;
	t_draw_limits	*draw_limits;
	t_raycast		*raycast;
	t_minimap		*minimap;
	t_parser		*xpms_path;
	t_textures		*txts;
}				t_data;

#endif