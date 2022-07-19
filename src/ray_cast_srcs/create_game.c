/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:56:50 by ptopping          #+#    #+#             */
/*   Updated: 2022/07/19 16:38:00 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	init_player_data(t_data *data)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	data->player = (t_player *)malloc(sizeof(t_player));
// 	if (!data->player)
// 		ft_error("malloc error\n");
// 	while (data->map[y])
// 	{
		
// 	}
// 	ft_error("No players in the field");
// }

// void	scale_print(int x, int y, int colour)
// {
// 	int scale;
// 	scale = 1;
// 	while (scale <= MAP_SCALE)
// 	{
// 		my_mlx_pixel_put(data->image, point.x, point.y, 0xFFFFFF);
// 	}
// }

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
				//scale_print(point.x, point.y, 0xFFFFFF);
				my_mlx_pixel_put(data->image, (point.x * MAP_SCALE), (point.y * MAP_SCALE), 0xFFFFFF);
			point.x++;
		}
		point.y++;
		point.x = 0;
	}
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
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, &data->image->line_length,
								&data->image->endian);//достаем адрес изображения
	draw_screen(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
}