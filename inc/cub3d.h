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

# define WIDTH 1920
# define HEIGHT 1080

//super+pussy_parser
void	parsing(char **map);
char	*ft_new_strdup(char *src);
int		ft_error(char *name);
int		is_cubfile(char *file);

typedef struct t_parser
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceilling;
} s_parser;
typedef struct s_data
{
	char **map;
} t_data;

#endif
