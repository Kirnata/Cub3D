/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:19:12 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/02 22:55:48 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "cub3d.h"
#include "parser.h"

/*структурка для текстурок
typedef struct s_textr {
//очень много штук для текстурок
}				t_textr;
*/

/*
// typedef struct s_keys {
// 	//разные штучччччки
// }
*/

//для конкретного изображения
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_point {
	double x;
	double y;
}				t_point;

typedef struct	s_raycast {
//много много всякой хуйни
	t_point	dir;//направление игрока
	t_point	plane;//плоскость камеры игрока(д.б. перпендикулярна dir)
	t_point	camera;//коорд  в прост кам
	t_point	rayDir;
	t_point	deltaDist;// длина луча от одной стор  до след стор
	int		mapX;// в какой мы клеточке
	int		mapY;
	t_point	sideDist;//расст кот луч долж пройти от нач позиции до первой стор
	double	perpWallDist;//длина перпендикуляра к стене от камеры
	int		stepX;//в каком направлении делать шаг по оси x (либо +1, либо -1)
	int		stepY;//в каком направлении делать шаг по оси y (либо +1, либо -1)
	int		side;
	double			wall_x; // в какое место мы ударились
	double			step; // Насколько увеличить координату текстуры на пиксель экрана
}				t_raycast;

typedef struct s_player
{
	char	name;
	double		x;//вектор позиции игрока
	double		y;
	int		move_key;
}	t_player;

typedef struct	s_draw_limits
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}				t_draw_limits;

typedef struct	s_minimap
{
	int		minimap_x;
	int		minimap_y;
	int		minimap_scale;
	int		colour;
}				t_minimap;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_image	*image;
	t_player *player;
	t_draw_limits *draw_limits;
	t_raycast	*raycast;
	t_minimap *minimap;
	char **map;
	
}				t_data;

#endif