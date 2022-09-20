/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:36:39 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/20 23:40:53 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	check_player(char c, int fl)
// {
// 	if (c == 'N' && fl == 1)
// 		ft_error("ERROR!: double player\n");
// }

// void find_start_pos(t_data *data)
// {
//     while (data->map[point.y])
// 	{
// 		point.x = 0;
// 		while(data->map[point.y][point.x])
// 		{
// 			check_player(data->map[point.y][point.x], fl);
// 			if (data->map[point.y][point.x] == 'N')
// 			{
// 				data->player->pos.x = point.x;
// 				data->player->pos.y = point.y;
// 				fl = 1;
// 			}
// 			point.x++;
// 		}
// 		point.y++;
// 		point.x = 0;
// 	}
// 	if (fl == 0)
// 		ft_error("ERROR!: no player in the field\n");
// }

// void player_init(t_data *data)
// {
// 	int fl;
// 	t_point	point;
// 	ft_bzero(&point, sizeof(t_point));
// 	fl = 0;
// 	data->player = (t_player *)malloc(sizeof(t_player));
// 	if (!data->player)
// 		ft_error("malloc error\n");
//     data->player->dir.x = -1;
//     data->player->dir.y = 0;
//     data->player->plane.x = 0;
// 	data->player->plane.y = 0.66;
//     data->player->time = 0;
//     data->player->oldTime = 0;
// }

// void game_init(t_data *data)
// {
//     data->mlx = NULL;
// 	data->win = NULL;
// 	data->mlx = mlx_init();//указатель который дальше запихивается в разные функции
// 	if (!data->mlx)
// 		ft_error("mlx_init error\n");
// 	data->image = (t_img *)malloc(sizeof(t_img));
// 	if (!data->image)
// 		ft_error("malloc error\n");
//     player_init(data);
// }

// void start_game(t_data *data)
// {
//     game_init(data);
//     data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
//     data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
// 	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, &data->image->line_length,
// 								&data->image->endian);//достаем адрес изображения
// }