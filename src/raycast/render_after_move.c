/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_after_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:54:08 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/28 21:58:33 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_move(int keycode, t_data *data)
{
	//move forward if no wall in front of you
	// if (data->player->move_key == KEY_W)
	if (keycode == KEY_W)
	{
		if (data->map[(int)(data->player->x + data->raycast->dir.x * data->raycast->moveSpeed)][(int)(data->player->y)] == '0')
			data->player->x += data->raycast->dir.x * data->raycast->moveSpeed;
		if (data->map[(int)(data->player->x)][(int)(data->player->y + data->raycast->dir.y * data->raycast->moveSpeed)] == '0')
			data->player->x += data->raycast->dir.x * data->raycast->moveSpeed;
	}
	//move backwards if no wall behind you
	// else if (data->player->move_key == KEY_S)
	else if (keycode == KEY_S)
	{
		if (data->map[(int)(data->player->x - data->raycast->dir.x * data->raycast->moveSpeed)][(int)(data->player->y)] == '0')
			data->player->x -= data->raycast->dir.x * data->raycast->moveSpeed;
		if (data->map[(int)(data->player->x)][(int)(data->player->y - data->raycast->dir.y * data->raycast->moveSpeed)] == '0')
			data->player->x -= data->raycast->dir.x * data->raycast->moveSpeed;
	}
	return (0);
}

void	check_rotate(t_data *data)
{
	double	oldDir;
	double	oldPlane;

	oldDir = data->raycast->dir.x;
	oldPlane = data->raycast->plane.x;
	//rotate to the right
	if (data->player->move_key == KEY_D)
	{
		//both camera direction and camera plane must be rotated
		data->raycast->dir.x = data->raycast->dir.x * cos(-data->raycast->rotSpeed) - data->raycast->dir.y * sin(-data->raycast->rotSpeed);
		data->raycast->dir.y = oldDir * sin(-data->raycast->rotSpeed) + data->raycast->dir.y * cos(-data->raycast->rotSpeed);
		data->raycast->plane.x = data->raycast->plane.x * cos(-data->raycast->rotSpeed) - data->raycast->plane.y * sin(-data->raycast->rotSpeed);
		data->raycast->plane.x = oldPlane * sin(-data->raycast->rotSpeed) + data->raycast->plane.y * cos(-data->raycast->rotSpeed);
	}
	else if (data->player->move_key == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		data->raycast->dir.x = data->raycast->dir.x * cos(data->raycast->rotSpeed) - data->raycast->dir.y * sin(data->raycast->rotSpeed);
		data->raycast->dir.y = oldDir * sin(data->raycast->rotSpeed) + data->raycast->dir.y * cos(data->raycast->rotSpeed);
		data->raycast->plane.x = data->raycast->plane.x * cos(data->raycast->rotSpeed) - data->raycast->plane.y * sin(data->raycast->rotSpeed);
		data->raycast->plane.x = oldPlane * sin(data->raycast->rotSpeed) + data->raycast->plane.y * cos(data->raycast->rotSpeed);
	}
}

void	check_exit(t_data *data)
{
	if (data->player->move_key == ESC)
		exit_cleaner(data);
}

// int render_after_move(t_data *data)
// {
// 	check_move(data);
// 	check_rotate(data);
// 	create_image(data);
// 	return (0);
// }