/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:08:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/20 22:41:31 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

int	key_press(int key, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	// if (key == W)
	// {
	// 	data->player->y += sin(data->player->dir) * 4;
	// 	data->player->x += cos(data->player->dir) * 4;
	// }
	// if (key == S)
	// {
	// 	data->player->y -= sin(data->player->dir) * 4;
	// 	data->player->x -= cos(data->player->dir) * 4;
	// }
	// if (key == A)
	// 	data->player->dir -= 0.1;
	// if (key == D)
	// 	data->player->dir += 0.1;
	if (key == W)
		data->player->y -= 1;
	if (key == S)
		data->player->y += 1;
	if (key == A)
		data->player->x -= 1;
	if (key == D)
		data->player->x += 1;
	if (key == ESC)
		destroy(data);
	draw_screen(data);
	return (0);
}