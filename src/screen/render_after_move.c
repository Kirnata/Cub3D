/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_after_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:54:08 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/16 21:54:02 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir;
	double	old_plane;

	old_dir = data->raycast->dir.x;
	old_plane = data->raycast->plane.x;
	data->raycast->dir.x = data->raycast->dir.x * cos(ROTATE_SPEED)
		- data->raycast->dir.y * sin(ROTATE_SPEED);
	data->raycast->dir.y = old_dir * sin(ROTATE_SPEED)
		+ data->raycast->dir.y * cos(ROTATE_SPEED);
	data->raycast->plane.x = data->raycast->plane.x * cos(ROTATE_SPEED)
		- data->raycast->plane.y * sin(ROTATE_SPEED);
	data->raycast->plane.y = old_plane * sin(ROTATE_SPEED)
		+ data->raycast->plane.y * cos(ROTATE_SPEED);
	//create_image(data);
}

void	rotate_right(t_data *data)
{
	double	old_dir;
	double	old_plane;

	old_dir = data->raycast->dir.x;
	old_plane = data->raycast->plane.x;
	data->raycast->dir.x = data->raycast->dir.x * cos(-ROTATE_SPEED)
		- data->raycast->dir.y * sin(-ROTATE_SPEED);
	data->raycast->dir.y = old_dir * sin(-ROTATE_SPEED)
		+ data->raycast->dir.y * cos(-ROTATE_SPEED);
	data->raycast->plane.x = data->raycast->plane.x * cos(-ROTATE_SPEED)
		- data->raycast->plane.y * sin(-ROTATE_SPEED);
	data->raycast->plane.y = old_plane * sin(-ROTATE_SPEED)
		+ data->raycast->plane.y * cos(-ROTATE_SPEED);
	//create_image(data);
}

int	render_after_move(t_data *data)
{
	if (data->player->move_key == KEY_W || data->player->move_key == KEY_S
		|| data->player->move_key == KEY_A || data->player->move_key == KEY_D)
		check_move(data);
	else if (data->player->move_key == KEY_RIGHT)
		rotate_right(data);
	else if (data->player->move_key == KEY_LEFT)
		rotate_left(data);
	else if (data->player->move_key == MAP_MINUS || data->player->move_key == MAP_PLUS)
		map_scaler(data->minimap, data->player->move_key);
	if (data->player->move_key == ESC)
		exit_cleaner(data);
	create_image(data);
	return (0);
}
