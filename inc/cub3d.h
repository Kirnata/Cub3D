#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
#include "get_next_line.h"
#include "../libft/libft.h"
// #include <X11/X.h>
// #include <X11/keysym.h>
//open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define WIDTH 640
# define HEIGHT 480

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

//координаты игрока и тд и тп
// typedef struct s_player {
// 	t_point pos;//x and y start position
// 	t_point dir;//initial direction vector
// 	t_point plane;//the 2d raycaster version of camera plane
// 	t_point plane;
// 	double time;//time of current frame
// 	double oldTime;//time of previous frame
// }				t_player;

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

typedef struct t_parser
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceilling;
} s_parser;

// typedef struct s_keys {
// 	//разные штучччччки
// }

typedef struct s_data {
	void *mlx;
	void *win;
	int		img_width;
	int		img_height;
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
void	parsing(char **map);
char	*ft_new_strdup(char *src);
int		ft_error(char *name);
int		is_cubfile(char *file);


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
