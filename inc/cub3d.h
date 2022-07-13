#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

//super+pussy_parser
int		parsing(int k, char *str);
char	*ft_new_strdup(char *src);
int		ft_error(char *name);
int		is_cubfile(char *file);

#endif CUB3D_H