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

typedef struct s_point {
	int x;
	int y;
}			t_point;

//для конкретного изображения
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

//структурка для текстурок
typedef struct s_textr {

}				t_textr;

//координаты игрока и тд и тп
typedef struct s_player {
	int x;
	int y;
	int dir;
}				t_player;

typedef struct t_parser
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceilling;
} s_parser;

typedef struct s_data {
	void *mlx;
	void *win;
	t_textr *textr;
	t_img	*image;
	t_player *player;
	char **map;
}				t_data;

//super+pussy_parser
void	parsing(char **map);
char	*ft_new_strdup(char *src);
int		ft_error(char *name);
int		is_cubfile(char *file);


//ray_cast_srcs
void create_game(t_data *data);
int	destroy(t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int	key_press(int key, t_data *data);
void	init_player_data(t_data *data);
void draw_screen(t_data *data);
void	ft_draw_player(t_data *data);
void	scale_print(t_img *image, int x, int y, int color);
#endif
