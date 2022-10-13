/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:19:12 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/13 17:37:13 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"
# include "parser.h"

//для конкретного изображения
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_weight;
}				t_image;

typedef struct s_point {
	double	x;
	double	y;
}				t_point;

typedef struct s_raycast {
//много много всякой хуйни
	t_point	dir;//направление игрока
	t_point	plane;//плоскость камеры игрока(д.б. перпендикулярна dir)
	t_point	camera;//коорд  в прост кам
	t_point	ray_dir;
	t_point	delta_dist;// длина луча от одной стор  до след стор
	int		map_x;// в какой мы клеточке
	int		map_y;
	t_point	side_dist;//расст кот луч долж пройти от нач позиции до первой стор
	double	perp_walldst;//длина перпендикуляра к стене от камеры
	int		step_x;//в каком направлении делать шаг по оси x (либо +1, либо -1)
	int		step_y;//в каком направлении делать шаг по оси y (либо +1, либо -1)
	int		side;
	double	step; // Насколько увеличить координату текстуры на пиксель экрана
	double	wall_x;//where exactly the wall was hit в какое место мы ударились
	int		tex_x;//x coordinate on the texture
	int		tex_y;
	double	tex_pos;
	// int texY;//y coordinate on the texture
}				t_raycast;

typedef struct s_player
{
	char		name;
	double		x;//вектор позиции игрока
	double		y;
	int			move_key;
}	t_player;

typedef struct s_draw_limits
{
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_draw_limits;

typedef struct s_minimap
{
	int		minimap_x;
	int		minimap_y;
	int		minimap_scale;
	int		colour;
}				t_minimap;

typedef struct s_parser
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceilling;
}	t_parser;

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
	t_image			*image;
	t_player		*player;
	t_draw_limits	*draw_limits;
	t_raycast		*raycast;
	t_minimap		*minimap;
	char			**map;
	t_parser		*xpms_path;
	t_textures		*txts;
}				t_data;

#endif