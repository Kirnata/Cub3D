/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:56:50 by ptopping          #+#    #+#             */
/*   Updated: 2022/07/21 17:56:49 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_player(char c, int fl)
{
	if (c == 'N' && fl == 1)
		ft_error("ERROR!: double player\n");
}

void	init_player_data(t_data *data)
{
	int fl;
	t_point	point;
	ft_bzero(&point, sizeof(t_point));
	fl = 0;
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
		ft_error("malloc error\n");
	while (data->map[point.y])
	{
		point.x = 0;
		while(data->map[point.y][point.x])
		{
			check_player(data->map[point.y][point.x], fl);
			if (data->map[point.y][point.x] == 'N')
			{
				data->player->x = point.x;
				data->player->y = point.y;
				data->player->dir = 0;
				fl = 1;
			}
			point.x++;
		}
		point.y++;
		point.x = 0;
	}
	if (fl == 0)
		ft_error("ERROR!: no player in the field\n");
}

void	scale_print(t_img *image, int x, int y, int color)
{
	int x_stop;
	int y_stop;
	
	x *= MAP_SCALE;
	y *= MAP_SCALE;
	x_stop = x + MAP_SCALE;
	y_stop = y + MAP_SCALE;
	while (y < y_stop)
	{
		while (x < x_stop) {
			my_mlx_pixel_put(image, x, y, color);
			x++;
		}
		x -= MAP_SCALE;
		y++;
	}
}

void	ft_draw_player(t_data *data)
{
	t_player plr = *data->player;
	while (data->map[(int)plr.y / MAP_SCALE][(int)plr.x / MAP_SCALE] != '1')
	{
		plr.x += cos(plr.dir);
		plr.y += sin(plr.dir);
		my_mlx_pixel_put(data->win, plr.x, plr.y, 0x990099);
	}
}

void draw_screen(t_data *data)
{
	t_point	point;
	ft_bzero(&point, sizeof(t_point));
	while (data->map[point.y])
	{
		point.x = 0;
		while(data->map[point.y][point.x])
		{
			if (data->map[point.y][point.x] == '1')
				scale_print(data->image, point.x, point.y, 0xFFFFFF);
			else if (data->map[point.y][point.x] != '\n')
				scale_print(data->image, point.x, point.y, 0x002000);
			if (point.x == data->player->x && point.y == data->player->y)
				scale_print(data->image, point.x, point.y, 0x006000);
				
			point.x++;
		}
		point.y++;
		point.x = 0;
	}
	ft_draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	//mlx_destroy_image(data->win, data->image);
}

void	create_game(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	
	data->mlx = mlx_init();//указатель который дальше запихивается в разные функции
	if (!data->mlx)
		ft_error("mlx_init error\n");
	data->image = (t_img *)malloc(sizeof(t_img));
	if (!data->image)
		ft_error("malloc error\n");
	init_player_data(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, &data->image->line_length,
								&data->image->endian);//достаем адрес изображения
}