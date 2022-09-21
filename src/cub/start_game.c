/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:46:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/21 15:54:53 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_game(t_data *data)
{
    data->mlx = NULL;
	data->win = NULL;
    data->img->addr = NULL;
    data->img->bits_per_pixel = 0;
    data->img->endian = 0;
    data->img->line_length = 0;
    data->game->pos.x = 11;
    data->game->pos.y = 23;    
    data->game->dir.x = -1;//initial direction vector
    data->game->dir.y = 0;
    data->game->plane.x = 0;//the 2d raycaster version of camera plane
    data->game->plane.y = 0.66;
    data->game->camera.x = 0;
    data->game->camera.y = 0;
    data->game->rayDir.x = 0;
    data->game->deltaDist.x = 0;
    data->game->deltaDist.y = 0;
    data->game->mapX = data->game->pos.x;
    data->game->mapY = data->game->pos.x;
    data->game->sideDist.x = 0;
    data->game->sideDist.y = 0;
    data->game->perpWallDist = 0;
    data->game->stepX = 0;
    data->game->stepY = 0;
    data->game->hit = 0;
    data->game->side = 0;
    data->game->lineHeight = 0;
    data->game->drawStart = 0;
    data->game->drawEnd = 0;
    data->game->wall_x = 0;
    data->game->step = 0;
    return (0);
}

int start_game(t_data *data)
{
	
    
    if (!(data->game = (t_game *)malloc(sizeof(t_game))))
        ft_error("fatal error: malloc\n");
    if (!(data->img = (t_img *)malloc(sizeof(t_img))))
        ft_error("fatal error: malloc\n");
    init_game(data);
    data->mlx = mlx_init();//указатель который дальше запихивается в разные функции
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	draw_image(data);//отрисовываю картинку в первый раз
	// //mlx_loop_hook(data->mlx, render, data);//здесь уже пересчитываю от координат, удаляю прошлое изображение и отрисовываю заново те draw_image в render
    // //mlx_hook(raycast->win, 17, 0, ft_final_cleaner, data);
	mlx_loop(data->mlx);
    return (0);
}