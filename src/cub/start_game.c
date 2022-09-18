/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:46:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/18 19:50:41 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int init_game(t_data *data)
{
    find_pos(data->map);//может в парсере установить сразу?//x and y start position
    data->game->dir.x = -1;//initial direction vector
    data->game->dir.y = 0;
    data->game->plane.x = 0;//the 2d raycaster version of camera plane
    data->game->plane.y = 0.66;
    data->game->pos.x = 22;
    data->game->pos.y = 12;
    
}

int start_game(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
    
    if (!(data->game = (t_game *)malloc(sizeof(t_game))))
        ft_error("fatal error: malloc\n");
    if (!(data->image = (t_img *)malloc(sizeof(t_image))))
        ft_error("fatal error: malloc\n");
    data->mlx = mlx_init();//указатель который дальше запихивается в разные функции
    init_game(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	draw_image(data);//отрисовываю картинку в первый раз
	//mlx_loop_hook(data->mlx, render, data);//здесь уже пересчитываю от координат, удаляю прошлое изображение и отрисовываю заново те draw_image в render
    //mlx_hook(raycast->win, 17, 0, ft_final_cleaner, data);
	mlx_loop(data->mlx);
}