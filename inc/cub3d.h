/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:53:40 by bpono             #+#    #+#             */
/*   Updated: 2022/09/22 18:44:39 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include "mlx.h"
# include <math.h>
# include "get_next_line.h"
# include "../libft/libft.h"
//open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ESC 53

#define W 13
#define S 1
#define A 0
#define D 2

# define KEY_RIGHT 124
# define KEY_LEFT 123

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ON_DESTROY 17

# define MAP_SCALE 15

#define ROTATE_SPEED 0.05
#define MOVE_SPEED 0.1

# define WIDTH 1920
# define HEIGHT 1080
# define MAP_INSIDE "0NSEW"

typedef struct s_player
{
	char	name;
	int		x;
	int		y;
}	t_player;

typedef struct s_parser
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceilling;
	t_player	player;
}	t_parser;

typedef struct s_colour
{
	int	r;
	int	g;
	int	b;
}	t_colour;


typedef struct s_dick
{
	int	i;
	int	j;
	int	b;
}	t_dick;

typedef struct	s_point {
	double x;
	double y;
}				t_point;

//для конкретного изображения
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

//структурка для текстурок
// typedef struct s_textr {
// //очень много штук для текстурок
// }				t_textr;

typedef struct	s_game {
//много много всякой хуйни
	t_point	pos;//вектор позиции игрока
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
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	// double		rotSpeed;
	// double		moveSpeed;
	double			wall_x; // в какое место мы ударились
	double			step; // Насколько увеличить координату текстуры на пиксель экрана
}				t_game;

// typedef struct s_keys {
// 	//разные штучччччки
// }

typedef struct s_data {
	void *mlx;
	void *win;
	t_img	*img;
	t_game *game;
	char **map;
	//t_key		*keys;
	// t_textures	*north;
	// t_textures	*south;
	// t_textures	*west;
	// t_textures	*east;
}				t_data;

//super+pussy_parser
char	**parsing(char **map, t_parser *parser);
char	**get_file(char *map_name);
char	*ft_new_strdup(char *src);
int		ft_error(char *name);
int		is_cubfile(char *file);
int		is_xpmfile(char *file);
int		check_colours(char **map, t_parser *parser);
int		count_separators(char *line);
int		check_numbers(t_colour *colour);
void	put_numbers(t_colour *colour, t_parser *parser, char name);
int		check_textures(char **map, t_parser *parser);
int		save_textures(char **map, t_parser *parser);
int		check_open_textures(t_parser *parser);
char	**check_map(char **content, t_parser *parser);
int		check_probel(char **s, int len);
int		check_last(char **new_map, int len);
int		ft_get_len(int start, char **list);
int		get_start_index(char **s);
char	**ft_clear(char **name);
int		check_player(char **map, t_parser *parser);


//ray_cast_srcs
// void create_game(t_data *data);
// int	destroy(t_data *data);
// void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
// int	key_press(int key, t_data *data);
// void	init_player_data(t_data *data);
//void draw_screen(t_data *data);
// void	ft_draw_player(t_data *data);
// void	scale_print(t_img *image, int x, int y, int color);
// void start_game(t_data *data);
// void game_init(t_data *data);
// void player_init(t_data *data);
// void	check_player(char c, int fl);
int start_game(t_data *data);
int init_game(t_data *data);
//int render(t_data *data);
int draw_image(t_data *data);
int ft_steps(t_data *data, int x);
int dda(t_data *data);
int create_line(t_data *data, int x);
int draw_line(t_data *data, int x);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
#endif
