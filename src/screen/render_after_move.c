/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_after_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:54:08 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/12 18:10:20 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_move(t_data *data)
{
	//move forward if no wall in front of you
	if (data->player->move_key == KEY_W)
	{
		if (data->map[(int)(data->player->x + data->raycast->dir.x * MOVE_SPEED)][(int)(data->player->y)] == '0')
			data->player->x += data->raycast->dir.x * MOVE_SPEED;
			
		if (data->map[(int)(data->player->x)][(int)(data->player->y + data->raycast->dir.y * MOVE_SPEED)] == '0')
			data->player->y += data->raycast->dir.y * MOVE_SPEED;
			
	}
	//move backwards if no wall behind you
	if (data->player->move_key == KEY_S)
	{
		if (data->map[(int)(data->player->x - data->raycast->dir.x * MOVE_SPEED)][(int)(data->player->y)] == '0')
			data->player->x -= data->raycast->dir.x * MOVE_SPEED;
		if (data->map[(int)(data->player->x)][(int)(data->player->y - data->raycast->dir.y * MOVE_SPEED)] == '0')
			data->player->y -= data->raycast->dir.y * MOVE_SPEED;
	}
	if (data->player->move_key == KEY_A)
	{
		if (data->map[(int)(data->player->x - data->raycast->plane.x * MOVE_SPEED)][(int)(data->player->y)] == '0')
			data->player->x -= data->raycast->plane.x * MOVE_SPEED;
		if (data->map[(int)(data->player->x)][(int)(data->player->y - data->raycast->plane.y * MOVE_SPEED)] == '0')
			data->player->y -= data->raycast->plane.y * MOVE_SPEED;
	}
	if (data->player->move_key == KEY_D)
	{
		if (data->map[(int)(data->player->x + data->raycast->plane.x * MOVE_SPEED)][(int)(data->player->y)] == '0')
			data->player->x += data->raycast->plane.x * MOVE_SPEED;
		if (data->map[(int)(data->player->x)][(int)(data->player->y + data->raycast->plane.y * MOVE_SPEED)] == '0')
			data->player->y += data->raycast->plane.y * MOVE_SPEED;
	}
	create_image(data);
}

void	check_rotate(t_data *data)
{
	double	oldDir;
	double	oldPlane;

	oldDir = data->raycast->dir.x;
	oldPlane = data->raycast->plane.x;
	//rotate to the right
	if (data->player->move_key == KEY_LEFT)
	{
		//both camera direction and camera plane must be rotated
		data->raycast->dir.x = data->raycast->dir.x * cos(-ROTATE_SPEED) - data->raycast->dir.y * sin(-ROTATE_SPEED);
		data->raycast->dir.y = oldDir * sin(-ROTATE_SPEED) + data->raycast->dir.y * cos(-ROTATE_SPEED);
		data->raycast->plane.x = data->raycast->plane.x * cos(-ROTATE_SPEED) - data->raycast->plane.y * sin(-ROTATE_SPEED);
		data->raycast->plane.y = oldPlane * sin(-ROTATE_SPEED) + data->raycast->plane.y * cos(-ROTATE_SPEED);
	}
	if (data->player->move_key == KEY_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		data->raycast->dir.x = data->raycast->dir.x * cos(ROTATE_SPEED) - data->raycast->dir.y * sin(ROTATE_SPEED);
		data->raycast->dir.y = oldDir * sin(ROTATE_SPEED) + data->raycast->dir.y * cos(ROTATE_SPEED);
		data->raycast->plane.x = data->raycast->plane.x * cos(ROTATE_SPEED) - data->raycast->plane.y * sin(ROTATE_SPEED);
		data->raycast->plane.y = oldPlane * sin(ROTATE_SPEED) + data->raycast->plane.y * cos(ROTATE_SPEED);
	}
	create_image(data);
}

int render_after_move(t_data *data)
{
	//printf("%d\n",data->player->move_key);
	if (data->player->move_key == KEY_W || data->player->move_key == KEY_S || data->player->move_key == KEY_A || data->player->move_key == KEY_D)
		check_move(data);
	else if (data->player->move_key == KEY_LEFT || data->player->move_key == KEY_RIGHT)	
		check_rotate(data);
	if (data->player->move_key == ESC)
		exit_cleaner(data);
	return (0);
}