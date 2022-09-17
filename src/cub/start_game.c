/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:46:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/17 18:29:18 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int init_game(t_data *data)
{
    find_pos(data->map);//может в парсере установить сразу?//x and y start position
    data->dir.x = -1;//initial direction vector
    data->dir.y = 0;
    data->plane.x = 0;//the 2d raycaster version of camera plane
    data->plane.y = 0.66;
    
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
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, &data->image->line_length,
								&data->image->endian);//достаем адрес изображения
	//draw_image(data);отрисовываю картинку в первый раз
	//mlx_loop_hook(data->mlx, render, data);//здесь уже пересчитываю от координат, удаляю прошлое изображение и отрисовываю заново те draw_image в render
    //mlx_hook(raycast->win, 17, 0, ft_final_cleaner, data);
	mlx_loop(data->mlx);
}