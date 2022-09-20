/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:46:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/21 00:18:17 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_game(t_data *data)
{
    data->game->dir.x = -1;//initial direction vector
    data->game->dir.y = 0;
    data->game->plane.x = 0;//the 2d raycaster version of camera plane
    data->game->plane.y = 0.66;
    // printf("data->game->pos.x  %f\n", data->game->pos.x);
    // printf("data->game->pos.y  %f\n", data->game->pos.y);
    // exit(0);
    data->game->pos.x = 18;
    data->game->pos.y = 4;
    data->game->mapX = data->game->pos.x;
    data->game->mapY = data->game->pos.y;
    return (0);
}

int start_game(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
    
    if (!(data->game = (t_game *)malloc(sizeof(t_game))))
        ft_error("fatal error: malloc\n");
    if (!(data->img = (t_img *)malloc(sizeof(t_img))))
        ft_error("fatal error: malloc\n");
    data->mlx = mlx_init();//указатель который дальше запихивается в разные функции
    init_game(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	draw_image(data);//отрисовываю картинку в первый раз
	// //mlx_loop_hook(data->mlx, render, data);//здесь уже пересчитываю от координат, удаляю прошлое изображение и отрисовываю заново те draw_image в render
    // //mlx_hook(raycast->win, 17, 0, ft_final_cleaner, data);
	mlx_loop(data->mlx);
    return (0);
}