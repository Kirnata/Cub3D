#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
#include "get_next_line.h"
#include "../libft/libft.h"
//open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define WIDTH 640
# define HEIGHT 480

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
	char **map;
}				t_data;

//super+pussy_parser
void	parsing(char **map);
char	*ft_new_strdup(char *src);
int		ft_error(char *name);
int		is_cubfile(char *file);


//ray_cast_srcs
void *init_game_data(t_data *data);
#endif
