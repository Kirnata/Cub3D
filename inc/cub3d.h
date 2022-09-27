/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:53:40 by bpono             #+#    #+#             */
/*   Updated: 2022/09/27 20:33:54 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include "mlx.h"
# include "parser.h"
#include "types.h"
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

# define WIDTH 800
# define HEIGHT 500
# define MAP_INSIDE "0NSEW"


//init
void raycast_init(t_raycast *raycast);
void draw_limits_init(t_draw_limits *draw_limits);
void image_init(t_image *image);
//raycasting
int create_image(t_data *data, t_raycast *raycast);
void ray_culc(t_raycast *raycast, int x, t_player *player);
void    dirs_to_steps(t_raycast *raycast, t_player *player);
void perp_culc(t_raycast *raycast);
void    dda(t_data *data, t_raycast *raycast);
void    culc_draw_limits(t_data *data, t_raycast *raycast);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int line_render(t_data *data, int x);
int game(t_data *data);

#endif
