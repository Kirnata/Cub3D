/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_after_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:54:08 by ptopping          #+#    #+#             */
/*   Updated: 2022/09/29 18:08:37 by ptopping         ###   ########.fr       */
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
	create_image(data);
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
		data->raycast->dir.x = data->raycast->dir.x * cos(-ROTATE_SPEED) - data->raycast->dir.y * sin(-ROTATE_SPEED);
		data->raycast->dir.y = oldDir * sin(-ROTATE_SPEED) + data->raycast->dir.y * cos(-ROTATE_SPEED);
		data->raycast->plane.x = data->raycast->plane.x * cos(-ROTATE_SPEED) - data->raycast->plane.y * sin(-ROTATE_SPEED);
		data->raycast->plane.y = oldPlane * sin(-ROTATE_SPEED) + data->raycast->plane.y * cos(-ROTATE_SPEED);
	}
	if (data->player->move_key == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		data->raycast->dir.x = data->raycast->dir.x * cos(ROTATE_SPEED) - data->raycast->dir.y * sin(ROTATE_SPEED);
		data->raycast->dir.y = oldDir * sin(ROTATE_SPEED) + data->raycast->dir.y * cos(ROTATE_SPEED);
		data->raycast->plane.x = data->raycast->plane.x * cos(ROTATE_SPEED) - data->raycast->plane.y * sin(ROTATE_SPEED);
		data->raycast->plane.y = oldPlane * sin(ROTATE_SPEED) + data->raycast->plane.y * cos(ROTATE_SPEED);
	}
	// printf("HUI\n");
	// exit(0);
	create_image(data);
}

void	check_exit(t_data *data)
{
	if (data->player->move_key == ESC)
		exit_cleaner(data);
}

int render_after_move(t_data *data)
{
	printf("%d\n",data->player->move_key);
	// printf("\n----------------------------HUI\n");
	if (data->player->move_key == KEY_W || data->player->move_key == KEY_S)
		check_move(data);
	else if (data->player->move_key == KEY_A || data->player->move_key == KEY_D)	
		check_rotate(data);
	// else if (data->player->move_key == ESC)
	// 	exit_cleaner(data);
	check_exit(data);
	return (0);
}