/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:53:40 by bpono             #+#    #+#             */
/*   Updated: 2022/10/13 20:46:09 by bpono            ###   ########.fr       */
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
# include "types.h"
# include <math.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ESC 53
# define ON_DESTROY 17
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define ROTATE_SPEED 0.05
# define MOVE_SPEED 0.1

# define WIDTH 800
# define HEIGHT 500
# define TEXWIDTH 64
# define TEXHEIGHT 64

# define COL_MINIMAP_WALL 0x00FFFFFF
# define COL_MINIMAP_SPACE 0x00FF6600
# define COL_MINIMAP_PL 0x0033FF00

//init
void	data_init(t_data *data);
void	structure_malloc(t_data *data);
void	raycast_init(t_raycast *raycast);
void	draw_limits_init(t_draw_limits *draw_limits);
void	image_init(t_image *image);
void	init_direction(t_point *dir, char name);
void	minimap_init(t_minimap *minimap);
//raycasting
void	create_image(t_data *data);
void	ray_culc(t_raycast *raycast, int x, t_player *player);
void	dirs_to_steps(t_raycast *raycast, t_player *player);
void	perp_culc(t_raycast *raycast);
void	dda(t_data *data);
void	culc_txt(t_raycast *raycast, t_player *player);
void	culc_draw_limits(t_data *data);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int		line_render(t_data *data, int x);
int		game(t_data *data);
int		render_after_move(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	check_move(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);
int		txt_init(t_data *data);
void	open_txt(void *mlx, t_image *txt, char *direction);
void	txt_loader(t_textures *txts, void *mlx, t_parser *xpms_path);
int		get_pixel_color(t_image *txt, int x, int y);

//minimap
void	draw_mini_map(t_data *data);
void	calc_map_scale(int *scale);
void	ft_scuare(t_data *data, char c, int x, int y);
void	put_colour(t_minimap *minimap, t_image *image);

//utls
int		exit_cleaner(t_data *data);

#endif
