/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:50:55 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/28 22:00:23 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, int *move_key)
{
	if (keycode == KEY_RIGHT)
		*move_key = KEY_RIGHT;
	else if (keycode == KEY_LEFT)
		*move_key = KEY_LEFT;
	else if (keycode == KEY_FORWARD)
		*move_key = KEY_FORWARD;
	else if (keycode == KEY_BACK)
		*move_key = KEY_BACK;
	else if (keycode == ESC)
		*move_key = ESC;
	return (0);
}

int	key_release(int keycode, int *move_key)
{
	if (keycode == *move_key)
		*move_key = 0;
	return (0);
}
