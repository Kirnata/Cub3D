/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:50:55 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/16 21:36:41 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_RIGHT)
		data->player->move_key = KEY_RIGHT;
	if (keycode == KEY_LEFT)
		data->player->move_key = KEY_LEFT;
	if (keycode == KEY_W)
		data->player->move_key = KEY_W;
	if (keycode == KEY_S)
		data->player->move_key = KEY_S;
	if (keycode == KEY_A)
		data->player->move_key = KEY_A;
	if (keycode == KEY_D)
		data->player->move_key = KEY_D;
	if (keycode == MAP_PLUS)
		data->player->move_key = MAP_PLUS;
	if (keycode == MAP_MINUS)
		data->player->move_key = MAP_MINUS;
	if (keycode == ESC)
		data->player->move_key = ESC;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == data->player->move_key)
		data->player->move_key = -1;
	return (0);
}
