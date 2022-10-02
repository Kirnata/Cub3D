/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:33:15 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/02 20:36:41 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int game(t_data *data)
{
    data_init(data);
    data->mlx = mlx_init();//указатель который дальше запихивается в разные функции
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
    create_image(data);
    mlx_hook(data->win, 2, 0, key_press, data);
    mlx_hook(data->win, 3, 0, key_release, data);
    mlx_hook(data->win, ON_DESTROY, 0, exit_cleaner, data);//реализовать cleaner
    mlx_loop_hook(data->mlx, render_after_move, data);
    mlx_loop(data->mlx);
    return (0);
}
//крестик работает нормально